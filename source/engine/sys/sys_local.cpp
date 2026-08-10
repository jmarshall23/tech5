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

#pragma hdrstop
#include "sys_precompiled.h"
#include "sys_local.h"
#include "win32/win_local.h"

const char * sysLanguageNames[] = {
	ID_LANG_ENGLISH, ID_LANG_FRENCH, ID_LANG_ITALIAN, ID_LANG_GERMAN, ID_LANG_SPANISH, ID_LANG_JAPANESE, NULL
};

const int numLanguages = sizeof( sysLanguageNames ) / sizeof sysLanguageNames[ 0 ] - 1;

idCVar sys_lang( "sys_lang", ID_LANG_ENGLISH, CVAR_SYSTEM | CVAR_INIT, "", sysLanguageNames, idCmdSystem::ArgCompletion_String<sysLanguageNames> );

idSysLocal			sysLocal;
idSys *				sys = &sysLocal;

idSysLocal::~idSysLocal() = default;

namespace {
idKeyboard keyboard;
idMouse mouse;
}

idJoystick & idSysLocal::Joystick() { return win32.g_Joystick; }
idKeyboard & idSysLocal::Keyboard() { return keyboard; }
idMouse & idSysLocal::Mouse() { return mouse; }

int64 idSysLocal::GetClockTicks() { return Sys_GetClockTicks(); }

int64 idSysLocal::ClockTicksPerSecond() { return Sys_ClockTicksPerSecond(); }

cpuid_t idSysLocal::GetProcessorId() {
	return Sys_GetProcessorId();
}

const char *idSysLocal::GetProcessorString() {
	return Sys_GetProcessorString();
}

const char *idSysLocal::FPU_GetState() {
	return Sys_FPU_GetState();
}

bool idSysLocal::FPU_StackIsEmpty() {
	return Sys_FPU_StackIsEmpty();
}

void idSysLocal::FPU_SetFTZ( bool enable ) {
	Sys_FPU_SetFTZ( enable );
}

void idSysLocal::FPU_SetDAZ( bool enable ) {
	Sys_FPU_SetDAZ( enable );
}

uint32 idSysLocal::DLL_Load( const char *dllName ) {
	return static_cast<uint32>( Sys_DLL_Load( dllName ) );
}

void *idSysLocal::DLL_GetProcAddress( uint32 dllHandle, const char *procName ) {
	return Sys_DLL_GetProcAddress( dllHandle, procName );
}

void idSysLocal::DLL_Unload( uint32 dllHandle ) {
	Sys_DLL_Unload( dllHandle );
}

void idSysLocal::DLL_GetFileName( const char *baseName, char *dllName, int maxLength ) {
	_snprintf_s( dllName, maxLength, _TRUNCATE, "%s.dll", baseName );
}

void idSysLocal::FPU_EnableExceptions( int exceptions ) {
	Sys_FPU_EnableExceptions( exceptions );
}

const char * idSysLocal::GetClipboardData() { return Sys_GetClipboardData(); }
void idSysLocal::SetClipboardData( const char * text ) { Sys_SetClipboardData( text ); }
int idSysLocal::Milliseconds() { return Sys_Milliseconds(); }
uint32 idSysLocal::VblCount() { return static_cast<uint32>( ( static_cast<uint64>( Sys_Milliseconds() ) * 60u ) / 1000u ); }
void idSysLocal::PrintStackTrace() { Sys_DebugPrintf( "%s", Sys_GetCallStackCurStr( 64 ) ); }
const char * idSysLocal::GetOSUserName() { return Sys_GetOSUserName(); }
const char * idSysLocal::GetMachineName() { return Sys_GetMachineName(); }
void idSysLocal::QueueEvent( sysEventType_t type, int value, int value2, int ptrLength, void * ptr, int inputDeviceNum ) {
	Sys_QueEvent( type, value, value2, ptrLength, ptr, inputDeviceNum );
}
void idSysLocal::GenerateEvents() { Sys_GenerateEvents(); }
sysEvent_t idSysLocal::GetEvent() { return Sys_GetEvent(); }
void idSysLocal::ClearEvents() { Sys_ClearEvents(); }

