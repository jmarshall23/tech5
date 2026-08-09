#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\mainmenulocal.h
// Recovered logical types: 243
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1456; PDB kind: enum.
enum idMainMenu::mainmenuState_t : __int32
{
  SELECTING_MAP = 0x1,
  SELECTING_GAMEMODE = 0x2,
  VIEWING_LEADERBOARD = 0x3,
  LOADING_LEADERBOARD = 0x4,
};

// IDA Local Type ordinal 1487; PDB kind: enum.
enum idMainMenu::popupResult_t : __int32
{
  POPUP_RESULT_NONE = 0xFFFFFFFF,
  POPUP_RESULT_OPTION1 = 0x0,
  POPUP_RESULT_OPTION2 = 0x1,
  POPUP_RESULT_OPTION3 = 0x2,
};

// IDA Local Type ordinal 16051; PDB kind: struct.
struct __declspec(align(4)) idMainMenu::actionRepeater_t
{
  idMenuWidget *widget;
  idWidgetEvent event;
  idWidgetAction action;
  int numRepetitions;
  int nextRepeatTime;
  mainMenuScreens_t menu;
  bool isActive;
};

// IDA Local Type ordinal 16069; PDB kind: class.
class idMainMenu
{
public:
  idMainMenu::actionRepeater_t actionRepeater;
  mainMenuScreens_t activeMenu;
  mainMenuScreens_t nextMenu;
  mainMenuTransition_t menuTransition;
  idMenuScreen *menuScreens[7];
  int menuIndex[7];
  int numOptions[7];
  bool scrollingMenu;
  int scrollCounter;
  idStr btn1Text;
  idStr btn2Text;
  idStr btn3Text;
  idStr btn4Text;
  int devMenuDepth;
  const idDeclDevMenuList *devMenuList;
  idList<char const *,5> devMapListNames;
  idList<int,5> devMapListIndexes;
  idList<int,5> optionTypes;
  float audioMasterVolume;
  float audioMasterVolume_Restore;
  float audioVoiceVolume;
  float audioVoiceVolume_Restore;
  float audioMusicVolume;
  float audioMusicVolume_Restore;
  float audioAmbientVolume;
  float audioAmbientVolume_Restore;
  bool audioSubtitles;
  bool audioSubtitles_Restore;
  idRenderModelGui *guiModel;
  idSoundWorld *soundWorld;
  idSWF *loadMostRecentCallingGui;
  idSWF *testGui;
  idSWF *mainMenu;
  idSWF *popupGui;
  int currentDeviceIndex;
  int savegameEnumHandle;
  bool closePopupGui;
  int popupResult;
  idStr popupCallback;
  bool showingMatchResults;
  int showingUnlockedItemIndex;
  int nextScrollTime;
  int scrollSpeed;
  bool waitForBinding;
  bool finishBinding;
  int bindWaitKey;
  idStr bindAction;
  int bindSet;
  bool savedGamesUpdateRequested;
  bool isDeletingGame;
  bool needsSaveInfoEnumerate;
  pauseMenuState_t pauseMenuState;
  bool askedForSignIn;
  idSysSignal deviceRequestedSignal;
  bool singlePlayerSelected;
  bool requestingDevice;
  bool saveAfterDeviceRequest;
  idStr saveAfterDeviceRequestFolder;
  bool autosaveWarningShown;
  bool autosaveWarningShownAllowsAutosave;
  bool requestingDLC;
  bool ps3MenuRequested;
  bool returnToPressStartWaitSaveComplete;
  int matchMapIndex;
  int matchModeIndex;
  int matchSearchIndex;
  int matchTypeIndex;
  bool privateMatch;
  bool localMatch;
  int coopDifficulty;
  int scoreLimit;
  int timeLimit;
  bool coopInviteOnly;
  bool vdmInviteOnly;
  int deferredActivateMsec;
  int deferredDeactivateMsec;
  int menuState;
  int lastMenuState;
  bool installMessageShown;
  bool diskSwapInputLock;
  bool storageDialogActivated;
  bool askToDeleteAutosaveOnNewGame;
  idLBCache *lbCache;
  bool vdmLeaderboard;
  int coopLBIndex;
  int vdmLBIndex;
  bool refreshLeaderboard;
  bool refreshWhenMasterIsOnline;
  bool moveToCampaign;
  bool isScrolling;
  bool refreshing;
  int scrollDelay;
  bool pausedOnEnter;
  bool isProfileScreenOpenBool;
  idList<idPcDisplayInfo,5> displayResolutions;
  bool onLoadMenu;
  menuSwitchRequest_t menuRequest;
  idStrStatic<2048> chatHistory;
  idList<idDeclRaceDescription const *,5> raceDescriptions;
  idLobbyController *lobbyController;
  idStaticList<idMainMenu::roadRageLeaderboard_t,5> roadRageLeaderboards;
  idList<idMainMenu::coopLeaderboard_t,5> coopLeaderboards;
  bool viewCoopNightmareLeaderboard;
  bool wasViewingMpConfig;
  idList<mpMap_t,57> mpMaps;
  idList<idDeclChapter const *,5> chapters;
  idList<idDeclSecretType const *,5> secretTypes;
  menuArea_t menuArea;
  menuArea_t desiredMenuArea;
  idSession::sessionState_t oldSessionState;
  int showingMigratingTime;
  idMainMenu::idSWFScriptFunction_setState scriptFunction_setState;
  idMainMenu::idSWFScriptFunction_registerUserMouse scriptFunction_registerUserMouse;
  idMainMenu::idSWFScriptFunction_quitGame scriptFunction_quitGame;
  idMainMenu::idSWFScriptFunction_waitForCredits scriptFunction_waitForCredits;
  idMainMenu::idSWFScriptFunction_clearWaitForCredits scriptFunction_clearWaitForCredits;
  idMainMenu::idSWFScriptFunction_updateScrolling scriptFunction_updateScrolling;
  idMainMenu::idSWFScriptFunction_checkCanPlayOnline scriptFunction_checkCanPlayOnline;
  idMainMenu::idSWFScriptFunction_isMpDisc scriptFunction_isMpDisc;
  idMainMenu::idSWFScriptFunction_moveBetweenSPAndMP scriptFunction_moveBetweenSPAndMP;
  idMainMenu::idSWFScriptFunction_setGameDifficulty scriptFunction_setGameDifficulty;
  idMainMenu::idSWFScriptFunction_setNewGameDifficulty scriptFunction_setNewGameDifficulty;
  idMainMenu::idSWFScriptFunction_getGameDifficulty scriptFunction_getGameDifficulty;
  idMainMenu::idSWFScriptFunction_closeMenu scriptFunction_closeMenu;
  idMainMenu::idSWFScriptFunction_setNewGame scriptFunction_setNewGame;
  idMainMenu::idSWFScriptFunction_needsDiskSwap scriptFunction_needsDiskSwap;
  idMainMenu::idSWFScriptFunction_isProfileScreenOpen scriptFunction_isProfileScreenOpen;
  idMainMenu::idSWFScriptFunction_createTeamLobby scriptFunction_createTeamLobby;
  idMainMenu::idSWFScriptFunction_createGameLobby scriptFunction_createGameLobby;
  idMainMenu::idSWFScriptFunction_autoJoinGameLobby scriptFunction_autoJoinGameLobby;
  idMainMenu::idSWFScriptFunction_isInGameLobby scriptFunction_isInGameLobby;
  idMainMenu::idSWFScriptFunction_needSpDiscSwap scriptFunction_needSpDiscSwap;
  idMainMenu::idSWFScriptFunction_setBindingWait scriptFunction_setBindingWait;
  idMainMenu::idSWFScriptFunction_canScroll scriptFunction_canScroll;
  idMainMenu::idSWFScriptFunction_setScrollSpeed scriptFunction_setScrollSpeed;
  idMainMenu::idSWFScriptFunction_startMatch scriptFunction_startMatch;
  idMainMenu::idSWFScriptFunction_startMatchCountdown scriptFunction_startMatchCountdown;
  idMainMenu::idSWFScriptFunction_cancelMatch scriptFunction_cancelMatch;
  idMainMenu::idSWFScriptFunction_cancelMatchCountdown scriptFunction_cancelMatchCountdown;
  idMainMenu::idSWFScriptFunction_joinMatch scriptFunction_joinMatch;
  idMainMenu::idSWFScriptFunction_showServerGamerCardUI scriptFunction_showServerGamerCardUI;
  idMainMenu::idSWFScriptFunction_inviteFriends scriptFunction_inviteFriends;
  idMainMenu::idSWFScriptFunction_showPartySessions scriptFunction_showPartySessions;
  idMainMenu::idSWFScriptFunction_getMatchType scriptFunction_getMatchType;
  idMainMenu::idSWFScriptFunction_setMatchType scriptFunction_setMatchType;
  idMainMenu::idSWFScriptFunction_isPeer scriptFunction_isPeer;
  idMainMenu::idSWFScriptFunction_isPartyPeer scriptFunction_isPartyPeer;
  idMainMenu::idSWFScriptFunction_updateLanServerList scriptFunction_updateLanServerList;
  idMainMenu::idSWFScriptFunction_isLobbyFull scriptFunction_isLobbyFull;
  idMainMenu::idSWFScriptFunction_getChapterList scriptFunction_getChapterList;
  idMainMenu::idSWFScriptFunction_showVoteResults scriptFunction_showVoteResults;
  idMainMenu::idSWFScriptFunction_voteToSkipMap scriptFunction_voteToSkipMap;
  idMainMenu::idSWFScriptFunction_getMapList scriptFunction_getMapList;
  idMainMenu::idSWFScriptFunction_getGameMapAvailable scriptFunction_getGameMapAvailable;
  idMainMenu::idSWFScriptFunction_getMatchMap scriptFunction_getMatchMap;
  idMainMenu::idSWFScriptFunction_setMatchMap scriptFunction_setMatchMap;
  idMainMenu::idSWFScriptFunction_updateMapSelection scriptFunction_updateMapSelection;
  idMainMenu::idSWFScriptFunction_getModeList scriptFunction_getModeList;
  idMainMenu::idSWFScriptFunction_getGameModeAvailable scriptFunction_getGameModeAvailable;
  idMainMenu::idSWFScriptFunction_getMatchMode scriptFunction_getMatchMode;
  idMainMenu::idSWFScriptFunction_setMatchMode scriptFunction_setMatchMode;
  idMainMenu::idSWFScriptFunction_joinQuickMatch scriptFunction_joinQuickMatch;
  idMainMenu::idSWFScriptFunction_setPrivateMatch scriptFunction_setPrivateMatch;
  idMainMenu::idSWFScriptFunction_isPrivateMatch scriptFunction_isPrivateMatch;
  idMainMenu::idSWFScriptFunction_setLocalMatch scriptFunction_setLocalMatch;
  idMainMenu::idSWFScriptFunction_isLocalMatch scriptFunction_isLocalMatch;
  idMainMenu::idSWFScriptFunction_sendChatText scriptFunction_sendChatText;
  idMainMenu::idSWFScriptFunction_togglePlayerMute scriptFunction_togglePlayerMute;
  idMainMenu::idSWFScriptFunction_showGamerCardUI scriptFunction_showGamerCardUI;
  idMainMenu::idSWFScriptFunction_kickPlayer scriptFunction_kickPlayer;
  idMainMenu::idSWFScriptFunction_isInPlatformParty scriptFunction_isInPlatformParty;
  idMainMenu::idSWFScriptFunction_invitePlatformParty scriptFunction_invitePlatformParty;
  idMainMenu::idSWFScriptFunction_loadProfileData scriptFunction_loadProfileData;
  idMainMenu::idSWFScriptFunction_setMenuArea scriptFunction_setMenuArea;
  idMainMenu::idSWFScriptFunction_forceMenuArea scriptFunction_forceMenuArea;
  idMainMenu::idSWFScriptFunction_getPostGameResults scriptFunction_getPostGameResults;
  idMainMenu::idSWFScriptFunction_updateModeSelection scriptFunction_updateModeSelection;
  idMainMenu::idSWFScriptFunction_changeTeam scriptFunction_changeTeam;
  idMainMenu::idSWFScriptFunction_isGameModeTeam scriptFunction_isGameModeTeam;
  idMainMenu::idSWFScriptFunction_showMatchResultsPopup scriptFunction_showMatchResultsPopup;
  idMainMenu::idSWFScriptFunction_showNextUnlockPopup scriptFunction_showNextUnlockPopup;
  idMainMenu::idSWFScriptFunction_showPopupDialog scriptFunction_showPopupDialog;
  idMainMenu::idSWFScriptFunction_closePopup scriptFunction_closePopup;
  idMainMenu::idSWFScriptFunction_loadMap scriptFunction_loadMap;
  idMainMenu::idSWFScriptFunction_getDefaultDevMenuOption scriptFunction_getDefaultDevMenuOption;
  idMainMenu::idSWFScriptFunction_restartMap scriptFunction_restartMap;
  idMainMenu::idSWFScriptFunction_returnToMainMenu scriptFunction_returnToMainMenu;
  idMainMenu::idSWFScriptFunction_confirmExitGame scriptFunction_confirmExitGame;
  idMainMenu::idSWFScriptFunction_restartFromPause scriptFunction_restartFromPause;
  idMainMenu::idSWFScriptFunction_cancelSaveEnumeration scriptFunction_cancelSaveEnumeration;
  idMainMenu::idSWFScriptFunction_GetSaveGame scriptFunction_GetSaveGame;
  idMainMenu::idSWFScriptFunction_CanSaveGame scriptFunction_CanSaveGame;
  idMainMenu::idSWFScriptFunction_SaveGame scriptFunction_SaveGame;
  idMainMenu::idSWFScriptFunction_LoadGame scriptFunction_LoadGame;
  idMainMenu::idSWFScriptFunction_deleteGame scriptFunction_deleteGame;
  idMainMenu::idSWFScriptFunction_select360Storage scriptFunction_select360Storage;
  idMainMenu::idSWFScriptFunction_canContinueGame scriptFunction_canContinueGame;
  idMainMenu::idSWFScriptFunction_canLoadGame scriptFunction_canLoadGame;
  idMainMenu::idSWFScriptFunction_canStartNewGame scriptFunction_canStartNewGame;
  idMainMenu::idSWFScriptFunction_startDeviceSignal scriptFunction_startDeviceSignal;
  idMainMenu::idSWFScriptFunction_endDeviceSignal scriptFunction_endDeviceSignal;
  idMainMenu::idSWFScriptFunction_setSaveLoadUpdate scriptFunction_setSaveLoadUpdate;
  idMainMenu::idSWFScriptFunction_isEnumerating scriptFunction_isEnumerating;
  idMainMenu::idSWFScriptFunction_continueGame scriptFunction_continueGame;
  idMainMenu::idSWFScriptFunction_continueFromMostRecentSave scriptFunction_continueFromMostRecentSave;
  idMainMenu::idSWFScriptFunction_loadDamagedFile scriptFunction_loadDamagedFile;
  idMainMenu::idSWFScriptFunction_isLookInverted scriptFunction_isLookInverted;
  idMainMenu::idSWFScriptFunction_invertLook scriptFunction_invertLook;
  idMainMenu::idSWFScriptFunction_updateSafeFrameScale scriptFunction_updateSafeFrameScale;
  idMainMenu::idSWFScriptFunction_GetSafeFrameScale scriptFunction_GetSafeFrameScale;
  idMainMenu::idSWFScriptFunction_updateGammaValue scriptFunction_updateGammaValue;
  idMainMenu::idSWFScriptFunction_getGammaValue scriptFunction_getGammaValue;
  idMainMenu::idSWFScriptFunction_setInvertLook scriptFunction_setInvertLook;
  idMainMenu::idSWFScriptFunction_subtitlesEnabled scriptFunction_subtitlesEnabled;
  idMainMenu::idSWFScriptFunction_setSubtitlesEnabled scriptFunction_setSubtitlesEnabled;
  idMainMenu::idSWFScriptFunction_calculateBenchmark scriptFunction_calculateBenchmark;
  idMainMenu::idSWFScriptFunction_getBenchmarkValue scriptFunction_getBenchmarkValue;
  idMainMenu::idSWFScriptFunction_getAudioVolume scriptFunction_getAudioVolume;
  idMainMenu::idSWFScriptFunction_setAudioVolume scriptFunction_setAudioVolume;
  idMainMenu::idSWFScriptFunction_updateJoyYawSpeed scriptFunction_updateJoyYawSpeed;
  idMainMenu::idSWFScriptFunction_GetJoyYawSpeed scriptFunction_GetJoyYawSpeed;
  idMainMenu::idSWFScriptFunction_updateJoyPitchSpeed scriptFunction_updateJoyPitchSpeed;
  idMainMenu::idSWFScriptFunction_GetJoyPitchSpeed scriptFunction_GetJoyPitchSpeed;
  idMainMenu::idSWFScriptFunction_getBinding scriptFunction_getBinding;
  idMainMenu::idSWFScriptFunction_confirmRestoreBindings scriptFunction_confirmRestoreBindings;
  idMainMenu::idSWFScriptFunction_getGamepadEnabled scriptFunction_getGamepadEnabled;
  idMainMenu::idSWFScriptFunction_setGamepadEnabled scriptFunction_setGamepadEnabled;
  idMainMenu::idSWFScriptFunction_getUseAimAssist scriptFunction_getUseAimAssist;
  idMainMenu::idSWFScriptFunction_setUseAimAssist scriptFunction_setUseAimAssist;
  idMainMenu::idSWFScriptFunction_setUseVibrate scriptFunction_setUseVibrate;
  idMainMenu::idSWFScriptFunction_getUseVibrate scriptFunction_getUseVibrate;
  idMainMenu::idSWFScriptFunction_setMouseSensitivity scriptFunction_setMouseSensitivity;
  idMainMenu::idSWFScriptFunction_getMouseSensitivity scriptFunction_getMouseSensitivity;
  idMainMenu::idSWFScriptFunction_getConfig scriptFunction_getConfig;
  idMainMenu::idSWFScriptFunction_setConfig scriptFunction_setConfig;
  idMainMenu::idSWFScriptFunction_changeConfig scriptFunction_changeConfig;
  idMainMenu::idSWFScriptFunction_getConfigText scriptFunction_getConfigText;
  idMainMenu::idSWFScriptFunction_hidePauseMenu scriptFunction_hidePauseMenu;
  idMainMenu::idSWFScriptFunction_getCoopDifficulty scriptFunction_getCoopDifficulty;
  idMainMenu::idSWFScriptFunction_setCoopDifficulty scriptFunction_setCoopDifficulty;
  idMainMenu::idSWFScriptFunction_getSessionCoopDifficulty scriptFunction_getSessionCoopDifficulty;
  idMainMenu::idSWFScriptFunction_loadScrollingControlValues scriptFunction_loadScrollingControlValues;
  idMainMenu::idSWFScriptFunction_getTimeLimit scriptFunction_getTimeLimit;
  idMainMenu::idSWFScriptFunction_setTimeLimit scriptFunction_setTimeLimit;
  idMainMenu::idSWFScriptFunction_getScoreLimit scriptFunction_getScoreLimit;
  idMainMenu::idSWFScriptFunction_setScoreLimit scriptFunction_setScoreLimit;
  idMainMenu::idSWFScriptFunction_getCOOPPrivacy scriptFunction_getCOOPPrivacy;
  idMainMenu::idSWFScriptFunction_setCOOPPrivacy scriptFunction_setCOOPPrivacy;
  idMainMenu::idSWFScriptFunction_shouldPrivacyBeVisible scriptFunction_shouldPrivacyBeVisible;
  idMainMenu::idSWFScriptFunction_getAllowFriendlyFire scriptFunction_getAllowFriendlyFire;
  idMainMenu::idSWFScriptFunction_setAllowFriendlyFire scriptFunction_setAllowFriendlyFire;
  idMainMenu::idSWFScriptFunction_getAllowSpectators scriptFunction_getAllowSpectators;
  idMainMenu::idSWFScriptFunction_setAllowSpectators scriptFunction_setAllowSpectators;
  idMainMenu::idSWFScriptFunction_getAllowPowerups scriptFunction_getAllowPowerups;
  idMainMenu::idSWFScriptFunction_setAllowPowerups scriptFunction_setAllowPowerups;
  idMainMenu::idSWFScriptFunction_getAllowQuickUse scriptFunction_getAllowQuickUse;
  idMainMenu::idSWFScriptFunction_setAllowQuickUse scriptFunction_setAllowQuickUse;
  idMainMenu::idSWFScriptFunction_getAllowSponsors scriptFunction_getAllowSponsors;
  idMainMenu::idSWFScriptFunction_setAllowSponsors scriptFunction_setAllowSponsors;
  idMainMenu::idSWFScriptFunction_getAllowBoost scriptFunction_getAllowBoost;
  idMainMenu::idSWFScriptFunction_setAllowBoost scriptFunction_setAllowBoost;
  idMainMenu::idSWFScriptFunction_suicide scriptFunction_suicide;
  idMainMenu::idSWFScriptFunction_getPlayerLevelTitle scriptFunction_getPlayerLevelTitle;
  idMainMenu::idSWFScriptFunction_getAccoladeInfo scriptFunction_getAccoladeInfo;
  idMainMenu::idSWFScriptFunction_getAccoladeCount scriptFunction_getAccoladeCount;
  idMainMenu::idSWFScriptFunction_selectAccolade scriptFunction_selectAccolade;
  idMainMenu::idSWFScriptFunction_drawPlayerInfo scriptFunction_drawPlayerInfo;
  idMainMenu::idSWFScriptFunction_getMissionMapList scriptFunction_getMissionMapList;
  idMainMenu::idSWFScriptFunction_hasNewAccolade scriptFunction_hasNewAccolade;
  idMainMenu::idSWFScriptFunction_loadMenuItems scriptFunction_loadMenuItems;
  idMainMenu::idSWFScriptFunction_saveSettings scriptFunction_saveSettings;
  idMainMenu::idSWFScriptFunction_clearLeaderboard scriptFunction_clearLeaderboard;
  idMainMenu::idSWFScriptFunction_refreshLeaderboard scriptFunction_refreshLeaderboard;
  idMainMenu::idSWFScriptFunction_scrollLeaderboard scriptFunction_scrollLeaderboard;
  idMainMenu::idSWFScriptFunction_nextLeaderboard scriptFunction_nextLeaderboard;
  idMainMenu::idSWFScriptFunction_prevLeaderboard scriptFunction_prevLeaderboard;
  idMainMenu::idSWFScriptFunction_selectLeaderboardIndex scriptFunction_selectLeaderboardIndex;
  idMainMenu::idSWFScriptFunction_showLeaderboardGamerCardUI scriptFunction_showLeaderboardGamerCardUI;
  idMainMenu::idSWFScriptFunction_toggleCoopNightmareLeaderboard scriptFunction_toggleCoopNightmareLeaderboard;
  idMainMenu::idSWFScriptFunction_isCoopNightmareLeaderboard scriptFunction_isCoopNightmareLeaderboard;
  idMainMenu::idSWFScriptFunction_filterList scriptFunction_filterList;
  idMainMenu::idSWFScriptFunction_setScrolling scriptFunction_setScrolling;
  idMainMenu::idSWFScriptFunction_updateScroll scriptFunction_updateScroll;
  idMainMenu::idSWFScriptFunction_updateLbScroll scriptFunction_updateLbScroll;
  idMainMenu::idSWFScriptFunction_stopPlaytestRenderDemoRecord scriptFunction_stopPlaytestRenderDemoRecord;
  idMainMenu::idSWFScriptFunction_setPlaytestSessionName scriptFunction_setPlaytestSessionName;
  idMainMenu::idSWFScriptFunction_checkActivatePlaytestLogging scriptFunction_checkActivatePlaytestLogging;
  idMainMenu::idSWFScriptFunction_checkActivateRenderDemo scriptFunction_checkActivateRenderDemo;
  idMainMenu::idSWFScriptFunction_loadDevMenuOption scriptFunction_loadDevMenuOption;
  idMainMenu::idSWFScriptFunction_isDemoMode scriptFunction_isDemoMode;
  idMainMenu::idSWFScriptFunction_showDLCOption scriptFunction_showDLCOption;
  idMainMenu::idSWFScriptFunction_hasNewDLC scriptFunction_hasNewDLC;
  idMainMenu::idSWFScriptFunction_showDLCMenu scriptFunction_showDLCMenu;
  idMainMenu::idSWFScriptFunction_isGameInstalled scriptFunction_isGameInstalled;
  idMainMenu::idSWFScriptFunction_showCredits scriptFunction_showCredits;
  idMainMenu::idSWFScriptFunction_ps3ShowFriends scriptFunction_ps3ShowFriends;
  idMainMenu::idSWFScriptFunction_ps3ShowNotifications scriptFunction_ps3ShowNotifications;
  idMainMenu::idSWFScriptFunction_ps3CheckInvites scriptFunction_ps3CheckInvites;
  idMainMenu::idSWFScriptFunction_hasContentPack scriptFunction_hasContentPack;
  idMainMenu::idSWFScriptFunction_isMpHandsOnDemo scriptFunction_isMpHandsOnDemo;
};

