#include "imageprocess.h"

#include "../jobs/transcode/image/dxt/dxtcodec.h"
#include "../../../shared/idlib/filesystem/filesystem.h"
#include "../../../shared/idlib/filesystem/file.h"

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <new>
#include <vector>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <objidl.h>
#include <wincodec.h>

#pragma comment( lib, "ole32.lib" )
#pragma comment( lib, "windowscodecs.lib" )

namespace {
	template< typename T > void Release( T *& object ) {
		if ( object != nullptr ) object->Release();
		object = nullptr;
	}

	bool ReadWholeFile( const char * name, std::vector< unsigned char > & bytes,
			unsigned int * timestamp ) {
		if ( fileSystem == nullptr || name == nullptr ) return false;
		void * data = nullptr;
		unsigned int fileTime = 0;
		const int length = fileSystem->ReadFile( name, &data, &fileTime );
		if ( length < 0 || data == nullptr ) return false;
		bytes.assign( static_cast< unsigned char * >( data ),
			static_cast< unsigned char * >( data ) + length );
		fileSystem->FreeFile( data );
		if ( timestamp != nullptr ) *timestamp = fileTime;
		return true;
	}

	bool DecodeWIC( const unsigned char * data, const unsigned int length,
			unsigned char ** pixels, int * width, int * height ) {
		if ( data == nullptr || length == 0 || pixels == nullptr ) return false;
		*pixels = nullptr;
		const HRESULT initializeResult = CoInitializeEx( nullptr, COINIT_MULTITHREADED );
		const bool uninitialize = SUCCEEDED( initializeResult );
		IWICImagingFactory * factory = nullptr;
		IWICStream * stream = nullptr;
		IWICBitmapDecoder * decoder = nullptr;
		IWICBitmapFrameDecode * frame = nullptr;
		IWICFormatConverter * converter = nullptr;
		bool success = false;
		if ( SUCCEEDED( CoCreateInstance( CLSID_WICImagingFactory, nullptr,
				CLSCTX_INPROC_SERVER, IID_PPV_ARGS( &factory ) ) ) &&
			SUCCEEDED( factory->CreateStream( &stream ) ) &&
			SUCCEEDED( stream->InitializeFromMemory( const_cast< BYTE * >( data ), length ) ) &&
			SUCCEEDED( factory->CreateDecoderFromStream( stream, nullptr,
				WICDecodeMetadataCacheOnDemand, &decoder ) ) &&
			SUCCEEDED( decoder->GetFrame( 0, &frame ) ) &&
			SUCCEEDED( factory->CreateFormatConverter( &converter ) ) &&
			SUCCEEDED( converter->Initialize( frame, GUID_WICPixelFormat32bppRGBA,
				WICBitmapDitherTypeNone, nullptr, 0.0, WICBitmapPaletteTypeCustom ) ) ) {
			UINT imageWidth = 0, imageHeight = 0;
			if ( SUCCEEDED( converter->GetSize( &imageWidth, &imageHeight ) ) &&
					imageWidth > 0 && imageHeight > 0 &&
					imageWidth <= 32768 && imageHeight <= 32768 ) {
				const std::size_t byteCount = static_cast< std::size_t >( imageWidth ) * imageHeight * 4;
				unsigned char * output = new ( std::nothrow ) unsigned char[byteCount];
				if ( output != nullptr && SUCCEEDED( converter->CopyPixels( nullptr,
					imageWidth * 4, static_cast< UINT >( byteCount ), output ) ) ) {
					*pixels = output;
					if ( width != nullptr ) *width = static_cast< int >( imageWidth );
					if ( height != nullptr ) *height = static_cast< int >( imageHeight );
					success = true;
				} else delete[] output;
			}
		}
		Release( converter ); Release( frame ); Release( decoder ); Release( stream ); Release( factory );
		if ( uninitialize ) CoUninitialize();
		return success;
	}

#pragma pack( push, 1 )
	struct tgaHeader_t {
		unsigned char idLength, colorMapType, imageType;
		unsigned short colorMapFirst, colorMapLength;
		unsigned char colorMapBits;
		unsigned short xOrigin, yOrigin, width, height;
		unsigned char pixelBits, attributes;
	};

