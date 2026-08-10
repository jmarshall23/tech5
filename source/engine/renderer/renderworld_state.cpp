#include "renderworld_local.h"

#include "renderlight.h"
#include "renderlightcommitted.h"
#include "decls/declenv.h"
#include "idlib/filesystem/file.h"
#include "idlib/networking/bitmsg.h"
#include "network/serializer.h"
#include "network/network_precompiled.h"
#include "network/snapshot.h"

#include <cstdint>

namespace {

bool WriteExact( idFile * file, const void * data, const unsigned int size ) {
	return file != nullptr && file->Write( data, size ) == size;
}
bool ReadExact( idFile * file, void * data, const unsigned int size ) {
	return file != nullptr && file->Read( data, size ) == size;
}

}

void idRenderWorldLocal::SaveGame( idFile * file ) {
	if ( file == nullptr ) return;
	const int modelCount = renderModels.Num();
	WriteExact( file, &modelCount, sizeof( modelCount ) );
	for ( int index = 0; index < modelCount; ++index ) {
		const std::uint8_t present = renderModels[index] != nullptr ? 1u : 0u;
		WriteExact( file, &present, sizeof( present ) );
		if ( present == 0 ) continue;
		file->WriteString( renderModels[index]->GetName() );
		renderModels[index]->Save( file );
	}
	const int lightCount = renderLights.Num();
	WriteExact( file, &lightCount, sizeof( lightCount ) );
	for ( int index = 0; index < lightCount; ++index ) {
		const std::uint8_t present = renderLights[index] != nullptr ? 1u : 0u;
		WriteExact( file, &present, sizeof( present ) );
		if ( present != 0 ) renderLights[index]->Save( file );
	}
	const int environmentCount = dynamicEnvironments.Num();
	WriteExact( file, &environmentCount, sizeof( environmentCount ) );
	for ( int index = 0; index < environmentCount; ++index ) {
		WriteExact( file, &dynamicEnvironments[index].bounds,
			sizeof( dynamicEnvironments[index].bounds ) );
		file->WriteString( dynamicEnvironments[index].env != nullptr
			? dynamicEnvironments[index].env->GetName() : "" );
	}
}

bool idRenderWorldLocal::LoadGame( idFile * file ) {
	if ( file == nullptr ) return false;
	for ( int index = 0; index < renderViews.Num(); ++index )
		delete renderViews[index];
	renderViews.Clear();
	for ( int index = 0; index < renderLights.Num(); ++index )
		delete renderLights[index];
	renderLights.Clear();
	for ( int index = 0; index < renderModels.Num(); ++index )
		delete renderModels[index];
	renderModels.Clear();
	dynamicEnvironments.Clear();

	int modelCount = 0;
	if ( !ReadExact( file, &modelCount, sizeof( modelCount ) ) ||
			modelCount < 0 || modelCount > renderModels.Max() ) return false;
	for ( int index = 0; index < modelCount; ++index ) {
		std::uint8_t present = 0;
		if ( !ReadExact( file, &present, sizeof( present ) ) ) return false;
		if ( present == 0 ) { renderModels.Append( nullptr ); continue; }
		idStr modelName;
		if ( file->ReadString( modelName ) == 0 ) return false;
		idRenderModel * const model = AllocRenderModel( modelName.c_str(),
			true, -1 );
		if ( model == nullptr || !model->Load( file ) ) return false;
	}
	int lightCount = 0;
	if ( !ReadExact( file, &lightCount, sizeof( lightCount ) ) ||
			lightCount < 0 || lightCount > renderLights.Max() ) return false;
	for ( int index = 0; index < lightCount; ++index ) {
		std::uint8_t present = 0;
		if ( !ReadExact( file, &present, sizeof( present ) ) ) return false;
		if ( present == 0 ) { renderLights.Append( nullptr ); continue; }
		idRenderLight * const light = AllocRenderLight( false );
		if ( light == nullptr || !light->Load( file ) ) return false;
	}
	int environmentCount = 0;
	if ( !ReadExact( file, &environmentCount, sizeof( environmentCount ) ) ||
			environmentCount < 0 || environmentCount > dynamicEnvironments.Max() )
		return false;
	for ( int index = 0; index < environmentCount; ++index ) {
		idBounds bounds;
		idStr environmentName;
		if ( !ReadExact( file, &bounds, sizeof( bounds ) ) ||
				file->ReadString( environmentName ) == 0 ) return false;
		const idDeclEnv * const environment = environmentName.IsEmpty()
			? nullptr : static_cast< const idDeclEnv * >(
				idDeclEnv::resourceList.Load( environmentName.c_str(), true ) );
		if ( environment != nullptr ) AddEnvironment( &bounds, environment );
	}
	MarkAllLightsAsSerialized();
	return true;
}

