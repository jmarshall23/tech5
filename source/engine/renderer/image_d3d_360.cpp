#include "image.h"

#include "imagedata.h"
#include "renderer_d3d9.h"

#include <algorithm>
#include <cstring>

// PDB-authentic filename retained; implementation translated to Windows D3D9.

namespace {
DWORD ImageFloatBits( float value ) {
	DWORD bits = 0;
	std::memcpy( &bits, &value, sizeof( bits ) );
	return bits;
}
}

D3DFORMAT D3DFMT_FromOpts( const idImageOpts & opts ) {
	switch ( opts.format ) {
		case FMT_RGBA32F: return D3DFMT_A32B32G32R32F;
		case FMT_RGBA16F: return D3DFMT_A16B16G16R16F;
		case FMT_RGBA8: return D3DFMT_A8B8G8R8;
		case FMT_ARGB8: return D3DFMT_A8R8G8B8;
		case FMT_ALPHA: return D3DFMT_A8;
		case FMT_L8A8: return D3DFMT_A8L8;
		case FMT_RG8: return D3DFMT_A8L8;
		case FMT_LUM8:
		case FMT_INT8: return D3DFMT_L8;
		case FMT_DXT1: return D3DFMT_DXT1;
		case FMT_DXT5: return D3DFMT_DXT5;
		case FMT_DEPTH: return D3DFMT_D24X8;
		case FMT_DEPTH_STENCIL: return D3DFMT_D24S8;
		case FMT_X32F: return D3DFMT_R32F;
		case FMT_Y16F_X16F: return D3DFMT_G16R16F;
		case FMT_X16: return D3DFMT_L16;
		case FMT_Y16_X16: return D3DFMT_G16R16;
		case FMT_RGB565: return D3DFMT_R5G6B5;
		default: return D3DFMT_UNKNOWN;
	}
}

void idImage::Resize( int width, int height, int depth ) {
	idImageOpts resized = opts;
	resized.width = std::max( width, 1 );
	resized.height = std::max( height, 1 );
	resized.depth = std::max( depth, 1 );
	if ( resized.width == opts.width && resized.height == opts.height &&
			resized.depth == opts.depth && d3dTexture != nullptr ) return;
	resized.numLevels = 0;
	ComputeNumLevels( resized, GetName() );
	const bool wasRenderTarget = d3dRenderTarget;
	PurgeImage();
	if ( wasRenderTarget ) AllocRenderTarget( resized );
	else AllocImage( resized );
}

void idImage::DetermineSamplerStateFromOpts() {
	switch ( opts.filter ) {
		case TF_NEAREST:
			samplerMagFilter = samplerMinFilter = D3DTEXF_POINT;
			samplerMipFilter = D3DTEXF_NONE;
			break;
		case TF_NEAREST_MIPMAP_NEAREST:
			samplerMagFilter = samplerMinFilter = samplerMipFilter = D3DTEXF_POINT;
			break;
		case TF_LINEAR_MIPMAP_NEAREST:
			samplerMagFilter = samplerMinFilter = D3DTEXF_LINEAR;
			samplerMipFilter = D3DTEXF_POINT;
			break;
		case TF_TRILINEAR_NO_ANISO:
			samplerMagFilter = samplerMinFilter = samplerMipFilter = D3DTEXF_LINEAR;
			break;
		default:
			samplerMagFilter = D3DTEXF_LINEAR;
			samplerMinFilter = opts.aniso > 1.0f ? D3DTEXF_ANISOTROPIC : D3DTEXF_LINEAR;
			samplerMipFilter = opts.numLevels > 1 ? D3DTEXF_LINEAR : D3DTEXF_NONE;
			break;
	}
	const D3DCAPS9 caps = rendererD3D9.Caps();
	samplerMaxAnisotropy = static_cast< int >( std::max( 1.0f,
		std::min( opts.aniso, static_cast< float >( std::max< DWORD >( caps.MaxAnisotropy, 1 ) ) ) ) );
	samplerMipMapLodBias = static_cast< int >( ImageFloatBits( opts.lodBias ) );
	samplerMaxMipLevel = static_cast< int >( std::max( opts.lodMinClamp, 0.0f ) );
	samplerMinMipLevel = static_cast< int >( std::max( opts.lodMaxClamp, 0.0f ) );
	samplerBorderColor = D3DCOLOR_COLORVALUE( opts.border.x, opts.border.y,
		opts.border.z, opts.border.w );
	D3DTEXTUREADDRESS addressU = D3DTADDRESS_WRAP;
	D3DTEXTUREADDRESS addressV = D3DTADDRESS_WRAP;
	switch ( opts.repeat ) {
		case TR_CLAMP: addressU = addressV = D3DTADDRESS_CLAMP; break;
		case TR_CLAMP_S: addressU = D3DTADDRESS_CLAMP; break;
		case TR_CLAMP_T: addressV = D3DTADDRESS_CLAMP; break;
		case TR_CLAMP_TO_BORDER: addressU = addressV = D3DTADDRESS_BORDER; break;
		case TR_MIRROR: addressU = addressV = D3DTADDRESS_MIRROR; break;
		default: break;
	}
	samplerAddressU = addressU;
	samplerAddressV = addressV;
	samplerAddressW = opts.repeat == TR_MIRROR ? D3DTADDRESS_MIRROR :
		( opts.repeat == TR_REPEAT ? D3DTADDRESS_WRAP : D3DTADDRESS_CLAMP );
}

