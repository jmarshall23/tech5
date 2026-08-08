
// ========================================================================
// ?BuildProjectionMatrix@renderView_t@@QBAXAAVidRenderMatrix@@HH@Z
// EA  : 0x82956488
// RVA : 0x00956488
// PDB : w:\tech5\engine\renderer\renderview.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall renderView_t::BuildProjectionMatrix(
        renderView_t *this,
        idRenderMatrix *projectionMatrix,
        int jitterWidth,
        int jitterHeight,
        long double a5)
{
  renderView_t *v5; // r31
  double fov_x; // fp1
  double v9; // fp6
  double valueFloat; // fp30
  double v11; // fp5
  double v12; // fp29
  long double v13; // fp2
  double v14; // fp28
  __int64 v15; // r5
  long double v16; // fp2
  __int64 v17; // r9
  double v18; // fp12
  int seed; // r8
  idRenderMatrix *v20; // r4
  renderView_t *v21; // r3

  v5 = this;
  if ( this->useExplicitProjectionMatrix )
  {
    *projectionMatrix = this->explicitProjectionMatrix;
  }
  else
  {
    fov_x = this->fov_x;
    v9 = 0.0;
    if ( fov_x <= 0.0 || this->fov_y <= 0.0 )
    {
      idLib::Error(fmt: "idRenderWorldLocal::Render: bad FOVs: %f, %f", fov_x, this->fov_y);
      renderView_t::BuildViewMatrix(this: v21, viewMatrix: v20);
    }
    else
    {
      if ( this->cramZNear )
        valueFloat = (float)(r_znear.valueFloat * (float)0.25);
      else
        valueFloat = r_znear.valueFloat;
      v11 = 0.0;
      v12 = r_zfar.valueFloat;
      if ( jitterWidth > 0 && jitterHeight > 0 )
      {
        *(double *)&a5 = (float)((float)(this->fov_y * idMath::M_DEG2RAD) * (float)0.5);
        v13 = tan(x: a5);
        v14 = (float)((float)*(double *)&v13 * (float)valueFloat);
        *(double *)&v13 = (float)((float)(idMath::M_DEG2RAD * v5->fov_x) * (float)0.5);
        v16 = tan(x: v13);
        LODWORD(v17) = jitterWidth;
        v18 = (float)((float)((float)((float)*(double *)&v16 * (float)valueFloat)
                            - (float)-(float)((float)*(double *)&v16 * (float)valueFloat))
                    / (float)v17);
        if ( (_S13_27 & 1) != 0 )
        {
          seed = random_5.seed;
        }
        else
        {
          seed = 0;
          _S13_27 |= 1u;
        }
        random_5.seed = 1103515245 * seed + 12345;
        LODWORD(v15) = HIWORD(random_5.seed) & 0x7FFF;
        random_5.seed = 1103515245 * random_5.seed + 12345;
        this = (renderView_t *)(HIWORD(random_5.seed) & 0x7FFF);
        v11 = (float)((float)((float)v15 * (float)v18) * (float)0.000030518509);
        v9 = (float)((float)((float)*(__int64 *)&this
                           * (float)((float)((float)v14 - (float)-v14) / (float)__SPAIR64__(jitterWidth, jitterHeight)))
                   * (float)0.000030518509);
      }
      idRenderMatrix::BuildProjectionFov(
        xFovDegrees: v5->fov_x,
        yFovDegrees: v5->fov_y,
        zNear: valueFloat,
        zFar: v12,
        xOffset: v11,
        yOffset: v9,
        out: (idRenderMatrix *)this);
    }
  }
}


// ========================================================================
// ?BuildViewMatrix@renderView_t@@QBAXAAVidRenderMatrix@@@Z
// EA  : 0x829566A8
// RVA : 0x009566A8
// PDB : w:\tech5\engine\renderer\renderview.cpp
// ========================================================================

void __fastcall renderView_t::BuildViewMatrix(renderView_t *this, idRenderMatrix *viewMatrix)
{
  if ( this->forceIdentityViewMatrix )
  {
    viewMatrix->m[0] = 1.0;
    viewMatrix->m[1] = 0.0;
    viewMatrix->m[2] = 0.0;
    viewMatrix->m[3] = 0.0;
    viewMatrix->m[4] = 0.0;
    viewMatrix->m[5] = 1.0;
    viewMatrix->m[6] = 0.0;
    viewMatrix->m[7] = 0.0;
    viewMatrix->m[8] = 0.0;
    viewMatrix->m[9] = 0.0;
    viewMatrix->m[10] = 1.0;
    viewMatrix->m[11] = 0.0;
    viewMatrix->m[12] = 0.0;
    viewMatrix->m[13] = 0.0;
    viewMatrix->m[14] = 0.0;
    viewMatrix->m[15] = 1.0;
  }
  else
  {
    idRenderMatrix::ModelViewFromOriginAxis(origin: &this->vieworg, axis: &this->viewaxis, out: viewMatrix);
  }
}


