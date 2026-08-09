#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\hands.h
// Recovered logical types: 13
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1070; PDB kind: enum.
enum idHands::handsAction_t : __int32
{
  HANDSACTION_NONE = 0x0,
  HANDSACTION_FIRE = 0x1,
  HANDSACTION_DRYFIRE = 0x2,
  HANDSACTION_RELOAD = 0x3,
  HANDSACTION_AMMOCHANGE = 0x4,
  HANDSACTION_PISTOLWHIP = 0x5,
  HANDSACTION_BRINGDOWN = 0x6,
  HANDSACTION_BRINGUP = 0x7,
  HANDSACTION_THROWITEM = 0x8,
  HANDSACTION_COOKITEM = 0x9,
  HANDSACTION_RETURNTOIDLE = 0xA,
  HANDSACTION_LOWERWEAPON = 0xB,
  HANDSACTION_RAISEWEAPON = 0xC,
  HANDSACTION_BEGINSPRINT = 0xD,
  HANDSACTION_ENDSPRINT = 0xE,
  HANDSACTION_TAKEDOWN = 0xF,
  HANDSACTION_HIDEMOVE = 0x10,
  HANDSACTION_TOGGLEDUALWIELD = 0x11,
  HANDSACTION_TOGGLEFIREMODE = 0x12,
  HANDSACTION_CHARGEWEAPONBATTERY = 0x13,
  HANDSACTION_UPGRADEWEAPON = 0x14,
  HANDSACTION_MAX = 0x15,
};

// IDA Local Type ordinal 1072; PDB kind: enum.
enum idHands::handsState_t : __int32
{
  HS_IDLE = 0x0,
  HS_ZOOM_IDLE = 0x1,
  HS_THROW_IDLE = 0x2,
  HS_TRANSITIONING = 0x3,
  HS_CHARGING = 0x4,
  HS_LASERING = 0x5,
  HS_SPRINTING = 0x6,
  HS_HIDEMOVE = 0x7,
  HS_CHARGEWEAPONBATTERY = 0x8,
  HS_SWIMMING = 0x9,
  HS_SWIMMING_ENTER = 0xA,
  HS_SWIMMING_EXIT = 0xB,
  HS_SWIMMING_LEFT = 0xC,
  HS_SWIMMING_RIGHT = 0xD,
  HS_SWIMMING_UP = 0xE,
  HS_SWIMMING_DOWN = 0xF,
  HS_SWIMMING_FORWARD = 0x10,
  HS_SWIMMING_FORWARD_SPRINT = 0x11,
  HS_SWIMMING_TURN_LEFT = 0x12,
  HS_SWIMMING_TURN_RIGHT = 0x13,
  HS_SWIMMING_SURFACE = 0x14,
  HS_SWIMMING_SUBMERGE = 0x15,
  HS_SWIMMING_LOCKED = 0x16,
  HS_SWIMMING_BACK = 0x17,
  HS_SWIMMING_ARMED = 0x18,
};

// IDA Local Type ordinal 1102; PDB kind: enum.
enum idHands::setRestStateType_t : __int32
{
  SET_RESTSTATE_TOGGLE = 0x0,
  SET_RESTSTATE_REST = 0x1,
  SET_RESTSTATE_COMBAT = 0x2,
};

// IDA Local Type ordinal 1211; PDB kind: enum.
enum __bitmask idHands::handHideReason_t : __int32
{
  HAND_HIDE_GENERIC = 0x1,
  HAND_HIDE_VEHICLE = 0x2,
  HAND_HIDE_ZOOM = 0x4,
  HAND_HIDE_SPECIAL = 0x8,
  HAND_HIDE_SERVER_AUTHORITATIVE = 0x10,
  HAND_HIDE_SPECTATING = 0x20,
  HAND_HIDE_FIRSTPERSONEVENT = 0x40,
  HAND_HIDE_TAKEDOWN = 0x80,
};

// IDA Local Type ordinal 1338; PDB kind: enum.
enum handsTag_t : __int32
{
  HANDSTAG_RIGHT = 0x0,
  HANDSTAG_LEFT = 0x1,
  HANDSTAG_MAX = 0x2,
};

// IDA Local Type ordinal 1339; PDB kind: enum.
enum idHands::handsSwimStroke_t : __int32
{
  SWIMSTROKE_FORWARD = 0x0,
  SWIMSTROKE_SPRINT = 0x1,
  SWIMSTROKE_BACK = 0x2,
  SWIMSTROKE_LEFT = 0x3,
  SWIMSTROKE_RIGHT = 0x4,
  SWIMSTROKE_UP = 0x5,
  SWIMSTROKE_DOWN = 0x6,
  SWIMSTROKE_SURFACE = 0x7,
  SWIMSTROKE_SUBMERGE = 0x8,
  SWIMSTROKE_TURNLEFT = 0x9,
  SWIMSTROKE_TURNRIGHT = 0xA,
};

// IDA Local Type ordinal 1340; PDB kind: enum.
enum idHands::handsTCAnglesBlendState_t : __int32
{
  HANDSTCBLENDSTATE_IN = 0x0,
  HANDSTCBLENDSTATE_IN_FULL = 0x1,
  HANDSTCBLENDSTATE_OUT = 0x2,
  HANDSTCBLENDSTATE_OUT_FULL = 0x3,
};

