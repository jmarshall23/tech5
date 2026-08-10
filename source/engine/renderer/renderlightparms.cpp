#include "renderlightparms.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace {

float SafeInverse( const float value ) {
	return std::fabs( value ) > 1.0e-20f ? 1.0f / value : 0.0f;
}

idVec3 NormalizedOr( const idVec3 & value, const idVec3 & fallback ) {
	const float lengthSquared = value.x * value.x + value.y * value.y +
		value.z * value.z;
	if ( lengthSquared <= 1.0e-30f ) {
		return fallback;
	}
	return value * ( 1.0f / std::sqrt( lengthSquared ) );
}

float Dot( const idVec3 & a, const idVec3 & b ) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

}

idRenderLightParms::idRenderLightParms() :
	axis( 1.0f ),
	origin( 0.0f, 0.0f, 0.0f ),
	allowLightOnlyInViewID( 0 ),
	suppressLightInViewID( 0 ),
	lightType( LIGHT_POINT ),
	lightClass( LIGHT_NORMAL ),
	lightFalloff( LIGHT_FALLOFF_TEXTURE ),
	noShadows( false ),
	slowLight( false ),
	shader( nullptr ),
	lightRadius( 300.0f, 300.0f, 300.0f ),
	lightCenter( 0.0f, 0.0f, 0.0f ),
	target( 0.0f, 0.0f, -256.0f ),
	right( 128.0f, 0.0f, 0.0f ),
	up( 0.0f, 128.0f, 0.0f ),
	start( 0.0f, 0.0f, 8.0f ),
	end( 0.0f, 0.0f, 256.0f ),
	dynamicModelLightingScale( 1.0f, 1.0f, 1.0f ),
	dimShadowStretch( 1.0f ),
	maxVisibleRange( 0.0f ),
	fadeVisibilityOver( 400.0f ),
	staticSpecularScale( 1.0f ),
	staticSpecularVector( 0.0f, 0.0f, 0.0f ),
	bakedParallelShadows( false ),
	iesFile( nullptr ),
	iesPowerScale( 1.0f ),
	iesAreaScale( 1.0f ),
	areaLightSize( 0.0f ),
	shadowSampleScale( 1.0f ),
	slowMultiPass( 0 ) {
}

void idRenderLightParms::ComputePointLightProjectionMatrix(
		idRenderMatrix & localProject ) const {
	std::memset( localProject.m, 0, sizeof( localProject.m ) );
	localProject.m[0] = 0.5f * SafeInverse( lightRadius.x );
	localProject.m[5] = 0.5f * SafeInverse( lightRadius.y );
	localProject.m[10] = 0.5f * SafeInverse( lightRadius.z );
	localProject.m[3] = localProject.m[7] = localProject.m[11] = 0.5f;
	localProject.m[15] = 1.0f;
}

void idRenderLightParms::ComputeSpotLightProjectionMatrix(
		idRenderMatrix & localProject ) const {
	// This is the scalar PC spelling of the recovered VMX body.  S and T are
	// formed from the authored right/up vectors, while Q follows the target.
	const float targetLengthSquared = Dot( target, target );
	const float rightLengthSquared = Dot( right, right );
	const float upLengthSquared = Dot( up, up );
	const idVec3 q = NormalizedOr( target, idVec3( 0.0f, 0.0f, -1.0f ) );
	const float targetLength = std::sqrt( std::max( targetLengthSquared,
		1.0e-30f ) );
	const float qScale = targetLength;

	std::memset( localProject.m, 0, sizeof( localProject.m ) );
	const float rightScale = targetLength * 0.5f *
		SafeInverse( rightLengthSquared );
	const float upScale = -targetLength * 0.5f *
		SafeInverse( upLengthSquared );
	localProject.m[0] = right.x * rightScale;
	localProject.m[1] = right.y * rightScale;
	localProject.m[2] = right.z * rightScale;
	localProject.m[4] = up.x * upScale;
	localProject.m[5] = up.y * upScale;
	localProject.m[6] = up.z * upScale;
	localProject.m[12] = q.x * qScale;
	localProject.m[13] = q.y * qScale;
	localProject.m[14] = q.z * qScale;

	float endDistance = Dot( end, q ) - 16.0f;
	float startDistance = Dot( start, q ) - 8.0f;
	if ( endDistance < 0.0f ) endDistance = 0.0f;
	if ( startDistance > 0.0f ) startDistance = 0.0f;
	if ( std::fabs( endDistance ) < 1.0e-20f ) endDistance = 1.0f;
	const float depthScale = ( endDistance + startDistance ) / endDistance;
	localProject.m[8] = q.x * qScale * depthScale;
	localProject.m[9] = q.y * qScale * depthScale;
	localProject.m[10] = q.z * qScale * depthScale;
	localProject.m[11] = -depthScale * startDistance;

	idVec4 projectedTarget;
	localProject.TransformPoint( target, projectedTarget );
	if ( std::fabs( projectedTarget.w ) > 1.0e-20f ) {
		const float ofsS = -( projectedTarget.x / projectedTarget.w - 0.5f );
		const float ofsT = -( projectedTarget.y / projectedTarget.w - 0.5f );
		for ( int column = 0; column < 4; ++column ) {
			localProject.m[column] += localProject.m[12 + column] * ofsS;
			localProject.m[4 + column] += localProject.m[12 + column] * ofsT;
		}
	}
}

