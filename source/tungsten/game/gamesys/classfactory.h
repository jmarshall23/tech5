#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\gamesys\classfactory.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 4821; PDB kind: struct.
struct IClassFactory : IUnknown
{
  // Recovered virtual interface; IDA vtable ordinal 4822.
  virtual HRESULT QueryInterface(const _GUID *, void **);
  virtual unsigned int AddRef();
  virtual unsigned int Release();
  virtual HRESULT CreateInstance(IUnknown *, const _GUID *, void **);
  virtual HRESULT LockServer(int);


};

// IDA Local Type ordinal 10489; PDB kind: struct.
struct /*VFT*/ IClassFactoryVtbl
{
  HRESULT (__fastcall *QueryInterface)(IClassFactory *, const _GUID *const, void **);
  unsigned int (__fastcall *AddRef)(IClassFactory *);
  unsigned int (__fastcall *Release)(IClassFactory *);
  HRESULT (__fastcall *CreateInstance)(IClassFactory *, IUnknown *, const _GUID *const, void **);
  HRESULT (__fastcall *LockServer)(IClassFactory *, int);
};

// IDA Local Type ordinal 17299; PDB kind: class.
class idClassFactory<idStateData,256,112>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17300.
  virtual ~idClassFactory();

  idList<idStateData *,5> list;
  idList<idStr,5> keyList;
  idHashIndex hashIndex;
};

// IDA Local Type ordinal 17302; PDB kind: class.
class idClassFactory<idStateTransition,1024,111>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17303.
  virtual ~idClassFactory();

  idList<idStateTransition *,5> list;
  idList<idStr,5> keyList;
  idHashIndex hashIndex;
};

// IDA Local Type ordinal 26320; PDB kind: typedef.
typedef IClassFactory *LPCLASSFACTORY;
