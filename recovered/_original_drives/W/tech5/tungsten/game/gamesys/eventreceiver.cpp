
// ========================================================================
// ?CancelEvents@idEventReceiver@@QAAXABVidEventDef@@@Z
// EA  : 0x82D5FE68
// RVA : 0x00D5FE68
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

void __fastcall idEventReceiver::CancelEvents(idEventReceiver *this, const idEventDef *ev)
{
  idEventSystem::CancelEvents(this: &clientGame->eventSystem, obj: this, evdef: ev);
}


// ========================================================================
// ?PostEventArgs@idEventReceiver@@AAA_NABVidEventDef@@HHZZ
// EA  : 0x82D5FE88
// RVA : 0x00D5FE88
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int idEventReceiver::PostEventArgs(
        idEventReceiver *this,
        const idEventDef *ev,
        int time,
        int numargs,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        ...)
{
  idEvent *v20; // r3
  __int64 v22; // [sp+C0h] [+30h] BYREF
  va_list va; // [sp+C0h] [+30h]
  __int64 v24; // [sp+C8h] [+38h]
  __int64 v25; // [sp+D0h] [+40h]
  __int64 v26; // [sp+D8h] [+48h]
  va_list va1; // [sp+E0h] [+50h] BYREF

  va_start(va1, a16);
  va_start(va, a16);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v22 = *(__int64 *)((char *)&a5 + 4);
  v24 = a5;
  v25 = *(__int64 *)((char *)&a6 + 4);
  v26 = a6;
  if ( ((unsigned __int8 (__fastcall *)(idEventReceiver *))this->RespondsTo)(a1: this) == 0 )
    return 0;
  v20 = idEventSystem::Alloc(this: &clientGame->eventSystem, evdef: ev, numargs, args: va);
  idEventSystem::Schedule(this: &clientGame->eventSystem, ev: v20, obj: this, time);
  return 1;
}


// ========================================================================
// ?PostEventMS@idEventReceiver@@QAA_NABVidEventDef@@H@Z
// EA  : 0x82D5FF30
// RVA : 0x00D5FF30
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

int __fastcall idEventReceiver::PostEventMS(
        idEventReceiver *this,
        const idEventDef *ev,
        int time,
        int a4,
        __int64 a5,
        __int64 a6)
{
  int v7; // [sp+8h] [-78h]
  int v8; // [sp+Ch] [-74h]
  int v9; // [sp+10h] [-70h]
  int v10; // [sp+14h] [-6Ch]
  int v11; // [sp+18h] [-68h]
  int v12; // [sp+1Ch] [-64h]
  int v13; // [sp+20h] [-60h]
  int v14; // [sp+24h] [-5Ch]
  int v15; // [sp+28h] [-58h]
  int v16; // [sp+2Ch] [-54h]

  return idEventReceiver::PostEventArgs(
           this,
           ev,
           time,
           numargs: 0,
           a5,
           a6,
           a7: v7,
           a8: v8,
           a9: v9,
           a10: v10,
           a11: v11,
           a12: v12,
           a13: v13,
           a14: v14,
           a15: v15,
           a16: v16);
}


// ========================================================================
// ?PostEventMS@idEventReceiver@@QAA_NABVidEventDef@@HVidEventArg@@@Z
// EA  : 0x82D5FF58
// RVA : 0x00D5FF58
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idEventReceiver::PostEventMS(
        idEventReceiver *this,
        const idEventDef *ev,
        __int64 arg1,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  int v14; // [sp+8h] [-88h]
  int v15; // [sp+Ch] [-84h]
  int v16; // [sp+10h] [-80h]
  int v17; // [sp+14h] [-7Ch]
  int v18; // [sp+18h] [-78h]
  int v19; // [sp+1Ch] [-74h]
  int v20; // [sp+20h] [-70h]
  int v21; // [sp+24h] [-6Ch]
  int v22; // [sp+28h] [-68h]
  int v23; // [sp+2Ch] [-64h]

  a11 = arg1;
  LODWORD(arg1) = 1;
  a12 = *(__int64 *)((char *)&a4 + 4);
  HIDWORD(a4) = &a11;
  a13 = a4;
  return idEventReceiver::PostEventArgs(
           this,
           ev,
           time: SHIDWORD(arg1),
           numargs: 1,
           a5: a4,
           a6: a5,
           a7: v14,
           a8: v15,
           a9: v16,
           a10: v17,
           a11: v18,
           a12: v19,
           a13: v20,
           a14: v21,
           a15: v22,
           a16: v23);
}


// ========================================================================
// ?PostEventMS@idEventReceiver@@QAA_NABVidEventDef@@HVidEventArg@@1@Z
// EA  : 0x82D5FF90
// RVA : 0x00D5FF90
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idEventReceiver::PostEventMS(
        idEventReceiver *this,
        const idEventDef *ev,
        __int64 arg1,
        __int64 arg2,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16)
{
  int v17; // [sp+8h] [-A8h]
  int v18; // [sp+Ch] [-A4h]
  int v19; // [sp+10h] [-A0h]
  int v20; // [sp+14h] [-9Ch]
  int v21; // [sp+18h] [-98h]
  int v22; // [sp+1Ch] [-94h]
  int v23; // [sp+20h] [-90h]
  int v24; // [sp+24h] [-8Ch]
  int v25; // [sp+28h] [-88h]
  int v26; // [sp+2Ch] [-84h]

  a11 = arg1;
  LODWORD(arg1) = 2;
  a12 = *(__int64 *)((char *)&arg2 + 4);
  HIDWORD(arg2) = &a11;
  a13 = arg2;
  LODWORD(arg2) = &a15;
  a15 = *(__int64 *)((char *)&a5 + 4);
  a16 = a5;
  return idEventReceiver::PostEventArgs(
           this,
           ev,
           time: SHIDWORD(arg1),
           numargs: 2,
           a5: arg2,
           a6: a5,
           a7: v17,
           a8: v18,
           a9: v19,
           a10: v20,
           a11: v21,
           a12: v22,
           a13: v23,
           a14: v24,
           a15: v25,
           a16: v26);
}


// ========================================================================
// ?PostEventMS@idEventReceiver@@QAA_NABVidEventDef@@HVidEventArg@@11@Z
// EA  : 0x82D5FFD0
// RVA : 0x00D5FFD0
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idEventReceiver::PostEventMS(
        idEventReceiver *this,
        const idEventDef *ev,
        __int64 arg1,
        __int64 arg3,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21)
{
  int v22; // [sp+8h] [-C8h]
  int v23; // [sp+Ch] [-C4h]
  int v24; // [sp+10h] [-C0h]
  int v25; // [sp+14h] [-BCh]
  int v26; // [sp+18h] [-B8h]
  int v27; // [sp+1Ch] [-B4h]
  int v28; // [sp+20h] [-B0h]
  int v29; // [sp+24h] [-ACh]
  int v30; // [sp+28h] [-A8h]
  int v31; // [sp+2Ch] [-A4h]

  a11 = arg1;
  LODWORD(arg1) = 3;
  a12 = *(__int64 *)((char *)&arg3 + 4);
  HIDWORD(arg3) = &a11;
  a13 = arg3;
  LODWORD(arg3) = &a15;
  a15 = *(__int64 *)((char *)&a5 + 4);
  HIDWORD(a5) = &a21;
  a16 = a5;
  return idEventReceiver::PostEventArgs(
           this,
           ev,
           time: SHIDWORD(arg1),
           numargs: 3,
           a5: arg3,
           a6: a5,
           a7: v22,
           a8: v23,
           a9: v24,
           a10: v25,
           a11: v26,
           a12: v27,
           a13: v28,
           a14: v29,
           a15: v30,
           a16: v31);
}


// ========================================================================
// ?PostEventMS@idEventReceiver@@QAA_NABVidEventDef@@HVidEventArg@@111@Z
// EA  : 0x82D60018
// RVA : 0x00D60018
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idEventReceiver::PostEventMS(
        idEventReceiver *this,
        const idEventDef *ev,
        __int64 arg1,
        __int64 arg3,
        __int64 arg4,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int arg3a,
        int arg3_4,
        int arg3_8,
        int arg3_12,
        int arg3_16,
        int a28,
        int arg4a)
{
  int v30; // [sp+8h] [-E8h]
  int v31; // [sp+Ch] [-E4h]
  int v32; // [sp+10h] [-E0h]
  int v33; // [sp+14h] [-DCh]
  int v34; // [sp+18h] [-D8h]
  int v35; // [sp+1Ch] [-D4h]
  int v36; // [sp+20h] [-D0h]
  int v37; // [sp+24h] [-CCh]
  int v38; // [sp+28h] [-C8h]
  int v39; // [sp+2Ch] [-C4h]

  a11 = arg1;
  LODWORD(arg1) = 4;
  a12 = *(__int64 *)((char *)&arg3 + 4);
  HIDWORD(arg3) = &a11;
  a13 = arg3;
  LODWORD(arg3) = &a15;
  a15 = *(__int64 *)((char *)&arg4 + 4);
  HIDWORD(arg4) = &a21;
  a16 = arg4;
  LODWORD(arg4) = &arg4a;
  return idEventReceiver::PostEventArgs(
           this,
           ev,
           time: SHIDWORD(arg1),
           numargs: 4,
           a5: arg3,
           a6: arg4,
           a7: v30,
           a8: v31,
           a9: v32,
           a10: v33,
           a11: v34,
           a12: v35,
           a13: v36,
           a14: v37,
           a15: v38,
           a16: v39);
}


// ========================================================================
// ??0idEventReceiver@@QAA@XZ
// EA  : 0x82D60250
// RVA : 0x00D60250
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

