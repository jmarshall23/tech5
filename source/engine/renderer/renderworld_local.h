#pragma once

#include "renderworld.h"
#include "ambientlighting.h"
#include "globalshadows.h"
#include "renderview.h"
#include "renderer_types.h"
#include "idlib/containers/list.h"
#include "idlib/containers/staticlist.h"
#include "idlib/math/plane.h"
#include "idlib/text/str.h"

class idRenderLightCommitted;
class idRenderModelCommitted;
class idVirtualTexture;

struct areaNode_t {
	idPlane plane;
	int children[2];
};

struct worldArea_t {
	worldArea_t() : firstSurfaceInWorldModel( 0 ), areaNum( 0 ) {}
	idList< idRenderIndex, 108 > drawModelRefs;
	idList< idRenderIndex, 108 > drawLightRefs;
	idList< idRenderIndex, 108 > approximatedLightRefs;
	int firstSurfaceInWorldModel;
	idList< idRenderModelSurface, 85 > worldSurfaces;
	int areaNum;
};

#if defined( _WIN32 ) && !defined( _WIN64 )
static_assert( sizeof( worldArea_t ) == 72,
	"Recovered world-area ABI changed" );
#endif

struct dynamicEnvironment_t {
	idBounds bounds;
	const idDeclEnv * env;
};

struct debugLine_t {
	idVec4 color;
	idVec3 start;
	idVec3 end;
	int lifeTime;
	bool depthTest;
};

struct debugText_t {
	idStr text;
	idVec3 origin;
	float scale;
	idVec4 color;
	idMat3 viewAxis;
	int align;
	int lifeTime;
	bool depthTest;
	bool fixedWidth;
};

struct debugPolygon_t {
	idVec4 color;
	idList< idVec3, 3 > points;
	int lifeTime;
	bool depthTest;
};

struct debugBounds_t {
	idVec4 color;
	idBounds bounds;
	idVec3 origin;
	idMat3 axis;
	int lifeTime;
	bool depthTest;
	bool filled;
};

class idRenderWorldLocal : public idRenderWorld {
public:
	enum layoutPhase_t : int {
		LAYOUT_NORMAL = 0,
		LAYOUT_PHASE1 = 1,
		LAYOUT_PHASE2 = 2
	};

	idRenderWorldLocal();
	~idRenderWorldLocal() override;
	const char * GetName() override;
	bool IsComboMap() override;
	bool HasGlobalShadows() override;
	void UpdateDeferredPositions() override;
	void AddEnvironment( const idBounds *, const idDeclEnv * ) override;
	void ClearEnvironments() override;
	int NumEnvironments() override;
	const idParmBlock * GetCurrentBlendedParms() override;
	const idDeclEnv * GetEnvironmentDeclForCurrentViewPoint() override;
	void TestEnvironment( const idDeclEnv * ) override;
	void SpecificationComplete( bool ) override;
	idRenderModel * StampModel() override;
	idRenderModelFoliageEdit * FoliageEditRenderModel() override;
	idRenderModelFoliage * FoliageRenderModel() override;
	idRenderModelDetailEdit * DetailEditRenderModel() override;
	idRenderModelDetail * DetailRenderModel() override;
	idRenderModelTransparency * TransparencyRenderModel() override;
	idRenderModelDecal * DecalModel() override;
	idRenderLight * AllocRenderLight( bool ) override;
	idRenderModel * AllocRenderModel( const char *, bool, int ) override;
	void MarkLightSerialized( idRenderLight *, bool, bool ) override;
	void MarkAllLightsAsSerialized() override;
	void SetBinaryModelState( const char *, const bool ) override;
	void SetNumRenderViews( int ) override;
	idRenderView * RenderViewForIndex( int ) override;
	bool InitForTools( const char * ) override;
	bool InitFromMap( const char *, bool );
	int GetNumRenderModels() override;
	idRenderModel * RenderModelForIndex( int ) override;
	int GetNumRenderLights() override;
	idRenderLight * RenderLightForIndex( int ) override;
	int GetNumMegatextures() override;
	pageSource_t MegatextureForIndex( int ) override;
	const idStaticModel * GetWorldStaticModel() override;
	const idRenderModel * GetWorldRenderModel() override;
	void GetStaticWorldBounds( idBounds * ) override;
	bool Trace( modelTrace_t *, const idVec3 *, const idVec3 *,
		const idTraceOpts * ) override;
	float ShadowSample( const idVec3 * ) override;
	void SaveGame( idFile * ) override;
	bool LoadGame( idFile * ) override;
	void WriteToSnapshot( idSnapShot *, const idSnapShot * ) override;
	void ReadFromSnapshot( idSnapShot *, const idSnapShot * ) override;
	void ResetSnapshots() override;
	void DebugClear( int ) override;
	void DebugLine( const idVec4 *, const idVec3 *, const idVec3 *, const int,
		const bool ) override;
	void DebugArrow( const idVec4 *, const idVec3 *, const idVec3 *, float,
		const int, const bool ) override;
	void DebugArrow2( const idVec4 *, const idVec3 *, const idVec3 *, float,
		const int, const bool, const idVec3 * ) override;
	void DebugArrow3( const idVec4 *, const idVec3 *, const idVec3 *, float,
		const int, const bool ) override;
	void DebugPyramid( const idVec4 *, const idVec3 *, const idVec3 *,
		const idVec3 *, float, float, const int, const bool ) override;
	void DebugWinding( const idVec4 *, const idWinding *, const idVec3 *,
		const idMat3 *, const int, const bool ) override;
	void DebugCircle( const idVec4 *, const idVec3 *, const idVec3 *,
		const float, const int, const int, const bool ) override;
	void DebugCylinder( const idVec4 *, const idCylinder *, const idVec3 *,
		const int, const int, const bool ) override;
	void DebugArc( const idVec4 *, const idVec3 *, const idVec3 *, const float,
		const float, const float, const float, const int, const bool,
		const bool ) override;
	void DebugShadedArc( const idVec4 *, const idVec3 *, const idVec3 *,
		const idVec3 *, const float, const float, const float, const float,
		const int, const bool ) override;
	void DebugSphere( const idVec4 *, const idSphere *, const int, const int,
		const bool ) override;
	void DebugBounds( const idVec4 *, const idBounds *, const idVec3 *,
		const int, const bool ) override;
	void DebugOrientedBounds( const idVec4 *, const idBounds *, const idVec3 *,
		const idMat3 *, const int, const bool ) override;
	void DebugBox( const idVec4 *, const idBox *, const int, const bool ) override;
	void DebugFrustum( const idVec4 *, const idFrustum *, const bool,
		const int ) override;
	void DebugCone( const idVec4 *, const idVec3 *, const idVec3 *, float,
		const int, const bool ) override;
	void DebugCone_2( const idVec4 *, const idVec3 *, const idVec3 *, float,
		float, const int, const bool ) override;
	void DebugAxis( const idVec4 *, const idVec3 *, const idMat3 *, const int,
		const bool ) override;
	void DebugAxis_2( const idVec3 *, const idMat3 *, const int,
		const bool ) override;
	void DebugAxisScaled( const idVec3 *, const idMat3 *, const float,
		const int, const bool ) override;
	void DebugPoint( const idVec4 *, const idVec3 *, const int,
		const bool ) override;
	void DebugFilledPolygon( const idVec4 *, const idWinding *, const int,
		const bool ) override;
	void DebugFilledBounds( const idVec4 *, const idBounds *, const idVec3 *,
		const int, const bool ) override;
	void DebugText( const char *, const idVec3 *, float, const idVec4 *,
		const int, const int, const bool, const bool ) override;
	void DebugText_2( const char *, const idVec3 *, float, const idVec4 *,
		const idMat3 *, const int, const int, const bool, const bool ) override;
	void DebugSpline( const idVec4 *, idCurve_Spline< idVec3 > *, float, bool,
		int, const bool ) override;

