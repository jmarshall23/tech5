
// ========================================================================
// ?Keyboard@idSysLocal@@UAAAAVidKeyboard@@XZ
// EA  : 0x829D2968
// RVA : 0x009D2968
// PDB : w:\tech5\engine\sys\xenon\xen_input_keyboard.cpp
// ========================================================================

idKeyboardXenon *__fastcall idSysLocal::Keyboard(idSysLocal *this)
{
  return &keyboard;
}


// ========================================================================
// ?ReturnInputEvent@idKeyboardXenon@@UAAHHAAHAA_N@Z
// EA  : 0x829D2978
// RVA : 0x009D2978
// PDB : w:\tech5\engine\sys\xenon\xen_input_keyboard.cpp
// ========================================================================

int __fastcall idKeyboardXenon::ReturnInputEvent(idKeyboardXenon *this, char n, int *ch, bool *state)
{
  int v7; // r30
  char *v8; // r29
  int v9; // r3
  int v10; // r30
  __int16 v11; // r11

  v7 = (unsigned __int8)(HIBYTE(this->tailEvent) + n);
  if ( v7 >= this->headEvent )
    return 0;
  v8 = (char *)this + 8 * v7;
  v9 = Key_CovertHIDCode(hid: (unsigned __int8)v8[19]);
  *ch = v9;
  v10 = 8 * (v7 + 2);
  v11 = *(_WORD *)((char *)&this->__vftable + v10);
  if ( (v11 & 2) != 0 )
  {
    sys->QueueEvent(this: sys, a2: SE_KEY, a3: v9, a4: 0, a5: 0, a6: nullptr, a7: 0);
    *state = false;
    return *ch;
  }
  else if ( (v11 & 1) != 0 )
  {
    sys->QueueEvent(this: sys, a2: SE_KEY, a3: v9, a4: 1, a5: 0, a6: nullptr, a7: 0);
    if ( (*(_WORD *)((_BYTE *)&this->__vftable + v10) & 0x1000) != 0 )
      sys->QueueEvent(this: sys, a2: SE_CHAR, a3: *((unsigned __int16 *)v8 + 7), a4: 0, a5: 0, a6: nullptr, a7: 0);
    *state = true;
    return *ch;
  }
  else
  {
    if ( (v11 & 4) != 0 && (*(_WORD *)((_BYTE *)&this->__vftable + v10) & 0x1000) != 0 )
      sys->QueueEvent(this: sys, a2: SE_CHAR, a3: *((unsigned __int16 *)v8 + 7), a4: 0, a5: 0, a6: nullptr, a7: 0);
    return *ch;
  }
}


// ========================================================================
// ?AsyncPollEvents@idKeyboardXenon@@QAAXXZ
// EA  : 0x829D2C50
// RVA : 0x009D2C50
// PDB : w:\tech5\engine\sys\xenon\xen_input_keyboard.cpp
// ========================================================================

void __fastcall idKeyboardXenon::AsyncPollEvents(idKeyboardXenon *this)
{
  idSysMutex *p_mutexPoll; // r30
  int v3; // r11

  p_mutexPoll = &this->mutexPoll;
  Sys_MutexLock(handle: &this->mutexPoll.handle, blocking: true);
  if ( (unsigned __int8)(HIBYTE(this->headEvent) + 1) != this->tailEvent )
  {
    do
    {
      if ( XInputGetKeystroke(dwUserIndex: 0xFFu, dwFlags: 2u, pKeystroke: &this->events[this->headEvent]) != 0 )
        break;
      v3 = (unsigned __int8)(this->headEvent + 1);
      this->headEvent = v3;
    }
    while ( (unsigned __int8)(v3 + 1) != this->tailEvent );
  }
  Sys_MutexUnlock(handle: &p_mutexPoll->handle);
}


// ========================================================================
// ?Xen_AsyncInputPoll@@YAXXZ
// EA  : 0x829D2D00
// RVA : 0x009D2D00
// PDB : w:\tech5\engine\sys\xenon\xen_input_keyboard.cpp
// ========================================================================

void __fastcall Xen_AsyncInputPoll()
{
  idKeyboardXenon::AsyncPollEvents(this: &keyboard);
}


// ========================================================================
// ?PollInputEvents@idKeyboardXenon@@UAAHXZ
// EA  : 0x829D2D10
// RVA : 0x009D2D10
// PDB : w:\tech5\engine\sys\xenon\xen_input_keyboard.cpp
// ========================================================================

int __fastcall idKeyboardXenon::PollInputEvents(idKeyboardXenon *this)
{
  Sys_MutexLock(handle: &this->mutexPoll.handle, blocking: true);
  return (unsigned __int8)(this->headEvent - this->tailEvent);
}


// ========================================================================
// ?EndInputEvents@idKeyboardXenon@@UAAXXZ
// EA  : 0x829D2D58
// RVA : 0x009D2D58
// PDB : w:\tech5\engine\sys\xenon\xen_input_keyboard.cpp
// ========================================================================

void __fastcall idKeyboardXenon::EndInputEvents(idKeyboardXenon *this)
{
  this->tailEvent = this->headEvent;
  Sys_MutexUnlock(handle: &this->mutexPoll.handle);
}


// ========================================================================
// `dynamic initializer for 'keyboard''
// EA  : 0x83363C68
// RVA : 0x01363C68
// PDB : w:\tech5\engine\sys\xenon\xen_input_keyboard.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__keyboard__()
{
  Sys_MutexCreate(handle: (_RTL_CRITICAL_SECTION **)&keyboard.mutexPoll);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__keyboard__);
}


// ========================================================================
// __unwind$219342
// EA  : 0x83363CAC
// RVA : 0x01363CAC
// PDB : w:\tech5\engine\sys\xenon\xen_input_keyboard.cpp
// ========================================================================

void _unwind_219342()
{
  idKeyboard::~idKeyboard(this: &keyboard);
}

