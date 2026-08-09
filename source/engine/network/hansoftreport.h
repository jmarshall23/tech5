#pragma once

#include "issuereport.h"

class idHansoftReport : public idIssueReport {
public:
	virtual ~idHansoftReport() {}
	virtual void WriteReport() {}

	void SendReport( char * report, unsigned int byteSize, const char * targetPlatform );
	static idStr CombineLines( idStr & source );
	void Write360Report( void * exceptionPointers );
};

extern idHansoftReport hansoftReport;

#if INTPTR_MAX == INT32_MAX
static_assert( sizeof( idHansoftReport ) == 36, "Recovered idHansoftReport ABI changed" );
#endif
