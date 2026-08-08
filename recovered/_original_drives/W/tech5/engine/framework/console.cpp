
// ========================================================================
// ?Init@idConsoleLocal@@UAAXXZ
// EA  : 0x826636D8
// RVA : 0x006636D8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::Init(idConsoleLocal *this)
{
  idPrintListener::RegisterPrintListener(this: &this->idPrintListener);
  this->keyCatching = false;
  this->nextKeyEvent = 0;
  idEditField::Clear(this: &this->consoleField);
  this->snapshotsLocked = false;
}


// ========================================================================
// ?IsActive@idConsoleLocal@@UAA_NXZ
// EA  : 0x82663740
// RVA : 0x00663740
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

int __fastcall idConsoleLocal::IsActive(idConsoleLocal *this)
{
  unsigned __int8 v1; // r11

  if ( this->keyCatching )
    return 1;
  v1 = 0;
  if ( this->lastFullscreen )
    return 1;
  return v1;
}


// ========================================================================
// ?Scroll@idConsoleLocal@@AAAXXZ
// EA  : 0x82663770
// RVA : 0x00663770
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::Scroll(idConsoleLocal *this)
{
  int v2; // r27
  int *p_nextKeyEvent; // r31
  __int16 *v4; // r30
  int *v5; // r29
  int *v6; // r30
  int v7; // r10
  int v8; // r11
  int v9; // r9
  idGame *v10; // r3
  int v11; // r5
  __int16 *v12; // r30
  int *v13; // r29
  int *v14; // r30
  int v15; // r10
  int v16; // r11
  idGame *v17; // r3
  int v18; // r5

  p_nextKeyEvent = &this->nextKeyEvent;
  v2 = Sys_Milliseconds();
  if ( this->nextKeyEvent <= v2 )
  {
    if ( idKeyInput::IsDown(deviceNum: 0, keyNum: K_PGUP) )
    {
      if ( *p_nextKeyEvent <= v2 )
      {
        v4 = &this->text.ptr[65008];
        v5 = (int *)(v4 + 8722);
        v6 = (int *)(v4 + 8728);
        do
        {
          v7 = *v5;
          v8 = *v6 - 2;
          v9 = *v5 - v8;
          *v6 = v8;
          if ( v9 >= 4096 )
            *v6 = v7 - 4095;
          v10 = common->Game(this: common);
          v11 = v10->GetGameMsPerFrame(this: v10, a2: GAMETIME_NORMAL) + *p_nextKeyEvent;
          *p_nextKeyEvent = v11;
        }
        while ( v11 <= v2 );
      }
    }
    else if ( idKeyInput::IsDown(deviceNum: 0, keyNum: K_PGDN) && *p_nextKeyEvent <= v2 )
    {
      v12 = &this->text.ptr[65008];
      v13 = (int *)(v12 + 8722);
      v14 = (int *)(v12 + 8728);
      do
      {
        v15 = *v13;
        v16 = *v14 + 2;
        *v14 = v16;
        if ( v16 > v15 )
          *v14 = v15;
        v17 = common->Game(this: common);
        v18 = v17->GetGameMsPerFrame(this: v17, a2: GAMETIME_NORMAL) + *p_nextKeyEvent;
        *p_nextKeyEvent = v18;
      }
      while ( v18 <= v2 );
    }
  }
}


// ========================================================================
// ?Activate@idConsoleLocal@@QAAXM@Z
// EA  : 0x826638E0
// RVA : 0x006638E0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::Activate(idConsoleLocal *this, double displayFrac)
{
  this->finalFrac = displayFrac;
  this->fracTime = Sys_Milliseconds();
  this->keyCatching = displayFrac != 0.0;
}


// ========================================================================
// ?WordWrap@idConsoleLocal@@ABA_NPBFHHH@Z
// EA  : 0x82663950
// RVA : 0x00663950
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

int __fastcall idConsoleLocal::WordWrap(
        idConsoleLocal *this,
        const __int16 *line,
        int index,
        int offset,
        int numColumns)
{
  int result; // r3
  const __int16 *v6; // r9
  int v7; // r10
  int v8; // r11

  if ( offset >= numColumns )
    return 1;
  v6 = &line[index];
  if ( (unsigned __int8)*v6 <= 0x20u || index != 0 && (unsigned __int8)*(v6 - 1) > 0x20u )
    return 0;
  v7 = 0;
  v8 = offset;
  do
  {
    if ( (unsigned __int8)*v6 <= 0x20u )
      break;
    ++v8;
    ++v7;
    ++v6;
  }
  while ( v8 < numColumns );
  if ( v7 >= numColumns )
    return 0;
  result = 1;
  if ( v7 + offset < numColumns )
    return 0;
  return result;
}


// ========================================================================
// `idConsoleLocal::DrawSnapshots'::`18'::local_t::R_QsortSnapObjects
// EA  : 0x826639E0
// RVA : 0x006639E0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

int __fastcall _idConsoleLocal::DrawSnapshots_::_18_::local_t::R_QsortSnapObjects(const void *a, const void *b)
{
  return *(_DWORD *)(*(_DWORD *)b + 20) - *(_DWORD *)(*(_DWORD *)a + 20);
}


// ========================================================================
// ?DrawSnapshotReport@idConsoleLocal@@AAAXXZ
// EA  : 0x826639F8
// RVA : 0x006639F8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::DrawSnapshotReport(idConsoleLocal *this)
{
  idRenderModelGui *v2; // r3
  bool v3; // [sp+Bh] [-65h]

  v2 = this->Gui(this);
  idSnapshotMetrics::GenerateReport(
    this: &snapshotMetrics,
    ss: this->snapshots,
    oldss: &this->snapshots[1],
    seq: this->snapshotSeqs[0],
    baseSeq: this->snapshotSeqs[1],
    peer: this->snapshotPeerNum,
    gui: v2,
    reportMetrics: false,
    printConsole: v3);
}


// ========================================================================
// ?SetBitmapConsole@idConsoleLocal@@UAAXPAE0HHH@Z
// EA  : 0x82663A80
// RVA : 0x00663A80
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::SetBitmapConsole(
        idConsoleLocal *this,
        unsigned __int8 *frontBuffer0,
        unsigned __int8 *frontBuffer1,
        int width,
        int height,
        int bytePitch)
{
  this->bitmapConsoleBuffers[0] = frontBuffer0;
  this->bitmapConsoleBuffers[1] = frontBuffer1;
  this->bitmapConsoleWidth = width;
  this->bitmapConsoleHeight = height;
  this->bitmapConsoleBytePitch = bytePitch;
}


// ========================================================================
// ?makeConsoleFont_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82663AD0
// RVA : 0x00663AD0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall makeConsoleFont_f(const idCmdArgs *args)
{
  idFile *v1; // r30
  int v2; // r24
  int i; // r21
  int v4; // r26
  int v5; // r25
  int v6; // r29
  int j; // r28
  int k; // r31
  unsigned __int8 *v9; // [sp+50h] [-80h] BYREF
  int v10; // [sp+54h] [-7Ch] BYREF
  int v11; // [sp+58h] [-78h] BYREF

  R_LoadTGA(name: "textures/consoleFont.tga", pic: &v9, width: &v11, height: &v10, timestamp: nullptr);
  v1 = fileSystem->OpenFileWrite(this: fileSystem, a2: "consoleFont.cpp", a3: 0);
  v1->Printf(this: v1, a2: "// 16x32 font images for characters 32 - 128\n");
  v1->Printf(this: v1, a2: "byte consoleFont[(128-32)*16*32+1] = {\n");
  v2 = 32;
  for ( i = 0x4000; i < 0x10000; i += 0x2000 )
  {
    v4 = 0;
    v5 = i;
    do
    {
      v1->Printf(this: v1, a2: "/* %c */\n", v2 + v4);
      v6 = v5;
      for ( j = 32; j != 0; --j )
      {
        for ( k = 0; k < 16; ++k )
          v1->Printf(this: v1, a2: "%3i,", v9[4 * v6 + 3 + 4 * k]);
        v1->Printf(this: v1, a2: "\n");
        v6 += 256;
      }
      ++v4;
      v5 += 16;
    }
    while ( v4 < 16 );
    v2 += 16;
  }
  v1->Printf(this: v1, a2: "\n};\n");
  ((void (__fastcall *)(idFile *, int))v1->dtr_idFile)(a1: v1, a2: 1);
  idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
}


