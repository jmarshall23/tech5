#include "game/entities/door_animated.h"

#include <algorithm>

namespace {
idDoorAnimatedServices defaultDoorAnimatedServices;
idDoorAnimatedServices* doorAnimatedServices =
    &defaultDoorAnimatedServices;

void ClearBounds(idBounds& bounds) {
    bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
}

void AddBounds(idBounds& destination, const idBounds& source) {
    for (int component = 0; component < 3; ++component) {
        destination[0][component] = std::min(destination[0][component],
            source[0][component]);
        destination[1][component] = std::max(destination[1][component],
            source[1][component]);
    }
}
}

int idDoorAnimatedServices::GetGameMilliseconds() const { return 0; }
bool idDoorAnimatedServices::HasAnimator(const idDoor_Animated&) const {
    return false;
}
void idDoorAnimatedServices::UpdateModelTransform(idDoor_Animated&) {}
void idDoorAnimatedServices::UpdateFrameCommands(idDoor_Animated&) {}
void idDoorAnimatedServices::UpdateAnimation(idDoor_Animated&) {}
void idDoorAnimatedServices::UpdateFX(idDoor_Animated&) {}
void idDoorAnimatedServices::UpdateDoorState(idDoor_Animated&) {}
void idDoorAnimatedServices::SetDoorState(idDoor_Animated&, idEntity*,
        idAnimatedDoorState) {}
void idDoorAnimatedServices::UpdateAASAreas(idDoor_Animated&) {}
void idDoorAnimatedServices::ActivateTargets(idDoor_Animated&, idEntity*) {}
void idDoorAnimatedServices::BecomeActive(idDoor_Animated&, int) {}
void idDoorAnimatedServices::BecomeInactive(idDoor_Animated&, int) {}
void idDoorAnimatedServices::PlaySound(idDoor_Animated&,
        const idSoundShader*, int) {}
bool idDoorAnimatedServices::IsLockedForEntity(
        const idDoor_Animated& door, const idEntity*, float) const {
    return door.locked;
}
bool idDoorAnimatedServices::IsActor(const idEntity*) const { return false; }
void idDoorAnimatedServices::AddMotionEvent(idDoor_Animated&,
        const idDeclAiEvent*, idEntity*, int, const idVec3&, int) {}
bool idDoorAnimatedServices::PlayAnimation(idDoor_Animated&,
        unsigned short, int) { return true; }
bool idDoorAnimatedServices::IsAnimationDone(
        const idDoor_Animated&, int) const { return true; }
idVec3 idDoorAnimatedServices::GetOrigin(
        const idDoor_Animated& door) const { return door.origin; }
void idDoorAnimatedServices::HideDoor(idDoor_Animated&) {}
void idDoorAnimatedServices::ShowDoor(idDoor_Animated&) {}
void idDoorAnimatedServices::UnlinkMainClip(idDoor_Animated&) {}
void idDoorAnimatedServices::LinkMainClip(idDoor_Animated&) {}
void idDoorAnimatedServices::HidePiece(idDoor_Animated&,
        idDoor_AnimatedPiece&) {}
void idDoorAnimatedServices::ShowPiece(idDoor_Animated&,
        idDoor_AnimatedPiece&) {}
void idDoorAnimatedServices::UnlinkPieceCollision(idDoor_Animated&,
        idDoor_AnimatedPiece&) {}
void idDoorAnimatedServices::LinkPieceCollision(idDoor_Animated&,
        idDoor_AnimatedPiece&) {}
void idDoorAnimatedServices::PresentPiece(idDoor_Animated&,
        idDoor_AnimatedPiece&) {}
bool idDoorAnimatedServices::GetDoorTransform(
        const idDoor_Animated& door, idVec3& resultOrigin,
        idMat3& resultAxis) const {
    resultOrigin = door.origin;
    resultAxis = door.axis;
    return true;
}
bool idDoorAnimatedServices::GetJointTransform(const idDoor_Animated&,
        short, idVec3&, idMat3&) const { return false; }
