#include "ambientlighting.h"

#include "renderworld_local.h"

#include "idlib/geometry/winding.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <limits>
#include <string>

namespace {
	unsigned char ClampByte( float value ) {
		return static_cast< unsigned char >( std::max( 0.0f,
			std::min( value, 255.0f ) ) + 0.5f );
	}

	bool ValidSample( const ambientMap_t & map, unsigned int index ) {
		return map.data != nullptr && index <
			static_cast< unsigned int >( std::max( map.data->numSamples, 0 ) );
	}
}

ambientMap_t::ambientMap_t() : data( nullptr ), dataLen( 0 ),
	useForcedColors( false ), nodes( nullptr ), samples( nullptr ) {
	std::memset( &forcedColors, 0, sizeof( forcedColors ) );
}

ambientMap_t::~ambientMap_t() {
	delete[] reinterpret_cast< unsigned char * >( data );
}

void ambientMap_t::SamplesForPoint( const idVec3 & worldPoint, int cube[4],
		ambientSample_t cubeSamples[8] ) const {
	std::memset( cubeSamples, 0, sizeof( ambientSample_t ) * 8 );
	cube[0] = cube[1] = cube[2] = -32768;
	cube[3] = 65536;
	if ( data == nullptr || nodes == nullptr || samples == nullptr ||
			data->numNodes <= 0 || data->numSamples <= 0 ) return;

	int minimum[3] = { -32768, -32768, -32768 };
	int maximum[3] = { 32768, 32768, 32768 };
	unsigned int nodeIndex = 0;
	unsigned short child = 0x8000u;
	for ( int depth = 0; depth < 32; ++depth ) {
		if ( nodeIndex >= static_cast< unsigned int >( data->numNodes ) ) break;
		const ambientNode_t & node = nodes[nodeIndex];
		const int middle[3] = {
			( minimum[0] + maximum[0] ) / 2,
			( minimum[1] + maximum[1] ) / 2,
			( minimum[2] + maximum[2] ) / 2 };
		const int bits = ( worldPoint.x >= middle[0] ? 1 : 0 ) |
			( worldPoint.y >= middle[1] ? 2 : 0 ) |
			( worldPoint.z >= middle[2] ? 4 : 0 );
		child = node.children[bits];
		if ( ( child & 0x8000u ) != 0 ) {
			bool cornerLeafs = true;
			for ( int corner = 0; corner < 8; ++corner )
				cornerLeafs &= ( node.children[corner] & 0x8000u ) != 0;
			if ( cornerLeafs ) {
				for ( int corner = 0; corner < 8; ++corner ) {
					const unsigned int sampleIndex =
						node.children[corner] & 0x7fffu;
					if ( ValidSample( *this, sampleIndex ) )
						cubeSamples[corner] = samples[sampleIndex];
				}
			} else {
				const unsigned int sampleIndex = child & 0x7fffu;
				if ( ValidSample( *this, sampleIndex ) )
					for ( int corner = 0; corner < 8; ++corner )
						cubeSamples[corner] = samples[sampleIndex];
			}
			cube[0] = minimum[0]; cube[1] = minimum[1]; cube[2] = minimum[2];
			cube[3] = maximum[0] - minimum[0];
			return;
		}
		for ( int axis = 0; axis < 3; ++axis ) {
			if ( ( bits & ( 1 << axis ) ) != 0 ) minimum[axis] = middle[axis];
			else maximum[axis] = middle[axis];
		}
		nodeIndex = child;
	}
}

