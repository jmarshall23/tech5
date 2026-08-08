
// ========================================================================
// ??0usercmd_t@@QAA@XZ
// EA  : 0x82642820
// RVA : 0x00642820
// PDB : w:\tech5\engine\framework\usercmdgen.h
// ========================================================================

usercmd_t *__fastcall usercmd_t::usercmd_t(usercmd_t *this)
{
  char v1; // r9

  v1 = *((_BYTE *)this + 9);
  this->buttons = 0;
  this->buttons2 = 0;
  this->forwardmove = 0;
  this->pos[2] = 0.0;
  this->rightmove = 0;
  this->pos[1] = 0.0;
  this->upmove = 0;
  this->pos[0] = 0.0;
  this->angles[2] = 0;
  this->angles[1] = 0;
  this->angles[0] = 0;
  this->clientGameFrame = 0;
  *((_BYTE *)this + 9) = v1 & 0x3F;
  this->yaw = 0;
  this->pitch = 0;
  this->roll = 0;
  this->predictionStateBits = 0;
  this->vehicleThrottle = 0;
  this->serverGameTime = 0;
  this->fireCount = 0;
  this->fireAngles[1] = 0;
  this->fireAngles[0] = 0;
  this->firePos[2] = 0;
  this->firePos[1] = 0;
  this->firePos[0] = 0;
  this->speed = 0;
  return this;
}


// ========================================================================
// ??0idUserCmdMgr@@QAA@XZ
// EA  : 0x82642FD8
// RVA : 0x00642FD8
// PDB : w:\tech5\engine\framework\usercmdgen.h
// ========================================================================

