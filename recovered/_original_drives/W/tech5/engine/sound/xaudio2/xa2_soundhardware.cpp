
// ========================================================================
// ?OnCriticalError@idSoundEngineCallback@@EAAXJ@Z
// EA  : 0x8299CF10
// RVA : 0x0099CF10
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void __fastcall idSoundEngineCallback::OnCriticalError(idSoundEngineCallback *this, HRESULT Error)
{
  soundSystemLocal.needsRestart = true;
}


// ========================================================================
// ?SetReverb@idSoundHardware_XAudio2@@QAAXABUsoundEnvironment_t@@@Z
// EA  : 0x8299D018
// RVA : 0x0099D018
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSoundHardware_XAudio2::SetReverb(
        idSoundHardware_XAudio2 *this,
        const soundEnvironment_t *parms,
        long double a3,
        long double a4,
        int a5,
        int a6,
        int a7,
        __int64 a8)
{
  idDebugHUD_vtbl *v10; // r30
  int v11; // r3
  __int64 *v12; // r11
  int i; // ctr
  long double v14; // fp2
  double RoomGain; // fp0
  __int64 v16; // r8 OVERLAPPED
  float v17; // r11
  double RoomHFGain; // fp0
  float v19; // r11
  __int64 v20; // r11
  __int64 v21; // r7
  long double v22; // fp2
  int v23; // r11
  float v26; // r5
  __int64 v27; // r7
  long double v28; // fp2
  int v29; // r11
  int ReflectionsDelay; // r10
  int ReverbDelay; // r11
  float ReflectionsGain; // r9
  double Diffusion; // fp13
  unsigned __int8 v36; // r11
  double v37; // fp0
  float v38; // r11
  float v39; // [sp+50h] [-80h]
  float v40; // [sp+50h] [-80h]
  float v41; // [sp+50h] [-80h]
  float v42; // [sp+50h] [-80h]
  float ReverbGain; // [sp+50h] [-80h]
  float v44; // [sp+50h] [-80h]
  __int64 v45; // [sp+58h] [-78h] BYREF
  float v46[2]; // [sp+60h] [-70h] BYREF
  char v47; // [sp+68h] [-68h]
  char v48; // [sp+69h] [-67h]
  char v49; // [sp+6Ah] [-66h]
  char v50; // [sp+6Bh] [-65h]
  char v51; // [sp+6Ch] [-64h]
  char v52; // [sp+6Dh] [-63h]
  unsigned __int8 v53; // [sp+6Eh] [-62h]
  unsigned __int8 v54; // [sp+6Fh] [-61h]
  char v55; // [sp+70h] [-60h]
  char v56; // [sp+71h] [-5Fh]
  char v57; // [sp+72h] [-5Eh]
  char v58; // [sp+73h] [-5Dh]
  float HFReference; // [sp+74h] [-5Ch]
  float v60; // [sp+78h] [-58h]
  float v61; // [sp+7Ch] [-54h]
  float v62; // [sp+80h] [-50h]
  float v63; // [sp+84h] [-4Ch]
  float v64; // [sp+88h] [-48h]
  float v65; // [sp+8Ch] [-44h]
  float v66; // [sp+90h] [-40h]

  if ( this->pSubmixVoice != nullptr )
  {
    if ( s_showReverb.valueInteger != 0 )
    {
      cvarSystem->SetCVarBool(this: cvarSystem, a2: "com_debugHUD", a3: true, a4: 0);
      v10 = debugHUD->__vftable;
      v11 = renderSystem->GetHeight(this: renderSystem);
      v10->SetTextPosition(this: debugHUD, a2: 0, a3: v11 >> 1);
      debugHUD->Printf(this: debugHUD, a2: "DryGain: %.2fdb\n", (unsigned int)COERCE_UNSIGNED_INT64(parms->DryGain));
      debugHUD->Printf(this: debugHUD, a2: "RoomGain: %.2fdb\n", (unsigned int)COERCE_UNSIGNED_INT64(parms->RoomGain));
      debugHUD->Printf(
        this: debugHUD,
        a2: "RoomHFGain: %.2fdb\n",
        (unsigned int)COERCE_UNSIGNED_INT64(parms->RoomHFGain));
      debugHUD->Printf(this: debugHUD, a2: "DecayTime: %dms\n", parms->DecayTime);
      debugHUD->Printf(this: debugHUD, a2: "DecayHFTime: %dms\n", parms->DecayHFTime);
      debugHUD->Printf(
        this: debugHUD,
        a2: "ReflectionsGain: %.2fdb\n",
        (unsigned int)COERCE_UNSIGNED_INT64(parms->ReflectionsGain));
      debugHUD->Printf(this: debugHUD, a2: "ReflectionsDelay: %dms\n", parms->ReflectionsDelay);
      debugHUD->Printf(
        this: debugHUD,
        a2: "ReverbGain: %.2fdb\n",
        (unsigned int)COERCE_UNSIGNED_INT64(parms->ReverbGain));
      debugHUD->Printf(this: debugHUD, a2: "ReverbDelay: %dms\n", parms->ReverbDelay);
      debugHUD->Printf(this: debugHUD, a2: "Diffusion: %.2f\n", (unsigned int)COERCE_UNSIGNED_INT64(parms->Diffusion));
      debugHUD->Printf(this: debugHUD, a2: "Density: %.2f\n", (unsigned int)COERCE_UNSIGNED_INT64(parms->Density));
      debugHUD->Printf(
        this: debugHUD,
        a2: "HFReference: %.2fHz\n",
        (unsigned int)COERCE_UNSIGNED_INT64(parms->HFReference));
    }
    v12 = &v45;
    LODWORD(a8) = 0;
    for ( i = 7; i != 0; --i )
      *++v12 = a8;
    if ( parms->DryGain <= -60.0 )
    {
      this->dryGain = 0.0;
    }
    else
    {
      *(_QWORD *)&v14 = 0x4000000000000000LL;
      *((double *)&v14 + 1) = (float)(parms->DryGain * (float)0.16666667);
      a3 = pow(x: v14, y: a4);
      this->dryGain = *(double *)&a3;
    }
    RoomGain = parms->RoomGain;
    HIDWORD(v16) = 5;
    v49 = 6;
    v48 = 5;
    v50 = 6;
    v51 = 27;
    v52 = 27;
    v46[0] = 100.0;
    v66 = 100.0;
    v56 = 4;
    v58 = 6;
    if ( RoomGain >= -100.0 )
    {
      if ( RoomGain <= 0.0 )
        v39 = RoomGain;
      else
        v39 = 0.0;
      v17 = v39;
    }
    else
    {
      v17 = -100.0;
    }
    RoomHFGain = parms->RoomHFGain;
    v60 = v17;
    if ( RoomHFGain >= -100.0 )
    {
      if ( RoomHFGain <= 0.0 )
        v40 = RoomHFGain;
      else
        v40 = 0.0;
      v19 = v40;
    }
    else
    {
      v19 = -100.0;
    }
    HIDWORD(v20) = parms->DecayHFTime;
    v61 = v19;
    LODWORD(v20) = parms->DecayTime;
    *(__int64 *)((char *)&v16 - 4) = v20;
    v45 = v20;
    *(double *)&a3 = (float)((float)v16 / (float)v20);
    if ( SHIDWORD(v20) < (int)v20 )
    {
      v55 = 8;
      v28 = log10(x: a3);
      LODWORD(v45) = (int)(float)((float)*(double *)&v28 * (float)-4.0);
      v29 = 8 - v45;
      if ( 8 - (int)v45 >= 0 )
      {
        if ( v29 > 8 )
          LOBYTE(v29) = 8;
      }
      else
      {
        LOBYTE(v29) = 0;
      }
      LODWORD(v27) = parms->DecayTime;
      v57 = v29;
      v45 = v27;
      _FP9 = (float)((float)0.1 - (float)((float)v27 * (float)0.001));
      __asm { fsel      f8, f9, f0, f10 }
      v42 = _FP8;
      v26 = v42;
    }
    else
    {
      v57 = 8;
      v22 = log10(x: a3);
      LODWORD(v45) = (int)(float)((float)*(double *)&v22 * (float)4.0);
      v23 = 8 - v45;
      if ( 8 - (int)v45 >= 0 )
      {
        if ( v23 > 12 )
          LOBYTE(v23) = 12;
      }
      else
      {
        LOBYTE(v23) = 0;
      }
      LODWORD(v21) = parms->DecayHFTime;
      v55 = v23;
      v45 = v21;
      _FP8 = (float)((float)0.1 - (float)((float)v21 * (float)0.001));
      __asm { fsel      f7, f8, f0, f9 }
      v41 = _FP7;
      v26 = v41;
    }
    ReflectionsDelay = parms->ReflectionsDelay;
    v64 = v26;
    if ( ReflectionsDelay >= 0 )
    {
      if ( ReflectionsDelay > 300 )
        ReflectionsDelay = 300;
    }
    else
    {
      ReflectionsDelay = 0;
    }
    ReverbDelay = parms->ReverbDelay;
    LODWORD(v46[1]) = ReflectionsDelay;
    if ( ReverbDelay >= 0 )
    {
      if ( ReverbDelay > 85 )
        LOBYTE(ReverbDelay) = 85;
    }
    else
    {
      LOBYTE(ReverbDelay) = 0;
    }
    ReflectionsGain = parms->ReflectionsGain;
    ReverbGain = parms->ReverbGain;
    v47 = ReverbDelay;
    Diffusion = parms->Diffusion;
    v62 = ReflectionsGain;
    v63 = ReverbGain;
    LODWORD(v45) = (int)(float)((float)Diffusion * (float)15.0);
    v36 = v45;
    if ( (int)v45 >= 0 )
    {
      if ( (int)v45 > 255 )
        v36 = -1;
    }
    else
    {
      v36 = 0;
    }
    if ( v36 > 0xFu )
      v36 = 15;
    v37 = (float)(parms->Density * (float)100.0);
    v54 = v36;
    v53 = v36;
    if ( v37 >= 0.0 )
    {
      if ( v37 <= 100.0 )
        v44 = v37;
      else
        v44 = 100.0;
      v38 = v44;
    }
    else
    {
      v38 = 0.0;
    }
    HFReference = parms->HFReference;
    v65 = v38;
    this->pSubmixVoice->SetEffectParameters(this: this->pSubmixVoice, a2: 0, a3: v46, a4: 56u, a5: 0);
  }
}


