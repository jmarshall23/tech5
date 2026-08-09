#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\entityinterface.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15127; PDB kind: class.
class idEntityInterface
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15171.
  virtual ~idEntityInterface();
  virtual bool IsValid();
  virtual idGame *Game();
  virtual void GetWorldOrigin(idVec3 *);
  virtual void SetWorldOrigin(const idVec3 *);
  virtual void TranslateWorld(const idVec3 *);
  virtual void GetWorldAxis(idMat3 *);
  virtual void SetWorldAxis(const idMat3 *);
  virtual void UpdateVisuals();
  virtual bool GetWorldSpaceTagTransform(const char *, const char *, idVec3 *, idMat3 *);
  virtual void BindToJoint(idEntity *, idIndex<short,enum invalidJointIndex_t>, const bindFlags_t);
  virtual void Unbind();
  virtual idHandle<int,enum invalidAttachment_t,-1> *AttachRenderModel(idHandle<int,enum invalidAttachment_t,-1> *result, const char *, const char *, const char *);
  virtual bool DetachRenderModel(const idHandle<int,enum invalidAttachment_t,-1> *);
  virtual int GetNumAttachments();
  virtual idRenderModel *GetAttachment(const idHandle<int,enum invalidAttachment_t,-1> *);
  virtual bool RebindAttachment(const idHandle<int,enum invalidAttachment_t,-1> *, const tagData_t *);
  virtual void GetLocalOrigin(idVec3 *);
  virtual void SetLocalOrigin(const idVec3 *);
  virtual void GetLocalAxis(idMat3 *);
  virtual void SetLocalAxis(const idMat3 *);
  virtual void GetSpawnPosition(idVec3 *);
  virtual void SetSpawnPosition(const idVec3 *);
  virtual void GetSpawnOrientation(idMat3 *);
  virtual void SetSpawnOrientation(const idMat3 *);
  virtual void SetModel(idRenderModel *);
  virtual void SetModel_2(const char *);
  virtual void StopSound();
  virtual void SetColor(const idColor *);
  virtual idRenderModel *GetRenderEntity();
  virtual void DeleteEntity();
  virtual void GetViewAngles(idAngles *);
  virtual void SetViewAngles(const idVec3 *);
  virtual void GetEyePosition(idVec3 *);
  virtual idTreeAnimator *GetTreeAnimator(const int);
  virtual idAnimStack *GetAnimStack();
  virtual bool PlayAnim(const idMD6Anim *, const bool);
  virtual bool PlayVTR(const idDeclVoiceOver *, const int);
  virtual bool StopVTR();
  virtual bool IsAnimPlaying();
  virtual void ShowUncompressed(const bool);
  virtual void SetRemoveOriginTranslation(bool);
  virtual void SetRemoveOriginRotation(bool);
  virtual bool GetRemoveOriginTranslation();
  virtual bool GetRemoveOriginRotation();
  virtual void SetAnimTime(float);
  virtual float GetAnimTime();
  virtual int GetCurrentAnimFrame();
  virtual void AddReference();
  virtual void RemoveReference();
  virtual int GetReferenceCount();
  virtual idTypeInfoObject *GetTypeInfoObject();
  virtual const idDeclEntityDef *GetEntityDef();
  virtual idEntity *GetEntity();
  virtual const char *GetEntityName();
  virtual void SetLightColor(const idColor *);
  virtual void GetLightColor(idColor *);
  virtual void SetLightRadius(const idVec3 *);
  virtual void GetLightRadius(idVec3 *);
  virtual void SetCastShadows(const bool);
  virtual bool GetCastShadows();
  virtual void SetLightMaterial(const char *);
  virtual void SetLightSpotlight(const bool);
  virtual bool GetLightSpotlight();
  virtual void SetLightParallel(const bool);
  virtual bool GetLightParallel();
  virtual void SetLightCenter(const idVec3 *);
  virtual void GetLightCenter(idVec3 *);
  virtual void SetLightTarget(const idVec3 *);
  virtual void SetLightRight(const idVec3 *);
  virtual void SetLightUp(const idVec3 *);
  virtual void SetLightStart(const idVec3 *);
  virtual void SetLightEnd(const idVec3 *);
  virtual void SetLightClass(lightClass_t);
  virtual void ReInit();
  virtual void SetPreviewTime(int);
  virtual int GetPreviewTime();
  virtual void RestartPlayback();
  virtual void StopPlayback();
  virtual bool RespondsToEvent(const idEventDef *);
  virtual bool OnCustomFunctionCall();

};
