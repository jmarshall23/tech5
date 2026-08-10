#include "renderdestination.h"

#include "image.h"

#include <algorithm>
#include <cstring>

// PDB-authentic filename retained; implementation translated to Windows D3D9.

idRenderDestination::idRenderDestination() : isDefault( false ), targetWidth( -1 ),
	targetHeight( -1 ), depthImage( nullptr ), stencilImage( nullptr ),
	depthSurface( nullptr ) {
	std::memset( targetImage, 0, sizeof( targetImage ) );
	std::memset( targetSurface, 0, sizeof( targetSurface ) );
}

idRenderDestination::~idRenderDestination() {
	ReleaseSurfaces();
}

void idRenderDestination::ReleaseSurfaces() {
	for ( IDirect3DSurface9 *& surface : targetSurface ) D3D9Release( surface );
	D3D9Release( depthSurface );
}

IDirect3DSurface9 * idRenderDestination::AcquireTargetSurface( int target,
		int face, int mipLevel ) const {
	if ( target < 0 || target >= 4 ) return nullptr;
	if ( targetSurface[target] != nullptr ) {
		targetSurface[target]->AddRef();
		return targetSurface[target];
	}
	idImage * image = targetImage[target];
	if ( image == nullptr || image->GetTexture() == nullptr ) return nullptr;
	IDirect3DSurface9 * surface = nullptr;
	if ( image->opts.textureType == TT_CUBIC ) {
		static_cast< IDirect3DCubeTexture9 * >( image->GetTexture() )->GetCubeMapSurface(
			static_cast< D3DCUBEMAP_FACES >( face ), mipLevel, &surface );
	} else if ( image->opts.textureType == TT_2D ) {
		static_cast< IDirect3DTexture9 * >( image->GetTexture() )->GetSurfaceLevel(
			mipLevel, &surface );
	}
	return surface;
}

IDirect3DSurface9 * idRenderDestination::AcquireDepthSurface( int mipLevel ) const {
	if ( depthSurface != nullptr ) {
		depthSurface->AddRef();
		return depthSurface;
	}
	if ( depthImage == nullptr || depthImage->GetTexture() == nullptr ||
			depthImage->opts.textureType != TT_2D ) return nullptr;
	IDirect3DSurface9 * surface = nullptr;
	static_cast< IDirect3DTexture9 * >( depthImage->GetTexture() )->GetSurfaceLevel(
		mipLevel, &surface );
	return surface;
}

void idRenderDestination::AddTarget( idImage * target,
		IDirect3DSurface9 * surface ) {
	for ( int index = 0; index < 4; ++index ) {
		if ( targetImage[index] == nullptr && targetSurface[index] == nullptr ) {
			targetImage[index] = target;
			targetSurface[index] = surface;
			if ( surface != nullptr ) surface->AddRef();
			return;
		}
	}
}

void idRenderDestination::Resize( int width, int height ) {
	targetWidth = std::max( width, 1 );
	targetHeight = std::max( height, 1 );
	ReleaseSurfaces();
	for ( idImage * image : targetImage ) {
		if ( image != nullptr ) image->Resize( targetWidth, targetHeight, 1 );
	}
	if ( depthImage != nullptr ) depthImage->Resize( targetWidth, targetHeight, 1 );
}

void idRenderDestination::CreateFromImages( idImage * color, idImage * depth,
		idImage * stencil, IDirect3DSurface9 * colorTargetSurface,
		IDirect3DSurface9 * depthTargetSurface ) {
	ReleaseSurfaces();
	std::memset( targetImage, 0, sizeof( targetImage ) );
	targetImage[0] = color;
	depthImage = depth;
	stencilImage = stencil;
	targetSurface[0] = colorTargetSurface;
	depthSurface = depthTargetSurface;
	if ( targetSurface[0] != nullptr ) targetSurface[0]->AddRef();
	if ( depthSurface != nullptr ) depthSurface->AddRef();

	if ( color != nullptr ) {
		targetWidth = color->opts.width;
		targetHeight = color->opts.height;
	} else if ( depth != nullptr ) {
		targetWidth = depth->opts.width;
		targetHeight = depth->opts.height;
	} else {
		IDirect3DSurface9 * source = colorTargetSurface != nullptr ?
			colorTargetSurface : depthTargetSurface;
		D3DSURFACE_DESC description = {};
		if ( source != nullptr && SUCCEEDED( source->GetDesc( &description ) ) ) {
			targetWidth = static_cast< int >( description.Width );
			targetHeight = static_cast< int >( description.Height );
		}
	}
}

bool idRenderDestination::Bind( int face, int mipLevel ) const {
	IDirect3DDevice9 * device = rendererD3D9.GetDevice();
	if ( device == nullptr ) return false;
	if ( isDefault ) {
		IDirect3DSurface9 * color = nullptr;
		IDirect3DSurface9 * depth = nullptr;
		const HRESULT colorResult = device->GetBackBuffer( 0, 0,
			D3DBACKBUFFER_TYPE_MONO, &color );
		device->GetDepthStencilSurface( &depth );
		if ( SUCCEEDED( colorResult ) ) device->SetRenderTarget( 0, color );
		for ( int target = 1; target < 4; ++target )
			device->SetRenderTarget( target, nullptr );
		device->SetDepthStencilSurface( depth );
		D3D9Release( color );
		D3D9Release( depth );
		return SUCCEEDED( colorResult );
	}
	bool boundColor = false;
	for ( int index = 0; index < 4; ++index ) {
		IDirect3DSurface9 * surface = AcquireTargetSurface( index, face, mipLevel );
		if ( surface != nullptr || index == 0 ) {
			if ( FAILED( device->SetRenderTarget( index, surface ) ) ) {
				D3D9Release( surface );
				return false;
			}
			boundColor |= surface != nullptr;
		}
		D3D9Release( surface );
	}
	IDirect3DSurface9 * depth = AcquireDepthSurface( mipLevel );
	device->SetDepthStencilSurface( depth );
	D3D9Release( depth );
	return boundColor || depthImage != nullptr || depthSurface != nullptr;
}
