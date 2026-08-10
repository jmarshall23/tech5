#include "imagemanager.h"

#include "image.h"
#include "imageatlas.h"
#include "renderer_d3d9.h"

#include <algorithm>
#include <cstring>

namespace {
	idImageManager localImageManager;

	idImage * CreateIntrinsic2D( idImageManager & manager, const char * name,
		const int width, const int height, const unsigned int * pixels,
		const textureFilter_t filter = TF_LINEAR,
		const textureRepeat_t repeat = TR_REPEAT ) {
		idImage * const image = manager.AllocImage( name );
		if ( image == nullptr ) return nullptr;
		idImageOpts opts;
		opts.textureType = TT_2D;
		opts.width = width;
		opts.height = height;
		opts.depth = 1;
		opts.numLevels = 1;
		opts.format = FMT_RGBA8;
		opts.filter = filter;
		opts.repeat = repeat;
		if ( image->AllocImage( opts ) ) {
			image->SubImageUpload( 0, 0, 0, 0, width, height, pixels, width * 4 );
		}
		return image;
	}
}

idImageManager * globalImages = &localImageManager;

idImageManager::idImageManager() :
	defaultImage( nullptr ), whiteImage( nullptr ), borderedPointWhiteImage( nullptr ),
	blackImage( nullptr ), ps3ReplacementImage( nullptr ), transSortImageAtlas( nullptr ),
	textureMinFilter( TF_LINEAR ), textureMaxFilter( TF_LINEAR ),
	textureMipFilter( TF_LINEAR_MIPMAP_NEAREST ), textureAnisotropy( 1.0f ),
	textureLODBias( 0.0f ) {}

idImageManager::~idImageManager() { Shutdown(); }

void idImageManager::Init() {
	textureMinFilter = TF_LINEAR;
	textureMaxFilter = TF_LINEAR;
	textureMipFilter = TF_LINEAR_MIPMAP_NEAREST;
	textureAnisotropy = 1.0f;
	textureLODBias = 0.0f;
	CreateIntrinsicImages();
	if ( transSortImageAtlas == nullptr )
		transSortImageAtlas = new idImageAtlas( "_transSortImageAtlas", 12 );
}

void idImageManager::Shutdown() {
	UnbindAll();
	delete transSortImageAtlas;
	transSortImageAtlas = nullptr;
	defaultImage = nullptr;
	whiteImage = nullptr;
	borderedPointWhiteImage = nullptr;
	blackImage = nullptr;
	ps3ReplacementImage = nullptr;
}

idImage * idImageManager::AllocImage( const char * name ) {
	if ( name == nullptr || name[0] == '\0' ) return nullptr;
	if ( idResource * const existing = idImage::resourceList.FindExisting( name, true ) ) {
		return static_cast< idImage * >( existing );
	}
	idImage * const image = static_cast< idImage * >( idImage::resourceList.Alloc( name ) );
	if ( image != nullptr ) idImage::resourceList.Add( image );
	return image;
}

idImage * idImageManager::ImageFromFile( const char * name, idImageOpts * imageOpts,
	const bool makeDefault ) {
	if ( name == nullptr || name[0] == '\0' ) return defaultImage;
	idImage * image = static_cast< idImage * >(
		idImage::resourceList.FindExisting( name, false ) );
	if ( image == nullptr ) {
		image = AllocImage( name );
		if ( image == nullptr ) return makeDefault ? defaultImage : nullptr;
		if ( imageOpts != nullptr ) {
			image->opts = *imageOpts;
			image->optsHasBeenSet = true;
		}
		image->LoadResource();
	} else if ( imageOpts != nullptr && !image->optsHasBeenSet ) {
		image->opts = *imageOpts;
		image->optsHasBeenSet = true;
	}
	return image->allocationFailed && makeDefault && defaultImage != nullptr
		? defaultImage : image;
}

