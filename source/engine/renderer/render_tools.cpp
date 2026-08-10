#include "render.h"

#include "renderer_d3d9.h"
#include "rendersystem_local.h"

#include "idlib/color.h"

idColor BrightColorForNumber( const int number ) {
	static const idColor colors[] = {
		idColor( 1, 0, 0 ), idColor( 0, 1, 0 ), idColor( 0, 0, 1 ),
		idColor( 1, 1, 0 ), idColor( 0, 1, 1 ), idColor( 1, 0, 1 ),
		idColor( 1, 0.5f, 0 ), idColor( 0.5f, 0, 1 ) };
	const int index = number < 0 ? -number : number;
	return colors[index % ( sizeof( colors ) / sizeof( colors[0] ) )];
}

void idRender::SimpleWorldSetup() {
	GL_SetRenderDestination( nullptr );
	GL_Viewport( 0, 0, renderSystemLocal.renderWidth, renderSystemLocal.renderHeight );
	GL_Scissor( 0, 0, renderSystemLocal.renderWidth, renderSystemLocal.renderHeight );
}

void idRender::PolygonClear( const idVec4 & color, const unsigned long long state ) {
	GL_State( state, true );
	GL_Clear( true, false, false, 0, color.x, color.y, color.z, color.w );
}

// These recovered inspection gates are intentionally separate methods: tool
// builds can attach their original CVars without changing the render path.
// The runtime-safe PC default leaves each gate disabled.
#define TOOL_GATE(name) void idRender::name() {}
TOOL_GATE( ShowModelGroupMasters )
TOOL_GATE( ShowDestinationAlpha )
TOOL_GATE( ShowIntensity )
TOOL_GATE( ShowDepthBuffer )
TOOL_GATE( ShowCracks )
TOOL_GATE( ShowLights )
TOOL_GATE( ShowEnvironments )
TOOL_GATE( ColorByStencilBuffer )
TOOL_GATE( ShowLightCount )
TOOL_GATE( ShowTransparencySortOverdraw )
TOOL_GATE( ShowViewModels )
TOOL_GATE( ShowSurfaceBounds )
TOOL_GATE( ShowOcclusionBaseModel )
TOOL_GATE( ShowGamma )
TOOL_GATE( ShowGammaBias )
TOOL_GATE( ShowTextureReconstruct )
TOOL_GATE( ShowGammaCalibrationTest )
TOOL_GATE( ShowLoadedImages )
TOOL_GATE( ShowTestImage )
TOOL_GATE( ShowTestVMTR )
TOOL_GATE( ShowTris )
TOOL_GATE( ShowTwoSided )
TOOL_GATE( ShowBlendedSurfaces )
TOOL_GATE( ShowBlendedSurfaceOverdraw )
TOOL_GATE( ShowTrace )
TOOL_GATE( ShowTangentSpace )
TOOL_GATE( ShowTextureSpace )
TOOL_GATE( ShowTextureDistortion )
TOOL_GATE( ShowVertexColor )
TOOL_GATE( ShowGlobalShadows )
TOOL_GATE( ShowAutosprite )
TOOL_GATE( ShowSurfaceInfo )
TOOL_GATE( ShowModelLightingInfo )
#undef TOOL_GATE

void idRender::RenderDebugTools() {
	if ( rendererD3D9.GetDevice() == nullptr || renderViewObject == nullptr ) return;
	ShowModelGroupMasters();
	ShowDestinationAlpha();
	ShowIntensity();
	ShowDepthBuffer();
	ShowCracks();
	ShowLights();
	ShowSurfaceBounds();
	ShowTris();
	ShowTrace();
	ShowSurfaceInfo();
	RenderDebugTools_NonPortable();
}
