
// ========================================================================
// ?GetVolume@idDuckLayer@idSoundWorldLocal@@QAAMHH@Z
// EA  : 0x8298AAA0
// RVA : 0x0098AAA0
// PDB : w:\tech5\engine\sound\soundworld_local.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idSoundWorldLocal::idDuckLayer::GetVolume(
        idSoundWorldLocal::idDuckLayer *this,
        int g,
        int currentTime)
{
  int v3; // r3
  double v4; // fp1
  int v5; // r3
  int v6; // r3
  int v7; // r3
  int v8; // r3
  int v9; // r11
  __int64 v10; // r4
  __int64 v11; // r11
  int v12; // r9
  int v13; // r7
  int v14; // r3
  int v15; // r11
  int v16; // r3
  int v17; // r11
  __int128 v18; // r5
  int v19; // r10
  int v20; // r9
  int v21; // r3

  v4 = 0.0;
  if ( *(float *)(v3 + 120) < 0.0 )
  {
    if ( currentTime >= *(_DWORD *)(v6 + 104) )
    {
      v9 = *(_DWORD *)(v8 + 108);
      if ( currentTime >= v9 )
      {
        v15 = *(_DWORD *)(v14 + 112);
        if ( currentTime < v15 || v15 < 0 )
        {
          v4 = *(float *)(4 * (g + 15) + *(_DWORD *)(v21 + 100));
        }
        else
        {
          v17 = *(_DWORD *)(v16 + 116);
          if ( currentTime < v17 )
          {
            v19 = *(_DWORD *)(DWORD1(v18) + 112);
            v20 = g + 15;
            LODWORD(v18) = currentTime - v19;
            DWORD2(v18) = v17 - v19;
            v4 = (float)((float)((float)((float)(__int64)v18 / (float)*(__int64 *)((char *)&v18 + 4))
                               * (float)-*(float *)(4 * v20 + *(_DWORD *)(DWORD1(v18) + 100)))
                       + *(float *)(4 * v20 + *(_DWORD *)(DWORD1(v18) + 100)));
          }
        }
      }
      else
      {
        HIDWORD(v11) = *(_DWORD *)(HIDWORD(v10) + 104);
        v12 = g + 15;
        v13 = 4 * g;
        LODWORD(v10) = currentTime - HIDWORD(v11);
        LODWORD(v11) = v9 - HIDWORD(v11);
        v4 = (float)((float)((float)((float)(*(float *)(4 * v12 + *(_DWORD *)(HIDWORD(v10) + 100))
                                           - *(float *)(v13 + HIDWORD(v10)))
                                   / (float)v11)
                           * (float)v10)
                   + *(float *)(v13 + HIDWORD(v10)));
      }
    }
    else
    {
      v4 = *(float *)(4 * g + v7);
    }
  }
  else
  {
    v4 = (float)((float)((float)(*(float *)(4 * (g + 15) + *(_DWORD *)(v5 + 100)) - *(float *)(4 * g + v5))
                       * *(float *)(v5 + 120))
               + *(float *)(4 * g + v5));
  }
  return *((float *)&v4 + 1);
}

