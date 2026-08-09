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
#include "swf_precompiled.h"
#include "../../renderer/image.h"

#pragma warning(disable: 4355) // 'this' : used in base member initializer list

idCVar swf_loadBinary( "swf_loadBinary", "1", CVAR_INTEGER, "used to set whether to load binary swf from generated" );
idCVar swf_platformOverride( "swf_platformOverride", "-1", CVAR_INTEGER, "used to force which buttons are displayed for testing UI 0 - xbox, 1 - ps3, 2 - pc" );
idCVar swf_purgeUnusedImages( "swf_purgeUnusedImages", "1", CVAR_BOOL, "purge atlas images when a swf is not being rendered" );

int idSWF::mouseX = -1;
int idSWF::mouseY = -1;
bool idSWF::isMouseInClientArea = false;
idList< idSWF *, TAG_SWF > idSWF::allSWFObjects;
purgableSwfImage_t idSWF::purgableSWFImages[ 8 ];
uint32 idSWF::swfFrameNum = 0;

static idRandom2 swfRandom;

static const char * dictTypeNames[ NUM_DICT_TYPES ] = {
	"NULL",
	"IMAGE",
	"SHAPE",
	"MORPH",
	"SPRITE",
	"FONT",
	"TEXT",
	"EDITTEXT"
};

void listSWF_f( const idCmdArgs & args ) {
	(void)args;
	for ( int index = 0; index < idSWF::allSWFObjects.Num(); ++index ) {
		idSWF * swf = idSWF::allSWFObjects[ index ];
		idLib::Printf( "%-2i %4ix%4i = %4ik ", index, swf->atlasWidth, swf->atlasHeight,
			( swf->atlasWidth * swf->atlasHeight ) / 1024 );
		switch ( swf->atlasImage->ImageState() ) {
			case IS_PURGED:
				idLib::Printf( "PURGED" );
				break;
			case IS_BACKGROUND_READING:
				idLib::Printf( "LOADING" );
				break;
			default:
				idLib::Printf( "      " );
				break;
		}
		idLib::Printf( " %s\n", swf->filename.c_str() );
	}
}

void reportSWFMemory_f( const idCmdArgs & args ) {
	(void)args;
	int typeCounts[ NUM_DICT_TYPES ] = {};
	for ( int swfIndex = 0; swfIndex < idSWF::allSWFObjects.Num(); ++swfIndex ) {
		const idSWF * swf = idSWF::allSWFObjects[ swfIndex ];
		for ( int dictionaryIndex = 0; dictionaryIndex < swf->dictionary.Num(); ++dictionaryIndex ) {
			const int type = swf->dictionary[ dictionaryIndex ].type;
			if ( type >= 0 && type < NUM_DICT_TYPES ) {
				++typeCounts[ type ];
			}
		}
	}
	for ( int type = 0; type < NUM_DICT_TYPES; ++type ) {
		idLib::Printf( "%6i %s\n", typeCounts[ type ], dictTypeNames[ type ] );
	}
}

void reportMainMenuFonts_f( const idCmdArgs & args ) {
	(void)args;
	for ( int swfIndex = 0; swfIndex < idSWF::allSWFObjects.Num(); ++swfIndex ) {
		idSWF * swf = idSWF::allSWFObjects[ swfIndex ];
		idLib::Printf( "++++ %s ++++\n", swf->filename.c_str() );
		for ( int index = 0; index < swf->dictionary.Num(); ++index ) {
			idSWFDictionaryEntry & entry = swf->dictionary[ index ];
			if ( entry.type != SWF_DICT_EDITTEXT || entry.edittext == NULL ) {
				continue;
			}
			idSWFDictionaryEntry * fontEntry = swf->FindDictionaryEntry( entry.edittext->fontID, SWF_DICT_FONT );
			if ( fontEntry == NULL || fontEntry->font == NULL || fontEntry->font->fontID == NULL ) {
				continue;
			}
			idStr initialText( entry.edittext->initialText.c_str() );
			idStr variable( entry.edittext->variable.c_str() );
			initialText.Replace( "\n", "\\n" );
			variable.Replace( "\n", "\\n" );
			idLib::Printf( "\t%s - [ %s, %s ] ( %f, %f ) - ( %f, %f )\n",
				fontEntry->font->fontID->GetName(), initialText.c_str(), variable.c_str(),
				entry.edittext->bounds.br.x, entry.edittext->bounds.br.y,
				entry.edittext->bounds.tl.x, entry.edittext->bounds.tl.y );
		}
	}
}

