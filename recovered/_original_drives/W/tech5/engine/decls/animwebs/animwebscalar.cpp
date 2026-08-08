
// ========================================================================
// ?Free@idScalarMemBlock@@AAAXXZ
// EA  : 0x825FDA58
// RVA : 0x005FDA58
// PDB : w:\tech5\engine\decls\animwebs\animwebscalar.cpp
// ========================================================================

void __fastcall idScalarMemBlock::Free(idScalarMemBlock *this)
{
  float *floats; // r4

  floats = this->floats;
  this->num = 0;
  if ( floats != nullptr )
  {
    idMem::Free(this: &mem, ptr: floats, align: ALIGN_16);
    this->floats = nullptr;
  }
}


// ========================================================================
// ?SetScalarPtr@idAnimWebScalar@@QAAXPAM@Z
// EA  : 0x825FDAB0
// RVA : 0x005FDAB0
// PDB : w:\tech5\engine\decls\animwebs\animwebscalar.cpp
// ========================================================================

void __fastcall idAnimWebScalar::SetScalarPtr(idAnimWebScalar *this, float *scalar)
{
  if ( scalar != nullptr )
  {
    this->scalarPtr = scalar;
    this->scalarIndex = -1;
  }
}


// ========================================================================
// ?SetIndex@idAnimWebScalar@@QAAXABVidScalarMemBlock@@H@Z
// EA  : 0x825FDAC8
// RVA : 0x005FDAC8
// PDB : w:\tech5\engine\decls\animwebs\animwebscalar.cpp
// ========================================================================

void __fastcall idAnimWebScalar::SetIndex(idAnimWebScalar *this, const idScalarMemBlock *memBlock, __int16 index)
{
  this->scalarIndex = index;
  this->scalarPtr = nullptr;
}


// ========================================================================
// ?Alloc@idScalarMemBlock@@QAAXH@Z
// EA  : 0x825FDAD8
// RVA : 0x005FDAD8
// PDB : w:\tech5\engine\decls\animwebs\animwebscalar.cpp
// ========================================================================

void __fastcall idScalarMemBlock::Alloc(idScalarMemBlock *this, int num_)
{
  float *floats; // r4

  floats = this->floats;
  this->num = 0;
  if ( floats != nullptr )
  {
    idMem::Free(this: &mem, ptr: floats, align: ALIGN_16);
    this->floats = nullptr;
  }
  this->num = num_;
  if ( num_ > 0 )
    this->floats = (float *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\engine\\decls\\AnimWebs\\AnimWebScalar.cpp(28) : TAG_ANIMWEB",
                              size: 4 * num_,
                              tag: TAG_ANIMWEB,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
}


// ========================================================================
// ?Free@idScalarMemBlock@@QAAXAAV?$idList@VidAnimWebScalar@@$04@@@Z
// EA  : 0x825FDB58
// RVA : 0x005FDB58
// PDB : w:\tech5\engine\decls\animwebs\animwebscalar.cpp
// ========================================================================

void __fastcall idScalarMemBlock::Free(idScalarMemBlock *this, idList<idAnimWebScalar,5> *scalars)
{
  int v3; // r11
  int v4; // r10
  idAnimWebScalar *v5; // r9
  float *floats; // r4

  v3 = 0;
  if ( scalars->num > 0 )
  {
    v4 = 0;
    do
    {
      ++v3;
      v5 = &scalars->list[v4++];
      v5->scalarIndex = -1;
    }
    while ( v3 < scalars->num );
  }
  floats = this->floats;
  this->num = 0;
  if ( floats != nullptr )
  {
    idMem::Free(this: &mem, ptr: floats, align: ALIGN_16);
    this->floats = nullptr;
  }
}


// ========================================================================
// ?SetName@idAnimWebScalar@@QAAXPBD@Z
// EA  : 0x825FDBE8
// RVA : 0x005FDBE8
// PDB : w:\tech5\engine\decls\animwebs\animwebscalar.cpp
// ========================================================================

// attributes: thunk
void __fastcall idAnimWebScalar::SetName(idAnimWebScalar *this, const char *name_)
{
  idAtomicString::Set(this: &this->name, str_: name_);
}


// ========================================================================
// ?GetScalar@idAnimWebScalar@@QBAMABVidScalarMemBlock@@@Z
// EA  : 0x825FDBF0
// RVA : 0x005FDBF0
// PDB : w:\tech5\engine\decls\animwebs\animwebscalar.cpp
// ========================================================================

float __fastcall idAnimWebScalar::GetScalar(idAnimWebScalar *this, const idScalarMemBlock *memBlock)
{
  int scalarIndex; // r11
  float *scalarPtr; // r11
  double v4; // fp1

  scalarIndex = this->scalarIndex;
  if ( scalarIndex >= 0 )
  {
    v4 = memBlock->floats[scalarIndex];
  }
  else
  {
    scalarPtr = this->scalarPtr;
    if ( scalarPtr != nullptr )
    {
      v4 = *scalarPtr;
    }
    else
    {
      idLib::Warning(
        fmt: "idAnimWebScalar::GetScalar - Trying to access uninitialized blend variable \"%s\"",
        this->name.str);
      v4 = 0.0;
    }
  }
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?SetScalar@idAnimWebScalar@@QAAXAAVidScalarMemBlock@@M@Z
// EA  : 0x825FDC70
// RVA : 0x005FDC70
// PDB : w:\tech5\engine\decls\animwebs\animwebscalar.cpp
// ========================================================================

void __fastcall idAnimWebScalar::SetScalar(idAnimWebScalar *this, idScalarMemBlock *memBlock, double f)
{
  int scalarIndex; // r11

  scalarIndex = this->scalarIndex;
  if ( scalarIndex >= 0 )
    memBlock->floats[scalarIndex] = f;
  else
    *this->scalarPtr = f;
}


// ========================================================================
// ?Init@idAnimWebScalar@@QAAXPBDEPAM@Z
// EA  : 0x825FDCA0
// RVA : 0x005FDCA0
// PDB : w:\tech5\engine\decls\animwebs\animwebscalar.cpp
// ========================================================================

void __fastcall idAnimWebScalar::Init(idAnimWebScalar *this, const char *name_, unsigned __int8 flags_, float *scalar)
{
  idAtomicString::Set(this: &this->name, str_: name_);
  this->flags = flags_;
  if ( scalar != nullptr )
  {
    this->scalarPtr = scalar;
    this->scalarIndex = -1;
  }
}

