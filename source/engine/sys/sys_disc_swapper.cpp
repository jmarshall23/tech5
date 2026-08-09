/*
===========================================================================

Licensed idTech 5 source recovery.
The state, commands, cvars, encoding and relaunch protocol come from the
Tungsten retail Hex-Rays dump.  Physical XSwapDisc calls are replaced by the
retail PC simulator cvars for the Win32 target.

===========================================================================
*/

#pragma hdrstop
#include "sys_precompiled.h"
#include "sys_disc_swapper.h"
#include "../../shared/idlib/text/base64.h"

#include <vector>

idCVar discSwapper_enable( "discSwapper_enable", "0", CVAR_BOOL | CVAR_NOCHEAT,
	"disc swap enabled, simulator for PC" );
idCVar discSwapper_verbose( "discSwapper_verbose", "0", CVAR_BOOL,
	"debug spam for disc swapper" );
idCVar discSwapper_enableSimulator( "discSwapper_enableSimulator", "0",
	CVAR_BOOL | CVAR_NOCHEAT, "simulator for disc swap testing on the PC" );
idCVar discSwapper_currentDisc( "discSwapper_currentDisc", "1",
	CVAR_INTEGER | CVAR_NOCHEAT, "for simulation purposes, which disc is in the drive" );
idCVar discSwapper_sleep( "discSwapper_sleep", "3000", CVAR_INTEGER | CVAR_NOCHEAT,
	"sleep amount for simulation" );
idCVar discSwapper_deleteSwapFile( "discSwapper_deleteSwapFile", "1",
	CVAR_BOOL | CVAR_NOCHEAT,
	"should we delete the swap file after reading it?  used for testing PS3 details in the XMB" );

static idCVar discSwapper_testTokenizationStr( "discSwapper_testTokenization",
	"~!@#$%^&*()_+{}|:<>?,.;'[]\\-", 0,
	"sample base64 string used by discSwapper_testTokenization" );

static idDiscSwapManager discSwapStateMgrLocal;
idDiscSwapManager * discSwapMgr = &discSwapStateMgrLocal;

CONSOLE_COMMAND( discSwapper_getDiscNumber, "Returns which disc is in use", NULL ) {
	(void)args;
	idLib::Printf( "Using disc %d.\n", discSwapper_currentDisc.GetInteger() );
}

CONSOLE_COMMAND( discSwapper_testTokenization,
	"Tests how the string is going to be broken up", NULL ) {
	(void)args;
	idCmdArgs tokens( discSwapper_testTokenizationStr.GetString(), true );
	idLib::Printf( "source string: %s\n", discSwapper_testTokenizationStr.GetString() );
	for ( int index = 0; index < tokens.Argc(); ++index ) {
		idLib::Printf( "string %d = %s\n", index, tokens.Argv( index ) );
	}
	idStr quoted;
	quoted.Format( "\"%s\"", discSwapper_testTokenizationStr.GetString() );
	tokens.TokenizeString( quoted.c_str(), true );
	idLib::Printf( "source string: %s\n", quoted.c_str() );
	for ( int index = 0; index < tokens.Argc(); ++index ) {
		idLib::Printf( "string %d = %s\n", index, tokens.Argv( index ) );
	}
}

idDiscSwapManager::idDiscSwapManager() : user( NULL ) {
	memset( &inviteInfo, 0, sizeof( inviteInfo ) );
}

idDiscSwapManager::~idDiscSwapManager() {
}

void idDiscSwapManager::Reset() {
	map.Clear();
	savegameFile.Clear();
	additionalArguments.Clear();
	user = session != NULL && session->HasSignInManager()
		? session->GetSignInManager().GetMasterLocalUser() : NULL;
}

bool idDiscSwapManager::IsSwapRequired( int requiredDiscNumber ) {
	const int currentDiscNumber = discSwapper_currentDisc.GetInteger();
	return discSwapper_enable.GetBool() && currentDiscNumber != 0 &&
		requiredDiscNumber != 0 && requiredDiscNumber != currentDiscNumber;
}

bool idDiscSwapManager::IsSwapRequired( const idStr & nextMap, int & newDiscNumber ) {
	(void)nextMap;
	// On Xbox the retail resource manager resolves a map to its disc number.
	// Win32 callers use the force-disc argument or the simulator cvar.
	return IsSwapRequired( newDiscNumber );
}

void idDiscSwapManager::EncodeData( idStr & text ) {
	idBase64 encoded;
	encoded.Encode( reinterpret_cast< const unsigned char * >( text.c_str() ), text.Length() );
	text = encoded.c_str();
	char * mutableText = const_cast< char * >( text.c_str() );
	for ( int index = 0; index < text.Length(); ++index ) {
		if ( mutableText[ index ] == '+' ) {
			mutableText[ index ] = '_';
		} else if ( mutableText[ index ] == '=' ) {
			mutableText[ index ] = ':';
		}
	}
}

