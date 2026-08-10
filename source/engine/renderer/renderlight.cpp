#include "renderlight.h"

#include "declmaterial.h"
#include "declrenderparm.h"
#include "renderlightcommitted.h"
#include "renderworld_local.h"
#include "idlib/filesystem/file.h"
#include "network/serializer.h"

#include <cstdint>

namespace {

bool WriteExact( idFile * file, const void * data, const unsigned int size ) {
	return file != nullptr && file->Write( data, size ) == size;
}

bool ReadExact( idFile * file, void * data, const unsigned int size ) {
	return file != nullptr && file->Read( data, size ) == size;
}

const idMaterial * ResolveMaterial( const char * name ) {
	if ( name == nullptr || name[0] == '\0' ) return nullptr;
	idResourceList * const list = idResourceList::ForTypeName( "material" );
	return list != nullptr
		? static_cast< const idMaterial * >( list->Load( name, true ) ) : nullptr;
}

const char * MaterialName( const idMaterial * material ) {
	return material != nullptr ? material->GetName() : "";
}

}

idRenderLight::idRenderLight() :
	g(),
	gameParmBlock(),
	deleteOnSync( false ),
	unlinked( true ),
	needWriteToSnapshot( true ),
	skipAutoReplication( false ),
	serializedChangeCount( 0 ),
	committed( new idRenderLightCommitted() ) {
}

idRenderLight::~idRenderLight() {
	delete committed;
	committed = nullptr;
}

int idRenderLight::GetIndex() const {
	return committed != nullptr ? committed->index.GetIndex() : -1;
}

idParmBlock * idRenderLight::GetParmBlock() { return &gameParmBlock; }
const idParmBlock * idRenderLight::GetParmBlock() const {
	return &gameParmBlock;
}

void idRenderLight::SetParm( const idDeclRenderParm * parm,
		const idVec4 & value ) {
	parmValue_t parmValue = {};
	parmValue.value[0] = value.x;
	parmValue.value[1] = value.y;
	parmValue.value[2] = value.z;
	parmValue.value[3] = value.w;
	gameParmBlock.SetParm( parm, parmValue );
}

void idRenderLight::CommitThisFrame() {
	unlinked = false;
	if ( committed != nullptr && committed->world != nullptr ) {
		committed->world->ScheduleLightCommit( this );
		committed->world->MarkLightSerialized( this, true, false );
	}
}

void idRenderLight::Delete() {
	deleteOnSync = true;
	CommitThisFrame();
	if ( committed != nullptr && committed->world != nullptr ) {
		committed->world->MarkLightSerialized( this, false, true );
	}
}

void idRenderLight::Unlink() {
	if ( unlinked ) return;
	CommitThisFrame();
	unlinked = true;
	if ( committed != nullptr ) committed->FreeReferences();
}

void idRenderLight::Commit() {
	if ( committed == nullptr ) return;
	committed->renderParmBlock = gameParmBlock;
	committed->r = g;
	committed->lightMtr = g.shader;
	if ( committed->lightMtr == nullptr ) {
		committed->lightMtr = ResolveMaterial( g.lightClass == LIGHT_BLENDED_ONLY
			? ( g.lightType == LIGHT_POINT ? "lights/defaultPointBlend"
				: g.lightType == LIGHT_PARALLEL ? "lights/defaultParallelBlend"
				: "lights/defaultProjectedBlend" )
			: ( g.lightType == LIGHT_POINT ? "lights/defaultPoint"
				: g.lightType == LIGHT_PARALLEL ? "lights/defaultParallel"
				: "lights/defaultProjected" ) );
	}
	committed->castsShadows = !g.noShadows &&
		( committed->lightMtr == nullptr || committed->lightMtr->CastsShadows() );
	committed->needsReferences = !unlinked;
	committed->PostCommit();
}

void idRenderLight::Save( idFile * file ) const {
	if ( file == nullptr ) return;
	const std::uint8_t savedUnlinked = unlinked ? 1u : 0u;
	WriteExact( file, &savedUnlinked, sizeof( savedUnlinked ) );
	file->WriteString( MaterialName( g.shader ) );
	WriteExact( file, &g.axis, sizeof( g.axis ) );
	WriteExact( file, &g.origin, sizeof( g.origin ) );
	WriteExact( file, &g.allowLightOnlyInViewID,
		sizeof( g.allowLightOnlyInViewID ) );
	WriteExact( file, &g.suppressLightInViewID,
		sizeof( g.suppressLightInViewID ) );
	WriteExact( file, &g.noShadows, sizeof( g.noShadows ) );
	WriteExact( file, &g.lightType, sizeof( g.lightType ) );
	WriteExact( file, &g.lightClass, sizeof( g.lightClass ) );
	WriteExact( file, &g.lightFalloff, sizeof( g.lightFalloff ) );
	WriteExact( file, &g.lightRadius, sizeof( g.lightRadius ) );
	WriteExact( file, &g.lightCenter, sizeof( g.lightCenter ) );
	WriteExact( file, &g.target, sizeof( g.target ) );
	WriteExact( file, &g.right, sizeof( g.right ) );
	WriteExact( file, &g.up, sizeof( g.up ) );
	WriteExact( file, &g.start, sizeof( g.start ) );
	WriteExact( file, &g.end, sizeof( g.end ) );
	WriteExact( file, &g.areaLightSize, sizeof( g.areaLightSize ) );
	WriteExact( file, &g.shadowSampleScale, sizeof( g.shadowSampleScale ) );
	gameParmBlock.Save( file );
}

