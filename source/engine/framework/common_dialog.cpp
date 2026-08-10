#include "framework/framework_runtime_internal.h"

#include "framework/common_local.h"
#include "framework/framework_hooks.h"
#include "framework/keyinput.h"
#include "framework/sysevent.h"
#include "idlib/csystems/cvarsystem.h"
#include "idlib/lib_print.h"

#include <algorithm>
#include <cstdlib>

namespace {

idCVar popupDialog_debug("popupDialog_debug", "0", CVAR_BOOL,
    "display debug spam");
idCVar dialog_saveClearLevel1("dialog_saveClearLevel1", "1000",
    CVAR_INTEGER, "Time required to show short message");
idCVar dialog_saveClearLevel2("dialog_saveClearLevel2", "3000",
    CVAR_INTEGER, "Time required to show long message");

int DialogMilliseconds() {
    if (frameworkHooks.milliseconds != nullptr) {
        return frameworkHooks.milliseconds();
    }
    return tech5Framework::State().milliseconds;
}

idSWFScriptFunction* DialogCallback(idDialogInfo& dialog,
        const int index) {
    switch (index) {
    case 0: return dialog.acceptCB;
    case 1: return dialog.cancelCB;
    case 2: return dialog.altCBOne;
    case 3: return dialog.altCBTwo;
    default: return nullptr;
    }
}

void RetainDialogCallbacks(idDialogInfo& dialog) {
    if (frameworkHooks.retainScriptCallback == nullptr) return;
    for (int index = 0; index < 4; ++index) {
        idSWFScriptFunction* const callback = DialogCallback(dialog, index);
        if (callback != nullptr) {
            frameworkHooks.retainScriptCallback(callback);
        }
    }
}

void ReleaseDialogCallbacks(idDialogInfo& dialog) {
    for (int index = 0; index < 4; ++index) {
        idSWFScriptFunction*& callback = index == 0 ? dialog.acceptCB
            : index == 1 ? dialog.cancelCB
            : index == 2 ? dialog.altCBOne : dialog.altCBTwo;
        if (callback != nullptr
                && frameworkHooks.releaseScriptCallback != nullptr) {
            frameworkHooks.releaseScriptCallback(callback);
        }
        callback = nullptr;
    }
}

bool IsMinimumDurationDialog(const int message) {
    return message == GDM_SAVING || message == GDM_REFRESHING
        || message == GDM_QUICK_SAVE || message == GDM_LOADING_PROFILE;
}

void RemoveDialogAt(tech5Framework::runtimeState_t& state,
        const std::size_t index) {
    if (index >= state.dialogs.size()) return;
    auto iterator = state.dialogs.begin()
        + static_cast<std::ptrdiff_t>(index);
    ReleaseDialogCallbacks(*iterator);
    state.dialogs.erase(iterator);
    if (state.dialogs.empty()) state.dialogActive = false;
}

const char* DialogKey(const gameDialogMessages_t msg, bool& use360Prefix) {
    use360Prefix = false;
    switch (msg) {
    case GDM_SWAP_DISKS_TO1: use360Prefix = true; return "switch_disc_to_1";
    case GDM_SWAP_DISKS_TO2: use360Prefix = true; return "switch_disc_to_2";
    case GDM_SWAP_DISKS_TO3: use360Prefix = true; return "switch_disc_to_3";
    case GDM_NO_GAMER_PROFILE: use360Prefix = true; return "signin_request";
    case GDM_PLAY_ONLINE_NO_PROFILE: use360Prefix = true; return "online_signin_request";
    case GDM_LEADERBOARD_ONLINE_NO_PROFILE: use360Prefix = true; return "online_signing_request_leaderboards";
    case GDM_NO_STORAGE_SELECTED: use360Prefix = true; return "storage_device_selection_request";
    case GDM_ONLINE_INCORRECT_PERMISSIONS: use360Prefix = true; return "incorrect_online_permissions";
    case GDM_SP_QUIT_SAVE: return "#str_dlg_quit_progress_lost";
    case GDM_SP_RESTART_SAVE: return "#str_dlg_restart_progress_lost";
    case GDM_SP_SIGNIN_CHANGE: return "#str_dlg_signin_changed";
    case GDM_SERVER_NOT_AVAILABLE: use360Prefix = true; return "game_server_unavailable";
    case GDM_CONNECTION_LOST_HOST: return "#str_dlg_opponent_connection_lost_ranking_not_counted";
    case GDM_CONNECTION_LOST: use360Prefix = true; return "online_connection_lost_main_menu_return";
    case GDM_OPPONENT_CONNECTION_LOST: return "#str_dlg_opponent_connection_lost";
    case GDM_HOST_CONNECTION_LOST: return "#str_dlg_host_connection_lost";
    case GDM_CONNECTION_TO_HOST_LOST: return "#str_dlg_host_connection_lost_ranking_not_counted";
    case GDM_FAILED_TO_LOAD_RANKINGS: return "#str_dlg_ranking_load_failed";
    case GDM_HOST_QUIT: return "#str_dlg_host_quit";
    case GDM_BECAME_HOST_PARTY: return "#str_dlg_became_host_party";
    case GDM_NEW_HOST_PARTY: return "#str_dlg_new_host_party";
    case GDM_LOBBY_BECAME_HOST_GAME: return "#str_dlg_lobby_became_host_game";
    case GDM_LOBBY_NEW_HOST_GAME: use360Prefix = true; return "lobby_new_host_game";
    case GDM_NEW_HOST_GAME: return "#str_dlg_new_host_game";
    case GDM_NEW_HOST_GAME_STATS_DROPPED: return "#str_dlg_new_host_game_stats_dropped";
    case GDM_BECAME_HOST_GAME: use360Prefix = true; return "became_host_game";
    case GDM_BECAME_HOST_GAME_STATS_DROPPED: return "#str_dlg_became_host_game_stats_dropped";
    case GDM_LOBBY_DISBANDED: use360Prefix = true; return "lobby_disbanded";
    case GDM_LEAVE_WITH_PARTY: return "#str_dlg_leave_with_party";
    case GDM_LEAVE_LOBBY_RET_MAIN: return "#str_dlg_leave_lobby_ret_main";
    case GDM_LEAVE_LOBBY_RET_NEW_PARTY: use360Prefix = true; return "leave_lobby_ret_new_party";
    case GDM_MIGRATING: return "#str_online_host_migration";
    case GDM_OPPONENT_LEFT: return "#str_dlg_opponent_left";
    case GDM_NO_MATCHES_FOUND: return "#str_dlg_matches_not_found";
    case GDM_INVALID_INVITE: return "#str_dlg_invalid_game";
    case GDM_KICKED: return "#str_dlg_kicked";
    case GDM_BANNED: return "#str_dlg_banned";
    case GDM_SAVING:
    case GDM_QUICK_SAVE: use360Prefix = true; return "saving";
    case GDM_OVERWRITE_SAVE: return "#str_dlg_overwrite_save";
    case GDM_LOAD_REQUEST: use360Prefix = true; return "load_request";
    case GDM_AUTOSAVE_DISABLED_STORAGE_REMOVED: use360Prefix = true; return "storage_removed_autosave_disabled";
    case GDM_STORAGE_INVALID: use360Prefix = true; return "storage_not_available";
    case GDM_CONNECTING: return "#str_dlg_connecting";
    case GDM_REFRESHING: return "#str_dlg_refreshing";
    case GDM_DELETE_SAVE: use360Prefix = true; return "delete_save";
    case GDM_DELETING: use360Prefix = true; return "deleting";
    case GDM_BINDING_ALREDY_SET: use360Prefix = true; return "bind_exists";
    case GDM_CANNOT_BIND: use360Prefix = true; return "cannont_bind";
    case GDM_OVERLAY_DISABLED: use360Prefix = true; return "overlay_disabled";
    case GDM_DIRECT_MAP_CHANGE: return "#str_dlg_direct_map_change";
    case GDM_DELETE_AUTOSAVE: use360Prefix = true; return "delete_autosave";
    case GDM_MULTI_RETRY: return "#str_online_confirm_retry";
    case GDM_MULTI_SELF_DESTRUCT: return "#str_online_confirm_suicide";
    case GDM_MULTI_VDM_QUIT: return "#str_online_confirm_quit_generic";
    case GDM_MULTI_COOP_QUIT: return "#str_online_confirm_coop_quit_game_generic";
    case GDM_LOADING_PROFILE: return "#str_dlg_loading_profile";
    case GDM_STORAGE_REQUIRED: use360Prefix = true; return "storage_required";
    case GDM_INSUFFICENT_STORAGE_SPACE: return "#str_dlg_insufficient_space";
    case GDM_PARTNER_LEFT: return "#str_dlg_partner_left";
    case GDM_RESTORE_CORRUPT_SAVEGAME: return "#str_dlg_restore_corrupt_savegame";
    case GDM_UNRECOVERABLE_SAVEGAME: return "#str_dlg_unrecoverable_savegame";
    case GDM_PROFILE_SAVE_ERROR: use360Prefix = true; return "profile_save_error";
    case GDM_LOBBY_FULL: return "#str_dlg_lobby_full";
    case GDM_QUIT_GAME: return "#str_dlg_confirm_quit";
    case GDM_CONNECTION_PROBLEMS: return "#str_online_connection_problems";
    case GDM_VOICE_RESTRICTED: use360Prefix = true; return "voice_restricted";
    case GDM_LOAD_DAMAGED_FILE: return "#str_dlg_corrupt_save_file";
    case GDM_MUST_SIGNIN: use360Prefix = true; return "must_signin";
    case GDM_CONNECTION_LOST_NO_LEADERBOARD: use360Prefix = true; return "online_connection_lost_no_leaderboard";
    case GDM_SP_SIGNIN_CHANGE_POST: use360Prefix = true; return "signin_changed_post";
    case GDM_MIGRATING_WAITING: return "#str_online_host_migration_waiting";
    case GDM_MIGRATING_RELAUNCHING: return "#str_online_host_migration_relaunching";
    case GDM_MIGRATING_FAILED_CONNECTION: return "#str_online_host_migration_failed";
    case GDM_MIGRATING_FAILED_CONNECTION_STATS: return "#str_online_host_migration_failed_stats";
    case GDM_MIGRATING_FAILED_DISBANDED: return "#str_online_host_migration_failed_disbanded";
    case GDM_MIGRATING_FAILED_DISBANDED_STATS: return "#str_online_host_migration_failed_disbanded_stats";
    case GDM_MIGRATING_FAILED_PARTNER_LEFT: return "#str_online_host_migration_failed_partner_left";
    case GDM_HOST_RETURNED_TO_LOBBY: use360Prefix = true; return "host_quit_to_lobby";
    case GDM_HOST_RETURNED_TO_LOBBY_STATS_DROPPED: use360Prefix = true; return "host_quit_to_lobby_stats_dropped";
    case GDM_FAILED_JOIN_LOCAL_SESSION: return "#str_dlg_failed_join_local_session";
    case GDM_DELETE_CORRUPT_SAVEGAME: return "#str_dlg_delete_corrupt_savegame";
    case GDM_LEAVE_INCOMPLETE_INSTANCE: return "#str_dlg_leave_incomplete_instance";
    case GDM_UNBIND_CONFIRM: return "#str_dlg_bind_unbind";
    case GDM_BINDINGS_RESTORE: return "#str_dlg_bind_restore";
    case GDM_NEW_HOST: use360Prefix = true; return "new_host";
    case GDM_CONFIRM_VIDEO_CHANGES: return "#str_dlg_confirm_display_changes";
    case GDM_UNABLE_TO_USE_SELECTED_STORAGE_DEVICE: use360Prefix = true; return "unable_to_use_selected_storage_device";
    case GDM_ERROR_LOADING_SAVEGAME: return "#str_dlg_error_loading_savegame";
    case GDM_ERROR_SAVING_SAVEGAME: return "#str_dlg_error_saving_savegame";
    case GDM_DISCARD_CHANGES: return "#str_dlg_confirm_discard";
    case GDM_LEAVE_LOBBY: return "#str_online_leave_game_lobby_alt_02";
    case GDM_LEAVE_LOBBY_AND_TEAM: return "#str_online_party_leave_game";
    case GDM_CONTROLLER_DISCONNECTED_0:
    case GDM_CONTROLLER_DISCONNECTED_1:
    case GDM_CONTROLLER_DISCONNECTED_2:
    case GDM_CONTROLLER_DISCONNECTED_3:
    case GDM_CONTROLLER_DISCONNECTED_4:
    case GDM_CONTROLLER_DISCONNECTED_5:
    case GDM_CONTROLLER_DISCONNECTED_6: return "#str_dlg_reconnect_controller";
    case GDM_DLC_ERROR_REMOVED: use360Prefix = true; return "dlc_error_content_removed";
    case GDM_DLC_ERROR_CORRUPT: use360Prefix = true; return "dlc_error_content_corrupt";
    case GDM_DLC_ERROR_MISSING: use360Prefix = true; return "dlc_error_content_missing";
    case GDM_DLC_ERROR_MISSING_GENERIC: use360Prefix = true; return "dlc_error_content_missing_generic";
    case GDM_DISC_SWAP: return "#str_dlg_disc_swap";
    case GDM_NEEDS_INSTALL: return "#str_dlg_game_install_message";
    case GDM_NO_SAVEGAMES_AVAILABLE: return "#str_dlg_no_savegames_available";
    case GDM_ERROR_JOIN_TWO_PROFILES_ONE_BOX: use360Prefix = true; return "online_join_error_two_profiles_one_box";
    case GDM_WARNING_PLAYING_COOP_SOLO: return "#str_online_lotw_solo_warning_alt_05";
    case GDM_MULTI_COOP_QUIT_LOSE_LEADERBOARDS: return "#str_online_confirm_coop_quit_game";
    case GDM_CORRUPT_CONTINUE: return "#str_online_360_cert_corrupt_save_load";
    case GDM_MULTI_VDM_QUIT_LOSE_LEADERBOARDS: return "#str_online_confirm_quit_game";
    case GDM_WARNING_PLAYING_VDM_SOLO: return "#str_online_cr_custom_game_no_stats";
    case GDM_NO_GUEST_SUPPORT: return "#str_dlg_ps3_incorrect_online_permissions";
    case GDM_DISC_SWAP_CONFIRMATION: return "#str_dlg_disc_swap_confirmation";
    case GDM_ERROR_LOADING_PROFILE: use360Prefix = true; return "error_loading_profile";
    case GDM_CANNOT_INVITE_LOBBY_FULL: return "#str_online_join_error_full";
    case GDM_WARNING_FOR_NEW_DEVICE_ABOUT_TO_LOSE_PROGRESS: return "#str_dlg_360_new_device_selected";
    case GDM_DISCONNECTED: return "#str_online_connection_error_03";
    case GDM_INCOMPATIBLE_NEWER_SAVE: return "#str_dlg_newer_incompatible_savegame";
    case GDM_ACHIEVEMENTS_DISABLED_DUE_TO_CHEATING: return "#str_dlg_achievements_disabled_due_to_cheating";
    case GDM_INCOMPATIBLE_POINTER_SIZE: return "#str_dlg_pointer_size_mismatch";
    case GDM_TEXTUREDETAIL_RESTARTREQUIRED: return "#str_swf_texture_restart";
    case GDM_TEXTUREDETAIL_INSUFFICIENT_CPU: return "#str_swf_insufficient_cores";
    case GDM_CALCULATING_BENCHMARK: return "#str_swf_calc_benchmark";
    case GDM_DISPLAY_BENCHMARK: return "BENCHMARK SCORE = ";
    case GDM_DISPLAY_CHANGE_FAILED: return "#str_swf_display_changes_failed";
    case GDM_GPU_TRANSCODE_FAILED: return "#str_swf_gpu_transcode_failed";
    case GDM_OUT_OF_MEMORY: return "#str_swf_failed_level_load";
    case GDM_CORRUPT_PROFILE: return "#str_dlg_corrupt_profile";
    case GDM_PROFILE_TOO_OUT_OF_DATE_DEVELOPMENT_ONLY: return "#str_dlg_profile_too_out_of_date_development_only";
    default: return "MESSAGE TYPE NOT DEFINED";
    }
}

} // namespace

