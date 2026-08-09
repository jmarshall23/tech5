#include "network_precompiled.h"
#include "localreport.h"

idLocalReport localReport;

void idLocalReport::WriteReport() {
	idStr prefix;
	prefix.Format( "%s.%s.", reportData.style.c_str(), Sys_GetMachineName() );
	int number = 0;
	fileSystem->GetNumberedFilename( number, prefix.c_str(), "html", fileName, true );
	fileName.MakeNameCanonical();

	idStr text;
	if ( reportData.callstack.Length() != 0 ) {
		text.Append( reportData.callstack ); text.Append( "\r\n" );
		text.Append( reportData.registers ); text.Append( "\r\n" );
		text.Append( reportData.exception ); text.Append( "\r\n" );
	}
	text.Append( reportData.systemInfo ); text.Append( "\r\n" );
	if ( reportData.someFunctionDetails.Length() != 0 ) {
		text.Append( "Function Details            \r\n" );
		text.Append( "--------------------------- \r\n" );
		text.Append( reportData.someFunctionDetails ); text.Append( "\r\n" );
	}

	idLib::Printf( "%s\n", text.c_str() );
	text.ReplaceRecovered( "<", "&lt;" );
	text.ReplaceRecovered( ">", "&gt;" );
	idStr html( "<PRE>\r\n" );
	html.Append( text );
	html.Append( "\r\n</PRE>" );
	fileSystem->WriteFile( fileName.c_str(), html.c_str(), html.Length(), FSPATH_SAVE );
}

CONSOLE_COMMAND_COMPILE( TestLocalReport, "Tests the Local Report code", NULL ) {
	reportData.SetDefaults();
	reportData.style = "TestLocal";
	reportData.title = "Local report code test";
	reportData.steps = "\r\n1. Do something\r\n2. Do something else";
	reportData.details = "Testing Local report code";
	reportData.severity = "Critical";
	reportData.reproduced = "Once";
	reportData.Format();
	localReport.WriteReport();
}
