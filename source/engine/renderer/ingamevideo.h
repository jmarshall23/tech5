#pragma once

#include "framework/resource.h"
#include "framework/resourcelist.h"
#include "jobs/videotranscode/videotranscode.h"

#include <cstdint>

class idParallelJobList;

struct inGameVideoHeader_t {
	std::uint32_t magic;
	std::uint32_t frameRate;
	std::uint32_t numFrames;
	std::uint32_t frameOffsets[1];
};

class idInGameVideoFile : public idResource {
public:
	idInGameVideoFile();
	~idInGameVideoFile() override;
	void LoadResource() override;
	bool ReloadIfStale() override;
	void WriteResourceFile() override;
	idResourceList * GetResourceList() override;
	void Print() override;
	void List() override;
	void Free();
	const inGameVideoHeader_t * Header() const;

	unsigned char * buffer;
	int bufferSize;
	static idTypedResourceList< idInGameVideoFile > resourceList;
};

class idInGameVideoManager {
public:
	virtual ~idInGameVideoManager();
	virtual void Init();
	virtual void Shutdown();
	virtual void Update();
	virtual void UnbindAll();
	virtual void BindVideo( int index, const idInGameVideoFile * file );
	virtual void SetVideoTime( int index, int time );
	virtual void SetLooping( int index, bool looping );
	virtual void SetPaused( int index, bool paused );
	virtual int GetWeaponVideoIndex();
};

class idInGameVideoManagerLocal : public idInGameVideoManager {
public:
	struct video_t {
		int timeOffset;
		int pausedTime;
		bool looping;
		int lastFrame;
		const idInGameVideoFile * file;
	};

	idInGameVideoManagerLocal();
	~idInGameVideoManagerLocal() override;
	void Init() override;
	void Shutdown() override;
	void Update() override;
	void UnbindAll() override;
	void BindVideo( int index, const idInGameVideoFile * file ) override;
	void SetVideoTime( int index, int time ) override;
	void SetLooping( int index, bool looping ) override;
	void SetPaused( int index, bool paused ) override;
	int GetWeaponVideoIndex() override;
	void UnbindVideo( const idInGameVideoFile * file );

	idParallelJobList * parallelJobList;
	video_t videos[6];
	videoTranscodeParms_t parms[6];
};

extern idInGameVideoManagerLocal localVideoManager;
extern idInGameVideoManager * videoManager;
