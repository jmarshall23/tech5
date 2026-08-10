#include "renderworld_local.h"

#include "declmaterial.h"
#include "renderlight.h"
#include "renderlightcommitted.h"
#include "rendermodelcommitted.h"
#include "idlib/filesystem/file.h"

#include <algorithm>
#include <cmath>

namespace {

idList< idRenderWorldLocal *, 5 > activeWorlds;

class idWorldRenderModel final : public idRenderModel {
public:
	idWorldRenderModel() : idRenderModel() {}
};

idRenderWorldLocal * WorldForModel( const idRenderModel * model,
		int * indexOut = nullptr ) {
	for ( int worldIndex = 0; worldIndex < activeWorlds.Num(); ++worldIndex ) {
		idRenderWorldLocal * const world = activeWorlds[worldIndex];
		for ( int index = 0; index < world->renderModels.Num(); ++index ) {
			if ( world->renderModels[index] == model ) {
				if ( indexOut != nullptr ) *indexOut = index;
				return world;
			}
		}
	}
	if ( indexOut != nullptr ) *indexOut = -1;
	return nullptr;
}

bool ScheduleModelCommit( idRenderModel * ) { return false; }
void ModelCommitted( idRenderModel * model, bool ) {
	if ( model == nullptr || model->committed == nullptr ) return;
	idRenderModelCommitted * const committed = model->committed;
	committed->name = model->GetName();
	committed->referenceBounds = model->referenceBounds;
	committed->r = model->g;
	committed->renderParmBlock.CopyFrom( model->gameParmBlock );
	committed->surfaces.SetNum( model->surfaces.Num() );
	for ( int index = 0; index < model->surfaces.Num(); ++index )
		committed->surfaces[index] = model->surfaces[index];
	committed->PostCommit();
}
idRenderWorld * ResolveModelWorld( const idRenderModel * model ) {
	return WorldForModel( model );
}
int ResolveModelIndex( const idRenderModel * model ) {
	int index = -1;
	WorldForModel( model, &index );
	return index;
}
int ResolveModelReferenceCount( const idRenderModel * model ) {
	return model != nullptr && model->committed != nullptr
		? model->committed->references.Num() : 0;
}
bool ResolveModelVisibility( const idRenderModel * model ) {
	return WorldForModel( model ) != nullptr && !model->unlinked &&
		model->committed != nullptr && model->committed->mayBeDrawn;
}
void ClearModelOcclusion( idRenderModel * ) {}
void CommitModelName( idRenderModel * model, const char * name ) {
	if ( model != nullptr && model->committed != nullptr )
		model->committed->name = name;
}
void CommitModelSurfaces( idRenderModel * model,
		const idList< idRenderModelSurface, 85 > & surfaces ) {
	if ( model != nullptr && model->committed != nullptr ) {
		model->committed->surfaces.SetNum( surfaces.Num() );
		for ( int index = 0; index < surfaces.Num(); ++index )
			model->committed->surfaces[index] = surfaces[index];
	}
}
void SetModelParm( idParmBlock * block, const idDeclRenderParm * parm,
		const parmValue_t & value ) {
	if ( block != nullptr ) block->SetParm( parm, value );
}
const char * ModelMaterialName( const idMaterial * material ) {
	return material != nullptr ? material->GetName() : "";
}
const idMaterial * ResolveModelMaterial( const char * name,
		bool makeDefault ) {
	idResourceList * const list = idResourceList::ForTypeName( "material" );
	return list != nullptr && name != nullptr && name[0] != '\0'
		? static_cast< const idMaterial * >( list->Load( name, makeDefault ) )
		: nullptr;
}
bool SaveModelParmBlock( const idParmBlock * block, idFile * file ) {
	if ( block == nullptr || file == nullptr ) return false;
	block->Save( file );
	return true;
}
bool LoadModelParmBlock( idParmBlock * block, idFile * file ) {
	return block != nullptr && file != nullptr && block->Load( file );
}

void InstallModelCallbacks() {
	static bool installed = false;
	if ( installed ) return;
	installed = true;
	idRenderModel::SetMaterialPersistenceCallbacks( ModelMaterialName,
		ResolveModelMaterial );
	idRenderModel::SetParmBlockPersistenceCallbacks( SaveModelParmBlock,
		LoadModelParmBlock );
	idRenderModel::SetRuntimeCallbacks( ScheduleModelCommit, ModelCommitted,
		ResolveModelWorld, ResolveModelIndex, ResolveModelReferenceCount,
		ResolveModelVisibility, ClearModelOcclusion, CommitModelName,
		CommitModelSurfaces );
	idRenderModel::SetModelResourceCallbacks( SetModelParm, nullptr );
}

idVec3 ComponentDivide( const idVec3 & value, const idVec3 & scale ) {
	return idVec3(
		std::fabs( scale.x ) > 1.0e-20f ? value.x / scale.x : value.x,
		std::fabs( scale.y ) > 1.0e-20f ? value.y / scale.y : value.y,
		std::fabs( scale.z ) > 1.0e-20f ? value.z / scale.z : value.z );
}

}

