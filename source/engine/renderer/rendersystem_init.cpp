#include "rendersystem_local.h"

#include "coderenderparm.h"
#include "declmaterial.h"
#include "declrenderparm.h"
#include "declrenderprog.h"
#include "image.h"
#include "imagemanager.h"
#include "ingamevideo.h"
#include "renderdestination.h"
#include "renderthread.h"
#include "triangles.h"
#include "virtualtexturepreloader.h"
#include "virtualtexturesystem.h"
#include "jobs/render/parmstate.h"

#include <cstring>

idRenderWorld * R_GetNextRenderWorld( idRenderWorld * );
void R_DestroyRenderWorld( idRenderWorld * );

namespace {
	void SetupDrawVert( idDrawVert & vert, const idVec3 & xyz, float s, float t ) {
		vert.xyz = xyz;
		vert.st.Set( s, t );
		vert.SetNormal( idVec3( 0.0f, 0.0f, 1.0f ) );
		vert.SetTangent( idVec3( 1.0f, 0.0f, 0.0f ) );
		vert.SetBiTangent( idVec3( 0.0f, 1.0f, 0.0f ) );
		vert.color[0] = vert.color[1] = vert.color[2] = vert.color[3] = 255;
	}

	idTriangles * MakeUnitSquare() {
		idTriangles * triangles = new idTriangles();
		R_InitTriangles( *triangles );
		triangles->numVerts = 4;
		triangles->numIndexes = 6;
		R_AllocTriangleVerts( *triangles, 4 );
		R_AllocTriangleIndexes( *triangles, 6 );
		SetupDrawVert( triangles->verts[0], idVec3( -1, -1, 0 ), 0, 1 );
		SetupDrawVert( triangles->verts[1], idVec3(  1, -1, 0 ), 1, 1 );
		SetupDrawVert( triangles->verts[2], idVec3(  1,  1, 0 ), 1, 0 );
		SetupDrawVert( triangles->verts[3], idVec3( -1,  1, 0 ), 0, 0 );
		const unsigned short indexes[6] = { 3, 0, 2, 2, 0, 1 };
		std::memcpy( triangles->indexes, indexes, sizeof( indexes ) );
		triangles->bounds[0].Set( -1, -1, 0 );
		triangles->bounds[1].Set( 1, 1, 0 );
		R_UpdateTriangleVertexBuffer( *triangles );
		R_UpdateTriangleIndexBuffer( *triangles );
		return triangles;
	}

	idTriangles * MakeCube( float minimum, float maximum ) {
		idTriangles * triangles = new idTriangles();
		R_InitTriangles( *triangles );
		triangles->numVerts = 8;
		triangles->numIndexes = 36;
		R_AllocTriangleVerts( *triangles, 8 );
		R_AllocTriangleIndexes( *triangles, 36 );
		for ( int corner = 0; corner < 8; ++corner ) SetupDrawVert(
			triangles->verts[corner], idVec3(
				corner & 1 ? maximum : minimum,
				corner & 2 ? maximum : minimum,
				corner & 4 ? maximum : minimum ), corner & 1 ? 1.0f : 0.0f,
			corner & 2 ? 1.0f : 0.0f );
		const unsigned short indexes[36] = {
			0,2,3, 0,3,1, 4,5,7, 4,7,6, 0,1,5, 0,5,4,
			2,6,7, 2,7,3, 0,4,6, 0,6,2, 1,3,7, 1,7,5 };
		std::memcpy( triangles->indexes, indexes, sizeof( indexes ) );
		triangles->bounds[0].Set( minimum, minimum, minimum );
		triangles->bounds[1].Set( maximum, maximum, maximum );
		R_UpdateTriangleVertexBuffer( *triangles );
		R_UpdateTriangleIndexBuffer( *triangles );
		return triangles;
	}

	void FreeShape( idTriangles *& triangles ) {
		if ( triangles == nullptr ) return;
		R_FreeTriangleData( *triangles );
		delete triangles;
		triangles = nullptr;
	}
}

void idRenderSystemLocal::InitUnitSquare() {
	if ( unitSquareTris == nullptr ) unitSquareTris = MakeUnitSquare();
	if ( unitCubeTris == nullptr ) unitCubeTris = MakeCube( -1.0f, 1.0f );
	if ( zeroOneCubeTris == nullptr ) zeroOneCubeTris = MakeCube( 0.0f, 1.0f );
	if ( extrudeBoxTris == nullptr ) extrudeBoxTris = MakeCube( -1.0f, 1.0f );
}

void idRenderSystemLocal::InitRenderTextures() { InitRenderTargets(); }

