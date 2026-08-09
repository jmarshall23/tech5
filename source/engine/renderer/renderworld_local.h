#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\renderworld_local.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1742; PDB kind: enum.
enum idRenderWorldLocal::layoutPhase_t : __int32
{
  LAYOUT_NORMAL = 0x0,
  LAYOUT_PHASE1 = 0x1,
  LAYOUT_PHASE2 = 0x2,
};

// IDA Local Type ordinal 13553; PDB kind: class.
class __declspec(align(4)) idRenderWorldLocal : public idRenderWorld
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34036.
  virtual ~idRenderWorldLocal();
  virtual const char *GetName();
  virtual bool IsComboMap();
  virtual bool HasGlobalShadows();
  virtual void UpdateDeferredPositions();
  virtual void AddEnvironment(const idBounds *, const idDeclEnv *);
  virtual void ClearEnvironments();
  virtual int NumEnvironments();
  virtual const idParmBlock *GetCurrentBlendedParms();
  virtual const idDeclEnv *GetEnvironmentDeclForCurrentViewPoint();
  virtual void TestEnvironment(const idDeclEnv *);
  virtual void SpecificationComplete(bool);
  virtual idRenderModel *StampModel();
  virtual idRenderModelFoliageEdit *FoliageEditRenderModel();
  virtual idRenderModelFoliage *FoliageRenderModel();
  virtual idRenderModelDetailEdit *DetailEditRenderModel();
  virtual idRenderModelDetail *DetailRenderModel();
  virtual idRenderModelTransparency *TransparencyRenderModel();
  virtual idRenderModelDecal *DecalModel();
  virtual idRenderLight *AllocRenderLight(bool);
  virtual idRenderModel *AllocRenderModel(const char *, bool, int);
  virtual void MarkLightSerialized(idRenderLight *, bool, bool);
  virtual void MarkAllLightsAsSerialized();
  virtual void SetBinaryModelState(const char *, const bool);
  virtual void SetNumRenderViews(int);
  virtual idRenderView *RenderViewForIndex(int);
  virtual bool InitForTools(const char *);
  virtual int GetNumRenderModels();
  virtual idRenderModel *RenderModelForIndex(int);
  virtual int GetNumRenderLights();
  virtual idRenderLight *RenderLightForIndex(int);
  virtual int GetNumMegatextures();
  virtual pageSource_t MegatextureForIndex(int);
  virtual const idStaticModel *GetWorldStaticModel();
  virtual const idRenderModel *GetWorldRenderModel();
  virtual void GetStaticWorldBounds(idBounds *);
  virtual bool Trace(modelTrace_t *, const idVec3 *, const idVec3 *, const idTraceOpts *);
  virtual float ShadowSample(const idVec3 *);
  virtual void SaveGame(idFile *);
  virtual bool LoadGame(idFile *);
  virtual void WriteToSnapshot(idSnapShot *, const idSnapShot *);
  virtual void ReadFromSnapshot(idSnapShot *, const idSnapShot *);
  virtual void ResetSnapshots();
  virtual void DebugClear(int);
  virtual void DebugLine(const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool);
  virtual void DebugArrow(const idVec4 *, const idVec3 *, const idVec3 *, float, const int, const bool);
  virtual void DebugArrow2(const idVec4 *, const idVec3 *, const idVec3 *, float, const int, const bool, const idVec3 *);
  virtual void DebugArrow3(const idVec4 *, const idVec3 *, const idVec3 *, float, const int, const bool);
  virtual void DebugPyramid(const idVec4 *, const idVec3 *, const idVec3 *, const idVec3 *, float, float, const int, const bool);
  virtual void DebugWinding(const idVec4 *, const idWinding *, const idVec3 *, const idMat3 *, const int, const bool);
  virtual void DebugCircle(const idVec4 *, const idVec3 *, const idVec3 *, const float, const int, const int, const bool);
  virtual void DebugCylinder(const idVec4 *, const idCylinder *, const idVec3 *, const int, const int, const bool);
  virtual void DebugArc(const idVec4 *, const idVec3 *, const idVec3 *, const float, const float, const float, const float, const int, const bool, const bool);
  virtual void DebugShadedArc(const idVec4 *, const idVec3 *, const idVec3 *, const idVec3 *, const float, const float, const float, const float, const int, const bool);
  virtual void DebugSphere(const idVec4 *, const idSphere *, const int, const int, const bool);
  virtual void DebugBounds(const idVec4 *, const idBounds *, const idVec3 *, const int, const bool);
  virtual void DebugOrientedBounds(const idVec4 *, const idBounds *, const idVec3 *, const idMat3 *, const int, const bool);
  virtual void DebugBox(const idVec4 *, const idBox *, const int, const bool);
  virtual void DebugFrustum(const idVec4 *, const idFrustum *, const bool, const int);
  virtual void DebugCone(const idVec4 *, const idVec3 *, const idVec3 *, float, const int, const bool);
  virtual void DebugCone_2(const idVec4 *, const idVec3 *, const idVec3 *, float, float, const int, const bool);
  virtual void DebugAxis(const idVec4 *, const idVec3 *, const idMat3 *, const int, const bool);
  virtual void DebugAxis_2(const idVec3 *, const idMat3 *, const int, const bool);
  virtual void DebugAxisScaled(const idVec3 *, const idMat3 *, const float, const int, const bool);
  virtual void DebugPoint(const idVec4 *, const idVec3 *, const int, const bool);
  virtual void DebugFilledPolygon(const idVec4 *, const idWinding *, const int, const bool);
  virtual void DebugFilledBounds(const idVec4 *, const idBounds *, const idVec3 *, const int, const bool);
  virtual void DebugText(const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool);
  virtual void DebugText_2(const char *, const idVec3 *, float, const idVec4 *, const idMat3 *, const int, const int, const bool, const bool);
  virtual void DebugSpline(const idVec4 *, idCurve_Spline<idVec3> *, float, bool, int, const bool);
  virtual bool InitFromMap(const char *, bool);

  idStr mapName;
  bool isComboMap;
  bool everInitialized;
  bool specificationCompleteHasBeenCalled;
  bool hasWorldSurfaceOffsets;
  idRenderWorldLocal *nextOnWorldList;
  areaNode_t *areaNodes;
  idBounds *areaNodeBounds;
  int *areaNodeOcclusionIndex;
  int numAreaNodes;
  worldArea_t *worldAreas;
  idBounds *worldAreaSubspaceBounds;
  idBounds *worldAreaGeometryBounds;
  int numWorldAreas;
  idVertexBuffer worldVertexBuffer;
  idIndexBuffer worldIndexBuffer;
  idStaticModel *worldStaticModel;
  idRenderModel *worldRenderModel;
  idRenderModel *skyModel;
  idRenderModel *occlusionBaseModel;
  idAmbientLighting ambientLighting;
  idGlobalShadows globalShadows;
  idStaticList<dynamicEnvironment_t,128> dynamicEnvironments;
  idStaticList<idRenderModel *,4096> renderModels;
  idStaticList<idRenderLight *,4096> renderLights;
  idStaticList<idRenderLight *,4096> serializedLights;
  idStaticList<idRenderView *,2> renderViews;
  idArray<bool,4096> commitModels;
  idArray<bool,4096> commitLights;
  idArray<bool,4096> postCommitModels;
  idArray<bool,4096> postCommitLights;
  idArray<bool,4096> deletedModels;
  idHashIndex binaryModelHash;
  idStaticList<idStr,1024> binaryModelNames;
  idStaticList<bool,1024> binaryModelState;
  idRenderModel *stampModel;
  idRenderModelFoliageEdit *foliageEditRenderModel;
  idRenderModelFoliage *foliageRenderModel;
  idRenderModelDetailEdit *detailEditRenderModel;
  idRenderModelDetail *detailRenderModel;
  idRenderModelTransparency *transparencyRenderModel;
  idRenderModelDecal *decalRenderModel;
  idParallelJobList *transparencyJobList;
  idParallelJobList *renderModelJobList;
  approximateLightingParms_t *approximateLightingParms;
  int numApproximateLightingParms;
  const idRenderLightCommitted **approximateLightingLights;
  int numApproximateLightingLights;
  idStaticList<idRenderModelCommitted *,4096> linkedRenderModels;
  idStaticList<idRenderLightCommitted *,4096> linkedRenderLights;
  idRenderModelCommitted *addAlwaysModels;
  idRenderModelCommitted *dimShadowModels;
  idList<idVirtualTexture *,61> megaTextures;
  const idDeclEnv *testEnv;
  idList<debugLine_t,3> rb_debugLines;
  idList<debugText_t,3> rb_debugText;
  idList<debugPolygon_t,3> rb_debugPolygons;
  idList<debugBounds_t,3> rb_debugBounds;
  idList<debugLine_t,3> latchedDebugLines;
  idList<debugText_t,3> latchedDebugText;
  idList<debugPolygon_t,3> latchedDebugPolygons;
  idList<debugBounds_t,3> latchedDebugBounds;
  bool worldEnableStaticSpecular;
};
