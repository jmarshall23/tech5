#include "iesfile.h"

#include "image.h"
#include "imagemanager.h"
#include "triangles.h"
#include "../models/static/staticmodel.h"
#include "../../shared/idlib/lib_print.h"
#include "../../shared/idlib/text/lexer.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <limits>
#include <new>
#include <vector>

namespace {
	constexpr float PI = 3.14159265358979323846f;
	constexpr int CANDELA_IMAGE_SIZE = 256;
	constexpr int HORIZONTAL_SEGMENTS = 36;
	constexpr float EDITOR_CANDELA_SCALE = 4.0f;
	constexpr int MAX_IES_ANGLES = 65536;

	float WrapDegrees( float angle ) {
		angle = std::fmod( angle, 360.0f );
		return angle < 0.0f ? angle + 360.0f : angle;
	}

	int LowerInterval( const idList< float, 5 > & values, const float sample,
			float & fraction ) {
		fraction = 0.0f;
		if ( values.Num() <= 1 ) return 0;
		if ( sample <= values[0] ) return 0;
		for ( int index = 1; index < values.Num(); ++index ) {
			if ( sample < values[index] ) {
				const float span = values[index] - values[index - 1];
				fraction = span > 0.0f ? ( sample - values[index - 1] ) / span : 0.0f;
				return index - 1;
			}
		}
		return values.Num() - 1;
	}

	void InitVertex( idDrawVert & vertex, const idVec3 & position,
			const idVec2 & texCoord = idVec2( 0.0f, 0.0f ) ) {
		std::memset( &vertex, 0, sizeof( vertex ) );
		vertex.xyz = position;
		vertex.st = texCoord;
		vertex.SetNormal( idVec3( 0.0f, 0.0f, 1.0f ) );
		vertex.SetTangent( idVec3( 1.0f, 0.0f, 0.0f ) );
		vertex.tangent[3] = 255;
		std::memset( vertex.color, 255, sizeof( vertex.color ) );
	}

	idTriangles * AllocGeometry( const int numVerts, const int numIndexes ) {
		idTriangles * const geometry = new ( std::nothrow ) idTriangles{};
		if ( geometry == nullptr ) return nullptr;
		R_InitTriangles( *geometry );
		R_AllocTriangleVerts( *geometry, numVerts );
		R_AllocTriangleIndexes( *geometry, numIndexes );
		if ( ( numVerts > 0 && geometry->verts == nullptr ) ||
				( numIndexes > 0 && geometry->indexes == nullptr ) ) {
			R_FreeTriangleCPUData( *geometry );
			delete geometry;
			return nullptr;
		}
		geometry->numVerts = numVerts;
		geometry->numIndexes = numIndexes;
		return geometry;
	}

	void AppendBoxFace( idTriangles & geometry, int & vertexCursor,
			int & indexCursor, const idVec3 & a, const idVec3 & b,
			const idVec3 & c, const idVec3 & d ) {
		InitVertex( geometry.verts[vertexCursor + 0], a, idVec2( 0.0f, 0.0f ) );
		InitVertex( geometry.verts[vertexCursor + 1], b, idVec2( 1.0f, 0.0f ) );
		InitVertex( geometry.verts[vertexCursor + 2], c, idVec2( 1.0f, 1.0f ) );
		InitVertex( geometry.verts[vertexCursor + 3], d, idVec2( 0.0f, 1.0f ) );
		const unsigned short base = static_cast< unsigned short >( vertexCursor );
		const unsigned short face[6] = { base, static_cast< unsigned short >( base + 1 ),
			static_cast< unsigned short >( base + 2 ), base,
			static_cast< unsigned short >( base + 2 ),
			static_cast< unsigned short >( base + 3 ) };
		std::memcpy( geometry.indexes + indexCursor, face, sizeof( face ) );
		vertexCursor += 4;
		indexCursor += 6;
	}

	bool ParseFloatValue( idLexer & lexer, float & value ) {
		bool error = false;
		value = lexer.ParseFloat( &error );
		return !error && !lexer.HadError();
	}
}

idTypedResourceList< idIESfile > idIESfile::resourceList( "ies" );

iesRenderInfo_t::iesRenderInfo_t() : maxCandela( 0.0f ),
	lightArea( 0.0f, 0.0f, 0.0f ), cutoffCosine( -1.0f ), projectMap{} {}

