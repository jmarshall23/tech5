#include "virtualtexturepreloader.h"

#include "declmaterial.h"
#include "virtualtexturesystem.h"

#include <algorithm>
#include <chrono>
#include <cstring>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

idVirtualTexturePreloader virtualTexturePreloader;

idVirtualTexturePreloadThread::idVirtualTexturePreloadThread() :
	preloadCommandQueueStart( 0 ), preloadCommandQueueEnd( 0 ), currentHandle( 0 ),
	endCalled( false ), cancelToTerminate( false ) {
	std::memset( preloadCommands, 0, sizeof( preloadCommands ) );
	std::memset( preloadCommandQueue, 0, sizeof( preloadCommandQueue ) );
	for ( preloadCommand_t & command : preloadCommands ) command.done = true;
}

idVirtualTexturePreloadThread::~idVirtualTexturePreloadThread() { StopPreloading(); }

int idVirtualTexturePreloadThread::AddCommand( const preloadType_t type,
		idVirtualTexture * texture, const preloadMaterial_t * materials,
		const int numMaterials, const int minLod ) {
	if ( type == PRELOAD_INVALID || ( preloadCommandQueueEnd - preloadCommandQueueStart ) >= 16 ) return -1;
	preloadCommand_t * command = nullptr;
	for ( preloadCommand_t & candidate : preloadCommands ) if ( candidate.done ) { command = &candidate; break; }
	if ( command == nullptr ) return -1;
	std::memset( command, 0, sizeof( *command ) );
	command->handle = ++currentHandle;
	command->type = type;
	command->texture = texture;
	command->minLod = minLod;
	command->done = false;
	if ( type == PRELOAD_MATERIAL_LIST && materials != nullptr ) {
		command->numTextureRects = (std::min)( numMaterials, 1024 );
		for ( int i = 0; i < command->numTextureRects; ++i ) {
			const idMaterial * material = materials[i].material;
			const idVec4 mapping = material != nullptr ? material->virtualMapping : idVec4( 0, 0, 1, 1 );
			const int pagesWide = texture != nullptr ? texture->header.pagesWide : 1;
			command->textureRects[i].x1 = static_cast< std::uint16_t >( (std::max)( 0, static_cast< int >( mapping.z * pagesWide ) ) );
			command->textureRects[i].y1 = static_cast< std::uint16_t >( (std::max)( 0, static_cast< int >( mapping.w * pagesWide ) ) );
			command->textureRects[i].x2 = static_cast< std::uint16_t >( (std::min)( pagesWide,
				static_cast< int >( ( mapping.z + mapping.x ) * pagesWide + 0.999f ) ) );
			command->textureRects[i].y2 = static_cast< std::uint16_t >( (std::min)( pagesWide,
				static_cast< int >( ( mapping.w + mapping.y ) * pagesWide + 0.999f ) ) );
			command->textureMinLod[i] = static_cast< std::uint8_t >( (std::max)( 0,
				(std::min)( materials[i].minLod, 15 ) ) );
		}
	}
	preloadCommandQueue[preloadCommandQueueEnd++ & 15] = command;
	MemoryBarrier();
	SignalWork();
	return command->handle;
}

bool idVirtualTexturePreloadThread::PreloadIsDone( const int handle ) {
	if ( handle < 0 ) return true;
	for ( const preloadCommand_t & command : preloadCommands )
		if ( command.handle == handle ) return command.done;
	return true;
}

void idVirtualTexturePreloadThread::StopPreloading() {
	cancelToTerminate = true;
	SignalWork();
	StopThread( true );
	for ( preloadCommand_t & command : preloadCommands ) command.done = true;
}

int idVirtualTexturePreloadThread::Run() {
	while ( !cancelToTerminate ) {
		if ( preloadCommandQueueStart == preloadCommandQueueEnd ) { Sleep( 1 ); continue; }
		preloadCommand_t * command = preloadCommandQueue[preloadCommandQueueStart++ & 15];
		if ( command == nullptr ) continue;
		const auto start = std::chrono::steady_clock::now();
		idVirtualTexture * texture = command->texture;
		if ( texture != nullptr ) {
			idVirtualTexture * textures[1] = { texture };
			int pages = 1024;
			if ( command->type == PRELOAD_MATERIAL_LIST ) {
				pages = 0;
				for ( int i = 0; i < command->numTextureRects; ++i ) {
					const preloadTextureRect_t & rect = command->textureRects[i];
					pages += (std::max)( 0, rect.x2 - rect.x1 ) * (std::max)( 0, rect.y2 - rect.y1 );
				}
				pages = (std::max)( 1, (std::min)( pages, 2043 ) );
			}
			virtualTextureSystem.LockPhysicalPages( textures, 1, pages );
			command->pagesLoaded[texture->pageSource] = pages;
		}
		command->totalTimeMSec = static_cast< int >(
			std::chrono::duration_cast< std::chrono::milliseconds >(
				std::chrono::steady_clock::now() - start ).count() );
		MemoryBarrier();
		command->done = true;
	}
	return 0;
}

idVirtualTexturePreloader::idVirtualTexturePreloader() : thread( nullptr ), running( false ) {}
idVirtualTexturePreloader::~idVirtualTexturePreloader() { DestroyThread(); }

void idVirtualTexturePreloader::SpawnThread() {
	if ( thread != nullptr ) return;
	thread = new idVirtualTexturePreloadThread();
	thread->StartThread( "VirtualTexturePreload", CORE_ANY, THREAD_BELOW_NORMAL );
}

void idVirtualTexturePreloader::DestroyThread() {
	if ( thread == nullptr ) return;
	thread->StopPreloading(); delete thread; thread = nullptr; running = false;
}

void idVirtualTexturePreloader::BeginPreloading() { SpawnThread(); running = thread != nullptr; }

void idVirtualTexturePreloader::EndPreloading() {
	if ( thread != nullptr ) thread->endCalled = true;
	running = false;
}

bool idVirtualTexturePreloader::MaterialPreloadIsDone( const int handle ) {
	return thread == nullptr || thread->PreloadIsDone( handle );
}

int idVirtualTexturePreloader::PreloadVMTRsForMap( const char *,
		const idStaticList< idStrStatic<128>, 256 > *, const char * ) {
	BeginPreloading();
	return thread != nullptr && virtualTextureSystem.vmtrMega != nullptr ?
		thread->AddCommand( PRELOAD_ALL, virtualTextureSystem.vmtrMega, nullptr, 0, 0 ) : -1;
}
