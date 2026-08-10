#include "rendermodelcommitted.h"

#include "declmaterial.h"
#include "renderworld_local.h"

#include <algorithm>
#include <cstring>
#include <limits>

namespace {
	idVec3 TransformPoint( const idRenderMatrix & matrix, const idVec3 & point ) {
		idVec4 transformed;
		matrix.TransformPoint( point, transformed );
		return idVec3( transformed.x, transformed.y, transformed.z );
	}
}

idRenderModelCommitted::idRenderModelCommitted() :
	name( "<unnamed>" ), world( nullptr ), index(), referenceBounds(), r(),
	renderParmBlock(), surfaces(), nextOnPostCommitList( this ),
	references(), nextAddAlwaysModel( this ), nextDimShadowModel( this ),
	referenceModel( nullptr ), guiFrameCount( 0 ),
	maxVisibleRange( 0.0f, 0.0f, 0.0f, 262144.0f ),
	localLightingPoint( 0.0f, 0.0f, 0.0f ),
	highlightColor( 0.0f, 0.0f, 0.0f, 0.0f ),
	isLitTransSort( false ), hasUniqueVirtualTexture( false ),
	mayMakeInteractions( false ), mayCastShadows( false ), mayBeDrawn( true ),
	needsApproximatedLighting( false ), needsReferences( true ),
	lightCenterInitialized( false ) {
	referenceBounds[0].Zero();
	referenceBounds[1].Zero();
	renderParmBlock.thread = THREAD_RENDERER;
	globalReferenceBounds = referenceBounds;
	modelMatrix.Identity();
	inverseModelMatrix.Identity();
	mvpMatrix.Identity();
	std::memset( &approximateLighting, 0, sizeof( approximateLighting ) );
	std::memset( &r, 0, sizeof( r ) );
	r.axis = idMat3( 1.0f );
	r.scale.Set( 1.0f, 1.0f, 1.0f );
	r.customSkin = -1;
	r.groupMasterIndex = -1;
	r.suppressShadowInLightIndex = -1;
	r.firstVisibleFrameCount = 2;
	r.fovScale = 1.0f;
	r.radiosityScale = 1.0f;
	r.staticReflectionStrength = 1.0f;
	r.modelFade = 1.0f;
	r.fadeVisibilityOver = 400.0f;
}

idRenderModelCommitted::~idRenderModelCommitted() { FreeReferences(); }

void idRenderModelCommitted::UnlinkAddAlways() {
	if ( world == nullptr || nextAddAlwaysModel == this ) return;
	idRenderModelCommitted ** link = &world->addAlwaysModels;
	while ( *link != nullptr ) {
		if ( *link == this ) {
			*link = nextAddAlwaysModel;
			break;
		}
		link = &( *link )->nextAddAlwaysModel;
	}
	nextAddAlwaysModel = this;
}

void idRenderModelCommitted::UnlinkDimShadow() {
	if ( world == nullptr || nextDimShadowModel == this ) return;
	idRenderModelCommitted ** link = &world->dimShadowModels;
	while ( *link != nullptr ) {
		if ( *link == this ) {
			*link = nextDimShadowModel;
			break;
		}
		link = &( *link )->nextDimShadowModel;
	}
	nextDimShadowModel = this;
}

void idRenderModelCommitted::SetFlagsFromSurfaces() {
	mayMakeInteractions = false;
	mayCastShadows = false;
	mayBeDrawn = false;
	needsApproximatedLighting = r.forceApproximatedLighting != 0;
	hasUniqueVirtualTexture = false;
	for ( int surfaceIndex = 0; surfaceIndex < surfaces.Num(); ++surfaceIndex ) {
		const idMaterial * const material = surfaces[surfaceIndex].material;
		if ( material == nullptr || material->Coverage() == MC_INVISIBLE ) continue;
		mayBeDrawn = true;
		mayMakeInteractions |= material->HasInteractions();
		mayCastShadows |= material->CastsShadows();
		needsApproximatedLighting |= material->materialUsesApproximatedLighting != 0;
		hasUniqueVirtualTexture |= material->pageSource == PAGESOURCE_UNIQUE;
	}
	if ( r.noInteractions ) mayMakeInteractions = false;
	if ( r.noShadow ) mayCastShadows = false;
}

