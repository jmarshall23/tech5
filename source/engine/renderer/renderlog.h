#pragma once

#include <cstdint>
#include <cstdarg>
#include <cstdio>

enum renderLogIndentLabel_t : int {
	RENDER_LOG_INDENT_BLOCK = 0,
	RENDER_LOG_INDENT_MAIN_BLOCK = 1
};

enum renderLogMainBlock_t : int {
	MRB_NONE = 0,
	MRB_BEGIN_DRAW_VIEW,
	MRB_FILL_DEPTH_BUFFER,
	MRB_DRAW_INTERACTIONS,
	MRB_DRAW_SHADER_PASSES,
	MRB_FOG_AND_BLEND_LIGHTS,
	MRB_POST_PROCESS,
	MRB_DRAW_GUI,
	MRB_SWAP_BUFFERS,
	MRB_MAX
};

class alignas( 8 ) idRenderLog {
public:
	struct logStats_t {
		std::uint64_t startTiming;
		int startDraws;
		int startIndexes;
	};

	idRenderLog();
	~idRenderLog();
	void Close();
	void Printf( const char * format, ... );
	void Indent( renderLogIndentLabel_t label );
	void OpenBlock( const char * format, ... );
	void CloseBlock();
	void StartFrame();
	void EndFrame();
	void OpenMainBlock( renderLogMainBlock_t block );
	void CloseMainBlock();
	void SetLogLevel( int level ) { logLevel = level; }
	void SetActiveFrames( int frames ) { activeLevel = frames; }

	int activeLevel;
	renderLogIndentLabel_t indentLabel[20];
	char indentString[80];
	int indentLevel;
	renderLogMainBlock_t lastMainBlock;
	std::FILE * logFile;
	std::uint64_t frameStartTime;
	std::uint64_t closeBlockTime;
	logStats_t logStats[20];
	int logLevel;

private:
	void LogOpenBlock( renderLogIndentLabel_t label, const char * format, va_list args );
	void LogCloseBlock( renderLogIndentLabel_t label );
};

extern idRenderLog renderLog;