// IDA Local Type ordinal 16071; PDB kind: struct.
struct idMainMenu::roadRageLeaderboard_t
{
  const leaderboardDefinition_t *lb;
  idStrId name;
};

// IDA Local Type ordinal 16074; PDB kind: struct.
struct idMainMenu::coopLeaderboard_t
{
  idStrId name;
  int leaderboardId;
  int nightmareLeaderboardId;
};

// IDA Local Type ordinal 16094; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setState : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16095.
  virtual ~idSWFScriptFunction_setState();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16096; PDB kind: class.
class idMainMenu::idSWFScriptFunction_registerUserMouse : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16097.
  virtual ~idSWFScriptFunction_registerUserMouse();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16098; PDB kind: class.
class idMainMenu::idSWFScriptFunction_quitGame : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16099.
  virtual ~idSWFScriptFunction_quitGame();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16100; PDB kind: class.
class idMainMenu::idSWFScriptFunction_waitForCredits : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16101.
  virtual ~idSWFScriptFunction_waitForCredits();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16102; PDB kind: class.
class idMainMenu::idSWFScriptFunction_clearWaitForCredits : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16103.
  virtual ~idSWFScriptFunction_clearWaitForCredits();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16104; PDB kind: class.
class idMainMenu::idSWFScriptFunction_updateScrolling : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16105.
  virtual ~idSWFScriptFunction_updateScrolling();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16106; PDB kind: class.
