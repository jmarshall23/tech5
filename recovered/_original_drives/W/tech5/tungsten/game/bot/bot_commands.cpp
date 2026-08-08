
// ========================================================================
// ?Cmd_RemoveBot_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82B40BF0
// RVA : 0x00B40BF0
// PDB : w:\tech5\tungsten\game\bot\bot_commands.cpp
// ========================================================================

void __fastcall Cmd_RemoveBot_f(const idCmdArgs *args)
{
  const char *v2; // r3
  int v3; // r3
  idPlayer *v4; // r3
  idPlayer *v5; // r31
  idLobbyBase *v6; // r3
  idPresentable *v7; // r11
  idLobbyBase *v8; // r31
  lobbyUserID_t *v9; // r4
  idLobbyBase_vtbl *v10; // r30
  lobbyUserID_t *v11; // r3
  int i; // r29
  idPlayer *Player; // r3
  idPlayer *v14; // r31
  idLobbyBase *v15; // r3
  idPresentable *presentable; // r11
  idLobbyBase *v17; // r31
  lobbyUserID_t *v18; // r4
  idLobbyBase_vtbl *v19; // r30
  lobbyUserID_t *LobbyUserID; // r3
  _BYTE v21[64]; // [sp+50h] [-40h] BYREF

  if ( !common->IsClient(this: common) )
  {
    if ( args->argc < 2 )
    {
      for ( i = 0; i < 6; ++i )
      {
        Player = idGameLocal::GetPlayer(this: gameLocal, i);
        v14 = Player;
        if ( Player != nullptr && idPlayer::IsBot(this: Player) && !idPlayer::IsBotControllingAFKPlayer(this: v14) )
        {
          v15 = session->GetActingGameStateLobbyBase(this: session);
          presentable = v14->presentable;
          v17 = v15;
          if ( presentable != nullptr )
            v18 = (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: presentable);
          else
            v18 = nullptr;
          v19 = v17->__vftable;
          LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)v21, result: v18);
          v19->RemoveBotFromLobbyUserList(
            this: (idLobbyBase *)LobbyUserID->localUserHandle.handle,
            a2: *(lobbyUserID_t **)&LobbyUserID->lobbyType);
        }
      }
    }
    else
    {
      if ( args->argc <= 1 )
        v2 = &byte_8200D768;
      else
        v2 = args->argv[1];
      v3 = atol(nptr: v2);
      v4 = idGameLocal::GetPlayer(this: gameLocal, i: v3);
      v5 = v4;
      if ( v4 != nullptr && idPlayer::IsBot(this: v4) && !idPlayer::IsBotControllingAFKPlayer(this: v5) )
      {
        v6 = session->GetActingGameStateLobbyBase(this: session);
        v7 = v5->presentable;
        v8 = v6;
        if ( v7 != nullptr )
          v9 = (lobbyUserID_t *)v7->GetPlayerInterface_2(this: v7);
        else
          v9 = nullptr;
        v10 = v8->__vftable;
        v11 = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)v21, result: v9);
        v10->RemoveBotFromLobbyUserList(
          this: (idLobbyBase *)v11->localUserHandle.handle,
          a2: *(lobbyUserID_t **)&v11->lobbyType);
      }
    }
  }
}


// ========================================================================
// ?Cmd_AddBot_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82B40DD0
// RVA : 0x00B40DD0
// PDB : w:\tech5\tungsten\game\bot\bot_commands.cpp
// ========================================================================