	void ScheduleLightCommit( idRenderLight * light );
	void CommitData();
	void PostCommitData();
	void ClearWorld();

	idStr mapName;
	bool isComboMap;
	bool everInitialized;
	bool specificationCompleteHasBeenCalled;
	bool hasWorldSurfaceOffsets;
	idRenderWorldLocal * nextOnWorldList;
	idList< areaNode_t, 62 > areaNodesStorage;
	areaNode_t * areaNodes;
	idList< idBounds, 62 > areaNodeBoundsStorage;
	idBounds * areaNodeBounds;
	idList< int, 62 > areaNodeOcclusionIndexStorage;
	int * areaNodeOcclusionIndex;
	int numAreaNodes;
	idList< worldArea_t, 62 > worldAreasStorage;
	worldArea_t * worldAreas;
	idList< idBounds, 62 > worldAreaSubspaceBoundsStorage;
	idBounds * worldAreaSubspaceBounds;
	idList< idBounds, 62 > worldAreaGeometryBoundsStorage;
	idBounds * worldAreaGeometryBounds;
	int numWorldAreas;
	idBounds staticWorldBounds;
	idStaticModel * worldStaticModel;
	idRenderModel * worldRenderModel;
	idAmbientLighting ambientLighting;
	idGlobalShadows globalShadows;
	idStaticList< dynamicEnvironment_t, 128 > dynamicEnvironments;
	idStaticList< idRenderModel *, 4096 > renderModels;
	idStaticList< idRenderLight *, 4096 > renderLights;
	idStaticList< idRenderLight *, 4096 > serializedLights;
	idStaticList< idRenderView *, 2 > renderViews;
	idList< bool, 5 > commitLights;
	idList< bool, 5 > postCommitLights;
	idStaticList< idRenderModelCommitted *, 4096 > linkedRenderModels;
	idStaticList< idRenderLightCommitted *, 4096 > linkedRenderLights;
	idRenderModelCommitted * addAlwaysModels;
	idRenderModelCommitted * dimShadowModels;
	idList< idStr, 5 > binaryModelNames;
	idList< bool, 5 > binaryModelState;
	idRenderModel * stampModel;
	idRenderModelFoliageEdit * foliageEditRenderModel;
	idRenderModelFoliage * foliageRenderModel;
	idRenderModelDetailEdit * detailEditRenderModel;
	idRenderModelDetail * detailRenderModel;
	idRenderModelTransparency * transparencyRenderModel;
	idRenderModelDecal * decalRenderModel;
	idList< idVirtualTexture *, 61 > megaTextures;
	const idDeclEnv * testEnv;
	idList< debugLine_t, 3 > rb_debugLines;
	idList< debugText_t, 3 > rb_debugText;
	idList< debugPolygon_t, 3 > rb_debugPolygons;
	idList< debugBounds_t, 3 > rb_debugBounds;
	bool worldEnableStaticSpecular;
};