// ========================================================================
// ?AddText@idWarningCollector@@QAAXPBD@Z
// EA  : 0x82663DA8
// RVA : 0x00663DA8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idWarningCollector::AddText(idWarningCollector *this, char *textIn)
{
  char v2; // r11
  int i; // r9
  char v5; // r10
  const char **v6; // r31
  char v7; // r11
  int numWarningsTotal; // r11
  const char **v9; // r31
  char v10; // r11
  const char **v11; // r31
  char v12; // r11
  const char **v13; // r31
  char v14; // r11
  const char **v15; // r31
  char v16; // r11
  const char **v17; // r31
  char v18; // r11
  const char **v19; // r31
  char v20; // r11
  const char **v21; // r31
  char v22; // r11
  const char **v23; // r31
  char v24; // r11
  const char **v25; // r31
  char v26; // r11
  const char **v27; // r31
  char v28; // r11
  const char **v29; // r31
  char v30; // r11
  const char **v31; // r31
  char v32; // r11
  const char **v33; // r31
  char v34; // r11
  char v35[8]; // [sp+50h] [-430h] BYREF
  char v36[1064]; // [sp+58h] [-428h] BYREF

  v2 = *textIn;
  for ( i = 0; *textIn != 0; v2 = *textIn )
  {
    if ( v2 != 94 || textIn[1] == 0 || (v5 = 1, textIn[1] == 32) )
      v5 = 0;
    if ( v5 != 0 )
    {
      textIn += 2;
    }
    else
    {
      if ( i >= 1023 )
        break;
      ++textIn;
      v35[i++] = v2;
    }
  }
  v35[i] = 0;
  if ( idStr::Find(
         searchIn: v35,
         searchFor: "--------- Initializing Game ----------",
         casesensitive: true,
         start: 0,
         end: -1) == -1 )
  {
    if ( idStr::Find(searchIn: v35, searchFor: "WARNING: ", casesensitive: true, start: 0, end: -1) != -1 )
    {
      v6 = g_ignoreWarningTypes;
      while ( idStr::Find(searchIn: v36, searchFor: *v6, casesensitive: true, start: 0, end: -1) == -1 )
      {
        if ( (int)++v6 >= (int)g_syntaxErrorWarningTypes )
        {
          v7 = 0;
          goto LABEL_18;
        }
      }
      v7 = 1;
LABEL_18:
      if ( v7 == 0 )
      {
        numWarningsTotal = this->numWarningsTotal;
        v9 = g_syntaxErrorWarningTypes;
        this->showTimer = 0;
        this->numWarningsTotal = numWarningsTotal + 1;
        while ( idStr::Find(searchIn: v36, searchFor: *v9, casesensitive: true, start: 0, end: -1) == -1 )
        {
          if ( (int)++v9 >= (int)g_duplicateWarningTypes )
          {
            v10 = 0;
            goto LABEL_23;
          }
        }
        v10 = 1;
LABEL_23:
        if ( v10 != 0 )
        {
          ++this->numSyntaxErrors;
        }
        else
        {
          v11 = g_duplicateWarningTypes;
          while ( idStr::Find(searchIn: v36, searchFor: *v11, casesensitive: true, start: 0, end: -1) == -1 )
          {
            if ( (int)++v11 >= (int)g_animWebWarningTypes )
            {
              v12 = 0;
              goto LABEL_31;
            }
          }
          v12 = 1;
LABEL_31:
          if ( v12 != 0 )
          {
            ++this->numDuplicate;
          }
          else
          {
            v13 = g_animWebWarningTypes;
            while ( idStr::Find(searchIn: v36, searchFor: *v13, casesensitive: true, start: 0, end: -1) == -1 )
            {
              if ( (int)++v13 >= (int)g_audioWarningTypes )
              {
                v14 = 0;
                goto LABEL_38;
              }
            }
            v14 = 1;
LABEL_38:
            if ( v14 != 0 )
            {
              ++this->numAnimWeb;
            }
            else
            {
              v15 = g_audioWarningTypes;
              while ( idStr::Find(searchIn: v36, searchFor: *v15, casesensitive: true, start: 0, end: -1) == -1 )
              {
                if ( (int)++v15 >= (int)g_effectsWarningTypes )
                {
                  v16 = 0;
                  goto LABEL_45;
                }
              }
              v16 = 1;
LABEL_45:
              if ( v16 != 0 )
              {
                ++this->numAudio;
              }
              else
              {
                v17 = g_effectsWarningTypes;
                while ( idStr::Find(searchIn: v36, searchFor: *v17, casesensitive: true, start: 0, end: -1) == -1 )
                {
                  if ( (int)++v17 >= (int)g_animWarningTypes )
                  {
                    v18 = 0;
                    goto LABEL_52;
                  }
                }
                v18 = 1;
LABEL_52:
                if ( v18 != 0 )
                {
                  ++this->numEffects;
                }
                else
                {
                  v19 = g_animWarningTypes;
                  while ( idStr::Find(searchIn: v36, searchFor: *v19, casesensitive: true, start: 0, end: -1) == -1 )
                  {
                    if ( (int)++v19 >= (int)g_mapWarningTypes )
                    {
                      v20 = 0;
                      goto LABEL_59;
                    }
                  }
                  v20 = 1;
LABEL_59:
                  if ( v20 != 0 )
                  {
                    ++this->numAnimation;
                  }
                  else
                  {
                    v21 = g_mapWarningTypes;
                    while ( idStr::Find(searchIn: v36, searchFor: *v21, casesensitive: true, start: 0, end: -1) == -1 )
                    {
                      if ( (int)++v21 >= (int)g_scriptingWarningTypes )
                      {
                        v22 = 0;
                        goto LABEL_66;
                      }
                    }
                    v22 = 1;
LABEL_66:
                    if ( v22 != 0 )
                    {
                      ++this->numMap;
                    }
                    else
                    {
                      v23 = g_scriptingWarningTypes;
                      while ( idStr::Find(searchIn: v36, searchFor: *v23, casesensitive: true, start: 0, end: -1) == -1 )
                      {
                        if ( (int)++v23 >= (int)g_modelWarningTypes )
                        {
                          v24 = 0;
                          goto LABEL_73;
                        }
                      }
                      v24 = 1;
LABEL_73:
                      if ( v24 != 0 )
                      {
                        ++this->numScripting;
                      }
                      else
                      {
                        v25 = g_modelWarningTypes;
                        while ( idStr::Find(searchIn: v36, searchFor: *v25, casesensitive: true, start: 0, end: -1) == -1 )
                        {
                          if ( (int)++v25 >= (int)g_materialWarningTypes )
                          {
                            v26 = 0;
                            goto LABEL_80;
                          }
                        }
                        v26 = 1;
LABEL_80:
                        if ( v26 != 0 )
                        {
                          ++this->numModel;
                        }
                        else
                        {
                          v27 = g_materialWarningTypes;
                          while ( idStr::Find(searchIn: v36, searchFor: *v27, casesensitive: true, start: 0, end: -1) == -1 )
                          {
                            if ( (int)++v27 >= (int)g_missingFileWarningTypes )
                            {
                              v28 = 0;
                              goto LABEL_87;
                            }
                          }
                          v28 = 1;
LABEL_87:
                          if ( v28 != 0 )
                          {
                            ++this->numMaterial;
                          }
                          else
                          {
                            v29 = g_missingFileWarningTypes;
                            while ( idStr::Find(searchIn: v36, searchFor: *v29, casesensitive: true, start: 0, end: -1) == -1 )
                            {
                              if ( (int)++v29 >= (int)g_obsoleteWarningTypes )
                              {
                                v30 = 0;
                                goto LABEL_94;
                              }
                            }
                            v30 = 1;
LABEL_94:
                            if ( v30 != 0 )
                            {
                              ++this->numMissingFile;
                            }
                            else
                            {
                              v31 = g_obsoleteWarningTypes;
                              while ( idStr::Find(
                                        searchIn: v36,
                                        searchFor: *v31,
                                        casesensitive: true,
                                        start: 0,
                                        end: -1) == -1 )
                              {
                                if ( (int)++v31 >= (int)g_subtitleWarningTypes )
                                {
                                  v32 = 0;
                                  goto LABEL_101;
                                }
                              }
                              v32 = 1;
LABEL_101:
                              if ( v32 != 0 )
                              {
                                ++this->numObsolete;
                              }
                              else
                              {
                                v33 = g_subtitleWarningTypes;
                                while ( idStr::Find(
                                          searchIn: v36,
                                          searchFor: *v33,
                                          casesensitive: true,
                                          start: 0,
                                          end: -1) == -1 )
                                {
                                  if ( (int)++v33 >= (int)&console )
                                  {
                                    v34 = 0;
                                    goto LABEL_108;
                                  }
                                }
                                v34 = 1;
LABEL_108:
                                if ( v34 != 0 )
                                  ++this->numSubtitle;
                                else
                                  ++this->numOther;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
    this->numWarningsTotal = 0;
    this->numSyntaxErrors = 0;
    this->numDuplicate = 0;
    this->numAnimWeb = 0;
    this->numAudio = 0;
    this->numEffects = 0;
    this->numAnimation = 0;
    this->numModel = 0;
    this->numMap = 0;
    this->numScripting = 0;
    this->numMaterial = 0;
    this->numMissingFile = 0;
    this->numObsolete = 0;
    this->numSubtitle = 0;
    this->numOther = 0;
    this->showTimer = 0;
  }
}


// ========================================================================
// ?print_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82664458
// RVA : 0x00664458
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall print_f(const idCmdArgs *args)
{
  int argc; // r11
  int v3; // r24
  char *v4; // r29
  int v5; // r27
  char **i; // r26
  char *v7; // r28
  int v8; // r30

  argc = args->argc;
  v3 = 0;
  v4 = nullptr;
  v5 = 1;
  if ( args->argc > 1 )
  {
    for ( i = &args->argv[1]; ; ++i )
    {
      v7 = v5 < 0 || v5 >= argc ? &byte_8200D768 : *i;
      v8 = 0;
      if ( *v7 != 0 )
      {
        do
          ++v8;
        while ( v7[v8] != 0 );
      }
      if ( v3 < v8 + 1 )
        break;
      if ( v4 == nullptr )
        goto LABEL_14;
LABEL_15:
      idStr::ToEscapedString(str: v7, strLen: v8, out: v4, outSize: v8 + 1);
      idLib::Printf(fmt: v4);
      argc = args->argc;
      if ( ++v5 >= args->argc )
      {
        if ( v4 != nullptr )
          idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
        return;
      }
    }
    if ( v4 != nullptr )
      idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
LABEL_14:
    v3 = v8 + 1;
    v4 = (char *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\engine\\framework\\Console.cpp(508) : TAG_TEMP",
                   size: v8 + 1,
                   tag: TAG_TEMP,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
    goto LABEL_15;
  }
}


// ========================================================================
// ?activateConsole_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82664580
// RVA : 0x00664580
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall activateConsole_f(const idCmdArgs *args)
{
  long double v1; // fp2
  double v2; // fp0
  double v3; // fp13

  if ( args->argc == 2 )
  {
    v1 = atof(nptr: args->argv[1]);
    v2 = (float)*(double *)&v1;
    v3 = 0.0;
    if ( v2 < 0.0 || (v3 = 1.0, v2 > 1.0) )
      v2 = v3;
    idConsoleLocal::Activate(this: &localConsole, displayFrac: v2);
  }
  else
  {
    idLib::Printf(fmt: "usage: activateConsole <fraction>\n");
  }
}


// ========================================================================
// ?DrawTextOffsetLeftAlign@idConsoleLocal@@AAAXMAAMMPBDZZ
// EA  : 0x82664608
// RVA : 0x00664608
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idConsoleLocal::DrawTextOffsetLeftAlign(
        idConsoleLocal *this,
        double x,
        float *y,
        double opacity,
        float *text,
        int a6,
        __int64 a7,
        __int64 a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        ...)
{
  __int64 v23; // r11
  char v24[1032]; // [sp+70h] [-430h] BYREF
  __int64 v25; // [sp+4D8h] [+38h] BYREF
  va_list va; // [sp+4D8h] [+38h]
  __int64 v27; // [sp+4E0h] [+40h]
  __int64 v28; // [sp+4E8h] [+48h]
  va_list va1; // [sp+4F0h] [+50h] BYREF

  va_start(va1, a20);
  va_start(va, a20);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v25 = a7;
  v27 = *(__int64 *)((char *)&a8 + 4);
  v28 = a8;
  idStr::vsnPrintf(dest: v24, size: 1024, fmt: (const char *)HIDWORD(a7), argptr: va);
  LODWORD(v23) = (int)(float)(*text + (float)2.0);
  idRenderModelGui::DrawString(
    this: this->gui,
    x,
    y: (float)v23,
    string: (const char *)v23,
    defaultColor: (const idVec4 *)0x82000000,
    forceColor: (bool)v24,
    scale: 1.0);
  *text = (float)(*text + SMALLCHAR_HEIGHT) + (float)4.0;
}


// ========================================================================
// ?DrawTextOffsetRightAlign@idConsoleLocal@@AAAXMAAMMPBDZZ
// EA  : 0x82664700
// RVA : 0x00664700
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idConsoleLocal::DrawTextOffsetRightAlign(
        idConsoleLocal *this,
        double x,
        float *y,
        double opacity,
        float *text,
        int a6,
        __int64 a7,
        __int64 a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        ...)
{
  __int64 v23; // r8
  __int64 v24; // r10
  char v25[1032]; // [sp+70h] [-430h] BYREF
  __int64 v26; // [sp+4D8h] [+38h] BYREF
  va_list va; // [sp+4D8h] [+38h]
  __int64 v28; // [sp+4E0h] [+40h]
  __int64 v29; // [sp+4E8h] [+48h]
  va_list va1; // [sp+4F0h] [+50h] BYREF

  va_start(va1, a20);
  va_start(va, a20);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v26 = a7;
  v28 = *(__int64 *)((char *)&a8 + 4);
  v29 = a8;
  LODWORD(v23) = idStr::vsnPrintf(dest: v25, size: 1024, fmt: (const char *)HIDWORD(a7), argptr: va);
  LODWORD(v24) = (int)(float)(*text + (float)2.0);
  idRenderModelGui::DrawString(
    this: this->gui,
    x: (float)-(float)((float)((float)v23 * SMALLCHAR_WIDTH) - (float)x),
    y: (float)v24,
    string: (const char *)&r_cuttablemodel_freecpudata.description,
    defaultColor: (const idVec4 *)0x82000000,
    forceColor: (bool)v25,
    scale: 1.0);
  *text = (float)(*text + SMALLCHAR_HEIGHT) + (float)4.0;
}


// ========================================================================
// ?DrawTextLeftAlign@idConsoleLocal@@AAAXAAMMPBDZZ
// EA  : 0x82664818
// RVA : 0x00664818
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idConsoleLocal::DrawTextLeftAlign(
        idConsoleLocal *this,
        float *y,
        double opacity,
        const char *text,
        const char *a5,
        __int64 a6,
        __int64 a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        ...)
{
  __int64 v19; // r10
  char v20[1056]; // [sp+70h] [-420h] BYREF
  __int64 v21; // [sp+4C0h] [+30h] BYREF
  va_list va; // [sp+4C0h] [+30h]
  __int64 v23; // [sp+4C8h] [+38h]
  __int64 v24; // [sp+4D0h] [+40h]
  __int64 v25; // [sp+4D8h] [+48h]
  va_list va1; // [sp+4E0h] [+50h] BYREF

  va_start(va1, a17);
  va_start(va, a17);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v21 = *(__int64 *)((char *)&a6 + 4);
  v23 = a6;
  v24 = *(__int64 *)((char *)&a7 + 4);
  v25 = a7;
  idStr::vsnPrintf(dest: v20, size: 1024, fmt: a5, argptr: va);
  LODWORD(v19) = (int)(float)(*y + (float)2.0);
  idRenderModelGui::DrawString(
    this: this->gui,
    x: 48.0,
    y: (float)v19,
    string: byte_821B0000,
    defaultColor: (const idVec4 *)0x82000000,
    forceColor: (bool)v20,
    scale: 1.0);
  *y = (float)(*y + SMALLCHAR_HEIGHT) + (float)4.0;
}


// ========================================================================
// ?DrawTextRightAlign@idConsoleLocal@@AAAXAAMMPBDZZ
// EA  : 0x82664910
// RVA : 0x00664910
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idConsoleLocal::DrawTextRightAlign(
        idConsoleLocal *this,
        float *y,
        double opacity,
        const char *text,
        const char *a5,
        __int64 a6,
        __int64 a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        ...)
{
  int v19; // r29
  __int64 v20; // r11
  __int64 v21; // r4
  __int128 v22; // r9
  __int64 v23; // [sp+50h] [-440h]
  char v24[1056]; // [sp+70h] [-420h] BYREF
  __int64 v25; // [sp+4C0h] [+30h] BYREF
  va_list va; // [sp+4C0h] [+30h]
  __int64 v27; // [sp+4C8h] [+38h]
  __int64 v28; // [sp+4D0h] [+40h]
  __int64 v29; // [sp+4D8h] [+48h]
  va_list va1; // [sp+4E0h] [+50h] BYREF

  va_start(va1, a17);
  va_start(va, a17);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v25 = *(__int64 *)((char *)&a6 + 4);
  v27 = a6;
  v28 = *(__int64 *)((char *)&a7 + 4);
  v29 = a7;
  idStr::vsnPrintf(dest: v24, size: 1024, fmt: a5, argptr: va);
  v19 = idStr::LengthWithoutColors(s: v24);
  LODWORD(v20) = (int)(float)(*y + (float)2.0);
  v23 = v20;
  v21 = ((__int64 (__fastcall *)(idRenderSystem *))renderSystem->GetWidth)(a1: renderSystem);
  LODWORD(v22) = v19;
  DWORD2(v22) = HIDWORD(v21) - 48;
  idRenderModelGui::DrawString(
    this: this->gui,
    x: (float)-(float)((float)((float)(__int64)v22 * SMALLCHAR_WIDTH) - (float)*(__int64 *)((char *)&v22 + 4)),
    y: (float)v23,
    string: (const char *)v21,
    defaultColor: (const idVec4 *)&r_cuttablemodel_freecpudata.description,
    forceColor: (bool)v24,
    scale: 1.0);
  *y = (float)(*y + SMALLCHAR_HEIGHT) + (float)4.0;
}


// ========================================================================
// ?DrawWarning@@YAXPAVidRenderModelGui@@PBDAAHM@Z
// EA  : 0x82664A58
// RVA : 0x00664A58
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall DrawWarning(idRenderModelGui *gui, const char *text, int *w, double yText)
{
  char v6; // r29
  int StringWidth; // r31
  __int128 v9; // r5
  __int64 v10; // r8
  double v11; // fp29
  const idVec4 *v12; // r5

  v6 = (char)text;
  StringWidth = idRenderModelGui::GetStringWidth(this: gui, string: text, scale: 1.0);
  *w += StringWidth;
  *(_QWORD *)((char *)&v9 + 4) = ((__int64 (__fastcall *)(idRenderSystem *))renderSystem->GetWidth)(a1: renderSystem);
  LODWORD(v9) = StringWidth;
  LODWORD(v10) = DWORD1(v9) + -53 - *w;
  v11 = (float)v10;
  idRenderModelGui::DrawFilled(
    this: gui,
    color: (const idVec4 *)&idColor::colorBlack,
    x: (float)((float)v10 - (float)8.0),
    y: (float)((float)yText + (float)1.5),
    w: (float)((float)(__int64)v9 + (float)4.0),
    h: (float)(SMALLCHAR_HEIGHT + (float)4.0));
  idRenderModelGui::DrawString(
    this: gui,
    x: v11,
    y: yText,
    string: &aAvSsobjectVCom[20],
    defaultColor: v12,
    forceColor: v6,
    scale: 1.0);
}


// ========================================================================
// ?DrawWarnings@idConsoleLocal@@AAAXAAM00@Z
// EA  : 0x82664B68
// RVA : 0x00664B68
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::DrawWarnings(idConsoleLocal *this, float *leftY, __int64 centerY)
{
  float *v3; // r30
  __int64 v5; // r8
  double v6; // fp31
  va *v7; // r3
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r10
  va *v11; // r3
  __int64 v12; // r10
  va *v13; // r3
  __int64 v14; // r10
  va *v15; // r3
  __int64 v16; // r10
  va *v17; // r3
  __int64 v18; // r10
  va *v19; // r3
  __int64 v20; // r10
  va *v21; // r3
  __int64 v22; // r10
  va *v23; // r3
  int v24; // [sp+8h] [-1078h]
  int v25; // [sp+8h] [-1078h]
  int v26; // [sp+Ch] [-1074h]
  int v27; // [sp+Ch] [-1074h]
  int v28; // [sp+10h] [-1070h]
  int v29; // [sp+10h] [-1070h]
  int v30; // [sp+14h] [-106Ch]
  int v31; // [sp+14h] [-106Ch]
  int v32; // [sp+18h] [-1068h]
  int v33; // [sp+18h] [-1068h]
  int v34; // [sp+1Ch] [-1064h]
  int v35; // [sp+1Ch] [-1064h]
  int v36[2]; // [sp+50h] [-1030h] BYREF
  __int64 v37; // [sp+58h] [-1028h]
  va v38; // [sp+60h] [-1020h] BYREF

  v3 = (float *)HIDWORD(centerY);
  HIDWORD(centerY) = this->warningCollector.numWarningsTotal;
  if ( HIDWORD(centerY) != 0 || this->warningCollector.showTimer <= this->warningCollector.howLongToShow )
  {
    LODWORD(v5) = this->warningCollector.showTimer + 1;
    v36[0] = 0;
    this->warningCollector.showTimer = v5;
    HIDWORD(v5) = (int)*v3 + 2;
    LODWORD(centerY) = HIDWORD(v5);
    v37 = centerY;
    v6 = (float)centerY;
    v7 = va::va(
           this: &v38,
           fmt: "NumWarningsTotal (%d)",
           a3: centerY,
           a4: v5,
           a5: (unsigned int)&unk_821D0000,
           a6: v24,
           a7: v26,
           a8: v28,
           a9: v30,
           a10: v32,
           a11: v34);
    DrawWarning(gui: this->gui, text: v7->buffer, w: v36, yText: v6);
    HIDWORD(v9) = this->warningCollector.numAnimWeb;
    if ( SHIDWORD(v9) > 0 )
    {
      LODWORD(v10) = &unk_821D0000;
      v36[0] += 4;
      HIDWORD(v10) = v36[0];
      v11 = va::va(
              this: &v38,
              fmt: "NumAnimweb (%d)",
              a3: v9,
              a4: v8,
              a5: v10,
              a6: v25,
              a7: v27,
              a8: v29,
              a9: v31,
              a10: v33,
              a11: v35);
      DrawWarning(gui: this->gui, text: v11->buffer, w: v36, yText: v6);
    }
    HIDWORD(v9) = this->warningCollector.numAnimation;
    if ( SHIDWORD(v9) > 0 )
    {
      LODWORD(v12) = &unk_821D0000;
      v36[0] += 4;
      HIDWORD(v12) = v36[0];
      v13 = va::va(
              this: &v38,
              fmt: "NumAnimation (%d)",
              a3: v9,
              a4: v8,
              a5: v12,
              a6: v25,
              a7: v27,
              a8: v29,
              a9: v31,
              a10: v33,
              a11: v35);
      DrawWarning(gui: this->gui, text: v13->buffer, w: v36, yText: v6);
    }
    HIDWORD(v9) = this->warningCollector.numAudio;
    if ( SHIDWORD(v9) > 0 )
    {
      LODWORD(v14) = &unk_821D0000;
      v36[0] += 4;
      HIDWORD(v14) = v36[0];
      v15 = va::va(
              this: &v38,
              fmt: "NumAudio (%d)",
              a3: v9,
              a4: v8,
              a5: v14,
              a6: v25,
              a7: v27,
              a8: v29,
              a9: v31,
              a10: v33,
              a11: v35);
      DrawWarning(gui: this->gui, text: v15->buffer, w: v36, yText: v6);
    }
    HIDWORD(v9) = this->warningCollector.numMap;
    if ( SHIDWORD(v9) > 0 )
    {
      LODWORD(v16) = &unk_821D0000;
      v36[0] += 4;
      HIDWORD(v16) = v36[0];
      v17 = va::va(
              this: &v38,
              fmt: "NumMap (%d)",
              a3: v9,
              a4: v8,
              a5: v16,
              a6: v25,
              a7: v27,
              a8: v29,
              a9: v31,
              a10: v33,
              a11: v35);
      DrawWarning(gui: this->gui, text: v17->buffer, w: v36, yText: v6);
    }
    HIDWORD(v9) = this->warningCollector.numModel;
    if ( SHIDWORD(v9) > 0 )
    {
      LODWORD(v18) = &unk_821D0000;
      v36[0] += 4;
      HIDWORD(v18) = v36[0];
      v19 = va::va(
              this: &v38,
              fmt: "NumModel (%d)",
              a3: v9,
              a4: v8,
              a5: v18,
              a6: v25,
              a7: v27,
              a8: v29,
              a9: v31,
              a10: v33,
              a11: v35);
      DrawWarning(gui: this->gui, text: v19->buffer, w: v36, yText: v6);
    }
    HIDWORD(v9) = this->warningCollector.numMissingFile;
    if ( SHIDWORD(v9) > 0 )
    {
      LODWORD(v20) = &unk_821D0000;
      v36[0] += 4;
      HIDWORD(v20) = v36[0];
      v21 = va::va(
              this: &v38,
              fmt: "NumMissingFile (%d)",
              a3: v9,
              a4: v8,
              a5: v20,
              a6: v25,
              a7: v27,
              a8: v29,
              a9: v31,
              a10: v33,
              a11: v35);
      DrawWarning(gui: this->gui, text: v21->buffer, w: v36, yText: v6);
    }
    HIDWORD(v9) = this->warningCollector.numSubtitle;
    if ( SHIDWORD(v9) > 0 )
    {
      LODWORD(v22) = &unk_821D0000;
      v36[0] += 4;
      HIDWORD(v22) = v36[0];
      v23 = va::va(
              this: &v38,
              fmt: "NumSubtitle (%d)",
              a3: v9,
              a4: v8,
              a5: v22,
              a6: v25,
              a7: v27,
              a8: v29,
              a9: v31,
              a10: v33,
              a11: v35);
      DrawWarning(gui: this->gui, text: v23->buffer, w: v36, yText: v6);
    }
    *v3 = (float)(*v3 + SMALLCHAR_HEIGHT) + (float)4.0;
  }
}


// ========================================================================
// ?DrawMemoryUsage@idConsoleLocal@@AAAXAAM00@Z
// EA  : 0x82664DE8
// RVA : 0x00664DE8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idConsoleLocal::DrawMemoryUsage(idConsoleLocal *this, float *leftY, float *rightY, float *centerY)
{
  char v6; // r30
  __int64 v7; // r11 OVERLAPPED
  __int128 v8; // r8 OVERLAPPED
  __int128 v9; // r9 OVERLAPPED
  int v10; // r3 OVERLAPPED
  double v11; // fp2
  __int64 v12; // r10 OVERLAPPED
  __int64 v13; // r8 OVERLAPPED
  int v14; // [sp+8h] [-D8h]
  int v15; // [sp+8h] [-D8h]
  int v16; // [sp+Ch] [-D4h]
  int v17; // [sp+Ch] [-D4h]
  int v18; // [sp+10h] [-D0h]
  int v19; // [sp+10h] [-D0h]
  int v20; // [sp+14h] [-CCh]
  int v21; // [sp+14h] [-CCh]
  int v22; // [sp+18h] [-C8h]
  int v23; // [sp+18h] [-C8h]
  int v24; // [sp+1Ch] [-C4h]
  int v25; // [sp+1Ch] [-C4h]
  int v26; // [sp+20h] [-C0h]
  int v27; // [sp+20h] [-C0h]
  const char *v28; // [sp+28h] [-B8h]
  const char *v29; // [sp+28h] [-B8h]
  int v30; // [sp+2Ch] [-B4h]
  int v31; // [sp+2Ch] [-B4h]

  v6 = 0;
  if ( com_showMemoryUsage.valueInteger == 1 || com_showMemoryUsage.valueInteger >= 2 && com_showFPS.valueInteger != 0 )
  {
    v6 = 1;
    LODWORD(v7) = idStreamFileCache::GetAvailableMemory(this: streamFileCache);
    *(double *)((char *)&v8 + 4) = (float)((float)v7 * (float)0.00000095367432);
    HIDWORD(v7) = &unk_821D0000;
    idConsoleLocal::DrawTextRightAlign(
      this,
      y: rightY,
      opacity: 1.0,
      text: v28,
      a5: (const char *)DWORD1(v8),
      a6: v8,
      a7: *(__int64 *)((char *)&v7 + 4),
      a8: v14,
      a9: v16,
      a10: v18,
      a11: v20,
      a12: v22,
      a13: v24,
      a14: v26,
      a15: COERCE_INT(1.0),
      a16: (int)v28,
      a17: v30);
    LODWORD(v9) = Sys_GetFreeMemory();
    *(double *)&v9 = (float)((float)(__int64)v9 * (float)0.00000095367432);
    DWORD2(v9) = &unk_821D0000;
    idConsoleLocal::DrawTextRightAlign(
      this,
      y: rightY,
      opacity: 1.0,
      text: v29,
      a5: (const char *)HIDWORD(v9),
      a6: *(__int64 *)((char *)&v9 + 4),
      a7: *(__int64 *)((char *)&v9 - 4),
      a8: v15,
      a9: v17,
      a10: v19,
      a11: v21,
      a12: v23,
      a13: v25,
      a14: v27,
      a15: COERCE_INT(1.0),
      a16: (int)v29,
      a17: v31);
  }
  v10 = (unsigned __int64)idStreamFileCache::GetCurrentUsageLimit(this: streamFileCache) >> 32;
  v11 = (float)((float)*(__int64 *)&v10 * (float)0.00000095367432);
  if ( v6 != 0 || com_showMemoryUsage.valueInteger == 2 && v11 < 8.0 )
  {
    LODWORD(v12) = "^0";
    if ( v11 >= 8.0 )
    {
      if ( v11 >= 16.0 )
        HIDWORD(v13) = "^0";
      else
        HIDWORD(v13) = "^3";
    }
    else
    {
      HIDWORD(v13) = "^1";
    }
    *(double *)((char *)&v12 + 4) = (float)((float)*(__int64 *)&v10 * (float)0.00000095367432);
    idConsoleLocal::DrawTextRightAlign(
      this,
      y: rightY,
      opacity: 1.0,
      text: v28,
      a5: "SFC Limit:%s%s %.1fMB%s",
      a6: v13,
      a7: v12,
      a8: v14,
      a9: v16,
      a10: v18,
      a11: v20,
      a12: v22,
      a13: v24,
      a14: v26,
      a15: COERCE_INT(1.0),
      a16: (int)v28,
      a17: v30);
  }
}


// ========================================================================
// `idConsoleLocal::DrawComSpeeds'::`2'::local_t::DrawTimeAvgMaxMin
// EA  : 0x82664FD0
// RVA : 0x00664FD0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall _idConsoleLocal::DrawComSpeeds_::_2_::local_t::DrawTimeAvgMaxMin(
        idConsoleLocal *console,
        float *rightY,
        const char *name,
        double avg,
        double max,
        double min,
        double orangeTime,
        double redTime)
{
  __int64 v8; // r8 OVERLAPPED
  __int64 v9; // r10 OVERLAPPED
  int v10; // [sp+8h] [-A8h]
  int v11; // [sp+Ch] [-A4h]
  int v12; // [sp+10h] [-A0h]
  int v13; // [sp+14h] [-9Ch]
  int v14; // [sp+18h] [-98h]
  int v15; // [sp+1Ch] [-94h]
  int v16; // [sp+20h] [-90h]
  const char *v17; // [sp+28h] [-88h]
  int v18; // [sp+2Ch] [-84h]

  HIDWORD(v8) = name;
  if ( max <= redTime )
  {
    LODWORD(v9) = "^3";
    if ( max <= orangeTime )
      LODWORD(v9) = "^2";
  }
  else
  {
    LODWORD(v9) = "^1";
  }
  *(__int64 *)((char *)&v8 - 4) = *(_QWORD *)&avg;
  idConsoleLocal::DrawTextRightAlign(
    this: console,
    y: COERCE_FLOAT_(1.0),
    opacity: 1.0,
    text: v17,
    a5: "%s%s%6.2f%s%6.2f%s%6.2f",
    a6: v8,
    a7: v9,
    a8: v10,
    a9: v11,
    a10: v12,
    a11: v13,
    a12: v14,
    a13: v15,
    a14: v16,
    a15: COERCE_INT(1.0),
    a16: (int)v17,
    a17: v18,
    avg,
    max);
}


// ========================================================================
// ?InitGuiModel@idConsoleLocal@@UAAXXZ
// EA  : 0x82665108
// RVA : 0x00665108
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::InitGuiModel(idConsoleLocal *this)
{
  idRenderModelGui *v2; // r3
  idRenderModelGui *v3; // r3

  v2 = (idRenderModelGui *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0xA410u,
                             tag: TAG_GUI_MODEL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idRenderModelGui::idRenderModelGui(this: v2);
  else
    v3 = nullptr;
  this->gui = v3;
  idRenderModel::SetName(this: v3, name_: "ConsoleGuiModel");
}


// ========================================================================
// __unwind$230085
// EA  : 0x82665190
// RVA : 0x00665190
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_230085()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_GUI_MODEL);
}


// ========================================================================
// ?Shutdown@idConsoleLocal@@UAAXXZ
// EA  : 0x826651C0
// RVA : 0x006651C0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::Shutdown(idConsoleLocal *this)
{
  idRenderModelGui *gui; // r3

  gui = this->gui;
  if ( gui != nullptr )
  {
    gui->unlinked = true;
    gui->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: gui);
    this->gui = nullptr;
  }
}


// ========================================================================
// ?LoadGraphics@idConsoleLocal@@UAAXXZ
// EA  : 0x82665210
// RVA : 0x00665210
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::LoadGraphics(idConsoleLocal *this)
{
  __int64 v2; // r8
  double v3; // fp29
  idDebugGraph *v4; // r3
  double v5; // fp0
  idDebugGraph *v6; // r3
  idDebugGraph *graphTotalTime; // r30
  idDebugGraph *v8; // r3
  idDebugGraph *graphRenderTime; // r30
  __int64 v10; // r4
  idDebugGraph *graphGameTime; // r30
  __int64 v12; // r4
  idDebugGraph *graphGPUTime; // r30

  LODWORD(v2) = renderSystem->GetWidth(this: renderSystem);
  HIDWORD(v2) = this->idConsole::__vftable;
  v3 = (float)((float)v2 - (float)228.0);
  v4 = this->CreateGraph(this, a2: 60);
  this->graphFPS = v4;
  v5 = SMALLCHAR_HEIGHT;
  v4->position.x = v3;
  v4->position.y = 32.0;
  v4->position.z = 120.0;
  v4->position.w = v5;
  v6 = this->CreateGraph(this, a2: 180);
  this->graphTotalTime = v6;
  v6->position.x = v3;
  v6->position.y = 200.0;
  v6->position.z = 180.0;
  v6->position.w = 30.0;
  idDebugGraph::AddGridLine(this: this->graphTotalTime, value: 0.5, color: (const idColor *)&unk_821C0000);
  this->graphTotalTime->clamp = true;
  graphTotalTime = this->graphTotalTime;
  idStr::operator=(this: &graphTotalTime->caption, text: "T:");
  graphTotalTime->capPos = CAP_LEFT;
  v8 = this->CreateGraph(this, a2: 180);
  this->graphRenderTime = v8;
  v8->position.x = v3;
  v8->position.y = 240.0;
  v8->position.z = 180.0;
  v8->position.w = 30.0;
  idDebugGraph::AddGridLine(this: this->graphRenderTime, value: 0.5, color: (const idColor *)&unk_821D0000);
  this->graphRenderTime->clamp = true;
  graphRenderTime = this->graphRenderTime;
  idStr::operator=(this: &graphRenderTime->caption, text: "RT:");
  graphRenderTime->capPos = CAP_LEFT;
  v10 = ((__int64 (__fastcall *)(idConsoleLocal *, int))this->CreateGraph)(a1: this, a2: 180);
  this->graphGameTime = (idDebugGraph *)HIDWORD(v10);
  *(float *)(HIDWORD(v10) + 48) = v3;
  *(float *)(HIDWORD(v10) + 52) = 280.0;
  *(float *)(HIDWORD(v10) + 56) = 180.0;
  *(float *)(HIDWORD(v10) + 60) = 30.0;
  idDebugGraph::AddGridLine(this: this->graphGameTime, value: 0.5, color: (const idColor *)v10);
  this->graphGameTime->clamp = true;
  graphGameTime = this->graphGameTime;
  idStr::operator=(this: &graphGameTime->caption, text: "GT:");
  graphGameTime->capPos = CAP_LEFT;
  v12 = ((__int64 (__fastcall *)(idConsoleLocal *, int))this->CreateGraph)(a1: this, a2: 180);
  this->graphGPUTime = (idDebugGraph *)HIDWORD(v12);
  *(float *)(HIDWORD(v12) + 48) = v3;
  *(float *)(HIDWORD(v12) + 52) = 320.0;
  *(float *)(HIDWORD(v12) + 56) = 180.0;
  *(float *)(HIDWORD(v12) + 60) = 30.0;
  idDebugGraph::AddGridLine(this: this->graphGPUTime, value: 0.5, color: (const idColor *)v12);
  this->graphGPUTime->clamp = true;
  graphGPUTime = this->graphGPUTime;
  idStr::operator=(this: &graphGPUTime->caption, text: "GPU:");
  graphGPUTime->capPos = CAP_LEFT;
  idRunningAverage::Init(this: &this->avgFPS, num: 120);
  idRunningAverage::Init(this: &this->avgTotalTime, num: 120);
  idRunningAverage::Init(this: &this->avgRenderTime, num: 120);
  idRunningAverage::Init(this: &this->avgGameTime, num: 120);
  idRunningAverage::Init(this: &this->avgGPUTime, num: 120);
  idRenderModelGui::SetupMonospaceFont(this: this->gui, drawWidth: con_fontSize.valueFloat);
  this->isInitialized = true;
}


// ========================================================================
// ?ClearNotifyLines@idConsoleLocal@@UAAXXZ
// EA  : 0x82665508
// RVA : 0x00665508
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::ClearNotifyLines(idConsoleLocal *this)
{
  this->times.ptr[0] = 0;
  this->times.ptr[1] = 0;
  this->times.ptr[2] = 0;
  this->times.ptr[3] = 0;
}


// ========================================================================
// ?Close@idConsoleLocal@@UAAX_N@Z
// EA  : 0x82665528
// RVA : 0x00665528
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::Close(idConsoleLocal *this, bool clearNotify)
{
  this->keyCatching = false;
  this->finalFrac = 0.0;
  this->fracTime = Sys_Milliseconds();
  this->displayFrac = 0.0;
  if ( clearNotify )
    this->ClearNotifyLines(this);
  idKeyInput::ClearStates();
}


// ========================================================================
// ?Clear@idConsoleLocal@@QAAXXZ
// EA  : 0x826655C0
// RVA : 0x006655C0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::Clear(idConsoleLocal *this)
{
  __int16 **v1; // r10
  int i; // ctr
  _WORD *v3; // r11
  __int16 *v4; // r11
  __int16 *v5; // r11

  v1 = &this->lines.ptr[1];
  for ( i = 1024; i != 0; --i )
  {
    v3 = *(v1 - 1);
    if ( v3 != nullptr )
      *v3 = 0;
    if ( *v1 != nullptr )
      **v1 = 0;
    v4 = v1[1];
    if ( v4 != nullptr )
      *v4 = 0;
    v5 = v1[2];
    if ( v5 != nullptr )
      *v5 = 0;
    v1 += 4;
  }
  this->displayLine = this->currentLine;
}


// ========================================================================
// ?Top@idConsoleLocal@@AAAXXZ
// EA  : 0x82665638
// RVA : 0x00665638
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::Top(idConsoleLocal *this)
{
  int currentLine; // r10
  int *p_displayLine; // r11
  int v3; // r6
  int v4; // r9
  __int16 *v5; // r6

  currentLine = this->currentLine;
  if ( currentLine < 4096 )
  {
    p_displayLine = &this->displayLine;
    v3 = __CFADD__(currentLine - 4096, 0x80000000) ? 0 : currentLine - 4096;
    this->displayLine = v3;
    if ( v3 <= currentLine )
    {
      do
      {
        v4 = *p_displayLine;
        v5 = this->lines.ptr[*p_displayLine];
        if ( v5 != nullptr && *v5 != 0 )
          break;
        *p_displayLine = v4 + 1;
      }
      while ( v4 + 1 <= this->currentLine );
    }
  }
  else
  {
    this->displayLine = currentLine - 4095;
  }
}


// ========================================================================
// ?KeyDownEvent@idConsoleLocal@@AAAXH@Z
// EA  : 0x826656E8
// RVA : 0x006656E8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::KeyDownEvent(idConsoleLocal *this, keyNum_t key)
{
  char IsShiftDown; // r3
  int currentLine; // r9
  int v6; // r10
  int v7; // r9
  int v8; // r10
  int v9; // r9
  int v10; // r10
  int v11; // r9
  int v12; // r10
  idEditField *p_consoleField; // r29
  const char **p_data; // r30
  idStr v15; // [sp+50h] [-70h] BYREF
  idStr v16[2]; // [sp+70h] [-50h] BYREF

  if ( key >= K_F1 && key <= K_F12 )
  {
    idKeyInput::ExecKeyBinding(numDevice: 0, bindset: BIND_DEFAULT, keynum: key);
    return;
  }
  switch ( key )
  {
    case K_L:
      if ( (unsigned __int8)idKeyInput::IsCtrlDown(deviceNum: 0) != 0 )
      {
        idConsoleLocal::Clear(this);
        return;
      }
      goto LABEL_11;
    case K_ENTER:
    case K_KP_ENTER:
LABEL_46:
      p_consoleField = &this->consoleField;
      if ( !idEditField::AcceptAutoComplete(this: &this->consoleField) )
      {
        p_data = (const char **)&this->consoleField.buffer.data;
        idLib::Printf(fmt: "]%s\n", *p_data);
        cmdSystem->AppendCommandText(this: cmdSystem, a2: *p_data);
        cmdSystem->AppendCommandText(this: cmdSystem, a2: "\n");
        idConsoleHistory::AddToHistory(this: &consoleHistory, line: *p_data, writeHistoryFile: true);
        idEditField::Clear(this: p_consoleField);
      }
      return;
    case K_M:
      if ( (unsigned __int8)idKeyInput::IsCtrlDown(deviceNum: 0) == 0 )
      {
LABEL_11:
        idEditField::KeyDownEvent(this: &this->consoleField, key);
        return;
      }
      goto LABEL_46;
    case K_TAB:
      IsShiftDown = idKeyInput::IsShiftDown(deviceNum: 0);
      idEditField::AutoComplete(this: &this->consoleField, reverseOrder: IsShiftDown);
      return;
    case K_UPARROW:
      goto LABEL_17;
    case K_P:
      if ( (unsigned __int8)idKeyInput::IsCtrlDown(deviceNum: 0) == 0 )
        goto LABEL_11;
LABEL_17:
      idConsoleHistory::RetrieveFromHistory(
        this: (idConsoleHistory *)v16,
        result: (idStr *)&consoleHistory,
        backward: true);
      if ( v16[0].len != 0 )
        idEditField::SetBuffer(this: &this->consoleField, buf: v16[0].data);
      idStr::FreeData(this: v16);
      return;
    case K_DOWNARROW:
      goto LABEL_23;
    case K_N:
      if ( (unsigned __int8)idKeyInput::IsCtrlDown(deviceNum: 0) == 0 )
        goto LABEL_11;
LABEL_23:
      idConsoleHistory::RetrieveFromHistory(
        this: (idConsoleHistory *)&v15,
        result: (idStr *)&consoleHistory,
        backward: false);
      if ( v15.len != 0 )
        idEditField::SetBuffer(this: &this->consoleField, buf: v15.data);
      idStr::FreeData(this: &v15);
      return;
    case K_PGUP:
      currentLine = this->currentLine;
      v6 = this->displayLine - 2;
      this->displayLine = v6;
      if ( currentLine - v6 >= 4096 )
        this->displayLine = currentLine - 4095;
LABEL_29:
      this->nextKeyEvent = Sys_Milliseconds() + 200;
      return;
    case K_PGDN:
      v7 = this->currentLine;
      v8 = this->displayLine + 2;
      this->displayLine = v8;
      if ( v8 > v7 )
        this->displayLine = v7;
      goto LABEL_29;
    case K_MWHEELUP:
      v9 = this->currentLine;
      v10 = this->displayLine - 2;
      this->displayLine = v10;
      if ( v9 - v10 >= 4096 )
        this->displayLine = v9 - 4095;
      break;
    case K_MWHEELDOWN:
      v11 = this->currentLine;
      v12 = this->displayLine + 2;
      this->displayLine = v12;
      if ( v12 > v11 )
        this->displayLine = v11;
      break;
    case K_HOME:
      if ( (unsigned __int8)idKeyInput::IsCtrlDown(deviceNum: 0) == 0 )
        goto LABEL_11;
      idConsoleLocal::Top(this);
      break;
    default:
      if ( key != K_END || (unsigned __int8)idKeyInput::IsCtrlDown(deviceNum: 0) == 0 )
        goto LABEL_11;
      this->displayLine = this->currentLine;
      break;
  }
}


// ========================================================================
// __unwind$230279
// EA  : 0x82665A78
// RVA : 0x00665A78
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_230279()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$230280
// EA  : 0x82665AA0
// RVA : 0x00665AA0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_230280()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?UpdateDisplayFraction@idConsoleLocal@@AAAXXZ
// EA  : 0x82665AC8
// RVA : 0x00665AC8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::UpdateDisplayFraction(idConsoleLocal *this)
{
  double valueFloat; // fp31
  int v3; // r3
  double finalFrac; // fp0
  float *p_finalFrac; // r29
  float *p_displayFrac; // r31
  double v7; // fp0
  double displayFrac; // fp13
  int *p_fracTime; // r30
  int v10; // r3
  double v11; // fp0
  __int64 v12; // r8
  double v13; // fp7
  int v14; // r3
  __int64 v15; // r8
  double v16; // fp7

  valueFloat = con_speed.valueFloat;
  if ( con_speed.valueFloat <= 0.1 )
  {
    v3 = Sys_Milliseconds();
    finalFrac = this->finalFrac;
    this->fracTime = v3;
    this->displayFrac = finalFrac;
    return;
  }
  p_finalFrac = &this->finalFrac;
  p_displayFrac = &this->displayFrac;
  v7 = this->finalFrac;
  displayFrac = this->displayFrac;
  if ( v7 >= displayFrac )
  {
    if ( v7 <= displayFrac )
      return;
    p_fracTime = &this->fracTime;
    v14 = Sys_Milliseconds();
    v11 = *p_finalFrac;
    LODWORD(v15) = v14 - *p_fracTime;
    v16 = (float)((float)((float)((float)v15 * (float)valueFloat) * (float)0.001) + *p_displayFrac);
    *p_displayFrac = (float)((float)((float)v15 * (float)valueFloat) * (float)0.001) + *p_displayFrac;
    if ( v11 < v16 )
      goto LABEL_8;
  }
  else
  {
    p_fracTime = &this->fracTime;
    v10 = Sys_Milliseconds();
    v11 = *p_finalFrac;
    LODWORD(v12) = v10 - *p_fracTime;
    v13 = (float)-(float)((float)((float)((float)v12 * (float)valueFloat) * (float)0.001) - *p_displayFrac);
    *p_displayFrac = -(float)((float)((float)((float)v12 * (float)valueFloat) * (float)0.001) - *p_displayFrac);
    if ( v11 > v13 )
LABEL_8:
      *p_displayFrac = v11;
  }
  *p_fracTime = Sys_Milliseconds();
}


// ========================================================================
// ?ProcessEvent@idConsoleLocal@@UAA_NPBUsysEvent_t@@_N@Z
// EA  : 0x82665C08
// RVA : 0x00665C08
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

int __fastcall idConsoleLocal::ProcessEvent(idConsoleLocal *this, const sysEvent_t *ev, bool forceAccept)
{
  bool v6; // r28
  idMouse *v7; // r3

  v6 = false;
  if ( ev->evType == SE_KEY )
    v6 = ev->evValue == 41;
  if ( com_drawSnapshotMetrics.valueInteger > 0 )
    idSnapshotMetrics::ProcessEvent(this: &snapshotMetrics, ev);
  if ( forceAccept )
    goto LABEL_21;
  if ( v6 )
  {
    if ( ev->evValue2 != 0 )
    {
      idEditField::ClearAutoComplete(this: &this->consoleField);
      if ( this->IsActive(this) )
      {
        this->Close(this, a2: true);
        if ( (com_editors & 2) == 0 || (com_editors & 0x4000000) != 0 )
        {
          v7 = sys->Mouse(this: sys);
          v7->GrabCursor(this: v7, a2: true);
          return 1;
        }
      }
      else
      {
        idEditField::Clear(this: &this->consoleField);
        if ( (unsigned __int8)idKeyInput::IsShiftDown(deviceNum: 0) != 0 )
        {
          idConsoleLocal::Activate(this, displayFrac: 0.2);
          return 1;
        }
        idConsoleLocal::Activate(this, displayFrac: 0.5);
      }
    }
    return 1;
  }
  if ( this->IsActive(this) )
  {
LABEL_21:
    if ( ev->evType == SE_CHAR )
    {
      if ( this->displayFrac > 0.0 )
        idEditField::CharEvent(this: &this->consoleField, ch: ev->evValue);
      return 1;
    }
    if ( ev->evType == SE_KEY )
    {
      if ( ev->evValue2 == 0 )
        return 1;
      idConsoleLocal::KeyDownEvent(this, key: (keyNum_t)ev->evValue);
      return 1;
    }
  }
  return 0;
}


// ========================================================================
// ?ClearOldLines@idConsoleLocal@@AAAXHHH@Z
// EA  : 0x82665E20
// RVA : 0x00665E20
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::ClearOldLines(
        idConsoleLocal *this,
        __int16 currentLine,
        int startOffset,
        int endOffset)
{
  __int16 *v4; // r7
  __int16 *v5; // r5
  int v6; // r6
  int v7; // r8
  __int16 **v8; // r11
  unsigned int v9; // r10
  __int16 *v10; // r10
  __int16 *v11; // r10

  v4 = &this->text.ptr[startOffset];
  v5 = &this->text.ptr[endOffset];
  v6 = currentLine & 0xFFF;
  v7 = 2;
  v8 = &this->lines.ptr[1];
  do
  {
    v9 = (unsigned int)*(v8 - 1);
    if ( v9 >= (unsigned int)v4 && v9 <= (unsigned int)v5 && v7 - 2 != v6 )
      *(v8 - 1) = &this->text.ptr[0x10000];
    if ( *v8 >= v4 && *v8 <= v5 && v7 - 1 != v6 )
      *v8 = &this->text.ptr[0x10000];
    v10 = v8[1];
    if ( v10 >= v4 && v10 <= v5 && v7 != v6 )
      v8[1] = &this->text.ptr[0x10000];
    v11 = v8[2];
    if ( v11 >= v4 && v11 <= v5 && v7 + 1 != v6 )
      v8[2] = &this->text.ptr[0x10000];
    v7 += 4;
    v8 += 4;
  }
  while ( v7 - 2 < 4096 );
}


// ========================================================================
// DrawVersionString
// EA  : 0x82665F08
// RVA : 0x00665F08
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall DrawVersionString(
        idRenderModelGui *gui,
        const char *version,
        const int sx,
        const int width,
        __int64 sy)
{
  int v7; // r29
  int v8; // r31
  int v9; // r9
  int v10; // r30
  double v11; // fp30
  double v12; // fp29
  __int64 v13; // r11

  v7 = 0;
  if ( *version != 0 )
  {
    do
      ++v7;
    while ( version[v7] != 0 );
  }
  v8 = 0;
  if ( v7 > 0 )
  {
    v9 = (int)(float)-(float)((float)(SMALLCHAR_HEIGHT * (float)1.5)
                            - (float)__SPAIR64__((idCVar *)&r_cuttablemodel_freecpudata.description, HIDWORD(sy)));
    LODWORD(sy) = sx + width;
    v10 = v7;
    v11 = (float)*(__int64 *)((char *)&sy - 4);
    v12 = (float)sy;
    do
    {
      LODWORD(v13) = v10;
      HIDWORD(v13) = (unsigned __int8)version[v8];
      idRenderModelGui::DrawChar(
        this: gui,
        x: (float)-(float)((float)((float)v13 * SMALLCHAR_WIDTH) - (float)v12),
        y: v11,
        character: (int)version,
        scale: 1.0);
      ++v8;
      --v10;
    }
    while ( v8 < v7 );
  }
}


// ========================================================================
// ?BeginTimeRange@idConsoleLocal@@UAAXW4rangeId_t@@ABVidColor@@@Z
// EA  : 0x82666020
// RVA : 0x00666020
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::BeginTimeRange(idConsoleLocal *this, rangeId_t id, const idColor *color)
{
  __int64 v3; // r27
  int v7; // r3
  idColor *v8; // r31
  char v9; // r11

  v8 = &this->lastRangeColor[id];
  v7 = Sys_Microseconds() >> 32;
  LODWORD(v3) = v7;
  if ( v8->r != idColor::colorBlack.r
    || v8->g != idColor::colorBlack.g
    || v8->b != idColor::colorBlack.b
    || (v9 = 1, v8->a != idColor::colorBlack.a) )
  {
    v9 = 0;
  }
  if ( v9 == 0 )
    console->AddTimeRange(
      this: console,
      a2: id,
      a3: (const idColor *)HIDWORD(this->lastRangeMicroseconds[id]),
      a4: LODWORD(this->lastRangeMicroseconds[id]),
      a5: v7);
  this->lastRangeMicroseconds[id] = v3;
  v8->r = color->r;
  v8->g = color->g;
  v8->b = color->b;
  v8->a = color->a;
}


// ========================================================================
// ?AddTimeRange@idConsoleLocal@@UAAXW4rangeId_t@@ABVidColor@@_K2@Z
// EA  : 0x82666110
// RVA : 0x00666110
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idConsoleLocal::AddTimeRange(
        idConsoleLocal *this,
        rangeId_t id,
        const idColor *color,
        unsigned int a4,
        unsigned __int64 startTimeMicroSec,
        unsigned __int64 endTimeMicroSec)
{
  unsigned __int64 v9; // r28 OVERLAPPED
  idSysMutex *p_mutexRange; // r26
  int currentRange; // r11
  char *v12; // r5

  v9 = __PAIR64__(HIDWORD(startTimeMicroSec), a4);
  if ( com_drawThreadSpeeds.valueInteger != 2 || con_logThreadSpeeds.valueInteger != 0 )
  {
    p_mutexRange = &this->mutexRange;
    Sys_MutexLock(handle: &this->mutexRange.handle, blocking: true);
    currentRange = this->currentRange;
    this->currentRange = currentRange + 1;
    v12 = (char *)this + 8 * (currentRange & 0x1FF) + 8 * ((4 * currentRange) & 0x7FC);
    *((_DWORD *)v12 + 37746) = id;
    *((_DWORD *)v12 + 37747) = LODWORD(color->r);
    *((_DWORD *)v12 + 37748) = LODWORD(color->g);
    *((_DWORD *)v12 + 37749) = LODWORD(color->b);
    *((_DWORD *)v12 + 37750) = LODWORD(color->a);
    *((_QWORD *)v12 + 18876) = v9;
    *((_QWORD *)v12 + 18877) = *(unsigned __int64 *)((char *)&v9 + 4);
    Sys_MutexUnlock(handle: &this->mutexRange.handle);
  }
}


// ========================================================================
// ?SetTimeRangeLabel@idConsoleLocal@@UAAXW4rangeId_t@@PBD@Z
// EA  : 0x826661E0
// RVA : 0x006661E0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::SetTimeRangeLabel(idConsoleLocal *this, unsigned int id, const char *label)
{
  if ( com_drawThreadSpeeds.valueInteger != 2 || con_logThreadSpeeds.valueInteger != 0 )
  {
    Sys_MutexLock(handle: &this->mutexRange.handle, blocking: true);
    if ( id <= 0x26 )
      strncpy(dest: this->rangeLabel[id].buf, source: label, count: 0x2Fu);
    Sys_MutexUnlock(handle: &this->mutexRange.handle);
  }
}


// ========================================================================
// ?AddJobListTimeRange@idConsoleLocal@@UAAXW4rangeId_t@@ABVidColor@@PBVidParallelJobList@@_K@Z
// EA  : 0x82666278
// RVA : 0x00666278
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::AddJobListTimeRange(
        idConsoleLocal *this,
        rangeId_t id,
        const idColor *color,
        idParallelJobList *jobList,
        const unsigned __int64 explicitWaitMicroSec)
{
  idConsoleLocal_vtbl *v9; // r27
  int v10; // r28
  int v11; // r25
  int v12; // r3
  idConsoleLocal_vtbl *v13; // r27
  int v14; // r25
  int v15; // r3
  unsigned __int64 WaitTimeMicroSec; // r4
  int v17; // r28
  double v18; // fp30
  unsigned __int64 TotalProcessingTimeMicroSec; // r4
  double v20; // fp29
  unsigned int NumSyncs; // r27
  unsigned int NumExecutedJobs; // r3
  __int64 v23; // r10
  va *v24; // r3
  int v25; // [sp+8h] [-10A8h]
  int v26; // [sp+Ch] [-10A4h]
  int v27; // [sp+10h] [-10A0h]
  int v28; // [sp+14h] [-109Ch]
  int v29; // [sp+18h] [-1098h]
  int v30; // [sp+1Ch] [-1094h]
  va v31; // [sp+50h] [-1060h] BYREF

  v9 = this->idConsole::__vftable;
  v10 = HIDWORD(explicitWaitMicroSec);
  v11 = idParallelJobList::GetStartTimeMicroSec(this: jobList) >> 32;
  v12 = idParallelJobList::GetSubmitTimeMicroSec(this: jobList) >> 32;
  v9->AddTimeRange(this, a2: id, a3: &idColor::colorOrange, a4: v12, a5: v11);
  v13 = this->idConsole::__vftable;
  v14 = idParallelJobList::GetFinishTimeMicroSec(this: jobList) >> 32;
  v15 = idParallelJobList::GetStartTimeMicroSec(this: jobList) >> 32;
  v13->AddTimeRange(this, a2: id, a3: color, a4: v15, a5: v14);
  if ( v10 != 0 )
    HIDWORD(WaitTimeMicroSec) = v10;
  else
    WaitTimeMicroSec = idParallelJobList::GetWaitTimeMicroSec(this: jobList);
  v17 = 49;
  if ( HIDWORD(WaitTimeMicroSec) == 0 )
    v17 = 55;
  v18 = (float)((float)_u64tod(a1: HIDWORD(WaitTimeMicroSec), a2: WaitTimeMicroSec) * (float)0.001);
  TotalProcessingTimeMicroSec = idParallelJobList::GetTotalProcessingTimeMicroSec(this: jobList);
  v20 = (float)_u64tod(a1: HIDWORD(TotalProcessingTimeMicroSec), a2: TotalProcessingTimeMicroSec);
  NumSyncs = idParallelJobList::GetNumSyncs(this: jobList);
  NumExecutedJobs = idParallelJobList::GetNumExecutedJobs(this: jobList);
  HIDWORD(v23) = LODWORD(v18);
  LODWORD(v23) = &unk_821D0000;
  v24 = va::va(
          this: &v31,
          fmt: "%3d jobs, %2d syncs, %2.1f msec, ^%c%1.1f wait",
          a3: __SPAIR64__(NumExecutedJobs, NumSyncs),
          a4: __SPAIR64__(COERCE_UNSIGNED_INT64((float)((float)v20 * (float)0.001)), v17),
          a5: v23,
          a6: v25,
          a7: v26,
          a8: v27,
          a9: v28,
          a10: v29,
          a11: v30);
  this->SetTimeRangeLabel(this, a2: id, a3: (const char *)v24);
}


// ========================================================================
// ?RangeColorIndex@@YAHABVidColor@@@Z
// EA  : 0x826663E0
// RVA : 0x006663E0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

int __fastcall RangeColorIndex(const idColor *color)
{
  double r; // fp0
  int result; // r3
  float *p_b; // r11
  char v5; // r10

  r = color->r;
  result = 0;
  p_b = &logColors[0].color.b;
  while ( 1 )
  {
    if ( r != *(p_b - 2) || color->g != *(p_b - 1) || color->b != *p_b || (v5 = 1, color->a != p_b[1]) )
      v5 = 0;
    if ( v5 != 0 )
      break;
    p_b += 5;
    ++result;
    if ( (int)p_b >= (int)&aAvIdsortUshows[4] )
      return 0;
  }
  return result;
}


// ========================================================================
// ?FindLogRanges@@YA?AUlogRanges_t@@QBUtimeRange_t@@HHW4rangeId_t@@ABVidColor@@@Z
// EA  : 0x82666468
// RVA : 0x00666468
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

logRanges_t *__fastcall FindLogRanges(
        logRanges_t *result,
        const timeRange_t *ranges,
        const int MAX_RANGES,
        const int currentRange,
        const rangeId_t rangeId,
        const idColor *delimeter)
{
  __int64 v6; // r11
  int v13; // r9
  int v14; // r30
  int v15; // r4
  const timeRange_t *v16; // r11
  double a; // fp0
  char v18; // r11
  int v19; // r5
  double r; // fp10
  double v21; // fp9
  double b; // fp8
  double g; // fp7
  const timeRange_t *v24; // r7
  char v25; // r11
  __int64 v26; // r10
  __int64 v27; // r7
  double v28; // fp11
  double v29; // fp6
  char v30; // r11
  int v31; // r11
  __int64 v32; // r10
  int i; // ctr
  int v34; // r10

  LODWORD(v6) = 0;
  result->total = v6;
  memset(Dst: result->microseconds, Val: 0, Size: sizeof(result->microseconds));
  v13 = currentRange - 1;
  v14 = currentRange - MAX_RANGES;
  if ( v13 >= v14 )
  {
    v15 = MAX_RANGES - 1;
    while ( 1 )
    {
      v16 = &ranges[v15 & v13];
      if ( v16->id == rangeId )
      {
        if ( v16->color.r != delimeter->r
          || v16->color.g != delimeter->g
          || v16->color.b != delimeter->b
          || (a = v16->color.a, v18 = 1, a != delimeter->a) )
        {
          v18 = 0;
        }
        if ( v18 != 0 )
          break;
      }
      if ( --v13 < v14 )
        goto LABEL_28;
    }
    v19 = v13 - 1;
    if ( v13 - 1 >= v14 )
    {
      r = idColor::colorRed.r;
      v21 = idColor::colorRed.a;
      b = idColor::colorRed.b;
      g = idColor::colorRed.g;
      do
      {
        v24 = &ranges[v15 & v19];
        if ( v24->id == rangeId )
        {
          if ( v24->color.r != r || v24->color.g != g || v24->color.b != b || (v25 = 1, v24->color.a != v21) )
            v25 = 0;
          if ( v25 == 0 )
          {
            RangeColorIndex(color: &v24->color);
            v26 = *(_QWORD *)(v27 + 32);
            LODWORD(v27) = v26 - *(_DWORD *)(v27 + 28) + *((_DWORD *)&result->total + 2 * HIDWORD(v26) + 1);
            *(&result->total + HIDWORD(v26)) = v27;
            if ( v28 != v29
              || *(float *)(HIDWORD(v27) + 4) != delimeter->g
              || *(float *)(HIDWORD(v27) + 8) != delimeter->b
              || (v30 = 1, *(float *)(HIDWORD(v27) + 12) != delimeter->a) )
            {
              v30 = 0;
            }
            if ( v30 != 0 )
              break;
          }
        }
        --v19;
      }
      while ( v19 >= v14 );
    }
  }
LABEL_28:
  v31 = 0;
  HIDWORD(v32) = result;
  for ( i = 7; i != 0; --i )
  {
    v31 += 16;
    v34 = *(_DWORD *)(HIDWORD(v32) + 12) + LODWORD(result->total);
    HIDWORD(v32) = (char *)result + v31;
    result->total = v32;
    LODWORD(v32) = *(_DWORD *)((char *)&result->total + v31 + 4) + v34;
    result->total = v32;
  }
  return result;
}


// ========================================================================
// ?DrawDebugGraphs@idConsoleLocal@@AAAXXZ
// EA  : 0x82666690
// RVA : 0x00666690
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::DrawDebugGraphs(idConsoleLocal *this)
{
  idDebugGraph *graphFPS; // r9
  idDebugGraph *graphTotalTime; // r11
  idDebugGraph *graphRenderTime; // r11
  idDebugGraph *graphGameTime; // r11
  idDebugGraph *graphGPUTime; // r11
  int v7; // r30
  int *p_num; // r27
  int v9; // r31
  idStaticList<idDebugGraph *,32> *p_debugGraphs; // r28

  graphFPS = this->graphFPS;
  if ( graphFPS != nullptr )
    graphFPS->enable = com_showFPS.valueInteger >= 2;
  graphTotalTime = this->graphTotalTime;
  if ( graphTotalTime != nullptr )
    graphTotalTime->enable = (_cntlzw(com_speeds.valueInteger - 3) & 0x20) != 0;
  graphRenderTime = this->graphRenderTime;
  if ( graphRenderTime != nullptr )
    graphRenderTime->enable = (_cntlzw(com_speeds.valueInteger - 3) & 0x20) != 0;
  graphGameTime = this->graphGameTime;
  if ( graphGameTime != nullptr )
    graphGameTime->enable = (_cntlzw(com_speeds.valueInteger - 3) & 0x20) != 0;
  graphGPUTime = this->graphGPUTime;
  if ( graphGPUTime != nullptr )
    graphGPUTime->enable = (_cntlzw(com_speeds.valueInteger - 3) & 0x20) != 0;
  v7 = 0;
  p_num = &this->debugGraphs.num;
  if ( this->debugGraphs.num > 0 )
  {
    v9 = 0;
    p_debugGraphs = &this->debugGraphs;
    do
    {
      if ( p_debugGraphs->list[v9] != nullptr )
        idDebugGraph::Render(this: p_debugGraphs->list[v9], gui: this->gui);
      ++v7;
      ++v9;
    }
    while ( v7 < *p_num );
  }
}


// ========================================================================
// ?ClearSnapshots@idConsoleLocal@@UAAXXZ
// EA  : 0x826667E0
// RVA : 0x006667E0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::ClearSnapshots(idConsoleLocal *this)
{
  int v1; // r8
  int v2; // r9
  snapObject_t *v3; // r11

  v1 = 0;
  if ( this->snapObjects.num > 0 )
  {
    v2 = 0;
    do
    {
      ++v1;
      v3 = &this->snapObjects.list[v2++];
      v3->ms = 0.0;
      v3->bytesTotal = 0;
      v3->bytesChanged = 0;
      v3->snapObjectsTotal = 0;
      v3->snapObjectsChanged = 0;
    }
    while ( v1 < this->snapObjects.num );
  }
}


// ========================================================================
// ?AddSnapshots@idConsoleLocal@@UAAXPBVidSnapShot@@0HHHH@Z
// EA  : 0x82666848
// RVA : 0x00666848
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::AddSnapshots(
        idConsoleLocal *this,
        const idSnapShot *newSS,
        const idSnapShot *oldSS,
        int size,
        int peer,
        int seq,
        int baseSeq)
{
  idSerializerLog *serializeLog; // r11
  idSnapShot *snapshots; // r3
  idSnapShot *v14; // r3

  if ( com_drawSnapshotMetrics.valueInteger != 0
    && (com_drawSnapshotMetricsPeer.valueInteger < 0 || peer == com_drawSnapshotMetricsPeer.valueInteger) )
  {
    if ( com_drawSnapshotMetrics.valueInteger == 2 )
    {
      if ( this->snapshotsLocked )
        return;
      this->snapshotsLocked = true;
    }
    else
    {
      this->snapshotsLocked = false;
    }
    if ( com_drawSnapshotMetrics.valueInteger == 3 )
    {
      if ( size < this->snapshotsMaxSize )
        return;
      this->snapshotsMaxSize = size;
    }
    else
    {
      this->snapshotsMaxSize = 0;
    }
    if ( com_drawSnapshotMetrics.valueInteger != 4
      || newSS != nullptr && (serializeLog = newSS->serializeLog) != nullptr && serializeLog->fragmented )
    {
      snapshots = this->snapshots;
      if ( newSS != nullptr )
      {
        idSnapShot::operator=(this: snapshots, other: newSS);
        this->snapshotSeqs[0] = seq;
      }
      else
      {
        idSnapShot::Clear(this: snapshots);
      }
      v14 = &this->snapshots[1];
      if ( oldSS != nullptr )
      {
        idSnapShot::operator=(this: v14, other: oldSS);
        this->snapshotSeqs[1] = baseSeq;
      }
      else
      {
        idSnapShot::Clear(this: v14);
      }
      this->snapshotPeerNum = peer;
    }
  }
}


// ========================================================================
// ?DrawBitmapConsole@idConsoleLocal@@UAAXXZ
// EA  : 0x826669A8
// RVA : 0x006669A8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::DrawBitmapConsole(idConsoleLocal *this)
{
  idConsoleLocal *v1; // r16
  unsigned __int8 **bitmapConsoleBuffers; // r20
  int *p_bitmapConsoleWidth; // r21
  int v4; // r23
  int *p_currentLine; // r22
  int bitmapConsoleHeight; // r11
  int v7; // r28
  int v8; // r24
  int currentLine; // r25
  int v10; // r15
  int v11; // r26
  int v12; // r6
  int v13; // r31
  const __int16 *v14; // r27
  int v15; // r29
  __int16 *v16; // r30
  int v17; // r6
  int v18; // r19
  int v19; // r28
  int v20; // r18
  const __int16 *v21; // r30
  char v22; // r31
  idVec4 *v23; // r3
  int v24; // r24
  int v25; // r25
  int v26; // r23
  char v27; // r3
  unsigned __int8 v28; // r11
  int v29; // r11
  int v30; // r26
  int v31; // r18
  unsigned __int8 *v32; // r5
  int v33; // r10
  int i; // ctr
  int v35; // r29
  unsigned int v36; // r9
  unsigned int v37; // r8
  int v38; // r11
  int v40; // [sp+50h] [-F0h]
  int v41; // [sp+54h] [-ECh]
  int v42; // [sp+58h] [-E8h]
  int v43; // [sp+5Ch] [-E4h]
  int v44; // [sp+60h] [-E0h]
  int v45; // [sp+64h] [-DCh]
  int v46; // [sp+68h] [-D8h]
  int v47; // [sp+6Ch] [-D4h]
  int v48; // [sp+70h] [-D0h]
  int v49; // [sp+78h] [-C8h]
  const __int16 *v50; // [sp+80h] [-C0h]
  int *v51; // [sp+84h] [-BCh]

  v48 = 2;
  v1 = this;
  bitmapConsoleBuffers = this->bitmapConsoleBuffers;
  do
  {
    if ( *bitmapConsoleBuffers != nullptr )
    {
      p_bitmapConsoleWidth = &v1->bitmapConsoleWidth;
      v4 = 0;
      p_currentLine = &v1->currentLine;
      bitmapConsoleHeight = v1->bitmapConsoleHeight;
      v51 = &v1->currentLine;
      v7 = bitmapConsoleHeight - 96;
      v46 = 0;
      v8 = bitmapConsoleHeight / 32;
      currentLine = v1->currentLine;
      v10 = v1->bitmapConsoleWidth / 16 - 6;
      v47 = currentLine;
      v45 = bitmapConsoleHeight / 32;
      v42 = v10;
      if ( bitmapConsoleHeight / 32 > 0 )
      {
        while ( currentLine >= 0 && v7 >= 0 )
        {
          if ( *p_currentLine - currentLine < 4096 )
          {
            v11 = 0;
            v12 = 0;
            v44 = 0;
            v13 = 0;
            v14 = v1->lines.ptr[currentLine & 0xFFF];
            v50 = v14;
            v15 = *v14;
            if ( *v14 != 0 )
            {
              v16 = v1->lines.ptr[currentLine & 0xFFF];
              do
              {
                if ( (unsigned __int8)idConsoleLocal::WordWrap(
                                        this: v1,
                                        line: v14,
                                        index: v13,
                                        offset: v12,
                                        numColumns: v10) != 0 )
                {
                  v17 = 0;
                  ++v11;
                }
                ++v16;
                v12 = v17 + 1;
                ++v13;
              }
              while ( *v16 != 0 );
              v44 = v11;
            }
            v18 = v7 - 32 * v11;
            v40 = v18;
            if ( v18 < 0 )
              break;
            v19 = 0;
            v20 = 0;
            v41 = 0;
            v43 = 0;
            if ( v15 != 0 )
            {
              v21 = v14;
              v22 = 31 - _cntlzw(4u);
              do
              {
                if ( (unsigned __int8)idConsoleLocal::WordWrap(
                                        this: v1,
                                        line: v14,
                                        index: v20,
                                        offset: v19,
                                        numColumns: v10) != 0 )
                {
                  v19 = 0;
                  v18 += 32;
                  v41 = 0;
                  v40 = v18;
                }
                v23 = idStr::ColorForIndex(i: (*v21 >> 8) & 0xF);
                v24 = (int)(float)(v23->y * (float)256.0);
                v25 = (int)(float)(v23->x * (float)256.0);
                v26 = (int)(float)(v23->z * (float)256.0);
                if ( v21[1] == 0
                  || (v27 = idConsoleLocal::WordWrap(this: v1, line: v14, index: v20 + 1, offset: v19, numColumns: v10),
                      v28 = 0,
                      v27 != 0) )
                {
                  v28 = 1;
                }
                v49 = v28;
                v29 = (unsigned __int8)*v21;
                v30 = 16 * (v19 + 3);
                while ( 1 )
                {
                  if ( v29 < 32 || v29 > 127 )
                    v29 = 32;
                  v31 = 32;
                  v32 = &consoleFont[512 * v29 - 16385];
                  do
                  {
                    v33 = 0;
                    for ( i = 16; i != 0; --i )
                    {
                      ++v32;
                      v36 = ((((unsigned int)(*p_bitmapConsoleWidth + 31) >> 5) * ((unsigned int)v18 >> 5)
                            + ((unsigned int)(v30 + v33) >> 5)) << (v22 + 7))
                          + 2 * ((((((v30 + v33) & 7) + ((4 * v18) & 0x18)) << v22) & 0xFFFFFFF0) + ((8 * v18) & 8))
                          + (((((v30 + v33) & 7) + ((4 * v18) & 0x18)) << v22) & 0xF);
                      v37 = ((2 * v18) & 0xFFFFFFF0) + v30 + v33++;
                      v35 = (v18 & 8) << (v22 + 3);
                      *(_DWORD *)&(*bitmapConsoleBuffers)[4
                                                        * ((4
                                                          * (2 * (((v36 + v35) & 0xFFFFFE00) + ((16 * v18) & 0x100))
                                                           + ((v36 + v35) & 0x1C0))
                                                          + ((8 * v37) & 0xC0)
                                                          + ((v36 + v35) & 0x3F)) >> v22)] = ((((*v32 * v26) << 8)
                                                                                             & 0xFFFF0000
                                                                                             | (*v32 * v24) & 0xFFFFFF00) << 8)
                                                                                           | (*v32 * v25)
                                                                                           | 0xFF;
                    }
                    --v31;
                    ++v18;
                  }
                  while ( v31 != 0 );
                  v30 += 16;
                  v29 = 32;
                  v19 = v41 + 1;
                  v10 = v42;
                  ++v41;
                  if ( v49 == 0 || v19 >= v42 )
                    break;
                  v18 = v40;
                }
                v14 = v50;
                v20 = v43 + 1;
                v1 = this;
                v18 = v40;
                v38 = ++v43;
                v21 = &v50[v38];
              }
              while ( v50[v38] != 0 );
              v8 = v45;
              currentLine = v47;
              v4 = v46;
              v11 = v44;
              p_currentLine = v51;
            }
            v8 -= v11;
            v45 = v8;
            v7 = v18 - 32 * v11 - 32;
          }
          ++v4;
          --currentLine;
          v46 = v4;
          v47 = currentLine;
          if ( v4 >= v8 )
            break;
        }
      }
    }
    ++bitmapConsoleBuffers;
  }
  while ( v48-- != 1 );
}


// ========================================================================
// ?bitmapConsole_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82666DF0
// RVA : 0x00666DF0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall bitmapConsole_f(const idCmdArgs *args)
{
  mgthread_sleep(ms: 100);
  idConsoleLocal::DrawBitmapConsole(this: &localConsole);
  mgthread_sleep(ms: 10000);
}


// ========================================================================
// ?clear_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82666FD8
// RVA : 0x00666FD8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall clear_f(const idCmdArgs *args)
{
  idConsoleLocal::Clear(this: &localConsole);
}


// ========================================================================
// ?DrawFPS@idConsoleLocal@@AAAXAAM00@Z
// EA  : 0x82666FF0
// RVA : 0x00666FF0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::DrawFPS(idConsoleLocal *this, float *leftY, __int64 centerY, __int64 a4, __int64 a5)
{
  float *v6; // r29
  va *v7; // r3
  int StringWidth; // r27
  char data; // r25
  __int64 v10; // r8
  __int64 v11; // r11
  const idColor *v12; // r5
  idDebugGraph *graphFPS; // r3
  int v14; // r26
  char v15; // r25
  __int64 v16; // r7
  __int64 v17; // r11
  int v18; // [sp+8h] [-10C8h]
  int v19; // [sp+Ch] [-10C4h]
  int v20; // [sp+10h] [-10C0h]
  int v21; // [sp+14h] [-10BCh]
  int v22; // [sp+18h] [-10B8h]
  int v23; // [sp+1Ch] [-10B4h]
  __int64 v24; // [sp+50h] [-1080h]
  __int64 v25; // [sp+50h] [-1080h]
  idStr v26; // [sp+60h] [-1070h] BYREF
  va v27; // [sp+80h] [-1050h] BYREF

  v6 = (float *)HIDWORD(centerY);
  HIDWORD(centerY) = time_FPS;
  v7 = va::va(this: &v27, fmt: "%ifps", a3: centerY, a4, a5, a6: v18, a7: v19, a8: v20, a9: v21, a10: v22, a11: v23);
  idStr::idStr(this: &v26, text: v7);
  StringWidth = idRenderModelGui::GetStringWidth(this: this->gui, string: v26.data, scale: 1.0);
  data = (char)v26.data;
  LODWORD(v10) = (int)*v6 + 2;
  v24 = v10;
  LODWORD(v11) = renderSystem->GetWidth(this: renderSystem) + -53 - StringWidth;
  idRenderModelGui::DrawString(
    this: this->gui,
    x: (float)v11,
    y: (float)v24,
    string: (const char *)v11,
    defaultColor: (const idVec4 *)(-53 - StringWidth),
    forceColor: data,
    scale: 1.0);
  graphFPS = this->graphFPS;
  if ( graphFPS != nullptr )
    idDebugGraph::SetValue(
      this: graphFPS,
      b: -1,
      value: (float)((float)__SPAIR64__(&unk_821D0000, time_FPS) * 0.016666668),
      color: v12);
  *v6 = (float)(*v6 + SMALLCHAR_HEIGHT) + (float)4.0;
  idResolutionScale::GetConsoleText(this: &resolutionScale, s: &v26);
  v14 = idRenderModelGui::GetStringWidth(this: this->gui, string: v26.data, scale: 1.0);
  v15 = (char)v26.data;
  HIDWORD(v16) = renderSystem->GetWidth;
  LODWORD(v16) = (int)*v6 + 2;
  v25 = v16;
  LODWORD(v17) = ((int (__fastcall *)(idRenderSystem *))HIDWORD(v16))(a1: renderSystem) + -53 - v14;
  idRenderModelGui::DrawString(
    this: this->gui,
    x: (float)v17,
    y: (float)v25,
    string: (const char *)v17,
    defaultColor: (const idVec4 *)(-53 - v14),
    forceColor: v15,
    scale: 1.0);
  *v6 = (float)(*v6 + SMALLCHAR_HEIGHT) + (float)4.0;
  idStr::FreeData(this: &v26);
}


// ========================================================================
// __unwind$231695
// EA  : 0x82667218
// RVA : 0x00667218
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_231695()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4304 + 96));
}


// ========================================================================
// ?DrawComSpeeds@idConsoleLocal@@AAAXAAM00@Z
// EA  : 0x82667240
// RVA : 0x00667240
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::DrawComSpeeds(idConsoleLocal *this, float *leftY, float *rightY, float *centerY)
{
  idGame *v6; // r3
  int v7; // r4
  double v8; // fp31
  int v9; // r10
  int v10; // r21
  double v11; // fp1
  __int64 v12; // r10
  __int64 v13; // r6
  __int64 v14; // r11
  int i; // r27
  __int64 v16; // r8
  __int64 v17; // r10
  __int64 v18; // r10
  __int64 v19; // r8
  double Max; // fp26
  double Min; // fp25
  double Average; // fp1
  double v23; // fp25
  double v24; // fp24
  double v25; // fp1
  double v26; // fp25
  double v27; // fp24
  double v28; // fp1
  double v29; // fp24
  double v30; // fp23
  double v31; // fp22
  double v32; // fp21
  double v33; // fp1
  int v34; // r4
  double v35; // fp1
  double v36; // fp31
  const idColor *v37; // r5
  __int64 v38; // r8
  const idColor *v39; // r5
  const idColor *v40; // r5
  int v41; // r4
  __int64 v42; // r10
  idDebugGraph *graphRenderTime; // r3
  double v44; // fp1
  __int64 v45; // r11
  const idColor *v46; // r5
  int v47; // [sp+8h] [-138h]
  int v48; // [sp+Ch] [-134h]
  int v49; // [sp+10h] [-130h]
  int v50; // [sp+14h] [-12Ch]
  int v51; // [sp+18h] [-128h]
  int v52; // [sp+1Ch] [-124h]
  int v53; // [sp+20h] [-120h]
  const char *v54; // [sp+28h] [-118h]
  int v55; // [sp+2Ch] [-114h]

  v6 = common->Game(this: common);
  v8 = ((double (__fastcall *)(idGame *, _DWORD))v6->GetRealMsPerFrame)(a1: v6, a2: 0);
  if ( count_numGameFrames <= 0 )
  {
    v10 = 0;
  }
  else
  {
    v9 = time_gameFrame;
    __twllei(count_numGameFrames, 0);
    v10 = v9 / count_numGameFrames;
    __twlgei(count_numGameFrames & ~(__ROL4__(v9, 1) - 1), 0xFFFFFFFF);
  }
  v11 = _u64tod(a1: time_frame, a2: v7);
  idRunningAverage::Add(this: &this->avgTotalTime, val: (float)((float)v11 * (float)0.001));
  LODWORD(v12) = time_maxGameFrame;
  idRunningAverage::Add(this: &this->avgGameTime, val: (float)((float)v12 * (float)0.001));
  LODWORD(v14) = count_numGameFrames;
  for ( i = 1; i < count_numGameFrames; ++i )
  {
    LODWORD(v16) = v14 - 1;
    HIDWORD(v16) = time_gameFrame - time_maxGameFrame;
    LODWORD(v13) = time_gameFrame - time_maxGameFrame;
    idRunningAverage::Add(this: &this->avgGameTime, val: (float)((float)((float)v13 * (float)0.001) / (float)v16));
    LODWORD(v14) = count_numGameFrames;
  }
  LODWORD(v14) = time_renderFrame;
  idRunningAverage::Add(this: &this->avgRenderTime, val: (float)((float)v14 * (float)0.001));
  LODWORD(v17) = time_GPUFrameTime;
  idRunningAverage::Add(this: &this->avgGPUTime, val: (float)((float)v17 * (float)0.001));
  HIDWORD(v18) = 0x82000000;
  LODWORD(v19) = &unk_821D0000;
  idConsoleLocal::DrawTextRightAlign(
    this,
    y: COERCE_FLOAT_(1.0),
    opacity: 1.0,
    text: v54,
    a5: "avg   min   max",
    a6: v19,
    a7: v18,
    a8: v47,
    a9: v48,
    a10: v49,
    a11: v50,
    a12: v51,
    a13: v52,
    a14: v53,
    a15: COERCE_INT(1.0),
    a16: (int)v54,
    a17: v55);
  Max = idRunningAverage::GetMax(this: &this->avgTotalTime);
  Min = idRunningAverage::GetMin(this: &this->avgTotalTime);
  Average = idRunningAverage::GetAverage(this: &this->avgTotalTime);
  _idConsoleLocal::DrawComSpeeds_::_2_::local_t::DrawTimeAvgMaxMin(
    console: this,
    rightY,
    name: "T:  ",
    avg: Average,
    max: Min,
    min: Max,
    orangeTime: (float)((float)v8 - (float)3.0),
    redTime: (float)((float)v8 + (float)1.0));
  v23 = idRunningAverage::GetMax(this: &this->avgGameTime);
  v24 = idRunningAverage::GetMin(this: &this->avgGameTime);
  v25 = idRunningAverage::GetAverage(this: &this->avgGameTime);
  _idConsoleLocal::DrawComSpeeds_::_2_::local_t::DrawTimeAvgMaxMin(
    console: this,
    rightY,
    name: "GT: ",
    avg: v25,
    max: v24,
    min: v23,
    orangeTime: (float)((float)v8 - (float)5.0),
    redTime: (float)((float)v8 - (float)1.0));
  v26 = idRunningAverage::GetMax(this: &this->avgRenderTime);
  v27 = idRunningAverage::GetMin(this: &this->avgRenderTime);
  v28 = idRunningAverage::GetAverage(this: &this->avgRenderTime);
  _idConsoleLocal::DrawComSpeeds_::_2_::local_t::DrawTimeAvgMaxMin(
    console: this,
    rightY,
    name: "RT: ",
    avg: v28,
    max: v27,
    min: v26,
    orangeTime: (float)((float)v8 - (float)3.0),
    redTime: (float)((float)v8 + (float)1.0));
  v29 = (float)(rs_dropMilliseconds.valueFloat - (float)0.1);
  v30 = (float)(rs_raiseMilliseconds.valueFloat - (float)0.1);
  v31 = idRunningAverage::GetMax(this: &this->avgGPUTime);
  v32 = idRunningAverage::GetMin(this: &this->avgGPUTime);
  v33 = idRunningAverage::GetAverage(this: &this->avgGPUTime);
  _idConsoleLocal::DrawComSpeeds_::_2_::local_t::DrawTimeAvgMaxMin(
    console: this,
    rightY,
    name: "GPU:",
    avg: v33,
    max: v32,
    min: v31,
    orangeTime: v30,
    redTime: v29);
  v35 = _u64tod(a1: time_frame, a2: v34);
  v36 = (float)((float)v8 * (float)1000.0);
  idDebugGraph::SetValue(
    this: this->graphTotalTime,
    b: -1,
    value: (float)((float)((float)v35 / (float)v36) * (float)0.5),
    color: v37);
  LODWORD(v38) = v10;
  idDebugGraph::SetValue(
    this: this->graphGameTime,
    b: -1,
    value: (float)((float)((float)v38 / (float)v36) * 0.5),
    color: v39);
  HIDWORD(v42) = &renderLog.indentString[28];
  if ( r_useSMP.valueInteger != 0 )
  {
    _u64tod(a1: time_frame, a2: v41);
    graphRenderTime = this->graphRenderTime;
    v44 = (float)((float)((float)(time_renderFrame | 0x2A52800000000uLL) / (float)v36) * (float)0.5);
  }
  else
  {
    LODWORD(v42) = time_renderFrame + v10;
    graphRenderTime = this->graphRenderTime;
    v44 = (float)((float)((float)v42 / (float)v36) * 0.5);
  }
  idDebugGraph::SetValue(this: graphRenderTime, b: -1, value: v44, color: v40);
  LODWORD(v45) = time_GPUFrameTime;
  idDebugGraph::SetValue(
    this: this->graphGPUTime,
    b: -1,
    value: (float)((float)((float)v45 / (float)v36) * 0.5),
    color: v46);
}


// ========================================================================
// ?DrawTimer@idConsoleLocal@@AAAXAAM00@Z
// EA  : 0x82667880
// RVA : 0x00667880
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::DrawTimer(idConsoleLocal *this, float *leftY, float *rightY, float *centerY)
{
  int valueInteger; // r30
  idGame *v7; // r3
  __int64 v8; // r7
  double v9; // fp31
  __int128 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  va *v13; // r3
  __int64 v14; // r6
  __int64 v15; // r11
  char data; // r30
  int v17; // r29
  __int64 v18; // r4
  __int64 v19; // r6
  int v20; // [sp+8h] [-10B8h]
  int v21; // [sp+Ch] [-10B4h]
  int v22; // [sp+10h] [-10B0h]
  int v23; // [sp+14h] [-10ACh]
  int v24; // [sp+18h] [-10A8h]
  int v25; // [sp+1Ch] [-10A4h]
  double v26; // [sp+20h] [-10A0h]
  __int64 v27; // [sp+58h] [-1068h]
  idStr v28; // [sp+60h] [-1060h] BYREF
  va v29; // [sp+80h] [-1040h] BYREF

  valueInteger = com_timer.valueInteger;
  if ( com_timer.valueInteger < 0 )
  {
    idCVar::SetInteger(this: &com_timer, newValue: idLib::frameNumber, force: true);
    valueInteger = idLib::frameNumber;
  }
  v7 = common->Game(this: common);
  LODWORD(v8) = idLib::frameNumber;
  HIDWORD(v8) = (idGame)v7->__vftable;
  v9 = (float)((float)v8 - (float)__SPAIR64__(idLib::frameNumber, valueInteger));
  v26 = (float)((float)v9 / (float)__SPAIR64__(&unk_821D0000, v7->GetGameHz(this: v7, a2: GAMETIME_SCALED)));
  *(double *)((char *)&v10 + 4) = v26;
  v13 = va::va(
          this: &v29,
          fmt: (const char *)HIDWORD(v26),
          a3: v10,
          a4: v12,
          a5: v11,
          a6: v20,
          a7: v21,
          a8: v22,
          a9: v23,
          a10: v24,
          a11: v25);
  idStr::idStr(this: &v28, text: v13);
  HIDWORD(v15) = v28.data;
  LODWORD(v15) = 0;
  if ( *v28.data != 0 )
  {
    do
      LODWORD(v15) = v15 + 1;
    while ( v28.data[v15] != 0 );
  }
  LODWORD(v14) = (int)*rightY + 2;
  data = (char)v28.data;
  v27 = v14;
  v17 = (int)(float)((float)v15 * SMALLCHAR_WIDTH);
  v18 = ((__int64 (__fastcall *)(idRenderSystem *))renderSystem->GetWidth)(a1: renderSystem);
  LODWORD(v19) = HIDWORD(v18) + -53 - v17;
  idRenderModelGui::DrawString(
    this: this->gui,
    x: (float)v19,
    y: (float)v27,
    string: (const char *)v18,
    defaultColor: (const idVec4 *)HIDWORD(v19),
    forceColor: data,
    scale: 1.0);
  *rightY = (float)(*rightY + SMALLCHAR_HEIGHT) + (float)4.0;
  idStr::FreeData(this: &v28);
}


// ========================================================================
// __unwind$231950
// EA  : 0x82667A64
// RVA : 0x00667A64
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_231950()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 96));
}


// ========================================================================
// ?Dump@idConsoleLocal@@UAAXPBDPAVidStr@@@Z
// EA  : 0x82667A90
// RVA : 0x00667A90
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::Dump(idConsoleLocal *this, const char *fileName, idStr *outString)
{
  idFile *v6; // r25
  int currentLine; // r8
  signed int v8; // r29
  int v9; // r11
  __int16 *v10; // r10
  unsigned __int8 v11; // r9
  int v12; // r31
  __int16 *v13; // r30
  unsigned int v14; // r11
  __int16 *i; // r10
  unsigned int v16; // r5
  char *v17; // r11
  const char *v18; // r3
  char v19[1120]; // [sp+50h] [-460h] BYREF

  if ( fileName != nullptr || outString != nullptr )
  {
    v6 = nullptr;
    if ( fileName == nullptr || (v6 = fileSystem->OpenFileWrite(this: fileSystem, a2: fileName, a3: 2)) != nullptr )
    {
      currentLine = this->currentLine;
      v8 = (((unsigned int)(currentLine - 4095) >> 31) - 1) & (currentLine - 4095);
      if ( v8 <= currentLine )
      {
        do
        {
          v9 = 0;
          v10 = this->lines.ptr[v8 & 0xFFF];
          v11 = *v10;
          if ( *v10 != 0 )
          {
            do
            {
              if ( v11 > 0x20u )
                break;
              v11 = v10[++v9];
            }
            while ( v10[v9] != 0 );
          }
          if ( v10[v9] != 0 )
            break;
          ++v8;
        }
        while ( v8 <= currentLine );
        if ( v8 <= currentLine )
        {
          do
          {
            v12 = 0;
            v13 = this->lines.ptr[v8 & 0xFFF];
            if ( *v13 != 0 )
            {
              do
              {
                v14 = 0;
                for ( i = &v13[v12]; *i != 0; ++i )
                {
                  if ( v14 >= 0x3FF )
                    break;
                  v19[v14++] = *i;
                }
                v12 += v14;
                v19[v14] = 0;
                if ( outString != nullptr )
                  idStr::Append(this: outString, text: v19);
                if ( v6 != nullptr )
                {
                  v16 = 0;
                  if ( v19[0] != 0 )
                  {
                    v17 = v19;
                    do
                    {
                      ++v17;
                      ++v16;
                    }
                    while ( *v17 != 0 );
                  }
                  v6->Write(this: v6, a2: v19, a3: v16);
                }
              }
              while ( v13[v12] != 0 );
            }
            if ( outString != nullptr )
              idStr::Append(this: outString, text: "\r\n");
            if ( v6 != nullptr )
              v6->Write(this: v6, a2: "\r\n", a3: 2u);
            ++v8;
          }
          while ( v8 <= this->currentLine );
        }
      }
      if ( v6 != nullptr )
      {
        v18 = v6->GetFullPath(this: v6);
        idLib::Printf(fmt: "Dumped console text to %s.\n", v18);
        ((void (__fastcall *)(idFile *, int))v6->dtr_idFile)(a1: v6, a2: 1);
      }
    }
    else
    {
      idLib::Warning(fmt: "couldn't open %s", fileName);
    }
  }
}


// ========================================================================
// ?DrawNotify@idConsoleLocal@@AAAXXZ
// EA  : 0x82667D18
// RVA : 0x00667D18
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::DrawNotify(idConsoleLocal *this)
{
  __int64 v2; // r8
  int v3; // r23
  int v4; // r20
  const idVec4 *v5; // r3
  idRenderModelGui *gui; // r31
  int v7; // r16
  int v8; // r26
  int currentLine; // r11
  int v10; // r24
  int v11; // r11
  __int64 v12; // r10
  int v13; // r30
  __int64 v14; // r11
  const __int16 *v15; // r27
  int v16; // r31
  unsigned __int16 *v17; // r29
  __int64 v18; // r11
  __int64 v19; // r9
  int v20; // r4
  int v21; // r9
  const idVec4 *v22; // r3
  idRenderModelGui *v23; // r15
  __int64 v24; // r11
  idRenderModelGui *v25; // r31

  LODWORD(v2) = renderSystem->GetWidth(this: renderSystem);
  v3 = 7;
  v4 = (int)(float)((float)((float)v2 - SMALLCHAR_WIDTH) / SMALLCHAR_WIDTH);
  v5 = idStr::ColorForIndex(i: 7);
  gui = this->gui;
  gui->currentVertexColor = idColor::PackColor(color: v5);
  v7 = Sys_Milliseconds();
  v8 = 32;
  currentLine = this->currentLine;
  v10 = currentLine - 3;
  if ( currentLine - 3 <= currentLine )
  {
    do
    {
      if ( v10 >= 1 )
      {
        v11 = this->times.ptr[v10 % 4];
        if ( v11 != 0 )
        {
          LODWORD(v12) = v7 - v11;
          HIDWORD(v12) = 4 * (v10 / 4);
          if ( (float)v12 <= (double)(float)(con_notifyTime.valueFloat * (float)1000.0) )
          {
            v13 = 0;
            HIDWORD(v14) = (v10 & 0xFFF) + 33033;
            v15 = *((const __int16 **)&this->idConsole::__vftable + HIDWORD(v14));
            v16 = (int)(float)((float)48.0 / SMALLCHAR_WIDTH);
            if ( *v15 != 0 )
            {
              v17 = *((unsigned __int16 **)&this->idConsole::__vftable + HIDWORD(v14));
              do
              {
                if ( (unsigned __int8)idConsoleLocal::WordWrap(this, line: v15, index: v13, offset: v16, numColumns: v4) != 0 )
                {
                  LODWORD(v18) = v8;
                  v16 = 0;
                  v8 = (int)(float)((float)v18 + SMALLCHAR_HEIGHT);
                }
                v21 = (__int16)*v17 >> 8;
                if ( (v21 & 0xF) != v3 )
                {
                  v3 = v21 & 0xF;
                  v22 = idStr::ColorForIndex(i: v3);
                  v23 = this->gui;
                  v23->currentVertexColor = idColor::PackColor(color: v22);
                }
                LODWORD(v24) = v8;
                HIDWORD(v24) = *v17;
                LODWORD(v19) = ++v16;
                idRenderModelGui::DrawChar(
                  this: this->gui,
                  x: (float)((float)v19 * SMALLCHAR_WIDTH),
                  y: (float)v24,
                  character: v20,
                  scale: 1.0);
                v17 = (unsigned __int16 *)&v15[++v13];
              }
              while ( *v17 != 0 );
            }
            LODWORD(v14) = v8;
            v8 = (int)(float)((float)v14 + SMALLCHAR_HEIGHT);
          }
        }
      }
      ++v10;
    }
    while ( v10 <= this->currentLine );
  }
  v25 = this->gui;
  v25->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&idColor::colorCyan);
}


// ========================================================================
// ?DrawSolidConsole@idConsoleLocal@@ABAXM@Z
// EA  : 0x82667FC0
// RVA : 0x00667FC0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::DrawSolidConsole(idConsoleLocal *this, double currentDisplayFrac)
{
  __int64 v4; // r9
  int v5; // r27
  int v6; // r29
  double v7; // fp30
  __int64 v8; // r9
  __int64 v9; // r9
  double v10; // fp2
  double v11; // fp30
  idVec4 *v12; // r3
  double v13; // fp31
  double v14; // fp29
  double v15; // fp28
  double v16; // fp27
  idVec4 *v17; // r3
  float y; // r7
  float z; // r6
  float w; // r5
  __int64 v21; // r11
  idRenderModelGui *gui; // r28
  __int64 v23; // r8
  __int64 v24; // r8
  double v25; // fp29
  const idVec4 *v26; // r3
  idRenderModelGui *v27; // r28
  idRenderModelGui *v28; // r27
  int v29; // r26
  unsigned int v30; // r3
  __int64 v31; // r7
  int v32; // r4
  __int64 v33; // r11
  __int64 v34; // r10
  int *p_currentLine; // r26
  double v36; // fp30
  int v37; // r15
  int v38; // r20
  idRenderModelGui *v39; // r28
  int v40; // r29
  __int64 v41; // r10
  int v42; // r4
  double v43; // fp29
  int displayLine; // r19
  __int64 v45; // r10
  __int64 v46; // r8
  __int64 v47; // r6
  int i; // r14
  int v49; // r29
  va *v50; // r3
  const __int16 *v51; // r25
  const idVec4 *v52; // r3
  idRenderModelGui *v53; // r28
  int v54; // r4
  int v55; // r11
  __int64 v56; // r9
  int v57; // r28
  const idVec4 *v58; // r3
  idRenderModelGui *v59; // r28
  _BYTE v60[12]; // r11
  int v61; // r4
  int v62; // r28
  int v63; // r27
  idRenderModelGui *v64; // r3
  int v65; // r21
  int v66; // r22
  int v67; // r26
  int v68; // r23
  int v69; // r28
  const __int16 *v70; // r27
  double v71; // fp0
  int v72; // r29
  int v73; // r28
  double v74; // fp30
  const __int16 *v75; // r27
  int v76; // r4
  double v77; // fp0
  __int64 v78; // r10
  const idVec4 *v79; // r3
  idRenderModelGui *v80; // r26
  idRenderModelGui *v81; // r3
  int v82; // [sp+8h] [-11B8h]
  int v83; // [sp+Ch] [-11B4h]
  int v84; // [sp+10h] [-11B0h]
  int v85; // [sp+14h] [-11ACh]
  int v86; // [sp+18h] [-11A8h]
  int v87; // [sp+1Ch] [-11A4h]
  idVec4 v88; // [sp+70h] [-1150h] BYREF
  idVec4 v89; // [sp+80h] [-1140h] BYREF
  __int64 v90; // [sp+90h] [-1130h]
  __int64 v91; // [sp+98h] [-1128h]
  unsigned __int64 v92; // [sp+A0h] [-1120h]
  idStr v93; // [sp+B0h] [-1110h] BYREF
  idStr v94; // [sp+D0h] [-10F0h] BYREF
  va v95; // [sp+F0h] [-10D0h] BYREF

  LODWORD(v4) = renderSystem->GetHeight(this: renderSystem);
  v5 = (int)(float)((float)v4 * (float)currentDisplayFrac);
  if ( v5 > 0 )
  {
    if ( v5 > renderSystem->GetHeight(this: renderSystem) )
      v5 = renderSystem->GetHeight(this: renderSystem);
    v6 = renderSystem->GetWidth(this: renderSystem) - 96;
    v88.z = 0.0;
    v88.x = 0.0;
    v88.y = 0.0;
    v88.w = r_consoleTransparency.valueFloat;
    v7 = (float)((float)__SPAIR64__(0x82000000, renderSystem->GetHeight(this: renderSystem)) * (float)currentDisplayFrac);
    if ( v7 >= 1.0 )
    {
      LODWORD(v8) = renderSystem->GetWidth(this: renderSystem);
      idRenderModelGui::DrawFilled(this: this->gui, color: &v88, x: 0.0, y: 0.0, w: (float)v8, h: v7);
    }
    else
    {
      v7 = 0.0;
    }
    v9 = __PAIR64__(&off_82010000, renderSystem->GetWidth(this: renderSystem));
    v10 = v7;
    v11 = *(float *)(HIDWORD(v9) - 11888);
    idRenderModelGui::DrawFilled(
      this: this->gui,
      color: (const idVec4 *)&idColor::colorOrange,
      x: 0.0,
      y: v10,
      w: (float)v9,
      h: v11);
    ++versionColorCounter;
    v12 = idStr::ColorForIndex(i: 49);
    v13 = (float)(v12->w * (float)0.75);
    v14 = (float)(v12->z * (float)0.75);
    v15 = (float)(v12->y * (float)0.75);
    v16 = (float)(v12->x * (float)0.75);
    v17 = idStr::ColorForIndex(i: 49);
    y = v17->y;
    z = v17->z;
    w = v17->w;
    LODWORD(v21) = versionColorCounter % 0x168;
    if ( versionColorCounter % 0x168 >= 0xB4 )
      LODWORD(v21) = 360 - v21;
    gui = this->gui;
    HIDWORD(v21) = &unk_821D0000;
    v89.x = (float)((float)((float)(v17->x - (float)v16) * (float)v21) * (float)0.0055555557) + (float)v16;
    v89.w = (float)((float)((float)(w - (float)v13) * (float)v21) * (float)0.0055555557) + (float)v13;
    v89.z = (float)((float)((float)(z - (float)v14) * (float)v21) * (float)0.0055555557) + (float)v14;
    v89.y = (float)((float)((float)(y - (float)v15) * (float)v21) * (float)0.0055555557) + (float)v15;
    gui->currentVertexColor = idColor::PackColor(color: &v89);
    HIDWORD(v23) = v5;
    DrawVersionString(gui: this->gui, version: versionInfo.fullVersion, sx: 48, width: v6, sy: v23);
    LODWORD(v24) = v5;
    v25 = (float)v24;
    HIDWORD(v24) = (int)(float)((float)v24 - SMALLCHAR_HEIGHT);
    DrawVersionString(gui: this->gui, version: versionInfo.netVersion, sx: 48, width: v6, sy: v24);
    v26 = idStr::ColorForIndex(i: 55);
    v27 = this->gui;
    v27->currentVertexColor = idColor::PackColor(color: v26);
    v28 = this->gui;
    v29 = (int)(float)-(float)((float)(SMALLCHAR_HEIGHT * (float)v11) - (float)v25);
    v30 = idColor::PackColor(color: (const idVec4 *)&idColor::colorWhite);
    LODWORD(v31) = v29;
    v28->currentVertexColor = v30;
    idRenderModelGui::DrawChar(
      this: this->gui,
      x: (float)(SMALLCHAR_WIDTH + (float)48.0),
      y: (float)v31,
      character: v32,
      scale: 1.0);
    LODWORD(v33) = v6 + 48;
    idEditField::Draw(
      this: &this->consoleField,
      gui: this->gui,
      x: (int)(float)((float)(SMALLCHAR_WIDTH * (float)v11) + (float)48.0),
      y: v29,
      width: (int)(float)-(float)((float)(SMALLCHAR_WIDTH * (float)3.0) - (float)v33),
      showCursor: true);
    LODWORD(v34) = v6;
    p_currentLine = &this->currentLine;
    v36 = (float)-(float)((float)(SMALLCHAR_HEIGHT * (float)3.0) - (float)v25);
    v37 = (int)(float)((float)((float)v25 - SMALLCHAR_HEIGHT) / SMALLCHAR_HEIGHT);
    v38 = (int)(float)((float)((float)v34 - SMALLCHAR_WIDTH) / SMALLCHAR_WIDTH);
    if ( this->displayLine != this->currentLine )
    {
      v39 = this->gui;
      v40 = 0;
      v39->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&idColor::colorWhite);
      if ( v38 > 0 )
      {
        LODWORD(v41) = (int)v36;
        v43 = (float)v41;
        do
        {
          LODWORD(v41) = v40 + 1;
          idRenderModelGui::DrawChar(
            this: this->gui,
            x: (float)((float)((float)v41 * SMALLCHAR_WIDTH) + (float)48.0),
            y: v43,
            character: v42,
            scale: 1.0);
          v40 += 4;
        }
        while ( v40 < v38 );
      }
      --v37;
      v36 = (float)((float)v36 - SMALLCHAR_HEIGHT);
    }
    displayLine = this->displayLine;
    idStr::idStr(this: &v94, text: " : ");
    for ( i = 0; i < v37; --displayLine )
    {
      if ( displayLine < 0 )
        break;
      LODWORD(v45) = *p_currentLine - displayLine;
      if ( (int)v45 < 4096 )
      {
        HIDWORD(v47) = displayLine;
        v49 = 0;
        v50 = va::va(
                this: &v95,
                fmt: "%d",
                a3: v47,
                a4: v46,
                a5: v45,
                a6: v82,
                a7: v83,
                a8: v84,
                a9: v85,
                a10: v86,
                a11: v87);
        idStr::idStr(this: &v93, text: v50);
        v51 = this->lines.ptr[displayLine & 0xFFF];
        v52 = idStr::ColorForIndex(i: 2);
        v53 = this->gui;
        v53->currentVertexColor = idColor::PackColor(color: v52);
        v55 = 0;
        HIDWORD(v56) = v93.len;
        if ( v93.len > 0 )
        {
          do
          {
            v57 = v55 + 1;
            LODWORD(v56) = v55 + 1;
            idRenderModelGui::DrawChar(
              this: this->gui,
              x: (float)((float)((float)v56 * SMALLCHAR_WIDTH) + (float)48.0),
              y: v36,
              character: v54,
              scale: 1.0);
            HIDWORD(v56) = v93.len;
            ++v49;
            v55 = v57;
          }
          while ( v57 < v93.len );
        }
        v58 = idStr::ColorForIndex(i: 4);
        v59 = this->gui;
        v59->currentVertexColor = idColor::PackColor(color: v58);
        v62 = 0;
        if ( v94.len > 0 )
        {
          v63 = v49 + 1;
          do
          {
            v64 = this->gui;
            v92 = __PAIR64__((unsigned int)v94.data, v63);
            idRenderModelGui::DrawChar(
              this: v64,
              x: (float)((float)((float)__SPAIR64__((unsigned int)v94.data, v63) * SMALLCHAR_WIDTH) + (float)48.0),
              y: v36,
              character: v61,
              scale: 1.0);
            *(_DWORD *)v60 = v94.len;
            ++v62;
            ++v49;
            ++v63;
          }
          while ( v62 < v94.len );
        }
        v65 = 4;
        v66 = v49;
        v67 = *v51;
        v68 = 0;
        v69 = 0;
        if ( *v51 != 0 )
        {
          v70 = v51;
          do
          {
            if ( (unsigned __int8)idConsoleLocal::WordWrap(this, line: v51, index: v69, offset: v49, numColumns: v38) != 0 )
            {
              v49 = v66;
              ++v68;
            }
            ++v70;
            ++v49;
            ++v69;
          }
          while ( *v70 != 0 );
        }
        *(_DWORD *)&v60[8] = v68;
        v71 = SMALLCHAR_HEIGHT;
        v72 = v66;
        v91 = *(_QWORD *)&v60[4];
        v73 = 0;
        v74 = (float)-(float)((float)((float)*(__int64 *)&v60[4] * SMALLCHAR_HEIGHT) - (float)v36);
        if ( v67 != 0 )
        {
          v75 = v51;
          do
          {
            if ( (unsigned __int8)idConsoleLocal::WordWrap(this, line: v51, index: v73, offset: v72, numColumns: v38) != 0 )
            {
              v72 = v66;
              v74 = (float)((float)v77 + (float)v74);
            }
            HIDWORD(v78) = *v75 >> 8;
            if ( (BYTE3(v78) & 0xF) != v65 )
            {
              v65 = BYTE3(v78) & 0xF;
              v79 = idStr::ColorForIndex(i: v65);
              v80 = this->gui;
              v80->currentVertexColor = idColor::PackColor(color: v79);
            }
            ++v72;
            v81 = this->gui;
            LODWORD(v78) = v72;
            v90 = v78;
            idRenderModelGui::DrawChar(
              this: v81,
              x: (float)((float)((float)v78 * SMALLCHAR_WIDTH) + (float)48.0),
              y: v74,
              character: v76,
              scale: 1.0);
            ++v73;
            v71 = SMALLCHAR_HEIGHT;
            v75 = &v51[v73];
            *(_DWORD *)v60 = *(unsigned __int16 *)v75;
          }
          while ( *v75 != 0 );
        }
        v37 -= v68;
        *(_DWORD *)&v60[4] = v68 + 1;
        v36 = (float)-(float)((float)((float)*(__int64 *)v60 * (float)v71) - (float)v74);
        idStr::FreeData(this: &v93);
        p_currentLine = &this->currentLine;
      }
      ++i;
    }
    idStr::FreeData(this: &v94);
  }
}


// ========================================================================
// __unwind$232118_0
// EA  : 0x826687B4
// RVA : 0x006687B4
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_232118_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4544 + 208));
}


// ========================================================================
// __unwind$232119
// EA  : 0x826687DC
// RVA : 0x006687DC
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_232119()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4544 + 176));
}


