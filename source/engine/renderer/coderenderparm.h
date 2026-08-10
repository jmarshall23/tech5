#pragma once

#include "parmblock.h"
#include "renderer_types.h"
#include "idlib/text/atomicstring.h"

class idDeclRenderParm;
class idParser;

void RegisterRecoveredCodeRenderParms();

// Code render parms are the compiled-in half of the render-parm registry.
// Their layout is retained because the generated definitions instantiate
// these records during static initialization.
class alignas( 4 ) idCodeRenderParm {
public:
	idCodeRenderParm( const char * name, const char * initializer );

	static idCodeRenderParm * RenderParmForName( const char * name );
	static void ResolveIRenderParmResources();
	const idDeclRenderParm * GetDecl() const;

	idAtomicString name;
	const char * initString;
	int parmIndex;
	parmType_t parmType;
	bool cubeFilterTexture;
	parmValue_t declaredValue;
	parmEdit_t edit;
	float editRange[2];

private:
	void ParseInitializer();
};

#if defined( _WIN32 ) && !defined( _WIN64 )
static_assert( sizeof( idCodeRenderParm ) == 48,
	"Recovered code-render-parm ABI changed" );
#endif
