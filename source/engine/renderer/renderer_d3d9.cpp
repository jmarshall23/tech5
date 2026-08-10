#include "renderer_d3d9.h"

#include <algorithm>
#include <cstring>

#pragma comment( lib, "d3d9.lib" )
#pragma comment( lib, "d3dcompiler.lib" )

idD3D9Renderer rendererD3D9;

wrapperContext_t::wrapperContext_t() : d3d( nullptr ) {
	std::memset( occlusionQueryBatch, 0, sizeof( occlusionQueryBatch ) );
}

idD3D9Renderer::idD3D9Renderer() :
	d3d( nullptr ), device( nullptr ), window( nullptr ), deviceType( D3DDEVTYPE_HAL ),
	behaviorFlags( 0 ), deviceLost( false ), sceneActive( false ) {
	std::memset( &presentParameters, 0, sizeof( presentParameters ) );
	std::memset( &caps, 0, sizeof( caps ) );
}

idD3D9Renderer::~idD3D9Renderer() {
	Shutdown();
}

bool idD3D9Renderer::Initialize( HWND gameWindow, int width, int height,
		bool fullscreen, int multisamples, bool vsync ) {
	Shutdown();
	window = gameWindow;
	d3d = Direct3DCreate9( D3D_SDK_VERSION );
	if ( d3d == nullptr || window == nullptr ) {
		Shutdown();
		return false;
	}
	if ( FAILED( d3d->GetDeviceCaps( D3DADAPTER_DEFAULT, deviceType, &caps ) ) ) {
		Shutdown();
		return false;
	}
	BuildPresentParameters( width, height, fullscreen, multisamples, vsync );
	return CreateDevice();
}

void idD3D9Renderer::Shutdown() {
	EndScene();
	D3D9Release( device );
	D3D9Release( d3d );
	window = nullptr;
	deviceLost = false;
	std::memset( &presentParameters, 0, sizeof( presentParameters ) );
	std::memset( &caps, 0, sizeof( caps ) );
}

void idD3D9Renderer::BuildPresentParameters( int width, int height,
		bool fullscreen, int multisamples, bool vsync ) {
	D3DDISPLAYMODE desktopMode = {};
	d3d->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, &desktopMode );

	std::memset( &presentParameters, 0, sizeof( presentParameters ) );
	presentParameters.BackBufferWidth = static_cast< UINT >( std::max( width, 1 ) );
	presentParameters.BackBufferHeight = static_cast< UINT >( std::max( height, 1 ) );
	presentParameters.BackBufferFormat = fullscreen ? desktopMode.Format : D3DFMT_UNKNOWN;
	presentParameters.BackBufferCount = 1;
	presentParameters.MultiSampleType = ChooseMultisampleType( multisamples );
	presentParameters.MultiSampleQuality = 0;
	presentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	presentParameters.hDeviceWindow = window;
	presentParameters.Windowed = fullscreen ? FALSE : TRUE;
	presentParameters.EnableAutoDepthStencil = TRUE;
	presentParameters.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;
	presentParameters.PresentationInterval = vsync ? D3DPRESENT_INTERVAL_ONE : D3DPRESENT_INTERVAL_IMMEDIATE;

	D3DFORMAT adapterFormat = desktopMode.Format;
	D3DFORMAT backBufferFormat = fullscreen ? presentParameters.BackBufferFormat : adapterFormat;
	if ( !FindDepthStencilFormat( adapterFormat, backBufferFormat,
			presentParameters.AutoDepthStencilFormat ) ) {
		presentParameters.AutoDepthStencilFormat = D3DFMT_D16;
	}
}

