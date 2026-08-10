#include "aivoicecontroller.h"

#include <algorithm>

int idAIVoiceController::sNumLogEntries = 0;
idAIVoiceController::logEntry_t
    idAIVoiceController::sLogEntries[50] = {};

idVoiceInfo::idVoiceInfo()
    : shader(nullptr)
    , voiceOver(nullptr)
    , priority(AIVOICEPRIORITY_NONE)
    , interval(0)
    , intervalMax(0)
    , controller(VC_SELF)
    , playChance(100)
    , playOnce(false)
    , dontPlayIfGroupDead(false) {
}

namespace {

void PrintEntry(const idAIVoiceController::logEntry_t& entry) {
    const char* entityName = "removed from map";
    const char* groupName = "removed from map";
    Tungsten_GetAIVoiceLogIdentity(
        entry.entityNum, entityName, groupName);
    Tungsten_AIVoicePrintf(
        "[%6d] voice: %-20s ent: %4d %-50s group: %-20s\n",
        entry.time, Tungsten_GetAIVoiceMessageName(entry.msg),
        entry.entityNum, entityName, groupName);
}

void DebugRejected(const idAI2& ai, const char* format,
        const char* voiceName) {
    if (Tungsten_IsAIVoiceDebugEnabled()) {
        Tungsten_AIVoicePrintf(format,
            Tungsten_GetAIVoiceGameTime(),
            Tungsten_GetAIVoiceAIName(ai), voiceName);
    }
}

int ScaleRealMillisecondsToGameTicks(const int milliseconds) {
    return Tungsten_ConvertAIVoiceDurationToGameTime(milliseconds);
}

} // namespace

// Retail symbol: ?PrintLog@idAIVoiceController@@SAXXZ
// EA: 0x82A61810, RVA: 0x00A61810
void idAIVoiceController::PrintLog() {
    const int modulo = sNumLogEntries % 50;
    if (sNumLogEntries >= 50) {
        for (int index = modulo + 1; index < 50; ++index) {
            PrintEntry(sLogEntries[index]);
        }
    }
    for (int index = 0; index < modulo; ++index) {
        PrintEntry(sLogEntries[index]);
    }
}

// Retail symbol: ??0idAIVoiceController@@QAA@W4voiceController_t@@@Z
// EA: 0x82A619D8, RVA: 0x00A619D8
idAIVoiceController::idAIVoiceController(
        const voiceController_t newControllerType)
    : nextVoiceTime(0)
    , lastVoiceTime(0)
    , lastVoicePriority(AIVOICEPRIORITY_NONE)
    , nextPlayTime{}
    , controllerType(newControllerType) {
}

// Retail symbol: ?InternalAdvanceNextPlayTime@idAIVoiceController@@QAAXW4voiceMsg_t@@PBVidVoiceInfo@@@Z
// EA: 0x82A61A08, RVA: 0x00A61A08
void idAIVoiceController::InternalAdvanceNextPlayTime(
        const voiceMsg_t message, const idVoiceInfo* const voiceInfo) {
    if (voiceInfo == nullptr || message < 0 || message >= AIVOICE_MAX) {
        return;
    }
    const int nextTime = Tungsten_GetAIVoiceGameTime()
        + Tungsten_GetAIVoiceRandomInterval(
            voiceInfo->interval, voiceInfo->intervalMax);
    nextPlayTime[message] = std::max(nextPlayTime[message], nextTime);
}

// Retail symbol: ?VoiceInfoForMessage@idAIVoiceController@@SAPBVidVoiceInfo@@PAVidAI2@@W4voiceMsg_t@@@Z
// EA: 0x82A61A78, RVA: 0x00A61A78
const idVoiceInfo* idAIVoiceController::VoiceInfoForMessage(
        idAI2* const ai, const voiceMsg_t message) {
    if (ai == nullptr || message < 0 || message >= AIVOICE_MAX) {
        return nullptr;
    }
    return Tungsten_GetAIVoiceInfo(*ai, message);
}

// Retail symbol: ?GetControllerForVoice@idAIVoiceController@@QAAPAV1@PAVidAI2@@W4voiceMsg_t@@@Z
// EA: 0x82A61B28, RVA: 0x00A61B28
idAIVoiceController* idAIVoiceController::GetControllerForVoice(
        idAI2* const ai, const voiceMsg_t message) {
    const idVoiceInfo* const voiceInfo = VoiceInfoForMessage(ai, message);
    if (voiceInfo == nullptr) {
        return nullptr;
    }
    if (voiceInfo->controller == VC_GROUP) {
        idAIVoiceController* const groupController =
            Tungsten_GetAIEncounterVoiceController(*ai);
        if (groupController != nullptr) {
            return groupController;
        }
        if (voiceInfo->voiceOver != nullptr) {
            Tungsten_AIVoiceWarning(
                "AI '%s' tried to play voice over '%s' marked as VC_GROUP, but the AI has no group! ALL AI must be grouped to work correctly!",
                Tungsten_GetAIVoiceAIName(*ai),
                Tungsten_GetAIVoiceOverName(*voiceInfo->voiceOver));
        } else if (voiceInfo->shader != nullptr) {
            Tungsten_AIVoiceWarning(
                "AI '%s' tried to play sound shader '%s' marked as VC_GROUP, but the AI has no group! ALL AI must be groupd to work correctly!",
                Tungsten_GetAIVoiceAIName(*ai),
                Tungsten_GetAIVoiceShaderName(*voiceInfo->shader));
        }
        return nullptr;
    }
    if (voiceInfo->controller == VC_GLOBAL) {
        return Tungsten_GetGlobalAIVoiceController();
    }
    return this;
}

