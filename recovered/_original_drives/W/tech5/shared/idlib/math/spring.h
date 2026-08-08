
// ========================================================================
// ?Update@?$idSpring@VidVec3@@@@QAAXM@Z
// EA  : 0x826E9198
// RVA : 0x006E9198
// PDB : w:\tech5\shared\idlib\math\spring.h
// ========================================================================

void __fastcall idSpring<idVec3>::Update(idSpring<idVec3> *this, double dt)
{
  double v2; // fp7
  idVec3 *p_vel; // r11
  idVec3 *p_p1; // r10
  double v5; // fp13
  double v6; // fp3
  double v7; // fp11
  double z; // fp23
  double y; // fp24
  double v12; // fp12
  double v13; // fp12
  double v14; // fp12
  double v15; // fp12
  double v16; // fp10
  double v17; // fp11
  double v18; // fp11
  double v19; // fp3
  double v20; // fp2
  double v21; // fp12
  double v22; // fp3
  double v23; // fp11
  double v24; // fp2
  double v25; // fp1
  double v28; // fp12
  double v29; // fp12
  double v30; // fp12
  double v31; // fp12
  double x; // fp1
  double v35; // fp11
  double v36; // fp2
  double v37; // fp11
  double v38; // fp3
  double v39; // fp1
  double v40; // fp13
  double v42; // fp11
  double v43; // fp10
  double v50; // fp11
  double v51; // fp10

  v2 = dt;
  if ( dt > 0.0 )
  {
    p_vel = &this->vel;
    p_p1 = &this->p1;
    do
    {
      if ( v2 <= 0.0085000005 )
      {
        v5 = v2;
        v2 = 0.0;
      }
      else
      {
        v2 = (float)((float)v2 - (float)0.0085000005);
        v5 = 0.0085000005;
      }
      v6 = (float)(this->p1.y - this->p0.y);
      v7 = (float)(this->p1.z - this->p0.z);
      z = this->vel.z;
      y = this->vel.y;
      _FP28 = (float)((float)((float)((float)(p_p1->x - this->p0.x) * (float)(p_p1->x - this->p0.x))
                            + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f12, f28, f10, f12 }
      v12 = __frsqrte(_FP12);
      v13 = (float)((float)-(float)((float)((float)((float)v12
                                                  * (float)((float)((float)((float)(p_p1->x - this->p0.x)
                                                                          * (float)(p_p1->x - this->p0.x))
                                                                  + (float)((float)((float)v7 * (float)v7)
                                                                          + (float)((float)v6 * (float)v6)))
                                                          * (float)0.5))
                                          * (float)v12)
                                  - (float)1.5)
                  * (float)v12);
      v14 = (float)((float)-(float)((float)((float)((float)v13
                                                  * (float)((float)((float)((float)(p_p1->x - this->p0.x)
                                                                          * (float)(p_p1->x - this->p0.x))
                                                                  + (float)((float)((float)v7 * (float)v7)
                                                                          + (float)((float)v6 * (float)v6)))
                                                          * (float)0.5))
                                          * (float)v13)
                                  - (float)1.5)
                  * (float)v13);
      v15 = (float)((float)-(float)((float)((float)((float)v14
                                                  * (float)((float)((float)((float)(p_p1->x - this->p0.x)
                                                                          * (float)(p_p1->x - this->p0.x))
                                                                  + (float)((float)((float)v7 * (float)v7)
                                                                          + (float)((float)v6 * (float)v6)))
                                                          * (float)0.5))
                                          * (float)v14)
                                  - (float)1.5)
                  * (float)v14);
      v16 = (float)((float)v15
                  * (float)((float)((float)(p_p1->x - this->p0.x) * (float)(p_p1->x - this->p0.x))
                          + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6))));
      v17 = -(float)((float)((float)((float)v15
                                   * (float)((float)((float)(p_p1->x - this->p0.x) * (float)(p_p1->x - this->p0.x))
                                           + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6))))
                           - this->restLength)
                   * this->k);
      v19 = (float)((float)((float)((float)((float)v17 * (float)((float)(p_p1->x - this->p0.x) * (float)v15))
                                  - (float)(p_vel->x * this->c))
                          * (float)((float)1.0 / this->m))
                  * (float)v5);
      v20 = (float)((float)((float)((float)((float)((float)(this->p1.y - this->p0.y) * (float)v15) * (float)v17)
                                  - (float)(this->c * this->vel.y))
                          * (float)((float)1.0 / this->m))
                  * (float)v5);
      v18 = (float)((float)((float)((float)((float)(this->p1.z - this->p0.z) * (float)v15) * (float)v17)
                          - (float)(this->c * this->vel.z))
                  * (float)((float)1.0 / this->m));
      v21 = (float)(p_vel->x + (float)v19);
      p_vel->x = p_vel->x + (float)v19;
      v22 = (float)((float)((float)v18 * (float)v5) + (float)z);
      this->vel.z = (float)((float)v18 * (float)v5) + (float)z;
      v23 = (float)((float)v20 + (float)y);
      this->vel.y = (float)v20 + (float)y;
      v24 = v21;
      v25 = v22;
      _FP31 = (float)((float)((float)((float)v25 * (float)v25)
                            + (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23)))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f12, f31, f3, f12 }
      v28 = __frsqrte(_FP12);
      v29 = (float)((float)-(float)((float)((float)((float)v28
                                                  * (float)((float)((float)((float)v25 * (float)v25)
                                                                  + (float)((float)((float)v24 * (float)v24)
                                                                          + (float)((float)v23 * (float)v23)))
                                                          * (float)0.5))
                                          * (float)v28)
                                  - (float)1.5)
                  * (float)v28);
      v30 = (float)((float)-(float)((float)((float)((float)v29
                                                  * (float)((float)((float)((float)v25 * (float)v25)
                                                                  + (float)((float)((float)v24 * (float)v24)
                                                                          + (float)((float)v23 * (float)v23)))
                                                          * (float)0.5))
                                          * (float)v29)
                                  - (float)1.5)
                  * (float)v29);
      v31 = (float)((float)-(float)((float)((float)((float)v30
                                                  * (float)((float)((float)((float)v25 * (float)v25)
                                                                  + (float)((float)((float)v24 * (float)v24)
                                                                          + (float)((float)v23 * (float)v23)))
                                                          * (float)0.5))
                                          * (float)v30)
                                  - (float)1.5)
                  * (float)v30);
      p_vel->x = (float)v24 * (float)v31;
      this->vel.y = (float)v23 * (float)v31;
      this->vel.z = (float)v22 * (float)v31;
      _FP12 = (float)((float)v31
                    * (float)((float)((float)v25 * (float)v25)
                            + (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23))));
      if ( this->maxSpeed > 0.0 )
      {
        _FP3 = (float)(this->maxSpeed - (float)_FP12);
        __asm { fsel      f12, f3, f12, f11 }
      }
      x = p_vel->x;
      v35 = (float)((float)_FP12 * this->vel.z);
      this->vel.y = (float)_FP12 * this->vel.y;
      this->vel.z = v35;
      p_vel->x = (float)x * (float)_FP12;
      v36 = (float)((float)v5 * this->vel.y);
      v37 = this->p1.y;
      v38 = (float)((float)((float)x * (float)_FP12) * (float)v5);
      v39 = this->p1.z;
      v40 = (float)((float)v5 * this->vel.z);
      p_p1->x = p_p1->x + (float)v38;
      this->p1.z = (float)v39 + (float)v40;
      this->p1.y = (float)v37 + (float)v36;
      if ( _FP12 < 0.0000099999997 )
      {
        this->vel.z = 0.0;
        this->vel.y = 0.0;
        p_vel->x = 0.0;
      }
      if ( v16 < 0.0000099999997 )
      {
        p_p1->x = this->p0.x;
        this->p1.y = this->p0.y;
        this->p1.z = this->p0.z;
      }
    }
    while ( v2 > 0.0 );
  }
  if ( this->hasPMin )
  {
    _FP12 = (float)(this->pMin.x - this->p1.x);
    v42 = this->p1.y;
    v43 = this->p1.z;
    __asm { fsel      f9, f12, f0, f13 }
    this->p1.x = _FP9;
    _FP7 = (float)(this->pMin.y - (float)v42);
    __asm { fsel      f6, f7, f8, f11 }
    this->p1.y = _FP6;
    _FP4 = (float)(this->pMin.z - (float)v43);
    __asm { fsel      f3, f4, f5, f10 }
    this->p1.z = _FP3;
  }
  if ( this->hasPMax )
  {
    _FP12 = (float)(this->pMax.x - this->p1.x);
    v50 = this->p1.y;
    v51 = this->p1.z;
    __asm { fsel      f9, f12, f13, f0 }
    this->p1.x = _FP9;
    _FP7 = (float)(this->pMax.y - (float)v50);
    __asm { fsel      f6, f7, f11, f8 }
    this->p1.y = _FP6;
    _FP4 = (float)(this->pMax.z - (float)v51);
    __asm { fsel      f3, f4, f10, f5 }
    this->p1.z = _FP3;
  }
}


