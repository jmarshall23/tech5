#include "approximatelighting.h"

#include "../../renderlightcommitted.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace {
	float Clamp01( float value ) {
		return std::max( 0.0f, std::min( value, 1.0f ) );
	}

	bool IsPrivateLight( lightClass_t lightClass ) {
		return lightClass == LIGHT_SLOWLIGHT_PRIVATE_ONLY ||
			lightClass == LIGHT_PRIVATE_DYNAMIC_ONLY ||
			lightClass == LIGHT_PRIVATE_PRIME;
	}

	float ColorMagnitude( const idVec3 & color ) {
		return color.x * color.x + color.y * color.y + color.z * color.z;
	}

	void AddDirectionalChannels( approximateLighting_t & lighting,
			const idVec3 & direction, const idVec3 & color ) {
		const float weights[6] = {
			std::max( direction.x, 0.0f ), std::max( -direction.x, 0.0f ),
			std::max( direction.y, 0.0f ), std::max( -direction.y, 0.0f ),
			std::max( direction.z, 0.0f ), std::max( -direction.z, 0.0f ) };
		for ( int channel = 0; channel < 6; ++channel ) {
			lighting.channelLighting[channel].x += color.x * weights[channel];
			lighting.channelLighting[channel].y += color.y * weights[channel];
			lighting.channelLighting[channel].z += color.z * weights[channel];
		}
	}
}

bool CalculateLightContribution( const idRenderLightCommitted * light,
		const shadowMap_t * shadowMap, const idVec3 & samplePoint,
		idVec3 & lightDir, idVec3 & lightColor ) {
	lightDir.Zero();
	lightColor.Zero();
	if ( light == nullptr ) return false;
	idVec4 projected;
	light->baseLightProject.TransformPoint( samplePoint, projected );
	if ( std::fabs( projected.w ) <= 1.0e-20f ) return false;
	const float inverseW = 1.0f / projected.w;
	const float x = projected.x * inverseW;
	const float y = projected.y * inverseW;
	const float z = projected.z * inverseW;
	float attenuation = 1.0f;
	if ( light->r.lightType == LIGHT_PARALLEL ) {
		if ( x < 0.0f || x > 1.0f || y < 0.0f || y > 1.0f ||
				z < 0.0f || z > 1.0f ) return false;
		attenuation *= shadowMap != nullptr
			? shadowMap->ShadowSample( samplePoint ) : 1.0f;
		lightDir = light->r.lightCenter;
		if ( lightDir.NormalizeFast() == 0.0f )
			lightDir.Set( 0.0f, 0.0f, 1.0f );
	} else {
		const float radial = 4.0f * ( ( x - 0.5f ) * ( x - 0.5f ) +
			( y - 0.5f ) * ( y - 0.5f ) );
		if ( radial >= 1.0f ) return false;
		if ( radial >= 0.25f ) attenuation *=
			1.0f - ( std::sqrt( radial ) - 0.5f ) * 2.0f;
		if ( light->r.lightType == LIGHT_SPOT ) {
			if ( z < 0.0f || z > 1.0f ) return false;
		} else if ( light->r.lightType == LIGHT_POINT ) {
			const float axial = std::fabs( ( z - 0.5f ) * 2.0f );
			if ( axial > 1.0f ) return false;
			if ( axial >= 0.5f ) attenuation *=
				1.0f - ( axial - 0.5f ) * 2.0f;
		}
		lightDir = light->globalLightOrigin - samplePoint;
		if ( lightDir.NormalizeFast() == 0.0f ) return false;
	}
	if ( attenuation <= 0.0f ) return false;
	lightColor = light->currentColor * attenuation;
	return ColorMagnitude( lightColor ) > 1.0e-12f;
}