// Retail symbol: ?AdvanceNextPlayTime@idAIVoiceController@@QAAXPAVidAI2@@W4voiceMsg_t@@@Z
// EA: 0x82A61C08, RVA: 0x00A61C08
void idAIVoiceController::AdvanceNextPlayTime(
        idAI2* const ai, const voiceMsg_t message) {
    const idVoiceInfo* const voiceInfo = VoiceInfoForMessage(ai, message);
    if (voiceInfo == nullptr) {
        return;
    }
    idAIVoiceController* const controller =
        GetControllerForVoice(ai, message);
    if (controller != nullptr) {
        controller->InternalAdvanceNextPlayTime(message, voiceInfo);
    }
}

// Retail symbol: ?StartVoice@idAIVoiceController@@AAA?AW4voiceController_t@@PAVidAI2@@W4voiceMsg_t@@PBVidVoiceInfo@@@Z
// EA: 0x82A61C78, RVA: 0x00A61C78
voiceController_t idAIVoiceController::StartVoice(idAI2* const ai,
        const voiceMsg_t message, const idVoiceInfo* const voiceInfo) {
    if (ai == nullptr || voiceInfo == nullptr || message < 0
        || message >= AIVOICE_MAX
        || (voiceInfo->shader == nullptr && voiceInfo->voiceOver == nullptr)) {
        return VC_MAX;
    }

    const int now = Tungsten_GetAIVoiceGameTime();
    if (now < nextPlayTime[message]
        || (voiceInfo->playOnce && nextPlayTime[message] != 0)) {
        return VC_MAX;
    }
    if (Tungsten_IsAIVoiceActorDead(*ai)
        && voiceInfo->priority < AIVOICEPRIORITY_PAIN) {
        DebugRejected(*ai,
            "(%d) %s - AI is dead. VO '%s' not played.",
            Tungsten_GetAIVoiceMessageName(message));
        return VC_MAX;
    }
    if (now < nextVoiceTime.value
        && voiceInfo->priority <= lastVoicePriority) {
        return VC_MAX;
    }

    AdvanceNextPlayTime(ai, message);
    if (Tungsten_GetAIVoiceRandomPercent() >= voiceInfo->playChance) {
        return VC_MAX;
    }
    lastVoicePriority = voiceInfo->priority;

    int voiceLength = 0;
    bool started = false;
    if (voiceInfo->voiceOver != nullptr) {
        if (controllerType == VC_GROUP) {
            started = true;
            voiceLength = Tungsten_GetAIVoiceOverMaxLength(
                *voiceInfo->voiceOver);
        } else {
            started = Tungsten_StartAIFaceVoiceOver(
                *ai, voiceInfo->voiceOver);
            if (started) {
                voiceLength = Tungsten_GetAIFaceVoiceDuration(*ai);
            }
        }
    } else if (controllerType == VC_GROUP) {
        started = true;
        voiceLength = Tungsten_GetAIVoiceShaderMaxLength(
            *voiceInfo->shader);
    } else {
        started = Tungsten_StartAIVoiceSound(*ai, *voiceInfo->shader);
        if (started) {
            voiceLength = Tungsten_GetAIVoiceShaderMaxLength(
                *voiceInfo->shader);
        }
    }

    if (!started) {
        return controllerType == VC_GROUP ? VC_GROUP : VC_MAX;
    }
    const int duration = ScaleRealMillisecondsToGameTicks(voiceLength);
    nextVoiceTime = now + duration;
    lastVoiceTime = now;
    if (Tungsten_AIVoiceHasEquippedWeapon(*ai)) {
        Tungsten_InhibitAIVoiceFire(*ai, std::min(duration, 500));
    }
    return controllerType;
}

