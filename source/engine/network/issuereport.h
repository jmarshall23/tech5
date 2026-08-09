#pragma once

// Retail PDB layout (tungsten.exe.h type 17678).
class idReportData {
public:
	enum { MAX_SEVERITY = 5, MAX_DEVGROUP = 4, MAX_REPRODUCED = 5 };

	idReportData() { Init(); SetDefaults(); }
	void Init();
	void SetDefaults();
	void Format();
	static idStr GetSeverity( int index );
	static idStr GetDevGroup( int index );
	static idStr GetReproduced( int index );

	static const char * const trackerSeverity[ MAX_SEVERITY + 1 ];
	static const char * const trackerDevGroup[ MAX_DEVGROUP + 1 ];
	static const char * const trackerReproduced[ MAX_REPRODUCED + 1 ];

	idStr userName;
	idStr platform;
	idStr buildMessage;
	int buildNumberMajor;
	int buildNumberMinor;
	idStr cpuID;
	int coreNum;
	int logicalNum;
	int packageNum;
	float cpuFrequency;
	idStr launchCommand;
	idStr vtFilePathCvar;
	idStr vtFilePathVmtrOverrideCvar;
	idStr title;
	idStr steps;
	idStr details;
	idStr severity;
	idStr component;
	idStr reproduced;
	idStr style;
	idStr mapPath;
	idStr priority;
	idStr systemInfo;
	idStr localFilename;
	idStr dmpPath;
	idList< idStr > originalCallstack;
	idStr callstack;
	idStr exception;
	idStr registers;
	idStr attachFilename;
	idStr fullFunctionDetails;
	idStr someFunctionDetails;
};

class idIssueReport {
public:
	virtual ~idIssueReport() {}
	virtual void WriteReport() {}
	static bool ReportToHansoft();

	idStr attachFileName;
};

extern idReportData reportData;

#if INTPTR_MAX == INT32_MAX
static_assert( sizeof( idIssueReport ) == 36, "Recovered idIssueReport ABI changed" );
static_assert( sizeof( idReportData ) == 840, "Recovered idReportData ABI changed" );
#endif
