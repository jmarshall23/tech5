
// ========================================================================
// ??$ReadQuantizedVector@VidVec3@@$0IAAA@$0M@@idBitMsg@@QBAXAAVidVec3@@@Z
// EA  : 0x82704F80
// RVA : 0x00704F80
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::ReadQuantizedVector<idVec3,32768,12>(idBitMsg *this, idVec3 *v)
{
  float *p_z; // r30
  int i; // r31
  __int64 v5; // r11

  p_z = &v[-1].z;
  for ( i = 3; i != 0; --i )
  {
    LODWORD(v5) = idBitMsg::ReadBits(this, numBits: -12);
    *++p_z = (float)v5 * (float)16.007816;
  }
}


// ========================================================================
// ??$WriteQuantizedVector@VidVec3@@$0IAAA@$0M@@idBitMsg@@QAAXABVidVec3@@@Z
// EA  : 0x82704FE0
// RVA : 0x00704FE0
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::WriteQuantizedVector<idVec3,32768,12>(idBitMsg *this, const idVec3 *v)
{
  int i; // r31
  int v5; // r4
  int v6; // [sp+54h] [-2Ch]

  for ( i = 3; i != 0; --i )
  {
    v6 = (int)(float)(v->x * (float)0.062469482);
    v5 = v6;
    if ( v6 >= -2047 )
    {
      if ( v6 > 2047 )
        v5 = 2047;
    }
    else
    {
      v5 = -2047;
    }
    idBitMsg::WriteBits(this, value: v5, numBits: -12);
    v = (const idVec3 *)((char *)v + 4);
  }
}


// ========================================================================
// ??$ReadQuantizedVector@VidVec3@@$0EAA@$07@idBitMsg@@QBAXAAVidVec3@@@Z
// EA  : 0x82713C78
// RVA : 0x00713C78
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::ReadQuantizedVector<idVec3,1024,8>(idBitMsg *this, idVec3 *v)
{
  float *p_z; // r30
  int i; // r31
  __int64 v5; // r11

  p_z = &v[-1].z;
  for ( i = 3; i != 0; --i )
  {
    LODWORD(v5) = idBitMsg::ReadBits(this, numBits: -8);
    *++p_z = (float)v5 * (float)8.0629921;
  }
}


// ========================================================================
// ??$WriteQuantizedVector@VidVec3@@$0EAA@$07@idBitMsg@@QAAXABVidVec3@@@Z
// EA  : 0x82713E50
// RVA : 0x00713E50
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::WriteQuantizedVector<idVec3,1024,8>(idBitMsg *this, const idVec3 *v)
{
  int i; // r31
  int v5; // r4
  int v6; // [sp+54h] [-2Ch]

  for ( i = 3; i != 0; --i )
  {
    v6 = (int)(float)(v->x * (float)0.12402344);
    v5 = v6;
    if ( v6 >= -127 )
    {
      if ( v6 > 127 )
        v5 = 127;
    }
    else
    {
      v5 = -127;
    }
    idBitMsg::WriteBits(this, value: v5, numBits: -8);
    v = (const idVec3 *)((char *)v + 4);
  }
}


// ========================================================================
// ??$ReadQuantizedVector@VidVec3@@$00$0M@@idBitMsg@@QBAXAAVidVec3@@@Z
// EA  : 0x82718630
// RVA : 0x00718630
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::ReadQuantizedVector<idVec3,1,12>(idBitMsg *this, idVec3 *v)
{
  float *p_z; // r30
  int i; // r31
  __int64 v5; // r11

  p_z = &v[-1].z;
  for ( i = 3; i != 0; --i )
  {
    LODWORD(v5) = idBitMsg::ReadBits(this, numBits: -12);
    *++p_z = (float)v5 * (float)0.00048851978;
  }
}


// ========================================================================
// ??$ReadQuantizedVector@VidVec3@@$0BAA@$07@idBitMsg@@QBAXAAVidVec3@@@Z
// EA  : 0x82718690
// RVA : 0x00718690
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::ReadQuantizedVector<idVec3,256,8>(idBitMsg *this, idVec3 *v)
{
  float *p_z; // r30
  int i; // r31
  __int64 v5; // r11

  p_z = &v[-1].z;
  for ( i = 3; i != 0; --i )
  {
    LODWORD(v5) = idBitMsg::ReadBits(this, numBits: -8);
    *++p_z = (float)v5 * (float)2.015748;
  }
}


// ========================================================================
// ??$WriteQuantizedVector@VidVec3@@$00$0M@@idBitMsg@@QAAXABVidVec3@@@Z
// EA  : 0x82718AF0
// RVA : 0x00718AF0
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::WriteQuantizedVector<idVec3,1,12>(idBitMsg *this, const idVec3 *v)
{
  int i; // r31
  int v5; // r4
  int v6; // [sp+54h] [-2Ch]

  for ( i = 3; i != 0; --i )
  {
    v6 = (int)(float)(v->x * (float)2047.0);
    v5 = v6;
    if ( v6 >= -2047 )
    {
      if ( v6 > 2047 )
        v5 = 2047;
    }
    else
    {
      v5 = -2047;
    }
    idBitMsg::WriteBits(this, value: v5, numBits: -12);
    v = (const idVec3 *)((char *)v + 4);
  }
}


