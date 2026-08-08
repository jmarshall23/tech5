
// ========================================================================
// ?EnumeratePlaylists@idXboxMediaPlayer@@AAAXXZ
// EA  : 0x82988E98
// RVA : 0x00988E98
// PDB : w:\tech5\engine\sound\mediaplayer\xboxmediaplayer.cpp
// ========================================================================

void __fastcall idXboxMediaPlayer::EnumeratePlaylists(idXboxMediaPlayer *this)
{
  unsigned int v2; // r31
  wchar_t *wszTitle; // r30
  XMP_USERPLAYLISTINFO *v4; // r31
  int v5; // [sp+50h] [-380h] BYREF
  unsigned int v6; // [sp+54h] [-37Ch] BYREF
  unsigned int v7[222]; // [sp+58h] [-378h] BYREF

  v5 = -1;
  XMPCreateUserPlaylistEnumerator(dwFlags: 0, cItems: 0xAu, pcbBuffer: v7, ph: (void **)&v5);
  XEnumerate(hEnum: (void *)v5, pvBuffer: this->playLists, cbBuffer: v7[0], pcItemsReturned: &v6, pOverlapped: nullptr);
  v2 = 1;
  if ( v6 > 1 )
  {
    wszTitle = this->playLists[1].wszTitle;
    while ( wcsicmp(dst: L"Rage", src: wszTitle) != 0 )
    {
      ++v2;
      wszTitle += 410;
      if ( v2 >= v6 )
        goto LABEL_7;
    }
    memcpy(Dst: &v7[2], Src: this->playLists, Size: 0x334u);
    v4 = &this->playLists[v2];
    memcpy(Dst: this->playLists, Src: v4, Size: 0x334u);
    memcpy(Dst: v4, Src: &v7[2], Size: sizeof(XMP_USERPLAYLISTINFO));
  }
LABEL_7:
  CloseHandle(hObject: (void *)v5);
}


// ========================================================================
// ?Start@idXboxMediaPlayer@@UAAXXZ
// EA  : 0x82988F80
// RVA : 0x00988F80
// PDB : w:\tech5\engine\sound\mediaplayer\xboxmediaplayer.cpp
// ========================================================================

void __fastcall idXboxMediaPlayer::Start(idXboxMediaPlayer *this)
{
  XMPPlayUserPlaylist(pUserPlaylist: &this->playLists[this->currentPlaylist], pOverlapped: nullptr);
}


// ========================================================================
// ?Stop@idXboxMediaPlayer@@UAAXXZ
// EA  : 0x82988F98
// RVA : 0x00988F98
// PDB : w:\tech5\engine\sound\mediaplayer\xboxmediaplayer.cpp
// ========================================================================

void __fastcall idXboxMediaPlayer::Stop(idXboxMediaPlayer *this)
{
  XMPStop(pOverlapped: nullptr);
}


// ========================================================================
// ?Pause@idXboxMediaPlayer@@UAAXXZ
// EA  : 0x82988FA0
// RVA : 0x00988FA0
// PDB : w:\tech5\engine\sound\mediaplayer\xboxmediaplayer.cpp
// ========================================================================

void __fastcall idXboxMediaPlayer::Pause(idXboxMediaPlayer *this)
{
  XMPPause(pOverlapped: nullptr);
}


// ========================================================================
// ?Resume@idXboxMediaPlayer@@UAAXXZ
// EA  : 0x82988FA8
// RVA : 0x00988FA8
// PDB : w:\tech5\engine\sound\mediaplayer\xboxmediaplayer.cpp
// ========================================================================

void __fastcall idXboxMediaPlayer::Resume(idXboxMediaPlayer *this)
{
  XMPContinue(pOverlapped: nullptr);
}


// ========================================================================
// ?NextSong@idXboxMediaPlayer@@UAAXXZ
// EA  : 0x82988FB0
// RVA : 0x00988FB0
// PDB : w:\tech5\engine\sound\mediaplayer\xboxmediaplayer.cpp
// ========================================================================

void __fastcall idXboxMediaPlayer::NextSong(idXboxMediaPlayer *this)
{
  XMPNext(pOverlapped: nullptr);
}


// ========================================================================
// ?PreviousSong@idXboxMediaPlayer@@UAAXXZ
// EA  : 0x82988FB8
// RVA : 0x00988FB8
// PDB : w:\tech5\engine\sound\mediaplayer\xboxmediaplayer.cpp
// ========================================================================

void __fastcall idXboxMediaPlayer::PreviousSong(idXboxMediaPlayer *this)
{
  XMPPrevious(pOverlapped: nullptr);
}


// ========================================================================
// ?Volume@idXboxMediaPlayer@@UAAXM@Z
// EA  : 0x82988FC0
// RVA : 0x00988FC0
// PDB : w:\tech5\engine\sound\mediaplayer\xboxmediaplayer.cpp
// ========================================================================

void __fastcall idXboxMediaPlayer::Volume(idXboxMediaPlayer *this, double vol)
{
  XMPSetVolume(fVolume: vol, pOverlapped: (_XOVERLAPPED *)this);
}


// ========================================================================
// ?SetCurrentPlaylist@idXboxMediaPlayer@@UAAXH@Z
// EA  : 0x82988FC8
// RVA : 0x00988FC8
// PDB : w:\tech5\engine\sound\mediaplayer\xboxmediaplayer.cpp
// ========================================================================

void __fastcall idXboxMediaPlayer::SetCurrentPlaylist(idXboxMediaPlayer *this, int listNum)
{
  if ( listNum >= 0 && listNum < this->numPlaylists )
  {
    this->Stop(this);
    this->currentPlaylist = listNum;
    this->Start(this);
  }
}


// ========================================================================
// `dynamic initializer for 'xboxMediaPlayer''
// EA  : 0x83360098
// RVA : 0x01360098
// PDB : w:\tech5\engine\sound\mediaplayer\xboxmediaplayer.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__xboxMediaPlayer__()
{
  idXboxMediaPlayer::EnumeratePlaylists(this: &xboxMediaPlayer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__xboxMediaPlayer__);
}

