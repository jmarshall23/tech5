
// ========================================================================
// ?Spawn@idPanzerHund@@QAAXXZ
// EA  : 0x82C955B8
// RVA : 0x00C955B8
// PDB : w:\tech5\tungsten\game\entities\panzerhund.cpp
// ========================================================================

void __fastcall idPanzerHund::Spawn(idPanzerHund *this)
{
  idEntity::BecomeActive(this, flags: 2);
}


// ========================================================================
// ?Think@idPanzerHund@@UAAXXZ
// EA  : 0x82C955C0
// RVA : 0x00C955C0
// PDB : w:\tech5\tungsten\game\entities\panzerhund.cpp
// ========================================================================

// attributes: thunk
void __fastcall idPanzerHund::Think(idPanzerHund *this)
{
  idAnimated_AnimWeb::Think(this);
}


// ========================================================================
// ?Action_ChangeAnimState@idPanzerHund@@QAA?AVeventVoid@@W4aiAnimWeb_t@@ABVidAnimWebPath@@W4aiAnimWait_t@@@Z
// EA  : 0x82C955C8
// RVA : 0x00C955C8
// PDB : w:\tech5\tungsten\game\entities\panzerhund.cpp
// ========================================================================

idPanzerHund *__fastcall idPanzerHund::Action_ChangeAnimState(
        idPanzerHund *this,
        eventVoid *result,
        aiAnimWeb_t animweb,
        const idAnimWebPath *destNode,
        const aiAnimWait_t waitType)
{
  (*(void (__fastcall **)(eventVoid *, char *, aiAnimWeb_t))(*(_DWORD *)result + 196))(
    a1: result,
    a2: destNode->data,
    a3: animweb);
  return this;
}


// ========================================================================
// ?Action_ChangeAnimStateVia@idPanzerHund@@QAA?AVeventVoid@@W4aiAnimWeb_t@@ABVidAnimWebPath@@1W4aiAnimWait_t@@@Z
// EA  : 0x82C95610
// RVA : 0x00C95610
// PDB : w:\tech5\tungsten\game\entities\panzerhund.cpp
// ========================================================================

idPanzerHund *__fastcall idPanzerHund::Action_ChangeAnimStateVia(
        idPanzerHund *this,
        eventVoid *result,
        const aiAnimWeb_t animweb,
        const idAnimWebPath *destNode,
        const idAnimWebPath *viaNode,
        const aiAnimWait_t wait)
{
  (*(void (__fastcall **)(eventVoid *, char *, char *))(*(_DWORD *)result + 208))(
    a1: result,
    a2: viaNode->data,
    a3: destNode->data);
  return this;
}

