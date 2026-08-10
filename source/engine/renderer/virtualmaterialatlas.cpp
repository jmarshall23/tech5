#include "virtualmaterialatlas.h"

#include <algorithm>

#include "declmaterial.h"
#include "virtualtexturesystem.h"

#include "../../shared/idlib/filesystem/filesystem.h"

#include <cstring>
#include <sstream>
#include <string>

idVirtualMaterial::idVirtualMaterial() : materialChecksum( 0 ), cpuVmtrTimeStamp( 0 ),
	allocX( 0 ), allocY( 0 ), allocWidth( 0 ), allocHeight( 0 ), flags( 0 ),
	material( nullptr ), cpuVmtr( nullptr ), scaleAndBias( 0.0f, 0.0f, 0.0f, 0.0f ) {}

void idVirtualTextureSystem::SetupVirtualMaterial( idVirtualMaterial * vmtr ) {
	if ( vmtr == nullptr || vmtrMega == nullptr || vmtrMega->VIRTUAL_TEXELS_WIDE <= 0 ) return;
	const bool noBorder = ( vmtr->flags & idVirtualMaterial::VF_NO_BORDER ) != 0;
	const float textureSize = static_cast< float >( vmtrMega->VIRTUAL_TEXELS_WIDE );
	const int border = noBorder ? 0 : 16;
	vmtr->scaleAndBias.x = (std::max)( 0, vmtr->allocWidth - border * 2 ) / textureSize;
	vmtr->scaleAndBias.y = (std::max)( 0, vmtr->allocHeight - border * 2 ) / textureSize;
	vmtr->scaleAndBias.z = ( vmtr->allocX + border ) / textureSize;
	vmtr->scaleAndBias.w = ( vmtr->allocY + border ) / textureSize;
	if ( vmtr->material != nullptr ) {
		idMaterial * material = const_cast< idMaterial * >( vmtr->material );
		material->virtualMapping = vmtr->scaleAndBias;
		material->devVmtr = vmtr;
	}
}

void idVirtualTextureSystem::SetupLoadedVirtualMaterials() {
	for ( int i = 0; i < vmtrs.Num(); ++i ) SetupVirtualMaterial( vmtrs[i] );
}

void idVirtualTextureSystem::ReadVmtrFile() {
	for ( int i = 0; i < vmtrs.Num(); ++i ) delete vmtrs[i];
	vmtrs.Clear();
	vmtrHash.Clear();
	if ( fileSystem == nullptr || vmtrPath[0] == '\0' ) return;
	void * raw = nullptr;
	const int length = fileSystem->ReadFile( vmtrPath, &raw, nullptr );
	if ( length <= 0 || raw == nullptr ) return;
	std::string text( static_cast< const char * >( raw ), static_cast< std::size_t >( length ) );
	fileSystem->FreeFile( raw );
	std::istringstream stream( text );
	int version = 0, count = 0;
	if ( !( stream >> version >> count ) || version != 25 || count < 0 || count > 65536 ) return;
	for ( int i = 0; i < count; ++i ) {
		idVirtualMaterial * vmtr = new idVirtualMaterial();
		std::string name;
		if ( !( stream >> vmtr->allocX >> vmtr->allocY >> vmtr->allocWidth >> vmtr->allocHeight >>
			vmtr->flags >> vmtr->cpuVmtrTimeStamp >> vmtr->materialChecksum >> name ) ) {
			delete vmtr; break;
		}
		vmtr->materialName.Set( name.c_str() );
		SetupVirtualMaterial( vmtr );
		const int index = vmtrs.Append( vmtr );
		vmtrHash.Add( vmtrHash.GenerateKeyForString( name.c_str(), true ), index );
	}
}
