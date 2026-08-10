#pragma once

#include "../../parmblock.h"

#include <cstdint>

class idDeclRenderParm;
class idDeclRenderProg;
class idDeclTable;
class idLookupTable;
class idRenderMatrix;
class idVertexScaleAndBias;
struct approximateLighting_t;

struct uniqueParmState_t {
	std::uint64_t renderParmVersion;
	unsigned int numBlocks;
	const idParmBlock * parmBlocks[32];
	void * userData;
};

class alignas( 16 ) idParmState {
public:
	struct parmStack_t {
		struct parmBlockStack_t {
			unsigned int lastOpLevel;
			const idParmBlock * parmBlock;
		};

		unsigned int virtualParmBlockLevel;
		unsigned int currentParmBlockLevel;
		unsigned int currentOpLevel;
		unsigned int virtualParmBlockStackMask;
		parmBlockStack_t parmBlockStack[32];
		parmValue_t opStack[1024];
	};

	idParmState();
	void Init();
	int AllocParmState( const idDeclRenderParm * parm );
	void FreeParmState( const idDeclRenderParm * parm );
	int GetTableIndex( const idDeclTable * table );
	const idDeclTable * GetTable( int tableIndex ) const;
	void RemoveTable( const idDeclTable * table );
	const char * GetParmNameForIndex( int parmIndex ) const;
	const idDeclRenderParm * GetRenderParmForIndex( int parmIndex ) const;
	void UpdateParmUsageMasks( const idDeclRenderProg * program );
	void PrintSharedRenderParms() const;

	void EvaluateParmBlock( const idParmBlock & localParmBlock,
		const idParmBlock & parmBlock );
	void RollbackParmBlock( const idParmBlock & localParmBlock,
		const idParmBlock & parmBlock );
	void VirtualEvaluateParmBlock( const idParmBlock & localParmBlock,
		const idParmBlock & parmBlock );
	void VirtualRollbackParmBlock( const idParmBlock & localParmBlock,
		const idParmBlock & parmBlock );
	void RemoveFromVirtualStack( const idParmBlock & parmBlock );
	void RollbackOpsToZero();

	void SetVertexMorphScale( const idVec4 & scale );
	void Set16BitVertexScaleBias( const idVertexScaleAndBias & scaleBias );
	void SetModelMatrix( const idRenderMatrix & matrix );
	void SetInverseModelMatrix( const idRenderMatrix & matrix );
	void SetMVPMatrix( const idRenderMatrix & matrix );
	void SetPositionToViewTexture( int windowWidth, int windowHeight,
		int renderWidth, int renderHeight );
	void SetRenderPositionToViewTexture( int windowWidth, int windowHeight,
		int renderWidth, int renderHeight );
	void SetPositionToFeedback( int renderWidth, int renderHeight,
		int feedbackWidth, int feedbackHeight );
	void SetHighlightColor( const idVec4 & highlightColor );
	void SetApproximateLighting( const approximateLighting_t & lighting );
	void SetParmValue( int parmIndex, const parmValue_t & value );

	std::uint64_t renderParmVersion;
	std::uint64_t vertexParmVersion;
	std::uint64_t fragmentParmVersion;
	std::uint64_t textureParmVersion;
	bool currentMVPHasNegativeDeterminant;
	alignas( 16 ) parmValue_t values[2048];
	unsigned int onParmBlockStack[2048];
	parmStack_t parmStack;
	const idDeclRenderParm * parmDecl[2048];
	unsigned char parmUsageMask[2048];
	const idDeclTable * globalTables[128];
	const idLookupTable * globalLookupTables[128];
	int numGlobalTables;
	int parmIndexPositionToViewTexture;
	int parmIndexRenderPositionToViewTexture;
	int parmIndexPositionToFeedback;
	int parmIndexModelMatrixX;
	int parmIndexModelMatrixY;
	int parmIndexModelMatrixZ;
	int parmIndexModelMatrixW;
	int parmIndexInverseModelMatrixX;
	int parmIndexInverseModelMatrixY;
	int parmIndexInverseModelMatrixZ;
	int parmIndexInverseModelMatrixW;
	int parmIndexMVPMatrixX;
	int parmIndexMVPMatrixY;
	int parmIndexMVPMatrixZ;
	int parmIndexMVPMatrixW;
	int parmIndexPrimeLightDir;
	int parmIndexPrimeLightColor;
	int parmIndexChannelLight[6];
	int parmIndexLightingModel;
	int parmIndexHighlightColor;
	int parmIndexVertexStScaleBias;
	int parmIndexVertexXYZScale;
	int parmIndexVertexXYZBias;
	int parmIndexIf;
	int parmIndexPolygonOffset;
	int parmIndexVertexMorphScale;

private:
	static void CopyParmUnaligned( void * destination, const void * source );
	void ApplyOp( const expOp_t & op, const parmValue_t & constant,
		const parmValue_t & parmA, const parmValue_t & parmB,
		parmValue_t & result ) const;
	void RollbackVirtualStack( bool renderParmChange );
	void BumpVersion( int parmIndex );
	int ParmIndex( const char * name );
};

extern idParmState renderThreadParmStateObject;
extern idParmState * renderThreadParmState;