class idMainMenu::idSWFScriptFunction_checkCanPlayOnline : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16107.
  virtual ~idSWFScriptFunction_checkCanPlayOnline();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16108; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isMpDisc : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16109.
  virtual ~idSWFScriptFunction_isMpDisc();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16110; PDB kind: class.
class idMainMenu::idSWFScriptFunction_moveBetweenSPAndMP : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16111.
  virtual ~idSWFScriptFunction_moveBetweenSPAndMP();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16112; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setGameDifficulty : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16113.
  virtual ~idSWFScriptFunction_setGameDifficulty();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16114; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setNewGameDifficulty : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16115.
  virtual ~idSWFScriptFunction_setNewGameDifficulty();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16116; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getGameDifficulty : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16117.
  virtual ~idSWFScriptFunction_getGameDifficulty();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16118; PDB kind: class.
class idMainMenu::idSWFScriptFunction_closeMenu : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16119.
  virtual ~idSWFScriptFunction_closeMenu();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16120; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setNewGame : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16121.
  virtual ~idSWFScriptFunction_setNewGame();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16122; PDB kind: class.
class idMainMenu::idSWFScriptFunction_needsDiskSwap : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16123.
  virtual ~idSWFScriptFunction_needsDiskSwap();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16124; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isProfileScreenOpen : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16125.
  virtual ~idSWFScriptFunction_isProfileScreenOpen();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16126; PDB kind: class.
