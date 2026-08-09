#pragma once

#include "flatsoundbsp.h"

struct soundRoutingParms_t {
	int * route;
	flatSoundBSP_t flatBSP;
	int numAreas;
	int listenerAreaNum;
	idVec3 listenerOrigin;
	unsigned char * temp;
	int tempSize;
};

void SoundRoutingJob( soundRoutingParms_t & parms );
