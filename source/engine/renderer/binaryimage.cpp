#include "binaryimage.h"

#include "image.h"
#include "imagetools/imageprocess.h"
#include "../../shared/idlib/filesystem/filesystem.h"

#include <algorithm>
#include <array>
#include <cstring>
#include <vector>

namespace {

static const int BIMAGE_MAGIC = 122505538;

unsigned short RGB565( const unsigned char * pixel ) {
	return static_cast< unsigned short >( ( ( pixel[0] >> 3 ) << 11 ) |
		( ( pixel[1] >> 2 ) << 5 ) | ( pixel[2] >> 3 ) );
}

void Expand565( unsigned short color, unsigned char * output ) {
	output[0] = static_cast< unsigned char >( ( ( color >> 11 ) & 31 ) * 255 / 31 );
	output[1] = static_cast< unsigned char >( ( ( color >> 5 ) & 63 ) * 255 / 63 );
	output[2] = static_cast< unsigned char >( ( color & 31 ) * 255 / 31 );
	output[3] = 255;
}

int ColorDistance( const unsigned char * a, const unsigned char * b ) {
	const int r = static_cast< int >( a[0] ) - b[0];
	const int g = static_cast< int >( a[1] ) - b[1];
	const int bl = static_cast< int >( a[2] ) - b[2];
	return r * r + 2 * g * g + bl * bl;
}

void BuildColorBlock( const unsigned char block[16][4], unsigned char * output,
		bool allowTransparent ) {
	int minLuma = 1000000, maxLuma = -1, minIndex = 0, maxIndex = 0;
	bool transparent = false;
	for ( int index = 0; index < 16; ++index ) {
		const int luma = 3 * block[index][0] + 6 * block[index][1] + block[index][2];
		if ( luma < minLuma ) { minLuma = luma; minIndex = index; }
		if ( luma > maxLuma ) { maxLuma = luma; maxIndex = index; }
		transparent |= block[index][3] < 128;
	}
	unsigned short color0 = RGB565( block[maxIndex] );
	unsigned short color1 = RGB565( block[minIndex] );
	if ( allowTransparent && transparent ) {
		if ( color0 > color1 ) std::swap( color0, color1 );
	} else if ( color0 <= color1 ) {
		std::swap( color0, color1 );
		if ( color0 == color1 ) color0 |= 1;
	}
	output[0] = static_cast< unsigned char >( color0 ); output[1] = color0 >> 8;
	output[2] = static_cast< unsigned char >( color1 ); output[3] = color1 >> 8;
	unsigned char palette[4][4] = {};
	Expand565( color0, palette[0] ); Expand565( color1, palette[1] );
	if ( color0 > color1 ) {
		for ( int component = 0; component < 3; ++component ) {
			palette[2][component] = static_cast<unsigned char>((2*palette[0][component]+palette[1][component])/3);
			palette[3][component] = static_cast<unsigned char>((palette[0][component]+2*palette[1][component])/3);
		}
		palette[2][3] = palette[3][3] = 255;
	} else {
		for ( int component = 0; component < 3; ++component )
			palette[2][component] = static_cast<unsigned char>((palette[0][component]+palette[1][component])/2);
		palette[2][3] = 255; palette[3][3] = 0;
	}
	unsigned int indices = 0;
	for ( int index = 0; index < 16; ++index ) {
		int best = allowTransparent && block[index][3] < 128 && color0 <= color1 ? 3 : 0;
		int bestDistance = best == 3 ? 0 : ColorDistance( block[index], palette[0] );
		for ( int candidate = 1; candidate < ( color0 > color1 ? 4 : 3 ); ++candidate ) {
			const int distance = ColorDistance( block[index], palette[candidate] );
			if ( distance < bestDistance ) { best = candidate; bestDistance = distance; }
		}
		indices |= static_cast<unsigned int>(best) << (index * 2);
	}
	std::memcpy( output + 4, &indices, sizeof( indices ) );
}

void BuildAlphaBlock( const unsigned char block[16][4], unsigned char * output ) {
	unsigned char minimum = 255, maximum = 0;
	for ( int index = 0; index < 16; ++index ) { minimum = std::min(minimum,block[index][3]); maximum = std::max(maximum,block[index][3]); }
	output[0] = maximum; output[1] = minimum;
	unsigned char palette[8] = { maximum, minimum, 0, 0, 0, 0, 0, 0 };
	if ( maximum > minimum ) {
		for ( int index = 1; index <= 6; ++index ) palette[index+1] =
			static_cast<unsigned char>(((7-index)*maximum+index*minimum)/7);
	} else {
		for ( int index = 1; index <= 4; ++index ) palette[index+1] =
			static_cast<unsigned char>(((5-index)*maximum+index*minimum)/5);
		palette[6] = 0; palette[7] = 255;
	}
	unsigned long long indices = 0;
	for ( int pixel = 0; pixel < 16; ++pixel ) {
		int best = 0, bestDistance = 1000;
		for ( int candidate = 0; candidate < 8; ++candidate ) {
			const int distance = std::abs( static_cast<int>(block[pixel][3]) - palette[candidate] );
			if ( distance < bestDistance ) { best = candidate; bestDistance = distance; }
		}
		indices |= static_cast<unsigned long long>(best) << (pixel * 3);
	}
	for ( int byte = 0; byte < 6; ++byte ) output[2+byte] = static_cast<unsigned char>(indices >> (byte*8));
}

void GatherBlock( const unsigned char * pixels, int width, int height,
		int blockX, int blockY, unsigned char block[16][4] ) {
	for ( int y = 0; y < 4; ++y ) for ( int x = 0; x < 4; ++x ) {
		const int sourceX = std::min( blockX * 4 + x, width - 1 );
		const int sourceY = std::min( blockY * 4 + y, height - 1 );
		std::memcpy( block[y*4+x], pixels + (sourceY*width+sourceX)*4, 4 );
	}
}

void CompressBC( const unsigned char * pixels, int width, int height,
		textureFormat_t format, unsigned char * output ) {
	const int blocksWide = std::max( 1, ( width + 3 ) / 4 );
	const int blocksHigh = std::max( 1, ( height + 3 ) / 4 );
	const int blockSize = format == FMT_DXT1 ? 8 : 16;
	for ( int y = 0; y < blocksHigh; ++y ) for ( int x = 0; x < blocksWide; ++x ) {
		unsigned char block[16][4]; GatherBlock( pixels, width, height, x, y, block );
		unsigned char * destination = output + (y*blocksWide+x)*blockSize;
		if ( format == FMT_DXT5 ) { BuildAlphaBlock( block, destination ); destination += 8; }
		BuildColorBlock( block, destination, format == FMT_DXT1 );
	}
}

std::vector<unsigned char> MipMapRGBA( const unsigned char * input, int width,
		int height ) {
	const int newWidth = std::max( width >> 1, 1 );
	const int newHeight = std::max( height >> 1, 1 );
	std::vector<unsigned char> output( static_cast<std::size_t>(newWidth)*newHeight*4 );
	for ( int y = 0; y < newHeight; ++y ) for ( int x = 0; x < newWidth; ++x ) {
		for ( int component = 0; component < 4; ++component ) {
			int total = 0;
			for ( int dy = 0; dy < 2; ++dy ) for ( int dx = 0; dx < 2; ++dx )
				total += input[((std::min(y*2+dy,height-1)*width)+std::min(x*2+dx,width-1))*4+component];
			output[(y*newWidth+x)*4+component] = static_cast<unsigned char>((total+2)/4);
		}
	}
	return output;
}

void WriteValue( idFile * file, const void * value, unsigned int size ) { file->Write( value, size ); }
bool ReadValue( idFile * file, void * value, unsigned int size ) { return file->Read( value, size ) == size; }

} // namespace