class idMainMenu::idSWFScriptFunction_createTeamLobby : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16127.
  virtual ~idSWFScriptFunction_createTeamLobby();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16128; PDB kind: class.
class idMainMenu::idSWFScriptFunction_createGameLobby : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16129.
  virtual ~idSWFScriptFunction_createGameLobby();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16130; PDB kind: class.
class idMainMenu::idSWFScriptFunction_autoJoinGameLobby : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16131.
  virtual ~idSWFScriptFunction_autoJoinGameLobby();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16132; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isInGameLobby : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16133.
  virtual ~idSWFScriptFunction_isInGameLobby();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16134; PDB kind: class.
class idMainMenu::idSWFScriptFunction_needSpDiscSwap : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16135.
  virtual ~idSWFScriptFunction_needSpDiscSwap();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16136; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setBindingWait : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16137.
  virtual ~idSWFScriptFunction_setBindingWait();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16138; PDB kind: class.
class idMainMenu::idSWFScriptFunction_canScroll : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16139.
  virtual ~idSWFScriptFunction_canScroll();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16140; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setScrollSpeed : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16141.
  virtual ~idSWFScriptFunction_setScrollSpeed();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16142; PDB kind: class.
class idMainMenu::idSWFScriptFunction_startMatch : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16143.
  virtual ~idSWFScriptFunction_startMatch();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16144; PDB kind: class.
class idMainMenu::idSWFScriptFunction_startMatchCountdown : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16145.
  virtual ~idSWFScriptFunction_startMatchCountdown();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16146; PDB kind: class.
class idMainMenu::idSWFScriptFunction_cancelMatch : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16147.
  virtual ~idSWFScriptFunction_cancelMatch();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16148; PDB kind: class.
class idMainMenu::idSWFScriptFunction_cancelMatchCountdown : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16149.
  virtual ~idSWFScriptFunction_cancelMatchCountdown();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16150; PDB kind: class.
class idMainMenu::idSWFScriptFunction_joinMatch : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16151.
  virtual ~idSWFScriptFunction_joinMatch();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16152; PDB kind: class.
class idMainMenu::idSWFScriptFunction_showServerGamerCardUI : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16153.
  virtual ~idSWFScriptFunction_showServerGamerCardUI();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16154; PDB kind: class.
class idMainMenu::idSWFScriptFunction_inviteFriends : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16155.
  virtual ~idSWFScriptFunction_inviteFriends();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16156; PDB kind: class.
class idMainMenu::idSWFScriptFunction_showPartySessions : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16157.
  virtual ~idSWFScriptFunction_showPartySessions();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16158; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getMatchType : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16159.
  virtual ~idSWFScriptFunction_getMatchType();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16160; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setMatchType : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16161.
  virtual ~idSWFScriptFunction_setMatchType();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16162; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isPeer : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16163.
  virtual ~idSWFScriptFunction_isPeer();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16164; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isPartyPeer : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16165.
  virtual ~idSWFScriptFunction_isPartyPeer();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16166; PDB kind: class.
class idMainMenu::idSWFScriptFunction_updateLanServerList : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16167.
  virtual ~idSWFScriptFunction_updateLanServerList();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16168; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isLobbyFull : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16169.
  virtual ~idSWFScriptFunction_isLobbyFull();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16170; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getChapterList : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16171.
  virtual ~idSWFScriptFunction_getChapterList();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16172; PDB kind: class.
class idMainMenu::idSWFScriptFunction_showVoteResults : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16173.
  virtual ~idSWFScriptFunction_showVoteResults();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16174; PDB kind: class.
class idMainMenu::idSWFScriptFunction_voteToSkipMap : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16175.
  virtual ~idSWFScriptFunction_voteToSkipMap();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16176; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getMapList : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16177.
  virtual ~idSWFScriptFunction_getMapList();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16178; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getGameMapAvailable : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16179.
  virtual ~idSWFScriptFunction_getGameMapAvailable();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16180; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getMatchMap : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16181.
  virtual ~idSWFScriptFunction_getMatchMap();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16182; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setMatchMap : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16183.
  virtual ~idSWFScriptFunction_setMatchMap();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16184; PDB kind: class.
class idMainMenu::idSWFScriptFunction_updateMapSelection : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16185.
  virtual ~idSWFScriptFunction_updateMapSelection();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16186; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getModeList : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16187.
  virtual ~idSWFScriptFunction_getModeList();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16188; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getGameModeAvailable : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16189.
  virtual ~idSWFScriptFunction_getGameModeAvailable();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16190; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getMatchMode : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16191.
  virtual ~idSWFScriptFunction_getMatchMode();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16192; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setMatchMode : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16193.
  virtual ~idSWFScriptFunction_setMatchMode();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16194; PDB kind: class.
class idMainMenu::idSWFScriptFunction_joinQuickMatch : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16195.
  virtual ~idSWFScriptFunction_joinQuickMatch();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16196; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setPrivateMatch : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16197.
  virtual ~idSWFScriptFunction_setPrivateMatch();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16198; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isPrivateMatch : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16199.
  virtual ~idSWFScriptFunction_isPrivateMatch();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16200; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setLocalMatch : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16201.
  virtual ~idSWFScriptFunction_setLocalMatch();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16202; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isLocalMatch : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16203.
  virtual ~idSWFScriptFunction_isLocalMatch();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16204; PDB kind: class.
