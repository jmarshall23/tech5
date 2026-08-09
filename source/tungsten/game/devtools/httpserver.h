#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\devtools\httpserver.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18677; PDB kind: class.
class mgHttpServer : public idSysThread
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18678.
  virtual ~mgHttpServer();
  virtual int Run();

  idTCP incoming;
  idList<mgHttpHandler *,5> handlers;
};