idBinaryImage::idBinaryImageData::idBinaryImageData() : level( 0 ), destZ( 0 ),
	width( 0 ), height( 0 ), dataSize( 0 ), data( 16 ) {}

void idBinaryImage::idBinaryImageData::Set( int imageLevel, int imageDestZ,
		int imageWidth, int imageHeight, int imageDataSize ) {
	level=imageLevel; destZ=imageDestZ; width=imageWidth; height=imageHeight;
	dataSize=std::max(imageDataSize,0); data.SetNum(dataSize);
}

idBinaryImage::idBinaryImage( const char * name ) : imgName( name != nullptr ? name : "" ),
	sourceFileTime( 0 ), binaryFileTime( 0 ), images( 16 ) {}

void idBinaryImage::Load2DFromMemory( int width, int height,
		const unsigned char * pixels ) {
	images.Clear();
	if ( pixels == nullptr || width <= 0 || height <= 0 ) return;
	opts.width=width; opts.height=height; opts.depth=1; opts.textureType=TT_2D;
	if ( opts.format == FMT_NONE ) {
		bool opaque=true; for ( int i=0;i<width*height;++i ) opaque &= pixels[i*4+3]==255;
		opts.format=opaque?FMT_DXT1:FMT_DXT5;
	}
	ComputeNumLevels( opts, imgName.c_str() );
	images.SetNum( opts.numLevels );
	std::vector<unsigned char> levelPixels( pixels, pixels + static_cast<std::size_t>(width)*height*4 );
	int levelWidth=width, levelHeight=height;
	for ( int level=0; level<opts.numLevels; ++level ) {
		idBinaryImageData & image=images[level];
		int dataSize=0;
		if ( opts.format==FMT_DXT1 || opts.format==FMT_DXT5 ) dataSize=
			std::max(1,(levelWidth+3)/4)*std::max(1,(levelHeight+3)/4)*(opts.format==FMT_DXT1?8:16);
		else dataSize=levelWidth*levelHeight*BitsForFormat(opts.format)/8;
		image.Set(level,0,levelWidth,levelHeight,dataSize);
		if ( opts.format==FMT_DXT1 || opts.format==FMT_DXT5 ) CompressBC(levelPixels.data(),levelWidth,levelHeight,opts.format,image.data.Ptr());
		else {
			for ( int pixel=0;pixel<levelWidth*levelHeight;++pixel ) {
				const unsigned char * source=&levelPixels[pixel*4];
				switch(opts.format){
					case FMT_ALPHA: image.data[pixel]=source[3]; break;
					case FMT_LUM8: case FMT_INT8: image.data[pixel]=source[0]; break;
					case FMT_L8A8: image.data[pixel*2]=source[0]; image.data[pixel*2+1]=source[3]; break;
					case FMT_RG8: image.data[pixel*2]=source[0]; image.data[pixel*2+1]=source[1]; break;
					default: if(pixel*4+3<dataSize) std::memcpy(image.data.Ptr()+pixel*4,source,4); break;
				}
			}
		}
		if(level+1<opts.numLevels) levelPixels=MipMapRGBA(levelPixels.data(),levelWidth,levelHeight);
		levelWidth=std::max(levelWidth>>1,1); levelHeight=std::max(levelHeight>>1,1);
	}
}

