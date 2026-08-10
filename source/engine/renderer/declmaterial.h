#pragma once

#include "../decls/decl.h"
#include "parmblock.h"

class idDeclRenderProg;
class idImage;
class idMaterialMap;
class idVirtualMaterial;

enum materialCoverage_t : int {
	MC_BAD = 0,
	MC_INVISIBLE = 1,
	MC_PERFORATED = 2,
	MC_TRANSLUCENT = 3,
	MC_OPAQUE = 4
};

enum autospriteType_t : int {
	AUTOSPRITE_NONE = 0,
	AUTOSPRITE_VIEW_ORIENTED = 1,
	AUTOSPRITE_LONGEST_AXIS_ALIGNED = 2
};

enum decalProjType_t : int {
	DECALPROJ_PLANAR = 0,
	DECALPROJ_SPHERICAL = 1
};

#ifndef TECH5_PHYSICAL_PAGES_POOL_T_DEFINED
#define TECH5_PHYSICAL_PAGES_POOL_T_DEFINED
enum physicalPagesPool_t : int {
	PHYSICAL_PAGES_POOL_VMTR = 0,
	PHYSICAL_PAGES_POOL_UNIQUE = 1,
	PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY = 2,
	PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY2 = 3,
	PHYSICAL_PAGES_POOL_MAX = 4
};
#endif

#ifndef TECH5_PAGE_SOURCE_T_DEFINED
#define TECH5_PAGE_SOURCE_T_DEFINED
enum pageSource_t : int {
	PAGESOURCE_INVALID = 0,
	PAGESOURCE_VMTR = 1,
	PAGESOURCE_UNIQUE = 2,
	PAGESOURCE_ALLOC2 = 3,
	PAGESOURCE_ALLOC3,
	PAGESOURCE_ALLOC4,
	PAGESOURCE_ALLOC5,
	PAGESOURCE_ALLOC6,
	PAGESOURCE_ALLOC7,
	PAGESOURCE_ALLOC8,
	PAGESOURCE_ALLOC9,
	PAGESOURCE_ALLOC10,
	PAGESOURCE_ALLOC11,
	PAGESOURCE_ALLOC12,
	PAGESOURCE_ALLOC13,
	PAGESOURCE_ALLOC14,
	PAGESOURCE_TOTAL
};
#endif

enum materialProgramRole_t : int {
	MPR_AMBIENT = 0,
	MPR_INTERACTION = 1,
	MPR_SHADOW = 2,
	MPR_DEPTH_FILL = 3,
	MPR_ADD = 4,
	MPR_BLEND = 5,
	MPR_STAGE = 6,
	MPR_FADE_PERTURB = 7,
	MPR_MAX = 8
};

struct materialStage_t {
	struct textureStage_t { void * cinematic; } texture;
};

class alignas( 4 ) idMaterial : public idDecl {
public:
	idMaterial();
	~idMaterial() override;

	idDeclInfo * GetDeclInfo() const override;
	const char * DefaultDefinition() const override;
	bool SetImplicitText() override;
	void Parse( idParser * parser ) override;
	void FreeData() override;
	void Print() override;
	void List() override;
	unsigned int Size() const override;

	static bool IsValidMaterialName( const char * name,
		bool allowUnderscore, bool allowAmpersand );
	static const idMaterial * PackMaterials( const char * name,
		const idList< const idMaterial *, 5 > & materials,
		unsigned int flags );
	void Clear();
	void OptimizeRenderParmBlock();
	bool MaterialIsMergableWith( const idMaterial * other ) const;
	const idVec4 & GetMaterialMapping( const idMaterial * material ) const;
	bool MaterialMappingsAreCompatible( const idMaterial * material ) const;
	bool GetImageDimensions( int & width, int & height ) const;
	int GetImageWidth() const;
	int GetImageHeight() const;
	const idImage * GetEditorImage() const { return editorImage; }
	const materialStage_t * GetStage( int index ) const;
	const idDeclRenderProg * GetProgram( materialProgramRole_t role ) const;
	materialCoverage_t Coverage() const { return coverage; }
	bool CastsShadows() const { return materialCastsShadows != 0; }
	bool IsTwoSided() const { return materialIsTwoSided != 0; }
	bool HasInteractions() const { return materialHasInteractions != 0; }
	idParmBlock * GetParmBlock() { return &parmBlock; }
	const idParmBlock * GetParmBlock() const { return &parmBlock; }
	const idParmBlock * GetRenderParmBlock() const { return &renderParmBlock; }

	idVec4 atlasScaleBias;
	unsigned char materialUsesWrinkleMaps : 1;
	unsigned char materialUsesApproximatedLighting : 1;
	unsigned char materialUsesTransSortAtlas : 1;
	unsigned char materialIsTransparencySorted : 1;
	unsigned char materialHasInteractions : 1;
	unsigned char materialIsMixedUnique : 1;
	unsigned char materialIsTwoSided : 1;
	unsigned char materialCastsShadows : 1;
	unsigned char reservedMaterialBits : 5;
	unsigned char materialHasClipSpheres : 1;
	unsigned char skipSurfaceInfo : 1;
	unsigned char materialHasMergeableBlendedPass : 1;
	autospriteType_t materialAutospriteType;
	decalProjType_t materialDecalProjType;
	idParmBlock parmBlock;
	idParmBlock renderParmBlock;
	pageSource_t pageSource;
	const char * pageFileName;
	physicalPagesPool_t physicalPagesPool;
	const idDeclRenderProg * progs[MPR_MAX];
	float stageSort[MPR_MAX];
	idMaterialMap * materialMap;
	idVirtualMaterial * devVmtr;
	idVec4 virtualMapping;
	const idImage * editorImage;
	materialCoverage_t coverage;

	static idDeclInfoTemplate< idMaterial > resourceList;
};

class idASEMaterial {
public:
	idStr name;
	float uOffset;
	float vOffset;
	float uTiling;
	float vTiling;
	float angle;
};

#if defined( _WIN32 ) && !defined( _WIN64 )
static_assert( sizeof( idMaterial ) == 272,
	"Recovered material declaration ABI changed" );
#endif
