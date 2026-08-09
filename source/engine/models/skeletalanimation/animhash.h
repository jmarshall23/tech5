#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\animhash.h
// Recovered logical types: 8
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23318; PDB kind: struct.
struct idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId> >::entry_t
{
  const idStr *ptr;
  const idStr *parent;
  idStr name;
  idAnimationLocal::jointTypeId typeId;
  idHandle<unsigned short,enum invalidJointHandle_t,65535> handle;
  idResource::referenceType_t refType;
};

// IDA Local Type ordinal 23320; PDB kind: class.
class idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId> >
{
public:
  idList<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId> >::entry_t,30> list;
  idHashIndex nameHash;
  int markStaticNum;
};

// IDA Local Type ordinal 23321; PDB kind: struct.
struct idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId> >::entry_t
{
  const idStr *ptr;
  const idStr *parent;
  idStr name;
  idAnimationLocal::userChannelTypeId typeId;
  idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> handle;
  idResource::referenceType_t refType;
};

// IDA Local Type ordinal 23323; PDB kind: class.
class idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId> >
{
public:
  idList<idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId> >::entry_t,30> list;
  idHashIndex nameHash;
  int markStaticNum;
};

// IDA Local Type ordinal 23326; PDB kind: struct.
struct idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> >::entry_t
{
  const idAliasGroup *ptr;
  const idDeclMD6 *parent;
  idStr name;
  idAnimationLocal::aliasTypeId typeId;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> handle;
  idResource::referenceType_t refType;
};

// IDA Local Type ordinal 23328; PDB kind: class.
class idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> >
{
public:
  idList<idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> >::entry_t,30> list;
  idHashIndex nameHash;
  int markStaticNum;
};

// IDA Local Type ordinal 23329; PDB kind: struct.
struct idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t
{
  const idJointConversion *ptr;
  const idJointConversion *parent;
  idStr name;
  idAnimationLocal::jointConversionTypeId typeId;
  idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> handle;
  idResource::referenceType_t refType;
};

// IDA Local Type ordinal 23331; PDB kind: class.
class idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >
{
public:
  idList<idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t,30> list;
  idHashIndex nameHash;
  int markStaticNum;
};
