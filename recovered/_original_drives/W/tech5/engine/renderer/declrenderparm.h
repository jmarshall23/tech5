
// ========================================================================
// ?Set@idDeclRenderParm@@QBAXMMMM@Z
// EA  : 0x827D2C90
// RVA : 0x007D2C90
// PDB : w:\tech5\engine\renderer\declrenderparm.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeclRenderParm::Set(idDeclRenderParm *this, double x, double y, double z, double w)
{
  int v5; // r2 OVERLAPPED
  int v7; // r9
  idParmState *v12; // r3
  idParmState *v13; // r11
  unsigned __int64 fragmentParmVersion; // r8 OVERLAPPED
  int v15; // r3
  unsigned __int64 textureParmVersion; // r10 OVERLAPPED
  unsigned __int64 vertexParmVersion; // r6
  char v18; // r4
  int v19; // r3

  v7 = this->parmIndex + 8204;
  v12 = renderThreadParmState;
  if ( (*((_DWORD *)&renderThreadParmState->renderParmVersion + v7)
      & renderThreadParmState->parmStack.virtualParmBlockStackMask) != 0 )
  {
    idParmState::RollbackVirtualStack(this: renderThreadParmState, renderParmChange: true);
    v12 = renderThreadParmState;
  }
  v12->values[this->parmIndex].value[0] = x;
  v13 = renderThreadParmState;
  renderThreadParmState->values[this->parmIndex].value[1] = y;
  v13->values[this->parmIndex].value[2] = z;
  v13->values[this->parmIndex].value[3] = w;
  fragmentParmVersion = v13->fragmentParmVersion;
  v15 = LODWORD(v13->renderParmVersion) + 1;
  textureParmVersion = v13->textureParmVersion;
  vertexParmVersion = v13->vertexParmVersion;
  v18 = *((_BYTE *)&v13->renderParmVersion + this->parmIndex + HIDWORD(fragmentParmVersion));
  v13->renderParmVersion = *(_QWORD *)(&v5 - 1);
  HIDWORD(fragmentParmVersion) = v18 & 1;
  HIDWORD(textureParmVersion) = (v18 & 2) + fragmentParmVersion;
  v19 = HIDWORD(fragmentParmVersion) + vertexParmVersion;
  LODWORD(fragmentParmVersion) = (v18 & 4) + textureParmVersion;
  *(_QWORD *)(HIDWORD(vertexParmVersion) + offsetof(idParmState, fragmentParmVersion)) = *(unsigned __int64 *)((char *)&fragmentParmVersion - 4);
  *(_QWORD *)(HIDWORD(vertexParmVersion) + offsetof(idParmState, vertexParmVersion)) = *(_QWORD *)(&v5 - 1);
  *(_QWORD *)(HIDWORD(vertexParmVersion) + offsetof(idParmState, textureParmVersion)) = fragmentParmVersion;
}


// ========================================================================
// ?GetDeclInfo@idDeclRenderParm@@UBAPAVidDeclInfo@@XZ
// EA  : 0x828AD710
// RVA : 0x008AD710
// PDB : w:\tech5\engine\renderer\declrenderparm.h
// ========================================================================

idDeclInfoTemplate<idDeclRenderParm> *__fastcall idDeclRenderParm::GetDeclInfo(idDeclRenderParm *this)
{
  return &idDeclRenderParm::resourceList;
}


// ========================================================================
// ?SetImage@idDeclRenderParm@@QBAXPBVidImage@@@Z
// EA  : 0x828AEBA0
// RVA : 0x008AEBA0
// PDB : w:\tech5\engine\renderer\declrenderparm.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeclRenderParm::SetImage(idDeclRenderParm *this, const idImage *image)
{
  int v2; // r9
  idParmState *v4; // r3
  unsigned __int64 fragmentParmVersion; // r7 OVERLAPPED
  unsigned __int64 textureParmVersion; // r9 OVERLAPPED
  unsigned __int64 vertexParmVersion; // r5
  int v9; // r10
  char v10; // r3
  __int64 v11; // r11

  v2 = this->parmIndex + 8204;
  v4 = renderThreadParmState;
  if ( (*((_DWORD *)&renderThreadParmState->renderParmVersion + v2)
      & renderThreadParmState->parmStack.virtualParmBlockStackMask) != 0 )
  {
    idParmState::RollbackVirtualStack(this: renderThreadParmState, renderParmChange: true);
    v4 = renderThreadParmState;
  }
  v4->values[this->parmIndex].swizzle[0] = (int)image;
  fragmentParmVersion = renderThreadParmState->fragmentParmVersion;
  textureParmVersion = renderThreadParmState->textureParmVersion;
  vertexParmVersion = renderThreadParmState->vertexParmVersion;
  *(unsigned __int64 *)((char *)&textureParmVersion - 4) = renderThreadParmState->renderParmVersion;
  v9 = LODWORD(renderThreadParmState->renderParmVersion) + 1;
  v10 = *((_BYTE *)&renderThreadParmState->renderParmVersion + this->parmIndex + HIDWORD(textureParmVersion));
  renderThreadParmState->renderParmVersion = *(unsigned __int64 *)((char *)&textureParmVersion - 4);
  HIDWORD(fragmentParmVersion) = v10 & 1;
  HIDWORD(v11) = v10 & 4;
  LODWORD(v11) = (v10 & 2) + fragmentParmVersion;
  HIDWORD(textureParmVersion) = HIDWORD(fragmentParmVersion) + vertexParmVersion;
  LODWORD(fragmentParmVersion) = HIDWORD(v11) + textureParmVersion;
  *(_QWORD *)(HIDWORD(vertexParmVersion) + offsetof(idParmState, fragmentParmVersion)) = v11;
  *(_QWORD *)(HIDWORD(vertexParmVersion) + offsetof(idParmState, vertexParmVersion)) = *(unsigned __int64 *)((char *)&fragmentParmVersion - 4);
  *(_QWORD *)(HIDWORD(vertexParmVersion) + offsetof(idParmState, textureParmVersion)) = fragmentParmVersion;
}


