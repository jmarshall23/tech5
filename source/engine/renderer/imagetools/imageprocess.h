#pragma once

#include "../../../shared/idlib/filesystem/file.h"

class idParser;
class idStr;

struct imageProperties_t {
	const class idMaterial * mtr;
	int x;
	int y;
	int width;
	int height;
	int area;
};

bool R_LoadTGA( const char * name, const unsigned char * fileData,
	unsigned int fileLength, unsigned char ** pixels, int * width,
	int * height, unsigned int * timestamp = nullptr );
bool R_LoadTGA( const char * name, unsigned char ** pixels, int * width,
	int * height, unsigned int * timestamp = nullptr );
bool R_LoadPNG( const char * name, unsigned char ** pixels, int * width,
	int * height, unsigned int * timestamp = nullptr );
void R_LoadImage( const char * name, unsigned char ** pixels, int * width,
	int * height, unsigned int * timestamp = nullptr );
void R_LoadImageDimensions( const char * name, int * width, int * height,
	unsigned int * timestamp = nullptr );
bool R_LoadCubeImages( const char * imageName, unsigned char * faces[6],
	int * size, unsigned int * timestamp = nullptr );
void R_ReorganizeCubeImages( unsigned char * faces[6], int size );

bool R_WritePNG( const char * fileName, const unsigned char * data,
	int width, int height, bool flipVertical = false,
	fsPath_t basePath = FSPATH_BASE );
bool R_WriteJPG( const char * fileName, const unsigned char * data,
	int width, int height, fsPath_t basePath = FSPATH_BASE,
	bool flipVertical = false );
bool R_WriteTGA( const char * fileName, const unsigned char * data,
	int width, int height, int bytesPerPixel = 4, bool flipVertical = false,
	bool swapRedBlue = true, fsPath_t basePath = FSPATH_BASE );

unsigned char * R_ResampleTexture( const unsigned char * input,
	int inputWidth, int inputHeight, int outputWidth, int outputHeight );
unsigned char * R_Dropsample( const unsigned char * input,
	int inputWidth, int inputHeight, int outputWidth, int outputHeight );
unsigned char * R_MipMap( const unsigned char * input, int width, int height );
void R_HorizontalFlip( unsigned char * data, int width, int height );
void R_VerticalFlip( unsigned char * data, int width, int height );
void R_RotatePic( unsigned char * data, int width );
void R_SetAlphaNormalDivergence( unsigned char * data, int width, int height );
void R_FilterCube( unsigned char * faces[6], int size );
void R_BlendCubeBorders( unsigned char * faces[6], int size );

unsigned char * R_AtlasBorder( unsigned char * input, int * width,
	int * height, int borderWidth, int borderHeight );
unsigned char * R_Resize( unsigned char * input, int width, int height,
	int outputWidth, int outputHeight );
bool R_LoadImageProgram( const char * program, unsigned char ** pixels,
	int * width, int * height, unsigned int * timestamp = nullptr );
idStr R_ParsePastImageProgram( idParser & parser );
