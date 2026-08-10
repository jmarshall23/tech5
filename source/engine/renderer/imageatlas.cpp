#include "imageatlas.h"

#include "binaryimage.h"
#include "image.h"
#include "imagemanager.h"
#include "../../shared/idlib/lib_print.h"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

idTypedResourceList< idAtlasResource > idAtlasResource::resourceList( "atlas" );

idImageAtlas::idImageAtlas( const char * atlasName, const int sizeLog2 ) :
	ATLAS_WIDTH_BITS( sizeLog2 ), ATLAS_HEIGHT_BITS( sizeLog2 ),
	ATLAS_MIP_LEVELS( 1 ), ATLAS_TILE_WIDTH_BITS( 3 ),
	ATLAS_TILE_HEIGHT_BITS( 3 ), ATLAS_WIDTH( 1 << sizeLog2 ),
	ATLAS_HEIGHT( 1 << sizeLog2 ), ATLAS_TILE_WIDTH( 8 ), ATLAS_TILE_HEIGHT( 8 ),
	ATLAS_TILES_WIDE( 1 << ( sizeLog2 - 3 ) ),
	ATLAS_TILES_HIGH( 1 << ( sizeLog2 - 3 ) ),
	ATLAS_TILES( ATLAS_TILES_WIDE * ATLAS_TILES_HIGH ), tileAlloc( 9 ),
	atlas( nullptr ) {
	tileAlloc.Alloc( ATLAS_TILES );
	if ( globalImages == nullptr ) return;
	idImageOpts opts;
	opts.textureType = TT_2D;
	opts.width = ATLAS_WIDTH;
	opts.height = ATLAS_HEIGHT;
	opts.depth = 1;
	opts.numLevels = ATLAS_MIP_LEVELS;
	opts.packedTail = true;
	opts.format = FMT_DXT5;
	opts.filter = TF_LINEAR_MIPMAP_NEAREST;
	opts.repeat = TR_REPEAT;
	atlas = globalImages->ScratchImage( atlasName != nullptr ? atlasName :
		"_transSortImageAtlas", &opts );
	if ( atlas != nullptr && atlas->GetTexture() != nullptr ) {
		const int bytes = ( ATLAS_WIDTH / 4 ) * ( ATLAS_HEIGHT / 4 ) * 16;
		std::vector< unsigned char > clearData( bytes, 0 );
		atlas->SubImageUpload( 0, 0, 0, 0, ATLAS_WIDTH, ATLAS_HEIGHT,
			clearData.data(), ATLAS_WIDTH / 4 * 16 );
	}
}

idImageAtlas::~idImageAtlas() { atlas = nullptr; }

bool idImageAtlas::BlockIsFree( const int x, const int y,
		const int tilesWide, const int tilesHigh ) const {
	if ( x < 0 || y < 0 || tilesWide <= 0 || tilesHigh <= 0 ||
			x + tilesWide > ATLAS_TILES_WIDE || y + tilesHigh > ATLAS_TILES_HIGH ) return false;
	for ( int row = 0; row < tilesHigh; ++row ) for ( int column = 0; column < tilesWide; ++column )
		if ( tileAlloc.Get( ( y + row ) * ATLAS_TILES_WIDE + x + column ) ) return false;
	return true;
}

bool idImageAtlas::AllocBlock( const int tilesWide, const int tilesHigh,
		int & x, int & y ) {
	for ( y = 0; y + tilesHigh <= ATLAS_TILES_HIGH; ++y ) {
		for ( x = 0; x + tilesWide <= ATLAS_TILES_WIDE; ++x ) {
			if ( !BlockIsFree( x, y, tilesWide, tilesHigh ) ) continue;
			for ( int row = 0; row < tilesHigh; ++row ) for ( int column = 0; column < tilesWide; ++column )
				tileAlloc.Set( ( y + row ) * ATLAS_TILES_WIDE + x + column );
			return true;
		}
	}
	x = y = 0;
	return false;
}

void idImageAtlas::FreeBlock( const int x, const int y, const int tilesWide,
		const int tilesHigh ) {
	for ( int row = 0; row < tilesHigh; ++row ) for ( int column = 0; column < tilesWide; ++column ) {
		const int tileX = x + column, tileY = y + row;
		if ( tileX >= 0 && tileY >= 0 && tileX < ATLAS_TILES_WIDE && tileY < ATLAS_TILES_HIGH )
			tileAlloc.Clear( tileY * ATLAS_TILES_WIDE + tileX );
	}
}

idAtlasResource::idAtlasResource() : binaryTimestamp( ~0u ), img_w( 0 ),
	img_h( 0 ), img_tiles_wide( 0 ), img_tiles_high( 0 ), img_x( 0 ), img_y( 0 ),
	scaleBias( 1.0f, 1.0f, 0.0f, 0.0f ) {}

idAtlasResource::~idAtlasResource() { FreeData(); }

idResourceList * idAtlasResource::GetResourceList() { return &resourceList; }

