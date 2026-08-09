#pragma once

#include "../decls/decltypeinfo.h"
#include "../decls/decltable.h"
#include "../framework/resourcelist.h"
#include "../../shared/idlib/containers/linklist.h"

class idParser;
class idSoundChannel;
class idSoundSample;

enum soundChannel_t : int {
	SND_CHANNEL_ANY = 0,
	SND_CHANNEL_VOICE, SND_CHANNEL_VOICE2,
	SND_CHANNEL_BODY, SND_CHANNEL_BODY2, SND_CHANNEL_BODY3,
	SND_CHANNEL_WEAPON, SND_CHANNEL_WEAPON2, SND_CHANNEL_WEAPON3,
	SND_CHANNEL_WEAPON4, SND_CHANNEL_WEAPON5, SND_CHANNEL_WEAPON6,
	SND_CHANNEL_WEAPON7, SND_CHANNEL_WEAPON8, SND_CHANNEL_WEAPON9,
	SND_CHANNEL_WEAPON_AMBIENT, SND_CHANNEL_WEAPON_AMBIENT2,
	SND_CHANNEL_WEAPON_LOOP, SND_CHANNEL_WEAPON_LOOP_SOUND1,
	SND_CHANNEL_WEAPON_LOOP_SOUND2, SND_CHANNEL_WEAPON_LOOP_LEFT_HAND,
	SND_CHANNEL_WEAPON_LOOP_LH_SOUND1, SND_CHANNEL_WEAPON_LOOP_LH_SOUND2,
	SND_CHANNEL_ITEM, SND_CHANNEL_ITEM2, SND_CHANNEL_BREATHE,
	SND_CHANNEL_HEARTBEAT1, SND_CHANNEL_HEARTBEAT2,
	SND_CHANNEL_GENERIC_AMBIENT, SND_CHANNEL_WEAPON_ALERT,
	SND_CHANNEL_ENVIRONMENTAL_HAZARD, SND_CHANNEL_ENGINE_IDLE,
	SND_CHANNEL_ENGINE_LOADED, SND_CHANNEL_ENGINE_UNLOADED,
	SND_CHANNEL_ENGINE_DAMAGE, SND_CHANNEL_ENGINE_EXPLOSION,
	SND_CHANNEL_ENGINE_FIRE, SND_CHANNEL_SURFACE_ROLL,
	SND_CHANNEL_SURFACE_SLIDE, SND_CHANNEL_SURFACE_SCRAPE,
	SND_CHANNEL_SURFACE_TIRE_SCRAPE, SND_CHANNEL_SURFACE_BODY_SCRAPE,
	SND_CHANNEL_WIND, SND_CHANNEL_WIND2, SND_CHANNEL_WIND3,
	SND_CHANNEL_WIND4, SND_CHANNEL_CRASH, SND_CHANNEL_COLLIDE,
	SND_CHANNEL_EXPLODE, SND_CHANNEL_BOOST, SND_CHANNEL_BOOST2,
	SND_CHANNEL_BOOST3, SND_CHANNEL_WATER, SND_CHANNEL_STEERING,
	SND_CHANNEL_MUSIC1, SND_CHANNEL_MUSIC2, SND_CHANNEL_MUSIC3,
	SND_CHANNEL_DOOR, SND_CHANNEL_WEAPON_1, SND_CHANNEL_WEAPON_2,
	SND_CHANNEL_TIREWOBBLE, SND_CHANNEL_TIRE_BUMP,
	SND_CHANNEL_VEH_SHIFT_DOWN, SND_CHANNEL_VEH_SHIFT_UP,
	SND_CHANNEL_VEH_BRAKE, SND_CHANNEL_ALERT, SND_CHANNEL_REPAIR,
	SND_CHANNEL_THROW_ACTOR, SND_CHANNEL_AMBIENT, SND_CHANNEL_DAMAGE,
	SND_CHANNEL_DEBUG, SND_CHANNEL_FX, SND_CHANNEL_QUAD_FIRE_LOOP,
	SND_CHANNEL_QUAD_FIRE, SND_CHANNEL_QUAD_FIRE2, SND_CHANNEL_QUAD_FIRE3,
	SND_CHANNEL_AI_STALK_ENEMY, SND_CHANNEL_JET_PACK,
	SND_CHANNEL_SYNC_MELEE_1, SND_CHANNEL_SYNC_MELEE_2,
	SND_CHANNEL_SYNC_MELEE_3, SND_CHANNEL_LOW_HEALTH,
	SND_CHANNEL_SPECIAL_FIRE_LOOP, SND_CHANNEL_SPECIAL_FIRE,
	SND_CHANNEL_SPECIAL_FIRE2, SND_CHANNEL_SPECIAL_FIRE3,
	SND_CHANNEL_ABILITY, SND_CHANNEL_GAMECHALLENGE,
	SND_CHANNEL_GAMECHALLENGE_LOOP,
	NUM_SND_CHANNELS
};

