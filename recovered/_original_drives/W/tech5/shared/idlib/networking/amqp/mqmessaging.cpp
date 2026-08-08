
// ========================================================================
// ?ToFrame@AMQPConnectionStartOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F43D78
// RVA : 0x00F43D78
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionStartOk::ToFrame(AMQPConnectionStartOk *this, idMQFrame *frame)
{
  idMQFrame::WriteTable(this: frame, dict: &this->clientProperties);
  idMQFrame::WriteShortString(this: frame, value: &this->mechanism);
  idMQFrame::WriteString(this: frame, str: &this->response);
  idMQFrame::WriteShortString(this: frame, value: &this->locale);
}


// ========================================================================
// ?Populate@AMQPConnectionSecure@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F43DE0
// RVA : 0x00F43DE0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionSecure::Populate(AMQPConnectionSecureOk *this, idMQFrame *frame)
{
  idMQFrame::ReadString(this: frame, str: (idList<unsigned char,37> *)&this->response);
}


// ========================================================================
// ?ToFrame@AMQPConnectionSecureOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F43DF0
// RVA : 0x00F43DF0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionSecureOk::ToFrame(AMQPConnectionSecureOk *this, idMQFrame *frame)
{
  idMQFrame::WriteString(this: frame, str: &this->response);
}


// ========================================================================
// ?Populate@AMQPConnectionTuneOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F43E00
// RVA : 0x00F43E00
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionTuneOk::Populate(AMQPConnectionTuneOk *this, idMQFrame *frame)
{
  this->channelMax = idMQFrame::ReadUInt16(this: frame);
  this->frameMax = idMQFrame::ReadUInt32(this: frame);
  this->heartbeat = idMQFrame::ReadUInt16(this: frame);
}


// ========================================================================
// ?ToFrame@AMQPConnectionTuneOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F43E58
// RVA : 0x00F43E58
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionTuneOk::ToFrame(
        AMQPConnectionTuneOk *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v15; // r5
  int v16; // r10
  int v17; // r9
  int v18; // r8
  int v19; // r7
  int v20; // r6
  int v21; // r5
  int v22; // [sp+8h] [-68h]
  int v23; // [sp+8h] [-68h]
  int v24; // [sp+8h] [-68h]
  int v25; // [sp+Ch] [-64h]
  int v26; // [sp+Ch] [-64h]
  int v27; // [sp+Ch] [-64h]
  int v28; // [sp+10h] [-60h]
  int v29; // [sp+10h] [-60h]
  int v30; // [sp+10h] [-60h]
  int v31; // [sp+14h] [-5Ch]
  int v32; // [sp+14h] [-5Ch]
  int v33; // [sp+14h] [-5Ch]
  int v34; // [sp+18h] [-58h]
  int v35; // [sp+18h] [-58h]
  int v36; // [sp+18h] [-58h]
  unsigned int v37; // [sp+1Ch] [-54h]
  unsigned __int16 v38; // [sp+1Eh] [-52h]
  unsigned __int16 v39; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->channelMax,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v22,
    a10: v25,
    a11: v28,
    a12: v31,
    a13: v34,
    a14: v38);
  idMQFrame::WriteUInt32(
    this: frame,
    value: this->frameMax,
    a3: v15,
    a4: v14,
    a5: v13,
    a6: v12,
    a7: v11,
    a8: v10,
    a9: v23,
    a10: v26,
    a11: v29,
    a12: v32,
    a13: v35,
    a14: v37);
  idMQFrame::WriteUInt16(
    this: frame,
    value: this->heartbeat,
    a3: v21,
    a4: v20,
    a5: v19,
    a6: v18,
    a7: v17,
    a8: v16,
    a9: v24,
    a10: v27,
    a11: v30,
    a12: v33,
    a13: v36,
    a14: v39);
}


// ========================================================================
// ?ToFrame@AMQPBasicProperties@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F43EB0
// RVA : 0x00F43EB0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicProperties::ToFrame(AMQPBasicProperties *this, idMQFrame *frame)
{
  int v4; // r10
  int v5; // r9
  int v6; // r8
  int v7; // r7
  unsigned __int64 v8; // r6
  __int64 v9; // [sp+8h] [-68h]
  __int64 v10; // [sp+10h] [-60h]
  __int64 v11; // [sp+18h] [-58h]

  idMQFrame::WritePropertyPresence(this: frame, exists: this->b_contentType);
  idMQFrame::WritePropertyPresence(this: frame, exists: this->b_contentEncoding);
  idMQFrame::WritePropertyPresence(this: frame, exists: this->b_headers);
  idMQFrame::WritePropertyPresence(this: frame, exists: this->b_deliveryMode);
  idMQFrame::WritePropertyPresence(this: frame, exists: this->b_priority);
  idMQFrame::WritePropertyPresence(this: frame, exists: this->b_correlationId);
  idMQFrame::WritePropertyPresence(this: frame, exists: this->b_replyTo);
  idMQFrame::WritePropertyPresence(this: frame, exists: this->b_expiration);
  idMQFrame::WritePropertyPresence(this: frame, exists: this->b_messageId);
  idMQFrame::WritePropertyPresence(this: frame, exists: this->b_timestamp);
  idMQFrame::WritePropertyPresence(this: frame, exists: this->b_type);
  idMQFrame::WritePropertyPresence(this: frame, exists: this->b_userId);
  idMQFrame::WritePropertyPresence(this: frame, exists: this->b_appId);
  idMQFrame::WritePropertyPresence(this: frame, exists: this->b_clusterId);
  idMQFrame::FinalizeWritePresence(this: frame);
  if ( this->b_contentType )
    idMQFrame::WriteShortString(this: frame, value: &this->contentType);
  if ( this->b_contentEncoding )
    idMQFrame::WriteShortString(this: frame, value: &this->contentEncoding);
  if ( this->b_headers )
    idMQFrame::WriteTable(this: frame, dict: &this->headers);
  if ( this->b_deliveryMode )
    idMQFrame::WriteByte(
      this: frame,
      value: this->deliveryMode,
      a3: SHIDWORD(v8),
      a4: v8,
      a5: v7,
      a6: v6,
      a7: v5,
      a8: v4,
      a9: SHIDWORD(v9),
      a10: v9,
      a11: SHIDWORD(v10),
      a12: v10,
      a13: SHIDWORD(v11),
      a14: v11);
  if ( this->b_priority )
    idMQFrame::WriteByte(
      this: frame,
      value: this->priority,
      a3: SHIDWORD(v8),
      a4: v8,
      a5: v7,
      a6: v6,
      a7: v5,
      a8: v4,
      a9: SHIDWORD(v9),
      a10: v9,
      a11: SHIDWORD(v10),
      a12: v10,
      a13: SHIDWORD(v11),
      a14: v11);
  if ( this->b_correlationId )
    idMQFrame::WriteShortString(this: frame, value: &this->correlationId);
  if ( this->b_replyTo )
    idMQFrame::WriteShortString(this: frame, value: &this->replyTo);
  if ( this->b_expiration )
    idMQFrame::WriteShortString(this: frame, value: &this->expiration);
  if ( this->b_messageId )
    idMQFrame::WriteShortString(this: frame, value: &this->messageId);
  if ( this->b_timestamp )
    idMQFrame::WriteUInt64(
      this: (idMQFrame *)HIDWORD(this->timestamp),
      a2: this->timestamp,
      value: v8,
      a4: v7,
      a5: v6,
      a6: v5,
      a7: v4,
      a8: v9,
      a9: v10,
      a10: v11);
  if ( this->b_type )
    idMQFrame::WriteShortString(this: frame, value: &this->type);
  if ( this->b_userId )
    idMQFrame::WriteShortString(this: frame, value: &this->userId);
  if ( this->b_appId )
    idMQFrame::WriteShortString(this: frame, value: &this->appId);
  if ( this->b_clusterId )
    idMQFrame::WriteShortString(this: frame, value: &this->clusterId);
}


// ========================================================================
// ?Populate@AMQPConnectionStart@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F440E8
// RVA : 0x00F440E8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionStart::Populate(AMQPConnectionStart *this, idMQFrame *frame)
{
  __int64 v4; // r8
  __int64 v5; // r6
  __int64 v6; // r10
  __int64 v7; // r4
  int v8; // [sp+8h] [-68h]
  int v9; // [sp+Ch] [-64h]
  int v10; // [sp+10h] [-60h]
  int v11; // [sp+14h] [-5Ch]

  this->versionMajor = idMQFrame::ReadByte(this: frame);
  this->versionMinor = idMQFrame::ReadByte(this: frame);
  idMQFrame::ReadTable(this: frame, dict: &this->serverProperties);
  idMQFrame::ReadString(this: frame, str: (idList<unsigned char,37> *)&this->mechanisms);
  idMQFrame::ReadString(this: frame, str: (idList<unsigned char,37> *)&this->locales);
  LODWORD(v6) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v5) = this->versionMinor;
    LODWORD(v7) = this->versionMajor;
    HIDWORD(v7) = "AMQP <<: ConnectionStart major=%d, minor=%d, mechanisms=X, locales=X\n";
    idLib::Printf(fmt: v7, a2: v5, a3: v4, a4: v6, a5: v8, a6: v9, a7: v10, a8: v11);
  }
}


// ========================================================================
// ?ToFrame@AMQPConnectionStart@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44180
// RVA : 0x00F44180
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionStart::ToFrame(
        AMQPConnectionStart *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v15; // r5
  __int64 v16; // r8
  __int64 v17; // r6
  __int64 v18; // r10
  __int64 v19; // r4
  int v20; // [sp+8h] [-68h]
  int v21; // [sp+8h] [-68h]
  int v22; // [sp+8h] [-68h]
  int v23; // [sp+Ch] [-64h]
  int v24; // [sp+Ch] [-64h]
  int v25; // [sp+Ch] [-64h]
  int v26; // [sp+10h] [-60h]
  int v27; // [sp+10h] [-60h]
  int v28; // [sp+10h] [-60h]
  int v29; // [sp+14h] [-5Ch]
  int v30; // [sp+14h] [-5Ch]
  int v31; // [sp+14h] [-5Ch]
  int v32; // [sp+18h] [-58h]
  int v33; // [sp+18h] [-58h]
  unsigned __int8 v34; // [sp+1Fh] [-51h]
  unsigned __int8 v35; // [sp+1Fh] [-51h]

  idMQFrame::WriteByte(
    this: frame,
    value: this->versionMajor,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v20,
    a10: v23,
    a11: v26,
    a12: v29,
    a13: v32,
    a14: v34);
  idMQFrame::WriteByte(
    this: frame,
    value: this->versionMinor,
    a3: v15,
    a4: v14,
    a5: v13,
    a6: v12,
    a7: v11,
    a8: v10,
    a9: v21,
    a10: v24,
    a11: v27,
    a12: v30,
    a13: v33,
    a14: v35);
  idMQFrame::WriteTable(this: frame, dict: &this->serverProperties);
  idMQFrame::WriteString(this: frame, str: &this->mechanisms);
  idMQFrame::WriteString(this: frame, str: &this->locales);
  LODWORD(v18) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v17) = this->versionMinor;
    LODWORD(v19) = this->versionMajor;
    HIDWORD(v19) = "AMQP >>: ConnectionStart major=%d, minor=%d, mechanisms=X, locales=X\n";
    idLib::Printf(fmt: v19, a2: v17, a3: v16, a4: v18, a5: v22, a6: v25, a7: v28, a8: v31);
  }
}


// ========================================================================
// ?Populate@AMQPConnectionTune@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44218
// RVA : 0x00F44218
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionTune::Populate(AMQPConnectionTune *this, idMQFrame *frame)
{
  __int64 v4; // r8
  unsigned __int16 UInt16; // r3
  __int64 v6; // r10
  __int64 v7; // r6
  __int64 v8; // r4
  int v9; // [sp+8h] [-68h]
  int v10; // [sp+Ch] [-64h]
  int v11; // [sp+10h] [-60h]
  int v12; // [sp+14h] [-5Ch]

  this->channelMax = idMQFrame::ReadUInt16(this: frame);
  this->frameMax = idMQFrame::ReadUInt32(this: frame);
  UInt16 = idMQFrame::ReadUInt16(this: frame);
  this->heartbeat = UInt16;
  LODWORD(v6) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v7) = this->frameMax;
    LODWORD(v7) = UInt16;
    LODWORD(v8) = this->channelMax;
    HIDWORD(v8) = "AMQP <<: ConnectionTune channelMax=%d, frameMax=%d, heartbeat=%d\n";
    idLib::Printf(fmt: v8, a2: v7, a3: v4, a4: v6, a5: v9, a6: v10, a7: v11, a8: v12);
  }
}


// ========================================================================
// ?ToFrame@AMQPConnectionTune@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F442A0
// RVA : 0x00F442A0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionTune::ToFrame(
        AMQPConnectionTune *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v15; // r5
  int v16; // r10
  int v17; // r9
  int v18; // r8
  int v19; // r7
  int v20; // r6
  int v21; // r5
  __int64 v22; // r8
  __int64 v23; // r10
  __int64 v24; // r6
  __int64 v25; // r4
  int v26; // [sp+8h] [-68h]
  int v27; // [sp+8h] [-68h]
  int v28; // [sp+8h] [-68h]
  int v29; // [sp+8h] [-68h]
  int v30; // [sp+Ch] [-64h]
  int v31; // [sp+Ch] [-64h]
  int v32; // [sp+Ch] [-64h]
  int v33; // [sp+Ch] [-64h]
  int v34; // [sp+10h] [-60h]
  int v35; // [sp+10h] [-60h]
  int v36; // [sp+10h] [-60h]
  int v37; // [sp+10h] [-60h]
  int v38; // [sp+14h] [-5Ch]
  int v39; // [sp+14h] [-5Ch]
  int v40; // [sp+14h] [-5Ch]
  int v41; // [sp+14h] [-5Ch]
  int v42; // [sp+18h] [-58h]
  int v43; // [sp+18h] [-58h]
  int v44; // [sp+18h] [-58h]
  unsigned int v45; // [sp+1Ch] [-54h]
  unsigned __int16 v46; // [sp+1Eh] [-52h]
  unsigned __int16 v47; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->channelMax,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v26,
    a10: v30,
    a11: v34,
    a12: v38,
    a13: v42,
    a14: v46);
  idMQFrame::WriteUInt32(
    this: frame,
    value: this->frameMax,
    a3: v15,
    a4: v14,
    a5: v13,
    a6: v12,
    a7: v11,
    a8: v10,
    a9: v27,
    a10: v31,
    a11: v35,
    a12: v39,
    a13: v43,
    a14: v45);
  idMQFrame::WriteUInt16(
    this: frame,
    value: this->heartbeat,
    a3: v21,
    a4: v20,
    a5: v19,
    a6: v18,
    a7: v17,
    a8: v16,
    a9: v28,
    a10: v32,
    a11: v36,
    a12: v40,
    a13: v44,
    a14: v47);
  LODWORD(v23) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v24) = this->heartbeat;
    HIDWORD(v24) = this->frameMax;
    HIDWORD(v25) = "AMQP >>: onnectionTune channelMax=%d, frameMax=%d, heartbeat=%d\n";
    LODWORD(v25) = this->channelMax;
    idLib::Printf(fmt: v25, a2: v24, a3: v22, a4: v23, a5: v29, a6: v33, a7: v37, a8: v41);
  }
}


// ========================================================================
// ?ToFrame@AMQPConnectionOpen@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44328
// RVA : 0x00F44328
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionOpen::ToFrame(AMQPConnectionOpen *this, idMQFrame *frame)
{
  __int64 v4; // r8
  __int64 v5; // r10
  __int64 v6; // r6
  __int64 v7; // r4
  int v8; // [sp+8h] [-68h]
  int v9; // [sp+Ch] [-64h]
  int v10; // [sp+10h] [-60h]
  int v11; // [sp+14h] [-5Ch]

  idMQFrame::WriteShortString(this: frame, value: &this->virtualHost);
  idMQFrame::WriteShortString(this: frame, value: &this->capabilities);
  idMQFrame::WriteBool(this: frame, value: this->insist);
  LODWORD(v5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v6) = this->insist;
    HIDWORD(v6) = this->capabilities.data;
    HIDWORD(v7) = "AMQP >>: ConnectionOpenOk virtualHost=%s, capabilities=%s, insist=%d\n";
    LODWORD(v7) = this->virtualHost.data;
    idLib::Printf(fmt: v7, a2: v6, a3: v4, a4: v5, a5: v8, a6: v9, a7: v10, a8: v11);
  }
}


// ========================================================================
// ?ToFrame@AMQPConnectionOpenOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F443B0
// RVA : 0x00F443B0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionOpenOk::ToFrame(AMQPConnectionOpenOk *this, idMQFrame *frame)
{
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r4
  int v7; // [sp+8h] [-58h]
  int v8; // [sp+Ch] [-54h]
  int v9; // [sp+10h] [-50h]
  int v10; // [sp+14h] [-4Ch]

  idMQFrame::WriteShortString(this: frame, value: &this->knownHosts);
  LODWORD(v5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v6) = this->knownHosts.data;
    HIDWORD(v6) = "AMQP >>: ConnectionOpenOk knownHosts=%s\n";
    idLib::Printf(fmt: v6, a2: v4, a3: v3, a4: v5, a5: v7, a6: v8, a7: v9, a8: v10);
  }
}


// ========================================================================
// ?ToFrame@AMQPConnectionRedirect@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44408
// RVA : 0x00F44408
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionRedirect::ToFrame(AMQPConnectionRedirect *this, idMQFrame *frame)
{
  __int64 v4; // r8
  __int64 v5; // r6
  __int64 v6; // r10
  __int64 v7; // r4
  int v8; // [sp+8h] [-68h]
  int v9; // [sp+Ch] [-64h]
  int v10; // [sp+10h] [-60h]
  int v11; // [sp+14h] [-5Ch]

  idMQFrame::WriteShortString(this: frame, value: &this->host);
  idMQFrame::WriteShortString(this: frame, value: &this->knownHosts);
  LODWORD(v6) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v7) = this->knownHosts.data;
    HIDWORD(v7) = "AMQP >>: AMQPConnectionRedirect knownHosts=%s\n";
    idLib::Printf(fmt: v7, a2: v5, a3: v4, a4: v6, a5: v8, a6: v9, a7: v10, a8: v11);
  }
}


