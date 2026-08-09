#pragma once

#include "issuereport.h"

class idLocalReport : public idIssueReport {
public:
	virtual ~idLocalReport() {}
	virtual void WriteReport();

	idStr fileName;
};

extern idLocalReport localReport;

#if INTPTR_MAX == INT32_MAX
static_assert( sizeof( idLocalReport ) == 68, "Recovered idLocalReport ABI changed" );
#endif
