#include "materialmap.h"

#include "idlib/filesystem/file.h"

idMaterialMapping::idMaterialMapping() :
	materialChecksum( 0 ), materialTimestamp( 0 ), x( 0 ), y( 0 ), width( 0 ),
	height( 0 ), scaleBias( 1.0f, 1.0f, 0.0f, 0.0f ) {
	specularFile.timeStamp = 0;
	coverFile.timeStamp = 0;
	diffuseFile.timeStamp = 0;
	bumpFile.timeStamp = 0;
	powerFile.timeStamp = 0;
}

idMaterialMap::idMaterialMap() : width( 0 ), height( 0 ),
	skinFileTimeStamp( 0 ), mappings( 16 ) {}

const idMaterialMapping * idMaterialMap::FindMapping( const char * materialName_ ) const {
	for ( int index = 0; index < mappings.Num(); ++index ) {
		if ( idStr::Icmp( mappings[index].materialName.c_str(), materialName_ ) == 0 ) {
			return &mappings[index];
		}
	}
	return nullptr;
}

bool idMaterialMap::GetImageDimensions( int & imageWidth, int & imageHeight ) const {
	imageWidth = width > 0 ? width : 1;
	imageHeight = height > 0 ? height : 1;
	return width > 0 && height > 0;
}

void idMaterialMap::Clear() {
	name.Clear();
	width = height = 0;
	skinFileTimeStamp = 0;
	mappings.Clear();
}

void idMaterialMap::Save( idFile * file ) const {
	if ( file == nullptr ) return;
	file->WriteString( name );
	file->WriteLittle( width );
	file->WriteLittle( height );
	file->WriteLittle( skinFileTimeStamp );
	const int count = mappings.Num();
	file->WriteLittle( count );
	for ( int index = 0; index < count; ++index ) {
		const idMaterialMapping & mapping = mappings[index];
		file->WriteString( mapping.materialName.c_str() );
		file->WriteLittle( mapping.materialChecksum );
		file->WriteLittle( mapping.materialTimestamp );
		file->WriteLittle( mapping.x );
		file->WriteLittle( mapping.y );
		file->WriteLittle( mapping.width );
		file->WriteLittle( mapping.height );
		file->Write( &mapping.scaleBias, sizeof( mapping.scaleBias ) );
	}
}

bool idMaterialMap::Load( idFile * file ) {
	if ( file == nullptr ) return false;
	Clear();
	int count = 0;
	if ( file->ReadString( name ) == 0 || file->ReadLittle( width ) != sizeof( width )
		|| file->ReadLittle( height ) != sizeof( height )
		|| file->ReadLittle( skinFileTimeStamp ) != sizeof( skinFileTimeStamp )
		|| file->ReadLittle( count ) != sizeof( count ) || count < 0 || count > 65536 ) return false;
	for ( int index = 0; index < count; ++index ) {
		idStr materialName_;
		idMaterialMapping mapping;
		if ( file->ReadString( materialName_ ) == 0
			|| file->ReadLittle( mapping.materialChecksum ) != sizeof( mapping.materialChecksum )
			|| file->ReadLittle( mapping.materialTimestamp ) != sizeof( mapping.materialTimestamp )
			|| file->ReadLittle( mapping.x ) != sizeof( mapping.x )
			|| file->ReadLittle( mapping.y ) != sizeof( mapping.y )
			|| file->ReadLittle( mapping.width ) != sizeof( mapping.width )
			|| file->ReadLittle( mapping.height ) != sizeof( mapping.height )
			|| file->Read( &mapping.scaleBias, sizeof( mapping.scaleBias ) )
				!= sizeof( mapping.scaleBias ) ) return false;
		mapping.materialName.Set( materialName_.c_str() );
		mappings.Append( mapping );
	}
	return true;
}
