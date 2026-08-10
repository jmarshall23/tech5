#pragma once

#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

class idDeclRenderParm;
class idDeclRenderProg;
class idFile;
class idImage;
class idParser;

static const short RENDERPARM_INVALID = 2047;

enum threadId_t : int {
	THREAD_INVALID = 0,
	THREAD_MAIN = 1,
	THREAD_RENDERER = 2
};

// Low five bits of expOp_t::type.  Bits 9..12 are the destination component
// mask; these values and packing are recovered from the retail executable.
enum expOpType_t : int {
	OP_TYPE_UNMASKED_MOVE_CONSTANT = 0,
	OP_TYPE_UNMASKED_MOVE = 1,
	OP_TYPE_MOVE_CONSTANT = 2,
	OP_TYPE_MOVE = 3,
	OP_TYPE_SWIZZLE = 4,
	OP_TYPE_ADD = 5,
	OP_TYPE_SUBTRACT = 6,
	OP_TYPE_MULTIPLY = 7,
	OP_TYPE_DOT3 = 8,
	OP_TYPE_DOT4 = 9,
	OP_TYPE_DIVIDE = 10,
	OP_TYPE_MOD = 11,
	OP_TYPE_GT = 12,
	OP_TYPE_GE = 13,
	OP_TYPE_LT = 14,
	OP_TYPE_LE = 15,
	OP_TYPE_EQ = 16,
	OP_TYPE_NE = 17,
	OP_TYPE_AND = 18,
	OP_TYPE_OR = 19,
	OP_TYPE_TABLE = 20
};

struct expOp_t {
	unsigned short type;
	short parmIndexDest;
	short parmIndexA;
	short parmIndexB;

	expOpType_t OpType() const {
		return static_cast< expOpType_t >( type & 0x1F );
	}
	unsigned int ComponentMask() const { return ( type >> 9 ) & 0xF; }
	const idDeclRenderParm * GetDest() const;
	const idDeclRenderParm * GetA() const;
	const idDeclRenderParm * GetB() const;
};

union alignas( 4 ) parmValue_t {
	float value[4];
	const idImage * image;
	const idDeclRenderProg * program;
	const char * string;
	int swizzle[4];
};

class alignas( 4 ) idParmBlock {
public:
	explicit idParmBlock( threadId_t ownerThread = THREAD_MAIN );
	idParmBlock( const idParmBlock & other );
	~idParmBlock();
	idParmBlock & operator=( const idParmBlock & other );

	void Clear();
	void CopyFrom( const idParmBlock & other );
	void Append( const idParmBlock & other );
	void AddOp( const expOp_t & op, const parmValue_t & constant );
	void ClearParm( const idDeclRenderParm * parm );
	void SetParm( const idDeclRenderParm * parm, const parmValue_t & value );
	void SetImage( const idDeclRenderParm * parm, const idImage * image );
	bool SetsRenderParm( const idDeclRenderParm * parm ) const;

	float GetFloat( const idDeclRenderParm * parm ) const;
	int GetInteger( const idDeclRenderParm * parm ) const;
	idVec4 GetVector( const idDeclRenderParm * parm ) const;
	const idImage * GetImage( const idDeclRenderParm * parm ) const;
	const idDeclRenderProg * GetProgram( const idDeclRenderParm * parm ) const;
	const char * GetString( const idDeclRenderParm * parm ) const;
	parmValue_t GetValue( const idDeclRenderParm * parm ) const;

	void Parse( idParser & parser );
	idStr * WriteString() const;
	void Print() const;
	void Save( idFile * file ) const;
	bool Load( idFile * file );
	void RemoveRedundantOperations();

	idList< expOp_t, 56 > ops;
	idList< parmValue_t, 56 > constants;
	threadId_t thread;
	bool usingTempOps;

private:
	void GetRenderParmFromOps_r( int numOps, int parmIndex,
		parmValue_t & value, int depth = 0 ) const;
	static void ApplyOp( const expOp_t & op, const parmValue_t & constant,
		const parmValue_t & parmA, const parmValue_t & parmB,
		parmValue_t & result );
};

template< int capacity >
class idStaticParmBlock : public idParmBlock {
public:
	idStaticParmBlock() : idParmBlock( THREAD_MAIN ) {
		ops.PreAllocate( capacity );
		constants.PreAllocate( capacity );
	}

	expOp_t staticOps[capacity];
	alignas( 16 ) parmValue_t staticConstants[capacity];
};

static_assert( sizeof( expOp_t ) == 8, "Recovered parm operation ABI changed" );
static_assert( sizeof( parmValue_t ) == 16, "Recovered parm value ABI changed" );
#if defined( _WIN32 ) && !defined( _WIN64 )
static_assert( sizeof( idParmBlock ) == 40,
	"Recovered parameter-block ABI changed" );
#endif