void idBinaryImage::LoadCubeFromMemory( int size,
		const unsigned char * const faces[6] ) {
	images.Clear(); if(size<=0 || faces==nullptr) return;
	opts.textureType=TT_CUBIC; opts.width=opts.height=size; opts.depth=1;
	if(opts.format==FMT_NONE) opts.format=FMT_DXT5;
	ComputeNumLevels(opts,imgName.c_str()); images.SetNum(opts.numLevels*6);
	for(int face=0;face<6;++face){
		if(faces[face]==nullptr) continue;
		std::vector<unsigned char> levelPixels(faces[face],faces[face]+static_cast<std::size_t>(size)*size*4);
		int dimension=size;
		for(int level=0;level<opts.numLevels;++level){
			idBinaryImageData & image=images[level*6+face];
			int dataSize=opts.format==FMT_DXT1?std::max(1,(dimension+3)/4)*std::max(1,(dimension+3)/4)*8:
				opts.format==FMT_DXT5?std::max(1,(dimension+3)/4)*std::max(1,(dimension+3)/4)*16:dimension*dimension*4;
			image.Set(level,face,dimension,dimension,dataSize);
			if(opts.format==FMT_DXT1||opts.format==FMT_DXT5) CompressBC(levelPixels.data(),dimension,dimension,opts.format,image.data.Ptr());
			else std::memcpy(image.data.Ptr(),levelPixels.data(),std::min<int>(dataSize,levelPixels.size()));
			if(level+1<opts.numLevels) levelPixels=MipMapRGBA(levelPixels.data(),dimension,dimension);
			dimension=std::max(dimension>>1,1);
		}
	}
}