	struct ddsPixelFormat_t {
		std::uint32_t size, flags, fourCC, rgbBits, redMask, greenMask, blueMask, alphaMask;
	};
	struct ddsHeader_t {
		std::uint32_t size, flags, height, width, pitchOrLinearSize, depth, mipCount;
		std::uint32_t reserved[11];
		ddsPixelFormat_t pixelFormat;
		std::uint32_t caps[5];
	};
#pragma pack( pop )

	unsigned char ExpandMask( const std::uint32_t value, const std::uint32_t mask ) {
		if ( mask == 0 ) return 255;
		unsigned int shift = 0, bits = 0;
		while ( ( ( mask >> shift ) & 1u ) == 0u ) ++shift;
		while ( ( ( mask >> ( shift + bits ) ) & 1u ) != 0u ) ++bits;
		const std::uint32_t component = ( value & mask ) >> shift;
		return static_cast< unsigned char >( component * 255u / ( ( 1u << bits ) - 1u ) );
	}

	bool DecodeDDS( const unsigned char * data, const unsigned int length,
			unsigned char ** pixels, int * width, int * height ) {
		if ( length < 4 + sizeof( ddsHeader_t ) || std::memcmp( data, "DDS ", 4 ) != 0 ) return false;
		const ddsHeader_t * header = reinterpret_cast< const ddsHeader_t * >( data + 4 );
		if ( header->size != 124 || header->width == 0 || header->height == 0 ||
				header->width > 32768 || header->height > 32768 ) return false;
		const unsigned char * source = data + 4 + sizeof( ddsHeader_t );
		const unsigned int available = length - 4 - sizeof( ddsHeader_t );
		const int imageWidth = static_cast< int >( header->width );
		const int imageHeight = static_cast< int >( header->height );
		unsigned char * output = new ( std::nothrow ) unsigned char[
			static_cast< std::size_t >( imageWidth ) * imageHeight * 4];
		if ( output == nullptr ) return false;
		const std::uint32_t DXT1 = 0x31545844u;
		const std::uint32_t DXT5 = 0x35545844u;
		if ( header->pixelFormat.fourCC == DXT1 || header->pixelFormat.fourCC == DXT5 ) {
			const int blockBytes = header->pixelFormat.fourCC == DXT1 ? 8 : 16;
			const unsigned int required = ( ( imageWidth + 3 ) / 4 ) *
				( ( imageHeight + 3 ) / 4 ) * blockBytes;
			if ( available < required ) { delete[] output; return false; }
			idDxtDecoder decoder;
			if ( blockBytes == 8 ) decoder.DecompressImageDXT1( source, output, imageWidth, imageHeight );
			else decoder.DecompressImageDXT5( source, output, imageWidth, imageHeight );
		} else if ( header->pixelFormat.rgbBits == 32 && available >=
				static_cast< unsigned int >( imageWidth * imageHeight * 4 ) ) {
			for ( int pixel = 0; pixel < imageWidth * imageHeight; ++pixel ) {
				std::uint32_t packed;
				std::memcpy( &packed, source + pixel * 4, 4 );
				output[pixel * 4 + 0] = ExpandMask( packed, header->pixelFormat.redMask );
				output[pixel * 4 + 1] = ExpandMask( packed, header->pixelFormat.greenMask );
				output[pixel * 4 + 2] = ExpandMask( packed, header->pixelFormat.blueMask );
				output[pixel * 4 + 3] = header->pixelFormat.alphaMask != 0 ?
					ExpandMask( packed, header->pixelFormat.alphaMask ) : 255;
			}
		} else { delete[] output; return false; }
		*pixels = output;
		if ( width != nullptr ) *width = imageWidth;
		if ( height != nullptr ) *height = imageHeight;
		return true;
	}