// ========================================================================
// ??$WriteQuantizedVector@VidVec3@@$0BAA@$07@idBitMsg@@QAAXABVidVec3@@@Z
// EA  : 0x82718B68
// RVA : 0x00718B68
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::WriteQuantizedVector<idVec3,256,8>(idBitMsg *this, const idVec3 *v)
{
  int i; // r31
  int v5; // r4
  int v6; // [sp+54h] [-2Ch]

  for ( i = 3; i != 0; --i )
  {
    v6 = (int)(float)(v->x * (float)0.49609375);
    v5 = v6;
    if ( v6 >= -127 )
    {
      if ( v6 > 127 )
        v5 = 127;
    }
    else
    {
      v5 = -127;
    }
    idBitMsg::WriteBits(this, value: v5, numBits: -8);
    v = (const idVec3 *)((char *)v + 4);
  }
}


// ========================================================================
// ??$WriteQuantizedUFloat@$0PP@$0BA@@idBitMsg@@QAAXM@Z
// EA  : 0x827F36E0
// RVA : 0x007F36E0
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::WriteQuantizedUFloat<255,16>(idBitMsg *this, double value)
{
  int v2; // r11

  v2 = (int)(float)((float)value * (float)257.0);
  if ( v2 >= 0 )
  {
    if ( v2 > 0xFFFF )
      v2 = 0xFFFF;
  }
  else
  {
    v2 = 0;
  }
  idBitMsg::WriteBits(this, value: v2, numBits: 16);
}


// ========================================================================
// ??$WriteQuantizedUFloat@$0CIAA@$0BA@@idBitMsg@@QAAXM@Z
// EA  : 0x829A74C8
// RVA : 0x009A74C8
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::WriteQuantizedUFloat<10240,16>(idBitMsg *this, double value)
{
  int v2; // r11

  v2 = (int)(float)((float)value * (float)6.0);
  if ( v2 >= 0 )
  {
    if ( v2 > 0xFFFF )
      v2 = 0xFFFF;
  }
  else
  {
    v2 = 0;
  }
  idBitMsg::WriteBits(this, value: v2, numBits: 16);
}


// ========================================================================
// ??$WriteQuantizedVector@VidVec3@@$0IAAA@$0L@@idBitMsg@@QAAXABVidVec3@@@Z
// EA  : 0x82B4DFA0
// RVA : 0x00B4DFA0
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::WriteQuantizedVector<idVec3,32768,11>(idBitMsg *this, const idVec3 *v)
{
  int i; // r31
  int v5; // r4
  int v6; // [sp+54h] [-2Ch]

  for ( i = 3; i != 0; --i )
  {
    v6 = (int)(float)(v->x * (float)0.031219482);
    v5 = v6;
    if ( v6 >= -1023 )
    {
      if ( v6 > 1023 )
        v5 = 1023;
    }
    else
    {
      v5 = -1023;
    }
    idBitMsg::WriteBits(this, value: v5, numBits: -11);
    v = (const idVec3 *)((char *)v + 4);
  }
}


// ========================================================================
// ??$ReadQuantizedVector@VidVec3@@$0IAAA@$0L@@idBitMsg@@QBAXAAVidVec3@@@Z
// EA  : 0x82B4E018
// RVA : 0x00B4E018
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::ReadQuantizedVector<idVec3,32768,11>(idBitMsg *this, idVec3 *v)
{
  float *p_z; // r30
  int i; // r31
  __int64 v5; // r11

  p_z = &v[-1].z;
  for ( i = 3; i != 0; --i )
  {
    LODWORD(v5) = idBitMsg::ReadBits(this, numBits: -11);
    *++p_z = (float)v5 * (float)32.031281;
  }
}


// ========================================================================
// ??$ReadQuantizedVector@VidVec3@@$0IAAA@$0BB@@idBitMsg@@QBAXAAVidVec3@@@Z
// EA  : 0x82B67C90
// RVA : 0x00B67C90
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::ReadQuantizedVector<idVec3,32768,17>(idBitMsg *this, idVec3 *v)
{
  float *p_z; // r30
  int i; // r31
  __int64 v5; // r11

  p_z = &v[-1].z;
  for ( i = 3; i != 0; --i )
  {
    LODWORD(v5) = idBitMsg::ReadBits(this, numBits: -17);
    *++p_z = (float)v5 * (float)0.50000763;
  }
}


// ========================================================================
// ??$WriteQuantizedVector@VidVec3@@$0IAAA@$0BB@@idBitMsg@@QAAXABVidVec3@@@Z
// EA  : 0x82B687E8
// RVA : 0x00B687E8
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::WriteQuantizedVector<idVec3,32768,17>(idBitMsg *this, const idVec3 *v)
{
  int i; // r30
  int x; // r4

  for ( i = 3; i != 0; --i )
  {
    x = (int)v->x;
    if ( x >= -65535 )
    {
      if ( x > 0xFFFF )
        x = 0xFFFF;
    }
    else
    {
      x = -65535;
    }
    idBitMsg::WriteBits(this, value: x, numBits: -17);
    v = (const idVec3 *)((char *)v + 4);
  }
}


