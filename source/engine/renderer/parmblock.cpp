#include "parmblock.h"

#include "declrenderparm.h"
#include "declrenderprog.h"
#include "image.h"
#include "idlib/filesystem/file.h"
#include "idlib/text/parser.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

namespace {
	const char * const opNames[] = {
		"=", "=", "=", "=", "swizzle", "+", "-", "*", "dot3", "dot4",
		"/", "%", ">", ">=", "<", "<=", "==", "!=", "&&", "||", "table"
	};

	bool IsTextureParm( const parmType_t type ) {
		return type >= PT_TEXTURE && type <= PT_TEXTURE_MULTISAMPLE_2D;
	}

	const char * ValueResourceName( const parmType_t type,
		const parmValue_t & value ) {
		if ( IsTextureParm( type ) ) {
			return value.image != nullptr ? value.image->GetName() : "";
		}
		if ( type == PT_PROGRAM ) {
			return value.program != nullptr ? value.program->GetName() : "";
		}
		return type == PT_STRING && value.string != nullptr ? value.string : "";
	}

	void AppendValueText( idStr & text, const parmType_t type,
		const parmValue_t & value ) {
		char buffer[256];
		if ( type == PT_VECTOR ) {
			if ( value.value[0] == value.value[1] && value.value[1] == value.value[2]
				&& value.value[2] == value.value[3] ) {
				std::snprintf( buffer, sizeof( buffer ), "%g", value.value[0] );
			} else {
				std::snprintf( buffer, sizeof( buffer ), "{ %g, %g, %g, %g }",
					value.value[0], value.value[1], value.value[2], value.value[3] );
			}
			text.Append( buffer );
		} else if ( type == PT_STRING ) {
			text.Append( '"' );
			text.Append( value.string != nullptr ? value.string : "" );
			text.Append( '"' );
		} else {
			text.Append( ValueResourceName( type, value ) );
		}
	}

	int MaskForText( const char * components ) {
		int mask = 0;
		if ( components == nullptr ) return 0xF;
		for ( const char * c = components; *c != '\0'; ++c ) {
			if ( *c == 'x' || *c == 'r' ) mask |= 1;
			else if ( *c == 'y' || *c == 'g' ) mask |= 2;
			else if ( *c == 'z' || *c == 'b' ) mask |= 4;
			else if ( *c == 'w' || *c == 'a' ) mask |= 8;
		}
		return mask != 0 ? mask : 0xF;
	}

	int SwizzleComponent( const char component ) {
		if ( component == 'x' || component == 'r' ) return 0;
		if ( component == 'y' || component == 'g' ) return 1;
		if ( component == 'z' || component == 'b' ) return 2;
		if ( component == 'w' || component == 'a' ) return 3;
		return 0;
	}

	int OperatorPriority( const char * op ) {
		if ( idStr::Cmp( op, "||" ) == 0 ) return 1;
		if ( idStr::Cmp( op, "&&" ) == 0 ) return 2;
		if ( idStr::Cmp( op, "==" ) == 0 || idStr::Cmp( op, "!=" ) == 0 ) return 3;
		if ( idStr::Cmp( op, ">" ) == 0 || idStr::Cmp( op, ">=" ) == 0
			|| idStr::Cmp( op, "<" ) == 0 || idStr::Cmp( op, "<=" ) == 0 ) return 4;
		if ( idStr::Cmp( op, "+" ) == 0 || idStr::Cmp( op, "-" ) == 0 ) return 5;
		if ( idStr::Cmp( op, "*" ) == 0 || idStr::Cmp( op, "/" ) == 0
			|| idStr::Cmp( op, "%" ) == 0 ) return 6;
		return 0;
	}