void printSWFVar_f( const idCmdArgs & args ) {
	if ( args.Argc() != 3 ) {
		idLib::Printf( "Usage: printSWFVar <SWF id from listSWF> <path.to.object>\n" );
		return;
	}

	const int index = std::atoi( args.Argv( 1 ) );
	if ( index < 0 || index >= idSWF::allSWFObjects.Num() ) {
		idLib::Printf( "printSWFVar index %d is out of range. Expecting range [0, %d]\n",
			index, idSWF::allSWFObjects.Num() - 1 );
		return;
	}

	idSWF * swf = idSWF::allSWFObjects[ index ];
	idLib::Printf( "Printing from SWF %s...\n", swf->filename.c_str() );
	idSWFScriptVar value = swf->globals->Get( "_global" );
	const std::string path( args.Argv( 2 ) );
	size_t start = 0;
	while ( start <= path.length() ) {
		const size_t end = path.find( '.', start );
		const std::string component = path.substr( start, end - start );
		if ( component.empty() || !value.IsObject() ) {
			idLib::Printf( "Could not resolve '%s' under object '%s'\n", component.c_str(), path.c_str() );
			return;
		}
		value = value.GetObject()->Get( component.c_str() );
		if ( end == std::string::npos ) {
			break;
		}
		start = end + 1;
	}
	value.PrintToConsole();
}

void checkSWF_f( const idCmdArgs & args ) {
	if ( args.Argc() != 2 ) {
		idLib::Printf( "USAGE: checkSWF <swfFile>\n" );
		return;
	}
	idSWF * swf = new (TAG_SWF) idSWF( args.Argv( 1 ), NULL, true );
	delete swf;
}

static idCommandLink listSWF_v( "listSWF", listSWF_f, "Lists all current idSWF objects" );
static idCommandLink printSWFVar_v( "printSWFVar", printSWFVar_f, "Prints the contents of a SWF variable to console" );
static idCommandLink reportSWFMemory_v( "reportSWFMemory", reportSWFMemory_f, "Lists all current idSWF dictType objects" );
static idCommandLink checkSWF_v( "checkSWF", checkSWF_f, "Loads and unloads a swf to report memory usage and check for leaks" );
static idCommandLink reportMainMenuFonts_v( "reportMainMenuFonts", reportMainMenuFonts_f, "reports font usage in main menu" );

extern idCVar in_useJoystick;
extern idCVar com_multiplayer;
extern idCVar com_version;
extern idCVar sys_langJapanese;