void idAtlasResource::FreeData() {
	if ( globalImages != nullptr && globalImages->transSortImageAtlas != nullptr &&
			img_tiles_wide > 0 && img_tiles_high > 0 )
		globalImages->transSortImageAtlas->FreeBlock( img_x, img_y,
			img_tiles_wide, img_tiles_high );
	img_w = img_h = img_tiles_wide = img_tiles_high = img_x = img_y = 0;
	scaleBias.Set( 1.0f, 1.0f, 0.0f, 0.0f );
}

void idAtlasResource::LoadResource() {
	ClearResourceError();
	if ( globalImages == nullptr || globalImages->transSortImageAtlas == nullptr ) {
		SetResourceError( "Image atlas is not allocated for '%s'", GetName() );
		return;
	}
	idImageAtlas * const target = globalImages->transSortImageAtlas;
	FreeData();
	char expression[1024];
	std::snprintf( expression, sizeof( expression ), "atlasBorder( %s, %d, %d )",
		GetName(), target->ATLAS_WIDTH, target->ATLAS_HEIGHT );
	idBinaryImage binary( expression );
	binary.opts.format = FMT_DXT5;
	char generatedName[1024];
	idImage::MakeGeneratedName( generatedName, sizeof( generatedName ), expression );
	if ( !binary.LoadFromGeneratedFile( generatedName ) || binary.opts.format != FMT_DXT5 ) {
		binary.opts.format = FMT_DXT5;
		if ( !binary.LoadFromSourceFile() || binary.images.Num() <= 0 ) {
			SetResourceError( "Couldn't load image '%s' into atlas", GetName() );
			return;
		}
		binary.WriteGeneratedFile( generatedName );
	}
	img_w = binary.opts.width;
	img_h = binary.opts.height;
	binaryTimestamp = binary.sourceFileTime;
	img_tiles_wide = ( img_w + target->ATLAS_TILE_WIDTH - 1 ) / target->ATLAS_TILE_WIDTH;
	img_tiles_high = ( img_h + target->ATLAS_TILE_HEIGHT - 1 ) / target->ATLAS_TILE_HEIGHT;
	if ( !target->AllocBlock( img_tiles_wide, img_tiles_high, img_x, img_y ) ) {
		SetResourceError( "Unable to allocate %dx%d atlas tiles for '%s'",
			img_tiles_wide, img_tiles_high, GetName() );
		img_tiles_wide = img_tiles_high = 0;
		return;
	}
	const int extraX = (std::max)( 0, target->ATLAS_WIDTH - img_w );
	const int extraY = (std::max)( 0, target->ATLAS_HEIGHT - img_h );
	const int left = (std::min)( 4, extraX );
	const int right = (std::min)( 4, (std::max)( 0, extraX - left ) );
	const int top = (std::min)( 4, extraY );
	const int bottom = (std::min)( 4, (std::max)( 0, extraY - top ) );
	scaleBias.x = static_cast< float >( img_w - left - right ) / target->ATLAS_WIDTH;
	scaleBias.y = static_cast< float >( img_h - top - bottom ) / target->ATLAS_HEIGHT;
	scaleBias.z = static_cast< float >( img_x * target->ATLAS_TILE_WIDTH + left ) / target->ATLAS_WIDTH;
	scaleBias.w = static_cast< float >( img_y * target->ATLAS_TILE_HEIGHT + top ) / target->ATLAS_HEIGHT;
	for ( int level = 0; level < target->ATLAS_MIP_LEVELS && level < binary.images.Num(); ++level ) {
		const idBinaryImage::idBinaryImageData & data = binary.images[level];
		target->atlas->SubImageUpload( level,
			img_x * target->ATLAS_TILE_WIDTH >> level,
			img_y * target->ATLAS_TILE_HEIGHT >> level, 0,
			data.width, data.height, data.data.Ptr(),
			(std::max)( 1, ( data.width + 3 ) / 4 ) * 16 );
	}
}

bool idAtlasResource::ReloadIfStale() {
	// Image programs may depend on multiple files.  Re-evaluating is cheap and
	// the allocator preserves correctness even when dimensions change.
	const unsigned int oldTimestamp = binaryTimestamp;
	LoadResource();
	return binaryTimestamp != oldTimestamp;
}

void idAtlasResource::WriteResourceFile() {}

void idAtlasResource::Print() { List(); }

void idAtlasResource::List() {
	if ( globalImages == nullptr || globalImages->transSortImageAtlas == nullptr ) {
		idLibPrint::Printf( "atlas: unallocated %s\n", GetName() );
		return;
	}
	const idImageAtlas * target = globalImages->transSortImageAtlas;
	idLibPrint::Printf( "%4i, %4i : %4i x %4i %s\n",
		img_x * target->ATLAS_TILE_WIDTH, img_y * target->ATLAS_TILE_HEIGHT,
		img_tiles_wide * target->ATLAS_TILE_WIDTH,
		img_tiles_high * target->ATLAS_TILE_HEIGHT, GetName() );
}
