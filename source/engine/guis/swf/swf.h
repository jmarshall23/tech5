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
#ifndef __SWF_H__
#define __SWF_H__

#include "swf_enums.h"
#include "swf_types.h"
#include "swf_bitstream.h"
#include "swf_scriptvar.h"
#include "swf_sprites.h"
#include "swf_scriptobject.h"
#include "swf_parmlist.h"
#include "swf_scriptfunction.h"
#include "swf_spriteinstance.h"
#include "swf_shapeparser.h"
#include "swf_textinstance.h"

class idSWFDictionaryEntry {
public:
	idSWFDictionaryEntry();
	~idSWFDictionaryEntry();
	idSWFDictionaryEntry & operator=( idSWFDictionaryEntry & other );

	swfDictType_t		type;
	const idMaterial *	material;
	idSWFShape *		shape;
	idSWFSprite *		sprite;
	idSWFFont *			font;
	idSWFText *			text;
	idSWFEditText *		edittext;

	idVec2i				imageSize;
	idVec2i				imageAtlasOffset;
	// the compressed images are normalize to reduce compression artifacts,
	// color must be scaled down by this
	idVec4				channelScale;
};

struct purgableSwfImage_t {
	purgableSwfImage_t() { image = NULL; swfFrameNum = 0; }
	idImage * image;
	unsigned swfFrameNum;
};

/*
================================================
This class handles loading and rendering SWF files
================================================
*/
class idSWF {
public:
	enum followBorder_t {
		FOLLOW_NONE = -1,
		FOLLOW_TOPLEFT = 0,
		FOLLOW_TOPCENTER,
		FOLLOW_TOPRIGHT,
		FOLLOW_CENTERLEFT,
		FOLLOW_CENTERCENTER,
		FOLLOW_CENTERRIGHT,
		FOLLOW_BOTTOMLEFT,
		FOLLOW_BOTTOMCENTER,
		FOLLOW_BOTTOMRIGHT
	};

	idSWF( const char * filename, idSoundWorld * soundWorld = NULL, bool atlasPurgable = true );
	~idSWF();

	bool	IsLoaded() { return ( frameRate > 0 ); }
	bool	IsActive() { return isActive; }
	void	Activate( bool b );
	
	const char * GetName() { return filename.c_str(); }

	void Pause() { mainspriteInstance->Stop(); paused = true; }
	void Resume() { mainspriteInstance->Play(); paused = false; }
	bool IsPaused() { return paused; }
	void SetPausedRender( bool valid ) { pausedRender = valid; }
	bool GetPausedRender() { return pausedRender; } 

	void Render( idRenderModelGui * gui, int time = 0, bool isSplitscreen = false );
	bool HandleEvent( const sysEvent_t * event );
	bool IsPlayerControlInhibited();
	bool InhibitControl() { return IsPlayerControlInhibited(); }
	void ForceInhibitControl( bool val ) { inhibitControl = val; }

	void SetGlobal( const char * name, const idSWFScriptVar & value ) { globals->Set( name, value ); }
	void SetGlobalNative( const char * name, idSWFScriptNativeVariable * native ) { globals->SetNative( name, native ); }
	idSWFScriptVar GetGlobal( const char * name ) { return globals->Get( name ); }
	idSWFScriptObject & GetRootObject() { assert( mainspriteInstance->GetScriptObject() != NULL ); return *( mainspriteInstance->GetScriptObject() ); }

	void Invoke( const char *  functionName, const idSWFParmList & parms );
	void Invoke( const char *  functionName, const idSWFParmList & parms, bool & functionExists );

	void AllocateEmitter( idSoundWorld * soundWorld );
	void ClearEmitter( bool instant );
	void SetListener( int listenerId );
	int PlaySound( const idSoundShader * soundShader, soundChannel_t channel, bool blocking = false );
	int PlaySound( const char * sound, soundChannel_t channel, bool blocking = false );
	void StopSound( soundChannel_t channel );

	float GetFrameWidth() const { return frameWidth; }
	float GetFrameHeight() const { return frameHeight; }

	int GetMouseX() { return mouseX; }
	int GetMouseY() { return mouseY; }

	bool UseCircleForAccept();

	void SetSWFScale( float scale ) { swfScale = scale; }