// ========================================================================
// ?s_xa2_limiter_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8299D648
// RVA : 0x0099D648
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void __fastcall s_xa2_limiter_f(const idCmdArgs *args)
{
  char v1; // r30
  const char *v3; // r4
  char *data; // r3
  int v5; // r3
  char v6; // r11
  char v7; // r28
  const char *v8; // r3
  int v9; // r30
  const char *v10; // r3
  int v11; // r3
  unsigned int v12; // r11
  unsigned int v13; // r10
  idStr v14[2]; // [sp+60h] [-50h] BYREF

  v1 = 0;
  if ( args->argc != 2
    || (args->argc <= 1 ? (v3 = &byte_8200D768) : (v3 = args->argv[1]),
        v1 = 1,
        data = idStr::idStr(this: v14, text: v3)->data,
        v5 = idStr::Cmp(s1: data, s2: "off"),
        v6 = 1,
        v5 != 0) )
  {
    v6 = 0;
  }
  v7 = v6;
  if ( (v1 & 1) != 0 )
    idStr::FreeData(this: v14);
  if ( v7 != 0 )
  {
    masteringLimiterState = MASTERINGLIMITER_STATE_OFF;
    idLib::Printf(fmt: "Mastering limiter is OFF\n");
  }
  else if ( args->argc == 3 )
  {
    if ( masteringLimiterState == MASTERINGLIMITER_STATE_OFF )
      idLib::Printf(fmt: "Mastering limiter is ON\n");
    if ( args->argc <= 1 )
      v8 = &byte_8200D768;
    else
      v8 = args->argv[1];
    v9 = atol(nptr: v8);
    if ( args->argc <= 2 )
      v10 = &byte_8200D768;
    else
      v10 = args->argv[2];
    v11 = atol(nptr: v10);
    v12 = v11;
    if ( v9 >= 1 )
    {
      v13 = 1800;
      if ( v9 <= 1800 )
        v13 = v9;
    }
    else
    {
      v13 = 1;
    }
    masteringLimiterParams.Loudness = v13;
    if ( v11 >= 1 )
    {
      if ( v11 > 20 )
        v12 = 20;
    }
    else
    {
      v12 = 1;
    }
    masteringLimiterParams.Release = v12;
    masteringLimiterState = MASTERINGLIMITER_STATE_ON_CHANGED;
  }
  else
  {
    idLib::Printf(
      fmt: "Usage: s_xa2_limiter <LOUDNESS [range %i-%i, def %i]> <RELEASE [range %i-%i, def %i]>\n"
      "       s_xa2_limiter off\n",
      1,
      1800,
      400,
      1,
      20,
      2);
  }
}


// ========================================================================
// __unwind$225471
// EA  : 0x8299D7EC
// RVA : 0x0099D7EC
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void _unwind_225471()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 176;
  if ( (*(_DWORD *)(v0 - 176 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 96));
  }
}


// ========================================================================
// ?AllocateVoice@idSoundHardware_XAudio2@@QAAPAVidSoundVoice@@PBVidSoundSample@@ABV?$idList@PAVidSoundSample@@$04@@@Z
// EA  : 0x8299D830
// RVA : 0x0099D830
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