void idRenderWorldLocal::WriteToSnapshot( idSnapShot * snapshot,
		const idSnapShot * ) {
	if ( snapshot == nullptr ) return;
	unsigned char sentinelByte = 0;
	idBitMsg sentinel( &sentinelByte, 1 );
	sentinel.BeginWriting();
	snapshot->S_AddObject( 10020, 0xFFFFFFFFu, sentinel, "lights-begin" );
	for ( int index = 0; index < renderLights.Num(); ++index ) {
		idRenderLight * const light = renderLights[index];
		if ( light == nullptr || light->skipAutoReplication ) continue;
		unsigned char data[8192] = {};
		idBitMsg message( data, sizeof( data ) );
		message.BeginWriting();
		idSerializer serializer( message, true );
		light->SerializeSnapshot( serializer );
		snapshot->S_AddObject( 10021 + index, 0xFFFFFFFFu, message, "lights" );
		light->needWriteToSnapshot = false;
	}
	unsigned char environmentData[8192] = {};
	idBitMsg environmentMessage( environmentData, sizeof( environmentData ) );
	environmentMessage.BeginWriting();
	environmentMessage.WriteBits( dynamicEnvironments.Num(), 8 );
	for ( int index = 0; index < dynamicEnvironments.Num(); ++index ) {
		const int networkID = dynamicEnvironments[index].env != nullptr
			? dynamicEnvironments[index].env->GetNetworkID( true ) : -1;
		environmentMessage.WriteBits( networkID, -16 );
		const float * const values =
			&dynamicEnvironments[index].bounds[0].x;
		for ( int component = 0; component < 6; ++component ) {
			const std::uint32_t bits =
				*reinterpret_cast< const std::uint32_t * >( values + component );
			environmentMessage.WriteBits( static_cast< int >( bits ), 32 );
		}
	}
	snapshot->S_AddObject( 15020, 0xFFFFFFFFu, environmentMessage,
		"environments" );
}

void idRenderWorldLocal::ReadFromSnapshot( idSnapShot * snapshot,
		const idSnapShot * ) {
	if ( snapshot == nullptr ) return;
	const int firstIndex = snapshot->FindObjectIndexByID( 10020 );
	const int environmentIndex = snapshot->FindObjectIndexByID( 15020 );
	if ( firstIndex < 0 || environmentIndex < 0 ) return;
	for ( int objectIndex = firstIndex + 1;
			objectIndex < environmentIndex; ++objectIndex ) {
		idBitMsg message;
		const int objectID = snapshot->GetObjectMsgByIndex( objectIndex,
			message, false );
		const int lightIndex = objectID - 10021;
		if ( lightIndex < 0 || lightIndex >= renderLights.Max() ) continue;
		while ( renderLights.Num() <= lightIndex ) renderLights.Append( nullptr );
		idRenderLight *& light = renderLights[lightIndex];
		if ( message.GetSize() == 0 ) {
			if ( light != nullptr ) light->Delete();
			continue;
		}
		if ( light == nullptr ) {
			light = new idRenderLight();
			light->committed->world = this;
			light->committed->index.Set(
				static_cast< unsigned int >( lightIndex ) );
		}
		message.BeginReading();
		idSerializer serializer( message, false );
		light->SerializeSnapshot( serializer );
		light->CommitThisFrame();
	}
	idBitMsg environmentMessage;
	if ( snapshot->GetObjectMsgByIndex( environmentIndex,
			environmentMessage, false ) != 15020 ) return;
	environmentMessage.BeginReading();
	const int environmentCount = environmentMessage.ReadBits( 8 );
	dynamicEnvironments.SetNum( environmentCount );
	for ( int index = 0; index < environmentCount; ++index ) {
		const int networkID = environmentMessage.ReadBits( -16 );
		dynamicEnvironments[index].env = static_cast< const idDeclEnv * >(
			idResourceList::GetNetworkResource( networkID ) );
		float * const values = &dynamicEnvironments[index].bounds[0].x;
		for ( int component = 0; component < 6; ++component ) {
			const std::uint32_t bits = static_cast< std::uint32_t >(
				environmentMessage.ReadBits( 32 ) );
			values[component] = *reinterpret_cast< const float * >( &bits );
		}
	}
}

void idRenderWorldLocal::ResetSnapshots() {
	serializedLights.Clear();
	for ( int index = 0; index < renderLights.Num(); ++index ) {
		if ( renderLights[index] == nullptr ) continue;
		renderLights[index]->serializedChangeCount = 0;
		renderLights[index]->needWriteToSnapshot = true;
		if ( !renderLights[index]->skipAutoReplication )
			serializedLights.Append( renderLights[index] );
	}
}