bool idImage::AllocImage( const idImageOpts & imageOpts ) {
	IDirect3DDevice9 * device = rendererD3D9.GetDevice();
	if ( device == nullptr ) {
		allocationFailed = true;
		return false;
	}
	PurgeImage();
	d3dRenderTarget = false;
	opts = imageOpts;
	opts.width = std::max( opts.width, 1 );
	opts.height = std::max( opts.height, 1 );
	opts.depth = std::max( opts.depth, 1 );
	ComputeNumLevels( opts, GetName() );
	d3dFormat = D3DFMT_FromOpts( opts );
	if ( d3dFormat == D3DFMT_UNKNOWN ) {
		allocationFailed = true;
		return false;
	}

	DWORD usage = 0;
	D3DPOOL pool = D3DPOOL_MANAGED;
	if ( opts.format == FMT_DEPTH || opts.format == FMT_DEPTH_STENCIL ) {
		usage = D3DUSAGE_DEPTHSTENCIL;
		pool = D3DPOOL_DEFAULT;
	} else if ( opts.readback ) {
		pool = D3DPOOL_SYSTEMMEM;
	} else if ( opts.linear ) {
		usage = D3DUSAGE_DYNAMIC;
		pool = D3DPOOL_DEFAULT;
	}

	HRESULT result = E_FAIL;
	const UINT levels = static_cast< UINT >( std::max( opts.numLevels, 1 ) );
	if ( opts.textureType == TT_CUBIC ) {
		IDirect3DCubeTexture9 * texture = nullptr;
		result = device->CreateCubeTexture( opts.width, levels, usage, d3dFormat,
			pool, &texture, nullptr );
		d3dTexture = texture;
	} else if ( opts.textureType == TT_3D ) {
		IDirect3DVolumeTexture9 * texture = nullptr;
		result = device->CreateVolumeTexture( opts.width, opts.height, opts.depth,
			levels, usage, d3dFormat, pool, &texture, nullptr );
		d3dTexture = texture;
	} else {
		IDirect3DTexture9 * texture = nullptr;
		result = device->CreateTexture( opts.width, opts.height, levels, usage,
			d3dFormat, pool, &texture, nullptr );
		d3dTexture = texture;
	}
	allocationFailed = FAILED( result );
	if ( allocationFailed ) {
		D3D9Release( d3dTexture );
		return false;
	}
	allocWidth = opts.width;
	allocHeight = opts.height;
	optsHasBeenSet = true;
	DetermineSamplerStateFromOpts();
	physicalMemoryBytes = StorageSize();
	return true;
}

