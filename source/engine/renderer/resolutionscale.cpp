#include "resolutionscale.h"

#include "../../shared/idlib/lib_print.h"

#include <algorithm>
#include <cstdio>

namespace {
	int resolutionScaleMode = 0;
	constexpr float MINIMUM_SCALE = 0.5f;
	constexpr float DROP_FRACTION = 0.11f;
	constexpr float RAISE_FRACTION = 0.06f;
	constexpr int RAISE_FRAMES = 5;
}

idResolutionScale resolutionScale;

idResolutionScale::idResolutionScale() : dropMilliseconds( 15.0f ),
	raiseMilliseconds( 13.0f ), framesAboveRaise( 0 ), currentResolution( 1.0f ),
	resolutionScaleMetricX( idStr( "resolutionScaleX" ),
		idStr( "horizontal resolution scaling" ) ),
	resolutionScaleMetricY( idStr( "resolutionScaleY" ),
		idStr( "vertical resolution scaling" ) ) {}

void idResolutionScale::SetMode( const int mode ) {
	resolutionScaleMode = (std::max)( 0, (std::min)( mode, 3 ) );
}

int idResolutionScale::GetMode() { return resolutionScaleMode; }

void idResolutionScale::InitForMap( const char * mapName ) {
	const bool expensiveWastelandMap = mapName != nullptr && (
		idStr::Icmp( mapName, "maps/game/wasteland1/wellspring" ) == 0 ||
		idStr::Icmp( mapName, "maps/game/wasteland1/scientist" ) == 0 ||
		idStr::Icmp( mapName, "maps/game/wasteland1/bash_tv_entrance" ) == 0 ||
		idStr::Icmp( mapName, "maps/game/wasteland2/subway_town" ) == 0 );
	dropMilliseconds = expensiveWastelandMap ? 16.0f : 15.0f;
	raiseMilliseconds = expensiveWastelandMap ? 15.0f : 13.0f;
	framesAboveRaise = 0;
}

void idResolutionScale::GetCurrentResolutionScale( float & x, float & y ) const {
	x = ( resolutionScaleMode & 2 ) != 0 ? currentResolution : 1.0f;
	y = ( resolutionScaleMode & 1 ) != 0 ? currentResolution : 1.0f;
}

void idResolutionScale::SetCurrentGPUFrameTime( const unsigned int microseconds ) {
	if ( resolutionScaleMode == 0 ) return;
	const float milliseconds = microseconds * 0.001f;
	if ( milliseconds > dropMilliseconds ) {
		currentResolution = (std::max)( MINIMUM_SCALE, currentResolution - DROP_FRACTION );
		framesAboveRaise = 0;
	} else if ( milliseconds < raiseMilliseconds ) {
		if ( ++framesAboveRaise >= RAISE_FRAMES ) {
			currentResolution = (std::min)( 1.0f, currentResolution + RAISE_FRACTION );
			framesAboveRaise = 0;
		}
	} else framesAboveRaise = 0;
}

void idResolutionScale::LogMetrics() {
	float x, y;
	GetCurrentResolutionScale( x, y );
	resolutionScaleMetricX.Log( x );
	resolutionScaleMetricY.Log( y );
}

void idResolutionScale::GetConsoleText( idStr & text ) const {
	if ( resolutionScaleMode == 0 ) { text = "rs-off"; return; }
	float x, y;
	GetCurrentResolutionScale( x, y );
	char buffer[64];
	std::snprintf( buffer, sizeof( buffer ), "%2i%%h,%2i%%v",
		static_cast< int >( x * 100.0f ), static_cast< int >( y * 100.0f ) );
	text = buffer;
}