// ========================================================================
// ?ToFrame@AMQPConnectionClose@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44478
// RVA : 0x00F44478
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionClose::ToFrame(
        AMQPConnectionClose *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v15; // r5
  int v16; // r10
  int v17; // r9
  int v18; // r8
  int v19; // r7
  int v20; // r6
  int v21; // r5
  __int64 v22; // r8
  __int64 v23; // r10
  __int64 v24; // r6
  __int64 v25; // r4
  int v26; // [sp+8h] [-68h]
  int v27; // [sp+8h] [-68h]
  int v28; // [sp+8h] [-68h]
  int v29; // [sp+8h] [-68h]
  int v30; // [sp+Ch] [-64h]
  int v31; // [sp+Ch] [-64h]
  int v32; // [sp+Ch] [-64h]
  int v33; // [sp+Ch] [-64h]
  int v34; // [sp+10h] [-60h]
  int v35; // [sp+10h] [-60h]
  int v36; // [sp+10h] [-60h]
  int v37; // [sp+10h] [-60h]
  int v38; // [sp+14h] [-5Ch]
  int v39; // [sp+14h] [-5Ch]
  int v40; // [sp+14h] [-5Ch]
  int v41; // [sp+14h] [-5Ch]
  int v42; // [sp+18h] [-58h]
  int v43; // [sp+18h] [-58h]
  int v44; // [sp+18h] [-58h]
  unsigned __int16 v45; // [sp+1Eh] [-52h]
  unsigned __int16 v46; // [sp+1Eh] [-52h]
  unsigned __int16 v47; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->replyCode,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v26,
    a10: v30,
    a11: v34,
    a12: v38,
    a13: v42,
    a14: v45);
  idMQFrame::WriteShortString(this: frame, value: &this->replyText);
  idMQFrame::WriteUInt16(
    this: frame,
    value: this->cId,
    a3: v15,
    a4: v14,
    a5: v13,
    a6: v12,
    a7: v11,
    a8: v10,
    a9: v27,
    a10: v31,
    a11: v35,
    a12: v39,
    a13: v43,
    a14: v46);
  idMQFrame::WriteUInt16(
    this: frame,
    value: this->mId,
    a3: v21,
    a4: v20,
    a5: v19,
    a6: v18,
    a7: v17,
    a8: v16,
    a9: v28,
    a10: v32,
    a11: v36,
    a12: v40,
    a13: v44,
    a14: v47);
  LODWORD(v23) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v22) = this->mId;
    LODWORD(v24) = this->cId;
    HIDWORD(v25) = "AMQP >>: AMQPConnectionClose replyCode=%d, replyText=%s, cId=%d, mId=%d\n";
    HIDWORD(v24) = this->replyText.data;
    LODWORD(v25) = this->replyCode;
    idLib::Printf(fmt: v25, a2: v24, a3: v22, a4: v23, a5: v29, a6: v33, a7: v37, a8: v41);
  }
}


// ========================================================================
// ?Populate@AMQPConnectionCloseOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44510
// RVA : 0x00F44510
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPConnectionCloseOk::Populate(
        AMQPConnectionCloseOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP <<: AMQPConnectionCloseOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?ToFrame@AMQPConnectionCloseOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44538
// RVA : 0x00F44538
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPConnectionCloseOk::ToFrame(
        AMQPConnectionCloseOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP >>: AMQPConnectionCloseOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?ToFrame@AMQPChannelOpen@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44560
// RVA : 0x00F44560
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPChannelOpen::ToFrame(AMQPChannelOpen *this, idMQFrame *frame)
{
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r4
  int v7; // [sp+8h] [-58h]
  int v8; // [sp+Ch] [-54h]
  int v9; // [sp+10h] [-50h]
  int v10; // [sp+14h] [-4Ch]

  idMQFrame::WriteShortString(this: frame, value: &this->oob);
  LODWORD(v5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v6) = this->oob.data;
    HIDWORD(v6) = "AMQP >>: AMQPChannelOpen oob=%s\n";
    idLib::Printf(fmt: v6, a2: v4, a3: v3, a4: v5, a5: v7, a6: v8, a7: v9, a8: v10);
  }
}


// ========================================================================
// ?Populate@AMQPChannelOpenOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F445B8
// RVA : 0x00F445B8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPChannelOpenOk::Populate(
        AMQPChannelOpenOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP <<: AMQPChannelOpenOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?ToFrame@AMQPChannelOpenOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F445E0
// RVA : 0x00F445E0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPChannelOpenOk::ToFrame(
        AMQPChannelOpenOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP >>: AMQPChannelOpenOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?Populate@AMQPChannelFlow@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44608
// RVA : 0x00F44608
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPChannelFlow::Populate(AMQPChannelFlow *this, idMQFrame *frame)
{
  __int64 v3; // r8
  __int64 v4; // r6
  bool Bool; // r3
  __int64 v6; // r10
  __int64 v7; // r4
  int v8; // [sp+8h] [-58h]
  int v9; // [sp+Ch] [-54h]
  int v10; // [sp+10h] [-50h]
  int v11; // [sp+14h] [-4Ch]

  Bool = idMQFrame::ReadBool(this: frame);
  this->active = Bool;
  LODWORD(v6) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v7) = Bool;
    HIDWORD(v7) = "AMQP <<: AMQPChannelFlow active=%d\n";
    idLib::Printf(fmt: v7, a2: v4, a3: v3, a4: v6, a5: v8, a6: v9, a7: v10, a8: v11);
  }
}


// ========================================================================
// ?ToFrame@AMQPChannelFlow@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44660
// RVA : 0x00F44660
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPChannelFlow::ToFrame(AMQPChannelFlow *this, idMQFrame *frame)
{
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r4
  int v7; // [sp+8h] [-58h]
  int v8; // [sp+Ch] [-54h]
  int v9; // [sp+10h] [-50h]
  int v10; // [sp+14h] [-4Ch]

  idMQFrame::WriteBool(this: frame, value: this->active);
  LODWORD(v5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v6) = this->active;
    HIDWORD(v6) = "AMQP >>: AMQPChannelFlow active=%d\n";
    idLib::Printf(fmt: v6, a2: v4, a3: v3, a4: v5, a5: v7, a6: v8, a7: v9, a8: v10);
  }
}


// ========================================================================
// ?Populate@AMQPChannelFlowOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F446B8
// RVA : 0x00F446B8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPChannelFlowOk::Populate(AMQPChannelFlowOk *this, idMQFrame *frame)
{
  __int64 v3; // r8
  __int64 v4; // r6
  bool Bool; // r3
  __int64 v6; // r10
  __int64 v7; // r4
  int v8; // [sp+8h] [-58h]
  int v9; // [sp+Ch] [-54h]
  int v10; // [sp+10h] [-50h]
  int v11; // [sp+14h] [-4Ch]

  Bool = idMQFrame::ReadBool(this: frame);
  this->active = Bool;
  LODWORD(v6) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v7) = Bool;
    HIDWORD(v7) = "AMQP <<: AMQPChannelFlowOk activie=%d\n";
    idLib::Printf(fmt: v7, a2: v4, a3: v3, a4: v6, a5: v8, a6: v9, a7: v10, a8: v11);
  }
}


// ========================================================================
// ?ToFrame@AMQPChannelFlowOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44710
// RVA : 0x00F44710
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPChannelFlowOk::ToFrame(AMQPChannelFlowOk *this, idMQFrame *frame)
{
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r4
  int v7; // [sp+8h] [-58h]
  int v8; // [sp+Ch] [-54h]
  int v9; // [sp+10h] [-50h]
  int v10; // [sp+14h] [-4Ch]

  idMQFrame::WriteBool(this: frame, value: this->active);
  LODWORD(v5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v6) = this->active;
    HIDWORD(v6) = "AMQP >>: AMQPChannelFlowOk active=%d\n";
    idLib::Printf(fmt: v6, a2: v4, a3: v3, a4: v5, a5: v7, a6: v8, a7: v9, a8: v10);
  }
}


// ========================================================================
// ?ToFrame@AMQPChannelAlert@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44768
// RVA : 0x00F44768
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPChannelAlert::ToFrame(
        AMQPChannelAlert *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v10; // r8
  __int64 v11; // r6
  __int64 v12; // r10
  __int64 v13; // r4
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+Ch] [-64h]
  int v18; // [sp+10h] [-60h]
  int v19; // [sp+10h] [-60h]
  int v20; // [sp+14h] [-5Ch]
  int v21; // [sp+14h] [-5Ch]
  int v22; // [sp+18h] [-58h]
  unsigned __int16 v23; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->replyCode,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v14,
    a10: v16,
    a11: v18,
    a12: v20,
    a13: v22,
    a14: v23);
  idMQFrame::WriteShortString(this: frame, value: &this->replyText);
  idMQFrame::WriteTable(this: frame, dict: &this->details);
  LODWORD(v12) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v11) = this->replyText.data;
    LODWORD(v13) = this->replyCode;
    HIDWORD(v13) = "AMQP >>: AMQPChannelAlert replyCode=%d, replyText=%s, details=X\n";
    idLib::Printf(fmt: v13, a2: v11, a3: v10, a4: v12, a5: v15, a6: v17, a7: v19, a8: v21);
  }
}


// ========================================================================
// ?ToFrame@AMQPChannelClose@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F447E8
// RVA : 0x00F447E8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPChannelClose::ToFrame(
        AMQPChannelClose *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v15; // r5
  int v16; // r10
  int v17; // r9
  int v18; // r8
  int v19; // r7
  int v20; // r6
  int v21; // r5
  __int64 v22; // r8
  __int64 v23; // r10
  __int64 v24; // r6
  __int64 v25; // r4
  int v26; // [sp+8h] [-68h]
  int v27; // [sp+8h] [-68h]
  int v28; // [sp+8h] [-68h]
  int v29; // [sp+8h] [-68h]
  int v30; // [sp+Ch] [-64h]
  int v31; // [sp+Ch] [-64h]
  int v32; // [sp+Ch] [-64h]
  int v33; // [sp+Ch] [-64h]
  int v34; // [sp+10h] [-60h]
  int v35; // [sp+10h] [-60h]
  int v36; // [sp+10h] [-60h]
  int v37; // [sp+10h] [-60h]
  int v38; // [sp+14h] [-5Ch]
  int v39; // [sp+14h] [-5Ch]
  int v40; // [sp+14h] [-5Ch]
  int v41; // [sp+14h] [-5Ch]
  int v42; // [sp+18h] [-58h]
  int v43; // [sp+18h] [-58h]
  int v44; // [sp+18h] [-58h]
  unsigned __int16 v45; // [sp+1Eh] [-52h]
  unsigned __int16 v46; // [sp+1Eh] [-52h]
  unsigned __int16 v47; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->replyCode,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v26,
    a10: v30,
    a11: v34,
    a12: v38,
    a13: v42,
    a14: v45);
  idMQFrame::WriteShortString(this: frame, value: &this->replyText);
  idMQFrame::WriteUInt16(
    this: frame,
    value: this->cId,
    a3: v15,
    a4: v14,
    a5: v13,
    a6: v12,
    a7: v11,
    a8: v10,
    a9: v27,
    a10: v31,
    a11: v35,
    a12: v39,
    a13: v43,
    a14: v46);
  idMQFrame::WriteUInt16(
    this: frame,
    value: this->mId,
    a3: v21,
    a4: v20,
    a5: v19,
    a6: v18,
    a7: v17,
    a8: v16,
    a9: v28,
    a10: v32,
    a11: v36,
    a12: v40,
    a13: v44,
    a14: v47);
  LODWORD(v23) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v22) = this->mId;
    LODWORD(v24) = this->cId;
    HIDWORD(v25) = "AMQP >>: AMQPChannelClose replyCode=%d, replyText=%s, cId=%d, mId=%d\n";
    HIDWORD(v24) = this->replyText.data;
    LODWORD(v25) = this->replyCode;
    idLib::Printf(fmt: v25, a2: v24, a3: v22, a4: v23, a5: v29, a6: v33, a7: v37, a8: v41);
  }
}


// ========================================================================
// ?Populate@AMQPChannelCloseOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44880
// RVA : 0x00F44880
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPChannelCloseOk::Populate(
        AMQPChannelCloseOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP <<: AMQPChannelCloseOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?ToFrame@AMQPChannelCloseOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F448A8
// RVA : 0x00F448A8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPChannelCloseOk::ToFrame(
        AMQPChannelCloseOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP >>: AMQPChannelCloseOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?ToFrame@AMQPExchangeDeclare@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F448D0
// RVA : 0x00F448D0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPExchangeDeclare::ToFrame(
        AMQPExchangeDeclare *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v10; // r10
  __int64 v11; // r4
  __int64 v12; // r8
  __int64 v13; // r6
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+Ch] [-64h]
  int v18; // [sp+10h] [-60h]
  int v19; // [sp+10h] [-60h]
  int v20; // [sp+14h] [-5Ch]
  int v21; // [sp+14h] [-5Ch]
  int v22; // [sp+18h] [-58h]
  unsigned __int16 v23; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->ticket,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v14,
    a10: v16,
    a11: v18,
    a12: v20,
    a13: v22,
    a14: v23);
  idMQFrame::WriteShortString(this: frame, value: &this->exchange);
  idMQFrame::WriteShortString(this: frame, value: &this->type);
  idMQFrame::WriteBool(this: frame, value: this->passive);
  idMQFrame::WriteBool(this: frame, value: this->durable);
  idMQFrame::WriteBool(this: frame, value: this->autoDelete);
  idMQFrame::WriteBool(this: frame, value: this->isInternal);
  idMQFrame::WriteBool(this: frame, value: this->noWait);
  idMQFrame::WriteTable(this: frame, dict: &this->arguments);
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v10) = this->isInternal;
    HIDWORD(v11) = "AMQP >>: AMQPExchangeDeclare ticket=%d, exchange=%s, type=%s, passive=%d, durable=%d, autoDelete=%d, "
                   "isInternal=%d, noWait=%d, arguments=X\n";
    HIDWORD(v10) = this->autoDelete;
    LODWORD(v12) = this->durable;
    HIDWORD(v12) = this->passive;
    LODWORD(v13) = this->type.data;
    HIDWORD(v13) = this->exchange.data;
    LODWORD(v11) = this->ticket;
    idLib::Printf(fmt: v11, a2: v13, a3: v12, a4: v10, a5: v15, a6: v17, a7: v19, a8: v21);
  }
}


// ========================================================================
// ?Populate@AMQPExchangeDeclareOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F449B8
// RVA : 0x00F449B8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPExchangeDeclareOk::Populate(
        AMQPExchangeDeclareOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP <<: AMQPExchangeDeclareOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?ToFrame@AMQPExchangeDeclareOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F449E0
// RVA : 0x00F449E0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPExchangeDeclareOk::ToFrame(
        AMQPExchangeDeclareOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP >>: AMQPExchangeDeclareOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?ToFrame@AMQPExchangeDelete@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44A08
// RVA : 0x00F44A08
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPExchangeDelete::ToFrame(
        AMQPExchangeDelete *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v10; // r8
  __int64 v11; // r10
  __int64 v12; // r6
  __int64 v13; // r4
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+Ch] [-64h]
  int v18; // [sp+10h] [-60h]
  int v19; // [sp+10h] [-60h]
  int v20; // [sp+14h] [-5Ch]
  int v21; // [sp+14h] [-5Ch]
  int v22; // [sp+18h] [-58h]
  unsigned __int16 v23; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->ticket,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v14,
    a10: v16,
    a11: v18,
    a12: v20,
    a13: v22,
    a14: v23);
  idMQFrame::WriteShortString(this: frame, value: &this->exchange);
  idMQFrame::WriteBool(this: frame, value: this->unused);
  idMQFrame::WriteBool(this: frame, value: this->noWait);
  LODWORD(v11) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v10) = this->noWait;
    LODWORD(v12) = this->unused;
    HIDWORD(v13) = "AMQP >>: AMQPExchangeDelete ticket=%d, exchange=%s, unused=%d, noWait=%d\n";
    HIDWORD(v12) = this->exchange.data;
    LODWORD(v13) = this->ticket;
    idLib::Printf(fmt: v13, a2: v12, a3: v10, a4: v11, a5: v15, a6: v17, a7: v19, a8: v21);
  }
}


// ========================================================================
// ?Populate@AMQPExchangeDeleteOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44AA0
// RVA : 0x00F44AA0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPExchangeDeleteOk::Populate(
        AMQPExchangeDeleteOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP <<: AMQPExchangeDeleteOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?ToFrame@AMQPExchangeDeleteOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44AC8
// RVA : 0x00F44AC8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPExchangeDeleteOk::ToFrame(
        AMQPExchangeDeleteOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP >>: AMQPExchangeDeleteOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?ToFrame@AMQPQueueDeclare@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44AF0
// RVA : 0x00F44AF0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPQueueDeclare::ToFrame(
        AMQPQueueDeclare *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v10; // r10
  __int64 v11; // r4
  __int64 v12; // r8
  __int64 v13; // r6
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+Ch] [-64h]
  int v18; // [sp+10h] [-60h]
  int v19; // [sp+10h] [-60h]
  int v20; // [sp+14h] [-5Ch]
  int v21; // [sp+14h] [-5Ch]
  int v22; // [sp+18h] [-58h]
  unsigned __int16 v23; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->ticket,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v14,
    a10: v16,
    a11: v18,
    a12: v20,
    a13: v22,
    a14: v23);
  idMQFrame::WriteShortString(this: frame, value: &this->queue);
  idMQFrame::WriteBool(this: frame, value: this->passive);
  idMQFrame::WriteBool(this: frame, value: this->durable);
  idMQFrame::WriteBool(this: frame, value: this->exclusive);
  idMQFrame::WriteBool(this: frame, value: this->autoDelete);
  idMQFrame::WriteBool(this: frame, value: this->noWait);
  idMQFrame::WriteTable(this: frame, dict: &this->arguments);
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v10) = this->noWait;
    HIDWORD(v10) = this->autoDelete;
    HIDWORD(v11) = "AMQP >>: AMQPQueueDeclare ticket=%d, queue=%s, passive=%d, durable=%d, exclusive=%d, autoDelete=%d, n"
                   "oWait=%d, arguments=X\n";
    LODWORD(v12) = this->exclusive;
    HIDWORD(v12) = this->durable;
    LODWORD(v13) = this->passive;
    HIDWORD(v13) = this->queue.data;
    LODWORD(v11) = this->ticket;
    idLib::Printf(fmt: v11, a2: v13, a3: v12, a4: v10, a5: v15, a6: v17, a7: v19, a8: v21);
  }
}