namespace tech5Framework {

void QueueDialog(const dialog_t& input) {
    runtimeState_t& state = State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    for (const idDialogInfo& existing : state.dialogs) {
        if (existing.msg == input.msg && !existing.clear) return;
    }
    if (input.msg == GDM_STORAGE_REQUIRED) {
        for (std::size_t index = 0; index < state.dialogs.size();) {
            const gameDialogMessages_t message = state.dialogs[index].msg;
            if (message == GDM_DELETE_SAVE || message == GDM_DELETE_AUTOSAVE
                    || message == GDM_LOAD_DAMAGED_FILE) {
                RemoveDialogAt(state, index);
            } else {
                ++index;
            }
        }
    }
    if (state.dialogs.size() >= 4) {
        RemoveDialogAt(state, state.dialogs.size() - 1);
    }
    idDialogInfo dialog = input;
    dialog.startTime = DialogMilliseconds();
    RetainDialogCallbacks(dialog);
    if (state.dialogs.empty()) state.dialogs.push_back(dialog);
    else state.dialogs.push_front(dialog);
    state.dialogActive = true;
    if (popupDialog_debug.GetBool()) {
        idLibPrint::Printf("dialog added: %d type %d\n", dialog.msg,
            dialog.type);
    }
}

bool PopDialog(dialog_t& dialog) {
    runtimeState_t& state = State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    if (state.dialogs.empty()) return false;
    dialog = state.dialogs.front();
    ReleaseDialogCallbacks(state.dialogs.front());
    dialog.acceptCB = dialog.cancelCB = dialog.altCBOne = dialog.altCBTwo =
        nullptr;
    state.dialogs.pop_front();
    state.dialogActive = !state.dialogs.empty();
    return true;
}

void ClearDialogs(const bool force) {
    runtimeState_t& state = State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    for (std::size_t index = 0; index < state.dialogs.size();) {
        if (force || !state.dialogs[index].leaveOnClear) {
            RemoveDialogAt(state, index);
        } else {
            ++index;
        }
    }
    state.dialogActive = !state.dialogs.empty();
}

bool ClearDialog(const int message) {
    runtimeState_t& state = State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    for (std::size_t index = 0; index < state.dialogs.size(); ++index) {
        idDialogInfo& dialog = state.dialogs[index];
        if (dialog.msg != message || dialog.clear) continue;
        if (IsMinimumDurationDialog(message) && !dialog.waitClear) {
            const int elapsed = DialogMilliseconds() - dialog.startTime;
            const int minimum = dialog_saveClearLevel2.GetInteger();
            if (elapsed < minimum) {
                dialog.killTime = DialogMilliseconds() + minimum - elapsed;
                dialog.waitClear = true;
                return true;
            }
        }
        dialog.clear = true;
        dialog.waitClear = false;
        if (index == 0) state.dialogActive = false;
        return true;
    }
    return false;
}

bool HasDialog(const int message, bool* const isActive) {
    runtimeState_t& state = State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    for (std::size_t index = 0; index < state.dialogs.size(); ++index) {
        if (state.dialogs[index].msg == message
                && !state.dialogs[index].clear) {
            if (isActive != nullptr) {
                *isActive = index == 0 && state.dialogActive;
            }
            return true;
        }
    }
    if (isActive != nullptr) *isActive = false;
    return false;
}

bool IsDialogActive() {
    runtimeState_t& state = State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    return state.dialogActive && !state.dialogs.empty();
}

bool IsDialogPausing() {
    runtimeState_t& state = State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    return state.dialogActive && !state.dialogs.empty()
        && (state.dialogs.front().pause || state.dialogs.front().forcePause);
}

bool RespondToDialog(const int responseIndex) {
    runtimeState_t& state = State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    if (!state.dialogActive || state.dialogs.empty()
            || responseIndex < 0 || responseIndex >= 4) {
        return false;
    }
    idSWFScriptFunction* const callback =
        DialogCallback(state.dialogs.front(), responseIndex);
    if (callback != nullptr && frameworkHooks.invokeScriptCallback != nullptr) {
        frameworkHooks.invokeScriptCallback(callback);
    }
    RemoveDialogAt(state, 0);
    state.dialogActive = !state.dialogs.empty();
    return true;
}

void RenderDialogs(bool loading) {
    runtimeState_t& state = State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    const int now = DialogMilliseconds();
    for (idDialogInfo& dialog : state.dialogs) {
        if (dialog.waitClear && now >= dialog.killTime) {
            dialog.waitClear = false;
            dialog.clear = true;
        }
    }
    for (std::size_t index = 0; index < state.dialogs.size();) {
        const idDialogInfo& dialog = state.dialogs[index];
        if (dialog.clear || (loading && !dialog.renderDuringLoad)) {
            RemoveDialogAt(state, index);
        } else {
            ++index;
        }
    }
    state.dialogActive = !state.dialogs.empty();
}

} // namespace tech5Framework