idUserCmdMgr *__fastcall idUserCmdMgr::idUserCmdMgr(idUserCmdMgr *this)
{
  char *v2; // r11
  int i; // ctr
  char v4; // r10
  char v5; // r9
  char v6; // r8
  char v7; // r4
  char v8; // r3
  char v9; // r10
  char v10; // r7
  char v11; // r5
  unsigned __int8 *p_vehicleThrottle; // r11
  int j; // ctr
  int *v14; // r11
  int k; // ctr

  v2 = (char *)this - 3;
  for ( i = 96; i != 0; --i )
  {
    v4 = v2[12];
    *(float *)(v2 + 31) = 0.0;
    v5 = v2[72];
    *(float *)(v2 + 27) = 0.0;
    v6 = v2[132];
    *(float *)(v2 + 23) = 0.0;
    *(float *)(v2 + 91) = 0.0;
    *(float *)(v2 + 87) = 0.0;
    *(_DWORD *)(v2 + 3) = 0;
    *(float *)(v2 + 83) = 0.0;
    *(_WORD *)(v2 + 7) = 0;
    *(float *)(v2 + 151) = 0.0;
    v2[9] = 0;
    *(float *)(v2 + 147) = 0.0;
    v2[10] = 0;
    *(float *)(v2 + 143) = 0.0;
    v2[11] = 0;
    *(_WORD *)(v2 + 17) = 0;
    *(_WORD *)(v2 + 15) = 0;
    *(_WORD *)(v2 + 13) = 0;
    *(_DWORD *)(v2 + 19) = 0;
    v2[12] = v4 & 0x3F;
    *(_WORD *)(v2 + 37) = 0;
    *(_WORD *)(v2 + 35) = 0;
    *(_WORD *)(v2 + 39) = 0;
    v2[41] = 0;
    v2[59] = 0;
    *(_DWORD *)(v2 + 43) = 0;
    *(_WORD *)(v2 + 47) = 0;
    *(_WORD *)(v2 + 51) = 0;
    *(_WORD *)(v2 + 49) = 0;
    *(_WORD *)(v2 + 57) = 0;
    *(_WORD *)(v2 + 55) = 0;
    *(_WORD *)(v2 + 53) = 0;
    v2[60] = 0;
    *(_DWORD *)(v2 + 63) = 0;
    *(_WORD *)(v2 + 67) = 0;
    v2[69] = 0;
    v2[70] = 0;
    v2[71] = 0;
    *(_WORD *)(v2 + 77) = 0;
    *(_WORD *)(v2 + 75) = 0;
    *(_WORD *)(v2 + 73) = 0;
    *(_DWORD *)(v2 + 79) = 0;
    v2[72] = v5 & 0x3F;
    *(_WORD *)(v2 + 97) = 0;
    *(_WORD *)(v2 + 95) = 0;
    *(_WORD *)(v2 + 99) = 0;
    v2[101] = 0;
    v2[119] = 0;
    *(_DWORD *)(v2 + 103) = 0;
    *(_WORD *)(v2 + 107) = 0;
    *(_WORD *)(v2 + 111) = 0;
    *(_WORD *)(v2 + 109) = 0;
    *(_WORD *)(v2 + 117) = 0;
    *(_WORD *)(v2 + 115) = 0;
    *(_WORD *)(v2 + 113) = 0;
    v2[120] = 0;
    *(_DWORD *)(v2 + 123) = 0;
    *(_WORD *)(v2 + 127) = 0;
    v2[129] = 0;
    v2[130] = 0;
    v2[131] = 0;
    *(_WORD *)(v2 + 137) = 0;
    *(_WORD *)(v2 + 135) = 0;
    *(_WORD *)(v2 + 133) = 0;
    *(_DWORD *)(v2 + 139) = 0;
    v2[132] = v6 & 0x3F;
    *(_WORD *)(v2 + 157) = 0;
    *(_WORD *)(v2 + 155) = 0;
    *(_WORD *)(v2 + 159) = 0;
    v2[161] = 0;
    v2[179] = 0;
    *(_DWORD *)(v2 + 163) = 0;
    *(_WORD *)(v2 + 167) = 0;
    *(_WORD *)(v2 + 171) = 0;
    *(_WORD *)(v2 + 169) = 0;
    *(_WORD *)(v2 + 177) = 0;
    v7 = v2[192];
    *(float *)(v2 + 211) = 0.0;
    v8 = v2[252];
    *(float *)(v2 + 207) = 0.0;
    v9 = v2[312];
    v10 = v2[372];
    *(float *)(v2 + 203) = 0.0;
    *(float *)(v2 + 271) = 0.0;
    *(_WORD *)(v2 + 175) = 0;
    *(float *)(v2 + 267) = 0.0;
    *(_WORD *)(v2 + 173) = 0;
    *(float *)(v2 + 263) = 0.0;
    v2[180] = 0;
    *(float *)(v2 + 331) = 0.0;
    *(_DWORD *)(v2 + 183) = 0;
    *(float *)(v2 + 327) = 0.0;
    *(_WORD *)(v2 + 187) = 0;
    *(float *)(v2 + 323) = 0.0;
    v2[189] = 0;
    *(float *)(v2 + 391) = 0.0;
    v2[190] = 0;
    *(float *)(v2 + 387) = 0.0;
    v2[191] = 0;
    *(float *)(v2 + 383) = 0.0;
    *(_WORD *)(v2 + 197) = 0;
    *(_WORD *)(v2 + 195) = 0;
    *(_WORD *)(v2 + 193) = 0;
    *(_DWORD *)(v2 + 199) = 0;
    v2[192] = v7 & 0x3F;
    *(_WORD *)(v2 + 217) = 0;
    *(_WORD *)(v2 + 215) = 0;
    *(_WORD *)(v2 + 219) = 0;
    v2[221] = 0;
    v2[239] = 0;
    *(_DWORD *)(v2 + 223) = 0;
    *(_WORD *)(v2 + 227) = 0;
    *(_WORD *)(v2 + 231) = 0;
    *(_WORD *)(v2 + 229) = 0;
    *(_WORD *)(v2 + 237) = 0;
    *(_WORD *)(v2 + 235) = 0;
    *(_WORD *)(v2 + 233) = 0;
    v2[240] = 0;
    *(_DWORD *)(v2 + 243) = 0;
    *(_WORD *)(v2 + 247) = 0;
    v2[249] = 0;
    v2[250] = 0;
    v2[251] = 0;
    *(_WORD *)(v2 + 257) = 0;
    *(_WORD *)(v2 + 255) = 0;
    *(_WORD *)(v2 + 253) = 0;
    *(_DWORD *)(v2 + 259) = 0;
    v2[252] = v8 & 0x3F;
    *(_WORD *)(v2 + 277) = 0;
    *(_WORD *)(v2 + 275) = 0;
    *(_WORD *)(v2 + 279) = 0;
    v2[281] = 0;
    v2[299] = 0;
    *(_DWORD *)(v2 + 283) = 0;
    *(_WORD *)(v2 + 287) = 0;
    *(_WORD *)(v2 + 291) = 0;
    *(_WORD *)(v2 + 289) = 0;
    *(_WORD *)(v2 + 297) = 0;
    *(_WORD *)(v2 + 295) = 0;
    *(_WORD *)(v2 + 293) = 0;
    v2[300] = 0;
    *(_DWORD *)(v2 + 303) = 0;
    *(_WORD *)(v2 + 307) = 0;
    v2[309] = 0;
    v2[310] = 0;
    v2[311] = 0;
    *(_WORD *)(v2 + 317) = 0;
    *(_WORD *)(v2 + 315) = 0;
    *(_WORD *)(v2 + 313) = 0;
    *(_DWORD *)(v2 + 319) = 0;
    v2[312] = v9 & 0x3F;
    *(_WORD *)(v2 + 337) = 0;
    *(_WORD *)(v2 + 335) = 0;
    *(_WORD *)(v2 + 339) = 0;
    v11 = v2[432];
    *(float *)(v2 + 451) = 0.0;
    v2[341] = 0;
    *(float *)(v2 + 447) = 0.0;
    *(float *)(v2 + 443) = 0.0;
    v2[359] = 0;
    *(_DWORD *)(v2 + 343) = 0;
    *(_WORD *)(v2 + 347) = 0;
    *(_WORD *)(v2 + 351) = 0;
    *(_WORD *)(v2 + 349) = 0;
    *(_WORD *)(v2 + 357) = 0;
    *(_WORD *)(v2 + 355) = 0;
    *(_WORD *)(v2 + 353) = 0;
    v2[360] = 0;
    *(_DWORD *)(v2 + 363) = 0;
    *(_WORD *)(v2 + 367) = 0;
    v2[369] = 0;
    v2[370] = 0;
    v2[371] = 0;
    *(_WORD *)(v2 + 377) = 0;
    *(_WORD *)(v2 + 375) = 0;
    *(_WORD *)(v2 + 373) = 0;
    *(_DWORD *)(v2 + 379) = 0;
    v2[372] = v10 & 0x3F;
    *(_WORD *)(v2 + 397) = 0;
    *(_WORD *)(v2 + 395) = 0;
    *(_WORD *)(v2 + 399) = 0;
    v2[401] = 0;
    v2[419] = 0;
    *(_DWORD *)(v2 + 403) = 0;
    *(_WORD *)(v2 + 407) = 0;
    *(_WORD *)(v2 + 411) = 0;
    *(_WORD *)(v2 + 409) = 0;
    *(_WORD *)(v2 + 417) = 0;
    *(_WORD *)(v2 + 415) = 0;
    *(_WORD *)(v2 + 413) = 0;
    v2[420] = 0;
    *(_DWORD *)(v2 + 423) = 0;
    *(_WORD *)(v2 + 427) = 0;
    v2[429] = 0;
    v2[430] = 0;
    v2[431] = 0;
    *(_WORD *)(v2 + 437) = 0;
    *(_WORD *)(v2 + 435) = 0;
    *(_WORD *)(v2 + 433) = 0;
    *(_DWORD *)(v2 + 439) = 0;
    v2[432] = v11 & 0x3F;
    *(_WORD *)(v2 + 457) = 0;
    *(_WORD *)(v2 + 455) = 0;
    *(_WORD *)(v2 + 459) = 0;
    v2[461] = 0;
    v2[479] = 0;
    *(_DWORD *)(v2 + 463) = 0;
    *(_WORD *)(v2 + 467) = 0;
    *(_WORD *)(v2 + 471) = 0;
    *(_WORD *)(v2 + 469) = 0;
    *(_WORD *)(v2 + 477) = 0;
    *(_WORD *)(v2 + 475) = 0;
    *(_WORD *)(v2 + 473) = 0;
    v2 += 480;
    *v2 = 0;
  }
  memset(Dst: this, Val: 0, Size: 0xB400u);
  p_vehicleThrottle = &this->cmdBuffer[127][5].vehicleThrottle;
  for ( j = 6; j != 0; --j )
  {
    p_vehicleThrottle += 4;
    *(_DWORD *)p_vehicleThrottle = 0;
  }
  v14 = &this->writeFrame[5];
  for ( k = 6; k != 0; --k )
    *++v14 = -1;
  return this;
}


