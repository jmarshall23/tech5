#include "rendersystem_local.h"

#include "framework/framework_runtime.h"
#include "imagetools/imageprocess.h"

#include <algorithm>
#include <array>
#include <atomic>
#include <cstdio>
#include <cstring>
#include <vector>

enum screenshotFormat_t { SCREENSHOT_TGA, SCREENSHOT_JPG, SCREENSHOT_PNG };

namespace {
	std::atomic< int > screenshotSequence( 0 );

	bool ReadBackBuffer( std::vector< unsigned char > & rgba, int & width, int & height ) {
		rgba.clear(); width = height = 0;
		IDirect3DDevice9 * device = rendererD3D9.GetDevice();
		if ( device == nullptr ) return false;
		IDirect3DSurface9 * source = nullptr;
		IDirect3DSurface9 * resolve = nullptr;
		IDirect3DSurface9 * readback = nullptr;
		bool success = false;
		if ( FAILED( device->GetRenderTarget( 0, &source ) ) ) return false;
		D3DSURFACE_DESC desc = {};
		source->GetDesc( &desc );
		IDirect3DSurface9 * copySource = source;
		if ( desc.MultiSampleType != D3DMULTISAMPLE_NONE ) {
			if ( SUCCEEDED( device->CreateRenderTarget( desc.Width, desc.Height,
				desc.Format, D3DMULTISAMPLE_NONE, 0, FALSE, &resolve, nullptr ) ) &&
				SUCCEEDED( device->StretchRect( source, nullptr, resolve, nullptr, D3DTEXF_NONE ) ) )
				copySource = resolve;
		}
		if ( SUCCEEDED( device->CreateOffscreenPlainSurface( desc.Width, desc.Height,
			desc.Format, D3DPOOL_SYSTEMMEM, &readback, nullptr ) ) &&
			SUCCEEDED( device->GetRenderTargetData( copySource, readback ) ) ) {
			D3DLOCKED_RECT lock = {};
			if ( SUCCEEDED( readback->LockRect( &lock, nullptr, D3DLOCK_READONLY ) ) ) {
				width = static_cast< int >( desc.Width );
				height = static_cast< int >( desc.Height );
				rgba.resize( static_cast< std::size_t >( width ) * height * 4 );
				for ( int y = 0; y < height; ++y ) {
					const unsigned char * input = static_cast< const unsigned char * >( lock.pBits ) + y * lock.Pitch;
					unsigned char * output = rgba.data() + static_cast< std::size_t >( y ) * width * 4;
					for ( int x = 0; x < width; ++x ) {
						output[x * 4 + 0] = input[x * 4 + 2];
						output[x * 4 + 1] = input[x * 4 + 1];
						output[x * 4 + 2] = input[x * 4 + 0];
						output[x * 4 + 3] = desc.Format == D3DFMT_X8R8G8B8 ? 255 : input[x * 4 + 3];
					}
				}
				readback->UnlockRect();
				success = true;
			}
		}
		D3D9Release( readback );
		D3D9Release( resolve );
		D3D9Release( source );
		return success;
	}

	const char * Extension( screenshotFormat_t format ) {
		return format == SCREENSHOT_JPG ? "jpg" : format == SCREENSHOT_TGA ? "tga" : "png";
	}

	bool WriteScreenshot( const char * name, screenshotFormat_t format ) {
		std::vector< unsigned char > pixels;
		int width = 0, height = 0;
		GL_Finish();
		if ( !ReadBackBuffer( pixels, width, height ) ) return false;
		if ( format == SCREENSHOT_JPG ) return R_WriteJPG( name, pixels.data(), width, height );
		if ( format == SCREENSHOT_TGA ) return R_WriteTGA( name, pixels.data(), width, height, 4 );
		return R_WritePNG( name, pixels.data(), width, height, false );
	}

	void ScreenshotCommand( const std::vector< idStr > & args ) {
		screenshotFormat_t format = SCREENSHOT_PNG;
		if ( args.size() > 2 ) {
			if ( idStr::Icmp( args[2].c_str(), "jpg" ) == 0 ) format = SCREENSHOT_JPG;
			else if ( idStr::Icmp( args[2].c_str(), "tga" ) == 0 ) format = SCREENSHOT_TGA;
		}
		char generated[128];
		const char * name = args.size() > 1 ? args[1].c_str() : nullptr;
		if ( name == nullptr || *name == '\0' ) {
			std::snprintf( generated, sizeof( generated ), "screenshots/shot%04d.%s",
				screenshotSequence.fetch_add( 1 ), Extension( format ) );
			name = generated;
		}
		const bool written = WriteScreenshot( name, format );
		tech5Framework::Print( written ? 0xFF80FF80u : 0xFFFF8080u,
			"screenshot %s: %s\n", written ? "written" : "failed", name );
	}

	void GfxInfoCommand( const std::vector< idStr > & ) {
		const D3DCAPS9 caps = rendererD3D9.Caps();
		tech5Framework::Print( 0xFFFFFFFFu,
			"D3D9 %dx%d, shader model %u.%u / %u.%u, MRT %u, multisamples %d\n",
			rendererD3D9.Width(), rendererD3D9.Height(),
			D3DSHADER_VERSION_MAJOR( caps.VertexShaderVersion ),
			D3DSHADER_VERSION_MINOR( caps.VertexShaderVersion ),
			D3DSHADER_VERSION_MAJOR( caps.PixelShaderVersion ),
			D3DSHADER_VERSION_MINOR( caps.PixelShaderVersion ),
			caps.NumSimultaneousRTs, rendererD3D9.Multisamples() );
	}
}

void R_ScreenshotFilename( int & sequence, const char * baseName,
		idStr & result, screenshotFormat_t format ) {
	char name[256];
	std::snprintf( name, sizeof( name ), "%s%04d.%s",
		baseName != nullptr ? baseName : "screenshots/shot", sequence++, Extension( format ) );
	result = name;
}

void idRenderSystemLocal::InitCommands() {
	tech5Framework::RegisterCommand( "screenshot", ScreenshotCommand );
	tech5Framework::RegisterCommand( "gfxinfo", GfxInfoCommand );
	tech5Framework::RegisterCommand( "vid_restart", []( const std::vector< idStr > & ) {
		renderSystemLocal.Restart();
	} );
}
