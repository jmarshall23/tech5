#pragma once

#include "idlib/math/vector.h"

class idRenderWorldLocal;

struct ambientHeader_t {
	int magic;
	int numNodes;
	int numSamples;
};

struct ambientColors_t {
	unsigned char channels[6][3];
};

struct ambientNode_t {
	unsigned short children[8];
};

struct ambientSample_t {
	ambientColors_t colors;
	short origin[3];
};

struct ambientMap_t {
	ambientMap_t();
	~ambientMap_t();
	void SamplesForPoint( const idVec3 & worldPoint, int cube[4],
		ambientSample_t cubeSamples[8] ) const;
	void AmbientSample( const idVec3 & worldPoint,
		ambientColors_t * lighting ) const;

	ambientHeader_t * data;
	int dataLen;
	ambientColors_t forcedColors;
	bool useForcedColors;
	ambientNode_t * nodes;
	ambientSample_t * samples;
};

class idAmbientLighting {
public:
	idAmbientLighting();
	~idAmbientLighting();
	void FreeData();
	void DebugDrawAmbientLightingSamples( idRenderWorldLocal * world,
		const idVec3 & position ) const;
	void DebugDrawColoredCube( idRenderWorldLocal * world,
		const ambientSample_t * sample, float size ) const;
	void DebugDrawAmbientLightingBoxes( idRenderWorldLocal * world,
		bool showValues ) const;
	void LoadAmbientLighting( idRenderWorldLocal * world );

	ambientMap_t * ambientMap;
};
