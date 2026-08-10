#pragma once

#include "../../../engine/decls/decltypeinfo.h"
#include "game/entities/entityptr.h"
#include "idlib/color.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

class idEntity;
class idSoundShader;
class idSplinePath;
template<typename T> class idCurve_Spline;

class idDeclCameraTrigger : public idDeclTypeInfo {
public:
    enum cam_move_t : int {
        CAM_MOVE_NONE = 0,
        CAM_MOVE_SPLINE = 1,
        CAM_MOVE_POSITION = 2,
        CAM_MOVE_ENTITY = 3,
        CAM_MOVE_PLAYER = 4,
        CAM_MOVE_PLAYER_VEHICLE = 5,
        CAM_MOVE_VEHICLE_DEFAULT = 6,
        CAM_MOVE_ENTITY_POSITION = 7,
        CAM_MOVE_ACTIVATOR = 8,
        CAM_MOVE_ACTIVATOR_POSITION = 9,
        CAM_MOVE_PLAYER_POSITION = 10,
        CAM_MOVE_PLAYER_VEHICLE_POSITION = 11,
        CAM_MOVE_CIRCLE_ENTITY = 12,
        CAM_MOVE_CIRCLE_PLAYER = 13,
        CAM_MOVE_CIRCLE_PLAYER_VEHICLE = 14,
        CAM_MOVE_RADIAL_ENTITY = 15,
        CAM_MOVE_RADIAL_PLAYER = 16,
        CAM_MOVE_RADIAL_PLAYER_VEHICLE = 17
    };

    enum cam_focus_t : int {
        CAM_FOCUS_NONE = 0,
        CAM_FOCUS_MOVEPATH = 1,
        CAM_FOCUS_SPLINE = 2,
        CAM_FOCUS_ACTIVATOR = 3,
        CAM_FOCUS_ACTIVATOR_POSITION = 4,
        CAM_FOCUS_PLAYER = 5,
        CAM_FOCUS_PLAYER_VEHICLE = 6,
        CAM_FOCUS_VEHICLE_DEFAULT = 7,
        CAM_FOCUS_ENTITY = 8,
        CAM_FOCUS_ENTITY_POSITION = 9,
        CAM_FOCUS_POSITION = 10,
        CAM_FOCUS_POSITION_LERP = 11
    };

    enum cam_showhud_t : int {
        CAM_SHOWHUD_NULL = 0,
        CAM_SHOWHUD_NO = 1,
        CAM_SHOWHUD_YES = 2
    };

    struct idSplineMove {
        idSplinePath* path;
        float dist;
        int sc;
    };

    struct idTimeLerpHelper {
        float duration;
        float easeInTime;
        float easeOutTime;
        bool looping;
        int startTimeOfs;
    };

    struct idTrigMovement {
        idTrigMovement();

        cam_move_t moveType;
        idSplineMove spline;
        idVec3 position;
        idEntityPtr<idEntity> entity;
        idVec3 entityOffset;
        float scalarOffset;
        idTimeLerpHelper timing;
        idTimeLerpHelper frameLerp;
        idVec3 additionalOffset;
        idVec3 viewOrigin;
    };

    struct idTrigFocus {
        idTrigFocus();

        cam_focus_t focusType;
        idSplineMove spline;
        float splineTime;
        idEntityPtr<idEntity> entity;
        idVec3 position;
        idAngles pathAdjust;
        idVec3 focusOffset;
        idTimeLerpHelper frameLerp;
        idMat3 viewAxis;
        idVec3 lastKnownPosition;
    };

    struct idTrigFade {
        idColor color;
        float transTime;
        bool timeScaleFade;
        bool activate;
    };

    struct idTrigTimeScale {
        float scale;
        idTimeLerpHelper timing;
        float initScale;
    };

    struct idTrigFovZoom {
        float angle;
        idTimeLerpHelper timing;
    };

    struct idTrigActivateEnt {
        idList<idEntityPtr<idEntity>, 5> entity;
    };

