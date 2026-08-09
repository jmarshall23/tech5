#pragma once

struct sbspFace_t {
	short center[ 3 ];
	unsigned short planeNum;
	unsigned short numVerts;
	unsigned short firstVert;
	short faceAreas[ 2 ];
};

struct sbspArea_t {
	unsigned short numFaces;
	unsigned short firstFace;
	short environment;
	short door;
};

struct sbspNode_t {
	unsigned int planeNum;
	short children[ 2 ];
};

struct flatSoundBSP_t {
	idPlane * planes;
	idVec3 * vertices;
	int * vertIndex;
	sbspFace_t * faces;
	int * faceIndex;
	sbspArea_t * areas;
	sbspNode_t * nodes;
	int numPlanes;
	int numVertices;
	int numVertIndex;
	int numFaces;
	int numFaceIndex;
	int numAreas;
	int numNodes;

	flatSoundBSP_t() { memset( this, 0, sizeof( *this ) ); }
};
