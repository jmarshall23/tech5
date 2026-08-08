
// ========================================================================
// ?EncodeBase64@idSMTP@@AAAHPAEHPAPAE@Z
// EA  : 0x8289C908
// RVA : 0x0089C908
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

unsigned __int8 *__fastcall idSMTP::EncodeBase64(
        idSMTP *this,
        unsigned __int8 *jpgBuffer,
        unsigned int jpgBufferLen,
        unsigned __int8 **base64Buffer)
{
  unsigned __int8 *result; // r3
  unsigned __int8 *v8; // r11
  int v9; // r9
  unsigned int v10; // ctr
  _BYTE *v11; // r11
  unsigned __int8 v12; // r5
  _BYTE *v13; // r11
  unsigned __int8 *v14; // r10
  _BYTE *v15; // r11
  _BYTE *v16; // r11
  char v17[112]; // [sp+50h] [-70h] BYREF

  strcpy(v17, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");
  result = (unsigned __int8 *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\engine\\network\\SMTP.cpp(292) : TAG_NETWORKING",
                                size: 2 * (((int)(8 * jpgBufferLen) / 6 + 4) / 76 + 1) + (int)(8 * jpgBufferLen) / 6 + 4,
                                tag: TAG_NETWORKING,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  v8 = result;
  *base64Buffer = result;
  if ( result != nullptr )
  {
    v9 = 0;
    if ( (int)jpgBufferLen >= 3 )
    {
      v10 = jpgBufferLen / 3;
      jpgBufferLen %= 3u;
      do
      {
        v9 += 4;
        *v8 = v17[*jpgBuffer >> 2];
        v11 = v8 + 1;
        *v11 = v17[(16 * *jpgBuffer) & 0x30 | (jpgBuffer[1] >> 4)];
        v11[1] = v17[(4 * jpgBuffer[1]) & 0x3C | (jpgBuffer[2] >> 6)];
        v12 = jpgBuffer[2];
        jpgBuffer += 3;
        v11[2] = v17[v12 & 0x3F];
        v8 = v11 + 3;
        if ( v9 >= 76 )
        {
          *v8 = 13;
          v9 = 0;
          v8[1] = 10;
          v8 += 2;
        }
        --v10;
      }
      while ( v10 != 0 );
    }
    if ( jpgBufferLen != 0 )
    {
      *v8 = v17[*jpgBuffer >> 2];
      v13 = v8 + 1;
      if ( jpgBufferLen == 1 )
      {
        *v13 = v17[(16 * *jpgBuffer) & 0x30];
        v13[1] = 61;
        v16 = v13 + 2;
        *v16 = 61;
      }
      else
      {
        v14 = jpgBuffer + 1;
        *v13 = v17[(16 * *jpgBuffer) & 0x30 | (jpgBuffer[1] >> 4)];
        v15 = v13 + 1;
        if ( jpgBufferLen == 2 )
        {
          *v15 = v17[(4 * *v14) & 0x3C];
          v16 = v15 + 1;
          *v16 = 61;
        }
        else
        {
          *v15 = v17[(4 * *v14) & 0x3C | (jpgBuffer[2] >> 6)];
          v16 = v15 + 1;
          *v16 = v17[jpgBuffer[2] & 0x3F];
        }
      }
      v8 = v16 + 1;
    }
    *v8 = 0;
    return (unsigned __int8 *)(v8 - *base64Buffer + 1);
  }
  return result;
}


// ========================================================================
// ?RecvFromServer@idSMTP@@AAA_NPBD@Z
// EA  : 0x8289CB48
// RVA : 0x0089CB48
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

int __fastcall idSMTP::RecvFromServer(idSMTP *this, const char *expected)
{
  int v4; // r30
  int v5; // r31
  char v8[80]; // [sp+50h] [-1050h] BYREF

  if ( !idTCP::Select(this: &this->tcp, timeoutMS: 32000) )
  {
LABEL_20:
    idLib::Warning(fmt: "SMTP Timeout while waiting for reply to %s", expected);
    return 0;
  }
  if ( smtp_debug.valueInteger != 0 )
    idLib::Printf(fmt: "SMTP Recv: ");
  v4 = -1;
  v5 = idTCP::Read(this: &this->tcp, data: v8, size: 4095);
  if ( v5 > 0 )
  {
    while ( 1 )
    {
      v8[v5] = 0;
      if ( v4 < 0 )
        v4 = (unsigned __int8)v8[0];
      if ( smtp_debug.valueInteger != 0 )
        idLib::Printf(fmt: "%s", v8);
      if ( v8[v5 - 1] == 10 )
      {
        if ( v4 != 53 )
          return 1;
        idLib::Warning(fmt: "SMTP Error in reply to %s", expected);
        return 0;
      }
      if ( !idTCP::Select(this: &this->tcp, timeoutMS: 32000) )
        break;
      v5 = idTCP::Read(this: &this->tcp, data: v8, size: 4095);
      if ( v5 <= 0 )
        goto LABEL_12;
    }
    if ( smtp_debug.valueInteger != 0 )
      idLib::Printf(fmt: "...\n");
    goto LABEL_20;
  }
LABEL_12:
  if ( smtp_debug.valueInteger != 0 )
    idLib::Printf(fmt: "...\n");
  idLib::Warning(fmt: "SMTP Error while waiting for a reply to %s", expected);
  return 0;
}


// ========================================================================
// ?SendToServer@idSMTP@@AAA_NPBD@Z
// EA  : 0x8289CCD8
// RVA : 0x0089CCD8
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

unsigned int __fastcall idSMTP::SendToServer(idSMTP *this, const char *buf)
{
  int v4; // r5
  int v5; // r3
  idStr v7[2]; // [sp+50h] [-50h] BYREF

  if ( smtp_debug.valueInteger != 0 )
  {
    idStr::idStr(this: v7, text: buf);
    idStr::Replace(this: v7, old: "\r\n", nw: "\n");
    idStr::Replace(this: v7, old: "\n", nw: "<nl>");
    idStr::StripTrailing(this: v7, string: "<nl>");
    if ( v7[0].len <= 50 )
      idLib::Printf(fmt: "SMTP Send: %s\n", v7[0].data);
    else
      idLib::Printf(fmt: "SMTP Send: %50s...\n", v7[0].data);
    idStr::FreeData(this: v7);
  }
  v4 = 0;
  if ( *buf != 0 )
  {
    do
      ++v4;
    while ( buf[v4] != 0 );
  }
  v5 = idTCP::Write(this: &this->tcp, data: buf, size: v4);
  return (-v5 & (unsigned int)~v5) >> 31;
}


// ========================================================================
// __unwind$219865_0
// EA  : 0x8289CDBC
// RVA : 0x0089CDBC
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

void _unwind_219865_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?SendEmail@idSMTP@@QAAXAAUemailData_t@@@Z
// EA  : 0x8289CDF0
// RVA : 0x0089CDF0
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

void __fastcall idSMTP::SendEmail(idSMTP *this, emailData_t *data)
{
  __int64 v4; // r8
  __int64 v5; // r6
  __int64 v6; // r10
  va *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  va *v11; // r3
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  int v15; // r27
  int v16; // r29
  va *v17; // r3
  __int64 v18; // r3
  tm *v19; // r3
  int tm_mon; // r28
  int tm_year; // r11
  __int64 v22; // r10
  __int64 v23; // r8
  __int64 v24; // r6
  va *v25; // r3
  int v26; // r29
  int v27; // r28
  idStr *p_attachment; // r28
  unsigned int v29; // r3
  char *v30; // r30
  char *v31; // r4
  int v32; // [sp+8h] [-21E8h]
  int v33; // [sp+8h] [-21E8h]
  int v34; // [sp+8h] [-21E8h]
  int v35; // [sp+Ch] [-21E4h]
  int v36; // [sp+Ch] [-21E4h]
  int v37; // [sp+Ch] [-21E4h]
  int v38; // [sp+10h] [-21E0h]
  int v39; // [sp+10h] [-21E0h]
  int v40; // [sp+10h] [-21E0h]
  int v41; // [sp+14h] [-21DCh]
  int v42; // [sp+14h] [-21DCh]
  int v43; // [sp+14h] [-21DCh]
  int v44; // [sp+18h] [-21D8h]
  int v45; // [sp+18h] [-21D8h]
  int v46; // [sp+18h] [-21D8h]
  int v47; // [sp+1Ch] [-21D4h]
  int v48; // [sp+1Ch] [-21D4h]
  int v49; // [sp+1Ch] [-21D4h]
  idStr v50; // [sp+50h] [-21A0h] BYREF
  unsigned __int8 *v51; // [sp+70h] [-2180h] BYREF
  char *v52; // [sp+74h] [-217Ch] BYREF
  idStr v53; // [sp+80h] [-2170h] BYREF
  idStr v54; // [sp+A0h] [-2150h] BYREF
  idStr v55; // [sp+C0h] [-2130h] BYREF
  idStr v56; // [sp+E0h] [-2110h] BYREF
  idStr v57; // [sp+100h] [-20F0h] BYREF
  _DWORD v58[12]; // [sp+120h] [-20D0h] BYREF
  __int64 v59; // [sp+150h] [-20A0h] BYREF
  va v60; // [sp+160h] [-2090h] BYREF
  va v61; // [sp+1160h] [-1090h] BYREF

  if ( !idTCP::Connect(
          this: &this->tcp,
          host: data->server.data,
          port: 0x19u,
          nonBlocking: true,
          silent: false,
          nagle: false) )
  {
    idLib::Warning(fmt: "SMTP: Could not connect to server %s", data->server.data);
    return;
  }
  if ( (unsigned __int8)idSMTP::RecvFromServer(this, expected: "hello from server") != 0 )
  {
    LODWORD(v6) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
    HIDWORD(v6) = &smtp_domain;
    HIDWORD(v5) = smtp_domain.valueString.data;
    v7 = va::va(
           this: &v60,
           fmt: "HELO %s\r\n",
           a3: v5,
           a4: v4,
           a5: v6,
           a6: v32,
           a7: v35,
           a8: v38,
           a9: v41,
           a10: v44,
           a11: v47);
    idStr::idStr(this: &v53, text: v7);
    if ( (unsigned __int8)idSMTP::SendToServer(this, buf: v53.data) != 0 )
    {
      LODWORD(v8) = (unsigned __int8)idSMTP::RecvFromServer(this, expected: "reply to HELO");
      if ( (_DWORD)v8 != 0 )
      {
        HIDWORD(v10) = data->senderEmail.data;
        v11 = va::va(
                this: &v61,
                fmt: "MAIL FROM: <%s>\r\n",
                a3: v10,
                a4: v9,
                a5: v8,
                a6: v33,
                a7: v36,
                a8: v39,
                a9: v42,
                a10: v45,
                a11: v48);
        if ( (unsigned __int8)idSMTP::SendToServer(this, buf: v11->buffer) != 0
          && (unsigned __int8)idSMTP::RecvFromServer(this, expected: "reply to MAIL FROM") != 0 )
        {
          v15 = 0;
          if ( data->recipientEmail.num > 0 )
          {
            LODWORD(v12) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
            v16 = 0;
            do
            {
              HIDWORD(v14) = data->recipientEmail.list[v16].data;
              v17 = va::va(
                      this: &v61,
                      fmt: "RCPT TO: <%s>\r\n",
                      a3: v14,
                      a4: v13,
                      a5: v12,
                      a6: v34,
                      a7: v37,
                      a8: v40,
                      a9: v43,
                      a10: v46,
                      a11: v49);
              if ( (unsigned __int8)idSMTP::SendToServer(this, buf: v17->buffer) == 0
                || (unsigned __int8)idSMTP::RecvFromServer(this, expected: "reply to RCPT TO") == 0 )
              {
                goto _M220426;
              }
              ++v15;
              ++v16;
            }
            while ( v15 < data->recipientEmail.num );
          }
          if ( (unsigned __int8)idSMTP::SendToServer(this, buf: "DATA\r\n") != 0
            && (unsigned __int8)idSMTP::RecvFromServer(this, expected: "reply to DATA") != 0 )
          {
            v50.len = 0;
            v50.baseBuffer[0] = 0;
            v50.allocedAndFlag = 20;
            v50.data = v50.baseBuffer;
            LODWORD(v18) = (unsigned __int64)time64(timeptr: nullptr) >> 32;
            v59 = v18;
            v19 = gmtime64(timp: &v59);
            tm_mon = v19->tm_mon;
            tm_year = v19->tm_year;
            LODWORD(v22) = v19->tm_sec;
            v58[0] = "Jan";
            HIDWORD(v22) = v19->tm_min;
            LODWORD(v23) = v19->tm_hour;
            v58[1] = "Feb";
            HIDWORD(v24) = v19->tm_mday;
            v58[2] = "Mar";
            v58[3] = "Apr";
            v58[4] = "May";
            v58[5] = "Jun";
            v58[6] = "Jul";
            v58[7] = "Aug";
            v58[8] = "Sep";
            v58[9] = "Oct";
            v58[10] = "Nov";
            v58[11] = "Dec";
            HIDWORD(v23) = tm_year + 1900;
            LODWORD(v24) = v58[tm_mon];
            v25 = va::va(
                    this: &v61,
                    fmt: "%d %s %d %02d:%02d:%02d GMT",
                    a3: v24,
                    a4: v23,
                    a5: v22,
                    a6: v34,
                    a7: v37,
                    a8: v40,
                    a9: v43,
                    a10: v46,
                    a11: v49);
            idStr::idStr(this: &v54, text: v25);
            idStr::operator=(this: &v50, text: "Date: ");
            idStr::Append(this: &v50, text: &v54);
            idStr::Append(this: &v50, text: "\r\n");
            idStr::Append(this: &v50, text: "From: ");
            idStr::Append(this: &v50, text: &data->senderName);
            idStr::Append(this: &v50, text: " <");
            idStr::Append(this: &v50, text: &data->senderEmail);
            idStr::Append(this: &v50, text: ">\r\n");
            idStr::Append(this: &v50, text: "To: ");
            v26 = 0;
            if ( data->recipientEmail.num > 0 )
            {
              v27 = 0;
              do
              {
                idStr::Append(this: &v50, text: &data->recipientEmail.list[v27]);
                if ( v26 < data->recipientEmail.num - 1 )
                  idStr::Append(this: &v50, text: ",");
                ++v26;
                ++v27;
              }
              while ( v26 < data->recipientEmail.num );
            }
            idStr::Append(this: &v50, text: "\r\n");
            idStr::Append(this: &v50, text: "Subject: ");
            idStr::Append(this: &v50, text: &data->subject);
            idStr::Append(this: &v50, text: "\r\n");
            idStr::Append(
              this: &v50,
              text: "MIME-Version: 1.0\r\n"
              "Content-Type: multipart/mixed; \r\n"
              " boundary=\"KkK170891tpbkKk__FV_KKKkkkjjwq\" \r\n");
            if ( (unsigned __int8)idSMTP::SendToServer(this, buf: v50.data) != 0
              && (unsigned __int8)idSMTP::SendToServer(
                                    this,
                                    buf: "--KkK170891tpbkKk__FV_KKKkkkjjwq\r\n"
                                    "Content-Type: text/plain; charset=US-ASCII\r\n"
                                    "\r\n") != 0
              && (unsigned __int8)idSMTP::SendToServer(this, buf: data->body.data) != 0 )
            {
              if ( smtp_sendAttachments.valueInteger != 0 )
              {
                p_attachment = &data->attachment;
                if ( data->attachment.len > 0 )
                {
                  v51 = nullptr;
                  v29 = fileSystem->ReadFile(
                          this: fileSystem,
                          a2: data->attachment.data,
                          a3: (void **)&v51,
                          a4: nullptr);
                  if ( v51 != nullptr )
                  {
                    v52 = nullptr;
                    idSMTP::EncodeBase64(
                      this,
                      jpgBuffer: v51,
                      jpgBufferLen: v29,
                      base64Buffer: (unsigned __int8 **)&v52);
                    v30 = v52;
                    if ( v52 != nullptr )
                    {
                      idStr::idStr(this: &v55, text: "\r\n\r\n--KkK170891tpbkKk__FV_KKKkkkjjwq\r\n");
                      v56.allocedAndFlag = 20;
                      v56.data = v56.baseBuffer;
                      v56.len = 0;
                      v56.baseBuffer[0] = 0;
                      idStr::ExtractFileExtension(this: p_attachment, dest: &v56);
                      if ( idStr::Icmp(s1: v56.data, s2: "txt") != 0 )
                        v31 = "Content-Type: image/jpeg\r\n";
                      else
                        v31 = "Content-Type: text/plain\r\n";
                      idStr::Append(this: &v55, text: v31);
                      idStr::Append(
                        this: &v55,
                        text: "Content-Transfer-Encoding: base64\r\nContent-Disposition: attachment;\r\n filename= \"");
                      v57.allocedAndFlag = 20;
                      v57.data = v57.baseBuffer;
                      v57.len = 0;
                      v57.baseBuffer[0] = 0;
                      idStr::ExtractFileName(this: p_attachment, dest: &v57);
                      idStr::Append(this: &v55, text: &v57);
                      idStr::Append(this: &v55, text: "\"\r\n\r\n");
                      if ( (unsigned __int8)idSMTP::SendToServer(this, buf: v55.data) == 0
                        || (unsigned __int8)idSMTP::SendToServer(this, buf: v30) == 0
                        || (mgthread_sleep(ms: 500), (unsigned __int8)idSMTP::SendToServer(this, buf: "\r\n\r\n") == 0) )
                      {
                        idStr::FreeData(this: &v57);
                        idStr::FreeData(this: &v56);
                        idStr::FreeData(this: &v55);
                        idStr::FreeData(this: &v54);
                        idStr::FreeData(this: &v50);
                        goto _M220426;
                      }
                      idMem::Free(this: &mem, ptr: v30, align: ALIGN_16);
                      idStr::FreeData(this: &v57);
                      idStr::FreeData(this: &v56);
                      idStr::FreeData(this: &v55);
                    }
                    idMem::Free(this: &mem, ptr: v51, align: ALIGN_16);
                  }
                }
              }
              if ( (unsigned __int8)idSMTP::SendToServer(this, buf: "\r\n\r\n--KkK170891tpbkKk__FV_KKKkkkjjwq--\r\n") != 0
                && (unsigned __int8)idSMTP::SendToServer(this, buf: "\r\n.\r\n") != 0
                && (unsigned __int8)idSMTP::RecvFromServer(this, expected: "reply to DATA body") != 0
                && (unsigned __int8)idSMTP::SendToServer(this, buf: "QUIT\r\n") != 0 )
              {
                idSMTP::RecvFromServer(this, expected: "reply to QUIT");
              }
            }
            idStr::FreeData(this: &v54);
            idStr::FreeData(this: &v50);
          }
        }
      }
    }
_M220426:
    idStr::FreeData(this: &v53);
  }
}


// ========================================================================
// __unwind$219935
// EA  : 0x8289D5E8
// RVA : 0x0089D5E8
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

void _unwind_219935()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8688 + 128));
}


