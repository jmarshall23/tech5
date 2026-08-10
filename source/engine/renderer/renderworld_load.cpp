#include "renderworld_local.h"

#include "idlib/sys/sys_alloc.h"
#include "idlib/text/parser.h"

#include <algorithm>
#include <string>

namespace {

std::string StripExtension( const std::string & name ) {
	const std::string::size_type slash = name.find_last_of( "/\\" );
	const std::string::size_type dot = name.find_last_of( '.' );
	return dot != std::string::npos &&
		( slash == std::string::npos || dot > slash ) ? name.substr( 0, dot ) : name;
}

std::string BaseName( const std::string & name ) {
	const std::string::size_type slash = name.find_last_of( "/\\" );
	return slash == std::string::npos ? name : name.substr( slash + 1 );
}

bool LoadProcParser( const char * mapName, idParser & parser,
		std::string & loadedName ) {
	if ( mapName == nullptr || mapName[0] == '\0' ) return false;
	const std::string input( mapName );
	const std::string root = StripExtension( input );
	const std::string candidates[] = {
		input.size() >= 5 && input.substr( input.size() - 5 ) == ".proc"
			? input : root + ".proc",
		root + "/" + BaseName( root ) + ".proc"
	};
	for ( const std::string & candidate : candidates ) {
		if ( parser.LoadFile( candidate.c_str(), false ) ) {
			loadedName = candidate;
			return true;
		}
		parser.FreeSource();
	}
	return false;
}

bool ParseNodes( idParser & parser, idRenderWorldLocal & world ) {
	if ( !parser.ExpectTokenString( "{" ) ) return false;
	const int count = parser.ParseInt();
	if ( count < 0 || count > 65536 || !world.areaNodesStorage.SetNum( count ) )
		return false;
	for ( int index = 0; index < count; ++index ) {
		float plane[4] = {};
		if ( !parser.Parse1DMatrix( 4, plane ) ) return false;
		world.areaNodesStorage[index].plane = idPlane( plane[0], plane[1],
			plane[2], plane[3] );
		world.areaNodesStorage[index].children[0] = parser.ParseInt();
		world.areaNodesStorage[index].children[1] = parser.ParseInt();
	}
	if ( !parser.ExpectTokenString( "}" ) ) return false;
	world.areaNodes = world.areaNodesStorage.Ptr();
	world.areaNodeBoundsStorage.SetNum( count );
	world.areaNodeOcclusionIndexStorage.SetNum( count );
	for ( int index = 0; index < count; ++index ) {
		world.areaNodeBoundsStorage[index][0].Set(
			-131072.0f, -131072.0f, -131072.0f );
		world.areaNodeBoundsStorage[index][1].Set(
			131072.0f, 131072.0f, 131072.0f );
		world.areaNodeOcclusionIndexStorage[index] = -1;
	}
	world.areaNodeBounds = world.areaNodeBoundsStorage.Ptr();
	world.areaNodeOcclusionIndex = world.areaNodeOcclusionIndexStorage.Ptr();
	world.numAreaNodes = count;
	return true;
}

bool ParseAreas( idParser & parser, idRenderWorldLocal & world ) {
	if ( !parser.ExpectTokenString( "{" ) ) return false;
	const int count = parser.ParseInt();
	if ( count < 0 || count > 8192 || !world.worldAreasStorage.SetNum( count ) )
		return false;
	world.hasWorldSurfaceOffsets = true;
	for ( int index = 0; index < count; ++index ) {
		worldArea_t & area = world.worldAreasStorage[index];
		area.areaNum = index;
		area.firstSurfaceInWorldModel = parser.ParseInt();
		const int surfaceCount = parser.ParseInt();
		if ( surfaceCount < 0 || surfaceCount > 65536 ||
				!area.worldSurfaces.SetNum( surfaceCount ) ) return false;
	}
	if ( !parser.ExpectTokenString( "}" ) ) return false;
	world.worldAreas = world.worldAreasStorage.Ptr();
	world.worldAreaSubspaceBoundsStorage.SetNum( count );
	world.worldAreaGeometryBoundsStorage.SetNum( count );
	for ( int index = 0; index < count; ++index ) {
		world.worldAreaSubspaceBoundsStorage[index][0].Set(
			-131072.0f, -131072.0f, -131072.0f );
		world.worldAreaSubspaceBoundsStorage[index][1].Set(
			131072.0f, 131072.0f, 131072.0f );
		world.worldAreaGeometryBoundsStorage[index] =
			world.worldAreaSubspaceBoundsStorage[index];
	}
	world.worldAreaSubspaceBounds =
		world.worldAreaSubspaceBoundsStorage.Ptr();
	world.worldAreaGeometryBounds =
		world.worldAreaGeometryBoundsStorage.Ptr();
	world.numWorldAreas = count;
	return true;
}

bool ParseBinaryModels( idParser & parser, idRenderWorldLocal & world ) {
	if ( !parser.ExpectTokenString( "{" ) ) return false;
	const int count = parser.ParseInt();
	if ( count < 0 || count > 4096 ) return false;
	for ( int index = 0; index < count; ++index ) {
		idToken name;
		if ( !parser.ReadToken( name ) ) return false;
		world.SetBinaryModelState( name.c_str(), parser.ParseBool() );
	}
	return parser.ExpectTokenString( "}" );
}

}

