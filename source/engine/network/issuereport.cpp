#include "network_precompiled.h"
#include "issuereport.h"

idCVar report_userName( "report_userName", "Unknown", 0,
	"User name to use for reports for any OS that does not provide one" );

idReportData reportData;

// The table bounds are present in the PDB.  These tracker labels are the
// strings used by the retail report UI and its local-report test command.
const char * const idReportData::trackerSeverity[] = {
	"Unspecified", "Blocker", "Critical", "Major", "Minor", "Trivial"
};
const char * const idReportData::trackerDevGroup[] = {
	"Unspecified", "Code", "Design", "Art", "QA"
};
const char * const idReportData::trackerReproduced[] = {
	"Unspecified", "Always", "Often", "Sometimes", "Once", "Unable"
};

void idReportData::Format() {
	steps.TrimWhitespaceRecovered();
	title.TrimWhitespaceRecovered();
	details.TrimWhitespaceRecovered();
}

bool idIssueReport::ReportToHansoft() {
	return common != NULL && common->IsMultiplayer();
}

void idReportData::Init() {
	platform = sizeof( void * ) == 8 ? "x64" : "win32";
	buildNumberMajor = 1683;
	buildNumberMinor = 2952;
	buildMessage.Clear();

	const char * osUser = Sys_GetOSUserName();
	userName = osUser != NULL ? osUser : "";
	if ( userName.Length() == 0 || idStr::Cmp( userName.c_str(), "User" ) == 0 ) {
		const char * machine = Sys_GetMachineName();
		userName = machine != NULL ? machine : report_userName.GetString();
	}

	cpuID = "Generic";
	coreNum = 0;
	logicalNum = 0;
	packageNum = 0;
	cpuFrequency = 0.0f;
	launchCommand = GetCommandLineA();
	vtFilePathCvar = cvarSystem != NULL ? cvarSystem->GetCVarString( "vt_filePath", "" ) : "";
	vtFilePathVmtrOverrideCvar = cvarSystem != NULL ? cvarSystem->GetCVarString( "vt_filePathVmtrOverride", "" ) : "";
}

idStr idReportData::GetSeverity( int index ) {
	if ( index < 0 || index > MAX_SEVERITY ) index = 0;
	return idStr( trackerSeverity[ index ] );
}

idStr idReportData::GetDevGroup( int index ) {
	if ( index < 0 || index > MAX_DEVGROUP ) index = 0;
	return idStr( trackerDevGroup[ index ] );
}

idStr idReportData::GetReproduced( int index ) {
	if ( common != NULL && common->IsMultiplayer() ) {
		return GetDevGroup( index );
	}
	if ( index < 0 || index > MAX_REPRODUCED ) index = 0;
	return idStr( trackerReproduced[ index ] );
}

void idReportData::SetDefaults() {
	title.Clear();
	steps.Clear();
	details.Clear();
	severity.Clear();
	component.Clear();
	reproduced.Clear();
	style = "unspecified";
	const char * currentMap = "None";
	if ( common != NULL && common->Game() != NULL && common->Game()->GetMapName() != NULL && common->Game()->GetMapName()[0] != '\0' ) {
		currentMap = common->Game()->GetMapName();
	}
	mapPath = currentMap;
	mapPath.StripFileExtension();
	priority.Clear();
	localFilename.Clear();
	dmpPath = "Not saved";
	originalCallstack.Clear();
	callstack.Clear();
	exception.Clear();
	registers.Clear();
	attachFilename.Clear();
	fullFunctionDetails.Clear();
	someFunctionDetails.Clear();

	char executable[ MAX_PATH ] = { 0 };
	GetModuleFileNameA( NULL, executable, MAX_PATH );
	SYSTEMTIME time;
	GetLocalTime( &time );
	char timeText[ 64 ];
	_snprintf_s( timeText, sizeof( timeText ), _TRUNCATE,
		"%04u-%02u-%02u %02u:%02u:%02u", time.wYear, time.wMonth,
		time.wDay, time.wHour, time.wMinute, time.wSecond );

	systemInfo.Format(
		"Build & Runtime Info        \r\n"
		"--------------------------- \r\n"
		"User:             %s        \r\n"
		"Version:          1.%d.%d   \r\n"
		"File Path:        %s        \r\n"
		"System Time:      %s        \r\n"
		"Build String:     %s        \r\n"
		"VT File Path:     %s        \r\n"
		"VMTR Override:    %s        \r\n"
		"Launch Command:   %s        \r\n",
		userName.c_str(), buildNumberMajor, buildNumberMinor, executable,
		timeText, buildMessage.c_str(), vtFilePathCvar.c_str(),
		vtFilePathVmtrOverrideCvar.c_str(), launchCommand.c_str() );
}
