#include "parmblockoptimizer.h"

#include "declrenderparm.h"
#include "parmblock.h"

idParmBlockOptimizer::idParmBlockOptimizer() : numUsedParms( 0 ) {}

int idParmBlockOptimizer::c_retainedOps = 0;
int idParmBlockOptimizer::c_removedOps = 0;

bool idParmBlockOptimizer::IsUsed( const int parmIndex ) const {
	for ( int index = 0; index < numUsedParms; ++index ) {
		if ( usedParms[index] == parmIndex ) return true;
	}
	return false;
}

void idParmBlockOptimizer::AddUsedParmIndex( const int parmIndex ) {
	if ( parmIndex == RENDERPARM_INVALID || IsUsed( parmIndex )
		|| numUsedParms >= static_cast< int >( sizeof( usedParms ) / sizeof( usedParms[0] ) ) ) return;
	usedParms[numUsedParms++] = parmIndex;
}

void idParmBlockOptimizer::AddUsedParm( const idDeclRenderParm * parm ) {
	if ( parm != nullptr ) AddUsedParmIndex( parm->parmIndex );
}

void idParmBlockOptimizer::OptimizeParmBlockForUsedParms( idParmBlock & parmBlock ) {
	for ( int index = parmBlock.ops.Num() - 1; index >= 0; --index ) {
		const expOp_t & op = parmBlock.ops[index];
		if ( !IsUsed( op.parmIndexDest ) ) {
			parmBlock.ops.RemoveIndex( index );
			parmBlock.constants.RemoveIndex( index );
			++c_removedOps;
			continue;
		}
		switch ( op.OpType() ) {
			case OP_TYPE_UNMASKED_MOVE_CONSTANT:
			case OP_TYPE_MOVE_CONSTANT:
				break;
			case OP_TYPE_TABLE:
				AddUsedParmIndex( op.parmIndexB );
				break;
			case OP_TYPE_UNMASKED_MOVE:
			case OP_TYPE_MOVE:
			case OP_TYPE_SWIZZLE:
				AddUsedParmIndex( op.parmIndexA );
				break;
			default:
				AddUsedParmIndex( op.parmIndexA );
				AddUsedParmIndex( op.parmIndexB );
				break;
		}
		++c_retainedOps;
	}
}