idSoundVoice *__fastcall idSoundHardware_XAudio2::AllocateVoice(
        idSoundHardware_XAudio2 *this,
        const idSoundSample *sample,
        const idList<idSoundSample *,5> *samples)
{
  int num; // r6
  int v6; // r7
  idSoundSample **v7; // r8
  int v8; // r9
  idSoundSample *v9; // r10
  idSoundSample *v10; // r11
  idSoundVoice_XAudio2 *v11; // r28
  int *p_num; // r27
  int v13; // r29
  int v14; // r31
  idStaticList<idSoundVoice_XAudio2 *,96> *p_freeVoices; // r30
  int v16; // r8
  int v17; // r11
  idSoundVoice_XAudio2 **list; // r9
  int i; // r10

  num = samples->num;
  v6 = 1;
  if ( num <= 1 )
  {
LABEL_7:
    v11 = nullptr;
    p_num = &this->freeVoices.num;
    v13 = 0;
    if ( this->freeVoices.num <= 0 )
      goto LABEL_26;
    v14 = 0;
    p_freeVoices = &this->freeVoices;
    do
    {
      if ( !idSoundVoice_XAudio2::IsPlaying(this: p_freeVoices->list[v14]) )
      {
        v11 = p_freeVoices->list[v14];
        if ( idSoundVoice_XAudio2::CompatibleFormat(this: v11, s: &sample->idSoundSample_XAudio2) )
          break;
      }
      ++v13;
      ++v14;
    }
    while ( v13 < *p_num );
    if ( v11 != nullptr )
    {
      idSoundVoice_XAudio2::Create(this: v11, firstSample: sample, samplesList: samples);
      v16 = p_freeVoices->num;
      v17 = 0;
      if ( v16 > 0 )
      {
        list = p_freeVoices->list;
        for ( i = 0; list[i] != v11; ++i )
        {
          if ( ++v17 >= p_freeVoices->num )
            return (idSoundVoice *)v11;
        }
        if ( v17 >= 0 && v17 < v16 )
        {
          p_freeVoices->num = v16 - 1;
          if ( v17 != v16 - 1 )
            list[v17] = list[v16 - 1];
        }
      }
      return (idSoundVoice *)v11;
    }
    else
    {
LABEL_26:
      idLib::Warning(fmt: "No hardware voices available");
      return nullptr;
    }
  }
  else
  {
    v7 = samples->list;
    v8 = 1;
    v9 = *samples->list;
    while ( 1 )
    {
      v10 = v7[v8];
      if ( v9->format.basic.numChannels != v10->format.basic.numChannels )
      {
        idLib::Warning(
          fmt: "Could not allocate voice with samples %s and %s, number of channels differ",
          v9->name.str,
          v7[v6]->name.str);
        return nullptr;
      }
      if ( v9->format.basic.bitsPerSample != v10->format.basic.bitsPerSample )
      {
        idLib::Warning(
          fmt: "Could not allocate voice with samples %s and %s, bits per channel differ",
          v9->name.str,
          v7[v6]->name.str);
        return nullptr;
      }
      if ( v9->format.basic.samplesPerSec != v10->format.basic.samplesPerSec )
        break;
      ++v6;
      ++v8;
      if ( v6 >= num )
        goto LABEL_7;
    }
    idLib::Warning(
      fmt: "Could not allocate voice with samples %s and %s, sample rate differ (%d,  %d) ",
      (*v7)->name.str,
      v7[v6]->name.str,
      (*v7)->format.basic.samplesPerSec,
      v7[v6]->format.basic.samplesPerSec);
    return nullptr;
  }
}