// ========================================================================
// ?ToFrame@AMQPQueueDeclareOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44BC0
// RVA : 0x00F44BC0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPQueueDeclareOk::ToFrame(AMQPQueueDeclareOk *this, idMQFrame *frame)
{
  int v4; // r10
  int v5; // r9
  int v6; // r8
  int v7; // r7
  int v8; // r6
  int v9; // r5
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v15; // r5
  __int64 v16; // r8
  __int64 v17; // r10
  __int64 v18; // r4
  int v19; // [sp+8h] [-68h]
  int v20; // [sp+8h] [-68h]
  int v21; // [sp+8h] [-68h]
  int v22; // [sp+Ch] [-64h]
  int v23; // [sp+Ch] [-64h]
  int v24; // [sp+Ch] [-64h]
  int v25; // [sp+10h] [-60h]
  int v26; // [sp+10h] [-60h]
  int v27; // [sp+10h] [-60h]
  int v28; // [sp+14h] [-5Ch]
  int v29; // [sp+14h] [-5Ch]
  int v30; // [sp+14h] [-5Ch]
  int v31; // [sp+18h] [-58h]
  int v32; // [sp+18h] [-58h]
  unsigned int v33; // [sp+1Ch] [-54h]
  unsigned int v34; // [sp+1Ch] [-54h]

  idMQFrame::WriteShortString(this: frame, value: &this->queue);
  idMQFrame::WriteUInt32(
    this: frame,
    value: this->messageCount,
    a3: v9,
    a4: v8,
    a5: v7,
    a6: v6,
    a7: v5,
    a8: v4,
    a9: v19,
    a10: v22,
    a11: v25,
    a12: v28,
    a13: v31,
    a14: v33);
  idMQFrame::WriteUInt32(
    this: frame,
    value: this->consumerCount,
    a3: v15,
    a4: v14,
    a5: v13,
    a6: v12,
    a7: v11,
    a8: v10,
    a9: v20,
    a10: v23,
    a11: v26,
    a12: v29,
    a13: v32,
    a14: v34);
  LODWORD(v17) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v18) = "AMQP >>: AMQPQueueDeclareOk queue=%s, messageCount=%d, consumerCount=%d\n";
    LODWORD(v18) = this->queue.data;
    idLib::Printf(fmt: v18, a2: *(_QWORD *)&this->messageCount, a3: v16, a4: v17, a5: v21, a6: v24, a7: v27, a8: v30);
  }
}


// ========================================================================
// ?ToFrame@AMQPQueueBind@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44C48
// RVA : 0x00F44C48
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPQueueBind::ToFrame(
        AMQPQueueBind *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r4
  __int64 v13; // r6
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+Ch] [-64h]
  int v18; // [sp+10h] [-60h]
  int v19; // [sp+10h] [-60h]
  int v20; // [sp+14h] [-5Ch]
  int v21; // [sp+14h] [-5Ch]
  int v22; // [sp+18h] [-58h]
  unsigned __int16 v23; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->ticket,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v14,
    a10: v16,
    a11: v18,
    a12: v20,
    a13: v22,
    a14: v23);
  idMQFrame::WriteShortString(this: frame, value: &this->queue);
  idMQFrame::WriteShortString(this: frame, value: &this->exchange);
  idMQFrame::WriteShortString(this: frame, value: &this->routingKey);
  idMQFrame::WriteBool(this: frame, value: this->noWait);
  idMQFrame::WriteTable(this: frame, dict: &this->arguments);
  LODWORD(v10) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v11) = this->noWait;
    HIDWORD(v11) = this->routingKey.data;
    HIDWORD(v12) = "AMQP >>: AMQPQueueBind ticket=%d, queue=%s, exchange=%s, routingKey=%s, noWait=%d, arguments=X\n";
    LODWORD(v13) = this->exchange.data;
    HIDWORD(v13) = this->queue.data;
    LODWORD(v12) = this->ticket;
    idLib::Printf(fmt: v12, a2: v13, a3: v11, a4: v10, a5: v15, a6: v17, a7: v19, a8: v21);
  }
}


// ========================================================================
// ?Populate@AMQPQueueBindOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44CF8
// RVA : 0x00F44CF8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPQueueBindOk::Populate(
        AMQPQueueBindOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP <<: AMQPQueueBindOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?ToFrame@AMQPQueueBindOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44D20
// RVA : 0x00F44D20
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPQueueBindOk::ToFrame(
        AMQPQueueBindOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP >>: AMQPQueueBindOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?ToFrame@AMQPQueueUnbind@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44D48
// RVA : 0x00F44D48
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPQueueUnbind::ToFrame(
        AMQPQueueUnbind *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v10; // r8
  __int64 v11; // r10
  __int64 v12; // r6
  __int64 v13; // r4
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+Ch] [-64h]
  int v18; // [sp+10h] [-60h]
  int v19; // [sp+10h] [-60h]
  int v20; // [sp+14h] [-5Ch]
  int v21; // [sp+14h] [-5Ch]
  int v22; // [sp+18h] [-58h]
  unsigned __int16 v23; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->ticket,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v14,
    a10: v16,
    a11: v18,
    a12: v20,
    a13: v22,
    a14: v23);
  idMQFrame::WriteShortString(this: frame, value: &this->queue);
  idMQFrame::WriteShortString(this: frame, value: &this->exchange);
  idMQFrame::WriteShortString(this: frame, value: &this->routingKey);
  idMQFrame::WriteTable(this: frame, dict: &this->arguments);
  LODWORD(v11) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v10) = this->routingKey.data;
    LODWORD(v12) = this->exchange.data;
    HIDWORD(v13) = "AMQP >>: AMQPQueueUnbind ticket=%d, queue=%s, exchange=%s, routingKey=%s, arguments=X\n";
    HIDWORD(v12) = this->queue.data;
    LODWORD(v13) = this->ticket;
    idLib::Printf(fmt: v13, a2: v12, a3: v10, a4: v11, a5: v15, a6: v17, a7: v19, a8: v21);
  }
}


// ========================================================================
// ?Populate@AMQPQueueUnbindOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44DE8
// RVA : 0x00F44DE8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPQueueUnbindOk::Populate(
        AMQPQueueUnbindOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP <<: AMQPQueueUnbindOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?ToFrame@AMQPQueueUnbindOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44E10
// RVA : 0x00F44E10
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPQueueUnbindOk::ToFrame(
        AMQPQueueUnbindOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP >>: AMQPQueueUnbindOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?ToFrame@AMQPQueuePurge@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44E38
// RVA : 0x00F44E38
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPQueuePurge::ToFrame(
        AMQPQueuePurge *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v10; // r8
  __int64 v11; // r10
  __int64 v12; // r6
  __int64 v13; // r4
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+Ch] [-64h]
  int v18; // [sp+10h] [-60h]
  int v19; // [sp+10h] [-60h]
  int v20; // [sp+14h] [-5Ch]
  int v21; // [sp+14h] [-5Ch]
  int v22; // [sp+18h] [-58h]
  unsigned __int16 v23; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->ticket,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v14,
    a10: v16,
    a11: v18,
    a12: v20,
    a13: v22,
    a14: v23);
  idMQFrame::WriteShortString(this: frame, value: &this->queue);
  idMQFrame::WriteBool(this: frame, value: this->noWait);
  LODWORD(v11) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v12) = this->noWait;
    HIDWORD(v12) = this->queue.data;
    HIDWORD(v13) = "AMQP >>: AMQPQueuePurge ticket=%d, queue=%s, noWait=%d\n";
    LODWORD(v13) = this->ticket;
    idLib::Printf(fmt: v13, a2: v12, a3: v10, a4: v11, a5: v15, a6: v17, a7: v19, a8: v21);
  }
}


// ========================================================================
// ?Populate@AMQPQueuePurgeOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44EC0
// RVA : 0x00F44EC0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPQueuePurgeOk::Populate(AMQPQueuePurgeOk *this, idMQFrame *frame)
{
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r4
  __int64 v6; // r10
  int v7; // [sp+8h] [-58h]
  int v8; // [sp+Ch] [-54h]
  int v9; // [sp+10h] [-50h]
  int v10; // [sp+14h] [-4Ch]

  HIDWORD(v5) = idMQFrame::ReadUInt32(this: frame);
  this->messageCount = HIDWORD(v5);
  LODWORD(v5) = HIDWORD(v5);
  LODWORD(v6) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v5) = "AMQP <<: AMQPQueuePurgeOk messageCount=%d\n";
    idLib::Printf(fmt: v5, a2: v4, a3: v3, a4: v6, a5: v7, a6: v8, a7: v9, a8: v10);
  }
}


// ========================================================================
// ?ToFrame@AMQPQueuePurgeOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44F18
// RVA : 0x00F44F18
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPQueuePurgeOk::ToFrame(
        AMQPQueuePurgeOk *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r4
  int v13; // [sp+8h] [-58h]
  int v14; // [sp+8h] [-58h]
  int v15; // [sp+Ch] [-54h]
  int v16; // [sp+Ch] [-54h]
  int v17; // [sp+10h] [-50h]
  int v18; // [sp+10h] [-50h]
  int v19; // [sp+14h] [-4Ch]
  int v20; // [sp+14h] [-4Ch]
  int v21; // [sp+18h] [-48h]
  unsigned int v22; // [sp+1Ch] [-44h]

  idMQFrame::WriteUInt32(
    this: frame,
    value: this->messageCount,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v13,
    a10: v15,
    a11: v17,
    a12: v19,
    a13: v21,
    a14: v22);
  LODWORD(v11) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v12) = this->messageCount;
    HIDWORD(v12) = "AMQP >>: AMQPQueuePurgeOk messageCount=%d\n";
    idLib::Printf(fmt: v12, a2: v10, a3: v9, a4: v11, a5: v14, a6: v16, a7: v18, a8: v20);
  }
}


// ========================================================================
// ?ToFrame@AMQPQueueDelete@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F44F70
// RVA : 0x00F44F70
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPQueueDelete::ToFrame(
        AMQPQueueDelete *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r4
  __int64 v13; // r6
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+Ch] [-64h]
  int v18; // [sp+10h] [-60h]
  int v19; // [sp+10h] [-60h]
  int v20; // [sp+14h] [-5Ch]
  int v21; // [sp+14h] [-5Ch]
  int v22; // [sp+18h] [-58h]
  unsigned __int16 v23; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->ticket,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v14,
    a10: v16,
    a11: v18,
    a12: v20,
    a13: v22,
    a14: v23);
  idMQFrame::WriteShortString(this: frame, value: &this->queue);
  idMQFrame::WriteBool(this: frame, value: this->unused);
  idMQFrame::WriteBool(this: frame, value: this->empty);
  idMQFrame::WriteBool(this: frame, value: this->noWait);
  LODWORD(v10) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v11) = this->noWait;
    HIDWORD(v11) = this->empty;
    HIDWORD(v12) = "AMQP >>: AMQPQueueDelete ticket=%d, queue=%s, unused=%d, empty=%d, noWait=%d\n";
    LODWORD(v13) = this->unused;
    HIDWORD(v13) = this->queue.data;
    LODWORD(v12) = this->ticket;
    idLib::Printf(fmt: v12, a2: v13, a3: v11, a4: v10, a5: v15, a6: v17, a7: v19, a8: v21);
  }
}


// ========================================================================
// ?Populate@AMQPQueueDeleteOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45018
// RVA : 0x00F45018
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPQueueDeleteOk::Populate(AMQPQueueDeleteOk *this, idMQFrame *frame)
{
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r4
  __int64 v6; // r10
  int v7; // [sp+8h] [-58h]
  int v8; // [sp+Ch] [-54h]
  int v9; // [sp+10h] [-50h]
  int v10; // [sp+14h] [-4Ch]

  HIDWORD(v5) = idMQFrame::ReadUInt32(this: frame);
  this->messageCount = HIDWORD(v5);
  LODWORD(v5) = HIDWORD(v5);
  LODWORD(v6) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v5) = "AMQP <<: AMQPQueueDeleteOk messageCount=%d\n";
    idLib::Printf(fmt: v5, a2: v4, a3: v3, a4: v6, a5: v7, a6: v8, a7: v9, a8: v10);
  }
}


// ========================================================================
// ?ToFrame@AMQPQueueDeleteOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45070
// RVA : 0x00F45070
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPQueueDeleteOk::ToFrame(
        AMQPQueueDeleteOk *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r4
  int v13; // [sp+8h] [-58h]
  int v14; // [sp+8h] [-58h]
  int v15; // [sp+Ch] [-54h]
  int v16; // [sp+Ch] [-54h]
  int v17; // [sp+10h] [-50h]
  int v18; // [sp+10h] [-50h]
  int v19; // [sp+14h] [-4Ch]
  int v20; // [sp+14h] [-4Ch]
  int v21; // [sp+18h] [-48h]
  unsigned int v22; // [sp+1Ch] [-44h]

  idMQFrame::WriteUInt32(
    this: frame,
    value: this->messageCount,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v13,
    a10: v15,
    a11: v17,
    a12: v19,
    a13: v21,
    a14: v22);
  LODWORD(v11) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v12) = this->messageCount;
    HIDWORD(v12) = "AMQP >>: AMQPQueueDeleteOk messageCount=%d\n";
    idLib::Printf(fmt: v12, a2: v10, a3: v9, a4: v11, a5: v14, a6: v16, a7: v18, a8: v20);
  }
}


// ========================================================================
// ?Populate@AMQPBasicQos@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F450C8
// RVA : 0x00F450C8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicQos::Populate(AMQPBasicQos *this, idMQFrame *frame)
{
  __int64 v4; // r8
  bool Bool; // r3
  __int64 v6; // r10
  __int64 v7; // r6
  __int64 v8; // r4
  int v9; // [sp+8h] [-68h]
  int v10; // [sp+Ch] [-64h]
  int v11; // [sp+10h] [-60h]
  int v12; // [sp+14h] [-5Ch]

  this->prefetchSize = (unsigned __int16)idMQFrame::ReadUInt16(this: frame);
  this->prefetchCount = idMQFrame::ReadUInt16(this: frame);
  Bool = idMQFrame::ReadBool(this: frame);
  LODWORD(v6) = allocationCurrent[242];
  this->isGlobal = Bool;
  HIDWORD(v6) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v7) = this->prefetchCount;
    LODWORD(v7) = Bool;
    LODWORD(v8) = this->prefetchSize;
    HIDWORD(v8) = "AMQP <<: AMQPBasicQos prefetchSize=%d, prefetchCount=%d, isGlobal=%d\n";
    idLib::Printf(fmt: v8, a2: v7, a3: v4, a4: v6, a5: v9, a6: v10, a7: v11, a8: v12);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicQos@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45150
// RVA : 0x00F45150
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicQos::ToFrame(
        AMQPBasicQos *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v15; // r5
  __int64 v16; // r8
  __int64 v17; // r10
  __int64 v18; // r6
  __int64 v19; // r4
  int v20; // [sp+8h] [-68h]
  int v21; // [sp+8h] [-68h]
  int v22; // [sp+8h] [-68h]
  int v23; // [sp+Ch] [-64h]
  int v24; // [sp+Ch] [-64h]
  int v25; // [sp+Ch] [-64h]
  int v26; // [sp+10h] [-60h]
  int v27; // [sp+10h] [-60h]
  int v28; // [sp+10h] [-60h]
  int v29; // [sp+14h] [-5Ch]
  int v30; // [sp+14h] [-5Ch]
  int v31; // [sp+14h] [-5Ch]
  int v32; // [sp+18h] [-58h]
  int v33; // [sp+18h] [-58h]
  unsigned __int16 v34; // [sp+1Eh] [-52h]
  unsigned __int16 v35; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->prefetchSize,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v20,
    a10: v23,
    a11: v26,
    a12: v29,
    a13: v32,
    a14: v34);
  idMQFrame::WriteUInt16(
    this: frame,
    value: this->prefetchCount,
    a3: v15,
    a4: v14,
    a5: v13,
    a6: v12,
    a7: v11,
    a8: v10,
    a9: v21,
    a10: v24,
    a11: v27,
    a12: v30,
    a13: v33,
    a14: v35);
  idMQFrame::WriteBool(this: frame, value: this->isGlobal);
  LODWORD(v17) = allocationCurrent[242];
  HIDWORD(v17) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v18) = this->isGlobal;
    HIDWORD(v18) = this->prefetchCount;
    HIDWORD(v19) = "AMQP >>: AMQPBasicQos prefetchSize=%d, prefetchCount=%d, isGlobal=%d\n";
    LODWORD(v19) = this->prefetchSize;
    idLib::Printf(fmt: v19, a2: v18, a3: v16, a4: v17, a5: v22, a6: v25, a7: v28, a8: v31);
  }
}


// ========================================================================
// ?Populate@AMQPBasicQosOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F451D8
// RVA : 0x00F451D8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPBasicQosOk::Populate(
        AMQPBasicQosOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP <<: AMQPBasicQosOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicQosOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45200
// RVA : 0x00F45200
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPBasicQosOk::ToFrame(
        AMQPBasicQosOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP >>: AMQPBasicQosOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicConsume@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45228
// RVA : 0x00F45228
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicConsume::ToFrame(
        AMQPBasicConsume *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v10; // r10
  __int64 v11; // r4
  __int64 v12; // r8
  __int64 v13; // r6
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+Ch] [-64h]
  int v18; // [sp+10h] [-60h]
  int v19; // [sp+10h] [-60h]
  int v20; // [sp+14h] [-5Ch]
  int v21; // [sp+14h] [-5Ch]
  int v22; // [sp+18h] [-58h]
  unsigned __int16 v23; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->ticket,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v14,
    a10: v16,
    a11: v18,
    a12: v20,
    a13: v22,
    a14: v23);
  idMQFrame::WriteShortString(this: frame, value: &this->queue);
  idMQFrame::WriteShortString(this: frame, value: &this->consumerTag);
  idMQFrame::WriteBool(this: frame, value: this->noLocal);
  idMQFrame::WriteBool(this: frame, value: this->noAck);
  idMQFrame::WriteBool(this: frame, value: this->exclusive);
  idMQFrame::WriteBool(this: frame, value: this->noWait);
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v10) = this->noWait;
    HIDWORD(v10) = this->exclusive;
    HIDWORD(v11) = "AMQP >>: AMQPBasicConsume ticket=%d, queue=%s, consumerTag=%s, noLocal=%d, noAck=%d, exclusive=%d, noWait=%d\n";
    LODWORD(v12) = this->noAck;
    HIDWORD(v12) = this->noLocal;
    LODWORD(v13) = this->consumerTag.data;
    HIDWORD(v13) = this->queue.data;
    LODWORD(v11) = this->ticket;
    idLib::Printf(fmt: v11, a2: v13, a3: v12, a4: v10, a5: v15, a6: v17, a7: v19, a8: v21);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicConsumeOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F452F0
