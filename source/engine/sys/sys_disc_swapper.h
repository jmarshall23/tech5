#pragma once

class idDiscSwapManager {
public:
	enum command_t {
		DSC_NONE = 0,
		DSC_MAP,
		DSC_MULTIPLAYER_INVITE,
		DSC_LOAD,
		DSC_MAIN_MENU,
		DSC_SIMPLE_REBOOT,
		DSC_NUM
	};

	enum error_t {
		DSE_OK = 0,
		DSE_CANCEL,
		DSE_UNKNOWN,
		DSE_INSUFFICIENT_ROOM,
		DSE_CORRECT_DISC_ALREADY,
		DSE_UNABLE_TO_SELECT_STORAGE_DEVICE,
		DSE_CREATE_USER,
		DSE_RESTART_NECESSARY,
		DSE_INVALID_USER
	};

	// _XINVITE_INFO is an 84-byte Xbox contract in the retail PDB.  The Win32
	// backend preserves its storage without importing Xbox SDK declarations.
	struct inviteInfo_t {
		byte data[ 84 ];
	};

	idDiscSwapManager();
	~idDiscSwapManager();

	void Reset();
	static bool IsSwapRequired( int requiredDiscNumber );
	static bool IsSwapRequired( const idStr & nextMap, int & newDiscNumber );
	bool RebuildStateAfterSwap( command_t command, const idCmdArgs & args );
	error_t Swap( command_t command, int forceDiscNumber = 0 );

	idStrStatic< 251 > map;
	idStrStatic< 64 > savegameFile;
	idStrStatic< 1000 > additionalArguments;
	idLocalUser * user;
	inviteInfo_t inviteInfo;

private:
	void EncodeData( idStr & data );
	void DecodeData( idStr & data );
	bool EncodeParmsForSwap( command_t command, idStr & encodedData );
	bool SwapLaunchProcess( command_t command, int newCurrentDiscNumber );
};

extern idDiscSwapManager * discSwapMgr;

extern idCVar discSwapper_enable;
extern idCVar discSwapper_verbose;
extern idCVar discSwapper_enableSimulator;
extern idCVar discSwapper_currentDisc;
extern idCVar discSwapper_sleep;
extern idCVar discSwapper_deleteSwapFile;
