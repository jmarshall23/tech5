#pragma once

#include "aidefs.h"
#include "aievents/aievent.h"

class idAI2;
class idDeclVoiceOver;
class idPlayer;
class idSoundShader;

enum voiceController_t : int {
    VC_SELF = 0,
    VC_GROUP = 1,
    VC_GLOBAL = 2,
    VC_MAX = 3
};

#ifndef TUNGSTEN_AI_VOICE_PRIORITY_T_DEFINED
#define TUNGSTEN_AI_VOICE_PRIORITY_T_DEFINED
enum aiVoicePriority_t : int {
    AIVOICEPRIORITY_NONE = 0,
    AIVOICEPRIORITY_LOW = 1,
    AIVOICEPRIORITY_MED = 2,
    AIVOICEPRIORITY_HIGH = 3,
    AIVOICEPRIORITY_AMBIENT = AIVOICEPRIORITY_LOW,
    AIVOICEPRIORITY_CHATTER = AIVOICEPRIORITY_MED,
    AIVOICEPRIORITY_ALERT = AIVOICEPRIORITY_HIGH,
    AIVOICEPRIORITY_PAIN = 4,
    AIVOICEPRIORITY_DEATH = 5
};
#endif

struct idVoiceInfo {
    idVoiceInfo();

    const idSoundShader* shader;
    const idDeclVoiceOver* voiceOver;
    aiVoicePriority_t priority;
    int interval;
    int intervalMax;
    voiceController_t controller;
    unsigned char playChance;
    bool playOnce;
    union {
        bool dontPlayIfGroupDead;
        bool requireMultipleGroupMembers;
    };
};

struct idAIVoiceInfoTable {
    const idVoiceInfo* messages[AIVOICE_MAX];
};

class idAIVoiceController {
public:
    struct logEntry_t {
        int entityNum;
        int time;
        voiceMsg_t msg;
    };

    explicit idAIVoiceController(
        voiceController_t controllerType = VC_SELF);

    static void PrintLog();
    void InternalAdvanceNextPlayTime(
        voiceMsg_t msg, const idVoiceInfo* voiceInfo);
    static const idVoiceInfo* VoiceInfoForMessage(
        idAI2* ai, voiceMsg_t msg);
    idAIVoiceController* GetControllerForVoice(
        idAI2* ai, voiceMsg_t msg);
    void AdvanceNextPlayTime(idAI2* ai, voiceMsg_t msg);
    voiceController_t StartVoice(
        idAI2* ai, voiceMsg_t msg, const idVoiceInfo* voiceInfo);
    voiceController_t PlayVoiceOver(idAI2* ai,
        const idDeclVoiceOver* voiceOver,
        aiVoicePriority_t priority, bool samePriorityInterrupts);
    voiceController_t PlayVoice(idAI2* ai, voiceMsg_t msg);
    void FadeVoiceOver(idAI2* ai);
    void StopVoiceOver(idAI2* ai);

    static int sNumLogEntries;
    static logEntry_t sLogEntries[50];

    gameTime_t nextVoiceTime;
    gameTime_t lastVoiceTime;
    aiVoicePriority_t lastVoicePriority;
    int nextPlayTime[AIVOICE_MAX];
    voiceController_t controllerType;
};

const idVoiceInfo* Tungsten_GetAIVoiceInfo(
    const idAI2& ai, voiceMsg_t message);
const char* Tungsten_GetAIVoiceAIName(const idAI2& ai);
const char* Tungsten_GetAIVoiceMessageName(voiceMsg_t message);
const char* Tungsten_GetAIVoiceOverName(
    const idDeclVoiceOver& voiceOver);
const char* Tungsten_GetAIVoiceShaderName(
    const idSoundShader& shader);
idAIVoiceController* Tungsten_GetAIEncounterVoiceController(idAI2& ai);
idAIVoiceController* Tungsten_GetAISelfVoiceController(idAI2& ai);
idAIVoiceController* Tungsten_GetGlobalAIVoiceController();
int Tungsten_GetAIEncounterLivingMembers(const idAI2& ai);
bool Tungsten_IsAIVoiceActorDead(const idAI2& ai);
bool Tungsten_IsAIVoiceActionScriptBlocked(const idAI2& ai);
int Tungsten_GetAIVoiceGameTime();
int Tungsten_GetAIVoiceRandomInterval(int minimum, int maximum);
int Tungsten_GetAIVoiceRandomPercent();
int Tungsten_ConvertAIVoiceDurationToGameTime(
    int durationMilliseconds);
bool Tungsten_IsAIVoiceDebugEnabled();
bool Tungsten_StartAIFaceVoiceOver(
    idAI2& ai, const idDeclVoiceOver* voiceOver);
int Tungsten_GetAIFaceVoiceDuration(const idAI2& ai);
bool Tungsten_GetAIActiveVoiceTrackDuration(const idAI2& ai,
    const idDeclVoiceOver& voiceOver, int& durationMilliseconds);
int Tungsten_GetAIVoiceOverMaxLength(
    const idDeclVoiceOver& voiceOver);
bool Tungsten_StartAIVoiceSound(
    idAI2& ai, const idSoundShader& shader);
int Tungsten_GetAIVoiceShaderMaxLength(const idSoundShader& shader);
bool Tungsten_AIVoiceHasEquippedWeapon(const idAI2& ai);
void Tungsten_InhibitAIVoiceFire(idAI2& ai, int durationMilliseconds);
void Tungsten_CancelAIStopSoundEvents(idAI2& ai);
void Tungsten_SetAISpeakingVoiceOver(idAI2& ai);
void Tungsten_SetAIVoiceGreetingTimes(
    int nextPlayerGreetingTime, int nextAIGreetingTime);
void Tungsten_ResetSpecifiedInteractAI(idAI2& ai);
float Tungsten_GetAIVoiceFadeSeconds();
void Tungsten_FadeAIVoiceSound(idAI2& ai, float seconds);
void Tungsten_PostAIStopVoiceEvent(idAI2& ai);
void Tungsten_StopAIVoiceSound(idAI2& ai);
void Tungsten_ResetAIFaceVoice(idAI2& ai);
const idPlayer* Tungsten_GetAIVoiceInteractionPlayer(const idAI2& ai);
void Tungsten_NotifyAIVoiceStopped(
    idAI2& ai, const idPlayer* target);
bool Tungsten_GetAIVoiceLogIdentity(int entityNum,
    const char*& entityName, const char*& groupName);
void Tungsten_AIVoicePrintf(const char* format, ...);
void Tungsten_AIVoiceWarning(const char* format, ...);