// RVA : 0x00F452F0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicConsumeOk::ToFrame(AMQPBasicConsumeOk *this, idMQFrame *frame)
{
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r4
  int v7; // [sp+8h] [-58h]
  int v8; // [sp+Ch] [-54h]
  int v9; // [sp+10h] [-50h]
  int v10; // [sp+14h] [-4Ch]

  idMQFrame::WriteShortString(this: frame, value: &this->consumerTag);
  LODWORD(v5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v6) = this->consumerTag.data;
    HIDWORD(v6) = "AMQP >>: AMQPBasicConsumeOk consumerTag=%s\n";
    idLib::Printf(fmt: v6, a2: v4, a3: v3, a4: v5, a5: v7, a6: v8, a7: v9, a8: v10);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicCancel@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45348
// RVA : 0x00F45348
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicCancel::ToFrame(AMQPBasicCancel *this, idMQFrame *frame)
{
  __int64 v4; // r8
  __int64 v5; // r6
  __int64 v6; // r10
  __int64 v7; // r4
  int v8; // [sp+8h] [-68h]
  int v9; // [sp+Ch] [-64h]
  int v10; // [sp+10h] [-60h]
  int v11; // [sp+14h] [-5Ch]

  idMQFrame::WriteShortString(this: frame, value: &this->consumerTag);
  idMQFrame::WriteBool(this: frame, value: this->noWait);
  LODWORD(v6) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v5) = this->noWait;
    LODWORD(v7) = this->consumerTag.data;
    HIDWORD(v7) = "AMQP >>: AMQPBasicCancel consumerTag=%s, noWait=%d\n";
    idLib::Printf(fmt: v7, a2: v5, a3: v4, a4: v6, a5: v8, a6: v9, a7: v10, a8: v11);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicCancelOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F453C0
// RVA : 0x00F453C0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicCancelOk::ToFrame(AMQPBasicCancelOk *this, idMQFrame *frame)
{
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r4
  int v7; // [sp+8h] [-58h]
  int v8; // [sp+Ch] [-54h]
  int v9; // [sp+10h] [-50h]
  int v10; // [sp+14h] [-4Ch]

  idMQFrame::WriteShortString(this: frame, value: &this->consumerTag);
  LODWORD(v5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v6) = this->consumerTag.data;
    HIDWORD(v6) = "AMQP >>: AMQPBasicCancelOk consumerTag=%s\n";
    idLib::Printf(fmt: v6, a2: v4, a3: v3, a4: v5, a5: v7, a6: v8, a7: v9, a8: v10);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicPublish@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45418
// RVA : 0x00F45418
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicPublish::ToFrame(
        AMQPBasicPublish *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r4
  __int64 v13; // r6
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+Ch] [-64h]
  int v18; // [sp+10h] [-60h]
  int v19; // [sp+10h] [-60h]
  int v20; // [sp+14h] [-5Ch]
  int v21; // [sp+14h] [-5Ch]
  int v22; // [sp+18h] [-58h]
  unsigned __int16 v23; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->ticket,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v14,
    a10: v16,
    a11: v18,
    a12: v20,
    a13: v22,
    a14: v23);
  idMQFrame::WriteShortString(this: frame, value: &this->exchange);
  idMQFrame::WriteShortString(this: frame, value: &this->routingKey);
  idMQFrame::WriteBool(this: frame, value: this->mandatory);
  idMQFrame::WriteBool(this: frame, value: this->immediate);
  LODWORD(v10) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v11) = this->immediate;
    HIDWORD(v11) = this->mandatory;
    HIDWORD(v12) = "AMQP >>: AMQPBasicPublish ticket=%d, exchange=%s, routingKey=%s, mandatory=%d, immediate=%d\n";
    LODWORD(v13) = this->routingKey.data;
    HIDWORD(v13) = this->exchange.data;
    LODWORD(v12) = this->ticket;
    idLib::Printf(fmt: v12, a2: v13, a3: v11, a4: v10, a5: v15, a6: v17, a7: v19, a8: v21);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicReturn@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F454C0
// RVA : 0x00F454C0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicReturn::ToFrame(
        AMQPBasicReturn *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v10; // r8
  __int64 v11; // r10
  __int64 v12; // r6
  __int64 v13; // r4
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+Ch] [-64h]
  int v18; // [sp+10h] [-60h]
  int v19; // [sp+10h] [-60h]
  int v20; // [sp+14h] [-5Ch]
  int v21; // [sp+14h] [-5Ch]
  int v22; // [sp+18h] [-58h]
  unsigned __int16 v23; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->replyCode,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v14,
    a10: v16,
    a11: v18,
    a12: v20,
    a13: v22,
    a14: v23);
  idMQFrame::WriteShortString(this: frame, value: &this->replyText);
  idMQFrame::WriteShortString(this: frame, value: &this->exchange);
  idMQFrame::WriteShortString(this: frame, value: &this->routingKey);
  LODWORD(v11) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v10) = this->routingKey.data;
    LODWORD(v12) = this->exchange.data;
    HIDWORD(v13) = "AMQP >>: AMQPBasicReturn replyCode=%d, replyText=%s, exchange=%s, routingKey=%s\n";
    HIDWORD(v12) = this->replyText.data;
    LODWORD(v13) = this->replyCode;
    idLib::Printf(fmt: v13, a2: v12, a3: v10, a4: v11, a5: v15, a6: v17, a7: v19, a8: v21);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicDeliver@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45558
// RVA : 0x00F45558
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPBasicDeliver::ToFrame(AMQPBasicDeliver *this, idMQFrame *frame)
{
  int v4; // r10
  int v5; // r9
  int v6; // r8
  int v7; // r7
  unsigned __int64 v8; // r6
  __int64 v9; // r10
  __int64 v10; // r8
  __int128 v11; // r5 OVERLAPPED
  BOOL redelivered; // r6
  __int64 v13; // [sp+8h] [-68h]
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+Ch] [-64h]
  __int64 v16; // [sp+10h] [-60h]
  int v17; // [sp+10h] [-60h]
  int v18; // [sp+14h] [-5Ch]
  __int64 v19; // [sp+18h] [-58h]

  idMQFrame::WriteShortString(this: frame, value: &this->consumerTag);
  idMQFrame::WriteUInt64(
    this: (idMQFrame *)HIDWORD(this->deliveryTag),
    a2: this->deliveryTag,
    value: v8,
    a4: v7,
    a5: v6,
    a6: v5,
    a7: v4,
    a8: v13,
    a9: v16,
    a10: v19);
  idMQFrame::WriteBool(this: frame, value: this->redelivered);
  idMQFrame::WriteShortString(this: frame, value: &this->exchange);
  idMQFrame::WriteShortString(this: frame, value: &this->routingKey);
  LODWORD(v9) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v10) = this->routingKey.data;
    HIDWORD(v10) = this->exchange.data;
    DWORD1(v11) = "AMQP >>: AMQPBasicDeliver consumerTag=%s, deliveryTag=%llu, redelivered=%d, exchange=%s, routingKey=%s\n";
    redelivered = this->redelivered;
    *((_QWORD *)&v11 + 1) = this->deliveryTag;
    DWORD2(v11) = this->consumerTag.data;
    idLib::Printf(
      fmt: *(__int64 *)((char *)&v11 + 4),
      a2: *(__int64 *)((char *)&v11 - 4),
      a3: v10,
      a4: v9,
      a5: v14,
      a6: v15,
      a7: v17,
      a8: v18);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicGet@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45600
// RVA : 0x00F45600
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicGet::ToFrame(
        AMQPBasicGet *this,
        idMQFrame *frame,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v10; // r8
  __int64 v11; // r10
  __int64 v12; // r6
  __int64 v13; // r4
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+Ch] [-64h]
  int v18; // [sp+10h] [-60h]
  int v19; // [sp+10h] [-60h]
  int v20; // [sp+14h] [-5Ch]
  int v21; // [sp+14h] [-5Ch]
  int v22; // [sp+18h] [-58h]
  unsigned __int16 v23; // [sp+1Eh] [-52h]

  idMQFrame::WriteUInt16(
    this: frame,
    value: this->ticket,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v14,
    a10: v16,
    a11: v18,
    a12: v20,
    a13: v22,
    a14: v23);
  idMQFrame::WriteShortString(this: frame, value: &this->queue);
  idMQFrame::WriteBool(this: frame, value: this->noAck);
  LODWORD(v11) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v12) = this->noAck;
    HIDWORD(v12) = this->queue.data;
    HIDWORD(v13) = "AMQP >>: AMQPBasicGet ticket=%d, queue=%s, noAck=%d\n";
    LODWORD(v13) = this->ticket;
    idLib::Printf(fmt: v13, a2: v12, a3: v10, a4: v11, a5: v15, a6: v17, a7: v19, a8: v21);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicGetOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45688
// RVA : 0x00F45688
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicGetOk::ToFrame(
        AMQPBasicGetOk *this,
        idMQFrame *frame,
        unsigned __int64 a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  int v9; // r10
  int v10; // r9
  int v11; // r8
  int v12; // r7
  int v13; // r6
  int v14; // r5
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r6
  __int64 v18; // [sp+8h] [-68h]
  int v19; // [sp+8h] [-68h]
  int v20; // [sp+8h] [-68h]
  int v21; // [sp+Ch] [-64h]
  int v22; // [sp+Ch] [-64h]
  __int64 v23; // [sp+10h] [-60h]
  int v24; // [sp+10h] [-60h]
  int v25; // [sp+10h] [-60h]
  int v26; // [sp+14h] [-5Ch]
  int v27; // [sp+14h] [-5Ch]
  __int64 v28; // [sp+18h] [-58h]
  int v29; // [sp+18h] [-58h]
  unsigned int v30; // [sp+1Ch] [-54h]

  idMQFrame::WriteUInt64(
    this: (idMQFrame *)HIDWORD(this->deliveryTag),
    a2: this->deliveryTag,
    value: a3,
    a4,
    a5,
    a6,
    a7,
    a8: v18,
    a9: v23,
    a10: v28);
  idMQFrame::WriteBool(this: frame, value: this->redelivered);
  idMQFrame::WriteShortString(this: frame, value: &this->exchange);
  idMQFrame::WriteShortString(this: frame, value: &this->routingKey);
  idMQFrame::WriteUInt32(
    this: frame,
    value: this->messageCount,
    a3: v14,
    a4: v13,
    a5: v12,
    a6: v11,
    a7: v10,
    a8: v9,
    a9: v19,
    a10: v21,
    a11: v24,
    a12: v26,
    a13: v29,
    a14: v30);
  LODWORD(v15) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v16) = this->messageCount;
    HIDWORD(v16) = this->routingKey.data;
    LODWORD(v17) = this->exchange.data;
    HIDWORD(v17) = this->redelivered;
    idLib::Printf(fmt: this->deliveryTag, a2: v17, a3: v16, a4: v15, a5: v20, a6: v22, a7: v25, a8: v27);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicGetEmpty@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45730
// RVA : 0x00F45730
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicGetEmpty::ToFrame(AMQPBasicGetEmpty *this, idMQFrame *frame)
{
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r4
  int v7; // [sp+8h] [-58h]
  int v8; // [sp+Ch] [-54h]
  int v9; // [sp+10h] [-50h]
  int v10; // [sp+14h] [-4Ch]

  idMQFrame::WriteShortString(this: frame, value: &this->clusterId);
  LODWORD(v5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v6) = this->clusterId.data;
    HIDWORD(v6) = "AMQP >>: AMQPBasicGetEmpty clusterId=%s\n";
    idLib::Printf(fmt: v6, a2: v4, a3: v3, a4: v5, a5: v7, a6: v8, a7: v9, a8: v10);
  }
}


// ========================================================================
// ?Populate@AMQPBasicAck@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45788
// RVA : 0x00F45788
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicAck::Populate(AMQPBasicAck *this, idMQFrame *frame)
{
  unsigned __int64 v4; // r3
  __int64 v5; // r8
  __int64 v6; // r6
  __int64 v7; // r10
  unsigned __int64 deliveryTag; // r4
  int v9; // [sp+8h] [-68h]
  int v10; // [sp+Ch] [-64h]
  int v11; // [sp+10h] [-60h]
  int v12; // [sp+14h] [-5Ch]

  LODWORD(v4) = idMQFrame::ReadUInt64(this: frame);
  this->deliveryTag = v4;
  this->multiple = idMQFrame::ReadBool(this: frame);
  LODWORD(v7) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    deliveryTag = this->deliveryTag;
    HIDWORD(v6) = (unsigned __int8)HIDWORD(this->deliveryTag);
    HIDWORD(deliveryTag) = "AMQP <<: AMQPBasicAck deliveryTag=%llu, multiple=%d\n";
    idLib::Printf(fmt: deliveryTag, a2: v6, a3: v5, a4: v7, a5: v9, a6: v10, a7: v11, a8: v12);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicAck@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45800
// RVA : 0x00F45800
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicAck::ToFrame(
        AMQPBasicAck *this,
        idMQFrame *frame,
        unsigned __int64 a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r10
  unsigned __int64 deliveryTag; // r4
  __int64 v13; // [sp+8h] [-68h]
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+Ch] [-64h]
  __int64 v16; // [sp+10h] [-60h]
  int v17; // [sp+10h] [-60h]
  int v18; // [sp+14h] [-5Ch]
  __int64 v19; // [sp+18h] [-58h]

  idMQFrame::WriteUInt64(
    this: (idMQFrame *)HIDWORD(this->deliveryTag),
    a2: this->deliveryTag,
    value: a3,
    a4,
    a5,
    a6,
    a7,
    a8: v13,
    a9: v16,
    a10: v19);
  idMQFrame::WriteBool(this: frame, value: this->multiple);
  LODWORD(v11) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v10) = this->multiple;
    deliveryTag = this->deliveryTag;
    HIDWORD(deliveryTag) = "AMQP >>: AMQPBasicAck deliveryTag=%llu, multiple=%d\n";
    idLib::Printf(fmt: deliveryTag, a2: v10, a3: v9, a4: v11, a5: v14, a6: v15, a7: v17, a8: v18);
  }
}


// ========================================================================
// ?Populate@AMQPBasicReject@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45878
// RVA : 0x00F45878
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicReject::Populate(AMQPBasicReject *this, idMQFrame *frame)
{
  unsigned __int64 v4; // r3
  __int64 v5; // r8
  __int64 v6; // r6
  __int64 v7; // r10
  unsigned __int64 deliveryTag; // r4
  int v9; // [sp+8h] [-68h]
  int v10; // [sp+Ch] [-64h]
  int v11; // [sp+10h] [-60h]
  int v12; // [sp+14h] [-5Ch]

  LODWORD(v4) = idMQFrame::ReadUInt64(this: frame);
  this->deliveryTag = v4;
  this->requeue = idMQFrame::ReadBool(this: frame);
  LODWORD(v7) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    deliveryTag = this->deliveryTag;
    HIDWORD(v6) = (unsigned __int8)HIDWORD(this->deliveryTag);
    HIDWORD(deliveryTag) = "AMQP <<: AMQPBasicReject deliveryTag=%llu, requeue=%d\n";
    idLib::Printf(fmt: deliveryTag, a2: v6, a3: v5, a4: v7, a5: v9, a6: v10, a7: v11, a8: v12);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicReject@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F458F0
// RVA : 0x00F458F0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicReject::ToFrame(
        AMQPBasicReject *this,
        idMQFrame *frame,
        unsigned __int64 a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r10
  unsigned __int64 deliveryTag; // r4
  __int64 v13; // [sp+8h] [-68h]
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+Ch] [-64h]
  __int64 v16; // [sp+10h] [-60h]
  int v17; // [sp+10h] [-60h]
  int v18; // [sp+14h] [-5Ch]
  __int64 v19; // [sp+18h] [-58h]

  idMQFrame::WriteUInt64(
    this: (idMQFrame *)HIDWORD(this->deliveryTag),
    a2: this->deliveryTag,
    value: a3,
    a4,
    a5,
    a6,
    a7,
    a8: v13,
    a9: v16,
    a10: v19);
  idMQFrame::WriteBool(this: frame, value: this->requeue);
  LODWORD(v11) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v10) = this->requeue;
    deliveryTag = this->deliveryTag;
    HIDWORD(deliveryTag) = "AMQP >>: AMQPBasicReject deliveryTag=%llu, requeue=%d\n";
    idLib::Printf(fmt: deliveryTag, a2: v10, a3: v9, a4: v11, a5: v14, a6: v15, a7: v17, a8: v18);
  }
}


// ========================================================================
// ?Populate@AMQPBasicRecoverAsync@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45968
// RVA : 0x00F45968
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicRecoverAsync::Populate(AMQPBasicRecoverAsync *this, idMQFrame *frame)
{
  __int64 v3; // r8
  __int64 v4; // r6
  bool Bool; // r3
  __int64 v6; // r10
  __int64 v7; // r4
  int v8; // [sp+8h] [-58h]
  int v9; // [sp+Ch] [-54h]
  int v10; // [sp+10h] [-50h]
  int v11; // [sp+14h] [-4Ch]

  Bool = idMQFrame::ReadBool(this: frame);
  this->requeue = Bool;
  LODWORD(v6) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v7) = Bool;
    HIDWORD(v7) = "AMQP <<: AMQPBasicRecoverAsync requeue=%d\n";
    idLib::Printf(fmt: v7, a2: v4, a3: v3, a4: v6, a5: v8, a6: v9, a7: v10, a8: v11);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicRecoverAsync@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F459C0
// RVA : 0x00F459C0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicRecoverAsync::ToFrame(AMQPBasicRecoverAsync *this, idMQFrame *frame)
{
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r4
  int v7; // [sp+8h] [-58h]
  int v8; // [sp+Ch] [-54h]
  int v9; // [sp+10h] [-50h]
  int v10; // [sp+14h] [-4Ch]

  idMQFrame::WriteBool(this: frame, value: this->requeue);
  LODWORD(v5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v6) = this->requeue;
    HIDWORD(v6) = "AMQP >>: AMQPBasicRecoverAsync requeue=%d\n";
    idLib::Printf(fmt: v6, a2: v4, a3: v3, a4: v5, a5: v7, a6: v8, a7: v9, a8: v10);
  }
}


// ========================================================================
// ?Populate@AMQPBasicRecover@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45A18
// RVA : 0x00F45A18
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicRecover::Populate(AMQPBasicRecover *this, idMQFrame *frame)
{
  __int64 v3; // r8
  __int64 v4; // r6
  bool Bool; // r3
  __int64 v6; // r10
  __int64 v7; // r4
  int v8; // [sp+8h] [-58h]
  int v9; // [sp+Ch] [-54h]
  int v10; // [sp+10h] [-50h]
  int v11; // [sp+14h] [-4Ch]

  Bool = idMQFrame::ReadBool(this: frame);
  this->requeue = Bool;
  LODWORD(v6) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v7) = Bool;
    HIDWORD(v7) = "AMQP <<: AMQPBasicRecover requeue=%d\n";
    idLib::Printf(fmt: v7, a2: v4, a3: v3, a4: v6, a5: v8, a6: v9, a7: v10, a8: v11);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicRecover@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45A70
// RVA : 0x00F45A70
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicRecover::ToFrame(AMQPBasicRecover *this, idMQFrame *frame)
{
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r4
  int v7; // [sp+8h] [-58h]
  int v8; // [sp+Ch] [-54h]
  int v9; // [sp+10h] [-50h]
  int v10; // [sp+14h] [-4Ch]

  idMQFrame::WriteBool(this: frame, value: this->requeue);
  LODWORD(v5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v6) = this->requeue;
    HIDWORD(v6) = "AMQP >>: AMQPBasicRecover requeue=%d\n";
    idLib::Printf(fmt: v6, a2: v4, a3: v3, a4: v5, a5: v7, a6: v8, a7: v9, a8: v10);
  }
}


