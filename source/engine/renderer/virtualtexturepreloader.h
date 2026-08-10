#pragma once

#include "virtualtexture.h"

#include "../../shared/idlib/containers/staticlist.h"
#include "../../shared/idlib/sys/sys_threading.h"
#include "../../shared/idlib/text/strstatic.h"

#include <cstdint>

class idMaterial;

enum preloadType_t : int {
	PRELOAD_INVALID = 0,
	PRELOAD_ALL = 1,
	PRELOAD_MATERIAL_LIST = 2
};

struct preloadTextureRect_t {
	std::uint16_t x1, y1, x2, y2;
};

struct preloadMaterial_t {
	const idMaterial * material;
	int minLod;
};

struct alignas( 4 ) preloadCommand_t {
	int handle;
	preloadType_t type;
	idVirtualTexture * texture;
	preloadTextureRect_t textureRects[1024];
	std::uint8_t textureMinLod[1024];
	int numTextureRects;
	int minLod;
	int totalTimeMSec;
	int pagesLoaded[16];
	volatile bool done;
};

class alignas( 4 ) idVirtualTexturePreloadThread : public idSysThread {
public:
	idVirtualTexturePreloadThread();
	~idVirtualTexturePreloadThread() override;
	int Run() override;
	int AddCommand( preloadType_t type, idVirtualTexture * texture,
		const preloadMaterial_t * materials, int numMaterials, int minLod );
	bool PreloadIsDone( int handle );
	void StopPreloading();

	preloadCommand_t preloadCommands[8];
	preloadCommand_t * preloadCommandQueue[16];
	volatile int preloadCommandQueueStart;
	volatile int preloadCommandQueueEnd;
	int currentHandle;
	volatile bool endCalled;
	volatile bool cancelToTerminate;
};

class alignas( 4 ) idVirtualTexturePreloader {
public:
	idVirtualTexturePreloader();
	~idVirtualTexturePreloader();
	void SpawnThread();
	void DestroyThread();
	void BeginPreloading();
	void EndPreloading();
	bool MaterialPreloadIsDone( int handle );
	int PreloadVMTRsForMap( const char * mapName,
		const idStaticList< idStrStatic<128>, 256 > * materialNames,
		const char * pageFile );

	idVirtualTexturePreloadThread * thread;
	bool running;
};

extern idVirtualTexturePreloader virtualTexturePreloader;