/*
===================
idSWF::idSWF
===================
*/
idSWF::idSWF( const char * filename_, idSoundWorld * soundWorld_, bool atlasPurgable_ ) {

	atlasPurgable = atlasPurgable_;
	atlasImage = NULL;
	atlasMaterial = NULL;
	atlasFile = NULL;
	atlasWidth = 0;
	atlasHeight = 0;

	swfScale = 1.0f;
	swfRandom.SetSeed( Sys_Milliseconds() );
	const bool pushedWarningInfo = idLib::PushWarningInfo( "swf", filename_ );

	guiSolid = declManager->FindMaterial( "guiSolid" );
	guiStencilIncr = declManager->FindMaterial( "guiStencilIncr" );
	guiStencilDecr = declManager->FindMaterial( "guiStencilDecr" );
	guiCursor_arrow = declManager->FindMaterial( "textures/guis/default/guicursor_arrow" );
	guiCursor_hand = declManager->FindMaterial( "textures/guis/default/guicursor_hand" );
	white = declManager->FindMaterial( "_white" );

	tooltipButtonImage.Append( keyButtonImages_t( "<DPAD>", "textures/guis/controller/xb360/360_dpad", "textures/guis/controller/ps3/ps3_dpad", 48, 48, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<JOY_DPAD_UP>", "textures/guis/controller/xb360/360_dpad_up", "textures/guis/controller/ps3/ps3_dpad_up", 48, 48, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<JOY_DPAD_RIGHT>", "textures/guis/controller/xb360/360_dpad_right", "textures/guis/controller/ps3/ps3_dpad_right", 48, 48, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<JOY_DPAD_DOWN>", "textures/guis/controller/xb360/360_dpad_down", "textures/guis/controller/ps3/ps3_dpad_down", 48, 48, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<JOY_DPAD_LEFT>", "textures/guis/controller/xb360/360_dpad_left", "textures/guis/controller/ps3/ps3_dpad_left", 48, 48, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<JOY1>", "textures/guis/controller/xb360/360_a_alt", "textures/guis/controller/ps3/ps3_x_alt", 32, 32, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<JOY2>", "textures/guis/controller/xb360/360_b_alt", "textures/guis/controller/ps3/ps3_circle", 32, 32, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<JOY3>", "textures/guis/controller/xb360/360_x_alt", "textures/guis/controller/ps3/ps3_square", 32, 32, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<JOY4>", "textures/guis/controller/xb360/360_y_alt", "textures/guis/controller/ps3/ps3_triangle", 32, 32, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<JOY5>", "textures/guis/controller/xb360/360_lb", "textures/guis/controller/ps3/ps3_l1", 48, 48, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<JOY6>", "textures/guis/controller/xb360/360_rb", "textures/guis/controller/ps3/ps3_r1", 48, 48, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<JOY10>", "textures/guis/controller/xb360/360_back", "textures/guis/controller/ps3/ps3_select", 64, 64, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<JOY7>", "textures/guis/controller/xb360/360_l3", "textures/guis/controller/ps3/ps3_l3", 64, 64, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<JOY8>", "textures/guis/controller/xb360/360_r3", "textures/guis/controller/ps3/ps3_r3", 64, 64, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<LEFT_STICK>", "textures/guis/controller/xb360/360_ls", "textures/guis/controller/ps3/ps3_ls", 48, 48, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<RIGHT_STICK>", "textures/guis/controller/xb360/360_rs", "textures/guis/controller/ps3/ps3_rs", 48, 48, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<JOY_TRIGGER2>", "textures/guis/controller/xb360/360_rt", "textures/guis/controller/ps3/ps3_r2", 48, 48, 0 ) );
	tooltipButtonImage.Append( keyButtonImages_t( "<JOY_TRIGGER1>", "textures/guis/controller/xb360/360_lt", "textures/guis/controller/ps3/ps3_l2", 48, 48, 0 ) );
	 	
	for ( int index = 0; index < tooltipButtonImage.Num(); index++ ) {
		if ( ( tooltipButtonImage[index].xbImage != NULL ) && ( tooltipButtonImage[index].xbImage[0] != '\0' ) ) {
			declManager->FindMaterial( tooltipButtonImage[index].xbImage );
		}
		if ( ( tooltipButtonImage[index].psImage != NULL ) && ( tooltipButtonImage[index].psImage[0] != '\0' ) ) {
			declManager->FindMaterial( tooltipButtonImage[index].psImage );
		}
	}
	declManager->FindMaterial( "textures/gui/load_image" );

	frameWidth = 0;
	frameHeight = 0;
	frameRate = 0;
	userDeviceNumber = 0;
	lastRenderTime = 0;

	isActive = false;
	inhibitControl = false;
	useInhibtControl = true;

	crop = false;
	blackbars = false;
	paused = false;
	hasHitObject = false;
	automaticRescale = true;

	useMouse = true;
	mouseEnabled = false;
	renderBorder = 0;
	mouseObject = NULL;
	hoverObject = NULL;
	soundEmitter = NULL;
	c_TextInstanceAdoptions = 0;
	c_TextInstanceOrphans = 0;
	c_SpriteInstanceAdoptions = 0;
	c_SpriteInstanceOrphans = 0;

	idStr canonicalFilename;
	if ( idStr::Cmpn( filename_, "swf/", 4 ) != 0 ) {
		// if it doesn't already have swf/ in front of it, add it
		canonicalFilename = "swf/";
		canonicalFilename += filename_;
	} else {
		canonicalFilename = filename_;
	}
	canonicalFilename.ToLower();
	canonicalFilename.BackSlashesToSlashes();
	canonicalFilename.SetFileExtension( ".swf" );
	filename.Set( canonicalFilename.c_str() );

	timestamp = fileSystem->GetTimestamp( filename.c_str() );

	mainsprite = new (TAG_SWF) idSWFSprite( this );
	mainspriteInstance = NULL;

	char generatedName[ 256 ];
	fileSystem->FixLongFilename( "generated", "bimage", filename.c_str(), generatedName, sizeof( generatedName ) );
	atlasTextureName.Set( generatedName );
	idStr binaryFileName( generatedName );
	binaryFileName.StripFileExtension();

	if ( swf_loadBinary.GetBool() ) {
		if ( !LoadBinary( binaryFileName ) ) {
			if ( LoadSWF( filename.c_str() ) ) {
				WriteBinary( binaryFileName );
			}
		}
	} else {
		LoadSWF( filename.c_str() );
	}
	CreateAltasImageAndMaterial();

	globals = idSWFScriptObject::Alloc();
	globals->Set( "_global", globals );

	globals->Set( "Object", &scriptFunction_Object );

	mainspriteInstance = spriteInstanceAllocator.Alloc();
	mainspriteInstance->Init( mainsprite, NULL, "_root", 0 );

	shortcutKeys = idSWFScriptObject::Alloc();
	scriptFunction_shortcutKeys_clear.Bind( this );
	scriptFunction_shortcutKeys_clear.Call( shortcutKeys, idSWFParmList() );
	globals->Set( "shortcutKeys", shortcutKeys );

	globals->Set( "deactivate", scriptFunction_deactivate.Bind( this ) );
	globals->Set( "inhibitControl", scriptFunction_inhibitControl.Bind( this ) );
	globals->Set( "useInhibit", scriptFunction_useInhibit.Bind( this ) );
	globals->Set( "precacheSound", scriptFunction_precacheSound.Bind( this ) );
	globals->Set( "playSound", scriptFunction_playSound.Bind( this ) );
	globals->Set( "stopSounds",scriptFunction_stopSounds.Bind( this ) );
	globals->Set( "getPlatform", scriptFunction_getPlatform.Bind( this ) );
	globals->Set( "getTruePlatform", scriptFunction_getTruePlatform.Bind( this ) );
	globals->Set( "getLocalString", scriptFunction_getLocalString.Bind( this ) );
	globals->Set( "isMultiplayer", scriptFunction_isMultiplayer.Bind( this ) );
	globals->Set( "swapPS3Buttons", scriptFunction_swapPS3Buttons.Bind( this ) );
	globals->Set( "_root", mainspriteInstance->scriptObject );
	globals->Set( "strReplace", scriptFunction_strReplace.Bind( this ) );
	globals->Set( "getCVarInteger", scriptFunction_getCVarInteger.Bind( this ) );
	globals->Set( "setCVarInteger", scriptFunction_setCVarInteger.Bind( this ) );
	globals->Set( "isJapanese", scriptFunction_isJapanese.Bind( this ) );

	globals->Set( "acos", scriptFunction_acos.Bind( this ) );
	globals->Set( "cos", scriptFunction_cos.Bind( this ) );
	globals->Set( "sin", scriptFunction_sin.Bind( this ) );
	globals->Set( "round", scriptFunction_round.Bind( this ) );
	globals->Set( "pow", scriptFunction_pow.Bind( this ) );
	globals->Set( "sqrt", scriptFunction_sqrt.Bind( this ) );
	globals->Set( "abs", scriptFunction_abs.Bind( this ) );
	globals->Set( "rand", scriptFunction_rand.Bind( this ) );
	globals->Set( "floor", scriptFunction_floor.Bind( this ) );
	globals->Set( "ceil", scriptFunction_ceil.Bind( this ) );
	globals->Set( "toUpper", scriptFunction_toUpper.Bind( this ) );
	globals->Set( "buildversion", com_version.GetString() );

	globals->SetNative( "platform", swfScriptVar_platform.Bind( &scriptFunction_getPlatform ) );
	globals->SetNative( "blackbars", swfScriptVar_blackbars.Bind( this ) );
	globals->SetNative( "automaticRescale", swfScriptVar_automaticRescale.Bind( this ) );
	globals->SetNative( "cropToHeight", swfScriptVar_crop.Bind( this ) );
	globals->SetNative( "cropToFit", swfScriptVar_crop.Bind( this ) );
	globals->SetNative( "crop", swfScriptVar_crop.Bind( this ) );

	// Do this to touch any external references (like sounds)
	// But disable script warnings because many globals won't have been created yet
	extern idCVar swf_debug;
	int debug = swf_debug.GetInteger();
	swf_debug.SetInteger( 0 );

	mainspriteInstance->Run();
	mainspriteInstance->RunActions();
	mainspriteInstance->RunTo( 0 );

	swf_debug.SetInteger( debug );

	if ( mouseX == -1 ) {
		mouseX = ( frameWidth / 2 );
	}

	if ( mouseY == -1 ) {
		mouseY = ( frameHeight / 2 );
	}

	AllocateEmitter( soundWorld_ );
	allSWFObjects.Append( this );
	if ( pushedWarningInfo ) {
		idLib::PopWarningInfo();
	}
}

