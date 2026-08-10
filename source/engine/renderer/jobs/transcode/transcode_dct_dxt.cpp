#include "transcode.h"

void TranscodePage_DCT_DXT( const transcodeParms_t * parms ) {
	TranscodePage( parms );
}

void TestPerformance_DCT_DXT( const transcodeParms_t * parms ) {
	TranscodePage_DCT_DXT( parms );
}