	expOpType_t OpForToken( const char * op ) {
		if ( idStr::Cmp( op, "+" ) == 0 ) return OP_TYPE_ADD;
		if ( idStr::Cmp( op, "-" ) == 0 ) return OP_TYPE_SUBTRACT;
		if ( idStr::Cmp( op, "*" ) == 0 ) return OP_TYPE_MULTIPLY;
		if ( idStr::Cmp( op, "/" ) == 0 ) return OP_TYPE_DIVIDE;
		if ( idStr::Cmp( op, "%" ) == 0 ) return OP_TYPE_MOD;
		if ( idStr::Cmp( op, ">" ) == 0 ) return OP_TYPE_GT;
		if ( idStr::Cmp( op, ">=" ) == 0 ) return OP_TYPE_GE;
		if ( idStr::Cmp( op, "<" ) == 0 ) return OP_TYPE_LT;
		if ( idStr::Cmp( op, "<=" ) == 0 ) return OP_TYPE_LE;
		if ( idStr::Cmp( op, "==" ) == 0 ) return OP_TYPE_EQ;
		if ( idStr::Cmp( op, "!=" ) == 0 ) return OP_TYPE_NE;
		if ( idStr::Cmp( op, "&&" ) == 0 ) return OP_TYPE_AND;
		return OP_TYPE_OR;
	}

	class ParmExpressionParser {
	public:
		ParmExpressionParser( idParmBlock & block_, idParser & parser_ ) :
			block( block_ ), parser( parser_ ), temporaryIndex( 0 ) {}

		const idDeclRenderParm * ParseExpression( const int minimumPriority = 1 ) {
			const idDeclRenderParm * left = ParseTerm();
			if ( left == nullptr ) return nullptr;
			for ( ;; ) {
				idToken token;
				if ( !parser.ReadToken( token ) ) break;
				const int priority = OperatorPriority( token.c_str() );
				if ( priority < minimumPriority ) {
					parser.UnreadToken( token );
					break;
				}
				const idDeclRenderParm * right = ParseExpression( priority + 1 );
				if ( right == nullptr ) return left;
				left = EmitBinary( OpForToken( token.c_str() ), left, right );
			}
			return left;
		}

	private:
		const idDeclRenderParm * Temporary() {
			char name[64];
			std::snprintf( name, sizeof( name ), "__expressionTemporary%d", temporaryIndex++ );
			idDeclRenderParm * parm = const_cast< idDeclRenderParm * >(
				idDeclRenderParm::FindByName( name, true ) );
			if ( parm != nullptr ) {
				parm->creator = PC_TEMPORARY;
				parm->parmType = PT_VECTOR;
			}
			return parm;
		}

		const idDeclRenderParm * Constant( const float value[4] ) {
			const idDeclRenderParm * dest = Temporary();
			if ( dest == nullptr ) return nullptr;
			parmValue_t constant = {};
			std::memcpy( constant.value, value, sizeof( constant.value ) );
			expOp_t op = {};
			op.type = OP_TYPE_UNMASKED_MOVE_CONSTANT;
			op.parmIndexDest = static_cast< short >( dest->parmIndex );
			op.parmIndexA = RENDERPARM_INVALID;
			op.parmIndexB = RENDERPARM_INVALID;
			block.AddOp( op, constant );
			return dest;
		}

		const idDeclRenderParm * EmitBinary( const expOpType_t type,
			const idDeclRenderParm * a, const idDeclRenderParm * b ) {
			const idDeclRenderParm * dest = Temporary();
			if ( dest == nullptr ) return a;
			expOp_t op = {};
			op.type = static_cast< unsigned short >( type | ( 0xF << 9 ) );
			op.parmIndexDest = static_cast< short >( dest->parmIndex );
			op.parmIndexA = static_cast< short >( a->parmIndex );
			op.parmIndexB = static_cast< short >( b->parmIndex );
			parmValue_t constant = {};
			block.AddOp( op, constant );
			return dest;
		}