/*
===================
idSWF::~idSWF
===================
*/
idSWF::~idSWF() {
	if ( atlasImage != NULL && atlasPurgable ) {
		MarkImageForPurging( atlasImage );
	}
	for ( int i = 0; i < allSWFObjects.Num(); i++ ) {
		if ( allSWFObjects[i] == this ) {
			allSWFObjects.RemoveIndex( i );
			break;
		}
	}
	PurgeOrphanage();
	spriteInstanceAllocator.Free( mainspriteInstance );
	delete mainsprite;

	for ( int i = 0 ; i < dictionary.Num() ; i++ ) {
		if ( dictionary[i].sprite ) {
			delete dictionary[i].sprite;
			dictionary[i].sprite = NULL;
		}
		if ( dictionary[i].shape ) {
			delete dictionary[i].shape;
			dictionary[i].shape = NULL;
		}
		if ( dictionary[i].font ) {
			delete dictionary[i].font;
			dictionary[i].font = NULL;
		}
		if ( dictionary[i].text ) {
			delete dictionary[i].text;
			dictionary[i].text = NULL;
		}
		if ( dictionary[i].edittext ) {
			delete dictionary[i].edittext;
			dictionary[i].edittext = NULL;
		}
	}
	
	globals->Clear();
	tooltipButtonImage.Clear();
	globals->Release();

	shortcutKeys->Clear();
	shortcutKeys->Release();
	ClearEmitter( true );
}

void idSWF::MarkImageForPurging( idImage * image ) {
	int emptyIndex = -1;
	for ( int i = 0; i < 8; i++ ) {
		if ( purgableSWFImages[i].image == image ) {
			purgableSWFImages[i].swfFrameNum = swfFrameNum;
			return;
		}
		if ( emptyIndex == -1 && purgableSWFImages[i].image == NULL ) {
			emptyIndex = i;
		}
	}
	if ( emptyIndex != -1 ) {
		purgableSWFImages[emptyIndex].image = image;
		purgableSWFImages[emptyIndex].swfFrameNum = swfFrameNum;
	}
}

