#include "coderenderparm.h"

#include "declrenderparm.h"
#include "declrenderprog.h"
#include "image.h"
#include "idlib/containers/list.h"
#include "idlib/text/parser.h"

#include <cstring>

namespace {
	idList< idCodeRenderParm *, 56 > & CodeRenderParms() {
		static idList< idCodeRenderParm *, 56 > parms( 128 );
		return parms;
	}

	parmType_t CodeParmType( const char * text, bool & cubeFilter ) {
		cubeFilter = false;
		if ( idStr::Icmp( text, "environment" ) == 0 ) {
			cubeFilter = true;
			return PT_TEXTURE_CUBE;
		}
		if ( idStr::Icmp( text, "Tex" ) == 0 ) return PT_TEXTURE;
		if ( idStr::Icmp( text, "Tex2D" ) == 0 ) return PT_TEXTURE_2D;
		if ( idStr::Icmp( text, "Tex3D" ) == 0 ) return PT_TEXTURE_3D;
		if ( idStr::Icmp( text, "TexCube" ) == 0 ) return PT_TEXTURE_CUBE;
		if ( idStr::Icmp( text, "TexShadow2D" ) == 0 ) return PT_TEXTURE_SHADOW_2D;
		if ( idStr::Icmp( text, "TexShadow3D" ) == 0 ) return PT_TEXTURE_SHADOW_3D;
		if ( idStr::Icmp( text, "TexShadowCube" ) == 0 ) return PT_TEXTURE_SHADOW_CUBE;
		if ( idStr::Icmp( text, "TexMultisample2D" ) == 0 ) return PT_TEXTURE_MULTISAMPLE_2D;
		if ( idStr::Icmp( text, "Program" ) == 0 ) return PT_PROGRAM;
		if ( idStr::Icmp( text, "String" ) == 0 ) return PT_STRING;
		return PT_VECTOR;
	}
}

idCodeRenderParm::idCodeRenderParm( const char * name_, const char * initializer ) :
	name( name_ != nullptr ? name_ : "" ), initString( initializer ),
	parmIndex( RENDERPARM_INVALID ), parmType( PT_VECTOR ),
	cubeFilterTexture( false ), edit( PE_NO_EDIT ) {
	std::memset( &declaredValue, 0, sizeof( declaredValue ) );
	editRange[0] = 0.0f;
	editRange[1] = 1.0f;
	if ( RenderParmForName( name.c_str() ) != nullptr ) return;
	CodeRenderParms().Append( this );
	// Retail defers resource-backed initializers until the renderer/resource
	// lists exist.  Vector and string constants are safe during registration.
	idParser typeParser( LEXFL_NOFATALERRORS | LEXFL_NOSTRINGCONCAT );
	if ( initString != nullptr ) {
		typeParser.LoadMemory( initString, static_cast< int >( std::strlen( initString ) ),
			name.c_str() );
		idToken typeToken;
		if ( typeParser.ReadToken( typeToken ) ) {
			bool filter = false;
			const parmType_t type = CodeParmType( typeToken.c_str(), filter );
			if ( type == PT_VECTOR || type == PT_STRING ) ParseInitializer();
		}
	}
}

idCodeRenderParm * idCodeRenderParm::RenderParmForName( const char * name_ ) {
	for ( int index = 0; index < CodeRenderParms().Num(); ++index ) {
		idCodeRenderParm * const parm = CodeRenderParms()[index];
		if ( parm != nullptr && idStr::Icmp( parm->name.c_str(), name_ ) == 0 ) return parm;
	}
	return nullptr;
}

void idCodeRenderParm::ParseInitializer() {
	if ( initString == nullptr ) return;
	idParser parser( LEXFL_NOFATALERRORS | LEXFL_NOSTRINGCONCAT );
	parser.LoadMemory( initString, static_cast< int >( std::strlen( initString ) ),
		name.c_str() );
	idToken token;
	if ( !parser.ReadToken( token ) ) return;
	parmType = CodeParmType( token.c_str(), cubeFilterTexture );
	if ( parmType == PT_VECTOR ) {
		idDeclRenderParm::ParseVectorConstant( parser, declaredValue.value );
	} else if ( parmType >= PT_TEXTURE && parmType <= PT_TEXTURE_MULTISAMPLE_2D ) {
		if ( parser.ReadToken( token ) && idStr::Cmp( token.c_str(), "0" ) != 0 ) {
			declaredValue.image = static_cast< const idImage * >(
				idImage::resourceList.Load( token.c_str(), true ) );
		}
	} else if ( parmType == PT_PROGRAM ) {
		if ( parser.ReadToken( token ) && idStr::Cmp( token.c_str(), "0" ) != 0 ) {
			idResourceList * const list = idResourceList::ForTypeName( "renderProg" );
			declaredValue.program = list != nullptr
				? static_cast< const idDeclRenderProg * >( list->Load( token.c_str(), true ) ) : nullptr;
		}
	} else if ( parmType == PT_STRING && parser.ReadToken( token ) ) {
		idAtomicString text( token.c_str() );
		declaredValue.string = text.c_str();
	}
}

void idCodeRenderParm::ResolveIRenderParmResources() {
	RegisterRecoveredCodeRenderParms();
	for ( int index = 0; index < CodeRenderParms().Num(); ++index ) {
		idCodeRenderParm * const codeParm = CodeRenderParms()[index];
		codeParm->ParseInitializer();
		idDeclRenderParm * const decl = const_cast< idDeclRenderParm * >(
			idDeclRenderParm::FindByName( codeParm->name.c_str(), true ) );
		if ( decl == nullptr ) continue;
		codeParm->parmIndex = decl->parmIndex;
		// Compiled initializers are authoritative for PC-only generated parms;
		// parsed declarations retain their authored value and editor metadata.
		decl->creator = PC_CONSTANT;
		decl->parmType = codeParm->parmType;
		decl->cubeFilterTexture = codeParm->cubeFilterTexture;
		decl->declaredValue = codeParm->declaredValue;
		decl->edit = codeParm->edit;
		decl->editRange[0] = codeParm->editRange[0];
		decl->editRange[1] = codeParm->editRange[1];
	}
}

const idDeclRenderParm * idCodeRenderParm::GetDecl() const {
	return idDeclRenderParm::FindByIndex( parmIndex );
}
