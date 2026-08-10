#include "globalshadows.h"

#include "renderworld_local.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <string>

namespace {
	unsigned short Swap16( unsigned short value ) {
		return static_cast< unsigned short >( ( value >> 8 ) | ( value << 8 ) );
	}
	void SwapFloat( float & value ) {
		unsigned char * bytes = reinterpret_cast< unsigned char * >( &value );
		std::swap( bytes[0], bytes[3] );
		std::swap( bytes[1], bytes[2] );
	}
}

shadowMap_t::shadowMap_t() : width( 1024 ), map( nullptr ),
	coordinateBias( -0.5f ), depthBias( -40.0f ), useShadowMap( true ) {
	mvp.Identity();
}
shadowMap_t::~shadowMap_t() { delete[] map; }

float shadowMap_t::ShadowSample( const idVec3 & worldPoint ) const {
	if ( !useShadowMap || map == nullptr || width < 2 ) return 1.0f;
	idVec4 projected;
	mvp.TransformPoint( worldPoint, projected );
	if ( std::fabs( projected.w ) <= 1.0e-20f ) return 1.0f;
	const float inverseW = 1.0f / projected.w;
	const float u = projected.x * inverseW * width + coordinateBias;
	const float v = projected.y * inverseW * width + coordinateBias;
	const float depth = std::max( 0.0f, std::min( 1.0f,
		projected.z * inverseW ) ) * 65535.0f + depthBias;
	int x = static_cast< int >( std::floor( u ) );
	int y = static_cast< int >( std::floor( v ) );
	const float fx = std::max( 0.0f, std::min( 1.0f, u - std::floor( u ) ) );
	const float fy = std::max( 0.0f, std::min( 1.0f, v - std::floor( v ) ) );
	x = std::max( 0, std::min( x, width - 2 ) );
	y = std::max( 0, std::min( y, width - 2 ) );
	float visible = 0.0f;
	for ( int row = 0; row < 2; ++row ) for ( int column = 0; column < 2; ++column ) {
		const float weight = ( column != 0 ? fx : 1.0f - fx ) *
			( row != 0 ? fy : 1.0f - fy );
		const unsigned short stored = map[( y + row ) * width + x + column];
		if ( stored > depth ) visible += weight;
		else if ( stored == static_cast< unsigned short >( depth ) )
			visible += weight * ( 1.0f - ( depth - std::floor( depth ) ) );
	}
	return visible;
}

idGlobalShadows::idGlobalShadows() : shadowMap( new shadowMap_t() ) {}
idGlobalShadows::~idGlobalShadows() { delete shadowMap; shadowMap = nullptr; }
float idGlobalShadows::ShadowSample( const idVec3 & point ) const {
	return shadowMap != nullptr ? shadowMap->ShadowSample( point ) : 1.0f;
}
const shadowMap_t * idGlobalShadows::GetShadowMap() const { return shadowMap; }

void idGlobalShadows::LoadGlobalShadows( idRenderWorldLocal * world ) {
	if ( shadowMap == nullptr ) shadowMap = new shadowMap_t();
	delete[] shadowMap->map;
	shadowMap->map = nullptr;
	shadowMap->mvp.Identity();
	if ( world == nullptr || world->mapName.Length() == 0 ) return;
	const std::string path = std::string( world->mapName.c_str() ) +
		"/globalShadows2.bin";
	std::ifstream file( path, std::ios::binary );
	if ( !file ) return;
	file.read( reinterpret_cast< char * >( shadowMap->mvp.m ),
		sizeof( shadowMap->mvp.m ) );
	if ( !file ) { shadowMap->mvp.Identity(); return; }
	for ( float & value : shadowMap->mvp.m ) SwapFloat( value );
	shadowMap->width = 1024;
	const std::size_t samples = static_cast< std::size_t >(
		shadowMap->width ) * shadowMap->width;
	shadowMap->map = new unsigned short[samples];
	file.read( reinterpret_cast< char * >( shadowMap->map ),
		static_cast< std::streamsize >( samples * sizeof( unsigned short ) ) );
	if ( !file ) {
		delete[] shadowMap->map;
		shadowMap->map = nullptr;
		return;
	}
	for ( std::size_t index = 0; index < samples; ++index )
		shadowMap->map[index] = Swap16( shadowMap->map[index] );
}

void idGlobalShadows::WriteShadowVisualizationModel( const char * ) {}