		const idDeclRenderParm * ParseTerm() {
			idToken token;
			if ( !parser.ReadToken( token ) ) return nullptr;
			if ( idStr::Cmp( token.c_str(), "(" ) == 0 ) {
				const idDeclRenderParm * value = ParseExpression();
				parser.ExpectTokenString( ")" );
				return ParseSwizzle( value );
			}
			if ( idStr::Cmp( token.c_str(), "{" ) == 0 ) {
				parser.UnreadToken( token );
				float value[4];
				return idDeclRenderParm::ParseVectorConstant( parser, value )
					? Constant( value ) : nullptr;
			}
			bool negative = idStr::Cmp( token.c_str(), "-" ) == 0;
			if ( negative && !parser.ReadToken( token ) ) return nullptr;
			char * end = nullptr;
			const float scalar = std::strtof( token.c_str(), &end );
			if ( end != token.c_str() && *end == '\0' ) {
				float value[4] = { scalar, scalar, scalar, scalar };
				if ( negative ) for ( float & component : value ) component = -component;
				return Constant( value );
			}
			if ( idStr::Icmp( token.c_str(), "dot3" ) == 0
				|| idStr::Icmp( token.c_str(), "dot4" ) == 0 ) {
				const bool dot4 = idStr::Icmp( token.c_str(), "dot4" ) == 0;
				parser.ExpectTokenString( "(" );
				const idDeclRenderParm * a = ParseExpression();
				parser.ExpectTokenString( "," );
				const idDeclRenderParm * b = ParseExpression();
				parser.ExpectTokenString( ")" );
				return EmitBinary( dot4 ? OP_TYPE_DOT4 : OP_TYPE_DOT3, a, b );
			}
			const idDeclRenderParm * parm = idDeclRenderParm::FindByName( token.c_str(), true );
			return ParseSwizzle( parm );
		}

		const idDeclRenderParm * ParseSwizzle( const idDeclRenderParm * source ) {
			if ( source == nullptr ) return nullptr;
			idToken dot;
			if ( !parser.ReadToken( dot ) ) return source;
			if ( idStr::Cmp( dot.c_str(), "." ) != 0 ) {
				parser.UnreadToken( dot );
				return source;
			}
			idToken swizzleText;
			if ( !parser.ReadToken( swizzleText ) ) return source;
			const idDeclRenderParm * dest = Temporary();
			if ( dest == nullptr ) return source;
			parmValue_t constant = {};
			const int length = (std::min)( swizzleText.Length(), 4 );
			for ( int i = 0; i < 4; ++i ) {
				constant.swizzle[i] = SwizzleComponent(
					swizzleText.c_str()[i < length ? i : length - 1] );
			}
			expOp_t op = {};
			op.type = static_cast< unsigned short >( OP_TYPE_SWIZZLE | ( 0xF << 9 ) );
			op.parmIndexDest = static_cast< short >( dest->parmIndex );
			op.parmIndexA = static_cast< short >( source->parmIndex );
			op.parmIndexB = RENDERPARM_INVALID;
			block.AddOp( op, constant );
			return dest;
		}

		idParmBlock & block;
		idParser & parser;
		int temporaryIndex;
	};
}

idParmBlock::idParmBlock( const threadId_t ownerThread ) :
	ops( 16 ), constants( 16 ), thread( ownerThread ), usingTempOps( false ) {}

idParmBlock::idParmBlock( const idParmBlock & other ) : idParmBlock( other.thread ) {
	CopyFrom( other );
}

idParmBlock::~idParmBlock() { Clear(); }

idParmBlock & idParmBlock::operator=( const idParmBlock & other ) {
	if ( this != &other ) CopyFrom( other );
	return *this;
}

void idParmBlock::Clear() {
	ops.Clear();
	constants.Clear();
	usingTempOps = false;
}

void idParmBlock::CopyFrom( const idParmBlock & other ) {
	ops = other.ops;
	constants = other.constants;
	thread = other.thread;
	usingTempOps = other.usingTempOps;
}

void idParmBlock::Append( const idParmBlock & other ) {
	for ( int index = 0; index < other.ops.Num(); ++index ) {
		AddOp( other.ops[index], other.constants[index] );
	}
	usingTempOps = usingTempOps || other.usingTempOps;
}

void idParmBlock::AddOp( const expOp_t & op, const parmValue_t & constant ) {
	if ( ops.Append( op ) >= 0 ) {
		if ( constants.Append( constant ) < 0 ) ops.RemoveIndex( ops.Num() - 1 );
	}
}

