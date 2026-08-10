#include "imageprocess.h"

#include "../../../shared/idlib/sys/sys_alloc.h"
#include "../../../shared/idlib/text/parser.h"
#include "../../../shared/idlib/text/str.h"

#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <new>
#include <string>

namespace {
	struct programImage_t {
		programImage_t() : pixels( nullptr ), width( 0 ), height( 0 ), timestamp( 0 ) {}
		~programImage_t() { delete[] pixels; }
		programImage_t( const programImage_t & ) = delete;
		programImage_t & operator=( const programImage_t & ) = delete;
		unsigned char * Release() { unsigned char * result = pixels; pixels = nullptr; return result; }
		unsigned char * pixels;
		int width;
		int height;
		unsigned int timestamp;
	};

	class imageProgramParser_t {
	public:
		explicit imageProgramParser_t( const char * text ) : cursor( text != nullptr ? text : "" ) {}

		bool Parse( programImage_t & output ) { return ParseImage( output ); }

	private:
		const char * cursor;

		void SkipWhitespace() { while ( *cursor != '\0' && std::isspace( static_cast< unsigned char >( *cursor ) ) ) ++cursor; }

		std::string Token() {
			SkipWhitespace();
			if ( *cursor == '\0' ) return {};
			if ( *cursor == '(' || *cursor == ')' || *cursor == ',' ) return std::string( 1, *cursor++ );
			const char * start = cursor;
			while ( *cursor != '\0' && !std::isspace( static_cast< unsigned char >( *cursor ) ) &&
					*cursor != '(' && *cursor != ')' && *cursor != ',' ) ++cursor;
			return std::string( start, cursor );
		}

		bool Consume( const char value ) {
			SkipWhitespace();
			if ( *cursor != value ) return false;
			++cursor;
			return true;
		}

		float Number( bool & okay ) {
			const std::string token = Token();
			char * end = nullptr;
			const float value = std::strtof( token.c_str(), &end );
			okay = end != token.c_str() && *end == '\0';
			return value;
		}

		bool FinishUnary( programImage_t & image ) { return image.pixels != nullptr && Consume( ')' ); }

		bool MatchDimensions( programImage_t & first, programImage_t & second ) {
			if ( first.pixels == nullptr || second.pixels == nullptr ) return false;
			if ( first.width == second.width && first.height == second.height ) return true;
			unsigned char * resized = R_ResampleTexture( second.pixels, second.width,
				second.height, first.width, first.height );
			if ( resized == nullptr ) return false;
			delete[] second.pixels;
			second.pixels = resized;
			second.width = first.width;
			second.height = first.height;
			return true;
		}

		bool ParseTwoImages( programImage_t & first, programImage_t & second ) {
			return Consume( '(' ) && ParseImage( first ) && Consume( ',' ) &&
				ParseImage( second ) && Consume( ')' ) && MatchDimensions( first, second );
		}

		void MakeIntrinsic( const std::string & name, programImage_t & output ) {
			output.width = output.height = 8;
			output.pixels = new ( std::nothrow ) unsigned char[8 * 8 * 4];
			if ( output.pixels == nullptr ) return;
			for ( int pixel = 0; pixel < 64; ++pixel ) {
				unsigned char * color = output.pixels + pixel * 4;
				if ( _stricmp( name.c_str(), "_flat" ) == 0 ) {
					color[0] = color[1] = 128; color[2] = 255; color[3] = 255;
				} else if ( _stricmp( name.c_str(), "_black" ) == 0 ) {
					color[0] = color[1] = color[2] = 0; color[3] = 255;
				} else {
					color[0] = color[1] = color[2] = color[3] = 255;
				}
			}
		}

