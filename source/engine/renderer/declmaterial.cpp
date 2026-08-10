#include "declmaterial.h"

#include "declrenderparm.h"
#include "declrenderprog.h"
#include "image.h"
#include "imagemanager.h"
#include "materialmap.h"
#include "parmblockoptimizer.h"
#include "idlib/text/parser.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>

namespace {
	const idVec4 defaultScaleBias( 1.0f, 1.0f, 0.0f, 0.0f );

	const idDeclRenderProg * LoadProgram( const char * name ) {
		if ( name == nullptr || name[0] == '\0' || idStr::Cmp( name, "0" ) == 0 ) return nullptr;
		idResourceList * const list = idResourceList::ForTypeName( "renderProg" );
		return list != nullptr
			? static_cast< const idDeclRenderProg * >( list->Load( name, true ) ) : nullptr;
	}

	int ProgramRoleForToken( const char * token ) {
		if ( idStr::Icmp( token, "interactionProgram" ) == 0 ) return MPR_INTERACTION;
		if ( idStr::Icmp( token, "shadowProgram" ) == 0 ) return MPR_SHADOW;
		if ( idStr::Icmp( token, "depthFillProgram" ) == 0 ) return MPR_DEPTH_FILL;
		if ( idStr::Icmp( token, "addProgram" ) == 0 ) return MPR_ADD;
		if ( idStr::Icmp( token, "blendProgram" ) == 0 ) return MPR_BLEND;
		if ( idStr::Icmp( token, "stageProgram" ) == 0 ) return MPR_STAGE;
		if ( idStr::Icmp( token, "fadePerturbProgram" ) == 0 ) return MPR_FADE_PERTURB;
		return idStr::Icmp( token, "ambientProgram" ) == 0 ? MPR_AMBIENT : -1;
	}

	bool StartsWith( const char * text, const char * prefix ) {
		if ( text == nullptr || prefix == nullptr ) return false;
		while ( *prefix != '\0' ) {
			if ( std::tolower( static_cast< unsigned char >( *text++ ) )
				!= std::tolower( static_cast< unsigned char >( *prefix++ ) ) ) return false;
		}
		return true;
	}
}

idDeclInfoTemplate< idMaterial > idMaterial::resourceList(
	"material", "idMaterial", "mtr" );

idMaterial::idMaterial() : parmBlock( THREAD_MAIN ),
	renderParmBlock( THREAD_RENDERER ) {
	Clear();
}

idMaterial::~idMaterial() { FreeData(); }

idDeclInfo * idMaterial::GetDeclInfo() const { return &resourceList; }
const char * idMaterial::DefaultDefinition() const {
	return "{ // DEFAULTED\n\ttransMap _default\n\tstageProgram guiBlend\n}\n";
}
unsigned int idMaterial::Size() const { return sizeof( *this ); }

void idMaterial::Clear() {
	atlasScaleBias.Set( 1.0f, 1.0f, 0.0f, 0.0f );
	materialUsesWrinkleMaps = 0;
	materialUsesApproximatedLighting = 0;
	materialUsesTransSortAtlas = 0;
	materialIsTransparencySorted = 0;
	materialHasInteractions = 0;
	materialIsMixedUnique = 0;
	materialIsTwoSided = 0;
	materialCastsShadows = 1;
	reservedMaterialBits = 0;
	materialHasClipSpheres = 0;
	skipSurfaceInfo = 0;
	materialHasMergeableBlendedPass = 0;
	materialAutospriteType = AUTOSPRITE_NONE;
	materialDecalProjType = DECALPROJ_PLANAR;
	parmBlock.Clear();
	renderParmBlock.Clear();
	pageSource = PAGESOURCE_VMTR;
	pageFileName = nullptr;
	physicalPagesPool = PHYSICAL_PAGES_POOL_VMTR;
	for ( int index = 0; index < MPR_MAX; ++index ) {
		progs[index] = nullptr;
		stageSort[index] = 0.0f;
	}
	materialMap = nullptr;
	devVmtr = nullptr;
	virtualMapping.Set( 0, 0, 0, 0 );
	editorImage = nullptr;
	coverage = MC_BAD;
}

void idMaterial::FreeData() { Clear(); }

bool idMaterial::IsValidMaterialName( const char * name,
	const bool allowUnderscore, const bool allowAmpersand ) {
	if ( name == nullptr || name[0] == '\0' ) return false;
	const unsigned char first = static_cast< unsigned char >( name[0] );
	if ( std::isalpha( first ) == 0 && !( allowUnderscore && first == '_' ) ) return false;
	for ( const char * c = name + 1; *c != '\0'; ++c ) {
		const unsigned char value = static_cast< unsigned char >( *c );
		if ( std::isalnum( value ) != 0 || value == '_' || value == '/'
			|| value == '\\' || value == '.' || ( allowAmpersand && value == '&' ) ) continue;
		return false;
	}
	return true;
}

