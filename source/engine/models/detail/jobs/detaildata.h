#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\detail\jobs\detaildata.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17687; PDB kind: struct.
struct emailData_t
{
  idStr server;
  idStr subject;
  idStr senderName;
  idStr senderEmail;
  idList<idStr,5> recipientEmail;
  idStr body;
  idStr attachment;
};