void idDoorAnimatedServices::PushPiece(idDoor_Animated&,
        idDoor_AnimatedPiece&, int, const idVec3&, const idMat3&) {}
idBounds idDoorAnimatedServices::GetPieceBounds(const idDoor_Animated&,
        const idDoor_AnimatedPiece& piece) const { return piece.bounds; }
idBounds idDoorAnimatedServices::GetPhysicsBounds(
        const idDoor_Animated& door) const { return door.bounds; }
int idDoorAnimatedServices::GetTracePhysicsId(const trace_t*) const {
    return -1;
}
void idDoorAnimatedServices::WarnInvalidJoint(const idDoor_Animated&,
        int, short) {}
bool idDoorAnimatedServices::IsGatherQuerySubmitted(std::uint64_t) const {
    return false;
}
bool idDoorAnimatedServices::GatheredQueryHasActor(std::uint64_t) const {
    return false;
}
std::uint64_t idDoorAnimatedServices::SubmitActorGather(
        const idBounds&, int) { return 0; }
float idDoorAnimatedServices::GetDoorClosingRange() const { return 0.0f; }
void idDoorAnimatedServices::InitializeAnimatorChannel(idDoor_Animated&) {}
short idDoorAnimatedServices::FindJointIndex(const idDoor_Animated&,
        const char*) const { return -1; }
idPresentableDoorAnimated*
idDoorAnimatedServices::AllocatePiecePresentable(idDoor_Animated&,
        idDoor_AnimatedPiece&) { return nullptr; }
void idDoorAnimatedServices::RegisterPiecePresentable(idDoor_Animated&,
        idDoor_AnimatedPiece&) {}
void idDoorAnimatedServices::DeletePiecePresentable(idDoor_Animated&,
        idDoor_AnimatedPiece&) {}
unsigned short idDoorAnimatedServices::LoadAnimationAlias(
        const idDoor_Animated&, const char*) const { return 0xFFFF; }
void idDoorAnimatedServices::WarnBadAnimation(const idDoor_Animated&,
        const char*, const char*) {}
void idDoorAnimatedServices::WarnMissingAnimator(const idDoor_Animated&) {}

void idDoor_Animated::SetServices(
        idDoorAnimatedServices* const services) {
    doorAnimatedServices = services == nullptr
        ? &defaultDoorAnimatedServices : services;
}

idDoorAnimatedServices& idDoor_Animated::Services() {
    return *doorAnimatedServices;
}

void idDoor_Animated::SetDoorState(idEntity* const activator,
        const idAnimatedDoorState newState) {
    state = newState;
    Services().SetDoorState(*this, activator, newState);
}

// Retail: 0x82C20630 ?SetLocked@idDoor_Animated@@UAAX_NPAVidEntity@@@Z
void idDoor_Animated::SetLocked(const bool lock, idEntity* const user) {
    if (locked == lock) {
        return;
    }
    locked = lock;
    if (!lock) {
        Services().PlaySound(*this, unlockSound, 0);
        if (IsClosed() && opensWhenUnlocked) {
            Use(user, USABLE_DOOR);
        }
    }
    Services().UpdateAASAreas(*this);
}

// Retail: 0x82C206F0 ?IsOpen@idDoor_Animated@@UBA_NXZ
bool idDoor_Animated::IsOpen() const {
    return state == ANIMATED_DOOR_OPENED;
}

// Retail: 0x82C20708 ?IsClosed@idDoor_Animated@@UBA_NXZ
bool idDoor_Animated::IsClosed() const {
    return state == ANIMATED_DOOR_CLOSED;
}