bool idImage::AllocRenderTarget( const idImageOpts & imageOpts ) {
	IDirect3DDevice9 * const device = rendererD3D9.GetDevice();
	if ( device == nullptr ) {
		allocationFailed = true;
		return false;
	}
	PurgeImage();
	opts = imageOpts;
	opts.width = std::max( opts.width, 1 );
	opts.height = std::max( opts.height, 1 );
	opts.depth = 1;
	if ( opts.textureType == TT_3D || opts.format == FMT_DEPTH ||
			opts.format == FMT_DEPTH_STENCIL || opts.readback ) {
		allocationFailed = true;
		return false;
	}
	ComputeNumLevels( opts, GetName() );
	d3dFormat = D3DFMT_FromOpts( opts );
	if ( d3dFormat == D3DFMT_UNKNOWN ) {
		allocationFailed = true;
		return false;
	}
	const UINT levels = static_cast< UINT >( std::max( opts.numLevels, 1 ) );
	HRESULT result = E_FAIL;
	if ( opts.textureType == TT_CUBIC ) {
		IDirect3DCubeTexture9 * texture = nullptr;
		result = device->CreateCubeTexture( opts.width, levels,
			D3DUSAGE_RENDERTARGET, d3dFormat, D3DPOOL_DEFAULT,
			&texture, nullptr );
		d3dTexture = texture;
	} else {
		IDirect3DTexture9 * texture = nullptr;
		result = device->CreateTexture( opts.width, opts.height, levels,
			D3DUSAGE_RENDERTARGET, d3dFormat, D3DPOOL_DEFAULT,
			&texture, nullptr );
		d3dTexture = texture;
	}
	allocationFailed = FAILED( result );
	if ( allocationFailed ) {
		D3D9Release( d3dTexture );
		return false;
	}
	d3dRenderTarget = true;
	allocWidth = opts.width;
	allocHeight = opts.height;
	optsHasBeenSet = true;
	DetermineSamplerStateFromOpts();
	physicalMemoryBytes = StorageSize();
	return true;
}

void idImage::PurgeImage() {
	IDirect3DDevice9 * device = rendererD3D9.GetDevice();
	if ( device != nullptr ) {
		for ( DWORD unit = 0; unit < 16; ++unit ) {
			IDirect3DBaseTexture9 * bound = nullptr;
			if ( SUCCEEDED( device->GetTexture( unit, &bound ) ) ) {
				if ( bound == d3dTexture ) device->SetTexture( unit, nullptr );
				D3D9Release( bound );
			}
		}
	}
	D3D9Release( d3dTexture );
	delete[] static_cast< unsigned char * >( imageBuffer );
	imageBuffer = nullptr;
	physicalMemoryBytes = 0;
	allocWidth = allocHeight = 0;
}