// ========================================================================
// ?DrawTimeRanges@idConsoleLocal@@AAAXXZ
// EA  : 0x82668810
// RVA : 0x00668810
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idConsoleLocal::DrawTimeRanges(idConsoleLocal *this)
{
  const idVec4 *v1; // r5
  __int64 v2; // r11
  const char *v3; // r4
  _DWORD *v4; // r28
  int v6; // r30
  unsigned __int64 lastVblMicroseconds; // r11 OVERLAPPED
  unsigned __int64 v8; // r3
  bool v9; // r17
  int v10; // r5
  __int64 v11; // r4 OVERLAPPED
  int currentRange; // r11
  __int64 v13; // r10 OVERLAPPED
  int v14; // r24
  double v15; // fp28
  double v16; // fp18
  double v17; // fp19
  char *v18; // r7
  _DWORD *v19; // r30
  __int128 v20; // r6
  double v21; // fp13
  double v22; // fp31
  double v23; // fp30
  double v24; // fp29
  __int128 v25; // r6
  __int64 v26; // r10
  __int64 v27; // r8
  va *v28; // r3
  int v29; // r30
  __int64 v30; // r10
  int v31; // r11
  int v32; // r26
  double v33; // fp28
  idRenderModelGui *gui; // r30
  int v35; // r28
  __int64 v36; // r11 OVERLAPPED
  int v37; // r9 OVERLAPPED
  __int64 v38; // r8
  int v39; // r4
  int v40; // r30
  double v41; // fp31
  double v42; // fp30
  double v43; // fp0
  double v44; // fp0
  int v45; // r10
  double v46; // fp31
  double v47; // fp30
  __int64 v48; // r5
  idRenderModelGui *v49; // r30
  int i; // r30
  double v51; // fp1
  __int64 v52; // r28
  idStrBuffer<48> *rangeLabel; // r30
  int v54; // r11
  const idVec4 *v55; // r5
  int v56; // [sp+8h] [-12A8h]
  int v57; // [sp+Ch] [-12A4h]
  int v58; // [sp+10h] [-12A0h]
  int v59; // [sp+14h] [-129Ch]
  int v60; // [sp+18h] [-1298h]
  int v61; // [sp+1Ch] [-1294h]
  double v62; // [sp+20h] [-1290h]
  _DWORD v63[41]; // [sp+BCh] [-11F4h] BYREF
  idStr v64; // [sp+160h] [-1150h] BYREF
  va v65; // [sp+180h] [-1130h] BYREF

  v63[1] = "main";
  v63[2] = "render";
  v63[3] = "GPU";
  v63[10] = -2112031516;
  v63[11] = -2112031540;
  v63[12] = -2112031480;
  v63[16] = "JPU  0";
  v63[17] = "JPU  1";
  v63[18] = "JPU  2";
  v63[9] = -2112031528;
  v63[15] = "stream OD";
  v63[7] = -2112031492;
  v63[8] = -2112031504;
  v63[4] = "jbl coll";
  v63[5] = -2112031552;
  v63[6] = -2112031564;
  v63[13] = -2112031608;
  v1 = (const idVec4 *)-2112031824;
  v63[14] = -2112031620;
  v63[19] = "JPU  3";
  v63[20] = "JPU  4";
  v63[21] = "JPU  5";
  v63[30] = "JPU 14";
  HIDWORD(v2) = 0x82000000;
  v63[31] = "JPU 15";
  v63[32] = "JPU 16";
  v63[33] = "JPU 17";
  v63[24] = "JPU  8";
  v63[38] = -2112031816;
  v3 = "JPU  6";
  v63[29] = "JPU 13";
  v63[25] = "JPU  9";
  v63[26] = "JPU 10";
  v63[35] = "JPU 19";
  v4 = v63;
  v6 = 0;
  v63[22] = "JPU  6";
  v63[23] = "JPU  7";
  v63[27] = "JPU 11";
  v63[28] = "JPU 12";
  v63[34] = "JPU 18";
  v63[36] = "JPU 20";
  v63[37] = "JPU 21";
  v63[39] = -2112031824;
  do
  {
    LODWORD(v2) = v6;
    idRenderModelGui::DrawString(
      this: this->gui,
      x: 68.0,
      y: (float)(unsigned int)(int)(float)((float)((float)((float)(SMALLCHAR_WIDTH + (float)8.0) * (float)v2) + (float)70.0)
                                      - (float)4.0),
      string: v3,
      defaultColor: v1,
      forceColor: *++v4,
      scale: 1.0);
    ++v6;
  }
  while ( v6 < 39 );
  if ( com_drawThreadSpeeds.valueInteger != 2 )
  {
    lastVblMicroseconds = this->lastVblMicroseconds;
    if ( (_DWORD)lastVblMicroseconds != 0 )
    {
      *(unsigned __int64 *)((char *)&lastVblMicroseconds + 4) = this->vblIntervalMicroseconds;
      LODWORD(lastVblMicroseconds) = HIDWORD(lastVblMicroseconds) + lastVblMicroseconds;
      this->rangeSyncTime = lastVblMicroseconds;
    }
    else
    {
      LODWORD(v8) = Sys_Microseconds() >> 32;
      this->rangeSyncTime = v8;
    }
  }
  v9 = (_cntlzw(com_drawThreadSpeeds.valueInteger - 2) & 0x20) != 0;
  v11 = ((__int64 (__fastcall *)(idRenderSystem *))renderSystem->GetWidth)(a1: renderSystem);
  v10 = HIDWORD(v11);
  currentRange = this->currentRange;
  HIDWORD(v13) = byte_821B0000;
  v14 = currentRange - 512;
  v15 = 0.001;
  v16 = (float)(com_threadSpeedScale.valueFloat * (float)0.001);
  v17 = (float)((float)*(__int64 *)((char *)&v11 - 4) * (float)0.69999999);
  LODWORD(v11) = &localConsole.text.ptr[2048];
  if ( currentRange - 512 < currentRange )
  {
    do
    {
      *(__int64 *)((char *)&v13 + 4) = this->rangeSyncTime;
      v18 = (char *)this + 8 * (v14 & 0x1FF) + 8 * ((4 * v14) & 0x7FC);
      v19 = v18 + 150984;
      *((_QWORD *)&v20 + 1) = *((_QWORD *)v18 + 18876);
      *(_QWORD *)((char *)&v20 + 4) = *((_QWORD *)v18 + 18877);
      LODWORD(v11) = LODWORD(this->rangeSyncTime) - v20;
      HIDWORD(v11) = LODWORD(this->rangeSyncTime) - DWORD2(v20);
      v21 = (float)-(float)((float)((float)*(__int64 *)((char *)&v11 + 4) * (float)v16) - (float)v17);
      v22 = (float)-(float)((float)((float)v11 * (float)v16) - (float)v17);
      if ( (float)((float)-(float)((float)((float)*(__int64 *)((char *)&v11 + 4) * (float)v16) - (float)v17)
                 - (float)-(float)((float)((float)v11 * (float)v16) - (float)v17)) < 1.0 )
        v21 = (float)((float)1.0 - (float)((float)((float)v11 * (float)v16) - (float)v17));
      if ( v22 >= 148.0 || (v22 = 148.0, v21 > 148.0) )
      {
        LODWORD(v13) = *v19;
        v23 = (float)((float)v21 - (float)v22);
        v24 = (float)((float)((float)(SMALLCHAR_WIDTH + (float)8.0) * (float)v13) + (float)70.0);
        idRenderModelGui::DrawFilled(
          this: this->gui,
          color: (const idVec4 *)(v18 + 150988),
          x: v22,
          y: (float)((float)((float)((float)(SMALLCHAR_WIDTH + (float)8.0) * (float)v13) + (float)70.0) - (float)2.0),
          w: v23,
          h: (float)(SMALLCHAR_WIDTH + (float)5.0));
        HIDWORD(v13) = v9;
        if ( v9 )
        {
          v62 = (float)((float)_u64tod(a1: v19[9] - v19[7], a2: v11) * (float)v15);
          *(double *)((char *)&v25 + 4) = v62;
          v28 = va::va(
                  this: &v65,
                  fmt: (const char *)HIDWORD(v62),
                  a3: v25,
                  a4: v27,
                  a5: v26,
                  a6: v56,
                  a7: v57,
                  a8: v58,
                  a9: v59,
                  a10: v60,
                  a11: v61);
          idStr::idStr(this: &v64, text: v28);
          v29 = 0;
          HIDWORD(v30) = (unsigned __int8)*v64.data;
          v31 = SBYTE3(v30);
          if ( BYTE3(v30) != 0 )
          {
            do
              HIDWORD(v30) = (unsigned __int8)v64.data[++v29];
            while ( v64.data[v29] != 0 );
          }
          LODWORD(v30) = v29;
          v32 = v29;
          v33 = (float)((float)((float)v30 - (float)0.5) * SMALLCHAR_WIDTH);
          if ( v31 == 48 )
          {
            v33 = (float)(SMALLCHAR_WIDTH * (float)1.5);
            idStr::StripLeadingOnce(this: &v64, string: "0");
            v32 = v29 - 1;
          }
          if ( v33 < v23 )
          {
            gui = this->gui;
            v35 = (int)(float)((float)((float)((float)v23 - (float)v33) * (float)0.5) + (float)v22);
            gui->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&idColor::colorBlack);
            v40 = 0;
            if ( v32 - 2 <= 0 )
            {
              v43 = SMALLCHAR_WIDTH;
            }
            else
            {
              LODWORD(v36) = (int)(float)((float)v24 - (float)4.0);
              v41 = (float)v36;
              do
              {
                v42 = (float)__SPAIR64__((unsigned int)v64.data, v35);
                idRenderModelGui::DrawChar(this: this->gui, x: v42, y: v41, character: v39, scale: 1.0);
                v43 = SMALLCHAR_WIDTH;
                ++v40;
                v35 = (int)(float)((float)v42 + SMALLCHAR_WIDTH);
              }
              while ( v40 < v32 - 2 );
            }
            if ( *v64.data == 46 )
              v44 = (float)((float)v43 * (float)0.125);
            else
              v44 = (float)((float)v43 * (float)0.375);
            v45 = (int)(float)((float)v24 - (float)4.0);
            v46 = (float)*(__int64 *)(&v37 - 1);
            LODWORD(v38) = (int)(float)((float)__SPAIR64__(v45, v35) - (float)v44);
            v47 = (float)v38;
            idRenderModelGui::DrawChar(this: this->gui, x: v47, y: v46, character: v39, scale: 1.0);
            HIDWORD(v48) = (unsigned __int8)v64.data[v32 - 1];
            LODWORD(v48) = (int)(float)((float)(SMALLCHAR_WIDTH * (float)0.625) + (float)v47);
            idRenderModelGui::DrawChar(this: this->gui, x: (float)v48, y: v46, character: SHIDWORD(v48), scale: 1.0);
            v49 = this->gui;
            v49->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&idColor::colorWhite);
          }
          idStr::FreeData(this: &v64);
          v15 = (float)0.001;
        }
      }
      ++v14;
    }
    while ( v14 < this->currentRange );
  }
  if ( LODWORD(this->lastVblMicroseconds) != 0 )
  {
    for ( i = 0; i < 10; ++i )
    {
      v51 = (float)-(float)((float)((float)_u64tod(a1: i * LODWORD(this->vblIntervalMicroseconds), a2: v11) * (float)v16)
                          - (float)v17);
      if ( v51 < 148.0 )
        break;
      idRenderModelGui::DrawFilled(
        this: this->gui,
        color: (const idVec4 *)&idColor::colorDkGrey,
        x: v51,
        y: (float)((float)((float)((float)(SMALLCHAR_WIDTH + (float)8.0) * (float)0.0) + (float)70.0) - (float)4.0),
        w: 3.0,
        h: (float)((float)(SMALLCHAR_WIDTH + (float)8.0) * (float)3.0));
    }
  }
  LODWORD(v52) = 0;
  rangeLabel = this->rangeLabel;
  do
  {
    v54 = 0;
    if ( rangeLabel->buf[0] != 0 )
    {
      do
        ++v54;
      while ( rangeLabel->buf[v54] != 0 );
      if ( v54 != 0 )
      {
        LODWORD(v13) = (int)(float)((float)v17 + (float)8.0);
        HIDWORD(v52) = v13;
        v55 = (const idVec4 *)(int)(float)((float)((float)((float)(SMALLCHAR_WIDTH + (float)8.0) * (float)v52)
                                                 + (float)70.0)
                                         - (float)4.0);
        idRenderModelGui::DrawString(
          this: this->gui,
          x: (float)v13,
          y: (float)*(__int64 *)((char *)&v11 - 4),
          string: (const char *)v11,
          defaultColor: v55,
          forceColor: (bool)rangeLabel,
          scale: 1.0);
      }
    }
    LODWORD(v52) = v52 + 1;
    ++rangeLabel;
  }
  while ( (int)v52 < 39 );
}


