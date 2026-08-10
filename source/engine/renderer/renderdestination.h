#pragma once

#include "renderer_d3d9.h"

class idImage;

class idRenderDestination {
public:
	idRenderDestination();
	~idRenderDestination();
	idRenderDestination( const idRenderDestination & ) = delete;
	idRenderDestination & operator=( const idRenderDestination & ) = delete;

	void AddTarget( idImage * target, IDirect3DSurface9 * surface = nullptr );
	void Resize( int width, int height );
	void CreateFromImages( idImage * color, idImage * depth, idImage * stencil,
		IDirect3DSurface9 * colorSurface = nullptr,
		IDirect3DSurface9 * depthTargetSurface = nullptr );
	bool Bind( int face = 0, int mipLevel = 0 ) const;
	IDirect3DSurface9 * AcquireTargetSurface( int target, int face,
		int mipLevel ) const;
	IDirect3DSurface9 * AcquireDepthSurface( int mipLevel ) const;
	void ReleaseSurfaces();

	bool isDefault;
	int targetWidth;
	int targetHeight;
	idImage * targetImage[4];
	idImage * depthImage;
	idImage * stencilImage;
	IDirect3DSurface9 * targetSurface[4];
	IDirect3DSurface9 * depthSurface;
};

