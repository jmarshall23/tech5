
// ========================================================================
// ??1idDeclTable@@UAA@XZ
// EA  : 0x8262A630
// RVA : 0x0062A630
// PDB : w:\tech5\engine\decls\decltable.cpp
// ========================================================================

void __fastcall idDeclTable::~idDeclTable(idDeclTable *this)
{
  this->__vftable = (idDeclTable_vtbl *)&idDeclTable::`vftable';
  idParmState::RemoveTable(this: renderThreadParmState, table: this);
  idMem::Free(this: &mem, ptr: this->table, align: ALIGN_16);
  idDecl::~idDecl(this: &this->idDecl);
}


// ========================================================================
// __unwind$219301
// EA  : 0x8262A6A0
// RVA : 0x0062A6A0
// PDB : w:\tech5\engine\decls\decltable.cpp
// ========================================================================

void _unwind_219301()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// ?FreeData@idDeclTable@@UAAXXZ
// EA  : 0x8262A6C8
// RVA : 0x0062A6C8
// PDB : w:\tech5\engine\decls\decltable.cpp
// ========================================================================

void __fastcall idDeclTable::FreeData(idDeclTable *this)
{
  idLookupTable::Clear(this: this->table);
}


// ========================================================================
// ?DefaultDefinition@idDeclTable@@UBAPBDXZ
// EA  : 0x8262A6D0
// RVA : 0x0062A6D0
// PDB : w:\tech5\engine\decls\decltable.cpp
// ========================================================================

const char *__fastcall idDeclTable::DefaultDefinition(idDeclTable *this)
{
  return "{ { 0 } }\n";
}


// ========================================================================
// ??0idDeclTable@@QAA@XZ
// EA  : 0x8262A758
// RVA : 0x0062A758
// PDB : w:\tech5\engine\decls\decltable.cpp
// ========================================================================

idDeclTable *__fastcall idDeclTable::idDeclTable(idDeclTable *this)
{
  float *v2; // r3
  idLookupTable *v3; // r10

  idDecl::idDecl(this: &this->idDecl);
  this->__vftable = (idDeclTable_vtbl *)&idDeclTable::`vftable';
  this->left = 0.0;
  this->right = 1.0;
  v2 = (float *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\engine\\decls\\DeclTable.cpp(20) : TAG_TABLE",
                  size: 0x220u,
                  tag: TAG_TABLE,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
  {
    v2[1] = 0.0;
    v2[2] = 1.0;
    *(_BYTE *)v2 = 0;
    *((_BYTE *)v2 + 1) = 0;
    v3 = (idLookupTable *)v2;
    *((_BYTE *)v2 + 2) = 0;
    v2[135] = 0.0;
    v2[131] = 0.0;
    v2[132] = NAN;
    *((_BYTE *)v2 + 532) = 0;
    v2[134] = 0.0;
  }
  else
  {
    v3 = nullptr;
  }
  this->table = v3;
  return this;
}


// ========================================================================
// __unwind$219672
// EA  : 0x8262A844
// RVA : 0x0062A844
// PDB : w:\tech5\engine\decls\decltable.cpp
// ========================================================================

void _unwind_219672()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 128 + 148));
}


// ========================================================================
// ?Parse@idDeclTable@@UAAXAAVidParser@@@Z
// EA  : 0x8262A878
// RVA : 0x0062A878
// PDB : w:\tech5\engine\decls\decltable.cpp
// ========================================================================

