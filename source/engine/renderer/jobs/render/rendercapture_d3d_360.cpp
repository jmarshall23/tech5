#include "rendercapture.h"

#include "../../bufferobject.h"
#include "../../declrenderparm.h"
#include "../../declrenderprog.h"
#include "../../image.h"
#include "../../renderdestination.h"
#include "../../renderer_d3d9.h"
#include "parmstate.h"

#include <algorithm>
#include <cstring>

namespace {
	void SetImageParm( const idDeclRenderParm * parm, const idImage * image ) {
		if ( parm == nullptr || renderThreadParmState == nullptr ) return;
		parmValue_t value = {};
		value.image = image;
		renderThreadParmState->SetParmValue( parm->parmIndex, value );
	}

	IDirect3DSurface9 * ImageSurface( const idImage * image, int level ) {
		if ( image == nullptr || image->GetTexture() == nullptr ||
				image->GetTexture()->GetType() != D3DRTYPE_TEXTURE ) return nullptr;
		IDirect3DSurface9 * surface = nullptr;
		static_cast< IDirect3DTexture9 * >( image->GetTexture() )
			->GetSurfaceLevel( level, &surface );
		return surface;
	}

	void RestoreDefault( const captureParms_t * parms ) {
		GL_SetRenderDestination( parms->renderDestDefault );
		GL_Viewport( 0, 0, parms->renderWidth, parms->renderHeight );
		GL_Scissor( 0, 0, parms->renderWidth, parms->renderHeight );
		if ( renderThreadParmState != nullptr )
			renderThreadParmState->SetPositionToViewTexture(
				parms->windowWidth, parms->windowHeight,
				parms->renderWidth, parms->renderHeight );
	}
}

void CaptureViewDepth( const captureParms_t * parms ) {
	if ( parms == nullptr || parms->imgViewDepth == nullptr ) return;
	IDirect3DDevice9 * const device = rendererD3D9.GetDevice();
	if ( device == nullptr ) return;
	IDirect3DSurface9 * source = nullptr;
	IDirect3DSurface9 * destination = ImageSurface( parms->imgViewDepth, 0 );
	if ( SUCCEEDED( device->GetDepthStencilSurface( &source ) ) &&
			destination != nullptr ) {
		D3DSURFACE_DESC sourceDesc = {}, destinationDesc = {};
		source->GetDesc( &sourceDesc );
		destination->GetDesc( &destinationDesc );
		// Standard D3D9 cannot sample or convert an ordinary depth-stencil
		// surface into R32F.  Only take the direct-copy path when the driver
		// exposes matching formats (for example INTZ-compatible resources).
		if ( sourceDesc.Format == destinationDesc.Format )
			device->StretchRect( source, nullptr, destination, nullptr, D3DTEXF_NONE );
	}
	D3D9Release( source );
	D3D9Release( destination );
}

void CreateColorMips( const captureParms_t * parms,
		const idRenderDestination * destination ) {
	if ( parms == nullptr || destination == nullptr ||
			destination->targetImage[0] == nullptr ) return;
	IDirect3DDevice9 * const device = rendererD3D9.GetDevice();
	idImage * const image = destination->targetImage[0];
	if ( device == nullptr || image->GetTexture() == nullptr ||
			image->GetTexture()->GetType() != D3DRTYPE_TEXTURE ) return;
	IDirect3DTexture9 * const texture =
		static_cast< IDirect3DTexture9 * >( image->GetTexture() );
	const DWORD levels = texture->GetLevelCount();
	for ( DWORD level = 1; level < levels; ++level ) {
		IDirect3DSurface9 * source = nullptr;
		IDirect3DSurface9 * target = nullptr;
		if ( SUCCEEDED( texture->GetSurfaceLevel( level - 1, &source ) ) &&
				SUCCEEDED( texture->GetSurfaceLevel( level, &target ) ) ) {
			HRESULT result = device->StretchRect( source, nullptr, target, nullptr,
				D3DTEXF_LINEAR );
			if ( FAILED( result ) ) {
				D3DSURFACE_DESC sourceDesc = {};
				source->GetDesc( &sourceDesc );
				IDirect3DSurface9 * temporary = nullptr;
				if ( SUCCEEDED( device->CreateRenderTarget( sourceDesc.Width,
						sourceDesc.Height, sourceDesc.Format, D3DMULTISAMPLE_NONE, 0,
						FALSE, &temporary, nullptr ) ) ) {
					if ( SUCCEEDED( device->StretchRect( source, nullptr, temporary,
							nullptr, D3DTEXF_NONE ) ) )
						device->StretchRect( temporary, nullptr, target, nullptr,
							D3DTEXF_LINEAR );
				}
				D3D9Release( temporary );
			}
		}
		D3D9Release( source );
		D3D9Release( target );
	}
	RestoreDefault( parms );
}

