
// ========================================================================
// ?IsValid@idEntityInterfaceLocal@@UBA_NXZ
// EA  : 0x82BDA710
// RVA : 0x00BDA710
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

BOOL __fastcall idEntityInterfaceLocal::IsValid(idEntityInterfaceLocal *this)
{
  const idGame *v2; // r3
  BOOL v3; // r30
  idGameLock v5[2]; // [sp+50h] [-20h] BYREF

  v2 = this->Game(this);
  idGameLock::idGameLock(this: v5, newGame: v2);
  v3 = this->GetEntity(this) != nullptr;
  idGameLock::~idGameLock(this: v5);
  return v3;
}


// ========================================================================
// __unwind$487886
// EA  : 0x82BDA788
// RVA : 0x00BDA788
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_487886()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?SetWorldOrigin@idEntityInterfaceLocal@@UAAXABVidVec3@@@Z
// EA  : 0x82BDA7B8
// RVA : 0x00BDA7B8
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::SetWorldOrigin(idEntityInterfaceLocal *this, const idVec3 *origin)
{
  const idGame *v4; // r3
  idEntity *v5; // r3
  idGameLock v6[12]; // [sp+50h] [-30h] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v6, newGame: v4);
  v5 = this->GetEntity(this);
  idEntity::SetOrigin(this: v5, org: origin);
  idGameLock::~idGameLock(this: v6);
}


// ========================================================================
// __unwind$487906
// EA  : 0x82BDA818
// RVA : 0x00BDA818
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_487906()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetWorldAxis@idEntityInterfaceLocal@@UAAXABVidMat3@@@Z
// EA  : 0x82BDA848
// RVA : 0x00BDA848
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::SetWorldAxis(idEntityInterfaceLocal *this, const idMat3 *axis)
{
  const idGame *v4; // r3
  idEntity *v5; // r3
  idGameLock v6[12]; // [sp+50h] [-30h] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v6, newGame: v4);
  v5 = this->GetEntity(this);
  v5->SetAxis(this: v5, a2: axis);
  idGameLock::~idGameLock(this: v6);
}


// ========================================================================
// __unwind$487926
// EA  : 0x82BDA8B4
// RVA : 0x00BDA8B4
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_487926()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?UpdateVisuals@idEntityInterfaceLocal@@UAAXXZ
// EA  : 0x82BDA8E8
// RVA : 0x00BDA8E8
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::UpdateVisuals(idEntityInterfaceLocal *this)
{
  const idGame *v2; // r3
  idEntity *v3; // r3
  idGameLock v4[2]; // [sp+50h] [-20h] BYREF

  v2 = this->Game(this);
  idGameLock::idGameLock(this: v4, newGame: v2);
  v3 = this->GetEntity(this);
  idEntity::UpdateVisuals(this: v3);
  idGameLock::~idGameLock(this: v4);
}


// ========================================================================
// __unwind$487944
// EA  : 0x82BDA958
// RVA : 0x00BDA958
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_487944()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?GetWorldSpaceTagTransform@idEntityInterfaceLocal@@UBA_NPBD0AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82BDA980
// RVA : 0x00BDA980
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

BOOL __fastcall idEntityInterfaceLocal::GetWorldSpaceTagTransform(
        idEntityInterfaceLocal *this,
        const char *propName,
        const char *tagName,
        idVec3 *origin,
        idMat3 *axis)
{
  idAnimatedEntity *v9; // r3
  idAnimatedEntity *v10; // r3

  v9 = (idAnimatedEntity *)this->GetEntity(this);
  v10 = idAnimatedEntity::CastTo(c: v9);
  return v10 != nullptr && idAnimatedEntity::GetTagPosition(this: v10, propName, tagName, origin, axis);
}


// ========================================================================
// ?BindToJoint@idEntityInterfaceLocal@@UAAXPAVidEntity@@V?$idIndex@FW4invalidJointIndex_t@@@@W4bindFlags_t@@@Z
// EA  : 0x82BDA9E8
// RVA : 0x00BDA9E8
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::BindToJoint(
        idEntityInterfaceLocal *this,
        idEntity *master,
        idIndex<short,enum invalidJointIndex_t> *jointnum,
        const bindFlags_t bindFlags)
{
  char v7; // r27
  const idGame *v8; // r3
  idEntity *v9; // r3
  idGameLock v10[16]; // [sp+50h] [-40h] BYREF

  v7 = bindFlags;
  v8 = this->Game(this);
  idGameLock::idGameLock(this: v10, newGame: v8);
  v9 = this->GetEntity(this);
  idEntity::BindToJoint(this: v9, master, jointnum, orientated: v7 & 1);
  idGameLock::~idGameLock(this: v10);
}


// ========================================================================
// __unwind$487969
// EA  : 0x82BDAA5C
// RVA : 0x00BDAA5C
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_487969()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 144 + 80));
}