void idParmBlock::ClearParm( const idDeclRenderParm * parm ) {
	if ( parm == nullptr ) return;
	for ( int index = ops.Num() - 1; index >= 0; --index ) {
		if ( ops[index].parmIndexDest == parm->parmIndex ) {
			ops.RemoveIndex( index );
			constants.RemoveIndex( index );
		}
	}
}

void idParmBlock::SetParm( const idDeclRenderParm * parm,
	const parmValue_t & value ) {
	if ( parm == nullptr || parm->parmIndex == RENDERPARM_INVALID ) return;
	expOp_t op = {};
	op.type = OP_TYPE_UNMASKED_MOVE_CONSTANT;
	op.parmIndexDest = static_cast< short >( parm->parmIndex );
	op.parmIndexA = RENDERPARM_INVALID;
	op.parmIndexB = RENDERPARM_INVALID;
	AddOp( op, value );
}

void idParmBlock::SetImage( const idDeclRenderParm * parm,
	const idImage * image ) {
	parmValue_t value = {};
	value.image = image;
	SetParm( parm, value );
}

bool idParmBlock::SetsRenderParm( const idDeclRenderParm * parm ) const {
	if ( parm == nullptr ) return false;
	for ( int index = 0; index < ops.Num(); ++index ) {
		if ( ops[index].parmIndexDest == parm->parmIndex ) return true;
	}
	return false;
}

void idParmBlock::ApplyOp( const expOp_t & op, const parmValue_t & constant,
	const parmValue_t & parmA, const parmValue_t & parmB, parmValue_t & result ) {
	parmValue_t computed = {};
	const expOpType_t type = op.OpType();
	if ( type == OP_TYPE_UNMASKED_MOVE_CONSTANT || type == OP_TYPE_MOVE_CONSTANT ) {
		computed = constant;
	} else if ( type == OP_TYPE_UNMASKED_MOVE || type == OP_TYPE_MOVE ) {
		computed = parmA;
	} else if ( type == OP_TYPE_SWIZZLE ) {
		for ( int component = 0; component < 4; ++component ) {
			computed.value[component] = parmA.value[constant.swizzle[component] & 3];
		}
	} else if ( type == OP_TYPE_DOT3 || type == OP_TYPE_DOT4 ) {
		const int count = type == OP_TYPE_DOT3 ? 3 : 4;
		float dot = 0.0f;
		for ( int component = 0; component < count; ++component ) {
			dot += parmA.value[component] * parmB.value[component];
		}
		for ( float & component : computed.value ) component = dot;
	} else if ( type == OP_TYPE_TABLE ) {
		computed = parmB;
	} else {
		for ( int component = 0; component < 4; ++component ) {
			const float a = parmA.value[component];
			const float b = parmB.value[component];
			switch ( type ) {
				case OP_TYPE_ADD: computed.value[component] = a + b; break;
				case OP_TYPE_SUBTRACT: computed.value[component] = a - b; break;
				case OP_TYPE_MULTIPLY: computed.value[component] = a * b; break;
				case OP_TYPE_DIVIDE: computed.value[component] = b != 0.0f ? a / b : 0.0f; break;
				case OP_TYPE_MOD: computed.value[component] = b != 0.0f ? std::fmod( a, b ) : 0.0f; break;
				case OP_TYPE_GT: computed.value[component] = a > b ? 1.0f : 0.0f; break;
				case OP_TYPE_GE: computed.value[component] = a >= b ? 1.0f : 0.0f; break;
				case OP_TYPE_LT: computed.value[component] = a < b ? 1.0f : 0.0f; break;
				case OP_TYPE_LE: computed.value[component] = a <= b ? 1.0f : 0.0f; break;
				case OP_TYPE_EQ: computed.value[component] = a == b ? 1.0f : 0.0f; break;
				case OP_TYPE_NE: computed.value[component] = a != b ? 1.0f : 0.0f; break;
				case OP_TYPE_AND: computed.value[component] = a != 0.0f && b != 0.0f ? 1.0f : 0.0f; break;
				case OP_TYPE_OR: computed.value[component] = a != 0.0f || b != 0.0f ? 1.0f : 0.0f; break;
				default: computed.value[component] = 0.0f; break;
			}
		}
	}
	if ( type == OP_TYPE_UNMASKED_MOVE_CONSTANT || type == OP_TYPE_UNMASKED_MOVE ) {
		result = computed;
		return;
	}
	const unsigned int mask = op.ComponentMask() != 0 ? op.ComponentMask() : 0xF;
	for ( int component = 0; component < 4; ++component ) {
		if ( ( mask & ( 1u << component ) ) != 0 ) result.value[component] = computed.value[component];
	}
}

