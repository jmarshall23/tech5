
// ========================================================================
// ?SetcurrentState@animState_t@idAIScriptedAnimWeb@@QAAXH@Z
// EA  : 0x82A60660
// RVA : 0x00A60660
// PDB : w:\tech5\tungsten\game\ai\aiscriptedanimweb.h
// ========================================================================

void __fastcall idAIScriptedAnimWeb::animState_t::SetcurrentState(idAIScriptedAnimWeb::animState_t *this, int state)
{
  signed int num; // r31
  int v4; // r3
  int currentState; // r11

  if ( state >= 0 || state == -2 || state == -3 )
  {
    num = this->animWebStates->num;
    if ( num > state )
    {
      if ( state == -2 )
      {
        v4 = idRandom2::RandomInt(this: &clientGame->random, max: this->animWebStates->num);
        currentState = this->currentState;
        state = v4;
        if ( currentState != -1 && currentState == v4 )
        {
          __twllei(num, 0);
          state = (v4 + 1) % num;
          __twlgei(num & ~(__ROL4__(v4 + 1, 1) - 1), 0xFFFFFFFF);
        }
      }
      this->currentState = state;
    }
  }
}

