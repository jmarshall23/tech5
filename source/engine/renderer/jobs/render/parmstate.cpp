#include "parmstate.h"

#include "../../declrenderparm.h"
#include "../../declrenderprog.h"
#include "../approximatelighting/approximatelighting.h"
#include "decls/decltable.h"
#include "idlib/lookuptable.h"
#include "idlib/geometry/rendermatrix.h"
#include "models/rendermodel.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

idParmState renderThreadParmStateObject;
idParmState * renderThreadParmState = &renderThreadParmStateObject;

const idDeclRenderParm * expOp_t::GetDest() const {
	return renderThreadParmState != nullptr && parmIndexDest >= 0 &&
		parmIndexDest < RENDERPARM_INVALID
		? renderThreadParmState->parmDecl[parmIndexDest] : nullptr;
}
const idDeclRenderParm * expOp_t::GetA() const {
	return renderThreadParmState != nullptr && parmIndexA >= 0 &&
		parmIndexA < RENDERPARM_INVALID
		? renderThreadParmState->parmDecl[parmIndexA] : nullptr;
}
const idDeclRenderParm * expOp_t::GetB() const {
	return renderThreadParmState != nullptr && parmIndexB >= 0 &&
		parmIndexB < RENDERPARM_INVALID
		? renderThreadParmState->parmDecl[parmIndexB] : nullptr;
}

idParmState::idParmState() { Init(); }

void idParmState::CopyParmUnaligned( void * destination,
		const void * source ) {
	std::memcpy( destination, source, sizeof( parmValue_t ) );
}

int idParmState::ParmIndex( const char * name ) {
	const idDeclRenderParm * const parm = idDeclRenderParm::FindByName( name, true );
	if ( parm == nullptr ) return RENDERPARM_INVALID;
	AllocParmState( parm );
	return parm->parmIndex;
}

void idParmState::Init() {
	renderParmVersion = vertexParmVersion = fragmentParmVersion =
		textureParmVersion = 1;
	currentMVPHasNegativeDeterminant = false;
	std::memset( values, 0, sizeof( values ) );
	std::memset( onParmBlockStack, 0, sizeof( onParmBlockStack ) );
	std::memset( &parmStack, 0, sizeof( parmStack ) );
	std::memset( parmDecl, 0, sizeof( parmDecl ) );
	std::memset( parmUsageMask, 0, sizeof( parmUsageMask ) );
	std::memset( globalTables, 0, sizeof( globalTables ) );
	std::memset( globalLookupTables, 0, sizeof( globalLookupTables ) );
	numGlobalTables = 0;
	for ( int index = 0; index < RENDERPARM_INVALID; ++index ) {
		const idDeclRenderParm * const parm = idDeclRenderParm::FindByIndex( index );
		if ( parm != nullptr ) AllocParmState( parm );
	}
	parmIndexPositionToViewTexture = ParmIndex( "positionToViewTexture" );
	parmIndexRenderPositionToViewTexture = ParmIndex( "renderPositionToViewTexture" );
	parmIndexPositionToFeedback = ParmIndex( "positionToFeedback" );
	parmIndexModelMatrixX = ParmIndex( "modelMatrixX" );
	parmIndexModelMatrixY = ParmIndex( "modelMatrixY" );
	parmIndexModelMatrixZ = ParmIndex( "modelMatrixZ" );
	parmIndexModelMatrixW = ParmIndex( "modelMatrixW" );
	parmIndexInverseModelMatrixX = ParmIndex( "inverseModelMatrixX" );
	parmIndexInverseModelMatrixY = ParmIndex( "inverseModelMatrixY" );
	parmIndexInverseModelMatrixZ = ParmIndex( "inverseModelMatrixZ" );
	parmIndexInverseModelMatrixW = ParmIndex( "inverseModelMatrixW" );
	parmIndexMVPMatrixX = ParmIndex( "mvpMatrixX" );
	parmIndexMVPMatrixY = ParmIndex( "mvpMatrixY" );
	parmIndexMVPMatrixZ = ParmIndex( "mvpMatrixZ" );
	parmIndexMVPMatrixW = ParmIndex( "mvpMatrixW" );
	parmIndexPrimeLightDir = ParmIndex( "primeLightDir" );
	parmIndexPrimeLightColor = ParmIndex( "primeLightColor" );
	for ( int index = 0; index < 6; ++index ) {
		char name[32];
		std::snprintf( name, sizeof( name ), "channelLight%d", index );
		parmIndexChannelLight[index] = ParmIndex( name );
	}
	parmIndexLightingModel = ParmIndex( "lightingModel" );
	parmIndexHighlightColor = ParmIndex( "highlightColor" );
	parmIndexVertexStScaleBias = ParmIndex( "vertexStScaleBias" );
	parmIndexVertexXYZScale = ParmIndex( "vertexXYZScale" );
	parmIndexVertexXYZBias = ParmIndex( "vertexXYZBias" );
	parmIndexIf = ParmIndex( "if" );
	parmIndexPolygonOffset = ParmIndex( "polygonOffset" );
	parmIndexVertexMorphScale = ParmIndex( "vertexMorphScale" );
}

