#include "imagedata.h"

idImageData::idImageData() : width( 0 ), height( 0 ), data( nullptr ),
	floatData( nullptr ) {
}

idImageData::~idImageData() {
	delete[] data;
	delete[] floatData;
}