idRenderWorld::~idRenderWorld() = default;

idRenderWorld * R_CreateRenderWorld( const char * mapName,
		const bool comboMap ) {
	idRenderWorldLocal * const world = new idRenderWorldLocal();
	if ( !world->InitFromMap( mapName, comboMap ) ) {
		delete world;
		return nullptr;
	}
	return world;
}

void R_DestroyRenderWorld( idRenderWorld * world ) { delete world; }

idRenderWorld * R_GetNextRenderWorld( idRenderWorld * world ) {
	return world != nullptr
		? static_cast< idRenderWorldLocal * >( world )->nextOnWorldList : nullptr;
}

void R_SetNextRenderWorld( idRenderWorld * world, idRenderWorld * next ) {
	if ( world != nullptr ) static_cast< idRenderWorldLocal * >( world )
		->nextOnWorldList = static_cast< idRenderWorldLocal * >( next );
}

idRenderWorldLocal::idRenderWorldLocal() :
	mapName( "" ),
	isComboMap( false ),
	everInitialized( false ),
	specificationCompleteHasBeenCalled( false ),
	hasWorldSurfaceOffsets( false ),
	nextOnWorldList( nullptr ),
	areaNodes( nullptr ),
	areaNodeBounds( nullptr ),
	areaNodeOcclusionIndex( nullptr ),
	numAreaNodes( 0 ),
	worldAreas( nullptr ),
	worldAreaSubspaceBounds( nullptr ),
	worldAreaGeometryBounds( nullptr ),
	numWorldAreas( 0 ),
	worldStaticModel( nullptr ),
	worldRenderModel( nullptr ),
	stampModel( nullptr ),
	foliageEditRenderModel( nullptr ),
	foliageRenderModel( nullptr ),
	detailEditRenderModel( nullptr ),
	detailRenderModel( nullptr ),
	transparencyRenderModel( nullptr ),
	decalRenderModel( nullptr ),
	testEnv( nullptr ),
	worldEnableStaticSpecular( true ) {
	ambientLighting.ambientMap = nullptr;
	globalShadows.shadowMap = nullptr;
	addAlwaysModels = nullptr;
	dimShadowModels = nullptr;
	staticWorldBounds[0].Zero();
	staticWorldBounds[1].Zero();
	InstallModelCallbacks();
	activeWorlds.Append( this );
	ClearWorld();
}

idRenderWorldLocal::~idRenderWorldLocal() {
	ClearWorld();
	activeWorlds.Remove( this );
}

const char * idRenderWorldLocal::GetName() { return mapName.c_str(); }
bool idRenderWorldLocal::IsComboMap() { return isComboMap; }
bool idRenderWorldLocal::HasGlobalShadows() {
	return globalShadows.shadowMap != nullptr &&
		globalShadows.shadowMap->map != nullptr &&
		globalShadows.shadowMap->useShadowMap;
}

void idRenderWorldLocal::UpdateDeferredPositions() {
	for ( int index = 0; index < renderModels.Num(); ++index ) {
		idRenderModel * const model = renderModels[index];
		if ( model != nullptr && model->useDeferredPosition ) model->Commit();
	}
}

void idRenderWorldLocal::AddEnvironment( const idBounds * bounds,
		const idDeclEnv * environment ) {
	if ( bounds == nullptr || environment == nullptr ||
			dynamicEnvironments.Num() >= dynamicEnvironments.Max() ) return;
	dynamicEnvironment_t entry;
	entry.bounds = *bounds;
	entry.env = environment;
	dynamicEnvironments.Append( entry );
}

