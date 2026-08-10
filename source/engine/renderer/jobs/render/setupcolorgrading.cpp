#include "setupcolorgrading.h"

#include "../../declrenderparm.h"
#include "../../image.h"
#include "parmstate.h"

#include <algorithm>
#include <cmath>

namespace {
	idVec4 Parm( const idDeclRenderParm * parm, const idVec4 & fallback ) {
		if ( parm == nullptr || renderThreadParmState == nullptr ||
				parm->parmIndex < 0 || parm->parmIndex >= RENDERPARM_INVALID )
			return fallback;
		const parmValue_t & value = renderThreadParmState->values[parm->parmIndex];
		return idVec4( value.value[0], value.value[1],
			value.value[2], value.value[3] );
	}

	float Saturate( float value ) {
		return std::max( 0.0f, std::min( value, 1.0f ) );
	}

	float Tone( float value, float shadow, float midtone, float highlight ) {
		const float shadowWeight = Saturate( 1.0f - value * 2.0f );
		const float highlightWeight = Saturate( value * 2.0f - 1.0f );
		const float midWeight = 1.0f - shadowWeight - highlightWeight;
		return Saturate( value + shadow * shadowWeight +
			midtone * midWeight + highlight * highlightWeight );
	}
}

void SetupColorGrading( const setupColorGradingParms_t * parms ) {
	if ( parms == nullptr || parms->imageLUT == nullptr ||
			renderThreadParmState == nullptr ) return;
	idImage * const image = parms->imageLUT;
	const idVec4 zero( 0.0f, 0.0f, 0.0f, 0.0f );
	const idVec4 shadow = Parm( parms->rpCGShadow, zero );
	const idVec4 midtone = Parm( parms->rpCGMidtone, zero );
	const idVec4 highlight = Parm( parms->rpCGHighlight, zero );
	const idVec4 dodge = Parm( parms->rpCGColorDodgeBlend, zero );
	const idVec4 burn = Parm( parms->rpCGColorBurnBlend, zero );
	const idVec4 multiply = Parm( parms->rpCGColorMultiplyBlend, zero );
	const idVec4 screen = Parm( parms->rpCGColorScreenBlend, zero );
	const idVec4 black = Parm( parms->rpCGBlackLevel, zero );
	if ( image->GetTexture() != nullptr &&
			image->GetTexture()->GetType() == D3DRTYPE_TEXTURE ) {
		IDirect3DTexture9 * const texture =
			static_cast< IDirect3DTexture9 * >( image->GetTexture() );
		D3DLOCKED_RECT lock = {};
		if ( SUCCEEDED( texture->LockRect( 0, &lock, nullptr, 0 ) ) ) {
			const int width = std::max( image->opts.width, 1 );
			const int height = std::max( image->opts.height, 1 );
			const int cubeSize = std::max( height, 2 );
			for ( int y = 0; y < height; ++y ) {
				unsigned int * row = reinterpret_cast< unsigned int * >(
					static_cast< unsigned char * >( lock.pBits ) + y * lock.Pitch );
				for ( int x = 0; x < width; ++x ) {
					float channel[3] = {
						static_cast< float >( x % cubeSize ) / ( cubeSize - 1 ),
						static_cast< float >( y ) / std::max( height - 1, 1 ),
						static_cast< float >( x / cubeSize ) /
							std::max( width / cubeSize - 1, 1 ) };
					const float corrections[3][3] = {
						{ shadow.x, midtone.x, highlight.x },
						{ shadow.y, midtone.y, highlight.y },
						{ shadow.z, midtone.z, highlight.z } };
					for ( int component = 0; component < 3; ++component ) {
						float value = Tone( channel[component],
							corrections[component][0], corrections[component][1],
							corrections[component][2] );
						value = Saturate( value - black[component] );
						value *= 1.0f + multiply[component] * ( value - 1.0f );
						const float screened = 1.0f - ( 1.0f - value ) *
							( 1.0f - value );
						value += ( screened - value ) * screen[component];
						const float dodged = value /
							std::max( 1.0f - value, 1.0f / 255.0f );
						value += ( Saturate( dodged ) - value ) * dodge[component];
						const float burned = 1.0f - ( 1.0f - value ) /
							std::max( value, 1.0f / 255.0f );
						channel[component] = Saturate( value +
							( Saturate( burned ) - value ) * burn[component] );
					}
					const unsigned int r = static_cast< unsigned int >(
						channel[0] * 255.0f + 0.5f );
					const unsigned int g = static_cast< unsigned int >(
						channel[1] * 255.0f + 0.5f );
					const unsigned int b = static_cast< unsigned int >(
						channel[2] * 255.0f + 0.5f );
					row[x] = 0xFF000000u | ( r << 16 ) | ( g << 8 ) | b;
				}
			}
			texture->UnlockRect( 0 );
		}
	}
	if ( parms->rpColorGradingLUT != nullptr ) {
		parmValue_t value = {};
		value.image = image;
		renderThreadParmState->SetParmValue(
			parms->rpColorGradingLUT->parmIndex, value );
	}
}