// ========================================================================
// ?Unbind@idEntityInterfaceLocal@@UAAXXZ
// EA  : 0x82BDAA90
// RVA : 0x00BDAA90
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::Unbind(idEntityInterfaceLocal *this)
{
  const idGame *v2; // r3
  idEntity *v3; // r3
  idGameLock v4[2]; // [sp+50h] [-20h] BYREF

  v2 = this->Game(this);
  idGameLock::idGameLock(this: v4, newGame: v2);
  v3 = this->GetEntity(this);
  idEntity::Unbind(this: v3);
  idGameLock::~idGameLock(this: v4);
}


// ========================================================================
// __unwind$487989
// EA  : 0x82BDAB00
// RVA : 0x00BDAB00
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_487989()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?DetachRenderModel@idEntityInterfaceLocal@@UAA_NABV?$idHandle@HW4invalidAttachment_t@@$0?0@@@Z
// EA  : 0x82BDAB30
// RVA : 0x00BDAB30
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

int __fastcall idEntityInterfaceLocal::DetachRenderModel(
        idEntityInterfaceLocal *this,
        const idHandle<int,enum invalidAttachment_t,-1> *handle)
{
  const idGame *v4; // r3
  idEntity *v5; // r3
  idAttachmentCollection *v7; // r3
  idGameLock v8[12]; // [sp+50h] [-30h] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v8, newGame: v4);
  v5 = this->GetEntity(this);
  if ( v5 != nullptr && (v7 = v5->GetAttachments_2(this: v5)) != nullptr )
  {
    idAttachmentCollection::RemoveAttachment(this: v7, handle);
    idGameLock::~idGameLock(this: v8);
    return 1;
  }
  else
  {
    idGameLock::~idGameLock(this: v8);
    return 0;
  }
}


// ========================================================================
// __unwind$488009
// EA  : 0x82BDABD4
// RVA : 0x00BDABD4
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488009()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?RebindAttachment@idEntityInterfaceLocal@@UAA_NABV?$idHandle@HW4invalidAttachment_t@@$0?0@@ABUtagData_t@@@Z
// EA  : 0x82BDAC08
// RVA : 0x00BDAC08
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

BOOL __fastcall idEntityInterfaceLocal::RebindAttachment(
        idEntityInterfaceLocal *this,
        const idHandle<int,enum invalidAttachment_t,-1> *handle,
        const tagData_t *tagData)
{
  const idGame *v6; // r3
  idEntity *v7; // r3
  idAttachmentCollection *v9; // r3
  BOOL v10; // r30
  idGameLock v11[12]; // [sp+50h] [-30h] BYREF

  v6 = this->Game(this);
  idGameLock::idGameLock(this: v11, newGame: v6);
  v7 = this->GetEntity(this);
  if ( v7 != nullptr && (v9 = v7->GetAttachments_2(this: v7)) != nullptr )
  {
    v10 = idAttachmentCollection::RebindAttachment(this: v9, handle, tagData);
    idGameLock::~idGameLock(this: v11);
    return v10;
  }
  else
  {
    idGameLock::~idGameLock(this: v11);
    return false;
  }
}


// ========================================================================
// __unwind$488034
// EA  : 0x82BDACB8
// RVA : 0x00BDACB8
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488034()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetModel@idEntityInterfaceLocal@@UAAXPBD@Z
// EA  : 0x82BDACE8
// RVA : 0x00BDACE8
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::SetModel(idEntityInterfaceLocal *this, const char *model)
{
  const idGame *v4; // r3
  idEntity *v5; // r3
  idGameLock v6[12]; // [sp+50h] [-30h] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v6, newGame: v4);
  v5 = this->GetEntity(this);
  v5->SetModelByName(this: v5, a2: model);
  idGameLock::~idGameLock(this: v6);
}


// ========================================================================
// __unwind$488063
// EA  : 0x82BDAD54
// RVA : 0x00BDAD54
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488063()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetModel@idEntityInterfaceLocal@@UAAXPAVidRenderModel@@@Z
// EA  : 0x82BDAD88
// RVA : 0x00BDAD88
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::SetModel(idEntityInterfaceLocal *this, idRenderModel *model)
{
  const idGame *v4; // r3
  idEntity *v5; // r3
  idGameLock v6[12]; // [sp+50h] [-30h] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v6, newGame: v4);
  v5 = this->GetEntity(this);
  v5->SetModel(this: v5, a2: model);
  idGameLock::~idGameLock(this: v6);
}


// ========================================================================
// __unwind$488081
// EA  : 0x82BDADF4
// RVA : 0x00BDADF4
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488081()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?StopSound@idEntityInterfaceLocal@@UAAXXZ
// EA  : 0x82BDAE28
// RVA : 0x00BDAE28
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::StopSound(idEntityInterfaceLocal *this)
{
  const idGame *v2; // r3
  idEntity *v3; // r3
  idGameLock v4[2]; // [sp+50h] [-20h] BYREF

  v2 = this->Game(this);
  idGameLock::idGameLock(this: v4, newGame: v2);
  v3 = this->GetEntity(this);
  idEntity::StopSound(this: v3, channel: SND_CHANNEL_ANY, peerMask: 0xFFu);
  idGameLock::~idGameLock(this: v4);
}