// Retail: 0x82C20720 ?GetUsableState@idDoor_Animated@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
int idDoor_Animated::GetUsableState(const idEntity*) const {
    if (playing) {
        return USABLE_NONE;
    }
    if (IsOpen() && playerUsable && playerCanClose) {
        return closeAnimHandle == INVALID_ANIMATION
            ? USABLE_NONE : USABLE_DOOR;
    }
    if (IsClosed() && playerUsable
            && (numMaxOpens == -1 || openCount < numMaxOpens)) {
        return openAnimHandle == INVALID_ANIMATION
            ? USABLE_NONE : USABLE_DOOR;
    }
    return USABLE_NONE;
}

// Retail: 0x82C20830 ?GetJointIndexFromTrace@idDoor_Animated@@UAA?AV?$idIndex@FW4invalidJointIndex_t@@@@Utrace_t@@@Z
short idDoor_Animated::GetJointIndexFromTrace(
        const trace_t* const trace) const {
    const int physicsId = Services().GetTracePhysicsId(trace);
    for (int index = 0; index < collisionParts.Num(); ++index) {
        if (collisionParts[index].presentable != nullptr
                && collisionParts[index].physicsId == physicsId) {
            return collisionParts[index].jointIndex;
        }
    }
    return -1;
}

// Retail: 0x82C208B8 ?Use@idDoor_Animated@@UAA_NPAVidEntity@@W4usableState_t@@@Z
bool idDoor_Animated::Use(idEntity* const user, int) {
    if (!Services().HasAnimator(*this)) {
        return false;
    }
    Services().UpdateModelTransform(*this);
    if (playing) {
        return false;
    }
    if (Services().IsLockedForEntity(*this, user, 0.0f)
            || (IsOpen() && Services().IsActor(user)
                && !playerCanClose)) {
        Services().PlaySound(*this, lockedSound, 0);
        return false;
    }

    unsigned short animation = INVALID_ANIMATION;
    if (IsClosed()) {
        animation = openAnimHandle;
    } else if (IsOpen()) {
        animation = closeAnimHandle;
    }
    Services().AddMotionEvent(*this, motionEventDecl, user,
        Services().GetGameMilliseconds(), Services().GetOrigin(*this),
        1000);
    if (animation == INVALID_ANIMATION) {
        return false;
    }
    Services().PlayAnimation(*this, animation,
        Services().GetGameMilliseconds());
    thinkFlags |= 5;
    Services().BecomeActive(*this, 4);
    Services().BecomeActive(*this, 1);
    playing = true;
    if (IsOpen()) {
        SetDoorState(user, ANIMATED_DOOR_CLOSING);
    } else {
        SetDoorState(user, ANIMATED_DOOR_OPENING);
        if (user != reinterpret_cast<idEntity*>(this)) {
            ++openCount;
        }
        if (triggerTargetsOnOpen) {
            Services().ActivateTargets(*this, user);
        }
        if (forceUnusableWhenOpened) {
            forcedUnusable = true;
        }
    }
    return true;
}

// Retail: 0x82C20B80 ?Hide@idDoor_Animated@@UAAXXZ
void idDoor_Animated::Hide() {
    hidden = true;
    Services().HideDoor(*this);
    thinkFlags &= ~7;
    Services().BecomeInactive(*this, 7);
    for (int index = 0; index < collisionParts.Num(); ++index) {
        idDoor_AnimatedPiece& piece = collisionParts[index];
        piece.hidden = true;
        piece.collisionLinked = false;
        Services().HidePiece(*this, piece);
        Services().UnlinkPieceCollision(*this, piece);
    }
    mainClipLinked = false;
    Services().UnlinkMainClip(*this);
}

// Retail: 0x82C20C18 ?Show@idDoor_Animated@@UAAXXZ
void idDoor_Animated::Show() {
    hidden = false;
    Services().ShowDoor(*this);
    thinkFlags |= 4;
    Services().BecomeActive(*this, 4);
    for (int index = 0; index < collisionParts.Num(); ++index) {
        idDoor_AnimatedPiece& piece = collisionParts[index];
        piece.hidden = false;
        piece.collisionLinked = true;
        Services().ShowPiece(*this, piece);
        Services().LinkPieceCollision(*this, piece);
    }
    mainClipLinked = true;
    Services().LinkMainClip(*this);
}

