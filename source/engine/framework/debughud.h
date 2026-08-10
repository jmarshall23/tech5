#pragma once

#include "idlib/color.h"
#include "idlib/containers/list.h"
#include "idlib/text/str.h"

#include <cstdarg>

class idMaterial;
class idRenderModelGui;

class idDebugHUD {
public:
    virtual ~idDebugHUD() = default;
    virtual void Render(idRenderModelGui*) = 0;
    virtual void Frame() = 0;
    virtual void Clear(bool) = 0;
    virtual void Printf(const char*, ...) = 0;
    virtual void VPrintf(int, int, const char*, va_list) = 0;
    virtual void Printf(int, int, const char*, ...) = 0;
    virtual void VPrintf(int, int, const idColor&, const idColor&,
        const char*, va_list) = 0;
    virtual void Printf(int, int, const idColor&, const idColor&,
        const char*, ...) = 0;
    virtual void VPrintf(int, int, const idColor&, const char*, va_list) = 0;
    virtual void Printf(int, int, const idColor&, const char*, ...) = 0;
    virtual void Printf(int, int, const idColor&, float, const char*, ...) = 0;
    virtual void VPrintf(int, int, const idColor&, float, int,
        const char*, va_list) = 0;
    virtual void Printf(int, int, const idColor&, const idColor&, float,
        const char*, ...) = 0;
    virtual void VPrintf(int, int, const idColor&, const idColor&, float,
        int, const char*, va_list) = 0;
    virtual void AddPersistentText(int, int, const idColor&, float,
        const char*, ...) = 0;
    virtual void RemovePersistentText(int, int) = 0;
    virtual void SetLeftAlign() = 0;
    virtual void SetRightAlign() = 0;
    virtual void SetTextPosition(int, int) = 0;
    virtual void SetTextScale(float) = 0;
    virtual void SetTextColor(const idColor&) = 0;
};

class idDebugHUDLocal : public idDebugHUD {
public:
    enum debugTextFlags_t : int { DTFL_COLOR=1, DTFL_SCALE=2, DTFL_XY=4,
        DTFL_RIGHTALIGN=8, DTFL_PERSIST=16, DTFL_BACKGROUNDCOLOR=32 };
    struct debugText_t { idStr text; int len; int x; int y; idColor color;
        int flags; float scale; idColor backgroundColor; };

    idDebugHUDLocal();
    ~idDebugHUDLocal() override = default;
    void Render(idRenderModelGui*) override;
    void Frame() override;
    void Clear(bool) override;
    void Printf(const char*, ...) override;
    void VPrintf(int, int, const char*, va_list) override;
    void Printf(int, int, const char*, ...) override;
    void VPrintf(int, int, const idColor&, const idColor&, const char*,
        va_list) override;
    void Printf(int, int, const idColor&, const idColor&, const char*,
        ...) override;
    void VPrintf(int, int, const idColor&, const char*, va_list) override;
    void Printf(int, int, const idColor&, const char*, ...) override;
    void Printf(int, int, const idColor&, float, const char*, ...) override;
    void VPrintf(int, int, const idColor&, float, int, const char*,
        va_list) override;
    void Printf(int, int, const idColor&, const idColor&, float,
        const char*, ...) override;
    void VPrintf(int, int, const idColor&, const idColor&, float, int,
        const char*, va_list) override;
    void AddPersistentText(int, int, const idColor&, float, const char*,
        ...) override;
    void RemovePersistentText(int, int) override;
    void SetLeftAlign() override;
    void SetRightAlign() override;
    void SetTextPosition(int, int) override;
    void SetTextScale(float) override;
    void SetTextColor(const idColor&) override;

    idList<debugText_t, 5> debugText;
    idList<debugText_t, 5> persistentText;
    idColor curColor;
    float curScale;
    int curX;
    int curY;
    int startX;
    bool alignRight;
    const idMaterial* white;

private:
    void AppendFormatted(idList<debugText_t, 5>& destination, int x, int y,
        const idColor& color, const idColor& background, float scale,
        int flags, const char* format, va_list arguments);
};

extern idDebugHUDLocal debugHUDLocal;
extern idDebugHUD* debugHUD;
