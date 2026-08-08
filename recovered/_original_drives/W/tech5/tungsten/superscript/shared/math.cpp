
// ========================================================================
// ?AngToVectors@math@@SAXABVssVector@@PAV2@11@Z
// EA  : 0x82EEB6C8
// RVA : 0x00EEB6C8
// PDB : w:\tech5\tungsten\superscript\shared\math.cpp
// ========================================================================

void __fastcall math::AngToVectors(const ssVector *a, ssVector *f, ssVector *r, ssVector *u, long double a5)
{
  long double v9; // fp2
  double v10; // fp29
  long double v11; // fp2
  double v12; // fp30
  long double v13; // fp2
  double v14; // fp28
  long double v15; // fp2
  double v16; // fp27
  long double v17; // fp2
  double v18; // fp26
  long double v19; // fp2

  *(double *)&a5 = (float)(a->x * (float)0.017452778);
  v9 = sin(x: a5);
  v10 = (float)*(double *)&v9;
  *(double *)&v9 = (float)(a->x * (float)0.017452778);
  v11 = cos(x: v9);
  v12 = (float)*(double *)&v11;
  *(double *)&v11 = (float)(a->y * (float)0.017452778);
  v13 = sin(x: v11);
  v14 = (float)*(double *)&v13;
  *(double *)&v13 = (float)(a->y * (float)0.017452778);
  v15 = cos(x: v13);
  v16 = (float)*(double *)&v15;
  *(double *)&v15 = (float)(a->z * (float)0.017452778);
  v17 = sin(x: v15);
  v18 = (float)*(double *)&v17;
  *(double *)&v17 = (float)(a->z * (float)0.017452778);
  v19 = cos(x: v17);
  if ( f != nullptr )
  {
    f->x = (float)v16 * (float)v12;
    f->y = (float)v14 * (float)v12;
    f->z = -v10;
  }
  if ( r != nullptr )
  {
    r->y = -(float)((float)((float)((float)v18 * (float)v14) * (float)v10) + (float)((float)*(double *)&v19 * (float)v16));
    r->z = -(float)((float)v18 * (float)v12);
    r->x = (float)((float)v14 * (float)v12) - (float)((float)((float)v18 * (float)v16) * (float)v10);
  }
  if ( u != nullptr )
  {
    u->z = (float)*(double *)&v19 * (float)*(double *)&v19;
    u->x = (float)((float)((float)v16 * (float)v12) * (float)v10) + (float)((float)v18 * (float)v14);
    u->y = (float)((float)((float)v14 * (float)v12) * (float)v10) - (float)((float)v18 * (float)v16);
  }
}


// ========================================================================
// `dynamic initializer for 'math::ONE_OVER_TWO_PI''
// EA  : 0x83393E00
// RVA : 0x01393E00
// PDB : w:\tech5\tungsten\superscript\shared\math.cpp
// ========================================================================

void _dynamic_initializer_for__math::ONE_OVER_TWO_PI__()
{
  math::ONE_OVER_TWO_PI = (float)1.0 / math::TWO_PI;
}

