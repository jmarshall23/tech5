#include "ingamevideo.h"

#include "image.h"
#include "imagemanager.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/lib_print.h"

#include <algorithm>
#include <cstdio>
#include <cstring>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

static const std::uint32_t INGAME_VIDEO_MAGIC = 0x00354456u; // "VD5\0"

idTypedResourceList< idInGameVideoFile > idInGameVideoFile::resourceList( "video" );
idInGameVideoManagerLocal localVideoManager;
idInGameVideoManager * videoManager = &localVideoManager;

idInGameVideoFile::idInGameVideoFile() : buffer( nullptr ), bufferSize( 0 ) {}
idInGameVideoFile::~idInGameVideoFile() { localVideoManager.UnbindVideo( this ); Free(); }
void idInGameVideoFile::Free() { delete[] buffer; buffer = nullptr; bufferSize = 0; }
const inGameVideoHeader_t * idInGameVideoFile::Header() const {
	return bufferSize >= 12 ? reinterpret_cast< const inGameVideoHeader_t * >( buffer ) : nullptr;
}
void idInGameVideoFile::LoadResource() {
	Free(); ClearResourceError();
	if ( GetName() == nullptr || *GetName() == '\0' ) { SetResourceError( "Empty name on ingamevideo" ); return; }
	idFileLocal file( fileSystem != nullptr ? fileSystem->OpenFileRead( GetName(), true, FSPATH_BASE ) : nullptr );
	if ( file.file == nullptr ) { SetResourceError( "Could not open video '%s'", GetName() ); return; }
	const std::int64_t length64 = file->Length();
	if ( length64 < 16 || length64 > 0x7fffffff ) { SetResourceError( "Video '%s' has invalid size", GetName() ); return; }
	bufferSize = static_cast< int >( length64 );
	buffer = new unsigned char[bufferSize];
	if ( file->Read( buffer, bufferSize ) != static_cast< unsigned int >( bufferSize ) ) {
		SetResourceError( "Video '%s' is truncated", GetName() ); Free(); return;
	}
	const inGameVideoHeader_t * header = Header();
	const std::uint64_t headerBytes = 12ull + ( static_cast< std::uint64_t >( header->numFrames ) + 1 ) * 4;
	if ( header->magic != INGAME_VIDEO_MAGIC || header->frameRate == 0 ||
		header->numFrames == 0 || headerBytes > static_cast< unsigned int >( bufferSize ) ) {
		SetResourceError( "Bad header in video '%s'", GetName() ); Free(); return;
	}
	for ( std::uint32_t i = 0; i <= header->numFrames; ++i ) {
		if ( header->frameOffsets[i] < headerBytes ||
			header->frameOffsets[i] > static_cast< unsigned int >( bufferSize ) ||
			( i > 0 && header->frameOffsets[i] < header->frameOffsets[i - 1] ) ) {
			SetResourceError( "Bad frame table in video '%s'", GetName() ); Free(); return;
		}
	}
}
bool idInGameVideoFile::ReloadIfStale() { return false; }
void idInGameVideoFile::WriteResourceFile() {}
idResourceList * idInGameVideoFile::GetResourceList() { return &resourceList; }
void idInGameVideoFile::Print() { idLibPrint::Printf( "%s: %d bytes\n", GetName(), bufferSize ); }
void idInGameVideoFile::List() { Print(); }

idInGameVideoManager::~idInGameVideoManager() {}
void idInGameVideoManager::Init() {}
void idInGameVideoManager::Shutdown() {}
void idInGameVideoManager::Update() {}
void idInGameVideoManager::UnbindAll() {}
void idInGameVideoManager::BindVideo( int, const idInGameVideoFile * ) {}
void idInGameVideoManager::SetVideoTime( int, int ) {}
void idInGameVideoManager::SetLooping( int, bool ) {}
void idInGameVideoManager::SetPaused( int, bool ) {}
int idInGameVideoManager::GetWeaponVideoIndex() { return 0; }

