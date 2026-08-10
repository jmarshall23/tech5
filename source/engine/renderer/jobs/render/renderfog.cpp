#include "renderfog.h"

#include "../../renderer_d3d9.h"

void RenderFog( const renderFogParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->settings->skipFog || parms->progGlobalFog == nullptr ||
			parms->unitSquareTris == nullptr ) return;
	GL_DrawElements( parms->progGlobalFog, parms->unitSquareTris,
		GLS_DEPTHMASK, false );
}
