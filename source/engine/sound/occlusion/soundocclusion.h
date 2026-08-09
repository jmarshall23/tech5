#pragma once

#include "flatsoundbsp.h"

struct soundOcclusionResult_t {
	idVec3 virtualSoundOrigin;
	float occludedDistance;
	idVec3 * pathPoints;
	int numPathPoints;
	int maxPathPoints;
	int valid;
};

struct soundOcclusionParms_t {
	soundOcclusionResult_t result;
	flatSoundBSP_t flatBSP;
	int * listenerRoute;
	int numAreas;
	float * doors;
	int numDoors;
	int listenerAreaNum;
	idVec3 listenerOrigin;
	int soundAreaNum;
	idVec3 soundOrigin;
	float maxDistance;
};

bool ExternalSoundTrace( const flatSoundBSP_t & bsp, const idVec3 & start,
	const idVec3 & end );
void SoundOcclusionJob( soundOcclusionParms_t & parms );