void idDiscSwapManager::DecodeData( idStr & text ) {
	char * mutableText = const_cast< char * >( text.c_str() );
	for ( int index = 0; index < text.Length(); ++index ) {
		if ( mutableText[ index ] == '_' ) {
			mutableText[ index ] = '+';
		} else if ( mutableText[ index ] == ':' ) {
			mutableText[ index ] = '=';
		}
	}

	idBase64 encoded;
	encoded.len = text.Length();
	encoded.alloced = encoded.len + 1;
	encoded.data = static_cast< unsigned char * >( malloc( encoded.alloced ) );
	if ( encoded.data == NULL ) {
		text.Clear();
		return;
	}
	memcpy( encoded.data, text.c_str(), encoded.len + 1 );
	std::vector< unsigned char > decoded( static_cast< size_t >( encoded.len ) * 3 / 4 + 4, 0 );
	const int decodedLength = encoded.Decode( decoded.data() );
	if ( decodedLength < 0 ) {
		text.Clear();
		return;
	}
	decoded[ static_cast< size_t >( decodedLength ) ] = 0;
	text = reinterpret_cast< const char * >( decoded.data() );
}

bool idDiscSwapManager::RebuildStateAfterSwap( command_t command, const idCmdArgs & args ) {
	if ( command != DSC_MULTIPLAYER_INVITE ) {
		idStr encodedUser = args.Argv( 1 );
		DecodeData( encodedUser );
		user = session != NULL && session->HasSignInManager()
			? session->GetSignInManager().GetMasterLocalUser() : NULL;
		if ( user == NULL ) {
			idLib::Warning( "Error finding user after relaunch." );
			return false;
		}
	}

	if ( command == DSC_MAP ) {
		additionalArguments = args.Argv( 2 );
		DecodeData( additionalArguments );
		map = args.Argv( 3 );
		DecodeData( map );
	} else if ( command == DSC_LOAD ) {
		savegameFile = args.Argv( 2 );
	}
	return true;
}

bool idDiscSwapManager::EncodeParmsForSwap( command_t command, idStr & encodedData ) {
	if ( command == DSC_MULTIPLAYER_INVITE ) {
		encodedData = additionalArguments;
		EncodeData( encodedData );
		return true;
	}
	if ( user == NULL ) {
		return false;
	}

	encodedData = user->GetGamerTag();
	EncodeData( encodedData );
	if ( command == DSC_MAP ) {
		idStr encoded = additionalArguments;
		EncodeData( encoded );
		encodedData.Append( " " );
		encodedData.Append( encoded );
		encoded = map;
		EncodeData( encoded );
		encodedData.Append( " " );
		encodedData.Append( encoded );
	} else if ( command == DSC_LOAD ) {
		encodedData.Append( " " );
		encodedData.Append( session->GetCurrentSaveSlot() );
	}
	return true;
}

bool idDiscSwapManager::SwapLaunchProcess( command_t command, int newCurrentDiscNumber ) {
	(void)newCurrentDiscNumber;
	idLib::PrintfIf( discSwapper_verbose.GetBool(),
		"[%s] Enter\n", "idDiscSwapManager::SwapLaunchProcess" );

	idStr encodedData;
	idStr launchData;
	if ( command != DSC_SIMPLE_REBOOT ) {
		if ( !EncodeParmsForSwap( command, encodedData ) ) {
			return false;
		}
		const char * restartCommand = "";
		switch ( command ) {
		case DSC_MAP: restartCommand = "+restart_mapAfterSwap"; break;
		case DSC_MULTIPLAYER_INVITE: restartCommand = "+restart_multiplayerInvite"; break;
		case DSC_LOAD: restartCommand = "+restart_loadgame"; break;
		case DSC_MAIN_MENU: restartCommand = "+restart_passMainMenu"; break;
		default: break;
		}
		launchData.Format( "+fromGameRestart %s %s", restartCommand, encodedData.c_str() );
	}

	idLib::PrintfIf( discSwapper_verbose.GetBool(),
		"launch cmd line, sizeof user data (%d): %s\n", encodedData.Length(), launchData.c_str() );
	Sys_ReLaunch( const_cast< char * >( launchData.c_str() ), launchData.Length() );
	return true;
}

idDiscSwapManager::error_t idDiscSwapManager::Swap( command_t command, int forceDiscNumber ) {
	int requiredDiscNumber = forceDiscNumber;
	if ( !IsSwapRequired( map, requiredDiscNumber ) ) {
		return DSE_OK;
	}
	idLib::PrintfIf( discSwapper_verbose.GetBool(), "--- NEED TO SWAP DISCS ---\n" );

	if ( !discSwapper_enableSimulator.GetBool() ) {
		idLib::Warning( "Physical disc swapping is unavailable on Win32; enable the disc swap simulator." );
		return DSE_UNKNOWN;
	}
	if ( discSwapper_sleep.GetInteger() > 0 ) {
		Sys_Sleep( discSwapper_sleep.GetInteger() );
	}
	discSwapper_currentDisc.SetInteger( requiredDiscNumber, true );
	return SwapLaunchProcess( command, requiredDiscNumber ) ? DSE_RESTART_NECESSARY : DSE_UNKNOWN;
}
