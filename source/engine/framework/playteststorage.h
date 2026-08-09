#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\playteststorage.h
// Recovered logical types: 32
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2915; PDB kind: enum.
enum idPlaytestStorage::playerBreadCrumbState_t : __int32
{
  PLAYERBREADCRUMBSTATE_NONE = 0x0,
  PLAYERBREADCRUMBSTATE_NORMAL = 0x1,
  PLAYERBREADCRUMBSTATE_MISC = 0x2,
  PLAYERBREADCRUMBSTATE_VEHICLE = 0x3,
};

// IDA Local Type ordinal 21529; PDB kind: class.
class idPlaytestStorage::playerNormalBreadCrumbInfo_t
{
public:
  idVec3 loc;
  idVec3 dir;
  float health;
  float healthPercent;
  float speed;
  int mainAmmoCount;
  bool combatHud;
  bool isCrouching;
  bool isZooming;
  bool isCooking;
  int count;
  int timestamp;
  int lastTimeStamp;
};

// IDA Local Type ordinal 21531; PDB kind: class.
class idPlaytestStorage::playerNormalBreadCrumbList_t
{
public:
  bool inInteraction;
  idStr interactionEntity;
  idStr interactionName;
  idList<idPlaytestStorage::playerNormalBreadCrumbInfo_t,5> breadCrumbs;
};

// IDA Local Type ordinal 21533; PDB kind: class.
class idPlaytestStorage::playerMiscControlBreadCrumbInfo_t
{
public:
  idVec3 loc;
  idVec3 dir;
  float speed;
  int count;
  int timestamp;
  int lastTimeStamp;
};

// IDA Local Type ordinal 21535; PDB kind: class.
class idPlaytestStorage::playerMiscControlBreadCrumbList_t
{
public:
  idStr controlName;
  bool isInteraction;
  idList<idPlaytestStorage::playerMiscControlBreadCrumbInfo_t,5> breadCrumbs;
};

// IDA Local Type ordinal 21537; PDB kind: class.
class __declspec(align(4)) idPlaytestStorage::playerVehicleBreadCrumbInfo_t
{
public:
  idVec3 loc;
  idVec3 dir;
  float health;
  float healthPercent;
  float speed;
  float boost;
  int ammo;
  int count;
  int timestamp;
  int lastTimeStamp;
  bool combatHud;
};

// IDA Local Type ordinal 21539; PDB kind: class.
class idPlaytestStorage::playerVehicleBreadCrumbList_t
{
public:
  idStr vehicleName;
  bool isRCBomb;
  idList<idPlaytestStorage::playerVehicleBreadCrumbInfo_t,5> breadCrumbs;
};

// IDA Local Type ordinal 21541; PDB kind: class.
class idPlaytestStorage::playerMainBreadCrumbInfo_t
{
public:
  idPlaytestStorage::playerBreadCrumbState_t state;
  idList<idPlaytestStorage::playerNormalBreadCrumbList_t,5> normalBreadCrumbs;
  idList<idPlaytestStorage::playerMiscControlBreadCrumbList_t,5> miscBreadCrumbs;
  idList<idPlaytestStorage::playerVehicleBreadCrumbList_t,5> vehicleBreadCrumbs;
};

// IDA Local Type ordinal 21543; PDB kind: class.
class idPlaytestStorage::playerButtonInfo_t
{
public:
  int buttons;
  char forwardmove;
  char rightmove;
  char upmove;
  int timestamp;
  int lastTimestamp;
};

// IDA Local Type ordinal 21546; PDB kind: class.
class idPlaytestStorage::itemInfo_t
{
public:
  idVec3 loc;
  idStr itemName;
  int count;
  idStr materialName;
  int timestamp;
};

// IDA Local Type ordinal 21549; PDB kind: class.
class idPlaytestStorage::useFocusInfo_t
{
public:
  idVec3 loc;
  idVec3 dir;
  idStr focusName;
  int timestamp;
};

