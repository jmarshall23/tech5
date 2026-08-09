#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\animation\gameanimtools.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2181; PDB kind: enum.
enum idGameAnimToolsLocal::textLines_t : __int32
{
  TL_NAME = 0x0,
  TL_BLEND_OP = 0x1,
  TL_ORIGIN_BLEND = 0x2,
  TL_FRAME = 0x3,
  TL_ALPHA = 0x4,
  TL_WRAP = 0x5,
  TL_RATE = 0x6,
  TL_WEIGHTGROUP = 0x7,
  TL_MAX = 0x8,
};

// IDA Local Type ordinal 18091; PDB kind: class.
class idGameAnimTools
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18092.
  virtual ~idGameAnimTools();
  virtual void AnimDebugHud(idClass *, const idTreeAnimator *, const idMD6Node *);
  virtual idRenderModelGui *DrawBlendTree(const char *, const idMD6Node *);
  virtual int TreeDepth(const idMD6Node *);
  virtual int GetAnimFrameRate(const idTreeAnimator *, const char *);
  virtual int GetAnimNumFrames(const idTreeAnimator *, const idMD6Anim *);
  virtual int GetAnimNumFrames_2(const idTreeAnimator *, const char *);
  virtual bool VerifyStrongAliasRefs(const idTreeAnimator *, const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *, const char *);

};

// IDA Local Type ordinal 20442; PDB kind: class.
class idGameAnimToolsLocal : public idGameAnimTools
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20443.
  virtual ~idGameAnimToolsLocal();
  virtual void AnimDebugHud(idClass *, const idTreeAnimator *, const idMD6Node *);
  virtual idRenderModelGui *DrawBlendTree(const char *, const idMD6Node *);
  virtual int TreeDepth(const idMD6Node *);
  virtual int GetAnimFrameRate(const idTreeAnimator *, const char *);
  virtual int GetAnimNumFrames(const idTreeAnimator *, const idMD6Anim *);
  virtual int GetAnimNumFrames_2(const idTreeAnimator *, const char *);
  virtual bool VerifyStrongAliasRefs(const idTreeAnimator *, const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *, const char *);

  idRenderModelGui *guiModel;
  float nodeWidth;
  float nodeHeight;
  const idMaterial *whiteMaterial;
  idColor branchColor;
  idColor leafColor;
  idColor outlineColor;
  idColor textColor;
  idColor linkColor;
};
