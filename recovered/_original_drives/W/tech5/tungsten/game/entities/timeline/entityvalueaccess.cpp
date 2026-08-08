
// ========================================================================
// ?SetValue@mgEntityValueAccess@@SA_NPAVidEntity@@W4tlKeyId_t@@M@Z
// EA  : 0x82CEA8B8
// RVA : 0x00CEA8B8
// PDB : w:\tech5\tungsten\game\entities\timeline\entityvalueaccess.cpp
// ========================================================================

int __fastcall mgEntityValueAccess::SetValue(idAnimCamera *entity, int key, double val)
{
  int v5; // r4
  idAnimCamera *v6; // r3

  if ( key < 3 )
    return 0;
  if ( key > 6 )
    return 0;
  v6 = idAnimCamera::CastTo(c: entity);
  if ( v6 == nullptr )
    return 0;
  idAnimCamera::SetDOFOverride(this: v6, val, index: v5, a4: key - 3);
  return 1;
}


// ========================================================================
// ?SetValue@mgEntityValueAccess@@SA_NPAVidEntity@@W4tlKeyId_t@@ABVidVec3@@@Z
// EA  : 0x82CEA920
// RVA : 0x00CEA920
// PDB : w:\tech5\tungsten\game\entities\timeline\entityvalueaccess.cpp
// ========================================================================

int __fastcall mgEntityValueAccess::SetValue(idLight *entity, tlKeyId_t key, const idVec3 *val)
{
  idLight *v4; // r3
  idLight *v5; // r31

  if ( key != TL_KEY_LIGHTCOLOR )
    return 0;
  v4 = idLight::CastTo(c: entity);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  v4->SetColor_3(this: v4, a2: val);
  idLight::SetLightLevel(this: v5);
  return 1;
}


// ========================================================================
// ?SetValue@mgEntityValueAccess@@SA_NPAVidEntity@@W4tlKeyId_t@@ABVidVec4@@@Z
// EA  : 0x82CEA990
// RVA : 0x00CEA990
// PDB : w:\tech5\tungsten\game\entities\timeline\entityvalueaccess.cpp
// ========================================================================

int __fastcall mgEntityValueAccess::SetValue(idAnimCamera *entity, tlKeyId_t key, const idVec4 *val)
{
  idAnimCamera *v4; // r3

  if ( key != TL_KEY_DOF )
    return 0;
  v4 = idAnimCamera::CastTo(c: entity);
  if ( v4 == nullptr )
    return 0;
  idAnimCamera::SetDOFOverride(this: v4, val);
  return 1;
}


// ========================================================================
// ?ResetKey@mgEntityValueAccess@@SAXPAVidEntity@@W4tlKeyId_t@@@Z
// EA  : 0x82CEA9F0
// RVA : 0x00CEA9F0
// PDB : w:\tech5\tungsten\game\entities\timeline\entityvalueaccess.cpp
// ========================================================================

void __fastcall mgEntityValueAccess::ResetKey(idAnimCamera *entity, unsigned int key)
{
  idVec4 v2; // [sp+50h] [-20h] BYREF

  if ( key <= 6 && key >= 2 )
  {
    if ( key == 2 )
    {
      v2.x = -1.0;
      v2.y = -1.0;
      v2.z = -1.0;
      v2.w = -1.0;
      mgEntityValueAccess::SetValue(entity, key: TL_KEY_DOF, val: &v2);
    }
    else
    {
      mgEntityValueAccess::SetValue(entity, key, val: -1.0);
    }
  }
}


// ========================================================================
// ?SetValueStr@mgEntityValueAccess@@SA_NPAVidEntity@@W4tlKeyId_t@@ABVidStr@@@Z
// EA  : 0x82CEAA78
// RVA : 0x00CEAA78
// PDB : w:\tech5\tungsten\game\entities\timeline\entityvalueaccess.cpp
// ========================================================================

int __fastcall mgEntityValueAccess::SetValueStr(idAnimCamera *entity, __int32 key, const idStr *valueStr)
{
  tlKeyType_t Type; // r3
  idEntity_vtbl *v7; // r11
  idAnimCamera *v10; // r3
  bool v11; // [sp+50h] [-50h] BYREF
  float v12; // [sp+54h] [-4Ch] BYREF
  idVec3 v13[2]; // [sp+58h] [-48h] BYREF
  idVec4 v14[3]; // [sp+70h] [-30h] BYREF

  Type = mgTimelineKeyUtil::GetType((tlKeyId_t)key);
  if ( (unsigned int)Type > TL_KEYTYPE_COLOR_RGBA )
    return 0;
  switch ( Type )
  {
    case TL_KEYTYPE_INT:
      mgTimelineKeyUtil::FromString(valueStr, val: (int *)&v12);
      return 0;
    case TL_KEYTYPE_FLOAT:
      if ( !mgTimelineKeyUtil::FromString(valueStr, val: &v12) )
        return 0;
      return mgEntityValueAccess::SetValue(entity, key, val: v12);
    case TL_KEYTYPE_FLOAT3:
    case TL_KEYTYPE_COLOR_RGB:
      if ( (unsigned __int8)mgTimelineKeyUtil::FromString(valueStr, val: v13) == 0 )
        return 0;
      return mgEntityValueAccess::SetValue((idLight *)entity, (tlKeyId_t)key, val: v13);
    default:
      if ( Type != TL_KEYTYPE_BOOL )
      {
        if ( (unsigned __int8)mgTimelineKeyUtil::FromString(valueStr, val: v14) != 0
          && key == 2
          && (v10 = idAnimCamera::CastTo(c: entity)) != nullptr )
        {
          idAnimCamera::SetDOFOverride(this: v10, val: v14);
          return 1;
        }
        else
        {
          return 0;
        }
      }
      else
      {
        if ( (unsigned __int8)mgTimelineKeyUtil::FromString(valueStr, val: &v11) == 0 || key != 0 )
          return 0;
        v7 = (idEntity_vtbl *)entity->__vftable;
        if ( v11 )
          v7->Show(this: entity);
        else
          v7->Hide_2(this: entity);
        return 1;
      }
  }
}