	idRandom2 & GetRandom();

	int	GetPlatform();

	//----------------------------------
	// SWF_Dictionary.cpp
	//----------------------------------
	idSWFDictionaryEntry *	AddDictionaryEntry( int characterID, swfDictType_t type );
	idSWFDictionaryEntry *	FindDictionaryEntry( int characterID, swfDictType_t type );
	idSWFDictionaryEntry *	FindDictionaryEntry( int characterID );

	idSWFDictionaryEntry *	GetDictionaryEntry( int index ) { return &dictionary[ index ];  }
	int	GetNumDictionaryEntry() { return dictionary.Num(); }

	idSWFScriptObject * HitTest( idSWFSpriteInstance * spriteInstance, const swfRenderState_t & renderState, int x, int y, idSWFScriptObject * parentObject );

	static void MarkImageForPurging( idImage * image );
	static void RemoveImgFromPurgableList( idImage * image );
	static void PurgeUnusedImages();
	static void ForcePurgeImages();
	static void RegisterSWFResources( const char * filename );
	bool LoadAtlasImage( bool force );
	void CreateAltasImageAndMaterial();

private:
	idAtomicString	filename;
	uint32			timestamp;
	bool			isActive;
	bool			inhibitControl;
	bool			useInhibtControl;
	bool			pausedRender;
	float			frameWidth;
	float			frameHeight;
	uint16			frameRate;
	float			renderBorder;
	float			swfScale;

	int				userDeviceNumber;
	int				lastRenderTime;
	bool			mouseEnabled;
	bool			useMouse;
	idSWFScriptObject * mouseObject;
	idSWFScriptObject * hoverObject;

	bool			blackbars;
	bool			crop;
	bool			paused;
	bool			hasHitObject;
	bool			automaticRescale;

	idSWFSprite *			mainsprite;
	idSWFSpriteInstance *	mainspriteInstance;

	idSWFScriptObject *		globals;
	idSWFScriptObject *		shortcutKeys;

	idSoundEmitter *		soundEmitter;
	idAtomicString		atlasTextureName;
	const idMaterial *		atlasMaterial;
	idImage *				atlasImage;
	bool					atlasPurgable;
	int					atlasWidth;
	int					atlasHeight;
	idFile *				atlasFile;

	idBlockAlloc< idSWFSpriteInstance, 16, TAG_SWF >	spriteInstanceAllocator;
	idBlockAlloc< idSWFTextInstance, 16, TAG_SWF >	textInstanceAllocator;