int idParmState::AllocParmState( const idDeclRenderParm * parm ) {
	if ( parm == nullptr || parm->parmIndex < 0 ||
			parm->parmIndex >= RENDERPARM_INVALID ) return RENDERPARM_INVALID;
	const int index = parm->parmIndex;
	parmDecl[index] = parm;
	values[index] = parm->declaredValue;
	return index;
}

void idParmState::FreeParmState( const idDeclRenderParm * parm ) {
	if ( parm == nullptr || parm->parmIndex < 0 ||
			parm->parmIndex >= RENDERPARM_INVALID ) return;
	parmDecl[parm->parmIndex] = nullptr;
	std::memset( &values[parm->parmIndex], 0, sizeof( parmValue_t ) );
	parmUsageMask[parm->parmIndex] = 0;
}

int idParmState::GetTableIndex( const idDeclTable * table ) {
	if ( table == nullptr ) return -1;
	for ( int index = 0; index < numGlobalTables; ++index )
		if ( globalTables[index] == table ) return index;
	if ( numGlobalTables >= 128 ) return -1;
	const int index = numGlobalTables++;
	globalTables[index] = table;
	globalLookupTables[index] = table->table;
	return index;
}

const idDeclTable * idParmState::GetTable( const int tableIndex ) const {
	return tableIndex >= 0 && tableIndex < numGlobalTables
		? globalTables[tableIndex] : nullptr;
}

void idParmState::RemoveTable( const idDeclTable * table ) {
	for ( int index = 0; index < numGlobalTables; ++index ) {
		if ( globalTables[index] != table ) continue;
		for ( int move = index; move + 1 < numGlobalTables; ++move ) {
			globalTables[move] = globalTables[move + 1];
			globalLookupTables[move] = globalLookupTables[move + 1];
		}
		--numGlobalTables;
		globalTables[numGlobalTables] = nullptr;
		globalLookupTables[numGlobalTables] = nullptr;
		return;
	}
}

const char * idParmState::GetParmNameForIndex( const int parmIndex ) const {
	const idDeclRenderParm * const parm = GetRenderParmForIndex( parmIndex );
	return parm != nullptr ? parm->GetName() : "<invalid render parm>";
}

const idDeclRenderParm * idParmState::GetRenderParmForIndex(
		const int parmIndex ) const {
	return parmIndex >= 0 && parmIndex < RENDERPARM_INVALID
		? parmDecl[parmIndex] : nullptr;
}

