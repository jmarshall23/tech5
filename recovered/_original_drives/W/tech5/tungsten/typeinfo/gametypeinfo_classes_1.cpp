
// ========================================================================
// ?Get_CellDmaListElement_notify@@YAHPAX@Z
// EA  : 0x82559DA0
// RVA : 0x00559DA0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall Get_CellDmaListElement_notify(_QWORD *ptr)
{
  __int64 result; // r4 OVERLAPPED

  *(__int64 *)((char *)&result + 4) = *ptr >> 63;
  return result;
}


// ========================================================================
// ?Set_CellDmaListElement_notify@@YAXPAXH@Z
// EA  : 0x82559DB0
// RVA : 0x00559DB0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_CellDmaListElement_notify(_DWORD *ptr, int value, int a3, int a4, int a5, int a6, __int64 a7)
{
  LODWORD(a7) = ptr[1];
  *(_QWORD *)ptr = a7;
}


// ========================================================================
// ?Get_CellDmaListElement_reserved@@YAHPAX@Z
// EA  : 0x82559DC8
// RVA : 0x00559DC8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_CellDmaListElement_reserved(_QWORD *ptr)
{
  return (unsigned __int16)(*ptr >> 47);
}


// ========================================================================
// ?Set_CellDmaListElement_reserved@@YAXPAXH@Z
// EA  : 0x82559DD8
// RVA : 0x00559DD8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_CellDmaListElement_reserved(_DWORD *ptr, int value, int a3, int a4, int a5, __int64 a6)
{
  LODWORD(a6) = ptr[1] & 0x80007FFF;
  *(_QWORD *)ptr = a6;
}


// ========================================================================
// ?Get_CellDmaListElement_size@@YAHPAX@Z
// EA  : 0x82559E00
// RVA : 0x00559E00
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_CellDmaListElement_size(_DWORD *ptr)
{
  return *ptr & 0x7FFF;
}


// ========================================================================
// ?Set_CellDmaListElement_size@@YAXPAXH@Z
// EA  : 0x82559E10
// RVA : 0x00559E10
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_CellDmaListElement_size(_DWORD *ptr, int value, int a3, int a4, int a5, __int64 a6)
{
  LODWORD(a6) = ptr[1] & 0xFFFF8000;
  *(_QWORD *)ptr = a6;
}


// ========================================================================
// ?Get_CellDmaListElement_eal@@YAHPAX@Z
// EA  : 0x82559E30
// RVA : 0x00559E30
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_CellDmaListElement_eal(_DWORD *ptr)
{
  return ptr[1];
}


// ========================================================================
// ?SetVoiceState@CX2SourceVoice@XAUDIO2@@UAAXW4EVoiceState@CX2Voice@2@@Z
// EA  : 0x82559E40
// RVA : 0x00559E40
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall XAUDIO2::CX2SourceVoice::SetVoiceState(
        XAUDIO2::CX2Voice *this,
        XAUDIO2::CX2Voice::EVoiceState eNewState)
{
  this->m_eVoiceState = eNewState;
}


// ========================================================================
// ?Get_usercmd_t_inhibited@@YAHPAX@Z
// EA  : 0x82559E48
// RVA : 0x00559E48
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_usercmd_t_inhibited(unsigned __int8 *ptr)
{
  return ptr[9] >> 7;
}


// ========================================================================
// ?Set_usercmd_t_inhibited@@YAXPAXH@Z
// EA  : 0x82559E58
// RVA : 0x00559E58
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_usercmd_t_inhibited(_BYTE *ptr, int value)
{
  ptr[9] = ((value != 0) << 7) | ptr[9] & 0x7F;
}


// ========================================================================
// ?Get_usercmd_t_fromBot@@YAHPAX@Z
// EA  : 0x82559E70
// RVA : 0x00559E70
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_usercmd_t_fromBot(_BYTE *ptr)
{
  return (ptr[9] & 0x40) != 0;
}


// ========================================================================
// ?Set_usercmd_t_fromBot@@YAXPAXH@Z
// EA  : 0x82559E80
// RVA : 0x00559E80
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_usercmd_t_fromBot(_BYTE *ptr, int value)
{
  ptr[9] = ((value != 0) << 6) & 0x40 | ptr[9] & 0xBF;
}


// ========================================================================
// ?Get_idMaterial_materialCastsShadows@@YAHPAX@Z
// EA  : 0x82559E98
// RVA : 0x00559E98
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idMaterial_materialCastsShadows(unsigned __int8 *ptr)
{
  return ptr[72] >> 7;
}


// ========================================================================
// ?Get_idNpMover_idLinkUseParms_customLinkMode@@YAHPAX@Z
// EA  : 0x82559EA8
// RVA : 0x00559EA8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idNpMover_idLinkUseParms_customLinkMode(_BYTE *ptr)
{
  return (ptr[72] & 0x40) != 0;
}


// ========================================================================
// ?Get_idMaterial_materialIsMixedUnique@@YAHPAX@Z
// EA  : 0x82559EB8
// RVA : 0x00559EB8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idMaterial_materialIsMixedUnique(_BYTE *ptr)
{
  return (ptr[72] & 0x20) != 0;
}


// ========================================================================
// ?Set_idMaterial_materialIsMixedUnique@@YAXPAXH@Z
// EA  : 0x82559EC8
// RVA : 0x00559EC8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idMaterial_materialIsMixedUnique(_BYTE *ptr, int value)
{
  ptr[72] = (32 * (value != 0)) & 0x20 | ptr[72] & 0xDF;
}


// ========================================================================
// ?Get_idMaterial_materialHasInteractions@@YAHPAX@Z
// EA  : 0x82559EE0
// RVA : 0x00559EE0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idMaterial_materialHasInteractions(_BYTE *ptr)
{
  return (ptr[72] & 0x10) != 0;
}


// ========================================================================
// ?Set_idMaterial_materialHasInteractions@@YAXPAXH@Z
// EA  : 0x82559EF0
// RVA : 0x00559EF0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idMaterial_materialHasInteractions(_BYTE *ptr, int value)
{
  ptr[72] = (16 * (value != 0)) & 0x10 | ptr[72] & 0xEF;
}


// ========================================================================
// ?Get_idMaterial_materialIsTransparencySorted@@YAHPAX@Z
// EA  : 0x82559F08
// RVA : 0x00559F08
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idMaterial_materialIsTransparencySorted(_BYTE *ptr)
{
  return (ptr[72] & 8) != 0;
}


// ========================================================================
// ?Set_idMaterial_materialIsTransparencySorted@@YAXPAXH@Z
// EA  : 0x82559F18
// RVA : 0x00559F18
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idMaterial_materialIsTransparencySorted(_BYTE *ptr, int value)
{
  ptr[72] = (8 * (value != 0)) & 8 | ptr[72] & 0xF7;
}


// ========================================================================
// ?Get_idMaterial_materialUsesTransSortAtlas@@YAHPAX@Z
// EA  : 0x82559F30
// RVA : 0x00559F30
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idMaterial_materialUsesTransSortAtlas(_BYTE *ptr)
{
  return (ptr[72] & 4) != 0;
}


// ========================================================================
// ?Set_idMaterial_materialUsesTransSortAtlas@@YAXPAXH@Z
// EA  : 0x82559F40
// RVA : 0x00559F40
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idMaterial_materialUsesTransSortAtlas(_BYTE *ptr, int value)
{
  ptr[72] = (4 * (value != 0)) & 4 | ptr[72] & 0xFB;
}


// ========================================================================
// ?Get_idMaterial_materialUsesApproximatedLighting@@YAHPAX@Z
// EA  : 0x82559F58
// RVA : 0x00559F58
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idMaterial_materialUsesApproximatedLighting(_BYTE *ptr)
{
  return (ptr[72] & 2) != 0;
}


// ========================================================================
// ?Set_idMaterial_materialUsesApproximatedLighting@@YAXPAXH@Z
// EA  : 0x82559F68
// RVA : 0x00559F68
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idMaterial_materialUsesApproximatedLighting(_BYTE *ptr, int value)
{
  ptr[72] = (2 * (value != 0)) & 2 | ptr[72] & 0xFD;
}


// ========================================================================
// ?Get_idMaterial_materialUsesWrinkleMaps@@YAHPAX@Z
// EA  : 0x82559F80
// RVA : 0x00559F80
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idMaterial_materialUsesWrinkleMaps(_BYTE *ptr)
{
  return ptr[72] & 1;
}


