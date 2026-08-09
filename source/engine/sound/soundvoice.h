#pragma once

#include <xaudio2.h>
#include "../../shared/idlib/math/vector.h"
#include "../../shared/idlib/containers/list.h"
#include "xaudio2/xa2_soundsample.h"

struct pinnedCacheLines_t {
	idFile * cacheFile;
	__int64 ofs;
	int length;
	int numLines;
	int extra;
	const void * lineData[ 2 ];
	int lineLength[ 2 ];
};

class idSoundVoice_Base {
public:
	idSoundVoice_Base();
	void InitSurround( unsigned int outputChannels, int outputChannelMask );
	void CalculateChannelSurrond( int srcChannel, float * matrix, int matrixChannels ) const;
	void CalculateSurround( int srcChannels, int dstChannels, float * matrix ) const;
	idSoundSample * SelectSample( int timeMS ) const;

	idMat3 invListenerAxis;
	idMat3 axis;
	idVec3 position;
	idVec3 velocity;
	float gain;
	float dryGain;
	float wetGain;
	float gainLFE;
	float centerChannel;
	float pitch;
	float innerRadius;
	float occlusion;
	unsigned int channelMask;
	float innerSampleRangeSqr;
	float outerSampleRangeSqr;
	idList< idSoundSample *, 5 > samples;
};

class idSoundVoice_XAudio2 : public idSoundVoice_Base {
public:
	idSoundVoice_XAudio2();
	~idSoundVoice_XAudio2();
	void Create( const idSoundSample * leadin, const idSoundSample * looping );
	void Start( int offsetMS, int soundShaderFlags );
	void Stop();
	void Pause();
	void UnPause();
	bool Update();
	float GetAmplitude();
	bool CompatibleFormat( idSoundSample_XAudio2 * soundSample ) const;
	bool IsPlaying() const;
	void FlushSourceBuffers();
	void DestroyInternal();
	int RestartAt( int offsetSamples );
	unsigned int GetSampleRate() const { return sampleRate; }

	IXAudio2SourceVoice * pSourceVoice;
	idSoundSample_XAudio2 * sample;
	pinnedCacheLines_t pins[ 3 ];
	int readPin;
	bool paused;
	unsigned short formatTag;
	unsigned short numChannels;
	unsigned int sourceVoiceRate;
	unsigned int sampleRate;
	unsigned short bitsPerSample;
	int currentStreamBlock;
	volatile int currentStreamRemaining;
	bool hasVUMeter;
	bool hasReverb;
	int startFlags;
};

class idSoundVoice : public idSoundVoice_XAudio2 {};