void idParmState::UpdateParmUsageMasks( const idDeclRenderProg * program ) {
	if ( program == nullptr ) return;
	for ( int index = 0; index < program->numVertexParms; ++index )
		if ( program->vertexParms[index] >= 0 &&
			program->vertexParms[index] < RENDERPARM_INVALID )
			parmUsageMask[program->vertexParms[index]] |= 1;
	for ( int index = 0; index < program->numFragmentParms; ++index )
		if ( program->fragmentParms[index] >= 0 &&
			program->fragmentParms[index] < RENDERPARM_INVALID )
			parmUsageMask[program->fragmentParms[index]] |= 2;
	for ( int index = 0; index < program->numTextureParms; ++index )
		if ( program->textureParms[index] >= 0 &&
			program->textureParms[index] < RENDERPARM_INVALID )
			parmUsageMask[program->textureParms[index]] |= 4;
}

void idParmState::PrintSharedRenderParms() const {
	for ( int index = 0; index < RENDERPARM_INVALID; ++index ) {
		if ( ( parmUsageMask[index] & 3 ) == 3 && parmDecl[index] != nullptr )
			std::printf( "%4d %s\n", index, parmDecl[index]->GetName() );
	}
}

void idParmState::BumpVersion( const int parmIndex ) {
	++renderParmVersion;
	if ( parmIndex < 0 || parmIndex >= RENDERPARM_INVALID ) return;
	const unsigned char usage = parmUsageMask[parmIndex];
	if ( ( usage & 1 ) != 0 ) ++vertexParmVersion;
	if ( ( usage & 2 ) != 0 ) ++fragmentParmVersion;
	if ( ( usage & 4 ) != 0 ) ++textureParmVersion;
}

void idParmState::ApplyOp( const expOp_t & op, const parmValue_t & constant,
		const parmValue_t & parmA, const parmValue_t & parmB,
		parmValue_t & result ) const {
	parmValue_t computed = {};
	const expOpType_t type = op.OpType();
	if ( type == OP_TYPE_UNMASKED_MOVE_CONSTANT ||
			type == OP_TYPE_MOVE_CONSTANT ) computed = constant;
	else if ( type == OP_TYPE_UNMASKED_MOVE || type == OP_TYPE_MOVE )
		computed = parmA;
	else if ( type == OP_TYPE_SWIZZLE ) {
		for ( int component = 0; component < 4; ++component )
			computed.value[component] = parmA.value[constant.swizzle[component] & 3];
	} else if ( type == OP_TYPE_DOT3 || type == OP_TYPE_DOT4 ) {
		float dot = 0.0f;
		const int count = type == OP_TYPE_DOT3 ? 3 : 4;
		for ( int component = 0; component < count; ++component )
			dot += parmA.value[component] * parmB.value[component];
		for ( float & component : computed.value ) component = dot;
	} else if ( type == OP_TYPE_TABLE ) {
		const int tableIndex = op.parmIndexA;
		const idLookupTable * const table = tableIndex >= 0 &&
			tableIndex < numGlobalTables ? globalLookupTables[tableIndex] : nullptr;
		const float value = table != nullptr
			? table->TableLookup( parmB.value[0], constant.value[0] != 0.0f )
			: 0.0f;
		for ( float & component : computed.value ) component = value;
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
				default: break;
			}
		}
	}
	if ( type == OP_TYPE_UNMASKED_MOVE_CONSTANT ||
			type == OP_TYPE_UNMASKED_MOVE ) { result = computed; return; }
	const unsigned int mask = op.ComponentMask() != 0 ? op.ComponentMask() : 0xF;
	for ( int component = 0; component < 4; ++component )
		if ( ( mask & ( 1u << component ) ) != 0 )
			result.value[component] = computed.value[component];
}

