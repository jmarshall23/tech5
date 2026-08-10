#pragma once

#include "idlib/text/str.h"

class idRadPreviewToolIface;

class idRadPreview {
public:
	virtual ~idRadPreview() {}
	virtual bool Start( idRadPreviewToolIface *, const idStr * ) = 0;
	virtual void Stop() = 0;
	virtual void Update() = 0;
	virtual void SignalWorldChanged( int ) = 0;
	virtual void Pause( bool ) = 0;
	virtual void Unpause() = 0;
	virtual void RebuildGeometry() = 0;
};