// ========================================================================
// ?PutUserCmdForPlayer@idUserCmdMgr@@QAAXHABVusercmd_t@@@Z
// EA  : 0x826513B8
// RVA : 0x006513B8
// PDB : w:\tech5\engine\framework\usercmdgen.h
// ========================================================================

void __fastcall idUserCmdMgr::PutUserCmdForPlayer(idUserCmdMgr *this, int playerIndex, const usercmd_t *cmd)
{
  int v5; // r29
  int v6; // r11
  int v7; // r10

  v5 = 4 * (playerIndex + 11520);
  memcpy(
    Dst: &this->cmdBuffer[*(int *)((char *)&this->cmdBuffer[0][0].buttons + v5) % 128][playerIndex],
    Src: cmd,
    Size: sizeof(this->cmdBuffer[*(int *)((char *)&this->cmdBuffer[0][0].buttons + v5) % 128][playerIndex]));
  v6 = *(int *)((char *)&this->cmdBuffer[0][0].buttons + v5);
  v7 = 4 * (playerIndex + 11526);
  if ( v6 - *(int *)((char *)&this->cmdBuffer[0][0].buttons + v7) + 1 > 128 )
  {
    *(int *)((char *)&this->cmdBuffer[0][0].buttons + v7) = v6 - 64;
    idLib::Printf(fmt: "PutUserCmdForPlayer: buffer overflow.\n");
  }
  ++*(int *)((char *)&this->cmdBuffer[0][0].buttons + v5);
}