// ========================================================================
// __unwind$219936
// EA  : 0x8289D610
// RVA : 0x0089D610
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

void _unwind_219936()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8688 + 80));
}


// ========================================================================
// __unwind$219937
// EA  : 0x8289D638
// RVA : 0x0089D638
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

void _unwind_219937()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8688 + 160));
}


// ========================================================================
// __unwind$219938
// EA  : 0x8289D660
// RVA : 0x0089D660
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

void _unwind_219938()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8688 + 192));
}


// ========================================================================
// __unwind$219939
// EA  : 0x8289D688
// RVA : 0x0089D688
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

void _unwind_219939()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8688 + 224));
}


// ========================================================================
// __unwind$219940_0
// EA  : 0x8289D6B0
// RVA : 0x0089D6B0
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

void _unwind_219940_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8688 + 256));
}


// ========================================================================
// ?TestEmail_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8289DA18
// RVA : 0x0089DA18
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

void __fastcall TestEmail_f(const idCmdArgs *args)
{
  const char *v2; // r4
  idTCP v3; // [sp+60h] [-130h] BYREF
  idStr v4; // [sp+80h] [-110h] BYREF
  emailData_t v5; // [sp+A0h] [-F0h] BYREF

  if ( args->argc >= 2 )
  {
    emailData_t::emailData_t(this: &v5);
    idStr::operator=(this: &v5.subject, text: "TestEmail_f");
    idStr::operator=(this: &v5.senderName, text: "Brian Harris");
    idStr::operator=(this: &v5.senderEmail, text: "brian@idsoftware.com");
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    idStr::idStr(this: &v4, text: v2);
    idList<idStr,5>::Append(this: &v5.recipientEmail, obj: &v4);
    idStr::FreeData(this: &v4);
    idStr::operator=(
      this: &v5.body,
      text: "Hi, this is a test of the SMTP code.\n\nIt looks like it worked.\r\n\r\nYay!");
    idTCP::idTCP(this: &v3);
    idSMTP::SendEmail(this: (idSMTP *)&v3, data: &v5);
    idTCP::~idTCP(this: &v3);
    emailData_t::~emailData_t(this: &v5);
  }
  else if ( args->argc <= 0 )
  {
    idLib::Printf(fmt: "Syntax: %s <recepient>\n", &byte_8200D768);
  }
  else
  {
    idLib::Printf(fmt: "Syntax: %s <recepient>\n", args->argv[0]);
  }
}


