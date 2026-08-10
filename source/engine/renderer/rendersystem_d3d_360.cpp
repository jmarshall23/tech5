#include "rendersystem_local.h"

#include <array>
#include <cstring>

// PDB-authentic filename retained; implementation translated to Windows D3D9.

namespace {
bool rendererOwnsWindow = false;

LRESULT CALLBACK RendererWindowProc( HWND window, UINT message, WPARAM wParam,
	LPARAM lParam ) {
	if ( message == WM_CLOSE ) { ShowWindow( window, SW_HIDE ); return 0; }
	return DefWindowProc( window, message, wParam, lParam );
}

HWND CreateFallbackRendererWindow( int width, int height ) {
	HINSTANCE instance = GetModuleHandle( nullptr );
	WNDCLASSA windowClass = {};
	windowClass.style = CS_OWNDC;
	windowClass.lpfnWndProc = RendererWindowProc;
	windowClass.hInstance = instance;
	windowClass.hCursor = LoadCursor( nullptr, IDC_ARROW );
	windowClass.lpszClassName = "idTech5D3D9Window";
	RegisterClassA( &windowClass );
	RECT rect = { 0, 0, width, height };
	AdjustWindowRect( &rect, WS_OVERLAPPEDWINDOW, FALSE );
	HWND window = CreateWindowA( windowClass.lpszClassName, "idTech 5",
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		rect.right - rect.left, rect.bottom - rect.top, nullptr, nullptr,
		instance, nullptr );
	rendererOwnsWindow = window != nullptr;
	return window;
}
}

void idRenderSystemLocal::InitContext() {
	HWND window = GetActiveWindow();
	if ( window == nullptr ) window = GetForegroundWindow();
	if ( window == nullptr ) window = CreateFallbackRendererWindow( windowWidth, windowHeight );
	if ( window != nullptr && rendererD3D9.Initialize( window, windowWidth,
		windowHeight, false, multisamples, true ) ) {
		renderWidth = windowWidth = rendererD3D9.Width();
		renderHeight = windowHeight = rendererD3D9.Height();
		renderingIsReadyForSwapbuffers = true;
	}
}

void idRenderSystemLocal::SwapBuffers( void *, bool ) { rendererD3D9.Present(); }

void idRenderSystemLocal::SetGamma( unsigned short * red,
		unsigned short * green, unsigned short * blue ) {
	if ( red == nullptr || green == nullptr || blue == nullptr ) return;
	WORD ramp[3][256];
	for ( int index = 0; index < 256; ++index ) {
		ramp[0][index] = red[index]; ramp[1][index] = green[index]; ramp[2][index] = blue[index];
		gammaTable[index] = green[index];
	}
	if ( IsFullscreen() ) {
		HDC dc = GetDC( static_cast< HWND >( GetGameWindow() ) );
		if ( dc != nullptr ) { SetDeviceGammaRamp( dc, ramp ); ReleaseDC( static_cast< HWND >( GetGameWindow() ), dc ); }
	}
}

void * idRenderSystemLocal::GetGameWindow() { return rendererD3D9.GetWindow(); }
int idRenderSystemLocal::GetHeight() { return rendererD3D9.Height(); }
float idRenderSystemLocal::GetPixelAspect() { return rendererD3D9.PixelAspect(); }
stereoRenderMode_t idRenderSystemLocal::GetStereoRenderMode() { return STEREO_RENDER_OFF; }

int idRenderSystemLocal::GetNumMonitors() { return GetSystemMetrics( SM_CMONITORS ); }
void idRenderSystemLocal::GetMonitorSize( int monitor, int * width, int * height ) {
	DISPLAY_DEVICEA device = {}; device.cb = sizeof( device );
	DEVMODEA mode = {}; mode.dmSize = sizeof( mode );
	if ( EnumDisplayDevicesA( nullptr, monitor, &device, 0 ) &&
			EnumDisplaySettingsA( device.DeviceName, ENUM_CURRENT_SETTINGS, &mode ) ) {
		if ( width ) *width = static_cast< int >( mode.dmPelsWidth );
		if ( height ) *height = static_cast< int >( mode.dmPelsHeight );
	} else { if ( width ) *width = GetSystemMetrics( SM_CXSCREEN ); if ( height ) *height = GetSystemMetrics( SM_CYSCREEN ); }
}
int idRenderSystemLocal::GetCurrentMonitor() { return 0; }

bool idRenderSystemLocal::EnumerateModes( int index, int * width, int * height,
		int * refreshRate ) {
	std::array< idD3D9Mode, 256 > modes;
	int count = 0;
	if ( !rendererD3D9.EnumerateModes( modes, count ) || index < 0 || index >= count ) return false;
	if ( width ) *width = modes[index].width;
	if ( height ) *height = modes[index].height;
	if ( refreshRate ) *refreshRate = modes[index].refreshRate;
	return true;
}

void idRenderSystemLocal::ShowGameWindow() { if ( GetGameWindow() ) ShowWindow( static_cast<HWND>(GetGameWindow()), SW_SHOW ); }
void idRenderSystemLocal::HideGameWindow() { if ( GetGameWindow() ) ShowWindow( static_cast<HWND>(GetGameWindow()), SW_HIDE ); }
bool idRenderSystemLocal::IsFullscreen() { return rendererD3D9.IsFullscreen(); }
void idRenderSystemLocal::GoWindowed() { ResetContext( GetWidth(), GetHeight(), false, multisamples ); }
void idRenderSystemLocal::GoFullScreen() { ResetContext( GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), true, multisamples ); }