// ========================================================================
// __unwind$232376
// EA  : 0x82669150
// RVA : 0x00669150
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_232376()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4784 + 352));
}


// ========================================================================
// ?ClearPresentables@idConsoleLocal@@UAAXXZ
// EA  : 0x82669178
// RVA : 0x00669178
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::ClearPresentables(idConsoleLocal *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->presentableObjects);
}


// ========================================================================
// ?DrawPresentables@idConsoleLocal@@AAAXXZ
// EA  : 0x82669190
// RVA : 0x00669190
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::DrawPresentables(idConsoleLocal *this, int a2, int a3, int a4, __int64 a5)
{
  int *p_maxPresentableObjectString; // r26
  int maxPresentableObjectString; // r11
  idRenderModelGui *gui; // r3
  int v9; // r6
  const idVec4 *v10; // r5
  const char *v11; // r4
  const idVec4 *v12; // r5
  const char *v13; // r4
  const idVec4 *v14; // r5
  const char *v15; // r4
  __int64 v16; // r10
  int v17; // r25
  double v18; // fp29
  int v19; // r27
  __int64 v20; // r8
  __int64 v21; // r10
  presentableObject_t *list; // r11
  presentableObject_t *v23; // r11
  __int64 v24; // r6
  va *v25; // r3
  int StringWidth; // r3
  __int64 v27; // r11
  int v28; // r29
  const idVec4 *v29; // r5
  int v30; // r11
  int v31; // [sp+8h] [-1118h]
  int v32; // [sp+Ch] [-1114h]
  int v33; // [sp+10h] [-1110h]
  int v34; // [sp+14h] [-110Ch]
  int v35; // [sp+18h] [-1108h]
  int v36; // [sp+1Ch] [-1104h]
  idVec4 v37; // [sp+60h] [-10C0h] BYREF
  idStr v38; // [sp+70h] [-10B0h] BYREF
  idColor v39; // [sp+90h] [-1090h] BYREF
  va v40; // [sp+A0h] [-1080h] BYREF

  p_maxPresentableObjectString = &this->maxPresentableObjectString;
  maxPresentableObjectString = this->maxPresentableObjectString;
  if ( maxPresentableObjectString <= 400 )
    maxPresentableObjectString = 400;
  gui = this->gui;
  LODWORD(a5) = maxPresentableObjectString + 20;
  v9 = this->presentableObjects.num + 6;
  v37.w = 0.69999999;
  v37.x = 1.0;
  v37.y = 1.0;
  v37.z = 1.0;
  idRenderModelGui::DrawFilled(
    this: gui,
    color: &v37,
    x: 338.0,
    y: 140.0,
    w: (float)a5,
    h: (float)((float)((float)__SPAIR64__(&unk_821D0000, v9) * (float)15.0) + (float)20.0));
  idRenderModelGui::DrawString(
    this: this->gui,
    x: 348.0,
    y: 150.0,
    string: v11,
    defaultColor: v10,
    forceColor: (bool)"** Presentables **",
    scale: 1.0);
  idRenderModelGui::DrawString(
    this: this->gui,
    x: 348.0,
    y: 165.0,
    string: (const char *)&unk_821D0000,
    defaultColor: (const idVec4 *)&unk_821D0000,
    forceColor: (bool)"Index | SkipRep | Debug Name ",
    scale: 1.0);
  idRenderModelGui::DrawString(
    this: this->gui,
    x: 348.0,
    y: 180.0,
    string: v13,
    defaultColor: v12,
    forceColor: (bool)"--------------------------------------------------",
    scale: 1.0);
  HIDWORD(v16) = &unk_821D0000;
  v17 = 0;
  v18 = 195.0;
  if ( this->presentableObjects.num > 0 )
  {
    v19 = 0;
    do
    {
      LODWORD(v20) = LODWORD(idColor::colorGreen.r);
      HIDWORD(v21) = &v39;
      LODWORD(v21) = &idColor::colorGreen;
      list = this->presentableObjects.list;
      v39 = idColor::colorGreen;
      v23 = &list[v19];
      HIDWORD(v24) = v23->presentableIndex;
      HIDWORD(v20) = v23->name;
      LODWORD(v24) = v23->skipReplication;
      v25 = va::va(
              this: &v40,
              fmt: "%5i     %5i   %s",
              a3: v24,
              a4: v20,
              a5: v21,
              a6: v31,
              a7: v32,
              a8: v33,
              a9: v34,
              a10: v35,
              a11: v36);
      idStr::idStr(this: &v38, text: v25);
      StringWidth = idRenderModelGui::GetStringWidth(this: this->gui, string: v38.data, scale: 1.0);
      LODWORD(v27) = (int)v18;
      v28 = StringWidth;
      idRenderModelGui::DrawString(
        this: this->gui,
        x: 348.0,
        y: (float)v27,
        string: (const char *)(int)v18,
        defaultColor: v29,
        forceColor: (bool)v38.data,
        scale: 1.0);
      v30 = *p_maxPresentableObjectString;
      if ( v28 > *p_maxPresentableObjectString )
        v30 = v28;
      *p_maxPresentableObjectString = v30;
      v18 = (float)((float)v18 + (float)15.0);
      idStr::FreeData(this: &v38);
      ++v17;
      ++v19;
    }
    while ( v17 < this->presentableObjects.num );
  }
  LODWORD(v16) = (int)v18;
  idRenderModelGui::DrawString(
    this: this->gui,
    x: 348.0,
    y: (float)v16,
    string: v15,
    defaultColor: v14,
    forceColor: (bool)"--------------------------------------------------",
    scale: 1.0);
}


// ========================================================================
// __unwind$232553
// EA  : 0x82669430
// RVA : 0x00669430
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_232553()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4384 + 112));
}