// ========================================================================
// __unwind$220747_0
// EA  : 0x8289DB34
// RVA : 0x0089DB34
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

void _unwind_220747_0()
{
  int v0; // r12

  emailData_t::~emailData_t(this: (emailData_t *)(v0 - 400 + 160));
}


// ========================================================================
// __unwind$220748_0
// EA  : 0x8289DB5C
// RVA : 0x0089DB5C
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

void _unwind_220748_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 128));
}


// ========================================================================
// __unwind$220749_1
// EA  : 0x8289DB84
// RVA : 0x0089DB84
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

void _unwind_220749_1()
{
  int v0; // r12

  idMQTCP::~idMQTCP(this: (idSMTP *)(v0 - 400 + 96));
}


// ========================================================================
// `dynamic initializer for 'smtp_debug''
// EA  : 0x83345940
// RVA : 0x01345940
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__smtp_debug__()
{
  idCVar::idCVar(
    this: &smtp_debug,
    name: "smtp_debug",
    value: "0",
    flags: 1,
    description: "Show SMTP messages.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__smtp_debug__);
}


// ========================================================================
// `dynamic initializer for 'smtp_sendAttachments''
// EA  : 0x83345998
// RVA : 0x01345998
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__smtp_sendAttachments__()
{
  idCVar::idCVar(
    this: &smtp_sendAttachments,
    name: "smtp_sendAttachments",
    value: "1",
    flags: 1,
    description: "sends attachments on emails, for viewnotes",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__smtp_sendAttachments__);
}


// ========================================================================
// `dynamic initializer for 'smtp_domain''
// EA  : 0x833459F0
// RVA : 0x013459F0
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__smtp_domain__()
{
  idCVar::idCVar(
    this: &smtp_domain,
    name: "smtp_domain",
    value: "machinegames.com",
    flags: 0,
    description: "Email domain for smtp server",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__smtp_domain__);
}


// ========================================================================
// `dynamic initializer for 'TestEmail_v''
// EA  : 0x83345A48
// RVA : 0x01345A48
// PDB : w:\tech5\engine\network\smtp.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestEmail_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestEmail_v,
           cmdName: "TestEmail",
           function: TestEmail_f,
           description: "Tests the SMTP code",
           argCompletion: nullptr);
}

