/*
===========================================================================

Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company. 

This file is part of the Doom 3 BFG Edition GPL Source Code ("Doom 3 BFG Edition Source Code").  

Doom 3 BFG Edition Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 BFG Edition Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 BFG Edition Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#ifndef __WIN_LOCAL_H__
#define __WIN_LOCAL_H__

#include <windows.h>
#include <mmsystem.h>
#include <gl/gl.h>
#ifndef DIRECTINPUT_VERSION
#define DIRECTINPUT_VERSION 0x0800
#endif
#include <dinput.h>
#include "win_input.h"

// Licensee strings recovered for the Tungsten build.  The original Windows
// project supplied these through framework/Licensee.h.
#ifndef GAME_NAME
#define GAME_NAME "Tungsten"
#endif
#ifndef WIN32_CONSOLE_CLASS
#define WIN32_CONSOLE_CLASS "Tungsten_WinConsole"
#endif
#ifndef WIN32_WINDOW_CLASS_NAME
#define WIN32_WINDOW_CLASS_NAME "Tungsten"
#endif
#ifndef WIN32_FAKE_WINDOW_CLASS_NAME
#define WIN32_FAKE_WINDOW_CLASS_NAME "Tungsten_WGL_FAKE"
#endif
#ifndef SAVE_PATH
#define SAVE_PATH "\\MachineGames\\Tungsten"
#endif

static const int MAX_CRITICAL_SECTIONS = 4;

// The Windows SDK no longer ships wglext.h.  Keep the extension surface used
// by this backend local to sys/win32, matching the Khronos/BFG declarations.
DECLARE_HANDLE( HPBUFFERARB );
typedef const char * ( WINAPI * PFNWGLGETEXTENSIONSSTRINGARBPROC )( HDC );
typedef BOOL ( WINAPI * PFNWGLSWAPINTERVALEXTPROC )( int );
typedef BOOL ( WINAPI * PFNWGLGETPIXELFORMATATTRIBIVARBPROC )( HDC, int, int, UINT, const int *, int * );
typedef BOOL ( WINAPI * PFNWGLGETPIXELFORMATATTRIBFVARBPROC )( HDC, int, int, UINT, const int *, FLOAT * );
typedef BOOL ( WINAPI * PFNWGLCHOOSEPIXELFORMATARBPROC )( HDC, const int *, const FLOAT *, UINT, int *, UINT * );
typedef HPBUFFERARB ( WINAPI * PFNWGLCREATEPBUFFERARBPROC )( HDC, int, int, int, const int * );
typedef HDC ( WINAPI * PFNWGLGETPBUFFERDCARBPROC )( HPBUFFERARB );
typedef int ( WINAPI * PFNWGLRELEASEPBUFFERDCARBPROC )( HPBUFFERARB, HDC );
typedef BOOL ( WINAPI * PFNWGLDESTROYPBUFFERARBPROC )( HPBUFFERARB );
typedef BOOL ( WINAPI * PFNWGLQUERYPBUFFERARBPROC )( HPBUFFERARB, int, int * );
typedef BOOL ( WINAPI * PFNWGLBINDTEXIMAGEARBPROC )( HPBUFFERARB, int );
typedef BOOL ( WINAPI * PFNWGLRELEASETEXIMAGEARBPROC )( HPBUFFERARB, int );
typedef BOOL ( WINAPI * PFNWGLSETPBUFFERATTRIBARBPROC )( HPBUFFERARB, const int * );
typedef HGLRC ( WINAPI * PFNWGLCREATECONTEXTATTRIBSARBPROC )( HDC, HGLRC, const int * );

// The Xbox-derived renderer declarations do not carry the Win32 OpenGL
// configuration boundary.  These are the exact BFG PC-side data contracts
// consumed and populated by win_glimp.cpp.
enum stereo3DMode_t {
	STEREO3D_OFF,
	STEREO3D_SIDE_BY_SIDE_COMPRESSED,
	STEREO3D_TOP_AND_BOTTOM_COMPRESSED,
	STEREO3D_SIDE_BY_SIDE,
	STEREO3D_INTERLACED,
	STEREO3D_QUAD_BUFFER,
	STEREO3D_HDMI_720
};

enum graphicsVendor_t {
	VENDOR_NVIDIA,
	VENDOR_AMD,
	VENDOR_INTEL
};

struct glconfig_t {
	const char * renderer_string;
	const char * vendor_string;
	const char * version_string;
	const char * extensions_string;
	const char * wgl_extensions_string;
	const char * shading_language_string;
	float glVersion;
	graphicsVendor_t vendor;
	int maxTextureSize;
	int maxTextureCoords;
	int maxTextureImageUnits;
	int uniformBufferOffsetAlignment;
	float maxTextureAnisotropy;
	int colorBits;
	int depthBits;
	int stencilBits;
	bool multitextureAvailable;
	bool directStateAccess;
	bool textureCompressionAvailable;
	bool anisotropicFilterAvailable;
	bool textureLODBiasAvailable;
	bool seamlessCubeMapAvailable;
	bool sRGBFramebufferAvailable;
	bool vertexBufferObjectAvailable;
	bool mapBufferRangeAvailable;
	bool vertexArrayObjectAvailable;
	bool drawElementsBaseVertexAvailable;
	bool fragmentProgramAvailable;
	bool glslAvailable;
	bool uniformBufferAvailable;
	bool twoSidedStencilAvailable;
	bool depthBoundsTestAvailable;
	bool syncAvailable;
	bool timerQueryAvailable;
	bool occlusionQueryAvailable;
	bool debugOutputAvailable;
	bool swapControlTearAvailable;
	stereo3DMode_t stereo3Dmode;
	int nativeScreenWidth;
	int nativeScreenHeight;
	int displayFrequency;
	int isFullscreen;
	bool isStereoPixelFormat;
	bool stereoPixelFormatAvailable;
	int multisamples;
	float physicalScreenWidthInCentimeters;
	float pixelAspect;
	GLuint global_vao;
};

struct vidMode_t {
	int width;
	int height;
	int displayHz;
	bool operator==( const vidMode_t & other ) const {
		return width == other.width && height == other.height && displayHz == other.displayHz;
	}
};

struct glimpParms_t {
	int x;
	int y;
	int width;
	int height;
	int fullScreen;
	bool stereo;
	int displayHz;
	int multiSamples;
};

extern glconfig_t glConfig;
extern idCVar r_swapInterval;
extern idCVar r_debugContext;
extern idCVar r_glDriver;
extern idCVar r_logFile;

typedef void ( * GLExtension_t )( void );
extern "C" GLExtension_t GLimp_ExtensionPointer( const char * name );
void GLimp_EnableLogging( bool enable );

extern void ( APIENTRY * qglDisable )( GLenum cap );
extern void ( APIENTRY * qglClearColor )( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha );
extern void ( APIENTRY * qglClear )( GLbitfield mask );
extern void ( APIENTRY * qglFinish )( void );
extern HGLRC ( WINAPI * qwglCreateContext )( HDC );
extern BOOL ( WINAPI * qwglDeleteContext )( HGLRC );
extern PROC ( WINAPI * qwglGetProcAddress )( LPCSTR );
extern BOOL ( WINAPI * qwglMakeCurrent )( HDC, HGLRC );
extern BOOL ( WINAPI * qwglSwapBuffers )( HDC );

#define WGL_SAMPLE_BUFFERS_ARB                    0x2041
#define WGL_SAMPLES_ARB                           0x2042
#define WGL_DOUBLE_BUFFER_ARB                     0x2011
#define WGL_STEREO_ARB                            0x2012
#define WGL_RED_BITS_ARB                          0x2015
#define WGL_GREEN_BITS_ARB                        0x2017
#define WGL_BLUE_BITS_ARB                         0x2019
#define WGL_ALPHA_BITS_ARB                        0x201B
#define WGL_DEPTH_BITS_ARB                        0x2022
#define WGL_STENCIL_BITS_ARB                      0x2023
#define WGL_CONTEXT_DEBUG_BIT_ARB                 0x00000001
#define WGL_CONTEXT_MAJOR_VERSION_ARB             0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB             0x2092
#define WGL_CONTEXT_FLAGS_ARB                     0x2094
#define WGL_CONTEXT_PROFILE_MASK_ARB              0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB          0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#define ERROR_INVALID_VERSION_ARB                  0x2095
#define ERROR_INVALID_PROFILE_ARB                  0x2096

// WGL_ARB_extensions_string
extern	PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB;

// WGL_EXT_swap_interval
extern	PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;

// WGL_ARB_pixel_format
extern	PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribivARB;
extern	PFNWGLGETPIXELFORMATATTRIBFVARBPROC wglGetPixelFormatAttribfvARB;
extern	PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;

// WGL_ARB_pbuffer
extern	PFNWGLCREATEPBUFFERARBPROC	wglCreatePbufferARB;
extern	PFNWGLGETPBUFFERDCARBPROC	wglGetPbufferDCARB;
extern	PFNWGLRELEASEPBUFFERDCARBPROC	wglReleasePbufferDCARB;
extern	PFNWGLDESTROYPBUFFERARBPROC	wglDestroyPbufferARB;
extern	PFNWGLQUERYPBUFFERARBPROC	wglQueryPbufferARB;

// WGL_ARB_render_texture 
extern	PFNWGLBINDTEXIMAGEARBPROC		wglBindTexImageARB;
extern	PFNWGLRELEASETEXIMAGEARBPROC	wglReleaseTexImageARB;
extern	PFNWGLSETPBUFFERATTRIBARBPROC	wglSetPbufferAttribARB;

#define	WINDOW_STYLE	(WS_OVERLAPPED|WS_BORDER|WS_CAPTION|WS_VISIBLE | WS_THICKFRAME)

void	Sys_QueEvent( sysEventType_t type, int value, int value2, int ptrLength, void *ptr, int inputDeviceNum );

void	Sys_CreateConsole();
void	Sys_DestroyConsole();

char	*Sys_ConsoleInput ();
char	*Sys_GetCurrentUser();

void	Win_SetErrorText( const char *text );

cpuid_t	Sys_GetCPUId();

// Input subsystem

void	IN_Init ();
void	IN_Shutdown ();
// add additional non keyboard / non mouse movement on top of the keyboard move cmd

void	IN_DeactivateMouseIfWindowed();
void	IN_DeactivateMouse();
void	IN_ActivateMouse();

void	IN_Frame();

void	DisableTaskKeys( BOOL bDisable, BOOL bBeep, BOOL bTaskMgr );

uint64 Sys_Microseconds();

// window procedure
LONG WINAPI MainWndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void Conbuf_AppendText( const char *msg );
void GLimp_Shutdown();

struct Win32Vars_t {
	HWND			hWnd;
	HINSTANCE		hInstance;

	bool			activeApp;			// changed with WM_ACTIVATE messages
	bool			mouseReleased;		// when the game has the console down or is doing a long operation
	bool			movingWindow;		// inhibit mouse grab when dragging the window
	bool			mouseGrabbed;		// current state of grab and hide

	OSVERSIONINFOEX	osversion;

	cpuid_t			cpuid;

	// when we get a windows message, we store the time off so keyboard processing
	// can know the exact time of an event (not really needed now that we use async direct input)
	int				sysMsgTime;

	bool			windowClassRegistered;

	WNDPROC			wndproc;

	HDC				hDC;							// handle to device context
	HGLRC			hGLRC;						// handle to GL rendering context
	PIXELFORMATDESCRIPTOR pfd;		
	int				pixelformat;

	HINSTANCE		hinstOpenGL;	// HINSTANCE for the OpenGL library

	int				desktopBitsPixel;
	int				desktopWidth, desktopHeight;

	int				cdsFullscreen;	// 0 = not fullscreen, otherwise monitor number

	idFileHandle	log_fp;

	unsigned short	oldHardwareGamma[3][256];
	// desktop gamma is saved here for restoration at exit

	static idCVar	sys_arch;
	static idCVar	sys_cpustring;
	static idCVar	in_mouse;
	static idCVar	win_allowAltTab;
	static idCVar	win_notaskkeys;
	static idCVar	win_username;
	static idCVar	win_outputEditString;
	static idCVar	win_viewlog;
	static idCVar	win_timerUpdate;
	static idCVar	win_allowMultipleInstances;

	CRITICAL_SECTION criticalSections[MAX_CRITICAL_SECTIONS];

	HINSTANCE		hInstDI;			// direct input

	LPDIRECTINPUT8			g_pdi;
	LPDIRECTINPUTDEVICE8	g_pMouse;
	LPDIRECTINPUTDEVICE8	g_pKeyboard;
	idJoystickWin32			g_Joystick;

	HANDLE			renderCommandsEvent;
	HANDLE			renderCompletedEvent;
	HANDLE			renderActiveEvent;
	HANDLE			renderThreadHandle;
	unsigned long	renderThreadId;
	void			(*glimpRenderThread)();
	void			*smpData;
	int				wglErrors;
	// SMP acceleration vars

};

extern Win32Vars_t	win32;

#endif /* !__WIN_LOCAL_H__ */
