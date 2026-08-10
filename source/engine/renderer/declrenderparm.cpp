#include "declrenderparm.h"

#include "declrenderprog.h"
#include "image.h"
#include "idlib/text/parser.h"

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace {
	static const int MAX_RENDER_PARMS = RENDERPARM_INVALID;
	const idDeclRenderParm * renderParmByIndex[MAX_RENDER_PARMS] = {};

	parmType_t ParmTypeForToken( const char * token, bool & cubeFilter ) {
		cubeFilter = false;
		if ( idStr::Icmp( token, "environment" ) == 0 ) {
			cubeFilter = true;
			return PT_TEXTURE_CUBE;
		}
		if ( idStr::Icmp( token, "Tex" ) == 0 ) return PT_TEXTURE;
		if ( idStr::Icmp( token, "Tex2D" ) == 0 ) return PT_TEXTURE_2D;
		if ( idStr::Icmp( token, "Tex3D" ) == 0 ) return PT_TEXTURE_3D;
		if ( idStr::Icmp( token, "TexCube" ) == 0 ) return PT_TEXTURE_CUBE;
		if ( idStr::Icmp( token, "TexShadow2D" ) == 0 ) return PT_TEXTURE_SHADOW_2D;
		if ( idStr::Icmp( token, "TexShadow3D" ) == 0 ) return PT_TEXTURE_SHADOW_3D;
		if ( idStr::Icmp( token, "TexShadowCube" ) == 0 ) return PT_TEXTURE_SHADOW_CUBE;
		if ( idStr::Icmp( token, "TexMultisample2D" ) == 0 ) return PT_TEXTURE_MULTISAMPLE_2D;
		if ( idStr::Icmp( token, "Program" ) == 0 ) return PT_PROGRAM;
		if ( idStr::Icmp( token, "String" ) == 0 ) return PT_STRING;
		return PT_VECTOR;
	}

	const char * ParmTypeName( const parmType_t type ) {
		static const char * const names[PT_MAX] = {
			"Vec", "Tex", "Tex2D", "Tex3D", "TexCube", "TexShadow2D",
			"TexShadow3D", "TexShadowCube", "TexMultisample2D", "Program", "String"
		};
		return type >= 0 && type < PT_MAX ? names[type] : "invalid";
	}
}

idDeclInfoTemplate< idDeclRenderParm > idDeclRenderParm::resourceList(
	"renderParm", "idDeclRenderParm", "renderparm" );

idDeclRenderParm::idDeclRenderParm() :
	parmIndex( RENDERPARM_INVALID ), parmType( PT_VECTOR ), creator( PC_PARSED ),
	cubeFilterTexture( false ), edit( PE_NO_EDIT ) {
	std::memset( &declaredValue, 0, sizeof( declaredValue ) );
	editRange[0] = 0.0f;
	editRange[1] = 1.0f;
}

idDeclRenderParm::~idDeclRenderParm() {
	if ( parmIndex >= 0 && parmIndex < MAX_RENDER_PARMS
		&& renderParmByIndex[parmIndex] == this ) {
		renderParmByIndex[parmIndex] = nullptr;
	}
}

idDeclInfo * idDeclRenderParm::GetDeclInfo() const { return &resourceList; }
const char * idDeclRenderParm::DefaultDefinition() const { return "{ vec 0 }\n"; }
unsigned int idDeclRenderParm::Size() const { return sizeof( *this ); }

void idDeclRenderParm::FreeData() {
	parmType = PT_VECTOR;
	creator = PC_PARSED;
	cubeFilterTexture = false;
	edit = PE_NO_EDIT;
	editRange[0] = 0.0f;
	editRange[1] = 1.0f;
	std::memset( &declaredValue, 0, sizeof( declaredValue ) );
}

void idDeclRenderParm::RegisterParm() {
	if ( parmIndex >= 0 && parmIndex < MAX_RENDER_PARMS ) {
		renderParmByIndex[parmIndex] = this;
		return;
	}
	for ( int index = 0; index < MAX_RENDER_PARMS; ++index ) {
		if ( renderParmByIndex[index] == nullptr ) {
			parmIndex = index;
			renderParmByIndex[index] = this;
			return;
		}
	}
	parmIndex = RENDERPARM_INVALID;
}

const idDeclRenderParm * idDeclRenderParm::FindByIndex( const int index ) {
	return index >= 0 && index < MAX_RENDER_PARMS ? renderParmByIndex[index] : nullptr;
}

const idDeclRenderParm * idDeclRenderParm::FindByName( const char * name,
	const bool makeDefault ) {
	if ( name == nullptr || name[0] == '\0' ) return nullptr;
	return static_cast< const idDeclRenderParm * >(
		resourceList.FindWithInheritance( name, makeDefault ) );
}

bool idDeclRenderParm::ParseVectorConstant( idParser & parser, float vector[4] ) {
	std::fill( vector, vector + 4, 0.0f );
	idToken token;
	if ( !parser.ReadToken( token ) ) return false;
	bool braced = idStr::Cmp( token.c_str(), "{" ) == 0;
	if ( !braced ) {
		bool negative = idStr::Cmp( token.c_str(), "-" ) == 0;
		if ( negative && !parser.ReadToken( token ) ) return false;
		char * end = nullptr;
		const float scalar = std::strtof( token.c_str(), &end );
		if ( end == token.c_str() || *end != '\0' ) {
			parser.Warning( "Non numeric render parm constant '%s'", token.c_str() );
			return false;
		}
		std::fill( vector, vector + 4, negative ? -scalar : scalar );
		return true;
	}

	int count = 0;
	while ( count < 4 && parser.ReadToken( token ) ) {
		if ( idStr::Cmp( token.c_str(), "}" ) == 0 ) break;
		bool negative = idStr::Cmp( token.c_str(), "-" ) == 0;
		if ( negative && !parser.ReadToken( token ) ) return false;
		char * end = nullptr;
		const float value = std::strtof( token.c_str(), &end );
		if ( end == token.c_str() || *end != '\0' ) return false;
		vector[count++] = negative ? -value : value;
		if ( !parser.ReadToken( token ) ) break;
		if ( idStr::Cmp( token.c_str(), "}" ) == 0 ) break;
		if ( idStr::Cmp( token.c_str(), "," ) != 0 ) {
			parser.Warning( "Missing comma in render parm vector" );
			return false;
		}
	}
	if ( count == 1 ) std::fill( vector + 1, vector + 4, vector[0] );
	return count > 0;
}