// IDA Local Type ordinal 21552; PDB kind: class.
class idPlaytestStorage::quickItemInfo_t
{
public:
  idVec3 loc;
  idStr quickItemName;
  idStr quickItemMaterial;
  int timestamp;
};

// IDA Local Type ordinal 21555; PDB kind: class.
class idPlaytestStorage::equipItemInfo_t
{
public:
  idVec3 loc;
  idStr equipedItemName;
  idStr equipedItemMaterial;
  int timestamp;
};

// IDA Local Type ordinal 21558; PDB kind: class.
class idPlaytestStorage::deathInfo_t
{
public:
  idVec3 loc;
  idVec3 killerLoc;
  int entityNum;
  idStr entityName;
  int killerEntityNum;
  idStr killerName;
  idStr damageName;
  int timestamp;
};

// IDA Local Type ordinal 21561; PDB kind: class.
class idPlaytestStorage::weaponFireInfo_t
{
public:
  idStr weaponName;
  idStr projectileName;
  int attackerNum;
  idStr attackerName;
  int targetNum;
  float spread;
  idVec3 start;
  idVec3 dir;
  int timestamp;
};

// IDA Local Type ordinal 21564; PDB kind: class.
class idPlaytestStorage::inventoryElement_t
{
public:
  idStr itemName;
  idStr materialName;
  int count;
};

// IDA Local Type ordinal 21566; PDB kind: class.
class idPlaytestStorage::inventoryInfo_t
{
public:
  int timestamp;
  idVec3 loc;
  idList<idPlaytestStorage::inventoryElement_t,5> inventoryList;
};

// IDA Local Type ordinal 21569; PDB kind: class.
class idPlaytestStorage::radiusDamageInfo_t
{
public:
  idVec3 loc;
  float radius;
  float minDamage;
  float maxDamage;
  float playerDamageScale;
  idStr inflictorName;
  idStr attackerName;
  idStr damageDefName;
  int timestamp;
};

// IDA Local Type ordinal 21571; PDB kind: class.
class idPlaytestStorage::ai2FSMStateInfo_t
{
public:
  idStr fsmName;
  idStr stateName;
  idStr lastTransition;
};

// IDA Local Type ordinal 21573; PDB kind: class.
class idPlaytestStorage::ai2StateInfo_t
{
public:
  int timestamp;
  int lastTimeStamp;
  int count;
  idList<idPlaytestStorage::ai2FSMStateInfo_t,5> states;
};

// IDA Local Type ordinal 21575; PDB kind: class.
class __declspec(align(4)) idPlaytestStorage::ai2BreadCrumbInfo_t
{
public:
  idVec3 loc;
  idVec3 dir;
  float health;
  float healthPercent;
  float speed;
  int count;
  int timestamp;
  int lastTimeStamp;
  bool isHostile;
  bool isTalking;
};

// IDA Local Type ordinal 21578; PDB kind: class.
class idPlaytestStorage::ai2Info_t
{
public:
  int entNum;
  idStr entName;
  int creationTimeStamp;
  bool isDormant;
  idList<idPlaytestStorage::ai2StateInfo_t,5> stateLog;
  idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> breadCrumbs;
  idList<int,5> dormantTimeStamps;
};

// IDA Local Type ordinal 21580; PDB kind: class.
class __declspec(align(4)) idPlaytestStorage::aiVehicleBreadCrumbInfo_t
{
public:
  idVec3 loc;
  idVec3 dir;
  float health;
  float healthPercent;
  float speed;
  float boost;
  int ammo;
  int count;
  int timestamp;
  int lastTimeStamp;
  bool hasCar;
  bool isRCBomb;
};

// IDA Local Type ordinal 21582; PDB kind: class.
class idPlaytestStorage::aiVehicleInfo_t
{
public:
  int entNum;
  idStr entName;
  int creationTimeStamp;
  idList<idPlaytestStorage::aiVehicleBreadCrumbInfo_t,5> breadCrumbs;
};