// ========================================================================
// ?conDump_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826697E0
// RVA : 0x006697E0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall conDump_f(const idCmdArgs *args)
{
  char *data; // r30
  idFile *v2; // r26
  int v3; // r6
  signed int v4; // r28
  int v5; // r9
  int v6; // r11
  __int16 *v7; // r10
  __int16 v8; // r9
  int v9; // r10
  int v10; // r30
  _WORD *v11; // r29
  unsigned int v12; // r11
  _WORD *i; // r10
  int v14; // r5
  _BYTE *v15; // r11
  const char *v16; // r3
  idStr v17; // [sp+60h] [-470h] BYREF
  _BYTE v18[1104]; // [sp+80h] [-450h] BYREF

  if ( args->argc == 2 )
  {
    idStr::idStr(this: &v17, text: args->argv[1]);
    idStr::DefaultFileExtension(this: &v17, extension: ".txt");
    data = v17.data;
    if ( v17.data != nullptr )
    {
      v2 = fileSystem->OpenFileWrite(this: fileSystem, a2: v17.data, a3: 2);
      if ( v2 != nullptr )
      {
        v4 = (((unsigned int)(localConsole.currentLine - 4095) >> 31) - 1) & (localConsole.currentLine - 4095);
        if ( v4 <= localConsole.currentLine )
        {
          v5 = (4 * v4) & 0x3FFC;
          while ( 1 )
          {
            v6 = 0;
            v7 = *(__int16 **)((char *)localConsole.lines.ptr + v5);
            v8 = *v7;
            if ( *v7 != 0 )
            {
              do
              {
                if ( (unsigned __int8)v8 > 0x20u )
                  break;
                LOBYTE(v8) = v7[++v6];
              }
              while ( v7[v6] != 0 );
            }
            if ( v7[v6] != 0 )
              break;
            ++v4;
            v5 = (4 * v4) & 0x3FFC;
            if ( v4 > localConsole.currentLine )
              goto LABEL_25;
          }
          if ( v4 <= localConsole.currentLine )
          {
            v9 = (4 * v4) & 0x3FFC;
            do
            {
              v10 = 0;
              v11 = *(__int16 **)((char *)localConsole.lines.ptr + v9);
              if ( *v11 != 0 )
              {
                do
                {
                  v12 = 0;
                  for ( i = &v11[v10]; *i != 0; v3 = (unsigned __int16)*i )
                  {
                    if ( v12 >= 0x3FF )
                      break;
                    v18[v12++] = *i++;
                  }
                  v10 += v12;
                  v14 = 0;
                  v18[v12] = 0;
                  if ( v18[0] != 0 )
                  {
                    v15 = v18;
                    do
                    {
                      ++v15;
                      ++v14;
                    }
                    while ( *v15 != 0 );
                  }
                  ((void (__fastcall *)(idFile *, _BYTE *, int, int))v2->Write)(a1: v2, a2: v18, a3: v14, a4: v3);
                }
                while ( v11[v10] != 0 );
              }
              v2->Write(this: v2, a2: "\r\n", a3: 2u);
              ++v4;
              v9 = (4 * v4) & 0x3FFC;
            }
            while ( v4 <= localConsole.currentLine );
          }
        }
LABEL_25:
        v16 = v2->GetFullPath(this: v2);
        idLib::Printf(fmt: "Dumped console text to %s.\n", v16);
        ((void (__fastcall *)(idFile *, int))v2->dtr_idFile)(a1: v2, a2: 1);
      }
      else
      {
        idLib::Warning(fmt: "couldn't open %s", data);
      }
    }
    idStr::FreeData(this: &v17);
  }
  else
  {
    idLib::Printf(fmt: "usage: conDump <filename>\n");
  }
}


// ========================================================================
// __unwind$233017
// EA  : 0x82669A78
// RVA : 0x00669A78
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_233017()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1232 + 96));
}


// ========================================================================
// ?reportThreadSpeedLogs_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82669AA8
// RVA : 0x00669AA8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall reportThreadSpeedLogs_f(const idCmdArgs *args)
{
  unsigned int v1; // r11
  int num; // ctr
  unsigned __int8 *list; // r6
  int i; // r29
  int j; // r27
  unsigned __int8 *v6; // r9
  unsigned int v7; // r11
  unsigned __int8 *v8; // r28
  int k; // ctr
  int v10; // r29
  unsigned int v11; // r18
  int v12; // r10
  int v13; // r5
  unsigned int v14; // r10
  double v15; // r6
  __int64 v16; // r7
  int m; // r29
  __int64 v18; // [sp+50h] [-170h] BYREF
  idFileLocal v19; // [sp+58h] [-168h] BYREF
  idStr v20; // [sp+60h] [-160h] BYREF
  __int64 v21; // [sp+80h] [-140h]
  idStr v22; // [sp+90h] [-130h] BYREF
  idStr v23; // [sp+B0h] [-110h] BYREF
  unsigned __int64 v24; // [sp+D0h] [-F0h]
  __int64 v25; // [sp+D8h] [-E8h]
  idStr v26; // [sp+E0h] [-E0h] BYREF
  _BYTE v27[56]; // [sp+100h] [-C0h] BYREF

  idLib::Printf(fmt: "Writing %s\n", "threadSpeedLog.txt");
  v19.file = fileSystem->OpenFileWrite(this: fileSystem, a2: "threadSpeedLog.txt", a3: 0);
  memset(v27, 0, 42);
  v1 = 0;
  if ( localConsole.timeLog.num > 0 )
  {
    num = localConsole.timeLog.num;
    list = localConsole.timeLog.list;
    do
    {
      if ( list[v1] != 0 )
        v27[v1 % 0x2A] = 1;
      ++v1;
      --num;
    }
    while ( num != 0 );
  }
  idStr::idStr(this: &v26, text: "frame\t0-total\t1-total");
  for ( i = 0; i < 42; ++i )
  {
    if ( v27[i] != 0 )
    {
      v22.allocedAndFlag = 20;
      v22.len = 0;
      v22.data = v22.baseBuffer;
      v22.baseBuffer[0] = 0;
      idStr::Format(this: &v22, fmt: "\t%i-%s", i / 0xEu, logColors[i % 0xEu].name);
      idStr::Append(this: &v26, text: &v22);
      idStr::FreeData(this: &v22);
    }
  }
  idStr::Append(this: &v26, text: "\n");
  if ( v19.file != nullptr )
    v19.file->Printf(this: v19.file, a2: v26.data);
  idLib::Printf(fmt: v26.data);
  v20.allocedAndFlag = 20;
  v20.len = 0;
  v20.data = v20.baseBuffer;
  v20.baseBuffer[0] = 0;
  for ( j = 0; j < localConsole.timeLog.num; j += 42 )
  {
    v6 = &localConsole.timeLog.list[j];
    v8 = &localConsole.timeLog.list[j + 3];
    v7 = 0;
    v18 = 0;
    for ( k = 7; k != 0; --k )
    {
      v10 = v8[v7];
      v11 = (v7 + 2) / 0xE;
      v12 = v6[v7 + 1];
      *((_DWORD *)&v18 + v7 / 0xE) += v6[v7];
      *((_DWORD *)&v18 + (v7 + 1) / 0xE) += v12;
      v13 = v6[v7 + 2];
      v14 = 4 * ((v7 + 3) / 0xE);
      v7 += 4;
      *((_DWORD *)&v18 + v11) += v13;
      *(_DWORD *)((char *)&v18 + v14) += v10;
    }
    v24 = __PAIR64__(&v18, HIDWORD(v18));
    v25 = v18;
    v15 = (float)((float)__SPAIR64__(&v18, HIDWORD(v18)) * (float)0.19607843);
    idStr::Format(
      this: &v20,
      fmt: "%i\t%4.1f\t%4.1f",
      HIDWORD(v15),
      LODWORD(v15),
      (unsigned int)COERCE_UNSIGNED_INT64((float)((float)v18 * (float)0.19607843)));
    for ( m = 0; m < 42; ++m )
    {
      if ( v27[m] != 0 )
      {
        LODWORD(v16) = localConsole.timeLog.list[m + j];
        v23.allocedAndFlag = 20;
        v23.data = v23.baseBuffer;
        v23.len = 0;
        v23.baseBuffer[0] = 0;
        v21 = v16;
        idStr::Format(this: &v23, fmt: "\t%4.1f", (float)((float)v16 * (float)0.19607843));
        idStr::Append(this: &v20, text: &v23);
        idStr::FreeData(this: &v23);
      }
    }
    idStr::Append(this: &v20, text: "\n");
    if ( v19.file != nullptr )
      v19.file->Printf(this: v19.file, a2: v20.data);
    idLib::Printf(fmt: v20.data);
  }
  idStr::FreeData(this: &v20);
  idStr::FreeData(this: &v26);
  idFileLocal::~idFileLocal(this: &v19);
}


// ========================================================================
// __unwind$233153
// EA  : 0x82669EA0
// RVA : 0x00669EA0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_233153()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 448 + 88));
}


// ========================================================================
// __unwind$233154
// EA  : 0x82669EC8
// RVA : 0x00669EC8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_233154()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 224));
}


// ========================================================================
// __unwind$233155
// EA  : 0x82669EF0
// RVA : 0x00669EF0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_233155()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 144));
}


// ========================================================================
// __unwind$233156
// EA  : 0x82669F18
// RVA : 0x00669F18
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_233156()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 96));
}


// ========================================================================
// __unwind$233157
// EA  : 0x82669F40
// RVA : 0x00669F40
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_233157()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 176));
}


// ========================================================================
// ?AddConsoleWatchText@@YAXPBD@Z
// EA  : 0x8266A328
// RVA : 0x0066A328
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall AddConsoleWatchText(char *txt)
{
  if ( txt != nullptr )
  {
    if ( (_S13_2 & 1) == 0 )
    {
      _S13_2 |= 1u;
      str.allocedAndFlag = 20;
      str.data = str.baseBuffer;
      str.len = 0;
      str.baseBuffer[0] = 0;
      atexit(func: (void (__fastcall *)())_AddConsoleWatchText_::_5_::_dynamic_atexit_destructor_for__str__);
    }
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idStr::Append(this: &str, text: txt);
    if ( idStr::Find(str: str.data, c: 10, start: 0, end: str.len) != -1 )
    {
      idStr::StripTrailingWhitespace(this: &str);
      idList<idStr,5>::Append(this: &cwatchResultTextList, obj: &str);
      idStr::Clear(this: &str);
    }
    idMem::PopHeap(this: &mem);
  }
}


// ========================================================================
// ?Print@idConsoleLocal@@UAAXPBD@Z
// EA  : 0x8266A400
// RVA : 0x0066A400
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::Print(idConsoleLocal *this, char *txt)
{
  char *v3; // r21
  int v4; // r3
  int *p_currentLine; // r26
  int v6; // r15
  int currentLine; // r11
  __int16 v8; // r19
  idArray<short,65537> *p_text; // r29
  char v10; // r11
  int i; // r24
  char v12; // r11
  int v13; // r11
  int *p_textOffset; // r28
  int lineOffset; // r6
  int *p_lineOffset; // r31
  idConsoleLocal *v17; // r3
  int v18; // r4
  int v19; // r6
  int v20; // r9
  int displayLine; // r10
  int v22; // r11
  int v23; // r11
  bool v24; // zf

  v3 = txt;
  idWarningCollector::AddText(this: &this->warningCollector, textIn: txt);
  if ( printConsoleWatchText )
  {
    AddConsoleWatchText(txt: v3);
  }
  else
  {
    v4 = Sys_Milliseconds();
    p_currentLine = &this->currentLine;
    v6 = v4;
    currentLine = this->currentLine;
    v8 = 7;
    p_text = (idArray<short,65537> *)this->lines.ptr[currentLine & 0xFFF];
    if ( currentLine >= 0 )
      this->times.ptr[currentLine % 4] = v4;
    v10 = *v3;
    for ( i = (unsigned __int8)*v3; *v3 != 0; i = (unsigned __int8)*v3 )
    {
      if ( v10 != 94 || v3[1] == 0 || (v12 = 1, v3[1] == 32) )
        v12 = 0;
      if ( v12 != 0 )
      {
        v8 = 7;
        v13 = v3[1];
        if ( v13 != 48 )
          v8 = v13 & 0xF;
        v3 += 2;
      }
      else
      {
        p_textOffset = &this->textOffset;
        lineOffset = this->lineOffset;
        p_lineOffset = &this->lineOffset;
        ++v3;
        if ( lineOffset + this->textOffset >= 65531 )
        {
          idConsoleLocal::ClearOldLines(
            this,
            currentLine: *p_currentLine,
            startOffset: ((char *)p_text - (char *)this - 1056) >> 1,
            endOffset: lineOffset);
          idConsoleLocal::ClearOldLines(
            this: v17,
            currentLine: *p_currentLine,
            startOffset: 0,
            endOffset: *p_lineOffset);
          memcpy(Dst: &this->text, Src: p_text, Size: 2 * *p_lineOffset);
          p_text = &this->text;
          this->lines.ptr[*p_currentLine & 0xFFF] = this->text.ptr;
          *p_textOffset = 0;
        }
        switch ( i )
        {
          case 9:
            v22 = *p_lineOffset;
            do
            {
              p_text->ptr[v22] = (v8 << 8) | 0x20;
              v23 = *p_lineOffset + 1;
              *p_lineOffset = v23;
              v24 = (v23 & 3) != 0;
              v22 = v23;
            }
            while ( v24 );
            break;
          case 10:
            p_text->ptr[*p_lineOffset] = 0;
            v18 = *p_currentLine;
            v19 = *p_lineOffset + *p_textOffset + 1;
            *p_textOffset = v19;
            idConsoleLocal::ClearOldLines(
              this,
              currentLine: v18,
              startOffset: ((char *)p_text - (char *)this - 1056) >> 1,
              endOffset: v19);
            v20 = *p_currentLine;
            displayLine = this->displayLine;
            *p_lineOffset = 0;
            if ( displayLine == v20 )
              this->displayLine = displayLine + 1;
            *p_currentLine = v20 + 1;
            if ( v20 + 1 >= 0 )
              this->times.ptr[(v20 + 1) % 4] = v6;
            this->lines.ptr[*p_currentLine & 0xFFF] = &this->text.ptr[*p_textOffset];
            p_text = (idArray<short,65537> *)this->lines.ptr[*p_currentLine & 0xFFF];
            p_text->ptr[*p_lineOffset] = 0;
            break;
          case 13:
            if ( *v3 != 10 )
              *p_lineOffset = 0;
            break;
          default:
            p_text->ptr[(*p_lineOffset)++] = (v8 << 8) | i;
            break;
        }
      }
      v10 = *v3;
    }
    p_text->ptr[this->lineOffset] = 0;
    if ( *p_currentLine >= 0 )
      this->times.ptr[*p_currentLine % 4] = v6;
  }
}


// ========================================================================
// ?LogThreadSpeeds@idConsoleLocal@@AAAXXZ
// EA  : 0x8266A740
// RVA : 0x0066A740
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::LogThreadSpeeds(idConsoleLocal *this)
{
  rangeId_t v2; // r27
  const idColor *v3; // r28
  int *p_currentRange; // r24
  timeRange_t *ranges; // r23
  idList<unsigned char,5> *p_timeLog; // r26
  logRanges_t *LogRanges; // r3
  _BYTE *v8; // r31
  int i; // r30
  int v10; // r11
  unsigned __int8 v11[16]; // [sp+50h] [-160h] BYREF
  _BYTE v12[128]; // [sp+60h] [-150h] BYREF
  logRanges_t v13; // [sp+E0h] [-D0h] BYREF

  v2 = RANGE_MAIN;
  if ( this->timeLog.num == 0 )
  {
    this->timeLogFirstFrame = 0;
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    if ( this->timeLog.size < 756000 )
      idList<unsigned char,25>::Resize(this: (idList<unsigned char,37> *)&this->timeLog, newsize: 756000);
    idMem::PopHeap(this: &mem);
  }
  if ( (_S14_0 & 1) == 0 )
  {
    _S14_0 |= 1u;
    rangeDelimeters[0] = idColor::colorWhite;
    rangeDelimeters[1] = idColor::colorOrange;
    rangeDelimeters[2] = idColor::colorGreen;
  }
  v3 = rangeDelimeters;
  p_currentRange = &this->currentRange;
  ranges = this->ranges;
  p_timeLog = &this->timeLog;
  do
  {
    LogRanges = FindLogRanges(
                  result: &v13,
                  ranges,
                  MAX_RANGES: 512,
                  currentRange: *p_currentRange,
                  rangeId: v2,
                  delimeter: v3);
    memcpy(Dst: v12, Src: LogRanges, Size: 0x78u);
    v8 = &v12[8];
    for ( i = 14; i != 0; --i )
    {
      v10 = 255 * *((_DWORD *)v8 + 1) / 50000;
      if ( v10 > 255 )
        LOBYTE(v10) = -1;
      v11[0] = v10;
      idList<unsigned char,25>::Append(this: (idList<unsigned char,37> *)p_timeLog, obj: v11);
      v8 += 8;
    }
    ++v3;
    ++v2;
  }
  while ( (int)v3 <= (int)&rangeDelimeters[2] );
}


// ========================================================================
// ?CreateGraph@idConsoleLocal@@UAAPAVidDebugGraph@@H@Z
// EA  : 0x8266A8F8
// RVA : 0x0066A8F8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

idDebugGraph *__fastcall idConsoleLocal::CreateGraph(idConsoleLocal *this, int numItems)
{
  idDebugGraph *v4; // r3
  idDebugGraph *v5; // r29
  idDebugGraph *v7; // [sp+50h] [-30h] BYREF

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v4 = (idDebugGraph *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x98u,
                         tag: TAG_DEBUG,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v7 = v4;
  if ( v4 != nullptr )
    v5 = idDebugGraph::idDebugGraph(this: v4, numItems);
  else
    v5 = nullptr;
  v7 = v5;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->debugGraphs,
    obj: (const encounterGroupRole_t *)&v7);
  idMem::PopHeap(this: &mem);
  return v5;
}


// ========================================================================
// __unwind$233926
// EA  : 0x8266A990
// RVA : 0x0066A990
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_233926()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_DEBUG);
}


// ========================================================================
// ?DrawSnapshots@idConsoleLocal@@AAAXXZ
// EA  : 0x8266A9C8
// RVA : 0x0066A9C8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idConsoleLocal::DrawSnapshots(idConsoleLocal *this, int a2, int a3, int a4, int a5, __int64 a6)
{
  int *p_maxSnapObjectString; // r14
  int v7; // r19
  unsigned int v9; // r21
  int v10; // r24
  int maxSnapObjectString; // r11
  unsigned int v12; // r20
  int v13; // r23
  double v14; // fp24
  int v15; // r22
  int *p_num; // r17
  idRenderModelGui *gui; // r3
  __int64 v18; // r5
  int num; // r11
  const idVec4 *v20; // r5
  const char *v21; // r4
  const char *v22; // r6
  const idVec4 *v23; // r5
  const char *v24; // r4
  const char *v25; // r25
  const char *v26; // r4
  const idVec4 *v27; // r5
  const char *v28; // r4
  double v29; // fp29
  int v30; // r11
  bool v31; // cr57
  int v32; // r28
  int v33; // r30
  __int64 v34; // r10
  __int64 v35; // r8 OVERLAPPED
  int v36; // r27
  encounterGroupRole_t v37; // r30
  double v38; // fp0
  int v39; // r11
  double v40; // fp13
  int v41; // r9
  double v42; // fp12
  double v43; // fp11
  double v44; // fp8
  int v45; // r6
  double v46; // fp6
  int v47; // r8 OVERLAPPED
  __int64 v48; // r10
  __int128 v49; // r7 OVERLAPPED
  va *v50; // r3
  __int64 v51; // r6
  __int64 v52; // r10
  __int64 v53; // r8
  va *v54; // r3
  idColor *v55; // r11
  float g; // r8
  float b; // r7
  float a; // r6
  idColor *v59; // r11
  float v60; // r8
  float v61; // r7
  float v62; // r6
  int StringWidth; // r30
  __int64 v64; // r4
  double v65; // fp23
  int v66; // r28
  __int64 v67; // r11
  idRenderModelGui *v68; // r3
  const idVec4 *v69; // r5
  const char *v70; // r4
  int v71; // r11
  __int128 v72; // r8
  double v73; // fp3
  va *v74; // r3
  __int64 v75; // r4
  int v76; // [sp+8h] [-2408h]
  int v77; // [sp+8h] [-2408h]
  int v78; // [sp+Ch] [-2404h]
  int v79; // [sp+Ch] [-2404h]
  int v80; // [sp+10h] [-2400h]
  int v81; // [sp+10h] [-2400h]
  int v82; // [sp+14h] [-23FCh]
  int v83; // [sp+14h] [-23FCh]
  int v84; // [sp+18h] [-23F8h]
  int v85; // [sp+18h] [-23F8h]
  int v86; // [sp+1Ch] [-23F4h]
  int v87; // [sp+1Ch] [-23F4h]
  double v88; // [sp+48h] [-23C8h]
  __int64 v89; // [sp+68h] [-23A8h] BYREF
  idVec4 v90; // [sp+70h] [-23A0h] BYREF
  __int64 v91; // [sp+80h] [-2390h]
  __int64 v92; // [sp+88h] [-2388h]
  __int64 v93; // [sp+90h] [-2380h]
  _DWORD v94[4]; // [sp+A0h] [-2370h] BYREF
  idStr v95; // [sp+B0h] [-2360h] BYREF
  float r; // [sp+D0h] [-2340h]
  float v97; // [sp+D4h] [-233Ch]
  float v98; // [sp+D8h] [-2338h]
  float v99; // [sp+DCh] [-2334h]
  idStr v100; // [sp+E0h] [-2330h] BYREF
  idStr v101; // [sp+100h] [-2310h] BYREF
  idList<enum encounterGroupRole_t,5> v102; // [sp+120h] [-22F0h] BYREF
  int v103; // [sp+130h] [-22E0h] BYREF
  va v104; // [sp+330h] [-20E0h] BYREF
  va v105; // [sp+1330h] [-10E0h] BYREF

  p_maxSnapObjectString = &this->maxSnapObjectString;
  v7 = 0;
  v9 = 0;
  v10 = 0;
  maxSnapObjectString = this->maxSnapObjectString;
  v12 = 0;
  v13 = 0;
  v14 = 0.0;
  v15 = 0;
  if ( maxSnapObjectString <= 400 )
    maxSnapObjectString = 400;
  v90.x = 0.0;
  v90.y = 0.0;
  p_num = &this->snapObjects.num;
  v90.z = 0.0;
  LODWORD(a6) = maxSnapObjectString + 20;
  gui = this->gui;
  HIDWORD(v18) = &unk_821C0000;
  num = this->snapObjects.num;
  v90.w = 0.69999999;
  LODWORD(v18) = num + 6;
  idRenderModelGui::DrawFilled(
    this: gui,
    color: &v90,
    x: 338.0,
    y: 140.0,
    w: (float)a6,
    h: (float)((float)((float)v18 * (float)15.0) + (float)20.0));
  switch ( com_drawSnapshots.valueInteger )
  {
    case 1:
      v22 = "** Presentables **";
      break;
    case 2:
      v22 = "** Sounds **";
      break;
    case 3:
      v22 = "** All **";
      break;
    default:
      goto LABEL_10;
  }
  idRenderModelGui::DrawString(
    this: this->gui,
    x: 348.0,
    y: 150.0,
    string: v21,
    defaultColor: v20,
    forceColor: (bool)v22,
    scale: 1.0);
LABEL_10:
  idRenderModelGui::DrawString(
    this: this->gui,
    x: 348.0,
    y: 165.0,
    string: v21,
    defaultColor: v20,
    forceColor: (bool)"Bytes Changed |  Bytes | Presentables",
    scale: 1.0);
  idRenderModelGui::DrawString(
    this: this->gui,
    x: 348.0,
    y: 180.0,
    string: v24,
    defaultColor: v23,
    forceColor: (bool)"  Avg /   Max |  Total | Changed / Total",
    scale: 1.0);
  v25 = "--------------------------------------------------";
  idRenderModelGui::DrawString(
    this: this->gui,
    x: 348.0,
    y: 195.0,
    string: v26,
    defaultColor: (const idVec4 *)&unk_821D0000,
    forceColor: (bool)"--------------------------------------------------",
    scale: 1.0);
  v28 = (const char *)&unk_821D0000;
  v102.num = 0;
  v102.granularity = 1;
  v102.size = 128;
  v29 = 210.0;
  v102.memTag = 5;
  v102.list = (encounterGroupRole_t *)&v103;
  v102.listStatic = 1;
  v30 = *p_num;
  v31 = *p_num > 0;
  HIDWORD(v89) = *p_num;
  if ( v31 )
  {
    HIDWORD(v89) = v30;
    v32 = 0;
    v33 = 0;
    do
    {
      HIDWORD(v89) = &this->snapObjects.list[v33];
      idList<idAnimWebBlendTree *,5>::Append(this: &v102, obj: (const encounterGroupRole_t *)&v89);
      ++v32;
      ++v33;
    }
    while ( v32 < *p_num );
    qsort(
      base: v102.list,
      num: v102.num,
      width: 4u,
      comp: _idConsoleLocal::DrawSnapshots_::_18_::local_t::R_QsortSnapObjects);
  }
  HIDWORD(v34) = *p_num;
  HIDWORD(v35) = &off_82040000;
  if ( *p_num > 0 )
  {
    v36 = 0;
    do
    {
      v37 = v102.list[v36];
      v38 = *(float *)(v37 + 24);
      v39 = *(_DWORD *)(v37 + 12);
      v40 = *(float *)(v37 + 28);
      v41 = *(_DWORD *)(v37 + 4);
      v42 = *(float *)(v37 + 16);
      LODWORD(v35) = v39;
      v43 = (float)(*(float *)(v37 + 16) - *(float *)(v37 + 28));
      v89 = *(__int64 *)((char *)&v35 - 4);
      v91 = v35;
      v44 = (double)v35;
      v12 += v41;
      v45 = *(_DWORD *)(v37 + 20);
      v46 = (double)*(__int64 *)((char *)&v35 - 4);
      v47 = *(_DWORD *)(v37 + 36);
      v88 = (float)((float)((float)v43 * (float)0.2) + (float)v40);
      LODWORD(v48) = LODWORD(v88);
      *(float *)(v37 + 28) = (float)((float)v43 * (float)0.2) + (float)v40;
      HIDWORD(v48) = *(_DWORD *)(v37 + 32);
      v10 += v45;
      v13 += v47;
      v14 = (float)((float)v42 + (float)v14);
      v15 += HIDWORD(v48);
      v9 += v39;
      *(float *)(v37 + 24) = (float)((float)((float)v44 - (float)v38) * (float)0.2) + (float)v38;
      *((double *)&v49 + 1) = (float)((float)v46 * (float)0.0009765625);
      DWORD1(v49) = (int)(float)((float)((float)((float)((float)v44 - (float)v38) * (float)0.2) + (float)v38)
                               + (float)0.5);
      v50 = va::va(
              this: &v104,
              fmt: "%4i  / %4i  | %5.02fk |    %3ix / %3ix - %2.2f ms",
              a3: *(__int64 *)((char *)&v49 + 4),
              a4: *(__int64 *)&v47,
              a5: v48,
              a6: v76,
              a7: v78,
              a8: v80,
              a9: v82,
              a10: v84,
              a11: v86);
      idStr::idStr(this: &v100, text: v50);
      HIDWORD(v51) = *(_DWORD *)v37;
      v54 = va::va(
              this: &v105,
              fmt: " [%s]",
              a3: v51,
              a4: v53,
              a5: v52,
              a6: v77,
              a7: v79,
              a8: v81,
              a9: v83,
              a10: v85,
              a11: v87);
      idStr::idStr(this: &v95, text: v54);
      v55 = &idColor::colorRed;
      if ( *(int *)(v37 + 12) <= 10 )
        v55 = &idColor::colorGreen;
      g = v55->g;
      b = v55->b;
      a = v55->a;
      v94[0] = LODWORD(v55->r);
      v59 = &idColor::colorBlue;
      *(float *)&v94[1] = g;
      *(float *)&v94[2] = b;
      *(float *)&v94[3] = a;
      if ( *(_DWORD *)(v37 + 8) != -1 )
        v59 = (idColor *)v94;
      v60 = v59->g;
      v61 = v59->b;
      v62 = v59->a;
      r = v59->r;
      v97 = v60;
      v98 = v61;
      v99 = v62;
      StringWidth = idRenderModelGui::GetStringWidth(this: this->gui, string: v100.data, scale: 1.0);
      HIDWORD(v64) = idRenderModelGui::GetStringWidth(this: this->gui, string: v95.data, scale: 1.0);
      LODWORD(v64) = (int)v29;
      v92 = v64;
      v65 = (float)v64;
      v66 = HIDWORD(v64);
      idRenderModelGui::DrawString(
        this: this->gui,
        x: 348.0,
        y: v65,
        string: (const char *)(int)v29,
        defaultColor: (const idVec4 *)(int)v29,
        forceColor: (bool)v100.data,
        scale: 1.0);
      LODWORD(v67) = StringWidth;
      v68 = this->gui;
      v93 = v67;
      idRenderModelGui::DrawString(
        this: v68,
        x: (float)(unsigned int)(int)(float)((float)v67 + (float)348.0),
        y: v65,
        string: v70,
        defaultColor: v69,
        forceColor: (bool)v95.data,
        scale: 1.0);
      v71 = v66 + StringWidth;
      if ( v66 + StringWidth <= *p_maxSnapObjectString )
        v71 = *p_maxSnapObjectString;
      *p_maxSnapObjectString = v71;
      v29 = (float)((float)v29 + (float)15.0);
      idStr::FreeData(this: &v95);
      idStr::FreeData(this: &v100);
      ++v7;
      ++v36;
    }
    while ( v7 < *p_num );
    LOBYTE(v25) = (unsigned __int8)"--------------------------------------------------";
  }
  LODWORD(v34) = (int)v29;
  idRenderModelGui::DrawString(
    this: this->gui,
    x: 348.0,
    y: (float)v34,
    string: v28,
    defaultColor: v27,
    forceColor: (bool)v25,
    scale: 1.0);
  LODWORD(v72) = v9;
  v73 = (float)((float)((float)((float)(__int64)v72 - this->avgBytesChanged) * (float)0.2) + this->avgBytesChanged);
  this->avgBytesChanged = (float)((float)((float)(__int64)v72 - this->avgBytesChanged) * (float)0.2)
                        + this->avgBytesChanged;
  LODWORD(v72) = v13;
  *(double *)((char *)&v72 + 4) = (float)((float)__SPAIR64__(v9, v12) * (float)0.0009765625);
  HIDWORD(v72) = (int)(float)((float)v73 + (float)0.5);
  v74 = va::va(
          this: &v105,
          fmt: "%4i  / %4i  | %5.02fk |    %3ix / %3ix - %2.2f ms",
          a3: *(__int64 *)&v72,
          a4: v72,
          a5: *(__int64 *)&v14,
          a6: v76,
          a7: v78,
          a8: v80,
          a9: v82,
          a10: v84,
          a11: v86);
  HIDWORD(v75) = idStr::idStr(this: &v101, text: v74);
  LODWORD(v75) = (int)(float)((float)v29 + (float)15.0);
  idRenderModelGui::DrawString(
    this: this->gui,
    x: 348.0,
    y: (float)v75,
    string: (const char *)v75,
    defaultColor: (const idVec4 *)v75,
    forceColor: (bool)v101.data,
    scale: 1.0);
  idStr::FreeData(this: &v101);
  if ( (v102.listStatic == 0 || v102.listStatic == 2) && v102.list != nullptr )
    idMem::Free(this: &mem, ptr: v102.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$233960
// EA  : 0x8266B020
// RVA : 0x0066B020
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_233960()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 9232 + 288));
}


// ========================================================================
// __unwind$233961
// EA  : 0x8266B048
// RVA : 0x0066B048
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_233961()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9232 + 224));
}


// ========================================================================
// __unwind$233962
// EA  : 0x8266B070
// RVA : 0x0066B070
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_233962()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9232 + 176));
}


// ========================================================================
// __unwind$233963
// EA  : 0x8266B098
// RVA : 0x0066B098
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_233963()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9232 + 256));
}