// ========================================================================
// ?Animate@mgEntityValueAccess@@SA_NPAVidEntity@@W4tlKeyId_t@@ABVmgTimelineKeyAnimData@@M@Z
// EA  : 0x82CEABF8
// RVA : 0x00CEABF8
// PDB : w:\tech5\tungsten\game\entities\timeline\entityvalueaccess.cpp
// ========================================================================

int __fastcall mgEntityValueAccess::Animate(
        idAnimCamera *entity,
        __int32 key,
        mgTimelineKeyAnimData *anim,
        double time)
{
  int *v8; // r4
  tlKeyType_t Type; // r3
  double v10; // fp8
  double v11; // fp7
  double v12; // fp6
  double v13; // fp5
  double v14; // fp4
  double v15; // fp3
  double v16; // fp2
  idEntity_vtbl *v17; // r11
  char Data; // r3
  idAnimCamera *v20; // r3
  _BYTE v21[4]; // [sp+50h] [-60h] BYREF
  float v22; // [sp+54h] [-5Ch] BYREF
  idVec3 v23[2]; // [sp+58h] [-58h] BYREF
  idVec4 v24; // [sp+70h] [-40h] BYREF

  Type = mgTimelineKeyUtil::GetType((tlKeyId_t)key);
  if ( (unsigned int)Type > TL_KEYTYPE_COLOR_RGBA )
    return 0;
  switch ( Type )
  {
    case TL_KEYTYPE_INT:
      mgTimelineKeyAnimData::GetData(
        this: anim,
        time,
        val: v8,
        a4: &v22,
        a5: v16,
        a6: v15,
        a7: v14,
        a8: v13,
        a9: v12,
        a10: v11,
        a11: v10);
      return 0;
    case TL_KEYTYPE_FLOAT:
      Data = mgTimelineKeyAnimData::GetData(
               this: anim,
               time,
               val: (float *)v8,
               a4: &v22,
               a5: v16,
               a6: v15,
               a7: v14,
               a8: v13,
               a9: v12,
               a10: v11,
               a11: v10);
      if ( Data == 0 )
        return 0;
      return mgEntityValueAccess::SetValue(entity, key, val: v22);
    case TL_KEYTYPE_FLOAT3:
    case TL_KEYTYPE_COLOR_RGB:
      if ( (unsigned __int8)mgTimelineKeyAnimData::GetData(
                              this: anim,
                              time,
                              val: (idVec3 *)v8,
                              a4: &v23[0].x,
                              a5: v16,
                              a6: v15,
                              a7: v14,
                              a8: v13,
                              a9: v12,
                              a10: v11,
                              a11: v10) == 0 )
        return 0;
      return mgEntityValueAccess::SetValue((idLight *)entity, (tlKeyId_t)key, val: v23);
    default:
      if ( Type != TL_KEYTYPE_BOOL )
      {
        if ( (unsigned __int8)mgTimelineKeyAnimData::GetData(
                                this: anim,
                                time,
                                val: (idVec4 *)v8,
                                a4: &v24.x,
                                a5: v16,
                                a6: v15,
                                a7: v14,
                                a8: v13,
                                a9: v12,
                                a10: v11,
                                a11: v10) != 0
          && key == 2
          && (v20 = idAnimCamera::CastTo(c: entity)) != nullptr )
        {
          idAnimCamera::SetDOFOverride(this: v20, val: &v24);
          return 1;
        }
        else
        {
          return 0;
        }
      }
      else
      {
        if ( (unsigned __int8)mgTimelineKeyAnimData::GetData(
                                this: anim,
                                time,
                                val: (bool *)v8,
                                a4: v21,
                                a5: v16,
                                a6: v15,
                                a7: v14,
                                a8: v13,
                                a9: v12,
                                a10: v11,
                                a11: v10) == 0
          || key != 0 )
        {
          return 0;
        }
        v17 = (idEntity_vtbl *)entity->__vftable;
        if ( v21[0] != 0 )
          v17->Show(this: entity);
        else
          v17->Hide_2(this: entity);
        return 1;
      }
  }
}