// ========================================================================
// __unwind$488099_0
// EA  : 0x82BDAEA0
// RVA : 0x00BDAEA0
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488099_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?SetColor@idEntityInterfaceLocal@@UAAXABVidColor@@@Z
// EA  : 0x82BDAED0
// RVA : 0x00BDAED0
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::SetColor(idEntityInterfaceLocal *this, const idColor *color)
{
  const idGame *v4; // r3
  idEntity *v5; // r3
  idGameLock v6[12]; // [sp+50h] [-30h] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v6, newGame: v4);
  v5 = this->GetEntity(this);
  v5->SetColor_2(this: v5, a2: color);
  idGameLock::~idGameLock(this: v6);
}


// ========================================================================
// __unwind$488116_0
// EA  : 0x82BDAF3C
// RVA : 0x00BDAF3C
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488116_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetRenderEntity@idEntityInterfaceLocal@@UAAPAVidRenderModel@@XZ
// EA  : 0x82BDAF70
// RVA : 0x00BDAF70
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

idRenderModel *__fastcall idEntityInterfaceLocal::GetRenderEntity(idEntityInterfaceLocal *this)
{
  const idGame *v2; // r3
  idEntity *v3; // r3
  idRenderModel *RenderModelFromPresentable; // r30
  idGameLock v6[2]; // [sp+50h] [-20h] BYREF

  v2 = this->Game(this);
  idGameLock::idGameLock(this: v6, newGame: v2);
  v3 = this->GetEntity(this);
  RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: v3);
  idGameLock::~idGameLock(this: v6);
  return RenderModelFromPresentable;
}


// ========================================================================
// __unwind$488135
// EA  : 0x82BDAFE8
// RVA : 0x00BDAFE8
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488135()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?DeleteEntity@idEntityInterfaceLocal@@UAAXXZ
// EA  : 0x82BDB018
// RVA : 0x00BDB018
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::DeleteEntity(idEntityInterfaceLocal *this)
{
  const idGame *v2; // r3
  idEntity *v3; // r3
  idGameLock v4[2]; // [sp+50h] [-20h] BYREF

  v2 = this->Game(this);
  idGameLock::idGameLock(this: v4, newGame: v2);
  v3 = this->GetEntity(this);
  gameLocal->DeleteEntity(this: gameLocal, a2: v3);
  idGameLock::~idGameLock(this: v4);
}


// ========================================================================
// __unwind$488152
// EA  : 0x82BDB0A0
// RVA : 0x00BDB0A0
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488152()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?GetEntity@idEntityInterfaceLocal@@UBAPAVidEntity@@XZ
// EA  : 0x82BDB0C8
// RVA : 0x00BDB0C8
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

idEntity *__fastcall idEntityInterfaceLocal::GetEntity(idEntityInterfaceLocal *this)
{
  const idGame *v2; // r3
  idEntity *entityPtr; // r31
  idGameLock v5[4]; // [sp+50h] [-20h] BYREF

  v2 = this->Game(this);
  idGameLock::idGameLock(this: v5, newGame: v2);
  entityPtr = this->entityPtr;
  idGameLock::~idGameLock(this: v5);
  return entityPtr;
}


// ========================================================================
// ?GetPhysics@idEntityInterfaceLocal@@IBAPAVidPhysics@@XZ
// EA  : 0x82BDB128
// RVA : 0x00BDB128
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

idPhysics *__fastcall idEntityInterfaceLocal::GetPhysics(idEntityInterfaceLocal *this)
{
  const idGame *v2; // r3
  idEntity *v3; // r3
  idPhysics *Physics; // r30
  idGameLock v6[2]; // [sp+50h] [-20h] BYREF

  v2 = this->Game(this);
  idGameLock::idGameLock(this: v6, newGame: v2);
  v3 = this->GetEntity(this);
  Physics = idEntity::GetPhysics(this: v3);
  idGameLock::~idGameLock(this: v6);
  return Physics;
}


// ========================================================================
// __unwind$488178_0
// EA  : 0x82BDB1A0
// RVA : 0x00BDB1A0
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488178_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?GetLightSpotlight@idEntityInterfaceLocal@@UBA_NXZ
// EA  : 0x82BDB1C8
// RVA : 0x00BDB1C8
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

int __fastcall idEntityInterfaceLocal::GetLightSpotlight(idEntityInterfaceLocal *this)
{
  const idGame *v1; // r3
  idGameLock v3[2]; // [sp+50h] [-10h] BYREF

  v1 = this->Game(this);
  idGameLock::idGameLock(this: v3, newGame: v1);
  idGameLock::~idGameLock(this: v3);
  return 0;
}


// ========================================================================
// ?GetAnimTime@idEntityInterfaceLocal@@UBAMXZ
// EA  : 0x82BDB210
// RVA : 0x00BDB210
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