// Retail: 0x82C20D28 ?UpdateCollisionParts@idDoor_Animated@@AAAXAAVidBounds@@_N@Z
void idDoor_Animated::UpdateCollisionParts(idBounds& updatedBounds,
        const bool push) {
    if (!Services().HasAnimator(*this)) {
        return;
    }
    Services().UpdateModelTransform(*this);
    ClearBounds(updatedBounds);
    for (int index = 0; index < collisionParts.Num(); ++index) {
        idDoor_AnimatedPiece& piece = collisionParts[index];
        if (piece.presentable == nullptr) {
            continue;
        }
        idVec3 newOrigin;
        idMat3 newAxis;
        bool haveTransform = false;
        if (piece.jointIndex < 0) {
            Services().WarnInvalidJoint(*this, index, piece.jointIndex);
            haveTransform = Services().GetDoorTransform(
                *this, newOrigin, newAxis);
        } else {
            haveTransform = Services().GetJointTransform(
                *this, piece.jointIndex, newOrigin, newAxis);
            if (haveTransform && push) {
                Services().PushPiece(*this, piece, pushFlags,
                    newOrigin, newAxis);
            }
        }
        if (!haveTransform) {
            continue;
        }
        piece.origin = newOrigin;
        piece.axis = newAxis;
        Services().PresentPiece(*this, piece);
        piece.bounds = Services().GetPieceBounds(*this, piece);
        AddBounds(updatedBounds, piece.bounds);
    }
}

// Retail: 0x82C210E0 ?CanClose@idDoor_Animated@@EBA_N_N@Z
bool idDoor_Animated::CanClose(bool) const {
    if (!testForActorsWhenClosing) {
        return true;
    }
    if (Services().IsGatherQuerySubmitted(canCloseQuery)) {
        return !Services().GatheredQueryHasActor(canCloseQuery);
    }
    idBounds gatherBounds = bounds;
    AddBounds(gatherBounds, Services().GetPhysicsBounds(*this));
    const float range = Services().GetDoorClosingRange();
    const idVec3 extension(range, range, range);
    gatherBounds[0] = gatherBounds[0] - extension;
    gatherBounds[1] = gatherBounds[1] + extension;
    canCloseQuery = Services().SubmitActorGather(gatherBounds, 33792);
    return false;
}

// Retail: 0x82C21278 ?Think@idDoor_Animated@@UAAXXZ
void idDoor_Animated::Think() {
    if (!Services().HasAnimator(*this)) {
        return;
    }
    Services().UpdateModelTransform(*this);
    Services().UpdateFrameCommands(*this);
    const int currentTime = Services().GetGameMilliseconds();
    if (playing && Services().IsAnimationDone(*this, currentTime)) {
        playing = false;
        if (state == ANIMATED_DOOR_CLOSING) {
            SetDoorState(reinterpret_cast<idEntity*>(this),
                ANIMATED_DOOR_CLOSED);
        } else if (state == ANIMATED_DOOR_OPENING) {
            SetDoorState(reinterpret_cast<idEntity*>(this),
                ANIMATED_DOOR_OPENED);
            if (msUntilClose >= 0) {
                autoCloseTime = currentTime + msUntilClose;
            }
        }
    }
    if (msUntilClose >= 0 && state == ANIMATED_DOOR_OPENED
            && currentTime >= autoCloseTime) {
        Use(reinterpret_cast<idEntity*>(this), USABLE_DOOR);
    }
    Services().UpdateAnimation(*this);
    Services().UpdateFX(*this);
    idBounds updatedBounds;
    UpdateCollisionParts(updatedBounds, true);
    Services().UpdateDoorState(*this);
    if (state == ANIMATED_DOOR_CLOSED
            || state == ANIMATED_DOOR_BROKEN
            || (msUntilClose < 0 && state == ANIMATED_DOOR_OPENED)) {
        thinkFlags &= ~7;
        Services().BecomeInactive(*this, 7);
    }
}

