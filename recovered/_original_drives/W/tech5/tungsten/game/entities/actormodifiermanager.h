
// ========================================================================
// ?Set@ActorModifierVar_s@idActorModifierManager@@QAAXM@Z
// EA  : 0x82BEC100
// RVA : 0x00BEC100
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.h
// ========================================================================

void __fastcall idActorModifierManager::ActorModifierVar_s::Set(
        idActorModifierManager::ActorModifierVar_s *this,
        double value_)
{
  int count; // r11

  this->value = value_;
  this->integer = (int)value_;
  if ( common->IsServer(this: common) )
  {
    count = this->netFloat.event.count;
    this->netFloat.value = this->value;
    this->netFloat.event.count = (count + 1) % 7;
  }
}


// ========================================================================
// ?Serialize@ActorModifierVar_s@idActorModifierManager@@QAAXAAVidSerializer@@@Z
// EA  : 0x82BEC5C0
// RVA : 0x00BEC5C0
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.h
// ========================================================================

void __fastcall idActorModifierManager::ActorModifierVar_s::Serialize(
        idActorModifierManager::ActorModifierVar_s *this,
        idSerializer *ser)
{
  double value; // fp31
  idBitMsg *msg; // r3
  idBitMsg *v6; // r3
  idBitMsg *v7; // r3
  char v8; // r11
  int v9; // [sp+50h] [-30h]

  value = this->value;
  msg = ser->msg;
  if ( ser->writing )
  {
    *(float *)&v9 = value;
    idBitMsg::WriteBits(this: msg, value: v9, numBits: 32);
  }
  else
  {
    value = COERCE_FLOAT(idBitMsg::ReadBits(this: msg, numBits: 32));
  }
  v6 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v6, value: this->integer, numBits: 32);
  else
    this->integer = idBitMsg::ReadBits(this: v6, numBits: 32);
  netBoolEvent_t::Serialize(this: &this->netFloat.event, ser);
  v7 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v7, value: COERCE_INT(this->netFloat.value), numBits: 32);
  else
    LODWORD(this->netFloat.value) = idBitMsg::ReadBits(this: v7, numBits: 32);
  if ( !ser->writing )
  {
    if ( this->netFloat.event.count == this->netFloat.event.lastCount )
    {
      v8 = 0;
    }
    else
    {
      this->netFloat.event.lastCount = this->netFloat.event.count;
      v8 = 1;
    }
    if ( v8 != 0 )
      this->value = value;
  }
}