bool idD3D9Renderer::CreateDevice() {
	behaviorFlags = D3DCREATE_FPU_PRESERVE | D3DCREATE_MULTITHREADED;
	if ( ( caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT ) != 0 ) {
		behaviorFlags |= D3DCREATE_HARDWARE_VERTEXPROCESSING;
		if ( ( caps.DevCaps & D3DDEVCAPS_PUREDEVICE ) != 0 ) {
			behaviorFlags |= D3DCREATE_PUREDEVICE;
		}
	} else {
		behaviorFlags |= D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	HRESULT result = d3d->CreateDevice( D3DADAPTER_DEFAULT, deviceType, window,
		behaviorFlags, &presentParameters, &device );
	if ( FAILED( result ) && ( behaviorFlags & D3DCREATE_PUREDEVICE ) != 0 ) {
		behaviorFlags &= ~D3DCREATE_PUREDEVICE;
		result = d3d->CreateDevice( D3DADAPTER_DEFAULT, deviceType, window,
			behaviorFlags, &presentParameters, &device );
	}
	if ( FAILED( result ) && ( behaviorFlags & D3DCREATE_HARDWARE_VERTEXPROCESSING ) != 0 ) {
		behaviorFlags &= ~( D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE );
		behaviorFlags |= D3DCREATE_SOFTWARE_VERTEXPROCESSING;
		result = d3d->CreateDevice( D3DADAPTER_DEFAULT, deviceType, window,
			behaviorFlags, &presentParameters, &device );
	}
	deviceLost = FAILED( result );
	return SUCCEEDED( result );
}

bool idD3D9Renderer::Reset( int width, int height, bool fullscreen,
		int multisamples, bool vsync ) {
	if ( d3d == nullptr || device == nullptr ) {
		return false;
	}
	EndScene();
	BuildPresentParameters( width, height, fullscreen, multisamples, vsync );
	const HRESULT result = device->Reset( &presentParameters );
	deviceLost = FAILED( result );
	return SUCCEEDED( result );
}

bool idD3D9Renderer::EnsureReady() {
	if ( device == nullptr ) {
		return false;
	}
	const HRESULT state = device->TestCooperativeLevel();
	if ( state == D3D_OK ) {
		deviceLost = false;
		return true;
	}
	deviceLost = true;
	if ( state != D3DERR_DEVICENOTRESET ) {
		return false;
	}
	// D3DPOOL_DEFAULT resources are owned by the render system.  It must purge
	// them before Reset and recreate them afterward, so report readiness here
	// and let idRenderSystemLocal perform the complete lost-device sequence.
	return false;
}

bool idD3D9Renderer::Present() {
	if ( device == nullptr ) {
		return false;
	}
	EndScene();
	const HRESULT result = device->Present( nullptr, nullptr, nullptr, nullptr );
	if ( result == D3DERR_DEVICELOST ) {
		deviceLost = true;
	}
	return SUCCEEDED( result );
}

void idD3D9Renderer::BeginScene() {
	if ( device != nullptr && !sceneActive && EnsureReady() &&
			SUCCEEDED( device->BeginScene() ) ) {
		sceneActive = true;
	}
}

void idD3D9Renderer::EndScene() {
	if ( device != nullptr && sceneActive ) {
		device->EndScene();
		sceneActive = false;
	}
}

D3DMULTISAMPLE_TYPE idD3D9Renderer::ChooseMultisampleType( int requested ) const {
	if ( d3d == nullptr || requested <= 1 ) {
		return D3DMULTISAMPLE_NONE;
	}
	D3DDISPLAYMODE mode = {};
	d3d->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, &mode );
	const D3DFORMAT format = presentParameters.Windowed ? mode.Format :
		( presentParameters.BackBufferFormat == D3DFMT_UNKNOWN ? mode.Format : presentParameters.BackBufferFormat );
	for ( int samples = std::min( requested, 16 ); samples >= 2; --samples ) {
		const D3DMULTISAMPLE_TYPE type = static_cast< D3DMULTISAMPLE_TYPE >( samples );
		if ( SUCCEEDED( d3d->CheckDeviceMultiSampleType( D3DADAPTER_DEFAULT,
			deviceType, format, presentParameters.Windowed, type, nullptr ) ) ) {
			return type;
		}
	}
	return D3DMULTISAMPLE_NONE;
}

bool idD3D9Renderer::FindDepthStencilFormat( D3DFORMAT adapterFormat,
		D3DFORMAT backBufferFormat, D3DFORMAT & result ) const {
	static const D3DFORMAT choices[] = { D3DFMT_D24S8, D3DFMT_D24X8,
		D3DFMT_D24X4S4, D3DFMT_D16 };
	for ( D3DFORMAT candidate : choices ) {
		if ( SUCCEEDED( d3d->CheckDeviceFormat( D3DADAPTER_DEFAULT, deviceType,
				adapterFormat, D3DUSAGE_DEPTHSTENCIL, D3DRTYPE_SURFACE, candidate ) ) &&
			SUCCEEDED( d3d->CheckDepthStencilMatch( D3DADAPTER_DEFAULT, deviceType,
				adapterFormat, backBufferFormat, candidate ) ) ) {
			result = candidate;
			return true;
		}
	}
	return false;
}

int idD3D9Renderer::Multisamples() const {
	return presentParameters.MultiSampleType == D3DMULTISAMPLE_NONE ? 0 :
		static_cast< int >( presentParameters.MultiSampleType );
}

int idD3D9Renderer::MaxSupportedMultisamples() const {
	if ( d3d == nullptr ) {
		return 0;
	}
	D3DDISPLAYMODE mode = {};
	d3d->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, &mode );
	for ( int samples = 16; samples >= 2; --samples ) {
		if ( SUCCEEDED( d3d->CheckDeviceMultiSampleType( D3DADAPTER_DEFAULT,
				deviceType, mode.Format, TRUE,
				static_cast< D3DMULTISAMPLE_TYPE >( samples ), nullptr ) ) ) {
			return samples;
		}
	}
	return 0;
}

float idD3D9Renderer::PixelAspect() const {
	return 1.0f;
}

bool idD3D9Renderer::EnumerateModes( std::array< idD3D9Mode, 256 > & modes,
		int & count ) const {
	count = 0;
	if ( d3d == nullptr ) {
		return false;
	}
	static const D3DFORMAT formats[] = { D3DFMT_X8R8G8B8, D3DFMT_A8R8G8B8,
		D3DFMT_R5G6B5 };
	for ( D3DFORMAT format : formats ) {
		const UINT modeCount = d3d->GetAdapterModeCount( D3DADAPTER_DEFAULT, format );
		for ( UINT index = 0; index < modeCount && count < static_cast< int >( modes.size() ); ++index ) {
			D3DDISPLAYMODE mode = {};
			if ( FAILED( d3d->EnumAdapterModes( D3DADAPTER_DEFAULT, format, index, &mode ) ) ) {
				continue;
			}
			bool duplicate = false;
			for ( int existing = 0; existing < count; ++existing ) {
				duplicate |= modes[ existing ].width == static_cast< int >( mode.Width ) &&
					modes[ existing ].height == static_cast< int >( mode.Height ) &&
					modes[ existing ].refreshRate == static_cast< int >( mode.RefreshRate );
			}
			if ( !duplicate ) {
				modes[ count++ ] = { static_cast< int >( mode.Width ),
					static_cast< int >( mode.Height ), static_cast< int >( mode.RefreshRate ), mode.Format };
			}
		}
	}
	return count > 0;
}