	bool EncodeWIC( const GUID & container, const char * fileName,
			const unsigned char * source, const int width, const int height,
			const bool flipVertical, const fsPath_t basePath, const bool jpeg ) {
		if ( fileSystem == nullptr || fileName == nullptr || source == nullptr || width <= 0 || height <= 0 ) return false;
		const HRESULT initializeResult = CoInitializeEx( nullptr, COINIT_MULTITHREADED );
		const bool uninitialize = SUCCEEDED( initializeResult );
		IWICImagingFactory * factory = nullptr;
		IWICBitmapEncoder * encoder = nullptr;
		IWICBitmapFrameEncode * frame = nullptr;
		IPropertyBag2 * properties = nullptr;
		IStream * memory = nullptr;
		bool success = false;
		std::vector< unsigned char > pixels;
		const int bytesPerPixel = jpeg ? 3 : 4;
		pixels.resize( static_cast< std::size_t >( width ) * height * bytesPerPixel );
		for ( int y = 0; y < height; ++y ) {
			const unsigned char * row = source + ( flipVertical ? height - 1 - y : y ) * width * 4;
			for ( int x = 0; x < width; ++x ) {
				unsigned char * destination = &pixels[( y * width + x ) * bytesPerPixel];
				if ( jpeg ) { destination[0] = row[x * 4 + 2]; destination[1] = row[x * 4 + 1]; destination[2] = row[x * 4 + 0]; }
				else std::memcpy( destination, row + x * 4, 4 );
			}
		}
		if ( SUCCEEDED( CreateStreamOnHGlobal( nullptr, TRUE, &memory ) ) &&
			SUCCEEDED( CoCreateInstance( CLSID_WICImagingFactory, nullptr,
				CLSCTX_INPROC_SERVER, IID_PPV_ARGS( &factory ) ) ) &&
			SUCCEEDED( factory->CreateEncoder( container, nullptr, &encoder ) ) &&
			SUCCEEDED( encoder->Initialize( memory, WICBitmapEncoderNoCache ) ) &&
			SUCCEEDED( encoder->CreateNewFrame( &frame, &properties ) ) &&
			SUCCEEDED( frame->Initialize( properties ) ) &&
			SUCCEEDED( frame->SetSize( width, height ) ) ) {
			WICPixelFormatGUID format = jpeg ? GUID_WICPixelFormat24bppBGR : GUID_WICPixelFormat32bppRGBA;
			if ( SUCCEEDED( frame->SetPixelFormat( &format ) ) &&
				SUCCEEDED( frame->WritePixels( height, width * bytesPerPixel,
					static_cast< UINT >( pixels.size() ), pixels.data() ) ) &&
				SUCCEEDED( frame->Commit() ) && SUCCEEDED( encoder->Commit() ) ) {
				HGLOBAL global = nullptr;
				if ( SUCCEEDED( GetHGlobalFromStream( memory, &global ) ) ) {
					const void * encoded = GlobalLock( global );
					const SIZE_T encodedSize = GlobalSize( global );
					idFileLocal file( fileSystem->OpenFileWrite( fileName, basePath ) );
					if ( encoded != nullptr && file.file != nullptr && encodedSize <= 0xffffffffu )
						success = file->Write( encoded, static_cast< unsigned int >( encodedSize ) ) == encodedSize;
					if ( encoded != nullptr ) GlobalUnlock( global );
				}
			}
		}
		Release( properties ); Release( frame ); Release( encoder ); Release( factory ); Release( memory );
		if ( uninitialize ) CoUninitialize();
		return success;
	}

	const char * Extension( const char * name ) {
		if ( name == nullptr ) return "";
		const char * forwardSlash = std::strrchr( name, '/' );
		const char * backSlash = std::strrchr( name, '\\' );
		const char * slash = forwardSlash == nullptr ? backSlash :
			( backSlash == nullptr ? forwardSlash : ( forwardSlash > backSlash ? forwardSlash : backSlash ) );
		const char * dot = std::strrchr( name, '.' );
		return dot != nullptr && ( slash == nullptr || dot > slash ) ? dot + 1 : "";
	}

	bool EqualsIgnoreCase( const char * a, const char * b ) {
		return a != nullptr && b != nullptr && _stricmp( a, b ) == 0;
	}
}