void ambientMap_t::AmbientSample( const idVec3 & worldPoint,
		ambientColors_t * lighting ) const {
	if ( lighting == nullptr ) return;
	if ( useForcedColors ) {
		*lighting = forcedColors;
		return;
	}
	std::memset( lighting, 0, sizeof( *lighting ) );
	if ( data == nullptr ) return;
	int cube[4];
	ambientSample_t corners[8];
	SamplesForPoint( worldPoint, cube, corners );
	const float inverseSize = cube[3] > 0 ? 1.0f / cube[3] : 0.0f;
	const float fraction[3] = {
		std::max( 0.0f, std::min( 1.0f,
			( worldPoint.x - cube[0] ) * inverseSize ) ),
		std::max( 0.0f, std::min( 1.0f,
			( worldPoint.y - cube[1] ) * inverseSize ) ),
		std::max( 0.0f, std::min( 1.0f,
			( worldPoint.z - cube[2] ) * inverseSize ) ) };
	for ( int channel = 0; channel < 6; ++channel ) {
		for ( int color = 0; color < 3; ++color ) {
			float value = 0.0f;
			for ( int corner = 0; corner < 8; ++corner ) {
				float weight = 1.0f;
				for ( int axis = 0; axis < 3; ++axis )
					weight *= ( corner & ( 1 << axis ) ) != 0
						? fraction[axis] : 1.0f - fraction[axis];
				value += corners[corner].colors.channels[channel][color] * weight;
			}
			lighting->channels[channel][color] = ClampByte( value );
		}
	}
}

idAmbientLighting::idAmbientLighting() : ambientMap( new ambientMap_t() ) {}
idAmbientLighting::~idAmbientLighting() { FreeData(); }

void idAmbientLighting::FreeData() {
	delete ambientMap;
	ambientMap = nullptr;
}

void idAmbientLighting::DebugDrawAmbientLightingSamples(
		idRenderWorldLocal * world, const idVec3 & position ) const {
	if ( world == nullptr || ambientMap == nullptr || ambientMap->data == nullptr ) return;
	int cube[4];
	ambientSample_t samples[8];
	ambientMap->SamplesForPoint( position, cube, samples );
	const idVec4 red( 1.0f, 0.0f, 0.0f, 1.0f );
	for ( int corner = 0; corner < 8; ++corner ) {
		DebugDrawColoredCube( world, &samples[corner], 4.0f );
		const idVec3 cubeCorner(
			static_cast< float >( cube[0] + ( ( corner & 1 ) != 0 ? cube[3] : 0 ) ),
			static_cast< float >( cube[1] + ( ( corner & 2 ) != 0 ? cube[3] : 0 ) ),
			static_cast< float >( cube[2] + ( ( corner & 4 ) != 0 ? cube[3] : 0 ) ) );
		const idVec3 sampleOrigin( static_cast< float >( samples[corner].origin[0] ),
			static_cast< float >( samples[corner].origin[1] ),
			static_cast< float >( samples[corner].origin[2] ) );
		world->DebugLine( &red, &cubeCorner, &sampleOrigin, 1, true );
	}
}
void idAmbientLighting::DebugDrawColoredCube( idRenderWorldLocal * world,
		const ambientSample_t * sample, const float size ) const {
	if ( world == nullptr || sample == nullptr || size <= 0.0f ) return;
	const idVec3 center( static_cast< float >( sample->origin[0] ),
		static_cast< float >( sample->origin[1] ),
		static_cast< float >( sample->origin[2] ) );
	const float radius = size * 0.5f;
	idVec3 corners[8];
	for ( int corner = 0; corner < 8; ++corner ) {
		corners[corner] = center + idVec3(
			( corner & 1 ) != 0 ? radius : -radius,
			( corner & 2 ) != 0 ? radius : -radius,
			( corner & 4 ) != 0 ? radius : -radius );
	}
	static const int faces[6][4] = {
		{ 0, 4, 6, 2 }, { 1, 3, 7, 5 }, { 0, 1, 5, 4 },
		{ 2, 6, 7, 3 }, { 0, 2, 3, 1 }, { 4, 5, 7, 6 }
	};
	for ( int face = 0; face < 6; ++face ) {
		idWinding winding;
		for ( int vertex = 0; vertex < 4; ++vertex )
			winding.AddPoint( corners[faces[face][vertex]] );
		const idVec4 color(
			sample->colors.channels[face][0] / 255.0f,
			sample->colors.channels[face][1] / 255.0f,
			sample->colors.channels[face][2] / 255.0f, 0.45f );
		world->DebugFilledPolygon( &color, &winding, 1, true );
	}
}
void idAmbientLighting::DebugDrawAmbientLightingBoxes(
		idRenderWorldLocal * world, const bool showValues ) const {
	if ( world == nullptr || ambientMap == nullptr || ambientMap->data == nullptr ||
			ambientMap->samples == nullptr ) return;
	idVec3 viewOrigin( 0.0f, 0.0f, 0.0f );
	if ( world->renderViews.Num() > 0 && world->renderViews[0] != nullptr )
		viewOrigin = world->renderViews[0]->g.vieworg;
	const idVec4 textColor( 1.0f, 0.0f, 0.0f, 1.0f );
	for ( int index = 0; index < ambientMap->data->numSamples; ++index ) {
		const ambientSample_t & sample = ambientMap->samples[index];
		const idVec3 origin( static_cast< float >( sample.origin[0] ),
			static_cast< float >( sample.origin[1] ),
			static_cast< float >( sample.origin[2] ) );
		if ( ( origin - viewOrigin ).LengthSqr() > 2048.0f * 2048.0f ) continue;
		DebugDrawColoredCube( world, &sample, 6.0f );
		if ( showValues ) {
			char text[32];
			std::snprintf( text, sizeof( text ), "%d", index );
			const idVec3 textOrigin = origin + idVec3( 0.0f, 0.0f, 32.0f );
			world->DebugText( text, &textOrigin, 0.5f, &textColor,
				1, 0, true, false );
		}
	}
	if ( showValues ) DebugDrawAmbientLightingSamples( world, viewOrigin );
}

