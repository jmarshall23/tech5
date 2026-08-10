#include "transcode.h"

// The Xenon build used a VMX-specialized direct-copy job.  D3D9 consumes the
// same BC1/BC3 byte layout, so the recovered entry point uses the portable
// dispatcher and retains its fast path.
void TranscodePage_DXT_DXT( const transcodeParms_t * parms ) {
	TranscodePage( parms );
}
