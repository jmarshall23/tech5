#include "renderlog.h"

#include "renderer_d3d9.h"

#include <cstdarg>
#include <cstring>
#include <ctime>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

idRenderLog renderLog;

namespace {
	std::uint64_t Microseconds() {
		LARGE_INTEGER counter = {}, frequency = {};
		QueryPerformanceCounter( &counter );
		QueryPerformanceFrequency( &frequency );
		return frequency.QuadPart != 0 ?
			static_cast< std::uint64_t >( counter.QuadPart * 1000000ull / frequency.QuadPart ) : 0;
	}
	const char * MainBlockName( const renderLogMainBlock_t block ) {
		static const char * names[MRB_MAX] = {
			"None", "BeginDrawView", "FillDepthBuffer", "DrawInteractions",
			"DrawShaderPasses", "FogAndBlendLights", "PostProcess", "DrawGui",
			"SwapBuffers" };
		return block >= MRB_NONE && block < MRB_MAX ? names[block] : "Unknown";
	}
}
idRenderLog::idRenderLog() : activeLevel( 0 ), indentLevel( 0 ),
	lastMainBlock( MRB_NONE ), logFile( nullptr ), frameStartTime( 0 ),
	closeBlockTime( 0 ), logLevel( 2 ) {
	std::memset( indentLabel, 0, sizeof( indentLabel ) );
	std::memset( indentString, 0, sizeof( indentString ) );
	std::memset( logStats, 0, sizeof( logStats ) );
}
idRenderLog::~idRenderLog() { Close(); }

void idRenderLog::Close() {
	if ( logFile == nullptr ) return;
	while ( indentLevel > 0 ) LogCloseBlock( indentLabel[indentLevel - 1] );
	std::fclose( logFile );
	logFile = nullptr;
}

void idRenderLog::Printf( const char * format, ... ) {
	if ( logFile == nullptr || logLevel < 2 || format == nullptr ) return;
	std::fputs( indentString, logFile );
	va_list args; va_start( args, format );
	std::vfprintf( logFile, format, args );
	va_end( args );
}

void idRenderLog::Indent( const renderLogIndentLabel_t label ) {
	if ( logFile == nullptr || indentLevel >= 19 ) return;
	indentLabel[indentLevel++] = label;
	const int spaces = indentLevel * 4;
	std::memset( indentString, ' ', spaces );
	indentString[spaces] = '\0';
}

void idRenderLog::LogOpenBlock( const renderLogIndentLabel_t label,
		const char * format, va_list args ) {
	if ( logFile == nullptr || format == nullptr ) return;
	std::fputs( indentString, logFile );
	if ( args != nullptr ) std::vfprintf( logFile, format, args );
	else std::fputs( format, logFile );
	std::fputs( " {\n", logFile );
	if ( indentLevel < 20 ) {
		logStats[indentLevel].startTiming = Microseconds();
		const wrapperStats_t stats = GL_GetCurrentStats();
		logStats[indentLevel].startDraws = stats.c_drawElements;
		logStats[indentLevel].startIndexes = stats.c_drawIndices;
	}
	Indent( label );
}

void idRenderLog::OpenBlock( const char * format, ... ) {
	va_list args; va_start( args, format );
	LogOpenBlock( RENDER_LOG_INDENT_BLOCK, format, args );
	va_end( args );
}

void idRenderLog::LogCloseBlock( const renderLogIndentLabel_t label ) {
	if ( logFile == nullptr || indentLevel <= 0 ) return;
	if ( indentLabel[indentLevel - 1] != label ) return;
	--indentLevel;
	indentString[indentLevel * 4] = '\0';
	const std::uint64_t elapsed = Microseconds() - logStats[indentLevel].startTiming;
	const wrapperStats_t stats = GL_GetCurrentStats();
	std::fprintf( logFile, "%s} // %llu us, %d draws, %d indexes\n",
		indentString, static_cast< unsigned long long >( elapsed ),
		stats.c_drawElements - logStats[indentLevel].startDraws,
		stats.c_drawIndices - logStats[indentLevel].startIndexes );
	closeBlockTime = Microseconds();
}

void idRenderLog::CloseBlock() { LogCloseBlock( RENDER_LOG_INDENT_BLOCK ); }

void idRenderLog::StartFrame() {
	if ( activeLevel <= 0 ) return;
	if ( logFile == nullptr ) {
		char name[64];
		std::snprintf( name, sizeof( name ), "renderlog_%04d.txt", activeLevel );
		logFile = std::fopen( name, "wt" );
		if ( logFile == nullptr ) return;
		std::time_t now = std::time( nullptr );
		char timeText[64] = {};
		ctime_s( timeText, sizeof( timeText ), &now );
		std::fprintf( logFile, "// idTech 5 D3D9 render log\n// %s\n", timeText );
	}
	frameStartTime = Microseconds();
	OpenBlock( "Frame" );
}

void idRenderLog::EndFrame() {
	if ( logFile == nullptr ) return;
	if ( lastMainBlock != MRB_NONE ) CloseMainBlock();
	CloseBlock();
	std::fflush( logFile );
	if ( --activeLevel <= 0 ) Close();
}

void idRenderLog::OpenMainBlock( const renderLogMainBlock_t block ) {
	if ( lastMainBlock != MRB_NONE ) CloseMainBlock();
	lastMainBlock = block;
	LogOpenBlock( RENDER_LOG_INDENT_MAIN_BLOCK, MainBlockName( block ), nullptr );
}
void idRenderLog::CloseMainBlock() {
	if ( lastMainBlock == MRB_NONE ) return;
	LogCloseBlock( RENDER_LOG_INDENT_MAIN_BLOCK );
	lastMainBlock = MRB_NONE;
}