bool R_LoadTGA( const char *, const unsigned char * data,
		const unsigned int length, unsigned char ** pixels, int * width,
		int * height, unsigned int * ) {
	if ( data == nullptr || length < sizeof( tgaHeader_t ) || pixels == nullptr ) return false;
	const tgaHeader_t * header = reinterpret_cast< const tgaHeader_t * >( data );
	if ( header->colorMapType != 0 || header->width == 0 || header->height == 0 ||
			( header->imageType != 2 && header->imageType != 3 && header->imageType != 10 && header->imageType != 11 ) ||
			( header->pixelBits != 8 && header->pixelBits != 24 && header->pixelBits != 32 ) ) return false;
	const int imageWidth = header->width, imageHeight = header->height;
	unsigned char * output = new ( std::nothrow ) unsigned char[
		static_cast< std::size_t >( imageWidth ) * imageHeight * 4];
	if ( output == nullptr ) return false;
	const unsigned char * source = data + sizeof( tgaHeader_t ) + header->idLength;
	const unsigned char * end = data + length;
	const int sourceBytes = header->pixelBits / 8;
	int pixel = 0;
	auto emit = [&]( const unsigned char * value ) {
		const int fileY = pixel / imageWidth;
		const int x = pixel % imageWidth;
		const int y = ( header->attributes & 0x20 ) != 0 ? fileY : imageHeight - 1 - fileY;
		unsigned char * destination = output + ( y * imageWidth + x ) * 4;
		if ( sourceBytes == 1 ) destination[0] = destination[1] = destination[2] = value[0];
		else { destination[0] = value[2]; destination[1] = value[1]; destination[2] = value[0]; }
		destination[3] = sourceBytes == 4 ? value[3] : 255;
		++pixel;
	};
	if ( header->imageType == 2 || header->imageType == 3 ) {
		while ( pixel < imageWidth * imageHeight && source + sourceBytes <= end ) { emit( source ); source += sourceBytes; }
	} else {
		while ( pixel < imageWidth * imageHeight && source < end ) {
			const unsigned char packet = *source++;
			const int count = ( packet & 0x7f ) + 1;
			if ( ( packet & 0x80 ) != 0 ) {
				if ( source + sourceBytes > end ) break;
				const unsigned char * value = source; source += sourceBytes;
				for ( int index = 0; index < count && pixel < imageWidth * imageHeight; ++index ) emit( value );
			} else {
				for ( int index = 0; index < count && pixel < imageWidth * imageHeight; ++index ) {
					if ( source + sourceBytes > end ) break;
					emit( source ); source += sourceBytes;
				}
			}
		}
	}
	if ( pixel != imageWidth * imageHeight ) { delete[] output; return false; }
	*pixels = output;
	if ( width != nullptr ) *width = imageWidth;
	if ( height != nullptr ) *height = imageHeight;
	return true;
}

bool R_LoadTGA( const char * name, unsigned char ** pixels, int * width,
		int * height, unsigned int * timestamp ) {
	std::vector< unsigned char > bytes;
	return ReadWholeFile( name, bytes, timestamp ) &&
		R_LoadTGA( name, bytes.data(), static_cast< unsigned int >( bytes.size() ),
			pixels, width, height, timestamp );
}

bool R_LoadPNG( const char * name, unsigned char ** pixels, int * width,
		int * height, unsigned int * timestamp ) {
	std::vector< unsigned char > bytes;
	return ReadWholeFile( name, bytes, timestamp ) &&
		DecodeWIC( bytes.data(), static_cast< unsigned int >( bytes.size() ), pixels, width, height );
}

void R_LoadImage( const char * name, unsigned char ** pixels, int * width,
		int * height, unsigned int * timestamp ) {
	if ( pixels != nullptr ) *pixels = nullptr;
	if ( width != nullptr ) *width = 0;
	if ( height != nullptr ) *height = 0;
	if ( timestamp != nullptr ) *timestamp = 0;
	if ( name == nullptr || pixels == nullptr ) return;
	const char * extension = Extension( name );
	if ( EqualsIgnoreCase( extension, "tga" ) ) { R_LoadTGA( name, pixels, width, height, timestamp ); return; }
	std::vector< unsigned char > bytes;
	if ( !ReadWholeFile( name, bytes, timestamp ) ) {
		if ( extension[0] == '\0' ) {
			const char * suffixes[] = { ".tga", ".png", ".jpg", ".jpeg", ".bmp", ".dds" };
			for ( const char * suffix : suffixes ) {
				std::vector< char > candidate( std::strlen( name ) + std::strlen( suffix ) + 1 );
				std::strcpy( candidate.data(), name ); std::strcat( candidate.data(), suffix );
				R_LoadImage( candidate.data(), pixels, width, height, timestamp );
				if ( *pixels != nullptr ) return;
			}
		}
		return;
	}
	if ( EqualsIgnoreCase( extension, "dds" ) )
		DecodeDDS( bytes.data(), static_cast< unsigned int >( bytes.size() ), pixels, width, height );
	else DecodeWIC( bytes.data(), static_cast< unsigned int >( bytes.size() ), pixels, width, height );
}

void R_LoadImageDimensions( const char * name, int * width, int * height,
		unsigned int * timestamp ) {
	unsigned char * pixels = nullptr;
	R_LoadImage( name, &pixels, width, height, timestamp );
	delete[] pixels;
}