void idRenderWorldLocal::ClearEnvironments() {
	dynamicEnvironments.Clear();
	testEnv = nullptr;
}

int idRenderWorldLocal::NumEnvironments() {
	return dynamicEnvironments.Num();
}

const idParmBlock * idRenderWorldLocal::GetCurrentBlendedParms() {
	return renderViews.Num() > 0 && renderViews[0] != nullptr
		? &renderViews[0]->blendedEnvironmentParms : nullptr;
}

const idDeclEnv * idRenderWorldLocal::GetEnvironmentDeclForCurrentViewPoint() {
	if ( testEnv != nullptr ) return testEnv;
	if ( renderViews.Num() == 0 || renderViews[0] == nullptr ) return nullptr;
	const idVec3 & point = renderViews[0]->r.vieworg;
	for ( int index = dynamicEnvironments.Num() - 1; index >= 0; --index ) {
		const idBounds & bounds = dynamicEnvironments[index].bounds;
		if ( point.x >= bounds[0].x && point.x <= bounds[1].x &&
			point.y >= bounds[0].y && point.y <= bounds[1].y &&
			point.z >= bounds[0].z && point.z <= bounds[1].z ) {
			return dynamicEnvironments[index].env;
		}
	}
	return nullptr;
}

void idRenderWorldLocal::TestEnvironment( const idDeclEnv * environment ) {
	testEnv = environment;
}

void idRenderWorldLocal::SpecificationComplete( bool ) {
	specificationCompleteHasBeenCalled = true;
	CommitData();
}

idRenderModel * idRenderWorldLocal::StampModel() { return stampModel; }
idRenderModelFoliageEdit * idRenderWorldLocal::FoliageEditRenderModel() {
	return foliageEditRenderModel;
}
idRenderModelFoliage * idRenderWorldLocal::FoliageRenderModel() {
	return foliageRenderModel;
}
idRenderModelDetailEdit * idRenderWorldLocal::DetailEditRenderModel() {
	return detailEditRenderModel;
}
idRenderModelDetail * idRenderWorldLocal::DetailRenderModel() {
	return detailRenderModel;
}
idRenderModelTransparency * idRenderWorldLocal::TransparencyRenderModel() {
	return transparencyRenderModel;
}
idRenderModelDecal * idRenderWorldLocal::DecalModel() {
	return decalRenderModel;
}

idRenderLight * idRenderWorldLocal::AllocRenderLight(
		const bool skipAutoReplication ) {
	if ( renderLights.Num() >= renderLights.Max() ) return nullptr;
	idRenderLight * const light = new idRenderLight();
	const int index = renderLights.Append( light );
	if ( index < 0 ) { delete light; return nullptr; }
	light->skipAutoReplication = skipAutoReplication;
	light->committed->world = this;
	light->committed->index.Set( static_cast< unsigned int >( index ) );
	commitLights.SetNum( renderLights.Num() );
	postCommitLights.SetNum( renderLights.Num() );
	commitLights[index] = false;
	postCommitLights[index] = false;
	return light;
}

idRenderModel * idRenderWorldLocal::AllocRenderModel( const char * name,
		bool, int ) {
	if ( renderModels.Num() >= renderModels.Max() ) return nullptr;
	idWorldRenderModel * const model = new idWorldRenderModel();
	model->SetName( name != nullptr ? name : "" );
	const int index = renderModels.Append( model );
	if ( index < 0 ) { delete model; return nullptr; }
	model->committed = new idRenderModelCommitted();
	model->committed->world = this;
	model->committed->index.Set( static_cast< unsigned int >( index ) );
	return model;
}

void idRenderWorldLocal::ScheduleLightCommit( idRenderLight * light ) {
	if ( light == nullptr ) return;
	const int index = light->GetIndex();
	if ( index < 0 || index >= renderLights.Num() ) return;
	commitLights.SetNum( renderLights.Num() );
	commitLights[index] = true;
}

void idRenderWorldLocal::MarkLightSerialized( idRenderLight * light,
		bool changed, bool deleted ) {
	if ( light == nullptr ) return;
	if ( serializedLights.FindIndex( light ) < 0 ) serializedLights.Append( light );
	if ( changed ) {
		light->needWriteToSnapshot = true;
		++light->serializedChangeCount;
	}
	if ( deleted ) light->deleteOnSync = true;
}