void idSWF::RemoveImgFromPurgableList( idImage * image ) {
	for ( int i = 0; i < 8; i++ ) {
		if ( purgableSWFImages[i].image == image ) {
			purgableSWFImages[i].image = NULL;
		}
	}
}

void idSWF::PurgeUnusedImages() {
	if ( !swf_purgeUnusedImages.GetBool() ) {
		return;
	}
	for ( int i = 0; i < 8; i++ ) {
		if ( purgableSWFImages[i].image != NULL && swfFrameNum - purgableSWFImages[i].swfFrameNum > 2 ) {
			purgableSWFImages[i].image->PurgeImage();
			purgableSWFImages[i].image = NULL;
		}
	}
	++swfFrameNum;
}

void idSWF::ForcePurgeImages() {
	if ( !swf_purgeUnusedImages.GetBool() ) {
		return;
	}
	renderSystem->SyncRenderThread( true );
	for ( int i = 0; i < 8; i++ ) {
		if ( purgableSWFImages[i].image != NULL ) {
			idLib::Printf( "Force purging image %s\n", purgableSWFImages[i].image->GetName() );
			purgableSWFImages[i].image->PurgeImage();
			purgableSWFImages[i].image = NULL;
		}
	}
}

idRandom2 & idSWF::GetRandom() {
	return swfRandom;
}

void idSWF::AllocateEmitter( idSoundWorld * soundWorld ) {
	if ( soundEmitter == NULL && soundWorld != NULL ) {
		soundEmitter = soundWorld->AllocSoundEmitter();
	}
}

void idSWF::ClearEmitter( bool instant ) {
	if ( soundEmitter != NULL ) {
		soundEmitter->Free( instant );
		soundEmitter = NULL;
	}
}

void idSWF::SetListener( int listenerId ) {
	if ( soundEmitter != NULL ) {
		soundEmitter->UpdateEmitter( NULL, NULL, NULL, listenerId );
	}
}

int idSWF::FindSpriteOrphanIndex( const idSWFSpriteInstance * spriteInstance ) const {
	for ( int i = 0; i < orphanedSprites.Num(); i++ ) {
		if ( orphanedSprites[i].spriteInstance == spriteInstance ) {
			return i;
		}
	}
	return -1;
}

int idSWF::FindTextOrphanIndex( const idSWFTextInstance * textInstance ) const {
	for ( int i = 0; i < orphanedTexts.Num(); i++ ) {
		if ( orphanedTexts[i].textInstance == textInstance ) {
			return i;
		}
	}
	return -1;
}

idSWFSpriteInstance * idSWF::ExtractSpriteFromOrphanage( const idStr & name, const idSWFSprite * sprite, int depth, const idSWFSpriteInstance * parent ) {
	for ( int i = 0; i < orphanedSprites.Num(); i++ ) {
		orphanedSprite_t & orphan = orphanedSprites[i];
		idSWFSpriteInstance * instance = orphan.spriteInstance;
		if ( instance->parent != parent || instance->sprite != sprite ) {
			continue;
		}
		const bool match = instance->name.IsEmpty() ? instance->depth == depth : idStr::Cmp( instance->name.c_str(), name.c_str() ) == 0;
		if ( !match ) {
			continue;
		}
		++c_SpriteInstanceAdoptions;
		if ( orphan.wasPlaying ) {
			instance->Play();
		} else {
			instance->Stop();
		}
		orphanedSprites.RemoveIndex( i );
		return instance;
	}
	return NULL;
}

idSWFTextInstance * idSWF::ExtractTextFromOrphanage( const idStr & name, idSWFEditText * editText, int depth, const idSWFSpriteInstance * parent ) {
	for ( int i = 0; i < orphanedTexts.Num(); i++ ) {
		idSWFTextInstance * instance = orphanedTexts[i].textInstance;
		if ( instance->parent != parent ) {
			continue;
		}
		const bool match = instance->name.IsEmpty() ? instance->depth == depth : idStr::Cmp( instance->name.c_str(), name.c_str() ) == 0;
		if ( !match ) {
			continue;
		}
		++c_TextInstanceAdoptions;
		instance->editText = editText;
		instance->ReInit();
		orphanedTexts.RemoveIndex( i );
		return instance;
	}
	return NULL;
}

void idSWF::AddSpriteOrphan( idSWFSpriteInstance * spriteInstance ) {
	if ( spriteInstance == NULL || FindSpriteOrphanIndex( spriteInstance ) != -1 ) {
		idLib::Warning( "SWF: Sprite Instance is NULL or already exists on the orphan list" );
		return;
	}
	orphanedSprite_t * orphan = orphanedSprites.Alloc();
	orphan->spriteInstance = spriteInstance;
	orphan->wasPlaying = spriteInstance->isPlaying;
	++c_SpriteInstanceOrphans;
}