void __fastcall Cmd_AddBot_f(const idCmdArgs *args)
{
  idGameLocal *v1; // r11
  int num; // r27
  int v3; // r28
  int value; // r9
  idPlayer *v5; // r3
  idPlayer *v6; // r30
  idLobbyBase *v7; // r3
  idPresentable *presentable; // r11
  idLobbyBase *v9; // r30
  lobbyUserID_t *v10; // r4
  idLobbyBase_vtbl *v11; // r29
  lobbyUserID_t *LobbyUserID; // r3
  const char *v13; // r3
  int v14; // r9
  int v15; // r22
  idStr *list; // r21
  idClientGame *v17; // r10
  signed int v18; // r11
  int v19; // r28
  idClientGame *v20; // r9
  int v21; // r3
  char v22; // r26
  int v23; // r29
  const char **p_data; // r30
  idVehicleState *v25; // r30
  idLobbyBase *v26; // r3
  _BYTE v27[16]; // [sp+50h] [-C0h] BYREF
  idList<idVehicleState *,5> v28; // [sp+60h] [-B0h] BYREF
  idList<idStr,5> v29; // [sp+70h] [-A0h] BYREF
  idStr v30[4]; // [sp+80h] [-90h] BYREF

  if ( !common->IsClient(this: common) && session->GetState(this: session) == INGAME )
  {
    *(_WORD *)&v29.memTag = 1280;
    memset(&v29, 0, 14);
    idList<idStr,3>::Resize(this: &v29, newsize: 6);
    v1 = gameLocal;
    if ( gameLocal->playerEntities.num > 0 )
    {
      num = gameLocal->playerEntities.num;
      v3 = 0;
      do
      {
        value = v1->playerEntities.list[v3].spawnId.value;
        if ( v1->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v5 = (idPlayer *)v1->entities.ptr[value & 0x1FFF];
          if ( v5 != nullptr )
          {
            v6 = idPlayer::CastTo(c: v5);
            if ( v6 != nullptr )
            {
              v7 = session->GetActingGameStateLobbyBase(this: session);
              presentable = v6->presentable;
              v9 = v7;
              if ( presentable != nullptr )
                v10 = (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: presentable);
              else
                v10 = nullptr;
              v11 = v9->__vftable;
              LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)v27, result: v10);
              v13 = v11->GetLobbyUserName(
                      this: (idLobbyBase *)LobbyUserID->localUserHandle.handle,
                      a2: *(lobbyUserID_t **)&LobbyUserID->lobbyType);
              idStr::idStr(this: v30, text: v13);
              idList<idStr,5>::Append(this: &v29, obj: v30);
              idStr::FreeData(this: v30);
            }
            v1 = gameLocal;
          }
        }
        --num;
        ++v3;
      }
      while ( num != 0 );
    }
    *(_WORD *)&v28.memTag = 1280;
    memset(&v28, 0, 14);
    idResourceList::GetLoadedResources(this: &idDeclBot::resourceList, resourceList: &v28);
    v14 = v28.num;
    if ( v28.num <= 0 )
      goto LABEL_34;
    v15 = v29.num;
    list = v29.list;
    while ( 1 )
    {
      v17 = clientGame;
      v18 = v14;
      if ( v14 != 0 )
      {
        v20 = clientGame;
        __twllei(v18, 0);
        v20->random.seed = 1664525 * v20->random.seed + 1013904223;
        v21 = (v17->random.seed >> 10) & 0x7FFF;
        v14 = v28.num;
        v19 = v21 % v18;
        __twlgei(v18 & ~(__ROL4__(v21, 1) - 1), 0xFFFFFFFF);
      }
      else
      {
        v19 = 0;
      }
      v22 = 0;
      v23 = 0;
      if ( v15 > 0 )
      {
        p_data = (const char **)&list->data;
        while ( idStr::Icmp(s1: *p_data, s2: v28.list[v19]->debugInfo.data) != 0 )
        {
          ++v23;
          p_data += 8;
          if ( v23 >= v15 )
            goto LABEL_25;
        }
        v22 = 1;
LABEL_25:
        v14 = v28.num;
      }
      if ( v22 == 0 )
        break;
      if ( v19 >= 0 && v19 < v14 )
      {
        v28.num = --v14;
        if ( v19 != v14 )
        {
          v28.list[v19] = v28.list[v14];
          v14 = v28.num;
        }
      }
      if ( v14 <= 0 )
        goto LABEL_34;
    }
    v25 = v28.list[v19];
    if ( v25 != nullptr )
    {
      v26 = session->GetActingGameStateLobbyBase(this: session);
      v26->AllocLobbyUserSlotForBot(
        this: (idLobbyBase *)v27,
        result: (lobbyUserID_t *)v26,
        a3: v25->debugInfo.data,
        a4: v25);
      idList<idThread *,58>::Clear(this: &v28);
    }
    else
    {
LABEL_34:
      idLib::Warning(fmt: "CMD: 'bot_add' - Can't Add Bot - No Valid Bot Defs Available!");
      idList<idThread *,58>::Clear(this: &v28);
    }
    idList<idStr,99>::~idList<idStr,99>(this: &v29);
  }
}


// ========================================================================
// __unwind$489206_0
// EA  : 0x82B4112C
// RVA : 0x00B4112C
// PDB : w:\tech5\tungsten\game\bot\bot_commands.cpp
// ========================================================================

void _unwind_489206_0()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 272 + 112));
}


// ========================================================================
// __unwind$489207_0
// EA  : 0x82B41154
// RVA : 0x00B41154
// PDB : w:\tech5\tungsten\game\bot\bot_commands.cpp
// ========================================================================

void _unwind_489207_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// __unwind$489208_0
// EA  : 0x82B4117C
// RVA : 0x00B4117C
// PDB : w:\tech5\tungsten\game\bot\bot_commands.cpp
// ========================================================================

void _unwind_489208_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 272 + 96));
}


// ========================================================================
// ?InitBotCommands@@YAXXZ
// EA  : 0x82B411A8
// RVA : 0x00B411A8
// PDB : w:\tech5\tungsten\game\bot\bot_commands.cpp
// ========================================================================

void __fastcall InitBotCommands()
{
  cmdSystem->AddCommand(this: cmdSystem, a2: "bot_add", a3: Cmd_AddBot_f, a4: "Spawns a bot", a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "bot_remove",
    a3: Cmd_RemoveBot_f,
    a4: "If clientNum passed, removes bot with that clientNum, else removes all bots",
    a5: nullptr);
}