enum soundShaderFlags_t : int {
	SSF_PRIVATE_SOUND = 0x00000001, SSF_ANTI_PRIVATE_SOUND = 0x00000002,
	SSF_NO_OCCLUSION = 0x00000004, SSF_GLOBAL = 0x00000008,
	SSF_OMNIDIRECTIONAL = 0x00000010, SSF_FRONTDIRECTIONAL = 0x00000020,
	SSF_REARDIRECTIONAL = 0x00000040, SSF_ENVIRONMENTAL = 0x00000080,
	SSF_CONEATTENUATION = 0x00000100, SSF_LOOPING = 0x00000200,
	SSF_PLAY_ONCE = 0x00000400, SSF_SEQUENTIAL = 0x00000800,
	SSF_NO_RANDOM_OFFSET = 0x00001000, SSF_AUTO_RESTART = 0x00002000,
	SSF_FLICKER = 0x00004000, SSF_NO_EFFECTS = 0x00008000,
	SSF_FINITE_SPEED_OF_SOUND = 0x00010000, SSF_DISTANCE_LOW_PASS = 0x00020000,
	SSF_LFE = 0x00040000, SSF_DISTANCE_BASED_STEREO = 0x00080000,
	SSF_RANDOM_LOOPING = 0x00100000, SSF_PASS_HDR = 0x00200000,
	SSF_BLOCK_ON_LOAD = 0x00400000, SSF_DOPPLER = 0x00800000,
	SSF_LOOP_FADE_IN = 0x01000000, SSF_LOOP_FADE_OUT = 0x02000000
};

enum soundShaderGroups_t : int {
	SSG_MASTER = 0, SSG_UI = 1, SSG_MUSIC_MENU = 2, SSG_MUSIC_INGAME = 4,
	SSG_SFX_GENERAL = 8, SSG_AMB_CORE = 0x10, SSG_AMB_SPOT = 0x20,
	SSG_EXPLOSIONS = 0x40, SSG_KEY_EVENTS = 0x80, SSG_IMPACTS = 0x100,
	SSG_RICO_BYS = 0x200, SSG_MOVEMENT_AI = 0x400, SSG_MOVEMENT_PL = 0x800,
	SSG_VEH_AI = 0x1000, SSG_VEH_PL = 0x2000, SSG_VEH_COLLISIONS_AI = 0x4000,
	SSG_VEH_COLLISIONS_PL = 0x8000, SSG_WEAPONS_AI = 0x10000,
	SSG_WEAPONS_PL = 0x20000, SSG_SPECIAL_ENEMY_MOVEMENT = 0x40000,
	SSG_SPECIAL_ENEMY_VOICE = 0x80000, SSG_VO_PLAYER = 0x100000,
	SSG_VO_EVENT = 0x200000, SSG_VO_INGAME = 0x400000,
	SSG_VO_RADIO = 0x800000, SSG_VO_BATTLE = 0x1000000
};

enum soundMaxPlaybackType_t : int {
	SMAX_IGNORE, SMAX_REPLACE, SMAX_RESTART, SMAX_KILLFARTHEST
};

enum soundPriority_t : int {
	SPRIORITY_LOW, SPRIORITY_MEDIUM, SPRIORITY_HIGH, SPRIORITY_ULTRA
};

struct randomValue_t {
	float min;
	float max;
	float granularity;
};

struct soundShaderParms_t {
	struct coneAttenuationVars_t { float innerAngle, outerAngle, outerVolume; };
	struct distancesBasedVars_t { float nearMinRange, farMaxRange; };
	struct maxPlayerVars_t { int maxShaders; soundMaxPlaybackType_t playbackType; };

	float minDistance;
	float maxDistance;
	float distanceFactor;
	float wetMinDistanceOffset;
	float wetMaxDistanceOffset;
	coneAttenuationVars_t coneAttenuation;
	distancesBasedVars_t distanceBasedRanges;
	randomValue_t volume;
	float wetVolume;
	randomValue_t pitch;
	float loopFadeInDuration;
	float loopFadeOutDuration;
	float dopplerMultiplier;
	float shakes;
	float minShakeDistance;
	float maxShakeDistance;
	const idDeclTable * shakeFalloff;
	soundShaderGroups_t groups;
	soundChannel_t soundChannel;
	soundShaderFlags_t soundShaderFlags;
	float lowPassMinDistance;
	float lowPassStrength;
	float lfeVolume;
	float centerChannel;
	const idDeclTable * falloff;
	const idDeclTable * wetFalloff;
	float headroom;
	maxPlayerVars_t maxPlay;
	soundPriority_t priority;
};

class idStrSound : public idAtomicString {
public:
	idStrSound() = default;
	explicit idStrSound( const char * text ) : idAtomicString( text ) {}
};

class idSoundShader : public idDeclTypeInfo {
public:
	idSoundShader();
	~idSoundShader() override;
	void Parse( idParser * parser ) override;
	void FreeData() override;
	bool SetImplicitText() override;
	void List() override;
	unsigned int Size() const override;
	idSoundSample * GetNextEntry( bool preTouchData = false );
	int GetMaxLength() const;

	soundShaderParms_t parms;
	idList< idStrSound, 38 > soundFiles;
	idList< idSoundSample *, 38 > entries;
	const idSoundShader * preSound;
	const idSoundShader * postSound;
	const idSoundShader * remoteSound;
	idSoundSample * nextSample;
	idLinkList< idSoundChannel > playingChannels;

	static idDeclInfoTemplate< idSoundShader > resourceList;
};

class idDeclDuck : public idDecl {
public:
	idDeclDuck();
	void Parse( idParser * parser ) override;
	bool RebuildTextSource() override;
	idDeclInfo * GetDeclInfo() const override;
	int layer;
	float groupVolume[ 25 ];
	static idDeclInfoTemplate< idDeclDuck > resourceList;
};