// ========================================================================
// ?Populate@AMQPBasicRecoverOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45AC8
// RVA : 0x00F45AC8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPBasicRecoverOk::Populate(
        AMQPBasicRecoverOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP <<: AMQPBasicRecoverOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?ToFrame@AMQPBasicRecoverOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45AF0
// RVA : 0x00F45AF0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPBasicRecoverOk::ToFrame(
        AMQPBasicRecoverOk *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const char *v9; // r3

  LODWORD(a5) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    v9 = "AMQP >>: AMQPBasicRecoverOk\n";
    idLib::Printf(fmt: *(__int64 *)&frame, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?Populate@AMQPConnectionStartOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45B20
// RVA : 0x00F45B20
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionStartOk::Populate(AMQPConnectionStartOk *this, idMQFrame *frame)
{
  idMQFrame *ShortString; // r28
  size_t v5; // r29
  idMQFrame *v6; // r27
  size_t v7; // r29
  idMQFrame v8[2]; // [sp+50h] [-70h] BYREF

  idMQFrame::ReadTable(this: frame, dict: &this->clientProperties);
  ShortString = idMQFrame::ReadShortString(this: v8, result: (idStr *)frame);
  v5 = *(_DWORD *)&ShortString->type;
  idStr::EnsureAlloced(
    this: &this->mechanism,
    amount: *(_DWORD *)&ShortString->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->mechanism.data, Src: ShortString->data.list, Size: v5);
  this->mechanism.data[v5] = 0;
  this->mechanism.len = v5;
  idStr::FreeData(this: (idStr *)v8);
  idMQFrame::ReadString(this: frame, str: (idList<unsigned char,37> *)&this->response);
  v6 = idMQFrame::ReadShortString(this: (idMQFrame *)&v8[0].flushWriteBitBuffer, result: (idStr *)frame);
  v7 = *(_DWORD *)&v6->type;
  idStr::EnsureAlloced(this: &this->locale, amount: *(_DWORD *)&v6->type + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->locale.data, Src: v6->data.list, Size: v7);
  this->locale.data[v7] = 0;
  this->locale.len = v7;
  idStr::FreeData(this: (idStr *)&v8[0].flushWriteBitBuffer);
}


// ========================================================================
// __unwind$118909
// EA  : 0x82F45BF4
// RVA : 0x00F45BF4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_118909()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$118910
// EA  : 0x82F45C1C
// RVA : 0x00F45C1C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_118910()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// ?Populate@AMQPConnectionOpen@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45C50
// RVA : 0x00F45C50
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionOpen::Populate(AMQPConnectionOpen *this, idStr *frame)
{
  idMQFrame *ShortString; // r28
  size_t v5; // r29
  idMQFrame *v6; // r26
  size_t v7; // r29
  bool Bool; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  __int64 v12; // r4
  int v13; // [sp+8h] [-C8h]
  int v14; // [sp+Ch] [-C4h]
  int v15; // [sp+10h] [-C0h]
  int v16; // [sp+14h] [-BCh]
  idMQFrame v17[2]; // [sp+50h] [-80h] BYREF

  ShortString = idMQFrame::ReadShortString(this: v17, result: frame);
  v5 = *(_DWORD *)&ShortString->type;
  idStr::EnsureAlloced(
    this: &this->virtualHost,
    amount: *(_DWORD *)&ShortString->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->virtualHost.data, Src: ShortString->data.list, Size: v5);
  this->virtualHost.data[v5] = 0;
  this->virtualHost.len = v5;
  idStr::FreeData(this: (idStr *)v17);
  v6 = idMQFrame::ReadShortString(this: (idMQFrame *)&v17[0].flushWriteBitBuffer, result: frame);
  v7 = *(_DWORD *)&v6->type;
  idStr::EnsureAlloced(
    this: &this->capabilities,
    amount: *(_DWORD *)&v6->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->capabilities.data, Src: v6->data.list, Size: v7);
  this->capabilities.data[v7] = 0;
  this->capabilities.len = v7;
  idStr::FreeData(this: (idStr *)&v17[0].flushWriteBitBuffer);
  Bool = idMQFrame::ReadBool(this: (idMQFrame *)frame);
  HIDWORD(v9) = allocationCurrent[242];
  this->insist = Bool;
  LODWORD(v10) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v11) = this->capabilities.data;
    LODWORD(v11) = Bool;
    LODWORD(v12) = this->virtualHost.data;
    HIDWORD(v12) = "AMQP <<: ConnectionOpenOk virtualHost=%s, capabilities=%s, insist=%d\n";
    idLib::Printf(fmt: v12, a2: v11, a3: v10, a4: v9, a5: v13, a6: v14, a7: v15, a8: v16);
  }
}


// ========================================================================
// __unwind$118966
// EA  : 0x82F45D40
// RVA : 0x00F45D40
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_118966()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// __unwind$118967_0
// EA  : 0x82F45D68
// RVA : 0x00F45D68
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_118967_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ?Populate@AMQPConnectionOpenOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45D98
// RVA : 0x00F45D98
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionOpenOk::Populate(AMQPConnectionOpenOk *this, idStr *frame)
{
  idMQFrame *v3; // r28
  size_t v4; // r29
  __int64 v5; // r6
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r4
  int v9; // [sp+8h] [-98h]
  int v10; // [sp+Ch] [-94h]
  int v11; // [sp+10h] [-90h]
  int v12; // [sp+14h] [-8Ch]
  idMQFrame v13; // [sp+50h] [-50h] BYREF

  v3 = idMQFrame::ReadShortString(this: &v13, result: frame);
  v4 = *(_DWORD *)&v3->type;
  idStr::EnsureAlloced(
    this: &this->knownHosts,
    amount: *(_DWORD *)&v3->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->knownHosts.data, Src: v3->data.list, Size: v4);
  this->knownHosts.data[v4] = 0;
  this->knownHosts.len = v4;
  idStr::FreeData(this: (idStr *)&v13);
  HIDWORD(v6) = allocationCurrent[242];
  LODWORD(v7) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v8) = this->knownHosts.data;
    HIDWORD(v8) = "AMQP <<: ConnectionOpenOk knownHosts=%s\n";
    idLib::Printf(fmt: v8, a2: v5, a3: v7, a4: v6, a5: v9, a6: v10, a7: v11, a8: v12);
  }
}


// ========================================================================
// __unwind$119033
// EA  : 0x82F45E24
// RVA : 0x00F45E24
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119033()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Populate@AMQPConnectionRedirect@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45E58
// RVA : 0x00F45E58
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionRedirect::Populate(AMQPConnectionRedirect *this, idStr *frame)
{
  idMQFrame *ShortString; // r28
  size_t v5; // r29
  idMQFrame *v6; // r27
  size_t v7; // r29
  __int64 v8; // r6
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r4
  int v12; // [sp+8h] [-B8h]
  int v13; // [sp+Ch] [-B4h]
  int v14; // [sp+10h] [-B0h]
  int v15; // [sp+14h] [-ACh]
  idMQFrame v16[2]; // [sp+50h] [-70h] BYREF

  ShortString = idMQFrame::ReadShortString(this: v16, result: frame);
  v5 = *(_DWORD *)&ShortString->type;
  idStr::EnsureAlloced(
    this: &this->host,
    amount: *(_DWORD *)&ShortString->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->host.data, Src: ShortString->data.list, Size: v5);
  this->host.data[v5] = 0;
  this->host.len = v5;
  idStr::FreeData(this: (idStr *)v16);
  v6 = idMQFrame::ReadShortString(this: (idMQFrame *)&v16[0].flushWriteBitBuffer, result: frame);
  v7 = *(_DWORD *)&v6->type;
  idStr::EnsureAlloced(
    this: &this->knownHosts,
    amount: *(_DWORD *)&v6->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->knownHosts.data, Src: v6->data.list, Size: v7);
  this->knownHosts.data[v7] = 0;
  this->knownHosts.len = v7;
  idStr::FreeData(this: (idStr *)&v16[0].flushWriteBitBuffer);
  HIDWORD(v9) = allocationCurrent[242];
  LODWORD(v10) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v11) = this->knownHosts.data;
    HIDWORD(v11) = "AMQP <<: AMQPConnectionRedirect knownHosts=%s\n";
    idLib::Printf(fmt: v11, a2: v8, a3: v10, a4: v9, a5: v12, a6: v13, a7: v14, a8: v15);
  }
}


// ========================================================================
// __unwind$119074
// EA  : 0x82F45F34
// RVA : 0x00F45F34
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119074()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$119075
// EA  : 0x82F45F5C
// RVA : 0x00F45F5C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119075()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// ?Populate@AMQPConnectionClose@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F45F90
// RVA : 0x00F45F90
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPConnectionClose::Populate(AMQPConnectionClose *this, idMQFrame *frame)
{
  idMQFrame *v4; // r27
  size_t v5; // r29
  unsigned __int16 UInt16; // r3
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r4
  int v11; // [sp+8h] [-98h]
  int v12; // [sp+Ch] [-94h]
  int v13; // [sp+10h] [-90h]
  int v14; // [sp+14h] [-8Ch]
  idMQFrame v15; // [sp+50h] [-50h] BYREF

  this->replyCode = idMQFrame::ReadUInt16(this: frame);
  v4 = idMQFrame::ReadShortString(this: &v15, result: (idStr *)frame);
  v5 = *(_DWORD *)&v4->type;
  idStr::EnsureAlloced(this: &this->replyText, amount: *(_DWORD *)&v4->type + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->replyText.data, Src: v4->data.list, Size: v5);
  this->replyText.data[v5] = 0;
  this->replyText.len = v5;
  idStr::FreeData(this: (idStr *)&v15);
  this->cId = idMQFrame::ReadUInt16(this: frame);
  UInt16 = idMQFrame::ReadUInt16(this: frame);
  HIDWORD(v7) = allocationCurrent[242];
  this->mId = UInt16;
  LODWORD(v8) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v9) = this->cId;
    HIDWORD(v8) = UInt16;
    HIDWORD(v9) = this->replyText.data;
    HIDWORD(v10) = "AMQP <<: AMQPConnectionClose replyCode=%d, replyText=%s, cId=%d, mId=%d\n";
    LODWORD(v10) = this->replyCode;
    idLib::Printf(fmt: v10, a2: v9, a3: v8, a4: v7, a5: v11, a6: v12, a7: v13, a8: v14);
  }
}


// ========================================================================
// __unwind$119135
// EA  : 0x82F46054
// RVA : 0x00F46054
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119135()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Populate@AMQPChannelOpen@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F46088
// RVA : 0x00F46088
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPChannelOpen::Populate(AMQPChannelOpen *this, idStr *frame)
{
  idMQFrame *v3; // r28
  size_t v4; // r29
  __int64 v5; // r6
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r4
  int v9; // [sp+8h] [-98h]
  int v10; // [sp+Ch] [-94h]
  int v11; // [sp+10h] [-90h]
  int v12; // [sp+14h] [-8Ch]
  idMQFrame v13; // [sp+50h] [-50h] BYREF

  v3 = idMQFrame::ReadShortString(this: &v13, result: frame);
  v4 = *(_DWORD *)&v3->type;
  idStr::EnsureAlloced(this: &this->oob, amount: *(_DWORD *)&v3->type + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->oob.data, Src: v3->data.list, Size: v4);
  this->oob.data[v4] = 0;
  this->oob.len = v4;
  idStr::FreeData(this: (idStr *)&v13);
  HIDWORD(v6) = allocationCurrent[242];
  LODWORD(v7) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v8) = this->oob.data;
    HIDWORD(v8) = "AMQP <<: AMQPChannelOpen oob=%s\n";
    idLib::Printf(fmt: v8, a2: v5, a3: v7, a4: v6, a5: v9, a6: v10, a7: v11, a8: v12);
  }
}


// ========================================================================
// __unwind$119175
// EA  : 0x82F46114
// RVA : 0x00F46114
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119175()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Populate@AMQPChannelAlert@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F46148
// RVA : 0x00F46148
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPChannelAlert::Populate(AMQPChannelAlert *this, idMQFrame *frame)
{
  idMQFrame *v4; // r27
  size_t v5; // r29
  __int64 v6; // r6
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r4
  int v10; // [sp+8h] [-98h]
  int v11; // [sp+Ch] [-94h]
  int v12; // [sp+10h] [-90h]
  int v13; // [sp+14h] [-8Ch]
  idMQFrame v14; // [sp+50h] [-50h] BYREF

  this->replyCode = idMQFrame::ReadUInt16(this: frame);
  v4 = idMQFrame::ReadShortString(this: &v14, result: (idStr *)frame);
  v5 = *(_DWORD *)&v4->type;
  idStr::EnsureAlloced(this: &this->replyText, amount: *(_DWORD *)&v4->type + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->replyText.data, Src: v4->data.list, Size: v5);
  this->replyText.data[v5] = 0;
  this->replyText.len = v5;
  idStr::FreeData(this: (idStr *)&v14);
  idMQFrame::ReadTable(this: frame, dict: &this->details);
  HIDWORD(v7) = allocationCurrent[242];
  LODWORD(v8) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v6) = this->replyText.data;
    LODWORD(v9) = this->replyCode;
    HIDWORD(v9) = "AMQP <<: AMQPChannelAlert replyCode=%d, replyText=%s, details=X\n";
    idLib::Printf(fmt: v9, a2: v6, a3: v8, a4: v7, a5: v10, a6: v11, a7: v12, a8: v13);
  }
}


// ========================================================================
// __unwind$119215
// EA  : 0x82F461F8
// RVA : 0x00F461F8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119215()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Populate@AMQPChannelClose@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F46228
// RVA : 0x00F46228
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPChannelClose::Populate(AMQPChannelClose *this, idMQFrame *frame)
{
  idMQFrame *v4; // r27
  size_t v5; // r29
  unsigned __int16 UInt16; // r3
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r4
  int v11; // [sp+8h] [-98h]
  int v12; // [sp+Ch] [-94h]
  int v13; // [sp+10h] [-90h]
  int v14; // [sp+14h] [-8Ch]
  idMQFrame v15; // [sp+50h] [-50h] BYREF

  this->replyCode = idMQFrame::ReadUInt16(this: frame);
  v4 = idMQFrame::ReadShortString(this: &v15, result: (idStr *)frame);
  v5 = *(_DWORD *)&v4->type;
  idStr::EnsureAlloced(this: &this->replyText, amount: *(_DWORD *)&v4->type + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->replyText.data, Src: v4->data.list, Size: v5);
  this->replyText.data[v5] = 0;
  this->replyText.len = v5;
  idStr::FreeData(this: (idStr *)&v15);
  this->cId = idMQFrame::ReadUInt16(this: frame);
  UInt16 = idMQFrame::ReadUInt16(this: frame);
  HIDWORD(v7) = allocationCurrent[242];
  this->mId = UInt16;
  LODWORD(v8) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v9) = this->cId;
    HIDWORD(v8) = UInt16;
    HIDWORD(v9) = this->replyText.data;
    HIDWORD(v10) = "AMQP <<: AMQPChannelClose replyCode=%d, replyText=%s, cId=%d, mId=%d\n";
    LODWORD(v10) = this->replyCode;
    idLib::Printf(fmt: v10, a2: v9, a3: v8, a4: v7, a5: v11, a6: v12, a7: v13, a8: v14);
  }
}


// ========================================================================
// __unwind$119255
// EA  : 0x82F462EC
// RVA : 0x00F462EC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119255()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Populate@AMQPExchangeDeclare@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F46320
// RVA : 0x00F46320
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPExchangeDeclare::Populate(AMQPExchangeDeclare *this, idMQFrame *frame)
{
  idMQFrame *ShortString; // r28
  size_t v5; // r29
  idMQFrame *v6; // r26
  size_t v7; // r29
  __int64 v8; // r10
  __int64 v9; // r4
  __int64 v10; // r8
  __int64 v11; // r6
  int v12; // [sp+8h] [-D8h]
  int v13; // [sp+Ch] [-D4h]
  int v14; // [sp+10h] [-D0h]
  int v15; // [sp+14h] [-CCh]
  idMQFrame v16[2]; // [sp+60h] [-80h] BYREF

  this->ticket = idMQFrame::ReadUInt16(this: frame);
  ShortString = idMQFrame::ReadShortString(this: v16, result: (idStr *)frame);
  v5 = *(_DWORD *)&ShortString->type;
  idStr::EnsureAlloced(
    this: &this->exchange,
    amount: *(_DWORD *)&ShortString->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->exchange.data, Src: ShortString->data.list, Size: v5);
  this->exchange.data[v5] = 0;
  this->exchange.len = v5;
  idStr::FreeData(this: (idStr *)v16);
  v6 = idMQFrame::ReadShortString(this: (idMQFrame *)&v16[0].flushWriteBitBuffer, result: (idStr *)frame);
  v7 = *(_DWORD *)&v6->type;
  idStr::EnsureAlloced(this: &this->type, amount: *(_DWORD *)&v6->type + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->type.data, Src: v6->data.list, Size: v7);
  this->type.data[v7] = 0;
  this->type.len = v7;
  idStr::FreeData(this: (idStr *)&v16[0].flushWriteBitBuffer);
  this->passive = idMQFrame::ReadBool(this: frame);
  this->durable = idMQFrame::ReadBool(this: frame);
  this->autoDelete = idMQFrame::ReadBool(this: frame);
  this->isInternal = idMQFrame::ReadBool(this: frame);
  this->noWait = idMQFrame::ReadBool(this: frame);
  idMQFrame::ReadTable(this: frame, dict: &this->arguments);
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v8) = this->isInternal;
    HIDWORD(v9) = "AMQP <<: AMQPExchangeDeclare ticket=%d, exchange=%s, type=%s, passive=%d, durable=%d, autoDelete=%d, i"
                  "sInternal=%d, noWait=%d, arguments=X\n";
    HIDWORD(v8) = this->autoDelete;
    LODWORD(v10) = this->durable;
    HIDWORD(v10) = this->passive;
    LODWORD(v11) = this->type.data;
    HIDWORD(v11) = this->exchange.data;
    LODWORD(v9) = this->ticket;
    idLib::Printf(fmt: v9, a2: v11, a3: v10, a4: v8, a5: v12, a6: v13, a7: v14, a8: v15);
  }
}