bool idMaterial::SetImplicitText() {
	char definition[4096];
	const char * const materialName = GetName();
	if ( StartsWith( materialName, "fonts/" ) ) {
		std::snprintf( definition, sizeof( definition ),
			"{ // IMPLICITLY GENERATED\ntransMap %s\nstageProgram FontBiasAndGamma\n}\n",
			materialName );
	} else {
		std::snprintf( definition, sizeof( definition ),
			"{ // IMPLICITLY GENERATED\ntransMap %s\nstageProgram guiBlend\n}\n",
			materialName );
	}
	SetText( definition );
	return true;
}

void idMaterial::Parse( idParser * parser ) {
	if ( parser == nullptr ) return;
	Clear();
	idToken token;
	if ( !parser->ReadToken( token ) ) return;
	if ( idStr::Cmp( token.c_str(), "{" ) != 0 ) parser->UnreadToken( token );
	while ( parser->ReadToken( token ) ) {
		if ( idStr::Cmp( token.c_str(), "}" ) == 0 ) break;
		if ( idStr::Icmp( token.c_str(), "noShadows" ) == 0 ) {
			materialCastsShadows = 0;
			continue;
		}
		if ( idStr::Icmp( token.c_str(), "twoSided" ) == 0 ) {
			materialIsTwoSided = 1;
			continue;
		}
		if ( idStr::Icmp( token.c_str(), "translucent" ) == 0 ) {
			coverage = MC_TRANSLUCENT;
			continue;
		}
		if ( idStr::Icmp( token.c_str(), "perforated" ) == 0 ) {
			coverage = MC_PERFORATED;
			continue;
		}
		if ( idStr::Icmp( token.c_str(), "invisible" ) == 0 ) {
			coverage = MC_INVISIBLE;
			continue;
		}
		if ( idStr::Icmp( token.c_str(), "autosprite" ) == 0 ) {
			materialAutospriteType = AUTOSPRITE_VIEW_ORIENTED;
			continue;
		}
		if ( idStr::Icmp( token.c_str(), "autosprite2" ) == 0 ) {
			materialAutospriteType = AUTOSPRITE_LONGEST_AXIS_ALIGNED;
			continue;
		}
		if ( idStr::Icmp( token.c_str(), "sphericalDecal" ) == 0 ) {
			materialDecalProjType = DECALPROJ_SPHERICAL;
			continue;
		}
		const int role = ProgramRoleForToken( token.c_str() );
		if ( role >= 0 ) {
			idToken programName;
			if ( parser->ReadToken( programName ) ) {
				progs[role] = LoadProgram( programName.c_str() );
				if ( role == MPR_INTERACTION ) materialHasInteractions = progs[role] != nullptr;
			}
			parser->SkipRestOfLine();
			continue;
		}
		if ( idStr::Icmp( token.c_str(), "sort" ) == 0 ) {
			stageSort[MPR_STAGE] = parser->ParseFloat();
			parser->SkipRestOfLine();
			continue;
		}
		if ( idStr::Icmp( token.c_str(), "pageFile" ) == 0 ) {
			idToken fileName;
			if ( parser->ReadToken( fileName ) ) {
				idAtomicString atomic( fileName.c_str() );
				pageFileName = atomic.c_str();
				pageSource = PAGESOURCE_UNIQUE;
			}
			parser->SkipRestOfLine();
			continue;
		}

		const idDeclRenderParm * const parm = idDeclRenderParm::FindByName(
			token.c_str(), false );
		if ( parm == nullptr ) {
			parser->Warning( "Unknown material parameter '%s' in %s",
				token.c_str(), GetName() );
			parser->SkipRestOfLine();
			continue;
		}
		idStr valueText;
		parser->ParseRestOfLine( valueText );
		valueText.TrimWhitespaceRecovered();
		parmValue_t value = {};
		parm->ParseStringToValue( valueText.c_str(), value );
		parmBlock.SetParm( parm, value );
	}

	if ( coverage == MC_BAD ) {
		coverage = materialIsTransparencySorted ? MC_TRANSLUCENT : MC_OPAQUE;
	}
	const idDeclRenderParm * const editorParm = idDeclRenderParm::FindByName(
		"qer_editorImage", false );
	if ( editorParm != nullptr ) {
		if ( editorParm->parmType >= PT_TEXTURE
			&& editorParm->parmType <= PT_TEXTURE_MULTISAMPLE_2D ) {
			editorImage = parmBlock.GetImage( editorParm );
		} else if ( editorParm->parmType == PT_STRING ) {
			const char * const imageName = parmBlock.GetString( editorParm );
			if ( imageName != nullptr && imageName[0] != '\0' ) {
				editorImage = globalImages->ImageFromFile( imageName );
			}
		}
	}
	if ( editorImage == nullptr && globalImages != nullptr ) editorImage = globalImages->defaultImage;
	OptimizeRenderParmBlock();
}