	struct orphanedSprite_t {
		idSWFSpriteInstance * spriteInstance;
		bool wasPlaying;
	};
	struct orphanedText_t {
		idSWFTextInstance * textInstance;
	};
	idList< orphanedSprite_t, TAG_SWF > orphanedSprites;
	idList< orphanedText_t, TAG_SWF > orphanedTexts;
	int c_TextInstanceAdoptions;
	int c_TextInstanceOrphans;
	int c_SpriteInstanceAdoptions;
	int c_SpriteInstanceOrphans;

#define SWF_NATIVE_FUNCTION_SWF_DECLARE( x ) \
	class idSWFScriptFunction_##x : public idSWFScriptFunction_Nested< idSWF > { \
	public: \
		idSWFScriptVar Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ); \
	} scriptFunction_##x;

	SWF_NATIVE_FUNCTION_SWF_DECLARE( shortcutKeys_clear );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( deactivate );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( inhibitControl );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( useInhibit );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( precacheSound );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( playSound );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( stopSounds );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( getPlatform );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( getTruePlatform );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( getLocalString );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( isMultiplayer );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( swapPS3Buttons );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( getCVarInteger );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( setCVarInteger );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( strReplace );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( isJapanese );

	SWF_NATIVE_FUNCTION_SWF_DECLARE( acos );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( cos );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( sin );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( round );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( pow );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( sqrt );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( abs );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( rand );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( floor );
	SWF_NATIVE_FUNCTION_SWF_DECLARE( ceil );

	SWF_NATIVE_FUNCTION_SWF_DECLARE( toUpper );

	SWF_NATIVE_VAR_DECLARE_NESTED_READONLY( platform, idSWFScriptFunction_getPlatform, Call( object, idSWFParmList() ) );
	SWF_NATIVE_VAR_DECLARE_NESTED( blackbars, idSWF );
	SWF_NATIVE_VAR_DECLARE_NESTED( crop, idSWF );
	SWF_NATIVE_VAR_DECLARE_NESTED( automaticRescale, idSWF );

	class idSWFScriptFunction_Object : public idSWFScriptFunction {
	public:
		idSWFScriptVar	Call( idSWFScriptObject * thisObject, const idSWFParmList & parms ) { return idSWFScriptVar(); }
		void			AddRef() { }
		void			Release() { }
		idSWFScriptObject * GetPrototype() { return &object; }
		void			SetPrototype( idSWFScriptObject * _object ) { assert( false ); }
		idSWFScriptObject object;
	} scriptFunction_Object;

	idList< idSWFDictionaryEntry, TAG_SWF >	dictionary;

	struct keyButtonImages_t {

		keyButtonImages_t() {
			key = "";
			xbImage = "";
			psImage = "";
			width = 0;
			height = 0; 
			baseline = 0;
		}

		keyButtonImages_t( const char* _key, const char* _xbImage, const char* _psImage, int w, int h, int _baseline ) {
			key = _key;
			xbImage = _xbImage;
			psImage = _psImage;
			width = w;
			height = h; 
			baseline = _baseline;
		}

		const char * key;
		const char * xbImage;
		const char * psImage;
		int width;
		int height;
		int baseline;
	};
	idList< keyButtonImages_t, TAG_SWF > tooltipButtonImage;

	struct tooltipIcon_t {
		tooltipIcon_t() {
			startIndex = -1;
			endIndex = -1;
			material = NULL;
			imageWidth = 0;
			imageHeight = 0;
			baseline = 0;
		};

		int					startIndex;
		int					endIndex;
		const idMaterial *	material;
		short				imageWidth;
		short				imageHeight;
		int					baseline;
	};
	idList< tooltipIcon_t, TAG_SWF > tooltipIconList;

	const idMaterial * guiSolid;
	const idMaterial * guiStencilIncr;
	const idMaterial * guiStencilDecr;
	const idMaterial * guiCursor_arrow;
	const idMaterial * guiCursor_hand;
	const idMaterial * white;