		bool ParseImage( programImage_t & output ) {
			const std::string operation = Token();
			if ( operation.empty() ) return false;
			SkipWhitespace();
			if ( *cursor != '(' ) {
				if ( operation[0] == '_' ) MakeIntrinsic( operation, output );
				else R_LoadImage( operation.c_str(), &output.pixels, &output.width,
					&output.height, &output.timestamp );
				return output.pixels != nullptr;
			}

			if ( _stricmp( operation.c_str(), "heightmap" ) == 0 ) {
				if ( !Consume( '(' ) || !ParseImage( output ) || !Consume( ',' ) ) return false;
				bool okay; const float scale = Number( okay );
				if ( !okay || !Consume( ')' ) ) return false;
				unsigned char * normal = new ( std::nothrow ) unsigned char[
					static_cast< std::size_t >( output.width ) * output.height * 4];
				if ( normal == nullptr ) return false;
				for ( int y = 0; y < output.height; ++y ) for ( int x = 0; x < output.width; ++x ) {
					auto heightAt = [&]( int sx, int sy ) { sx = ( sx + output.width ) % output.width; sy = ( sy + output.height ) % output.height;
						const unsigned char * p = output.pixels + ( sy * output.width + sx ) * 4; return ( p[0] + p[1] + p[2] ) / ( 3.0f * 255.0f ); };
					float nx = ( heightAt( x - 1, y ) - heightAt( x + 1, y ) ) * scale;
					float ny = ( heightAt( x, y - 1 ) - heightAt( x, y + 1 ) ) * scale;
					float nz = 1.0f;
					const float inverse = 1.0f / std::sqrt( nx * nx + ny * ny + nz * nz ); nx *= inverse; ny *= inverse; nz *= inverse;
					unsigned char * p = normal + ( y * output.width + x ) * 4;
					p[0] = static_cast< unsigned char >( nx * 127.5f + 127.5f ); p[1] = static_cast< unsigned char >( ny * 127.5f + 127.5f );
					p[2] = static_cast< unsigned char >( nz * 127.5f + 127.5f ); p[3] = 255;
				}
				delete[] output.pixels; output.pixels = normal; return true;
			}

			if ( _stricmp( operation.c_str(), "addnormals" ) == 0 ) {
				programImage_t second;
				if ( !ParseTwoImages( output, second ) ) return false;
				for ( int pixel = 0; pixel < output.width * output.height; ++pixel ) {
					float x = output.pixels[pixel * 4] + second.pixels[pixel * 4] - 255.0f;
					float y = output.pixels[pixel * 4 + 1] + second.pixels[pixel * 4 + 1] - 255.0f;
					float z = output.pixels[pixel * 4 + 2] + second.pixels[pixel * 4 + 2] - 255.0f;
					const float length = std::sqrt( x * x + y * y + z * z ); if ( length > 0.0f ) { x /= length; y /= length; z /= length; }
					output.pixels[pixel * 4] = static_cast< unsigned char >( x * 127.5f + 127.5f );
					output.pixels[pixel * 4 + 1] = static_cast< unsigned char >( y * 127.5f + 127.5f );
					output.pixels[pixel * 4 + 2] = static_cast< unsigned char >( z * 127.5f + 127.5f );
				}
				output.timestamp = (std::max)( output.timestamp, second.timestamp ); return true;
			}

			if ( _stricmp( operation.c_str(), "multiplyImages" ) == 0 ||
					_stricmp( operation.c_str(), "add" ) == 0 ||
					_stricmp( operation.c_str(), "patchAlpha" ) == 0 ) {
				programImage_t second;
				if ( !ParseTwoImages( output, second ) ) return false;
				for ( int pixel = 0; pixel < output.width * output.height; ++pixel ) {
					if ( _stricmp( operation.c_str(), "patchAlpha" ) == 0 ) output.pixels[pixel * 4 + 3] = second.pixels[pixel * 4 + 3];
					else for ( int component = 0; component < 4; ++component ) {
						const int index = pixel * 4 + component;
						output.pixels[index] = _stricmp( operation.c_str(), "add" ) == 0 ?
							static_cast< unsigned char >( (std::min)( 255, output.pixels[index] + second.pixels[index] ) ) :
							static_cast< unsigned char >( ( output.pixels[index] * second.pixels[index] + 127 ) / 255 );
					}
				}
				output.timestamp = (std::max)( output.timestamp, second.timestamp ); return true;
			}

			if ( _stricmp( operation.c_str(), "constantColor" ) == 0 ) {
				if ( !Consume( '(' ) ) return false;
				float values[4];
				for ( int component = 0; component < 4; ++component ) { bool okay; values[component] = Number( okay ); if ( !okay || ( component < 3 && !Consume( ',' ) ) ) return false; }
				if ( !Consume( ')' ) ) return false;
				output.width = output.height = 8; output.pixels = new unsigned char[8 * 8 * 4];
				for ( int pixel = 0; pixel < 64; ++pixel ) for ( int component = 0; component < 4; ++component ) output.pixels[pixel * 4 + component] =
					static_cast< unsigned char >( (std::max)( 0.0f, (std::min)( 255.0f, values[component] * 255.0f ) ) );
				return true;
			}

			if ( _stricmp( operation.c_str(), "scale" ) == 0 ) {
				if ( !Consume( '(' ) || !ParseImage( output ) ) return false;
				float values[4];
				for ( int component = 0; component < 4; ++component ) { if ( !Consume( ',' ) ) return false; bool okay; values[component] = Number( okay ); if ( !okay ) return false; }
				if ( !Consume( ')' ) ) return false;
				for ( int pixel = 0; pixel < output.width * output.height; ++pixel ) for ( int component = 0; component < 4; ++component )
					output.pixels[pixel * 4 + component] = static_cast< unsigned char >( (std::max)( 0.0f,
						(std::min)( 255.0f, output.pixels[pixel * 4 + component] * values[component] ) ) );
				return true;
			}

			if ( _stricmp( operation.c_str(), "resize" ) == 0 ||
					_stricmp( operation.c_str(), "atlasBorder" ) == 0 ) {
				if ( !Consume( '(' ) || !ParseImage( output ) || !Consume( ',' ) ) return false;
				bool okay; const int targetWidth = static_cast< int >( Number( okay ) ); if ( !okay || !Consume( ',' ) ) return false;
				const int targetHeight = static_cast< int >( Number( okay ) ); if ( !okay || !Consume( ')' ) ) return false;
				if ( _stricmp( operation.c_str(), "resize" ) == 0 ) {
					output.pixels = R_Resize( output.Release(), output.width, output.height, targetWidth, targetHeight );
					output.width = targetWidth; output.height = targetHeight;
				} else output.pixels = R_AtlasBorder( output.Release(), &output.width,
					&output.height, targetWidth, targetHeight );
				return output.pixels != nullptr;
			}

			if ( !Consume( '(' ) || !ParseImage( output ) ) return false;
			if ( !FinishUnary( output ) ) return false;
			if ( _stricmp( operation.c_str(), "invertAlpha" ) == 0 ) {
				for ( int pixel = 0; pixel < output.width * output.height; ++pixel ) output.pixels[pixel * 4 + 3] = 255 - output.pixels[pixel * 4 + 3];
			} else if ( _stricmp( operation.c_str(), "invertColor" ) == 0 ) {
				for ( int pixel = 0; pixel < output.width * output.height; ++pixel ) for ( int component = 0; component < 3; ++component ) output.pixels[pixel * 4 + component] = 255 - output.pixels[pixel * 4 + component];
			} else if ( _stricmp( operation.c_str(), "makeIntensity" ) == 0 ) {
				for ( int pixel = 0; pixel < output.width * output.height; ++pixel ) { const unsigned char intensity = output.pixels[pixel * 4]; for ( int component = 0; component < 4; ++component ) output.pixels[pixel * 4 + component] = intensity; }
			} else if ( _stricmp( operation.c_str(), "makeAlpha" ) == 0 ) {
				for ( int pixel = 0; pixel < output.width * output.height; ++pixel ) { const unsigned char alpha = static_cast< unsigned char >( ( output.pixels[pixel * 4] + output.pixels[pixel * 4 + 1] + output.pixels[pixel * 4 + 2] ) / 3 ); output.pixels[pixel * 4] = output.pixels[pixel * 4 + 1] = output.pixels[pixel * 4 + 2] = 255; output.pixels[pixel * 4 + 3] = alpha; }
			} else if ( _stricmp( operation.c_str(), "extractAlpha" ) == 0 ) {
				for ( int pixel = 0; pixel < output.width * output.height; ++pixel ) { const unsigned char alpha = output.pixels[pixel * 4 + 3]; output.pixels[pixel * 4] = output.pixels[pixel * 4 + 1] = output.pixels[pixel * 4 + 2] = alpha; output.pixels[pixel * 4 + 3] = 255; }
			} else if ( _stricmp( operation.c_str(), "divideAlpha" ) == 0 ) {
				for ( int pixel = 0; pixel < output.width * output.height; ++pixel ) { const int alpha = output.pixels[pixel * 4 + 3]; if ( alpha > 0 ) for ( int component = 0; component < 3; ++component ) output.pixels[pixel * 4 + component] = static_cast< unsigned char >( (std::min)( 255, output.pixels[pixel * 4 + component] * 255 / alpha ) ); }
			} else if ( _stricmp( operation.c_str(), "makeDivergence" ) == 0 ) {
				R_SetAlphaNormalDivergence( output.pixels, output.width, output.height );
			} else if ( _stricmp( operation.c_str(), "smoothnormals" ) == 0 ) {
				unsigned char * smooth = R_ResampleTexture( output.pixels, output.width, output.height, output.width, output.height );
				if ( smooth != nullptr ) { delete[] output.pixels; output.pixels = smooth; }
			} else if ( _stricmp( operation.c_str(), "nameBase" ) != 0 ) return false;
			return true;
		}
	};
}