/*
=================
Sys_TimeStampToStr
=================
*/
const char *Sys_TimeStampToStr( ID_TIME_T timeStamp ) {
	static char timeString[MAX_STRING_CHARS];
	timeString[0] = '\0';

	time_t ts = (time_t)timeStamp;
	tm*	time = localtime( &ts );
	if ( time == NULL ) {
		return "??/??/???? ??:??";
	}

	idStr out;
	
	idStr lang = cvarSystem->GetCVarString( "sys_lang" );
	if ( _stricmp( lang.c_str(), ID_LANG_ENGLISH ) == 0 ) {
		// english gets "month/day/year  hour:min" + "am" or "pm"
		out = va( "%02d", time->tm_mon + 1 );
		out.Append( "/" );
		out.Append( va( "%02d", time->tm_mday ) );
		out.Append( "/" );
		out.Append( va( "%d", time->tm_year + 1900 ) );
		out.Append( " " );	// changed to spaces since flash doesn't recognize \t
		if ( time->tm_hour > 12 ) {
			out.Append( va( "%02d", time->tm_hour - 12 ) );
		} else if ( time->tm_hour == 0 ) {
				out.Append( "12" );
		} else {
			out.Append( va( "%02d", time->tm_hour ) );
		}
		out.Append( ":" );
		out.Append( va( "%02d", time->tm_min ) );
		if ( time->tm_hour >= 12 ) {
			out.Append( "pm" );
		} else {
			out.Append( "am" );
		}
	} else {
		// europeans get "day/month/year  24hour:min"
		out = va( "%02d", time->tm_mday );
		out.Append( "/" );
		out.Append( va( "%02d", time->tm_mon + 1 ) );
		out.Append( "/" );
		out.Append( va( "%d", time->tm_year + 1900 ) );
		out.Append( " " );	// changed to spaces since flash doesn't recognize \t
		out.Append( va( "%02d", time->tm_hour ) );
		out.Append( ":" );
		out.Append( va( "%02d", time->tm_min ) );
	}
	strncpy_s( timeString, sizeof( timeString ), out.c_str(), _TRUNCATE );

	return timeString;
}

/*
========================
Sys_SecToStr
========================
*/
const char * Sys_SecToStr( int sec ) {
	static char timeString[MAX_STRING_CHARS];

	int weeks = sec / ( 3600 * 24 * 7 );
	sec -= weeks * ( 3600 * 24 * 7 );

	int days = sec / ( 3600 * 24 );
	sec -= days * ( 3600 * 24 );

	int hours = sec / 3600;
	sec -= hours * 3600;

	int min = sec / 60;
	sec -= min * 60;

	if ( weeks > 0 ) {
		sprintf( timeString, "%dw, %dd, %d:%02d:%02d", weeks, days, hours, min, sec );
	} else if ( days > 0 ) {
		sprintf( timeString, "%dd, %d:%02d:%02d", days, hours, min, sec );
	} else {
		sprintf( timeString, "%d:%02d:%02d", hours, min, sec );
	}

	return timeString;
}

// return number of supported languages
int Sys_NumLangs() {
	return numLanguages;
}

// get language name by index
const char * Sys_Lang( int idx ) {
	if ( idx >= 0 && idx < numLanguages ) {
		return sysLanguageNames[ idx ];
	}
	return "";
}

const char * Sys_DefaultLanguage() {
	// sku breakdowns are as follows
	//  EFIGS	Digital
	//  EF  S	North America
	//   FIGS	EU
	//  E		UK
	// JE    	Japan

	// If japanese exists, default to japanese
	// else if english exists, defaults to english
	// otherwise, french

	return ID_LANG_ENGLISH;
}
