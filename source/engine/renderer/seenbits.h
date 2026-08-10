#pragma once

#include <cstdint>

class idSeenBits {
public:
	idSeenBits();
	~idSeenBits();
	idSeenBits( const idSeenBits & ) = delete;
	idSeenBits & operator=( const idSeenBits & ) = delete;

	bool Init( int pageWidth, int coarsestMip, int version = 0 );
	void Clear();
	bool Get( int level, int x, int y ) const;
	void Set( int level, int x, int y );
	void Clear( int level, int x, int y );
	void Merge( const idSeenBits & source );

	int merges;
	int layoutVersion;
	int width;
	int coarsestLevel;
	std::int64_t bitArraySize;
	unsigned char * bits;
	std::int64_t levelOffset[32];

private:
	std::int64_t BitIndex( int level, int x, int y ) const;
};