unsigned char * R_AtlasBorder( unsigned char * input, int * width,
		int * height, const int maxWidth, const int maxHeight ) {
	if ( input == nullptr || width == nullptr || height == nullptr || *width <= 0 || *height <= 0 ) return input;
	const int extraX = (std::max)( 0, maxWidth - *width );
	const int extraY = (std::max)( 0, maxHeight - *height );
	const int left = (std::min)( 4, extraX );
	const int right = (std::min)( 4, (std::max)( 0, extraX - left ) );
	const int top = (std::min)( 4, extraY );
	const int bottom = (std::min)( 4, (std::max)( 0, extraY - top ) );
	const int outputWidth = *width + left + right;
	const int outputHeight = *height + top + bottom;
	unsigned char * output = new ( std::nothrow ) unsigned char[
		static_cast< std::size_t >( outputWidth ) * outputHeight * 4];
	if ( output == nullptr ) return input;
	for ( int y = 0; y < outputHeight; ++y ) for ( int x = 0; x < outputWidth; ++x ) {
		const int sourceX = (std::max)( 0, (std::min)( *width - 1, x - left ) );
		const int sourceY = (std::max)( 0, (std::min)( *height - 1, y - top ) );
		std::memcpy( output + ( y * outputWidth + x ) * 4,
			input + ( sourceY * *width + sourceX ) * 4, 4 );
	}
	delete[] input;
	*width = outputWidth;
	*height = outputHeight;
	return output;
}