void idParmState::EvaluateParmBlock( const idParmBlock & localParmBlock,
		const idParmBlock & parmBlock ) {
	if ( parmStack.currentParmBlockLevel >= 32 ||
		parmStack.currentOpLevel + localParmBlock.ops.Num() > 1024 ) return;
	const unsigned int level = parmStack.currentParmBlockLevel;
	parmStack.parmBlockStack[level].lastOpLevel = parmStack.currentOpLevel;
	parmStack.parmBlockStack[level].parmBlock = &parmBlock;
	const unsigned int levelBit = 1u << level;
	for ( int index = 0; index < localParmBlock.ops.Num(); ++index ) {
		const expOp_t & op = localParmBlock.ops[index];
		if ( op.parmIndexDest < 0 || op.parmIndexDest >= RENDERPARM_INVALID )
			continue;
		parmStack.opStack[parmStack.currentOpLevel++] = values[op.parmIndexDest];
		const parmValue_t zero = {};
		const parmValue_t & a = op.parmIndexA >= 0 &&
			op.parmIndexA < RENDERPARM_INVALID ? values[op.parmIndexA] : zero;
		const parmValue_t & b = op.parmIndexB >= 0 &&
			op.parmIndexB < RENDERPARM_INVALID ? values[op.parmIndexB] : zero;
		const parmValue_t & constant = index < localParmBlock.constants.Num()
			? localParmBlock.constants[index] : zero;
		ApplyOp( op, constant, a, b, values[op.parmIndexDest] );
		onParmBlockStack[op.parmIndexDest] |= levelBit;
		if ( op.parmIndexA >= 0 && op.parmIndexA < RENDERPARM_INVALID )
			onParmBlockStack[op.parmIndexA] |= levelBit;
		if ( op.parmIndexB >= 0 && op.parmIndexB < RENDERPARM_INVALID )
			onParmBlockStack[op.parmIndexB] |= levelBit;
		BumpVersion( op.parmIndexDest );
	}
	++parmStack.currentParmBlockLevel;
}

void idParmState::RollbackParmBlock( const idParmBlock & localParmBlock,
		const idParmBlock & parmBlock ) {
	if ( parmStack.currentParmBlockLevel == 0 ) return;
	const unsigned int level = --parmStack.currentParmBlockLevel;
	if ( parmStack.parmBlockStack[level].parmBlock != &parmBlock ) {
		++parmStack.currentParmBlockLevel;
		return;
	}
	const unsigned int levelBit = ~( 1u << level );
	for ( int index = localParmBlock.ops.Num() - 1; index >= 0; --index ) {
		const expOp_t & op = localParmBlock.ops[index];
		if ( op.parmIndexDest < 0 || op.parmIndexDest >= RENDERPARM_INVALID ||
			parmStack.currentOpLevel == 0 ) continue;
		values[op.parmIndexDest] = parmStack.opStack[--parmStack.currentOpLevel];
		onParmBlockStack[op.parmIndexDest] &= levelBit;
		if ( op.parmIndexA >= 0 && op.parmIndexA < RENDERPARM_INVALID )
			onParmBlockStack[op.parmIndexA] &= levelBit;
		if ( op.parmIndexB >= 0 && op.parmIndexB < RENDERPARM_INVALID )
			onParmBlockStack[op.parmIndexB] &= levelBit;
		BumpVersion( op.parmIndexDest );
	}
	parmStack.currentOpLevel = parmStack.parmBlockStack[level].lastOpLevel;
}

void idParmState::VirtualEvaluateParmBlock( const idParmBlock & localParmBlock,
		const idParmBlock & parmBlock ) {
	if ( parmStack.virtualParmBlockLevel < parmStack.currentParmBlockLevel &&
		parmStack.parmBlockStack[parmStack.virtualParmBlockLevel].parmBlock ==
			&parmBlock ) {
		++parmStack.virtualParmBlockLevel;
		return;
	}
	RollbackVirtualStack( false );
	EvaluateParmBlock( localParmBlock, parmBlock );
	parmStack.virtualParmBlockLevel = parmStack.currentParmBlockLevel;
}