// ========================================================================
// ?SetConstants@?$idSpring@VidVec3@@@@QAAXMM@Z
// EA  : 0x826E94E0
// RVA : 0x006E94E0
// PDB : w:\tech5\shared\idlib\math\spring.h
// ========================================================================

void __fastcall idSpring<idVec3>::SetConstants(idSpring<idVec3> *this, double _k, double _c)
{
  if ( _k > 10000.0 )
  {
    idLib::Warning(fmt: "%s - k=%0.2f exceeds K_MAX=%0.2f", "idSpring<class idVec3>::SetConstants", _k, 10000.0);
    _k = 10000.0;
  }
  this->k = _k;
  if ( _c < 0.0 )
    this->c = (float)__fsqrts((float)(this->m * (float)_k)) * (float)2.0;
  else
    this->c = _c;
}


// ========================================================================
// ?Update@?$idSpring@VidVec1@@@@QAAXM@Z
// EA  : 0x82B83C00
// RVA : 0x00B83C00
// PDB : w:\tech5\shared\idlib\math\spring.h
// ========================================================================

void __fastcall idSpring<idVec1>::Update(idSpring<idVec1> *this, double dt)
{
  double v2; // fp9
  double v3; // fp12
  double v5; // fp11
  double v7; // fp2
  double v12; // fp4

  v2 = dt;
  while ( v2 > 0.0 )
  {
    if ( v2 <= 0.0085000005 )
    {
      v3 = v2;
      v2 = 0.0;
    }
    else
    {
      v2 = (float)((float)v2 - (float)0.0085000005);
      v3 = 0.0085000005;
    }
    _FP4 = (float)(this->p1.x - this->p0.x);
    v5 = __fabs(_FP4);
    __asm { fsel      f4, f4, f8, f7 }
    v7 = -(float)((float)((float)_FP4 * (float)((float)v5 - this->restLength)) * this->k);
    _FP13 = (float)((float)((float)((float)-(float)((float)(this->vel.x * this->c) - (float)v7) / this->m) * (float)v3)
                  + this->vel.x);
    this->vel.x = (float)((float)((float)-(float)((float)(this->vel.x * this->c) - (float)v7) / this->m) * (float)v3)
                + this->vel.x;
    __asm { fsel      f3, f13, f8, f7 }
    this->vel.x = _FP3;
    _FP0 = __fabs(_FP13);
    if ( this->maxSpeed > 0.0 )
    {
      _FP4 = (float)(this->maxSpeed - (float)_FP0);
      __asm { fsel      f0, f4, f0, f13 }
    }
    v12 = (float)(this->vel.x * (float)_FP0);
    this->vel.x = this->vel.x * (float)_FP0;
    this->p1.x = (float)((float)v12 * (float)v3) + this->p1.x;
    if ( _FP0 < 0.0000099999997 )
      this->vel.x = 0.0;
    if ( v5 < 0.0000099999997 )
      this->p1.x = this->p0.x;
  }
  if ( this->hasPMin )
  {
    _FP12 = (float)(this->p1.x - this->pMin.x);
    __asm { fsel      f11, f12, f13, f0 }
    this->p1.x = _FP11;
  }
  if ( this->hasPMax )
  {
    _FP12 = (float)(this->p1.x - this->pMax.x);
    __asm { fsel      f11, f12, f0, f13 }
    this->p1.x = _FP11;
  }
}


