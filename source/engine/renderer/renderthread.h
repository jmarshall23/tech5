#pragma once

#include "idlib/sys/sys_threading.h"
#include "models/rendermodel.h"

// D3D9 devices are created with multithread protection, but ownership is
// still transferred explicitly around background present work.
class alignas( 4 ) idRenderThread : public idSysThread {
public:
	idRenderThread();
	~idRenderThread() override;
	int Run() override;

	void * hdc;
	renderMode_t renderMode;
	renderMode_t renderModeBeforeSync;
	bool initialized;
};