// ========================================================================
// __unwind$119296
// EA  : 0x82F46474
// RVA : 0x00F46474
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119296()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$119297
// EA  : 0x82F4649C
// RVA : 0x00F4649C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119297()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// ?Populate@AMQPExchangeDelete@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F464D0
// RVA : 0x00F464D0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPExchangeDelete::Populate(AMQPExchangeDelete *this, idMQFrame *frame)
{
  idMQFrame *v4; // r27
  size_t v5; // r29
  bool Bool; // r3
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r4
  int v11; // [sp+8h] [-98h]
  int v12; // [sp+Ch] [-94h]
  int v13; // [sp+10h] [-90h]
  int v14; // [sp+14h] [-8Ch]
  idMQFrame v15; // [sp+50h] [-50h] BYREF

  this->ticket = idMQFrame::ReadUInt16(this: frame);
  v4 = idMQFrame::ReadShortString(this: &v15, result: (idStr *)frame);
  v5 = *(_DWORD *)&v4->type;
  idStr::EnsureAlloced(this: &this->exchange, amount: *(_DWORD *)&v4->type + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->exchange.data, Src: v4->data.list, Size: v5);
  this->exchange.data[v5] = 0;
  this->exchange.len = v5;
  idStr::FreeData(this: (idStr *)&v15);
  this->unused = idMQFrame::ReadBool(this: frame);
  Bool = idMQFrame::ReadBool(this: frame);
  HIDWORD(v7) = allocationCurrent[242];
  this->noWait = Bool;
  LODWORD(v8) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v9) = this->unused;
    HIDWORD(v8) = Bool;
    HIDWORD(v9) = this->exchange.data;
    HIDWORD(v10) = "AMQP <<: AMQPExchangeDelete ticket=%d, exchange=%s, unused=%d, noWait=%d\n";
    LODWORD(v10) = this->ticket;
    idLib::Printf(fmt: v10, a2: v9, a3: v8, a4: v7, a5: v11, a6: v12, a7: v13, a8: v14);
  }
}


// ========================================================================
// __unwind$119361
// EA  : 0x82F46594
// RVA : 0x00F46594
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119361()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Populate@AMQPQueueDeclare@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F465C8
// RVA : 0x00F465C8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPQueueDeclare::Populate(AMQPQueueDeclare *this, idMQFrame *frame)
{
  idMQFrame *v4; // r27
  size_t v5; // r29
  __int64 v6; // r10
  __int64 v7; // r4
  __int64 v8; // r8
  __int64 v9; // r6
  int v10; // [sp+8h] [-98h]
  int v11; // [sp+Ch] [-94h]
  int v12; // [sp+10h] [-90h]
  int v13; // [sp+14h] [-8Ch]
  idMQFrame v14; // [sp+50h] [-50h] BYREF

  this->ticket = idMQFrame::ReadUInt16(this: frame);
  v4 = idMQFrame::ReadShortString(this: &v14, result: (idStr *)frame);
  v5 = *(_DWORD *)&v4->type;
  idStr::EnsureAlloced(this: &this->queue, amount: *(_DWORD *)&v4->type + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->queue.data, Src: v4->data.list, Size: v5);
  this->queue.data[v5] = 0;
  this->queue.len = v5;
  idStr::FreeData(this: (idStr *)&v14);
  this->passive = idMQFrame::ReadBool(this: frame);
  this->durable = idMQFrame::ReadBool(this: frame);
  this->exclusive = idMQFrame::ReadBool(this: frame);
  this->autoDelete = idMQFrame::ReadBool(this: frame);
  this->noWait = idMQFrame::ReadBool(this: frame);
  idMQFrame::ReadTable(this: frame, dict: &this->arguments);
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v6) = this->noWait;
    HIDWORD(v6) = this->autoDelete;
    HIDWORD(v7) = "AMQP <<: AMQPQueueDeclare ticket=%d, queue=%s, passive=%d, durable=%d, exclusive=%d, autoDelete=%d, no"
                  "Wait=%d, arguments=X\n";
    LODWORD(v8) = this->exclusive;
    HIDWORD(v8) = this->durable;
    LODWORD(v9) = this->passive;
    HIDWORD(v9) = this->queue.data;
    LODWORD(v7) = this->ticket;
    idLib::Printf(fmt: v7, a2: v9, a3: v8, a4: v6, a5: v10, a6: v11, a7: v12, a8: v13);
  }
}


// ========================================================================
// __unwind$119401
// EA  : 0x82F466C8
// RVA : 0x00F466C8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119401()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Populate@AMQPQueueDeclareOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F466F8
// RVA : 0x00F466F8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPQueueDeclareOk::Populate(AMQPQueueDeclareOk *this, idStr *frame)
{
  idMQFrame *v4; // r27
  size_t v5; // r29
  unsigned int UInt32; // r3
  __int64 v7; // r10
  __int64 v8; // r6
  __int64 v9; // r8
  __int64 v10; // r4
  int v11; // [sp+8h] [-98h]
  int v12; // [sp+Ch] [-94h]
  int v13; // [sp+10h] [-90h]
  int v14; // [sp+14h] [-8Ch]
  idMQFrame v15; // [sp+50h] [-50h] BYREF

  v4 = idMQFrame::ReadShortString(this: &v15, result: frame);
  v5 = *(_DWORD *)&v4->type;
  idStr::EnsureAlloced(this: &this->queue, amount: *(_DWORD *)&v4->type + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->queue.data, Src: v4->data.list, Size: v5);
  this->queue.data[v5] = 0;
  this->queue.len = v5;
  idStr::FreeData(this: (idStr *)&v15);
  this->messageCount = idMQFrame::ReadUInt32(this: (idMQFrame *)frame);
  UInt32 = idMQFrame::ReadUInt32(this: (idMQFrame *)frame);
  HIDWORD(v7) = allocationCurrent[242];
  this->consumerCount = UInt32;
  LODWORD(v8) = UInt32;
  LODWORD(v9) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v8) = this->messageCount;
    LODWORD(v10) = this->queue.data;
    HIDWORD(v10) = "AMQP <<: AMQPQueueDeclareOk queue=%s, messageCount=%d, consumerCount=%d\n";
    idLib::Printf(fmt: v10, a2: v8, a3: v9, a4: v7, a5: v11, a6: v12, a7: v13, a8: v14);
  }
}


// ========================================================================
// __unwind$119441
// EA  : 0x82F467A8
// RVA : 0x00F467A8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119441()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Populate@AMQPQueueBind@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F467D8
// RVA : 0x00F467D8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPQueueBind::Populate(AMQPQueueBind *this, idMQFrame *frame)
{
  idMQFrame *v4; // r28
  size_t v5; // r29
  idMQFrame *ShortString; // r26
  size_t v7; // r29
  idMQFrame *v8; // r26
  size_t v9; // r29
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r4
  __int64 v13; // r6
  int v14; // [sp+8h] [-E8h]
  int v15; // [sp+Ch] [-E4h]
  int v16; // [sp+10h] [-E0h]
  int v17; // [sp+14h] [-DCh]
  idMQFrame v18; // [sp+50h] [-A0h] BYREF
  idMQFrame v19[2]; // [sp+90h] [-60h] BYREF

  this->ticket = idMQFrame::ReadUInt16(this: frame);
  v4 = idMQFrame::ReadShortString(this: &v18, result: (idStr *)frame);
  v5 = *(_DWORD *)&v4->type;
  idStr::EnsureAlloced(this: &this->queue, amount: *(_DWORD *)&v4->type + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->queue.data, Src: v4->data.list, Size: v5);
  this->queue.data[v5] = 0;
  this->queue.len = v5;
  idStr::FreeData(this: (idStr *)&v18);
  ShortString = idMQFrame::ReadShortString(this: (idMQFrame *)&v18.flushWriteBitBuffer, result: (idStr *)frame);
  v7 = *(_DWORD *)&ShortString->type;
  idStr::EnsureAlloced(
    this: &this->exchange,
    amount: *(_DWORD *)&ShortString->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->exchange.data, Src: ShortString->data.list, Size: v7);
  this->exchange.data[v7] = 0;
  this->exchange.len = v7;
  idStr::FreeData(this: (idStr *)&v18.flushWriteBitBuffer);
  v8 = idMQFrame::ReadShortString(this: v19, result: (idStr *)frame);
  v9 = *(_DWORD *)&v8->type;
  idStr::EnsureAlloced(
    this: &this->routingKey,
    amount: *(_DWORD *)&v8->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->routingKey.data, Src: v8->data.list, Size: v9);
  this->routingKey.data[v9] = 0;
  this->routingKey.len = v9;
  idStr::FreeData(this: (idStr *)v19);
  this->noWait = idMQFrame::ReadBool(this: frame);
  idMQFrame::ReadTable(this: frame, dict: &this->arguments);
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v11) = this->noWait;
    HIDWORD(v11) = this->routingKey.data;
    HIDWORD(v12) = "AMQP <<: AMQPQueueBind ticket=%d, queue=%s, exchange=%s, routingKey=%s, noWait=%d, arguments=X\n";
    LODWORD(v13) = this->exchange.data;
    HIDWORD(v13) = this->queue.data;
    LODWORD(v12) = this->ticket;
    idLib::Printf(fmt: v12, a2: v13, a3: v11, a4: v10, a5: v14, a6: v15, a7: v16, a8: v17);
  }
}


// ========================================================================
// __unwind$119483_0
// EA  : 0x82F46938
// RVA : 0x00F46938
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119483_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$119484
// EA  : 0x82F46960
// RVA : 0x00F46960
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119484()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$119485
// EA  : 0x82F46988
// RVA : 0x00F46988
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119485()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// ?Populate@AMQPQueueUnbind@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F469B8
// RVA : 0x00F469B8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPQueueUnbind::Populate(AMQPQueueUnbind *this, idMQFrame *frame)
{
  idMQFrame *v4; // r28
  size_t v5; // r29
  idMQFrame *ShortString; // r26
  size_t v7; // r29
  idMQFrame *v8; // r26
  size_t v9; // r29
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r4
  int v14; // [sp+8h] [-E8h]
  int v15; // [sp+Ch] [-E4h]
  int v16; // [sp+10h] [-E0h]
  int v17; // [sp+14h] [-DCh]
  idMQFrame v18; // [sp+50h] [-A0h] BYREF
  idMQFrame v19[2]; // [sp+90h] [-60h] BYREF

  this->ticket = idMQFrame::ReadUInt16(this: frame);
  v4 = idMQFrame::ReadShortString(this: &v18, result: (idStr *)frame);
  v5 = *(_DWORD *)&v4->type;
  idStr::EnsureAlloced(this: &this->queue, amount: *(_DWORD *)&v4->type + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->queue.data, Src: v4->data.list, Size: v5);
  this->queue.data[v5] = 0;
  this->queue.len = v5;
  idStr::FreeData(this: (idStr *)&v18);
  ShortString = idMQFrame::ReadShortString(this: (idMQFrame *)&v18.flushWriteBitBuffer, result: (idStr *)frame);
  v7 = *(_DWORD *)&ShortString->type;
  idStr::EnsureAlloced(
    this: &this->exchange,
    amount: *(_DWORD *)&ShortString->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->exchange.data, Src: ShortString->data.list, Size: v7);
  this->exchange.data[v7] = 0;
  this->exchange.len = v7;
  idStr::FreeData(this: (idStr *)&v18.flushWriteBitBuffer);
  v8 = idMQFrame::ReadShortString(this: v19, result: (idStr *)frame);
  v9 = *(_DWORD *)&v8->type;
  idStr::EnsureAlloced(
    this: &this->routingKey,
    amount: *(_DWORD *)&v8->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->routingKey.data, Src: v8->data.list, Size: v9);
  this->routingKey.data[v9] = 0;
  this->routingKey.len = v9;
  idStr::FreeData(this: (idStr *)v19);
  idMQFrame::ReadTable(this: frame, dict: &this->arguments);
  LODWORD(v11) = allocationCurrent[242];
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v11) = this->routingKey.data;
    LODWORD(v12) = this->exchange.data;
    HIDWORD(v13) = "AMQP <<: AMQPQueueUnbind ticket=%d, queue=%s, exchange=%s, routingKey=%s, arguments=X\n";
    HIDWORD(v12) = this->queue.data;
    LODWORD(v13) = this->ticket;
    idLib::Printf(fmt: v13, a2: v12, a3: v11, a4: v10, a5: v14, a6: v15, a7: v16, a8: v17);
  }
}


// ========================================================================
// __unwind$119575
// EA  : 0x82F46B08
// RVA : 0x00F46B08
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119575()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$119576
// EA  : 0x82F46B30
// RVA : 0x00F46B30
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119576()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$119577
// EA  : 0x82F46B58
// RVA : 0x00F46B58
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119577()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// ?Populate@AMQPQueuePurge@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F46B88
// RVA : 0x00F46B88
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPQueuePurge::Populate(AMQPQueuePurge *this, idMQFrame *frame)
{
  idMQFrame *v4; // r27
  size_t v5; // r29
  bool Bool; // r3
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r4
  int v11; // [sp+8h] [-98h]
  int v12; // [sp+Ch] [-94h]
  int v13; // [sp+10h] [-90h]
  int v14; // [sp+14h] [-8Ch]
  idMQFrame v15; // [sp+50h] [-50h] BYREF

  this->ticket = idMQFrame::ReadUInt16(this: frame);
  v4 = idMQFrame::ReadShortString(this: &v15, result: (idStr *)frame);
  v5 = *(_DWORD *)&v4->type;
  idStr::EnsureAlloced(this: &this->queue, amount: *(_DWORD *)&v4->type + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->queue.data, Src: v4->data.list, Size: v5);
  this->queue.data[v5] = 0;
  this->queue.len = v5;
  idStr::FreeData(this: (idStr *)&v15);
  Bool = idMQFrame::ReadBool(this: frame);
  HIDWORD(v7) = allocationCurrent[242];
  this->noWait = Bool;
  LODWORD(v8) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v9) = this->queue.data;
    LODWORD(v9) = Bool;
    LODWORD(v10) = this->ticket;
    HIDWORD(v10) = "AMQP <<: AMQPQueuePurge ticket=%d, queue=%s, noWait=%d\n";
    idLib::Printf(fmt: v10, a2: v9, a3: v8, a4: v7, a5: v11, a6: v12, a7: v13, a8: v14);
  }
}


// ========================================================================
// __unwind$119665
// EA  : 0x82F46C3C
// RVA : 0x00F46C3C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119665()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Populate@AMQPQueueDelete@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F46C70
// RVA : 0x00F46C70
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPQueueDelete::Populate(AMQPQueueDelete *this, idMQFrame *frame)
{
  idMQFrame *v4; // r27
  size_t v5; // r29
  bool Bool; // r3
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r4
  int v11; // [sp+8h] [-98h]
  int v12; // [sp+Ch] [-94h]
  int v13; // [sp+10h] [-90h]
  int v14; // [sp+14h] [-8Ch]
  idMQFrame v15; // [sp+50h] [-50h] BYREF

  this->ticket = idMQFrame::ReadUInt16(this: frame);
  v4 = idMQFrame::ReadShortString(this: &v15, result: (idStr *)frame);
  v5 = *(_DWORD *)&v4->type;
  idStr::EnsureAlloced(this: &this->queue, amount: *(_DWORD *)&v4->type + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->queue.data, Src: v4->data.list, Size: v5);
  this->queue.data[v5] = 0;
  this->queue.len = v5;
  idStr::FreeData(this: (idStr *)&v15);
  this->unused = idMQFrame::ReadBool(this: frame);
  this->empty = idMQFrame::ReadBool(this: frame);
  Bool = idMQFrame::ReadBool(this: frame);
  HIDWORD(v7) = allocationCurrent[242];
  this->noWait = Bool;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v8) = this->empty;
    LODWORD(v8) = Bool;
    LODWORD(v9) = this->unused;
    HIDWORD(v10) = "AMQP <<: AMQPQueueDelete ticket=%d, queue=%s, unused=%d, empty=%d, noWait=%d\n";
    HIDWORD(v9) = this->queue.data;
    LODWORD(v10) = this->ticket;
    idLib::Printf(fmt: v10, a2: v9, a3: v8, a4: v7, a5: v11, a6: v12, a7: v13, a8: v14);
  }
}


