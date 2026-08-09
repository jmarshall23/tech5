#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\superscript\ss_fibers.h
// Recovered logical types: 8
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 4279; PDB kind: struct.
struct _FIBER
{
  void *FiberData;
  void *StackAllocatedBase;
  void *StackBase;
  void *StackLimit;
  _CONTEXT Context;
};

// IDA Local Type ordinal 15999; PDB kind: class.
class idSSFiber : public idSysFiber
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16000.
  virtual ~idSSFiber();
  virtual void Run();

  idSSObject *object;
  int id;
  bool waitingForFSM;
  idList<void *,108> allocations;
};

// IDA Local Type ordinal 17604; PDB kind: class.
class idSSFiber0 : public idSSFiber
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17605.
  virtual ~idSSFiber0();
  virtual void Run();

  void (__fastcall *function)(idSSObject *, void *);
  void *data;
};

// IDA Local Type ordinal 19932; PDB kind: class.
class idSSFiber1<int> : public idSSFiber
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19933.
  virtual ~idSSFiber1();
  virtual void Run();

  void (__fastcall *function)(idSSObject *, int);
  int parameter1;
};

// IDA Local Type ordinal 19934; PDB kind: class.
class idSSFiber2<int,float> : public idSSFiber
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19935.
  virtual ~idSSFiber2();
  virtual void Run();

  void (__fastcall *function)(idSSObject *, int, float);
  int parameter1;
  float parameter2;
};

// IDA Local Type ordinal 19936; PDB kind: class.
class idSSFiber1<char const *> : public idSSFiber
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19937.
  virtual ~idSSFiber1();
  virtual void Run();

  void (__fastcall *function)(idSSObject *, const char *);
  const char *parameter1;
};

// IDA Local Type ordinal 22450; PDB kind: class.
class __declspec(align(4)) idSSFiber3<int,int,bool> : public idSSFiber
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22451.
  virtual ~idSSFiber3();
  virtual void Run();

  void (__fastcall *function)(idSSObject *, int, int, bool);
  int parameter1;
  int parameter2;
  bool parameter3;
};

// IDA Local Type ordinal 25980; PDB kind: typedef.
typedef _FIBER FIBER;