void idAmbientLighting::LoadAmbientLighting( idRenderWorldLocal * world ) {
	if ( ambientMap == nullptr ) ambientMap = new ambientMap_t();
	delete[] reinterpret_cast< unsigned char * >( ambientMap->data );
	ambientMap->data = nullptr;
	ambientMap->dataLen = 0;
	ambientMap->nodes = nullptr;
	ambientMap->samples = nullptr;
	ambientMap->useForcedColors = false;
	if ( world == nullptr || world->mapName.Length() == 0 ) return;
	const std::string path = std::string( world->mapName.c_str() ) + ".ambient";
	std::ifstream file( path, std::ios::binary | std::ios::ate );
	if ( !file ) return;
	const std::streamoff length = file.tellg();
	if ( length < static_cast< std::streamoff >( sizeof( ambientHeader_t ) ) ||
			length > std::numeric_limits< int >::max() ) return;
	file.seekg( 0 );
	unsigned char * const bytes = new unsigned char[
		static_cast< std::size_t >( length )];
	if ( !file.read( reinterpret_cast< char * >( bytes ), length ) ) {
		delete[] bytes;
		return;
	}
	ambientHeader_t * const header =
		reinterpret_cast< ambientHeader_t * >( bytes );
	const std::size_t required = sizeof( ambientHeader_t ) +
		static_cast< std::size_t >( std::max( header->numNodes, 0 ) ) *
			sizeof( ambientNode_t ) +
		static_cast< std::size_t >( std::max( header->numSamples, 0 ) ) *
			sizeof( ambientSample_t );
	if ( header->numNodes <= 0 || header->numSamples < 0 ||
			required > static_cast< std::size_t >( length ) ) {
		delete[] bytes;
		return;
	}
	ambientMap->data = header;
	ambientMap->dataLen = static_cast< int >( length );
	ambientMap->nodes = reinterpret_cast< ambientNode_t * >( header + 1 );
	ambientMap->samples = reinterpret_cast< ambientSample_t * >(
		ambientMap->nodes + header->numNodes );
}
