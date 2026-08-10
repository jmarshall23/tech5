#pragma once

#include "../framework/resource.h"
#include "../framework/resourcelist.h"
#include "renderer_d3d9.h"

class idBinaryImage;
class idFile;
class idImageData;

class idImage : public idResource {
public:
	idImage();
	~idImage() override;

	void LoadResource() override;
	bool ReloadIfStale() override;
	void WriteResourceFile() override;
	idResourceList * GetResourceList() override;
	void Print() override;
	void List() override;

	int BitsForInternalFormat() const;
	bool IsCompressed() const;
	int StorageSize() const;
	imageState_t ImageState() const;
	void DeriveNumLevels();
	void LoadFromBinaryImage( const idBinaryImage & image );
	idImageData * GetImageData( int mipLevel, int cubeFace ) const;
	void BackgroundRead( idFile * file, unsigned int length );
	bool EnableDepthCompareMode( bool enable );

	void Resize( int width, int height, int depth = 1 );
	void DetermineSamplerStateFromOpts();
	void SubImageUpload( int mipLevel, int destX, int destY, int destZ,
		int width, int height, const void * pixels, int pixelPitch ) const;
	void PurgeImage();
	bool AllocImage( const idImageOpts & imageOpts );
	bool AllocRenderTarget( const idImageOpts & imageOpts );
	void Bind( int textureUnit ) const;

	IDirect3DBaseTexture9 * GetTexture() const { return d3dTexture; }
	D3DFORMAT GetD3DFormat() const { return d3dFormat; }
	static void MakeGeneratedName( char * output, int outputSize,
		const char * sourceName );
	static void WriteBinaryImage( const char * name, idImageOpts imageOpts,
		const unsigned char * pixels, unsigned int sourceTimestamp );

	void * backgroundReadData;
	volatile bool backgroundReadComplete;
	bool defaulted;
	unsigned int sourceFileTime;
	unsigned int binaryFileTime;
	int frameUsed;
	int bindCount;
	idImageOpts opts;
	bool optsHasBeenSet;
	bool allocationFailed;
	D3DFORMAT d3dFormat;
	D3DLOCKED_RECT lockRect[14];
	IDirect3DBaseTexture9 * d3dTexture;
	void * imageBuffer;
	int allocWidth;
	int allocHeight;
	int samplerMagFilter;
	int samplerMinFilter;
	int samplerMipFilter;
	int samplerMaxAnisotropy;
	int samplerMipMapLodBias;
	int samplerMaxMipLevel;
	int samplerMinMipLevel;
	int samplerBorderColor;
	int samplerAddressU;
	int samplerAddressV;
	int samplerAddressW;
	int physicalMemoryBytes;
	// D3D9 has no Xbox-style texture/resolve aliasing.  Preserve whether a
	// scratch image owns render-target storage so Resize can recreate it in
	// D3DPOOL_DEFAULT with the correct usage bits.
	bool d3dRenderTarget;

	static idTypedResourceList< idImage > resourceList;
};

D3DFORMAT D3DFMT_FromOpts( const idImageOpts & opts );