idIESfile::idIESfile() : formatYear( 0 ), lampToLuminaireGeometry( 0 ),
	numAngleFactors( 0 ), numLamps( 0 ), lumensPerLamp( 0.0f ),
	candelaMultiplier( 1.0f ), numVerticalAngles( 0 ), numHorizontalAngles( 0 ),
	photoMetricType( 0 ), unitsType( 0 ), width( 0.0f ), length( 0.0f ),
	height( 0.0f ), ballastFactor( 1.0f ), futureUse( 0 ), inputWats( 0.0f ),
	editorModel( nullptr ) {}

idIESfile::~idIESfile() {
	delete editorModel;
	editorModel = nullptr;
}

void idIESfile::ClearPhotometricData() {
	factorAngles.ClearFree();
	factorScales.ClearFree();
	verticalAngles.ClearFree();
	horizontalAngles.ClearFree();
	candela.ClearFree();
	renderInfo = iesRenderInfo_t();
	delete editorModel;
	editorModel = nullptr;
}

idResourceList * idIESfile::GetResourceList() { return &resourceList; }

bool idIESfile::ReloadIfStale() { return false; }

void idIESfile::WriteResourceFile() {
	// IES is a source interchange format.  Retail generated auxiliary images
	// and editor models; the PC path keeps both generated resources in memory.
}

void idIESfile::Print() {
	idLibPrint::Printf( "%s: %.2f cd, area (%.2f %.2f %.2f), cutoff %.3f\n",
		GetName(), renderInfo.maxCandela, renderInfo.lightArea.x,
		renderInfo.lightArea.y, renderInfo.lightArea.z,
		renderInfo.cutoffCosine );
}

void idIESfile::List() { Print(); }

float idIESfile::CandelaAtAngle( float horizontalAngle,
		float verticalAngle ) const {
	if ( numHorizontalAngles <= 0 || numVerticalAngles <= 0 ||
			horizontalAngles.Num() < numHorizontalAngles ||
			verticalAngles.Num() < numVerticalAngles ||
			candela.Num() < numHorizontalAngles * numVerticalAngles ) return 0.0f;

	horizontalAngle = WrapDegrees( horizontalAngle );
	const float firstHorizontal = horizontalAngles[0];
	const float lastHorizontal = horizontalAngles[numHorizontalAngles - 1];
	if ( firstHorizontal == 0.0f && lastHorizontal == 90.0f ) {
		if ( horizontalAngle > 90.0f && horizontalAngle < 180.0f )
			horizontalAngle = 180.0f - horizontalAngle;
		else if ( horizontalAngle >= 180.0f && horizontalAngle < 270.0f )
			horizontalAngle = 540.0f - horizontalAngle;
		if ( horizontalAngle >= 270.0f ) horizontalAngle = 360.0f - horizontalAngle;
	} else if ( firstHorizontal == 0.0f && lastHorizontal == 180.0f ) {
		if ( horizontalAngle >= 180.0f ) horizontalAngle = 360.0f - horizontalAngle;
	} else if ( firstHorizontal == 90.0f && lastHorizontal == 270.0f ) {
		if ( horizontalAngle < 90.0f ) horizontalAngle = 180.0f - horizontalAngle;
		else if ( horizontalAngle >= 270.0f ) horizontalAngle = 540.0f - horizontalAngle;
	} else if ( firstHorizontal == -90.0f && lastHorizontal == 90.0f ) {
		if ( horizontalAngle >= 180.0f ) horizontalAngle = 360.0f - horizontalAngle;
		horizontalAngle -= 90.0f;
	}

	const float firstVertical = verticalAngles[0];
	const float lastVertical = verticalAngles[numVerticalAngles - 1];
	if ( firstVertical == 0.0f && lastVertical == 90.0f ) {
		if ( verticalAngle > 90.0f ) return 0.0f;
	} else if ( firstVertical == 90.0f && lastVertical == 180.0f ) {
		if ( verticalAngle < 90.0f ) return 0.0f;
	} else if ( firstVertical == -90.0f && lastVertical == 90.0f ) {
		verticalAngle -= 90.0f;
	} else if ( numVerticalAngles == 1 ) {
		verticalAngle = verticalAngles[0];
	}

	float horizontalFraction = 0.0f;
	float verticalFraction = 0.0f;
	const int horizontal0 = LowerInterval( horizontalAngles, horizontalAngle,
		horizontalFraction );
	const int vertical0 = LowerInterval( verticalAngles, verticalAngle,
		verticalFraction );
	const int horizontal1 = (std::min)( horizontal0 + 1, numHorizontalAngles - 1 );
	const int vertical1 = (std::min)( vertical0 + 1, numVerticalAngles - 1 );
	const float c00 = candela[horizontal0 * numVerticalAngles + vertical0];
	const float c10 = candela[horizontal1 * numVerticalAngles + vertical0];
	const float c01 = candela[horizontal0 * numVerticalAngles + vertical1];
	const float c11 = candela[horizontal1 * numVerticalAngles + vertical1];
	const float c0 = c00 + ( c10 - c00 ) * horizontalFraction;
	const float c1 = c01 + ( c11 - c01 ) * horizontalFraction;
	return c0 + ( c1 - c0 ) * verticalFraction;
}