void idCommonLocal::AddDialog(const gameDialogMessages_t message,
        const dialogType_t type, idSWFScriptFunction* const accept,
        idSWFScriptFunction* const cancel, const bool pause,
        const char*, int, const bool leaveOnReset, const bool waitOnAtlas,
        const bool renderDuringLoad) {
    idDialogInfo info;
    info.msg = message;
    info.type = type;
    info.acceptCB = accept;
    info.cancelCB = cancel;
    info.pause = pause;
    info.leaveOnClear = leaveOnReset;
    info.waitOnAtlas = waitOnAtlas;
    info.renderDuringLoad = renderDuringLoad;
    AddDialogInternal(info);
}

void idCommonLocal::AddDynamicDialog(const gameDialogMessages_t message,
        const idStaticList<idSWFScriptFunction*, 4>* const callbacks,
        const idStaticList<idStrId, 4>* const options, const bool pause,
        idStrStatic<256> text, const bool leaveOnReset,
        const bool waitOnAtlas, const bool renderDuringLoad) {
    idDialogInfo info;
    info.msg = message;
    info.type = DIALOG_DYNAMIC;
    info.pause = pause;
    info.leaveOnClear = leaveOnReset;
    info.waitOnAtlas = waitOnAtlas;
    info.renderDuringLoad = renderDuringLoad;
    info.overrideMsg = text;
    idSWFScriptFunction** callbackSlots[] = {
        &info.acceptCB, &info.cancelCB, &info.altCBOne, &info.altCBTwo
    };
    idStrId* optionSlots[] = {
        &info.txt1, &info.txt2, &info.txt3, &info.txt4
    };
    for (int index = 0; index < 4; ++index) {
        if (callbacks != nullptr && index < callbacks->Num()) {
            *callbackSlots[index] = (*callbacks)[index];
        }
        if (options != nullptr && index < options->Num()) {
            *optionSlots[index] = (*options)[index];
        }
    }
    AddDialogInternal(info);
}

