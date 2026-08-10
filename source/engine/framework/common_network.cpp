#include "framework/framework_runtime_internal.h"

#include "framework/common_local.h"
#include "framework/game.h"
#include "framework/resourcelist.h"
#include "framework/usercmdgen.h"
#include "idlib/networking/bitmsg.h"

#include <algorithm>
#include <cstring>

namespace tech5Framework {
void QueueNetworkMessage(const networkMessage_t& message) { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); state.networkMessages.push_back(message); }
bool PopNetworkMessage(networkMessage_t& message) { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); if (state.networkMessages.empty()) return false; message = std::move(state.networkMessages.front()); state.networkMessages.pop_front(); return true; }
void ClearNetworkMessages() { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); state.networkMessages.clear(); }
} // namespace tech5Framework

bool idCommonLocal::IsLosingConnectionToHost() {
    return losingConnection;
}

void idCommonLocal::NetReceiveReliable(const int type, idBitMsg* const input,
        const int peer) {
    if (game != nullptr) {
        game->NetReceiveReliable(type, input, peer);
        return;
    }
    tech5Framework::networkMessage_t message;
    message.peer = peer;
    message.type = type;
    if (input != nullptr && input->GetReadData() != nullptr
            && input->GetSize() > 0) {
        message.payload.assign(input->GetReadData(),
            input->GetReadData() + input->GetSize());
    }
    tech5Framework::QueueNetworkMessage(message);
}

namespace {
int FloatBits(const float value) {
    int bits = 0;
    static_assert(sizeof(bits) == sizeof(value), "float wire size changed");
    std::memcpy(&bits, &value, sizeof(bits));
    return bits;
}

float BitsFloat(const int bits) {
    float value = 0.0f;
    std::memcpy(&value, &bits, sizeof(value));
    return value;
}
} // namespace

void idCommonLocal::WriteUserCmdDelta(idBitMsg& message,
        const usercmd_t& command, const usercmd_t* const base) {
    if (base != nullptr) {
        message.WriteDeltaLongCounter(base->clientGameFrame,
            command.clientGameFrame);
        message.WriteDelta(base->buttons, command.buttons, 32);
        message.WriteDelta(base->forwardmove, command.forwardmove, -8);
        message.WriteDelta(base->rightmove, command.rightmove, -8);
        message.WriteDelta(base->upmove, command.upmove, -8);
        for (int index = 0; index < 3; ++index) {
            message.WriteDelta(base->angles[index], command.angles[index], -16);
        }
        for (int index = 0; index < 3; ++index) {
            message.WriteDelta(FloatBits(base->pos[index]),
                FloatBits(command.pos[index]), 32);
        }
        message.WriteDelta(base->pitch, command.pitch, -16);
        message.WriteDelta(base->yaw, command.yaw, -16);
        message.WriteDelta(base->roll, command.roll, -16);
        message.WriteDelta(base->predictionStateBits,
            command.predictionStateBits, 8);
        message.WriteDelta(base->vehicleThrottle,
            command.vehicleThrottle, 8);
        message.WriteDeltaLongCounter(base->serverGameTime,
            command.serverGameTime);
        message.WriteDeltaShortCounter(base->fireCount, command.fireCount);
        for (int index = 0; index < 2; ++index) {
            message.WriteDelta(base->fireAngles[index],
                command.fireAngles[index], -16);
        }
        for (int index = 0; index < 3; ++index) {
            message.WriteDelta(base->firePos[index], command.firePos[index],
                -16);
        }
        message.WriteDelta(base->speed, command.speed, 8);
    } else {
        message.WriteBits(command.clientGameFrame, 32);
        message.WriteBits(command.buttons, 32);
        message.WriteBits(command.forwardmove, -8);
        message.WriteBits(command.rightmove, -8);
        message.WriteBits(command.upmove, -8);
        for (int index = 0; index < 3; ++index) {
            message.WriteBits(command.angles[index], -16);
        }
        for (int index = 0; index < 3; ++index) {
            message.WriteBits(FloatBits(command.pos[index]), 32);
        }
        message.WriteBits(command.pitch, -16);
        message.WriteBits(command.yaw, -16);
        message.WriteBits(command.roll, -16);
        message.WriteBits(command.predictionStateBits, 8);
        message.WriteBits(command.vehicleThrottle, 8);
        message.WriteBits(command.serverGameTime, 32);
        message.WriteBits(command.fireCount, -16);
        for (int index = 0; index < 2; ++index) {
            message.WriteBits(command.fireAngles[index], -16);
        }
        for (int index = 0; index < 3; ++index) {
            message.WriteBits(command.firePos[index], -16);
        }
        message.WriteBits(command.speed, 8);
    }
    message.WriteBits(command.inhibited ? 1 : 0, 1);
}

