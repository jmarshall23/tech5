#pragma once

#include "render_types.h"

struct renderGodRaysParms_t {
	const renderSettings_t * settings;
	const idRenderView * renderView;
	const idDeclRenderProg * progCreateGodRays;
	const idDeclRenderProg * progDrawGodRays;
	const idRenderDestination * renderDestDefault;
	const idRenderDestination * renderDestOffScreen;
	const idImage * imgOffScreen;
	const idTriangles * unitSquareTris;
	bool godRaysRelativeToCamera;
	idVec3 godRaysPosition;
	float godRaysSize;
	float godRaysSourceSize;
	idVec3 godRaysColor;
	const idMaterial * godRaysMaterial;
	const idDeclRenderParm * rpGodRayMap;
	const idDeclRenderParm * rpScaleBiasQuad;
	const idDeclRenderParm * rpScaleBiasSource;
	const idDeclRenderParm * rpGodRaysColor;
	const idDeclRenderParm * rpTransMap;
};

void RenderGodRays( const renderGodRaysParms_t * parms );