void idSWF::AddTextOrphan( idSWFTextInstance * textInstance ) {
	if ( textInstance == NULL || FindTextOrphanIndex( textInstance ) != -1 ) {
		idLib::Warning( "SWF: Text Instance is NULL or already exists on the orphan list" );
		return;
	}
	orphanedText_t * orphan = orphanedTexts.Alloc();
	orphan->textInstance = textInstance;
	++c_TextInstanceOrphans;
}

void idSWF::PurgeOrphanage() {
	for ( int i = 0; i < orphanedSprites.Num(); i++ ) {
		spriteInstanceAllocator.Free( orphanedSprites[i].spriteInstance );
	}
	for ( int i = 0; i < orphanedTexts.Num(); i++ ) {
		textInstanceAllocator.Free( orphanedTexts[i].textInstance );
	}
	orphanedSprites.Clear();
	orphanedTexts.Clear();
}

/*
===================
idSWF::Activate
when a SWF is deactivated, it rewinds the timeline back to the start
===================
*/
void idSWF::Activate( bool b ) {
	if ( !isActive && b ) {
		inhibitControl = false;
		lastRenderTime = Sys_Milliseconds();

		mainspriteInstance->FreeDisplayList();
		mainspriteInstance->Play();
		mainspriteInstance->Run();
		mainspriteInstance->RunActions();
	}
	isActive = b;
}

/*
===================
idSWF::InhibitControl
===================
*/
bool idSWF::IsPlayerControlInhibited() {
	if ( !IsLoaded() || !IsActive() ) {
		return false;
	}
	return ( inhibitControl && useInhibtControl );
}

/*
===================
idSWF::PlaySound
===================
*/
int idSWF::PlaySound( const idSoundShader * soundShader, soundChannel_t channel, bool blocking ) {
	if ( !IsActive() ) {
		return -1;
	}
	if ( soundEmitter == NULL ) {
		idLib::Warning( "idSWF::PlaySound: No playing sound world on soundSystem!" );
		return -1;
	}
	soundShaderParms_t parms = {};
	parms.soundChannel = channel;
	parms.groups = ( channel == SND_CHANNEL_MUSIC1 || channel == SND_CHANNEL_MUSIC2 || channel == SND_CHANNEL_MUSIC3 ) ? SSG_MUSIC_MENU : SSG_UI;
	if ( blocking ) {
		parms.soundShaderFlags = static_cast< soundShaderFlags_t >( parms.soundShaderFlags | SSF_BLOCK_ON_LOAD );
	}
	return soundEmitter->StartSound( channel, soundShader, &parms );
}

int idSWF::PlaySound( const char * sound, soundChannel_t channel, bool blocking ) {
	if ( !IsActive() ) {
		return -1;
	}
	if ( soundEmitter == NULL ) {
		idLib::Warning( "idSWF::PlaySound: No playing sound world on soundSystem!" );
		return -1;
	}
	if ( sound == NULL ) {
		return PlaySound( static_cast< const idSoundShader * >( NULL ), channel, blocking );
	}
	const idSoundShader * soundShader = declManager->FindSound( sound, true );
	return PlaySound( soundShader, channel, blocking );
}

/*
===================
idSWF::PlaySound
===================
*/
void idSWF::StopSound( soundChannel_t channel ) {
	if ( soundEmitter != NULL ) {
		soundEmitter->StopSound( channel );
	} else {
		idLib::Warning( "idSWF::StopSound: No playing sound world on soundSystem!" );
	}
}

