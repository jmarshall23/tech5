
// ========================================================================
// ?RandomInt@idRandom2@@QAAHH@Z
// EA  : 0x826D0B70
// RVA : 0x006D0B70
// PDB : w:\tech5\shared\idlib\math\random.h
// ========================================================================

int __fastcall idRandom2::RandomInt(idRandom2 *this, int max)
{
  unsigned int seed; // r10
  unsigned int v4; // r7
  int v5; // r6

  if ( max == 0 )
    return 0;
  seed = this->seed;
  __twllei(max, 0);
  v4 = 1664525 * seed + 1013904223;
  v5 = (v4 >> 10) & 0x7FFF;
  this->seed = v4;
  __twlgei(max & ~(__ROL4__(v5, 1) - 1), 0xFFFFFFFF);
  return v5 % max;
}


// ========================================================================
// ?RandomInt@idRandom@@QAAHH@Z
// EA  : 0x826DE760
// RVA : 0x006DE760
// PDB : w:\tech5\shared\idlib\math\random.h
// ========================================================================

int __fastcall idRandom::RandomInt(idRandom *this, int max)
{
  int seed; // r10
  int v4; // r11
  int v5; // r7

  if ( max == 0 )
    return 0;
  seed = this->seed;
  __twllei(max, 0);
  v4 = 1103515245 * seed + 12345;
  this->seed = v4;
  v5 = (v4 >> 16) & 0x7FFF;
  __twlgei(max & ~(__ROL4__(v5, 1) - 1), 0xFFFFFFFF);
  return v5 % max;
}


// ========================================================================
// ?RandomInt@idRandom2@@QAAHHH@Z
// EA  : 0x82799408
// RVA : 0x00799408
// PDB : w:\tech5\shared\idlib\math\random.h
// ========================================================================

int __fastcall idRandom2::RandomInt(idRandom2 *this, int min, int max)
{
  signed int v4; // r7
  unsigned int v5; // r5
  int v6; // r10

  if ( min >= max )
    return min;
  v4 = max - min + 1;
  v5 = 1664525 * this->seed + 1013907456;
  __twllei(v4, 0);
  v5 -= 3233;
  v6 = (v5 >> 10) & 0x7FFF;
  this->seed = v5;
  __twlgei(v4 & ~(__ROL4__(v6, 1) - 1), 0xFFFFFFFF);
  return v6 % v4 + min;
}


// ========================================================================
// ?GenerateNumbers@idRandomMersenne@@QAAXXZ
// EA  : 0x828C0B30
// RVA : 0x008C0B30
// PDB : w:\tech5\shared\idlib\math\random.h
// ========================================================================

void __fastcall idRandomMersenne::GenerateNumbers(idRandomMersenne *this)
{
  idRandomMersenne *v1; // r11
  int i; // ctr
  unsigned int v3; // r6
  unsigned int *v4; // r11
  int j; // ctr
  unsigned int v6; // r6
  unsigned int v7; // r7

  v1 = this;
  for ( i = 227; i != 0; --i )
  {
    v3 = v1->MT[0] & 0x80000000 | v1->MT[1] & 0x7FFFFFFE;
    v1->MT[0] = *(unsigned int *)((char *)`idRandomMersenne::GenerateNumbers'::`2'::mag01 + ((4 * v3) & 4))
              ^ (v3 >> 1)
              ^ v1->MT[397];
    v1 = (idRandomMersenne *)((char *)v1 + 4);
  }
  v4 = &this->MT[227];
  for ( j = 396; j != 0; --j )
  {
    v6 = *v4 & 0x80000000 | v4[1] & 0x7FFFFFFE;
    *v4 = *(unsigned int *)((char *)`idRandomMersenne::GenerateNumbers'::`2'::mag01 + ((4 * v6) & 4))
        ^ (v6 >> 1)
        ^ *(v4 - 227);
    ++v4;
  }
  v7 = this->MT[0] & 0x7FFFFFFE | this->MT[623] & 0x80000000;
  this->MT[623] = *(unsigned int *)((char *)`idRandomMersenne::GenerateNumbers'::`2'::mag01 + ((4 * v7) & 4))
                ^ this->MT[396]
                ^ (v7 >> 1);
}


// ========================================================================
// ?RandomInt@idRandomMersenne@@QAAIXZ
// EA  : 0x828C0BE8
// RVA : 0x008C0BE8
// PDB : w:\tech5\shared\idlib\math\random.h
// ========================================================================

int __fastcall idRandomMersenne::RandomInt(idRandomMersenne *this)
{
  unsigned int index; // r11
  unsigned int v3; // r8
  unsigned int v4; // r10

  if ( this->index >= 0x270 )
  {
    this->index = 0;
    idRandomMersenne::GenerateNumbers(this);
  }
  index = this->index;
  v3 = this->MT[index];
  this->index = index + 1;
  v4 = ((((((v3 >> 11) ^ v3) & 0xFF3A58AD) << 7) ^ (v3 >> 11) ^ v3) << 15)
     & 0xEFC60000
     ^ ((((v3 >> 11) ^ v3) & 0xFF3A58AD) << 7)
     ^ (v3 >> 11)
     ^ v3;
  return (v4 >> 18) ^ v4;
}


// ========================================================================
// ?BellCurve@idRandom2@@QAAMH@Z
// EA  : 0x82A2DDE0
// RVA : 0x00A2DDE0
// PDB : w:\tech5\shared\idlib\math\random.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idRandom2::BellCurve(idRandom2 *this, __int64 degree)
{
  double v2; // fp12
  double v3; // fp11
  double v4; // fp10
  __int64 v5; // r11
  int v6; // r9
  unsigned int v7; // r6
  int v8; // r7
  unsigned int v9; // r6
  unsigned int v10; // r7
  double v11; // fp1

  v2 = 0.0;
  v3 = 0.0;
  v4 = 0.0;
  HIDWORD(v5) = 1664525;
  v6 = 0;
  if ( SHIDWORD(degree) >= 2 )
  {
    do
    {
      v6 += 2;
      LODWORD(degree) = 1664525 * this->seed + 1013904223;
      this->seed = degree;
      v7 = 1664525 * degree + 1013904223;
      v8 = (v7 >> 10) & 0x7FFF;
      this->seed = v7;
      v9 = ((unsigned int)degree >> 10) & 0x7FFF;
      LODWORD(degree) = v8;
      v3 = (float)((float)((float)((float)*(__int64 *)((char *)&degree - 4) * (float)0.000061037019) - (float)1.0)
                 + (float)v3);
      v4 = (float)((float)((float)((float)degree * (float)0.000061037019) - (float)1.0) + (float)v4);
    }
    while ( v6 < HIDWORD(degree) - 1 );
  }
  if ( v6 < SHIDWORD(degree) )
  {
    v10 = 1664525 * this->seed + 1013904223;
    LODWORD(degree) = (v10 >> 10) & 0x7FFF;
    this->seed = v10;
    v2 = (float)((float)((float)degree * (float)0.000061037019) - (float)1.0);
  }
  LODWORD(v5) = HIDWORD(degree);
  v11 = (float)((float)((float)((float)v4 + (float)v3) + (float)v2) / (float)v5);
  return *((float *)&v11 + 1);
}