bool idRenderWorldLocal::InitForTools( const char * name ) {
	return InitFromMap( name, false );
}

bool idRenderWorldLocal::InitFromMap( const char * name,
		const bool comboMap ) {
	ClearWorld();
	everInitialized = true;
	isComboMap = comboMap;
	mapName = name != nullptr ? StripExtension( name ).c_str() : "";
	worldRenderModel = AllocRenderModel( "_world", true, -1 );
	transparencyRenderModel = reinterpret_cast< idRenderModelTransparency * >(
		AllocRenderModel( "_transparency", true, -1 ) );
	decalRenderModel = reinterpret_cast< idRenderModelDecal * >(
		AllocRenderModel( "_decal", true, -1 ) );

	if ( name == nullptr || name[0] == '\0' ) return true;
	idParser parser;
	std::string procName;
	if ( !LoadProcParser( name, parser, procName ) ) return false;
	idToken token;
	if ( !parser.ReadToken( token ) ||
		( idStr::Icmp( token.c_str(), "mapProcFile006" ) != 0 &&
			idStr::Icmp( token.c_str(), "mapProcFile005" ) != 0 ) ) {
		return false;
	}
	while ( parser.ReadToken( token ) ) {
		if ( idStr::Cmp( token.c_str(), "nodes" ) == 0 ) {
			if ( !ParseNodes( parser, *this ) ) return false;
		} else if ( idStr::Cmp( token.c_str(), "areas" ) == 0 ) {
			if ( !ParseAreas( parser, *this ) ) return false;
		} else if ( idStr::Cmp( token.c_str(), "binaryModels" ) == 0 ) {
			if ( !ParseBinaryModels( parser, *this ) ) return false;
		} else if ( idStr::Cmp( token.c_str(), "interAreaPortals" ) == 0 ) {
			if ( !parser.SkipBracedSection( true ) ) return false;
		} else {
			return false;
		}
	}
	if ( numWorldAreas == 0 ) {
		worldAreasStorage.SetNum( 1 );
		worldAreasStorage[0].areaNum = 0;
		worldAreas = worldAreasStorage.Ptr();
		worldAreaSubspaceBoundsStorage.SetNum( 1 );
		worldAreaSubspaceBoundsStorage[0][0].Set(
			-131072.0f, -131072.0f, -131072.0f );
		worldAreaSubspaceBoundsStorage[0][1].Set(
			131072.0f, 131072.0f, 131072.0f );
		worldAreaSubspaceBounds = worldAreaSubspaceBoundsStorage.Ptr();
		worldAreaGeometryBoundsStorage.SetNum( 1 );
		worldAreaGeometryBoundsStorage[0] = worldAreaSubspaceBoundsStorage[0];
		worldAreaGeometryBounds = worldAreaGeometryBoundsStorage.Ptr();
		numWorldAreas = 1;
	}
	ambientLighting.LoadAmbientLighting( this );
	globalShadows.LoadGlobalShadows( this );
	return !parser.HadError();
}