/*
===================
idSWF::idSWFScriptFunction_inhibitControl::Call
===================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_inhibitControl::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	pThis->inhibitControl = parms[0].ToBool();
	return idSWFScriptVar();
}

/*
===================
idSWF::idSWFScriptFunction_inhibitControl::Call
===================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_useInhibit::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	pThis->useInhibtControl = parms[0].ToBool();
	return idSWFScriptVar();
}

/*
===================
idSWF::idSWFScriptFunction_deactivate::Call
===================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_deactivate::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	pThis->Activate( false );
	return idSWFScriptVar();
}

/*
===================
idSWF::idSWFScriptFunction_precacheSound::Call
===================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_precacheSound::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	const idSoundShader * soundShader = declManager->FindSound( parms[0].ToString(), true );
	return soundShader->GetName();
}

/*
===================
idSWF::idSWFScriptFunction_playSound::Call
===================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_playSound::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	soundChannel_t channel = SND_CHANNEL_ANY;
	// specific channel passed in
	if ( parms.Num() > 1 ) {
		channel = static_cast< soundChannel_t >( parms[1].ToInteger() );
	}

	pThis->PlaySound( parms[0].ToString(), channel );

	return idSWFScriptVar();
}

/*
===================
idSWF::idSWFScriptFunction_stopSounds::Call
===================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_stopSounds::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {

	soundChannel_t channel = SND_CHANNEL_ANY;
	if ( parms.Num() == 1 ) {
		channel = static_cast< soundChannel_t >( parms[0].ToInteger() );
	}

	if ( pThis->soundEmitter != NULL ) {
		pThis->soundEmitter->StopSound( channel );
	} else {
		idLib::Warning( "No playing sound world on soundSystem in swf play sound!" );
	}

	return idSWFScriptVar();
}

/*
========================
idSWFScriptFunction_GetPlatform::Call
========================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_getPlatform::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	return pThis->GetPlatform();
}

/*
========================
idSWFScriptFunction_GetPlatform::Call
========================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_getTruePlatform::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	return idSWFScriptVar();
}

idSWFScriptVar idSWF::idSWFScriptFunction_isMultiplayer::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	return com_multiplayer.GetBool();
}


/*
========================
idSWFScriptFunction_GetPlatform::Call
========================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_strReplace::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {

	if ( parms.Num() != 3 ) {
		return "";
	}

	idStr str = parms[0].ToString();
	idStr repString = parms[1].ToString();
	idStr val = parms[2].ToString();
	str.Replace( repString, val );

	return str;
}

/*
========================
idSWFScriptFunction_GetPlatform::Call
========================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_getLocalString::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {

	if ( parms.Num() == 0 ) {
		return idSWFScriptVar();
	}

	idStr val = idLocalization::GetString( parms[0].ToString() );
	return val; 
}

/*
========================
idSWF::UseCircleForAccept
========================
*/
bool idSWF::UseCircleForAccept() {
	return false;
}

/*
========================
idSWF::GetPlatform
========================
*/
int	idSWF::GetPlatform() {
	if ( swf_platformOverride.GetInteger() >= SWF_PLATFORM_360 && swf_platformOverride.GetInteger() < SWF_NUM_PLATFORMS ) {
		return swf_platformOverride.GetInteger();
	}
	if ( in_useJoystick.GetBool() ) {
		return 0;
	}

	return 2;
}

void idSWF::RegisterSWFResources( const char * filename ) {
	const int startTime = Sys_Milliseconds();
	idSWF * swf = new ( TAG_SWF ) idSWF( filename, NULL, true );
	delete swf;
	idLib::Printf( "idSWF::RegisterSWFResources %s took %d ms\n", filename, Sys_Milliseconds() - startTime );
}

idSWFScriptVar idSWF::idSWFScriptFunction_isJapanese::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	return sys_langJapanese.GetBool();
}