// IDA Local Type ordinal 1348; PDB kind: enum.
enum idHands::setWeaponModeType_t : __int32
{
  SET_WEAPONMODE_TOGGLE = 0x0,
  SET_WEAPONMODE_PRIMARY = 0x1,
  SET_WEAPONMODE_SECONDARY = 0x2,
};

// IDA Local Type ordinal 1349; PDB kind: enum.
enum idHands::setWeaponDualWieldType_t : __int32
{
  SET_DUALWIELD_TOGGLE = 0x0,
  SET_DUALWIELD_ON = 0x1,
  SET_DUALWIELD_OFF = 0x2,
  SET_DUALWIELD_JUST_CLEAR_LEFT = 0x3,
  SET_DUALWIELD_OFF_AND_REMOVE = 0x4,
};

// IDA Local Type ordinal 1350; PDB kind: enum.
enum idHands::weaponCondition_t : __int32
{
  WEAPONCONDITION_EMPTY_CHAMBER_BOLT_FRONT = 0x0,
  WEAPONCONDITION_EMPTY_CHAMBER_BOLT_BACK = 0x1,
  WEAPONCONDITION_ROUND_IN_CHAMBER = 0x2,
};

// IDA Local Type ordinal 15369; PDB kind: class.
class idHands : public idEventReceiver
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15375.
  virtual idTypeInfo *GetType();
  virtual ~idHands();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);

  idPresentablePlayer *owner;
  idAnimStack animStack;
  idPresentableAnimatedEntity *presentable;
  idAnimWebHands web;
  idAnimWebHands secondaryWeb;
  idRenderModel *testModel;
  int hiddenReasons;
  int usedToHaveHideReasons;
  bool disabled;
  bool shouldDisable;
  bool shouldShowAfterUpdate;
  bool unlinked;
  equipSlot_t pickupSlot;
  idHandsItem rightItem;
  idHandsItem leftItem;
  const idDeclThrowable *throwItem;
  idAngles modelAngles;
  float modelScale;
  idVec3 modelOffset;
  idMat3 modelAxis;
  idAnimEventHandler animEventHandler;
  int lastFriendlyTime;
  idVec3 lockOnPosition;
  idVec3 extraWorldTranslation;
  idMat3 extraWorldRotation;
  bool isReloading;
  bool isWeaponBringUp;
  bool isInReloadOut;
  bool isInMeleeSwing;
  bool isInterruptableTransition;
  bool isChainFiring;
  bool isChargeFiring;
  bool isLaserFiring;
  bool isZooming;
  bool isInEndSprint;
  bool isHandsSprinting;
  bool isInAccentIdle;
  bool isInTown;
  bool isChangingAmmo;
  idEntityPtr<idProjectile> cookingProjectile;
  const idDeclProjectile *cookingProjectileDecl;
  bool canInteruptCooking;
  bool playingWarningSound;
  int cookingStartTime;
  int cookingDetonationTime;
  int lastActionTime;
  idMeleeTrace handsMeleeTrace;
  idHands::idHandsAction pendingAction;
  idHands::idHandsAction lingeringAction;
  idEntityPtr<idProjectile> previousProjectile;
  int meleeComboCount;
  int lastMeleeHitTime;
  int lastAttackTime;
  int lastWeaponUsedTime;
  int lastOnLadderTime;
  unsigned __int8 : 2;
  __int8 isWallClimbing : 1;
  __int8 meleeTraceHit : 1;
  __int8 isIdle : 1;
  __int8 lastShotLeft : 1;
  __int8 lastShotRight : 1;
  __int8 deleteWeaponOnBringDown : 1;
  int currentVariationIndex;
  int pendingVariationIndex;
  int weaponAnimVar;
  bool weaponRelaxed;
  bool weaponRelaxedToggler;
  int lastAttackVariation;
  int lastAttackVariationDWLeft;
  int lastAimUpdateTime;
  float aimPointDepthBlend;
  float aimPointBlend;
  bool alternateFiringNode;
  bool alternateLeftFiringNode;
  idHands::setWeaponDualWieldType_t currentDualWieldState;
  idHands::idHandsAction dualWieldLeftHandPendingAction;
  idWeapon *pendingWeaponToEquip;
  idHands::handsState_t currentSwimState;
  swimdepthstate_t lastSwimDepthState;
  bool handBubblesActivated;
  idAngles handsTCAngles;
  idHands::handsTCAnglesBlendState_t handsTCAnglesBlendState;
  float handsTCAnglesBlend;
};

// IDA Local Type ordinal 15374; PDB kind: class.
class idHands::idHandsAction
{
public:
  idHands::handsAction_t action;
  const idDeclAmmo *ammoDecl;
  idWeapon *weapon;
  const idDeclThrowable *throwable;
  bool useIntroBringUp;
  bool isSecondary;
  bool leftHand;
  idStr extraNodeInfo;
};

// IDA Local Type ordinal 18093; PDB kind: class.
class idHands::PreLoadWeaponSounds::__l2::local_t
{
public:
};
