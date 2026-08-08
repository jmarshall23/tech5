
// ========================================================================
// ?GetComponentName@ComponentManager@bfx@@SAPBDW4ComponentID@2@@Z
// EA  : 0x832921E0
// RVA : 0x012921E0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcomponents.cpp
// ========================================================================

const char *__fastcall bfx::ComponentManager::GetComponentName(unsigned int componentID)
{
  if ( componentID > 7 )
    return "<unknown>";
  switch ( componentID )
  {
    case 1u:
      return "bfxPlanner";
    case 2u:
      return "bfxPlanner3D";
    case 3u:
      return "bfxNavigator";
    case 4u:
      return "bfxMover";
    case 5u:
      return "bfxMover3D";
    case 6u:
      return "bfxBuilder";
    default:
      break;
  }
  if ( componentID != 0 )
    return "bfxBuilder3D";
  return "bfxSystem";
}


// ========================================================================
// ?RegisterComponent@ComponentManager@bfx@@QAAXW4ComponentID@2@PAVInstanceComponent@2@@Z
// EA  : 0x83292278
// RVA : 0x01292278
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcomponents.cpp
// ========================================================================

void __fastcall bfx::ComponentManager::RegisterComponent(
        bfx::ComponentManager *this,
        unsigned int id,
        bfx::InstanceComponent *pComponent)
{
  if ( id < 8 && this->m_components[id] == nullptr )
    this->m_components[id] = pComponent;
}


// ========================================================================
// ?IsComponentRegistered@ComponentManager@bfx@@QBA_NW4ComponentID@2@@Z
// EA  : 0x832922A0
// RVA : 0x012922A0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcomponents.cpp
// ========================================================================

BOOL __fastcall bfx::ComponentManager::IsComponentRegistered(bfx::ComponentManager *this, bfx::ComponentID id)
{
  return this->m_components[id] != nullptr;
}


// ========================================================================
// ?ComponentsInitSpace@ComponentManager@bfx@@QAAXPAVSpace@2@@Z
// EA  : 0x832922B8
// RVA : 0x012922B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcomponents.cpp
// ========================================================================

void __fastcall bfx::ComponentManager::ComponentsInitSpace(bfx::ComponentManager *this, bfx::Space *pSpace)
{
  int i; // r30

  for ( i = 8; i != 0; --i )
  {
    if ( this->m_components[0] != nullptr )
      this->m_components[0]->SpaceInit(this: this->m_components[0], a2: pSpace);
    this = (bfx::ComponentManager *)((char *)this + 4);
  }
}


// ========================================================================
// ?StartComponents@ComponentManager@bfx@@QAA_NXZ
// EA  : 0x83292308
// RVA : 0x01292308
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcomponents.cpp
// ========================================================================

int __fastcall bfx::ComponentManager::StartComponents(bfx::ComponentManager *this)
{
  bfx::ComponentManager::State m_state; // r11
  bfx::ComponentManager *v3; // r31
  int i; // r30

  m_state = this->m_state;
  if ( m_state != OPEN && m_state != STOPPED )
    return 0;
  v3 = this;
  this->m_state = STARTED;
  for ( i = 8; i != 0; --i )
  {
    if ( v3->m_components[0] != nullptr )
      v3->m_components[0]->Start(this: v3->m_components[0]);
    v3 = (bfx::ComponentManager *)((char *)v3 + 4);
  }
  return 1;
}


// ========================================================================
// ?StopComponents@ComponentManager@bfx@@QAAXXZ
// EA  : 0x83292390
// RVA : 0x01292390
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcomponents.cpp
// ========================================================================

void __fastcall bfx::ComponentManager::StopComponents(bfx::ComponentManager *this)
{
  int v1; // r30
  bfx::InstanceComponent **v2; // r31

  if ( this->m_state == STARTED )
  {
    v1 = 7;
    this->m_state = STOPPED;
    v2 = &this->m_components[7];
    do
    {
      if ( *v2 != nullptr )
        (*v2)->Stop(this: *v2);
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
  }
}


// ========================================================================
// ?DrawComponents@ComponentManager@bfx@@QAAXXZ
// EA  : 0x83292400
// RVA : 0x01292400
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcomponents.cpp
// ========================================================================

void __fastcall bfx::ComponentManager::DrawComponents(bfx::ComponentManager *this)
{
  bfx::ComponentManager *v1; // r31
  int i; // r30

  if ( this->m_state == STARTED )
  {
    v1 = this;
    for ( i = 8; i != 0; --i )
    {
      if ( v1->m_components[0] != nullptr )
        v1->m_components[0]->Draw(this: v1->m_components[0]);
      v1 = (bfx::ComponentManager *)((char *)v1 + 4);
    }
  }
}

