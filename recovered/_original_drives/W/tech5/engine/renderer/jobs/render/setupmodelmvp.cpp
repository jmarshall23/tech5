
// ========================================================================
// ?SetupModelMVPMatrix@@YAXAAVidRenderMatrix@@PBVidRenderModelCommitted@@PBVidRenderView@@MM@Z
// EA  : 0x828E4948
// RVA : 0x008E4948
// PDB : w:\tech5\engine\renderer\jobs\render\setupmodelmvp.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall SetupModelMVPMatrix(
        idRenderMatrix *mvpMatrix,
        const idRenderModelCommitted *model,
        const idRenderView *renderView,
        double zNear,
        double zFar)
{
  __int64 v10; // r9
  __int64 v11; // r7 OVERLAPPED
  double x; // fp11
  double y; // fp12
  double z; // fp0
  char *v15; // r11
  int i; // ctr
  double v17; // fp10
  double v18; // fp9
  int windowWidth; // r8
  long double v20; // fp2
  idRenderMatrix *p_projectionMatrix; // r3
  long double v22; // fp2
  double v23; // fp28
  long double v24; // fp2
  idRenderMatrix *v25; // r3
  double modelDepthHack; // fp0
  idVec4 v27; // [sp+60h] [-180h] BYREF
  __int64 v28; // [sp+70h] [-170h]
  char v29; // [sp+78h] [-168h] BYREF
  idRenderMatrix v30; // [sp+80h] [-160h] BYREF
  idRenderMatrix viewMatrix; // [sp+C0h] [-120h] BYREF
  idVec4 v32; // [sp+100h] [-E0h] BYREF
  idRenderMatrix v33; // [sp+110h] [-D0h] BYREF
  char v34; // [sp+150h] [-90h] BYREF

  if ( (*((_BYTE *)&model->r + 105) & 1) != 0 )
    goto LABEL_2;
  if ( (*((_BYTE *)&model->r + 106) & 0x80) != 0 )
  {
    mvpMatrix->m[0] = model->r.scale.x;
    mvpMatrix->m[1] = 0.0;
    mvpMatrix->m[2] = 0.0;
    mvpMatrix->m[3] = model->r.origin.x;
    mvpMatrix->m[4] = 0.0;
    mvpMatrix->m[5] = model->r.scale.y;
    mvpMatrix->m[6] = 0.0;
    mvpMatrix->m[7] = model->r.origin.y;
    mvpMatrix->m[8] = 0.0;
    mvpMatrix->m[9] = 0.0;
    mvpMatrix->m[10] = 0.0;
    mvpMatrix->m[11] = 0.0;
    mvpMatrix->m[12] = 0.0;
    mvpMatrix->m[13] = 0.0;
    mvpMatrix->m[14] = 0.0;
    mvpMatrix->m[15] = 1.0;
  }
  else
  {
    if ( renderView == nullptr )
    {
LABEL_2:
      mvpMatrix->m[0] = 1.0;
      mvpMatrix->m[1] = 0.0;
      mvpMatrix->m[2] = 0.0;
      mvpMatrix->m[3] = 0.0;
      mvpMatrix->m[4] = 0.0;
      mvpMatrix->m[5] = 1.0;
      mvpMatrix->m[6] = 0.0;
      mvpMatrix->m[7] = 0.0;
      mvpMatrix->m[8] = 0.0;
      mvpMatrix->m[9] = 0.0;
      mvpMatrix->m[10] = 1.0;
      mvpMatrix->m[11] = 0.0;
      mvpMatrix->m[12] = 0.0;
      mvpMatrix->m[13] = 0.0;
      mvpMatrix->m[14] = 0.0;
      mvpMatrix->m[15] = 1.0;
      return;
    }
    if ( (*((_BYTE *)&model->r + 106) & 0x40) != 0 )
    {
      viewMatrix = renderView->viewMatrix;
      viewMatrix.m[3] = 0.0;
      viewMatrix.m[7] = 0.0;
      viewMatrix.m[11] = 0.0;
      idRenderMatrix::TransformModelToClip(
        src: &model->r.origin,
        modelMatrix: &viewMatrix,
        projectionMatrix: &renderView->projectionMatrix,
        eye: &v32,
        clip: &v27);
      *(float *)&v10 = v27.x;
      *(float *)&v11 = v27.z;
      if ( __fabs(v27.w) <= idMath::FLT_SMALLEST_NON_DENORMAL )
      {
        z = v27.z;
        y = v27.y;
        x = v27.x;
      }
      else
      {
        x = (float)(v27.x * (float)((float)1.0 / v27.w));
        y = (float)(v27.y * (float)((float)1.0 / v27.w));
        z = (float)(v27.z * (float)((float)1.0 / v27.w));
      }
      v15 = &v29;
      LODWORD(v10) = 0;
      for ( i = 8; i != 0; --i )
      {
        v15 += 8;
        *(_QWORD *)v15 = v10;
      }
      v17 = model->r.scale.x;
      LODWORD(v11) = renderView->windowHeight;
      v18 = model->r.scale.y;
      windowWidth = renderView->windowWidth;
      v30.m[3] = x;
      v28 = v11;
      v30.m[10] = 1.0;
      v30.m[7] = y;
      v30.m[0] = (float)v17 / (float)*(__int64 *)((char *)&v11 - 4);
      v30.m[5] = (float)v18 / (float)v11;
      if ( z >= -1.0 && z <= 1.0 )
        z = 0.99989998;
      v30.m[11] = z;
      v30.m[15] = 1.0;
      idRenderMatrix::Multiply(a: &v30, b: &renderMatrix_flipToOpenGL, out: mvpMatrix);
    }
    else
    {
      idRenderMatrix::Multiply(a: &renderView->viewMatrix, b: &model->modelMatrix, out: &v33);
      if ( model->r.fovScale == 1.0 )
      {
        p_projectionMatrix = &renderView->projectionMatrix;
      }
      else
      {
        if ( renderView->r.cramZNear )
          zNear = (float)((float)zNear * (float)0.25);
        *(double *)&v20 = (float)((float)((float)(renderView->r.fov_y * model->r.fovScale) * idMath::M_DEG2RAD)
                                * (float)0.5);
        v22 = tan(x: v20);
        v23 = (float)((float)*(double *)&v22 * (float)zNear);
        *(double *)&v22 = (float)((float)((float)(renderView->r.fov_x * model->r.fovScale) * idMath::M_DEG2RAD)
                                * (float)0.5);
        v24 = tan(x: v22);
        idRenderMatrix::BuildProjection(
          xMin: -(float)((float)*(double *)&v24 * (float)zNear),
          xMax: (float)((float)*(double *)&v24 * (float)zNear),
          yMin: -v23,
          yMax: v23,
          zNear,
          zFar,
          out: v25);
        p_projectionMatrix = (idRenderMatrix *)&v34;
      }
      idRenderMatrix::Multiply(a: p_projectionMatrix, b: &v33, out: mvpMatrix);
      modelDepthHack = model->r.modelDepthHack;
      if ( modelDepthHack > 0.0 )
      {
        mvpMatrix->m[8] = mvpMatrix->m[8] * model->r.modelDepthHack;
        mvpMatrix->m[9] = mvpMatrix->m[9] * (float)modelDepthHack;
        mvpMatrix->m[10] = mvpMatrix->m[10] * (float)modelDepthHack;
        mvpMatrix->m[11] = mvpMatrix->m[11] * (float)modelDepthHack;
      }
    }
  }
}