// ========================================================================
// ?Set_idMaterial_materialUsesWrinkleMaps@@YAXPAXH@Z
// EA  : 0x82559F90
// RVA : 0x00559F90
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idMaterial_materialUsesWrinkleMaps(_BYTE *ptr, int value)
{
  ptr[72] = (value != 0) | ptr[72] & 0xFE;
}


// ========================================================================
// ?Get_idMaterial_materialHasMergeableBlendedPass@@YAHPAX@Z
// EA  : 0x82559FA8
// RVA : 0x00559FA8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idMaterial_materialHasMergeableBlendedPass(unsigned __int8 *ptr)
{
  return ptr[73] >> 7;
}


// ========================================================================
// ?Set_idMaterial_materialHasMergeableBlendedPass@@YAXPAXH@Z
// EA  : 0x82559FB8
// RVA : 0x00559FB8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idMaterial_materialHasMergeableBlendedPass(_BYTE *ptr, int value)
{
  ptr[73] = ((value != 0) << 7) | ptr[73] & 0x7F;
}


// ========================================================================
// ?Get_idMaterial_skipSurfaceInfo@@YAHPAX@Z
// EA  : 0x82559FD0
// RVA : 0x00559FD0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idMaterial_skipSurfaceInfo(_BYTE *ptr)
{
  return (ptr[73] & 0x40) != 0;
}


// ========================================================================
// ?Set_idMaterial_skipSurfaceInfo@@YAXPAXH@Z
// EA  : 0x82559FE0
// RVA : 0x00559FE0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idMaterial_skipSurfaceInfo(_BYTE *ptr, int value)
{
  ptr[73] = ((value != 0) << 6) & 0x40 | ptr[73] & 0xBF;
}


// ========================================================================
// ?Get_idMaterial_materialHasClipSpheres@@YAHPAX@Z
// EA  : 0x82559FF8
// RVA : 0x00559FF8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idMaterial_materialHasClipSpheres(_BYTE *ptr)
{
  return (ptr[73] & 0x20) != 0;
}


// ========================================================================
// ?Set_idMaterial_materialHasClipSpheres@@YAXPAXH@Z
// EA  : 0x8255A008
// RVA : 0x0055A008
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idMaterial_materialHasClipSpheres(_BYTE *ptr, int value)
{
  ptr[73] = (32 * (value != 0)) & 0x20 | ptr[73] & 0xDF;
}


// ========================================================================
// ?Set_idResource_loadedResource@@YAXPAXH@Z
// EA  : 0x8255A020
// RVA : 0x0055A020
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idResource_loadedResource(_BYTE *ptr, int value)
{
  ptr[32] = ((value != 0) << 7) | ptr[32] & 0x7F;
}


// ========================================================================
// ?Set_idResource_staticResource@@YAXPAXH@Z
// EA  : 0x8255A038
// RVA : 0x0055A038
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idResource_staticResource(_BYTE *ptr, int value)
{
  ptr[32] = ((value != 0) << 6) & 0x40 | ptr[32] & 0xBF;
}


// ========================================================================
// ?Get_idResource_insideRecursiveLoad@@YAHPAX@Z
// EA  : 0x8255A050
// RVA : 0x0055A050
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idResource_insideRecursiveLoad(_BYTE *ptr)
{
  return (ptr[32] & 0x20) != 0;
}


// ========================================================================
// ?Set_idResource_insideRecursiveLoad@@YAXPAXH@Z
// EA  : 0x8255A060
// RVA : 0x0055A060
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idResource_insideRecursiveLoad(_BYTE *ptr, int value)
{
  ptr[32] = (32 * (value != 0)) & 0x20 | ptr[32] & 0xDF;
}


// ========================================================================
// ?Get_idResource_forceLoad@@YAHPAX@Z
// EA  : 0x8255A078
// RVA : 0x0055A078
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idResource_forceLoad(_BYTE *ptr)
{
  return (ptr[32] & 0x10) != 0;
}


// ========================================================================
// ?Set_idResource_forceLoad@@YAXPAXH@Z
// EA  : 0x8255A088
// RVA : 0x0055A088
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idResource_forceLoad(_BYTE *ptr, int value)
{
  ptr[32] = (16 * (value != 0)) & 0x10 | ptr[32] & 0xEF;
}


// ========================================================================
// ?Get_idResource_loadDeferred@@YAHPAX@Z
// EA  : 0x8255A0A0
// RVA : 0x0055A0A0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idResource_loadDeferred(_BYTE *ptr)
{
  return (ptr[32] & 8) != 0;
}


// ========================================================================
// ?Set_idResource_loadDeferred@@YAXPAXH@Z
// EA  : 0x8255A0B0
// RVA : 0x0055A0B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idResource_loadDeferred(_BYTE *ptr, int value)
{
  ptr[32] = (8 * (value != 0)) & 8 | ptr[32] & 0xF7;
}