void idRenderLightParms::ComputeWorldToLightMatrix(
		idRenderMatrix & baseLightProject,
		idRenderMatrix & inverseBaseLightProject ) const {
	idRenderMatrix localProject;
	if ( lightType == LIGHT_SPOT ) {
		ComputeSpotLightProjectionMatrix( localProject );
	} else {
		ComputePointLightProjectionMatrix( localProject );
	}

	idRenderMatrix lightTransform;
	idRenderMatrix::FromOriginAxisScale( origin, axis,
		idVec3( 1.0f, 1.0f, 1.0f ), lightTransform );
	idRenderMatrix inverseTransform;
	if ( !idRenderMatrix::Inverse( lightTransform, inverseTransform ) ) {
		inverseTransform.Identity();
	}
	idRenderMatrix::Multiply( localProject, inverseTransform,
		baseLightProject );
	if ( !idRenderMatrix::Inverse( baseLightProject,
			inverseBaseLightProject ) ) {
		inverseBaseLightProject.Identity();
	}
}

void idRenderLightParms::ComputeLightGlobalOrigin(
		idVec3 & globalOrigin ) const {
	if ( lightType == LIGHT_PARALLEL ) {
		globalOrigin = origin + NormalizedOr( lightCenter,
			idVec3( 0.0f, 0.0f, 1.0f ) ) * 100000.0f;
	} else if ( lightType == LIGHT_SPOT ) {
		globalOrigin = origin;
	} else {
		globalOrigin = origin + idVec3(
			axis[0].x * lightCenter.x + axis[1].x * lightCenter.y +
				axis[2].x * lightCenter.z,
			axis[0].y * lightCenter.x + axis[1].y * lightCenter.y +
				axis[2].y * lightCenter.z,
			axis[0].z * lightCenter.x + axis[1].z * lightCenter.y +
				axis[2].z * lightCenter.z );
	}
}

void idRenderLightParms::ComputeLightGlobalReferenceBounds(
		idBounds & globalReferenceBounds, idVec3 * corners ) const {
	idRenderMatrix project;
	idRenderMatrix inverseProject;
	ComputeWorldToLightMatrix( project, inverseProject );
	globalReferenceBounds[0].Set( 1.0e30f, 1.0e30f, 1.0e30f );
	globalReferenceBounds[1].Set( -1.0e30f, -1.0e30f, -1.0e30f );
	for ( int cornerIndex = 0; cornerIndex < 8; ++cornerIndex ) {
		const idVec4 local(
			( cornerIndex & 1 ) != 0 ? 1.0f : 0.0f,
			( cornerIndex & 2 ) != 0 ? 1.0f : 0.0f,
			( cornerIndex & 4 ) != 0 ? 1.0f : 0.0f,
			1.0f );
		idVec4 world;
		inverseProject.TransformPoint( local, world );
		const float inverseW = SafeInverse( world.w );
		const idVec3 point( world.x * inverseW, world.y * inverseW,
			world.z * inverseW );
		if ( corners != nullptr ) corners[cornerIndex] = point;
		for ( int axisIndex = 0; axisIndex < 3; ++axisIndex ) {
			globalReferenceBounds[0][axisIndex] = std::min(
				globalReferenceBounds[0][axisIndex], point[axisIndex] );
			globalReferenceBounds[1][axisIndex] = std::max(
				globalReferenceBounds[1][axisIndex], point[axisIndex] );
		}
	}
}