class idMainMenu::idSWFScriptFunction_sendChatText : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16205.
  virtual ~idSWFScriptFunction_sendChatText();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16206; PDB kind: class.
class idMainMenu::idSWFScriptFunction_togglePlayerMute : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16207.
  virtual ~idSWFScriptFunction_togglePlayerMute();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16208; PDB kind: class.
class idMainMenu::idSWFScriptFunction_showGamerCardUI : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16209.
  virtual ~idSWFScriptFunction_showGamerCardUI();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16210; PDB kind: class.
class idMainMenu::idSWFScriptFunction_kickPlayer : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16211.
  virtual ~idSWFScriptFunction_kickPlayer();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16212; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isInPlatformParty : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16213.
  virtual ~idSWFScriptFunction_isInPlatformParty();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16214; PDB kind: class.
class idMainMenu::idSWFScriptFunction_invitePlatformParty : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16215.
  virtual ~idSWFScriptFunction_invitePlatformParty();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16216; PDB kind: class.
class idMainMenu::idSWFScriptFunction_loadProfileData : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16217.
  virtual ~idSWFScriptFunction_loadProfileData();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16218; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setMenuArea : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16219.
  virtual ~idSWFScriptFunction_setMenuArea();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16220; PDB kind: class.
class idMainMenu::idSWFScriptFunction_forceMenuArea : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16221.
  virtual ~idSWFScriptFunction_forceMenuArea();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16222; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getPostGameResults : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16223.
  virtual ~idSWFScriptFunction_getPostGameResults();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16224; PDB kind: class.
class idMainMenu::idSWFScriptFunction_updateModeSelection : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16225.
  virtual ~idSWFScriptFunction_updateModeSelection();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16226; PDB kind: class.
class idMainMenu::idSWFScriptFunction_changeTeam : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16227.
  virtual ~idSWFScriptFunction_changeTeam();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16228; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isGameModeTeam : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16229.
  virtual ~idSWFScriptFunction_isGameModeTeam();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16230; PDB kind: class.
class idMainMenu::idSWFScriptFunction_showMatchResultsPopup : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16231.
  virtual ~idSWFScriptFunction_showMatchResultsPopup();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16232; PDB kind: class.
class idMainMenu::idSWFScriptFunction_showNextUnlockPopup : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16233.
  virtual ~idSWFScriptFunction_showNextUnlockPopup();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16234; PDB kind: class.
class idMainMenu::idSWFScriptFunction_showPopupDialog : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16235.
  virtual ~idSWFScriptFunction_showPopupDialog();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16236; PDB kind: class.
class idMainMenu::idSWFScriptFunction_closePopup : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16237.
  virtual ~idSWFScriptFunction_closePopup();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16238; PDB kind: class.
class idMainMenu::idSWFScriptFunction_loadMap : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16239.
  virtual ~idSWFScriptFunction_loadMap();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16240; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getDefaultDevMenuOption : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16241.
  virtual ~idSWFScriptFunction_getDefaultDevMenuOption();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16242; PDB kind: class.
class idMainMenu::idSWFScriptFunction_restartMap : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16243.
  virtual ~idSWFScriptFunction_restartMap();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16244; PDB kind: class.
class idMainMenu::idSWFScriptFunction_returnToMainMenu : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16245.
  virtual ~idSWFScriptFunction_returnToMainMenu();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16246; PDB kind: class.
class idMainMenu::idSWFScriptFunction_confirmExitGame : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16247.
  virtual ~idSWFScriptFunction_confirmExitGame();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16248; PDB kind: class.
class idMainMenu::idSWFScriptFunction_restartFromPause : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16249.
  virtual ~idSWFScriptFunction_restartFromPause();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16250; PDB kind: class.
class idMainMenu::idSWFScriptFunction_cancelSaveEnumeration : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16251.
  virtual ~idSWFScriptFunction_cancelSaveEnumeration();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16252; PDB kind: class.
class idMainMenu::idSWFScriptFunction_GetSaveGame : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16253.
  virtual ~idSWFScriptFunction_GetSaveGame();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16254; PDB kind: class.
class idMainMenu::idSWFScriptFunction_CanSaveGame : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16255.
  virtual ~idSWFScriptFunction_CanSaveGame();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16256; PDB kind: class.
class idMainMenu::idSWFScriptFunction_SaveGame : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16257.
  virtual ~idSWFScriptFunction_SaveGame();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16258; PDB kind: class.
class idMainMenu::idSWFScriptFunction_LoadGame : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16259.
  virtual ~idSWFScriptFunction_LoadGame();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16260; PDB kind: class.
class idMainMenu::idSWFScriptFunction_deleteGame : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16261.
  virtual ~idSWFScriptFunction_deleteGame();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16262; PDB kind: class.
class idMainMenu::idSWFScriptFunction_select360Storage : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16263.
  virtual ~idSWFScriptFunction_select360Storage();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16264; PDB kind: class.
class idMainMenu::idSWFScriptFunction_canContinueGame : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16265.
  virtual ~idSWFScriptFunction_canContinueGame();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16266; PDB kind: class.
class idMainMenu::idSWFScriptFunction_canLoadGame : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16267.
  virtual ~idSWFScriptFunction_canLoadGame();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16268; PDB kind: class.
class idMainMenu::idSWFScriptFunction_canStartNewGame : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16269.
  virtual ~idSWFScriptFunction_canStartNewGame();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16270; PDB kind: class.
class idMainMenu::idSWFScriptFunction_startDeviceSignal : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16271.
  virtual ~idSWFScriptFunction_startDeviceSignal();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16272; PDB kind: class.
class idMainMenu::idSWFScriptFunction_endDeviceSignal : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16273.
  virtual ~idSWFScriptFunction_endDeviceSignal();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16274; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setSaveLoadUpdate : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16275.
  virtual ~idSWFScriptFunction_setSaveLoadUpdate();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16276; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isEnumerating : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16277.
  virtual ~idSWFScriptFunction_isEnumerating();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16278; PDB kind: class.
class idMainMenu::idSWFScriptFunction_continueGame : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16279.
  virtual ~idSWFScriptFunction_continueGame();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16280; PDB kind: class.
class idMainMenu::idSWFScriptFunction_continueFromMostRecentSave : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16281.
  virtual ~idSWFScriptFunction_continueFromMostRecentSave();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16282; PDB kind: class.
class idMainMenu::idSWFScriptFunction_loadDamagedFile : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16283.
  virtual ~idSWFScriptFunction_loadDamagedFile();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16284; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isLookInverted : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16285.
  virtual ~idSWFScriptFunction_isLookInverted();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16286; PDB kind: class.
class idMainMenu::idSWFScriptFunction_invertLook : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16287.
  virtual ~idSWFScriptFunction_invertLook();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16288; PDB kind: class.
class idMainMenu::idSWFScriptFunction_updateSafeFrameScale : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16289.
  virtual ~idSWFScriptFunction_updateSafeFrameScale();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16290; PDB kind: class.
class idMainMenu::idSWFScriptFunction_GetSafeFrameScale : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16291.
  virtual ~idSWFScriptFunction_GetSafeFrameScale();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16292; PDB kind: class.
class idMainMenu::idSWFScriptFunction_updateGammaValue : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16293.
  virtual ~idSWFScriptFunction_updateGammaValue();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16294; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getGammaValue : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16295.
  virtual ~idSWFScriptFunction_getGammaValue();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16296; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setInvertLook : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16297.
  virtual ~idSWFScriptFunction_setInvertLook();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16298; PDB kind: class.
class idMainMenu::idSWFScriptFunction_subtitlesEnabled : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16299.
  virtual ~idSWFScriptFunction_subtitlesEnabled();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16300; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setSubtitlesEnabled : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16301.
  virtual ~idSWFScriptFunction_setSubtitlesEnabled();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16302; PDB kind: class.
class idMainMenu::idSWFScriptFunction_calculateBenchmark : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16303.
  virtual ~idSWFScriptFunction_calculateBenchmark();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16304; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getBenchmarkValue : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16305.
  virtual ~idSWFScriptFunction_getBenchmarkValue();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16306; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getAudioVolume : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16307.
  virtual ~idSWFScriptFunction_getAudioVolume();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16308; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setAudioVolume : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16309.
  virtual ~idSWFScriptFunction_setAudioVolume();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16310; PDB kind: class.