void idCommonLocal::AddDialogIntVal(const char* const name,
        const int value) {
    if (name == nullptr) return;
    tech5Framework::runtimeState_t& state = tech5Framework::State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    state.dialogIntValues[name] = value;
}

bool idCommonLocal::HasDialogMsg(const gameDialogMessages_t message,
        bool* const isActive) {
    return tech5Framework::HasDialog(static_cast<int>(message), isActive);
}

void idCommonLocal::ClearDialog(const gameDialogMessages_t message,
        const char*, int) {
    tech5Framework::ClearDialog(static_cast<int>(message));
}

idStr idCommonLocal::GetDialogMsg(const gameDialogMessages_t message) const {
    bool prefix = false;
    const char* const key = DialogKey(message, prefix);
    idStr result;
    if (prefix) result.Format("#str_dlg_360_%s", key);
    else result = key;
    return result;
}

void idCommonLocal::RemoveWaitDialogs() {
    tech5Framework::RenderDialogs(false);
}

void idCommonLocal::ClearAllDialogHack() {
    tech5Framework::runtimeState_t& state = tech5Framework::State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    for (idDialogInfo& dialog : state.dialogs) {
        dialog.clear = true;
        dialog.waitClear = false;
    }
    state.dialogActive = false;
}

void idCommonLocal::ReleaseCallBacks(const int index) {
    tech5Framework::runtimeState_t& state = tech5Framework::State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    if (index >= 0 && index < static_cast<int>(state.dialogs.size())) {
        ReleaseDialogCallbacks(state.dialogs[static_cast<std::size_t>(index)]);
    }
}

