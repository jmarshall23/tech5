#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aidamageinfo.h
// Recovered logical types: 7
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3513; PDB kind: unknown.
typedef CCalAudioMetadata::<unnamed_tag> CCalImageInfo::<unnamed_tag>;

// IDA Local Type ordinal 14697; PDB kind: struct.
struct damageInfo_t
{
  idEntityPtr<idEntity> inflictor;
  idEntityPtr<idEntity> attacker;
  const idDeclDamage *damageDef;
  float damage;
  int time;
  idEntityPtr<idActor> actor;
  int actorTime;
};

// IDA Local Type ordinal 16749; PDB kind: struct.
struct idAIDamageInfo::recentDamager_t
{
  idSpawnId spawnId;
  float recentDamage;
};

// IDA Local Type ordinal 16752; PDB kind: class.
class idAIDamageInfo
{
public:
  idStaticList<idDamageImpulse,8> impulses;
  idEntityPtr<idEntity> inflictor;
  idEntityPtr<idEntity> attacker;
  idStaticList<idAIDamageInfo::recentDamager_t,4> recentDamagers;
  idIndex<short,enum invalidJointIndex_t> jointIndex;
  int deathImpulseIdx;
  float frameDamage;
  float frameArmorDamage;
  float recentUnscaledDamage;
  float recentBodyDamage;
  int lastBloodSprayTime;
  int mostDamagedIndex;
  bool shouldPain;
  idAtomicString injuryDamageGroup;
  int injuryGoreLevelIndex;
};

// IDA Local Type ordinal 17154; PDB kind: struct.
struct idAIMoveInfo
{
  idEntityPtr<idEntity> destEntity;
  idVec3 destPosition;
  idMat3 destOrientation;
  idVec3 destNormal;
  bool useDestOrientation;
  aiArrivalAction_t arrivalAction;
  float arrivalRadius;
  int moveFlags;
};

// IDA Local Type ordinal 18492; PDB kind: struct.
struct pageImageInfo_t
{
  void *bits;
  int bytePitch;
};

// IDA Local Type ordinal 25815; PDB kind: class.
class CCalImageInfo : public CCalMediaInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 25816.
  virtual ~CCalImageInfo();
  virtual unsigned int AddRef();
  virtual unsigned int Release();
  virtual HRESULT Lock();
  virtual HRESULT TryLock();
  virtual HRESULT Unlock();
  virtual CCalBase *Enqueue(CCalBase **);
  virtual CCalBase *Dequeue(CCalBase **);
  virtual HRESULT GetHResult();
  virtual void SetMediaType(CCalBase::MEDIA_TYPE);
  virtual void SetCodecType(CCalBase::CODEC_TYPE);
  virtual void SetCodecVersion(unsigned int);
  virtual CCalBase::MEDIA_TYPE GetMediaType();
  virtual CCalBase::CODEC_TYPE GetCodecType();
  virtual unsigned int GetCodecVersion();
  virtual void InitializeMemberVariables();

  unsigned int m_ulWidth;
  unsigned int m_ulHeight;
  CCalBase::IMAGE_FORMAT_TYPE m_format;
  CCalBase::ORIENTATION_MODE m_OrientationMode;
};
