#pragma once

#include <algorithm>
#include <vector>

class VertexCache {
public:
	explicit VertexCache( int size = 16 ) : entries( (std::max)( size, 1 ), -1 ) {}
	int AddEntry( int entry );
	bool InCache( int entry ) const;
	void Clear() { std::fill( entries.begin(), entries.end(), -1 ); }

private:
	std::vector< int > entries;
};
struct NvFaceInfo {
	NvFaceInfo( unsigned short a = 0, unsigned short b = 0, unsigned short c = 0 )
		: m_stripId( -1 ), m_testStripId( -1 ) { m_v0 = a; m_v1 = b; m_v2 = c; }
	unsigned short m_v0, m_v1, m_v2;
	int m_stripId;
	int m_testStripId;
};

struct NvEdgeInfo {
	unsigned short v0, v1;
	NvFaceInfo * face0;
	NvFaceInfo * face1;
};

class NvStripInfo {
public:
	explicit NvStripInfo( int stripId = -1 ) : m_stripId( stripId ), m_experimentId( -1 ) {}
	bool IsInStrip( const NvFaceInfo * face ) const;
	bool Unique( std::vector< NvFaceInfo * > & faces, NvFaceInfo * face );
	bool SharesEdge( const NvFaceInfo * face ) const;
	std::vector< NvFaceInfo * > m_faces;
	int m_stripId;
	int m_experimentId;
};

class NvStripifier {
public:
	void Stripify( const std::vector< unsigned short > & indices,
		int cacheSize, int minStripSize, unsigned short maxIndex,
		std::vector< NvStripInfo * > & strips,
		std::vector< NvFaceInfo * > & leftovers );
	void CreateStrips( const std::vector< NvStripInfo * > & strips,
		std::vector< int > & output, bool stitch, unsigned int & numSeparateStrips,
		bool restart, unsigned int restartIndex );
};