float __fastcall idEntityInterfaceLocal::GetAnimTime(idEntityInterfaceLocal *this)
{
  const idGame *v1; // r3
  double v2; // fp1
  idGameLock v4[2]; // [sp+50h] [-10h] BYREF

  v1 = this->Game(this);
  idGameLock::idGameLock(this: v4, newGame: v1);
  idGameLock::~idGameLock(this: v4);
  v2 = 0.0;
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?GetCastShadows@idEntityInterfaceLocal@@UBA_NXZ
// EA  : 0x82BDB258
// RVA : 0x00BDB258
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

int __fastcall idEntityInterfaceLocal::GetCastShadows(idEntityInterfaceLocal *this)
{
  const idGame *v1; // r3
  idGameLock v3[2]; // [sp+50h] [-10h] BYREF

  v1 = this->Game(this);
  idGameLock::idGameLock(this: v3, newGame: v1);
  idGameLock::~idGameLock(this: v3);
  return 1;
}


// ========================================================================
// ?SetRemoveOriginRotation@idEntityInterfaceLocal@@UAAX_N@Z
// EA  : 0x82BDB2A0
// RVA : 0x00BDB2A0
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::SetRemoveOriginRotation(idEntityInterfaceLocal *this, lightClass_t lightClass)
{
  const idGame *v2; // r3
  idGameLock v3[2]; // [sp+50h] [-10h] BYREF

  v2 = (const idGame *)((int (__fastcall *)(idEntityInterfaceLocal *, lightClass_t))this->Game)(
                         a1: this,
                         a2: lightClass);
  idGameLock::idGameLock(this: v3, newGame: v2);
  idGameLock::~idGameLock(this: v3);
}


// ========================================================================
// ?RespondsToEvent@idEntityInterfaceLocal@@UAA_NABVidEventDef@@@Z
// EA  : 0x82BDB2E8
// RVA : 0x00BDB2E8
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

int __fastcall idEntityInterfaceLocal::RespondsToEvent(idEntityInterfaceLocal *this, const idEventDef *event)
{
  const idGame *v4; // r3
  idEntity *v5; // r3
  int v6; // r30
  idGameLock v8[12]; // [sp+50h] [-30h] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v8, newGame: v4);
  v5 = this->GetEntity(this);
  v6 = ((int (__fastcall *)(idEntity *, const idEventDef *))v5->RespondsTo)(a1: v5, a2: event);
  idGameLock::~idGameLock(this: v8);
  return v6;
}


// ========================================================================
// __unwind$488405
// EA  : 0x82BDB35C
// RVA : 0x00BDB35C
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488405()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetWorldOrigin@idEntityInterfaceLocal@@UBAXAAVidVec3@@@Z
// EA  : 0x82BDB3F8
// RVA : 0x00BDB3F8
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::GetWorldOrigin(idEntityInterfaceLocal *this, idVec3 *origin)
{
  const idGame *v4; // r3
  idPhysics *Physics; // r3
  idGameLock v6[12]; // [sp+50h] [-30h] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v6, newGame: v4);
  Physics = idEntityInterfaceLocal::GetPhysics(this);
  *origin = *Physics->GetOrigin(this: Physics, a2: 0);
  idGameLock::~idGameLock(this: v6);
}


// ========================================================================
// __unwind$488702
// EA  : 0x82BDB470
// RVA : 0x00BDB470
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488702()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?TranslateWorld@idEntityInterfaceLocal@@UAAXABVidVec3@@@Z
// EA  : 0x82BDB4A0
// RVA : 0x00BDB4A0
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::TranslateWorld(idEntityInterfaceLocal *this, const idVec3 *translation)
{
  const idGame *v4; // r3
  idPhysics *Physics; // r3
  idGameLock v6[12]; // [sp+50h] [-30h] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v6, newGame: v4);
  Physics = idEntityInterfaceLocal::GetPhysics(this);
  Physics->Translate(this: Physics, a2: translation, a3: -1);
  idGameLock::~idGameLock(this: v6);
}


// ========================================================================
// __unwind$488724_0
// EA  : 0x82BDB504
// RVA : 0x00BDB504
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488724_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetWorldAxis@idEntityInterfaceLocal@@UBAXAAVidMat3@@@Z
// EA  : 0x82BDB538
// RVA : 0x00BDB538
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::GetWorldAxis(idEntityInterfaceLocal *this, idMat3 *axis)
{
  const idGame *v4; // r3
  idPhysics *Physics; // r3
  idGameLock v6[11]; // [sp+54h] [-2Ch] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v6, newGame: v4);
  Physics = idEntityInterfaceLocal::GetPhysics(this);
  *axis = *Physics->GetAxis(this: Physics, a2: 0);
  idGameLock::~idGameLock(this: v6);
}


// ========================================================================
// __unwind$488742
// EA  : 0x82BDB600
// RVA : 0x00BDB600
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488742()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 84));
}


// ========================================================================
// ?AttachRenderModel@idEntityInterfaceLocal@@UAA?AV?$idHandle@HW4invalidAttachment_t@@$0?0@@PBD00@Z
// EA  : 0x82BDB630
// RVA : 0x00BDB630
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

