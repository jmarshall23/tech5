#pragma once

#include "../models/rendermodel.h"
#include "jobs/approximatelighting/approximatelighting.h"
#include "idlib/geometry/rendermatrix.h"

class idRenderWorldLocal;
struct worldArea_t;

class alignas( 16 ) idRenderModelCommitted {
public:
	idRenderModelCommitted();
	~idRenderModelCommitted();

	void UnlinkAddAlways();
	void UnlinkDimShadow();
	void SetFlagsFromSurfaces();
	void CreateReferences();
	void CheckBounds();
	const idVec3 & GetLightingPoint();
	void FreeReferences();
	void PostCommit();
	bool CastsDimShadows() const;

	const char * name;
	idRenderWorldLocal * world;
	idRenderIndex index;
	idBounds referenceBounds;
	idRenderModelParms r;
	idStaticParmBlock<32> renderParmBlock;
	idList<idRenderModelSurface,62> surfaces;
	idRenderModelCommitted * nextOnPostCommitList;
	idList<worldArea_t *,62> references;
	idRenderModelCommitted * nextAddAlwaysModel;
	idRenderModelCommitted * nextDimShadowModel;
	idRenderModelCommitted * referenceModel;
	int guiFrameCount;
	idVec4 maxVisibleRange;
	idBounds globalReferenceBounds;
	idVec3 localLightingPoint;
	idRenderMatrix modelMatrix;
	idRenderMatrix inverseModelMatrix;
	approximateLighting_t approximateLighting;
	idVec4 highlightColor;
	unsigned char isLitTransSort : 1;
	unsigned char hasUniqueVirtualTexture : 1;
	unsigned char mayMakeInteractions : 1;
	unsigned char mayCastShadows : 1;
	unsigned char mayBeDrawn : 1;
	unsigned char needsApproximatedLighting : 1;
	unsigned char needsReferences : 1;
	unsigned char lightCenterInitialized : 1;
	idRenderMatrix mvpMatrix;
};
