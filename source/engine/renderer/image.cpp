#include "image.h"

#include "binaryimage.h"
#include "imagedata.h"
#include "renderer_d3d9.h"

#include <algorithm>
#include <cstdio>
#include <cstring>

idTypedResourceList< idImage > idImage::resourceList( "image" );

int BitsForFormat( textureFormat_t format ) {
	switch ( format ) {
		case FMT_RGBA32F: return 128;
		case FMT_RGBA16F: return 64;
		case FMT_RGBA8:
		case FMT_ARGB8:
		case FMT_X32F:
		case FMT_Y16_X16: return 32;
		case FMT_L8A8:
		case FMT_RG8:
		case FMT_Y16F_X16F:
		case FMT_X16:
		case FMT_RGB565: return 16;
		case FMT_ALPHA:
		case FMT_LUM8:
		case FMT_INT8:
		case FMT_DXT5: return 8;
		case FMT_DXT1: return 4;
		case FMT_DEPTH:
		case FMT_DEPTH_STENCIL: return 32;
		default: return 0;
	}
}

void ComputeNumLevels( idImageOpts & opts, const char * name ) {
	if ( opts.numLevels != 0 ) return;
	const bool generated = name != nullptr && name[0] == '_';
	const bool powerOfTwo = opts.width > 0 && opts.height > 0 &&
		( opts.width & ( opts.width - 1 ) ) == 0 &&
		( opts.height & ( opts.height - 1 ) ) == 0;
	if ( !generated && !powerOfTwo ) {
		opts.numLevels = 1;
		return;
	}
	if ( opts.filter < TF_NEAREST_MIPMAP_NEAREST ) {
		opts.numLevels = 1;
		return;
	}
	int width = std::max( opts.width, 1 );
	int height = std::max( opts.height, 1 );
	int depth = std::max( opts.depth, 1 );
	opts.numLevels = 1;
	while ( width > 1 || height > 1 || depth > 1 ) {
		width = std::max( width >> 1, 1 );
		height = std::max( height >> 1, 1 );
		depth = std::max( depth >> 1, 1 );
		if ( ( opts.format == FMT_DXT1 || opts.format == FMT_DXT5 ) &&
			( ( width & 3 ) != 0 || ( height & 3 ) != 0 ) ) break;
		++opts.numLevels;
	}
}

idImage::idImage() : backgroundReadData( nullptr ), backgroundReadComplete( true ),
	defaulted( false ), sourceFileTime( ~0u ), binaryFileTime( ~0u ), frameUsed( 0 ),
	bindCount( 0 ), optsHasBeenSet( false ), allocationFailed( false ),
	d3dFormat( D3DFMT_UNKNOWN ), d3dTexture( nullptr ), imageBuffer( nullptr ),
	allocWidth( 0 ), allocHeight( 0 ), samplerMagFilter( D3DTEXF_LINEAR ),
	samplerMinFilter( D3DTEXF_LINEAR ), samplerMipFilter( D3DTEXF_LINEAR ),
	samplerMaxAnisotropy( 1 ), samplerMipMapLodBias( 0 ), samplerMaxMipLevel( 0 ),
	samplerMinMipLevel( 0 ), samplerBorderColor( 0 ), samplerAddressU( D3DTADDRESS_WRAP ),
	samplerAddressV( D3DTADDRESS_WRAP ), samplerAddressW( D3DTADDRESS_WRAP ),
	physicalMemoryBytes( 0 ), d3dRenderTarget( false ) {
	std::memset( lockRect, 0, sizeof( lockRect ) );
}

idImage::~idImage() {
	PurgeImage();
}

int idImage::BitsForInternalFormat() const { return BitsForFormat( opts.format ); }
bool idImage::IsCompressed() const { return opts.format == FMT_DXT1 || opts.format == FMT_DXT5; }

int idImage::StorageSize() const {
	if ( d3dTexture == nullptr ) return 0;
	int total = 0;
	int width = std::max( opts.width, 1 );
	int height = std::max( opts.height, 1 );
	int depth = std::max( opts.depth, 1 );
	const int faces = opts.textureType == TT_CUBIC ? 6 : 1;
	const int levels = std::max( opts.numLevels, 1 );
	for ( int level = 0; level < levels; ++level ) {
		if ( opts.format == FMT_DXT1 || opts.format == FMT_DXT5 ) {
			const int blockBytes = opts.format == FMT_DXT1 ? 8 : 16;
			total += std::max( 1, ( width + 3 ) / 4 ) *
				std::max( 1, ( height + 3 ) / 4 ) * blockBytes * depth * faces;
		} else {
			total += width * height * depth * faces * BitsForFormat( opts.format ) / 8;
		}
		width = std::max( width >> 1, 1 );
		height = std::max( height >> 1, 1 );
		depth = std::max( depth >> 1, 1 );
	}
	return total;
}

