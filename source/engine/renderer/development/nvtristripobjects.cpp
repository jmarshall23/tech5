#include "nvtristripobjects.h"

int VertexCache::AddEntry( const int entry ) {
	const int removed = entries.back();
	for ( std::size_t i = entries.size() - 1; i > 0; --i ) entries[i] = entries[i - 1];
	entries[0] = entry;
	return removed;
}
bool VertexCache::InCache( const int entry ) const {
	return std::find( entries.begin(), entries.end(), entry ) != entries.end();
}
bool NvStripInfo::IsInStrip( const NvFaceInfo * face ) const {
	return face != nullptr && ( m_experimentId < 0 ? face->m_stripId : face->m_testStripId ) == m_stripId;
}
bool NvStripInfo::Unique( std::vector< NvFaceInfo * > & faces, NvFaceInfo * face ) {
	if ( std::find( faces.begin(), faces.end(), face ) != faces.end() ) return false;
	faces.push_back( face ); return true;
}
namespace {
	int SharedVertices( const NvFaceInfo * a, const NvFaceInfo * b ) {
		const unsigned short av[3] = { a->m_v0, a->m_v1, a->m_v2 };
		const unsigned short bv[3] = { b->m_v0, b->m_v1, b->m_v2 };
		int shared = 0;
		for ( int i = 0; i < 3; ++i ) for ( int j = 0; j < 3; ++j )
			if ( av[i] == bv[j] ) { ++shared; break; }
		return shared;
	}
}
bool NvStripInfo::SharesEdge( const NvFaceInfo * face ) const {
	for ( const NvFaceInfo * existing : m_faces ) if ( SharedVertices( existing, face ) >= 2 ) return true;
	return false;
}
void NvStripifier::Stripify( const std::vector< unsigned short > & indices,
		const int, const int minStripSize, const unsigned short maxIndex,
		std::vector< NvStripInfo * > & strips, std::vector< NvFaceInfo * > & leftovers ) {
	std::vector< NvFaceInfo * > faces;
	for ( std::size_t i = 0; i + 2 < indices.size(); i += 3 ) {
		if ( indices[i] > maxIndex || indices[i + 1] > maxIndex || indices[i + 2] > maxIndex ) continue;
		if ( indices[i] == indices[i + 1] || indices[i] == indices[i + 2] || indices[i + 1] == indices[i + 2] ) continue;
		faces.push_back( new NvFaceInfo( indices[i], indices[i + 1], indices[i + 2] ) );
	}
	int stripId = 0;
	for ( NvFaceInfo * seed : faces ) {
		if ( seed->m_stripId >= 0 ) continue;
		NvStripInfo * strip = new NvStripInfo( stripId++ );
		strip->m_faces.push_back( seed ); seed->m_stripId = strip->m_stripId;
		for ( bool advanced = true; advanced; ) {
			advanced = false;
			for ( NvFaceInfo * candidate : faces ) if ( candidate->m_stripId < 0 && strip->SharesEdge( candidate ) ) {
				candidate->m_stripId = strip->m_stripId; strip->m_faces.push_back( candidate ); advanced = true; break;
			}
		}
		if ( static_cast< int >( strip->m_faces.size() ) >= (std::max)( minStripSize, 1 ) ) strips.push_back( strip );
		else { for ( NvFaceInfo * face : strip->m_faces ) leftovers.push_back( face ); delete strip; }
	}
}

void NvStripifier::CreateStrips( const std::vector< NvStripInfo * > & strips,
		std::vector< int > & output, const bool stitch, unsigned int & numSeparateStrips,
		const bool restart, const unsigned int restartIndex ) {
	numSeparateStrips = static_cast< unsigned int >( strips.size() );
	bool firstStrip = true;
	for ( const NvStripInfo * strip : strips ) {
		if ( strip == nullptr || strip->m_faces.empty() ) continue;
		if ( !firstStrip && restart ) output.push_back( static_cast< int >( restartIndex ) );
		else if ( !firstStrip && stitch && !output.empty() ) output.push_back( output.back() );
		for ( const NvFaceInfo * face : strip->m_faces ) {
			output.push_back( face->m_v0 ); output.push_back( face->m_v1 ); output.push_back( face->m_v2 );
		}
		firstStrip = false;
	}
}
