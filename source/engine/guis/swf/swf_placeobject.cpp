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

int c_PlaceObject2;
int c_PlaceObject3;

#define PlaceFlagHasClipActions		BIT( 7 )
#define PlaceFlagHasClipDepth		BIT( 6 )
#define PlaceFlagHasName			BIT( 5 )
#define PlaceFlagHasRatio			BIT( 4 )
#define PlaceFlagHasColorTransform	BIT( 3 )
#define PlaceFlagHasMatrix			BIT( 2 )
#define PlaceFlagHasCharacter		BIT( 1 )
#define PlaceFlagMove				BIT( 0 )

#define PlaceFlagPad0				BIT( 7 )
#define PlaceFlagPad1				BIT( 6 )
#define PlaceFlagPad2				BIT( 5 )
#define PlaceFlagHasImage			BIT( 4 )
#define PlaceFlagHasClassName		BIT( 3 )
#define PlaceFlagCacheAsBitmap		BIT( 2 )
#define PlaceFlagHasBlendMode		BIT( 1 )
#define PlaceFlagHasFilterList		BIT( 0 )

swfDisplayEntry_t * idSWFSpriteInstance::ExecutePlaceObject2( const placeObject2Data_t & po2 ) {
	swfDisplayEntry_t * display = NULL;
	if ( ( po2.flags & PlaceFlagMove ) != 0 ) {
		display = FindDisplayEntry( po2.depth );
		if ( display == NULL ) {
			idLib::Warning( "ExecutePlaceObject2: trying to modify entry %d, which doesn't exist", po2.depth );
			return NULL;
		}
		if ( po2.characterID >= 0 ) {
			if ( display->spriteInstance != NULL || display->textInstance != NULL ) {
				idLib::Warning( "ExecutePlaceObject2: Trying to change the character of a sprite after it's been created" );
				return NULL;
			}
			idSWFDictionaryEntry * entry = sprite->swf->FindDictionaryEntry( po2.characterID );
			if ( entry != NULL && ( entry->type == SWF_DICT_SPRITE || entry->type == SWF_DICT_EDITTEXT ) ) {
				idLib::Warning( "ExecutePlaceObject2: Trying to change the character of a shape to a sprite" );
				return NULL;
			}
			display->characterID = po2.characterID;
		}
	} else {
		if ( po2.characterID < 0 ) {
			idLib::Warning( "ExecutePlaceObject2: Trying to create a new object without a character" );
			return NULL;
		}
		display = AddDisplayEntry( po2.depth, po2.characterID, po2.name );
		if ( display == NULL ) {
			idLib::Warning( "ExecutePlaceObject2: trying to create a new entry at %d, but an item already exists there", po2.depth );
			return NULL;
		}
	}

	if ( ( po2.flags & PlaceFlagHasMatrix ) != 0 ) {
		display->matrix = po2.matrix;
	}
	if ( ( po2.flags & PlaceFlagHasColorTransform ) != 0 ) {
		display->cxf = po2.cxf;
	}
	if ( ( po2.flags & PlaceFlagHasRatio ) != 0 ) {
		display->ratio = po2.ratio;
	}
	if ( ( po2.flags & PlaceFlagHasName ) != 0 ) {
		if ( po2.characterID < 0 ) {
			idLib::Warning( "ExecutePlaceObject2: Trying to set name of a newly created object" );
			return NULL;
		}
		if ( display->spriteInstance != NULL ) {
			display->spriteInstance->name.Set( po2.name.c_str() );
			scriptObject->Set( po2.name.c_str(), idSWFScriptVar( display->spriteInstance->scriptObject ) );
		} else if ( display->textInstance != NULL ) {
			display->textInstance->name.Set( po2.name.c_str() );
			scriptObject->Set( po2.name.c_str(), idSWFScriptVar( display->textInstance->scriptObject ) );
		}
	}
	if ( ( po2.flags & PlaceFlagHasClipDepth ) != 0 ) {
		display->clipDepth = po2.clipDepth;
	}
	return display;
}