// ========================================================================
// ?Set@idDeclRenderParm@@QBAXABVidVec3@@@Z
// EA  : 0x828DBAB0
// RVA : 0x008DBAB0
// PDB : w:\tech5\engine\renderer\declrenderparm.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeclRenderParm::Set(idDeclRenderParm *this, const idVec3 *vec)
{
  int v2; // r2 OVERLAPPED
  int v3; // r9
  idParmState *v5; // r3
  idParmState *v7; // r11
  idParmState *v8; // r4
  unsigned __int64 fragmentParmVersion; // r8 OVERLAPPED
  unsigned __int64 textureParmVersion; // r10 OVERLAPPED
  unsigned __int64 vertexParmVersion; // r6
  int v12; // r3

  v3 = this->parmIndex + 8204;
  v5 = renderThreadParmState;
  if ( (*((_DWORD *)&renderThreadParmState->renderParmVersion + v3)
      & renderThreadParmState->parmStack.virtualParmBlockStackMask) != 0 )
  {
    idParmState::RollbackVirtualStack(this: renderThreadParmState, renderParmChange: true);
    v5 = renderThreadParmState;
  }
  v5->values[this->parmIndex].value[0] = vec->x;
  v7 = renderThreadParmState;
  v8 = renderThreadParmState;
  renderThreadParmState->values[this->parmIndex].value[1] = vec->y;
  v7->values[this->parmIndex].value[2] = vec->z;
  v7->values[this->parmIndex].value[3] = 1.0;
  fragmentParmVersion = v7->fragmentParmVersion;
  textureParmVersion = v7->textureParmVersion;
  vertexParmVersion = v7->vertexParmVersion;
  BYTE3(vertexParmVersion) = *((_BYTE *)&v7->renderParmVersion + this->parmIndex + HIDWORD(vertexParmVersion));
  HIDWORD(fragmentParmVersion) = BYTE3(vertexParmVersion) & 1;
  v7->renderParmVersion = *(unsigned __int64 *)((char *)&fragmentParmVersion - 4);
  HIDWORD(textureParmVersion) = (BYTE3(vertexParmVersion) & 2) + fragmentParmVersion;
  v12 = HIDWORD(fragmentParmVersion) + vertexParmVersion;
  LODWORD(fragmentParmVersion) = (BYTE3(vertexParmVersion) & 4) + textureParmVersion;
  v8->fragmentParmVersion = *(unsigned __int64 *)((char *)&fragmentParmVersion - 4);
  v8->vertexParmVersion = *(_QWORD *)(&v2 - 1);
  v8->textureParmVersion = fragmentParmVersion;
}