void idParmBlock::GetRenderParmFromOps_r( const int numOps,
	const int parmIndex, parmValue_t & value, const int depth ) const {
	std::memset( &value, 0, sizeof( value ) );
	const idDeclRenderParm * const parm = idDeclRenderParm::FindByIndex( parmIndex );
	if ( parm != nullptr ) value = parm->declaredValue;
	if ( depth > 128 ) return;
	const int end = (std::min)( numOps, ops.Num() );
	for ( int index = 0; index < end; ++index ) {
		const expOp_t & op = ops[index];
		if ( op.parmIndexDest != parmIndex ) continue;
		parmValue_t a = {};
		parmValue_t b = {};
		if ( op.parmIndexA != RENDERPARM_INVALID ) {
			GetRenderParmFromOps_r( index, op.parmIndexA, a, depth + 1 );
		}
		if ( op.parmIndexB != RENDERPARM_INVALID ) {
			GetRenderParmFromOps_r( index, op.parmIndexB, b, depth + 1 );
		}
		ApplyOp( op, constants[index], a, b, value );
	}
}

parmValue_t idParmBlock::GetValue( const idDeclRenderParm * parm ) const {
	parmValue_t value = {};
	if ( parm != nullptr ) GetRenderParmFromOps_r( ops.Num(), parm->parmIndex, value );
	return value;
}

float idParmBlock::GetFloat( const idDeclRenderParm * parm ) const {
	return GetValue( parm ).value[0];
}
int idParmBlock::GetInteger( const idDeclRenderParm * parm ) const {
	return static_cast< int >( GetFloat( parm ) );
}
idVec4 idParmBlock::GetVector( const idDeclRenderParm * parm ) const {
	const parmValue_t value = GetValue( parm );
	return idVec4( value.value[0], value.value[1], value.value[2], value.value[3] );
}
const idImage * idParmBlock::GetImage( const idDeclRenderParm * parm ) const {
	return parm != nullptr && IsTextureParm( parm->parmType ) ? GetValue( parm ).image : nullptr;
}
const idDeclRenderProg * idParmBlock::GetProgram( const idDeclRenderParm * parm ) const {
	return parm != nullptr && parm->parmType == PT_PROGRAM ? GetValue( parm ).program : nullptr;
}
const char * idParmBlock::GetString( const idDeclRenderParm * parm ) const {
	return parm != nullptr && parm->parmType == PT_STRING ? GetValue( parm ).string : nullptr;
}

void idParmBlock::Parse( idParser & parser ) {
	Clear();
	parser.ExpectTokenString( "{" );
	ParmExpressionParser expressions( *this, parser );
	idToken token;
	while ( parser.ReadToken( token ) ) {
		if ( idStr::Cmp( token.c_str(), "}" ) == 0 ) break;
		const idDeclRenderParm * const dest = idDeclRenderParm::FindByName( token.c_str(), true );
		if ( dest == nullptr ) {
			parser.Warning( "Unknown render parm '%s'", token.c_str() );
			parser.SkipRestOfLine();
			continue;
		}
		int mask = 0xF;
		if ( parser.CheckTokenString( "." ) ) {
			idToken components;
			if ( parser.ReadToken( components ) ) mask = MaskForText( components.c_str() );
		}
		if ( !parser.ExpectTokenString( "=" ) ) break;
		const idDeclRenderParm * const source = expressions.ParseExpression();
		if ( source == nullptr ) break;
		expOp_t op = {};
		op.type = static_cast< unsigned short >( OP_TYPE_MOVE | ( mask << 9 ) );
		op.parmIndexDest = static_cast< short >( dest->parmIndex );
		op.parmIndexA = static_cast< short >( source->parmIndex );
		op.parmIndexB = RENDERPARM_INVALID;
		parmValue_t constant = {};
		AddOp( op, constant );
		parser.CheckTokenString( ";" );
	}
	usingTempOps = true;
	RemoveRedundantOperations();
}