    struct idTrigSounds {
        idList<const idSoundShader*, 5> sound;
    };

    struct idTrigDof {
        float blurStart;
        float blurScale;
        idTimeLerpHelper timing;
        idVec3 vec;
    };

    struct idTrigShakeView {
        float shakeVolume;
        bool activate;
    };

    struct idTrigRenderParms {
        float fogScale;
        idColor fogColor;
        idTimeLerpHelper timing;
    };

    struct idTrigMisc {
        bool endCinematic;
        bool notifyGUI;
        bool suspendCamera;
        cam_showhud_t showHud;
    };

    struct idCameraTriggerParms {
        idStr title;
        float offsetTime;
        idTrigMovement movement;
        idTrigFocus focus;
        idTrigFade fade;
        idTrigTimeScale timeScale;
        idTrigFovZoom fovZoom;
        idTrigActivateEnt activate;
        idTrigSounds sounds;
        idTrigDof depthOfField;
        idTrigShakeView shakeView;
        idTrigRenderParms renderParms;
        idTrigMisc misc;
        bool triggered;
    };

    struct idCameraTriggerState {
        idTrigMovement movement;
        idTrigFocus focus;
        idTrigFade fade;
        idTrigTimeScale timeScale;
        idTrigFovZoom fovZoom;
        idTrigDof depthOfField;
        idTrigShakeView shakeView;
        idTrigRenderParms renderParms;
        idTrigMisc misc;
    };

    struct idSplineCurve {
        idSplinePath* splinePath;
        idCurve_Spline<idVec3>* curve;
        float length;
        idVec3 lastOrigin;
    };

    idDeclCameraTrigger();
    ~idDeclCameraTrigger() override;

    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    idList<idCameraTriggerParms, 5> triggers;

    static idDeclInfoTemplate<idDeclCameraTrigger> resourceList;
};

// ??0idTrigMovement@idDeclCameraTrigger@@QAA@XZ (0x82592608)
inline idDeclCameraTrigger::idTrigMovement::idTrigMovement()
    : moveType(CAM_MOVE_NONE), spline{nullptr, 0.0f, 0},
      position(0.0f, 0.0f, 0.0f), entity(),
      entityOffset(0.0f, 0.0f, 0.0f), scalarOffset(0.0f),
      timing{0.0f, 0.0f, 0.0f, false, 0},
      frameLerp{0.0f, 0.0f, 0.0f, false, 0},
      additionalOffset(0.0f, 0.0f, 0.0f),
      viewOrigin(0.0f, 0.0f, 0.0f) {
}

// ??0idTrigFocus@idDeclCameraTrigger@@QAA@XZ (0x825926D8)
inline idDeclCameraTrigger::idTrigFocus::idTrigFocus()
    : focusType(CAM_FOCUS_NONE), spline{nullptr, 0.0f, 0}, splineTime(1.0f),
      entity(), position(0.0f, 0.0f, 0.0f), pathAdjust(0.0f, 0.0f, 0.0f),
      focusOffset(0.0f, 0.0f, 0.0f),
      frameLerp{0.0f, 0.0f, 0.0f, false, 0}, viewAxis(1.0f),
      lastKnownPosition(0.0f, 0.0f, 0.0f) {
}

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclCameraTrigger::idTimeLerpHelper) == 20,
    "Recovered camera time-lerp ABI changed");
static_assert(sizeof(idDeclCameraTrigger::idTrigMovement) == 112,
    "Recovered camera movement-trigger ABI changed");
static_assert(sizeof(idDeclCameraTrigger::idTrigFocus) == 128,
    "Recovered camera focus-trigger ABI changed");
static_assert(sizeof(idDeclCameraTrigger::idCameraTriggerParms) == 484,
    "Recovered camera trigger-parameter ABI changed");
static_assert(sizeof(idDeclCameraTrigger) == 80,
    "Recovered camera-trigger declaration ABI changed");
#endif