idInGameVideoManagerLocal::idInGameVideoManagerLocal() : parallelJobList( nullptr ) {
	std::memset( parms, 0, sizeof( parms ) );
	UnbindAll();
}
idInGameVideoManagerLocal::~idInGameVideoManagerLocal() { Shutdown(); }

void idInGameVideoManagerLocal::Init() {
	if ( globalImages == nullptr ) return;
	for ( int i = 0; i < 6; ++i ) {
		if ( parms[i].image == nullptr ) {
			char name[32]; std::snprintf( name, sizeof( name ), "_video%d", i );
			idImageOpts opts;
			opts.width = opts.height = 128; opts.depth = 1; opts.numLevels = 1;
			opts.format = FMT_DXT5; opts.filter = TF_LINEAR; opts.repeat = TR_CLAMP;
			parms[i].image = globalImages->ScratchImage( name, &opts );
		}
		if ( parms[i].dxtBuffer == nullptr ) parms[i].dxtBuffer = new unsigned char[128 * 128];
		parms[i].targetBytePitch = 512;
		parms[i].needSubImageUpload = true;
	}
}
void idInGameVideoManagerLocal::Shutdown() {
	UnbindAll();
	for ( int i = 0; i < 6; ++i ) {
		delete[] parms[i].dxtBuffer;
		parms[i].dxtBuffer = nullptr;
		parms[i].image = nullptr;
	}
}
void idInGameVideoManagerLocal::UnbindAll() {
	for ( video_t & video : videos ) {
		video.timeOffset = 0; video.pausedTime = -1; video.looping = true;
		video.lastFrame = -1; video.file = nullptr;
	}
}
void idInGameVideoManagerLocal::UnbindVideo( const idInGameVideoFile * file ) {
	for ( int i = 0; i < 6; ++i ) if ( videos[i].file == file ) BindVideo( i, nullptr );
}
void idInGameVideoManagerLocal::BindVideo( const int index, const idInGameVideoFile * file ) {
	if ( index < 0 || index >= 6 ) return;
	videos[index].file = file; videos[index].lastFrame = -1;
}
void idInGameVideoManagerLocal::SetVideoTime( const int index, const int time ) {
	if ( index >= 0 && index < 6 ) videos[index].timeOffset = static_cast< int >( GetTickCount64() ) - time;
}
void idInGameVideoManagerLocal::SetLooping( const int index, const bool looping ) {
	if ( index >= 0 && index < 6 ) videos[index].looping = looping;
}
void idInGameVideoManagerLocal::SetPaused( const int index, const bool paused ) {
	if ( index < 0 || index >= 6 ) return;
	videos[index].pausedTime = paused ? static_cast< int >( GetTickCount64() ) : -1;
}
int idInGameVideoManagerLocal::GetWeaponVideoIndex() { return 0; }

void idInGameVideoManagerLocal::Update() {
	const int now = static_cast< int >( GetTickCount64() );
	for ( int index = 0; index < 6; ++index ) {
		video_t & video = videos[index];
		if ( video.file == nullptr || video.file->Header() == nullptr ) continue;
		const inGameVideoHeader_t * header = video.file->Header();
		const int clock = video.pausedTime >= 0 ? video.pausedTime : now;
		int frame = ( clock - video.timeOffset ) * static_cast< int >( header->frameRate ) / 1000;
		frame = (std::max)( frame, 0 );
		if ( video.looping ) frame %= static_cast< int >( header->numFrames );
		else frame = (std::min)( frame, static_cast< int >( header->numFrames ) - 1 );
		if ( frame == video.lastFrame ) continue;
		video.lastFrame = frame;
		videoTranscodeParms_t & transcode = parms[index];
		transcode.dctQualityLuma = 90; transcode.dctQualityChroma = 80;
		transcode.dctBuffer = video.file->buffer + header->frameOffsets[frame];
		transcode.dctBufferSize = header->frameOffsets[frame + 1] - header->frameOffsets[frame];
		VideoTranscodeJob( transcode );
	}
}