// ========================================================================
// __unwind$119705
// EA  : 0x82F46D44
// RVA : 0x00F46D44
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119705()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Populate@AMQPBasicProperties@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F46D78
// RVA : 0x00F46D78
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicProperties::Populate(
        AMQPBasicProperties *this,
        idMQFrame *frame,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  int v10; // r4
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  int v14; // r4
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r6
  int v18; // r4
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  int v22; // r4
  __int64 v23; // r10
  __int64 v24; // r8
  __int64 v25; // r6
  int v26; // r4
  __int64 v27; // r10
  __int64 v28; // r8
  __int64 v29; // r6
  int v30; // r4
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 v33; // r6
  int v34; // r4
  __int64 v35; // r10
  __int64 v36; // r8
  __int64 v37; // r6
  int v38; // r4
  __int64 v39; // r10
  __int64 v40; // r8
  __int64 v41; // r6
  int v42; // r4
  __int64 v43; // r10
  __int64 v44; // r8
  __int64 v45; // r6
  int v46; // r4
  __int64 v47; // r10
  __int64 v48; // r8
  __int64 v49; // r6
  int v50; // r4
  __int64 v51; // r10
  __int64 v52; // r8
  __int64 v53; // r6
  int v54; // r4
  __int64 v55; // r10
  __int64 v56; // r8
  __int64 v57; // r6
  int v58; // r4
  __int64 v59; // r10
  __int64 v60; // r8
  __int64 v61; // r6
  int v62; // r4
  idMQFrame *ShortString; // r26
  size_t v64; // r27
  idMQFrame *v65; // r26
  size_t v66; // r27
  idMQFrame *v67; // r26
  size_t v68; // r27
  idMQFrame *v69; // r26
  size_t v70; // r27
  idMQFrame *v71; // r26
  size_t v72; // r27
  idMQFrame *v73; // r26
  size_t v74; // r27
  unsigned __int64 v75; // r3
  idMQFrame *v76; // r26
  size_t v77; // r27
  idMQFrame *v78; // r26
  size_t v79; // r27
  idMQFrame *v80; // r26
  size_t v81; // r27
  idMQFrame *v82; // r27
  size_t v83; // r29
  int v84; // [sp+8h] [-1C8h]
  int v85; // [sp+Ch] [-1C4h]
  int v86; // [sp+10h] [-1C0h]
  int v87; // [sp+14h] [-1BCh]
  idMQFrame v88; // [sp+50h] [-180h] BYREF
  idMQFrame v89; // [sp+90h] [-140h] BYREF
  idMQFrame v90; // [sp+D0h] [-100h] BYREF
  idMQFrame v91; // [sp+110h] [-C0h] BYREF
  idMQFrame v92[2]; // [sp+150h] [-80h] BYREF

  this->b_contentType = idMQFrame::ReadPropertyPresence(this: frame, a2: (int)frame, a3, a4, a5);
  this->b_contentEncoding = idMQFrame::ReadPropertyPresence(this: frame, a2: v10, a3: v9, a4: v8, a5: v7);
  this->b_headers = idMQFrame::ReadPropertyPresence(this: frame, a2: v14, a3: v13, a4: v12, a5: v11);
  this->b_deliveryMode = idMQFrame::ReadPropertyPresence(this: frame, a2: v18, a3: v17, a4: v16, a5: v15);
  this->b_priority = idMQFrame::ReadPropertyPresence(this: frame, a2: v22, a3: v21, a4: v20, a5: v19);
  this->b_correlationId = idMQFrame::ReadPropertyPresence(this: frame, a2: v26, a3: v25, a4: v24, a5: v23);
  this->b_replyTo = idMQFrame::ReadPropertyPresence(this: frame, a2: v30, a3: v29, a4: v28, a5: v27);
  this->b_expiration = idMQFrame::ReadPropertyPresence(this: frame, a2: v34, a3: v33, a4: v32, a5: v31);
  this->b_messageId = idMQFrame::ReadPropertyPresence(this: frame, a2: v38, a3: v37, a4: v36, a5: v35);
  this->b_timestamp = idMQFrame::ReadPropertyPresence(this: frame, a2: v42, a3: v41, a4: v40, a5: v39);
  this->b_type = idMQFrame::ReadPropertyPresence(this: frame, a2: v46, a3: v45, a4: v44, a5: v43);
  this->b_userId = idMQFrame::ReadPropertyPresence(this: frame, a2: v50, a3: v49, a4: v48, a5: v47);
  this->b_appId = idMQFrame::ReadPropertyPresence(this: frame, a2: v54, a3: v53, a4: v52, a5: v51);
  this->b_clusterId = idMQFrame::ReadPropertyPresence(this: frame, a2: v58, a3: v57, a4: v56, a5: v55);
  idMQFrame::FinalizeReadPresence(this: frame, a2: v62, a3: v61, a4: v60, a5: v59, a6: v84, a7: v85, a8: v86, a9: v87);
  if ( this->b_contentType )
  {
    ShortString = idMQFrame::ReadShortString(this: v92, result: (idStr *)frame);
    v64 = *(_DWORD *)&ShortString->type;
    idStr::EnsureAlloced(
      this: &this->contentType,
      amount: *(_DWORD *)&ShortString->type + 1,
      keepold: false,
      geometricGrowth: false);
    memcpy(Dst: this->contentType.data, Src: ShortString->data.list, Size: v64);
    this->contentType.data[v64] = 0;
    this->contentType.len = v64;
    idStr::FreeData(this: (idStr *)v92);
  }
  if ( this->b_contentEncoding )
  {
    v65 = idMQFrame::ReadShortString(this: &v89, result: (idStr *)frame);
    v66 = *(_DWORD *)&v65->type;
    idStr::EnsureAlloced(
      this: &this->contentEncoding,
      amount: *(_DWORD *)&v65->type + 1,
      keepold: false,
      geometricGrowth: false);
    memcpy(Dst: this->contentEncoding.data, Src: v65->data.list, Size: v66);
    this->contentEncoding.data[v66] = 0;
    this->contentEncoding.len = v66;
    idStr::FreeData(this: (idStr *)&v89);
  }
  if ( this->b_headers )
    idMQFrame::ReadTable(this: frame, dict: &this->headers);
  if ( this->b_deliveryMode )
    this->deliveryMode = idMQFrame::ReadByte(this: frame);
  if ( this->b_priority )
    this->priority = idMQFrame::ReadByte(this: frame);
  if ( this->b_correlationId )
  {
    v67 = idMQFrame::ReadShortString(this: &v91, result: (idStr *)frame);
    v68 = *(_DWORD *)&v67->type;
    idStr::EnsureAlloced(
      this: &this->correlationId,
      amount: *(_DWORD *)&v67->type + 1,
      keepold: false,
      geometricGrowth: false);
    memcpy(Dst: this->correlationId.data, Src: v67->data.list, Size: v68);
    this->correlationId.data[v68] = 0;
    this->correlationId.len = v68;
    idStr::FreeData(this: (idStr *)&v91);
  }
  if ( this->b_replyTo )
  {
    v69 = idMQFrame::ReadShortString(this: &v90, result: (idStr *)frame);
    v70 = *(_DWORD *)&v69->type;
    idStr::EnsureAlloced(
      this: &this->replyTo,
      amount: *(_DWORD *)&v69->type + 1,
      keepold: false,
      geometricGrowth: false);
    memcpy(Dst: this->replyTo.data, Src: v69->data.list, Size: v70);
    this->replyTo.data[v70] = 0;
    this->replyTo.len = v70;
    idStr::FreeData(this: (idStr *)&v90);
  }
  if ( this->b_expiration )
  {
    v71 = idMQFrame::ReadShortString(this: &v88, result: (idStr *)frame);
    v72 = *(_DWORD *)&v71->type;
    idStr::EnsureAlloced(
      this: &this->expiration,
      amount: *(_DWORD *)&v71->type + 1,
      keepold: false,
      geometricGrowth: false);
    memcpy(Dst: this->expiration.data, Src: v71->data.list, Size: v72);
    this->expiration.data[v72] = 0;
    this->expiration.len = v72;
    idStr::FreeData(this: (idStr *)&v88);
  }
  if ( this->b_messageId )
  {
    v73 = idMQFrame::ReadShortString(this: (idMQFrame *)&v88.flushWriteBitBuffer, result: (idStr *)frame);
    v74 = *(_DWORD *)&v73->type;
    idStr::EnsureAlloced(
      this: &this->messageId,
      amount: *(_DWORD *)&v73->type + 1,
      keepold: false,
      geometricGrowth: false);
    memcpy(Dst: this->messageId.data, Src: v73->data.list, Size: v74);
    this->messageId.data[v74] = 0;
    this->messageId.len = v74;
    idStr::FreeData(this: (idStr *)&v88.flushWriteBitBuffer);
  }
  if ( this->b_timestamp )
  {
    LODWORD(v75) = idMQFrame::ReadUInt64(this: frame);
    this->timestamp = v75;
  }
  if ( this->b_type )
  {
    v76 = idMQFrame::ReadShortString(this: (idMQFrame *)&v89.flushWriteBitBuffer, result: (idStr *)frame);
    v77 = *(_DWORD *)&v76->type;
    idStr::EnsureAlloced(this: &this->type, amount: *(_DWORD *)&v76->type + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->type.data, Src: v76->data.list, Size: v77);
    this->type.data[v77] = 0;
    this->type.len = v77;
    idStr::FreeData(this: (idStr *)&v89.flushWriteBitBuffer);
  }
  if ( this->b_userId )
  {
    v78 = idMQFrame::ReadShortString(this: (idMQFrame *)&v90.flushWriteBitBuffer, result: (idStr *)frame);
    v79 = *(_DWORD *)&v78->type;
    idStr::EnsureAlloced(this: &this->userId, amount: *(_DWORD *)&v78->type + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->userId.data, Src: v78->data.list, Size: v79);
    this->userId.data[v79] = 0;
    this->userId.len = v79;
    idStr::FreeData(this: (idStr *)&v90.flushWriteBitBuffer);
  }
  if ( this->b_appId )
  {
    v80 = idMQFrame::ReadShortString(this: (idMQFrame *)&v91.flushWriteBitBuffer, result: (idStr *)frame);
    v81 = *(_DWORD *)&v80->type;
    idStr::EnsureAlloced(this: &this->appId, amount: *(_DWORD *)&v80->type + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->appId.data, Src: v80->data.list, Size: v81);
    this->appId.data[v81] = 0;
    this->appId.len = v81;
    idStr::FreeData(this: (idStr *)&v91.flushWriteBitBuffer);
  }
  if ( this->b_clusterId )
  {
    v82 = idMQFrame::ReadShortString(this: (idMQFrame *)&v92[0].flushWriteBitBuffer, result: (idStr *)frame);
    v83 = *(_DWORD *)&v82->type;
    idStr::EnsureAlloced(
      this: &this->clusterId,
      amount: *(_DWORD *)&v82->type + 1,
      keepold: false,
      geometricGrowth: false);
    memcpy(Dst: this->clusterId.data, Src: v82->data.list, Size: v83);
    this->clusterId.data[v83] = 0;
    this->clusterId.len = v83;
    idStr::FreeData(this: (idStr *)&v92[0].flushWriteBitBuffer);
  }
}


// ========================================================================
// __unwind$119754
// EA  : 0x82F4721C
// RVA : 0x00F4721C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119754()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 336));
}


// ========================================================================
// __unwind$119755
// EA  : 0x82F47244
// RVA : 0x00F47244
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119755()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 144));
}


// ========================================================================
// __unwind$119756
// EA  : 0x82F4726C
// RVA : 0x00F4726C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119756()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 272));
}


// ========================================================================
// __unwind$119757
// EA  : 0x82F47294
// RVA : 0x00F47294
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119757()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 208));
}


// ========================================================================
// __unwind$119758
// EA  : 0x82F472BC
// RVA : 0x00F472BC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119758()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 80));
}


// ========================================================================
// __unwind$119759
// EA  : 0x82F472E4
// RVA : 0x00F472E4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119759()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 112));
}


// ========================================================================
// __unwind$119760
// EA  : 0x82F4730C
// RVA : 0x00F4730C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119760()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 176));
}


// ========================================================================
// __unwind$119761
// EA  : 0x82F47334
// RVA : 0x00F47334
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119761()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 240));
}


// ========================================================================
// __unwind$119762
// EA  : 0x82F4735C
// RVA : 0x00F4735C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119762()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 304));
}


// ========================================================================
// __unwind$119763
// EA  : 0x82F47384
// RVA : 0x00F47384
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119763()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 368));
}


// ========================================================================
// ?Populate@AMQPBasicConsume@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F473B8
// RVA : 0x00F473B8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicConsume::Populate(AMQPBasicConsume *this, idMQFrame *frame)
{
  idMQFrame *ShortString; // r28
  size_t v5; // r29
  idMQFrame *v6; // r26
  size_t v7; // r29
  bool Bool; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r4
  __int64 v12; // r6
  int v13; // [sp+8h] [-C8h]
  int v14; // [sp+Ch] [-C4h]
  int v15; // [sp+10h] [-C0h]
  int v16; // [sp+14h] [-BCh]
  idMQFrame v17[2]; // [sp+50h] [-80h] BYREF

  this->ticket = idMQFrame::ReadUInt16(this: frame);
  ShortString = idMQFrame::ReadShortString(this: v17, result: (idStr *)frame);
  v5 = *(_DWORD *)&ShortString->type;
  idStr::EnsureAlloced(
    this: &this->queue,
    amount: *(_DWORD *)&ShortString->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->queue.data, Src: ShortString->data.list, Size: v5);
  this->queue.data[v5] = 0;
  this->queue.len = v5;
  idStr::FreeData(this: (idStr *)v17);
  v6 = idMQFrame::ReadShortString(this: (idMQFrame *)&v17[0].flushWriteBitBuffer, result: (idStr *)frame);
  v7 = *(_DWORD *)&v6->type;
  idStr::EnsureAlloced(
    this: &this->consumerTag,
    amount: *(_DWORD *)&v6->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->consumerTag.data, Src: v6->data.list, Size: v7);
  this->consumerTag.data[v7] = 0;
  this->consumerTag.len = v7;
  idStr::FreeData(this: (idStr *)&v17[0].flushWriteBitBuffer);
  this->noLocal = idMQFrame::ReadBool(this: frame);
  this->noAck = idMQFrame::ReadBool(this: frame);
  this->exclusive = idMQFrame::ReadBool(this: frame);
  Bool = idMQFrame::ReadBool(this: frame);
  this->noWait = Bool;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v9) = this->exclusive;
    LODWORD(v9) = Bool;
    LODWORD(v10) = this->noAck;
    HIDWORD(v11) = "AMQP <<: AMQPBasicConsume ticket=%d, queue=%s, consumerTag=%s, noLocal=%d, noAck=%d, exclusive=%d, noWait=%d\n";
    HIDWORD(v10) = this->noLocal;
    LODWORD(v12) = this->consumerTag.data;
    HIDWORD(v12) = this->queue.data;
    LODWORD(v11) = this->ticket;
    idLib::Printf(fmt: v11, a2: v12, a3: v10, a4: v9, a5: v13, a6: v14, a7: v15, a8: v16);
  }
}


// ========================================================================
// __unwind$119977
// EA  : 0x82F474EC
// RVA : 0x00F474EC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119977()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// __unwind$119978
// EA  : 0x82F47514
// RVA : 0x00F47514
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_119978()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ?Populate@AMQPBasicConsumeOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F47548
// RVA : 0x00F47548
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicConsumeOk::Populate(AMQPBasicConsumeOk *this, idStr *frame)
{
  idMQFrame *v3; // r28
  size_t v4; // r29
  __int64 v5; // r6
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r4
  int v9; // [sp+8h] [-98h]
  int v10; // [sp+Ch] [-94h]
  int v11; // [sp+10h] [-90h]
  int v12; // [sp+14h] [-8Ch]
  idMQFrame v13; // [sp+50h] [-50h] BYREF

  v3 = idMQFrame::ReadShortString(this: &v13, result: frame);
  v4 = *(_DWORD *)&v3->type;
  idStr::EnsureAlloced(
    this: &this->consumerTag,
    amount: *(_DWORD *)&v3->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->consumerTag.data, Src: v3->data.list, Size: v4);
  this->consumerTag.data[v4] = 0;
  this->consumerTag.len = v4;
  idStr::FreeData(this: (idStr *)&v13);
  HIDWORD(v6) = allocationCurrent[242];
  LODWORD(v7) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v8) = this->consumerTag.data;
    HIDWORD(v8) = "AMQP <<: AMQPBasicConsumeOk consumerTag=%s\n";
    idLib::Printf(fmt: v8, a2: v5, a3: v7, a4: v6, a5: v9, a6: v10, a7: v11, a8: v12);
  }
}


// ========================================================================
// __unwind$120042
// EA  : 0x82F475D4
// RVA : 0x00F475D4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120042()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Populate@AMQPBasicCancel@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F47608
// RVA : 0x00F47608
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicCancel::Populate(AMQPBasicCancel *this, idStr *frame)
{
  idMQFrame *v4; // r27
  size_t v5; // r29
  __int64 v6; // r6
  bool Bool; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r4
  int v11; // [sp+8h] [-98h]
  int v12; // [sp+Ch] [-94h]
  int v13; // [sp+10h] [-90h]
  int v14; // [sp+14h] [-8Ch]
  idMQFrame v15; // [sp+50h] [-50h] BYREF

  v4 = idMQFrame::ReadShortString(this: &v15, result: frame);
  v5 = *(_DWORD *)&v4->type;
  idStr::EnsureAlloced(
    this: &this->consumerTag,
    amount: *(_DWORD *)&v4->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->consumerTag.data, Src: v4->data.list, Size: v5);
  this->consumerTag.data[v5] = 0;
  this->consumerTag.len = v5;
  idStr::FreeData(this: (idStr *)&v15);
  Bool = idMQFrame::ReadBool(this: (idMQFrame *)frame);
  HIDWORD(v8) = allocationCurrent[242];
  this->noWait = Bool;
  LODWORD(v9) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v10) = this->consumerTag.data;
    HIDWORD(v6) = Bool;
    HIDWORD(v10) = "AMQP <<: AMQPBasicCancel consumerTag=%s, noWait=%d\n";
    idLib::Printf(fmt: v10, a2: v6, a3: v9, a4: v8, a5: v11, a6: v12, a7: v13, a8: v14);
  }
}


// ========================================================================
// __unwind$120082
// EA  : 0x82F476A8
// RVA : 0x00F476A8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120082()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Populate@AMQPBasicCancelOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F476D8
// RVA : 0x00F476D8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicCancelOk::Populate(AMQPBasicCancelOk *this, idStr *frame)
{
  idMQFrame *v3; // r28
  size_t v4; // r29
  __int64 v5; // r6
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r4
  int v9; // [sp+8h] [-98h]
  int v10; // [sp+Ch] [-94h]
  int v11; // [sp+10h] [-90h]
  int v12; // [sp+14h] [-8Ch]
  idMQFrame v13; // [sp+50h] [-50h] BYREF

  v3 = idMQFrame::ReadShortString(this: &v13, result: frame);
  v4 = *(_DWORD *)&v3->type;
  idStr::EnsureAlloced(
    this: &this->consumerTag,
    amount: *(_DWORD *)&v3->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->consumerTag.data, Src: v3->data.list, Size: v4);
  this->consumerTag.data[v4] = 0;
  this->consumerTag.len = v4;
  idStr::FreeData(this: (idStr *)&v13);
  HIDWORD(v6) = allocationCurrent[242];
  LODWORD(v7) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v8) = this->consumerTag.data;
    HIDWORD(v8) = "AMQP <<: AMQPBasicCancelOk consumerTag=%s\n";
    idLib::Printf(fmt: v8, a2: v5, a3: v7, a4: v6, a5: v9, a6: v10, a7: v11, a8: v12);
  }
}


// ========================================================================
// __unwind$120122
// EA  : 0x82F47764
// RVA : 0x00F47764
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120122()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Populate@AMQPBasicPublish@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F47798
// RVA : 0x00F47798
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicPublish::Populate(AMQPBasicPublish *this, idMQFrame *frame)
{
  idMQFrame *ShortString; // r28
  size_t v5; // r29
  idMQFrame *v6; // r26
  size_t v7; // r29
  bool Bool; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  __int64 v12; // r4
  int v13; // [sp+8h] [-C8h]
  int v14; // [sp+Ch] [-C4h]
  int v15; // [sp+10h] [-C0h]
  int v16; // [sp+14h] [-BCh]
  idMQFrame v17[2]; // [sp+50h] [-80h] BYREF

  this->ticket = idMQFrame::ReadUInt16(this: frame);
  ShortString = idMQFrame::ReadShortString(this: v17, result: (idStr *)frame);
  v5 = *(_DWORD *)&ShortString->type;
  idStr::EnsureAlloced(
    this: &this->exchange,
    amount: *(_DWORD *)&ShortString->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->exchange.data, Src: ShortString->data.list, Size: v5);
  this->exchange.data[v5] = 0;
  this->exchange.len = v5;
  idStr::FreeData(this: (idStr *)v17);
  v6 = idMQFrame::ReadShortString(this: (idMQFrame *)&v17[0].flushWriteBitBuffer, result: (idStr *)frame);
  v7 = *(_DWORD *)&v6->type;
  idStr::EnsureAlloced(
    this: &this->routingKey,
    amount: *(_DWORD *)&v6->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->routingKey.data, Src: v6->data.list, Size: v7);
  this->routingKey.data[v7] = 0;
  this->routingKey.len = v7;
  idStr::FreeData(this: (idStr *)&v17[0].flushWriteBitBuffer);
  this->mandatory = idMQFrame::ReadBool(this: frame);
  Bool = idMQFrame::ReadBool(this: frame);
  HIDWORD(v9) = allocationCurrent[242];
  this->immediate = Bool;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v10) = this->mandatory;
    LODWORD(v10) = Bool;
    LODWORD(v11) = this->routingKey.data;
    HIDWORD(v12) = "AMQP <<: AMQPBasicPublish ticket=%d, exchange=%s, routingKey=%s, mandatory=%d, immediate=%d\n";
    HIDWORD(v11) = this->exchange.data;
    LODWORD(v12) = this->ticket;
    idLib::Printf(fmt: v12, a2: v11, a3: v10, a4: v9, a5: v13, a6: v14, a7: v15, a8: v16);
  }
}