// ========================================================================
// ??$ReadQuantizedVector@VidVec3@@$0CAA@$07@idBitMsg@@QBAXAAVidVec3@@@Z
// EA  : 0x82B6CA78
// RVA : 0x00B6CA78
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::ReadQuantizedVector<idVec3,512,8>(idBitMsg *this, idVec3 *v)
{
  float *p_z; // r30
  int i; // r31
  __int64 v5; // r11

  p_z = &v[-1].z;
  for ( i = 3; i != 0; --i )
  {
    LODWORD(v5) = idBitMsg::ReadBits(this, numBits: -8);
    *++p_z = (float)v5 * (float)4.031496;
  }
}


// ========================================================================
// ??$WriteQuantizedVector@VidVec3@@$0CAA@$07@idBitMsg@@QAAXABVidVec3@@@Z
// EA  : 0x82B6CEC8
// RVA : 0x00B6CEC8
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::WriteQuantizedVector<idVec3,512,8>(idBitMsg *this, const idVec3 *v)
{
  int i; // r31
  int v5; // r4
  int v6; // [sp+54h] [-2Ch]

  for ( i = 3; i != 0; --i )
  {
    v6 = (int)(float)(v->x * (float)0.24804688);
    v5 = v6;
    if ( v6 >= -127 )
    {
      if ( v6 > 127 )
        v5 = 127;
    }
    else
    {
      v5 = -127;
    }
    idBitMsg::WriteBits(this, value: v5, numBits: -8);
    v = (const idVec3 *)((char *)v + 4);
  }
}


// ========================================================================
// ??$ReadQuantizedVector@VidVec3@@$0IAAA@$0BA@@idBitMsg@@QBAXAAVidVec3@@@Z
// EA  : 0x82B72720
// RVA : 0x00B72720
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::ReadQuantizedVector<idVec3,32768,16>(idBitMsg *this, idVec3 *v)
{
  float *p_z; // r30
  int i; // r31
  __int64 v5; // r11

  p_z = &v[-1].z;
  for ( i = 3; i != 0; --i )
  {
    LODWORD(v5) = idBitMsg::ReadBits(this, numBits: -16);
    *++p_z = (float)v5 * (float)1.0000305;
  }
}


// ========================================================================
// ??$WriteQuantizedVector@VidVec3@@$0IAAA@$0BA@@idBitMsg@@QAAXABVidVec3@@@Z
// EA  : 0x82B72900
// RVA : 0x00B72900
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::WriteQuantizedVector<idVec3,32768,16>(idBitMsg *this, const idVec3 *v)
{
  int i; // r31
  int v5; // r4
  int v6; // [sp+54h] [-2Ch]

  for ( i = 3; i != 0; --i )
  {
    v6 = (int)(float)(v->x * (float)0.99996948);
    v5 = v6;
    if ( v6 >= -32767 )
    {
      if ( v6 > 0x7FFF )
        v5 = 0x7FFF;
    }
    else
    {
      v5 = -32767;
    }
    idBitMsg::WriteBits(this, value: v5, numBits: -16);
    v = (const idVec3 *)((char *)v + 4);
  }
}


// ========================================================================
// ??$ReadQuantizedVector@VidVec3@@$0BAAA@$07@idBitMsg@@QBAXAAVidVec3@@@Z
// EA  : 0x82B730B0
// RVA : 0x00B730B0
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::ReadQuantizedVector<idVec3,4096,8>(idBitMsg *this, idVec3 *v)
{
  float *p_z; // r30
  int i; // r31
  __int64 v5; // r11

  p_z = &v[-1].z;
  for ( i = 3; i != 0; --i )
  {
    LODWORD(v5) = idBitMsg::ReadBits(this, numBits: -8);
    *++p_z = (float)v5 * (float)32.251968;
  }
}


// ========================================================================
// ??$WriteQuantizedVector@VidVec3@@$0BAAA@$07@idBitMsg@@QAAXABVidVec3@@@Z
// EA  : 0x82B73290
// RVA : 0x00B73290
// PDB : w:\tech5\shared\idlib\networking\bitmsg.h
// ========================================================================

void __fastcall idBitMsg::WriteQuantizedVector<idVec3,4096,8>(idBitMsg *this, const idVec3 *v)
{
  int i; // r31
  int v5; // r4
  int v6; // [sp+54h] [-2Ch]

  for ( i = 3; i != 0; --i )
  {
    v6 = (int)(float)(v->x * (float)0.031005859);
    v5 = v6;
    if ( v6 >= -127 )
    {
      if ( v6 > 127 )
        v5 = 127;
    }
    else
    {
      v5 = -127;
    }
    idBitMsg::WriteBits(this, value: v5, numBits: -8);
    v = (const idVec3 *)((char *)v + 4);
  }
}