bool R_LoadCubeImages( const char * imageName, unsigned char * faces[6],
		int * size, unsigned int * timestamp ) {
	if ( imageName == nullptr || faces == nullptr ) return false;
	const char * suffixes[6] = { "_px", "_nx", "_py", "_ny", "_pz", "_nz" };
	const char * extension = Extension( imageName );
	const char * extensionWithDot = extension[0] != '\0' ? extension - 1 : imageName + std::strlen( imageName );
	const std::size_t baseLength = static_cast< std::size_t >( extensionWithDot - imageName );
	int dimension = 0;
	unsigned int newest = 0;
	for ( int face = 0; face < 6; ++face ) {
		const std::size_t suffixLength = std::strlen( suffixes[face] );
		const std::size_t extensionLength = std::strlen( extensionWithDot );
		std::vector< char > name( baseLength + suffixLength + extensionLength + 1 );
		std::memcpy( name.data(), imageName, baseLength );
		std::memcpy( name.data() + baseLength, suffixes[face], suffixLength );
		std::memcpy( name.data() + baseLength + suffixLength, extensionWithDot, extensionLength + 1 );
		int width = 0, height = 0; unsigned int fileTime = 0;
		R_LoadImage( name.data(), &faces[face], &width, &height, &fileTime );
		if ( faces[face] == nullptr || width != height || ( face > 0 && width != dimension ) ) {
			for ( int release = 0; release <= face; ++release ) { delete[] faces[release]; faces[release] = nullptr; }
			return false;
		}
		dimension = width; newest = (std::max)( newest, fileTime );
	}
	if ( size != nullptr ) *size = dimension;
	if ( timestamp != nullptr ) *timestamp = newest;
	return true;
}

void R_ReorganizeCubeImages( unsigned char * faces[6], int size ) {
	if ( faces == nullptr || size <= 0 ) return;
	// The PC D3D cube convention differs from the 360 only in the handedness
	// of the Y faces for the recovered source naming scheme.
	R_HorizontalFlip( faces[2], size, size );
	R_HorizontalFlip( faces[3], size, size );
}

bool R_WritePNG( const char * name, const unsigned char * data, int width,
		int height, bool flipVertical, fsPath_t basePath ) {
	return EncodeWIC( GUID_ContainerFormatPng, name, data, width, height,
		flipVertical, basePath, false );
}

bool R_WriteJPG( const char * name, const unsigned char * data, int width,
		int height, fsPath_t basePath, bool flipVertical ) {
	return EncodeWIC( GUID_ContainerFormatJpeg, name, data, width, height,
		flipVertical, basePath, true );
}

bool R_WriteTGA( const char * name, const unsigned char * data, int width,
		int height, int bytesPerPixel, bool flipVertical, bool swapRedBlue,
		fsPath_t basePath ) {
	if ( fileSystem == nullptr || name == nullptr || data == nullptr || width <= 0 || height <= 0 ||
			( bytesPerPixel != 3 && bytesPerPixel != 4 ) ) return false;
	idFileLocal file( fileSystem->OpenFileWrite( name, basePath ) );
	if ( file.file == nullptr ) return false;
	tgaHeader_t header = {};
	header.imageType = 2; header.width = static_cast< unsigned short >( width );
	header.height = static_cast< unsigned short >( height ); header.pixelBits = bytesPerPixel * 8;
	header.attributes = bytesPerPixel == 4 ? 0x28 : 0x20;
	if ( file->Write( &header, sizeof( header ) ) != sizeof( header ) ) return false;
	std::vector< unsigned char > row( static_cast< std::size_t >( width ) * bytesPerPixel );
	for ( int y = 0; y < height; ++y ) {
		const unsigned char * source = data + ( flipVertical ? height - 1 - y : y ) * width * bytesPerPixel;
		for ( int x = 0; x < width; ++x ) {
			for ( int component = 0; component < bytesPerPixel; ++component ) row[x * bytesPerPixel + component] = source[x * bytesPerPixel + component];
			if ( swapRedBlue ) std::swap( row[x * bytesPerPixel + 0], row[x * bytesPerPixel + 2] );
		}
		if ( file->Write( row.data(), static_cast< unsigned int >( row.size() ) ) != row.size() ) return false;
	}
	return true;
}
