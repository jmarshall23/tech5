#pragma once

class idDeclRenderParm;
class idParmBlock;

class idParmBlockOptimizer {
public:
	idParmBlockOptimizer();
	void AddUsedParm( const idDeclRenderParm * parm );
	void AddUsedParmIndex( int parmIndex );
	void OptimizeParmBlockForUsedParms( idParmBlock & parmBlock );

	int usedParms[200];
	int numUsedParms;

	static int c_retainedOps;
	static int c_removedOps;

private:
	bool IsUsed( int parmIndex ) const;
};