void idRenderWorldLocal::MarkAllLightsAsSerialized() {
	for ( int index = 0; index < renderLights.Num(); ++index ) {
		MarkLightSerialized( renderLights[index], true, false );
	}
}

void idRenderWorldLocal::SetBinaryModelState( const char * name,
		const bool state ) {
	if ( name == nullptr ) return;
	for ( int index = 0; index < binaryModelNames.Num(); ++index ) {
		if ( idStr::Icmp( binaryModelNames[index].c_str(), name ) == 0 ) {
			binaryModelState[index] = state;
			return;
		}
	}
	binaryModelNames.Append( idStr( name ) );
	binaryModelState.Append( state );
}

void idRenderWorldLocal::SetNumRenderViews( int count ) {
	count = std::max( 0, std::min( count, renderViews.Max() ) );
	while ( renderViews.Num() > count ) {
		delete renderViews[renderViews.Num() - 1];
		renderViews.RemoveIndex( renderViews.Num() - 1 );
	}
	while ( renderViews.Num() < count ) renderViews.Append( new idRenderView() );
	for ( int index = 0; index < renderViews.Num(); ++index ) {
		renderViews[index]->viewIndex = index;
	}
}

idRenderView * idRenderWorldLocal::RenderViewForIndex( const int index ) {
	return index >= 0 && index < renderViews.Num() ? renderViews[index] : nullptr;
}
int idRenderWorldLocal::GetNumRenderModels() { return renderModels.Num(); }
idRenderModel * idRenderWorldLocal::RenderModelForIndex( const int index ) {
	return index >= 0 && index < renderModels.Num() ? renderModels[index] : nullptr;
}
int idRenderWorldLocal::GetNumRenderLights() { return renderLights.Num(); }
idRenderLight * idRenderWorldLocal::RenderLightForIndex( const int index ) {
	return index >= 0 && index < renderLights.Num() ? renderLights[index] : nullptr;
}
int idRenderWorldLocal::GetNumMegatextures() { return megaTextures.Num(); }
pageSource_t idRenderWorldLocal::MegatextureForIndex( const int index ) {
	return index >= 0 && index < megaTextures.Num()
		? static_cast< pageSource_t >( index + PAGESOURCE_VMTR )
		: PAGESOURCE_INVALID;
}
const idStaticModel * idRenderWorldLocal::GetWorldStaticModel() {
	return worldStaticModel;
}
const idRenderModel * idRenderWorldLocal::GetWorldRenderModel() {
	return worldRenderModel;
}
void idRenderWorldLocal::GetStaticWorldBounds( idBounds * bounds ) {
	if ( bounds != nullptr ) *bounds = staticWorldBounds;
}

bool idRenderWorldLocal::Trace( modelTrace_t * result,
		const idVec3 * start, const idVec3 * end, const idTraceOpts * ) {
	if ( result == nullptr || start == nullptr || end == nullptr ) return false;
	result->tr.fraction = 1.0f;
	result->tr.point = *end;
	result->tr.normal.Zero();
	result->tr.jointIndex = -1;
	result->tr.indexes[0] = result->tr.indexes[1] = result->tr.indexes[2] = -1;
	result->surf = nullptr;
	result->entity = nullptr;
	for ( int modelIndex = 0; modelIndex < renderModels.Num(); ++modelIndex ) {
		const idRenderModel * const model = renderModels[modelIndex];
		if ( model == nullptr || model->unlinked ) continue;
		idVec3 localStart;
		idVec3 localEnd;
		model->GlobalPointToLocal( *start, localStart );
		model->GlobalPointToLocal( *end, localEnd );
		localStart = ComponentDivide( localStart, model->g.scale );
		localEnd = ComponentDivide( localEnd, model->g.scale );
		for ( int surfaceIndex = 0; surfaceIndex < model->surfaces.Num();
				++surfaceIndex ) {
			const idRenderModelSurface & surface = model->surfaces[surfaceIndex];
			if ( surface.geometry == nullptr ) continue;
			const localTrace_t trace = R_TraceTriangles( *surface.geometry,
				localStart, localEnd, 0.0f, true );
			if ( trace.fraction >= result->tr.fraction ) continue;
			result->tr = trace;
			result->surf = &surface;
			result->entity = model;
			model->LocalPointToGlobal( trace.point, result->tr.point );
			result->tr.normal = model->g.axis[0] * trace.normal.x +
				model->g.axis[1] * trace.normal.y +
				model->g.axis[2] * trace.normal.z;
			result->tr.normal.NormalizeFast();
		}
	}
	return result->tr.fraction < 1.0f;
}

