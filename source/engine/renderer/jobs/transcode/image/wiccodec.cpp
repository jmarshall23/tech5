#include "wiccodec.h"

#include <algorithm>
#include <cstddef>
#include <cstring>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <objidl.h>
#include <propidl.h>
#include <wincodec.h>

#pragma comment( lib, "ole32.lib" )
#pragma comment( lib, "windowscodecs.lib" )

namespace {
	template< typename T > void Release( T *& object ) {
		if ( object != nullptr ) object->Release();
		object = nullptr;
	}

	class scopedCom_t {
	public:
		scopedCom_t() : result( CoInitializeEx( nullptr, COINIT_MULTITHREADED ) ) {}
		~scopedCom_t() { if ( result == S_OK || result == S_FALSE ) CoUninitialize(); }
	private:
		HRESULT result;
	};
}

bool RendererWICDecode( const unsigned char * data, const unsigned int dataLength,
		std::vector< unsigned char > & rgba, int & width, int & height ) {
	rgba.clear();
	width = height = 0;
	if ( data == nullptr || dataLength == 0 ) return false;
	scopedCom_t com;
	IWICImagingFactory * factory = nullptr;
	IWICStream * stream = nullptr;
	IWICBitmapDecoder * decoder = nullptr;
	IWICBitmapFrameDecode * frame = nullptr;
	IWICFormatConverter * converter = nullptr;
	bool success = false;
	if ( SUCCEEDED( CoCreateInstance( CLSID_WICImagingFactory, nullptr,
			CLSCTX_INPROC_SERVER, IID_PPV_ARGS( &factory ) ) ) &&
		SUCCEEDED( factory->CreateStream( &stream ) ) &&
		SUCCEEDED( stream->InitializeFromMemory( const_cast< BYTE * >( data ), dataLength ) ) &&
		SUCCEEDED( factory->CreateDecoderFromStream( stream, nullptr,
			WICDecodeMetadataCacheOnLoad, &decoder ) ) &&
		SUCCEEDED( decoder->GetFrame( 0, &frame ) ) &&
		SUCCEEDED( factory->CreateFormatConverter( &converter ) ) &&
		SUCCEEDED( converter->Initialize( frame, GUID_WICPixelFormat32bppRGBA,
			WICBitmapDitherTypeNone, nullptr, 0.0, WICBitmapPaletteTypeCustom ) ) ) {
		UINT w = 0, h = 0;
		if ( SUCCEEDED( converter->GetSize( &w, &h ) ) && w > 0 && h > 0 &&
			w <= 32768 && h <= 32768 ) {
			const std::size_t bytes = static_cast< std::size_t >( w ) * h * 4;
			rgba.resize( bytes );
			if ( SUCCEEDED( converter->CopyPixels( nullptr, w * 4,
				static_cast< UINT >( bytes ), rgba.data() ) ) ) {
				width = static_cast< int >( w );
				height = static_cast< int >( h );
				success = true;
			} else rgba.clear();
		}
	}
	Release( converter );
	Release( frame );
	Release( decoder );
	Release( stream );
	Release( factory );
	return success;
}

bool RendererWICEncode( const unsigned char * rgba, const int width, const int height,
		const int bytePitch, const rendererWICContainer_t container, float quality,
		std::vector< unsigned char > & encoded ) {
	encoded.clear();
	if ( rgba == nullptr || width <= 0 || height <= 0 || bytePitch < width * 4 ) return false;
	scopedCom_t com;
	IWICImagingFactory * factory = nullptr;
	IStream * stream = nullptr;
	IWICBitmapEncoder * encoder = nullptr;
	IWICBitmapFrameEncode * frame = nullptr;
	IPropertyBag2 * properties = nullptr;
	HGLOBAL memory = nullptr;
	bool success = false;
	const GUID & format = container == RENDERER_WIC_JPEG_XR ?
		GUID_ContainerFormatWmp : GUID_ContainerFormatJpeg;
	quality = (std::max)( 0.01f, (std::min)( quality, 1.0f ) );
	if ( SUCCEEDED( CoCreateInstance( CLSID_WICImagingFactory, nullptr,
			CLSCTX_INPROC_SERVER, IID_PPV_ARGS( &factory ) ) ) &&
		SUCCEEDED( CreateStreamOnHGlobal( nullptr, TRUE, &stream ) ) &&
		SUCCEEDED( factory->CreateEncoder( format, nullptr, &encoder ) ) &&
		SUCCEEDED( encoder->Initialize( stream, WICBitmapEncoderNoCache ) ) &&
		SUCCEEDED( encoder->CreateNewFrame( &frame, &properties ) ) ) {
		if ( properties != nullptr ) {
			PROPBAG2 option = {};
			option.pstrName = const_cast< LPOLESTR >( L"ImageQuality" );
			VARIANT value;
			VariantInit( &value );
			value.vt = VT_R4;
			value.fltVal = quality;
			properties->Write( 1, &option, &value );
			VariantClear( &value );
		}
		WICPixelFormatGUID pixelFormat = GUID_WICPixelFormat24bppBGR;
		std::vector< unsigned char > bgr( static_cast< std::size_t >( width ) * height * 3 );
		for ( int y = 0; y < height; ++y ) {
			const unsigned char * source = rgba + y * bytePitch;
			unsigned char * target = bgr.data() + static_cast< std::size_t >( y ) * width * 3;
			for ( int x = 0; x < width; ++x ) {
				target[x * 3 + 0] = source[x * 4 + 2];
				target[x * 3 + 1] = source[x * 4 + 1];
				target[x * 3 + 2] = source[x * 4 + 0];
			}
		}
		if ( SUCCEEDED( frame->Initialize( properties ) ) &&
			SUCCEEDED( frame->SetSize( width, height ) ) &&
			SUCCEEDED( frame->SetPixelFormat( &pixelFormat ) ) &&
			SUCCEEDED( frame->WritePixels( height, width * 3,
				static_cast< UINT >( bgr.size() ), bgr.data() ) ) &&
			SUCCEEDED( frame->Commit() ) && SUCCEEDED( encoder->Commit() ) &&
			SUCCEEDED( GetHGlobalFromStream( stream, &memory ) ) ) {
			const SIZE_T bytes = GlobalSize( memory );
			const void * source = GlobalLock( memory );
			if ( source != nullptr && bytes > 0 ) {
				encoded.assign( static_cast< const unsigned char * >( source ),
					static_cast< const unsigned char * >( source ) + bytes );
				GlobalUnlock( memory );
				success = true;
			}
		}
	}
	Release( properties );
	Release( frame );
	Release( encoder );
	Release( stream );
	Release( factory );
	return success;
}