bool idCommonLocal::HandleDialogEvent(const sysEvent_t* const event) {
    if (event == nullptr || event->evType != SE_KEY || event->evValue2 == 0
            || !IsDialogActive()) {
        return false;
    }
    if (event->evValue == K_ENTER || event->evValue == K_SPACE) {
        return tech5Framework::RespondToDialog(0);
    }
    if (event->evValue == K_ESCAPE) {
        return tech5Framework::RespondToDialog(1);
    }
    return true;
}

void idCommonLocal::ShowDialog(const idDialogInfo&, bool) {
    tech5Framework::State().dialogActive = true;
}

void idCommonLocal::ShowNextDialog(bool) {
    tech5Framework::runtimeState_t& state = tech5Framework::State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    state.dialogActive = !state.dialogs.empty();
}

void idCommonLocal::InitDialog() {
    tech5Framework::ClearDialogs(true);
}

void idCommonLocal::AddDialogInternal(idDialogInfo& info) {
    tech5Framework::QueueDialog(info);
}

void idCommonLocal::RenderDialog(const bool loading) {
    tech5Framework::RenderDialogs(loading);
}

void idCommonLocal::KillDialog() {
    tech5Framework::ClearDialogs(true);
}

void idCommonLocal::ActivateDialog(const bool active) {
    tech5Framework::runtimeState_t& state = tech5Framework::State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    state.dialogActive = active && !state.dialogs.empty();
}