idEntityInterfaceLocal *__fastcall idEntityInterfaceLocal::AttachRenderModel(
        idEntityInterfaceLocal *this,
        idHandle<int,enum invalidAttachment_t,-1> *result,
        const char *modelName,
        const char *propName,
        const char *tagName)
{
  const idGame *v10; // r3
  int v11; // r3
  idHandle<int,enum invalidAttachment_t,-1> *v12; // r4
  idGameLock v14; // [sp+50h] [-40h] BYREF
  idAttachmentCollection v15[3]; // [sp+54h] [-3Ch] BYREF

  v10 = (const idGame *)(*(int (__fastcall **)(idHandle<int,enum invalidAttachment_t,-1> *))(result->value + 8))(a1: result);
  idGameLock::idGameLock(this: &v14, newGame: v10);
  v11 = (*(int (__fastcall **)(idHandle<int,enum invalidAttachment_t,-1> *))(result->value + 212))(a1: result);
  if ( v11 != 0 )
  {
    v12 = (idHandle<int,enum invalidAttachment_t,-1> *)(*(int (__fastcall **)(int))(*(_DWORD *)v11 + 484))(a1: v11);
    if ( v12 != nullptr )
    {
      idAttachmentCollection::AddAttachment(
        this: v15,
        result: v12,
        modelName,
        propName,
        tag: tagName,
        tagInfo: nullptr,
        allowDuplicate: true);
      this->__vftable = (idEntityInterfaceLocal_vtbl *)v15[0].attachments.list;
    }
    else
    {
      this->__vftable = (idEntityInterfaceLocal_vtbl *)-1;
    }
  }
  else
  {
    this->__vftable = (idEntityInterfaceLocal_vtbl *)-1;
  }
  idGameLock::~idGameLock(this: &v14);
  return this;
}


// ========================================================================
// __unwind$488781
// EA  : 0x82BDB6FC
// RVA : 0x00BDB6FC
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488781()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 144 + 80));
}


// ========================================================================
// ?GetAttachment@idEntityInterfaceLocal@@UAAPAVidRenderModel@@ABV?$idHandle@HW4invalidAttachment_t@@$0?0@@@Z
// EA  : 0x82BDB730
// RVA : 0x00BDB730
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

const idGame *__fastcall idEntityInterfaceLocal::GetAttachment(
        idEntityInterfaceLocal *this,
        const idHandle<int,enum invalidAttachment_t,-1> *handle)
{
  const idGame *v4; // r3
  idEntity *v5; // r3
  idAttachmentCollection *v7; // r3
  const idAttachment *v8; // r3
  const idGame *model; // r30
  idGameLock v10[12]; // [sp+50h] [-30h] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v10, newGame: v4);
  v5 = this->GetEntity(this);
  if ( v5 != nullptr && (v7 = v5->GetAttachments_2(this: v5)) != nullptr )
  {
    v8 = idAttachmentCollection::Get(this: v7, handle);
    if ( v8 != nullptr && v8->presentable != nullptr )
      model = (const idGame *)v8->presentable->model;
    else
      model = nullptr;
    v10[1].prevGame = model;
    idGameLock::~idGameLock(this: v10);
    return model;
  }
  else
  {
    idGameLock::~idGameLock(this: v10);
    return nullptr;
  }
}


// ========================================================================
// __unwind$488817_0
// EA  : 0x82BDB7F8
// RVA : 0x00BDB7F8
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488817_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetLocalOrigin@idEntityInterfaceLocal@@UBAXAAVidVec3@@@Z
// EA  : 0x82BDB828
// RVA : 0x00BDB828
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::GetLocalOrigin(idEntityInterfaceLocal *this, idVec3 *origin)
{
  const idGame *v4; // r3
  idEntity *v5; // r3
  idEntity *v6; // r3
  idEntity *v7; // r3
  idPhysics *Physics; // r3
  float *v9; // r3
  double v10; // fp31
  double v11; // fp30
  double v12; // fp29
  float *v13; // r3
  double v14; // fp12
  double v15; // fp11
  double v16; // fp9
  double v17; // fp8
  idPhysics *v18; // r3
  float *v19; // r3
  idGameLock v20[2]; // [sp+50h] [-B0h] BYREF
  idVec3 v21; // [sp+58h] [-A8h] BYREF
  idMat3 v22; // [sp+70h] [-90h] BYREF
  idMat3 v23; // [sp+A0h] [-60h] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v20, newGame: v4);
  v5 = this->GetEntity(this);
  if ( idEntity::IsBound(this: v5) && (v6 = this->GetEntity(this), idEntity::IsBoundOriented(this: v6)) )
  {
    v7 = this->GetEntity(this);
    idEntity::GetMasterPosition(this: v7, masterOrigin: &v21, masterAxis: &v22);
    Physics = idEntityInterfaceLocal::GetPhysics(this);
    v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v10 = (float)(v9[2] - v21.z);
    v11 = (float)(v9[1] - v21.y);
    v12 = (float)(*v9 - v21.x);
    v13 = (float *)idMat3::Inverse(this: &v23, result: &v22);
    v14 = v13[7];
    v15 = *v13;
    v16 = (float)((float)(v13[1] * (float)v12) + (float)(v13[4] * (float)v11));
    v17 = (float)((float)(v13[3] * (float)v11) + (float)(v13[6] * (float)v10));
    origin->z = (float)(v13[8] * (float)v10) + (float)((float)(v13[2] * (float)v12) + (float)(v13[5] * (float)v11));
    origin->y = (float)((float)v14 * (float)v10) + (float)v16;
    origin->x = (float)((float)v15 * (float)v12) + (float)v17;
  }
  else
  {
    v18 = idEntityInterfaceLocal::GetPhysics(this);
    v19 = (float *)v18->GetOrigin(this: v18, a2: 0);
    origin->x = *v19;
    origin->y = v19[1];
    origin->z = v19[2];
  }
  idGameLock::~idGameLock(this: v20);
}