// ========================================================================
// ?convertToSuperScript_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8266B0C8
// RVA : 0x0066B0C8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall convertToSuperScript_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v2; // r4
  int v3; // r29
  const char *v4; // r30
  char v5; // r28
  char v6; // r29
  char v7; // r30
  double v8; // fp30
  double v9; // fp31
  double v10; // fp1
  int v11; // r3
  char *data; // r4
  int i; // r30
  idFile *v14; // r30
  idFile_vtbl *v15; // r27
  char *filePtr; // r26
  unsigned int v17; // r3
  idFile *v18; // r30
  idFile_vtbl *v19; // r29
  char *v20; // r28
  unsigned int v21; // r3
  double FloatValue; // [sp+20h] [-830h]
  int v23; // [sp+50h] [-800h]
  idList<idStr,5> v24; // [sp+70h] [-7E0h] BYREF
  idToken v25; // [sp+80h] [-7D0h] BYREF
  const char *v26; // [sp+C8h] [-788h]
  idStr v27; // [sp+D0h] [-780h] BYREF
  const char *v28; // [sp+F0h] [-760h]
  const char *v29; // [sp+F4h] [-75Ch]
  const char *v30; // [sp+F8h] [-758h]
  const char *v31; // [sp+FCh] [-754h]
  const char *v32; // [sp+100h] [-750h]
  const char *v33; // [sp+104h] [-74Ch]
  const char *v34; // [sp+108h] [-748h]
  const char *v35; // [sp+10Ch] [-744h]
  const char *v36; // [sp+110h] [-740h]
  const char *v37; // [sp+114h] [-73Ch]
  const char *v38; // [sp+118h] [-738h]
  const char *v39; // [sp+11Ch] [-734h]
  const char *v40; // [sp+120h] [-730h]
  idStr v41; // [sp+130h] [-720h] BYREF
  idStr v42; // [sp+150h] [-700h] BYREF
  idStr v43; // [sp+170h] [-6E0h] BYREF
  idToken v44; // [sp+190h] [-6C0h] BYREF
  idToken v45; // [sp+1E0h] [-670h] BYREF
  idStr v46; // [sp+230h] [-620h] BYREF
  idStr v47; // [sp+250h] [-600h] BYREF
  idFile_Memory v48; // [sp+270h] [-5E0h] BYREF
  idParser v49; // [sp+3C0h] [-490h] BYREF
  idFile_Memory v50; // [sp+650h] [-200h] BYREF

  argc = args->argc;
  v26 = (const char *)args->argc;
  if ( v26 != (const char *)2 )
  {
    idLib::Printf(fmt: "USAGE: spConvertToSuperScriptawn <.script file name>\n");
    return;
  }
  v2 = &byte_8200D768;
  v35 = &byte_8200D768;
  if ( argc > 1 )
    v2 = args->argv[1];
  idStr::idStr(this: &v43, text: v2);
  idParser::idParser(this: &v49, flags: 0);
  idParser::SetFlags(this: &v49, flags: 0x80000);
  v25.len = 0;
  v25.allocedAndFlag = 20;
  v25.data = v25.baseBuffer;
  v25.floatvalue = -3.4028235e38;
  v25.baseBuffer[0] = 0;
  v25.intvalue = 0;
  memset(&v25.whiteSpaceStart_p, 0, 12);
  v44.floatvalue = -3.4028235e38;
  v44.allocedAndFlag = 20;
  v44.data = v44.baseBuffer;
  v44.len = 0;
  v44.baseBuffer[0] = 0;
  v44.intvalue = 0;
  memset(&v44.whiteSpaceStart_p, 0, 12);
  v45.floatvalue = -3.4028235e38;
  v45.allocedAndFlag = 20;
  v45.data = v45.baseBuffer;
  v45.len = 0;
  v45.baseBuffer[0] = 0;
  v45.intvalue = 0;
  memset(&v45.whiteSpaceStart_p, 0, 12);
  v42.allocedAndFlag = 20;
  v42.data = v42.baseBuffer;
  v42.len = 0;
  v42.baseBuffer[0] = 0;
  v41.allocedAndFlag = 20;
  v41.data = v41.baseBuffer;
  v41.len = 0;
  v41.baseBuffer[0] = 0;
  *(_WORD *)&v24.memTag = 1280;
  memset(&v24, 0, 14);
  v23 = 0;
  idFile_Memory::idFile_Memory(this: &v48);
  idFile_Memory::idFile_Memory(this: &v50);
  v27.allocedAndFlag = 20;
  v27.data = v27.baseBuffer;
  v27.len = 0;
  v27.baseBuffer[0] = 0;
  if ( !idParser::LoadFile(this: &v49, filename: v43.data, OSPath: true) )
    goto LABEL_82;
  if ( idParser::ReadToken(this: &v49, token: &v25) )
  {
    v26 = "waitFor( !entity( \"%s\" ).isMoving() )";
    v28 = "sys";
    v37 = "%ff";
    v33 = "vector( %ff, %ff, %ff )";
    v32 = "entity( \"%s\" ).activate( entity( \"%s\" ) )";
    v30 = "trigger";
    v40 = (const char *)-2113854304;
    v38 = (const char *)-2113854296;
    v31 = (const char *)-2113615168;
    v29 = (const char *)-2112029840;
    v36 = (const char *)-2112029856;
    v39 = (const char *)-2112029860;
    v34 = "$";
    do
    {
      v3 = v23;
      if ( v23 == 0 )
      {
        idStr::Append(this: &v27, text: v25.data);
        if ( idStr::Cmp(s1: v25.data, s2: ")") != 0
          || idStr::Cmp(s1: v25.data, s2: ",") != 0
          || idStr::Cmp(s1: v25.data, s2: ";") != 0 )
        {
          idStr::Append(this: &v27, text: " ");
        }
      }
      if ( idStr::Cmp(s1: v25.data, s2: "{") != 0 )
      {
        if ( idStr::Cmp(s1: v25.data, s2: "thread") != 0 )
        {
          if ( idStr::Cmp(s1: v25.data, s2: v34) != 0 )
          {
            if ( idStr::Cmp(s1: v25.data, s2: v29) != 0 )
            {
              if ( idStr::Cmp(s1: v25.data, s2: v38) != 0 )
              {
                if ( idStr::Cmp(s1: v25.data, s2: v39) != 0 )
                {
                  if ( v25.type == 3 )
                  {
                    FloatValue = idToken::GetFloatValue(this: &v25);
                    idFile::Printf(this: &v48, fmt: v37, LODWORD(FloatValue));
                  }
                  else if ( idStr::Cmp(s1: v25.data, s2: v28) != 0 )
                  {
                    if ( idStr::Cmp(s1: v25.data, s2: "\n") != 0 )
                    {
                      v11 = idStr::Cmp(s1: v25.data, s2: "\t");
                      data = "\t";
                      if ( v11 != 0 )
                        data = v25.data;
                      idFile::Printf(this: &v48, fmt: data);
                    }
                    else
                    {
                      idFile::Printf(this: &v48, fmt: "\n");
                    }
                  }
                  else
                  {
                    idParser::ReadToken(this: &v49, token: &v25);
                    idParser::ReadToken(this: &v49, token: &v25);
                    if ( idStr::Cmp(s1: v25.data, s2: v30) != 0 )
                    {
                      if ( idStr::Cmp(s1: v25.data, s2: "waitFor") != 0 )
                      {
                        idParser::UnreadToken(this: &v49, token: &v25);
                      }
                      else
                      {
                        idParser::ReadToken(this: &v49, token: &v25);
                        idParser::ReadToken(this: &v49, token: &v25);
                        idParser::ReadToken(this: &v49, token: &v25);
                        idFile::Printf(this: &v48, fmt: v26, v25.data);
                        idParser::ReadToken(this: &v49, token: &v25);
                      }
                    }
                    else
                    {
                      idParser::ReadToken(this: &v49, token: &v25);
                      idParser::ReadToken(this: &v49, token: &v25);
                      idParser::ReadToken(this: &v49, token: &v25);
                      idParser::ReadToken(this: &v49, token: &v44);
                      idParser::ReadToken(this: &v49, token: &v44);
                      idParser::ReadToken(this: &v49, token: &v44);
                      idFile::Printf(this: &v48, fmt: v32, v25.data, v44.data);
                      idParser::ReadToken(this: &v49, token: &v25);
                    }
                  }
                }
                else
                {
                  v5 = 0;
                  v6 = 0;
                  v7 = 0;
                  idParser::ReadToken(this: &v49, token: &v25);
                  if ( idStr::Cmp(s1: v25.data, s2: "-") == 0 )
                  {
                    v5 = 1;
                    idParser::ReadToken(this: &v49, token: &v25);
                  }
                  idParser::ReadToken(this: &v49, token: &v44);
                  if ( idStr::Cmp(s1: v44.data, s2: "-") == 0 )
                  {
                    v6 = 1;
                    idParser::ReadToken(this: &v49, token: &v44);
                  }
                  idParser::ReadToken(this: &v49, token: &v45);
                  if ( idStr::Cmp(s1: v45.data, s2: "-") == 0 )
                  {
                    v7 = 1;
                    idParser::ReadToken(this: &v49, token: &v45);
                  }
                  if ( v7 != 0 )
                    v8 = -idToken::GetFloatValue(this: &v45);
                  else
                    v8 = idToken::GetFloatValue(this: &v45);
                  if ( v6 != 0 )
                    v9 = -idToken::GetFloatValue(this: &v44);
                  else
                    v9 = idToken::GetFloatValue(this: &v44);
                  if ( v5 != 0 )
                    v10 = -idToken::GetFloatValue(this: &v25);
                  else
                    v10 = idToken::GetFloatValue(this: &v25);
                  idFile::Printf(this: &v48, fmt: v33, LODWORD(v10), LODWORD(v9), LODWORD(v8));
                  idParser::ReadToken(this: &v49, token: &v25);
                  v3 = v23;
                }
              }
              else
              {
                idFile::Printf(this: &v48, fmt: v40);
              }
            }
            else
            {
              idFile::Printf(this: &v48, fmt: v31);
            }
          }
          else
          {
            idParser::ReadToken(this: &v49, token: &v25);
            idFile::Printf(this: &v48, fmt: v36, v25.data);
          }
        }
        else
        {
          idParser::ReadToken(this: &v49, token: &v25);
          idStr::operator=(this: &v41, text: v25.data);
          idList<idStr,99>::~idList<idStr,99>(this: &v24);
          idParser::ReadToken(this: &v49, token: &v25);
          while ( idParser::ReadToken(this: &v49, token: &v25) )
          {
            if ( idStr::Cmp(s1: v25.data, s2: ")") == 0 )
              break;
            if ( idStr::Cmp(s1: v25.data, s2: ",") != 0 )
            {
              idStr::idStr(this: &v47, text: v25.data);
              idList<idStr,5>::Append(this: &v24, obj: &v47);
              idStr::FreeData(this: &v47);
            }
          }
          if ( v24.num != 0 )
          {
            switch ( v24.num )
            {
              case 1:
                idFile::Printf(this: &v48, fmt: "createThread1( %s, %s )", v41.data, v24.list->data);
                break;
              case 2:
                idFile::Printf(
                  this: &v48,
                  fmt: "createThread2( %s, %s, %s )",
                  v41.data,
                  v24.list->data,
                  v24.list[1].data);
                break;
              case 3:
                idFile::Printf(
                  this: &v48,
                  fmt: "createThread3( %s, %s, %s, %s )",
                  v41.data,
                  v24.list->data,
                  v24.list[1].data,
                  v24.list[2].data);
                break;
              default:
                idStrListCombineString(result: &v46, list: &v24, separator: ", ");
                idFile::Printf(this: &v48, fmt: "createThread( %s, FIXME /* %s */ )", v41.data, v46.data);
                idStr::FreeData(this: &v46);
                break;
            }
          }
          else
          {
            idFile::Printf(this: &v48, fmt: "createThread( %s )", v41.data);
          }
        }
      }
      else
      {
        if ( v23 == 0 )
        {
          v4 = v35;
          idStr::Replace(this: &v27, old: "{", nw: v35);
          idStr::Replace(this: &v27, old: "}", nw: v4);
          idStr::Replace(this: &v27, old: "\r", nw: v4);
          idStr::Replace(this: &v27, old: "\n", nw: v4);
          idFile_Memory::Write(this: &v50, buffer: v27.data, len: v27.len);
          idFile_Memory::Write(this: &v50, buffer: ";\n", len: 2u);
          idStr::Clear(this: &v27);
        }
        ++v23;
        idFile::Printf(this: &v48, fmt: "{");
        ++v3;
      }
      idParser::GetNextWhiteSpace(this: &v49, whiteSpace: &v42, currentLine: true);
      if ( idStr::Find(str: v42.data, c: 13, start: 0, end: v42.len) == -1
        || idStr::Find(str: v42.data, c: 10, start: 0, end: v42.len) == -1 )
      {
        idFile::Printf(this: &v48, fmt: v42.data);
      }
      else
      {
        idFile::Printf(this: &v48, fmt: "\n");
        if ( idParser::PeekTokenString(this: &v49, string: "}") != 0 )
          v23 = --v3;
        if ( v3 > 0 )
        {
          for ( i = v3; i != 0; --i )
            idFile::Printf(this: &v48, fmt: "\t");
        }
      }
    }
    while ( idParser::ReadToken(this: &v49, token: &v25) );
  }
  idStr::Replace(this: &v43, old: ".script", nw: ".cpp");
  v14 = fileSystem->OpenFileWrite(this: fileSystem, a2: v43.data, a3: 0);
  if ( v14 != nullptr )
  {
    v15 = v14->__vftable;
    filePtr = v48.filePtr;
    v17 = (unsigned __int64)idFile_Memory::Length(this: &v48) >> 32;
    v15->Write(this: v14, a2: filePtr, a3: v17);
    ((void (__fastcall *)(idFile *, int))v14->dtr_idFile)(a1: v14, a2: 1);
    idStr::Replace(this: &v43, old: ".cpp", nw: ".ss");
    v18 = fileSystem->OpenFileWrite(this: fileSystem, a2: v43.data, a3: 0);
    if ( v18 != nullptr )
    {
      v19 = v18->__vftable;
      v20 = v50.filePtr;
      v21 = (unsigned __int64)idFile_Memory::Length(this: &v50) >> 32;
      v19->Write(this: v18, a2: v20, a3: v21);
      ((void (__fastcall *)(idFile *, int))v18->dtr_idFile)(a1: v18, a2: 1);
LABEL_82:
      idStr::FreeData(this: &v27);
      idFile_Memory::~idFile_Memory(this: &v50);
      idFile_Memory::~idFile_Memory(this: &v48);
      idList<idStr,99>::~idList<idStr,99>(this: &v24);
      idStr::FreeData(this: &v41);
      idStr::FreeData(this: &v42);
      idStr::FreeData(this: &v45);
      idStr::FreeData(this: &v44);
      idStr::FreeData(this: &v25);
      idParser::~idParser(this: &v49);
      goto LABEL_83;
    }
  }
  idLib::Printf(fmt: "Couldn't open %s for writing\n", v43.data);
  idStr::FreeData(this: &v27);
  idFile_Memory::~idFile_Memory(this: &v50);
  idFile_Memory::~idFile_Memory(this: &v48);
  idList<idStr,99>::~idList<idStr,99>(this: &v24);
  idStr::FreeData(this: &v41);
  idStr::FreeData(this: &v42);
  idStr::FreeData(this: &v45);
  idStr::FreeData(this: &v44);
  idStr::FreeData(this: &v25);
  idParser::~idParser(this: &v49);
LABEL_83:
  idStr::FreeData(this: &v43);
}


// ========================================================================
// __unwind$234309
// EA  : 0x8266BC88
// RVA : 0x0066BC88
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_234309()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2128 + 368));
}


// ========================================================================
// __unwind$234310
// EA  : 0x8266BCB0
// RVA : 0x0066BCB0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_234310()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 2128 + 960));
}


// ========================================================================
// __unwind$234311
// EA  : 0x8266BCD8
// RVA : 0x0066BCD8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_234311()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2128 + 128));
}


// ========================================================================
// __unwind$234312
// EA  : 0x8266BD00
// RVA : 0x0066BD00
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_234312()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2128 + 400));
}


// ========================================================================
// __unwind$234313
// EA  : 0x8266BD28
// RVA : 0x0066BD28
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_234313()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2128 + 480));
}


// ========================================================================
// __unwind$234314
// EA  : 0x8266BD50
// RVA : 0x0066BD50
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_234314()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2128 + 336));
}


// ========================================================================
// __unwind$234315
// EA  : 0x8266BD78
// RVA : 0x0066BD78
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_234315()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2128 + 304));
}


// ========================================================================
// __unwind$234316
// EA  : 0x8266BDA0
// RVA : 0x0066BDA0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_234316()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 2128 + 112));
}


// ========================================================================
// __unwind$234317
// EA  : 0x8266BDC8
// RVA : 0x0066BDC8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_234317()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 2128 + 624));
}


// ========================================================================
// __unwind$234318
// EA  : 0x8266BDF0
// RVA : 0x0066BDF0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_234318()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 2128 + 1616));
}


// ========================================================================
// __unwind$234319
// EA  : 0x8266BE18
// RVA : 0x0066BE18
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_234319()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2128 + 208));
}


// ========================================================================
// __unwind$234320
// EA  : 0x8266BE40
// RVA : 0x0066BE40
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_234320()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2128 + 592));
}


// ========================================================================
// __unwind$234321
// EA  : 0x8266BE68
// RVA : 0x0066BE68
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_234321()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2128 + 560));
}


// ========================================================================
// ?DestroyGraph@idConsoleLocal@@UAAXPAVidDebugGraph@@@Z
// EA  : 0x8266C068
// RVA : 0x0066C068
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::DestroyGraph(idConsoleLocal *this, idDebugGraph *graph)
{
  idList<idEntityPtr<idEntity>,58> *p_debugGraphs; // r3
  int v4; // r4
  int num; // r10
  int v6; // r11

  p_debugGraphs = (idList<idEntityPtr<idEntity>,58> *)&this->debugGraphs;
  v4 = 0;
  num = p_debugGraphs->num;
  if ( num > 0 )
  {
    v6 = 0;
    while ( (idDebugGraph *)p_debugGraphs->list[v6].spawnId.value != graph )
    {
      ++v4;
      ++v6;
      if ( v4 >= num )
        goto LABEL_8;
    }
    if ( v4 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_debugGraphs, index: v4);
  }
LABEL_8:
  if ( graph != nullptr )
  {
    idDebugGraph::~idDebugGraph(this: graph);
    idMem::Free(this: &mem, ptr: graph, align: ALIGN_16);
  }
}


// ========================================================================
// ?AddSnapObject@idConsoleLocal@@UAAXPBDHHM@Z
// EA  : 0x8266C100
// RVA : 0x0066C100
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::AddSnapObject(
        idConsoleLocal *this,
        const char *name,
        int bytesTotal,
        int bytesChanged,
        double ms)
{
  int num; // r7
  int v10; // r9
  snapObject_t *v11; // r8
  int v12; // r11
  idStaticList<snapObject_t,128> *v13; // r10
  idStaticList<snapObject_t,128> *p_snapObjects; // r30
  int v15; // r11
  int size; // r10
  snapObject_t *list; // r9
  int v18; // r11
  int v19; // r11
  snapObject_t *v20; // r9
  snapObject_t *v21; // r9
  int maxBytesChanged; // r8
  int v23; // r9
  snapObject_t *v24; // r9
  int maxSnapObjectsChanged; // r8
  int snapObjectsChanged; // r9
  unsigned int v27; // r7

  num = this->snapObjects.num;
  v10 = 0;
  if ( num <= 0 )
  {
LABEL_5:
    if ( num < 128 )
    {
      p_snapObjects = &this->snapObjects;
      idList<snapObject_t,5>::PreAllocateWithGranularity(this: &this->snapObjects, newSize: this->snapObjects.num + 1);
      v15 = p_snapObjects->num;
      size = p_snapObjects->size;
      list = p_snapObjects->list;
      if ( v15 >= size )
      {
        v18 = (int)&list[size - 1];
      }
      else
      {
        p_snapObjects->num = v15 + 1;
        v18 = (int)&list[v15];
      }
      *(float *)(v18 + 16) = ms;
      *(_DWORD *)v18 = name;
      *(_DWORD *)(v18 + 4) = bytesTotal;
      *(_DWORD *)(v18 + 8) = bytesTotal;
      v27 = (-bytesChanged & (unsigned int)~bytesChanged) >> 31;
      *(_DWORD *)(v18 + 12) = bytesChanged;
      *(_DWORD *)(v18 + 20) = bytesChanged;
      *(_DWORD *)(v18 + 32) = 1;
      *(_DWORD *)(v18 + 36) = v27;
      *(_DWORD *)(v18 + 40) = v27;
    }
  }
  else
  {
    v11 = this->snapObjects.list;
    v12 = 0;
    v13 = &this->snapObjects;
    while ( v11[v12].name != name )
    {
      ++v10;
      ++v12;
      if ( v10 >= num )
        goto LABEL_5;
    }
    v19 = v10;
    v20 = &v11[v10];
    if ( v20->bytesTotalForSingle != bytesTotal )
      v20->bytesTotalForSingle = -1;
    v13->list[v19].bytesTotal += bytesTotal;
    v13->list[v19].bytesChanged += bytesChanged;
    v13->list[v19].ms = v13->list[v19].ms + (float)ms;
    ++v13->list[v19].snapObjectsTotal;
    v13->list[v19].snapObjectsChanged += (-bytesChanged & (unsigned int)~bytesChanged) >> 31;
    v21 = &v13->list[v19];
    maxBytesChanged = v21->maxBytesChanged;
    v23 = v21->bytesChanged;
    if ( v23 <= maxBytesChanged )
      v23 = maxBytesChanged;
    v13->list[v19].maxBytesChanged = v23;
    v24 = &v13->list[v19];
    maxSnapObjectsChanged = v24->maxSnapObjectsChanged;
    snapObjectsChanged = v24->snapObjectsChanged;
    if ( snapObjectsChanged <= maxSnapObjectsChanged )
      snapObjectsChanged = maxSnapObjectsChanged;
    v13->list[v19].maxSnapObjectsChanged = snapObjectsChanged;
  }
}


// ========================================================================
// ?AddPresentableObject@idConsoleLocal@@UAAXPBDH_N@Z
// EA  : 0x8266C2F8
// RVA : 0x0066C2F8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::AddPresentableObject(
        idConsoleLocal *this,
        const char *name,
        int presentableIndex,
        bool skipReplication)
{
  presentableObject_t *v7; // r3

  if ( this->presentableObjects.num < 32 )
  {
    v7 = idList<idDataQueue<63,8000>::msgItem_t,5>::Alloc(this: &this->presentableObjects);
    v7->name = name;
    v7->presentableIndex = presentableIndex;
    v7->skipReplication = skipReplication;
  }
}


// ========================================================================
// ??0idConsoleLocal@@QAA@XZ
// EA  : 0x8266CCF8
// RVA : 0x0066CCF8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

