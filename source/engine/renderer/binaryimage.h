#pragma once

#include "renderer_types.h"
#include "../../shared/idlib/containers/list.h"
#include "../../shared/idlib/text/str.h"

class idFile;

class idBinaryImage {
public:
	class idBinaryImageData {
	public:
		idBinaryImageData();
		void Set( int imageLevel, int imageDestZ, int imageWidth,
			int imageHeight, int imageDataSize );

		int level;
		int destZ;
		int width;
		int height;
		int dataSize;
		idList< unsigned char, 34 > data;
	};

	explicit idBinaryImage( const char * name = "" );
	void WriteGeneratedFile( const char * fileName );
	void Load2DFromMemory( int width, int height, const unsigned char * pixels );
	void LoadCubeFromMemory( int size, const unsigned char * const faces[6] );
	bool LoadFromGeneratedFile( const char * fileName );
	bool LoadFromSourceFile();

	idStr imgName;
	unsigned int sourceFileTime;
	unsigned int binaryFileTime;
	idImageOpts opts;
	idList< idBinaryImageData, 34 > images;
};