void CaptureViewColor( const captureParms_t * parms ) {
	if ( parms == nullptr || parms->renderDestViewColor == nullptr ) return;
	GL_SetRenderDestination( parms->renderDestDefault );
	GL_ResolveTarget( RESOLVE_TARGET_COLOR0, parms->renderDestViewColor );
	if ( parms->createMipMaps )
		CreateColorMips( parms, parms->renderDestViewColor );
}

void CaptureFeedback( const captureParms_t * parms ) {
	if ( parms == nullptr || parms->settings == nullptr ||
			parms->settings->skipFeedback ||
			parms->renderDestFeedback == nullptr ) return;
	CaptureViewColor( parms );
	const int numViews = std::max( parms->settings->numViews, 1 );
	const int viewHeight = 128 / numViews;
	parms->renderDestFeedback->Resize( 160, 128 );
	GL_SetRenderDestination( parms->renderDestFeedback );
	GL_Viewport( 0, parms->viewIndex * viewHeight, 160, viewHeight );
	GL_Scissor( 0, parms->viewIndex * viewHeight, 160, viewHeight );
	if ( renderThreadParmState != nullptr )
		renderThreadParmState->SetPositionToViewTexture(
			160, viewHeight, 160, viewHeight );
	SetImageParm( parms->rpViewColor,
		parms->renderDestViewColor != nullptr
			? parms->renderDestViewColor->targetImage[0] : nullptr );
	if ( parms->progFeedbackDownSample != nullptr &&
			parms->unitSquareTris != nullptr )
		GL_DrawElements( parms->progFeedbackDownSample,
			parms->unitSquareTris, 0, false );

	if ( parms->viewIndex == numViews - 1 &&
			parms->feedbackBufferObject != nullptr ) {
		IDirect3DDevice9 * const device = rendererD3D9.GetDevice();
		IDirect3DSurface9 * source =
			parms->renderDestFeedback->AcquireTargetSurface( 0, 0, 0 );
		idPixelPackBuffer * const pack = parms->feedbackBufferObject;
		if ( pack->apiObject == nullptr || pack->size != 160 * 128 * 4 ) {
			R_FreePixelPackBuffer( *pack );
			IDirect3DSurface9 * readback = nullptr;
			if ( device != nullptr ) device->CreateOffscreenPlainSurface(
				160, 128, D3DFMT_A8R8G8B8, D3DPOOL_SYSTEMMEM,
				&readback, nullptr );
			pack->apiObject = readback;
			pack->size = readback != nullptr ? 160 * 128 * 4 : 0;
		}
		IDirect3DSurface9 * const readback =
			static_cast< IDirect3DSurface9 * >( pack->apiObject );
		if ( device != nullptr && source != nullptr && readback != nullptr &&
				SUCCEEDED( device->GetRenderTargetData( source, readback ) ) &&
				parms->feedbackBuffer != nullptr ) {
			D3DLOCKED_RECT lock = {};
			if ( SUCCEEDED( readback->LockRect( &lock, nullptr, D3DLOCK_READONLY ) ) ) {
				for ( int row = 0; row < 128; ++row )
					std::memcpy( static_cast< unsigned char * >(
						parms->feedbackBuffer ) + row * 160 * 4,
						static_cast< const unsigned char * >( lock.pBits ) +
							row * lock.Pitch, 160 * 4 );
				readback->UnlockRect();
			}
		}
		D3D9Release( source );
	}
	if ( parms->forceFullVirtualTextureLoad ) GL_Finish();
	RestoreDefault( parms );
}

void CaptureGlareMap( const captureParms_t * parms ) {
	if ( parms == nullptr || parms->renderDestMip3 == nullptr ) return;
	CaptureViewColor( parms );
	GL_SetRenderDestination( parms->renderDestMip3 );
	GL_Viewport( 0, 0, parms->renderDestMip3->targetWidth,
		parms->renderDestMip3->targetHeight );
	GL_Scissor( 0, 0, parms->renderDestMip3->targetWidth,
		parms->renderDestMip3->targetHeight );
	SetImageParm( parms->rpGlareMap,
		parms->renderDestViewColor != nullptr
			? parms->renderDestViewColor->targetImage[0] : nullptr );
	if ( parms->progGlareScale != nullptr && parms->unitSquareTris != nullptr )
		GL_DrawElements( parms->progGlareScale, parms->unitSquareTris, 0, false );
	GL_ResolveTarget( RESOLVE_TARGET_COLOR0, parms->renderDestMip3 );
	RestoreDefault( parms );
}

void CaptureGuiImage( const captureParms_t * parms ) {
	if ( parms == nullptr || parms->renderDestGui == nullptr ) return;
	GL_ResolveTarget( RESOLVE_TARGET_COLOR0, parms->renderDestGui );
	CreateColorMips( parms, parms->renderDestGui );
}