idConsoleLocal *__fastcall idConsoleLocal::idConsoleLocal(idConsoleLocal *this)
{
  int v2; // ctr
  float *v3; // r11
  float *bitmapConsoleBuffers; // r11
  int i; // ctr
  char *v6; // r11
  int j; // ctr

  this->next = nullptr;
  this->wantColor = true;
  this->idPrintListener::__vftable = (idPrintListener_vtbl *)&idPrintListener::`vftable';
  this->threadSafe = false;
  this->minSeverity = SEV_PRINT;
  v2 = 39;
  this->idConsole::__vftable = (idConsoleLocal_vtbl *)&idConsoleLocal::`vftable'{for `idConsole'};
  v3 = (float *)&this->lastRangeMicroseconds[37];
  this->idPrintListener::__vftable = (idPrintListener_vtbl *)&idConsoleLocal::`vftable'{for `idPrintListener'};
  do
  {
    v3[7] = -1.0;
    v3[6] = -1.0;
    v3[5] = -1.0;
    v3 += 4;
    *v3 = -1.0;
    --v2;
  }
  while ( v2 != 0 );
  this->timeLog.list = nullptr;
  this->timeLog.granularity = 0;
  this->timeLog.memTag = 5;
  this->timeLog.listStatic = 0;
  this->timeLog.size = 0;
  this->timeLog.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->timeLog);
  this->warningCollector.numWarningsTotal = 0;
  this->warningCollector.numSyntaxErrors = 0;
  this->warningCollector.numDuplicate = 0;
  this->warningCollector.numAnimWeb = 0;
  this->warningCollector.numAudio = 0;
  this->warningCollector.numEffects = 0;
  this->warningCollector.numAnimation = 0;
  this->warningCollector.numModel = 0;
  this->warningCollector.numMap = 0;
  this->warningCollector.numScripting = 0;
  this->warningCollector.numMaterial = 0;
  this->warningCollector.numMissingFile = 0;
  this->warningCollector.numObsolete = 0;
  this->warningCollector.numSubtitle = 0;
  this->warningCollector.numOther = 0;
  this->warningCollector.howLongToShow = 600;
  this->warningCollector.showTimer = 0;
  idEditField::idEditField(this: &this->consoleField);
  this->overlayText.granularity = 0;
  this->overlayText.memTag = 5;
  this->overlayText.listStatic = 0;
  this->overlayText.list = nullptr;
  this->overlayText.size = 0;
  this->overlayText.num = 0;
  bitmapConsoleBuffers = (float *)this->bitmapConsoleBuffers;
  for ( i = 512; i != 0; --i )
  {
    bitmapConsoleBuffers[13] = -1.0;
    bitmapConsoleBuffers[12] = -1.0;
    bitmapConsoleBuffers[11] = -1.0;
    bitmapConsoleBuffers += 10;
    *bitmapConsoleBuffers = -1.0;
  }
  v6 = (char *)&this->currentRange + 3;
  for ( j = 39; j != 0; --j )
  {
    v6[1] = 0;
    v6 += 48;
    *v6 = 0;
  }
  Sys_MutexCreate(handle: &this->mutexRange.handle);
  this->debugGraphs.size = 32;
  this->debugGraphs.num = 0;
  this->debugGraphs.granularity = 1;
  this->debugGraphs.list = this->debugGraphs.staticList;
  this->debugGraphs.memTag = 5;
  this->debugGraphs.listStatic = 1;
  this->avgFPS.maxNum = 0;
  this->avgFPS.current = 0;
  this->avgFPS.vals.list = nullptr;
  this->avgFPS.vals.granularity = 0;
  this->avgFPS.vals.memTag = 5;
  this->avgFPS.vals.listStatic = 0;
  this->avgFPS.vals.size = 0;
  this->avgFPS.vals.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->avgFPS.vals);
  this->avgTotalTime.maxNum = 0;
  this->avgTotalTime.current = 0;
  this->avgTotalTime.vals.list = nullptr;
  this->avgTotalTime.vals.granularity = 0;
  this->avgTotalTime.vals.memTag = 5;
  this->avgTotalTime.vals.listStatic = 0;
  this->avgTotalTime.vals.size = 0;
  this->avgTotalTime.vals.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->avgTotalTime.vals);
  this->avgRenderTime.maxNum = 0;
  this->avgRenderTime.current = 0;
  this->avgRenderTime.vals.list = nullptr;
  this->avgRenderTime.vals.granularity = 0;
  this->avgRenderTime.vals.memTag = 5;
  this->avgRenderTime.vals.listStatic = 0;
  this->avgRenderTime.vals.size = 0;
  this->avgRenderTime.vals.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->avgRenderTime.vals);
  this->avgGameTime.maxNum = 0;
  this->avgGameTime.current = 0;
  this->avgGameTime.vals.list = nullptr;
  this->avgGameTime.vals.granularity = 0;
  this->avgGameTime.vals.memTag = 5;
  this->avgGameTime.vals.listStatic = 0;
  this->avgGameTime.vals.size = 0;
  this->avgGameTime.vals.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->avgGameTime.vals);
  this->avgGPUTime.maxNum = 0;
  this->avgGPUTime.current = 0;
  this->avgGPUTime.vals.list = nullptr;
  this->avgGPUTime.vals.granularity = 0;
  this->avgGPUTime.vals.memTag = 5;
  this->avgGPUTime.vals.listStatic = 0;
  this->avgGPUTime.vals.size = 0;
  this->avgGPUTime.vals.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->avgGPUTime.vals);
  this->showSoundDebugInfoList.granularity = 0;
  this->showSoundDebugInfoList.memTag = 5;
  this->showSoundDebugInfoList.listStatic = 0;
  this->showSoundDebugInfoList.list = nullptr;
  this->showSoundDebugInfoList.size = 0;
  this->showSoundDebugInfoList.num = 0;
  this->snapObjects.size = 128;
  this->snapObjects.num = 0;
  this->snapObjects.granularity = 1;
  this->snapObjects.list = this->snapObjects.staticList;
  this->snapObjects.memTag = 5;
  this->snapObjects.listStatic = 1;
  `eh vector constructor iterator'(
    ptr: this->snapshots,
    size: 0x34u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idSnapShot::idSnapShot,
    pDtor: (void (__fastcall *)(void *))idSnapShot::~idSnapShot);
  this->presentableObjects.list = this->presentableObjects.staticList;
  this->presentableObjects.size = 32;
  this->presentableObjects.num = 0;
  this->presentableObjects.granularity = 1;
  this->presentableObjects.memTag = 5;
  this->presentableObjects.listStatic = 1;
  this->keyCatching = false;
  this->gui = nullptr;
  this->text.ptr[0x10000] = 0;
  this->text.ptr[0] = 0;
  this->lines.ptr[0] = this->text.ptr;
  this->displayFrac = 0.0;
  this->currentLine = 0;
  this->finalFrac = 0.0;
  this->lineOffset = 0;
  this->textOffset = 0;
  this->displayLine = 0;
  this->nextKeyEvent = 0;
  this->snapshotsMaxSize = 0;
  this->isInitialized = false;
  this->fracTime = 0;
  this->lastFullscreen = false;
  this->times.ptr[0] = 0;
  this->times.ptr[1] = 0;
  this->times.ptr[2] = 0;
  this->times.ptr[3] = 0;
  this->bitmapConsoleBuffers[0] = nullptr;
  this->bitmapConsoleBuffers[1] = nullptr;
  this->currentRange = 0;
  this->graphFPS = nullptr;
  this->graphTotalTime = nullptr;
  this->graphRenderTime = nullptr;
  this->graphGameTime = nullptr;
  this->graphGPUTime = nullptr;
  this->avgBytesChanged = 0.0;
  this->maxSnapObjectString = 0;
  this->lastDrawSnapshots = 0;
  this->lastDrawPresentables = 0;
  this->maxPresentableObjectString = 0;
  this->snapshotSeqs[0] = 0;
  this->snapshotSeqs[1] = 0;
  this->snapshotPeerNum = 0;
  return this;
}


// ========================================================================
// __unwind$236014
// EA  : 0x8266D1B4
// RVA : 0x0066D1B4
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236014()
{
  int v0; // r12

  idConsole::~idConsole(this: *(idConsole **)(v0 - 192 + 212));
}


// ========================================================================
// __unwind$236015
// EA  : 0x8266D1DC
// RVA : 0x0066D1DC
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236015()
{
  int v0; // r12

  idPrintListener::~idPrintListener(this: (idCommonLocal::idRefreshOnPrint *)(*(_DWORD *)(v0 - 192 + 212) + 4));
}


// ========================================================================
// __unwind$236016
// EA  : 0x8266D208
// RVA : 0x0066D208
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236016()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 964));
}


// ========================================================================
// __unwind$236017
// EA  : 0x8266D234
// RVA : 0x0066D234
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236017()
{
  int v0; // r12

  idEditField::~idEditField(this: (idEditField *)(*(_DWORD *)(v0 - 192 + 212) + 148568));
}


// ========================================================================
// __unwind$236018
// EA  : 0x8266D268
// RVA : 0x0066D268
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236018()
{
  int v0; // r12

  idList<overlayText_t,5>::~idList<overlayText_t,5>(this: (idList<overlayText_t,5> *)(*(_DWORD *)(v0 - 192 + 212)
                                                                                    + 150968));
}


// ========================================================================
// __unwind$236019
// EA  : 0x8266D29C
// RVA : 0x0066D29C
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236019()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 192 + 212) + 173340));
}


// ========================================================================
// __unwind$236020
// EA  : 0x8266D2D0
// RVA : 0x0066D2D0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236020()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 173364));
}


// ========================================================================
// __unwind$236021
// EA  : 0x8266D304
// RVA : 0x0066D304
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236021()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(*(_DWORD *)(v0 - 192 + 212) + 173508));
}


// ========================================================================
// __unwind$236022
// EA  : 0x8266D338
// RVA : 0x0066D338
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236022()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(*(_DWORD *)(v0 - 192 + 212) + 173532));
}


// ========================================================================
// __unwind$236023
// EA  : 0x8266D36C
// RVA : 0x0066D36C
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236023()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(*(_DWORD *)(v0 - 192 + 212) + 173556));
}


// ========================================================================
// __unwind$236024
// EA  : 0x8266D3A0
// RVA : 0x0066D3A0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236024()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(*(_DWORD *)(v0 - 192 + 212) + 173580));
}


// ========================================================================
// __unwind$236025
// EA  : 0x8266D3D4
// RVA : 0x0066D3D4
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236025()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(*(_DWORD *)(v0 - 192 + 212) + 173604));
}


// ========================================================================
// __unwind$236026
// EA  : 0x8266D408
// RVA : 0x0066D408
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236026()
{
  int v0; // r12

  idList<showSoundDebugInfo_t,5>::Clear(this: (idList<showSoundDebugInfo_t,5> *)(*(_DWORD *)(v0 - 192 + 212) + 173628));
}


// ========================================================================
// __unwind$236027
// EA  : 0x8266D43C
// RVA : 0x0066D43C
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236027()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 173644));
}


// ========================================================================
// ?IsInitialized@idConsoleLocal@@UAA_NXZ
// EA  : 0x8266D470
// RVA : 0x0066D470
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

BOOL __fastcall idConsoleLocal::IsInitialized(idConsoleLocal *this)
{
  return this->isInitialized;
}


// ========================================================================
// ?WasLastFullScreen@idConsoleLocal@@UAA_NXZ
// EA  : 0x8266D480
// RVA : 0x0066D480
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

BOOL __fastcall idConsoleLocal::WasLastFullScreen(idConsoleLocal *this)
{
  return this->lastFullscreen;
}


// ========================================================================
// ?Gui@idConsoleLocal@@UAAPAVidRenderModelGui@@XZ
// EA  : 0x8266D490
// RVA : 0x0066D490
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

idRenderModelGui *__fastcall idConsoleLocal::Gui(idConsoleLocal *this)
{
  return this->gui;
}


// ========================================================================
// ?GetTimeRangeColor@idConsoleLocal@@UAA?AVidColor@@W4rangeId_t@@@Z
// EA  : 0x8266D498
// RVA : 0x0066D498
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

idConsoleLocal *__fastcall idConsoleLocal::GetTimeRangeColor(idConsoleLocal *this, idColor *result, const rangeId_t id)
{
  idColor *v3; // r10
  idPrintListener_vtbl *g_low; // r8
  idPrintListener *b_low; // r7
  float a; // r6

  v3 = &result[id + 21];
  g_low = (idPrintListener_vtbl *)LODWORD(v3->g);
  b_low = (idPrintListener *)LODWORD(v3->b);
  a = v3->a;
  this->idConsole::__vftable = (idConsoleLocal_vtbl *)LODWORD(v3->r);
  this->idPrintListener::__vftable = g_low;
  this->next = b_low;
  *(float *)&this->wantColor = a;
  return this;
}


// ========================================================================
// ?MarkVBLTime@idConsoleLocal@@EAAXXZ
// EA  : 0x8266D4C8
// RVA : 0x0066D4C8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::MarkVBLTime(idConsoleLocal *this)
{
  unsigned __int64 v2; // r3
  __int128 v3; // r8

  LODWORD(v2) = Sys_Microseconds() >> 32;
  *((_QWORD *)&v3 + 1) = this->lastVblMicroseconds;
  this->lastVblMicroseconds = v2;
  DWORD2(v3) = v2 - v3;
  this->vblIntervalMicroseconds = *(_QWORD *)((char *)&v3 + 4);
}


// ========================================================================
// ?ClearEditLine@idConsoleLocal@@UAAXXZ
// EA  : 0x8266D528
// RVA : 0x0066D528
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::ClearEditLine(idConsoleLocal *this)
{
  idList<overlayText_t,5> *p_overlayText; // r31

  p_overlayText = &this->overlayText;
  idEditField::Clear(this: &this->consoleField);
  if ( p_overlayText->listStatic == 0 || p_overlayText->listStatic == 2 )
  {
    if ( p_overlayText->list != nullptr )
      idListArrayDelete<overlayText_t>(ptr: p_overlayText->list, num: p_overlayText->size);
    p_overlayText->list = nullptr;
    p_overlayText->size = 0;
  }
  p_overlayText->num = 0;
}


// ========================================================================
// ??1idConsoleLocal@@UAA@XZ
// EA  : 0x8266D5B0
// RVA : 0x0066D5B0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::~idConsoleLocal(idConsoleLocal *this)
{
  idPrintListener *v2; // r21
  int *p_num; // r25
  int v4; // r26
  int v5; // r30
  idStaticList<idDebugGraph *,32> *p_debugGraphs; // r27
  idDebugGraph *v7; // r10
  idDebugGraph *v8; // r29
  idStaticList<idDebugGraph *,32> *v9; // r29
  idStaticList<presentableObject_t,32> *p_presentableObjects; // r30
  idStaticList<snapObject_t,128> *p_snapObjects; // r30
  char **p_showSoundDebugInfoList; // r30
  float *list; // r4
  float *v14; // r4
  float *v15; // r4
  float *v16; // r4
  float *v17; // r4
  idList<overlayText_t,5> *p_overlayText; // r27
  overlayText_t *v19; // r26
  int size; // r30
  idStr *p_text; // r29
  unsigned __int8 *v22; // r4

  this->idConsole::__vftable = (idConsoleLocal_vtbl *)&idConsoleLocal::`vftable'{for `idConsole'};
  v2 = &this->idPrintListener;
  this->idPrintListener::__vftable = (idPrintListener_vtbl *)&idConsoleLocal::`vftable'{for `idPrintListener'};
  p_num = &this->debugGraphs.num;
  v4 = 0;
  if ( this->debugGraphs.num > 0 )
  {
    v5 = 0;
    p_debugGraphs = &this->debugGraphs;
    do
    {
      v7 = p_debugGraphs->list[v5];
      if ( v7 != nullptr )
      {
        v8 = p_debugGraphs->list[v5];
        idDebugGraph::~idDebugGraph(this: v7);
        idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
        p_debugGraphs->list[v5] = nullptr;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < *p_num );
  }
  v9 = &this->debugGraphs;
  if ( this->debugGraphs.listStatic == 0 || this->debugGraphs.listStatic == 2 )
  {
    if ( v9->list != nullptr )
      idMem::Free(this: &mem, ptr: v9->list, align: ALIGN_16);
    v9->list = nullptr;
    this->debugGraphs.size = 0;
  }
  this->debugGraphs.num = 0;
  p_presentableObjects = &this->presentableObjects;
  if ( this->presentableObjects.listStatic == 0 || this->presentableObjects.listStatic == 2 )
  {
    if ( p_presentableObjects->list != nullptr )
      idMem::Free(this: &mem, ptr: p_presentableObjects->list, align: ALIGN_16);
    p_presentableObjects->list = nullptr;
    this->presentableObjects.size = 0;
  }
  this->presentableObjects.num = 0;
  `eh vector destructor iterator'(
    ptr: this->snapshots,
    size: 0x34u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idSnapShot::~idSnapShot);
  p_snapObjects = &this->snapObjects;
  if ( this->snapObjects.listStatic == 0 || this->snapObjects.listStatic == 2 )
  {
    if ( p_snapObjects->list != nullptr )
      idMem::Free(this: &mem, ptr: p_snapObjects->list, align: ALIGN_16);
    p_snapObjects->list = nullptr;
    this->snapObjects.size = 0;
  }
  this->snapObjects.num = 0;
  p_showSoundDebugInfoList = (char **)&this->showSoundDebugInfoList;
  if ( this->showSoundDebugInfoList.listStatic == 0 || this->showSoundDebugInfoList.listStatic == 2 )
  {
    if ( *p_showSoundDebugInfoList != nullptr )
      idListArrayDelete<showSoundDebugInfo_t>(ptr: *p_showSoundDebugInfoList, num: this->showSoundDebugInfoList.size);
    *p_showSoundDebugInfoList = nullptr;
    this->showSoundDebugInfoList.size = 0;
  }
  this->showSoundDebugInfoList.num = 0;
  if ( this->avgGPUTime.vals.listStatic == 0 || this->avgGPUTime.vals.listStatic == 2 )
  {
    list = this->avgGPUTime.vals.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->avgGPUTime.vals.list = nullptr;
    this->avgGPUTime.vals.size = 0;
  }
  this->avgGPUTime.vals.num = 0;
  if ( this->avgGameTime.vals.listStatic == 0 || this->avgGameTime.vals.listStatic == 2 )
  {
    v14 = this->avgGameTime.vals.list;
    if ( v14 != nullptr )
      idMem::Free(this: &mem, ptr: v14, align: ALIGN_16);
    this->avgGameTime.vals.list = nullptr;
    this->avgGameTime.vals.size = 0;
  }
  this->avgGameTime.vals.num = 0;
  if ( this->avgRenderTime.vals.listStatic == 0 || this->avgRenderTime.vals.listStatic == 2 )
  {
    v15 = this->avgRenderTime.vals.list;
    if ( v15 != nullptr )
      idMem::Free(this: &mem, ptr: v15, align: ALIGN_16);
    this->avgRenderTime.vals.list = nullptr;
    this->avgRenderTime.vals.size = 0;
  }
  this->avgRenderTime.vals.num = 0;
  if ( this->avgTotalTime.vals.listStatic == 0 || this->avgTotalTime.vals.listStatic == 2 )
  {
    v16 = this->avgTotalTime.vals.list;
    if ( v16 != nullptr )
      idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
    this->avgTotalTime.vals.list = nullptr;
    this->avgTotalTime.vals.size = 0;
  }
  this->avgTotalTime.vals.num = 0;
  if ( this->avgFPS.vals.listStatic == 0 || this->avgFPS.vals.listStatic == 2 )
  {
    v17 = this->avgFPS.vals.list;
    if ( v17 != nullptr )
      idMem::Free(this: &mem, ptr: v17, align: ALIGN_16);
    this->avgFPS.vals.list = nullptr;
    this->avgFPS.vals.size = 0;
  }
  this->avgFPS.vals.num = 0;
  if ( this->debugGraphs.listStatic == 0 || this->debugGraphs.listStatic == 2 )
  {
    if ( v9->list != nullptr )
      idMem::Free(this: &mem, ptr: v9->list, align: ALIGN_16);
    v9->list = nullptr;
    this->debugGraphs.size = 0;
  }
  this->debugGraphs.num = 0;
  Sys_MutexDestroy(handle: &this->mutexRange.handle);
  p_overlayText = &this->overlayText;
  if ( this->overlayText.listStatic == 0 || this->overlayText.listStatic == 2 )
  {
    v19 = p_overlayText->list;
    if ( p_overlayText->list != nullptr )
    {
      size = this->overlayText.size;
      if ( size > 0 )
      {
        p_text = &p_overlayText->list->text;
        do
        {
          idStr::FreeData(this: p_text);
          --size;
          p_text = (idStr *)((char *)p_text + 48);
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: v19, align: ALIGN_16);
    }
    p_overlayText->list = nullptr;
    this->overlayText.size = 0;
  }
  this->overlayText.num = 0;
  idEditField::~idEditField(this: &this->consoleField);
  if ( this->timeLog.listStatic == 0 || this->timeLog.listStatic == 2 )
  {
    v22 = this->timeLog.list;
    if ( v22 != nullptr )
      idMem::Free(this: &mem, ptr: v22, align: ALIGN_16);
    this->timeLog.list = nullptr;
    this->timeLog.size = 0;
  }
  this->timeLog.num = 0;
  v2->__vftable = (idPrintListener_vtbl *)&idPrintListener::`vftable';
  idPrintListener::UnRegisterPrintListener(this: v2);
  this->idConsole::__vftable = (idConsoleLocal_vtbl *)&idConsole::`vftable';
}


// ========================================================================
// __unwind$236373
// EA  : 0x8266DA00
// RVA : 0x0066DA00
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236373()
{
  int v0; // r12

  idConsole::~idConsole(this: *(idConsole **)(v0 - 192 + 212));
}


// ========================================================================
// __unwind$236374
// EA  : 0x8266DA28
// RVA : 0x0066DA28
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236374()
{
  int v0; // r12

  idPrintListener::~idPrintListener(this: (idCommonLocal::idRefreshOnPrint *)(*(_DWORD *)(v0 - 192 + 212) + 4));
}


// ========================================================================
// __unwind$236375
// EA  : 0x8266DA54
// RVA : 0x0066DA54
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236375()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 964));
}


// ========================================================================
// __unwind$236376
// EA  : 0x8266DA80
// RVA : 0x0066DA80
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236376()
{
  int v0; // r12

  idEditField::~idEditField(this: (idEditField *)(*(_DWORD *)(v0 - 192 + 212) + 148568));
}


// ========================================================================
// __unwind$236377
// EA  : 0x8266DAB4
// RVA : 0x0066DAB4
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236377()
{
  int v0; // r12

  idList<overlayText_t,5>::~idList<overlayText_t,5>(this: (idList<overlayText_t,5> *)(*(_DWORD *)(v0 - 192 + 212)
                                                                                    + 150968));
}


// ========================================================================
// __unwind$236378
// EA  : 0x8266DAE8
// RVA : 0x0066DAE8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236378()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 192 + 212) + 173340));
}


// ========================================================================
// __unwind$236379
// EA  : 0x8266DB1C
// RVA : 0x0066DB1C
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236379()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 173364));
}


// ========================================================================
// __unwind$236380
// EA  : 0x8266DB50
// RVA : 0x0066DB50
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236380()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(*(_DWORD *)(v0 - 192 + 212) + 173508));
}


// ========================================================================
// __unwind$236381
// EA  : 0x8266DB84
// RVA : 0x0066DB84
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236381()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(*(_DWORD *)(v0 - 192 + 212) + 173532));
}


// ========================================================================
// __unwind$236382
// EA  : 0x8266DBB8
// RVA : 0x0066DBB8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236382()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(*(_DWORD *)(v0 - 192 + 212) + 173556));
}


// ========================================================================
// __unwind$236383
// EA  : 0x8266DBEC
// RVA : 0x0066DBEC
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236383()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(*(_DWORD *)(v0 - 192 + 212) + 173580));
}


// ========================================================================
// __unwind$236384
// EA  : 0x8266DC20
// RVA : 0x0066DC20
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236384()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(*(_DWORD *)(v0 - 192 + 212) + 173604));
}


// ========================================================================
// __unwind$236385
// EA  : 0x8266DC54
// RVA : 0x0066DC54
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236385()
{
  int v0; // r12

  idList<showSoundDebugInfo_t,5>::Clear(this: (idList<showSoundDebugInfo_t,5> *)(*(_DWORD *)(v0 - 192 + 212) + 173628));
}


// ========================================================================
// __unwind$236386
// EA  : 0x8266DC88
// RVA : 0x0066DC88
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236386()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 173644));
}


// ========================================================================
// __unwind$236387
// EA  : 0x8266DCBC
// RVA : 0x0066DCBC
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236387()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 192 + 212) + 179304),
    size: 0x34u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idSnapShot::~idSnapShot);
}


// ========================================================================
// __unwind$236388
// EA  : 0x8266DD00
// RVA : 0x0066DD00
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_236388()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 179428));
}


// ========================================================================
// ?DrawOverlayText@idConsoleLocal@@AAAXAAM00@Z
// EA  : 0x8266DD40
// RVA : 0x0066DD40
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __fastcall idConsoleLocal::DrawOverlayText(idConsoleLocal *this, float *leftY, float *rightY, float *centerY)
{
  int *p_num; // r29
  float *v6; // r3
  int num; // r10
  __int64 v10; // r9
  int v11; // r26
  idList<overlayText_t,5> *p_overlayText; // r23
  int v13; // r7
  unsigned int v14; // r6
  overlayText_t *v15; // r28
  int v16; // r11
  int i; // r10
  int v18; // r9
  overlayText_t *v19; // r11
  double v20; // fp30
  double bgopacity; // fp10
  double v22; // fp31
  double v23; // fp29
  double v24; // fp2
  double v25; // fp1
  justify_t justify; // r11
  double v27; // fp23
  __int64 v28; // r8
  __int64 v29; // r9
  int v30; // r27
  double j; // fp30
  __int64 v32; // r10
  __int64 v33; // r8
  int v34; // r30
  char v35; // r29
  int v36; // r11
  int v37; // r10
  justify_t v38; // r11
  char *data; // r30
  __int128 v40; // r10
  char *v41; // r30
  __int128 v42; // r10
  idList<overlayText_t,5> *v43; // r30
  int size; // r4
  idStr *list; // r28
  int v46; // r30
  idStr *v47; // r29
  int v48; // r22
  int v49; // r23
  idConsoleWatch *v50; // r25
  __int64 v51; // r10
  const idVec4 *v52; // r5
  const char *v53; // r4
  int drawX; // r11
  double v55; // fp0
  int v56; // r29
  int v57; // r28
  idStr *v58; // r11
  int v59; // r30
  double v60; // fp31
  idStr *v61; // r26
  int v62; // r30
  idStr *v63; // r29
  int v64; // [sp+8h] [-1D8h]
  int v65; // [sp+Ch] [-1D4h]
  int v66; // [sp+10h] [-1D0h]
  int v67; // [sp+14h] [-1CCh]
  int v68; // [sp+18h] [-1C8h]
  int v69; // [sp+1Ch] [-1C4h]
  float v70; // [sp+1Ch] [-1C4h]
  float v71; // [sp+1Ch] [-1C4h]
  float *v72; // [sp+20h] [-1C0h]
  int v73; // [sp+24h] [-1BCh]
  float *v74; // [sp+24h] [-1BCh]
  float *v75; // [sp+24h] [-1BCh]
  const char *v76; // [sp+28h] [-1B8h]
  int v77; // [sp+2Ch] [-1B4h]
  int v78; // [sp+2Ch] [-1B4h]
  float *v79; // [sp+2Ch] [-1B4h]
  int v80; // [sp+30h] [-1B0h]
  int v81; // [sp+34h] [-1ACh]
  int v82; // [sp+84h] [-15Ch]
  int *v83; // [sp+90h] [-150h]
  idVec4 v84; // [sp+D0h] [-110h] BYREF
  idStr v85[3]; // [sp+E0h] [-100h] BYREF

  p_num = &this->overlayText.num;
  v82 = 0;
  v83 = &this->overlayText.num;
  num = this->overlayText.num;
  v6 = leftY;
  if ( num > 0 )
  {
    HIDWORD(v10) = &off_82010000;
    v11 = 0;
    p_overlayText = &this->overlayText;
    while ( 1 )
    {
      v13 = 0;
      v14 = 0;
      v15 = &p_overlayText->list[v11];
      v16 = 0;
      for ( i = v15->text.len; v16 < i; ++v16 )
      {
        v18 = 1;
        if ( v16 < i )
        {
          HIDWORD(v10) = v15->text.data;
          do
          {
            if ( *(_BYTE *)(HIDWORD(v10) + v16) == 10 )
              break;
            ++v16;
            ++v18;
          }
          while ( v16 < i );
        }
        ++v14;
        if ( v18 > v13 )
          v13 = v18;
      }
      LODWORD(v10) = v13;
      v19 = &p_overlayText->list[v11];
      v20 = (float)(SMALLCHAR_WIDTH * (float)-0.5);
      bgopacity = v19->bgopacity;
      v84.x = 0.0;
      v84.y = 0.0;
      v84.z = 0.0;
      v84.w = bgopacity;
      v22 = (float)((float)v10 * SMALLCHAR_WIDTH);
      v23 = (float)((float)(SMALLCHAR_HEIGHT + (float)4.0) * (float)__SPAIR64__(v13, v14));
      if ( v19->justify == JUSTIFY_LEFT )
        break;
      justify = v15->justify;
      if ( justify == JUSTIFY_RIGHT )
      {
        v27 = *rightY;
        LODWORD(v28) = renderSystem->GetWidth(this: renderSystem) - 48;
        v25 = (float)((float)((float)v28 - (float)v22) + (float)v20);
        goto LABEL_19;
      }
      if ( justify == JUSTIFY_CENTER_LEFT || justify == JUSTIFY_CENTER_RIGHT )
      {
        v27 = *centerY;
        LODWORD(v29) = renderSystem->GetWidth(this: renderSystem);
        v25 = (float)((float)((float)((float)v29 - (float)v22) + (float)v20) * (float)0.5);
LABEL_19:
        v24 = v27;
LABEL_20:
        idRenderModelGui::DrawFilled(this: this->gui, color: &v84, x: v25, y: v24, w: v22, h: v23);
      }
      v85[0].allocedAndFlag = 20;
      v85[0].len = 0;
      v85[0].data = v85[0].baseBuffer;
      v85[0].baseBuffer[0] = 0;
      v30 = 0;
      for ( j = p_overlayText->list[v11].fgopacity; v30 < v15->text.len; v30 += v85[0].len + 1 )
      {
        idStr::operator=(this: v85, text: &byte_8200D768);
        v34 = v30;
        if ( v30 < v15->text.len )
        {
          do
          {
            v35 = v15->text.data[v34];
            if ( v35 == 10 )
              break;
            v36 = v85[0].len + 2;
            v37 = v85[0].allocedAndFlag & 0x7FFFFFFF;
            if ( v85[0].allocedAndFlag >= 0 )
            {
              if ( v36 > v37 )
                idStr::ReAllocate(this: v85, amount: (v36 >> 1) + v36, keepold: true);
            }
            else if ( v36 > v37
                   && AssertFailed(
                        file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                        line: 463,
                        expression: "amount <= GetAlloced()",
                        inlineBreak: true) )
            {
              __trap();
            }
            ++v34;
            LODWORD(v32) = v85[0].data;
            v85[0].data[v85[0].len] = v35;
            LODWORD(v33) = v85[0].len;
            HIDWORD(v32) = v85[0].data;
            v85[0].data[++v85[0].len] = 0;
          }
          while ( v34 < v15->text.len );
          p_num = v83;
        }
        v38 = p_overlayText->list[v11].justify;
        if ( v38 != JUSTIFY_LEFT )
        {
          switch ( v38 )
          {
            case JUSTIFY_RIGHT:
              *(float *)&v75 = j;
              HIDWORD(v33) = v85[0].data;
              idConsoleLocal::DrawTextRightAlign(
                this,
                y: v75,
                opacity: j,
                text: v76,
                a5: "%s",
                a6: v33,
                a7: v32,
                a8: v64,
                a9: v65,
                a10: v66,
                a11: v67,
                a12: v68,
                a13: v69,
                a14: (int)v72,
                a15: (int)v75,
                a16: (int)v76,
                a17: v77);
              break;
            case JUSTIFY_CENTER_LEFT:
              data = v85[0].data;
              DWORD2(v40) = renderSystem->GetWidth(this: renderSystem);
              *(float *)&v78 = j;
              v70 = (float)((float)*(__int64 *)((char *)&v40 + 4) - (float)v22) * (float)0.5;
              idConsoleLocal::DrawTextOffsetLeftAlign(
                this: (idConsoleLocal *)LODWORD(v70),
                x: v70,
                y: v72,
                opacity: j,
                text: centerY,
                a6: v80,
                a7: __SPAIR64__("%s", (unsigned int)data),
                a8: v40,
                a9: v64,
                a10: v65,
                a11: v66,
                a12: v67,
                a13: v68,
                a14: SLODWORD(v70),
                a15: (int)v72,
                a16: v73,
                a17: (int)v76,
                a18: v78,
                a19: v80,
                a20: v81);
              break;
            case JUSTIFY_CENTER_RIGHT:
              v41 = v85[0].data;
              DWORD2(v42) = renderSystem->GetWidth(this: renderSystem);
              *(float *)&v79 = j;
              v71 = (float)((float)*(__int64 *)((char *)&v42 + 4) + (float)v22) * (float)0.5;
              idConsoleLocal::DrawTextOffsetRightAlign(
                this: (idConsoleLocal *)LODWORD(v71),
                x: v71,
                y: v72,
                opacity: j,
                text: v79,
                a6: v80,
                a7: __SPAIR64__("%s", (unsigned int)v41),
                a8: v42,
                a9: v64,
                a10: v65,
                a11: v66,
                a12: v67,
                a13: v68,
                a14: SLODWORD(v71),
                a15: (int)v72,
                a16: v73,
                a17: (int)v76,
                a18: (int)v79,
                a19: v80,
                a20: v81);
              break;
            default:
              break;
          }
        }
        else
        {
          *(float *)&v74 = j;
          HIDWORD(v33) = v85[0].data;
          idConsoleLocal::DrawTextLeftAlign(
            this,
            y: v74,
            opacity: j,
            text: v76,
            a5: "%s",
            a6: v33,
            a7: v32,
            a8: v64,
            a9: v65,
            a10: v66,
            a11: v67,
            a12: v68,
            a13: v69,
            a14: (int)v72,
            a15: (int)v74,
            a16: (int)v76,
            a17: v77);
        }
      }
      idStr::FreeData(this: v85);
      ++v11;
      if ( ++v82 >= *p_num )
        goto LABEL_42;
      v6 = leftY;
    }
    v24 = *v6;
    v25 = (float)((float)(SMALLCHAR_WIDTH * (float)-0.5) + (float)48.0);
    goto LABEL_20;
  }
LABEL_42:
  v43 = &this->overlayText;
  size = this->overlayText.size;
  if ( size < 0 )
  {
    if ( this->overlayText.listStatic == 0 || this->overlayText.listStatic == 2 )
    {
      if ( v43->list != nullptr )
        idListArrayDelete<overlayText_t>(ptr: v43->list, num: size);
      v43->list = nullptr;
      this->overlayText.size = 0;
    }
    this->overlayText.num = 0;
  }
  this->overlayText.num = __CFADD__(-this->overlayText.size, this->overlayText.size ^ 0x80000000)
                        ? 0
                        : this->overlayText.size;
  if ( cwatchResultTextList.listStatic == 0 || cwatchResultTextList.listStatic == 2 )
  {
    list = cwatchResultTextList.list;
    if ( cwatchResultTextList.list != nullptr )
    {
      v46 = cwatchResultTextList.size;
      if ( cwatchResultTextList.size > 0 )
      {
        v47 = cwatchResultTextList.list;
        do
        {
          idStr::FreeData(this: v47);
          --v46;
          ++v47;
        }
        while ( v46 != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    cwatchResultTextList.list = nullptr;
    cwatchResultTextList.size = 0;
  }
  cwatchResultTextList.num = 0;
  if ( cwatchList.num > 0 )
  {
    v48 = 0;
    printConsoleWatchText = true;
    v49 = 0;
    do
    {
      v50 = &cwatchList.list[v49];
      cmdSystem->ExecuteCommandText(this: cmdSystem, a2: cwatchList.list[v49]._watchString.data);
      drawX = v50->_drawX;
      if ( drawX == -1 )
        drawX = 48;
      LODWORD(v51) = v50->_drawY;
      if ( (_DWORD)v51 == -1 )
        v55 = *leftY;
      else
        v55 = (float)v51;
      v56 = (int)v55;
      v57 = 0;
      if ( cwatchResultTextList.num <= 0 )
      {
        v61 = cwatchResultTextList.list;
      }
      else
      {
        LODWORD(v51) = drawX;
        v58 = cwatchResultTextList.list;
        v59 = 0;
        v60 = (float)v51;
        do
        {
          idRenderModelGui::DrawString(
            this: this->gui,
            x: v60,
            y: (float)(unsigned int)(v56 + 2),
            string: v53,
            defaultColor: v52,
            forceColor: (bool)v58->data,
            scale: 1.0);
          ++v57;
          ++v59;
          v61 = cwatchResultTextList.list;
          v58 = &cwatchResultTextList.list[v59];
          v56 = (int)(float)((float)((float)(__int64)((unsigned int)v56 | 0x8372000000000000uLL) + SMALLCHAR_HEIGHT)
                           + (float)4.0);
        }
        while ( v57 < cwatchResultTextList.num );
      }
      if ( v50->_drawY == -1 )
      {
        *leftY = (float)__SPAIR64__((unsigned int)leftY, v56);
        v61 = cwatchResultTextList.list;
      }
      if ( cwatchResultTextList.listStatic == 0 || cwatchResultTextList.listStatic == 2 )
      {
        if ( v61 != nullptr )
        {
          v62 = cwatchResultTextList.size;
          if ( cwatchResultTextList.size > 0 )
          {
            v63 = v61;
            do
            {
              idStr::FreeData(this: v63);
              --v62;
              ++v63;
            }
            while ( v62 != 0 );
          }
          idMem::Free(this: &mem, ptr: v61, align: ALIGN_16);
        }
        cwatchResultTextList.list = nullptr;
        cwatchResultTextList.size = 0;
      }
      ++v48;
      cwatchResultTextList.num = 0;
      ++v49;
    }
    while ( v48 < cwatchList.num );
    printConsoleWatchText = false;
  }
}


// ========================================================================
// __unwind$237153
// EA  : 0x8266E4F8
// RVA : 0x0066E4F8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_237153()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 224));
}


// ========================================================================
// ?PrintOverlay@idConsoleLocal@@UAAXAAVidOverlayHandle@@W4justify_t@@MMPBDZZ
// EA  : 0x8266E750
// RVA : 0x0066E750
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idConsoleLocal::PrintOverlay(
        idConsoleLocal *this,
        idOverlayHandle *handle,
        justify_t justify,
        double bgopacity,
        double fgopacity,
        const char *text,
        int a7,
        const char *a8,
        __int64 a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        ...)
{
  int index; // r11
  overlayText_t *v29; // r29
  char v30[64]; // [sp+60h] [-1040h] BYREF
  __int64 v31; // [sp+10E0h] [+40h] BYREF
  va_list va; // [sp+10E0h] [+40h]
  __int64 v33; // [sp+10E8h] [+48h]
  va_list va1; // [sp+10F0h] [+50h] BYREF

  va_start(va1, a23);
  va_start(va, a23);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v31 = *(__int64 *)((char *)&a9 + 4);
  v33 = a9;
  index = handle->index;
  if ( handle->index < 0 || index >= this->overlayText.num || this->overlayText.list[index].time != handle->time )
  {
    idStr::vsnPrintf(dest: v30, size: 4096, fmt: a8, argptr: va);
    v29 = idList<overlayText_t,5>::Alloc(this: &this->overlayText);
    idStr::operator=(this: &v29->text, text: v30);
    v29->justify = justify;
    v29->time = Sys_Milliseconds();
    v29->bgopacity = g_consoleOverlayBackgroundOpacity.valueFloat * (float)bgopacity;
    v29->fgopacity = g_consoleOverlayForegroundOpacity.valueFloat * (float)fgopacity;
    handle->index = this->overlayText.num - 1;
    handle->time = v29->time;
  }
}


// ========================================================================
// ?DrawSounds@idConsoleLocal@@AAAXAAM00@Z
// EA  : 0x8266E8E0
// RVA : 0x0066E8E0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idConsoleLocal::DrawSounds(idConsoleLocal *this, float *leftY, float *rightY, float *centerY)
{
  idSoundWorld *v5; // r3
  idSoundWorld *v6; // r26
  int v7; // r30
  int v8; // r19
  long double v9; // fp2
  __int64 v10; // r8
  idList<showSoundDebugInfo_t,5> *p_showSoundDebugInfoList; // r24
  int v12; // r25
  __int64 v13; // r10
  int v14; // r6
  int i; // r22
  int v16; // r3
  int v17; // r28
  int j; // r27
  showSoundDebugInfo_t *v19; // r30
  const char *v20; // r4
  const idVec3 *v21; // r3
  __int64 v22; // r10
  showSoundDebugInfo_t *v23; // r30
  char v24; // r29
  double v25; // fp29
  long double v26; // fp2
  double v27; // fp28
  const char *v28; // r28
  int len; // r7
  const char *data; // r3
  long double v31; // fp2
  float x; // r11
  float y; // r9
  float z; // r8
  double v35; // fp30
  double v36; // fp31
  long double v37; // fp2
  double v38; // fp2
  __int64 v39; // r11
  va *v40; // r3
  va *v41; // r28
  size_t k; // r29
  __int64 v43; // r9
  __int128 v44; // r10
  __int64 v45; // r6 OVERLAPPED
  va *v46; // r3
  __int64 v47; // r8
  int v48; // r11
  __int64 v49; // r10
  __int64 v50; // r8
  __int64 v51; // r10
  __int64 v52; // r10
  idStr *v53; // r28
  size_t v54; // r29
  idStr *v55; // r3
  idStr *v56; // r28
  size_t v57; // r29
  __int64 v58; // r8
  int num; // r6
  int v60; // [sp+8h] [-1368h]
  int v61; // [sp+8h] [-1368h]
  int v62; // [sp+8h] [-1368h]
  int v63; // [sp+Ch] [-1364h]
  int v64; // [sp+Ch] [-1364h]
  int v65; // [sp+Ch] [-1364h]
  int v66; // [sp+10h] [-1360h]
  int v67; // [sp+10h] [-1360h]
  int v68; // [sp+10h] [-1360h]
  int v69; // [sp+14h] [-135Ch]
  int v70; // [sp+14h] [-135Ch]
  int v71; // [sp+14h] [-135Ch]
  int v72; // [sp+18h] [-1358h]
  int v73; // [sp+18h] [-1358h]
  int v74; // [sp+18h] [-1358h]
  int v75; // [sp+1Ch] [-1354h]
  int v76; // [sp+1Ch] [-1354h]
  int v77; // [sp+1Ch] [-1354h]
  int v78; // [sp+20h] [-1350h]
  int v79; // [sp+20h] [-1350h]
  double v80; // [sp+28h] [-1348h]
  const char *v81; // [sp+28h] [-1348h]
  int v82; // [sp+2Ch] [-1344h]
  int v83; // [sp+88h] [-12E8h]
  idSort_Quick<showSoundDebugInfo_t,idSort_DrawSound> v84; // [sp+8Ch] [-12E4h] BYREF
  int v85; // [sp+90h] [-12E0h]
  float v86[2]; // [sp+98h] [-12D8h] BYREF
  idCVar *v87; // [sp+A0h] [-12D0h]
  const char *v88; // [sp+A4h] [-12CCh]
  const char *v89; // [sp+A8h] [-12C8h]
  const char *v90; // [sp+ACh] [-12C4h]
  const char *v91; // [sp+B0h] [-12C0h]
  const char *v92; // [sp+B4h] [-12BCh]
  const char *v93; // [sp+B8h] [-12B8h]
  const char *v94; // [sp+BCh] [-12B4h]
  const char *v95; // [sp+C0h] [-12B0h]
  idCVar *v96; // [sp+C4h] [-12ACh]
  float v97; // [sp+C8h] [-12A8h]
  float v98; // [sp+CCh] [-12A4h]
  float v99; // [sp+D0h] [-12A0h]
  idList<showSoundDebugInfo_t,5> *v100; // [sp+D4h] [-129Ch]
  idStr v101; // [sp+E0h] [-1290h] BYREF
  idStr v102; // [sp+100h] [-1270h] BYREF
  idStr v103; // [sp+120h] [-1250h] BYREF
  int v105; // [sp+144h] [-122Ch]
  int v107; // [sp+14Ch] [-1224h]
  __int64 v108; // [sp+150h] [-1220h]
  soundDebugInfo_t v109; // [sp+160h] [-1210h] BYREF
  __int64 v110; // [sp+1B0h] [-11C0h]
  idStr v111; // [sp+1C0h] [-11B0h] BYREF
  idStr v112; // [sp+1E0h] [-1190h] BYREF
  idStr v113; // [sp+200h] [-1170h] BYREF
  idStr v114; // [sp+220h] [-1150h] BYREF
  idStr v115; // [sp+240h] [-1130h] BYREF
  va v116; // [sp+260h] [-1110h] BYREF

  v5 = soundSystem->GetPlayingSoundWorld(this: soundSystem);
  v6 = v5;
  if ( v5 != nullptr )
  {
    if ( s_showSounds.valueInteger >= 0 )
    {
      v7 = 0;
      v8 = v5->NumEmitters(this: v5);
    }
    else
    {
      v7 = -s_showSounds.valueInteger;
      v8 = 1 - s_showSounds.valueInteger;
      if ( v7 >= v5->NumEmitters(this: v5) )
        return;
    }
    LODWORD(v10) = 0x20000;
    v87 = &s_showSoundsFreeze;
    v90 = "^8";
    HIDWORD(v10) = (s_showSoundsFreeze.flags & 0x20000) != 0;
    if ( (s_showSoundsFreeze.flags & 0x20000) != 0 || s_showSoundsFreeze.valueInteger == 0 )
    {
      p_showSoundDebugInfoList = &this->showSoundDebugInfoList;
      s_showSoundsFreeze.flags &= ~0x20000u;
      idList<showSoundDebugInfo_t,5>::SetNum(this: &this->showSoundDebugInfoList, newNum: 0);
      v12 = v6->GetSoundTime(this: v6);
      for ( i = v7; i < v8; ++i )
      {
        v16 = (int)v6->EmitterForIndex(this: v6, a2: i);
        v17 = v16;
        if ( v16 != 0 )
        {
          HIDWORD(v13) = (*(unsigned __int8 (__fastcall **)(int, _DWORD))(*(_DWORD *)v16 + 44))(a1: v16, a2: 0);
          if ( HIDWORD(v13) != 0 )
          {
            for ( j = 0; j < 8; ++j )
            {
              v109.sample.len = 0;
              v109.sample.data = v109.sample.baseBuffer;
              v109.sample.baseBuffer[0] = 0;
              v109.sample.allocedAndFlag = 20;
              if ( (*(unsigned __int8 (__fastcall **)(int, int, soundDebugInfo_t *))(*(_DWORD *)v17 + 76))(
                     a1: v17,
                     a2: j,
                     a3: &v109) != 0
                && v109.playing
                && v109.volume != 0.0
                && v109.voiceVolume != 0.0 )
              {
                v19 = idList<showSoundDebugInfo_t,5>::Alloc(this: &this->showSoundDebugInfoList);
                soundDebugInfo_t::operator=(this: &v19->info, __that: &v109);
                if ( v109.shader != nullptr )
                {
                  v20 = "^8";
                  if ( v109.hardwareVoice )
                    v20 = &byte_8200D768;
                  idStr::operator=(this: &v19->shaderName, text: v20);
                  idStr::Append(this: &v19->shaderName, text: (char *)v109.shader->name.str);
                  memcpy(Dst: &v19->soundShaderParms, Src: &v109.shader->parms, Size: sizeof(v19->soundShaderParms));
                }
                else
                {
                  idStr::operator=(this: &v19->shaderName, text: "^1<NULL>^0");
                }
                v19->emitterIndex = v109.emitter->Index(this: (idSoundEmitter *)v109.emitter);
                v21 = v109.emitter->GetPosition(this: v109.emitter);
                v19->emitterPos.x = v21->x;
                v19->emitterPos.y = v21->y;
                v19->emitterPos.z = v21->z;
                v19->info.emitter = nullptr;
                v19->runTime = v12 - v19->info.startTime;
                v19->info.shader = nullptr;
              }
              idStr::FreeData(this: &v109.sample);
            }
          }
        }
      }
      v84.__vftable = (idSort_Quick<showSoundDebugInfo_t,idSort_DrawSound>_vtbl *)&idSort_DrawSound::`vftable';
      if ( p_showSoundDebugInfoList->list != nullptr )
        idSort_Quick<showSoundDebugInfo_t,idSort_DrawSound>::Sort(
          this: &v84,
          base: p_showSoundDebugInfoList->list,
          num: this->showSoundDebugInfoList.num,
          a4: v14,
          a5: SHIDWORD(v10),
          a6: v13);
      v84.__vftable = (idSort_Quick<showSoundDebugInfo_t,idSort_DrawSound>_vtbl *)&idSort<showSoundDebugInfo_t>::`vftable';
    }
    v85 = 0;
    HIDWORD(v22) = this->showSoundDebugInfoList.num;
    if ( SHIDWORD(v22) > 0 )
    {
      v83 = 0;
      v100 = &this->showSoundDebugInfoList;
      v96 = &s_showSoundsFilter;
      v95 = "^5";
      v93 = "^7";
      v91 = "^3";
      v89 = "  ";
      v88 = "ST";
      v94 = "^2";
      v92 = "off";
      while ( 1 )
      {
        v23 = &v100->list[v83];
        *(double *)&v9 = v23->info.volume;
        v24 = !v23->info.looping ? 32 : 79;
        if ( *(double *)&v9 <= 0.0 )
        {
          v25 = -999.0;
        }
        else
        {
          v9 = log(x: v9);
          v25 = (float)((float)*(double *)&v9 * (float)8.6561699);
        }
        *(double *)&v9 = v23->info.pitch;
        if ( *(double *)&v9 <= 0.0 )
        {
          v27 = -999.0;
        }
        else
        {
          v26 = log(x: v9);
          v27 = (float)((float)*(double *)&v26 * (float)17.31234);
        }
        if ( v25 <= 0.0 )
        {
          if ( v25 <= -15.0 )
          {
            if ( v25 <= -30.0 )
            {
              v28 = v95;
              if ( v25 <= -60.0 )
                v28 = v90;
            }
            else
            {
              v28 = v93;
            }
          }
          else
          {
            v28 = v91;
          }
        }
        else
        {
          v28 = "^1";
        }
        idStr::idStr(this: &v111, text: v96->valueString.data);
        if ( v111.len != 0 )
        {
          len = v23->shaderName.len;
          data = v23->shaderName.data;
          LODWORD(v86[0]) = &v23->shaderName;
          if ( idStr::Find(searchIn: data, searchFor: v111.data, casesensitive: false, start: 0, end: len) == -1 )
            goto LABEL_77;
        }
        idStr::idStr(this: &v112, text: s_soundGroupFilter.valueString.data);
        if ( v112.len == 0 || idStr::Cmp(s1: v112.data, s2: v92) == 0 )
          goto LABEL_50;
        v103.allocedAndFlag = 20;
        v103.len = 0;
        v103.data = v103.baseBuffer;
        v103.baseBuffer[0] = 0;
        idTypeInfoTools::GetEnumBitFlags(
          this: typeInfoTools,
          flags: v23->soundShaderParms.groups,
          enumType: "soundShaderGroups_t",
          flagNames: &v103,
          delimiter: " ");
        if ( idStr::Find(searchIn: v103.data, searchFor: v112.data, casesensitive: false, start: 0, end: v103.len) != -1 )
          break;
        idStr::FreeData(this: &v103);
        idStr::FreeData(this: &v112);
LABEL_77:
        idStr::FreeData(this: &v111);
        HIDWORD(v22) = v85;
        LODWORD(v10) = v83 * 280;
        HIDWORD(v10) = v83 * 280 + 280;
        num = this->showSoundDebugInfoList.num;
        ++v85;
        ++v83;
        if ( v85 >= num )
          goto LABEL_78;
      }
      idStr::FreeData(this: &v103);
LABEL_50:
      x = v23->emitterPos.x;
      y = v23->emitterPos.y;
      z = v23->emitterPos.z;
      v101.allocedAndFlag = 20;
      v101.data = v101.baseBuffer;
      v97 = x;
      v98 = y;
      v99 = z;
      v101.len = 0;
      v101.baseBuffer[0] = 0;
      if ( s_showSounds.valueInteger == 2 )
      {
        *(double *)&v31 = v23->info.voiceWetVolume;
        if ( *(double *)&v31 <= 0.0 )
        {
          v35 = -999.0;
        }
        else
        {
          v31 = log(x: v31);
          v35 = (float)((float)*(double *)&v31 * (float)8.6561699);
        }
        *(double *)&v31 = v23->info.voiceDryVolume;
        if ( *(double *)&v31 <= 0.0 )
        {
          v36 = -999.0;
        }
        else
        {
          v31 = log(x: v31);
          v36 = (float)((float)*(double *)&v31 * (float)8.6561699);
        }
        *(double *)&v31 = v23->info.voiceVolume;
        if ( *(double *)&v31 <= 0.0 )
        {
          v38 = -999.0;
        }
        else
        {
          v37 = log(x: v31);
          v38 = (float)((float)*(double *)&v37 * (float)8.6561699);
        }
        LODWORD(v39) = v23->runTime;
        HIDWORD(v39) = LODWORD(v27);
        v80 = v25;
        v110 = v39;
        v40 = va::va(
                this: &v116,
                fmt: "r:%s% 4.0fdb^0 m:% 4.0f (d:% 4.0f / w:% 4.0f) p:% 6.1f d:%5.0f t:% 7.2f %s",
                a3: __SPAIR64__((unsigned int)v28, LODWORD(v25)),
                a4: *(__int64 *)&v36,
                a5: __SPAIR64__(LODWORD(v35), LODWORD(v27)),
                a6: v60,
                a7: v63,
                a8: v66,
                a9: v69,
                a10: v72,
                a11: v75,
                v25,
                v38,
                v36,
                v35,
                v27);
        v41 = v40;
        for ( k = 0; v40->buffer[k] != 0; ++k )
          ;
      }
      else
      {
        LODWORD(v43) = v23->runTime;
        HIDWORD(v43) = v23->shaderName.data;
        v108 = v43;
        v105 = (int)v99;
        v107 = (int)v97;
        LODWORD(v44) = LODWORD(v27);
        LODWORD(v86[1]) = (int)v98;
        HIDWORD(v44) = v24;
        LODWORD(v45) = v23->info.channel;
        HIDWORD(v45) = v23->emitterIndex;
        *(double *)((char *)&v44 + 4) = v25;
        v46 = va::va(
                this: &v116,
                fmt: "%3i,%02i: %c %s% 3.0fdb^0 p% 6.1f t% 6.2f (% 5d,% 5d,% 5d ) %s",
                a3: v45,
                a4: *(__int64 *)&v44,
                a5: v44,
                a6: v60,
                a7: v63,
                a8: v66,
                a9: v69,
                a10: v72,
                a11: v75,
                v25,
                v27);
        v41 = v46;
        for ( k = 0; v46->buffer[k] != 0; ++k )
          ;
      }
      idStr::EnsureAlloced(this: &v101, amount: k + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v101.data, Src: v41, Size: k);
      v101.data[k] = 0;
      v101.len = k;
      idStr::idStr(this: &v113, text: &v101);
      idStr::RemoveColors(string: v113.data);
      HIDWORD(v47) = v113.data;
      v48 = 0;
      LODWORD(v49) = (unsigned __int8)*v113.data;
      if ( *v113.data != 0 )
      {
        do
          LODWORD(v49) = (unsigned __int8)v113.data[++v48];
        while ( v113.data[v48] != 0 );
      }
      v86[0] = *leftY + (float)2.0;
      v113.len = v48;
      idConsoleLocal::DrawTextLeftAlign(
        this,
        y: v86,
        opacity: 1.0,
        text: (const char *)HIDWORD(v80),
        a5: "^9%s",
        a6: v47,
        a7: v49,
        a8: v61,
        a9: v64,
        a10: v67,
        a11: v70,
        a12: v73,
        a13: v76,
        a14: v78,
        a15: COERCE_INT(1.0),
        a16: SHIDWORD(v80),
        a17: SLODWORD(v80));
      HIDWORD(v50) = v101.data;
      idConsoleLocal::DrawTextLeftAlign(
        this,
        y: COERCE_FLOAT_(1.0),
        opacity: 1.0,
        text: v81,
        a5: "%s",
        a6: v50,
        a7: v51,
        a8: v62,
        a9: v65,
        a10: v68,
        a11: v71,
        a12: v74,
        a13: v77,
        a14: v79,
        a15: COERCE_INT(1.0),
        a16: (int)v81,
        a17: v82);
      if ( s_showSounds.valueInteger >= 0 )
      {
LABEL_76:
        idStr::FreeData(this: &v113);
        idStr::FreeData(this: &v101);
        idStr::FreeData(this: &v112);
        goto LABEL_77;
      }
      idStr::idStr(this: &v102, text: &v23->info.sample);
      if ( v23->info.isdefault )
      {
        v53 = operator+(result: &v115, a: "^1", b: &v102);
        v54 = v53->len;
        idStr::EnsureAlloced(this: &v102, amount: v53->len + 1, keepold: false, geometricGrowth: false);
        memcpy(Dst: v102.data, Src: v53->data, Size: v54);
        v102.data[v54] = 0;
        v102.len = v54;
        v55 = &v115;
      }
      else
      {
        if ( !v23->info.iscompressed )
        {
LABEL_73:
          HIDWORD(v58) = v88;
          if ( !v23->info.isstereo )
            HIDWORD(v58) = v89;
          LODWORD(v58) = v102.data;
          idConsoleLocal::DrawTextLeftAlign(
            this,
            y: leftY,
            opacity: 1.0,
            text: (const char *)HIDWORD(v80),
            a5: "                 %s %s",
            a6: v58,
            a7: v52,
            a8: v60,
            a9: v63,
            a10: v66,
            a11: v69,
            a12: v72,
            a13: v75,
            a14: v78,
            a15: COERCE_INT(1.0),
            a16: SHIDWORD(v80),
            a17: SLODWORD(v80));
          idStr::FreeData(this: &v102);
          goto LABEL_76;
        }
        v56 = operator+(result: &v114, a: v94, b: &v102);
        v57 = v56->len;
        idStr::EnsureAlloced(this: &v102, amount: v56->len + 1, keepold: false, geometricGrowth: false);
        memcpy(Dst: v102.data, Src: v56->data, Size: v57);
        v102.data[v57] = 0;
        v102.len = v57;
        v55 = &v114;
      }
      idStr::FreeData(this: v55);
      goto LABEL_73;
    }
LABEL_78:
    LODWORD(v22) = v87->valueInteger;
    if ( (_DWORD)v22 != 0 )
      idConsoleLocal::DrawTextLeftAlign(
        this,
        y: COERCE_FLOAT_(1.0),
        opacity: 1.0,
        text: (const char *)HIDWORD(v80),
        a5: "^7frozen",
        a6: v10,
        a7: v22,
        a8: v60,
        a9: v63,
        a10: v66,
        a11: v69,
        a12: v72,
        a13: v75,
        a14: v78,
        a15: COERCE_INT(1.0),
        a16: SHIDWORD(v80),
        a17: SLODWORD(v80));
  }
}


// ========================================================================
// __unwind$237803
// EA  : 0x8266F308
// RVA : 0x0066F308
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_237803()
{
  int v0; // r12

  idDialogInfo::~idDialogInfo(this: (idDialogInfo *)(v0 - 4976 + 352));
}


// ========================================================================
// __unwind$237804
// EA  : 0x8266F330
// RVA : 0x0066F330
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_237804()
{
  int v0; // r12

  idSort_DrawSound::~idSort_DrawSound(this: (idSort_DrawSound *)(v0 - 4976 + 140));
}


// ========================================================================
// __unwind$237805
// EA  : 0x8266F358
// RVA : 0x0066F358
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_237805()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4976 + 448));
}


// ========================================================================
// __unwind$237806
// EA  : 0x8266F380
// RVA : 0x0066F380
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_237806()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4976 + 480));
}


// ========================================================================
// __unwind$237807
// EA  : 0x8266F3A8
// RVA : 0x0066F3A8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_237807()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4976 + 288));
}


// ========================================================================
// __unwind$237808
// EA  : 0x8266F3D0
// RVA : 0x0066F3D0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_237808()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4976 + 224));
}


// ========================================================================
// __unwind$237809
// EA  : 0x8266F3F8
// RVA : 0x0066F3F8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_237809()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4976 + 512));
}


// ========================================================================
// __unwind$237810_0
// EA  : 0x8266F420
// RVA : 0x0066F420
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_237810_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4976 + 256));
}


// ========================================================================
// __unwind$237811
// EA  : 0x8266F448
// RVA : 0x0066F448
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_237811()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4976 + 576));
}


// ========================================================================
// __unwind$237812
// EA  : 0x8266F470
// RVA : 0x0066F470
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_237812()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4976 + 544));
}


// ========================================================================
// ?Draw@idConsoleLocal@@UAAX_N0@Z
// EA  : 0x8266F4A0
// RVA : 0x0066F4A0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idConsoleLocal::Draw(idConsoleLocal *this, bool forceFullScreen, bool skipNotifyLines)
{
  unsigned __int64 v6; // r6
  bool v7; // r4
  double valueFloat; // fp1
  __int64 v9; // r10 OVERLAPPED
  double displayFrac; // fp13
  __int64 v11; // r8 OVERLAPPED
  __int64 v14; // r6
  __int64 v15; // r6
  __int64 v16; // r8
  int v17; // r6
  int v18; // r5
  int v19; // r4
  __int64 v20; // r10
  int valueInteger; // r11
  double v22; // fp0
  int StringWidth; // r25
  int StringHeight; // r3
  __int64 v25; // r7
  int v26; // r24
  __int64 v27; // r29
  int (__fastcall *GetWidth)(idRenderSystem *); // ctr
  int v29; // r27
  __int128 v30; // r5 OVERLAPPED
  int v31; // r6
  int v32; // r26
  __int64 v33; // r11
  __int64 v34; // r4
  __int64 v35; // r11
  float v36; // [sp+50h] [-B0h] BYREF
  float v37; // [sp+54h] [-ACh] BYREF
  __int64 v38; // [sp+58h] [-A8h] BYREF
  idVec4 v39; // [sp+60h] [-A0h] BYREF
  float v40; // [sp+70h] [-90h]
  float v41; // [sp+74h] [-8Ch]
  float v42; // [sp+78h] [-88h]
  float v43; // [sp+7Ch] [-84h]
  idStr v44; // [sp+80h] [-80h] BYREF

  if ( !this->IsInitialized(this) || this->gui == nullptr )
    return;
  if ( (con_fontSize.flags & 0x20000) != 0 )
  {
    valueFloat = con_fontSize.valueFloat;
    if ( con_fontSize.valueFloat < 4.0 )
    {
      idCVar::SetFloat(this: &con_fontSize, newValue: 4.0, force: v7);
      valueFloat = con_fontSize.valueFloat;
    }
    idRenderModelGui::SetupMonospaceFont(this: this->gui, drawWidth: valueFloat);
    con_fontSize.flags &= ~0x20000u;
  }
  this->lastFullscreen = forceFullScreen;
  idRenderModelGui::Clear(this: (idRenderModelGui *)HIDWORD(defaultExtraGLState), bits: v6);
  idConsoleLocal::UpdateDisplayFraction(this);
  if ( forceFullScreen )
  {
    idConsoleLocal::DrawSolidConsole(this, currentDisplayFrac: 1.0);
    goto LABEL_14;
  }
  if ( this->displayFrac != 0.0 )
  {
    idConsoleLocal::Scroll(this);
    idConsoleLocal::DrawSolidConsole(this, currentDisplayFrac: this->displayFrac);
    goto LABEL_14;
  }
  if ( con_noPrint.valueInteger != 0 )
    return;
  if ( !skipNotifyLines )
  {
    idConsoleLocal::DrawNotify(this);
LABEL_14:
    if ( con_noPrint.valueInteger != 0 )
      return;
  }
  if ( !skipNotifyLines )
  {
    HIDWORD(v9) = renderSystem->GetHeight(this: renderSystem);
    displayFrac = this->displayFrac;
    LODWORD(v38) = HIDWORD(v9);
    HIDWORD(v11) = &unk_82150000;
    v37 = 32.0;
    _FP7 = (float)((float)(SMALLCHAR_HEIGHT * (float)4.0)
                 - (float)((float)*(__int64 *)((char *)&v9 + 4) * (float)displayFrac));
    LODWORD(v11) = &localConsole.text.ptr[2048];
    __asm { fsel      f6, f7, f9, f8 }
    *(float *)&v38 = (float)_FP6 + (float)32.0;
    v36 = *(float *)&v38;
    if ( com_showWarningDisplay.valueInteger != 0 )
    {
      LODWORD(v14) = &v36;
      HIDWORD(v14) = &v37;
      idConsoleLocal::DrawWarnings(this, leftY: (float *)&v38, centerY: v14);
    }
    if ( s_showSounds.valueInteger != 0 )
      idConsoleLocal::DrawSounds(this, leftY: (float *)&v38, rightY: &v37, centerY: &v36);
    LODWORD(v9) = &com_showFPS;
    if ( com_showFPS.valueInteger != 0 )
    {
      LODWORD(v15) = &v36;
      HIDWORD(v15) = &v37;
      idConsoleLocal::DrawFPS(this, leftY: (float *)&v38, centerY: v15, a4: v11, a5: v9);
    }
    if ( com_timer.valueInteger != 0 )
      idConsoleLocal::DrawTimer(this, leftY: (float *)&v38, rightY: &v37, centerY: &v36);
    if ( com_showMemoryUsage.valueInteger >= 1 )
      idConsoleLocal::DrawMemoryUsage(this, leftY: (float *)&v38, rightY: &v37, centerY: &v36);
    if ( com_speeds.valueInteger == 2 || com_speeds.valueInteger == 3 )
      idConsoleLocal::DrawComSpeeds(this, leftY: (float *)&v38, rightY: &v37, centerY: &v36);
    idConsoleLocal::DrawOverlayText(this, leftY: (float *)&v38, rightY: &v37, centerY: &v36);
    if ( com_drawThreadSpeeds.valueInteger != 0 )
      idConsoleLocal::DrawTimeRanges(this);
    if ( con_logThreadSpeeds.valueInteger != 0 )
      idConsoleLocal::LogThreadSpeeds(this);
    idConsoleLocal::DrawDebugGraphs(this);
    LODWORD(v20) = this->lastDrawSnapshots;
    valueInteger = com_drawSnapshots.valueInteger;
    if ( (_DWORD)v20 != com_drawSnapshots.valueInteger )
    {
      this->avgBytesChanged = 0.0;
      this->maxSnapObjectString = 0;
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->snapObjects);
      this->lastDrawSnapshots = com_drawSnapshots.valueInteger;
      valueInteger = com_drawSnapshots.valueInteger;
    }
    if ( valueInteger > 0 )
      idConsoleLocal::DrawSnapshots(this, a2: v19, a3: v18, a4: v17, a5: SHIDWORD(v16), a6: v20);
    if ( com_drawSnapshotMetrics.valueInteger > 0 && this->displayFrac == 0.0 )
      idConsoleLocal::DrawSnapshotReport(this);
    if ( com_drawPresentables.valueInteger != 0 )
      idConsoleLocal::DrawPresentables(this, a2: v19, a3: v18, a4: v17, a5: v16);
    if ( con_drawVersion.valueInteger > 0 )
    {
      v22 = 1.0;
      if ( con_drawVersion.valueInteger == 1 )
        v22 = g_consoleOverlayBackgroundOpacity.valueFloat;
      v39.x = 0.0;
      v39.y = 0.0;
      v39.z = 0.0;
      v39.w = v22;
      v40 = 1.0;
      v41 = 0.0;
      v42 = 0.0;
      v43 = 1.0;
      idStr::idStr(this: &v44, text: com_version.resetString);
      StringWidth = idRenderModelGui::GetStringWidth(this: this->gui, string: v44.data, scale: 1.0);
      StringHeight = idRenderModelGui::GetStringHeight(this: this->gui, scale: 1.0);
      LODWORD(v25) = v44.len;
      v26 = StringHeight;
      LODWORD(v38) = (int)SMALLCHAR_HEIGHT;
      LODWORD(v27) = v38 + 16;
      GetWidth = renderSystem->GetWidth;
      LODWORD(v38) = (int)(float)((float)v25 * SMALLCHAR_WIDTH);
      HIDWORD(v27) = v38 + 16;
      v29 = GetWidth(this: renderSystem) + -52 - HIDWORD(v27);
      *(_QWORD *)((char *)&v30 + 4) = ((__int64 (__fastcall *)(idRenderSystem *))renderSystem->GetHeight)(a1: renderSystem);
      v31 = HIDWORD(v27);
      v32 = DWORD1(v30) + -36 - v27;
      LODWORD(v30) = v32;
      DWORD1(v30) = this->gui;
      LODWORD(v33) = v29;
      v38 = v33;
      idRenderModelGui::DrawFilled(
        this: (idRenderModelGui *)DWORD1(v30),
        color: &v39,
        x: (float)v33,
        y: (float)(__int64)v30,
        w: (float)*(__int64 *)((char *)&v30 - 4),
        h: (float)v27);
      HIDWORD(v34) = this->gui;
      HIDWORD(v35) = ((int)v27 - v26) / 2;
      LODWORD(v34) = (HIDWORD(v27) - StringWidth) / 2 + v29;
      LODWORD(v35) = HIDWORD(v35) + v32;
      v38 = v35;
      idRenderModelGui::DrawString(
        this: (idRenderModelGui *)HIDWORD(v34),
        x: (float)v34,
        y: (float)v35,
        string: (const char *)v34,
        defaultColor: (const idVec4 *)(((int)v27 - v26) >> 1),
        forceColor: (bool)v44.data,
        scale: 1.0);
      idStr::FreeData(this: &v44);
    }
  }
}


// ========================================================================
// __unwind$238435
// EA  : 0x8266FA40
// RVA : 0x0066FA40
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void _unwind_238435()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// `dynamic initializer for 'com_allowConsole''
// EA  : 0x8333A8A0
// RVA : 0x0133A8A0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_allowConsole__()
{
  idCVar::idCVar(
    this: &com_allowConsole,
    name: "com_allowConsole",
    value: "0",
    flags: 1,
    description: "allow toggling console with the tilde key",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_allowConsole__);
}


// ========================================================================
// `dynamic initializer for 'com_timer''
// EA  : 0x8333A8F8
// RVA : 0x0133A8F8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_timer__()
{
  idCVar::idCVar(
    this: &com_timer,
    name: "com_timer",
    value: "0",
    flags: 2,
    description: "replaces FPS with a seconds counter, set to -1 to start, set to 0 to turn off",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_timer__);
}


// ========================================================================
// `dynamic initializer for 'com_showFPS''
// EA  : 0x8333A950
// RVA : 0x0133A950
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_showFPS__()
{
  idCVar::idCVar(
    this: &com_showFPS,
    name: "com_showFPS",
    value: "0",
    flags: 65538,
    description: "show frames rendered per second",
    valueMin: 0.0,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)&unk_821D0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_showFPS__);
}


