/*
===========================================================================
Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company.

This Windows XAudio2 resource loader is adapted from the BFG implementation.
The member layout and streaming metadata follow the licensed idTech 5 PDB.
===========================================================================
*/
#include "../sound_local.h"

namespace {
unsigned int WaveFourCC( char a, char b, char c, char d ) {
	return static_cast< unsigned char >( a ) |
		( static_cast< unsigned int >( static_cast< unsigned char >( b ) ) << 8 ) |
		( static_cast< unsigned int >( static_cast< unsigned char >( c ) ) << 16 ) |
		( static_cast< unsigned int >( static_cast< unsigned char >( d ) ) << 24 );
}

unsigned int DefaultChannelMask( int channels ) {
	switch ( channels ) {
		case 1: return SPEAKER_FRONT_CENTER;
		case 2: return SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT;
		case 4: return SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT | SPEAKER_BACK_LEFT | SPEAKER_BACK_RIGHT;
		case 6: return SPEAKER_5POINT1;
		case 8: return SPEAKER_7POINT1;
		default: return 0;
	}
}
}

idSoundSample_XAudio2::idSoundSample_XAudio2() : timestamp( 0 ), loaded( false ),
	localizedStream( false ), numStaticSamples( 0 ), numStreamSamples( 0 ),
	staticBufferSize( 0 ), staticBuffer( NULL ), firstValidSample( 0 ), lastValidSample( 0 ),
	loopBegin( 0 ), loopEnd( 0 ), streamBlockSize( 0 ), streamedLength( 0 ), streamedOffset( 0 ),
	streamFile( NULL ), xma2SeekTable( NULL ), channelMask( 0 ) {
	memset( &format, 0, sizeof( format ) );
}

idSoundSample_XAudio2::~idSoundSample_XAudio2() { FreeData(); }

idResourceList * idSoundSample_XAudio2::GetResourceList() { return &idSoundSample::resourceList; }

void idSoundSample_XAudio2::FreeData() {
	soundSystemLocal.StopVoicesWithSample( reinterpret_cast< const idSoundSample * >( this ) );
	delete[] staticBuffer;
	staticBuffer = NULL;
	delete[] xma2SeekTable;
	xma2SeekTable = NULL;
	delete streamFile;
	streamFile = NULL;
	loaded = false;
	localizedStream = false;
	numStaticSamples = numStreamSamples = staticBufferSize = 0;
	firstValidSample = lastValidSample = loopBegin = loopEnd = 0;
	streamBlockSize = streamedLength = 0;
	streamedOffset = 0;
	channelMask = 0;
	memset( &format, 0, sizeof( format ) );
}

int idSoundSample_XAudio2::LengthInMsec() const {
	return format.basic.samplesPerSec > 0 ? static_cast< int >(
		( static_cast< __int64 >( NumSamples() ) * 1000 ) / format.basic.samplesPerSec ) : 0;
}

bool idSoundSample_XAudio2::LoadWav( const idStr & fileName ) {
	idWaveFile wave;
	if ( !wave.Open( fileName.c_str() ) ) return false;
	if ( wave.ReadWaveFormat( format ) != NULL ) return false;
	if ( format.basic.formatTag != idWaveFile::FORMAT_PCM &&
		format.basic.formatTag != idWaveFile::FORMAT_IEEE_FLOAT &&
		format.basic.formatTag != idWaveFile::FORMAT_EXTENSIBLE &&
		format.basic.formatTag != idWaveFile::FORMAT_ADPCM ) return false;
	const unsigned int dataSize = wave.SeekToChunk( WaveFourCC( 'd', 'a', 't', 'a' ) );
	if ( dataSize == 0 || format.basic.blockSize == 0 ) return false;
	char * buffer = new ( std::nothrow ) char[ dataSize ];
	if ( buffer == NULL || wave.file->Read( buffer, dataSize ) != dataSize ) { delete[] buffer; return false; }
	staticBuffer = buffer;
	staticBufferSize = static_cast< int >( dataSize );
	numStaticSamples = staticBufferSize / format.basic.blockSize;
	numStreamSamples = 0;
	firstValidSample = 0;
	lastValidSample = numStaticSamples;
	loopBegin = 0;
	loopEnd = numStaticSamples;
	wave.ReadLoopData( loopBegin, loopEnd );
	if ( loopEnd <= loopBegin || loopEnd > numStaticSamples ) { loopBegin = 0; loopEnd = numStaticSamples; }
	channelMask = format.basic.formatTag == idWaveFile::FORMAT_EXTENSIBLE ?
		format.extra.extensible.channelMask : DefaultChannelMask( format.basic.numChannels );
	timestamp = fileSystem != NULL ? fileSystem->GetTimestamp( fileName.c_str() ) : 0;
	loaded = true;
	return true;
}

void idSoundSample_XAudio2::MakeDefault() {
	FreeData();
	format.basic.formatTag = idWaveFile::FORMAT_PCM;
	format.basic.numChannels = 1;
	format.basic.samplesPerSec = 22050;
	format.basic.bitsPerSample = 16;
	format.basic.blockSize = 2;
	format.basic.avgBytesPerSec = format.basic.samplesPerSec * format.basic.blockSize;
	format.extraSize = 0;
	numStaticSamples = 2205;
	staticBufferSize = numStaticSamples * 2;
	char * sampleBytes = new char[ staticBufferSize ];
	short * samples = reinterpret_cast< short * >( sampleBytes );
	for ( int i = 0; i < numStaticSamples; ++i ) {
		const float envelope = 1.0f - static_cast< float >( i ) / numStaticSamples;
		samples[ i ] = static_cast< short >( std::sin( i * 2.0f * 3.1415926535f * 440.0f /
			format.basic.samplesPerSec ) * envelope * 12000.0f );
	}
	staticBuffer = sampleBytes;
	firstValidSample = loopBegin = 0;
	lastValidSample = loopEnd = numStaticSamples;
	channelMask = SPEAKER_FRONT_CENTER;
	timestamp = 0;
	loaded = true;
}

void idSoundSample_XAudio2::LoadResource() {
	FreeData();
	idStr fileName( GetName() );
	if ( strrchr( fileName.c_str(), '.' ) == NULL ) fileName.Append( ".wav" );
	if ( !LoadWav( fileName ) ) {
		idLib::Warning( "Couldn't load sound sample '%s'; using default", fileName.c_str() );
		MakeDefault();
	}
}

bool idSoundSample_XAudio2::ReloadIfStale() {
	idStr fileName( GetName() );
	if ( strrchr( fileName.c_str(), '.' ) == NULL ) fileName.Append( ".wav" );
	const unsigned int current = fileSystem != NULL ? fileSystem->GetTimestamp( fileName.c_str() ) : timestamp;
	if ( !loaded || current != timestamp ) { LoadResource(); return true; }
	return false;
}

unsigned int idSoundSample_XAudio2::PreCacheStreamData( bool ) {
	if ( !loaded ) LoadResource();
	return loaded ? static_cast< unsigned int >( staticBufferSize ) : 0;
}

unsigned int idSoundSample_XAudio2::GetCRC32() const {
	return staticBuffer != NULL && staticBufferSize > 0 ? CRC32_BlockChecksum( staticBuffer, staticBufferSize ) : 0;
}

void idSoundSample_XAudio2::List() {
	idLib::Printf( "%s %2.2fkHz\t%6dms\t%5.1fkB %c %s\n", GetName(), SampleRate() / 1000.0f,
		LengthInMsec(), BufferSize() / 1024.0f, NumChannels() == 2 ? 'S' : 'M',
		IsCompressed() ? "compressed" : "PCM" );
}