// ========================================================================
// __unwind$120163
// EA  : 0x82F478AC
// RVA : 0x00F478AC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120163()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// __unwind$120164
// EA  : 0x82F478D4
// RVA : 0x00F478D4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120164()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ?Populate@AMQPBasicReturn@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F47908
// RVA : 0x00F47908
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicReturn::Populate(AMQPBasicReturn *this, idMQFrame *frame)
{
  idMQFrame *v4; // r28
  size_t v5; // r29
  idMQFrame *ShortString; // r26
  size_t v7; // r29
  idMQFrame *v8; // r27
  size_t v9; // r29
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r4
  int v14; // [sp+8h] [-E8h]
  int v15; // [sp+Ch] [-E4h]
  int v16; // [sp+10h] [-E0h]
  int v17; // [sp+14h] [-DCh]
  idMQFrame v18; // [sp+50h] [-A0h] BYREF
  idMQFrame v19[2]; // [sp+90h] [-60h] BYREF

  this->replyCode = idMQFrame::ReadUInt16(this: frame);
  v4 = idMQFrame::ReadShortString(this: &v18, result: (idStr *)frame);
  v5 = *(_DWORD *)&v4->type;
  idStr::EnsureAlloced(this: &this->replyText, amount: *(_DWORD *)&v4->type + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->replyText.data, Src: v4->data.list, Size: v5);
  this->replyText.data[v5] = 0;
  this->replyText.len = v5;
  idStr::FreeData(this: (idStr *)&v18);
  ShortString = idMQFrame::ReadShortString(this: (idMQFrame *)&v18.flushWriteBitBuffer, result: (idStr *)frame);
  v7 = *(_DWORD *)&ShortString->type;
  idStr::EnsureAlloced(
    this: &this->exchange,
    amount: *(_DWORD *)&ShortString->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->exchange.data, Src: ShortString->data.list, Size: v7);
  this->exchange.data[v7] = 0;
  this->exchange.len = v7;
  idStr::FreeData(this: (idStr *)&v18.flushWriteBitBuffer);
  v8 = idMQFrame::ReadShortString(this: v19, result: (idStr *)frame);
  v9 = *(_DWORD *)&v8->type;
  idStr::EnsureAlloced(
    this: &this->routingKey,
    amount: *(_DWORD *)&v8->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->routingKey.data, Src: v8->data.list, Size: v9);
  this->routingKey.data[v9] = 0;
  this->routingKey.len = v9;
  idStr::FreeData(this: (idStr *)v19);
  LODWORD(v11) = allocationCurrent[242];
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v11) = this->routingKey.data;
    LODWORD(v12) = this->exchange.data;
    HIDWORD(v13) = "AMQP <<: AMQPBasicReturn replyCode=%d, replyText=%s, exchange=%s, routingKey=%s\n";
    HIDWORD(v12) = this->replyText.data;
    LODWORD(v13) = this->replyCode;
    idLib::Printf(fmt: v13, a2: v12, a3: v11, a4: v10, a5: v14, a6: v15, a7: v16, a8: v17);
  }
}


// ========================================================================
// __unwind$120230
// EA  : 0x82F47A4C
// RVA : 0x00F47A4C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120230()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$120231
// EA  : 0x82F47A74
// RVA : 0x00F47A74
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120231()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$120232
// EA  : 0x82F47A9C
// RVA : 0x00F47A9C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120232()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// ?Populate@AMQPBasicDeliver@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F47AD0
// RVA : 0x00F47AD0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall AMQPBasicDeliver::Populate(AMQPBasicDeliver *this, idStr *frame)
{
  idMQFrame *v4; // r28
  size_t v5; // r29
  unsigned __int64 v6; // r3
  idMQFrame *ShortString; // r26
  size_t v8; // r29
  idMQFrame *v9; // r27
  size_t v10; // r29
  __int64 v11; // r10
  __int64 v12; // r8
  __int128 v13; // r5 OVERLAPPED
  BOOL redelivered; // r6
  int v15; // [sp+8h] [-E8h]
  int v16; // [sp+Ch] [-E4h]
  int v17; // [sp+10h] [-E0h]
  int v18; // [sp+14h] [-DCh]
  idMQFrame v19; // [sp+50h] [-A0h] BYREF
  idMQFrame v20[2]; // [sp+90h] [-60h] BYREF

  v4 = idMQFrame::ReadShortString(this: &v19, result: frame);
  v5 = *(_DWORD *)&v4->type;
  idStr::EnsureAlloced(
    this: &this->consumerTag,
    amount: *(_DWORD *)&v4->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->consumerTag.data, Src: v4->data.list, Size: v5);
  this->consumerTag.data[v5] = 0;
  this->consumerTag.len = v5;
  idStr::FreeData(this: (idStr *)&v19);
  LODWORD(v6) = idMQFrame::ReadUInt64(this: (idMQFrame *)frame);
  this->deliveryTag = v6;
  this->redelivered = idMQFrame::ReadBool(this: (idMQFrame *)frame);
  ShortString = idMQFrame::ReadShortString(this: (idMQFrame *)&v19.flushWriteBitBuffer, result: frame);
  v8 = *(_DWORD *)&ShortString->type;
  idStr::EnsureAlloced(
    this: &this->exchange,
    amount: *(_DWORD *)&ShortString->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->exchange.data, Src: ShortString->data.list, Size: v8);
  this->exchange.data[v8] = 0;
  this->exchange.len = v8;
  idStr::FreeData(this: (idStr *)&v19.flushWriteBitBuffer);
  v9 = idMQFrame::ReadShortString(this: v20, result: frame);
  v10 = *(_DWORD *)&v9->type;
  idStr::EnsureAlloced(
    this: &this->routingKey,
    amount: *(_DWORD *)&v9->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->routingKey.data, Src: v9->data.list, Size: v10);
  this->routingKey.data[v10] = 0;
  this->routingKey.len = v10;
  idStr::FreeData(this: (idStr *)v20);
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v12) = this->routingKey.data;
    HIDWORD(v12) = this->exchange.data;
    DWORD1(v13) = "AMQP <<: AMQPBasicDeliver consumerTag=%s, deliveryTag=%llu, redelivered=%d, exchange=%s, routingKey=%s\n";
    redelivered = this->redelivered;
    *((_QWORD *)&v13 + 1) = this->deliveryTag;
    DWORD2(v13) = this->consumerTag.data;
    idLib::Printf(
      fmt: *(__int64 *)((char *)&v13 + 4),
      a2: *(__int64 *)((char *)&v13 - 4),
      a3: v12,
      a4: v11,
      a5: v15,
      a6: v16,
      a7: v17,
      a8: v18);
  }
}


// ========================================================================
// __unwind$120322
// EA  : 0x82F47C20
// RVA : 0x00F47C20
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120322()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$120323
// EA  : 0x82F47C48
// RVA : 0x00F47C48
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120323()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$120324
// EA  : 0x82F47C70
// RVA : 0x00F47C70
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120324()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// ?Populate@AMQPBasicGet@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F47CA0
// RVA : 0x00F47CA0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicGet::Populate(AMQPBasicGet *this, idMQFrame *frame)
{
  idMQFrame *v4; // r27
  size_t v5; // r29
  bool Bool; // r3
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r4
  int v11; // [sp+8h] [-98h]
  int v12; // [sp+Ch] [-94h]
  int v13; // [sp+10h] [-90h]
  int v14; // [sp+14h] [-8Ch]
  idMQFrame v15; // [sp+50h] [-50h] BYREF

  this->ticket = idMQFrame::ReadUInt16(this: frame);
  v4 = idMQFrame::ReadShortString(this: &v15, result: (idStr *)frame);
  v5 = *(_DWORD *)&v4->type;
  idStr::EnsureAlloced(this: &this->queue, amount: *(_DWORD *)&v4->type + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->queue.data, Src: v4->data.list, Size: v5);
  this->queue.data[v5] = 0;
  this->queue.len = v5;
  idStr::FreeData(this: (idStr *)&v15);
  Bool = idMQFrame::ReadBool(this: frame);
  HIDWORD(v7) = allocationCurrent[242];
  this->noAck = Bool;
  LODWORD(v8) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v9) = this->queue.data;
    LODWORD(v9) = Bool;
    LODWORD(v10) = this->ticket;
    HIDWORD(v10) = "AMQP <<: AMQPBasicGet ticket=%d, queue=%s, noAck=%d\n";
    idLib::Printf(fmt: v10, a2: v9, a3: v8, a4: v7, a5: v11, a6: v12, a7: v13, a8: v14);
  }
}


// ========================================================================
// __unwind$120412
// EA  : 0x82F47D54
// RVA : 0x00F47D54
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120412()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Populate@AMQPBasicGetOk@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F47D88
// RVA : 0x00F47D88
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicGetOk::Populate(AMQPBasicGetOk *this, idMQFrame *frame)
{
  unsigned __int64 v4; // r3
  idMQFrame *ShortString; // r28
  size_t v6; // r29
  idMQFrame *v7; // r26
  size_t v8; // r29
  unsigned int UInt32; // r3
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  int v13; // [sp+8h] [-C8h]
  int v14; // [sp+Ch] [-C4h]
  int v15; // [sp+10h] [-C0h]
  int v16; // [sp+14h] [-BCh]
  idMQFrame v17[2]; // [sp+50h] [-80h] BYREF

  LODWORD(v4) = idMQFrame::ReadUInt64(this: frame);
  this->deliveryTag = v4;
  this->redelivered = idMQFrame::ReadBool(this: frame);
  ShortString = idMQFrame::ReadShortString(this: v17, result: (idStr *)frame);
  v6 = *(_DWORD *)&ShortString->type;
  idStr::EnsureAlloced(
    this: &this->exchange,
    amount: *(_DWORD *)&ShortString->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->exchange.data, Src: ShortString->data.list, Size: v6);
  this->exchange.data[v6] = 0;
  this->exchange.len = v6;
  idStr::FreeData(this: (idStr *)v17);
  v7 = idMQFrame::ReadShortString(this: (idMQFrame *)&v17[0].flushWriteBitBuffer, result: (idStr *)frame);
  v8 = *(_DWORD *)&v7->type;
  idStr::EnsureAlloced(
    this: &this->routingKey,
    amount: *(_DWORD *)&v7->type + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->routingKey.data, Src: v7->data.list, Size: v8);
  this->routingKey.data[v8] = 0;
  this->routingKey.len = v8;
  idStr::FreeData(this: (idStr *)&v17[0].flushWriteBitBuffer);
  UInt32 = idMQFrame::ReadUInt32(this: frame);
  HIDWORD(v10) = allocationCurrent[242];
  this->messageCount = UInt32;
  LODWORD(v11) = UInt32;
  if ( mq_verbose.valueInteger != 0 )
  {
    HIDWORD(v11) = this->routingKey.data;
    LODWORD(v12) = this->exchange.data;
    HIDWORD(v12) = this->redelivered;
    idLib::Printf(fmt: this->deliveryTag, a2: v12, a3: v11, a4: v10, a5: v13, a6: v14, a7: v15, a8: v16);
  }
}


// ========================================================================
// __unwind$120453
// EA  : 0x82F47E9C
// RVA : 0x00F47E9C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120453()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// __unwind$120454
// EA  : 0x82F47EC4
// RVA : 0x00F47EC4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120454()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ?Populate@AMQPBasicGetEmpty@@UAAXAAVidMQFrame@@@Z
// EA  : 0x82F47EF8
// RVA : 0x00F47EF8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicGetEmpty::Populate(AMQPBasicGetEmpty *this, idStr *frame)
{
  idMQFrame *v3; // r28
  size_t v4; // r29
  __int64 v5; // r6
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r4
  int v9; // [sp+8h] [-98h]
  int v10; // [sp+Ch] [-94h]
  int v11; // [sp+10h] [-90h]
  int v12; // [sp+14h] [-8Ch]
  idMQFrame v13; // [sp+50h] [-50h] BYREF

  v3 = idMQFrame::ReadShortString(this: &v13, result: frame);
  v4 = *(_DWORD *)&v3->type;
  idStr::EnsureAlloced(this: &this->clusterId, amount: *(_DWORD *)&v3->type + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->clusterId.data, Src: v3->data.list, Size: v4);
  this->clusterId.data[v4] = 0;
  this->clusterId.len = v4;
  idStr::FreeData(this: (idStr *)&v13);
  HIDWORD(v6) = allocationCurrent[242];
  LODWORD(v7) = &mq_verbose;
  if ( mq_verbose.valueInteger != 0 )
  {
    LODWORD(v8) = this->clusterId.data;
    HIDWORD(v8) = "AMQP <<: AMQPBasicGetEmpty clusterId=%s\n";
    idLib::Printf(fmt: v8, a2: v5, a3: v7, a4: v6, a5: v9, a6: v10, a7: v11, a8: v12);
  }
}


// ========================================================================
// __unwind$120518
// EA  : 0x82F47F84
// RVA : 0x00F47F84
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120518()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ??0AMQPBasicProperties@@QAA@XZ
// EA  : 0x82F47FB8
// RVA : 0x00F47FB8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

AMQPBasicProperties *__fastcall AMQPBasicProperties::AMQPBasicProperties(AMQPBasicProperties *this)
{
  unsigned __int64 v1; // r29

  LODWORD(v1) = 0;
  this->bodyLength = v1;
  HIDWORD(v1) = 20;
  this->__vftable = (AMQPBasicProperties_vtbl *)&AMQPBasicProperties::`vftable';
  this->contentType.allocedAndFlag = 20;
  this->contentType.data = this->contentType.baseBuffer;
  this->contentType.len = 0;
  this->contentType.baseBuffer[0] = 0;
  this->contentEncoding.allocedAndFlag = 20;
  this->contentEncoding.len = 0;
  this->contentEncoding.data = this->contentEncoding.baseBuffer;
  this->contentEncoding.baseBuffer[0] = 0;
  idDict::idDict(this: &this->headers);
  this->deliveryMode = 0;
  this->priority = 0;
  this->correlationId.allocedAndFlag = 20;
  this->correlationId.data = this->correlationId.baseBuffer;
  this->correlationId.len = 0;
  this->correlationId.baseBuffer[0] = 0;
  this->replyTo.data = this->replyTo.baseBuffer;
  this->replyTo.allocedAndFlag = 20;
  this->replyTo.len = 0;
  this->replyTo.baseBuffer[0] = 0;
  this->expiration.data = this->expiration.baseBuffer;
  this->expiration.allocedAndFlag = 20;
  this->expiration.len = 0;
  this->expiration.baseBuffer[0] = 0;
  this->messageId.data = this->messageId.baseBuffer;
  this->messageId.allocedAndFlag = 20;
  this->messageId.len = 0;
  this->messageId.baseBuffer[0] = 0;
  this->timestamp = v1;
  this->type.data = this->type.baseBuffer;
  this->type.allocedAndFlag = 20;
  this->type.len = 0;
  this->type.baseBuffer[0] = 0;
  this->userId.data = this->userId.baseBuffer;
  this->userId.allocedAndFlag = 20;
  this->userId.len = 0;
  this->userId.baseBuffer[0] = 0;
  this->appId.data = this->appId.baseBuffer;
  this->appId.allocedAndFlag = 20;
  this->appId.len = 0;
  this->appId.baseBuffer[0] = 0;
  this->clusterId.allocedAndFlag = 20;
  this->clusterId.data = this->clusterId.baseBuffer;
  this->clusterId.len = 0;
  this->clusterId.baseBuffer[0] = 0;
  this->b_contentType = false;
  this->b_contentEncoding = false;
  this->b_headers = false;
  this->b_deliveryMode = false;
  this->b_priority = false;
  this->b_correlationId = false;
  this->b_replyTo = false;
  this->b_expiration = false;
  this->b_messageId = false;
  this->b_timestamp = false;
  this->b_type = false;
  this->b_userId = false;
  this->b_appId = false;
  this->b_clusterId = false;
  return this;
}


// ========================================================================
// __unwind$120680
// EA  : 0x82F48130
// RVA : 0x00F48130
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120680()
{
  int v0; // r12

  idMQContentHeader::~idMQContentHeader(this: *(idMQContentHeader **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$120681
// EA  : 0x82F48158
// RVA : 0x00F48158
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120681()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$120682
// EA  : 0x82F48184
// RVA : 0x00F48184
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120682()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 48));
}


// ========================================================================
// ??1AMQPBasicProperties@@UAA@XZ
// EA  : 0x82F481B8
// RVA : 0x00F481B8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void __fastcall AMQPBasicProperties::~AMQPBasicProperties(AMQPBasicProperties *this)
{
  this->__vftable = (AMQPBasicProperties_vtbl *)&AMQPBasicProperties::`vftable';
  idStr::FreeData(this: &this->clusterId);
  idStr::FreeData(this: &this->appId);
  idStr::FreeData(this: &this->userId);
  idStr::FreeData(this: &this->type);
  idStr::FreeData(this: &this->messageId);
  idStr::FreeData(this: &this->expiration);
  idStr::FreeData(this: &this->replyTo);
  idStr::FreeData(this: &this->correlationId);
  idDict::~idDict(this: &this->headers);
  idStr::FreeData(this: &this->contentEncoding);
  idStr::FreeData(this: &this->contentType);
  this->__vftable = (AMQPBasicProperties_vtbl *)&idMQContentHeader::`vftable';
}


// ========================================================================
// __unwind$120951
// EA  : 0x82F48260
// RVA : 0x00F48260
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120951()
{
  int v0; // r12

  idMQContentHeader::~idMQContentHeader(this: *(idMQContentHeader **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$120952
// EA  : 0x82F48288
// RVA : 0x00F48288
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120952()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// __unwind$120953
// EA  : 0x82F482B4
// RVA : 0x00F482B4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120953()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 48));
}


// ========================================================================
// __unwind$120954
// EA  : 0x82F482E0
// RVA : 0x00F482E0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120954()
{
  int v0; // r12

  idDict::~idDict(this: (idDict *)(*(_DWORD *)(v0 - 112 + 132) + 80));
}


// ========================================================================
// __unwind$120955
// EA  : 0x82F4830C
// RVA : 0x00F4830C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120955()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 132));
}


// ========================================================================
// __unwind$120956
// EA  : 0x82F48338
// RVA : 0x00F48338
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120956()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// __unwind$120957
// EA  : 0x82F48364
// RVA : 0x00F48364
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120957()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 196));
}


// ========================================================================
// __unwind$120958
// EA  : 0x82F48390
// RVA : 0x00F48390
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120958()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 228));
}


// ========================================================================
// __unwind$120959
// EA  : 0x82F483BC
// RVA : 0x00F483BC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120959()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 272));
}


// ========================================================================
// __unwind$120960
// EA  : 0x82F483E8
// RVA : 0x00F483E8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120960()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 304));
}


// ========================================================================
// __unwind$120961
// EA  : 0x82F48414
// RVA : 0x00F48414
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.cpp
// ========================================================================

void _unwind_120961()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 336));
}

