#include "../sound_local.h"

namespace {
unsigned int MakeFourCC( char a, char b, char c, char d ) {
	return static_cast< unsigned char >( a ) |
		( static_cast< unsigned int >( static_cast< unsigned char >( b ) ) << 8 ) |
		( static_cast< unsigned int >( static_cast< unsigned char >( c ) ) << 16 ) |
		( static_cast< unsigned int >( static_cast< unsigned char >( d ) ) << 24 );
}

bool ReadExact( idFile * file, void * data, unsigned int size ) {
	return file != NULL && file->Read( data, size ) == size;
}
}

idWaveFile::idWaveFile() : file( NULL ) {}
idWaveFile::~idWaveFile() { Close(); }

unsigned int idWaveFile::SeekToChunk( unsigned int id ) {
	for ( int i = 0; i < chunks.Num(); ++i ) {
		if ( chunks[ i ].id == id ) {
			file->Seek( chunks[ i ].offset, FS_SEEK_SET );
			return chunks[ i ].size;
		}
	}
	return 0;
}

unsigned int idWaveFile::GetChunkOffset( unsigned int id ) {
	for ( int i = 0; i < chunks.Num(); ++i ) {
		if ( chunks[ i ].id == id ) {
			return chunks[ i ].offset;
		}
	}
	return 0;
}

bool idWaveFile::ReadLoopData( int & start, int & end ) {
	start = end = 0;
	const unsigned int size = SeekToChunk( MakeFourCC( 's', 'm', 'p', 'l' ) );
	if ( size < 36 ) {
		return false;
	}
	unsigned int sampler[ 9 ];
	if ( !ReadExact( file, sampler, sizeof( sampler ) ) || sampler[ 7 ] == 0 || size < 60 ) {
		return false;
	}
	unsigned int loop[ 6 ];
	if ( !ReadExact( file, loop, sizeof( loop ) ) ) {
		return false;
	}
	start = static_cast< int >( loop[ 2 ] );
	end = static_cast< int >( loop[ 3 ] );
	return end > start;
}

const char * idWaveFile::ReadWaveFormat( waveFmt_t & outFormat ) {
	if ( SeekToChunk( MakeFourCC( 'f', 'm', 't', ' ' ) ) == 0 ) {
		return "missing format chunk";
	}
	return ReadWaveFormatDirect( outFormat, file ) ? NULL : "invalid format chunk";
}

bool idWaveFile::ReadWaveFormatDirect( waveFmt_t & outFormat, idFile * input ) {
	memset( &outFormat, 0, sizeof( outFormat ) );
	if ( !ReadExact( input, &outFormat.basic, sizeof( outFormat.basic ) ) ) {
		return false;
	}
	if ( outFormat.basic.formatTag == FORMAT_PCM || outFormat.basic.formatTag == FORMAT_IEEE_FLOAT ) {
		return outFormat.basic.numChannels > 0 && outFormat.basic.samplesPerSec > 0;
	}
	if ( !ReadExact( input, &outFormat.extraSize, sizeof( outFormat.extraSize ) ) ) {
		return false;
	}
	const unsigned int toRead = ( std::min )( static_cast< unsigned int >( outFormat.extraSize ),
		static_cast< unsigned int >( sizeof( outFormat.extra ) ) );
	if ( toRead > 0 && !ReadExact( input, &outFormat.extra, toRead ) ) {
		return false;
	}
	if ( outFormat.extraSize > toRead ) {
		input->Seek( outFormat.extraSize - toRead, FS_SEEK_CUR );
	}
	return outFormat.basic.numChannels > 0 && outFormat.basic.samplesPerSec > 0;
}

void idWaveFile::Close() {
	delete file;
	file = NULL;
	chunks.Clear();
}

bool idWaveFile::Open( const char * fileName ) {
	Close();
	if ( fileSystem == NULL || fileName == NULL ) {
		return false;
	}
	file = fileSystem->OpenFileRead( fileName );
	if ( file == NULL ) {
		return false;
	}
	struct riffHeader_t { unsigned int id, size, format; } header;
	if ( !ReadExact( file, &header, sizeof( header ) ) ||
		header.id != MakeFourCC( 'R', 'I', 'F', 'F' ) ||
		header.format != MakeFourCC( 'W', 'A', 'V', 'E' ) ) {
		Close();
		return false;
	}
	const std::int64_t fileLength = file->Length();
	while ( file->Tell() + 8 <= fileLength && chunks.Num() < 32 ) {
		chunk_t chunk;
		if ( !ReadExact( file, &chunk.id, 4 ) || !ReadExact( file, &chunk.size, 4 ) ) {
			break;
		}
		chunk.offset = static_cast< unsigned int >( file->Tell() );
		chunks.Append( chunk );
		const std::int64_t next = static_cast< std::int64_t >( chunk.offset ) +
			( ( static_cast< std::int64_t >( chunk.size ) + 1 ) & ~1LL );
		if ( next > fileLength || file->Seek( next, FS_SEEK_SET ) < 0 ) {
			break;
		}
	}
	return GetChunkOffset( MakeFourCC( 'f', 'm', 't', ' ' ) ) != 0 &&
		GetChunkOffset( MakeFourCC( 'd', 'a', 't', 'a' ) ) != 0;
}