idEventReceiver *__fastcall idEventReceiver::idEventReceiver(idEventReceiver *this)
{
  this->listenerList = nullptr;
  this->__vftable = (idEventReceiver_vtbl *)&idEventReceiver::`vftable';
  this->listeningToList = nullptr;
  return this;
}


// ========================================================================
// ?PostEventSec@idEventReceiver@@QAA_NABVidEventDef@@M@Z
// EA  : 0x82D60270
// RVA : 0x00D60270
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

int __fastcall idEventReceiver::PostEventSec(
        idEventReceiver *this,
        const idEventDef *ev,
        double time,
        int a4,
        int a5,
        __int64 a6,
        __int64 a7)
{
  int v8; // [sp+8h] [-78h]
  int v9; // [sp+Ch] [-74h]
  int v10; // [sp+10h] [-70h]
  int v11; // [sp+14h] [-6Ch]
  int v12; // [sp+18h] [-68h]
  int v13; // [sp+1Ch] [-64h]
  int v14; // [sp+20h] [-60h]
  int v15; // [sp+24h] [-5Ch]
  int v16; // [sp+28h] [-58h]
  int v17; // [sp+2Ch] [-54h]

  return idEventReceiver::PostEventArgs(
           this,
           ev,
           time: (int)(float)((float)1000.0 * (float)time),
           numargs: 0,
           a5: a6,
           a6: a7,
           a7: v8,
           a8: v9,
           a9: v10,
           a10: v11,
           a11: v12,
           a12: v13,
           a13: v14,
           a14: v15,
           a15: v16,
           a16: v17);
}


// ========================================================================
// ?PostEventSec@idEventReceiver@@QAA_NABVidEventDef@@MVidEventArg@@@Z
// EA  : 0x82D602B0
// RVA : 0x00D602B0
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idEventReceiver::PostEventSec(
        idEventReceiver *this,
        const idEventDef *ev,
        double time,
        __int64 arg1,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14)
{
  int v15; // [sp+8h] [-98h]
  int v16; // [sp+Ch] [-94h]
  int v17; // [sp+10h] [-90h]
  int v18; // [sp+14h] [-8Ch]
  int v19; // [sp+18h] [-88h]
  int v20; // [sp+1Ch] [-84h]
  int v21; // [sp+20h] [-80h]
  int v22; // [sp+24h] [-7Ch]
  int v23; // [sp+28h] [-78h]
  int v24; // [sp+2Ch] [-74h]

  a12 = arg1;
  a13 = *(__int64 *)((char *)&a5 + 4);
  HIDWORD(a5) = &a12;
  a14 = a5;
  return idEventReceiver::PostEventArgs(
           this,
           ev,
           time: (int)(float)((float)1000.0 * (float)time),
           numargs: 1,
           a5,
           a6,
           a7: v15,
           a8: v16,
           a9: v17,
           a10: v18,
           a11: v19,
           a12: v20,
           a13: v21,
           a14: v22,
           a15: v23,
           a16: v24);
}


// ========================================================================
// ?PostEventSec@idEventReceiver@@QAA_NABVidEventDef@@MVidEventArg@@1@Z
// EA  : 0x82D60300
// RVA : 0x00D60300
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idEventReceiver::PostEventSec(
        idEventReceiver *this,
        const idEventDef *ev,
        double time,
        __int64 arg2,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17)
{
  int v18; // [sp+8h] [-B8h]
  int v19; // [sp+Ch] [-B4h]
  int v20; // [sp+10h] [-B0h]
  int v21; // [sp+14h] [-ACh]
  int v22; // [sp+18h] [-A8h]
  int v23; // [sp+1Ch] [-A4h]
  int v24; // [sp+20h] [-A0h]
  int v25; // [sp+24h] [-9Ch]
  int v26; // [sp+28h] [-98h]
  int v27; // [sp+2Ch] [-94h]

  a12 = arg2;
  a13 = *(__int64 *)((char *)&a5 + 4);
  HIDWORD(a5) = &a12;
  a14 = a5;
  LODWORD(a5) = &a16;
  a16 = *(__int64 *)((char *)&a6 + 4);
  a17 = a6;
  return idEventReceiver::PostEventArgs(
           this,
           ev,
           time: (int)(float)((float)1000.0 * (float)time),
           numargs: 2,
           a5,
           a6,
           a7: v18,
           a8: v19,
           a9: v20,
           a10: v21,
           a11: v22,
           a12: v23,
           a13: v24,
           a14: v25,
           a15: v26,
           a16: v27);
}


// ========================================================================
// ?Event_Remove@idEventReceiver@@QAA?AVeventVoid@@XZ
// EA  : 0x82D60358
// RVA : 0x00D60358
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

idEventReceiver *__fastcall idEventReceiver::Event_Remove(idEventReceiver *this, eventVoid *result)
{
  if ( result != nullptr )
    (*(void (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 4))(a1: result, a2: 1);
  return this;
}


// ========================================================================
// ?InternalCallNotice@idEventReceiver@@IAAXABVidEventDef@@PBVidEventArg@@@Z
// EA  : 0x82D603A8
// RVA : 0x00D603A8
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

void __fastcall idEventReceiver::InternalCallNotice(
        idEventReceiver *this,
        const idEventDef *event,
        const idEventArg *args)
{
  idList<idEventReceiver *,5> *listenerList; // r30
  char v7; // r31
  int v8; // r25
  int v9; // r29
  char *v10; // r10
  int v11; // ctr
  _DWORD *v12; // r11
  int numargs; // r11
  _DWORD v14[8]; // [sp+4Ch] [-144h] BYREF
  char v15; // [sp+6Ch] [-124h] BYREF
  char v16; // [sp+70h] [-120h] BYREF
  int v17; // [sp+74h] [-11Ch]
  _BYTE v18[4]; // [sp+84h] [-10Ch] BYREF
  int v19; // [sp+88h] [-108h]
  char v20; // [sp+98h] [-F8h]
  int v21; // [sp+9Ch] [-F4h]
  char v22; // [sp+ACh] [-E4h]
  int v23; // [sp+B0h] [-E0h]
  char v24; // [sp+C0h] [-D0h]
  int v25; // [sp+C4h] [-CCh]
  char v26; // [sp+D4h] [-BCh]
  int v27; // [sp+D8h] [-B8h]
  char v28; // [sp+E8h] [-A8h]
  int v29; // [sp+ECh] [-A4h]
  char v30; // [sp+FCh] [-94h]
  int v31; // [sp+100h] [-90h]
  char v32; // [sp+110h] [-80h]
  int v33; // [sp+114h] [-7Ch]
  char v34; // [sp+130h] [-60h] BYREF

  listenerList = this->listenerList;
  v16 = 0;
  v17 = 0;
  v7 = 0;
  v18[0] = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  if ( listenerList != nullptr )
  {
    v8 = 0;
    if ( listenerList->num > 0 )
    {
      v9 = 0;
      do
      {
        if ( listenerList->list[v9]->RespondsTo(this: listenerList->list[v9], a2: event) )
        {
          if ( v7 == 0 )
          {
            v14[2] = this;
            v10 = &v15;
            HIBYTE(v14[1]) = 114;
            v11 = 5;
            v12 = v14;
            do
            {
              ++v12;
              v10 += 4;
              *(_DWORD *)v10 = *v12;
              --v11;
            }
            while ( v11 != 0 );
            numargs = event->numargs;
            if ( numargs > 1 )
              memcpy(Dst: v18, Src: args, Size: 20 * (numargs - 1));
            v7 = 1;
          }
          listenerList->list[v9]->CallEvent(
            this: (idEventReceiver *)&v34,
            result: (idEventArg *)listenerList->list[v9],
            a3: event,
            a4: (const idEventArg *)&v16);
        }
        ++v8;
        ++v9;
      }
      while ( v8 < listenerList->num );
    }
  }
}


// ========================================================================
// ?BroadcastEventArgs@idEventReceiver@@AAA_NABVidEventDef@@HZZ
// EA  : 0x82D60500
// RVA : 0x00D60500
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int idEventReceiver::BroadcastEventArgs(
        idEventReceiver *this,
        const idEventDef *ev,
        __int64 numargs,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        ...)
{
  va_list v14; // r11
  idEventArg *v15; // r8
  _DWORD *v16; // r9
  int v17; // ctr
  _DWORD *v18; // r10
  idEventArg v19; // [sp+60h] [-B0h] BYREF
  char v20; // [sp+74h] [-9Ch]
  int v21; // [sp+78h] [-98h]
  char v22; // [sp+88h] [-88h]
  int v23; // [sp+8Ch] [-84h]
  char v24; // [sp+9Ch] [-74h]
  int v25; // [sp+A0h] [-70h]
  char v26; // [sp+B0h] [-60h]
  int v27; // [sp+B4h] [-5Ch]
  char v28; // [sp+C4h] [-4Ch]
  int v29; // [sp+C8h] [-48h]
  char v30; // [sp+D8h] [-38h]
  int v31; // [sp+DCh] [-34h]
  char v32; // [sp+ECh] [-24h]
  int v33; // [sp+F0h] [-20h]
  __int64 v34; // [sp+138h] [+28h] BYREF
  va_list va; // [sp+138h] [+28h]
  __int64 v36; // [sp+140h] [+30h]
  __int64 v37; // [sp+148h] [+38h]
  __int64 v38; // [sp+150h] [+40h]
  __int64 v39; // [sp+158h] [+48h]
  va_list va1; // [sp+160h] [+50h] BYREF

  va_start(va1, a13);
  va_start(va, a13);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v34 = numargs;
  v36 = *(__int64 *)((char *)&a4 + 4);
  v37 = a4;
  v38 = *(__int64 *)((char *)&a5 + 4);
  v39 = a5;
  if ( this->listenerList == nullptr )
    return 0;
  v19.type = 0;
  v19.value.i = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  if ( SHIDWORD(numargs) > 0 )
  {
    va_copy(v14, va);
    v15 = &v19;
    do
    {
      v16 = (_DWORD *)&v15[-1].value.q[3];
      v14 = (va_list)(((unsigned int)(v14 + 7) & 0xFFFFFFF8) + 8);
      v17 = 5;
      v18 = (_DWORD *)(*((_DWORD *)v14 - 1) - 4);
      do
      {
        *++v16 = *++v18;
        --v17;
      }
      while ( v17 != 0 );
      --HIDWORD(numargs);
      ++v15;
    }
    while ( HIDWORD(numargs) != 0 );
  }
  idEventReceiver::InternalCallNotice(this, event: ev, args: &v19);
  return 1;
}


// ========================================================================
// ?ProcessEventArgPtr@idEventReceiver@@QAA?AVidEventArg@@ABVidEventDef@@PBV2@@Z
// EA  : 0x82D605F8
// RVA : 0x00D605F8
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

idEventReceiver *__fastcall idEventReceiver::ProcessEventArgPtr(
        idEventReceiver *this,
        idEventReceiver *result,
        const idEventDef *ev,
        idAICover *args)
{
  const idEntity *Entity; // r3
  const char *data; // r30
  idList<idEventReceiver *,5> *listenerList; // r26
  int v11; // r3
  const idEventDef *noticeEvent; // r4

  if ( g_debugTriggers.valueInteger != 0
    && ev == &EV_Activate
    && (unsigned __int8)idClass::IsType(this: result, superclass: &idEntity::Type) != 0 )
  {
    Entity = idEventArg::GetEntity(this: args);
    if ( Entity != nullptr )
      data = Entity->name.data;
    else
      data = "NULL";
    listenerList = result[1].listenerList;
    v11 = idAccolade::Count(this: &clientGame->gameTimeManager);
    idLib::Printf(fmt: "%d: '%s' activated by '%s'\n", v11, (const char *)listenerList, data);
  }
  result->CallEvent(this, (idEventArg *)result, a3: ev, a4: (const idEventArg *)args);
  noticeEvent = ev->noticeEvent;
  if ( noticeEvent != nullptr )
    idEventReceiver::InternalCallNotice(this: result, event: noticeEvent, (const idEventArg *)args);
  return this;
}


// ========================================================================
// ?RemoveEventListener@idEventReceiver@@QAAXPAV1@@Z
// EA  : 0x82D606E8
// RVA : 0x00D606E8
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

void __fastcall idEventReceiver::RemoveEventListener(
        idEventReceiver *this,
        lobbyUser_t *listener,
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
        lobbyUser_t *a14)
{
  idList<idEventReceiver *,5> *listenerList; // r3
  idList<idEventReceiver *,5> *peerIndex; // r11
  idEventReceiver *v18; // [sp+50h] [-20h] BYREF

  listenerList = this->listenerList;
  a14 = listener;
  if ( listenerList != nullptr )
  {
    idList<idPresentableAnimatedEntity *,5>::Remove(this: (idList<lobbyUser_t *,5> *)listenerList, obj: &a14);
    peerIndex = (idList<idEventReceiver *,5> *)listener->peerIndex;
    if ( peerIndex != nullptr )
    {
      v18 = this;
      idList<idPresentableAnimatedEntity *,5>::Remove(
        this: (idList<lobbyUser_t *,5> *)peerIndex,
        obj: (lobbyUser_t *const *)&v18);
    }
  }
}


// ========================================================================
// ?BroadcastEvent@idEventReceiver@@QAA_NABVidEventDef@@VidEventArg@@@Z
// EA  : 0x82D60750
// RVA : 0x00D60750
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idEventReceiver::BroadcastEvent(
        idEventReceiver *this,
        const idEventDef *ev,
        __int64 arg1,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  int v12; // [sp+8h] [-78h]
  int v13; // [sp+Ch] [-74h]
  int v14; // [sp+10h] [-70h]
  int v15; // [sp+14h] [-6Ch]
  int v16; // [sp+18h] [-68h]
  int v17; // [sp+1Ch] [-64h]
  int v18; // [sp+20h] [-60h]
  int v19; // [sp+24h] [-5Ch]

  a9 = *(__int64 *)((char *)&arg1 + 4);
  HIDWORD(arg1) = 1;
  a10 = arg1;
  LODWORD(arg1) = &a9;
  a11 = *(__int64 *)((char *)&a4 + 4);
  return idEventReceiver::BroadcastEventArgs(
           this,
           ev,
           numargs: arg1,
           a4,
           a5,
           a6: v12,
           a7: v13,
           a8: v14,
           a9: v15,
           a10: v16,
           a11: v17,
           a12: v18,
           a13: v19);
}


// ========================================================================
// ?BroadcastEvent@idEventReceiver@@QAA_NABVidEventDef@@VidEventArg@@1@Z
// EA  : 0x82D60788
// RVA : 0x00D60788
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idEventReceiver::BroadcastEvent(
        idEventReceiver *this,
        const idEventDef *ev,
        __int64 arg2,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15)
{
  int v16; // [sp+8h] [-98h]
  int v17; // [sp+Ch] [-94h]
  int v18; // [sp+10h] [-90h]
  int v19; // [sp+14h] [-8Ch]
  int v20; // [sp+18h] [-88h]
  int v21; // [sp+1Ch] [-84h]
  int v22; // [sp+20h] [-80h]
  int v23; // [sp+24h] [-7Ch]

  a9 = *(__int64 *)((char *)&arg2 + 4);
  HIDWORD(arg2) = 2;
  a10 = arg2;
  LODWORD(arg2) = &a9;
  a11 = *(__int64 *)((char *)&a4 + 4);
  HIDWORD(a4) = &a13;
  a13 = a4;
  a14 = *(__int64 *)((char *)&a5 + 4);
  a15 = a5;
  return idEventReceiver::BroadcastEventArgs(
           this,
           ev,
           numargs: arg2,
           a4,
           a5,
           a6: v16,
           a7: v17,
           a8: v18,
           a9: v19,
           a10: v20,
           a11: v21,
           a12: v22,
           a13: v23);
}


// ========================================================================
// ?BroadcastEvent@idEventReceiver@@QAA_NABVidEventDef@@VidEventArg@@11@Z
// EA  : 0x82D607D0
// RVA : 0x00D607D0
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idEventReceiver::BroadcastEvent(
        idEventReceiver *this,
        const idEventDef *ev,
        __int64 arg2,
        __int64 arg3,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        int a16,
        int a17,
        int a18)
{
  int v19; // [sp+8h] [-B8h]
  int v20; // [sp+Ch] [-B4h]
  int v21; // [sp+10h] [-B0h]
  int v22; // [sp+14h] [-ACh]
  int v23; // [sp+18h] [-A8h]
  int v24; // [sp+1Ch] [-A4h]
  int v25; // [sp+20h] [-A0h]
  int v26; // [sp+24h] [-9Ch]

  a9 = *(__int64 *)((char *)&arg2 + 4);
  HIDWORD(arg2) = 3;
  a10 = arg2;
  LODWORD(arg2) = &a9;
  a11 = *(__int64 *)((char *)&arg3 + 4);
  HIDWORD(arg3) = &a13;
  a13 = arg3;
  LODWORD(arg3) = &a18;
  a14 = *(__int64 *)((char *)&a5 + 4);
  a15 = a5;
  return idEventReceiver::BroadcastEventArgs(
           this,
           ev,
           numargs: arg2,
           a4: arg3,
           a5,
           a6: v19,
           a7: v20,
           a8: v21,
           a9: v22,
           a10: v23,
           a11: v24,
           a12: v25,
           a13: v26);
}


// ========================================================================
// ?BroadcastEvent@idEventReceiver@@QAA_NABVidEventDef@@VidEventArg@@111@Z
// EA  : 0x82D60818
// RVA : 0x00D60818
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idEventReceiver::BroadcastEvent(
        idEventReceiver *this,
        const idEventDef *ev,
        __int64 arg2,
        __int64 arg4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int arg3,
        int arg3_4,
        int arg3_8,
        int arg3_12,
        int arg3_16)
{
  int v27; // [sp+8h] [-D8h]
  int v28; // [sp+Ch] [-D4h]
  int v29; // [sp+10h] [-D0h]
  int v30; // [sp+14h] [-CCh]
  int v31; // [sp+18h] [-C8h]
  int v32; // [sp+1Ch] [-C4h]
  int v33; // [sp+20h] [-C0h]
  int v34; // [sp+24h] [-BCh]

  a9 = *(__int64 *)((char *)&arg2 + 4);
  HIDWORD(arg2) = 4;
  a10 = arg2;
  LODWORD(arg2) = &a9;
  a11 = *(__int64 *)((char *)&arg4 + 4);
  HIDWORD(arg4) = &a13;
  a13 = arg4;
  LODWORD(arg4) = &a18;
  a14 = *(__int64 *)((char *)&a5 + 4);
  HIDWORD(a5) = &arg3_16;
  a15 = a5;
  return idEventReceiver::BroadcastEventArgs(
           this,
           ev,
           numargs: arg2,
           a4: arg4,
           a5,
           a6: v27,
           a7: v28,
           a8: v29,
           a9: v30,
           a10: v31,
           a11: v32,
           a12: v33,
           a13: v34);
}


// ========================================================================
// ?AllocListenerList@idEventReceiver@@IAAXXZ
// EA  : 0x82D60870
// RVA : 0x00D60870
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

void __fastcall idEventReceiver::AllocListenerList(idEventReceiver *this)
{
  idList<idDeclVehicleUpgrade const *,5> *v2; // r3
  idList<idEventReceiver *,5> *v3; // r3

  if ( this->listenerList == nullptr )
  {
    v2 = (idList<idDeclVehicleUpgrade const *,5> *)idMem::AllocWithLocation(
                                                     this: &mem,
                                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                     size: 0x10u,
                                                     tag: TAG_EVENT_LISTENER,
                                                     zeroBuffer: false,
                                                     align: ALIGN_16,
                                                     heap: HEAP_DEFAULTHEAP);
    if ( v2 != nullptr )
      v3 = (idList<idEventReceiver *,5> *)idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: v2);
    else
      v3 = nullptr;
    this->listenerList = v3;
  }
}


// ========================================================================
// __unwind$489483_0
// EA  : 0x82D608F4
// RVA : 0x00D608F4
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

void _unwind_489483_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_EVENT_LISTENER);
}


// ========================================================================
// ?ProcessEventArgs@idEventReceiver@@AAA?AVidEventArg@@ABVidEventDef@@HZZ
// EA  : 0x82D60920
// RVA : 0x00D60920
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idEventReceiver *idEventReceiver::ProcessEventArgs(
        idEventReceiver *this,
        idEventReceiver *result,
        const idEventDef *ev,
        int numargs,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        ...)
{
  va_list v17; // r11
  idAICover *v18; // r8
  __int16 *p_coverIndex; // r9
  int v20; // ctr
  _DWORD *v21; // r10
  idAICover v23; // [sp+60h] [-B0h] BYREF
  char v24; // [sp+74h] [-9Ch]
  int v25; // [sp+78h] [-98h]
  char v26; // [sp+88h] [-88h]
  int v27; // [sp+8Ch] [-84h]
  char v28; // [sp+9Ch] [-74h]
  int v29; // [sp+A0h] [-70h]
  char v30; // [sp+B0h] [-60h]
  int v31; // [sp+B4h] [-5Ch]
  char v32; // [sp+C4h] [-4Ch]
  int v33; // [sp+C8h] [-48h]
  char v34; // [sp+D8h] [-38h]
  int v35; // [sp+DCh] [-34h]
  char v36; // [sp+ECh] [-24h]
  int v37; // [sp+F0h] [-20h]
  __int64 v38; // [sp+140h] [+30h] BYREF
  va_list va; // [sp+140h] [+30h]
  __int64 v40; // [sp+148h] [+38h]
  __int64 v41; // [sp+150h] [+40h]
  __int64 v42; // [sp+158h] [+48h]
  va_list va1; // [sp+160h] [+50h] BYREF

  va_start(va1, a16);
  va_start(va, a16);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v38 = *(__int64 *)((char *)&a5 + 4);
  v40 = a5;
  v41 = *(__int64 *)((char *)&a6 + 4);
  v42 = a6;
  HIBYTE(v23.aas) = 0;
  v23.spawnId.value = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  if ( numargs > 0 )
  {
    va_copy(v17, va);
    v18 = &v23;
    do
    {
      p_coverIndex = &v18[-1].coverIndex;
      v17 = (va_list)(((unsigned int)(v17 + 7) & 0xFFFFFFF8) + 8);
      v20 = 5;
      v21 = (_DWORD *)(*((_DWORD *)v17 - 1) - 4);
      do
      {
        ++v21;
        p_coverIndex += 2;
        *(_DWORD *)p_coverIndex = *v21;
        --v20;
      }
      while ( v20 != 0 );
      --numargs;
      v18 = (idAICover *)((char *)v18 + 20);
    }
    while ( numargs != 0 );
  }
  idEventReceiver::ProcessEventArgPtr(this, result, ev, args: &v23);
  return this;
}


// ========================================================================
// ?ProcessEvent@idEventReceiver@@QAA?AVidEventArg@@ABVidEventDef@@@Z
// EA  : 0x82D60A08
// RVA : 0x00D60A08
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

idEventReceiver *__fastcall idEventReceiver::ProcessEvent(
        idEventReceiver *this,
        idEventReceiver *result,
        const idEventDef *ev,
        int a4,
        __int64 a5,
        __int64 a6)
{
  int v8; // [sp+8h] [-78h]
  int v9; // [sp+Ch] [-74h]
  int v10; // [sp+10h] [-70h]
  int v11; // [sp+14h] [-6Ch]
  int v12; // [sp+18h] [-68h]
  int v13; // [sp+1Ch] [-64h]
  int v14; // [sp+20h] [-60h]
  int v15; // [sp+24h] [-5Ch]
  int v16; // [sp+28h] [-58h]
  int v17; // [sp+2Ch] [-54h]

  idEventReceiver::ProcessEventArgs(
    this,
    result,
    ev,
    numargs: 0,
    a5,
    a6,
    a7: v8,
    a8: v9,
    a9: v10,
    a10: v11,
    a11: v12,
    a12: v13,
    a13: v14,
    a14: v15,
    a15: v16,
    a16: v17);
  return this;
}


// ========================================================================
// ?ProcessEvent@idEventReceiver@@QAA?AVidEventArg@@ABVidEventDef@@V2@@Z
// EA  : 0x82D60A40
// RVA : 0x00D60A40
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idEventReceiver *__fastcall idEventReceiver::ProcessEvent(
        idEventReceiver *this,
        idEventReceiver *result,
        __int64 arg1,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  int v15; // [sp+8h] [-98h]
  int v16; // [sp+Ch] [-94h]
  int v17; // [sp+10h] [-90h]
  int v18; // [sp+14h] [-8Ch]
  int v19; // [sp+18h] [-88h]
  int v20; // [sp+1Ch] [-84h]
  int v21; // [sp+20h] [-80h]
  int v22; // [sp+24h] [-7Ch]
  int v23; // [sp+28h] [-78h]
  int v24; // [sp+2Ch] [-74h]

  a11 = arg1;
  LODWORD(arg1) = 1;
  a12 = *(__int64 *)((char *)&a4 + 4);
  HIDWORD(a4) = &a11;
  a13 = a4;
  idEventReceiver::ProcessEventArgs(
    this,
    result,
    ev: (const idEventDef *)HIDWORD(arg1),
    numargs: 1,
    a5: a4,
    a6: a5,
    a7: v15,
    a8: v16,
    a9: v17,
    a10: v18,
    a11: v19,
    a12: v20,
    a13: v21,
    a14: v22,
    a15: v23,
    a16: v24);
  return this;
}


// ========================================================================
// ?ProcessEvent@idEventReceiver@@QAA?AVidEventArg@@ABVidEventDef@@V2@1@Z
// EA  : 0x82D60A88
// RVA : 0x00D60A88
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idEventReceiver *__fastcall idEventReceiver::ProcessEvent(
        idEventReceiver *this,
        idEventReceiver *result,
        __int64 arg1,
        __int64 arg2,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16)
{
  int v18; // [sp+8h] [-B8h]
  int v19; // [sp+Ch] [-B4h]
  int v20; // [sp+10h] [-B0h]
  int v21; // [sp+14h] [-ACh]
  int v22; // [sp+18h] [-A8h]
  int v23; // [sp+1Ch] [-A4h]
  int v24; // [sp+20h] [-A0h]
  int v25; // [sp+24h] [-9Ch]
  int v26; // [sp+28h] [-98h]
  int v27; // [sp+2Ch] [-94h]

  a11 = arg1;
  LODWORD(arg1) = 2;
  a12 = *(__int64 *)((char *)&arg2 + 4);
  HIDWORD(arg2) = &a11;
  a13 = arg2;
  LODWORD(arg2) = &a15;
  a15 = *(__int64 *)((char *)&a5 + 4);
  a16 = a5;
  idEventReceiver::ProcessEventArgs(
    this,
    result,
    ev: (const idEventDef *)HIDWORD(arg1),
    numargs: 2,
    a5: arg2,
    a6: a5,
    a7: v18,
    a8: v19,
    a9: v20,
    a10: v21,
    a11: v22,
    a12: v23,
    a13: v24,
    a14: v25,
    a15: v26,
    a16: v27);
  return this;
}


// ========================================================================
// ?ProcessEvent@idEventReceiver@@QAA?AVidEventArg@@ABVidEventDef@@V2@11@Z
// EA  : 0x82D60AD8
// RVA : 0x00D60AD8
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idEventReceiver *__fastcall idEventReceiver::ProcessEvent(
        idEventReceiver *this,
        idEventReceiver *result,
        __int64 arg1,
        __int64 arg3,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21)
{
  int v23; // [sp+8h] [-D8h]
  int v24; // [sp+Ch] [-D4h]
  int v25; // [sp+10h] [-D0h]
  int v26; // [sp+14h] [-CCh]
  int v27; // [sp+18h] [-C8h]
  int v28; // [sp+1Ch] [-C4h]
  int v29; // [sp+20h] [-C0h]
  int v30; // [sp+24h] [-BCh]
  int v31; // [sp+28h] [-B8h]
  int v32; // [sp+2Ch] [-B4h]

  a11 = arg1;
  LODWORD(arg1) = 3;
  a12 = *(__int64 *)((char *)&arg3 + 4);
  HIDWORD(arg3) = &a11;
  a13 = arg3;
  LODWORD(arg3) = &a15;
  a15 = *(__int64 *)((char *)&a5 + 4);
  HIDWORD(a5) = &a21;
  a16 = a5;
  idEventReceiver::ProcessEventArgs(
    this,
    result,
    ev: (const idEventDef *)HIDWORD(arg1),
    numargs: 3,
    a5: arg3,
    a6: a5,
    a7: v23,
    a8: v24,
    a9: v25,
    a10: v26,
    a11: v27,
    a12: v28,
    a13: v29,
    a14: v30,
    a15: v31,
    a16: v32);
  return this;
}


// ========================================================================
// ?ProcessEvent@idEventReceiver@@QAA?AVidEventArg@@ABVidEventDef@@V2@111@Z
// EA  : 0x82D60B30
// RVA : 0x00D60B30
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idEventReceiver *__fastcall idEventReceiver::ProcessEvent(
        idEventReceiver *this,
        idEventReceiver *result,
        __int64 arg1,
        __int64 arg3,
        __int64 arg4,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int arg3a,
        int arg3_4,
        int arg3_8,
        int arg3_12,
        int arg3_16,
        int a28,
        int arg4a)
{
  int v31; // [sp+8h] [-F8h]
  int v32; // [sp+Ch] [-F4h]
  int v33; // [sp+10h] [-F0h]
  int v34; // [sp+14h] [-ECh]
  int v35; // [sp+18h] [-E8h]
  int v36; // [sp+1Ch] [-E4h]
  int v37; // [sp+20h] [-E0h]
  int v38; // [sp+24h] [-DCh]
  int v39; // [sp+28h] [-D8h]
  int v40; // [sp+2Ch] [-D4h]

  a11 = arg1;
  LODWORD(arg1) = 4;
  a12 = *(__int64 *)((char *)&arg3 + 4);
  HIDWORD(arg3) = &a11;
  a13 = arg3;
  LODWORD(arg3) = &a15;
  a15 = *(__int64 *)((char *)&arg4 + 4);
  HIDWORD(arg4) = &a21;
  a16 = arg4;
  LODWORD(arg4) = &arg4a;
  idEventReceiver::ProcessEventArgs(
    this,
    result,
    ev: (const idEventDef *)HIDWORD(arg1),
    numargs: 4,
    a5: arg3,
    a6: arg4,
    a7: v31,
    a8: v32,
    a9: v33,
    a10: v34,
    a11: v35,
    a12: v36,
    a13: v37,
    a14: v38,
    a15: v39,
    a16: v40);
  return this;
}


// ========================================================================
// ?ProcessEvent@idEventReceiver@@QAA?AVidEventArg@@ABVidEventDef@@V2@1111@Z
// EA  : 0x82D60B88
// RVA : 0x00D60B88
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idEventReceiver *__fastcall idEventReceiver::ProcessEvent(
        idEventReceiver *this,
        idEventReceiver *result,
        __int64 arg1,
        __int64 arg3,
        __int64 arg5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int arg3a,
        int arg3_4,
        int arg3_8,
        int arg3_12,
        int arg3_16,
        int a28,
        int arg4)
{
  int v31; // [sp+8h] [-118h]
  int v32; // [sp+Ch] [-114h]
  int v33; // [sp+10h] [-110h]
  int v34; // [sp+14h] [-10Ch]
  int v35; // [sp+18h] [-108h]
  int v36; // [sp+1Ch] [-104h]
  int v37; // [sp+20h] [-100h]
  int v38; // [sp+24h] [-FCh]
  int v39; // [sp+28h] [-F8h]
  int v40; // [sp+2Ch] [-F4h]

  a11 = arg1;
  a12 = *(__int64 *)((char *)&arg3 + 4);
  HIDWORD(arg3) = &a11;
  a13 = arg3;
  LODWORD(arg3) = &a15;
  a15 = *(__int64 *)((char *)&arg5 + 4);
  HIDWORD(arg5) = &a21;
  a16 = arg5;
  LODWORD(arg5) = &arg4;
  idEventReceiver::ProcessEventArgs(
    this,
    result,
    ev: (const idEventDef *)HIDWORD(arg1),
    numargs: 5,
    a5: arg3,
    a6: arg5,
    a7: v31,
    a8: v32,
    a9: v33,
    a10: v34,
    a11: v35,
    a12: v36,
    a13: v37,
    a14: v38,
    a15: v39,
    a16: v40);
  return this;
}


// ========================================================================
// ?ProcessEvent@idEventReceiver@@QAA?AVidEventArg@@ABVidEventDef@@V2@11111@Z
// EA  : 0x82D60BE8
// RVA : 0x00D60BE8
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idEventReceiver *__fastcall idEventReceiver::ProcessEvent(
        idEventReceiver *this,
        idEventReceiver *result,
        __int64 arg1,
        __int64 arg3,
        __int64 arg5,
        const idEventArg *arg6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int arg3a,
        int arg3_4,
        int arg3_8,
        int arg3_12,
        int arg3_16,
        int a28,
        int arg4,
        int arg4_4,
        int arg4_8,
        int arg4_12,
        int arg4_16,
        int a34,
        int arg5a,
        int arg5_4,
        int arg5_8)
{
  __int64 v37; // r10
  int v40; // [sp+8h] [-138h]
  int v41; // [sp+Ch] [-134h]
  int v42; // [sp+10h] [-130h]
  int v43; // [sp+14h] [-12Ch]
  int v44; // [sp+18h] [-128h]
  int v45; // [sp+1Ch] [-124h]
  int v46; // [sp+20h] [-120h]
  int v47; // [sp+24h] [-11Ch]
  int v48; // [sp+28h] [-118h]
  int v49; // [sp+2Ch] [-114h]

  a11 = arg1;
  a12 = *(__int64 *)((char *)&arg3 + 4);
  HIDWORD(arg3) = &a11;
  a13 = arg3;
  LODWORD(arg3) = &a15;
  a15 = *(__int64 *)((char *)&arg5 + 4);
  HIDWORD(arg5) = &arg5_8;
  a16 = arg5;
  LODWORD(v37) = &arg4;
  HIDWORD(v37) = &a21;
  idEventReceiver::ProcessEventArgs(
    this,
    result,
    ev: (const idEventDef *)HIDWORD(arg1),
    numargs: 6,
    a5: arg3,
    a6: v37,
    a7: v40,
    a8: v41,
    a9: v42,
    a10: v43,
    a11: v44,
    a12: v45,
    a13: v46,
    a14: v47,
    a15: v48,
    a16: v49);
  return this;
}


// ========================================================================
// ?ProcessEvent@idEventReceiver@@QAA?AVidEventArg@@ABVidEventDef@@V2@111111@Z
// EA  : 0x82D60C50
// RVA : 0x00D60C50
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idEventReceiver *__fastcall idEventReceiver::ProcessEvent(
        idEventReceiver *this,
        idEventReceiver *result,
        __int64 arg1,
        __int64 arg3,
        __int64 arg5,
        const idEventArg *arg6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int arg3a,
        int arg3_4,
        int arg3_8,
        int arg3_12,
        int arg3_16,
        int a28,
        int arg4,
        int arg4_4,
        int arg4_8,
        int arg4_12,
        int arg4_16,
        int a34,
        int arg5a,
        int arg5_4,
        int arg5_8)
{
  __int64 v38; // r10
  int v41; // [sp+8h] [-158h]
  int v42; // [sp+Ch] [-154h]
  int v43; // [sp+10h] [-150h]
  int v44; // [sp+14h] [-14Ch]
  int v45; // [sp+18h] [-148h]
  int v46; // [sp+1Ch] [-144h]
  int v47; // [sp+20h] [-140h]
  int v48; // [sp+24h] [-13Ch]
  int v49; // [sp+28h] [-138h]
  int v50; // [sp+2Ch] [-134h]

  a11 = arg1;
  a12 = *(__int64 *)((char *)&arg3 + 4);
  HIDWORD(arg3) = &a11;
  a13 = arg3;
  LODWORD(arg3) = &a15;
  a15 = *(__int64 *)((char *)&arg5 + 4);
  HIDWORD(arg5) = &arg5_8;
  a16 = arg5;
  HIDWORD(v38) = &a21;
  LODWORD(v38) = &arg4;
  idEventReceiver::ProcessEventArgs(
    this,
    result,
    ev: (const idEventDef *)HIDWORD(arg1),
    numargs: 7,
    a5: arg3,
    a6: v38,
    a7: v41,
    a8: v42,
    a9: v43,
    a10: v44,
    a11: v45,
    a12: v46,
    a13: v47,
    a14: v48,
    a15: v49,
    a16: v50);
  return this;
}


// ========================================================================
// ?ProcessEvent@idEventReceiver@@QAA?AVidEventArg@@ABVidEventDef@@V2@1111111@Z
// EA  : 0x82D60CC0
// RVA : 0x00D60CC0
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idEventReceiver *__fastcall idEventReceiver::ProcessEvent(
        idEventReceiver *this,
        idEventReceiver *result,
        __int64 arg1,
        __int64 arg3,
        __int64 arg5,
        const idEventArg *arg6,
        const idEventArg *arg7,
        const idEventArg *arg8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int arg3a,
        int arg3_4,
        int arg3_8,
        int arg3_12,
        int arg3_16,
        int a29,
        int arg4,
        int arg4_4,
        int arg4_8,
        int arg4_12,
        int arg4_16,
        int a35,
        int arg5a,
        int arg5_4,
        int arg5_8,
        int arg5_12,
        int arg5_16,
        int a41,
        int arg6a,
        int arg6_4,
        int arg6_8,
        int arg6_12,
        int arg6_16)
{
  __int64 v46; // r10
  int v49; // [sp+8h] [-178h]
  int v50; // [sp+Ch] [-174h]
  int v51; // [sp+10h] [-170h]
  int v52; // [sp+14h] [-16Ch]
  int v53; // [sp+18h] [-168h]
  int v54; // [sp+1Ch] [-164h]
  int v55; // [sp+20h] [-160h]
  int v56; // [sp+24h] [-15Ch]
  int v57; // [sp+28h] [-158h]
  int v58; // [sp+2Ch] [-154h]

  a12 = arg1;
  a13 = *(__int64 *)((char *)&arg3 + 4);
  HIDWORD(arg3) = &a12;
  a14 = arg3;
  LODWORD(arg3) = &arg5_8;
  a16 = *(__int64 *)((char *)&arg5 + 4);
  HIDWORD(arg5) = &arg6_16;
  a17 = arg5;
  HIDWORD(v46) = &a22;
  LODWORD(v46) = &arg4;
  LODWORD(arg3) = &a16;
  idEventReceiver::ProcessEventArgs(
    this,
    result,
    ev: (const idEventDef *)HIDWORD(arg1),
    numargs: 8,
    a5: arg3,
    a6: v46,
    a7: v49,
    a8: v50,
    a9: v51,
    a10: v52,
    a11: v53,
    a12: v54,
    a13: v55,
    a14: v56,
    a15: v57,
    a16: v58);
  return this;
}


// ========================================================================
// ?ProcessEventArgArray@idEventReceiver@@QAA?AVidEventArg@@ABVidEventDef@@HQBV2@@Z
// EA  : 0x82D60D38
// RVA : 0x00D60D38
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idEventReceiver *__fastcall idEventReceiver::ProcessEventArgArray(
        idEventReceiver *this,
        idEventReceiver *result,
        const idEventDef *ev,
        int numargs,
        __int64 args,
        __int64 a6)
{
  int v8; // r31
  __int64 v10; // r10
  _DWORD *v11; // r11
  int i; // ctr
  char *v13; // r10
  _DWORD *v14; // r11
  int j; // ctr
  __int64 v16; // r10
  _DWORD *v17; // r11
  int k; // ctr
  __int64 v19; // r8
  char *v20; // r10
  _DWORD *v21; // r11
  int m; // ctr
  char *v23; // r10
  _DWORD *v24; // r11
  int n; // ctr
  __int64 v26; // r10
  _DWORD *v27; // r11
  int ii; // ctr
  __int64 v29; // r8
  char *v30; // r10
  _DWORD *v31; // r11
  int jj; // ctr
  char *v33; // r10
  _DWORD *v34; // r11
  int kk; // ctr
  char *v36; // r10
  _DWORD *v37; // r11
  int mm; // ctr
  char *v39; // r10
  _DWORD *v40; // r11
  int nn; // ctr
  __int64 v42; // r10
  __int64 v43; // r8
  char *v44; // r10
  _DWORD *v45; // r11
  int i1; // ctr
  char *v47; // r10
  _DWORD *v48; // r11
  int i2; // ctr
  char *v50; // r10
  _DWORD *v51; // r11
  int i3; // ctr
  char *v53; // r10
  _DWORD *v54; // r11
  int i4; // ctr
  char *v56; // r10
  _DWORD *v57; // r11
  int i5; // ctr
  __int64 v59; // r10
  __int64 v60; // r8
  __int128 v61; // r7 OVERLAPPED
  __int64 v62; // r9
  __int128 v63; // r7 OVERLAPPED
  __int64 v64; // r9
  __int128 v65; // r7 OVERLAPPED
  __int64 v66; // r9
  const idEventArg *v67; // [sp+8h] [-1E8h]
  const idEventArg *v68; // [sp+Ch] [-1E4h]
  __int64 v69; // [sp+10h] [-1E0h]
  __int64 v70; // [sp+18h] [-1D8h]
  __int64 v71; // [sp+20h] [-1D0h]
  __int64 v72; // [sp+28h] [-1C8h]
  __int64 v73; // [sp+30h] [-1C0h]
  __int64 v74; // [sp+38h] [-1B8h]
  __int64 v75; // [sp+40h] [-1B0h]
  __int64 v76; // [sp+48h] [-1A8h]
  __int64 v77; // [sp+50h] [-1A0h]
  __int64 v78; // [sp+58h] [-198h]
  int v79; // [sp+64h] [-18Ch]
  int v80; // [sp+68h] [-188h]
  int v81; // [sp+6Ch] [-184h]
  int v82[5]; // [sp+70h] [-180h] BYREF
  int v83; // [sp+84h] [-16Ch]
  int v84; // [sp+88h] [-168h]
  int v85; // [sp+8Ch] [-164h]
  int v86[5]; // [sp+90h] [-160h] BYREF
  int v87; // [sp+A4h] [-14Ch]
  int v88; // [sp+A8h] [-148h]
  int v89; // [sp+ACh] [-144h]
  int v90[8]; // [sp+B0h] [-140h] BYREF
  int v91[8]; // [sp+D0h] [-120h] BYREF
  _BYTE v92[20]; // [sp+F0h] [-100h] BYREF
  _BYTE v93[20]; // [sp+110h] [-E0h] BYREF
  char v94; // [sp+12Ch] [-C4h] BYREF
  _BYTE v95[28]; // [sp+130h] [-C0h] BYREF
  char v96; // [sp+14Ch] [-A4h] BYREF
  _BYTE v97[28]; // [sp+150h] [-A0h] BYREF
  char v98; // [sp+16Ch] [-84h] BYREF
  _BYTE v99[28]; // [sp+170h] [-80h] BYREF
  char v100; // [sp+18Ch] [-64h] BYREF
  char v101; // [sp+190h] [-60h] BYREF
  char v102; // [sp+1ACh] [-44h] BYREF
  char v103; // [sp+1B0h] [-40h] BYREF

  v8 = HIDWORD(args);
  if ( numargs != 0 )
  {
    switch ( numargs )
    {
      case 1:
        LODWORD(v10) = &v94;
        v11 = (_DWORD *)(HIDWORD(args) - 4);
        for ( i = 5; i != 0; --i )
        {
          HIDWORD(v10) = *++v11;
          LODWORD(v10) = v10 + 4;
          *(_DWORD *)v10 = *v11;
        }
        HIDWORD(args) = v95;
        idEventReceiver::ProcessEventArgs(
          this,
          result,
          ev,
          numargs: 1,
          a5: args,
          a6: v10,
          a7: (int)v67,
          a8: (int)v68,
          a9: SHIDWORD(v69),
          a10: v69,
          a11: SHIDWORD(v70),
          a12: v70,
          a13: SHIDWORD(v71),
          a14: v71,
          a15: SHIDWORD(v72),
          a16: v72);
        return this;
      case 2:
        v13 = &v94;
        v14 = (_DWORD *)(HIDWORD(args) + 16);
        for ( j = 5; j != 0; --j )
        {
          ++v14;
          v13 += 4;
          *(_DWORD *)v13 = *v14;
        }
        LODWORD(v16) = &v96;
        v17 = (_DWORD *)(HIDWORD(args) - 4);
        for ( k = 5; k != 0; --k )
        {
          HIDWORD(v16) = *++v17;
          LODWORD(v16) = v16 + 4;
          *(_DWORD *)v16 = *v17;
        }
        LODWORD(v19) = v95;
        HIDWORD(v19) = v97;
        idEventReceiver::ProcessEventArgs(
          this,
          result,
          ev,
          numargs: 2,
          a5: v19,
          a6: v16,
          a7: (int)v67,
          a8: (int)v68,
          a9: SHIDWORD(v69),
          a10: v69,
          a11: SHIDWORD(v70),
          a12: v70,
          a13: SHIDWORD(v71),
          a14: v71,
          a15: SHIDWORD(v72),
          a16: v72);
        return this;
      case 3:
        v20 = &v96;
        v21 = (_DWORD *)(HIDWORD(args) + 36);
        for ( m = 5; m != 0; --m )
        {
          ++v21;
          v20 += 4;
          *(_DWORD *)v20 = *v21;
        }
        v23 = &v94;
        v24 = (_DWORD *)(HIDWORD(args) + 16);
        for ( n = 5; n != 0; --n )
        {
          ++v24;
          v23 += 4;
          *(_DWORD *)v23 = *v24;
        }
        LODWORD(v26) = &v98;
        v27 = (_DWORD *)(HIDWORD(args) - 4);
        for ( ii = 5; ii != 0; --ii )
        {
          ++v27;
          LODWORD(v26) = v26 + 4;
          *(_DWORD *)v26 = *v27;
        }
        HIDWORD(v26) = v97;
        LODWORD(v29) = v95;
        HIDWORD(v29) = v99;
        idEventReceiver::ProcessEventArgs(
          this,
          result,
          ev,
          numargs: 3,
          a5: v29,
          a6: v26,
          a7: (int)v67,
          a8: (int)v68,
          a9: SHIDWORD(v69),
          a10: v69,
          a11: SHIDWORD(v70),
          a12: v70,
          a13: SHIDWORD(v71),
          a14: v71,
          a15: SHIDWORD(v72),
          a16: v72);
        return this;
      case 4:
        v30 = &v98;
        v31 = (_DWORD *)(HIDWORD(args) + 56);
        for ( jj = 5; jj != 0; --jj )
        {
          ++v31;
          v30 += 4;
          *(_DWORD *)v30 = *v31;
        }
        v33 = &v96;
        v34 = (_DWORD *)(HIDWORD(args) + 36);
        for ( kk = 5; kk != 0; --kk )
        {
          ++v34;
          v33 += 4;
          *(_DWORD *)v33 = *v34;
        }
        v36 = &v94;
        v37 = (_DWORD *)(HIDWORD(args) + 16);
        for ( mm = 5; mm != 0; --mm )
        {
          ++v37;
          v36 += 4;
          *(_DWORD *)v36 = *v37;
        }
        v39 = &v100;
        v40 = (_DWORD *)(HIDWORD(args) - 4);
        for ( nn = 5; nn != 0; --nn )
        {
          ++v40;
          v39 += 4;
          *(_DWORD *)v39 = *v40;
        }
        LODWORD(v42) = v99;
        HIDWORD(v42) = v97;
        LODWORD(v43) = v95;
        HIDWORD(v43) = &v101;
        idEventReceiver::ProcessEventArgs(
          this,
          result,
          ev,
          numargs: 4,
          a5: v43,
          a6: v42,
          a7: (int)v67,
          a8: (int)v68,
          a9: SHIDWORD(v69),
          a10: v69,
          a11: SHIDWORD(v70),
          a12: v70,
          a13: SHIDWORD(v71),
          a14: v71,
          a15: SHIDWORD(v72),
          a16: v72);
        return this;
      case 5:
        v44 = &v100;
        v45 = (_DWORD *)(HIDWORD(args) + 76);
        for ( i1 = 5; i1 != 0; --i1 )
        {
          ++v45;
          v44 += 4;
          *(_DWORD *)v44 = *v45;
        }
        v47 = &v98;
        v48 = (_DWORD *)(HIDWORD(args) + 56);
        for ( i2 = 5; i2 != 0; --i2 )
        {
          ++v48;
          v47 += 4;
          *(_DWORD *)v47 = *v48;
        }
        v50 = &v96;
        v51 = (_DWORD *)(HIDWORD(args) + 36);
        for ( i3 = 5; i3 != 0; --i3 )
        {
          ++v51;
          v50 += 4;
          *(_DWORD *)v50 = *v51;
        }
        v53 = &v94;
        v54 = (_DWORD *)(HIDWORD(args) + 16);
        for ( i4 = 5; i4 != 0; --i4 )
        {
          ++v54;
          v53 += 4;
          *(_DWORD *)v53 = *v54;
        }
        v56 = &v102;
        v57 = (_DWORD *)(HIDWORD(args) - 4);
        for ( i5 = 5; i5 != 0; --i5 )
        {
          ++v57;
          v56 += 4;
          *(_DWORD *)v56 = *v57;
        }
        LODWORD(v59) = v99;
        HIDWORD(v59) = v97;
        LODWORD(v60) = v95;
        HIDWORD(v60) = &v103;
        idEventReceiver::ProcessEventArgs(
          this,
          result,
          ev,
          numargs: 5,
          a5: v60,
          a6: v59,
          a7: (int)v67,
          a8: (int)v68,
          a9: SHIDWORD(v69),
          a10: v69,
          a11: SHIDWORD(v70),
          a12: v70,
          a13: SHIDWORD(v71),
          a14: v71,
          a15: SHIDWORD(v72),
          a16: v72);
        return this;
      case 6:
        memcpy(Dst: v91, Src: (const void *)(HIDWORD(args) + 100), Size: 0x14u);
        memcpy(Dst: v90, Src: (const void *)(v8 + 80), Size: 0x14u);
        memcpy(Dst: v86, Src: (const void *)(v8 + 60), Size: sizeof(v86));
        memcpy(Dst: v82, Src: (const void *)(v8 + 40), Size: sizeof(v82));
        *(_QWORD *)((char *)&v61 + 4) = *(_QWORD *)v8;
        *((_QWORD *)&v61 + 1) = *(_QWORD *)(v8 + 8);
        v62 = *(_QWORD *)(v8 + 20);
        idEventReceiver::ProcessEvent(
          this,
          result,
          arg1: *(__int64 *)((char *)&v61 + 4),
          arg3: *(__int64 *)((char *)&v61 - 4),
          arg5: *(_QWORD *)(v8 + 28),
          arg6: v67,
          a7: v69,
          a8: v70,
          a9: v71,
          a10: v72,
          a11: v73,
          a12: v74,
          a13: v75,
          a14: v76,
          a15: v77,
          a16: v78,
          a17: *(_DWORD *)(v8 + 36),
          a18: v79,
          a19: v80,
          a20: v81,
          a21: v82[0],
          a22: v82[1],
          arg3a: v82[2],
          arg3_4: v82[3],
          arg3_8: v82[4],
          arg3_12: v83,
          arg3_16: v84,
          a28: v85,
          arg4: v86[0],
          arg4_4: v86[1],
          arg4_8: v86[2],
          arg4_12: v86[3],
          arg4_16: v86[4],
          a34: v87,
          arg5a: v88,
          arg5_4: v89,
          arg5_8: v90[0]);
        return this;
      case 7:
        memcpy(Dst: v92, Src: (const void *)(HIDWORD(args) + 120), Size: sizeof(v92));
        memcpy(Dst: v91, Src: (const void *)(v8 + 100), Size: 0x14u);
        memcpy(Dst: v90, Src: (const void *)(v8 + 80), Size: 0x14u);
        memcpy(Dst: v86, Src: (const void *)(v8 + 60), Size: sizeof(v86));
        memcpy(Dst: v82, Src: (const void *)(v8 + 40), Size: sizeof(v82));
        *(_QWORD *)((char *)&v63 + 4) = *(_QWORD *)v8;
        *((_QWORD *)&v63 + 1) = *(_QWORD *)(v8 + 8);
        v64 = *(_QWORD *)(v8 + 20);
        idEventReceiver::ProcessEvent(
          this,
          result,
          arg1: *(__int64 *)((char *)&v63 + 4),
          arg3: *(__int64 *)((char *)&v63 - 4),
          arg5: *(_QWORD *)(v8 + 28),
          arg6: v67,
          a7: v69,
          a8: v70,
          a9: v71,
          a10: v72,
          a11: v73,
          a12: v74,
          a13: v75,
          a14: v76,
          a15: v77,
          a16: v78,
          a17: *(_DWORD *)(v8 + 36),
          a18: v79,
          a19: v80,
          a20: v81,
          a21: v82[0],
          a22: v82[1],
          arg3a: v82[2],
          arg3_4: v82[3],
          arg3_8: v82[4],
          arg3_12: v83,
          arg3_16: v84,
          a28: v85,
          arg4: v86[0],
          arg4_4: v86[1],
          arg4_8: v86[2],
          arg4_12: v86[3],
          arg4_16: v86[4],
          a34: v87,
          arg5a: v88,
          arg5_4: v89,
          arg5_8: v90[0]);
        return this;
      case 8:
        memcpy(Dst: v93, Src: (const void *)(HIDWORD(args) + 140), Size: sizeof(v93));
        memcpy(Dst: v92, Src: (const void *)(v8 + 120), Size: sizeof(v92));
        memcpy(Dst: v91, Src: (const void *)(v8 + 100), Size: 0x14u);
        memcpy(Dst: v90, Src: (const void *)(v8 + 80), Size: 0x14u);
        memcpy(Dst: v86, Src: (const void *)(v8 + 60), Size: sizeof(v86));
        memcpy(Dst: v82, Src: (const void *)(v8 + 40), Size: sizeof(v82));
        *(_QWORD *)((char *)&v65 + 4) = *(_QWORD *)v8;
        *((_QWORD *)&v65 + 1) = *(_QWORD *)(v8 + 8);
        v66 = *(_QWORD *)(v8 + 20);
        idEventReceiver::ProcessEvent(
          this,
          result,
          arg1: *(__int64 *)((char *)&v65 + 4),
          arg3: *(__int64 *)((char *)&v65 - 4),
          arg5: *(_QWORD *)(v8 + 28),
          arg6: v67,
          arg7: v68,
          arg8: (const idEventArg *)HIDWORD(v69),
          a9: v70,
          a10: v71,
          a11: v72,
          a12: v73,
          a13: v74,
          a14: v75,
          a15: v76,
          a16: v77,
          a17: v78,
          a18: *(_DWORD *)(v8 + 36),
          a19: v79,
          a20: v80,
          a21: v81,
          a22: v82[0],
          a23: v82[1],
          arg3a: v82[2],
          arg3_4: v82[3],
          arg3_8: v82[4],
          arg3_12: v83,
          arg3_16: v84,
          a29: v85,
          arg4: v86[0],
          arg4_4: v86[1],
          arg4_8: v86[2],
          arg4_12: v86[3],
          arg4_16: v86[4],
          a35: v87,
          arg5a: v88,
          arg5_4: v89,
          arg5_8: v90[0],
          arg5_12: v90[1],
          arg5_16: v90[2],
          a41: v90[3],
          arg6a: v90[4],
          arg6_4: v90[5],
          arg6_8: v90[6],
          arg6_12: v90[7],
          arg6_16: v91[0]);
        return this;
      default:
        idLib::Warning(fmt: "Unhandled Arg Count");
        HIBYTE(this->__vftable) = 0;
        this->listenerList = nullptr;
        return this;
    }
  }
  else
  {
    idEventReceiver::ProcessEventArgs(
      this,
      result,
      ev,
      numargs: 0,
      a5: args,
      a6,
      a7: (int)v67,
      a8: (int)v68,
      a9: SHIDWORD(v69),
      a10: v69,
      a11: SHIDWORD(v70),
      a12: v70,
      a13: SHIDWORD(v71),
      a14: v71,
      a15: SHIDWORD(v72),
      a16: v72);
    return this;
  }
}


// ========================================================================
// ??1idEventReceiver@@UAA@XZ
// EA  : 0x82D61200
// RVA : 0x00D61200
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

void __fastcall idEventReceiver::~idEventReceiver(idEventReceiver *this)
{
  idList<idEventReceiver *,5> *listeningToList; // r28
  int v3; // r29
  int v4; // r30
  idList<idEntityPtr<idEntity>,58> *listenerList; // r3
  int num; // r9
  int v7; // r4
  int v8; // r11
  idList<idEventReceiver *,5> *v9; // r30
  idList<idEventReceiver *,5> *v10; // r4
  int v11; // r5
  int v12; // r6
  idList<idEventReceiver *,5> *v13; // r11
  int v14; // r7
  int v15; // r10
  int v16; // r9
  int v17; // r9
  idEventReceiver **v18; // r8
  idList<idEventReceiver *,5> *v19; // r30

  this->__vftable = (idEventReceiver_vtbl *)&idEventReceiver::`vftable';
  if ( clientGame != nullptr )
    idEventSystem::CancelEvents(this: &clientGame->eventSystem, obj: this, evdef: nullptr);
  listeningToList = this->listeningToList;
  if ( listeningToList != nullptr )
  {
    v3 = listeningToList->num - 1;
    if ( v3 >= 0 )
    {
      v4 = v3;
      do
      {
        listenerList = (idList<idEntityPtr<idEntity>,58> *)listeningToList->list[v4]->listenerList;
        if ( listenerList != nullptr )
        {
          num = listenerList->num;
          v7 = 0;
          if ( num > 0 )
          {
            v8 = 0;
            while ( (idEventReceiver *)listenerList->list[v8].spawnId.value != this )
            {
              ++v7;
              ++v8;
              if ( v7 >= num )
                goto LABEL_14;
            }
            if ( v7 >= 0 )
              idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: listenerList, index: v7);
          }
        }
LABEL_14:
        --v3;
        --v4;
      }
      while ( v3 >= 0 );
    }
    v9 = this->listeningToList;
    if ( v9 != nullptr )
    {
      if ( v9->listStatic == 0 || v9->listStatic == 2 )
      {
        if ( v9->list != nullptr )
          idMem::Free(this: &mem, ptr: v9->list, align: ALIGN_16);
        v9->list = nullptr;
        v9->size = 0;
      }
      v9->num = 0;
      idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
    }
    this->listeningToList = nullptr;
  }
  v10 = this->listenerList;
  if ( v10 != nullptr )
  {
    v11 = v10->num - 1;
    if ( v11 >= 0 )
    {
      v12 = v11;
      do
      {
        v13 = v10->list[v12]->listeningToList;
        if ( v13 != nullptr )
        {
          v14 = v13->num;
          v15 = 0;
          if ( v14 > 0 )
          {
            v16 = 0;
            while ( v13->list[v16] != this )
            {
              ++v15;
              ++v16;
              if ( v15 >= v13->num )
                goto LABEL_37;
            }
            if ( v15 >= 0 && v15 < v14 )
            {
              v13->num = v14 - 1;
              if ( v15 < v14 - 1 )
              {
                v17 = v15;
                do
                {
                  ++v15;
                  v18 = &v13->list[v17++];
                  *v18 = v18[1];
                }
                while ( v15 < v13->num );
              }
            }
          }
        }
LABEL_37:
        --v11;
        --v12;
      }
      while ( v11 >= 0 );
    }
    v19 = this->listenerList;
    if ( v19 != nullptr )
    {
      if ( v19->listStatic == 0 || v19->listStatic == 2 )
      {
        if ( v19->list != nullptr )
          idMem::Free(this: &mem, ptr: v19->list, align: ALIGN_16);
        v19->list = nullptr;
        v19->size = 0;
      }
      v19->num = 0;
      idMem::Free(this: &mem, ptr: v19, align: ALIGN_16);
    }
  }
  this->__vftable = (idEventReceiver_vtbl *)&idClass::`vftable';
}


// ========================================================================
// __unwind$489677
// EA  : 0x82D6145C
// RVA : 0x00D6145C
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

void _unwind_489677()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 160 + 180));
}


// ========================================================================
// ?AddListeningTo@idEventReceiver@@AAAXPAV1@@Z
// EA  : 0x82D614F0
// RVA : 0x00D614F0
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

void __fastcall idEventReceiver::AddListeningTo(
        idEventReceiver *this,
        idEventReceiver *listeningTo,
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
        idEventReceiver *a14)
{
  idList<idEventReceiver *,5> *listeningToList; // r11
  idList<idDeclVehicleUpgrade const *,5> *v17; // r3
  idList<idEventReceiver *,5> *v18; // r3
  idList<enum encounterGroupRole_t,5> *v19; // r3
  int v20; // r10
  int num; // r9
  int v22; // r11

  listeningToList = this->listeningToList;
  a14 = listeningTo;
  if ( listeningToList == nullptr )
  {
    v17 = (idList<idDeclVehicleUpgrade const *,5> *)idMem::AllocWithLocation(
                                                      this: &mem,
                                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                      size: 0x10u,
                                                      tag: TAG_EVENT_LISTENER,
                                                      zeroBuffer: false,
                                                      align: ALIGN_16,
                                                      heap: HEAP_DEFAULTHEAP);
    if ( v17 != nullptr )
      v18 = (idList<idEventReceiver *,5> *)idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: v17);
    else
      v18 = nullptr;
    this->listeningToList = v18;
  }
  v19 = (idList<enum encounterGroupRole_t,5> *)this->listeningToList;
  v20 = 0;
  num = v19->num;
  if ( num <= 0 )
    goto LABEL_12;
  v22 = 0;
  while ( (idEventReceiver *)v19->list[v22] != listeningTo )
  {
    ++v20;
    ++v22;
    if ( v20 >= num )
      goto LABEL_12;
  }
  if ( v20 < 0 )
LABEL_12:
    idList<idAnimWebBlendTree *,5>::Append(this: v19, obj: (encounterGroupRole_t *)&a14);
}


// ========================================================================
// __unwind$489947
// EA  : 0x82D615B0
// RVA : 0x00D615B0
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

void _unwind_489947()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_EVENT_LISTENER);
}


// ========================================================================
// ?ProcessAnimEvents@idEventReceiver@@QAAXAAVidAnimEventHandler@@@Z
// EA  : 0x82D615E8
// RVA : 0x00D615E8
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

void __fastcall idEventReceiver::ProcessAnimEvents(idEventReceiver *this, idAnimEventHandler *handler)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  const idEventDef *EventCommand; // r3
  idMD6AnimEvent *v7; // r28
  const idEventDef *v8; // r17
  int *v9; // r10
  int v10; // ctr
  _DWORD *v11; // r11
  int v12; // r30
  _DWORD *v13; // r29
  _DWORD *v14; // r10
  _DWORD *v15; // r9
  int i; // ctr
  _DWORD *v17; // r10
  _DWORD *v18; // r9
  int v19; // ctr
  _DWORD *v20; // r10
  _DWORD *v21; // r9
  int v22; // ctr
  float *v23; // r10
  _DWORD *v24; // r9
  int j; // ctr
  float *v26; // r10
  _DWORD *v27; // r9
  int v28; // ctr
  float *p_w; // r10
  _DWORD *v30; // r9
  int v31; // ctr
  float *v32; // r10
  _DWORD *v33; // r9
  int v34; // ctr
  float *v35; // r10
  _DWORD *v36; // r9
  int v37; // ctr
  _DWORD *v38; // r10
  _DWORD *v39; // r9
  int v40; // ctr
  idEventArg *v41; // r3
  _DWORD *v42; // r10
  _DWORD *v43; // r11
  int k; // ctr
  _DWORD *v45; // r10
  _DWORD *v46; // r9
  int v47; // ctr
  _DWORD *v48; // r10
  _DWORD *v49; // r9
  int v50; // ctr
  idPLog *pLog; // r29
  idPLog::logEntry_t *v52; // r30
  int v53; // r3
  __int64 totalTicks; // r11
  __int64 v55; // r9
  char v56; // [sp+50h] [-340h] BYREF
  bool v57; // [sp+51h] [-33Fh] BYREF
  idMD6AnimEvent *v58; // [sp+54h] [-33Ch] BYREF
  const idMD6Anim *v59; // [sp+58h] [-338h] BYREF
  const char *v60; // [sp+5Ch] [-334h] BYREF
  int v61; // [sp+60h] [-330h] BYREF
  float v62; // [sp+64h] [-32Ch] BYREF
  int numargs; // [sp+68h] [-328h]
  const idEntity *v64; // [sp+6Ch] [-324h] BYREF
  int v65; // [sp+70h] [-320h] BYREF
  void *v66; // [sp+74h] [-31Ch] BYREF
  idPLogScope v67; // [sp+78h] [-318h] BYREF
  idVec3 v68; // [sp+80h] [-310h] BYREF
  idAngles v69; // [sp+90h] [-300h] BYREF
  idQuat v70; // [sp+A0h] [-2F0h] BYREF
  char v71; // [sp+B0h] [-2E0h]
  float x; // [sp+B4h] [-2DCh]
  float y; // [sp+B8h] [-2D8h]
  float z; // [sp+BCh] [-2D4h]
  float w; // [sp+C0h] [-2D0h]
  float v76[8]; // [sp+CCh] [-2C4h] BYREF
  float v77[9]; // [sp+ECh] [-2A4h] BYREF
  idVec4 v78; // [sp+110h] [-280h] BYREF
  char v79; // [sp+120h] [-270h]
  float v80; // [sp+124h] [-26Ch]
  float v81; // [sp+128h] [-268h]
  float v82; // [sp+12Ch] [-264h]
  _DWORD v83[8]; // [sp+13Ch] [-254h] BYREF
  _DWORD v84[8]; // [sp+15Ch] [-234h] BYREF
  _DWORD v85[8]; // [sp+17Ch] [-214h] BYREF
  _DWORD v86[8]; // [sp+19Ch] [-1F4h] BYREF
  _DWORD v87[8]; // [sp+1BCh] [-1D4h] BYREF
  _DWORD v88[8]; // [sp+1DCh] [-1B4h] BYREF
  _DWORD v89[8]; // [sp+1FCh] [-194h] BYREF
  float v90[8]; // [sp+21Ch] [-174h] BYREF
  int v91; // [sp+23Ch] [-154h] BYREF
  idAICover v92; // [sp+240h] [-150h] BYREF
  _DWORD v93[35]; // [sp+254h] [-13Ch] BYREF
  idEventArg v94[8]; // [sp+2E0h] [-B0h] BYREF

  RD_EventBegin(name: "idEventReceiver::ProcessAnimEvents");
  LODWORD(v4) = "idEventReceiver::ProcessAnimEvents";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: &v67, pl: &::pLog, gMask: v4, label: v5);
  v58 = nullptr;
  while ( (unsigned __int8)idAnimEventHandler::FetchNextEvent(
                             this: handler,
                             animHandle: &v59,
                             ev: (const idMD6AnimEvent **)&v58) != 0 )
  {
    EventCommand = idEventDef::GetEventCommand(eventnum: v58->eventNum);
    v7 = v58;
    v8 = EventCommand;
    numargs = EventCommand->numargs;
    if ( numargs >= 1 && numargs <= 8 )
    {
      v9 = &v91;
      HIBYTE(v93[0]) = 0;
      v93[1] = 0;
      HIBYTE(v93[5]) = 0;
      v93[6] = 0;
      v10 = 5;
      HIBYTE(v93[10]) = 0;
      v93[11] = 0;
      v11 = v89;
      HIBYTE(v93[15]) = 0;
      v93[16] = 0;
      HIBYTE(v93[20]) = 0;
      v93[21] = 0;
      HIBYTE(v93[25]) = 0;
      v93[26] = 0;
      HIBYTE(v93[30]) = 0;
      v93[31] = 0;
      HIBYTE(v89[1]) = 52;
      v89[2] = v59;
      do
      {
        *++v9 = *++v11;
        --v10;
      }
      while ( v10 != 0 );
      v12 = 0;
      if ( v7->args.numArgs != 0 )
      {
        v13 = v93;
        do
        {
          switch ( v7->args.argTypes[v12] )
          {
            case 1u:
              idVarArgs<4>::GetArg(this: &v7->args, index: v12, val: &v57);
              HIBYTE(v85[1]) = 105;
              v14 = v85;
              v15 = v13 - 1;
              v85[2] = v57;
              for ( i = 5; i != 0; --i )
                *++v15 = *++v14;
              break;
            case 2u:
              idVarArgs<4>::GetArg(this: &v7->args, index: v12, val: &v56);
              v17 = v83;
              HIBYTE(v83[1]) = 105;
              v18 = v13 - 1;
              v19 = 5;
              v83[2] = v56;
              do
              {
                *++v18 = *++v17;
                --v19;
              }
              while ( v19 != 0 );
              break;
            case 3u:
              idVarArgs<4>::GetArg(this: &v7->args, index: v12, val: &v65);
              v20 = v87;
              HIBYTE(v87[1]) = 105;
              v21 = v13 - 1;
              v22 = 5;
              v87[2] = v65;
              do
              {
                *++v21 = *++v20;
                --v22;
              }
              while ( v22 != 0 );
              break;
            case 4u:
              idVarArgs<4>::GetArg(this: &v7->args, index: v12, val: &v62);
              v23 = v90;
              v90[2] = v62;
              HIBYTE(v90[1]) = 102;
              v24 = v13 - 1;
              for ( j = 5; j != 0; --j )
                *++v24 = *(_DWORD *)++v23;
              break;
            case 5u:
              idVarArgs<4>::GetArg(this: &v7->args, index: v12, val: &v68);
              v26 = v76;
              HIBYTE(v76[1]) = 118;
              v27 = v13 - 1;
              v76[2] = v68.x;
              v76[3] = v68.y;
              v28 = 5;
              v76[4] = v68.z;
              do
              {
                *++v27 = *(_DWORD *)++v26;
                --v28;
              }
              while ( v28 != 0 );
              break;
            case 6u:
              idVarArgs<4>::GetArg(this: &v7->args, index: v12, val: &v70);
              p_w = &v70.w;
              v71 = 113;
              v30 = v13 - 1;
              x = v70.x;
              v31 = 5;
              y = v70.y;
              z = v70.z;
              w = v70.w;
              do
              {
                *++v30 = *(_DWORD *)++p_w;
                --v31;
              }
              while ( v31 != 0 );
              break;
            case 7u:
              idVarArgs<4>::GetArg(this: &v7->args, index: v12, val: &v69);
              v32 = v77;
              HIBYTE(v77[1]) = 97;
              v33 = v13 - 1;
              v77[2] = v69.pitch;
              v77[3] = v69.yaw;
              v34 = 5;
              v77[4] = v69.roll;
              do
              {
                *++v33 = *(_DWORD *)++v32;
                --v34;
              }
              while ( v34 != 0 );
              break;
            case 8u:
              idVarArgs<4>::GetArg(this: &v7->args, index: v12, val: &v60);
              v38 = v84;
              HIBYTE(v84[1]) = 115;
              v39 = v13 - 1;
              v40 = 5;
              v84[2] = v60;
              do
              {
                *++v39 = *++v38;
                --v40;
              }
              while ( v40 != 0 );
              break;
            case 9u:
              idVarArgs<4>::GetArg(this: &v7->args, index: v12, ptr: &v66);
              v45 = v86;
              HIBYTE(v86[1]) = 100;
              v46 = v13 - 1;
              v47 = 5;
              v86[2] = v66;
              do
              {
                *++v46 = *++v45;
                --v47;
              }
              while ( v47 != 0 );
              break;
            case 0xAu:
              idVarArgs<4>::GetArg(this: &v7->args, index: v12, ptr: (void **)&v64);
              v41 = idEventArg::idEventArg(this: v94, data: v64);
              v42 = v13 - 1;
              v43 = (_DWORD *)&v41[-1].value.q[3];
              for ( k = 5; k != 0; --k )
                *++v42 = *++v43;
              break;
            case 0xCu:
              idVarArgs<4>::GetArg(this: &v7->args, index: v12, val: &v78);
              v35 = &v78.w;
              v79 = 118;
              v36 = v13 - 1;
              v80 = v78.x;
              v81 = v78.y;
              v37 = 5;
              v82 = v78.z;
              do
              {
                *++v36 = *(_DWORD *)++v35;
                --v37;
              }
              while ( v37 != 0 );
              break;
            case 0xDu:
              idVarArgs<4>::GetHandleArg(this: &v7->args, index: v12, val: &v61, type: 0xDu);
              v48 = v88;
              HIBYTE(v88[1]) = 51;
              v49 = v13 - 1;
              v50 = 5;
              v88[2] = (unsigned __int16)v61;
              do
              {
                *++v49 = *++v48;
                --v50;
              }
              while ( v50 != 0 );
              break;
            default:
              break;
          }
          ++v12;
          v13 += 5;
        }
        while ( v12 < v7->args.numArgs );
      }
      idEventReceiver::ProcessEventArgPtr(this: (idEventReceiver *)v94, result: this, ev: v8, args: &v92);
    }
  }
  if ( v67.logIndex >= 0 )
  {
    pLog = v67.pLog;
    v52 = &v67.pLog->logEntries.list[v67.logIndex];
    v53 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v52->totalTicks;
    HIDWORD(totalTicks) = v52->parent;
    LODWORD(v55) = v53 - totalTicks;
    v52->totalTicks = v55;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$490022
// EA  : 0x82D61B20
// RVA : 0x00D61B20
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

void _unwind_490022()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 912 + 756));
}


// ========================================================================
// __unwind$490023
// EA  : 0x82D61B48
// RVA : 0x00D61B48
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

void _unwind_490023()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 912 + 120));
}


// ========================================================================
// ?AddEventListener@idEventReceiver@@QAAXPAV1@@Z
// EA  : 0x82D61B70
// RVA : 0x00D61B70
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.cpp
// ========================================================================

void __fastcall idEventReceiver::AddEventListener(
        idEventReceiver *this,
        idVoiceEvent *listener,
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
        const idVoiceEvent *a14)
{
  idList<idEventReceiver *,5> *listenerList; // r3
  int v17; // r10
  int v18; // r9
  int v19; // r8
  int v20; // r7
  int v21; // r6
  int v22; // r5
  int v23; // [sp+8h] [-68h]
  int v24; // [sp+Ch] [-64h]
  int v25; // [sp+10h] [-60h]
  int v26; // [sp+14h] [-5Ch]
  int v27; // [sp+18h] [-58h]
  idEventReceiver *v28; // [sp+1Ch] [-54h]

  a14 = listener;
  idEventReceiver::AllocListenerList(this);
  listenerList = this->listenerList;
  if ( listenerList != nullptr )
  {
    idList<idDeclMD6 const *,5>::AddUnique(this: (idList<idVoiceEvent const *,5> *)listenerList, obj: &a14);
    idEventReceiver::AddListeningTo(
      this: (idEventReceiver *)listener,
      listeningTo: this,
      a3: v22,
      a4: v21,
      a5: v20,
      a6: v19,
      a7: v18,
      a8: v17,
      a9: v23,
      a10: v24,
      a11: v25,
      a12: v26,
      a13: v27,
      a14: v28);
  }
}