class idMainMenu::idSWFScriptFunction_updateJoyYawSpeed : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16311.
  virtual ~idSWFScriptFunction_updateJoyYawSpeed();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16312; PDB kind: class.
class idMainMenu::idSWFScriptFunction_GetJoyYawSpeed : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16313.
  virtual ~idSWFScriptFunction_GetJoyYawSpeed();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16314; PDB kind: class.
class idMainMenu::idSWFScriptFunction_updateJoyPitchSpeed : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16315.
  virtual ~idSWFScriptFunction_updateJoyPitchSpeed();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16316; PDB kind: class.
class idMainMenu::idSWFScriptFunction_GetJoyPitchSpeed : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16317.
  virtual ~idSWFScriptFunction_GetJoyPitchSpeed();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16318; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getBinding : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16319.
  virtual ~idSWFScriptFunction_getBinding();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16320; PDB kind: class.
class idMainMenu::idSWFScriptFunction_confirmRestoreBindings : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16321.
  virtual ~idSWFScriptFunction_confirmRestoreBindings();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16322; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getGamepadEnabled : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16323.
  virtual ~idSWFScriptFunction_getGamepadEnabled();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16324; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setGamepadEnabled : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16325.
  virtual ~idSWFScriptFunction_setGamepadEnabled();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16326; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getUseAimAssist : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16327.
  virtual ~idSWFScriptFunction_getUseAimAssist();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16328; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setUseAimAssist : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16329.
  virtual ~idSWFScriptFunction_setUseAimAssist();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16330; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setUseVibrate : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16331.
  virtual ~idSWFScriptFunction_setUseVibrate();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16332; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getUseVibrate : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16333.
  virtual ~idSWFScriptFunction_getUseVibrate();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16334; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setMouseSensitivity : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16335.
  virtual ~idSWFScriptFunction_setMouseSensitivity();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16336; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getMouseSensitivity : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16337.
  virtual ~idSWFScriptFunction_getMouseSensitivity();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16338; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getConfig : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16339.
  virtual ~idSWFScriptFunction_getConfig();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16340; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setConfig : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16341.
  virtual ~idSWFScriptFunction_setConfig();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16342; PDB kind: class.
class idMainMenu::idSWFScriptFunction_changeConfig : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16343.
  virtual ~idSWFScriptFunction_changeConfig();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16344; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getConfigText : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16345.
  virtual ~idSWFScriptFunction_getConfigText();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16346; PDB kind: class.
class idMainMenu::idSWFScriptFunction_hidePauseMenu : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16347.
  virtual ~idSWFScriptFunction_hidePauseMenu();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16348; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getCoopDifficulty : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16349.
  virtual ~idSWFScriptFunction_getCoopDifficulty();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16350; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setCoopDifficulty : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16351.
  virtual ~idSWFScriptFunction_setCoopDifficulty();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16352; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getSessionCoopDifficulty : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16353.
  virtual ~idSWFScriptFunction_getSessionCoopDifficulty();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16354; PDB kind: class.
class idMainMenu::idSWFScriptFunction_loadScrollingControlValues : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16355.
  virtual ~idSWFScriptFunction_loadScrollingControlValues();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16356; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getTimeLimit : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16357.
  virtual ~idSWFScriptFunction_getTimeLimit();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16358; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setTimeLimit : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16359.
  virtual ~idSWFScriptFunction_setTimeLimit();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16360; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getScoreLimit : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16361.
  virtual ~idSWFScriptFunction_getScoreLimit();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16362; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setScoreLimit : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16363.
  virtual ~idSWFScriptFunction_setScoreLimit();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16364; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getCOOPPrivacy : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16365.
  virtual ~idSWFScriptFunction_getCOOPPrivacy();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16366; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setCOOPPrivacy : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16367.
  virtual ~idSWFScriptFunction_setCOOPPrivacy();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16368; PDB kind: class.
class idMainMenu::idSWFScriptFunction_shouldPrivacyBeVisible : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16369.
  virtual ~idSWFScriptFunction_shouldPrivacyBeVisible();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16370; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getAllowFriendlyFire : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16371.
  virtual ~idSWFScriptFunction_getAllowFriendlyFire();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16372; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setAllowFriendlyFire : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16373.
  virtual ~idSWFScriptFunction_setAllowFriendlyFire();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16374; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getAllowSpectators : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16375.
  virtual ~idSWFScriptFunction_getAllowSpectators();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16376; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setAllowSpectators : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16377.
  virtual ~idSWFScriptFunction_setAllowSpectators();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16378; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getAllowPowerups : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16379.
  virtual ~idSWFScriptFunction_getAllowPowerups();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16380; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setAllowPowerups : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16381.
  virtual ~idSWFScriptFunction_setAllowPowerups();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16382; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getAllowQuickUse : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16383.
  virtual ~idSWFScriptFunction_getAllowQuickUse();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16384; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setAllowQuickUse : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16385.
  virtual ~idSWFScriptFunction_setAllowQuickUse();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16386; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getAllowSponsors : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16387.
  virtual ~idSWFScriptFunction_getAllowSponsors();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16388; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setAllowSponsors : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16389.
  virtual ~idSWFScriptFunction_setAllowSponsors();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16390; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getAllowBoost : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16391.
  virtual ~idSWFScriptFunction_getAllowBoost();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16392; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setAllowBoost : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16393.
  virtual ~idSWFScriptFunction_setAllowBoost();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16394; PDB kind: class.
class idMainMenu::idSWFScriptFunction_suicide : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16395.
  virtual ~idSWFScriptFunction_suicide();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16396; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getPlayerLevelTitle : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16397.
  virtual ~idSWFScriptFunction_getPlayerLevelTitle();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16398; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getAccoladeInfo : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16399.
  virtual ~idSWFScriptFunction_getAccoladeInfo();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16400; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getAccoladeCount : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16401.
  virtual ~idSWFScriptFunction_getAccoladeCount();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16402; PDB kind: class.
class idMainMenu::idSWFScriptFunction_selectAccolade : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16403.
  virtual ~idSWFScriptFunction_selectAccolade();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16404; PDB kind: class.
class idMainMenu::idSWFScriptFunction_drawPlayerInfo : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16405.
  virtual ~idSWFScriptFunction_drawPlayerInfo();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16406; PDB kind: class.
class idMainMenu::idSWFScriptFunction_getMissionMapList : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16407.
  virtual ~idSWFScriptFunction_getMissionMapList();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16408; PDB kind: class.
class idMainMenu::idSWFScriptFunction_hasNewAccolade : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16409.
  virtual ~idSWFScriptFunction_hasNewAccolade();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16410; PDB kind: class.
class idMainMenu::idSWFScriptFunction_loadMenuItems : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16411.
  virtual ~idSWFScriptFunction_loadMenuItems();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16412; PDB kind: class.
class idMainMenu::idSWFScriptFunction_saveSettings : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16413.
  virtual ~idSWFScriptFunction_saveSettings();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16414; PDB kind: class.
class idMainMenu::idSWFScriptFunction_clearLeaderboard : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16415.
  virtual ~idSWFScriptFunction_clearLeaderboard();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16416; PDB kind: class.
class idMainMenu::idSWFScriptFunction_refreshLeaderboard : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16417.
  virtual ~idSWFScriptFunction_refreshLeaderboard();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16418; PDB kind: class.
class idMainMenu::idSWFScriptFunction_scrollLeaderboard : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16419.
  virtual ~idSWFScriptFunction_scrollLeaderboard();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16420; PDB kind: class.
class idMainMenu::idSWFScriptFunction_nextLeaderboard : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16421.
  virtual ~idSWFScriptFunction_nextLeaderboard();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16422; PDB kind: class.
class idMainMenu::idSWFScriptFunction_prevLeaderboard : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16423.
  virtual ~idSWFScriptFunction_prevLeaderboard();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16424; PDB kind: class.
class idMainMenu::idSWFScriptFunction_selectLeaderboardIndex : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16425.
  virtual ~idSWFScriptFunction_selectLeaderboardIndex();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16426; PDB kind: class.
class idMainMenu::idSWFScriptFunction_showLeaderboardGamerCardUI : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16427.
  virtual ~idSWFScriptFunction_showLeaderboardGamerCardUI();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16428; PDB kind: class.
class idMainMenu::idSWFScriptFunction_toggleCoopNightmareLeaderboard : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16429.
  virtual ~idSWFScriptFunction_toggleCoopNightmareLeaderboard();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16430; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isCoopNightmareLeaderboard : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16431.
  virtual ~idSWFScriptFunction_isCoopNightmareLeaderboard();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16432; PDB kind: class.
