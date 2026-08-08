
// ========================================================================
// ?SetAliasHandle@idMD6AnimProps@@QAAXV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@@Z
// EA  : 0x825F89D0
// RVA : 0x005F89D0
// PDB : w:\tech5\engine\decls\animwebs\animprops.cpp
// ========================================================================

void __fastcall idMD6AnimProps::SetAliasHandle(
        idMD6AnimProps *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *handle)
{
  this->aliasHandle.value = (unsigned __int16)handle;
  this->anim = nullptr;
}


// ========================================================================
// ?SetAnim@idMD6AnimProps@@QAAXPBVidMD6Anim@@@Z
// EA  : 0x825F89E0
// RVA : 0x005F89E0
// PDB : w:\tech5\engine\decls\animwebs\animprops.cpp
// ========================================================================

void __fastcall idMD6AnimProps::SetAnim(idMD6AnimProps *this, const idMD6Anim *anim_)
{
  this->anim = anim_;
  this->aliasHandle.value = -1;
}


// ========================================================================
// ?SelectAnim@idMD6AnimProps@@QBAPBVidMD6Anim@@PBVidDeclMD6@@H@Z
// EA  : 0x825F89F0
// RVA : 0x005F89F0
// PDB : w:\tech5\engine\decls\animwebs\animprops.cpp
// ========================================================================

const idMD6Anim *__fastcall idMD6AnimProps::SelectAnim(idMD6AnimProps *this, const idDeclMD6 *declMD6, const int index)
{
  const idMD6Alias *Alias; // r3

  if ( this->anim != nullptr )
    return this->anim;
  if ( this->aliasHandle.value == 0xFFFF )
    return nullptr;
  Alias = idDeclMD6::FindAlias(this: declMD6, aliasHandle: &this->aliasHandle, includeInherited: true);
  if ( Alias == nullptr )
    return nullptr;
  return (const idMD6Anim *)idResourceList::FindExisting(
                              this: &idMD6Anim::resourceList,
                              name: Alias->animRefs.list[index].str,
                              skipStaleCheck: true);
}


// ========================================================================
// ?SelectAndLoadAnim@idMD6AnimProps@@QBAPBVidMD6Anim@@PBVidDeclMD6@@H@Z
// EA  : 0x825F8A98
// RVA : 0x005F8A98
// PDB : w:\tech5\engine\decls\animwebs\animprops.cpp
// ========================================================================

const idMD6Anim *__fastcall idMD6AnimProps::SelectAndLoadAnim(
        idMD6AnimProps *this,
        const idDeclMD6 *declMD6,
        const int index)
{
  const idMD6Alias *Alias; // r3

  if ( this->anim != nullptr )
    return this->anim;
  if ( this->aliasHandle.value == 0xFFFF )
    return nullptr;
  Alias = idDeclMD6::FindAlias(this: declMD6, aliasHandle: &this->aliasHandle, includeInherited: true);
  if ( Alias == nullptr )
    return nullptr;
  return (const idMD6Anim *)idResourceList::Load(
                              this: &idMD6Anim::resourceList,
                              name: Alias->animRefs.list[index].str,
                              makeDefault: false,
                              skipStaleCheck: true);
}