void idIESfile::BuildCandelaImage() {
	if ( globalImages == nullptr || renderInfo.maxCandela <= 0.0f ||
			renderInfo.projectMap[0] == '\0' ) return;
	std::vector< unsigned char > pixels(
		CANDELA_IMAGE_SIZE * CANDELA_IMAGE_SIZE * 4, 255 );
	for ( int y = 0; y < CANDELA_IMAGE_SIZE; ++y ) {
		const float vertical = y * ( 180.0f / CANDELA_IMAGE_SIZE );
		for ( int x = 0; x < CANDELA_IMAGE_SIZE; ++x ) {
			const float horizontal = x * ( 360.0f / CANDELA_IMAGE_SIZE );
			const float scaled = CandelaAtAngle( horizontal, vertical ) *
				255.0f / renderInfo.maxCandela;
			const unsigned char value = static_cast< unsigned char >(
				(std::max)( 0.0f, (std::min)( 255.0f, scaled ) ) );
			unsigned char * const pixel = &pixels[( y * CANDELA_IMAGE_SIZE + x ) * 4];
			pixel[0] = pixel[1] = pixel[2] = value;
		}
	}
	idImageOpts opts;
	opts.textureType = TT_2D;
	opts.width = CANDELA_IMAGE_SIZE;
	opts.height = CANDELA_IMAGE_SIZE;
	opts.depth = 1;
	opts.numLevels = 1;
	opts.format = FMT_RGBA8;
	opts.filter = TF_LINEAR;
	opts.repeat = TR_CLAMP;
	idImage * const image = globalImages->ScratchImage( renderInfo.projectMap, &opts );
	if ( image != nullptr && image->GetTexture() != nullptr ) {
		image->SubImageUpload( 0, 0, 0, 0, CANDELA_IMAGE_SIZE,
			CANDELA_IMAGE_SIZE, pixels.data(), CANDELA_IMAGE_SIZE * 4 );
	}
}