class idMainMenu::idSWFScriptFunction_filterList : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16433.
  virtual ~idSWFScriptFunction_filterList();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16434; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setScrolling : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16435.
  virtual ~idSWFScriptFunction_setScrolling();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16436; PDB kind: class.
class idMainMenu::idSWFScriptFunction_updateScroll : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16437.
  virtual ~idSWFScriptFunction_updateScroll();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16438; PDB kind: class.
class idMainMenu::idSWFScriptFunction_updateLbScroll : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16439.
  virtual ~idSWFScriptFunction_updateLbScroll();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16440; PDB kind: class.
class idMainMenu::idSWFScriptFunction_stopPlaytestRenderDemoRecord : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16441.
  virtual ~idSWFScriptFunction_stopPlaytestRenderDemoRecord();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16442; PDB kind: class.
class idMainMenu::idSWFScriptFunction_setPlaytestSessionName : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16443.
  virtual ~idSWFScriptFunction_setPlaytestSessionName();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16444; PDB kind: class.
class idMainMenu::idSWFScriptFunction_checkActivatePlaytestLogging : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16445.
  virtual ~idSWFScriptFunction_checkActivatePlaytestLogging();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16446; PDB kind: class.
class idMainMenu::idSWFScriptFunction_checkActivateRenderDemo : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16447.
  virtual ~idSWFScriptFunction_checkActivateRenderDemo();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16448; PDB kind: class.
class idMainMenu::idSWFScriptFunction_loadDevMenuOption : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16449.
  virtual ~idSWFScriptFunction_loadDevMenuOption();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16450; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isDemoMode : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16451.
  virtual ~idSWFScriptFunction_isDemoMode();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16452; PDB kind: class.
class idMainMenu::idSWFScriptFunction_showDLCOption : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16453.
  virtual ~idSWFScriptFunction_showDLCOption();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16454; PDB kind: class.
class idMainMenu::idSWFScriptFunction_hasNewDLC : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16455.
  virtual ~idSWFScriptFunction_hasNewDLC();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16456; PDB kind: class.
class idMainMenu::idSWFScriptFunction_showDLCMenu : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16457.
  virtual ~idSWFScriptFunction_showDLCMenu();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16458; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isGameInstalled : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16459.
  virtual ~idSWFScriptFunction_isGameInstalled();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16460; PDB kind: class.
class idMainMenu::idSWFScriptFunction_showCredits : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16461.
  virtual ~idSWFScriptFunction_showCredits();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16462; PDB kind: class.
class idMainMenu::idSWFScriptFunction_ps3ShowFriends : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16463.
  virtual ~idSWFScriptFunction_ps3ShowFriends();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16464; PDB kind: class.
class idMainMenu::idSWFScriptFunction_ps3ShowNotifications : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16465.
  virtual ~idSWFScriptFunction_ps3ShowNotifications();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16466; PDB kind: class.
class idMainMenu::idSWFScriptFunction_ps3CheckInvites : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16467.
  virtual ~idSWFScriptFunction_ps3CheckInvites();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16468; PDB kind: class.
class idMainMenu::idSWFScriptFunction_hasContentPack : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16469.
  virtual ~idSWFScriptFunction_hasContentPack();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 16470; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isMpHandsOnDemo : public idSWFScriptFunction_Nested<idMainMenu>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16471.
  virtual ~idSWFScriptFunction_isMpHandsOnDemo();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18371; PDB kind: class.
class idMainMenu::UpdateMenu_Settings::__l21::idSWFScriptFunction_accept : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18372.
  virtual ~idSWFScriptFunction_accept();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  idMainMenu *menu;
  int listing;
};

// IDA Local Type ordinal 18373; PDB kind: class.
class idMainMenu::UpdateMenu_Root::__l21::idSWFScriptFunction_accept : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18374.
  virtual ~idSWFScriptFunction_accept();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  idMainMenu *menu;
  int listing;
};

// IDA Local Type ordinal 18375; PDB kind: class.
class idMainMenu::HandleMenu_Root::__l26::idSWFScriptFunction_DeclineQuit : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18376.
  virtual ~idSWFScriptFunction_DeclineQuit();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
};

// IDA Local Type ordinal 18377; PDB kind: class.
class idMainMenu::HandleMenu_Root::__l25::idSWFScriptFunction_AcceptQuit : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18378.
  virtual ~idSWFScriptFunction_AcceptQuit();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18451; PDB kind: class.
class idMainMenu::SetupMPMenuBindings::__l12::idSWFScriptFunction_ShowPauseGamerCardUI : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18452.
  virtual ~idSWFScriptFunction_ShowPauseGamerCardUI();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18453; PDB kind: class.
class idMainMenu::idSWFScriptFunction_startMatch::Call::__l2::idSWFScriptFunction_Accept : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18454.
  virtual ~idSWFScriptFunction_Accept();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  gameDialogMessages_t msg;
};

// IDA Local Type ordinal 18455; PDB kind: class.
class idMainMenu::idSWFScriptFunction_startMatch::Call::__l3::idSWFScriptFunction_Cancel : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18456.
  virtual ~idSWFScriptFunction_Cancel();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  gameDialogMessages_t msg;
};

// IDA Local Type ordinal 18457; PDB kind: class.
class idMainMenu::idSWFScriptFunction_inviteFriends::Call::__l5::idSWFScriptFunction_Accept : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18458.
  virtual ~idSWFScriptFunction_Accept();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18459; PDB kind: class.
class idMainMenu::idSWFScriptFunction_invitePlatformParty::Call::__l8::idSWFScriptFunction_Accept : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18460.
  virtual ~idSWFScriptFunction_Accept();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18461; PDB kind: class.
class idMainMenu::ShowLeaveLobbyDialog::__l2::idSWFScriptFunction_LeaveWithParty : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18462.
  virtual ~idSWFScriptFunction_LeaveWithParty();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
};

// IDA Local Type ordinal 18463; PDB kind: class.
class idMainMenu::ShowLeaveLobbyDialog::__l3::idSWFScriptFunction_LeaveWithoutParty : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18464.
  virtual ~idSWFScriptFunction_LeaveWithoutParty();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
};

// IDA Local Type ordinal 18465; PDB kind: class.
class idMainMenu::ShowLeaveLobbyDialog::__l4::idSWFScriptFunction_LeaveCancel : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18466.
  virtual ~idSWFScriptFunction_LeaveCancel();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
};

// IDA Local Type ordinal 18467; PDB kind: class.
class idMainMenu::ShowLeaveLobbyDialog::__l5::idSWFScriptFunction_LeaveLobbyYes : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18468.
  virtual ~idSWFScriptFunction_LeaveLobbyYes();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
  gameDialogMessages_t msg;
};

// IDA Local Type ordinal 18469; PDB kind: class.
class idMainMenu::ShowLeaveLobbyDialog::__l6::idSWFScriptFunction_LeaveLobbyNo : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18470.
  virtual ~idSWFScriptFunction_LeaveLobbyNo();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
  gameDialogMessages_t msg;
};

// IDA Local Type ordinal 18471; PDB kind: class.
class idMainMenu::UpdateMenu_Dev::__l24::idSWFScriptFunction_accept : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18472.
  virtual ~idSWFScriptFunction_accept();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  idMainMenu *menu;
  int listing;
};

// IDA Local Type ordinal 18473; PDB kind: class.
class idMainMenu::UpdateMenu_Audio::__l18::idSWFScriptFunction_accept : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18474.
  virtual ~idSWFScriptFunction_accept();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  idMainMenu *menu;
  int listing;
};

// IDA Local Type ordinal 18475; PDB kind: class.
class idMainMenu::UpdateAdjustmentCmds::__l25::idSWFScriptFunction_adjustSetting : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18476.
  virtual ~idSWFScriptFunction_adjustSetting();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
  bool less;
  int speed;
};

// IDA Local Type ordinal 18477; PDB kind: class.
class idMainMenu::UpdateAdjustmentCmds::__l26::idSWFScriptFunction_release : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18478.
  virtual ~idSWFScriptFunction_release();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  idMainMenu *menu;
};

// IDA Local Type ordinal 18545; PDB kind: class.
class idMainMenu::SetupBindings::__l7::idSWFScriptFunction_GetKeyBindings : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18546.
  virtual ~idSWFScriptFunction_GetKeyBindings();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWFScriptObject *binding;
};

