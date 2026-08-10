#include "seenbits.h"

#include <algorithm>
#include <cstring>
#include <new>

idSeenBits::idSeenBits() : merges( 0 ), layoutVersion( 0 ), width( 0 ),
	coarsestLevel( 0 ), bitArraySize( 0 ), bits( nullptr ), levelOffset{} {}

idSeenBits::~idSeenBits() {
	delete[] bits;
	bits = nullptr;
	bitArraySize = 0;
}

bool idSeenBits::Init( const int pageWidth, const int coarsestMip,
		const int version ) {
	delete[] bits;
	bits = nullptr;
	merges = 0;
	layoutVersion = version;
	width = (std::max)( pageWidth, 0 );
	coarsestLevel = (std::max)( 0, (std::min)( coarsestMip, 31 ) );
	std::memset( levelOffset, 0, sizeof( levelOffset ) );
	std::int64_t totalBits = 0;
	for ( int level = 0; level <= coarsestLevel; ++level ) {
		levelOffset[level] = totalBits;
		const std::int64_t levelWidth = (std::max)( width >> level, 1 );
		totalBits += levelWidth * levelWidth;
	}
	bitArraySize = ( totalBits + 7 ) >> 3;
	if ( bitArraySize <= 0 ) return true;
	bits = new ( std::nothrow ) unsigned char[static_cast< std::size_t >( bitArraySize )]();
	if ( bits == nullptr ) { bitArraySize = 0; width = 0; return false; }
	return true;
}

void idSeenBits::Clear() {
	if ( bits != nullptr ) std::memset( bits, 0, static_cast< std::size_t >( bitArraySize ) );
	merges = 0;
}

std::int64_t idSeenBits::BitIndex( const int level, const int x,
		const int y ) const {
	if ( bits == nullptr || level < 0 || level > coarsestLevel ) return -1;
	const int levelWidth = (std::max)( width >> level, 1 );
	if ( x < 0 || y < 0 || x >= levelWidth || y >= levelWidth ) return -1;
	return levelOffset[level] + static_cast< std::int64_t >( y ) * levelWidth + x;
}

bool idSeenBits::Get( const int level, const int x, const int y ) const {
	const std::int64_t bit = BitIndex( level, x, y );
	return bit >= 0 && ( bits[bit >> 3] & ( 1u << ( bit & 7 ) ) ) != 0;
}

void idSeenBits::Set( const int level, const int x, const int y ) {
	const std::int64_t bit = BitIndex( level, x, y );
	if ( bit >= 0 ) bits[bit >> 3] |= static_cast< unsigned char >( 1u << ( bit & 7 ) );
}

void idSeenBits::Clear( const int level, const int x, const int y ) {
	const std::int64_t bit = BitIndex( level, x, y );
	if ( bit >= 0 ) bits[bit >> 3] &= static_cast< unsigned char >( ~( 1u << ( bit & 7 ) ) );
}

void idSeenBits::Merge( const idSeenBits & source ) {
	if ( bits == nullptr || source.bits == nullptr || width != source.width ||
			coarsestLevel != source.coarsestLevel || layoutVersion != source.layoutVersion ) return;
	const std::int64_t bytes = (std::min)( bitArraySize, source.bitArraySize );
	for ( std::int64_t index = 0; index < bytes; ++index ) bits[index] |= source.bits[index];
	++merges;
}
