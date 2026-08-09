/*
===========================================================================

Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company. 

This file is part of the Doom 3 BFG Edition GPL Source Code ("Doom 3 BFG Edition Source Code").  

Doom 3 BFG Edition Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 BFG Edition Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 BFG Edition Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/
#ifndef __SYS_PROFILE_H__
#define __SYS_PROFILE_H__

#include "sys_savegame.h"
#include "sys_session_savegames.h"


class idSaveGameProcessorSaveProfile;
class idSaveGameProcessorLoadProfile;
class idLocalUser;

union profileStatValue_t {
	int i;
	float f;
};

// PDB-authoritative RAGE profile layout.  The platform/game layer can derive
// from this class; the concrete base implementation is a safe Windows
// fallback for the recovered system code.
class idPlayerProfile {
	friend class idLocalUser;
	friend class idProfileMgr;
public:
	static const int MAX_PLAYER_PROFILE_STATS = 500;
	enum state_t {
		IDLE = 0,
		SAVING = 1,
		LOADING = 2,
		SAVE_REQUESTED = 3,
		LOAD_REQUESTED = 4,
		ERR = 5
	};

	virtual ~idPlayerProfile() {}
	virtual void SetDefaults() {
		hasUser = true;
		achievementBits = 0;
		achievementBits2 = 0;
		dlcReleaseVersion = 0;
		stats.SetNum( MAX_PLAYER_PROFILE_STATS );
		for ( int index = 0; index < stats.Num(); ++index ) stats[ index ].i = 0;
	}
	virtual bool Serialize( idSerializer * serializer ) {
		if ( serializer == NULL ) return false;
		serializer->Serialize( achievementBits );
		serializer->Serialize( achievementBits2 );
		serializer->Serialize( dlcReleaseVersion );
		for ( int index = 0; index < stats.Num(); ++index ) serializer->Serialize( stats[ index ].i );
		return true;
	}
	virtual bool UpdateDisplayModeFromCvars() { return false; }
	virtual bool CommitDisplayChanges() { return false; }
	virtual float GetMouseSensitivity() const { return 1.0f; }
	virtual int GetLevel() const { return 0; }
	virtual int GetChosenEmblem() const { return 0; }
	virtual void SetInvertLook( bool ) {}
	virtual uint32 GetSubtitleLanguageMask() const { return 0; }

	static idPlayerProfile * CreatePlayerProfile( int deviceIndex ) {
		idPlayerProfile * profile = new idPlayerProfile();
		profile->deviceNum = deviceIndex;
		return profile;
	}

	bool Serialize( idSerializer & serializer ) { return Serialize( &serializer ); }
	int GetDeviceNumForProfile() const { return deviceNum; }
	void SetDeviceNumForProfile( int value ) { deviceNum = value; }
	state_t GetState() const { return state; }
	state_t GetRequestedState() const { return requestedState; }
	bool IsDirty() const { return true; }
	void SaveSettings( bool = true ) {
		if ( state != SAVING && requestedState == IDLE ) requestedState = SAVE_REQUESTED;
	}
	void LoadSettings() {
		if ( hasUser && state != LOADING && requestedState == IDLE ) requestedState = LOAD_REQUESTED;
	}
	bool GetAchievement( int id ) const {
		if ( id < 0 || id >= 128 ) return false;
		return id < 64 ? ( achievementBits & BIT64( id ) ) != 0 :
			( achievementBits2 & BIT64( id - 64 ) ) != 0;
	}
	void SetAchievement( int id ) {
		if ( id >= 0 && id < 64 ) achievementBits |= BIT64( id );
		else if ( id >= 64 && id < 128 ) achievementBits2 |= BIT64( id - 64 );
	}
	void ClearAchievement( int id ) {
		if ( id >= 0 && id < 64 ) achievementBits &= ~BIT64( id );
		else if ( id >= 64 && id < 128 ) achievementBits2 &= ~BIT64( id - 64 );
	}
	int GetDlcReleaseVersion() const { return dlcReleaseVersion; }
	void SetDlcReleaseVersion( int value ) { dlcReleaseVersion = value; }
	void StatSetInt( int stat, int value ) { if ( stat >= 0 && stat < stats.Num() ) stats[ stat ].i = value; }
	void StatSetFloat( int stat, float value ) { if ( stat >= 0 && stat < stats.Num() ) stats[ stat ].f = value; }
	int StatGetInt( int stat ) const { return stat >= 0 && stat < stats.Num() ? stats[ stat ].i : 0; }
	float StatGetFloat( int stat ) const { return stat >= 0 && stat < stats.Num() ? stats[ stat ].f : 0.0f; }
	void MarkDirty( bool ) {}

protected:
	idPlayerProfile() : state( IDLE ), requestedState( IDLE ), deviceNum( -1 ), hasUser( false ),
		achievementBits( 0 ), achievementBits2( 0 ), dlcReleaseVersion( 0 ) { SetDefaults(); }
	void SetState( state_t value ) { state = value; }
	void SetRequestedState( state_t value ) { requestedState = value; }

	__declspec( align( 8 ) ) state_t state;
	state_t requestedState;
	int deviceNum;
	bool hasUser;
	uint64 achievementBits;
	uint64 achievementBits2;
	int dlcReleaseVersion;
	idStaticList< profileStatValue_t, MAX_PLAYER_PROFILE_STATS > stats;
};

/*
================================================
idProfileMgr 
================================================
*/
class idProfileMgr {
public:
						idProfileMgr();
						~idProfileMgr();

	// Called the first time it's asked to load
	void				Init( idLocalUser * user );

	void 				Pump();
	idPlayerProfile *	GetProfile();

private:
	void				LoadSettingsAsync();
	void				SaveSettingsAsync();
	
	void				OnLoadSettingsCompleted( idSaveLoadParms * parms );
	void				OnSaveSettingsCompleted( idSaveLoadParms * parms );

private:
	std::auto_ptr< idSaveGameProcessorSaveProfile >	profileSaveProcessor;
	std::auto_ptr< idSaveGameProcessorLoadProfile >	profileLoadProcessor;

	idLocalUser *						user;					// reference passed in
	idPlayerProfile *					profile;				
	saveGameHandle_t					handle;
};

/*
================================================
idSaveGameProcessorSaveProfile
================================================
*/
class idSaveGameProcessorSaveProfile : public idSaveGameProcessorSaveFiles {
public:
	DEFINE_CLASS( idSaveGameProcessorSaveProfile );
					
					idSaveGameProcessorSaveProfile();

	bool			InitSaveProfile( idPlayerProfile * profile, const char * folder );
	virtual bool	Process();

private:
	idFile_SaveGame *	profileFile;
	idPlayerProfile *	profile;

};

/*
================================================
idSaveGameProcessorLoadProfile
================================================
*/
class idSaveGameProcessorLoadProfile : public idSaveGameProcessorLoadFiles {
public:
	DEFINE_CLASS( idSaveGameProcessorLoadProfile );

					idSaveGameProcessorLoadProfile();
					~idSaveGameProcessorLoadProfile();

	bool			InitLoadProfile( idPlayerProfile * profile, const char * folder );
	virtual bool	Process();


private:
	idFile_SaveGame *	profileFile;
	idPlayerProfile *	profile;

};

// Synchronous check, just checks if a profile exists within the savegame location
bool Sys_SaveGameProfileCheck();

#endif
