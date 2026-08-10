#pragma once

#include "../framework/resource.h"
#include "../framework/resourcelist.h"
#include "../../shared/idlib/containers/bitarray.h"
#include "../../shared/idlib/math/vector.h"

class idImage;

enum imageFlags_t : int {
	IMAGE_SPECULAR = 0x1,
	IMAGE_DIFFUSE = 0x2,
	IMAGE_NORMAL = 0x4,
	IMAGE_TEST_FBR = 0x8,
	IMAGE_TEST_VBR = 0x10
};

class idImageAtlas {
public:
	idImageAtlas( const char * atlasName, int sizeLog2 );
	~idImageAtlas();
	bool AllocBlock( int tilesWide, int tilesHigh, int & x, int & y );
	void FreeBlock( int x, int y, int tilesWide, int tilesHigh );
	bool BlockIsFree( int x, int y, int tilesWide, int tilesHigh ) const;

	int ATLAS_WIDTH_BITS;
	int ATLAS_HEIGHT_BITS;
	int ATLAS_MIP_LEVELS;
	int ATLAS_TILE_WIDTH_BITS;
	int ATLAS_TILE_HEIGHT_BITS;
	int ATLAS_WIDTH;
	int ATLAS_HEIGHT;
	int ATLAS_TILE_WIDTH;
	int ATLAS_TILE_HEIGHT;
	int ATLAS_TILES_WIDE;
	int ATLAS_TILES_HIGH;
	int ATLAS_TILES;
	idBitArray tileAlloc;
	idImage * atlas;
};

class idAtlasResource : public idResource {
public:
	idAtlasResource();
	~idAtlasResource() override;
	void LoadResource() override;
	bool ReloadIfStale() override;
	void WriteResourceFile() override;
	idResourceList * GetResourceList() override;
	void Print() override;
	void List() override;

	void FreeData();
	const idVec4 & GetScaleBias() const { return scaleBias; }

	unsigned int binaryTimestamp;
	int img_w;
	int img_h;
	int img_tiles_wide;
	int img_tiles_high;
	int img_x;
	int img_y;
	idVec4 scaleBias;

	static idTypedResourceList< idAtlasResource > resourceList;
};