unsigned char * R_Resize( unsigned char * input, const int width,
		const int height, const int outputWidth, const int outputHeight ) {
	if ( input == nullptr || outputWidth <= 0 || outputHeight <= 0 ) return input;
	unsigned char * output = R_ResampleTexture( input, width, height, outputWidth, outputHeight );
	if ( output != nullptr ) delete[] input;
	return output != nullptr ? output : input;
}

bool R_LoadImageProgram( const char * program, unsigned char ** pixels,
		int * width, int * height, unsigned int * timestamp ) {
	if ( pixels != nullptr ) *pixels = nullptr;
	if ( width != nullptr ) *width = 0;
	if ( height != nullptr ) *height = 0;
	if ( timestamp != nullptr ) *timestamp = 0;
	if ( program == nullptr || pixels == nullptr ) return false;
	programImage_t image;
	imageProgramParser_t parser( program );
	if ( !parser.Parse( image ) || image.pixels == nullptr ) return false;
	*pixels = image.Release();
	if ( width != nullptr ) *width = image.width;
	if ( height != nullptr ) *height = image.height;
	if ( timestamp != nullptr ) *timestamp = image.timestamp;
	return true;
}

idStr R_ParsePastImageProgram( idParser & parser ) {
	idStr result;
	idToken token;
	int depth = 0;
	bool started = false;
	while ( parser.ReadToken( token ) ) {
		if ( started && token.type != TT_PUNCTUATION ) result.Append( " " );
		result.Append( token.c_str() );
		started = true;
		if ( idStr::Cmp( token.c_str(), "(" ) == 0 ) ++depth;
		else if ( idStr::Cmp( token.c_str(), ")" ) == 0 ) {
			if ( depth > 0 ) --depth;
			if ( depth == 0 ) break;
		} else if ( depth == 0 ) break;
	}
	return result;
}