void idMaterial::OptimizeRenderParmBlock() {
	renderParmBlock.CopyFrom( parmBlock );
	idParmBlockOptimizer optimizer;
	for ( int programIndex = 0; programIndex < MPR_MAX; ++programIndex ) {
		const idDeclRenderProg * const program = progs[programIndex];
		if ( program == nullptr ) continue;
		for ( int index = 0; index < program->numVertexParms; ++index ) {
			optimizer.AddUsedParmIndex( program->vertexParms[index] );
		}
		for ( int index = 0; index < program->numFragmentParms; ++index ) {
			optimizer.AddUsedParmIndex( program->fragmentParms[index] );
		}
		for ( int index = 0; index < program->numTextureParms; ++index ) {
			optimizer.AddUsedParmIndex( program->textureParms[index] );
		}
	}
	if ( optimizer.numUsedParms > 0 ) {
		optimizer.OptimizeParmBlockForUsedParms( renderParmBlock );
	}
}

bool idMaterial::MaterialIsMergableWith( const idMaterial * other ) const {
	if ( other == this ) return true;
	if ( other == nullptr ) return false;
	for ( int index = 0; index <= MPR_DEPTH_FILL; ++index ) {
		if ( progs[index] != other->progs[index] ) return false;
	}
	if ( materialHasMergeableBlendedPass != 0 ) {
		return progs[MPR_ADD] == other->progs[MPR_ADD]
			&& progs[MPR_BLEND] == other->progs[MPR_BLEND];
	}
	return progs[MPR_ADD] == nullptr && other->progs[MPR_ADD] == nullptr
		&& progs[MPR_BLEND] == nullptr && other->progs[MPR_BLEND] == nullptr;
}

const idVec4 & idMaterial::GetMaterialMapping( const idMaterial * material ) const {
	if ( materialMap == nullptr || material == nullptr ) return defaultScaleBias;
	const idMaterialMapping * const mapping = materialMap->FindMapping( material->GetName() );
	return mapping != nullptr ? mapping->scaleBias : defaultScaleBias;
}

bool idMaterial::MaterialMappingsAreCompatible( const idMaterial * material ) const {
	if ( material == nullptr || materialMap == nullptr || material->materialMap == nullptr
		|| materialMap->mappings.Num() != material->materialMap->mappings.Num() ) return false;
	for ( int index = 0; index < materialMap->mappings.Num(); ++index ) {
		const idVec4 & a = materialMap->mappings[index].scaleBias;
		const idVec4 & b = material->materialMap->mappings[index].scaleBias;
		if ( a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w ) return false;
	}
	return true;
}

bool idMaterial::GetImageDimensions( int & width, int & height ) const {
	if ( materialMap != nullptr ) return materialMap->GetImageDimensions( width, height );
	if ( editorImage != nullptr ) {
		width = (std::max)( editorImage->opts.width, 1 );
		height = (std::max)( editorImage->opts.height, 1 );
		return !editorImage->defaulted;
	}
	width = height = 1;
	return false;
}

int idMaterial::GetImageWidth() const { int width, height; GetImageDimensions( width, height ); return width; }
int idMaterial::GetImageHeight() const { int width, height; GetImageDimensions( width, height ); return height; }

const materialStage_t * idMaterial::GetStage( const int index ) const {
	static const materialStage_t stage = { { nullptr } };
	return index == 0 && ( progs[MPR_STAGE] != nullptr || editorImage != nullptr ) ? &stage : nullptr;
}

const idDeclRenderProg * idMaterial::GetProgram( const materialProgramRole_t role ) const {
	return role >= 0 && role < MPR_MAX ? progs[role] : nullptr;
}

void idMaterial::List() { std::printf( "%s\n", GetName() ); }

void idMaterial::Print() {
	std::printf( "material %s coverage=%d shadows=%d twoSided=%d\n", GetName(),
		static_cast< int >( coverage ), materialCastsShadows != 0,
		materialIsTwoSided != 0 );
	for ( int index = 0; index < MPR_MAX; ++index ) {
		if ( progs[index] != nullptr ) {
			std::printf( "  program[%d] %s sort=%g\n", index,
				progs[index]->GetName(), stageSort[index] );
		}
	}
}