/*
========================
idSWFScriptFunction_swapPS3Buttons::Call
========================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_swapPS3Buttons::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	return pThis->UseCircleForAccept();
}

/*
========================
idSWFScriptFunction_getCVarInteger::Call
========================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_getCVarInteger::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	return cvarSystem->GetCVarInteger( parms[0].ToString() );
}

/*
========================
idSWFScriptFunction_setCVarInteger::Call
========================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_setCVarInteger::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	cvarSystem->SetCVarInteger( parms[0].ToString(), parms[1].ToInteger() );
	return idSWFScriptVar();
}

/*
===================
idSWF::idSWFScriptFunction_acos::Call
===================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_acos::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	if ( parms.Num() != 1 ) {
		return idSWFScriptVar();
	}
	return idMath::ACos( parms[0].ToFloat() );
}

/*
===================
idSWF::idSWFScriptFunction_cos::Call
===================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_cos::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	if ( parms.Num() != 1 ) {
		return idSWFScriptVar();
	}
	return idMath::Cos( parms[0].ToFloat() );
}

/*
===================
idSWF::idSWFScriptFunction_sin::Call
===================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_sin::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	if ( parms.Num() != 1 ) {
		return idSWFScriptVar();
	}
	return ( idMath::Sin( parms[0].ToFloat() ) );
}

/*
===================
idSWF::idSWFScriptFunction_round::Call
===================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_round::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	if ( parms.Num() != 1 ) {
		return idSWFScriptVar();
	}
	int value = idMath::Ftoi( parms[0].ToFloat() + 0.5f );
	return value;
}

/*
===================
idSWF::idSWFScriptFunction_pow::Call
===================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_pow::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	if ( parms.Num() != 2 ) {
		return idSWFScriptVar();
	}	

	float value = parms[0].ToFloat();
	float power = parms[1].ToFloat();
	return ( idMath::Pow( value, power ) );
}

/*
===================
idSWF::idSWFScriptFunction_pow::Call
===================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_sqrt::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	if ( parms.Num() != 1 ) {
		return idSWFScriptVar();
	}	

	float value = parms[0].ToFloat();
	return ( idMath::Sqrt( value ) );
}

/*
===================
idSWF::idSWFScriptFunction_abs::Call
===================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_abs::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	if ( parms.Num() != 1 ) {
		return idSWFScriptVar();
	}	

	float value = idMath::Fabs( parms[0].ToFloat() );
	return value;
}

/*
===================
idSWF::idSWFScriptFunction_rand::Call
===================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_rand::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	float min = 0.0f;
	float max = 1.0f;
	switch ( parms.Num() ) {
	case 0:
		break;
	case 1:
		max = parms[0].ToFloat();
		break;
	default:
		min = parms[0].ToFloat();
		max = parms[1].ToFloat();
		break;
	}
	return min + pThis->GetRandom().RandomFloat() * ( max - min );
}

/*
========================
idSWFScriptFunction_floor::Call
========================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_floor::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	if ( parms.Num() != 1 || !parms[0].IsNumeric() ) {
		idLib::Warning( "Invalid parameters specified for floor" );
		return idSWFScriptVar();
	}

	float num = parms[0].ToFloat();

	return idSWFScriptVar( idMath::Floor( num ) );
}

/*
========================
idSWFScriptFunction_ceil::Call
========================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_ceil::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	if ( parms.Num() != 1 || !parms[0].IsNumeric() ) {
		idLib::Warning( "Invalid parameters specified for ceil" );
		return idSWFScriptVar();
	}

	float num = parms[0].ToFloat();

	return idSWFScriptVar( idMath::Ceil( num ) );
}

/*
========================
idSWFScriptFunction_toUpper::Call
========================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_toUpper::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	if ( parms.Num() != 1 || !parms[0].IsString() ) {
		idLib::Warning( "Invalid parameters specified for toUpper" );
		return idSWFScriptVar();
	}

	idStr val = idLocalization::GetString( parms[0].ToString() );
	val.ToUpper();
	return val;
}

/*
===================
idSWF::idSWFScriptFunction_shortcutKeys_clear::Call
===================
*/
idSWFScriptVar idSWF::idSWFScriptFunction_shortcutKeys_clear::Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) {
	idSWFScriptObject * object = pThis->shortcutKeys;
	object->Clear();
	object->Set( "clear", this );
	object->Set( "JOY1", "ENTER" );
	object->Set( "JOY2", "BACKSPACE" );
	object->Set( "JOY3", "START" );
	object->Set( "JOY5", "LB" );
	object->Set( "JOY6", "RB" );
	object->Set( "JOY9", "START" );
	object->Set( "JOY10", "BACKSPACE" );
	object->Set( "JOY_DPAD_UP", "UP" );
	object->Set( "JOY_DPAD_DOWN", "DOWN" );
	object->Set( "JOY_DPAD_LEFT", "LEFT" );
	object->Set( "JOY_DPAD_RIGHT", "RIGHT" );
	object->Set( "JOY_STICK1_UP", "STICK1_UP" );
	object->Set( "JOY_STICK1_DOWN", "STICK1_DOWN" );
	object->Set( "JOY_STICK1_LEFT", "STICK1_LEFT" );
	object->Set( "JOY_STICK1_RIGHT", "STICK1_RIGHT" );
	object->Set( "JOY_STICK2_UP", "STICK2_UP" );
	object->Set( "JOY_STICK2_DOWN", "STICK2_DOWN" );
	object->Set( "JOY_STICK2_LEFT", "STICK2_LEFT" );
	object->Set( "JOY_STICK2_RIGHT", "STICK2_RIGHT" );
	object->Set( "KP_ENTER", "ENTER" );
	object->Set( "MWHEELDOWN", "MWHEEL_DOWN" );
	object->Set( "MWHEELUP", "MWHEEL_UP" );
	object->Set( "K_TAB", "TAB" );


	// FIXME: I'm an RTARD and didn't realize the keys all have "ARROW" after them
	object->Set( "LEFTARROW", "LEFT" );
	object->Set( "RIGHTARROW", "RIGHT" );
	object->Set( "UPARROW", "UP" );
	object->Set( "DOWNARROW", "DOWN" );


	return idSWFScriptVar();
}

idSWFScriptVar idSWF::idSWFScriptNativeVar_blackbars::Get( idSWFScriptObject * object ) {
	return pThis->blackbars;
}

void idSWF::idSWFScriptNativeVar_blackbars::Set( idSWFScriptObject * object, const idSWFScriptVar & value ) {
	pThis->blackbars = value.ToBool();
}

idSWFScriptVar idSWF::idSWFScriptNativeVar_crop::Get( idSWFScriptObject * object ) {
	return pThis->crop;
}

void idSWF::idSWFScriptNativeVar_crop::Set( idSWFScriptObject * object, const idSWFScriptVar & value ) {
	pThis->crop = value.ToBool();
}

idSWFScriptVar idSWF::idSWFScriptNativeVar_automaticRescale::Get( idSWFScriptObject * object ) {
	return pThis->automaticRescale;
}

void idSWF::idSWFScriptNativeVar_automaticRescale::Set( idSWFScriptObject * object, const idSWFScriptVar & value ) {
	pThis->automaticRescale = value.ToBool();
}
