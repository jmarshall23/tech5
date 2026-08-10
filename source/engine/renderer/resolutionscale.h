#pragma once

#include "../../shared/idlib/metrics/metrics.h"
#include "../../shared/idlib/text/str.h"

class idResolutionScale {
public:
	idResolutionScale();
	void InitForMap( const char * mapName );
	void GetCurrentResolutionScale( float & x, float & y ) const;
	void SetCurrentGPUFrameTime( unsigned int microseconds );
	void LogMetrics();
	void GetConsoleText( idStr & text ) const;

	static void SetMode( int mode );
	static int GetMode();

	float dropMilliseconds;
	float raiseMilliseconds;
	int framesAboveRaise;
	float currentResolution;
	idGaugeMetric resolutionScaleMetricX;
	idGaugeMetric resolutionScaleMetricY;
};

extern idResolutionScale resolutionScale;