idStr * idParmBlock::WriteString() const {
	idStr * text = new idStr( "{\n" );
	for ( int index = 0; index < ops.Num(); ++index ) {
		const expOp_t & op = ops[index];
		const idDeclRenderParm * const dest = idDeclRenderParm::FindByIndex( op.parmIndexDest );
		const idDeclRenderParm * const a = idDeclRenderParm::FindByIndex( op.parmIndexA );
		const idDeclRenderParm * const b = idDeclRenderParm::FindByIndex( op.parmIndexB );
		if ( dest == nullptr ) continue;
		text->Append( "\t" );
		text->Append( dest->GetName() );
		const unsigned int mask = op.ComponentMask();
		if ( mask != 0 && mask != 0xF ) {
			text->Append( "." );
			if ( mask & 1 ) text->Append( "x" );
			if ( mask & 2 ) text->Append( "y" );
			if ( mask & 4 ) text->Append( "z" );
			if ( mask & 8 ) text->Append( "w" );
		}
		text->Append( " = " );
		const expOpType_t type = op.OpType();
		if ( type == OP_TYPE_UNMASKED_MOVE_CONSTANT || type == OP_TYPE_MOVE_CONSTANT ) {
			AppendValueText( *text, dest->parmType, constants[index] );
		} else if ( type == OP_TYPE_UNMASKED_MOVE || type == OP_TYPE_MOVE ) {
			text->Append( a != nullptr ? a->GetName() : "0" );
		} else if ( type == OP_TYPE_SWIZZLE ) {
			text->Append( a != nullptr ? a->GetName() : "0" );
			text->Append( "." );
			static const char componentNames[] = "xyzw";
			for ( int component = 0; component < 4; ++component ) {
				text->Append( componentNames[constants[index].swizzle[component] & 3] );
			}
		} else if ( type == OP_TYPE_DOT3 || type == OP_TYPE_DOT4 ) {
			text->Append( type == OP_TYPE_DOT3 ? "dot3( " : "dot4( " );
			text->Append( a != nullptr ? a->GetName() : "0" );
			text->Append( ", " );
			text->Append( b != nullptr ? b->GetName() : "0" );
			text->Append( " )" );
		} else {
			text->Append( a != nullptr ? a->GetName() : "0" );
			text->Append( " " );
			text->Append( opNames[type] );
			text->Append( " " );
			text->Append( b != nullptr ? b->GetName() : "0" );
		}
		text->Append( ";\n" );
	}
	text->Append( "}\n" );
	return text;
}

void idParmBlock::Print() const {
	idStr * const text = WriteString();
	std::printf( "%s", text->c_str() );
	delete text;
}

void idParmBlock::Save( idFile * file ) const {
	if ( file == nullptr ) return;
	const unsigned char temp = usingTempOps ? 1 : 0;
	file->Write( &temp, sizeof( temp ) );
	const int count = ops.Num();
	file->WriteLittle( count );
	for ( int index = 0; index < count; ++index ) {
		const expOp_t & op = ops[index];
		const unsigned char type = static_cast< unsigned char >( op.OpType() );
		const unsigned char mask = static_cast< unsigned char >( op.ComponentMask() );
		file->Write( &type, 1 );
		file->Write( &mask, 1 );
		const idDeclRenderParm * const dest = idDeclRenderParm::FindByIndex( op.parmIndexDest );
		file->WriteString( dest != nullptr ? dest->GetName() : "" );
		if ( type == OP_TYPE_UNMASKED_MOVE_CONSTANT || type == OP_TYPE_MOVE_CONSTANT ) {
			if ( dest != nullptr && dest->parmType == PT_VECTOR ) {
				file->Write( &constants[index], sizeof( parmValue_t ) );
			} else {
				file->WriteString( dest != nullptr
					? ValueResourceName( dest->parmType, constants[index] ) : "" );
			}
		} else {
			const idDeclRenderParm * const a = idDeclRenderParm::FindByIndex( op.parmIndexA );
			const idDeclRenderParm * const b = idDeclRenderParm::FindByIndex( op.parmIndexB );
			file->WriteString( a != nullptr ? a->GetName() : "" );
			if ( type == OP_TYPE_SWIZZLE ) file->Write( &constants[index], sizeof( parmValue_t ) );
			file->WriteString( b != nullptr ? b->GetName() : "" );
		}
	}
}

