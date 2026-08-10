#include "renderpostprocess.h"

#include "../../declrenderparm.h"
#include "../../renderer_d3d9.h"
#include "parmstate.h"

namespace {
	void SetImage( const idDeclRenderParm * parm, const idImage * image ) {
		if ( parm == nullptr || renderThreadParmState == nullptr ) return;
		parmValue_t value = {};
		value.image = image;
		renderThreadParmState->SetParmValue( parm->parmIndex, value );
	}
}

void RenderPostProcess( const renderPostProcessParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->settings->skipPostProcess || parms->progPostProcess == nullptr ||
			parms->unitSquareTris == nullptr ) return;
	SetImage( parms->rpViewColor, parms->imgViewColor );
	SetImage( parms->rpGlareMap, parms->imgGlare );
	SetImage( parms->rpAdaptiveGlareMap, parms->imgAdaptiveGlare );
	SetImage( parms->rpAdaptiveGlareLuminance,
		parms->imgAdaptiveGlareLuminance );
	SetImage( parms->rpDistortionMap, parms->imgDistortion );
	GL_DrawElements( parms->progPostProcess, parms->unitSquareTris,
		GLS_DEPTHMASK | GLS_CULL_TWOSIDED, false );
}