void idBinaryImage::WriteGeneratedFile( const char * fileName ) {
	if(fileSystem==nullptr||fileName==nullptr) return;
	idFileLocal file(fileSystem->OpenFileWrite(fileName,FSPATH_CACHE)); if(file.file==nullptr) return;
	WriteValue(file.file,&sourceFileTime,4); WriteValue(file.file,&BIMAGE_MAGIC,4);
	WriteValue(file.file,&opts.textureType,4); WriteValue(file.file,&opts.width,4);
	WriteValue(file.file,&opts.height,4); WriteValue(file.file,&opts.depth,4);
	WriteValue(file.file,&opts.numLevels,4); WriteValue(file.file,&opts.cubeFilter,1);
	WriteValue(file.file,&opts.format,4); WriteValue(file.file,&opts.filter,4);
	WriteValue(file.file,&opts.repeat,4); unsigned char color=static_cast<unsigned char>(opts.colorFormat);
	WriteValue(file.file,&color,1);
	for(int index=0;index<images.Num();++index){ const idBinaryImageData & image=images[index];
		WriteValue(file.file,&image.level,4); WriteValue(file.file,&image.destZ,4);
		WriteValue(file.file,&image.width,4); WriteValue(file.file,&image.height,4);
		WriteValue(file.file,&image.dataSize,4); WriteValue(file.file,image.data.Ptr(),image.dataSize); }
}

bool idBinaryImage::LoadFromGeneratedFile( const char * fileName ) {
	if(fileSystem==nullptr||fileName==nullptr) return false;
	idFileLocal file(fileSystem->OpenFileRead(fileName,true,false)); if(file.file==nullptr) return false;
	binaryFileTime=file->Timestamp(); int magic=0; unsigned char color=0;
	if(!ReadValue(file.file,&sourceFileTime,4)||!ReadValue(file.file,&magic,4)||magic!=BIMAGE_MAGIC) return false;
	if(!ReadValue(file.file,&opts.textureType,4)||!ReadValue(file.file,&opts.width,4)||
		!ReadValue(file.file,&opts.height,4)||!ReadValue(file.file,&opts.depth,4)||
		!ReadValue(file.file,&opts.numLevels,4)||!ReadValue(file.file,&opts.cubeFilter,1)||
		!ReadValue(file.file,&opts.format,4)||!ReadValue(file.file,&opts.filter,4)||
		!ReadValue(file.file,&opts.repeat,4)||!ReadValue(file.file,&color,1)) return false;
	opts.colorFormat=static_cast<textureColor_t>(color);
	const int imageCount=opts.numLevels*(opts.textureType==TT_CUBIC?6:opts.textureType==TT_3D?opts.depth:1);
	if(imageCount<0||imageCount>16384||!images.SetNum(imageCount)) return false;
	for(int index=0;index<imageCount;++index){ idBinaryImageData & image=images[index];
		if(!ReadValue(file.file,&image.level,4)||!ReadValue(file.file,&image.destZ,4)||
			!ReadValue(file.file,&image.width,4)||!ReadValue(file.file,&image.height,4)||
			!ReadValue(file.file,&image.dataSize,4)||image.dataSize<0||image.dataSize>(1<<30)||
			!image.data.SetNum(image.dataSize)||!ReadValue(file.file,image.data.Ptr(),image.dataSize)) return false; }
	return true;
}

bool idBinaryImage::LoadFromSourceFile() {
	unsigned char * pixels = nullptr;
	int width = 0, height = 0;
	unsigned int timestamp = 0;
	if ( !R_LoadImageProgram( imgName.c_str(), &pixels, &width, &height,
			&timestamp ) || pixels == nullptr ) return false;
	sourceFileTime = timestamp;
	Load2DFromMemory( width, height, pixels );
	delete[] pixels;
	return images.Num() > 0;
}

void idImage::WriteBinaryImage( const char * name, idImageOpts imageOpts,
		const unsigned char * pixels, unsigned int sourceTimestamp ) {
	char generated[512]; MakeGeneratedName(generated,sizeof(generated),name);
	idBinaryImage image(name); image.opts=imageOpts; image.sourceFileTime=sourceTimestamp;
	image.Load2DFromMemory(imageOpts.width,imageOpts.height,pixels); image.WriteGeneratedFile(generated);
}