void idImage::SubImageUpload( int mipLevel, int destX, int destY, int destZ,
		int width, int height, const void * pixels, int pixelPitch ) const {
	if ( d3dTexture == nullptr || pixels == nullptr || mipLevel < 0 ) return;
	const int bits = BitsForFormat( opts.format );
	const int sourcePitch = pixelPitch > 0 ? pixelPitch :
		( IsCompressed() ? std::max( 1, ( width + 3 ) / 4 ) *
			( opts.format == FMT_DXT1 ? 8 : 16 ) : width * bits / 8 );
	const int rows = IsCompressed() ? std::max( 1, ( height + 3 ) / 4 ) : height;
	if ( opts.textureType == TT_CUBIC ) {
		IDirect3DCubeTexture9 * cube = static_cast< IDirect3DCubeTexture9 * >( d3dTexture );
		D3DLOCKED_RECT locked = {};
		RECT rect = { destX, destY, destX + width, destY + height };
		if ( SUCCEEDED( cube->LockRect( static_cast< D3DCUBEMAP_FACES >( destZ ),
				mipLevel, &locked, &rect, 0 ) ) ) {
			for ( int row = 0; row < rows; ++row )
				std::memcpy( static_cast< unsigned char * >( locked.pBits ) + row * locked.Pitch,
					static_cast< const unsigned char * >( pixels ) + row * sourcePitch,
					std::min( sourcePitch, locked.Pitch ) );
			cube->UnlockRect( static_cast< D3DCUBEMAP_FACES >( destZ ), mipLevel );
		}
	} else if ( opts.textureType == TT_3D ) {
		IDirect3DVolumeTexture9 * volume = static_cast< IDirect3DVolumeTexture9 * >( d3dTexture );
		D3DLOCKED_BOX locked = {};
		D3DBOX box = { static_cast< UINT >( destX ), static_cast< UINT >( destY ),
			static_cast< UINT >( destX + width ), static_cast< UINT >( destY + height ),
			static_cast< UINT >( destZ ), static_cast< UINT >( destZ + 1 ) };
		if ( SUCCEEDED( volume->LockBox( mipLevel, &locked, &box, 0 ) ) ) {
			for ( int row = 0; row < rows; ++row )
				std::memcpy( static_cast< unsigned char * >( locked.pBits ) + row * locked.RowPitch,
					static_cast< const unsigned char * >( pixels ) + row * sourcePitch,
					std::min< int >( sourcePitch, locked.RowPitch ) );
			volume->UnlockBox( mipLevel );
		}
	} else {
		IDirect3DTexture9 * texture = static_cast< IDirect3DTexture9 * >( d3dTexture );
		D3DLOCKED_RECT locked = {};
		RECT rect = { destX, destY, destX + width, destY + height };
		if ( SUCCEEDED( texture->LockRect( mipLevel, &locked, &rect, 0 ) ) ) {
			for ( int row = 0; row < rows; ++row )
				std::memcpy( static_cast< unsigned char * >( locked.pBits ) + row * locked.Pitch,
					static_cast< const unsigned char * >( pixels ) + row * sourcePitch,
					std::min( sourcePitch, locked.Pitch ) );
			texture->UnlockRect( mipLevel );
		}
	}
}

idImageData * idImage::GetImageData( int mipLevel, int cubeFace ) const {
	if ( d3dTexture == nullptr || opts.textureType == TT_3D ) return nullptr;
	idImageData * output = new idImageData();
	output->width = std::max( opts.width >> mipLevel, 1 );
	output->height = std::max( opts.height >> mipLevel, 1 );
	const int rowBytes = IsCompressed() ? std::max( 1, ( output->width + 3 ) / 4 ) *
		( opts.format == FMT_DXT1 ? 8 : 16 ) : output->width * BitsForFormat( opts.format ) / 8;
	const int rows = IsCompressed() ? std::max( 1, ( output->height + 3 ) / 4 ) : output->height;
	output->data = new unsigned char[ static_cast< std::size_t >( rowBytes ) * rows ];
	D3DLOCKED_RECT locked = {};
	HRESULT result = E_FAIL;
	if ( opts.textureType == TT_CUBIC ) {
		result = static_cast< IDirect3DCubeTexture9 * >( d3dTexture )->LockRect(
			static_cast< D3DCUBEMAP_FACES >( cubeFace ), mipLevel, &locked, nullptr, D3DLOCK_READONLY );
	} else {
		result = static_cast< IDirect3DTexture9 * >( d3dTexture )->LockRect(
			mipLevel, &locked, nullptr, D3DLOCK_READONLY );
	}
	if ( FAILED( result ) ) { delete output; return nullptr; }
	for ( int row = 0; row < rows; ++row )
		std::memcpy( output->data + row * rowBytes,
			static_cast< const unsigned char * >( locked.pBits ) + row * locked.Pitch, rowBytes );
	if ( opts.textureType == TT_CUBIC )
		static_cast< IDirect3DCubeTexture9 * >( d3dTexture )->UnlockRect(
			static_cast< D3DCUBEMAP_FACES >( cubeFace ), mipLevel );
	else static_cast< IDirect3DTexture9 * >( d3dTexture )->UnlockRect( mipLevel );
	return output;
}
