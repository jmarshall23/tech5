
// ========================================================================
// ?GetValidSpawnLocations@idSpawnNodeGroup@@QBAXABVidGameplayFilterTarget@@ABW4gameTeam_t@@M_NAAV?$idList@VidSpawnLocation@@$04@@@Z
// EA  : 0x82EA97B0
// RVA : 0x00EA97B0
// PDB : w:\tech5\tungsten\game\spawning\spawnnodegroup.cpp
// ========================================================================

void __fastcall idSpawnNodeGroup::GetValidSpawnLocations(
        idSpawnNodeGroup *this,
        const idGameplayFilterTarget *userType,
        const gameTeam_t *team,
        double userHalfSize,
        bool onlyInitial,
        idList<idSpawnLocation,5> *spawnLocations,
        int a7)
{
  __int64 v9; // r7
  int v14; // r29
  int v17; // r30

  LODWORD(v9) = this->approximateLocationCount;
  HIDWORD(v9) = &g_maxSpawnLocations;
  v14 = 0;
  _FP10 = (float)((float)1.0 - (float)(g_maxSpawnLocations.valueFloat / (float)v9));
  __asm { fsel      f30, f10, f11, f0 }
  if ( this->nodes.num > 0 )
  {
    v17 = 0;
    do
    {
      this->nodes.list[v17]->GetApproximateLocationCount(this: this->nodes.list[v17]);
      ((void (__fastcall *)(idSpawnNode *, const idGameplayFilterTarget *, const gameTeam_t *, void (__fastcall *)(idSpawnNode *, const idGameplayFilterTarget *, const gameTeam_t *, float, bool, idList<idSpawnLocation,5> *, const int), idList<idSpawnLocation,5> *, int, double))this->nodes.list[v17]->GetValidSpawnLocations)(
        a1: this->nodes.list[v17],
        a2: userType,
        a3: team,
        a4: this->nodes.list[v17]->GetValidSpawnLocations,
        a5: spawnLocations,
        a6: a7,
        a7: userHalfSize);
      ++v14;
      ++v17;
    }
    while ( v14 < this->nodes.num );
  }
}


// ========================================================================
// ?AddNode@idSpawnNodeGroup@@QAAXPAVidSpawnNode@@@Z
// EA  : 0x82EA98C0
// RVA : 0x00EA98C0
// PDB : w:\tech5\tungsten\game\spawning\spawnnodegroup.cpp
// ========================================================================

void __fastcall idSpawnNodeGroup::AddNode(
        idSpawnNodeGroup *this,
        idSpawnNode *node,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idSpawnNode *a14)
{
  a14 = node;
  idList<idAnimWebBlendTree *,5>::Append((idList<enum encounterGroupRole_t,5> *)this, obj: (encounterGroupRole_t *)&a14);
  this->approximateLocationCount += node->GetApproximateLocationCount(this: node);
}


// ========================================================================
// `dynamic initializer for 'g_maxSpawnLocations''
// EA  : 0x83392958
// RVA : 0x01392958
// PDB : w:\tech5\tungsten\game\spawning\spawnnodegroup.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_maxSpawnLocations__()
{
  idCVar::idCVar(
    this: &g_maxSpawnLocations,
    name: "g_maxSpawnLocations",
    value: "150",
    flags: 4,
    description: "Approximate limit to generated spawn locations.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_maxSpawnLocations__);
}