idImage * idImageManager::ScratchImage( const char * name, idImageOpts * imageOpts ) {
	if ( imageOpts == nullptr ) return nullptr;
	idImage * const image = AllocImage( name );
	if ( image == nullptr ) return nullptr;
	if ( image->GetTexture() == nullptr || image->opts != *imageOpts ) {
		image->AllocImage( *imageOpts );
	}
	return image;
}

void idImageManager::BindNull() {
	IDirect3DDevice9 * const device = rendererD3D9.GetDevice();
	if ( device != nullptr ) device->SetTexture( 0, nullptr );
}

void idImageManager::UnbindAll() {
	IDirect3DDevice9 * const device = rendererD3D9.GetDevice();
	if ( device != nullptr ) {
		for ( DWORD unit = 0; unit < 16; ++unit ) device->SetTexture( unit, nullptr );
	}
	GL_ResetTextureState();
}

void idImageManager::ChangeTextureFilter() {
	idList< idResource * > images;
	idImage::resourceList.GetLoadedResources( images );
	for ( int index = 0; index < images.Num(); ++index ) {
		idImage * const image = static_cast< idImage * >( images[index] );
		if ( image == nullptr || image->opts.filter != TF_DEFAULT ) continue;
		image->opts.aniso = (std::max)( textureAnisotropy, 1.0f );
		image->opts.lodBias = textureLODBias;
		image->DetermineSamplerStateFromOpts();
	}
	GL_ResetTextureState();
}

void idImageManager::CheckCvars() { ChangeTextureFilter(); }

void idImageManager::PurgeAllOverlays() {
	idList< idResource * > images;
	idImage::resourceList.GetLoadedResources( images );
	for ( int index = 0; index < images.Num(); ++index ) {
		idImage * const image = static_cast< idImage * >( images[index] );
		if ( image != nullptr && image->opts.overlayMemory ) image->PurgeImage();
	}
}

void idImageManager::CreateIntrinsicImages() {
	unsigned int defaultPixels[64];
	for ( int y = 0; y < 8; ++y ) {
		for ( int x = 0; x < 8; ++x ) {
			const bool border = x == 0 || y == 0 || x == 7 || y == 7;
			defaultPixels[y * 8 + x] = border || ( ( x ^ y ) & 1 ) != 0
				? 0xff000000u : 0xffff00ffu;
		}
	}
	defaultImage = CreateIntrinsic2D( *this, "_default", 8, 8, defaultPixels );
	const unsigned int white = 0xffffffffu;
	const unsigned int black = 0xff000000u;
	whiteImage = CreateIntrinsic2D( *this, "_white", 1, 1, &white );
	blackImage = CreateIntrinsic2D( *this, "_black", 1, 1, &black );
	ps3ReplacementImage = defaultImage;

	unsigned int bordered[64];
	for ( int y = 0; y < 8; ++y ) for ( int x = 0; x < 8; ++x ) {
		bordered[y * 8 + x] = ( x == 0 || y == 0 || x == 7 || y == 7 )
			? 0x00000000u : 0xffffffffu;
	}
	borderedPointWhiteImage = CreateIntrinsic2D( *this, "_borderedPointWhite",
		8, 8, bordered, TF_LINEAR, TR_CLAMP_TO_BORDER );

	const unsigned int flatNormal = 0xffff8080u;
	CreateIntrinsic2D( *this, "_flat", 1, 1, &flatNormal );
	unsigned int noFalloff[64];
	for ( int i = 0; i < 64; ++i ) noFalloff[i] = 0xffffffffu;
	for ( int i = 0; i < 8; ++i ) noFalloff[i] = noFalloff[56 + i] = 0xff000000u;
	for ( int i = 0; i < 8; ++i ) noFalloff[i * 8] = noFalloff[i * 8 + 7] = 0xff000000u;
	CreateIntrinsic2D( *this, "_nofalloff", 8, 8, noFalloff, TF_LINEAR, TR_CLAMP );
}