// ========================================================================
// ?SetConstants@?$idSpring@VidVec1@@@@QAAXMM@Z
// EA  : 0x82B85D40
// RVA : 0x00B85D40
// PDB : w:\tech5\shared\idlib\math\spring.h
// ========================================================================

void __fastcall idSpring<idVec1>::SetConstants(idSpring<idVec1> *this, double _k, double _c)
{
  if ( _k > 10000.0 )
  {
    idLib::Warning(fmt: "%s - k=%0.2f exceeds K_MAX=%0.2f", "idSpring<class idVec1>::SetConstants", _k, 10000.0);
    _k = 10000.0;
  }
  this->k = _k;
  if ( _c < 0.0 )
    this->c = (float)__fsqrts((float)(this->m * (float)_k)) * (float)2.0;
  else
    this->c = _c;
}


// ========================================================================
// ?SetConstants@?$idSpring@VidVec2@@@@QAAXMM@Z
// EA  : 0x82E3FF20
// RVA : 0x00E3FF20
// PDB : w:\tech5\shared\idlib\math\spring.h
// ========================================================================

void __fastcall idSpring<idVec2>::SetConstants(idSpring<idVec2> *this, double _k, double _c)
{
  if ( _k > 10000.0 )
  {
    idLib::Warning(fmt: "%s - k=%0.2f exceeds K_MAX=%0.2f", "idSpring<class idVec2>::SetConstants", _k, 10000.0);
    _k = 10000.0;
  }
  this->k = _k;
  if ( _c < 0.0 )
    this->c = (float)__fsqrts((float)(this->m * (float)_k)) * (float)2.0;
  else
    this->c = _c;
}