void LocalLighting( const approximateLightingParms_t * parms ) {
	if ( parms == nullptr || parms->lighting == nullptr ) return;
	approximateLighting_t output = {};
	output.lightingModel.x = static_cast< float >( LM_LOCAL_LIGHTS );
	int localCount = 0;
	for ( int index = 0; index < parms->numLights && localCount < 3; ++index ) {
		const idRenderLightCommitted * const light = parms->lights[index];
		if ( light == nullptr || light->r.lightFalloff != LIGHT_FALLOFF_RADIAL )
			continue;
		idVec3 delta = light->globalLightOrigin - parms->samplePoint;
		const float distance = delta.Length();
		const float radius = std::max( light->r.lightRadius.x, 1.0f );
		const float attenuation = Clamp01( 1.0f -
			std::min( distance, radius - 1.0f ) / radius );
		const idVec3 color = light->currentColor * attenuation;
		output.primeLightDir.x += delta.x * attenuation;
		output.primeLightDir.y += delta.y * attenuation;
		output.primeLightDir.z += delta.z * attenuation;
		output.primeLightColor.x += color.x;
		output.primeLightColor.y += color.y;
		output.primeLightColor.z += color.z;
		output.channelLighting[localCount * 2].Set(
			light->globalLightOrigin.x, light->globalLightOrigin.y,
			light->globalLightOrigin.z, radius );
		output.channelLighting[localCount * 2 + 1].Set(
			light->currentColor.x, light->currentColor.y,
			light->currentColor.z, 0.0f );
		++localCount;
	}
	idVec3 direction( output.primeLightDir.x,
		output.primeLightDir.y, output.primeLightDir.z );
	if ( direction.NormalizeFast() != 0.0f ) {
		output.primeLightDir.x = direction.x;
		output.primeLightDir.y = direction.y;
		output.primeLightDir.z = direction.z;
	}
	*parms->lighting = output;
}

void ApproximateLightingJob( const approximateLightingParms_t * parms ) {
	if ( parms == nullptr || parms->lighting == nullptr ) return;
	if ( parms->lightingModel == LM_LOCAL_LIGHTS ) {
		LocalLighting( parms );
		return;
	}
	if ( parms->contributions != nullptr ) {
		for ( int index = 0; index < 16; ++index ) {
			parms->contributions[index].light = nullptr;
			parms->contributions[index].color.Zero();
		}
	}
	approximateLighting_t output = {};
	output.lightingModel.x = static_cast< float >( LM_PRIME_AND_CHANNEL );
	ambientColors_t ambient = {};
	if ( !parms->noAmbient && parms->ambientMap != nullptr )
		parms->ambientMap->AmbientSample( parms->samplePoint, &ambient );
	const float ambientScale = parms->ambientChannelScale / 255.0f;
	for ( int channel = 0; channel < 6; ++channel ) {
		output.channelLighting[channel].Set(
			ambient.channels[channel][0] * ambientScale,
			ambient.channels[channel][1] * ambientScale,
			ambient.channels[channel][2] * ambientScale, 0.0f );
	}
	if ( parms->noApproximateLighting ) {
		*parms->lighting = output;
		return;
	}
	float strongest = -1.0f;
	int contributionCount = 0;
	for ( int index = 0; index < parms->numLights; ++index ) {
		const idRenderLightCommitted * const light = parms->lights[index];
		if ( light == nullptr || IsPrivateLight( light->r.lightClass ) !=
				parms->privateLightOnly || light->r.lightClass == LIGHT_PRELIGHT_ONLY )
			continue;
		idVec3 direction;
		idVec3 color;
		if ( !CalculateLightContribution( light, parms->shadowMap,
				parms->samplePoint, direction, color ) ) continue;
		color.x *= light->r.dynamicModelLightingScale.x *
			parms->dynamicLightingScale;
		color.y *= light->r.dynamicModelLightingScale.y *
			parms->dynamicLightingScale;
		color.z *= light->r.dynamicModelLightingScale.z *
			parms->dynamicLightingScale;
		if ( parms->contributions != nullptr && contributionCount < 16 ) {
			parms->contributions[contributionCount].light = light;
			parms->contributions[contributionCount].color = color;
		}
		++contributionCount;
		const float magnitude = ColorMagnitude( color ) *
			std::max( light->r.staticSpecularScale, 0.0f );
		if ( light->r.lightClass == LIGHT_PRIVATE_PRIME || magnitude > strongest ) {
			strongest = magnitude;
			output.primeLightDir.Set( direction.x, direction.y, direction.z,
				light->castsShadows ? 0.0f : 1.0f );
			output.primeLightColor.Set( color.x * parms->primeLightScale,
				color.y * parms->primeLightScale,
				color.z * parms->primeLightScale, 0.0f );
		}
		AddDirectionalChannels( output, direction,
			color * parms->directChannelScale );
	}
	*parms->lighting = output;
}