float idRenderWorldLocal::ShadowSample( const idVec3 * point ) {
	return point != nullptr ? globalShadows.ShadowSample( *point ) : 1.0f;
}

void idRenderWorldLocal::CommitData() {
	for ( int index = 0; index < renderModels.Num(); ++index ) {
		if ( renderModels[index] != nullptr && !renderModels[index]->unlinked )
			renderModels[index]->Commit();
	}
	commitLights.SetNum( renderLights.Num() );
	postCommitLights.SetNum( renderLights.Num() );
	for ( int index = 0; index < renderLights.Num(); ++index ) {
		idRenderLight * const light = renderLights[index];
		if ( light == nullptr ) continue;
		if ( commitLights[index] || !light->unlinked ) {
			light->Commit();
			commitLights[index] = false;
			postCommitLights[index] = true;
		}
	}
	PostCommitData();
}

void idRenderWorldLocal::PostCommitData() {
	for ( int index = 0; index < renderLights.Num(); ++index ) {
		if ( index < postCommitLights.Num() && postCommitLights[index] &&
				renderLights[index] != nullptr ) {
			renderLights[index]->committed->PostCommit();
			postCommitLights[index] = false;
		}
	}
	for ( int index = renderLights.Num() - 1; index >= 0; --index ) {
		idRenderLight * const light = renderLights[index];
		if ( light == nullptr || !light->deleteOnSync ) continue;
		delete light;
		renderLights[index] = nullptr;
	}
}

void idRenderWorldLocal::ClearWorld() {
	for ( int index = 0; index < renderViews.Num(); ++index )
		delete renderViews[index];
	renderViews.Clear();
	for ( int index = 0; index < renderLights.Num(); ++index )
		delete renderLights[index];
	renderLights.Clear();
	for ( int index = 0; index < renderModels.Num(); ++index ) {
		if ( renderModels[index] != nullptr ) {
			delete renderModels[index]->committed;
			renderModels[index]->committed = nullptr;
		}
		delete renderModels[index];
	}
	renderModels.Clear();
	linkedRenderModels.Clear();
	linkedRenderLights.Clear();
	addAlwaysModels = nullptr;
	dimShadowModels = nullptr;
	serializedLights.Clear();
	commitLights.Clear();
	postCommitLights.Clear();
	dynamicEnvironments.Clear();
	megaTextures.Clear();
	areaNodesStorage.SetNum( 1 );
	areaNodesStorage[0].plane = idPlane( 0.0f, 0.0f, 1.0f, 131072.0f );
	areaNodesStorage[0].children[0] = -1;
	areaNodesStorage[0].children[1] = 0;
	areaNodes = areaNodesStorage.Ptr();
	areaNodeBoundsStorage.SetNum( 1 );
	areaNodeBoundsStorage[0][0].Set( -131072.0f, -131072.0f, -131072.0f );
	areaNodeBoundsStorage[0][1].Set( 131072.0f, 131072.0f, 131072.0f );
	areaNodeBounds = areaNodeBoundsStorage.Ptr();
	areaNodeOcclusionIndexStorage.SetNum( 1 );
	areaNodeOcclusionIndexStorage[0] = -1;
	areaNodeOcclusionIndex = areaNodeOcclusionIndexStorage.Ptr();
	numAreaNodes = 1;
	worldAreasStorage.SetNum( 1 );
	worldAreasStorage[0].areaNum = 0;
	worldAreas = worldAreasStorage.Ptr();
	worldAreaSubspaceBoundsStorage.SetNum( 1 );
	worldAreaSubspaceBoundsStorage[0] = areaNodeBoundsStorage[0];
	worldAreaSubspaceBounds = worldAreaSubspaceBoundsStorage.Ptr();
	worldAreaGeometryBoundsStorage.SetNum( 1 );
	worldAreaGeometryBoundsStorage[0] = areaNodeBoundsStorage[0];
	worldAreaGeometryBounds = worldAreaGeometryBoundsStorage.Ptr();
	numWorldAreas = 1;
	staticWorldBounds[0].Zero();
	staticWorldBounds[1].Zero();
	worldRenderModel = nullptr;
	stampModel = nullptr;
}
