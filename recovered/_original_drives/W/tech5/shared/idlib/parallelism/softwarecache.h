
// ========================================================================
// ??1?$idODSOutputArray@UviewWorldArea_t@@$0IA@@@QAA@XZ
// EA  : 0x828DDB98
// RVA : 0x008DDB98
// PDB : w:\tech5\shared\idlib\parallelism\softwarecache.h
// ========================================================================

void __fastcall idODSOutputArray<viewWorldArea_t,128>::~idODSOutputArray<viewWorldArea_t,128>(
        idODSOutputArray<int,128> *this)
{
  *this->outNum = this->localNum;
}

