#include "renderdynamicenv.h"

#include "../../declrenderparm.h"
#include "../../renderdestination.h"
#include "../../renderer_d3d9.h"
#include "parmstate.h"

#include <algorithm>

namespace {
	void SetValue( const idDeclRenderParm * parm, const parmValue_t & value ) {
		if ( parm != nullptr && renderThreadParmState != nullptr )
			renderThreadParmState->SetParmValue( parm->parmIndex, value );
	}
}

void RenderDynamicEnv( const renderDynamicEnvParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->settings->skipDynamic || parms->renderDestDynamicEnv == nullptr ||
			parms->unitCubeTris == nullptr || parms->progBlend == nullptr ) return;
	parmValue_t value = {};
	value.image = parms->imgAmbientEnv;
	SetValue( parms->rpAmbientEnvMap, value );
	value.image = parms->imgUserEnv;
	SetValue( parms->rpUserEnvMap, value );
	float blend = 1.0f;
	if ( parms->envBlend != nullptr && parms->envBlend->blendDuration > 0.0f )
		blend = std::max( 0.0f, std::min( 1.0f,
			( parms->renderView->r.renderTime - parms->envBlend->blendStartTime ) /
				parms->envBlend->blendDuration ) );
	value = {};
	value.value[0] = blend;
	SetValue( parms->rpEnvBlendMip, value );
	const idDeclRenderParm * rows[3] = { parms->rpEnvSMatrix,
		parms->rpEnvTMatrix, parms->rpEnvRMatrix };
	for ( int row = 0; row < 3; ++row ) {
		value = {};
		value.value[0] = parms->envMapRotation[row].x;
		value.value[1] = parms->envMapRotation[row].y;
		value.value[2] = parms->envMapRotation[row].z;
		SetValue( rows[row], value );
	}
	for ( int face = 0; face < 6; ++face ) {
		GL_SetRenderDestination( parms->renderDestDynamicEnv, face, 0 );
		GL_Viewport( 0, 0, parms->renderDestDynamicEnv->targetWidth,
			parms->renderDestDynamicEnv->targetHeight );
		GL_Scissor( 0, 0, parms->renderDestDynamicEnv->targetWidth,
			parms->renderDestDynamicEnv->targetHeight );
		GL_DrawElements( parms->progBlend, parms->unitCubeTris,
			GLS_DEPTHMASK | GLS_CULL_TWOSIDED, false );
	}
	if ( parms->envBlend != nullptr ) parms->envBlend->cubeFinished = true;
}