void idCommonLocal::ClearDialogs(const bool force) {
    tech5Framework::ClearDialogs(force);
}

bool idCommonLocal::IsDialogActive() {
    return tech5Framework::IsDialogActive();
}

bool idCommonLocal::IsDialogPausing() {
    return tech5Framework::IsDialogPausing();
}

void RegisterDialogCommands() {
    tech5Framework::RegisterCommand("commonDialogClear",
        [](const std::vector<idStr>&) {
            commonLocal.ClearAllDialogHack();
            commonLocal.RenderDialog(false);
        });
    tech5Framework::RegisterCommand("testShowDialog",
        [](const std::vector<idStr>& args) {
            const int message = args.size() > 1
                ? std::atoi(args[1].c_str()) : GDM_INVALID;
            commonLocal.AddDialog(static_cast<gameDialogMessages_t>(message),
                DIALOG_ACCEPT, nullptr, nullptr, false);
        });
    tech5Framework::RegisterCommand("testShowDialogBug",
        [](const std::vector<idStr>& args) {
            commonLocal.ShowSaveIndicator(true, false);
            commonLocal.ShowSaveIndicator(false, false);
            const int message = args.size() > 1
                ? std::atoi(args[1].c_str()) : GDM_INVALID;
            commonLocal.AddDialog(static_cast<gameDialogMessages_t>(message),
                DIALOG_ACCEPT, nullptr, nullptr, false);
        });
    tech5Framework::RegisterCommand("testShowDynamicDialog",
        [](const std::vector<idStr>& args) {
            idStrStatic<256> text(args.size() > 1 ? args[1].c_str()
                : "Dynamic dialog test");
            commonLocal.AddDynamicDialog(GDM_INSUFFICENT_STORAGE_SPACE,
                nullptr, nullptr, false, text, false, false, false);
        });
}
