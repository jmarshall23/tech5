#include "autorenderparms.h"

#include "declrenderparm.h"

#include <cstdio>
#include <cstring>

namespace {
	const idDeclRenderParm * AutoParm( const char * name ) {
		return idDeclRenderParm::FindByName( name, true );
	}
}

idAutoRenderParms::idAutoRenderParms() {
	std::memset( this, 0, sizeof( *this ) );
	const char components[] = "xyzw";
	char name[64];
	for ( int index = 0; index < 4; ++index ) {
		std::snprintf( name, sizeof( name ), "viewMatrix%c", components[index] );
		viewMatrix[index] = AutoParm( name );
		std::snprintf( name, sizeof( name ), "inverseViewMatrix%c", components[index] );
		inverseViewMatrix[index] = AutoParm( name );
		std::snprintf( name, sizeof( name ), "modelMatrix%c", components[index] );
		modelMatrix[index] = AutoParm( name );
		std::snprintf( name, sizeof( name ), "inverseModelMatrix%c", components[index] );
		inverseModelMatrix[index] = AutoParm( name );
		std::snprintf( name, sizeof( name ), "projectionMatrix%c", components[index] );
		projectionMatrix[index] = AutoParm( name );
		std::snprintf( name, sizeof( name ), "inverseProjectionMatrix%c", components[index] );
		inverseProjectionMatrix[index] = AutoParm( name );
		std::snprintf( name, sizeof( name ), "mvpMatrix%c", components[index] );
		mvpMatrix[index] = AutoParm( name );
		std::snprintf( name, sizeof( name ), "worldSpaceInverseMVPMatrix%c", components[index] );
		worldSpaceInverseMVPMatrix[index] = AutoParm( name );
	}

#define LOAD_AUTO_PARM( member ) member = AutoParm( #member )
	LOAD_AUTO_PARM( If );
	LOAD_AUTO_PARM( Time );
	LOAD_AUTO_PARM( Color );
	LOAD_AUTO_PARM( coverage );
	LOAD_AUTO_PARM( modelFade );
	LOAD_AUTO_PARM( useSkinBlending );
	LOAD_AUTO_PARM( exposure );
	LOAD_AUTO_PARM( TimeScale );
	LOAD_AUTO_PARM( TimeOffset );
	LOAD_AUTO_PARM( TimeStop );
	LOAD_AUTO_PARM( Diversity );
	LOAD_AUTO_PARM( Wind );
	LOAD_AUTO_PARM( NoShadows );
	LOAD_AUTO_PARM( polygonOffset );
	LOAD_AUTO_PARM( lightColor );
	LOAD_AUTO_PARM( lightScale );
	LOAD_AUTO_PARM( lightProjectMap );
	LOAD_AUTO_PARM( lightFalloffMap );
	LOAD_AUTO_PARM( globalViewOrigin );
	LOAD_AUTO_PARM( globalViewFwd );
	LOAD_AUTO_PARM( globalViewLeft );
	LOAD_AUTO_PARM( globalViewUp );
	LOAD_AUTO_PARM( stageProgram );
	LOAD_AUTO_PARM( interactionProgram );
	LOAD_AUTO_PARM( shadowProgram );
	LOAD_AUTO_PARM( depthFillProgram );
	LOAD_AUTO_PARM( addProgram );
	LOAD_AUTO_PARM( blendProgram );
	LOAD_AUTO_PARM( stageSort );
	LOAD_AUTO_PARM( sortCoverage );
	LOAD_AUTO_PARM( sortSkybox );
	LOAD_AUTO_PARM( sortBackground );
	LOAD_AUTO_PARM( sortEmit );
	LOAD_AUTO_PARM( sortEmitOnly );
	LOAD_AUTO_PARM( sortLight );
	LOAD_AUTO_PARM( sortDecal );
	LOAD_AUTO_PARM( sortTransSort );
	LOAD_AUTO_PARM( sortTrans );
	LOAD_AUTO_PARM( sortWater );
	LOAD_AUTO_PARM( sortPerturber );
	LOAD_AUTO_PARM( surfaceFlags );
	LOAD_AUTO_PARM( contentFlags );
	LOAD_AUTO_PARM( toolsFlags );
	LOAD_AUTO_PARM( surfaceType );
	skipSurfaceInfo = AutoParm( "skipSurfaceInfo" );
	LOAD_AUTO_PARM( discrete );
	LOAD_AUTO_PARM( noFragment );
	editorImage = AutoParm( "qer_editorImage" );
	LOAD_AUTO_PARM( editorDraw );
	LOAD_AUTO_PARM( editorAlpha );
	LOAD_AUTO_PARM( powerMip );
	LOAD_AUTO_PARM( diffuseMap );
	LOAD_AUTO_PARM( specularMap );
	LOAD_AUTO_PARM( bumpMap );
	LOAD_AUTO_PARM( powerMap );
	LOAD_AUTO_PARM( coverMap );
	LOAD_AUTO_PARM( virtualTransMap );
	LOAD_AUTO_PARM( transMap );
	LOAD_AUTO_PARM( textureMap );
	LOAD_AUTO_PARM( sMatrix );
	LOAD_AUTO_PARM( tMatrix );
	LOAD_AUTO_PARM( rMatrix );
	LOAD_AUTO_PARM( qMatrix );
	LOAD_AUTO_PARM( select );
	LOAD_AUTO_PARM( virtualMapping );
	LOAD_AUTO_PARM( positionToViewTexture );
	LOAD_AUTO_PARM( renderPositionToViewTexture );
	LOAD_AUTO_PARM( positionToFeedback );
	LOAD_AUTO_PARM( ambientLightColor );
	for ( int index = 0; index < 6; ++index ) {
		std::snprintf( name, sizeof( name ), "channelLight%d", index );
		channelLight[index] = AutoParm( name );
	}
	LOAD_AUTO_PARM( primeLightDir );
	LOAD_AUTO_PARM( primeLightColor );
	LOAD_AUTO_PARM( highlightColor );
	LOAD_AUTO_PARM( landPageFile );
	renderBump = AutoParm( "renderbump" );
	LOAD_AUTO_PARM( stampCovers );
	LOAD_AUTO_PARM( stampScales );
	stampBlendMode = AutoParm( "landStampBlendMode" );
	stampBlendModeNone = AutoParm( "landStampBlendModeNone" );
	LOAD_AUTO_PARM( depthOfField );
	LOAD_AUTO_PARM( radialBlurCenter );
	LOAD_AUTO_PARM( globalBlur );
	LOAD_AUTO_PARM( doubleVision );
#undef LOAD_AUTO_PARM
}
