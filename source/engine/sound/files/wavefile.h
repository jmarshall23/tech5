#pragma once

class idWaveFile {
public:
	enum {
		CHANNEL_INDEX_FRONT_LEFT = 0,
		CHANNEL_INDEX_FRONT_RIGHT,
		CHANNEL_INDEX_FRONT_CENTER,
		CHANNEL_INDEX_LOW_FREQUENCY,
		CHANNEL_INDEX_BACK_LEFT,
		CHANNEL_INDEX_BACK_RIGHT,
		CHANNEL_INDEX_FRONT_LEFT_CENTER,
		CHANNEL_INDEX_FRONT_RIGHT_CENTER,
		CHANNEL_INDEX_BACK_CENTER,
		CHANNEL_INDEX_SIDE_LEFT,
		CHANNEL_INDEX_SIDE_RIGHT,
		CHANNEL_INDEX_MAX
	};

	enum formatTag_t {
		FORMAT_PCM = 0x0001,
		FORMAT_ADPCM = 0x0002,
		FORMAT_IEEE_FLOAT = 0x0003,
		FORMAT_XMA2 = 0x0166,
		FORMAT_EXTENSIBLE = 0xFFFE
	};

#pragma pack(push, 2)
	struct waveFmt_t {
		struct basic_t {
			unsigned short formatTag;
			unsigned short numChannels;
			unsigned int samplesPerSec;
			unsigned int avgBytesPerSec;
			unsigned short blockSize;
			unsigned short bitsPerSample;
		} basic;
		unsigned short extraSize;
		union extra_t {
			struct extensible_t {
				unsigned short validBitsPerSample;
				unsigned int channelMask;
				struct guid_t {
					unsigned int data1;
					unsigned short data2;
					unsigned short data3;
					unsigned short data4;
					unsigned char data5[ 6 ];
				} subFormat;
			} extensible;
			struct adpcm_t {
				struct adpcmcoef_t { short coef1; short coef2; };
				unsigned short samplesPerBlock;
				unsigned short numCoef;
				adpcmcoef_t aCoef[ 7 ];
			} adpcm;
			struct xma2_t {
				unsigned short numStreams;
				unsigned int channelMask;
				unsigned int samplesEncoded;
				unsigned int bytesPerBlock;
				unsigned int playBegin;
				unsigned int playLength;
				unsigned int loopBegin;
				unsigned int loopLength;
				unsigned char loopCount;
				unsigned char encoderVersion;
				unsigned short blockCount;
			} xma2;
			extra_t() { memset( this, 0, sizeof( *this ) ); }
		} extra;
	};
#pragma pack(pop)

	struct chunk_t {
		unsigned int id;
		unsigned int size;
		unsigned int offset;
	};

	idWaveFile();
	~idWaveFile();
	bool Open( const char * fileName );
	void Close();
	unsigned int SeekToChunk( unsigned int id );
	unsigned int GetChunkOffset( unsigned int id );
	bool ReadLoopData( int & loopStart, int & loopEnd );
	const char * ReadWaveFormat( waveFmt_t & format );
	static bool ReadWaveFormatDirect( waveFmt_t & format, idFile * file );

	idFile * file;
	idStaticList< chunk_t, 32 > chunks;
};