// ========================================================================
// ?Set@idDeclRenderParm@@QBAXABVidVec4@@@Z
// EA  : 0x828DBBB8
// RVA : 0x008DBBB8
// PDB : w:\tech5\engine\renderer\declrenderparm.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeclRenderParm::Set(idDeclRenderParm *this, const idPlane *plane)
{
  int v2; // r2 OVERLAPPED
  int v3; // r9
  idParmState *v5; // r3
  idParmState *v7; // r11
  unsigned __int64 fragmentParmVersion; // r8 OVERLAPPED
  int v9; // r3
  unsigned __int64 textureParmVersion; // r10 OVERLAPPED
  unsigned __int64 vertexParmVersion; // r6
  char v12; // r4
  int v13; // r3

  v3 = this->parmIndex + 8204;
  v5 = renderThreadParmState;
  if ( (*((_DWORD *)&renderThreadParmState->renderParmVersion + v3)
      & renderThreadParmState->parmStack.virtualParmBlockStackMask) != 0 )
  {
    idParmState::RollbackVirtualStack(this: renderThreadParmState, renderParmChange: true);
    v5 = renderThreadParmState;
  }
  v5->values[this->parmIndex].value[0] = plane->a;
  v7 = renderThreadParmState;
  renderThreadParmState->values[this->parmIndex].value[1] = plane->b;
  v7->values[this->parmIndex].value[2] = plane->c;
  v7->values[this->parmIndex].value[3] = plane->d;
  fragmentParmVersion = v7->fragmentParmVersion;
  v9 = LODWORD(v7->renderParmVersion) + 1;
  textureParmVersion = v7->textureParmVersion;
  vertexParmVersion = v7->vertexParmVersion;
  v12 = *((_BYTE *)&v7->renderParmVersion + this->parmIndex + HIDWORD(fragmentParmVersion));
  v7->renderParmVersion = *(_QWORD *)(&v2 - 1);
  HIDWORD(fragmentParmVersion) = v12 & 1;
  HIDWORD(textureParmVersion) = (v12 & 2) + fragmentParmVersion;
  v13 = HIDWORD(fragmentParmVersion) + vertexParmVersion;
  LODWORD(fragmentParmVersion) = (v12 & 4) + textureParmVersion;
  *(_QWORD *)(HIDWORD(vertexParmVersion) + offsetof(idParmState, fragmentParmVersion)) = *(unsigned __int64 *)((char *)&fragmentParmVersion - 4);
  *(_QWORD *)(HIDWORD(vertexParmVersion) + offsetof(idParmState, vertexParmVersion)) = *(_QWORD *)(&v2 - 1);
  *(_QWORD *)(HIDWORD(vertexParmVersion) + offsetof(idParmState, textureParmVersion)) = fragmentParmVersion;
}


// ========================================================================
// ?Set@idDeclRenderParm@@QBAXM@Z
// EA  : 0x828DBCB8
// RVA : 0x008DBCB8
// PDB : w:\tech5\engine\renderer\declrenderparm.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeclRenderParm::Set(idDeclRenderParm *this, double v)
{
  int v2; // r2 OVERLAPPED
  int v4; // r9
  idParmState *v6; // r3
  idParmState *v7; // r11
  unsigned __int64 fragmentParmVersion; // r8 OVERLAPPED
  int v9; // r3
  unsigned __int64 textureParmVersion; // r10 OVERLAPPED
  unsigned __int64 vertexParmVersion; // r6
  char v12; // r4
  int v13; // r3

  v4 = this->parmIndex + 8204;
  v6 = renderThreadParmState;
  if ( (*((_DWORD *)&renderThreadParmState->renderParmVersion + v4)
      & renderThreadParmState->parmStack.virtualParmBlockStackMask) != 0 )
  {
    idParmState::RollbackVirtualStack(this: renderThreadParmState, renderParmChange: true);
    v6 = renderThreadParmState;
  }
  v6->values[this->parmIndex].value[0] = v;
  v7 = renderThreadParmState;
  renderThreadParmState->values[this->parmIndex].value[1] = v;
  v7->values[this->parmIndex].value[2] = v;
  v7->values[this->parmIndex].value[3] = v;
  fragmentParmVersion = v7->fragmentParmVersion;
  v9 = LODWORD(v7->renderParmVersion) + 1;
  textureParmVersion = v7->textureParmVersion;
  vertexParmVersion = v7->vertexParmVersion;
  v12 = *((_BYTE *)&v7->renderParmVersion + this->parmIndex + HIDWORD(fragmentParmVersion));
  v7->renderParmVersion = *(_QWORD *)(&v2 - 1);
  HIDWORD(fragmentParmVersion) = v12 & 1;
  HIDWORD(textureParmVersion) = (v12 & 2) + fragmentParmVersion;
  v13 = HIDWORD(fragmentParmVersion) + vertexParmVersion;
  LODWORD(fragmentParmVersion) = (v12 & 4) + textureParmVersion;
  *(_QWORD *)(HIDWORD(vertexParmVersion) + offsetof(idParmState, fragmentParmVersion)) = *(unsigned __int64 *)((char *)&fragmentParmVersion - 4);
  *(_QWORD *)(HIDWORD(vertexParmVersion) + offsetof(idParmState, vertexParmVersion)) = *(_QWORD *)(&v2 - 1);
  *(_QWORD *)(HIDWORD(vertexParmVersion) + offsetof(idParmState, textureParmVersion)) = fragmentParmVersion;
}