// Retail symbol: ?PlayVoiceOver@idAIVoiceController@@QAA?AW4voiceController_t@@PAVidAI2@@PBVidDeclVoiceOver@@W4aiVoicePriority_t@@_N@Z
// EA: 0x82A61FF0, RVA: 0x00A61FF0
voiceController_t idAIVoiceController::PlayVoiceOver(
        idAI2* const ai, const idDeclVoiceOver* const voiceOver,
        const aiVoicePriority_t priority,
        const bool samePriorityInterrupts) {
    if (ai == nullptr) {
        return VC_MAX;
    }
    Tungsten_CancelAIStopSoundEvents(*ai);
    const int now = Tungsten_GetAIVoiceGameTime();
    if (now < nextVoiceTime.value) {
        if (samePriorityInterrupts) {
            if (priority < lastVoicePriority) {
                DebugRejected(*ai,
                    "(%d) %s - Same priority voice already playing. VO '%s' not played.",
                    voiceOver != nullptr
                        ? Tungsten_GetAIVoiceOverName(*voiceOver) : "");
                return VC_MAX;
            }
        } else if (priority <= lastVoicePriority) {
            DebugRejected(*ai,
                "(%d) %s - Higher priority voice already playing. VO '%s' not played.",
                voiceOver != nullptr
                    ? Tungsten_GetAIVoiceOverName(*voiceOver) : "");
            return VC_MAX;
        }
    }
    if (Tungsten_IsAIVoiceActorDead(*ai)
        && priority < AIVOICEPRIORITY_PAIN) {
        DebugRejected(*ai,
            "(%d) %s - AI is dead. VO '%s' not played.",
            voiceOver != nullptr
                ? Tungsten_GetAIVoiceOverName(*voiceOver) : "");
        return VC_MAX;
    }
    if (!Tungsten_StartAIFaceVoiceOver(*ai, voiceOver)) {
        if (voiceOver != nullptr) {
            DebugRejected(*ai,
                "(%d) %s - Face manager failed to start voice '%s'.",
                Tungsten_GetAIVoiceOverName(*voiceOver));
        }
        return VC_MAX;
    }
    Tungsten_SetAISpeakingVoiceOver(*ai);
    if (voiceOver == nullptr) {
        return VC_MAX;
    }
    int approximateDuration = 0;
    if (!Tungsten_GetAIActiveVoiceTrackDuration(
            *ai, *voiceOver, approximateDuration)) {
        return VC_MAX;
    }

    lastVoicePriority = priority;
    nextVoiceTime = now
        + ScaleRealMillisecondsToGameTicks(approximateDuration);
    lastVoiceTime = now;
    const int nextGreeting = nextVoiceTime.value
        + Tungsten_GetAIVoiceRandomInterval(2500, 7500);
    Tungsten_SetAIVoiceGreetingTimes(
        nextGreeting, nextGreeting + 5000);
    return controllerType;
}

// Retail symbol: ?PlayVoice@idAIVoiceController@@QAA?AW4voiceController_t@@PAVidAI2@@W4voiceMsg_t@@@Z
// EA: 0x82A622D8, RVA: 0x00A622D8
voiceController_t idAIVoiceController::PlayVoice(
        idAI2* const ai, const voiceMsg_t message) {
    if (ai == nullptr || Tungsten_IsAIVoiceActionScriptBlocked(*ai)) {
        return VC_MAX;
    }
    const idVoiceInfo* const voiceInfo = VoiceInfoForMessage(ai, message);
    if (voiceInfo == nullptr) {
        return VC_MAX;
    }
    idAIVoiceController* const selected =
        GetControllerForVoice(ai, message);
    if (selected == nullptr) {
        Tungsten_AIVoiceWarning(
            "AI '%s' has no voice control for voice msg %d.",
            Tungsten_GetAIVoiceAIName(*ai), message);
        return VC_MAX;
    }
    if (selected->controllerType == VC_GROUP) {
        if (voiceInfo->dontPlayIfGroupDead
            && Tungsten_GetAIEncounterLivingMembers(*ai) < 2) {
            return VC_MAX;
        }
        if (selected->StartVoice(ai, message, voiceInfo) == VC_MAX) {
            return VC_MAX;
        }
    }
    idAIVoiceController* const selfController =
        Tungsten_GetAISelfVoiceController(*ai);
    return selfController != nullptr
        ? selfController->StartVoice(ai, message, voiceInfo) : VC_MAX;
}

// Retail symbol: ?FadeVoiceOver@idAIVoiceController@@QAAXPAVidAI2@@@Z
// EA: 0x82A623D8, RVA: 0x00A623D8
void idAIVoiceController::FadeVoiceOver(idAI2* const ai) {
    if (ai == nullptr) {
        return;
    }
    Tungsten_ResetSpecifiedInteractAI(*ai);
    Tungsten_FadeAIVoiceSound(*ai, Tungsten_GetAIVoiceFadeSeconds());
    Tungsten_PostAIStopVoiceEvent(*ai);
    Tungsten_ResetAIFaceVoice(*ai);
    nextVoiceTime = 0;
    lastVoiceTime = 0;
    Tungsten_NotifyAIVoiceStopped(
        *ai, Tungsten_GetAIVoiceInteractionPlayer(*ai));
}

// Retail symbol: ?StopVoiceOver@idAIVoiceController@@QAAXPAVidAI2@@@Z
// EA: 0x82A62568, RVA: 0x00A62568
void idAIVoiceController::StopVoiceOver(idAI2* const ai) {
    if (ai == nullptr) {
        return;
    }
    Tungsten_StopAIVoiceSound(*ai);
    Tungsten_ResetAIFaceVoice(*ai);
    nextVoiceTime = 0;
    lastVoiceTime = 0;
    Tungsten_NotifyAIVoiceStopped(
        *ai, Tungsten_GetAIVoiceInteractionPlayer(*ai));
}