void idCommonLocal::ReadUserCmdDelta(const idBitMsg& message,
        usercmd_t& command, const usercmd_t* const base) {
    command.Clear();
    if (base != nullptr) {
        command.clientGameFrame = message.ReadDeltaLongCounter(
            base->clientGameFrame);
        command.buttons = message.ReadDelta(base->buttons, 32);
        command.forwardmove = static_cast<char>(message.ReadDelta(
            base->forwardmove, -8));
        command.rightmove = static_cast<char>(message.ReadDelta(
            base->rightmove, -8));
        command.upmove = static_cast<char>(message.ReadDelta(base->upmove, -8));
        for (int index = 0; index < 3; ++index) {
            command.angles[index] = static_cast<std::int16_t>(
                message.ReadDelta(base->angles[index], -16));
        }
        for (int index = 0; index < 3; ++index) {
            command.pos[index] = BitsFloat(message.ReadDelta(
                FloatBits(base->pos[index]), 32));
        }
        command.pitch = static_cast<std::int16_t>(
            message.ReadDelta(base->pitch, -16));
        command.yaw = static_cast<std::int16_t>(
            message.ReadDelta(base->yaw, -16));
        command.roll = static_cast<std::int16_t>(
            message.ReadDelta(base->roll, -16));
        command.predictionStateBits = static_cast<unsigned char>(
            message.ReadDelta(base->predictionStateBits, 8));
        command.vehicleThrottle = static_cast<unsigned char>(
            message.ReadDelta(base->vehicleThrottle, 8));
        command.serverGameTime = message.ReadDeltaLongCounter(
            base->serverGameTime);
        command.fireCount = static_cast<std::uint16_t>(
            message.ReadDeltaShortCounter(base->fireCount));
        for (int index = 0; index < 2; ++index) {
            command.fireAngles[index] = static_cast<std::int16_t>(
                message.ReadDelta(base->fireAngles[index], -16));
        }
        for (int index = 0; index < 3; ++index) {
            command.firePos[index] = static_cast<std::int16_t>(
                message.ReadDelta(base->firePos[index], -16));
        }
        command.speed = static_cast<unsigned char>(
            message.ReadDelta(base->speed, 8));
    } else {
        command.clientGameFrame = message.ReadBits(32);
        command.buttons = message.ReadBits(32);
        command.forwardmove = static_cast<char>(message.ReadBits(-8));
        command.rightmove = static_cast<char>(message.ReadBits(-8));
        command.upmove = static_cast<char>(message.ReadBits(-8));
        for (int index = 0; index < 3; ++index) {
            command.angles[index] = static_cast<std::int16_t>(
                message.ReadBits(-16));
        }
        for (int index = 0; index < 3; ++index) {
            command.pos[index] = BitsFloat(message.ReadBits(32));
        }
        command.pitch = static_cast<std::int16_t>(message.ReadBits(-16));
        command.yaw = static_cast<std::int16_t>(message.ReadBits(-16));
        command.roll = static_cast<std::int16_t>(message.ReadBits(-16));
        command.predictionStateBits = static_cast<unsigned char>(
            message.ReadBits(8));
        command.vehicleThrottle = static_cast<unsigned char>(
            message.ReadBits(8));
        command.serverGameTime = message.ReadBits(32);
        command.fireCount = static_cast<std::uint16_t>(message.ReadBits(-16));
        for (int index = 0; index < 2; ++index) {
            command.fireAngles[index] = static_cast<std::int16_t>(
                message.ReadBits(-16));
        }
        for (int index = 0; index < 3; ++index) {
            command.firePos[index] = static_cast<std::int16_t>(
                message.ReadBits(-16));
        }
        command.speed = static_cast<unsigned char>(message.ReadBits(8));
    }
    command.inhibited = message.ReadBits(1) != 0;
}

void idCommonLocal::NetReceiveSnapshot(idSnapShot*) {
    snapshotsStalled = false;
}

void idCommonLocal::NetReceiveUsercmds(idBitMsg*) {
    losingConnection = false;
}

int idCommonLocal::NetWriteResources(idLZWCompressor*, const int start,
        const int max, bool) {
    const int count = idResourceList::GetNumNetworkResources();
    if (start < 0 || start >= count) return 0;
    return (std::min)(count - start, (std::max)(max, 0));
}

void idCommonLocal::NetReadResources(idLZWCompressor*) {
    idResourceList::ResetNetworkResources();
}

int idCommonLocal::GetSnapRate() { return snapRate; }
bool idCommonLocal::SnapshotsAreStalled() { return snapshotsStalled; }
bool idCommonLocal::AllowCheats() { return !multiplayer || server; }
idRenderVideoOverlay* idCommonLocal::VideoOverlay() {
    return videoOverlay;
}
idFile* idCommonLocal::GetLogfile() { return logFileWriter.logFile; }