// ========================================================================
// ?Get_idRenderModelParms_isAugment@@YAHPAX@Z
// EA  : 0x8255A0C8
// RVA : 0x0055A0C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_isAugment(_BYTE *ptr)
{
  return (ptr[104] & 2) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_isAugment@@YAXPAXH@Z
// EA  : 0x8255A0D8
// RVA : 0x0055A0D8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_isAugment(_BYTE *ptr, int value)
{
  ptr[104] = (2 * (value != 0)) & 2 | ptr[104] & 0xFD;
}


// ========================================================================
// ?Get_idRenderModelParms_augmentShowOnlyWhenOccluded@@YAHPAX@Z
// EA  : 0x8255A0F0
// RVA : 0x0055A0F0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idRenderModelParms_augmentShowOnlyWhenOccluded(_BYTE *ptr)
{
  return ptr[104] & 1;
}


// ========================================================================
// ?Set_idRenderModelParms_augmentShowOnlyWhenOccluded@@YAXPAXH@Z
// EA  : 0x8255A100
// RVA : 0x0055A100
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_augmentShowOnlyWhenOccluded(_BYTE *ptr, int value)
{
  ptr[104] = (value != 0) | ptr[104] & 0xFE;
}


// ========================================================================
// ?Get_idRenderModelParms_noShadow@@YAHPAX@Z
// EA  : 0x8255A118
// RVA : 0x0055A118
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idRenderModelParms_noShadow(unsigned __int8 *ptr)
{
  return ptr[105] >> 7;
}


// ========================================================================
// ?Set_idRenderModelParms_noShadow@@YAXPAXH@Z
// EA  : 0x8255A128
// RVA : 0x0055A128
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_noShadow(_BYTE *ptr, int value)
{
  ptr[105] = ((value != 0) << 7) | ptr[105] & 0x7F;
}


// ========================================================================
// ?Get_idRenderModelParms_noInteractions@@YAHPAX@Z
// EA  : 0x8255A140
// RVA : 0x0055A140
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_noInteractions(_BYTE *ptr)
{
  return (ptr[105] & 0x40) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_noInteractions@@YAXPAXH@Z
// EA  : 0x8255A150
// RVA : 0x0055A150
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_noInteractions(_BYTE *ptr, int value)
{
  ptr[105] = ((value != 0) << 6) & 0x40 | ptr[105] & 0xBF;
}


// ========================================================================
// ?Get_idRenderModelParms_staticShadowsFromDynamicModel@@YAHPAX@Z
// EA  : 0x8255A168
// RVA : 0x0055A168
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_staticShadowsFromDynamicModel(_BYTE *ptr)
{
  return (ptr[105] & 0x20) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_staticShadowsFromDynamicModel@@YAXPAXH@Z
// EA  : 0x8255A178
// RVA : 0x0055A178
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_staticShadowsFromDynamicModel(_BYTE *ptr, int value)
{
  ptr[105] = (32 * (value != 0)) & 0x20 | ptr[105] & 0xDF;
}


// ========================================================================
// ?Get_idRenderModelParms_acceptDimShadows@@YAHPAX@Z
// EA  : 0x8255A190
// RVA : 0x0055A190
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_acceptDimShadows(_BYTE *ptr)
{
  return (ptr[105] & 0x10) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_acceptDimShadows@@YAXPAXH@Z
// EA  : 0x8255A1A0
// RVA : 0x0055A1A0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_acceptDimShadows(_BYTE *ptr, int value)
{
  ptr[105] = (16 * (value != 0)) & 0x10 | ptr[105] & 0xEF;
}


// ========================================================================
// ?Get_idRenderModelParms_megatexturedModel@@YAHPAX@Z
// EA  : 0x8255A1B8
// RVA : 0x0055A1B8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_megatexturedModel(_BYTE *ptr)
{
  return (ptr[105] & 8) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_megatexturedModel@@YAXPAXH@Z
// EA  : 0x8255A1C8
// RVA : 0x0055A1C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_megatexturedModel(_BYTE *ptr, int value)
{
  ptr[105] = (8 * (value != 0)) & 8 | ptr[105] & 0xF7;
}


// ========================================================================
// ?Get_idRenderModelParms_addAlways@@YAHPAX@Z
// EA  : 0x8255A1E0
// RVA : 0x0055A1E0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_addAlways(_BYTE *ptr)
{
  return (ptr[105] & 4) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_addAlways@@YAXPAXH@Z
// EA  : 0x8255A1F0
// RVA : 0x0055A1F0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_addAlways(_BYTE *ptr, int value)
{
  ptr[105] = (4 * (value != 0)) & 4 | ptr[105] & 0xFB;
}


// ========================================================================
// ?Get_idRenderModelParms_viewOriented@@YAHPAX@Z
// EA  : 0x8255A208
// RVA : 0x0055A208
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_viewOriented(_BYTE *ptr)
{
  return (ptr[105] & 2) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_viewOriented@@YAXPAXH@Z
// EA  : 0x8255A218
// RVA : 0x0055A218
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_viewOriented(_BYTE *ptr, int value)
{
  ptr[105] = (2 * (value != 0)) & 2 | ptr[105] & 0xFD;
}


// ========================================================================
// ?Get_idRenderModelParms_mvpIsIdentity@@YAHPAX@Z
// EA  : 0x8255A230
// RVA : 0x0055A230
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idRenderModelParms_mvpIsIdentity(_BYTE *ptr)
{
  return ptr[105] & 1;
}


// ========================================================================
// ?Set_idRenderModelParms_mvpIsIdentity@@YAXPAXH@Z
// EA  : 0x8255A240
// RVA : 0x0055A240
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_mvpIsIdentity(_BYTE *ptr, int value)
{
  ptr[105] = (value != 0) | ptr[105] & 0xFE;
}


// ========================================================================
// ?Get_idRenderModelParms_mvpIsOrthographic@@YAHPAX@Z
// EA  : 0x8255A258
// RVA : 0x0055A258
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idRenderModelParms_mvpIsOrthographic(unsigned __int8 *ptr)
{
  return ptr[106] >> 7;
}


// ========================================================================
// ?Set_idRenderModelParms_mvpIsOrthographic@@YAXPAXH@Z
// EA  : 0x8255A268
// RVA : 0x0055A268
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_mvpIsOrthographic(_BYTE *ptr, int value)
{
  ptr[106] = ((value != 0) << 7) | ptr[106] & 0x7F;
}


// ========================================================================
// ?Get_idRenderModelParms_mvpIsSunFlare@@YAHPAX@Z
// EA  : 0x8255A280
// RVA : 0x0055A280
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_mvpIsSunFlare(_BYTE *ptr)
{
  return (ptr[106] & 0x40) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_mvpIsSunFlare@@YAXPAXH@Z
// EA  : 0x8255A290
// RVA : 0x0055A290
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_mvpIsSunFlare(_BYTE *ptr, int value)
{
  ptr[106] = ((value != 0) << 6) & 0x40 | ptr[106] & 0xBF;
}


// ========================================================================
// ?Get_idRenderModelParms_woundsActive@@YAHPAX@Z
// EA  : 0x8255A2A8
// RVA : 0x0055A2A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_woundsActive(_BYTE *ptr)
{
  return (ptr[106] & 0x20) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_woundsActive@@YAXPAXH@Z
// EA  : 0x8255A2B8
// RVA : 0x0055A2B8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_woundsActive(_BYTE *ptr, int value)
{
  ptr[106] = (32 * (value != 0)) & 0x20 | ptr[106] & 0xDF;
}


// ========================================================================
// ?Get_idRenderModelParms_noGPUocclusionTest@@YAHPAX@Z
// EA  : 0x8255A2D0
// RVA : 0x0055A2D0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_noGPUocclusionTest(_BYTE *ptr)
{
  return (ptr[106] & 0x10) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_noGPUocclusionTest@@YAXPAXH@Z
// EA  : 0x8255A2E0
// RVA : 0x0055A2E0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_noGPUocclusionTest(_BYTE *ptr, int value)
{
  ptr[106] = (16 * (value != 0)) & 0x10 | ptr[106] & 0xEF;
}


// ========================================================================
// ?Get_idRenderModelParms_neverOcclusionCullBounds@@YAHPAX@Z
// EA  : 0x8255A2F8
// RVA : 0x0055A2F8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_neverOcclusionCullBounds(_BYTE *ptr)
{
  return (ptr[106] & 8) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_neverOcclusionCullBounds@@YAXPAXH@Z
// EA  : 0x8255A308
// RVA : 0x0055A308
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_neverOcclusionCullBounds(_BYTE *ptr, int value)
{
  ptr[106] = (8 * (value != 0)) & 8 | ptr[106] & 0xF7;
}


// ========================================================================
// ?Get_idRenderModelParms_alwaysOcclusionCullBounds@@YAHPAX@Z
// EA  : 0x8255A320
// RVA : 0x0055A320
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_alwaysOcclusionCullBounds(_BYTE *ptr)
{
  return (ptr[106] & 4) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_alwaysOcclusionCullBounds@@YAXPAXH@Z
// EA  : 0x8255A330
// RVA : 0x0055A330
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_alwaysOcclusionCullBounds(_BYTE *ptr, int value)
{
  ptr[106] = (4 * (value != 0)) & 4 | ptr[106] & 0xFB;
}


// ========================================================================
// ?Get_idRenderModelParms_addAlwaysForceOcclusionQuery@@YAHPAX@Z
// EA  : 0x8255A348
// RVA : 0x0055A348
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_addAlwaysForceOcclusionQuery(_BYTE *ptr)
{
  return (ptr[106] & 2) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_addAlwaysForceOcclusionQuery@@YAXPAXH@Z
// EA  : 0x8255A358
// RVA : 0x0055A358
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_addAlwaysForceOcclusionQuery(_BYTE *ptr, int value)
{
  ptr[106] = (2 * (value != 0)) & 2 | ptr[106] & 0xFD;
}


// ========================================================================
// ?Get_idRenderModelParms_privateLightOnly@@YAHPAX@Z
// EA  : 0x8255A370
// RVA : 0x0055A370
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idRenderModelParms_privateLightOnly(_BYTE *ptr)
{
  return ptr[106] & 1;
}


// ========================================================================
// ?Set_idRenderModelParms_privateLightOnly@@YAXPAXH@Z
// EA  : 0x8255A380
// RVA : 0x0055A380
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_privateLightOnly(_BYTE *ptr, int value)
{
  ptr[106] = (value != 0) | ptr[106] & 0xFE;
}


// ========================================================================
// ?Get_idRenderModelParms_noLocalLighting@@YAHPAX@Z
// EA  : 0x8255A398
// RVA : 0x0055A398
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idRenderModelParms_noLocalLighting(unsigned __int8 *ptr)
{
  return ptr[107] >> 7;
}


// ========================================================================
// ?Set_idRenderModelParms_noLocalLighting@@YAXPAXH@Z
// EA  : 0x8255A3A8
// RVA : 0x0055A3A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_noLocalLighting(_BYTE *ptr, int value)
{
  ptr[107] = ((value != 0) << 7) | ptr[107] & 0x7F;
}


// ========================================================================
// ?Get_idRenderModelParms_moveLightingPoint@@YAHPAX@Z
// EA  : 0x8255A3C0
// RVA : 0x0055A3C0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_moveLightingPoint(_BYTE *ptr)
{
  return (ptr[107] & 0x40) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_moveLightingPoint@@YAXPAXH@Z
// EA  : 0x8255A3D0
// RVA : 0x0055A3D0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_moveLightingPoint(_BYTE *ptr, int value)
{
  ptr[107] = ((value != 0) << 6) & 0x40 | ptr[107] & 0xBF;
}


// ========================================================================
// ?Get_idRenderModelParms_boostLightingPoint@@YAHPAX@Z
// EA  : 0x8255A3E8
// RVA : 0x0055A3E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_boostLightingPoint(_BYTE *ptr)
{
  return (ptr[107] & 0x20) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_boostLightingPoint@@YAXPAXH@Z
// EA  : 0x8255A3F8
// RVA : 0x0055A3F8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_boostLightingPoint(_BYTE *ptr, int value)
{
  ptr[107] = (32 * (value != 0)) & 0x20 | ptr[107] & 0xDF;
}


// ========================================================================
// ?Get_idRenderModelParms_noAmbient@@YAHPAX@Z
// EA  : 0x8255A410
// RVA : 0x0055A410
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_noAmbient(_BYTE *ptr)
{
  return (ptr[107] & 0x10) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_noAmbient@@YAXPAXH@Z
// EA  : 0x8255A420
// RVA : 0x0055A420
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_noAmbient(_BYTE *ptr, int value)
{
  ptr[107] = (16 * (value != 0)) & 0x10 | ptr[107] & 0xEF;
}


// ========================================================================
// ?Get_idRenderModelParms_forceApproximatedLighting@@YAHPAX@Z
// EA  : 0x8255A438
// RVA : 0x0055A438
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_forceApproximatedLighting(_BYTE *ptr)
{
  return (ptr[107] & 8) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_forceApproximatedLighting@@YAXPAXH@Z
// EA  : 0x8255A448
// RVA : 0x0055A448
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_forceApproximatedLighting(_BYTE *ptr, int value)
{
  ptr[107] = (8 * (value != 0)) & 8 | ptr[107] & 0xF7;
}


// ========================================================================
// ?Get_idRenderModelParms_enableStaticSpecular@@YAHPAX@Z
// EA  : 0x8255A460
// RVA : 0x0055A460
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_enableStaticSpecular(_BYTE *ptr)
{
  return (ptr[107] & 4) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_enableStaticSpecular@@YAXPAXH@Z
// EA  : 0x8255A470
// RVA : 0x0055A470
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_enableStaticSpecular(_BYTE *ptr, int value)
{
  ptr[107] = (4 * (value != 0)) & 4 | ptr[107] & 0xFB;
}


// ========================================================================
// ?Get_idRenderModelParms_traceGroup@@YAHPAX@Z
// EA  : 0x8255A488
// RVA : 0x0055A488
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idRenderModelParms_traceGroup(char *ptr)
{
  return ptr[108];
}


// ========================================================================
// ?Set_idRenderModelParms_traceGroup@@YAXPAXH@Z
// EA  : 0x8255A498
// RVA : 0x0055A498
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_traceGroup(_BYTE *ptr, char value)
{
  ptr[108] = value;
}


// ========================================================================
// ?Get_idRenderModelParms_noStippleFade@@YAHPAX@Z
// EA  : 0x8255A4A0
// RVA : 0x0055A4A0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelParms_noStippleFade(_BYTE *ptr)
{
  return (ptr[116] & 0x20) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_noStippleFade@@YAXPAXH@Z
// EA  : 0x8255A4B0
// RVA : 0x0055A4B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_noStippleFade(_BYTE *ptr, int value)
{
  ptr[116] = (32 * (value != 0)) & 0x20 | ptr[116] & 0xDF;
}


// ========================================================================
// ?Get_idTreeAnimator_hasDeferredJoints@@YAHPAX@Z
// EA  : 0x8255A4C8
// RVA : 0x0055A4C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idTreeAnimator_hasDeferredJoints(unsigned __int8 *ptr)
{
  return ptr[2164] >> 7;
}


// ========================================================================
// ?Set_idTreeAnimator_hasDeferredJoints@@YAXPAXH@Z
// EA  : 0x8255A4D8
// RVA : 0x0055A4D8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idTreeAnimator_hasDeferredJoints(_BYTE *ptr, int value)
{
  ptr[2164] = ((value != 0) << 7) | ptr[2164] & 0x7F;
}


// ========================================================================
// ?Set_idTreeAnimator_clearOriginTransform@@YAXPAXH@Z
// EA  : 0x8255A4F0
// RVA : 0x0055A4F0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idTreeAnimator_clearOriginTransform(_BYTE *ptr, int value)
{
  ptr[2164] = ((value != 0) << 6) & 0x40 | ptr[2164] & 0xBF;
}


// ========================================================================
// ?Get_idTreeAnimator_originDeltaLookAhead@@YAHPAX@Z
// EA  : 0x8255A508
// RVA : 0x0055A508
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idTreeAnimator_originDeltaLookAhead(_BYTE *ptr)
{
  return (ptr[2164] & 0x20) != 0;
}


// ========================================================================
// ?Set_idTreeAnimator_originDeltaLookAhead@@YAXPAXH@Z
// EA  : 0x8255A518
// RVA : 0x0055A518
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idTreeAnimator_originDeltaLookAhead(_BYTE *ptr, int value)
{
  ptr[2164] = (32 * (value != 0)) & 0x20 | ptr[2164] & 0xDF;
}


// ========================================================================
// ?Get_idTreeAnimator_calcRefBoundsFromJoints@@YAHPAX@Z
// EA  : 0x8255A530
// RVA : 0x0055A530
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idTreeAnimator_calcRefBoundsFromJoints(_BYTE *ptr)
{
  return (ptr[2164] & 0x10) != 0;
}


// ========================================================================
// ?Set_idTreeAnimator_calcRefBoundsFromJoints@@YAXPAXH@Z
// EA  : 0x8255A540
// RVA : 0x0055A540
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idTreeAnimator_calcRefBoundsFromJoints(_BYTE *ptr, int value)
{
  ptr[2164] = (16 * (value != 0)) & 0x10 | ptr[2164] & 0xEF;
}


// ========================================================================
// ?Get_idTreeAnimator_updateMorphBuffers@@YAHPAX@Z
// EA  : 0x8255A558
// RVA : 0x0055A558
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idTreeAnimator_updateMorphBuffers(_BYTE *ptr)
{
  return (ptr[2164] & 8) != 0;
}


// ========================================================================
// ?Set_idTreeAnimator_updateMorphBuffers@@YAXPAXH@Z
// EA  : 0x8255A568
// RVA : 0x0055A568
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idTreeAnimator_updateMorphBuffers(_BYTE *ptr, int value)
{
  ptr[2164] = (8 * (value != 0)) & 8 | ptr[2164] & 0xF7;
}


// ========================================================================
// ?Get_idTreeAnimator_skipSerialization@@YAHPAX@Z
// EA  : 0x8255A580
// RVA : 0x0055A580
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idTreeAnimator_skipSerialization(_BYTE *ptr)
{
  return (ptr[2164] & 4) != 0;
}


// ========================================================================
// ?Set_idTreeAnimator_skipSerialization@@YAXPAXH@Z
// EA  : 0x8255A590
// RVA : 0x0055A590
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idTreeAnimator_skipSerialization(_BYTE *ptr, int value)
{
  ptr[2164] = (4 * (value != 0)) & 4 | ptr[2164] & 0xFB;
}


// ========================================================================
// ?Get_idTreeAnimator_useDualQuatSkinning@@YAHPAX@Z
// EA  : 0x8255A5A8
// RVA : 0x0055A5A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idTreeAnimator_useDualQuatSkinning(_BYTE *ptr)
{
  return (ptr[2164] & 2) != 0;
}


// ========================================================================
// ?Set_idTreeAnimator_useDualQuatSkinning@@YAXPAXH@Z
// EA  : 0x8255A5B8
// RVA : 0x0055A5B8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idTreeAnimator_useDualQuatSkinning(_BYTE *ptr, int value)
{
  ptr[2164] = (2 * (value != 0)) & 2 | ptr[2164] & 0xFD;
}


// ========================================================================
// ?Set_idDeclAIBehavior_canUseLadders@@YAXPAXH@Z
// EA  : 0x8255A5D0
// RVA : 0x0055A5D0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_canUseLadders(_BYTE *ptr, int value)
{
  ptr[84] = (4 * (value != 0)) & 4 | ptr[84] & 0xFB;
}


// ========================================================================
// ?Set_idDeclAIBehavior_idDamageBehaviors_usesRechargeHints@@YAXPAXH@Z
// EA  : 0x8255A5E8
// RVA : 0x0055A5E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_idDamageBehaviors_usesRechargeHints(_BYTE *ptr, int value)
{
  ptr[84] = (2 * (value != 0)) & 2 | ptr[84] & 0xFD;
}


// ========================================================================
// ?Get_idDeclFlare_useAltViewVecCalc@@YAHPAX@Z
// EA  : 0x8255A600
// RVA : 0x0055A600
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idDeclFlare_useAltViewVecCalc(unsigned __int8 *ptr)
{
  return ptr[80] >> 7;
}


// ========================================================================
// ?Set_idDeclFlare_useAltViewVecCalc@@YAXPAXH@Z
// EA  : 0x8255A610
// RVA : 0x0055A610
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idDeclFlare_useAltViewVecCalc(_BYTE *ptr, int value)
{
  ptr[80] = ((value != 0) << 7) | ptr[80] & 0x7F;
}


// ========================================================================
// ?Get_idParticleStage_alphaBlended@@YAHPAX@Z
// EA  : 0x8255A628
// RVA : 0x0055A628
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idParticleStage_alphaBlended(unsigned __int8 *ptr)
{
  return ptr[68] >> 7;
}


// ========================================================================
// ?Set_idParticleStage_alphaBlended@@YAXPAXH@Z
// EA  : 0x8255A638
// RVA : 0x0055A638
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idParticleStage_alphaBlended(_BYTE *ptr, int value)
{
  ptr[68] = ((value != 0) << 7) | ptr[68] & 0x7F;
}


// ========================================================================
// ?Get_idParticleStage_isTransparencySorted@@YAHPAX@Z
// EA  : 0x8255A650
// RVA : 0x0055A650
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idParticleStage_isTransparencySorted(_BYTE *ptr)
{
  return (ptr[68] & 0x40) != 0;
}


// ========================================================================
// ?Set_idPhysics_Static_isOrientated@@YAXPAXH@Z
// EA  : 0x8255A660
// RVA : 0x0055A660
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idPhysics_Static_isOrientated(_BYTE *ptr, int value)
{
  ptr[68] = ((value != 0) << 6) & 0x40 | ptr[68] & 0xBF;
}


// ========================================================================
// ?Get_idParticleStage_usesTransSortAtlas@@YAHPAX@Z
// EA  : 0x8255A678
// RVA : 0x0055A678
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idParticleStage_usesTransSortAtlas(_BYTE *ptr)
{
  return (ptr[68] & 0x20) != 0;
}


// ========================================================================
// ?Set_idParticleStage_usesTransSortAtlas@@YAXPAXH@Z
// EA  : 0x8255A688
// RVA : 0x0055A688
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idParticleStage_usesTransSortAtlas(_BYTE *ptr, int value)
{
  ptr[68] = (32 * (value != 0)) & 0x20 | ptr[68] & 0xDF;
}


// ========================================================================
// ?Get_idParticleStage_hasEmissivePass@@YAHPAX@Z
// EA  : 0x8255A6A0
// RVA : 0x0055A6A0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idParticleStage_hasEmissivePass(_BYTE *ptr)
{
  return (ptr[68] & 0x10) != 0;
}


// ========================================================================
// ?Set_idParticleStage_hasEmissivePass@@YAXPAXH@Z
// EA  : 0x8255A6B0
// RVA : 0x0055A6B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idParticleStage_hasEmissivePass(_BYTE *ptr, int value)
{
  ptr[68] = (16 * (value != 0)) & 0x10 | ptr[68] & 0xEF;
}


// ========================================================================
// ?Get_idParticleStage_hidden@@YAHPAX@Z
// EA  : 0x8255A6C8
// RVA : 0x0055A6C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idParticleStage_hidden(_BYTE *ptr)
{
  return (ptr[68] & 8) != 0;
}


// ========================================================================
// ?Set_idParticleStage_hidden@@YAXPAXH@Z
// EA  : 0x8255A6D8
// RVA : 0x0055A6D8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idParticleStage_hidden(_BYTE *ptr, int value)
{
  ptr[68] = (8 * (value != 0)) & 8 | ptr[68] & 0xF7;
}


// ========================================================================
// ?Get_idRenderModelChain_updateMorphBuffers@@YAHPAX@Z
// EA  : 0x8255A6F0
// RVA : 0x0055A6F0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idRenderModelChain_updateMorphBuffers(unsigned __int8 *ptr)
{
  return ptr[2204] >> 7;
}


// ========================================================================
// ?Set_idRenderModelChain_updateMorphBuffers@@YAXPAXH@Z
// EA  : 0x8255A700
// RVA : 0x0055A700
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelChain_updateMorphBuffers(_BYTE *ptr, int value)
{
  ptr[2204] = ((value != 0) << 7) | ptr[2204] & 0x7F;
}


// ========================================================================
// ?Get_idRenderModelChain_updateJointBuffers@@YAHPAX@Z
// EA  : 0x8255A718
// RVA : 0x0055A718
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelChain_updateJointBuffers(_BYTE *ptr)
{
  return (ptr[2204] & 0x40) != 0;
}


// ========================================================================
// ?Set_idRenderModelChain_updateJointBuffers@@YAXPAXH@Z
// EA  : 0x8255A728
// RVA : 0x0055A728
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelChain_updateJointBuffers(_BYTE *ptr, int value)
{
  ptr[2204] = ((value != 0) << 6) & 0x40 | ptr[2204] & 0xBF;
}


// ========================================================================
// ?Get_idEarClipTriangulate_Vertex_t_isConvex@@YAHPAX@Z
// EA  : 0x8255A740
// RVA : 0x0055A740
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idEarClipTriangulate_Vertex_t_isConvex(unsigned __int16 *ptr)
{
  return (int)__ROL4__(ptr[7], 16) >> 31;
}


// ========================================================================
// ?Set_idEarClipTriangulate_Vertex_t_isConvex@@YAXPAXH@Z
// EA  : 0x8255A750
// RVA : 0x0055A750
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idEarClipTriangulate_Vertex_t_isConvex(_WORD *ptr, __int16 value)
{
  ptr[7] = (value << 15) | ptr[7] & 0x7FFF;
}


// ========================================================================
// ?Get_idEarClipTriangulate_Vertex_t_isEar@@YAHPAX@Z
// EA  : 0x8255A760
// RVA : 0x0055A760
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idEarClipTriangulate_Vertex_t_isEar(unsigned __int16 *ptr)
{
  return ptr[7] << 17 >> 31;
}


// ========================================================================
// ?Set_idEarClipTriangulate_Vertex_t_isEar@@YAXPAXH@Z
// EA  : 0x8255A770
// RVA : 0x0055A770
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idEarClipTriangulate_Vertex_t_isEar(_WORD *ptr, __int16 value)
{
  ptr[7] = (value << 14) & 0x4000 | ptr[7] & 0xBFFF;
}


// ========================================================================
// ?Get_idEarClipTriangulate_Vertex_t___free@@YAHPAX@Z
// EA  : 0x8255A788
// RVA : 0x0055A788
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idEarClipTriangulate_Vertex_t___free(unsigned __int16 *ptr)
{
  return ptr[7] << 18 >> 18;
}


// ========================================================================
// ?Set_idEarClipTriangulate_Vertex_t___free@@YAXPAXH@Z
// EA  : 0x8255A798
// RVA : 0x0055A798
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idEarClipTriangulate_Vertex_t___free(_WORD *ptr, __int16 value)
{
  ptr[7] = value & 0x3FFF | ptr[7] & 0xC000;
}


// ========================================================================
// ?Get_idCutterGraphManager_Link_t_allocated@@YAHPAX@Z
// EA  : 0x8255A7B0
// RVA : 0x0055A7B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idCutterGraphManager_Link_t_allocated(int *ptr)
{
  return ptr[3] >> 31;
}


// ========================================================================
// ?Set_idCutterGraphManager_Link_t_allocated@@YAXPAXH@Z
// EA  : 0x8255A7C0
// RVA : 0x0055A7C0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idCutterGraphManager_Link_t_allocated(_DWORD *ptr, int value)
{
  ptr[3] = (value << 31) | ptr[3] & 0x7FFFFFFF;
}


// ========================================================================
// ?Get_idCutterGraphManager_Node_t_id@@YAHPAX@Z
// EA  : 0x8255A7D0
// RVA : 0x0055A7D0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idCutterGraphManager_Node_t_id(int *ptr)
{
  return ptr[4] >> 1;
}


// ========================================================================
// ?Set_idCutterGraphManager_IDHeap_index@@YAXPAXH@Z
// EA  : 0x8255A7E0
// RVA : 0x0055A7E0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idCutterGraphManager_IDHeap_index(_DWORD *ptr, int value)
{
  ptr[4] = (2 * value) | ptr[4] & 1;
}


// ========================================================================
// ?Get_idCutterGraphManager_Node_t_allocated@@YAHPAX@Z
// EA  : 0x8255A7F0
// RVA : 0x0055A7F0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idCutterGraphManager_Node_t_allocated(_DWORD *ptr)
{
  return (int)(ptr[4] << 31) >> 31;
}


// ========================================================================
// ?Set_idCutterGraphManager_Node_t_allocated@@YAXPAXH@Z
// EA  : 0x8255A800
// RVA : 0x0055A800
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idCutterGraphManager_Node_t_allocated(_DWORD *ptr, char value)
{
  ptr[4] = ptr[4] & 0xFFFFFFFE | value & 1;
}


// ========================================================================
// ?Get_idCutterGraphManager_Edge_t_visited@@YAHPAX@Z
// EA  : 0x8255A810
// RVA : 0x0055A810
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idCutterGraphManager_Edge_t_visited(int *ptr)
{
  return ptr[5] >> 31;
}


// ========================================================================
// ?Set_idCutterGraphManager_Edge_t_visited@@YAXPAXH@Z
// EA  : 0x8255A820
// RVA : 0x0055A820
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idCutterGraphManager_Edge_t_visited(_DWORD *ptr, int value)
{
  ptr[5] = (value << 31) | ptr[5] & 0x7FFFFFFF;
}


// ========================================================================
// ?Get_idCutterGraphManager_Edge_t_allocated@@YAHPAX@Z
// EA  : 0x8255A830
// RVA : 0x0055A830
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idCutterGraphManager_Edge_t_allocated(_DWORD *ptr)
{
  return (2 * ptr[5]) >> 31;
}


// ========================================================================
// ?Set_idCutterGraphManager_Edge_t_allocated@@YAXPAXH@Z
// EA  : 0x8255A840
// RVA : 0x0055A840
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idCutterGraphManager_Edge_t_allocated(_DWORD *ptr, int value)
{
  ptr[5] = (value << 30) & 0x40000000 | ptr[5] & 0xBFFFFFFF;
}


// ========================================================================
// ?Get_idCutterGraphManager_IDHeap_index@@YAHPAX@Z
// EA  : 0x8255A850
// RVA : 0x0055A850
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idCutterGraphManager_IDHeap_index(_DWORD *ptr)
{
  return ptr[4] >> 1;
}


// ========================================================================
// ?Get_idCutterGraphManager_IDHeap_isStatic@@YAHPAX@Z
// EA  : 0x8255A860
// RVA : 0x0055A860
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idCutterGraphManager_IDHeap_isStatic(_DWORD *ptr)
{
  return ptr[4] & 1;
}


// ========================================================================
// ?Get_idCutterClip_running@@YAHPAX@Z
// EA  : 0x8255A870
// RVA : 0x0055A870
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idCutterClip_running(unsigned __int8 *ptr)
{
  return (int)__ROR4__(ptr[272], 8) >> 31;
}


// ========================================================================
// ?Set_idCutterClip_running@@YAXPAXH@Z
// EA  : 0x8255A880
// RVA : 0x0055A880
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idCutterClip_running(_BYTE *ptr, char value)
{
  ptr[272] = (value << 7) | ptr[272] & 0x7F;
}


// ========================================================================
// ?Get_idCutterClip_Edge_t_side@@YAHPAX@Z
// EA  : 0x8255A890
// RVA : 0x0055A890
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idCutterClip_Edge_t_side(unsigned __int16 *ptr)
{
  return ptr[36] >> 15;
}


// ========================================================================
// ?Set_idCutterClip_Edge_t_side@@YAXPAXH@Z
// EA  : 0x8255A8A0
// RVA : 0x0055A8A0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idCutterClip_Edge_t_side(_WORD *ptr, __int16 value)
{
  ptr[36] = (value << 15) | ptr[36] & 0x7FFF;
}


// ========================================================================
// ?Get_idCutterClip_Edge_t_polyType@@YAHPAX@Z
// EA  : 0x8255A8B0
// RVA : 0x0055A8B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idCutterClip_Edge_t_polyType(_WORD *ptr)
{
  return (ptr[36] & 0x4000) != 0;
}


// ========================================================================
// ?Set_idCutterClip_Edge_t_polyType@@YAXPAXH@Z
// EA  : 0x8255A8C0
// RVA : 0x0055A8C0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idCutterClip_Edge_t_polyType(_WORD *ptr, __int16 value)
{
  ptr[36] = (value << 14) & 0x4000 | ptr[36] & 0xBFFF;
}


// ========================================================================
// ?Get_idCutterClip_Edge_t_horizontal@@YAHPAX@Z
// EA  : 0x8255A8D0
// RVA : 0x0055A8D0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idCutterClip_Edge_t_horizontal(_WORD *ptr)
{
  return (ptr[36] & 0x2000) != 0;
}


// ========================================================================
// ?Set_idCutterClip_Edge_t_horizontal@@YAXPAXH@Z
// EA  : 0x8255A8E0
// RVA : 0x0055A8E0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idCutterClip_Edge_t_horizontal(_WORD *ptr, __int16 value)
{
  ptr[36] = (value << 13) & 0x2000 | ptr[36] & 0xDFFF;
}


// ========================================================================
// ?Get_idCutterClip_Edge_t___free@@YAHPAX@Z
// EA  : 0x8255A8F0
// RVA : 0x0055A8F0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idCutterClip_Edge_t___free(unsigned __int16 *ptr)
{
  return (ptr[36] >> 1) & 0xFFF;
}


// ========================================================================
// ?Set_idCutterClip_Edge_t___free@@YAXPAXH@Z
// EA  : 0x8255A900
// RVA : 0x0055A900
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idCutterClip_Edge_t___free(_WORD *ptr, __int16 value)
{
  ptr[36] = (2 * value) & 0x1FFE | ptr[36] & 0xE001;
}


// ========================================================================
// ?Set_idContents_solid@@YAXPAXH@Z
// EA  : 0x8255A910
// RVA : 0x0055A910
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idContents_solid(_BYTE *ptr, int value)
{
  *ptr = ((value != 0) << 7) | *ptr & 0x7F;
}


// ========================================================================
// ?Set_idAFBody_afBodyFlags_t_selfCollision@@YAXPAXH@Z
// EA  : 0x8255A928
// RVA : 0x0055A928
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idAFBody_afBodyFlags_t_selfCollision(_BYTE *ptr, int value)
{
  *ptr = ((value != 0) << 6) & 0x40 | *ptr & 0xBF;
}


// ========================================================================
// ?Get_idAFConstraint_constraintFlags_s_noCollision@@YAHPAX@Z
// EA  : 0x8255A940
// RVA : 0x0055A940
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idAFConstraint_constraintFlags_s_noCollision(_BYTE *ptr)
{
  return (*ptr & 0x20) != 0;
}


// ========================================================================
// ?Set_idPhysics_RigidBody3DOF_simpleBodyFlags_t_hasMaster@@YAXPAXH@Z
// EA  : 0x8255A950
// RVA : 0x0055A950
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idPhysics_RigidBody3DOF_simpleBodyFlags_t_hasMaster(_BYTE *ptr, int value)
{
  *ptr = (32 * (value != 0)) & 0x20 | *ptr & 0xDF;
}


// ========================================================================
// ?Set_idNavSplinePath_splineFlags_t_raceForward@@YAXPAXH@Z
// EA  : 0x8255A968
// RVA : 0x0055A968
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idNavSplinePath_splineFlags_t_raceForward(_BYTE *ptr, int value)
{
  *ptr = (16 * (value != 0)) & 0x10 | *ptr & 0xEF;
}


// ========================================================================
// ?Set_idHudPickupInfo_inVehicle@@YAXPAXH@Z
// EA  : 0x8255A980
// RVA : 0x0055A980
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idHudPickupInfo_inVehicle(_BYTE *ptr, int value)
{
  *ptr = (8 * (value != 0)) & 8 | *ptr & 0xF7;
}


// ========================================================================
// ?Set_idNavSplinePath_splineFlags_t_canRespawn@@YAXPAXH@Z
// EA  : 0x8255A998
// RVA : 0x0055A998
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idNavSplinePath_splineFlags_t_canRespawn(_BYTE *ptr, int value)
{
  *ptr = (4 * (value != 0)) & 4 | *ptr & 0xFB;
}


// ========================================================================
// ?Set_idEntity_entityFlags_t_takedamage@@YAXPAXH@Z
// EA  : 0x8255A9B0
// RVA : 0x0055A9B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idEntity_entityFlags_t_takedamage(_BYTE *ptr, int value)
{
  *ptr = (2 * (value != 0)) & 2 | *ptr & 0xFD;
}


// ========================================================================
// ?Set_idAFBody_afBodyFlags_t_clearClipMaskInSolid@@YAXPAXH@Z
// EA  : 0x8255A9C8
// RVA : 0x0055A9C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idAFBody_afBodyFlags_t_clearClipMaskInSolid(_BYTE *ptr, int value)
{
  *ptr = (value != 0) | *ptr & 0xFE;
}


// ========================================================================
// ?Get_idContents_ikClip@@YAHPAX@Z
// EA  : 0x8255A9E0
// RVA : 0x0055A9E0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idContents_ikClip(unsigned __int8 *ptr)
{
  return ptr[1] >> 7;
}


// ========================================================================
// ?Set_idEntity_entityFlags_t_isDormant@@YAXPAXH@Z
// EA  : 0x8255A9F0
// RVA : 0x0055A9F0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idEntity_entityFlags_t_isDormant(_BYTE *ptr, int value)
{
  ptr[1] = ((value != 0) << 7) | ptr[1] & 0x7F;
}


// ========================================================================
// ?Get_idEntity_entityFlags_t_noSightStimulus@@YAHPAX@Z
// EA  : 0x8255AA08
// RVA : 0x0055AA08
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idEntity_entityFlags_t_noSightStimulus(_BYTE *ptr)
{
  return (ptr[1] & 0x40) != 0;
}


// ========================================================================
// ?Set_idEntity_entityFlags_t_noSightStimulus@@YAXPAXH@Z
// EA  : 0x8255AA18
// RVA : 0x0055AA18
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idEntity_entityFlags_t_noSightStimulus(_BYTE *ptr, int value)
{
  ptr[1] = ((value != 0) << 6) & 0x40 | ptr[1] & 0xBF;
}


// ========================================================================
// ?Get_idContents_ai@@YAHPAX@Z
// EA  : 0x8255AA30
// RVA : 0x0055AA30
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idContents_ai(_BYTE *ptr)
{
  return (ptr[1] & 0x20) != 0;
}


// ========================================================================
// ?Set_idEntity_entityFlags_t_enableStaticSpecular@@YAXPAXH@Z
// EA  : 0x8255AA40
// RVA : 0x0055AA40
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idEntity_entityFlags_t_enableStaticSpecular(_BYTE *ptr, int value)
{
  ptr[1] = (32 * (value != 0)) & 0x20 | ptr[1] & 0xDF;
}


// ========================================================================
// ?Get_idEntity_entityFlags_t_touchesTriggers@@YAHPAX@Z
// EA  : 0x8255AA58
// RVA : 0x0055AA58
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idEntity_entityFlags_t_touchesTriggers(_BYTE *ptr)
{
  return (ptr[1] & 0x10) != 0;
}


// ========================================================================
// ?Set_idEntity_entityFlags_t_touchesTriggers@@YAXPAXH@Z
// EA  : 0x8255AA68
// RVA : 0x0055AA68
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idEntity_entityFlags_t_touchesTriggers(_BYTE *ptr, int value)
{
  ptr[1] = (16 * (value != 0)) & 0x10 | ptr[1] & 0xEF;
}


// ========================================================================
// ?Get_idEntity_entityFlags_t_afTouchesTriggers@@YAHPAX@Z
// EA  : 0x8255AA80
// RVA : 0x0055AA80
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idEntity_entityFlags_t_afTouchesTriggers(_BYTE *ptr)
{
  return (ptr[1] & 8) != 0;
}


// ========================================================================
// ?Set_idContents_corpse@@YAXPAXH@Z
// EA  : 0x8255AA90
// RVA : 0x0055AA90
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idContents_corpse(_BYTE *ptr, int value)
{
  ptr[1] = (8 * (value != 0)) & 8 | ptr[1] & 0xF7;
}


// ========================================================================
// ?Get_idContents_trigger@@YAHPAX@Z
// EA  : 0x8255AAA8
// RVA : 0x0055AAA8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idContents_trigger(_BYTE *ptr)
{
  return (ptr[1] & 4) != 0;
}


// ========================================================================
// ?Set_idContents_trigger@@YAXPAXH@Z
// EA  : 0x8255AAB8
// RVA : 0x0055AAB8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idContents_trigger(_BYTE *ptr, int value)
{
  ptr[1] = (4 * (value != 0)) & 4 | ptr[1] & 0xFB;
}


// ========================================================================
// ?Get_idEntity_entityFlags_t_dynamicClipReplication@@YAHPAX@Z
// EA  : 0x8255AAD0
// RVA : 0x0055AAD0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idEntity_entityFlags_t_dynamicClipReplication(_BYTE *ptr)
{
  return (ptr[1] & 2) != 0;
}


// ========================================================================
// ?Set_idContents_player@@YAXPAXH@Z
// EA  : 0x8255AAE0
// RVA : 0x0055AAE0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idContents_player(_BYTE *ptr, int value)
{
  ptr[1] = (2 * (value != 0)) & 2 | ptr[1] & 0xFD;
}


// ========================================================================
// ?Get_idContents_vehicle@@YAHPAX@Z
// EA  : 0x8255AAF8
// RVA : 0x0055AAF8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idContents_vehicle(_BYTE *ptr)
{
  return ptr[1] & 1;
}


// ========================================================================
// ?Set_idContents_vehicle@@YAXPAXH@Z
// EA  : 0x8255AB08
// RVA : 0x0055AB08
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idContents_vehicle(_BYTE *ptr, int value)
{
  ptr[1] = (value != 0) | ptr[1] & 0xFE;
}


// ========================================================================
// ?Get_idContents_obstacle@@YAHPAX@Z
// EA  : 0x8255AB20
// RVA : 0x0055AB20
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idContents_obstacle(unsigned __int8 *ptr)
{
  return ptr[2] >> 7;
}


// ========================================================================
// ?Set_idEntity_entityFlags_t_isAimAssistTarget@@YAXPAXH@Z
// EA  : 0x8255AB30
// RVA : 0x0055AB30
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idEntity_entityFlags_t_isAimAssistTarget(_BYTE *ptr, int value)
{
  ptr[2] = ((value != 0) << 7) | ptr[2] & 0x7F;
}


// ========================================================================
// ?Get_idContents_contextualCoverClip@@YAHPAX@Z
// EA  : 0x8255AB48
// RVA : 0x0055AB48
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idContents_contextualCoverClip(_BYTE *ptr)
{
  return (ptr[2] & 0x40) != 0;
}


// ========================================================================
// ?Set_idContents_contextualCoverClip@@YAXPAXH@Z
// EA  : 0x8255AB58
// RVA : 0x0055AB58
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idContents_contextualCoverClip(_BYTE *ptr, int value)
{
  ptr[2] = ((value != 0) << 6) & 0x40 | ptr[2] & 0xBF;
}


// ========================================================================
// ?Get_idContents_playerCoverClip@@YAHPAX@Z
// EA  : 0x8255AB70
// RVA : 0x0055AB70
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idContents_playerCoverClip(_BYTE *ptr)
{
  return (ptr[2] & 0x20) != 0;
}


// ========================================================================
// ?Set_idContents_playerCoverClip@@YAXPAXH@Z
// EA  : 0x8255AB80
// RVA : 0x0055AB80
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idContents_playerCoverClip(_BYTE *ptr, int value)
{
  ptr[2] = (32 * (value != 0)) & 0x20 | ptr[2] & 0xDF;
}


// ========================================================================
// ?Get_idContents_monsterCoverClip@@YAHPAX@Z
// EA  : 0x8255AB98
// RVA : 0x0055AB98
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idContents_monsterCoverClip(_BYTE *ptr)
{
  return (ptr[2] & 0x10) != 0;
}


// ========================================================================
// ?Set_idContents_monsterCoverClip@@YAXPAXH@Z
// EA  : 0x8255ABA8
// RVA : 0x0055ABA8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idContents_monsterCoverClip(_BYTE *ptr, int value)
{
  ptr[2] = (16 * (value != 0)) & 0x10 | ptr[2] & 0xEF;
}


// ========================================================================
// ?Get_idContents_playerFocus@@YAHPAX@Z
// EA  : 0x8255ABC0
// RVA : 0x0055ABC0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idContents_playerFocus(_BYTE *ptr)
{
  return (ptr[2] & 8) != 0;
}


// ========================================================================
// ?Set_idContents_playerFocus@@YAXPAXH@Z
// EA  : 0x8255ABD0
// RVA : 0x0055ABD0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idContents_playerFocus(_BYTE *ptr, int value)
{
  ptr[2] = (8 * (value != 0)) & 8 | ptr[2] & 0xF7;
}


// ========================================================================
// ?Get_idContents_pushable@@YAHPAX@Z
// EA  : 0x8255ABE8
// RVA : 0x0055ABE8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idContents_pushable(_BYTE *ptr)
{
  return (ptr[2] & 4) != 0;
}


// ========================================================================
// ?Set_idContents_pushable@@YAXPAXH@Z
// EA  : 0x8255ABF8
// RVA : 0x0055ABF8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idContents_pushable(_BYTE *ptr, int value)
{
  ptr[2] = (4 * (value != 0)) & 4 | ptr[2] & 0xFB;
}


// ========================================================================
// ?Get_idContents_tickClip@@YAHPAX@Z
// EA  : 0x8255AC10
// RVA : 0x0055AC10
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idContents_tickClip(_BYTE *ptr)
{
  return (ptr[2] & 2) != 0;
}


// ========================================================================
// ?Set_idContents_tickClip@@YAXPAXH@Z
// EA  : 0x8255AC20
// RVA : 0x0055AC20
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idContents_tickClip(_BYTE *ptr, int value)
{
  ptr[2] = (2 * (value != 0)) & 2 | ptr[2] & 0xFD;
}


// ========================================================================
// ?Get_idContents_shield@@YAHPAX@Z
// EA  : 0x8255AC38
// RVA : 0x0055AC38
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idContents_shield(_BYTE *ptr)
{
  return ptr[2] & 1;
}


// ========================================================================
// ?Set_idContents_shield@@YAXPAXH@Z
// EA  : 0x8255AC48
// RVA : 0x0055AC48
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idContents_shield(_BYTE *ptr, int value)
{
  ptr[2] = (value != 0) | ptr[2] & 0xFE;
}


// ========================================================================
// ?Get_idContents_noCover@@YAHPAX@Z
// EA  : 0x8255AC60
// RVA : 0x0055AC60
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idContents_noCover(unsigned __int8 *ptr)
{
  return ptr[3] >> 7;
}


// ========================================================================
// ?Set_idContents_noCover@@YAXPAXH@Z
// EA  : 0x8255AC70
// RVA : 0x0055AC70
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idContents_noCover(_BYTE *ptr, int value)
{
  ptr[3] = ((value != 0) << 7) | ptr[3] & 0x7F;
}


// ========================================================================
// ?Get_playerCoverPoint_t_lean@@YAHPAX@Z
// EA  : 0x8255AC88
// RVA : 0x0055AC88
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_playerCoverPoint_t_lean(unsigned __int8 *ptr)
{
  return ptr[16] >> 7;
}


// ========================================================================
// ?Set_playerCoverPoint_t_lean@@YAXPAXH@Z
// EA  : 0x8255AC98
// RVA : 0x0055AC98
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_playerCoverPoint_t_lean(_BYTE *ptr, int value)
{
  ptr[16] = ((value != 0) << 7) | ptr[16] & 0x7F;
}


// ========================================================================
// ?Get_playerCoverPoint_t_valid@@YAHPAX@Z
// EA  : 0x8255ACB0
// RVA : 0x0055ACB0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_playerCoverPoint_t_valid(_BYTE *ptr)
{
  return (ptr[16] & 0x40) != 0;
}


// ========================================================================
// ?Set_playerCoverPoint_t_valid@@YAXPAXH@Z
// EA  : 0x8255ACC0
// RVA : 0x0055ACC0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_playerCoverPoint_t_valid(_BYTE *ptr, int value)
{
  ptr[16] = ((value != 0) << 6) & 0x40 | ptr[16] & 0xBF;
}


// ========================================================================
// ?Set_idRenderModelInfo_allowInline@@YAXPAXH@Z
// EA  : 0x8255ACD8
// RVA : 0x0055ACD8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelInfo_allowInline(_BYTE *ptr, int value)
{
  ptr[4] = ((value != 0) << 7) | ptr[4] & 0x7F;
}


// ========================================================================
// ?Set_idPhysics_RigidBody_rigidBodyFlags_t_testSolid@@YAXPAXH@Z
// EA  : 0x8255ACF0
// RVA : 0x0055ACF0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idPhysics_RigidBody_rigidBodyFlags_t_testSolid(_BYTE *ptr, int value)
{
  ptr[4] = ((value != 0) << 6) & 0x40 | ptr[4] & 0xBF;
}


// ========================================================================
// ?Set_idRenderModelInfo_noShadows@@YAXPAXH@Z
// EA  : 0x8255AD08
// RVA : 0x0055AD08
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idRenderModelInfo_noShadows(_BYTE *ptr, int value)
{
  ptr[4] = (32 * (value != 0)) & 0x20 | ptr[4] & 0xDF;
}


// ========================================================================
// ?Set_idCoverActions_fireLeanRight@@YAXPAXH@Z
// EA  : 0x8255AD20
// RVA : 0x0055AD20
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idCoverActions_fireLeanRight(_BYTE *ptr, int value)
{
  ptr[4] = (16 * (value != 0)) & 0x10 | ptr[4] & 0xEF;
}


// ========================================================================
// ?Set_idPhysics_RigidBody_rigidBodyFlags_t_isOrientated@@YAXPAXH@Z
// EA  : 0x8255AD38
// RVA : 0x0055AD38
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idPhysics_RigidBody_rigidBodyFlags_t_isOrientated(_BYTE *ptr, int value)
{
  ptr[4] = (8 * (value != 0)) & 8 | ptr[4] & 0xF7;
}


// ========================================================================
// ?Get_idAnimator_Channel_forceFree@@YAHPAX@Z
// EA  : 0x8255AD50
// RVA : 0x0055AD50
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

int __fastcall Get_idAnimator_Channel_forceFree(unsigned __int8 *ptr)
{
  return ptr[94] >> 7;
}


// ========================================================================
// ?Set_idAnimator_Channel_forceFree@@YAXPAXH@Z
// EA  : 0x8255AD60
// RVA : 0x0055AD60
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idAnimator_Channel_forceFree(_BYTE *ptr, int value)
{
  ptr[94] = ((value != 0) << 7) | ptr[94] & 0x7F;
}


// ========================================================================
// ?Get_idAnimator_Channel_omitFreeLeafWarning@@YAHPAX@Z
// EA  : 0x8255AD78
// RVA : 0x0055AD78
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

BOOL __fastcall Get_idAnimator_Channel_omitFreeLeafWarning(_BYTE *ptr)
{
  return (ptr[94] & 0x40) != 0;
}


// ========================================================================
// ?Set_idAnimator_Channel_omitFreeLeafWarning@@YAXPAXH@Z
// EA  : 0x8255AD88
// RVA : 0x0055AD88
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void __fastcall Set_idAnimator_Channel_omitFreeLeafWarning(_BYTE *ptr, int value)
{
  ptr[94] = ((value != 0) << 6) & 0x40 | ptr[94] & 0xBF;
}


// ========================================================================
// `dynamic initializer for 'idTimeManager_typeInfo''
// EA  : 0x83334D20
// RVA : 0x01334D20
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void _dynamic_initializer_for__idTimeManager_typeInfo__()
{
  idTimeManager_typeInfo[2].get = nullptr;
  idTimeManager_typeInfo[2].set = nullptr;
  idTimeManager_typeInfo[2].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idAnimStack_typeInfo''
// EA  : 0x83334D40
// RVA : 0x01334D40
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void _dynamic_initializer_for__idAnimStack_typeInfo__()
{
  idAnimStack_typeInfo[18].get = nullptr;
  idAnimStack_typeInfo[18].set = nullptr;
  idAnimStack_typeInfo[18].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idVoiceTrack_typeInfo''
// EA  : 0x83334D60
// RVA : 0x01334D60
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void _dynamic_initializer_for__idVoiceTrack_typeInfo__()
{
  idVoiceTrack_typeInfo[33].get = nullptr;
  idVoiceTrack_typeInfo[33].set = nullptr;
  idVoiceTrack_typeInfo[33].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idVoiceTrack_idSubtitleText_typeInfo''
// EA  : 0x83334D80
// RVA : 0x01334D80
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void _dynamic_initializer_for__idVoiceTrack_idSubtitleText_typeInfo__()
{
  idVoiceTrack_idSubtitleText_typeInfo[2].get = nullptr;
  idVoiceTrack_idSubtitleText_typeInfo[2].set = nullptr;
  idVoiceTrack_idSubtitleText_typeInfo[2].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idDeclPonytail_idPonytailJointInfo_typeInfo''
// EA  : 0x83334DA0
// RVA : 0x01334DA0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_1.cpp
// ========================================================================

void _dynamic_initializer_for__idDeclPonytail_idPonytailJointInfo_typeInfo__()
{
  idDeclPonytail_idPonytailJointInfo_typeInfo[4].get = nullptr;
  idDeclPonytail_idPonytailJointInfo_typeInfo[4].set = nullptr;
  idDeclPonytail_idPonytailJointInfo_typeInfo[4].reallocate = nullptr;
}