// ========================================================================
// __unwind$488846_0
// EA  : 0x82BDB9C8
// RVA : 0x00BDB9C8
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488846_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 256 + 80));
}


// ========================================================================
// ?SetLocalOrigin@idEntityInterfaceLocal@@UAAXABVidVec3@@@Z
// EA  : 0x82BDB9F8
// RVA : 0x00BDB9F8
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::SetLocalOrigin(idEntityInterfaceLocal *this, const idVec3 *origin)
{
  const idGame *v4; // r3
  idPhysics *Physics; // r3
  idGameLock v6[12]; // [sp+50h] [-30h] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v6, newGame: v4);
  Physics = idEntityInterfaceLocal::GetPhysics(this);
  Physics->SetLocalOrigin(this: Physics, a2: origin, a3: -1);
  idGameLock::~idGameLock(this: v6);
}


// ========================================================================
// __unwind$488905
// EA  : 0x82BDBA5C
// RVA : 0x00BDBA5C
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488905()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetLocalAxis@idEntityInterfaceLocal@@UBAXAAVidMat3@@@Z
// EA  : 0x82BDBA90
// RVA : 0x00BDBA90
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::GetLocalAxis(idEntityInterfaceLocal *this, idMat3 *axis)
{
  const idGame *v4; // r3
  idEntity *v5; // r3
  idEntity *v6; // r3
  idEntity *v7; // r3
  idPhysics *Physics; // r29
  const idMat3 *v9; // r28
  idMat3 *v10; // r3
  float *v11; // r3
  idPhysics *v12; // r3
  idGameLock v13; // [sp+54h] [-CCh] BYREF
  idVec3 v14[2]; // [sp+58h] [-C8h] BYREF
  idMat3 v15; // [sp+70h] [-B0h] BYREF
  idMat3 v16; // [sp+A0h] [-80h] BYREF
  idMat3 v17[2]; // [sp+D0h] [-50h] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: &v13, newGame: v4);
  v5 = this->GetEntity(this);
  if ( idEntity::IsBound(this: v5) && (v6 = this->GetEntity(this), idEntity::IsBoundOriented(this: v6)) )
  {
    v7 = this->GetEntity(this);
    idEntity::GetMasterPosition(this: v7, masterOrigin: v14, masterAxis: &v15);
    Physics = idEntityInterfaceLocal::GetPhysics(this);
    v9 = idMat3::Inverse(this: &v16, result: &v15);
    v10 = (idMat3 *)Physics->GetAxis(this: Physics, a2: 0);
    v11 = (float *)idMat3::operator*(this: v17, result: v10, a: v9);
  }
  else
  {
    v12 = idEntityInterfaceLocal::GetPhysics(this);
    v11 = (float *)v12->GetAxis(this: v12, a2: 0);
  }
  axis->mat[0].x = *v11;
  axis->mat[0].y = v11[1];
  axis->mat[0].z = v11[2];
  axis->mat[1].x = v11[3];
  axis->mat[1].y = v11[4];
  axis->mat[1].z = v11[5];
  axis->mat[2].x = v11[6];
  axis->mat[2].y = v11[7];
  axis->mat[2].z = v11[8];
  idGameLock::~idGameLock(this: &v13);
}


// ========================================================================
// __unwind$488925
// EA  : 0x82BDBC28
// RVA : 0x00BDBC28
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488925()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 288 + 84));
}


// ========================================================================
// ?SetLocalAxis@idEntityInterfaceLocal@@UAAXABVidMat3@@@Z
// EA  : 0x82BDBC58
// RVA : 0x00BDBC58
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::SetLocalAxis(idEntityInterfaceLocal *this, const idMat3 *axis)
{
  const idGame *v4; // r3
  idPhysics *Physics; // r3
  idGameLock v6[12]; // [sp+50h] [-30h] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v6, newGame: v4);
  Physics = idEntityInterfaceLocal::GetPhysics(this);
  Physics->SetLocalAxis(this: Physics, a2: axis, a3: -1);
  idGameLock::~idGameLock(this: v6);
}


// ========================================================================
// __unwind$488989
// EA  : 0x82BDBCBC
// RVA : 0x00BDBCBC
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_488989()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetSpawnPosition@idEntityInterfaceLocal@@UBAXAAVidVec3@@@Z
// EA  : 0x82BDBCF0
// RVA : 0x00BDBCF0
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::GetSpawnPosition(idEntityInterfaceLocal *this, idVec3 *pos)
{
  const idGame *v4; // r3
  idEntity *v5; // r3
  double y; // fp13
  idGameLock v7[12]; // [sp+50h] [-30h] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v7, newGame: v4);
  v5 = this->GetEntity(this);
  pos->x = v5->spawnPosition.x;
  y = v5->spawnPosition.y;
  v7[1].prevGame = (const idGame *)&v5->spawnPosition;
  pos->y = y;
  pos->z = v5->spawnPosition.z;
  idGameLock::~idGameLock(this: v7);
}


