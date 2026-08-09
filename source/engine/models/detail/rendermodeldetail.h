#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\detail\rendermodeldetail.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 10701; PDB kind: struct.
struct RendererDetails
{
  RendererType type;
  RendererRole role;
  wchar_t *pszRendererID;
  wchar_t *pszDisplayName;
  WAVEFORMATEXTENSIBLE format;
};

// IDA Local Type ordinal 13631; PDB kind: class.
class __declspec(align(8)) idRenderModelDetail : public idRenderModel
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13632.
  virtual void Save(idFile *);
  virtual bool Load(idFile *);
  virtual void SerializeSnapshot(idSerializer *, bool);
  virtual const idDeclSkins *GetSkins();
  virtual idHandle<int,enum invalidDecalHandle_t,-1> *AddDecalFromPoint(idHandle<int,enum invalidDecalHandle_t,-1> *result, const decalParams_t *, const int, const idVec3 *, const idVec3 *, idIndex<short,enum invalidJointIndex_t>);
  virtual bool RemoveDecal(const idHandle<int,enum invalidDecalHandle_t,-1>);
  virtual void RemoveDecals();
  virtual void FreeSurfaces();
  virtual bool CommitSubclass();
  virtual bool UpdateInView(const idRenderView *, const idRenderView *, idRenderModelUpdateTools *);
  virtual const idList<sourceSurface_t,5> *GetSourceSurfaces();
  virtual ~idRenderModelDetail();

  idDetailModel *detailBSP;
  deferredDetailGatherParms_t *detailGatherParms;
  deferredDetailGenParms_t *detailGenParms;
  detailRenderView_t *viewData;
  int currentIndex;
  unsigned __int16 *detailIndices;
  detailSubTreeStats_t *subTreeDetailCounts;
  detailGenTotals_t *totalsUsed;
  idVertexBuffer vertexBuffers[3];
  idIndexBuffer indexBuffers[3];
  idDrawVert *deferredVerts;
  unsigned __int16 *deferredIndices;
  const idMaterial *detailMaterial;
};

// IDA Local Type ordinal 22882; PDB kind: struct.
struct renderModelDetails_t
{
  const char *modelName;
  int count;
};