void idIESfile::BuildEditorModel() {
	delete editorModel;
	editorModel = new ( std::nothrow ) idStaticModel();
	if ( editorModel == nullptr ) return;
	editorModel->SetName( editorModelName.c_str() );
	editorModel->modelLoadFlags = idStaticModel::MODELLOADFLAGS_RESIDE_ON_CPU;

	idStaticModelSurface surface;
	surface.material = idStaticModel::ResolveMaterial( "_white" );
	idTriangles * box = AllocGeometry( 24, 36 );
	if ( box != nullptr ) {
		const float x = renderInfo.lightArea.x;
		const float y = renderInfo.lightArea.y;
		const float z = renderInfo.lightArea.z;
		const idVec3 p000( -x, -y, -z ), p100( x, -y, -z );
		const idVec3 p110( x, y, -z ), p010( -x, y, -z );
		const idVec3 p001( -x, -y, z ), p101( x, -y, z );
		const idVec3 p111( x, y, z ), p011( -x, y, z );
		int vertex = 0, index = 0;
		AppendBoxFace( *box, vertex, index, p001, p101, p111, p011 );
		AppendBoxFace( *box, vertex, index, p100, p000, p010, p110 );
		AppendBoxFace( *box, vertex, index, p101, p100, p110, p111 );
		AppendBoxFace( *box, vertex, index, p000, p001, p011, p010 );
		AppendBoxFace( *box, vertex, index, p000, p100, p101, p001 );
		AppendBoxFace( *box, vertex, index, p011, p111, p110, p010 );
		R_DeriveTriangleTangents( *box );
		box->bounds = R_BoundsFromTriangleVerts( *box );
		surface.geometry = box;
		editorModel->AddSurface( surface );
	}

	const int verticalSegments = verticalAngles.Num() > 0 &&
		verticalAngles[verticalAngles.Num() - 1] > 90.0f ? 18 : 9;
	const int rowVerts = HORIZONTAL_SEGMENTS + 1;
	idTriangles * polar = AllocGeometry( rowVerts * ( verticalSegments + 1 ),
		HORIZONTAL_SEGMENTS * verticalSegments * 6 );
	if ( polar != nullptr ) {
		for ( int ring = 0; ring <= verticalSegments; ++ring ) {
			const float vertical = ring * ( verticalSegments == 18 ? 10.0f : 10.0f );
			const float verticalRadians = vertical * PI / 180.0f;
			for ( int segment = 0; segment <= HORIZONTAL_SEGMENTS; ++segment ) {
				const float horizontal = segment * 10.0f;
				const float horizontalRadians = horizontal * PI / 180.0f;
				const float radius = std::sqrt( (std::max)( 0.0f,
					CandelaAtAngle( horizontal, vertical ) ) ) * EDITOR_CANDELA_SCALE;
				const idVec3 position( std::cos( horizontalRadians ) *
					std::sin( verticalRadians ) * radius,
					std::sin( horizontalRadians ) * std::sin( verticalRadians ) * radius,
					-std::cos( verticalRadians ) * radius );
				InitVertex( polar->verts[ring * rowVerts + segment], position,
					idVec2( segment / static_cast< float >( HORIZONTAL_SEGMENTS ),
					ring / static_cast< float >( verticalSegments ) ) );
			}
		}
		int out = 0;
		for ( int ring = 0; ring < verticalSegments; ++ring ) {
			for ( int segment = 0; segment < HORIZONTAL_SEGMENTS; ++segment ) {
				const unsigned short a = static_cast< unsigned short >( ring * rowVerts + segment );
				const unsigned short b = static_cast< unsigned short >( a + rowVerts );
				polar->indexes[out++] = a;
				polar->indexes[out++] = b;
				polar->indexes[out++] = static_cast< unsigned short >( a + 1 );
				polar->indexes[out++] = static_cast< unsigned short >( a + 1 );
				polar->indexes[out++] = b;
				polar->indexes[out++] = static_cast< unsigned short >( b + 1 );
			}
		}
		R_DeriveTriangleTangents( *polar );
		polar->bounds = R_BoundsFromTriangleVerts( *polar );
		surface.geometry = polar;
		editorModel->AddSurface( surface );
	}
	editorModel->FinishStaticModel( false );
}