// ========================================================================
// ??1idRenderView@@AAA@XZ
// EA  : 0x82956720
// RVA : 0x00956720
// PDB : w:\tech5\engine\renderer\renderview.cpp
// ========================================================================

void __fastcall idRenderView::~idRenderView(idRenderView *this)
{
  idMem::Free(this: &mem, ptr: this->occlusionState, align: ALIGN_16);
  renderView_t::~renderView_t(this: &this->r);
  idParmBlock::~idParmBlock(this: &this->blendedEnvironmentParms);
  renderView_t::~renderView_t(this: &this->g);
}


// ========================================================================
// __unwind$229488
// EA  : 0x82956784
// RVA : 0x00956784
// PDB : w:\tech5\engine\renderer\renderview.cpp
// ========================================================================

void _unwind_229488()
{
  int v0; // r12

  renderView_t::~renderView_t(this: *(renderView_t **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$229489
// EA  : 0x829567AC
// RVA : 0x009567AC
// PDB : w:\tech5\engine\renderer\renderview.cpp
// ========================================================================

void _unwind_229489()
{
  int v0; // r12

  idParmBlock::~idParmBlock(this: (idParmBlock *)(*(_DWORD *)(v0 - 112 + 132) + 1896));
}


// ========================================================================
// __unwind$229490
// EA  : 0x829567D8
// RVA : 0x009567D8
// PDB : w:\tech5\engine\renderer\renderview.cpp
// ========================================================================

void _unwind_229490()
{
  int v0; // r12

  renderView_t::~renderView_t(this: (renderView_t *)(*(_DWORD *)(v0 - 112 + 132) + 1936));
}


// ========================================================================
// ??0idRenderView@@AAA@XZ
// EA  : 0x82956810
// RVA : 0x00956810
// PDB : w:\tech5\engine\renderer\renderview.cpp
// ========================================================================

idRenderView *__fastcall idRenderView::idRenderView(idRenderView *this)
{
  __int64 v1; // r29
  __int64 v3; // r11
  occlusionState_t *v4; // r3

  renderView_t::renderView_t(this: &this->g, threadId: THREAD_MAIN);
  idParmBlock::idParmBlock(this: &this->blendedEnvironmentParms, threadId: THREAD_RENDERER);
  renderView_t::renderView_t(this: &this->r, threadId: THREAD_RENDERER);
  LODWORD(v3) = 0;
  HIDWORD(v3) = 0x82000000;
  this->imgViewColor = nullptr;
  *(_QWORD *)&this->envBlend.env = v3;
  *(_QWORD *)&this->envBlend.blendDuration = v3;
  this->projectionMatrix.m[0] = 1.0;
  this->projectionMatrix.m[1] = 0.0;
  this->projectionMatrix.m[2] = 0.0;
  this->projectionMatrix.m[3] = 0.0;
  this->projectionMatrix.m[4] = 0.0;
  this->projectionMatrix.m[5] = 1.0;
  this->projectionMatrix.m[6] = 0.0;
  this->projectionMatrix.m[7] = 0.0;
  this->projectionMatrix.m[8] = 0.0;
  this->projectionMatrix.m[9] = 0.0;
  this->projectionMatrix.m[10] = 1.0;
  this->projectionMatrix.m[11] = 0.0;
  this->projectionMatrix.m[12] = 0.0;
  this->projectionMatrix.m[13] = 0.0;
  this->projectionMatrix.m[14] = 0.0;
  this->projectionMatrix.m[15] = 1.0;
  this->inverseProjectionMatrix.m[0] = 1.0;
  this->inverseProjectionMatrix.m[1] = 0.0;
  this->inverseProjectionMatrix.m[2] = 0.0;
  this->inverseProjectionMatrix.m[3] = 0.0;
  this->inverseProjectionMatrix.m[4] = 0.0;
  this->inverseProjectionMatrix.m[5] = 1.0;
  this->inverseProjectionMatrix.m[6] = 0.0;
  this->inverseProjectionMatrix.m[7] = 0.0;
  this->inverseProjectionMatrix.m[8] = 0.0;
  this->inverseProjectionMatrix.m[9] = 0.0;
  this->inverseProjectionMatrix.m[10] = 1.0;
  this->inverseProjectionMatrix.m[11] = 0.0;
  this->inverseProjectionMatrix.m[12] = 0.0;
  this->inverseProjectionMatrix.m[13] = 0.0;
  this->inverseProjectionMatrix.m[14] = 0.0;
  this->inverseProjectionMatrix.m[15] = 1.0;
  this->viewMatrix.m[0] = 1.0;
  this->viewMatrix.m[1] = 0.0;
  this->viewMatrix.m[2] = 0.0;
  this->viewMatrix.m[3] = 0.0;
  this->viewMatrix.m[4] = 0.0;
  this->viewMatrix.m[5] = 1.0;
  this->viewMatrix.m[6] = 0.0;
  this->viewMatrix.m[7] = 0.0;
  this->viewMatrix.m[8] = 0.0;
  this->viewMatrix.m[9] = 0.0;
  this->viewMatrix.m[10] = 1.0;
  this->viewMatrix.m[11] = 0.0;
  this->viewMatrix.m[12] = 0.0;
  this->viewMatrix.m[13] = 0.0;
  this->viewMatrix.m[14] = 0.0;
  this->viewMatrix.m[15] = 1.0;
  this->inverseViewMatrix.m[0] = 1.0;
  this->inverseViewMatrix.m[1] = 0.0;
  this->inverseViewMatrix.m[2] = 0.0;
  this->inverseViewMatrix.m[3] = 0.0;
  this->inverseViewMatrix.m[4] = 0.0;
  this->inverseViewMatrix.m[5] = 1.0;
  this->inverseViewMatrix.m[6] = 0.0;
  this->inverseViewMatrix.m[7] = 0.0;
  this->inverseViewMatrix.m[8] = 0.0;
  this->inverseViewMatrix.m[9] = 0.0;
  this->inverseViewMatrix.m[10] = 1.0;
  this->inverseViewMatrix.m[11] = 0.0;
  this->inverseViewMatrix.m[12] = 0.0;
  this->inverseViewMatrix.m[13] = 0.0;
  this->inverseViewMatrix.m[14] = 0.0;
  this->inverseViewMatrix.m[15] = 1.0;
  this->worldSpaceMVPMatrix.m[0] = 1.0;
  this->worldSpaceMVPMatrix.m[1] = 0.0;
  this->worldSpaceMVPMatrix.m[2] = 0.0;
  this->worldSpaceMVPMatrix.m[3] = 0.0;
  this->worldSpaceMVPMatrix.m[4] = 0.0;
  this->worldSpaceMVPMatrix.m[5] = 1.0;
  this->worldSpaceMVPMatrix.m[6] = 0.0;
  this->worldSpaceMVPMatrix.m[7] = 0.0;
  this->worldSpaceMVPMatrix.m[8] = 0.0;
  this->worldSpaceMVPMatrix.m[9] = 0.0;
  this->worldSpaceMVPMatrix.m[10] = 1.0;
  this->worldSpaceMVPMatrix.m[11] = 0.0;
  this->worldSpaceMVPMatrix.m[12] = 0.0;
  this->worldSpaceMVPMatrix.m[13] = 0.0;
  this->worldSpaceMVPMatrix.m[14] = 0.0;
  this->worldSpaceMVPMatrix.m[15] = 1.0;
  this->worldSpaceInverseMVPMatrix.m[0] = 1.0;
  this->worldSpaceInverseMVPMatrix.m[1] = 0.0;
  this->worldSpaceInverseMVPMatrix.m[2] = 0.0;
  this->worldSpaceInverseMVPMatrix.m[3] = 0.0;
  this->worldSpaceInverseMVPMatrix.m[4] = 0.0;
  this->worldSpaceInverseMVPMatrix.m[5] = 1.0;
  this->worldSpaceInverseMVPMatrix.m[6] = 0.0;
  this->worldSpaceInverseMVPMatrix.m[7] = 0.0;
  this->worldSpaceInverseMVPMatrix.m[8] = 0.0;
  this->worldSpaceInverseMVPMatrix.m[9] = 0.0;
  this->worldSpaceInverseMVPMatrix.m[10] = 1.0;
  this->worldSpaceInverseMVPMatrix.m[11] = 0.0;
  this->worldSpaceInverseMVPMatrix.m[12] = 0.0;
  this->worldSpaceInverseMVPMatrix.m[13] = 0.0;
  this->worldSpaceInverseMVPMatrix.m[14] = 0.0;
  this->worldSpaceInverseMVPMatrix.m[15] = 1.0;
  this->viewSpaceModelMatrix.m[0] = 1.0;
  this->viewSpaceModelMatrix.m[1] = 0.0;
  this->viewSpaceModelMatrix.m[2] = 0.0;
  this->viewSpaceModelMatrix.m[3] = 0.0;
  this->viewSpaceModelMatrix.m[4] = 0.0;
  this->viewSpaceModelMatrix.m[5] = 1.0;
  this->viewSpaceModelMatrix.m[6] = 0.0;
  this->viewSpaceModelMatrix.m[7] = 0.0;
  this->viewSpaceModelMatrix.m[8] = 0.0;
  this->viewSpaceModelMatrix.m[9] = 0.0;
  this->viewSpaceModelMatrix.m[10] = 1.0;
  this->viewSpaceModelMatrix.m[11] = 0.0;
  this->viewSpaceModelMatrix.m[12] = 0.0;
  this->viewSpaceModelMatrix.m[13] = 0.0;
  this->viewSpaceModelMatrix.m[14] = 0.0;
  this->viewSpaceModelMatrix.m[15] = 1.0;
  this->viewSpaceInverseModelMatrix.m[0] = 1.0;
  this->viewSpaceInverseModelMatrix.m[1] = 0.0;
  this->viewSpaceInverseModelMatrix.m[2] = 0.0;
  this->viewSpaceInverseModelMatrix.m[3] = 0.0;
  this->viewSpaceInverseModelMatrix.m[4] = 0.0;
  this->viewSpaceInverseModelMatrix.m[5] = 1.0;
  this->viewSpaceInverseModelMatrix.m[6] = 0.0;
  this->viewSpaceInverseModelMatrix.m[7] = 0.0;
  this->viewSpaceInverseModelMatrix.m[8] = 0.0;
  this->viewSpaceInverseModelMatrix.m[9] = 0.0;
  this->viewSpaceInverseModelMatrix.m[10] = 1.0;
  this->viewSpaceInverseModelMatrix.m[11] = 0.0;
  this->viewSpaceInverseModelMatrix.m[12] = 0.0;
  this->viewSpaceInverseModelMatrix.m[13] = 0.0;
  this->viewSpaceInverseModelMatrix.m[14] = 0.0;
  this->viewSpaceInverseModelMatrix.m[15] = 1.0;
  this->viewSpaceMVPMatrix.m[0] = 1.0;
  this->viewSpaceMVPMatrix.m[1] = 0.0;
  this->viewSpaceMVPMatrix.m[2] = 0.0;
  this->viewSpaceMVPMatrix.m[3] = 0.0;
  this->viewSpaceMVPMatrix.m[4] = 0.0;
  this->viewSpaceMVPMatrix.m[5] = 1.0;
  this->viewSpaceMVPMatrix.m[6] = 0.0;
  this->viewSpaceMVPMatrix.m[7] = 0.0;
  this->viewSpaceMVPMatrix.m[8] = 0.0;
  this->viewSpaceMVPMatrix.m[9] = 0.0;
  this->viewSpaceMVPMatrix.m[10] = 1.0;
  this->viewSpaceMVPMatrix.m[11] = 0.0;
  this->viewSpaceMVPMatrix.m[12] = 0.0;
  this->viewSpaceMVPMatrix.m[13] = 0.0;
  this->viewSpaceMVPMatrix.m[14] = 0.0;
  this->viewSpaceMVPMatrix.m[15] = 1.0;
  this->windowWidth = 0;
  this->windowHeight = 0;
  this->renderWidth = 0;
  this->renderHeight = 0;
  this->feedbackWidth = 0;
  this->feedbackHeight = 0;
  idScreenRect::Clear(this: &this->viewport);
  idScreenRect::Clear(this: &this->scissorRect);
  idScreenRect::Clear(this: &this->testScissor);
  LODWORD(v1) = 1;
  this->firstOcclusionQueryInPreviousFrame = v1;
  v4 = (occlusionState_t *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\engine\\renderer\\RenderView.cpp(110) : TAG_RENDERWORLD",
                             size: 0x34208u,
                             tag: TAG_RENDERWORLD,
                             zeroBuffer: true,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  this->occlusionState = v4;
  memset(Dst: v4, Val: 0, Size: sizeof(occlusionState_t));
  this->occlusionState->renderFrameNumber = 1;
  return this;
}


// ========================================================================
// __unwind$229764
// EA  : 0x82956B84
// RVA : 0x00956B84
// PDB : w:\tech5\engine\renderer\renderview.cpp
// ========================================================================

void _unwind_229764()
{
  int v0; // r12

  renderView_t::~renderView_t(this: *(renderView_t **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$229765
// EA  : 0x82956BAC
// RVA : 0x00956BAC
// PDB : w:\tech5\engine\renderer\renderview.cpp
// ========================================================================

void _unwind_229765()
{
  int v0; // r12

  idParmBlock::~idParmBlock(this: (idParmBlock *)(*(_DWORD *)(v0 - 128 + 148) + 1896));
}


// ========================================================================
// __unwind$229766
// EA  : 0x82956BD8
// RVA : 0x00956BD8
// PDB : w:\tech5\engine\renderer\renderview.cpp
// ========================================================================

void _unwind_229766()
{
  int v0; // r12

  renderView_t::~renderView_t(this: (renderView_t *)(*(_DWORD *)(v0 - 128 + 148) + 1936));
}


// ========================================================================
// ?CommitParameters@idRenderView@@QAAXHHHH@Z
// EA  : 0x82956C08
// RVA : 0x00956C08
// PDB : w:\tech5\engine\renderer\renderview.cpp
// ========================================================================

void __fastcall idRenderView::CommitParameters(
        idRenderView *this,
        int windowWidth,
        int windowHeight,
        int renderWidth,
        int renderHeight)
{
  renderView_t *p_r; // r28
  long double v11; // fp2
  int v12; // r6
  int v13; // r5

  p_r = &this->r;
  renderView_t::operator=(this: &this->r, __that: &this->g);
  if ( r_jitter.valueInteger != 0 )
  {
    v12 = renderHeight;
    v13 = renderWidth;
  }
  else
  {
    v12 = 0;
    v13 = 0;
  }
  renderView_t::BuildProjectionMatrix(
    this: p_r,
    projectionMatrix: &this->projectionMatrix,
    jitterWidth: v13,
    jitterHeight: v12,
    a5: v11);
  if ( !idRenderMatrix::Inverse(src: &this->projectionMatrix, out: &this->inverseProjectionMatrix) )
    idLib::Error(fmt: "idRenderView: Projection Matrix Invert failed!\n");
  renderView_t::BuildViewMatrix(this: p_r, viewMatrix: &this->viewMatrix);
  idRenderMatrix::InverseByTranspose(src: &this->viewMatrix, out: &this->inverseViewMatrix);
  idRenderMatrix::Multiply(a: &this->projectionMatrix, b: &this->viewMatrix, out: &this->worldSpaceMVPMatrix);
  if ( !idRenderMatrix::Inverse(src: &this->worldSpaceMVPMatrix, out: &this->worldSpaceInverseMVPMatrix) )
    idLib::Error(fmt: "idRenderView: MVP Matrix Invert failed!\n");
  memcpy(Dst: &this->viewSpaceModelMatrix, Src: &this->inverseViewMatrix, Size: sizeof(this->viewSpaceModelMatrix));
  memcpy(
    Dst: &this->viewSpaceInverseModelMatrix,
    Src: &this->viewMatrix,
    Size: sizeof(this->viewSpaceInverseModelMatrix));
  memcpy(Dst: &this->viewSpaceMVPMatrix, Src: &this->projectionMatrix, Size: sizeof(this->viewSpaceMVPMatrix));
  this->viewport.y1 = 0;
  this->viewport.x2 = renderWidth - 1;
  this->viewport.y2 = renderHeight - 1;
  this->viewport.x1 = 0;
  this->windowWidth = windowWidth;
  this->windowHeight = windowHeight;
  this->renderWidth = renderWidth;
  this->renderHeight = renderHeight;
  this->feedbackWidth = 160;
  this->feedbackHeight = 128;
  this->scissorRect.x1 = 0;
  this->scissorRect.y1 = 0;
  this->scissorRect.x2 = renderWidth - 1;
  this->scissorRect.y2 = renderHeight - 1;
}