// ========================================================================
// ?listDevices_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8299DBB0
// RVA : 0x0099DBB0
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void __fastcall listDevices_f(const idCmdArgs *args)
{
  int v1; // r30
  int num; // r11
  int v3; // r11
  int v4; // r29
  int v5; // r28
  int v6; // r11
  int v7; // r29
  const char *v8; // [sp+50h] [-680h] BYREF
  unsigned int v9; // [sp+54h] [-67Ch]
  unsigned int v10; // [sp+58h] [-678h] BYREF
  idList<enum encounterGroupRole_t,5> v11; // [sp+60h] [-670h] BYREF
  int v12; // [sp+70h] [-660h] BYREF
  const char *v13; // [sp+84h] [-64Ch]
  const char *v14; // [sp+88h] [-648h]
  const char *v15; // [sp+8Ch] [-644h]
  const char *v16; // [sp+90h] [-640h]
  const char *v17; // [sp+94h] [-63Ch]
  const char *v18; // [sp+98h] [-638h]
  const char *v19; // [sp+9Ch] [-634h]
  const char *v20; // [sp+A0h] [-630h]
  const char *v21; // [sp+A4h] [-62Ch]
  IXAudio2 *pXAudio2; // [sp+A8h] [-628h]
  const char *v23; // [sp+ACh] [-624h]
  const char *v24; // [sp+B0h] [-620h]
  const char *v25; // [sp+B4h] [-61Ch]
  idList<enum encounterGroupRole_t,5> v26; // [sp+C0h] [-610h] BYREF
  int v27; // [sp+D0h] [-600h] BYREF
  int v28; // [sp+100h] [-5D0h] BYREF
  wchar_t v29[256]; // [sp+300h] [-3D0h] BYREF
  char v30; // [sp+503h] [-1CDh]
  unsigned __int16 v31; // [sp+506h] [-1CAh]
  int v32; // [sp+508h] [-1C8h]
  __int16 v33; // [sp+51Ah] [-1B6h]
  char v34[416]; // [sp+530h] [-1A0h] BYREF

  pXAudio2 = soundSystemLocal.hardware.pXAudio2;
  if ( soundSystemLocal.hardware.pXAudio2 != nullptr )
  {
    v10 = 0;
    if ( soundSystemLocal.hardware.pXAudio2->GetDeviceCount(a1: soundSystemLocal.hardware.pXAudio2, a2: &v10) != 0
      || v10 == 0 )
    {
      idLib::Warning(fmt: "No audio devices found");
    }
    else
    {
      v9 = 0;
      v14 = "Back Left";
      v20 = "     Default %s\n";
      v18 = "     %s\n";
      v16 = "Side Right";
      v13 = "Front Right";
      v21 = "Low Frequency";
      v25 = "Front Center";
      v23 = "Front Left";
      v17 = "Game Device";
      v24 = "Communications Device";
      v15 = "Multimedia Device";
      v19 = "Console Device";
      do
      {
        if ( pXAudio2->GetDeviceDetails(a1: pXAudio2, a2: v9, a3: (XAUDIO2_DEVICE_DETAILS *)&v28) == 0 )
        {
          v1 = 1;
          v11.size = 5;
          v11.granularity = 1;
          v11.list = (encounterGroupRole_t *)&v12;
          v11.num = 0;
          v11.memTag = 5;
          v11.listStatic = 1;
          if ( (v30 & 1) != 0 )
          {
            v8 = v19;
            idList<idAnimWebBlendTree *,5>::Append(this: &v11, obj: (const encounterGroupRole_t *)&v8);
          }
          if ( (v30 & 2) != 0 )
          {
            v8 = v15;
            idList<idAnimWebBlendTree *,5>::Append(this: &v11, obj: (const encounterGroupRole_t *)&v8);
          }
          if ( (v30 & 4) != 0 )
          {
            v8 = v24;
            idList<idAnimWebBlendTree *,5>::Append(this: &v11, obj: (const encounterGroupRole_t *)&v8);
          }
          if ( (v30 & 8) != 0 )
          {
            v8 = v17;
            idList<idAnimWebBlendTree *,5>::Append(this: &v11, obj: (const encounterGroupRole_t *)&v8);
          }
          v26.num = 0;
          v26.granularity = 1;
          v26.size = 11;
          v26.list = (encounterGroupRole_t *)&v27;
          v26.memTag = 5;
          v26.listStatic = 1;
          if ( (v33 & 1) != 0 )
          {
            v8 = v23;
            idList<idAnimWebBlendTree *,5>::Append(this: &v26, obj: (const encounterGroupRole_t *)&v8);
          }
          if ( (v33 & 2) != 0 )
          {
            v8 = v13;
            idList<idAnimWebBlendTree *,5>::Append(this: &v26, obj: (const encounterGroupRole_t *)&v8);
          }
          if ( (v33 & 4) != 0 )
          {
            v8 = v25;
            idList<idAnimWebBlendTree *,5>::Append(this: &v26, obj: (const encounterGroupRole_t *)&v8);
          }
          if ( (v33 & 8) != 0 )
          {
            v8 = v21;
            idList<idAnimWebBlendTree *,5>::Append(this: &v26, obj: (const encounterGroupRole_t *)&v8);
          }
          if ( (v33 & 0x10) != 0 )
          {
            v8 = v14;
            idList<idAnimWebBlendTree *,5>::Append(this: &v26, obj: (const encounterGroupRole_t *)&v8);
          }
          if ( (v33 & 0x20) != 0 )
          {
            v8 = "Back Right";
            idList<idAnimWebBlendTree *,5>::Append(this: &v26, obj: (const encounterGroupRole_t *)&v8);
          }
          if ( (v33 & 0x40) != 0 )
          {
            v8 = "Front Left of Center";
            idList<idAnimWebBlendTree *,5>::Append(this: &v26, obj: (const encounterGroupRole_t *)&v8);
          }
          if ( (v33 & 0x80) != 0 )
          {
            v8 = "Front Right of Center";
            idList<idAnimWebBlendTree *,5>::Append(this: &v26, obj: (const encounterGroupRole_t *)&v8);
          }
          if ( (v33 & 0x100) != 0 )
          {
            v8 = "Back Center";
            idList<idAnimWebBlendTree *,5>::Append(this: &v26, obj: (const encounterGroupRole_t *)&v8);
          }
          if ( (v33 & 0x200) != 0 )
          {
            v8 = "Side Left";
            idList<idAnimWebBlendTree *,5>::Append(this: &v26, obj: (const encounterGroupRole_t *)&v8);
          }
          if ( (v33 & 0x400) != 0 )
          {
            v8 = v16;
            idList<idAnimWebBlendTree *,5>::Append(this: &v26, obj: (const encounterGroupRole_t *)&v8);
          }
          wcstombs(s: v34, pwcs: v29, n: 0x100u);
          idLib::Printf(fmt: "%3d: %s\n", v9, v34);
          idLib::Printf(fmt: "     %d channels, %d Hz\n", v31, v32);
          num = v26.num;
          if ( v26.num != v31 )
          {
            idLib::Printf(fmt: "^3WARNING: ^1Mismatch between # of channels and channel mask\n");
            num = v26.num;
          }
          if ( num == 1 )
          {
            idLib::Printf(fmt: v18, *v26.list);
          }
          else if ( num == 2 )
          {
            idLib::Printf(fmt: "     %s and %s\n", *(const char **)v26.list, *((const char **)v26.list + 1));
          }
          else if ( num > 2 )
          {
            idLib::Printf(fmt: "     %s", *(const char **)v26.list);
            v3 = v26.num;
            v4 = 1;
            if ( v26.num - 1 > 1 )
            {
              v5 = 1;
              do
              {
                idLib::Printf(fmt: ", %s", (const char *)v26.list[v5]);
                v3 = v26.num;
                ++v4;
                ++v5;
              }
              while ( v4 < v26.num - 1 );
            }
            idLib::Printf(fmt: ", and %s\n", v26.list[v3 - 1]);
          }
          if ( v11.num == 1 )
          {
            idLib::Printf(fmt: v20, *v11.list);
          }
          else if ( v11.num == 2 )
          {
            idLib::Printf(fmt: "     Default %s and %s\n", *(const char **)v11.list, *((const char **)v11.list + 1));
          }
          else if ( v11.num > 2 )
          {
            idLib::Printf(fmt: "     Default %s", *(const char **)v11.list);
            v6 = v11.num;
            if ( v11.num - 1 > 1 )
            {
              v7 = 1;
              do
              {
                idLib::Printf(fmt: ", %s", (const char *)v11.list[v7]);
                v6 = v11.num;
                ++v1;
                ++v7;
              }
              while ( v1 < v11.num - 1 );
            }
            idLib::Printf(fmt: ", and %s\n", v11.list[v6 - 1]);
          }
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v26);
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v11);
        }
        ++v9;
      }
      while ( v9 < v10 );
    }
  }
  else
  {
    idLib::Warning(fmt: "No xaudio object");
  }
}


// ========================================================================
// __unwind$225928
// EA  : 0x8299E160
// RVA : 0x0099E160
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void _unwind_225928()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1744 + 96));
}


// ========================================================================
// __unwind$225929
// EA  : 0x8299E188
// RVA : 0x0099E188
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void _unwind_225929()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1744 + 192));
}


