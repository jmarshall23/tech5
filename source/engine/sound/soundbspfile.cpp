#include "sound_local.h"

namespace {
const unsigned int SOUND_BSP_IDENT = 1397638153u;

bool ReadBlock( idFile * file, void * data, unsigned int bytes ) {
	return file != NULL && file->Read( data, bytes ) == bytes;
}

template< typename type, int tag >
bool ReadList( idFile * file, idList< type, tag > & list ) {
	int count = 0;
	if ( !ReadBlock( file, &count, sizeof( count ) ) || count < 0 || count > ( 1 << 24 ) ||
		!list.SetNum( count ) ) {
		return false;
	}
	return count == 0 || ReadBlock( file, list.Ptr(), count * static_cast< unsigned int >( sizeof( type ) ) );
}
}

idSoundBSPFile::idSoundBSPFile() : numEnvironments( 0 ), numDoors( 0 ) { Clear(); }

void idSoundBSPFile::BuildFlatBSP() {
	flatBSP.planes = planes.Ptr(); flatBSP.numPlanes = planes.Num();
	flatBSP.vertices = vertices.Ptr(); flatBSP.numVertices = vertices.Num();
	flatBSP.vertIndex = vertIndex.Ptr(); flatBSP.numVertIndex = vertIndex.Num();
	flatBSP.faces = faces.Ptr(); flatBSP.numFaces = faces.Num();
	flatBSP.faceIndex = faceIndex.Ptr(); flatBSP.numFaceIndex = faceIndex.Num();
	flatBSP.areas = areas.Ptr(); flatBSP.numAreas = areas.Num();
	flatBSP.nodes = nodes.Ptr(); flatBSP.numNodes = nodes.Num();
}

void idSoundBSPFile::Clear() {
	planes.Clear(); vertices.SetNum( 1 ); vertices[ 0 ].Set( 0.0f, 0.0f, 0.0f );
	vertIndex.Clear(); faces.SetNum( 1 ); memset( &faces[ 0 ], 0, sizeof( faces[ 0 ] ) );
	faceIndex.Clear(); areas.SetNum( 1 ); memset( &areas[ 0 ], 0, sizeof( areas[ 0 ] ) );
	areas[ 0 ].door = -1; nodes.SetNum( 1 ); memset( &nodes[ 0 ], 0, sizeof( nodes[ 0 ] ) );
	numEnvironments = 0; numDoors = 0; BuildFlatBSP();
}

int idSoundBSPFile::PointAreaNum( const idVec3 & point ) const {
	if ( nodes.Num() <= 1 ) return 0;
	int nodeNum = 1;
	while ( nodeNum > 0 && nodeNum < nodes.Num() ) {
		const sbspNode_t & node = nodes[ nodeNum ];
		if ( node.planeNum >= static_cast< unsigned int >( planes.Num() ) ) return 0;
		const idPlane & plane = planes[ node.planeNum ];
		const float distance = plane.a * point.x + plane.b * point.y + plane.c * point.z + plane.d;
		nodeNum = node.children[ distance >= 0.0f ? 0 : 1 ];
	}
	return nodeNum < 0 ? -nodeNum : 0;
}

bool idSoundBSPFile::Read( const char * fileName ) {
	Clear();
	if ( fileSystem == NULL || fileName == NULL ) return false;
	idFile * file = fileSystem->OpenFileRead( fileName );
	idStr fallback;
	if ( file == NULL ) {
		fallback = fileName;
		fallback.StripFileExtension();
		fallback.Append( "/soundworld.sbsp" );
		file = fileSystem->OpenFileRead( fallback.c_str() );
	}
	if ( file == NULL ) return false;
	unsigned int ident = 0;
	bool ok = ReadBlock( file, &ident, 4 ) && ident == SOUND_BSP_IDENT;
	ok = ok && ReadList( file, planes ) && ReadList( file, vertices ) && ReadList( file, vertIndex );
	int count = 0;
	if ( ok ) ok = ReadBlock( file, &count, 4 ) && count >= 0 && faces.SetNum( count );
	for ( int i = 0; ok && i < count; ++i ) {
		ok = ReadBlock( file, &faces[ i ].planeNum, 2 ) && ReadBlock( file, &faces[ i ].numVerts, 2 ) &&
			ReadBlock( file, &faces[ i ].firstVert, 2 ) && ReadBlock( file, faces[ i ].faceAreas, 4 ) &&
			ReadBlock( file, faces[ i ].center, 6 );
	}
	ok = ok && ReadList( file, faceIndex );
	if ( ok ) ok = ReadBlock( file, &count, 4 ) && count >= 0 && areas.SetNum( count );
	for ( int i = 0; ok && i < count; ++i ) ok = ReadBlock( file, &areas[ i ], sizeof( areas[ i ] ) );
	if ( ok ) ok = ReadBlock( file, &count, 4 ) && count >= 0 && nodes.SetNum( count );
	for ( int i = 0; ok && i < count; ++i ) ok = ReadBlock( file, &nodes[ i ], sizeof( nodes[ i ] ) );
	ok = ok && ReadBlock( file, &numEnvironments, 4 ) && ReadBlock( file, &numDoors, 4 ) &&
		ReadBlock( file, &ident, 4 ) && ident == SOUND_BSP_IDENT;
	delete file;
	if ( !ok ) { Clear(); return false; }
	BuildFlatBSP();
	return true;
}