// ========================================================================
// __unwind$489007
// EA  : 0x82BDBD68
// RVA : 0x00BDBD68
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_489007()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetSpawnPosition@idEntityInterfaceLocal@@UAAXABVidVec3@@@Z
// EA  : 0x82BDBD98
// RVA : 0x00BDBD98
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::SetSpawnPosition(idEntityInterfaceLocal *this, const idVec3 *pos)
{
  const idGame *v4; // r3
  idEntity *v5; // r3
  double y; // fp13
  idGameLock v7[12]; // [sp+50h] [-30h] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v7, newGame: v4);
  v5 = this->GetEntity(this);
  v5->spawnPosition.x = pos->x;
  y = pos->y;
  v7[1].prevGame = (const idGame *)&v5->spawnPosition;
  v5->spawnPosition.y = y;
  v5->spawnPosition.z = pos->z;
  idGameLock::~idGameLock(this: v7);
}


// ========================================================================
// __unwind$489033
// EA  : 0x82BDBE10
// RVA : 0x00BDBE10
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_489033()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetSpawnOrientation@idEntityInterfaceLocal@@UBAXAAVidMat3@@@Z
// EA  : 0x82BDBE40
// RVA : 0x00BDBE40
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::GetSpawnOrientation(idEntityInterfaceLocal *this, idMat3 *axis)
{
  const idGame *v4; // r3
  idGameLock v5[11]; // [sp+54h] [-2Ch] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v5, newGame: v4);
  *axis = this->GetEntity(this)->spawnOrientation;
  idGameLock::~idGameLock(this: v5);
}


// ========================================================================
// __unwind$489061
// EA  : 0x82BDBF08
// RVA : 0x00BDBF08
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_489061()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 84));
}


// ========================================================================
// ?SetSpawnOrientation@idEntityInterfaceLocal@@UAAXABVidMat3@@@Z
// EA  : 0x82BDBF38
// RVA : 0x00BDBF38
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::SetSpawnOrientation(idEntityInterfaceLocal *this, const idMat3 *axis)
{
  const idGame *v4; // r3
  idGameLock v5[11]; // [sp+54h] [-2Ch] BYREF

  v4 = this->Game(this);
  idGameLock::idGameLock(this: v5, newGame: v4);
  this->GetEntity(this)->spawnOrientation = *axis;
  idGameLock::~idGameLock(this: v5);
}


// ========================================================================
// __unwind$489103
// EA  : 0x82BDBFFC
// RVA : 0x00BDBFFC
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_489103()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 84));
}


// ========================================================================
// ?GetViewAngles@idEntityInterfaceLocal@@UBAXAAVidAngles@@@Z
// EA  : 0x82BDC028
// RVA : 0x00BDC028
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::GetViewAngles(idEntityInterfaceLocal *this, idAngles *angles)
{
  const idGame *v3; // r3
  idGameLock v4[4]; // [sp+50h] [-20h] BYREF

  v3 = this->Game(this);
  idGameLock::idGameLock(this: v4, newGame: v3);
  angles->pitch = 0.0;
  angles->yaw = 0.0;
  angles->roll = 0.0;
  idGameLock::~idGameLock(this: v4);
}


// ========================================================================
// ?GetEntityName@idEntityInterfaceLocal@@UBAPBDXZ
// EA  : 0x82BDC090
// RVA : 0x00BDC090
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

char *__fastcall idEntityInterfaceLocal::GetEntityName(idEntityInterfaceLocal *this)
{
  const idGame *v2; // r3
  char *data; // r30
  idGameLock v5[2]; // [sp+50h] [-20h] BYREF

  v2 = this->Game(this);
  idGameLock::idGameLock(this: v5, newGame: v2);
  data = this->GetEntity(this)->name.data;
  idGameLock::~idGameLock(this: v5);
  return data;
}


// ========================================================================
// __unwind$489165_0
// EA  : 0x82BDC104
// RVA : 0x00BDC104
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_489165_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?GetEntityDef@idEntityInterfaceLocal@@UBAPBVidDeclEntityDef@@XZ
// EA  : 0x82BDC130
// RVA : 0x00BDC130
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

const idDeclEntityDef *__fastcall idEntityInterfaceLocal::GetEntityDef(idEntityInterfaceLocal *this)
{
  return this->GetEntity(this)->entityDef;
}


// ========================================================================
// ??0idEntityInterfaceLocal@@QAA@PAVidGame@@PAVidEntity@@@Z
// EA  : 0x82BDC168
// RVA : 0x00BDC168
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