static void ReadPlaceObject2Data( idSWFBitStream & bitstream, idSWFSpriteInstance::placeObject2Data_t & po2 ) {
	po2.flags = bitstream.ReadU8();
	po2.depth = bitstream.ReadU16();
	po2.characterID = ( po2.flags & PlaceFlagHasCharacter ) != 0 ? bitstream.ReadU16() : -1;
	if ( ( po2.flags & PlaceFlagHasMatrix ) != 0 ) {
		bitstream.ReadMatrix( po2.matrix );
	}
	if ( ( po2.flags & PlaceFlagHasColorTransform ) != 0 ) {
		bitstream.ReadColorXFormRGBA( po2.cxf );
	}
	if ( ( po2.flags & PlaceFlagHasRatio ) != 0 ) {
		po2.ratio = bitstream.ReadU16() * ( 1.0f / 65535.0f );
	}
	if ( ( po2.flags & PlaceFlagHasName ) != 0 ) {
		po2.name = bitstream.ReadString();
	}
	if ( ( po2.flags & PlaceFlagHasClipDepth ) != 0 ) {
		po2.clipDepth = bitstream.ReadU16();
	}
}

void idSWFSpriteInstance::PlaceObject2( idSWFBitStream & bitstream ) {
	++c_PlaceObject2;
	placeObject2Data_t po2;
	ReadPlaceObject2Data( bitstream, po2 );
	ExecutePlaceObject2( po2 );
}

void idSWFSpriteInstance::PlaceObject3( idSWFBitStream & bitstream ) {
	++c_PlaceObject3;
	placeObject2Data_t po2;
	po2.flags = bitstream.ReadU8();
	const uint64 flags2 = bitstream.ReadU8();
	po2.depth = bitstream.ReadU16();
	if ( ( flags2 & PlaceFlagHasClassName ) != 0 || ( ( flags2 & PlaceFlagHasImage ) != 0 && ( po2.flags & PlaceFlagHasCharacter ) != 0 ) ) {
		bitstream.ReadString();
	}
	po2.characterID = ( po2.flags & PlaceFlagHasCharacter ) != 0 ? bitstream.ReadU16() : -1;
	if ( ( po2.flags & PlaceFlagHasMatrix ) != 0 ) {
		bitstream.ReadMatrix( po2.matrix );
	}
	if ( ( po2.flags & PlaceFlagHasColorTransform ) != 0 ) {
		bitstream.ReadColorXFormRGBA( po2.cxf );
	}
	if ( ( po2.flags & PlaceFlagHasRatio ) != 0 ) {
		po2.ratio = bitstream.ReadU16() * ( 1.0f / 65535.0f );
	}
	if ( ( po2.flags & PlaceFlagHasName ) != 0 ) {
		po2.name = bitstream.ReadString();
	}
	if ( ( po2.flags & PlaceFlagHasClipDepth ) != 0 ) {
		po2.clipDepth = bitstream.ReadU16();
	}
	if ( ( flags2 & PlaceFlagHasFilterList ) != 0 ) {
		idLib::Warning( "PlaceObject3: has filters" );
		return;
	}
	const bool hasBlendMode = ( flags2 & PlaceFlagHasBlendMode ) != 0;
	const uint16 blendMode = hasBlendMode ? bitstream.ReadU8() : 0;
	swfDisplayEntry_t * display = ExecutePlaceObject2( po2 );
	if ( display != NULL && hasBlendMode ) {
		display->blendMode = static_cast< uint8 >( blendMode );
	}
}

/*
========================
idSWFSpriteInstance::RemoveObject2
========================
*/
void idSWFSpriteInstance::RemoveObject2( idSWFBitStream & bitstream ) {
	RemoveDisplayEntry( bitstream.ReadU16() );
}
