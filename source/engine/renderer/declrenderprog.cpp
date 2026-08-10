#include "declrenderprog.h"

#include "declrenderparm.h"
#include "image.h"
#include "../../shared/idlib/text/parser.h"

#include <cstdio>
#include <cstring>

idDeclInfoTemplate< idDeclRenderProg > idDeclRenderProg::resourceList(
	"renderProg", "idDeclRenderProg", "renderprog" );

idDeclRenderProg::vertexDeclaration_t::vertexDeclaration_t() :
	vertexShaderD3D( nullptr ), vertexDeclarationD3D( nullptr ), vertexMask( 0 ) {
	streamStrides[0] = streamStrides[1] = streamStrides[2] = 0;
}

idDeclRenderProg::idDeclRenderProg() : renamed( nullptr ), glState( GLS_DEFAULT ),
	hasClip( false ), hasAlphaToCoverage( false ), hasHardwareSkinning( false ),
	hasInteractions( false ), has16BitScaleBias( false ), hasVertexTexture( false ),
	fragmentOutputs( 1 ), registerCountPS3( 0 ), registerCount360( 0 ), stageSort( 0.0f ),
	parmBlock( THREAD_MAIN ), vertexMask( 0 ), vertexProgramChecksum( 0 ),
	fragmentProgramChecksum( 0 ), numVertexParms( 0 ), numFragmentParms( 0 ),
	numTextureParms( 0 ), hasDerived( false ), inheritedVertexProgram( nullptr ),
	inheritedFragmentProgram( nullptr ), numVertexDeclarations( 0 ),
	compiledVertexCode( nullptr ), fragmentShaderD3D( nullptr ), isFastZ( false ) {
	std::memset( vertexParms, 0, sizeof( vertexParms ) );
	std::memset( fragmentParms, 0, sizeof( fragmentParms ) );
	std::memset( textureParms, 0, sizeof( textureParms ) );
	std::memset( versions, 0, sizeof( versions ) );
}

idDeclRenderProg::~idDeclRenderProg() { FreeData(); }

idDeclInfo * idDeclRenderProg::GetDeclInfo() const { return &resourceList; }

const char * idDeclRenderProg::DefaultDefinition() const {
	return "renderProg { vertex { float4 main(float4 p:POSITION):POSITION{return p;} } "
		"fragment { float4 main():COLOR{return float4(1,0,1,1);} } }";
}

void idDeclRenderProg::SetSource( programType_t type, progTarget_t target,
		const char * source ) {
	if ( target < 0 || target >= PT_NUM_TARGETS ) return;
	if ( type == PROGRAM_TYPE_VERTEX ) vertexCode[target] = source != nullptr ? source : "";
	else fragmentCode[target] = source != nullptr ? source : "";
}

void idDeclRenderProg::Parse( idParser * parser ) {
	FreeData();
	if ( parser == nullptr ) return;
	idToken token;
	while ( parser->ReadToken( token ) ) {
		if ( idStr::Icmp( token.c_str(), "vertex" ) == 0 ||
				idStr::Icmp( token.c_str(), "vertex_d3d" ) == 0 ) {
			idStr source;
			if ( parser->ParseBracedSectionExact( source, true ) ) SetSource(
				PROGRAM_TYPE_VERTEX, PT_PC_D3D, source.c_str() );
		} else if ( idStr::Icmp( token.c_str(), "fragment" ) == 0 ||
				idStr::Icmp( token.c_str(), "pixel" ) == 0 ||
				idStr::Icmp( token.c_str(), "fragment_d3d" ) == 0 ) {
			idStr source;
			if ( parser->ParseBracedSectionExact( source, true ) ) SetSource(
				PROGRAM_TYPE_FRAGMENT, PT_PC_D3D, source.c_str() );
		} else if ( idStr::Icmp( token.c_str(), "state" ) == 0 ) {
			glState = static_cast< glStateBits_t >( parser->ParseInt() );
		}
	}
	UploadTargetCode();
}

void idDeclRenderProg::Clear( progTarget_t target ) {
	if ( target >= 0 && target < PT_NUM_TARGETS ) {
		vertexCode[target].Clear();
		fragmentCode[target].Clear();
		versions[target] = nullptr;
	}
}

void idDeclRenderProg::FreeData() {
	for ( vertexDeclaration_t & declaration : vertexDeclarations ) {
		D3D9Release( declaration.vertexShaderD3D );
		D3D9Release( declaration.vertexDeclarationD3D );
		declaration.vertexMask = 0;
	}
	numVertexDeclarations = 0;
	D3D9Release( compiledVertexCode );
	D3D9Release( fragmentShaderD3D );
	inheritedVertexProgram = nullptr;
	inheritedFragmentProgram = nullptr;
	GL_ResetProgramState();
}

void idDeclRenderProg::Print() {
	std::printf( "renderProg %-40s state=%016llx vertexMask=%08x%s\n", GetName(),
		static_cast< unsigned long long >( glState ), vertexMask,
		compilerError.Length() > 0 ? " [compile error]" : "" );
}

void idDeclRenderProg::List() { Print(); }

unsigned int idDeclRenderProg::Size() const {
	return static_cast< unsigned int >( sizeof( *this ) +
		vertexCode[PT_PC_D3D].Length() + fragmentCode[PT_PC_D3D].Length() );
}

bool idDeclRenderProg::ProgUsesParm( const idDeclRenderParm * parm ) const {
	if ( parm == nullptr ) return false;
	for ( int index = 0; index < numVertexParms; ++index )
		if ( vertexParms[index] == parm->parmIndex ) return true;
	for ( int index = 0; index < numFragmentParms; ++index )
		if ( fragmentParms[index] == parm->parmIndex ) return true;
	for ( int index = 0; index < numTextureParms; ++index )
		if ( textureParms[index] == parm->parmIndex ) return true;
	return false;
}

void idDeclRenderProg::SetTextureParm( int index, const idImage * image ) const {
	BindTexture( image, index );
}

void idDeclRenderProg::BindTexture( const idImage * image, int unit ) {
	if ( image != nullptr ) image->Bind( unit );
	else if ( rendererD3D9.GetDevice() != nullptr ) rendererD3D9.GetDevice()->SetTexture( unit, nullptr );
}

void idDeclRenderProg::BindForImmediate( glStateBits_t extraState ) const {
	idDeclRenderProg * mutableThis = const_cast< idDeclRenderProg * >( this );
	if ( mutableThis->compiledVertexCode == nullptr && mutableThis->fragmentShaderD3D == nullptr )
		mutableThis->UploadTargetCode();
	if ( GetVertexProgramForVertexFormat( vertexMask ) == nullptr )
		mutableThis->CreateVertexShaderForVertexFormat( vertexMask );
	IDirect3DDevice9 * device = rendererD3D9.GetDevice();
	if ( device == nullptr ) return;
	device->SetVertexShader( GetVertexProgramForVertexFormat( vertexMask ) );
	device->SetVertexDeclaration( GetVertexDeclarationForVertexFormat( vertexMask ) );
	device->SetPixelShader( fragmentShaderD3D );
	GL_State( glState | extraState );
}
