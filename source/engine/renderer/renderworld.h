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
	virtual const char * GetName();
	virtual bool IsComboMap();
	virtual bool HasGlobalShadows();
	virtual void UpdateDeferredPositions();
	virtual void AddEnvironment( const idBounds *, const idDeclEnv * );
	virtual void ClearEnvironments();
	virtual int NumEnvironments();
	virtual const idParmBlock * GetCurrentBlendedParms();
	virtual const idDeclEnv * GetEnvironmentDeclForCurrentViewPoint();
	virtual void TestEnvironment( const idDeclEnv * );
	virtual void SpecificationComplete( bool );
	virtual idRenderModel * StampModel();
	virtual idRenderModelFoliageEdit * FoliageEditRenderModel();
	virtual idRenderModelFoliage * FoliageRenderModel();
	virtual idRenderModelDetailEdit * DetailEditRenderModel();
	virtual idRenderModelDetail * DetailRenderModel();
	virtual idRenderModelTransparency * TransparencyRenderModel();
	virtual idRenderModelDecal * DecalModel();
	virtual idRenderLight * AllocRenderLight( bool );
	virtual idRenderModel * AllocRenderModel( const char *, bool, int );
	virtual void MarkLightSerialized( idRenderLight *, bool, bool );
	virtual void MarkAllLightsAsSerialized();
	virtual void SetBinaryModelState( const char *, const bool );
	virtual void SetNumRenderViews( int );
	virtual idRenderView * RenderViewForIndex( int );
	virtual bool InitForTools( const char * );
	virtual int GetNumRenderModels();
	virtual idRenderModel * RenderModelForIndex( int );
	virtual int GetNumRenderLights();
	virtual idRenderLight * RenderLightForIndex( int );
	virtual int GetNumMegatextures();
	virtual pageSource_t MegatextureForIndex( int );
	virtual const idStaticModel * GetWorldStaticModel();
	virtual const idRenderModel * GetWorldRenderModel();
	virtual void GetStaticWorldBounds( idBounds * );
	virtual bool Trace( modelTrace_t *, const idVec3 *, const idVec3 *,
		const idTraceOpts * );
	virtual float ShadowSample( const idVec3 * );
	virtual void SaveGame( idFile * );
	virtual bool LoadGame( idFile * );
	virtual void WriteToSnapshot( idSnapShot *, const idSnapShot * );
	virtual void ReadFromSnapshot( idSnapShot *, const idSnapShot * );
	virtual void ResetSnapshots();
	virtual void DebugClear( int );
	virtual void DebugLine( const idVec4 *, const idVec3 *, const idVec3 *,
		const int, const bool );
	virtual void DebugArrow( const idVec4 *, const idVec3 *, const idVec3 *,
		float, const int, const bool );
	virtual void DebugArrow2( const idVec4 *, const idVec3 *, const idVec3 *,
		float, const int, const bool, const idVec3 * );
	virtual void DebugArrow3( const idVec4 *, const idVec3 *, const idVec3 *,
		float, const int, const bool );
	virtual void DebugPyramid( const idVec4 *, const idVec3 *, const idVec3 *,
		const idVec3 *, float, float, const int, const bool );
	virtual void DebugWinding( const idVec4 *, const idWinding *, const idVec3 *,
		const idMat3 *, const int, const bool );
	virtual void DebugCircle( const idVec4 *, const idVec3 *, const idVec3 *,
		const float, const int, const int, const bool );
	virtual void DebugCylinder( const idVec4 *, const idCylinder *,
		const idVec3 *, const int, const int, const bool );
	virtual void DebugArc( const idVec4 *, const idVec3 *, const idVec3 *,
		const float, const float, const float, const float, const int,
		const bool, const bool );
	virtual void DebugShadedArc( const idVec4 *, const idVec3 *, const idVec3 *,
		const idVec3 *, const float, const float, const float, const float,
		const int, const bool );
	virtual void DebugSphere( const idVec4 *, const idSphere *, const int,
		const int, const bool );
	virtual void DebugBounds( const idVec4 *, const idBounds *, const idVec3 *,
		const int, const bool );
	virtual void DebugOrientedBounds( const idVec4 *, const idBounds *,
		const idVec3 *, const idMat3 *, const int, const bool );
	virtual void DebugBox( const idVec4 *, const idBox *, const int, const bool );
	virtual void DebugFrustum( const idVec4 *, const idFrustum *, const bool,
		const int );
	virtual void DebugCone( const idVec4 *, const idVec3 *, const idVec3 *,
		float, const int, const bool );
	virtual void DebugCone_2( const idVec4 *, const idVec3 *, const idVec3 *,
		float, float, const int, const bool );
	virtual void DebugAxis( const idVec4 *, const idVec3 *, const idMat3 *,
		const int, const bool );
	virtual void DebugAxis_2( const idVec3 *, const idMat3 *, const int,
		const bool );
	virtual void DebugAxisScaled( const idVec3 *, const idMat3 *, const float,
		const int, const bool );
	virtual void DebugPoint( const idVec4 *, const idVec3 *, const int,
		const bool );
	virtual void DebugFilledPolygon( const idVec4 *, const idWinding *,
		const int, const bool );
	virtual void DebugFilledBounds( const idVec4 *, const idBounds *,
		const idVec3 *, const int, const bool );
	virtual void DebugText( const char *, const idVec3 *, float, const idVec4 *,
		const int, const int, const bool, const bool );
	virtual void DebugText_2( const char *, const idVec3 *, float,
		const idVec4 *, const idMat3 *, const int, const int, const bool,
		const bool );
	virtual void DebugSpline( const idVec4 *, idCurve_Spline< idVec3 > *,
		float, bool, int, const bool );
};

// Opaque ownership bridge used by the D3D9 system translation unit.  Keeping
// this bridge pointer-only avoids leaking platform D3D headers into the world
// geometry declarations while preserving the retail intrusive world list.
idRenderWorld * R_CreateRenderWorld( const char * mapName, bool comboMap );
void R_DestroyRenderWorld( idRenderWorld * world );
idRenderWorld * R_GetNextRenderWorld( idRenderWorld * world );
void R_SetNextRenderWorld( idRenderWorld * world, idRenderWorld * next );
