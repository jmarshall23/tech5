#pragma once

#include "../feedbackanalysis/feedbackanalysis.h"

class idImage;

struct pageImageInfo_t {
	void * bits;
	int bytePitch;
};

struct pageImagesUpdate_t {
	physicalPagesPool_t physicalPagesPool;
	int physicalPageNum;
	int physX;
	int physY;
	bool cancelled;
	bool compressed;
	const void * pageDataPBO;
	const unsigned char * pageData;
	idImage * physicalPagesImage0;
	idImage * physicalPagesImage1;
	idImage * physicalPagesImage2;
	float map[4];
	const void * physicalMappingsImagePBO;
	int physicalMappingsImagePBOSize;
	idImage * physicalMappingsImage0;
	pageImageInfo_t physicalMappingsImage0Info;
	int effectivePageLevel;
	int spotX;
	int spotY;
	unsigned char pageSpot[4];
	const void * pageTableImagePBO;
	int pageTableImagePBOSize;
	idImage * pageTableImage;
	pageImageInfo_t pageTableImageInfo[14];
	int pad[10];
};

struct pageImagesUpdateParms_t {
	pageImagesUpdate_t * updates;
	int numUpdates;
	int numCancelled;
	bool submittedJob;
	bool usePageTablePBOs;
	bool useUnsynchronizedPageTablePBOs;
	bool skipPhysicalTextureUploads;
};

void UpdatePageTables_Xenon( const pageImagesUpdateParms_t * parms );
void UpdatePageImagesJob( const pageImagesUpdateParms_t * parms );
