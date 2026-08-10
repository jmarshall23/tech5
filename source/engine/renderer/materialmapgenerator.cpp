#include "declmaterial.h"

#include <algorithm>

const idMaterial * idMaterial::PackMaterials( const char * name,
		const idList< const idMaterial *, 5 > & materials, const unsigned int ) {
	if ( name == nullptr || *name == '\0' || materials.Num() == 0 || materials[0] == nullptr )
		return nullptr;
	const idMaterial * first = materials[0];
	for ( int i = 1; i < materials.Num(); ++i ) {
		if ( materials[i] == nullptr || !first->MaterialIsMergableWith( materials[i] ) )
			return nullptr;
	}
	if ( materials.Num() == 1 ) return first;
	idMaterial * packed = static_cast< idMaterial * >(
		idMaterial::resourceList.FindExisting( name, true ) );
	if ( packed == nullptr ) {
		packed = new idMaterial();
		packed->SetName( name );
		idMaterial::resourceList.Add( packed );
	}
	packed->Clear();
	packed->atlasScaleBias = first->atlasScaleBias;
	packed->coverage = first->coverage;
	packed->pageSource = first->pageSource;
	packed->pageFileName = first->pageFileName;
	packed->physicalPagesPool = first->physicalPagesPool;
	packed->materialMap = first->materialMap;
	packed->editorImage = first->editorImage;
	packed->virtualMapping = first->virtualMapping;
	packed->materialIsTwoSided = first->materialIsTwoSided;
	packed->materialCastsShadows = first->materialCastsShadows;
	packed->materialHasInteractions = first->materialHasInteractions;
	packed->materialHasMergeableBlendedPass = first->materialHasMergeableBlendedPass;
	for ( int role = 0; role < MPR_MAX; ++role ) {
		packed->progs[role] = first->progs[role];
		packed->stageSort[role] = first->stageSort[role];
	}
	for ( int i = 0; i < materials.Num(); ++i ) {
		packed->parmBlock.Append( materials[i]->parmBlock );
		packed->renderParmBlock.Append( materials[i]->renderParmBlock );
		packed->coverage = static_cast< materialCoverage_t >(
			(std::max)( static_cast< int >( packed->coverage ),
				static_cast< int >( materials[i]->coverage ) ) );
	}
	packed->OptimizeRenderParmBlock();
	return packed;
}
