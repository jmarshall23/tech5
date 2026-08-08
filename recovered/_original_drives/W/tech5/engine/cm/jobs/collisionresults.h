
// ========================================================================
// ?CopyFrom@contactsResult_t@@QAAXABU1@@Z
// EA  : 0x825DDB08
// RVA : 0x005DDB08
// PDB : w:\tech5\engine\cm\jobs\collisionresults.h
// ========================================================================

void __fastcall contactsResult_t::CopyFrom(contactsResult_t *this, const contactsResult_t *other)
{
  int v2; // r9
  bool v3; // cr57
  char *v4; // r10
  float *p_y; // r11

  v2 = 0;
  v3 = other->numContacts > 0;
  this->numContacts = other->numContacts;
  if ( v3 )
  {
    v4 = (char *)&other->pad[2] + 3;
    p_y = &this->contacts[0].point.y;
    do
    {
      if ( v2 >= 12 )
        break;
      ++v2;
      *(p_y - 2) = *(float *)(v4 + 1);
      *(p_y - 1) = *(float *)(v4 + 5);
      *p_y = *(float *)((char *)p_y + (char *)other - (char *)this);
      p_y[1] = *(float *)(v4 + 13);
      p_y[2] = *(float *)(v4 + 17);
      p_y[3] = *(float *)(v4 + 21);
      p_y[4] = *(float *)(v4 + 25);
      p_y[5] = *(float *)(v4 + 29);
      p_y[6] = *(float *)(v4 + 33);
      p_y[7] = *(float *)(v4 + 37);
      p_y[8] = *(float *)(v4 + 41);
      p_y[9] = *(float *)(v4 + 45);
      p_y[10] = *(float *)(v4 + 49);
      p_y[11] = *(float *)(v4 + 53);
      p_y[12] = *(float *)(v4 + 57);
      p_y[13] = *(float *)(v4 + 61);
      p_y[14] = *(float *)(v4 + 65);
      p_y[15] = *(float *)(v4 + 69);
      *((_BYTE *)p_y + 64) = v4[73];
      *((_BYTE *)p_y + 65) = v4[74];
      *((_BYTE *)p_y + 66) = v4[75];
      v4 += 76;
      *((_BYTE *)p_y + 67) = *v4;
      p_y += 19;
    }
    while ( v2 < this->numContacts );
  }
}