idEntityInterfaceLocal *__fastcall idEntityInterfaceLocal::idEntityInterfaceLocal(
        idEntityInterfaceLocal *this,
        idGame *game,
        idEntity *ent)
{
  idTypeInfoObject *v6; // r27
  const idTypeInfoTools *v7; // r29
  const char *Classname; // r3
  idTypeInfoObject *v9; // r3

  this->game = game;
  this->entityPtr = ent;
  this->refCount = 0;
  this->__vftable = (idEntityInterfaceLocal_vtbl *)&idEntityInterfaceLocal::`vftable';
  v6 = (idTypeInfoObject *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                             size: 0x2Cu,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v6 != nullptr )
  {
    v7 = game->GetTypeInfoTools(this: game);
    Classname = idClass::GetClassname(this: ent);
    v9 = idTypeInfoObject::idTypeInfoObject(this: v6, objectPtr: ent, objectType: Classname, ti: v7);
  }
  else
  {
    v9 = nullptr;
  }
  this->typeInfoObject = v9;
  return this;
}


// ========================================================================
// __unwind$489273
// EA  : 0x82BDC228
// RVA : 0x00BDC228
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_489273()
{
  int v0; // r12

  idEntityInterface::~idEntityInterface(this: *(idEntityInterface **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$489274
// EA  : 0x82BDC250
// RVA : 0x00BDC250
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall _unwind_489274(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ??1idEntityInterfaceLocal@@UAA@XZ
// EA  : 0x82BDC280
// RVA : 0x00BDC280
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void __fastcall idEntityInterfaceLocal::~idEntityInterfaceLocal(idEntityInterfaceLocal *this)
{
  idTypeInfoObject *typeInfoObject; // r29

  this->__vftable = (idEntityInterfaceLocal_vtbl *)&idEntityInterfaceLocal::`vftable';
  typeInfoObject = this->typeInfoObject;
  if ( typeInfoObject != nullptr )
  {
    idStr::FreeData(this: &typeInfoObject->objectType);
    idMem::Free(this: &mem, ptr: typeInfoObject, align: ALIGN_16);
  }
  this->__vftable = (idEntityInterfaceLocal_vtbl *)&idEntityInterface::`vftable';
}


// ========================================================================
// __unwind$489329_0
// EA  : 0x82BDC2E0
// RVA : 0x00BDC2E0
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_489329_0()
{
  int v0; // r12

  idEntityInterface::~idEntityInterface(this: *(idEntityInterface **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetNumAttachments@idEntityInterfaceLocal@@UBAHXZ
// EA  : 0x82BDC310
// RVA : 0x00BDC310
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

int __fastcall idEntityInterfaceLocal::GetNumAttachments(idEntityInterfaceLocal *this)
{
  const idGame *v2; // r3
  idEntity *v3; // r3
  int v5; // r3
  int v6; // r30
  idGameLock v7[2]; // [sp+50h] [-20h] BYREF

  v2 = this->Game(this);
  idGameLock::idGameLock(this: v7, newGame: v2);
  v3 = this->GetEntity(this);
  if ( v3 != nullptr && (v5 = (int)v3->GetAttachments_2(this: v3)) != 0 )
  {
    v6 = *(_DWORD *)(v5 + 4);
    idGameLock::~idGameLock(this: v7);
    return v6;
  }
  else
  {
    idGameLock::~idGameLock(this: v7);
    return 0;
  }
}


// ========================================================================
// __unwind$489373_0
// EA  : 0x82BDC3C4
// RVA : 0x00BDC3C4
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_489373_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?OnCustomFunctionCall@idEntityInterfaceLocal@@UAA_NXZ
// EA  : 0x82BDC458
// RVA : 0x00BDC458
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

int __fastcall idEntityInterfaceLocal::OnCustomFunctionCall(idEntityInterfaceLocal *this)
{
  const idGame *v2; // r3
  idAI2 *v3; // r3
  int v4; // r10
  int v5; // r9
  idAI2 *v6; // r3
  idList<idScriptAction,5> *p_actionScript; // r30
  int v9; // [sp+8h] [-68h]
  int v10; // [sp+Ch] [-64h]
  int v11; // [sp+10h] [-60h]
  idGameLock v12[2]; // [sp+50h] [-20h] BYREF

  v2 = this->Game(this);
  idGameLock::idGameLock(this: v12, newGame: v2);
  v3 = (idAI2 *)this->GetEntity(this);
  v6 = idAI2::CastTo(c: v3);
  if ( v6 != nullptr && v6->aiEditable.spawnSettings.actionScript.num != 0 )
  {
    p_actionScript = &v6->aiEditable.spawnSettings.actionScript;
    idComponentActionScript::SetActionScript(
      this: &v6->actionScript,
      entity: v6,
      script: &v6->aiEditable.spawnSettings.actionScript,
      scriptExecutor: v6,
      activator: nullptr,
      tool: true,
      a7: v5,
      a8: v4,
      a9: v9,
      a10: v10,
      a11: v11);
    idList<idScriptAction,5>::Clear(this: p_actionScript);
    idGameLock::~idGameLock(this: v12);
    return 1;
  }
  else
  {
    idGameLock::~idGameLock(this: v12);
    return 0;
  }
}


// ========================================================================
// __unwind$489699
// EA  : 0x82BDC524
// RVA : 0x00BDC524
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.cpp
// ========================================================================

void _unwind_489699()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}

