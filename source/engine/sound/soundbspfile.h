#pragma once

#include "occlusion/flatsoundbsp.h"

class idSoundBSPFile {
public:
	idSoundBSPFile();
	void Clear();
	bool Read( const char * fileName );
	int PointAreaNum( const idVec3 & point ) const;
	void BuildFlatBSP();

	idList< idPlane, 39 > planes;
	idList< idVec3, 39 > vertices;
	idList< int, 39 > vertIndex;
	idList< sbspFace_t, 39 > faces;
	idList< int, 39 > faceIndex;
	idList< sbspArea_t, 39 > areas;
	idList< sbspNode_t, 39 > nodes;
	int numEnvironments;
	int numDoors;
	flatSoundBSP_t flatBSP;
};