void idIESfile::LoadResource() {
	ClearResourceError();
	ClearPhotometricData();
	idLexer lexer( LEXFL_NOSTRINGS | LEXFL_NOFATALERRORS );
	if ( !lexer.LoadFile( GetName(), false ) ) {
		SetResourceError( "IES file not found '%s'", GetName() );
		return;
	}
	idStr line;
	lexer.ParseCompleteLine( line );
	if ( std::strncmp( line.c_str(), "IESNA91", 7 ) == 0 ) formatYear = 91;
	else if ( std::strncmp( line.c_str(), "IESNA:LM-63-1995", 16 ) == 0 ) formatYear = 1995;
	else if ( std::strncmp( line.c_str(), "IESNA:LM-63-2002", 16 ) == 0 ) formatYear = 2002;
	else {
		SetResourceError( "File wasn't IESNA LM-63-1991, 1995, or 2002: %s", GetName() );
		return;
	}

	idToken token;
	while ( lexer.ReadToken( token ) && idStr::Icmp( token.c_str(), "TILT" ) != 0 ) {}
	if ( idStr::Icmp( token.c_str(), "TILT" ) != 0 ||
			!lexer.ExpectTokenString( "=" ) || !lexer.ReadToken( token ) ) {
		SetResourceError( "TILT keyword not present in %s", GetName() );
		return;
	}
	if ( idStr::Icmp( token.c_str(), "INCLUDE" ) == 0 ) {
		lampToLuminaireGeometry = lexer.ParseInt();
		numAngleFactors = lexer.ParseInt();
		if ( numAngleFactors < 0 || numAngleFactors > MAX_IES_ANGLES ) {
			SetResourceError( "Invalid TILT angle count in %s", GetName() );
			return;
		}
		for ( int index = 0; index < numAngleFactors; ++index ) {
			float value;
			if ( !ParseFloatValue( lexer, value ) ) { SetResourceError( "Truncated TILT angles in %s", GetName() ); return; }
			factorAngles.Append( value );
		}
		for ( int index = 0; index < numAngleFactors; ++index ) {
			float value;
			if ( !ParseFloatValue( lexer, value ) ) { SetResourceError( "Truncated TILT factors in %s", GetName() ); return; }
			factorScales.Append( value );
		}
	} else if ( idStr::Icmp( token.c_str(), "NONE" ) != 0 ) {
		SetResourceError( "External TILT files are unsupported in %s", GetName() );
		return;
	}

	numLamps = lexer.ParseInt();
	if ( !ParseFloatValue( lexer, lumensPerLamp ) ||
			!ParseFloatValue( lexer, candelaMultiplier ) ) {
		SetResourceError( "Truncated lamp data in %s", GetName() ); return;
	}
	numVerticalAngles = lexer.ParseInt();
	numHorizontalAngles = lexer.ParseInt();
	photoMetricType = lexer.ParseInt();
	unitsType = lexer.ParseInt();
	if ( numVerticalAngles <= 0 || numHorizontalAngles <= 0 ||
			numVerticalAngles > MAX_IES_ANGLES || numHorizontalAngles > MAX_IES_ANGLES ||
			static_cast< long long >( numVerticalAngles ) * numHorizontalAngles >
			std::numeric_limits< int >::max() ) {
		SetResourceError( "Invalid photometric angle dimensions in %s", GetName() );
		return;
	}
	if ( !ParseFloatValue( lexer, width ) || !ParseFloatValue( lexer, length ) ||
			!ParseFloatValue( lexer, height ) || !ParseFloatValue( lexer, ballastFactor ) ) {
		SetResourceError( "Truncated luminaire dimensions in %s", GetName() ); return;
	}
	futureUse = lexer.ParseInt();
	if ( !ParseFloatValue( lexer, inputWats ) ) {
		SetResourceError( "Truncated luminaire power in %s", GetName() ); return;
	}
	for ( int index = 0; index < numVerticalAngles; ++index ) {
		float value;
		if ( !ParseFloatValue( lexer, value ) ) { SetResourceError( "Truncated vertical angles in %s", GetName() ); return; }
		verticalAngles.Append( value );
	}
	for ( int index = 0; index < numHorizontalAngles; ++index ) {
		float value;
		if ( !ParseFloatValue( lexer, value ) ) { SetResourceError( "Truncated horizontal angles in %s", GetName() ); return; }
		horizontalAngles.Append( value );
	}
	const int candelaCount = numVerticalAngles * numHorizontalAngles;
	for ( int index = 0; index < candelaCount; ++index ) {
		float value;
		if ( !ParseFloatValue( lexer, value ) ) { SetResourceError( "Truncated candela table in %s", GetName() ); return; }
		value *= candelaMultiplier;
		candela.Append( value );
		renderInfo.maxCandela = (std::max)( renderInfo.maxCandela, value );
	}
	if ( verticalAngles[numVerticalAngles - 1] <= 90.0f ) {
		renderInfo.cutoffCosine = 0.0f;
		for ( int horizontal = 0; horizontal < numHorizontalAngles; ++horizontal )
			candela[horizontal * numVerticalAngles + numVerticalAngles - 1] = 0.0f;
	} else renderInfo.cutoffCosine = -1.0f;

	if ( width == 0.0f && length > 0.0f && height < 0.0f ) width = length;
	if ( width > 0.0f && length == 0.0f && height < 0.0f ) length = width;
	renderInfo.lightArea.Set( std::fabs( width ), std::fabs( length ), std::fabs( height ) );
	const float unitScale = unitsType == 1 ? 16.0f : unitsType == 2 ? 52.48f : 1.0f;
	renderInfo.lightArea = renderInfo.lightArea * ( unitScale * 0.5f );

	idStr generatedName( "generated/cloud/cpuImages/" );
	generatedName.Append( GetName() );
	generatedName.StripFileExtension();
	generatedName.Append( ".cpuimage" );
	std::snprintf( renderInfo.projectMap, sizeof( renderInfo.projectMap ), "%s",
		generatedName.c_str() );
	editorModelName = "generated/models/";
	editorModelName.Append( GetName() );
	editorModelName.StripFileExtension();
	editorModelName.Append( ".bmodel" );
	BuildCandelaImage();
	BuildEditorModel();
}