void idParmState::VirtualRollbackParmBlock( const idParmBlock &,
		const idParmBlock & parmBlock ) {
	if ( parmStack.virtualParmBlockLevel == 0 ) return;
	const unsigned int level = parmStack.virtualParmBlockLevel - 1;
	if ( parmStack.parmBlockStack[level].parmBlock != &parmBlock ) return;
	parmStack.virtualParmBlockLevel = level;
	parmStack.virtualParmBlockStackMask |= 1u << level;
}

void idParmState::RollbackVirtualStack( bool ) {
	while ( parmStack.currentParmBlockLevel > parmStack.virtualParmBlockLevel ) {
		const unsigned int level = parmStack.currentParmBlockLevel - 1;
		const idParmBlock * const block = parmStack.parmBlockStack[level].parmBlock;
		if ( block == nullptr ) break;
		RollbackParmBlock( *block, *block );
	}
	parmStack.virtualParmBlockStackMask = 0;
}

void idParmState::RemoveFromVirtualStack( const idParmBlock & parmBlock ) {
	for ( unsigned int level = 0; level < parmStack.currentParmBlockLevel; ++level )
		if ( parmStack.parmBlockStack[level].parmBlock == &parmBlock ) {
			RollbackOpsToZero();
			return;
		}
}

void idParmState::RollbackOpsToZero() {
	RollbackVirtualStack( true );
	while ( parmStack.currentParmBlockLevel > 0 ) {
		const unsigned int level = parmStack.currentParmBlockLevel - 1;
		const idParmBlock * const block = parmStack.parmBlockStack[level].parmBlock;
		if ( block == nullptr ) break;
		RollbackParmBlock( *block, *block );
	}
	parmStack.virtualParmBlockLevel = 0;
	parmStack.virtualParmBlockStackMask = 0;
}

void idParmState::SetParmValue( const int parmIndex,
		const parmValue_t & value ) {
	if ( parmIndex < 0 || parmIndex >= RENDERPARM_INVALID ) return;
	if ( ( onParmBlockStack[parmIndex] &
			parmStack.virtualParmBlockStackMask ) != 0 ) RollbackVirtualStack( true );
	values[parmIndex] = value;
	BumpVersion( parmIndex );
}

void idParmState::SetVertexMorphScale( const idVec4 & scale ) {
	parmValue_t value = {};
	std::memcpy( value.value, &scale.x, sizeof( value.value ) );
	SetParmValue( parmIndexVertexMorphScale, value );
}

void idParmState::Set16BitVertexScaleBias(
		const idVertexScaleAndBias & scaleBias ) {
	parmValue_t value = {};
	value.value[0] = scaleBias.stScale.x;
	value.value[1] = scaleBias.stScale.y;
	value.value[2] = scaleBias.stBias.x;
	value.value[3] = scaleBias.stBias.y;
	SetParmValue( parmIndexVertexStScaleBias, value );
	value.value[0] = scaleBias.xyzScale.x;
	value.value[1] = scaleBias.xyzScale.y;
	value.value[2] = scaleBias.xyzScale.z;
	value.value[3] = 0.0f;
	SetParmValue( parmIndexVertexXYZScale, value );
	value.value[0] = scaleBias.xyzBias.x;
	value.value[1] = scaleBias.xyzBias.y;
	value.value[2] = scaleBias.xyzBias.z;
	SetParmValue( parmIndexVertexXYZBias, value );
}

namespace {
	void SetMatrixParms( idParmState & state, const idRenderMatrix & matrix,
			const int firstParm ) {
		for ( int row = 0; row < 4; ++row ) {
			parmValue_t value = {};
			std::memcpy( value.value, &matrix.m[row * 4], sizeof( value.value ) );
			state.SetParmValue( firstParm + row, value );
		}
	}
}

void idParmState::SetModelMatrix( const idRenderMatrix & matrix ) {
	SetMatrixParms( *this, matrix, parmIndexModelMatrixX );
}