void __fastcall idDeclTable::Parse(idDeclTable *this, idParser *src)
{
  bool v4; // r14
  double v5; // fp29
  double v6; // fp28
  double v7; // fp30
  int v8; // r9
  int v9; // r10
  idLookupTable *v10; // r11
  idLookupTable *v11; // r11
  double min; // fp0
  idLookupTable *v13; // r10
  double max; // fp11
  idLookupTable *v15; // r11
  double v16; // fp31
  idLookupTable *table; // r3
  bool v18; // [sp+50h] [-120h] BYREF
  idLookupTable *v19; // [sp+54h] [-11Ch]
  idToken v20; // [sp+60h] [-110h] BYREF

  v20.len = 0;
  v20.baseBuffer[0] = 0;
  v20.floatvalue = -3.4028235e38;
  v20.intvalue = 0;
  memset(&v20.whiteSpaceStart_p, 0, 12);
  v20.allocedAndFlag = 20;
  v20.data = v20.baseBuffer;
  v4 = false;
  v5 = 1.0e30;
  v6 = -1.0e30;
  v7 = 0.0;
  idLookupTable::Clear(this: this->table);
  if ( idParser::ReadToken(this: src, token: &v20) )
  {
    while ( idStr::Cmp(s1: v20.data, s2: "}") != 0 )
    {
      if ( idStr::Icmp(s1: v20.data, s2: "snap") != 0 )
      {
        if ( idStr::Icmp(s1: v20.data, s2: "clamp") != 0 )
        {
          if ( idStr::Icmp(s1: v20.data, s2: "spline") != 0 )
          {
            if ( idStr::Icmp(s1: v20.data, s2: "max") != 0 )
            {
              if ( idStr::Icmp(s1: v20.data, s2: "min") != 0 )
              {
                if ( idStr::Icmp(s1: v20.data, s2: "left") != 0 )
                {
                  if ( idStr::Icmp(s1: v20.data, s2: "right") != 0 )
                  {
                    if ( idStr::Icmp(s1: v20.data, s2: "{") != 0 )
                    {
                      idParser::Warning(this: src, str: "unknown token '%s'", v20.data);
                    }
                    else
                    {
                      while ( 1 )
                      {
                        v16 = idParser::ParseFloat(this: src, errorFlag: &v18);
                        if ( v18 )
                          break;
                        if ( idParser::CheckTokenString(this: src, string: ":") != 0 )
                        {
                          v7 = v16;
                          v16 = idParser::ParseFloat(this: src, errorFlag: &v18);
                          if ( v18 )
                            break;
                        }
                        table = this->table;
                        if ( table->values.numKnots >= 64 )
                        {
                          idParser::Warning(this: src, str: "more than %d points", 64);
                          goto _M220076;
                        }
                        if ( v16 < v5 )
                          v5 = v16;
                        if ( v16 > v6 )
                          v6 = v16;
                        idLookupTable::AddValue(this: table, t: v7, v: v16);
                        v7 = (float)((float)v7 + (float)1.0);
                        idParser::ReadToken(this: src, token: &v20);
                        if ( idStr::Cmp(s1: v20.data, s2: "}") == 0 )
                          goto LABEL_5;
                        if ( idStr::Cmp(s1: v20.data, s2: ",") != 0 )
                        {
                          idParser::Warning(this: src, str: "expected comma or brace");
                          goto _M220076;
                        }
                      }
                    }
                    goto _M220076;
                  }
                  this->right = idParser::ParseFloat(this: src, errorFlag: nullptr);
                }
                else
                {
                  this->left = idParser::ParseFloat(this: src, errorFlag: nullptr);
                }
              }
              else
              {
                this->table->_min = idParser::ParseFloat(this: src, errorFlag: nullptr);
              }
            }
            else
            {
              this->table->_max = idParser::ParseFloat(this: src, errorFlag: nullptr);
            }
          }
          else
          {
            idLookupTable::SetSpline(this: this->table, b: true);
          }
        }
        else
        {
          v4 = true;
        }
      }
      else
      {
        idLookupTable::SetSnap(this: this->table, b: true);
      }
LABEL_5:
      if ( !idParser::ReadToken(this: src, token: &v20) )
        break;
    }
  }
  if ( v5 < 0.0 || v6 > 1.0 )
  {
    v8 = 0;
    if ( this->table->values.numKnots > 0 )
    {
      v9 = 64;
      do
      {
        ++v8;
        v19 = this->table;
        v10 = v19;
        v19->values.times[v9] = (float)(v19->values.times[v9] - (float)v5)
                              * (float)((float)1.0 / (float)((float)v6 - (float)v5));
        v10->values.changed = true;
        ++v9;
      }
      while ( v8 < this->table->values.numKnots );
    }
    v11 = this->table;
    min = v11->_min;
    v19 = v11;
    v11->_min = (float)((float)min * (float)((float)v6 - (float)v5)) + (float)v5;
    v13 = this->table;
    max = v13->_max;
    v19 = v13;
    v13->_max = (float)((float)max * (float)((float)v6 - (float)v5)) + (float)v5;
  }
  v15 = this->table;
  if ( v15->spline && v15->snap )
  {
    idParser::Warning(this: src, str: "both spline and snap specified, snap ignored");
    idLookupTable::SetSnap(this: this->table, b: false);
  }
  idLookupTable::SetClamp(this: this->table, b: v4);
  idLookupTable::Finalize(this: this->table);
_M220076:
  idStr::FreeData(this: &v20);
}


// ========================================================================
// __unwind$219844
// EA  : 0x8262ACC4
// RVA : 0x0062ACC4
// PDB : w:\tech5\engine\decls\decltable.cpp
// ========================================================================

void _unwind_219844()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 96));
}