// ========================================================================
// `dynamic initializer for 'com_showWarningDisplay''
// EA  : 0x8333A9B8
// RVA : 0x0133A9B8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_showWarningDisplay__()
{
  idCVar::idCVar(
    this: &com_showWarningDisplay,
    name: "com_showWarningDisplay",
    value: "1",
    flags: 1,
    description: "show warning display",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_showWarningDisplay__);
}


// ========================================================================
// `dynamic initializer for 'com_showMemoryUsage''
// EA  : 0x8333AA10
// RVA : 0x0133AA10
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_showMemoryUsage__()
{
  idCVar::idCVar(
    this: &com_showMemoryUsage,
    name: "com_showMemoryUsage",
    value: "2",
    flags: 65538,
    description: "show memory usage. 1 = always, 2 = fc low warnings + with com_showFPS, 3 = only with com_showFPS",
    valueMin: 0.0,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))off_82010000,
    a9: (int)&unk_821D0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_showMemoryUsage__);
}


// ========================================================================
// `dynamic initializer for 's_showSounds''
// EA  : 0x8333AA78
// RVA : 0x0133AA78
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_showSounds__()
{
  idCVar::idCVar(
    this: &s_showSounds,
    name: "s_showSounds",
    value: "0",
    flags: 2,
    description: "draw sound information on the hud. negative = a specific emitter",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_showSounds__);
}


// ========================================================================
// `dynamic initializer for 's_showSoundsFreeze''
// EA  : 0x8333AAD0
// RVA : 0x0133AAD0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_showSoundsFreeze__()
{
  idCVar::idCVar(
    this: &s_showSoundsFreeze,
    name: "s_showSoundsFreeze",
    value: "0",
    flags: 2,
    description: "freeze the showSound output while 1",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_showSoundsFreeze__);
}


// ========================================================================
// `dynamic initializer for 's_showSoundsFilter''
// EA  : 0x8333AB28
// RVA : 0x0133AB28
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_showSoundsFilter__()
{
  idCVar::idCVar(
    this: &s_showSoundsFilter,
    name: "s_showSoundsFilter",
    value: &byte_8200D768,
    flags: 0,
    description: "filter s_showSounds data by name based on this string",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_showSoundsFilter__);
}


// ========================================================================
// `dynamic initializer for 'com_drawSnapshotMetrics''
// EA  : 0x8333AB80
// RVA : 0x0133AB80
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_drawSnapshotMetrics__()
{
  idCVar::idCVar(
    this: &com_drawSnapshotMetrics,
    name: "com_drawSnapshotMetrics",
    value: "0",
    flags: 2,
    description: "Draw snapshot metrics on screen. 1 = dynamic draw, 2 = static draw, 3 = dynamic raw for largest delta, 4 = draw on fragmentation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_drawSnapshotMetrics__);
}


// ========================================================================
// `dynamic initializer for 'com_drawSnapshotMetricsPeer''
// EA  : 0x8333ABD8
// RVA : 0x0133ABD8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_drawSnapshotMetricsPeer__()
{
  idCVar::idCVar(
    this: &com_drawSnapshotMetricsPeer,
    name: "com_drawSnapshotMetricsPeer",
    value: "0",
    flags: 2,
    description: "Peer to show with com_drawSnapshotMetrics",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_drawSnapshotMetricsPeer__);
}


// ========================================================================
// `dynamic initializer for 'r_consoleTransparency''
// EA  : 0x8333AC30
// RVA : 0x0133AC30
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_consoleTransparency__()
{
  idCVar::idCVar(
    this: &r_consoleTransparency,
    name: "r_consoleTransparency",
    value: "1.0",
    flags: 65540,
    description: "transparency of the console background 0-1",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"DE_LEFT",
    a9: (int)&unk_821D0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_consoleTransparency__);
}


// ========================================================================
// `dynamic initializer for 'g_consoleOverlayBackgroundOpacity''
// EA  : 0x8333AC98
// RVA : 0x0133AC98
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_consoleOverlayBackgroundOpacity__()
{
  idCVar::idCVar(
    this: &g_consoleOverlayBackgroundOpacity,
    name: "g_consoleOverlayBackgroundOpacity",
    value: "0.75",
    flags: 65540,
    description: "opacity scale of text overlay background console windows",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&unk_821D0000,
    a9: (int)&unk_821D0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_consoleOverlayBackgroundOpacity__);
}


// ========================================================================
// `dynamic initializer for 'g_consoleOverlayForegroundOpacity''
// EA  : 0x8333AD00
// RVA : 0x0133AD00
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_consoleOverlayForegroundOpacity__()
{
  idCVar::idCVar(
    this: &g_consoleOverlayForegroundOpacity,
    name: "g_consoleOverlayForegroundOpacity",
    value: "1.0",
    flags: 65540,
    description: "opacity scale of text overlay foreground console windows",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"DE_LEFT",
    a9: (int)&unk_821D0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_consoleOverlayForegroundOpacity__);
}


// ========================================================================
// `dynamic initializer for 'localConsole''
// EA  : 0x8333AD68
// RVA : 0x0133AD68
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__localConsole__()
{
  idConsoleLocal::idConsoleLocal(this: &localConsole);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__localConsole__);
}


// ========================================================================
// `dynamic initializer for 'con_noPrint''
// EA  : 0x8333ADA0
// RVA : 0x0133ADA0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__con_noPrint__()
{
  idCVar::idCVar(
    this: &con_noPrint,
    name: "con_noPrint",
    value: "1",
    flags: 17,
    description: "print on the console but not onscreen when console is pulled up",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__con_noPrint__);
}


// ========================================================================
// `dynamic initializer for 'con_speed''
// EA  : 0x8333ADF8
// RVA : 0x0133ADF8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__con_speed__()
{
  idCVar::idCVar(
    this: &con_speed,
    name: "con_speed",
    value: "3",
    flags: 4,
    description: "speed at which the console moves up and down",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__con_speed__);
}


// ========================================================================
// `dynamic initializer for 'con_notifyTime''
// EA  : 0x8333AE50
// RVA : 0x0133AE50
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__con_notifyTime__()
{
  idCVar::idCVar(
    this: &con_notifyTime,
    name: "con_notifyTime",
    value: "3",
    flags: 4,
    description: "time messages are displayed onscreen when console is pulled up",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__con_notifyTime__);
}


// ========================================================================
// `dynamic initializer for 'com_drawSnapshots''
// EA  : 0x8333AEA8
// RVA : 0x0133AEA8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_drawSnapshots__()
{
  idCVar::idCVar(
    this: &com_drawSnapshots,
    name: "com_drawSnapshots",
    value: "0",
    flags: 2,
    description: "0 = off, 1 = presentables, 2 = sound 3 = all",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_drawSnapshots__);
}


// ========================================================================
// `dynamic initializer for 'com_drawPresentables''
// EA  : 0x8333AF00
// RVA : 0x0133AF00
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_drawPresentables__()
{
  idCVar::idCVar(
    this: &com_drawPresentables,
    name: "com_drawPresentables",
    value: "0",
    flags: 1,
    description: "0 = off, 1 = draw all presentables we know about.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_drawPresentables__);
}


// ========================================================================
// `dynamic initializer for 'con_fontSize''
// EA  : 0x8333AF58
// RVA : 0x0133AF58
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__con_fontSize__()
{
  idCVar::idCVar(
    this: &con_fontSize,
    name: "con_fontSize",
    value: "10",
    flags: 4,
    description: "Use con_fontName at this many pixels wide per char",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__con_fontSize__);
}


// ========================================================================
// `dynamic initializer for 'con_logThreadSpeeds''
// EA  : 0x8333AFB0
// RVA : 0x0133AFB0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__con_logThreadSpeeds__()
{
  idCVar::idCVar(
    this: &con_logThreadSpeeds,
    name: "con_logThreadSpeeds",
    value: "0",
    flags: 1,
    description: "log the thread speeds for offline graphing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__con_logThreadSpeeds__);
}


// ========================================================================
// `dynamic initializer for 'con_drawVersion''
// EA  : 0x8333B008
// RVA : 0x0133B008
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__con_drawVersion__()
{
  idCVar::idCVar(
    this: &con_drawVersion,
    name: "con_drawVersion",
    value: "0",
    flags: 2,
    description: "0 = 0ff, 1 = draw with opacity background, 2 = draw with solid background",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__con_drawVersion__);
}


// ========================================================================
// `dynamic initializer for 'com_superScriptDLLPath''
// EA  : 0x8333B060
// RVA : 0x0133B060
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_superScriptDLLPath__()
{
  idCVar::idCVar(
    this: &com_superScriptDLLPath,
    name: "com_superScriptDLLPath",
    value: &byte_8200D768,
    flags: 0,
    description: "path for superscript to pull from",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_superScriptDLLPath__);
}


// ========================================================================
// `dynamic initializer for 'clear_v''
// EA  : 0x8333B0B8
// RVA : 0x0133B0B8
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__clear_v__()
{
  return idCommandLink::idCommandLink(
           this: &clear_v,
           cmdName: "clear",
           function: clear_f,
           description: "clears the console",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'print_v''
// EA  : 0x8333B0E0
// RVA : 0x0133B0E0
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__print_v__()
{
  return idCommandLink::idCommandLink(
           this: &print_v,
           cmdName: "print",
           function: print_f,
           description: "Prints the arguments to the console",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'conDump_v''
// EA  : 0x8333B108
// RVA : 0x0133B108
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__conDump_v__()
{
  return idCommandLink::idCommandLink(
           this: &conDump_v,
           cmdName: "conDump",
           function: conDump_f,
           description: "dumps the console text to a file",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'activateConsole_v''
// EA  : 0x8333B130
// RVA : 0x0133B130
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__activateConsole_v__()
{
  return idCommandLink::idCommandLink(
           this: &activateConsole_v,
           cmdName: "activateConsole",
           function: activateConsole_f,
           description: "forces the console down ( or up ) and the desired fraction.. 0.5 is normal 0.2 is shifted",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'logColors''
// EA  : 0x8333B158
// RVA : 0x0133B158
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

int _dynamic_initializer_for__logColors__()
{
  logColors[0].color = idColor::colorWhite;
  logColors[1].color = idColor::colorRed;
  logColors[2].color = idColor::colorGreen;
  logColors[3].color = idColor::colorBlue;
  logColors[4].color = idColor::colorYellow;
  logColors[5].color = idColor::colorMagenta;
  logColors[6].color = idColor::colorCyan;
  logColors[9].color = idColor::colorPink;
  logColors[10].color = idColor::colorBrown;
  logColors[11].color = idColor::colorLtGrey;
  logColors[7].color = idColor::colorOrange;
  logColors[8].color = idColor::colorPurple;
  logColors[12].color = idColor::colorMdGrey;
  logColors[13].color = idColor::colorDkGrey;
  return LODWORD(idColor::colorDkGrey.b);
}


// ========================================================================
// `dynamic initializer for 'reportThreadSpeedLogs_v''
// EA  : 0x8333B508
// RVA : 0x0133B508
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__reportThreadSpeedLogs_v__()
{
  return idCommandLink::idCommandLink(
           this: &reportThreadSpeedLogs_v,
           cmdName: "reportThreadSpeedLogs",
           function: reportThreadSpeedLogs_f,
           description: "Write a file suitable for excel",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'makeConsoleFont_v''
// EA  : 0x8333B530
// RVA : 0x0133B530
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__makeConsoleFont_v__()
{
  return idCommandLink::idCommandLink(
           this: &makeConsoleFont_v,
           cmdName: "makeConsoleFont",
           function: makeConsoleFont_f,
           description: "writes consoleFont.cpp",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'bitmapConsole_v''
// EA  : 0x8333B558
// RVA : 0x0133B558
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__bitmapConsole_v__()
{
  return idCommandLink::idCommandLink(
           this: &bitmapConsole_v,
           cmdName: "bitmapConsole",
           function: bitmapConsole_f,
           description: "tests bitmap console",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'convertToSuperScript_v''
// EA  : 0x8333B580
// RVA : 0x0133B580
// PDB : w:\tech5\engine\framework\console.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__convertToSuperScript_v__()
{
  return idCommandLink::idCommandLink(
           this: &convertToSuperScript_v,
           cmdName: "convertToSuperScript",
           function: convertToSuperScript_f,
           description: "converts a .script file to a .ss file",
           argCompletion: nullptr);
}