// ========================================================================
// ?Shutdown@idSoundHardware_XAudio2@@QAAXXZ
// EA  : 0x8299E1B0
// RVA : 0x0099E1B0
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void __fastcall idSoundHardware_XAudio2::Shutdown(idSoundHardware_XAudio2 *this)
{
  int v2; // r29
  int v3; // r30
  idSoundVoice_XAudio2 *list; // r28
  int size; // r30
  idSoundVoice_XAudio2 *v6; // r29
  idStaticList<idSoundVoice_XAudio2 *,96> *p_freeVoices; // r30
  idStaticList<idSoundVoice_XAudio2 *,96> *p_zombieVoices; // r30
  IXAudio2SubmixVoice *pSubmixVoice; // r3
  IXAudio2MasteringVoice *pMasterVoice; // r3
  int v11; // r3
  int v12; // r4
  double v13; // fp31
  int v14; // r4
  double v15; // [sp+28h] [-A8h]
  __int64 v16; // [sp+50h] [-80h] BYREF
  __int64 v17; // [sp+58h] [-78h]
  int v18; // [sp+74h] [-5Ch]

  v2 = 0;
  if ( this->voices.num > 0 )
  {
    v3 = 0;
    do
    {
      idSoundVoice_XAudio2::DestroyInternal(this: &this->voices.list[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->voices.num );
  }
  if ( this->voices.listStatic == 0 || this->voices.listStatic == 2 )
  {
    list = this->voices.list;
    if ( list != nullptr )
    {
      size = this->voices.size;
      if ( size > 0 )
      {
        v6 = this->voices.list;
        do
        {
          idSoundVoice_XAudio2::~idSoundVoice_XAudio2(this: v6);
          --size;
          ++v6;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    this->voices.list = nullptr;
    this->voices.size = 0;
  }
  this->voices.num = 0;
  p_freeVoices = &this->freeVoices;
  if ( this->freeVoices.listStatic == 0 || this->freeVoices.listStatic == 2 )
  {
    if ( p_freeVoices->list != nullptr )
      idMem::Free(this: &mem, ptr: p_freeVoices->list, align: ALIGN_16);
    p_freeVoices->list = nullptr;
    this->freeVoices.size = 0;
  }
  this->freeVoices.num = 0;
  p_zombieVoices = &this->zombieVoices;
  if ( this->zombieVoices.listStatic == 0 || this->zombieVoices.listStatic == 2 )
  {
    if ( p_zombieVoices->list != nullptr )
      idMem::Free(this: &mem, ptr: p_zombieVoices->list, align: ALIGN_16);
    p_zombieVoices->list = nullptr;
    this->zombieVoices.size = 0;
  }
  this->zombieVoices.num = 0;
  if ( this->pXAudio2 != nullptr )
    ((void (__fastcall *)(IXAudio2 *, idSoundEngineCallback *))this->pXAudio2->UnregisterForCallbacks)(
      a1: this->pXAudio2,
      a2: &this->soundEngineCallback);
  pSubmixVoice = this->pSubmixVoice;
  if ( pSubmixVoice != nullptr )
  {
    pSubmixVoice->DestroyVoice(this: pSubmixVoice);
    this->pSubmixVoice = nullptr;
  }
  pMasterVoice = this->pMasterVoice;
  if ( pMasterVoice != nullptr )
  {
    pMasterVoice->SetEffectChain(this: pMasterVoice, a2: nullptr);
    this->pMasterVoice->DestroyVoice(this: this->pMasterVoice);
    this->pMasterVoice = nullptr;
  }
  if ( this->pXAudio2 != nullptr )
  {
    this->pXAudio2->GetPerformanceData(a1: this->pXAudio2, a2: (XAUDIO2_PERFORMANCE_DATA *)&v16);
    this->pXAudio2->Release(a1: this->pXAudio2);
    v11 = v16;
    this->pXAudio2 = nullptr;
    v13 = (float)_u64tod(a1: v11, a2: v12);
    v15 = (float)((float)v13 / (float)_u64tod(a1: v17, a2: v14));
    idLib::Printf(
      fmt: "Final pXAudio2 performanceData: Voices: %d/%d CPU: %.2f%% Mem: %dkb\n",
      v18,
      HIDWORD(v15),
      v15,
      LODWORD(v15));
  }
  if ( this->vuMeterRMS != nullptr )
  {
    ((void (__fastcall *)(idConsole *))console->DestroyGraph)(a1: console);
    this->vuMeterRMS = nullptr;
  }
  if ( this->vuMeterPeak != nullptr )
  {
    ((void (__fastcall *)(idConsole *))console->DestroyGraph)(a1: console);
    this->vuMeterPeak = nullptr;
  }
}


// ========================================================================
// ?FreeVoice@idSoundHardware_XAudio2@@QAAXPAVidSoundVoice@@@Z
// EA  : 0x8299E430
// RVA : 0x0099E430
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void __fastcall idSoundHardware_XAudio2::FreeVoice(idSoundHardware_XAudio2 *this, idSoundVoice *voice)
{
  idSoundVoice *v3; // [sp+50h] [-20h] BYREF

  v3 = voice;
  idSoundVoice_XAudio2::Stop(this: voice);
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->zombieVoices,
    obj: (const encounterGroupRole_t *)&v3);
}


// ========================================================================
// ?Update@idSoundHardware_XAudio2@@QAAXXZ
// EA  : 0x8299E480
// RVA : 0x0099E480
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void __fastcall idSoundHardware_XAudio2::Update(idSoundHardware_XAudio2 *this)
{
  int v2; // r31
  int v3; // r29
  idStaticList<idSoundVoice_XAudio2 *,96> *p_zombieVoices; // r28
  int num; // r11
  int v6; // r11
  int v7; // r4
  double v8; // fp31
  int v9; // r4
  idDebugGraph *vuMeterRMS; // r10
  IXAudio2MasteringVoice_vtbl *v11; // r11
  unsigned int outputChannels; // r11
  int v13; // r24
  const idColor *v14; // r5
  int v15; // r31
  int v16; // r29
  int *vuMeterPeakTimes; // r28
  const idColor *v18; // r5
  int v19; // r3
  __int64 v20; // r10
  double v21; // fp0
  unsigned int v22; // r31
  double v23; // fp12
  double v24; // fp11
  idDebugGraph *v25; // r11
  __int64 v26; // r8
  double v27; // fp6
  idDebugGraph *vuMeterPeak; // r11
  double v29; // fp5
  double v30; // fp4
  int v31; // r27
  int *v32; // r28
  int v33; // r29
  idDebugGraph *v34; // r3
  idDebugGraph *v35; // r3
  double v36; // fp1
  double v37; // [sp+28h] [-148h]
  float v38; // [sp+50h] [-120h] BYREF
  float v39; // [sp+54h] [-11Ch] BYREF
  float v40; // [sp+58h] [-118h] BYREF
  float v41; // [sp+5Ch] [-114h] BYREF
  _DWORD v42[2]; // [sp+60h] [-110h] BYREF
  unsigned int v43; // [sp+68h] [-108h]
  __int64 v44; // [sp+70h] [-100h]
  float v45[4]; // [sp+80h] [-F0h] BYREF
  _BYTE v46[32]; // [sp+90h] [-E0h] BYREF
  __int64 v47; // [sp+B0h] [-C0h] BYREF
  __int64 v48; // [sp+B8h] [-B8h]
  int v49; // [sp+D4h] [-9Ch]
  _BYTE v50[32]; // [sp+F0h] [-80h] BYREF

  if ( this->pXAudio2 != nullptr )
  {
    if ( masteringLimiterState != MASTERINGLIMITER_STATE_OFF )
    {
      if ( masteringLimiterState == MASTERINGLIMITER_STATE_ON_CHANGED )
      {
        this->pMasterVoice->EnableEffect(this: this->pMasterVoice, a2: 0, a3: 0);
        this->pMasterVoice->SetEffectParameters(
          this: this->pMasterVoice,
          a2: 0,
          a3: &masteringLimiterParams,
          a4: 8u,
          a5: 0);
        masteringLimiterState = MASTERINGLIMITER_STATE_ON;
      }
    }
    else
    {
      this->pMasterVoice->DisableEffect(this: this->pMasterVoice, a2: 0, a3: 0);
    }
    this->pXAudio2->CommitChanges(a1: this->pXAudio2, a2: 0);
    v2 = 0;
    if ( this->zombieVoices.num > 0 )
    {
      v3 = 0;
      p_zombieVoices = &this->zombieVoices;
      do
      {
        idSoundVoice_XAudio2::FlushSourceBuffers(this: p_zombieVoices->list[v3]);
        if ( idSoundVoice_XAudio2::IsPlaying(this: p_zombieVoices->list[v3]) )
        {
          ++playingZombies;
        }
        else
        {
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&this->freeVoices,
            obj: (const encounterGroupRole_t *)&p_zombieVoices->list[v3]);
          if ( v2 >= 0 )
          {
            num = this->zombieVoices.num;
            if ( v2 < num )
            {
              v6 = num - 1;
              this->zombieVoices.num = v6;
              if ( v2 != v6 )
                p_zombieVoices->list[v3] = p_zombieVoices->list[v6];
            }
          }
          --v2;
          --v3;
        }
        ++v2;
        ++v3;
      }
      while ( v2 < this->zombieVoices.num );
    }
    if ( s_showPerfData.valueInteger != 0 )
    {
      this->pXAudio2->GetPerformanceData(a1: this->pXAudio2, a2: (XAUDIO2_PERFORMANCE_DATA *)&v47);
      v8 = (float)_u64tod(a1: v47, a2: v7);
      v37 = (float)((float)v8 / (float)_u64tod(a1: v48, a2: v9));
      idLib::Printf(fmt: "Voices: %d/%d CPU: %.2f%% Mem: %dkb\n", v49, HIDWORD(v37), v37, LODWORD(v37));
    }
    vuMeterRMS = this->vuMeterRMS;
    if ( vuMeterRMS != nullptr )
    {
      vuMeterRMS->enable = s_showLevelMeter.valueInteger != 0;
      this->vuMeterPeak->enable = s_showLevelMeter.valueInteger != 0;
      v11 = this->pMasterVoice->__vftable;
      if ( s_showLevelMeter.valueInteger != 0 )
      {
        ((void (*)(void))v11->EnableEffect)();
        outputChannels = this->outputChannels;
        v42[0] = v50;
        v42[1] = v46;
        v43 = outputChannels;
        if ( outputChannels > 8 )
          v43 = 8;
        this->pMasterVoice->GetEffectParameters(this: this->pMasterVoice, a2: 1u, a3: v42, a4: 12u);
        v13 = Sys_Milliseconds();
        v15 = 0;
        if ( this->outputChannels > 0 )
        {
          v16 = 0;
          vuMeterPeakTimes = this->vuMeterPeakTimes;
          do
          {
            if ( *vuMeterPeakTimes < v13 )
              idDebugGraph::SetValue(
                this: this->vuMeterPeak,
                b: v15,
                value: (float)(this->vuMeterPeak->bars.list[v16].value * (float)0.89999998),
                color: v14,
                a5: &idColor::colorRed.r);
            ++v15;
            ++vuMeterPeakTimes;
            ++v16;
          }
          while ( v15 < this->outputChannels );
        }
        v40 = 20.0;
        v39 = 200.0;
        v41 = 100.0;
        v38 = 100.0;
        v19 = sscanf(string: s_meterPosition.valueString.data, format: "%f %f %f %f", &v41, &v38, &v40, &v39);
        LODWORD(v20) = v43;
        v21 = v40;
        v22 = 0;
        v23 = v38;
        v24 = v41;
        ignoredReturnValue = v19;
        v44 = v20;
        v25 = this->vuMeterRMS;
        v25->position.w = v39;
        v25->position.x = v24;
        v25->position.y = v23;
        v25->position.z = (float)v20 * (float)v21;
        LODWORD(v26) = v43;
        v27 = v40;
        v44 = v26;
        vuMeterPeak = this->vuMeterPeak;
        v29 = v39;
        v30 = v38;
        vuMeterPeak->position.x = v41;
        vuMeterPeak->position.y = v30;
        vuMeterPeak->position.w = v29;
        vuMeterPeak->position.z = (float)v26 * (float)v27;
        if ( v43 != 0 )
        {
          v31 = 0;
          v32 = this->vuMeterPeakTimes;
          v33 = 0;
          do
          {
            v45[0] = 0.5;
            v45[1] = 1.0;
            v45[2] = 0.0;
            v34 = this->vuMeterRMS;
            v45[3] = 1.0;
            idDebugGraph::SetValue(this: v34, b: v22, value: *(float *)&v46[v33], color: v18, a5: v45);
            v35 = this->vuMeterPeak;
            v36 = *(float *)&v50[v33];
            if ( v36 >= v35->bars.list[v31].value )
            {
              idDebugGraph::SetValue(this: v35, b: v22, value: v36, color: v18, a5: &idColor::colorRed.r);
              *v32 = s_meterTopTime.valueInteger + v13;
            }
            ++v22;
            ++v31;
            v33 += 4;
            ++v32;
          }
          while ( v22 < v43 );
        }
      }
      else
      {
        ((void (*)(void))v11->DisableEffect)();
      }
    }
  }
}


// ========================================================================
// ??0idSoundHardware_XAudio2@@QAA@XZ
// EA  : 0x8299ED00
// RVA : 0x0099ED00
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

idSoundHardware_XAudio2 *__fastcall idSoundHardware_XAudio2::idSoundHardware_XAudio2(idSoundHardware_XAudio2 *this)
{
  idStaticList<idSoundVoice_XAudio2,96> *p_voices; // r26

  p_voices = &this->voices;
  this->soundEngineCallback.__vftable = (idSoundEngineCallback_vtbl *)&idSoundEngineCallback::`vftable';
  idStaticList<idSoundVoice_XAudio2,96>::idStaticList<idSoundVoice_XAudio2,96>(this: &this->voices);
  this->zombieVoices.size = 96;
  this->zombieVoices.num = 0;
  this->zombieVoices.granularity = 1;
  this->zombieVoices.list = this->zombieVoices.staticList;
  this->zombieVoices.memTag = 5;
  this->zombieVoices.listStatic = 1;
  this->freeVoices.size = 96;
  this->freeVoices.num = 0;
  this->freeVoices.granularity = 1;
  this->freeVoices.list = this->freeVoices.staticList;
  this->freeVoices.memTag = 5;
  this->freeVoices.listStatic = 1;
  this->pXAudio2 = nullptr;
  this->pMasterVoice = nullptr;
  this->pSubmixVoice = nullptr;
  this->vuMeterRMS = nullptr;
  this->vuMeterPeak = nullptr;
  this->dryGain = 0.0;
  this->outputChannels = 0;
  this->channelMask = 0;
  if ( this->voices.size < 0 )
    idList<idSoundVoice_XAudio2,5>::Clear(this: p_voices);
  p_voices->num = __CFADD__(-p_voices->size, p_voices->size ^ 0x80000000) ? 0 : p_voices->size;
  if ( this->zombieVoices.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->zombieVoices);
  this->zombieVoices.num = __CFADD__(-this->zombieVoices.size, this->zombieVoices.size ^ 0x80000000)
                         ? 0
                         : this->zombieVoices.size;
  if ( this->freeVoices.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->freeVoices);
  this->freeVoices.num = __CFADD__(-this->freeVoices.size, this->freeVoices.size ^ 0x80000000)
                       ? 0
                       : this->freeVoices.size;
  return this;
}


// ========================================================================
// __unwind$226474
// EA  : 0x8299EE5C
// RVA : 0x0099EE5C
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void _unwind_226474()
{
  int v0; // r12

  idStaticList<idSoundVoice_XAudio2,96>::~idStaticList<idSoundVoice_XAudio2,96>(this: (idStaticList<idSoundVoice_XAudio2,96> *)(*(_DWORD *)(v0 - 144 + 164) + 72));
}


// ========================================================================
// __unwind$226475
// EA  : 0x8299EE88
// RVA : 0x0099EE88
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void _unwind_226475()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 33880));
}


// ========================================================================
// __unwind$226476
// EA  : 0x8299EEBC
// RVA : 0x0099EEBC
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void _unwind_226476()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 34280));
}


// ========================================================================
// ?Init@idSoundHardware_XAudio2@@QAAXXZ
// EA  : 0x8299EEF0
// RVA : 0x0099EEF0
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void __fastcall idSoundHardware_XAudio2::Init(idSoundHardware_XAudio2 *this)
{
  __int64 v2; // r30
  IXAudio2 *pXAudio2; // r3
  unsigned int valueInteger; // r28
  int v5; // r27
  unsigned int i; // r29
  unsigned int v7; // r3
  int v8; // r4
  int outputChannels; // r8
  int v10; // r3
  idDebugGraph *v11; // r3
  idDebugGraph *vuMeterRMS; // r10
  idDebugGraph *vuMeterPeak; // r4
  float v14; // r3
  float v15; // r10
  float v16; // r9
  float v17; // r8
  idDebugGraph *v18; // r11
  idDebugGraph *v19; // r3
  const idColor *v20; // r4
  int v21; // r25
  int v22; // r28
  const char **v23; // r29
  int j; // r26
  int v25; // r11
  int v26; // r10
  idSoundVoice_XAudio2 *v27; // r7
  int v28; // [sp+50h] [-1280h] BYREF
  IUnknown *v29; // [sp+54h] [-127Ch] BYREF
  IUnknown *v30; // [sp+58h] [-1278h] BYREF
  IUnknown *v31; // [sp+5Ch] [-1274h] BYREF
  int v32; // [sp+60h] [-1270h] BYREF
  _DWORD *v33; // [sp+64h] [-126Ch]
  _DWORD v34[2]; // [sp+68h] [-1268h] BYREF
  _DWORD v35[4]; // [sp+70h] [-1260h] BYREF
  float v36; // [sp+80h] [-1250h]
  float v37; // [sp+84h] [-124Ch]
  float v38; // [sp+88h] [-1248h]
  float v39; // [sp+8Ch] [-1244h]
  idColor v40; // [sp+90h] [-1240h] BYREF
  idColor v41; // [sp+A0h] [-1230h] BYREF
  idColor v42; // [sp+B0h] [-1220h] BYREF
  _DWORD v43[8]; // [sp+C0h] [-1210h] BYREF
  _DWORD v44[12]; // [sp+E0h] [-11F0h] BYREF
  _BYTE v45[1030]; // [sp+110h] [-11C0h] BYREF
  unsigned __int16 v46; // [sp+516h] [-DBAh]
  _BYTE v47[1030]; // [sp+540h] [-D90h] BYREF
  unsigned __int16 v48; // [sp+946h] [-98Ah]
  int v49; // [sp+958h] [-978h]
  idCmdArgs v50; // [sp+970h] [-960h] BYREF

  if ( XAudio2Create(ppXAudio2: &this->pXAudio2, uFlags: 0, eXAudio2Processor: 0x30u) < 0 )
    idLib::FatalError(fmt: "Failed to create XAudio2 engine.  Try installing the latest DirectX.");
  ((void (__fastcall *)(IXAudio2 *, idSoundEngineCallback *))this->pXAudio2->RegisterForCallbacks)(
    a1: this->pXAudio2,
    a2: &this->soundEngineCallback);
  LODWORD(v2) = 0;
  this->soundEngineCallback.hardware = this;
  pXAudio2 = this->pXAudio2;
  v28 = 0;
  if ( pXAudio2->GetDeviceCount(a1: pXAudio2, a2: (unsigned int *)&v28) != 0 || v28 == 0 )
  {
    idLib::Warning(fmt: "No audio devices found");
    goto LABEL_30;
  }
  v50.argc = 0;
  listDevices_f(args: &v50);
  valueInteger = s_device.valueInteger;
  if ( s_device.valueInteger < 0 || s_device.valueInteger >= v28 )
  {
    v5 = 0;
    for ( i = 0; i < v28; ++i )
    {
      if ( this->pXAudio2->GetDeviceDetails(a1: this->pXAudio2, a2: i, a3: (XAUDIO2_DEVICE_DETAILS *)v45) == 0 )
      {
        if ( (v45[1027] & 8) != 0 )
        {
          valueInteger = i;
          break;
        }
        if ( v46 > v5 )
        {
          valueInteger = i;
          v5 = v46;
        }
      }
    }
  }
  idLib::Printf(fmt: "Using device %d\n", valueInteger);
  if ( this->pXAudio2->GetDeviceDetails(a1: this->pXAudio2, a2: valueInteger, a3: (XAUDIO2_DEVICE_DETAILS *)v47) != 0 )
  {
    idLib::Warning(fmt: "Failed to get device details");
LABEL_30:
    this->pXAudio2->Release(a1: this->pXAudio2);
    this->pXAudio2 = nullptr;
    return;
  }
  HIDWORD(v2) = &this->pMasterVoice;
  if ( this->pXAudio2->CreateMasteringVoice(
         a1: this->pXAudio2,
         a2: &this->pMasterVoice,
         a3: 0,
         a4: 44100u,
         a5: 0,
         a6: valueInteger,
         a7: nullptr) < 0 )
  {
    idLib::Warning(fmt: "Failed to create master voice");
    goto LABEL_30;
  }
  v7 = v48;
  v8 = v49;
  this->outputChannels = v48;
  this->channelMask = v8;
  idSoundVoice_Base::InitSurround(outputChannels: v7, channelMask: v8);
  v31 = nullptr;
  CreateAudioVolumeMeter(ppApo: &v31);
  v30 = nullptr;
  CreateFX(
    clsid: (const _GUID *)&GUID_a90bc001_e897_e897_7439_435500000001,
    pEffect: &v30,
    pInitData: nullptr,
    InitDataByteSize: 0);
  outputChannels = this->outputChannels;
  v43[1] = 1;
  v43[4] = 1;
  v32 = 2;
  v33 = v43;
  v43[2] = outputChannels;
  v43[0] = v30;
  v43[3] = v31;
  v43[5] = outputChannels;
  (*(void (__fastcall **)(_DWORD, int *))(**(_DWORD **)HIDWORD(v2) + 8))(a1: *(_DWORD *)HIDWORD(v2), a2: &v32);
  v31->Release(this: v31);
  v30->Release(this: v30);
  v34[0] = 2;
  v10 = *(_DWORD *)HIDWORD(v2);
  v34[1] = 400;
  (*(void (__fastcall **)(int, _DWORD, _DWORD *, int, _DWORD))(*(_DWORD *)v10 + 24))(
    a1: v10,
    a2: 0,
    a3: v34,
    a4: 8,
    a5: 0);
  (*(void (__fastcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)HIDWORD(v2) + 16))(
    a1: *(_DWORD *)HIDWORD(v2),
    a2: 0,
    a3: 0);
  HIDWORD(v2) = &consoleFont[21088];
  this->vuMeterRMS = console->CreateGraph(this: console, a2: this->outputChannels);
  v11 = console->CreateGraph(this: console, a2: this->outputChannels);
  vuMeterRMS = this->vuMeterRMS;
  this->vuMeterPeak = v11;
  vuMeterRMS->enable = false;
  v36 = 0.0;
  vuMeterPeak = this->vuMeterPeak;
  v37 = 0.0;
  vuMeterPeak->enable = false;
  v38 = 0.0;
  *(_QWORD *)this->vuMeterPeakTimes = v2;
  *(_QWORD *)&this->vuMeterPeakTimes[2] = v2;
  *(_QWORD *)&this->vuMeterPeakTimes[4] = v2;
  v39 = 0.0;
  *(_QWORD *)&this->vuMeterPeakTimes[6] = v2;
  v14 = v37;
  v15 = v38;
  v16 = v39;
  v17 = v36;
  this->vuMeterPeak->mode = GRAPH_LINE;
  v18 = this->vuMeterPeak;
  v18->bgColor.r = v17;
  v18->bgColor.g = v14;
  v18->bgColor.b = v15;
  v18->bgColor.a = v16;
  v41.r = 0.5;
  v41.g = 0.5;
  v19 = this->vuMeterRMS;
  v41.b = 0.5;
  v41.a = 1.0;
  idDebugGraph::AddGridLine(this: v19, value: 0.5, color: (const idColor *)vuMeterPeak, a4: &v41);
  v40.r = 0.5;
  v40.g = 0.5;
  v40.b = 0.5;
  v40.a = 1.0;
  idDebugGraph::AddGridLine(this: this->vuMeterRMS, value: 0.25, color: (const idColor *)&unk_82150000, a4: &v40);
  v42.r = 0.5;
  v42.g = 0.5;
  v42.b = 0.5;
  v42.a = 1.0;
  idDebugGraph::AddGridLine(this: this->vuMeterRMS, value: 0.125, color: v20, a4: &v42);
  v44[0] = "L";
  v44[1] = "R";
  v44[2] = "C";
  v44[3] = "S";
  v44[4] = "Lb";
  v44[5] = "Rb";
  v44[6] = "Lf";
  v44[7] = "Rf";
  v44[9] = "Ls";
  v21 = 0;
  v44[10] = "Rs";
  v44[8] = "Cb";
  v22 = 1;
  v23 = (const char **)v44;
  for ( j = 11; j != 0; --j )
  {
    if ( (this->channelMask & v22) != 0 )
      idDebugGraph::SetLabel(this: this->vuMeterRMS, b: v21++, text: *v23);
    ++v23;
    v22 = __ROL4__(v22, 1);
  }
  v29 = nullptr;
  CreateAudioReverb(ppApo: &v29);
  v33 = v35;
  v35[2] = 1;
  v32 = 1;
  v35[1] = 1;
  v35[0] = v29;
  if ( this->pXAudio2->CreateSubmixVoice(
         a1: this->pXAudio2,
         a2: &this->pSubmixVoice,
         a3: 1u,
         a4: 44100u,
         a5: 0,
         a6: 0,
         a7: nullptr,
         a8: (const XAUDIO2_EFFECT_CHAIN *)&v32) < 0 )
    idLib::FatalError(fmt: "Failed to create submix voice");
  v29->Release(this: v29);
  idList<idSoundVoice_XAudio2,5>::SetNum(this: &this->voices, newNum: this->voices.size);
  idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->freeVoices, newNum: this->voices.size);
  idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->zombieVoices, newNum: 0);
  v25 = 0;
  if ( this->voices.num > 0 )
  {
    v26 = 0;
    do
    {
      ++v25;
      v27 = (idSoundVoice_XAudio2 *)((char *)this->voices.list + v2);
      LODWORD(v2) = v2 + 352;
      this->freeVoices.list[v26++] = v27;
    }
    while ( v25 < this->voices.num );
  }
}


// ========================================================================
// `dynamic initializer for 's_showLevelMeter''
// EA  : 0x83361638
// RVA : 0x01361638
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_showLevelMeter__()
{
  idCVar::idCVar(
    this: &s_showLevelMeter,
    name: "s_showLevelMeter",
    value: "0",
    flags: 1,
    description: "Show VU meter",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_showLevelMeter__);
}


// ========================================================================
// `dynamic initializer for 's_meterTopTime''
// EA  : 0x83361690
// RVA : 0x01361690
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_meterTopTime__()
{
  idCVar::idCVar(
    this: &s_meterTopTime,
    name: "s_meterTopTime",
    value: "1000",
    flags: 2,
    description: "How long (in milliseconds) peaks are displayed on the VU meter",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_meterTopTime__);
}


// ========================================================================
// `dynamic initializer for 's_meterPosition''
// EA  : 0x833616E8
// RVA : 0x013616E8
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_meterPosition__()
{
  idCVar::idCVar(
    this: &s_meterPosition,
    name: "s_meterPosition",
    value: "100 100 20 200",
    flags: 0,
    description: "VU meter location (x y w h)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_meterPosition__);
}


// ========================================================================
// `dynamic initializer for 's_showReverb''
// EA  : 0x83361740
// RVA : 0x01361740
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_showReverb__()
{
  idCVar::idCVar(
    this: &s_showReverb,
    name: "s_showReverb",
    value: "0",
    flags: 1,
    description: "show the reverb parameters",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_showReverb__);
}


// ========================================================================
// `dynamic initializer for 's_device''
// EA  : 0x83361798
// RVA : 0x01361798
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_device__()
{
  idCVar::idCVar(
    this: &s_device,
    name: "s_device",
    value: "-1",
    flags: 2,
    description: "Which audio device to use (listDevices to list, -1 for default)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_device__);
}


// ========================================================================
// `dynamic initializer for 's_showPerfData''
// EA  : 0x833617F0
// RVA : 0x013617F0
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_showPerfData__()
{
  idCVar::idCVar(
    this: &s_showPerfData,
    name: "s_showPerfData",
    value: "0",
    flags: 1,
    description: "Show XAudio2 Performance data",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_showPerfData__);
}


// ========================================================================
// `dynamic initializer for 's_xa2_limiter_v''
// EA  : 0x83361848
// RVA : 0x01361848
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__s_xa2_limiter_v__()
{
  return idCommandLink::idCommandLink(
           this: &s_xa2_limiter_v,
           cmdName: "s_xa2_limiter",
           function: s_xa2_limiter_f,
           description: "Controlls the parameters for the XAudio2 mastering limiter",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'listDevices_v''
// EA  : 0x83361870
// RVA : 0x01361870
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundhardware.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__listDevices_v__()
{
  return idCommandLink::idCommandLink(
           this: &listDevices_v,
           cmdName: "listDevices",
           function: listDevices_f,
           description: "Lists the connected sound devices",
           argCompletion: nullptr);
}