// IDA Local Type ordinal 21584; PDB kind: class.
class idPlaytestStorage
{
public:
  idList<idPlaytestStorage::playerMainBreadCrumbInfo_t,5> playerBreadCrumbs;
  idList<idList<idPlaytestStorage::playerButtonInfo_t,5>,5> playerButtonInfo;
  idList<idList<idPlaytestStorage::itemInfo_t,5>,5> playerItemInfo;
  idList<idList<idPlaytestStorage::useFocusInfo_t,5>,5> playerUseFocusInfo;
  idList<idList<idPlaytestStorage::quickItemInfo_t,5>,5> playerUseQuickItemInfo;
  idList<idList<idPlaytestStorage::equipItemInfo_t,5>,5> playerEquipItemInfo;
  idList<idList<idPlaytestStorage::deathInfo_t,5>,5> playerDeathInfo;
  idList<idList<idPlaytestStorage::weaponFireInfo_t,5>,5> playerWeaponFireInfo;
  idList<idList<idPlaytestStorage::inventoryInfo_t,5>,5> playerInventoryInfo;
  idList<idPlaytestStorage::radiusDamageInfo_t,5> radiusDamageInfo;
  idList<idPlaytestStorage::deathInfo_t,5> otherDeathInfo;
  idList<idPlaytestStorage::weaponFireInfo_t,5> otherWeaponFireInfo;
  idList<idPlaytestStorage::ai2Info_t,5> ai2Info;
  idList<idPlaytestStorage::aiVehicleInfo_t,5> aiVehicleInfo;
  int numPlayers;
  int version;
  idStr buildVersionString;
  int buildNumberMajor;
  int buildNumberMinor;
  idStr machineName;
  idStr fileName;
  idStr playMapName;
  int numActiveLayers;
  idList<idStr,5> activeLayers;
  int beginTime;
  int lastTime;
  int offsetTime;
};

// IDA Local Type ordinal 21639; PDB kind: class.
class idPlaytestStorage::weaponUsageReport_t
{
public:
  idStr weaponName;
  int time;
  float percentage;
  int projectilesSpawned;
};

// IDA Local Type ordinal 21813; PDB kind: class.
class idPlaytestStorage::quickItemReport_t
{
public:
  idStr itemName;
  int count;
};

// IDA Local Type ordinal 21910; PDB kind: class.
class idPlaytestStorage::killReport_t
{
public:
  idStr damageName;
  int count;
};

// IDA Local Type ordinal 21978; PDB kind: class.
class idPlaytestMetaStorage
{
public:
  int version;
  int beginTime;
  int lastTime;
  idStr fileName;
  idStr buildVersionString;
  int buildNumberMajor;
  int buildNumberMinor;
  idStr machineName;
  idList<idPlaytestStorage,5> storageList;
};

// IDA Local Type ordinal 22426; PDB kind: class.
class idPlaytestStorage::idSort_WeaponUsageReport : public idSort_Quick<idPlaytestStorage::weaponUsageReport_t,idPlaytestStorage::idSort_WeaponUsageReport>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22427.
  virtual ~idSort_WeaponUsageReport();
  virtual void Sort(idPlaytestStorage::weaponUsageReport_t *, unsigned int);

};

// IDA Local Type ordinal 22428; PDB kind: class.
class idPlaytestStorage::idSort_KillReport : public idSort_Quick<idPlaytestStorage::killReport_t,idPlaytestStorage::idSort_KillReport>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22429.
  virtual ~idSort_KillReport();
  virtual void Sort(idPlaytestStorage::killReport_t *, unsigned int);

};

// IDA Local Type ordinal 22430; PDB kind: class.
class idPlaytestStorage::idSort_QuickItemReport : public idSort_Quick<idPlaytestStorage::quickItemReport_t,idPlaytestStorage::idSort_QuickItemReport>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22431.
  virtual ~idSort_QuickItemReport();
  virtual void Sort(idPlaytestStorage::quickItemReport_t *, unsigned int);

};
