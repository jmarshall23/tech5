#pragma once

#include "triangles.h"
#include "idlib/bv/bounds.h"
#include "idlib/math/vector.h"

class idBox;
class idCylinder;
class idCurve_Spline_Base;
class idDeclEnv;
class idFile;
class idFrustum;
class idMaterial;
class idParmBlock;
class idRenderLight;
class idRenderModel;
class idRenderModelDecal;
class idRenderModelDetail;
class idRenderModelDetailEdit;
class idRenderModelFoliage;
class idRenderModelFoliageEdit;
class idRenderModelSurface;
class idRenderModelTransparency;
class idRenderView;
class idSnapShot;
class idSphere;
class idStaticModel;
class idTraceOpts;
class idWinding;
template< typename type > class idCurve_Spline;
enum pageSource_t : int;

struct modelTrace_t {
	localTrace_t tr;
	const idRenderModelSurface * surf;
	const idRenderModel * entity;
};

// Vtable order and signatures are retained from the retail PDB.  Pointer
// parameters deliberately remain pointer-shaped where the original ABI did.
class idRenderWorld {
public:
	virtual ~idRenderWorld();
	virtual const char * GetName() = 0;
	virtual bool IsComboMap() = 0;
	virtual bool HasGlobalShadows() = 0;
	virtual void UpdateDeferredPositions() = 0;
	virtual void AddEnvironment( const idBounds *, const idDeclEnv * ) = 0;
	virtual void ClearEnvironments() = 0;
	virtual int NumEnvironments() = 0;
	virtual const idParmBlock * GetCurrentBlendedParms() = 0;
	virtual const idDeclEnv * GetEnvironmentDeclForCurrentViewPoint() = 0;
	virtual void TestEnvironment( const idDeclEnv * ) = 0;
	virtual void SpecificationComplete( bool ) = 0;
	virtual idRenderModel * StampModel() = 0;
	virtual idRenderModelFoliageEdit * FoliageEditRenderModel() = 0;
	virtual idRenderModelFoliage * FoliageRenderModel() = 0;
	virtual idRenderModelDetailEdit * DetailEditRenderModel() = 0;
	virtual idRenderModelDetail * DetailRenderModel() = 0;
	virtual idRenderModelTransparency * TransparencyRenderModel() = 0;
	virtual idRenderModelDecal * DecalModel() = 0;
	virtual idRenderLight * AllocRenderLight( bool ) = 0;
	virtual idRenderModel * AllocRenderModel( const char *, bool, int ) = 0;
	virtual void MarkLightSerialized( idRenderLight *, bool, bool ) = 0;
	virtual void MarkAllLightsAsSerialized() = 0;
	virtual void SetBinaryModelState( const char *, const bool ) = 0;
	virtual void SetNumRenderViews( int ) = 0;
	virtual idRenderView * RenderViewForIndex( int ) = 0;
	virtual bool InitForTools( const char * ) = 0;
	virtual int GetNumRenderModels() = 0;
	virtual idRenderModel * RenderModelForIndex( int ) = 0;
	virtual int GetNumRenderLights() = 0;
	virtual idRenderLight * RenderLightForIndex( int ) = 0;
	virtual int GetNumMegatextures() = 0;
	virtual pageSource_t MegatextureForIndex( int ) = 0;
	virtual const idStaticModel * GetWorldStaticModel() = 0;
	virtual const idRenderModel * GetWorldRenderModel() = 0;
	virtual void GetStaticWorldBounds( idBounds * ) = 0;
	virtual bool Trace( modelTrace_t *, const idVec3 *, const idVec3 *,
		const idTraceOpts * ) = 0;
	virtual float ShadowSample( const idVec3 * ) = 0;
	virtual void SaveGame( idFile * ) = 0;
	virtual bool LoadGame( idFile * ) = 0;
	virtual void WriteToSnapshot( idSnapShot *, const idSnapShot * ) = 0;
	virtual void ReadFromSnapshot( idSnapShot *, const idSnapShot * ) = 0;
	virtual void ResetSnapshots() = 0;
	virtual void DebugClear( int ) = 0;
	virtual void DebugLine( const idVec4 *, const idVec3 *, const idVec3 *,
		const int, const bool ) = 0;
	virtual void DebugArrow( const idVec4 *, const idVec3 *, const idVec3 *,
		float, const int, const bool ) = 0;
	virtual void DebugArrow2( const idVec4 *, const idVec3 *, const idVec3 *,
		float, const int, const bool, const idVec3 * ) = 0;
	virtual void DebugArrow3( const idVec4 *, const idVec3 *, const idVec3 *,
		float, const int, const bool ) = 0;
	virtual void DebugPyramid( const idVec4 *, const idVec3 *, const idVec3 *,
		const idVec3 *, float, float, const int, const bool ) = 0;
	virtual void DebugWinding( const idVec4 *, const idWinding *, const idVec3 *,
		const idMat3 *, const int, const bool ) = 0;
	virtual void DebugCircle( const idVec4 *, const idVec3 *, const idVec3 *,
		const float, const int, const int, const bool ) = 0;
	virtual void DebugCylinder( const idVec4 *, const idCylinder *,
		const idVec3 *, const int, const int, const bool ) = 0;
	virtual void DebugArc( const idVec4 *, const idVec3 *, const idVec3 *,
		const float, const float, const float, const float, const int,
		const bool, const bool ) = 0;
	virtual void DebugShadedArc( const idVec4 *, const idVec3 *, const idVec3 *,
		const idVec3 *, const float, const float, const float, const float,
		const int, const bool ) = 0;
	virtual void DebugSphere( const idVec4 *, const idSphere *, const int,
		const int, const bool ) = 0;
	virtual void DebugBounds( const idVec4 *, const idBounds *, const idVec3 *,
		const int, const bool ) = 0;
	virtual void DebugOrientedBounds( const idVec4 *, const idBounds *,
		const idVec3 *, const idMat3 *, const int, const bool ) = 0;
	virtual void DebugBox( const idVec4 *, const idBox *, const int, const bool ) = 0;
	virtual void DebugFrustum( const idVec4 *, const idFrustum *, const bool,
		const int ) = 0;
	virtual void DebugCone( const idVec4 *, const idVec3 *, const idVec3 *,
		float, const int, const bool ) = 0;
	virtual void DebugCone_2( const idVec4 *, const idVec3 *, const idVec3 *,
		float, float, const int, const bool ) = 0;
	virtual void DebugAxis( const idVec4 *, const idVec3 *, const idMat3 *,
		const int, const bool ) = 0;
	virtual void DebugAxis_2( const idVec3 *, const idMat3 *, const int,
		const bool ) = 0;
	virtual void DebugAxisScaled( const idVec3 *, const idMat3 *, const float,
		const int, const bool ) = 0;
	virtual void DebugPoint( const idVec4 *, const idVec3 *, const int,
		const bool ) = 0;
	virtual void DebugFilledPolygon( const idVec4 *, const idWinding *,
		const int, const bool ) = 0;
	virtual void DebugFilledBounds( const idVec4 *, const idBounds *,
		const idVec3 *, const int, const bool ) = 0;
	virtual void DebugText( const char *, const idVec3 *, float, const idVec4 *,
		const int, const int, const bool, const bool ) = 0;
	virtual void DebugText_2( const char *, const idVec3 *, float,
		const idVec4 *, const idMat3 *, const int, const int, const bool,
		const bool ) = 0;
	virtual void DebugSpline( const idVec4 *, idCurve_Spline< idVec3 > *,
		float, bool, int, const bool ) = 0;
};

// Opaque ownership bridge used by the D3D9 system translation unit.  Keeping
// this bridge pointer-only avoids leaking platform D3D headers into the world
// geometry declarations while preserving the retail intrusive world list.
idRenderWorld * R_CreateRenderWorld( const char * mapName, bool comboMap );
void R_DestroyRenderWorld( idRenderWorld * world );
idRenderWorld * R_GetNextRenderWorld( idRenderWorld * world );
void R_SetNextRenderWorld( idRenderWorld * world, idRenderWorld * next );
