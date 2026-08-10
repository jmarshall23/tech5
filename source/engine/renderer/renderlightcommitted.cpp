#include "renderlightcommitted.h"

#include "declmaterial.h"
#include "declrenderparm.h"
#include "renderworld_local.h"

#include <algorithm>
#include <cmath>

idRenderLightCommitted::idRenderLightCommitted() :
	world( nullptr ),
	index(),
	r(),
	renderParmBlock(),
	nextOnPostCommitList( this ),
	references(),
	needsReferences( false ),
	globalLightOrigin( 0.0f, 0.0f, 0.0f ),
	currentColor( 0.0f, 0.0f, 0.0f ),
	maxVisibleRange( 0.0f, 0.0f, 0.0f, 262144.0f ),
	lightMtr( nullptr ),
	castsShadows( false ) {
	globalReferenceBounds[0].Zero();
	globalReferenceBounds[1].Zero();
	baseLightProject.Identity();
	inverseBaseLightProject.Identity();
}

idRenderLightCommitted::~idRenderLightCommitted() {
	FreeReferences();
}

void idRenderLightCommitted::CreateReferences() {
	FreeReferences();
	idVec3 corners[8];
	r.ComputeLightGlobalReferenceBounds( globalReferenceBounds, corners );
	if ( r.maxVisibleRange <= 0.0f ) {
		maxVisibleRange.Set( 0.0f, 0.0f, 0.0f, 262144.0f );
	} else {
		const idVec3 center = ( globalReferenceBounds[0] +
			globalReferenceBounds[1] ) * 0.5f;
		const idVec3 extent = globalReferenceBounds[1] - center;
		maxVisibleRange.Set( center.x, center.y, center.z,
			std::max( extent.x, std::max( extent.y, extent.z ) ) +
				r.maxVisibleRange );
	}
	if ( world != nullptr ) {
		for ( int areaIndex = 0; areaIndex < world->numWorldAreas; ++areaIndex ) {
			worldArea_t & area = world->worldAreas[areaIndex];
			area.drawLightRefs.AddUnique( index );
			references.Append( &area );
		}
		if ( index.IsValid() && index.GetIndex() < world->linkedRenderLights.Max() ) {
			while ( world->linkedRenderLights.Num() <= index.GetIndex() )
				world->linkedRenderLights.Append( nullptr );
			world->linkedRenderLights[index.GetIndex()] = this;
		}
	}
	needsReferences = false;
}

void idRenderLightCommitted::FreeReferences() {
	for ( int referenceIndex = 0; referenceIndex < references.Num();
			++referenceIndex ) {
		worldArea_t * const area = references[referenceIndex];
		if ( area != nullptr ) area->drawLightRefs.Remove( index );
	}
	references.Clear();
	if ( world != nullptr && index.IsValid() &&
			index.GetIndex() < world->linkedRenderLights.Num() )
		world->linkedRenderLights[index.GetIndex()] = nullptr;
}

void idRenderLightCommitted::PostCommit() {
	r.ComputeWorldToLightMatrix( baseLightProject, inverseBaseLightProject );
	r.ComputeLightGlobalOrigin( globalLightOrigin );

	const idDeclRenderParm * const lightColor =
		idDeclRenderParm::FindByName( "lightColor", true );
	const idDeclRenderParm * const exposure =
		idDeclRenderParm::FindByName( "exposure", true );
	idVec4 color = renderParmBlock.GetVector( lightColor );
	idVec4 scale = renderParmBlock.GetVector( exposure );
	if ( lightMtr != nullptr ) {
		if ( !renderParmBlock.SetsRenderParm( lightColor ) ) {
			color = lightMtr->GetRenderParmBlock()->GetVector( lightColor );
		}
		if ( !renderParmBlock.SetsRenderParm( exposure ) ) {
			scale = lightMtr->GetRenderParmBlock()->GetVector( exposure );
		}
	}
	currentColor.Set( color.x * scale.x, color.y * scale.y,
		color.z * scale.z );
	if ( needsReferences || references.Num() == 0 ) CreateReferences();
}