bool idParmBlock::Load( idFile * file ) {
	if ( file == nullptr ) return false;
	Clear();
	unsigned char temp = 0;
	int count = 0;
	if ( file->Read( &temp, 1 ) != 1 || file->ReadLittle( count ) != sizeof( count )
		|| count < 0 || count > 65536 ) return false;
	usingTempOps = temp != 0;
	for ( int index = 0; index < count; ++index ) {
		unsigned char type = 0;
		unsigned char mask = 0;
		idStr name;
		if ( file->Read( &type, 1 ) != 1 || file->Read( &mask, 1 ) != 1
			|| file->ReadString( name ) == 0 ) return false;
		const idDeclRenderParm * const dest = idDeclRenderParm::FindByName( name.c_str(), true );
		if ( dest == nullptr ) return false;
		expOp_t op = {};
		op.type = static_cast< unsigned short >( ( type & 0x1F ) | ( ( mask & 0xF ) << 9 ) );
		op.parmIndexDest = static_cast< short >( dest->parmIndex );
		op.parmIndexA = RENDERPARM_INVALID;
		op.parmIndexB = RENDERPARM_INVALID;
		parmValue_t constant = {};
		if ( type == OP_TYPE_UNMASKED_MOVE_CONSTANT || type == OP_TYPE_MOVE_CONSTANT ) {
			if ( dest->parmType == PT_VECTOR ) {
				if ( file->Read( &constant, sizeof( constant ) ) != sizeof( constant ) ) return false;
			} else {
				idStr valueName;
				if ( file->ReadString( valueName ) == 0 ) return false;
				dest->ParseStringToValue( valueName.c_str(), constant );
			}
		} else {
			idStr aName;
			idStr bName;
			if ( file->ReadString( aName ) == 0 ) return false;
			const idDeclRenderParm * const a = idDeclRenderParm::FindByName( aName.c_str(), true );
			op.parmIndexA = a != nullptr ? static_cast< short >( a->parmIndex ) : RENDERPARM_INVALID;
			if ( type == OP_TYPE_SWIZZLE
				&& file->Read( &constant, sizeof( constant ) ) != sizeof( constant ) ) return false;
			if ( file->ReadString( bName ) == 0 ) return false;
			const idDeclRenderParm * const b = idDeclRenderParm::FindByName( bName.c_str(), false );
			op.parmIndexB = b != nullptr ? static_cast< short >( b->parmIndex ) : RENDERPARM_INVALID;
		}
		AddOp( op, constant );
	}
	return true;
}

void idParmBlock::RemoveRedundantOperations() {
	// An earlier full write is dead when no operation between it and the next
	// full write reads the destination.  Masked writes deliberately retain the
	// previous value of components outside their mask and are never folded here.
	for ( int index = 0; index < ops.Num(); ++index ) {
		const int dest = ops[index].parmIndexDest;
		if ( dest == RENDERPARM_INVALID ) continue;
		bool read = false;
		for ( int later = index + 1; later < ops.Num(); ++later ) {
			if ( ops[later].parmIndexA == dest || ops[later].parmIndexB == dest ) {
				read = true;
				break;
			}
			if ( ops[later].parmIndexDest == dest
				&& ( ops[later].OpType() == OP_TYPE_UNMASKED_MOVE
					|| ops[later].OpType() == OP_TYPE_UNMASKED_MOVE_CONSTANT
					|| ops[later].ComponentMask() == 0xF ) ) {
				if ( !read ) {
					ops.RemoveIndex( index );
					constants.RemoveIndex( index );
					--index;
				}
				break;
			}
		}
	}
}