// ========================================================================
// ?GetPlayerCmds@idUserCmdMgr@@QAAHHPAPAVusercmd_t@@H@Z
// EA  : 0x82659890
// RVA : 0x00659890
// PDB : w:\tech5\engine\framework\usercmdgen.h
// ========================================================================

unsigned int __fastcall idUserCmdMgr::GetPlayerCmds(idUserCmdMgr *this, int user, usercmd_t **buffer, int bufferSize)
{
  int v5; // r11
  int v6; // r8
  unsigned int v7; // r7
  unsigned int result; // r3
  usercmd_t **v9; // r9
  unsigned int v10; // ctr
  int v11; // r10

  if ( bufferSize >= 128 )
    bufferSize = 128;
  v5 = 0;
  v6 = this->writeFrame[user];
  v7 = ((v6 == bufferSize) + ((unsigned int)(v6 - bufferSize) >> 31) - 1) & (v6 - bufferSize);
  result = v6 - v7;
  if ( (int)(v6 - v7) > 0 )
  {
    v9 = buffer - 1;
    v10 = v6 - v7;
    do
    {
      v11 = (int)(v5 + v7) % 128;
      ++v5;
      *++v9 = &this->cmdBuffer[v11][user];
      --v10;
    }
    while ( v10 != 0 );
  }
  return result;
}


// ========================================================================
// ?ResetPlayer@idUserCmdMgr@@QAAXH@Z
// EA  : 0x8265CD20
// RVA : 0x0065CD20
// PDB : w:\tech5\engine\framework\usercmdgen.h
// ========================================================================

void __fastcall idUserCmdMgr::ResetPlayer(idUserCmdMgr *this, int playerIndex)
{
  char *v4; // r30
  int i; // r31

  v4 = (char *)this + 60 * playerIndex;
  for ( i = 128; i != 0; --i )
  {
    memset(Dst: v4, Val: 0, Size: 0x3Cu);
    v4 += 360;
  }
  this->writeFrame[playerIndex] = 0;
  this->readFrame[playerIndex] = -1;
}