bool idRenderLight::Load( idFile * file ) {
	if ( file == nullptr ) return false;
	std::uint8_t loadedUnlinked = 0;
	idStr materialName;
	if ( !ReadExact( file, &loadedUnlinked, sizeof( loadedUnlinked ) ) ||
			file->ReadString( materialName ) == 0 ) return false;
	g.shader = ResolveMaterial( materialName.c_str() );
	if ( !ReadExact( file, &g.axis, sizeof( g.axis ) ) ||
		!ReadExact( file, &g.origin, sizeof( g.origin ) ) ||
		!ReadExact( file, &g.allowLightOnlyInViewID,
			sizeof( g.allowLightOnlyInViewID ) ) ||
		!ReadExact( file, &g.suppressLightInViewID,
			sizeof( g.suppressLightInViewID ) ) ||
		!ReadExact( file, &g.noShadows, sizeof( g.noShadows ) ) ||
		!ReadExact( file, &g.lightType, sizeof( g.lightType ) ) ||
		!ReadExact( file, &g.lightClass, sizeof( g.lightClass ) ) ||
		!ReadExact( file, &g.lightFalloff, sizeof( g.lightFalloff ) ) ||
		!ReadExact( file, &g.lightRadius, sizeof( g.lightRadius ) ) ||
		!ReadExact( file, &g.lightCenter, sizeof( g.lightCenter ) ) ||
		!ReadExact( file, &g.target, sizeof( g.target ) ) ||
		!ReadExact( file, &g.right, sizeof( g.right ) ) ||
		!ReadExact( file, &g.up, sizeof( g.up ) ) ||
		!ReadExact( file, &g.start, sizeof( g.start ) ) ||
		!ReadExact( file, &g.end, sizeof( g.end ) ) ||
		!ReadExact( file, &g.areaLightSize, sizeof( g.areaLightSize ) ) ||
		!ReadExact( file, &g.shadowSampleScale, sizeof( g.shadowSampleScale ) ) ||
		!gameParmBlock.Load( file ) ) return false;
	unlinked = loadedUnlinked != 0;
	Commit();
	return true;
}

void idRenderLight::SerializeSnapshot( idSerializer & serializer ) {
	idFile_BitMsg parmFile( serializer.GetMsg() );
	if ( serializer.IsWriting() ) gameParmBlock.Save( &parmFile );
	else gameParmBlock.Load( &parmFile );
	int materialNetworkID = serializer.IsWriting() && g.shader != nullptr
		? g.shader->GetNetworkID( true ) : -1;
	serializer.Serialize( materialNetworkID );
	if ( serializer.IsReading() ) {
		g.shader = materialNetworkID >= 0
			? static_cast< const idMaterial * >(
				idResourceList::GetNetworkResource( materialNetworkID ) )
			: nullptr;
	}
	serializer.SerializeQ( g.axis, 15 );
	serializer.Serialize( g.origin );
	serializer.Serialize( g.allowLightOnlyInViewID );
	serializer.Serialize( g.suppressLightInViewID );
	serializer.Serialize( g.noShadows );
	serializer.Serialize( g.dynamicModelLightingScale );
	serializer.Serialize( g.dimShadowStretch );
	int type = static_cast< int >( g.lightType );
	serializer.SerializeUMax( type, LIGHT_MAX_TYPES - 1 );
	g.lightType = static_cast< lightType_t >( type );
	int lightClassValue = static_cast< int >( g.lightClass );
	serializer.SerializeUMax( lightClassValue, LIGHT_BLENDED_ONLY );
	g.lightClass = static_cast< lightClass_t >( lightClassValue );
	serializer.Serialize( unlinked );
	serializer.Serialize( g.lightRadius );
	serializer.Serialize( g.lightCenter );
	serializer.Serialize( g.target );
	serializer.Serialize( g.right );
	serializer.Serialize( g.up );
	serializer.Serialize( g.start );
	serializer.Serialize( g.end );
	serializer.Serialize( g.areaLightSize );
	serializer.Serialize( g.shadowSampleScale );
}