private:
	friend class idSWFSprite;
	friend class idSWFSpriteInstance;
	friend class idSWFTextInstance;
	friend void listSWF_f( const idCmdArgs & args );
	friend void printSWFVar_f( const idCmdArgs & args );
	friend void reportSWFMemory_f( const idCmdArgs & args );
	friend void reportMainMenuFonts_f( const idCmdArgs & args );

	static idList< idSWF *, TAG_SWF > allSWFObjects;
	static purgableSwfImage_t purgableSWFImages[ 8 ];
	static uint32 swfFrameNum;
	static int mouseX;
	static int mouseY;
	static bool isMouseInClientArea;

	int FindSpriteOrphanIndex( const idSWFSpriteInstance * spriteInstance ) const;
	int FindTextOrphanIndex( const idSWFTextInstance * textInstance ) const;
	idSWFSpriteInstance * ExtractSpriteFromOrphanage( const idStr & name, const idSWFSprite * sprite, int depth, const idSWFSpriteInstance * parent );
	idSWFTextInstance * ExtractTextFromOrphanage( const idStr & name, idSWFEditText * editText, int depth, const idSWFSpriteInstance * parent );
	void AddSpriteOrphan( idSWFSpriteInstance * spriteInstance );
	void AddTextOrphan( idSWFTextInstance * textInstance );
	void PurgeOrphanage();

	bool			LoadSWF( const char * fullpath );
	bool			LoadBinary( const char * bfilename );
	void			WriteBinary( const char * bfilename );

	//----------------------------------
	// SWF_Shapes.cpp
	//----------------------------------
	void			DefineShape( idSWFBitStream & bitstream );
	void			DefineShape2( idSWFBitStream & bitstream );
	void			DefineShape3( idSWFBitStream & bitstream );
	void			DefineShape4( idSWFBitStream & bitstream );

	//----------------------------------
	// SWF_Sprites.cpp
	//----------------------------------
	void			DefineSprite( idSWFBitStream & bitstream );

	//----------------------------------
	// SWF_Sounds.cpp
	//----------------------------------
	void			DefineSound( idSWFBitStream & bitstream );

	//----------------------------------
	// SWF_Render.cpp
	//----------------------------------
	void			DrawStretchPic( float x, float y, float w, float h, float s1, float t1, float s2, float t2, const idMaterial *material );
	void			DrawStretchPic( const idVec4 & topLeft, const idVec4 & topRight, const idVec4 & bottomRight, const idVec4 & bottomLeft, const idMaterial * material );
	void			RenderSprite( idRenderModelGui * gui, idSWFSpriteInstance * sprite, const swfRenderState_t & renderState, int time, bool isSplitscreen = false );
	void			RenderMask( idRenderModelGui * gui, const swfDisplayEntry_t * mask, const swfRenderState_t & renderState, const idMaterial * material );
	void			RenderShape( idRenderModelGui * gui, const idSWFShape * shape, const swfRenderState_t & renderState );
	void			RenderMorphShape( idRenderModelGui * gui, const idSWFShape* shape, const swfRenderState_t & renderState );
	void			RenderRadial( idRenderModelGui * gui, idSWFSpriteInstance * sprite, const swfRenderState_t & renderState, int time, bool isSplitscreen );
	void			DrawEditCursor( idRenderModelGui * gui, float x, float y, float w, float h, const swfMatrix_t & matrix );
	void			RenderEditText( idRenderModelGui * gui, idSWFTextInstance * textInstance, const swfRenderState_t & renderState, int time, bool isSplitscreen = false );
	uint64			GLStateForRenderState( const swfRenderState_t & renderState );
	void			FindTooltipIcons( idStr * text, int bindset, int deviceNum );

	//----------------------------------
	// SWF_Image.cpp
	//----------------------------------

	class idDecompressJPEG {
	public:
		idDecompressJPEG();
		~idDecompressJPEG();

		byte * Load( const byte * input, int inputSize, int & width, int & height );

	private:
		void * vinfo;
	};

	idDecompressJPEG	jpeg;

	void			LoadImageA( int characterID, const byte * imageData, int width, int height );

	void			JPEGTables( idSWFBitStream & bitstream );
	void			DefineBits( idSWFBitStream & bitstream );
	void			DefineBitsJPEG2( idSWFBitStream & bitstream );
	void			DefineBitsJPEG3( idSWFBitStream & bitstream );
	void			DefineBitsLossless( idSWFBitStream & bitstream );
	void			DefineBitsLossless2( idSWFBitStream & bitstream );


	// per-swf image atlas
	struct imageToPack_t {
		int	characterID;
		idVec2i	trueSize;	// in texels
		byte * imageData;	// trueSize.x * trueSize.y * 4
		idVec2i	allocSize;	// in DXT tiles, includes a border texel and rounding up to DXT blocks
	};

 	class idSortBlocks : public idSort_Quick< imageToPack_t, idSortBlocks > {
 	public:
 		int Compare( const imageToPack_t & a, const imageToPack_t & b ) const {
 			return ( b.allocSize.x * b.allocSize.y ) - ( a.allocSize.x * a.allocSize.y );
 		}
 	};

	idList<imageToPack_t, TAG_SWF>	packImages;	// only used during creation
	void			WriteSwfImageAtlas( const char *filename );

	//----------------------------------
	// SWF_Text.cpp
	//----------------------------------
	void			DefineFont2( idSWFBitStream & bitstream );
	void			DefineFont3( idSWFBitStream & bitstream );
	void			DefineTextX( idSWFBitStream & bitstream, bool rgba );
	void			DefineText( idSWFBitStream & bitstream );
	void			DefineText2( idSWFBitStream & bitstream );
	void			DefineEditText( idSWFBitStream & bitstream );

	//----------------------------------
	// SWF_Zlib.cpp
	//----------------------------------
	bool			Inflate( const byte * input, int inputSize, byte * output, int outputSize );

public:
	//----------------------------------
	// SWF_Names.cpp
	//----------------------------------
	static const char * GetTagName( swfTag_t tag );
	static const char * GetActionName( swfAction_t action );

};

#endif // !__SWF_H__
