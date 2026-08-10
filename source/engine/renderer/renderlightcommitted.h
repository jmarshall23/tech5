#pragma once

#include "renderlightparms.h"
#include "parmblock.h"
#include "renderer_types.h"
#include "idlib/containers/list.h"

class idMaterial;
class idRenderWorldLocal;
struct worldArea_t;

class alignas( 16 ) idRenderLightCommitted {
public:
	idRenderLightCommitted();
	~idRenderLightCommitted();

	void CreateReferences();
	void FreeReferences();
	void PostCommit();

	idRenderWorldLocal * world;
	idRenderIndex index;
	idRenderLightParms r;
	idStaticParmBlock<32> renderParmBlock;
	idRenderLightCommitted * nextOnPostCommitList;
	idList< worldArea_t *, 62 > references;
	bool needsReferences;
	idBounds globalReferenceBounds;
	idVec3 globalLightOrigin;
	idVec3 currentColor;
	idVec4 maxVisibleRange;
	idRenderMatrix baseLightProject;
	idRenderMatrix inverseBaseLightProject;
	const idMaterial * lightMtr;
	bool castsShadows;
};
