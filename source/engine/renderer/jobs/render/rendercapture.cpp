#include "rendercapture.h"

void RenderCapture( const captureParms_t * parms ) {
	if ( parms == nullptr ) return;
	switch ( parms->capture ) {
		case CAPTURE_VIEW_DEPTH: CaptureViewDepth( parms ); break;
		case CAPTURE_FEEDBACK: CaptureFeedback( parms ); break;
		case CAPTURE_GLARE_MAP: CaptureGlareMap( parms ); break;
		case CAPTURE_GUI_IMAGE: CaptureGuiImage( parms ); break;
		case CAPTURE_VIEW_COLOR: CaptureViewColor( parms ); break;
		default: break;
	}
}
