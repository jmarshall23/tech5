#pragma once

#include "idlib/containers/list.h"
#include "idlib/text/str.h"

class idComputeClusterInfo;
class idGenWorld;
class idPageGenClient;
class idPixelGenClient;
class idQualityPreset;
class idRenderBumpClient;
class idRenderWorld;
enum cloudMode_t : int;

class idCloud {
public:
	virtual ~idCloud() {}
	virtual bool IsAvailable() = 0;
	virtual bool IsRemote() = 0;
	virtual void Reset() = 0;
	virtual void Heartbeat() = 0;
	virtual int NumCloudServers() = 0;
	virtual int NumCommandsStillOutstanding() = 0;
	virtual idPageGenClient * GetPageGenClient() = 0;
	virtual idPixelGenClient * GetPixelGenClient() = 0;
	virtual idRenderBumpClient * GetRenderBumpClient() = 0;
	virtual void CloudStamp( idRenderWorld *, const idStr *, int, cloudMode_t,
		const idList< int, 5 > * ) = 0;
	virtual void CloudRadPreview( const idStr *, idGenWorld *, cloudMode_t ) = 0;
	virtual void CloudRenderBump( cloudMode_t ) = 0;
	virtual void GetClusterInfos( idList< idComputeClusterInfo, 5 > * ) = 0;
	virtual int GetNumQualityPresets() = 0;
	virtual const idQualityPreset * GetQualityPreset( int ) = 0;
	virtual void LoadQualityPresets() = 0;
	virtual int ProcessResponses() = 0;
	virtual bool LoadBuildCVars( const idStr * ) = 0;
	virtual void AddTraceFile( const idStr *, const idStr *, const idStr * ) = 0;
	virtual int GetOutstandingPages() = 0;
	virtual int GetOutstandingMips() = 0;
	virtual float GetPagesPerSecond() = 0;
	virtual float GetMipsPerSecond() = 0;
	virtual void ClearPendingWork() = 0;
};
