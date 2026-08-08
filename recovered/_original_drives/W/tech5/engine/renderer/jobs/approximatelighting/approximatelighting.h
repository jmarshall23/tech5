
// ========================================================================
// ?Clear@approximateLighting_t@@QAAXXZ
// EA  : 0x828D2300
// RVA : 0x008D2300
// PDB : w:\tech5\engine\renderer\jobs\approximatelighting\approximatelighting.h
// ========================================================================

void __fastcall approximateLighting_t::Clear(approximateLighting_t *this)
{
  this->primeLightDir.w = 0.0;
  this->primeLightDir.z = 0.0;
  this->primeLightDir.y = 0.0;
  this->primeLightDir.x = 0.0;
  this->primeLightColor.w = 0.0;
  this->primeLightColor.z = 0.0;
  this->primeLightColor.y = 0.0;
  this->primeLightColor.x = 0.0;
  this->channelLighting[0].x = 0.0;
  this->channelLighting[0].w = 0.0;
  this->channelLighting[0].z = 0.0;
  this->channelLighting[0].y = 0.0;
  this->channelLighting[1].w = 0.0;
  this->channelLighting[1].z = 0.0;
  this->channelLighting[1].y = 0.0;
  this->channelLighting[1].x = 0.0;
  this->channelLighting[2].w = 0.0;
  this->channelLighting[2].z = 0.0;
  this->channelLighting[2].y = 0.0;
  this->channelLighting[2].x = 0.0;
  this->channelLighting[3].w = 0.0;
  this->channelLighting[3].z = 0.0;
  this->channelLighting[3].y = 0.0;
  this->channelLighting[3].x = 0.0;
  this->channelLighting[4].w = 0.0;
  this->channelLighting[4].z = 0.0;
  this->channelLighting[4].y = 0.0;
  this->channelLighting[4].x = 0.0;
  this->channelLighting[5].w = 0.0;
  this->channelLighting[5].z = 0.0;
  this->channelLighting[5].y = 0.0;
  this->channelLighting[5].x = 0.0;
}