void idParmState::SetInverseModelMatrix( const idRenderMatrix & matrix ) {
	SetMatrixParms( *this, matrix, parmIndexInverseModelMatrixX );
}

void idParmState::SetMVPMatrix( const idRenderMatrix & matrix ) {
	SetMatrixParms( *this, matrix, parmIndexMVPMatrixX );
	const float determinant =
		matrix.m[0] * ( matrix.m[5] * matrix.m[10] - matrix.m[6] * matrix.m[9] ) -
		matrix.m[1] * ( matrix.m[4] * matrix.m[10] - matrix.m[6] * matrix.m[8] ) +
		matrix.m[2] * ( matrix.m[4] * matrix.m[9] - matrix.m[5] * matrix.m[8] );
	currentMVPHasNegativeDeterminant = determinant < 0.0f;
}

void idParmState::SetPositionToViewTexture( int, int, const int renderWidth,
		const int renderHeight ) {
	parmValue_t value = {};
	value.value[0] = renderWidth > 0 ? 0.5f / renderWidth : 0.0f;
	value.value[1] = renderHeight > 0 ? 0.5f / renderHeight : 0.0f;
	value.value[2] = renderWidth > 0 ? 1.0f / renderWidth : 0.0f;
	value.value[3] = renderHeight > 0 ? 1.0f / renderHeight : 0.0f;
	SetParmValue( parmIndexPositionToViewTexture, value );
}

void idParmState::SetRenderPositionToViewTexture( int, int,
		const int renderWidth, const int renderHeight ) {
	parmValue_t value = {};
	value.value[0] = renderWidth > 0 ? 0.5f / renderWidth : 0.0f;
	value.value[1] = renderHeight > 0 ? 0.5f / renderHeight : 0.0f;
	value.value[2] = renderWidth > 0 ? 1.0f / renderWidth : 0.0f;
	value.value[3] = renderHeight > 0 ? 1.0f / renderHeight : 0.0f;
	SetParmValue( parmIndexRenderPositionToViewTexture, value );
}

void idParmState::SetPositionToFeedback( const int renderWidth,
		const int renderHeight, const int feedbackWidth,
		const int feedbackHeight ) {
	parmValue_t value = {};
	value.value[2] = renderWidth > 0
		? 0.5f * feedbackWidth / renderWidth : 0.0f;
	value.value[3] = renderHeight > 0
		? 0.5f * feedbackHeight / renderHeight : 0.0f;
	SetParmValue( parmIndexPositionToFeedback, value );
}

void idParmState::SetHighlightColor( const idVec4 & highlightColor ) {
	parmValue_t value = {};
	value.value[0] = highlightColor.x;
	value.value[1] = highlightColor.y;
	value.value[2] = highlightColor.z;
	value.value[3] = 1.0f;
	SetParmValue( parmIndexHighlightColor, value );
}

void idParmState::SetApproximateLighting(
		const approximateLighting_t & lighting ) {
	const idVec4 * valuesToSet[9] = { &lighting.primeLightDir,
		&lighting.primeLightColor, &lighting.channelLighting[0],
		&lighting.channelLighting[1], &lighting.channelLighting[2],
		&lighting.channelLighting[3], &lighting.channelLighting[4],
		&lighting.channelLighting[5], &lighting.lightingModel };
	const int indices[9] = { parmIndexPrimeLightDir, parmIndexPrimeLightColor,
		parmIndexChannelLight[0], parmIndexChannelLight[1],
		parmIndexChannelLight[2], parmIndexChannelLight[3],
		parmIndexChannelLight[4], parmIndexChannelLight[5],
		parmIndexLightingModel };
	for ( int index = 0; index < 9; ++index ) {
		parmValue_t value = {};
		std::memcpy( value.value, &valuesToSet[index]->x, sizeof( value.value ) );
		SetParmValue( indices[index], value );
	}
}
