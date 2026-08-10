#pragma once

#include "idlib/geometry/rendermatrix.h"

class idRenderWorldLocal;

struct alignas( 4 ) shadowMap_t {
	shadowMap_t();
	~shadowMap_t();
	float ShadowSample( const idVec3 & worldPoint ) const;

	int width;
	unsigned short * map;
	idRenderMatrix mvp;
	float coordinateBias;
	float depthBias;
	bool useShadowMap;
};

class idGlobalShadows {
public:
	idGlobalShadows();
	~idGlobalShadows();
	float ShadowSample( const idVec3 & worldPoint ) const;
	const shadowMap_t * GetShadowMap() const;
	void LoadGlobalShadows( idRenderWorldLocal * world );
	void WriteShadowVisualizationModel( const char * fileName );

	shadowMap_t * shadowMap;
};
