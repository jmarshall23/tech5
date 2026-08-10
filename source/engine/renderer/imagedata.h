#pragma once

class idImageData {
public:
	idImageData();
	~idImageData();
	idImageData( const idImageData & ) = delete;
	idImageData & operator=( const idImageData & ) = delete;

	int width;
	int height;
	unsigned char * data;
	float * floatData;
};