imageState_t idImage::ImageState() const {
	if ( d3dTexture == nullptr ) return IS_PURGED;
	return backgroundReadData != nullptr && !backgroundReadComplete ?
		IS_BACKGROUND_READING : IS_READY;
}

void idImage::DeriveNumLevels() { ComputeNumLevels( opts, GetName() ); }

void idImage::LoadFromBinaryImage( const idBinaryImage & image ) {
	PurgeImage();
	sourceFileTime = image.sourceFileTime;
	binaryFileTime = image.binaryFileTime;
	if ( !AllocImage( image.opts ) ) return;
	for ( int index = 0; index < image.images.Num(); ++index ) {
		const idBinaryImage::idBinaryImageData & level = image.images[index];
		SubImageUpload( level.level, 0, 0, level.destZ, level.width, level.height,
			level.data.Ptr(), 0 );
	}
}

void idImage::Print() {
	std::printf( "%c %4d %4d %2d fmt=%d type=%d %6dk %s\n",
		d3dTexture != nullptr ? ' ' : 'P', opts.width, opts.height,
		opts.numLevels, static_cast< int >( opts.format ),
		static_cast< int >( opts.textureType ), StorageSize() / 1024, GetName() );
}

void idImage::List() { Print(); }
void idImage::WriteResourceFile() {}
idResourceList * idImage::GetResourceList() { return &resourceList; }

void idImage::MakeGeneratedName( char * output, int outputSize, const char * sourceName ) {
	if ( output == nullptr || outputSize <= 0 ) return;
	std::snprintf( output, static_cast< std::size_t >( outputSize ), "generated/%s.bimage",
		sourceName != nullptr ? sourceName : "_default" );
	for ( char * cursor = output; *cursor != '\0'; ++cursor ) {
		if ( *cursor == '\\' ) *cursor = '/';
	}
}

bool idImage::EnableDepthCompareMode( bool enable ) {
	const bool oldValue = opts.depthCompareMode;
	if ( oldValue != enable ) {
		opts.depthCompareMode = enable;
		DetermineSamplerStateFromOpts();
		GL_ResetTextureState();
	}
	return oldValue;
}

void idImage::Bind( int textureUnit ) const {
	IDirect3DDevice9 * device = rendererD3D9.GetDevice();
	if ( device == nullptr || textureUnit < 0 || textureUnit >= 16 ) return;
	device->SetTexture( static_cast< DWORD >( textureUnit ), d3dTexture );
	device->SetSamplerState( textureUnit, D3DSAMP_MAGFILTER, samplerMagFilter );
	device->SetSamplerState( textureUnit, D3DSAMP_MINFILTER, samplerMinFilter );
	device->SetSamplerState( textureUnit, D3DSAMP_MIPFILTER, samplerMipFilter );
	device->SetSamplerState( textureUnit, D3DSAMP_MAXANISOTROPY, samplerMaxAnisotropy );
	device->SetSamplerState( textureUnit, D3DSAMP_MIPMAPLODBIAS, samplerMipMapLodBias );
	device->SetSamplerState( textureUnit, D3DSAMP_MAXMIPLEVEL, samplerMaxMipLevel );
	device->SetSamplerState( textureUnit, D3DSAMP_BORDERCOLOR, samplerBorderColor );
	device->SetSamplerState( textureUnit, D3DSAMP_ADDRESSU, samplerAddressU );
	device->SetSamplerState( textureUnit, D3DSAMP_ADDRESSV, samplerAddressV );
	device->SetSamplerState( textureUnit, D3DSAMP_ADDRESSW, samplerAddressW );
}

void idImage::BackgroundRead( idFile *, unsigned int ) {
	backgroundReadComplete = true;
	backgroundReadData = nullptr;
}

bool idImage::ReloadIfStale() {
	if ( staleCount == 0 ) return false;
	PurgeImage();
	LoadResource();
	staleCount = 0;
	return true;
}

void idImage::LoadResource() {
	if ( d3dTexture != nullptr || opts.startPurged ) return;
	if ( !optsHasBeenSet ) {
		opts.width = 8;
		opts.height = 8;
		opts.depth = 1;
		opts.numLevels = 1;
		opts.format = FMT_RGBA8;
		opts.filter = TF_LINEAR;
	}
	if ( !AllocImage( opts ) ) return;
	if ( opts.textureType == TT_2D && opts.format == FMT_RGBA8 ) {
		unsigned int pixels[64];
		for ( int y = 0; y < 8; ++y ) for ( int x = 0; x < 8; ++x )
			pixels[y * 8 + x] = ( ( x ^ y ) & 1 ) != 0 ? 0xff000000u : 0xffff00ffu;
		SubImageUpload( 0, 0, 0, 0, 8, 8, pixels, 8 * 4 );
		defaulted = true;
	}
}