void idRenderSystemLocal::Init() {
	if ( rendererD3D9.IsInitialized() ) return;
	InitContext();
	if ( !rendererD3D9.IsInitialized() ) { outOfMemory = true; return; }
	wrapperContext_t context;
	context.d3d = rendererD3D9.GetDevice();
	GL_SetWrapperContext( context );
	GL_SetDefaultState();
	globalImages->Init();
	videoManager->Init();
	idCodeRenderParm::ResolveIRenderParmResources();
	renderThreadParmState->Init();
	mtrDefault = static_cast< const idMaterial * >(
		idMaterial::resourceList.Load( "_default", true ) );
	progDepthOnly = static_cast< const idDeclRenderProg * >(
		idDeclRenderProg::resourceList.Load( "depthOnly", true ) );
	progColorOnly = static_cast< const idDeclRenderProg * >(
		idDeclRenderProg::resourceList.Load( "colorOnly", true ) );
	progTextureOnly = static_cast< const idDeclRenderProg * >(
		idDeclRenderProg::resourceList.Load( "textureOnly", true ) );
	progBasicBlend = static_cast< const idDeclRenderProg * >(
		idDeclRenderProg::resourceList.Load( "basicBlend", true ) );
	progOccluderDepthOnly = static_cast< const idDeclRenderProg * >(
		idDeclRenderProg::resourceList.Load( "occluderDepthOnly", true ) );
	progDeferredPointLight = static_cast< const idDeclRenderProg * >(
		idDeclRenderProg::resourceList.Load( "deferredPointLight", true ) );
	progDeferredSpotLight = static_cast< const idDeclRenderProg * >(
		idDeclRenderProg::resourceList.Load( "deferredSpotLight", true ) );
	progDeferredParallelLight = static_cast< const idDeclRenderProg * >(
		idDeclRenderProg::resourceList.Load( "deferredParallelLight", true ) );
	progGlobalFog = static_cast< const idDeclRenderProg * >(
		idDeclRenderProg::resourceList.Load( "globalFog", true ) );
	progPostProcess = static_cast< const idDeclRenderProg * >(
		idDeclRenderProg::resourceList.Load( "postProcess", true ) );
	rpFrameNumber = idDeclRenderParm::FindByName( "frameNumber", true );
	rpViewColor = idDeclRenderParm::FindByName( "viewColor", true );
	virtualTextureSystem.Init();
	virtualTexturePreloader.SpawnThread();
	InitUnitSquare();
	InitRenderTextures();
	InitCommands();
	StartRenderThread();
	outOfMemory = false;
}

void idRenderSystemLocal::Init2() {
	if ( !rendererD3D9.IsInitialized() ) Init();
}

void idRenderSystemLocal::Shutdown() {
	FreeBinkVideo();
	if ( renderThread != nullptr ) {
		renderThread->StopThread( true );
		delete renderThread;
		renderThread = nullptr;
	}
	while ( worlds != nullptr ) {
		idRenderWorld * world = reinterpret_cast< idRenderWorld * >( worlds );
		worlds = reinterpret_cast< idRenderWorldLocal * >( R_GetNextRenderWorld( world ) );
		R_DestroyRenderWorld( world );
	}
	primaryWorld = nullptr;
	delete renderDestDefault; renderDestDefault = nullptr;
	for ( int i = 0; i < 2; ++i ) {
		delete renderDestViewColor[i]; renderDestViewColor[i] = nullptr;
		delete renderDestDistortion[i]; renderDestDistortion[i] = nullptr;
		if ( imgViewColor[i] != nullptr ) imgViewColor[i]->PurgeImage();
		if ( imgDistortion[i] != nullptr ) imgDistortion[i]->PurgeImage();
		imgViewColor[i] = imgDistortion[i] = nullptr;
	}
	delete renderDestViewDepth; renderDestViewDepth = nullptr;
	delete renderDestGui; renderDestGui = nullptr;
	if ( imgViewDepth != nullptr ) imgViewDepth->PurgeImage();
	if ( imgGui != nullptr ) imgGui->PurgeImage();
	imgViewDepth = imgGui = nullptr;
	FreeShape( unitSquareTris );
	FreeShape( unitCubeTris );
	FreeShape( zeroOneCubeTris );
	FreeShape( extrudeBoxTris );
	virtualTexturePreloader.DestroyThread();
	virtualTextureSystem.SyncFeedback();
	virtualTextureSystem.Shutdown();
	videoManager->Shutdown();
	if ( globalImages != nullptr ) globalImages->Shutdown();
	rendererD3D9.Shutdown();
	renderingIsReadyForSwapbuffers = false;
}
