#pragma once

#include "renderer_types.h"

class idImage;
class idImageAtlas;

class alignas( 4 ) idImageManager {
public:
	idImageManager();
	~idImageManager();

	void Init();
	void Shutdown();
	void CreateIntrinsicImages();
	void BindNull();
	void UnbindAll();
	void ChangeTextureFilter();
	void CheckCvars();
	void PurgeAllOverlays();

	idImage * AllocImage( const char * name );
	idImage * ImageFromFile( const char * name, idImageOpts * opts = nullptr,
		bool makeDefault = true );
	idImage * ScratchImage( const char * name, idImageOpts * opts );

	idImage * defaultImage;
	idImage * whiteImage;
	idImage * borderedPointWhiteImage;
	idImage * blackImage;
	idImage * ps3ReplacementImage;
	idImageAtlas * transSortImageAtlas;
	textureFilter_t textureMinFilter;
	textureFilter_t textureMaxFilter;
	textureFilter_t textureMipFilter;
	float textureAnisotropy;
	float textureLODBias;
	idImageOpts newImageOpts;
};

extern idImageManager * globalImages;
