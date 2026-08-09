#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\animation.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17968; PDB kind: class.
class idAnimation
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17975.
  virtual ~idAnimation();
  virtual void Initialize();
  virtual void Shutdown();
  virtual void FreeDynamic();
  virtual const char *GetOriginJointName();
  virtual const idHandle<unsigned short,enum invalidJointHandle_t,65535> *GetOriginJointHandle();
  virtual idHandle<unsigned short,enum invalidJointHandle_t,65535> *RegisterJoint(idHandle<unsigned short,enum invalidJointHandle_t,65535> *result, const char *);
  virtual idHandle<unsigned short,enum invalidJointHandle_t,65535> *FindJointHandle(idHandle<unsigned short,enum invalidJointHandle_t,65535> *result, const char *);
  virtual const char *GetJointName(const idHandle<unsigned short,enum invalidJointHandle_t,65535> *);
  virtual idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *RegisterUserChannel(idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *result, const char *);
  virtual idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *FindUserChannelHandle(idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *result, const char *);
  virtual const char *GetUserChannelName(const idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *);
  virtual int GetNumUserChannels();
  virtual void MakeDefaultJointConversion(const char *, const idList<idStr,5> *, const idList<idStr,5> *);
  virtual idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> *FindJointConversionHandle(idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> *result, const char *);
  virtual const char *GetJointConversionName(const idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> *);
  virtual void UnregisterJointConversion(idJointConversion *);
  virtual __int16 GetJointIndex(idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>, const idHandle<unsigned short,enum invalidJointHandle_t,65535> *);
  virtual __int16 GetJointIndex_2(idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>, const char *);
  virtual __int16 GetJointIndex_3(const char *, const char *);
  virtual idHandle<unsigned short,enum invalidCrc_t,65535> *GetJointConversionCrc(idHandle<unsigned short,enum invalidCrc_t,65535> *result, idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>);
  virtual __int16 GetUserChannelIndex(idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>, const idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *);
  virtual __int16 GetUserChannelIndex_2(idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>, const char *);
  virtual __int16 GetUserChannelIndex_3(const char *, const char *);
  virtual idHandle<unsigned short,enum invalidAliasHandle_t,65535> *RegisterAlias(idHandle<unsigned short,enum invalidAliasHandle_t,65535> *result, const idDeclMD6 *, const char *);
  virtual void UnregisterAlias(const idDeclMD6 *, const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *);
  virtual void UnregisterAliases(const idDeclMD6 *);
  virtual idHandle<unsigned short,enum invalidAliasHandle_t,65535> *FindAliasHandle(idHandle<unsigned short,enum invalidAliasHandle_t,65535> *result, const idDeclMD6 *, const char *);
  virtual idHandle<unsigned short,enum invalidAliasHandle_t,65535> *FindAliasHandle_2(idHandle<unsigned short,enum invalidAliasHandle_t,65535> *result, const char *);
  virtual const char *FindAliasName(const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *);
  virtual idHandle<unsigned short,enum invalidAliasHandle_t,65535> *AddStrongAliasRef(idHandle<unsigned short,enum invalidAliasHandle_t,65535> *result, const char *);
  virtual idHandle<unsigned short,enum invalidAliasHandle_t,65535> *StrongLoadAlias(idHandle<unsigned short,enum invalidAliasHandle_t,65535> *result, const idDeclMD6 *, const char *);
  virtual const idMD6Alias *StrongLoadAlias_2(const idDeclMD6 *, const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *);
  virtual void FinalizeAliasRefs();
  virtual void GetAliasRefs(const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *, const bool, idList<idDeclMD6 const *,5> *);

  idRandom2 randomNumberGenerator;
};