// IDA Local Type ordinal 18547; PDB kind: class.
class idMainMenu::SetupBindings::__l8::idSWFScriptFunction_updateMenuDisplay : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18548.
  virtual ~idSWFScriptFunction_updateMenuDisplay();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  idMainMenu *menu;
};

// IDA Local Type ordinal 18549; PDB kind: class.
class idMainMenu::SetupBindings::__l9::idSWFScriptFunction_updateMenuCmds : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18550.
  virtual ~idSWFScriptFunction_updateMenuCmds();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  idMainMenu *menu;
};

// IDA Local Type ordinal 18551; PDB kind: class.
class idMainMenu::ShowOverwriteSavingDialog::__l6::idSWFScriptFunction_AcceptOverwrite : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18552.
  virtual ~idSWFScriptFunction_AcceptOverwrite();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
  int index;
};

// IDA Local Type ordinal 18553; PDB kind: class.
class idMainMenu::ShowOverwriteSavingDialog::__l7::idSWFScriptFunction_DeclineOverwrite : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18554.
  virtual ~idSWFScriptFunction_DeclineOverwrite();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
};

// IDA Local Type ordinal 18555; PDB kind: class.
class idMainMenu::DeleteSaveGameConfirm::__l2::idSWFScriptFunction_CancelDelete : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18556.
  virtual ~idSWFScriptFunction_CancelDelete();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
};

// IDA Local Type ordinal 18557; PDB kind: class.
class idMainMenu::DeleteSaveGameConfirm::__l3::idSWFScriptFunction_AcceptDelete : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18558.
  virtual ~idSWFScriptFunction_AcceptDelete();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
  int saveIndex;
};

// IDA Local Type ordinal 18559; PDB kind: class.
class idMainMenu::ExitGameConfirm::__l2::idSWFScriptFunction_CancelExit : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18560.
  virtual ~idSWFScriptFunction_CancelExit();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  int option;
  gameDialogMessages_t msg;
};

// IDA Local Type ordinal 18561; PDB kind: class.
class idMainMenu::ExitGameConfirm::__l3::idSWFScriptFunction_AcceptExit : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18562.
  virtual ~idSWFScriptFunction_AcceptExit();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  int option;
  gameDialogMessages_t msg;
  int *currentDeviceIndex;
};

// IDA Local Type ordinal 18563; PDB kind: class.
class idMainMenu::CanStartNewGame::__l9::idSWFScriptFunction_SelectDevice : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18564.
  virtual ~idSWFScriptFunction_SelectDevice();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
};

// IDA Local Type ordinal 18565; PDB kind: class.
class idMainMenu::CanStartNewGame::__l19::idSWFScriptFunction_AcceptExit : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18566.
  virtual ~idSWFScriptFunction_AcceptExit();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *mainMenu;
  gameDialogMessages_t msg;
  bool *askToDeleteAutosaveOnNewGame;
};

// IDA Local Type ordinal 18567; PDB kind: class.
class idMainMenu::CanStartNewGame::__l20::idSWFScriptFunction_CancelExit : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18568.
  virtual ~idSWFScriptFunction_CancelExit();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  gameDialogMessages_t msg;
  bool *askToDeleteAutosaveOnNewGame;
};

// IDA Local Type ordinal 18569; PDB kind: class.
class idMainMenu::LoadDamagedGame::__l5::idSWFScriptFunction_AcceptDelete : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18570.
  virtual ~idSWFScriptFunction_AcceptDelete();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *mainMenu;
  gameDialogMessages_t msg;
  int saveIndex;
};

// IDA Local Type ordinal 18571; PDB kind: class.
class idMainMenu::LoadDamagedGame::__l6::idSWFScriptFunction_CancelDelete : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18572.
  virtual ~idSWFScriptFunction_CancelDelete();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  gameDialogMessages_t msg;
  idSWF *gui;
};

// IDA Local Type ordinal 18573; PDB kind: class.
class idMainMenu::RebindAction::__l52::idSWFScriptFunction_AcceptBind : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18574.
  virtual ~idSWFScriptFunction_AcceptBind();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
  idSWF *swf;
  idPlayerProfile *profile;
  idStr action;
  idStr oldAction;
  keyNum_t keyNum;
  int bindSet;
  int inputDevice;
};

// IDA Local Type ordinal 18575; PDB kind: class.
class idMainMenu::RebindAction::__l53::idSWFScriptFunction_ConfirmUnbind : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18576.
  virtual ~idSWFScriptFunction_ConfirmUnbind();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
  idSWF *swf;
  idPlayerProfile *profile;
  idStr action;
  int bindSet;
  int keyNum;
  int inputDevice;
};

// IDA Local Type ordinal 18577; PDB kind: class.
class idMainMenu::RebindAction::__l11::idSWFScriptFunction_CancelInvalidBind : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18578.
  virtual ~idSWFScriptFunction_CancelInvalidBind();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
  idSWF *swf;
};

// IDA Local Type ordinal 18579; PDB kind: class.
class idMainMenu::RebindAction::__l51::idSWFScriptFunction_CancelBind : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18580.
  virtual ~idSWFScriptFunction_CancelBind();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *menu;
  idSWF *swf;
  gameDialogMessages_t msg;
};

// IDA Local Type ordinal 18581; PDB kind: class.
class idMainMenu::ConfirmBindingReset::__l2::idSWFScriptFunction_CancelRestore : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18582.
  virtual ~idSWFScriptFunction_CancelRestore();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *swf;
};

// IDA Local Type ordinal 18583; PDB kind: class.
class idMainMenu::ConfirmBindingReset::__l3::idSWFScriptFunction_AcceptRestore : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18584.
  virtual ~idSWFScriptFunction_AcceptRestore();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *swf;
  idPlayerProfileGame *profile;
};

// IDA Local Type ordinal 18585; PDB kind: class.
class idMainMenu::idSWFScriptFunction_quitGame::Call::__l2::idSWFScriptFunction_AcceptQuit : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18586.
  virtual ~idSWFScriptFunction_AcceptQuit();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18587; PDB kind: class.
class idMainMenu::idSWFScriptFunction_quitGame::Call::__l3::idSWFScriptFunction_DeclineQuit : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18588.
  virtual ~idSWFScriptFunction_DeclineQuit();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18589; PDB kind: class.
class idMainMenu::idSWFScriptFunction_isGameInstalled::Call::__l8::idSWFScriptFunction_Accept : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18590.
  virtual ~idSWFScriptFunction_Accept();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  gameDialogMessages_t msg;
};

// IDA Local Type ordinal 18591; PDB kind: class.
class idMainMenu::CalculateBenchmark::__l5::idSWFScriptFunction_BenchmarkComplete : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18592.
  virtual ~idSWFScriptFunction_BenchmarkComplete();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18593; PDB kind: class.
class idMainMenu::ShowDisplaySettingFailedMessage::__l5::idSWFScriptFunction_AcceptFailedChanges : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18594.
  virtual ~idSWFScriptFunction_AcceptFailedChanges();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  gameDialogMessages_t msg;
};

// IDA Local Type ordinal 18595; PDB kind: class.
class idMainMenu::UpdateCmds_Start::__l5::idSWFScriptFunction_startPress : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18596.
  virtual ~idSWFScriptFunction_startPress();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  idMainMenu *menu;
};

// IDA Local Type ordinal 18597; PDB kind: class.
class __declspec(align(4)) idMainMenu::UpdateScrollCmds::__l2::idSWFScriptFunction_scroll : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18598.
  virtual ~idSWFScriptFunction_scroll();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  idMainMenu *menu;
  bool up;
};

// IDA Local Type ordinal 18599; PDB kind: class.
class __declspec(align(4)) idMainMenu::UpdateScrollCmds::__l3::idSWFScriptFunction_scrollWheel : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18600.
  virtual ~idSWFScriptFunction_scrollWheel();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  idMainMenu *menu;
  bool up;
};

// IDA Local Type ordinal 18601; PDB kind: class.
class idMainMenu::UpdateAcceptBackCmds::__l2::idSWFScriptFunction_accept : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18602.
  virtual ~idSWFScriptFunction_accept();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  idMainMenu *menu;
};

// IDA Local Type ordinal 18603; PDB kind: class.
class idMainMenu::UpdateAcceptBackCmds::__l14::idSWFScriptFunction_back : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18604.
  virtual ~idSWFScriptFunction_back();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  idMainMenu *menu;
};
