/*
===========================================================================
Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company.

Windows XAudio2 adaptation.  The object layout and resource behavior are
recovered from the licensed idTech 5 executable; the PC backend follows the
BFG XAudio2 implementation under GPLv3 and its additional terms.
===========================================================================
*/
#pragma once

#include "../../framework/resource.h"
#include "../../framework/resourcelist.h"
#include "../files/wavefile.h"

class idSoundSample_XAudio2 : public idResource {
public:
	idSoundSample_XAudio2();
	~idSoundSample_XAudio2() override;
	void LoadResource() override;
	bool ReloadIfStale() override;
	void List() override;
	idResourceList * GetResourceList() override;

	void FreeData();
	void MakeDefault();
	bool LoadWav( const idStr & fileName );
	unsigned int PreCacheStreamData( bool highPriority );
	unsigned int GetCRC32() const;

	int LengthInMsec() const;
	int SampleRate() const { return static_cast< int >( format.basic.samplesPerSec ); }
	int NumSamples() const { return numStaticSamples + numStreamSamples; }
	int NumChannels() const { return format.basic.numChannels; }
	int BufferSize() const { return staticBufferSize + streamedLength; }
	bool IsCompressed() const { return format.basic.formatTag != idWaveFile::FORMAT_PCM; }
	bool IsLoaded() const { return loaded; }

	unsigned int timestamp;
	bool loaded;
	bool localizedStream;
	int numStaticSamples;
	int numStreamSamples;
	int staticBufferSize;
	const char * staticBuffer;
	int firstValidSample;
	int lastValidSample;
	int loopBegin;
	int loopEnd;
	int streamBlockSize;
	int streamedLength;
	unsigned int streamedOffset;
	idFile * streamFile;
	idWaveFile::waveFmt_t format;
	int * xma2SeekTable;
	unsigned int channelMask;
};

class idSoundSample : public idSoundSample_XAudio2 {
public:
	static idTypedResourceList< idSoundSample > resourceList;
};
