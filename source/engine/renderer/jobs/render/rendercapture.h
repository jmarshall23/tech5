#pragma once

#include "render_types.h"

void RenderCapture( const captureParms_t * parms );
void CaptureViewDepth( const captureParms_t * parms );
void CreateColorMips( const captureParms_t * parms,
	const idRenderDestination * source );
void CaptureViewColor( const captureParms_t * parms );
void CaptureFeedback( const captureParms_t * parms );
void CaptureGlareMap( const captureParms_t * parms );
void CaptureGuiImage( const captureParms_t * parms );