// ========================================================================
// ?Update@?$idSpring@VidVec2@@@@QAAXM@Z
// EA  : 0x82E48D50
// RVA : 0x00E48D50
// PDB : w:\tech5\shared\idlib\math\spring.h
// ========================================================================

void __fastcall idSpring<idVec2>::Update(idSpring<idVec2> *this, double dt)
{
  double v2; // fp7
  idVec2 *p_vel; // r11
  idVec2 *p_p1; // r10
  double v5; // fp12
  double v6; // fp11
  double y; // fp27
  double v10; // fp13
  double v11; // fp13
  double v12; // fp13
  double v13; // fp13
  double v14; // fp10
  double v15; // fp1
  double v16; // fp3
  double v17; // fp2
  double v18; // fp1
  double v19; // fp3
  double v20; // fp11
  double v21; // fp1
  double v24; // fp2
  double v25; // fp13
  double v26; // fp13
  double v29; // fp2
  double v30; // fp1
  double v31; // fp3
  double v33; // fp11
  double v38; // fp11

  v2 = dt;
  if ( dt > 0.0 )
  {
    p_vel = &this->vel;
    p_p1 = &this->p1;
    do
    {
      if ( v2 <= 0.0085000005 )
      {
        v5 = v2;
        v2 = 0.0;
      }
      else
      {
        v2 = (float)((float)v2 - (float)0.0085000005);
        v5 = 0.0085000005;
      }
      v6 = (float)(this->p1.y - this->p0.y);
      y = this->vel.y;
      _FP26 = (float)((float)((float)((float)v6 * (float)v6)
                            + (float)((float)(p_p1->x - this->p0.x) * (float)(p_p1->x - this->p0.x)))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f13, f26, f10, f13 }
      v10 = __frsqrte(_FP13);
      v11 = (float)((float)-(float)((float)((float)((float)v10
                                                  * (float)((float)((float)((float)v6 * (float)v6)
                                                                  + (float)((float)(p_p1->x - this->p0.x)
                                                                          * (float)(p_p1->x - this->p0.x)))
                                                          * (float)0.5))
                                          * (float)v10)
                                  - (float)1.5)
                  * (float)v10);
      v12 = (float)((float)-(float)((float)((float)((float)v11
                                                  * (float)((float)((float)((float)v6 * (float)v6)
                                                                  + (float)((float)(p_p1->x - this->p0.x)
                                                                          * (float)(p_p1->x - this->p0.x)))
                                                          * (float)0.5))
                                          * (float)v11)
                                  - (float)1.5)
                  * (float)v11);
      v13 = (float)((float)-(float)((float)((float)((float)v12
                                                  * (float)((float)((float)((float)v6 * (float)v6)
                                                                  + (float)((float)(p_p1->x - this->p0.x)
                                                                          * (float)(p_p1->x - this->p0.x)))
                                                          * (float)0.5))
                                          * (float)v12)
                                  - (float)1.5)
                  * (float)v12);
      v14 = (float)((float)v13
                  * (float)((float)((float)v6 * (float)v6)
                          + (float)((float)(p_p1->x - this->p0.x) * (float)(p_p1->x - this->p0.x))));
      v15 = -(float)((float)((float)((float)v13
                                   * (float)((float)((float)v6 * (float)v6)
                                           + (float)((float)(p_p1->x - this->p0.x) * (float)(p_p1->x - this->p0.x))))
                           - this->restLength)
                   * this->k);
      v16 = (float)((float)((float)((float)((float)v15 * (float)((float)(p_p1->x - this->p0.x) * (float)v13))
                                  - (float)(this->c * p_vel->x))
                          * (float)((float)1.0 / this->m))
                  * (float)v5);
      v17 = (float)((float)((float)((float)((float)((float)(this->p1.y - this->p0.y) * (float)v13) * (float)v15)
                                  - (float)(this->c * this->vel.y))
                          * (float)((float)1.0 / this->m))
                  * (float)v5);
      v18 = (float)((float)((float)((float)((float)((float)v15 * (float)((float)(p_p1->x - this->p0.x) * (float)v13))
                                          - (float)(this->c * p_vel->x))
                                  * (float)((float)1.0 / this->m))
                          * (float)v5)
                  + p_vel->x);
      p_vel->x = (float)v16 + p_vel->x;
      this->vel.y = (float)v17 + (float)y;
      v19 = this->vel.y;
      v20 = v18;
      v21 = (float)((float)((float)v18 * (float)v18) + (float)(this->vel.y * this->vel.y));
      _FP2 = (float)((float)v21 - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f13, f2, f1, f13 }
      v24 = __frsqrte(_FP13);
      v25 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24
                                                                                          * (float)((float)v21
                                                                                                  * (float)0.5))
                                                                                  * (float)v24)
                                                                          - (float)1.5)
                                                          * (float)v24)
                                                  * (float)((float)v21 * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v24
                                                                                  * (float)((float)v21 * (float)0.5))
                                                                          * (float)v24)
                                                                  - (float)1.5)
                                                  * (float)v24))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)v21 * (float)0.5)) * (float)v24)
                                          - (float)1.5)
                          * (float)v24));
      v26 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)v21 * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                                  * (float)v24)
                                                                                          * (float)((float)v21
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)v21 * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                          * (float)v24))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v24
                                                                                                  * (float)((float)v21 * (float)0.5))
                                                                                          * (float)v24)
                                                                                  - (float)1.5)
                                                                  * (float)v24))
                                                  * (float)((float)v21 * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)v21 * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                          * (float)v24)
                                                                                  * (float)((float)v21 * (float)0.5))
                                                                          * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)v21 * (float)0.5)) * (float)v24)
                                                                                                  - (float)1.5)
                                                                                  * (float)v24))
                                                                  - (float)1.5)
                                                  * (float)((float)-(float)((float)((float)((float)v24
                                                                                          * (float)((float)v21
                                                                                                  * (float)0.5))
                                                                                  * (float)v24)
                                                                          - (float)1.5)
                                                          * (float)v24)))
                                  - (float)1.5)
                  * (float)v25);
      p_vel->x = (float)v20 * (float)v26;
      this->vel.y = (float)v19 * (float)v26;
      _FP13 = (float)((float)v26 * (float)v21);
      if ( this->maxSpeed > 0.0 )
      {
        _FP3 = (float)(this->maxSpeed - (float)_FP13);
        __asm { fsel      f13, f3, f13, f11 }
      }
      v29 = (float)((float)_FP13 * p_vel->x);
      v30 = (float)((float)_FP13 * this->vel.y);
      this->vel.y = (float)_FP13 * this->vel.y;
      p_vel->x = v29;
      v31 = this->p1.y;
      p_p1->x = p_p1->x + (float)((float)v5 * (float)v29);
      this->p1.y = (float)v31 + (float)((float)v5 * (float)v30);
      if ( _FP13 < 0.0000099999997 )
      {
        this->vel.y = 0.0;
        p_vel->x = 0.0;
      }
      if ( v14 < 0.0000099999997 )
      {
        p_p1->x = this->p0.x;
        this->p1.y = this->p0.y;
      }
    }
    while ( v2 > 0.0 );
  }
  if ( this->hasPMin )
  {
    _FP12 = (float)(this->p1.x - this->pMin.x);
    v33 = this->p1.y;
    __asm { fsel      f10, f12, f13, f0 }
    this->p1.x = _FP10;
    _FP8 = (float)((float)v33 - this->pMin.y);
    __asm { fsel      f7, f8, f11, f9 }
    this->p1.y = _FP7;
  }
  if ( this->hasPMax )
  {
    _FP12 = (float)(this->p1.x - this->pMax.x);
    v38 = this->p1.y;
    __asm { fsel      f10, f12, f0, f13 }
    this->p1.x = _FP10;
    _FP8 = (float)((float)v38 - this->pMax.y);
    __asm { fsel      f7, f8, f9, f11 }
    this->p1.y = _FP7;
  }
}