const idImage * idDeclRenderParm::ParseImageLine( idParser & parser ) const {
	idToken token;
	if ( !parser.ReadToken( token ) || idStr::Cmp( token.c_str(), "0" ) == 0 ) {
		return nullptr;
	}
	return static_cast< const idImage * >(
		idImage::resourceList.Load( token.c_str(), true ) );
}

void idDeclRenderParm::ParseValue( idParser & parser, parmValue_t & value ) const {
	std::memset( &value, 0, sizeof( value ) );
	if ( parmType == PT_VECTOR ) {
		ParseVectorConstant( parser, value.value );
		return;
	}
	if ( parmType >= PT_TEXTURE && parmType <= PT_TEXTURE_MULTISAMPLE_2D ) {
		value.image = ParseImageLine( parser );
		return;
	}
	idToken token;
	if ( !parser.ReadToken( token ) ) return;
	if ( parmType == PT_PROGRAM ) {
		if ( idStr::Cmp( token.c_str(), "0" ) != 0 ) {
			idResourceList * const list = idResourceList::ForTypeName( "renderProg" );
			value.program = list != nullptr
				? static_cast< const idDeclRenderProg * >( list->Load( token.c_str(), true ) )
				: nullptr;
		}
		return;
	}
	if ( parmType == PT_STRING ) {
		idStr text( token.c_str() );
		while ( parser.ReadToken( token ) ) {
			if ( idStr::Cmp( token.c_str(), "}" ) == 0 ) {
				parser.UnreadToken( token );
				break;
			}
			text.Append( ' ' );
			text.Append( token.c_str() );
		}
		idAtomicString atomic( text.c_str() );
		value.string = atomic.c_str();
	}
}

void idDeclRenderParm::ParseStringToValue( const char * text,
	parmValue_t & value ) const {
	idParser parser( LEXFL_NOSTRINGCONCAT | LEXFL_NOFATALERRORS );
	const char * const source = text != nullptr ? text : "";
	parser.LoadMemory( source, static_cast< int >( std::strlen( source ) ),
		"render parm value" );
	ParseValue( parser, value );
}

void idDeclRenderParm::Parse( idParser * parser ) {
	if ( parser == nullptr ) return;
	FreeData();
	idToken token;
	if ( !parser->ReadToken( token ) ) return;
	if ( idStr::Cmp( token.c_str(), "{" ) == 0 && !parser->ReadToken( token ) ) return;
	bool cubeFilter = false;
	parmType = ParmTypeForToken( token.c_str(), cubeFilter );
	cubeFilterTexture = cubeFilter;
	ParseValue( *parser, declaredValue );
	RegisterParm();

	if ( !parser->ReadToken( token ) || idStr::Cmp( token.c_str(), "}" ) == 0 ) return;
	if ( idStr::Icmp( token.c_str(), "Bool" ) == 0 ) {
		edit = PE_BOOL;
	} else if ( idStr::Icmp( token.c_str(), "Color" ) == 0 ) {
		edit = PE_COLOR;
		if ( !parser->PeekTokenString( "}" ) ) {
			editRange[0] = parser->ParseFloat();
			parser->ExpectTokenString( "," );
			editRange[1] = parser->ParseFloat();
		}
	} else if ( idStr::Icmp( token.c_str(), "Range" ) == 0 ) {
		edit = PE_RANGE;
		editRange[0] = parser->ParseFloat();
		parser->ExpectTokenString( "," );
		editRange[1] = parser->ParseFloat();
	} else if ( idStr::Icmp( token.c_str(), "NoDisplay" ) == 0 ) {
		edit = PE_NO_DISPLAY;
	} else {
		parser->Warning( "Unknown render parm edit specifier '%s'", token.c_str() );
	}
	parser->CheckTokenString( "}" );
}

void idDeclRenderParm::List() {
	std::printf( "%4d %-28s %-20s", parmIndex, GetName(), ParmTypeName( parmType ) );
	if ( parmType == PT_VECTOR ) {
		std::printf( " { %g, %g, %g, %g }", declaredValue.value[0],
			declaredValue.value[1], declaredValue.value[2], declaredValue.value[3] );
	} else if ( parmType >= PT_TEXTURE && parmType <= PT_TEXTURE_MULTISAMPLE_2D ) {
		std::printf( " %s", declaredValue.image != nullptr ? declaredValue.image->GetName() : "0" );
	} else if ( parmType == PT_PROGRAM ) {
		std::printf( " %s", declaredValue.program != nullptr ? declaredValue.program->GetName() : "0" );
	} else if ( parmType == PT_STRING ) {
		std::printf( " \"%s\"", declaredValue.string != nullptr ? declaredValue.string : "" );
	}
	std::printf( "\n" );
}

void idDeclRenderParm::Print() { List(); }