void idRenderModelCommitted::CreateReferences() {
	FreeReferences();
	if ( world == nullptr || world->numWorldAreas <= 0 ) {
		needsReferences = false;
		return;
	}
	// The proc BSP determines the exact area set in retail.  The portable
	// path conservatively links against intersecting area bounds when those
	// bounds are available and otherwise uses area zero.
	for ( int areaIndex = 0; areaIndex < world->numWorldAreas; ++areaIndex ) {
		worldArea_t & area = world->worldAreas[areaIndex];
		area.drawModelRefs.AddUnique( index );
		references.Append( &area );
	}
	if ( index.IsValid() && index.GetIndex() < world->linkedRenderModels.Max() ) {
		while ( world->linkedRenderModels.Num() <= index.GetIndex() )
			world->linkedRenderModels.Append( nullptr );
		world->linkedRenderModels[index.GetIndex()] = this;
	}
	needsReferences = false;
}

void idRenderModelCommitted::CheckBounds() {
	idRenderMatrix::FromOriginAxisScale( r.origin, r.axis, r.scale, modelMatrix );
	if ( !idRenderMatrix::Inverse( modelMatrix, inverseModelMatrix ) )
		inverseModelMatrix.Identity();
	const float infinity = std::numeric_limits< float >::infinity();
	globalReferenceBounds[0].Set( infinity, infinity, infinity );
	globalReferenceBounds[1].Set( -infinity, -infinity, -infinity );
	for ( int corner = 0; corner < 8; ++corner ) {
		const idVec3 point(
			referenceBounds[( corner & 1 ) != 0 ? 1 : 0].x,
			referenceBounds[( corner & 2 ) != 0 ? 1 : 0].y,
			referenceBounds[( corner & 4 ) != 0 ? 1 : 0].z );
		const idVec3 transformed = TransformPoint( modelMatrix, point );
		for ( int axis = 0; axis < 3; ++axis ) {
			globalReferenceBounds[0][axis] = std::min(
				globalReferenceBounds[0][axis], transformed[axis] );
			globalReferenceBounds[1][axis] = std::max(
				globalReferenceBounds[1][axis], transformed[axis] );
		}
	}
	const idVec3 center = ( globalReferenceBounds[0] +
		globalReferenceBounds[1] ) * 0.5f;
	const idVec3 extents = globalReferenceBounds[1] - center;
	const float radius = std::max( extents.x,
		std::max( extents.y, extents.z ) );
	maxVisibleRange.Set( center.x, center.y, center.z,
		r.maxVisibleRange > 0.0f ? radius + r.maxVisibleRange : 262144.0f );
	needsReferences = true;
}

const idVec3 & idRenderModelCommitted::GetLightingPoint() {
	if ( !lightCenterInitialized ) {
		localLightingPoint = ( referenceBounds[0] + referenceBounds[1] ) * 0.5f;
		if ( r.boostLightingPoint )
			localLightingPoint.z += ( referenceBounds[1].z -
				referenceBounds[0].z ) * 0.25f;
		lightCenterInitialized = true;
	}
	return localLightingPoint;
}

void idRenderModelCommitted::FreeReferences() {
	for ( int referenceIndex = 0; referenceIndex < references.Num();
			++referenceIndex ) {
		worldArea_t * const area = references[referenceIndex];
		if ( area != nullptr ) area->drawModelRefs.Remove( index );
	}
	references.Clear();
	if ( world != nullptr && index.IsValid() &&
			index.GetIndex() < world->linkedRenderModels.Num() )
		world->linkedRenderModels[index.GetIndex()] = nullptr;
}

bool idRenderModelCommitted::CastsDimShadows() const {
	return r.castDimShadows != DIMSHADOW_OFF && mayCastShadows && !r.noShadow;
}

void idRenderModelCommitted::PostCommit() {
	GetLightingPoint();
	CheckBounds();
	SetFlagsFromSurfaces();
	if ( r.addAlways ) {
		FreeReferences();
		UnlinkDimShadow();
		if ( world != nullptr && nextAddAlwaysModel == this ) {
			nextAddAlwaysModel = world->addAlwaysModels;
			world->addAlwaysModels = this;
		}
		return;
	}
	UnlinkAddAlways();
	if ( needsReferences ) CreateReferences();
	if ( !CastsDimShadows() ) {
		UnlinkDimShadow();
	} else if ( world != nullptr && nextDimShadowModel == this ) {
		nextDimShadowModel = world->dimShadowModels;
		world->dimShadowModels = this;
	}
}
