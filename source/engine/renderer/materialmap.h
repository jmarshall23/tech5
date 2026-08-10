#pragma once

#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/atomicstring.h"
#include "idlib/text/str.h"

class idFile;
class idMaterial;

struct idVirtualImageFile {
	idAtomicString fileName;
	unsigned int timeStamp;
};

class idMaterialMapping {
public:
	idMaterialMapping();

	idAtomicString materialName;
	unsigned int materialChecksum;
	unsigned int materialTimestamp;
	int x;
	int y;
	int width;
	int height;
	idVec4 scaleBias;
	idVirtualImageFile specularFile;
	idVirtualImageFile coverFile;
	idVirtualImageFile diffuseFile;
	idVirtualImageFile bumpFile;
	idVirtualImageFile powerFile;
};

class idMaterialMap {
public:
	idMaterialMap();
	const idMaterialMapping * FindMapping( const char * materialName ) const;
	bool GetImageDimensions( int & imageWidth, int & imageHeight ) const;
	void Clear();
	bool Load( idFile * file );
	void Save( idFile * file ) const;

	idStr name;
	int width;
	int height;
	unsigned int skinFileTimeStamp;
	idList< idMaterialMapping, 46 > mappings;
};