// Retail: 0x82C21458 ?Spawn@idDoor_Animated@@QAAXXZ
void idDoor_Animated::Spawn() {
    SetDoorState(reinterpret_cast<idEntity*>(this), ANIMATED_DOOR_CLOSED);
    Services().InitializeAnimatorChannel(*this);
    const bool hasAnimator = Services().HasAnimator(*this);
    for (int index = 0; index < collisionParts.Num(); ++index) {
        idDoor_AnimatedPiece& piece = collisionParts[index];
        piece.jointIndex = !piece.joint.IsEmpty() && hasAnimator
            ? Services().FindJointIndex(*this, piece.joint.c_str()) : -1;
        piece.presentable = Services().AllocatePiecePresentable(*this, piece);
        if (piece.presentable != nullptr) {
            Services().RegisterPiecePresentable(*this, piece);
        }
    }
    thinkFlags |= 4;
    Services().BecomeActive(*this, 4);
    Services().UpdateAnimation(*this);
    idBounds spawnedBounds;
    UpdateCollisionParts(spawnedBounds, false);
    bounds = spawnedBounds;
    if (hasAnimator) {
        openAnimHandle = Services().LoadAnimationAlias(
            *this, openAnim.c_str());
        closeAnimHandle = Services().LoadAnimationAlias(
            *this, closeAnim.c_str());
        if (!lockAnim.IsEmpty()) {
            lockAnimHandle = Services().LoadAnimationAlias(
                *this, lockAnim.c_str());
        }
        if (!unlockAnim.IsEmpty()) {
            unlockAnimHandle = Services().LoadAnimationAlias(
                *this, unlockAnim.c_str());
        }
        if (openAnimHandle == INVALID_ANIMATION) {
            Services().WarnBadAnimation(*this, "open", openAnim.c_str());
        }
        if (closeAnimHandle == INVALID_ANIMATION) {
            Services().WarnBadAnimation(*this, "close", closeAnim.c_str());
        }
    } else {
        Services().WarnMissingAnimator(*this);
    }
}

// Retail: 0x82C21840 ??0idDoor_Animated@@QAA@XZ
idDoor_Animated::idDoor_Animated()
    : usableByAI(false), locked(false), opensWhenUnlocked(false),
      forcedUnusable(false), forceUnusableWhenOpened(false),
      playerUsable(false), lockedSound(nullptr), unlockSound(nullptr),
      motionEventDecl(nullptr), state(ANIMATED_DOOR_UNKNOWN), bounds(),
      origin(0.0f, 0.0f, 0.0f), axis(1.0f), pushFlags(40),
      openAnim("open"), closeAnim("close"), lockAnim("lock"),
      unlockAnim("unlock"), msUntilClose(-1),
      triggerTargetsOnOpen(false), playerCanClose(true), numMaxOpens(-1),
      collisionParts(), testForActorsWhenClosing(false), autoCloseTime(0),
      playing(false), openCount(0), openAnimHandle(INVALID_ANIMATION),
      closeAnimHandle(INVALID_ANIMATION), lockAnimHandle(INVALID_ANIMATION),
      unlockAnimHandle(INVALID_ANIMATION), canCloseQuery(~0ULL),
      thinkFlags(0), hidden(false), mainClipLinked(true) {
    ClearBounds(bounds);
}

// Retail: 0x82C21A80 ??1idDoor_Animated@@UAA@XZ
idDoor_Animated::~idDoor_Animated() {
    for (int index = 0; index < collisionParts.Num(); ++index) {
        idDoor_AnimatedPiece& piece = collisionParts[index];
        if (piece.presentable != nullptr) {
            Services().DeletePiecePresentable(*this, piece);
            piece.presentable = nullptr;
        }
    }
    collisionParts.Clear();
}
