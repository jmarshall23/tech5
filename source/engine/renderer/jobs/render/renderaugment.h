#pragma once

#include "render_types.h"

struct renderAugmentParms_t {
	const renderSettings_t * settings;
	const idRenderView * renderView;
	const idRenderModelCommitted ** viewAugmentModels;
	int numViewAugmentModels;
	const idDeclRenderProg * progColorParmOnly;
	const idRenderDestination * renderDestDefault;
	const idRenderDestination * renderDestAugment;
};

void RenderAugment( const renderAugmentParms_t * parms );
