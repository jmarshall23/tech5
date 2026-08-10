#pragma once

#include "renderlightparms.h"
#include "parmblock.h"

class idDeclRenderParm;
class idFile;
class idRenderLightCommitted;
class idRenderWorldLocal;
class idSerializer;

class alignas( 16 ) idRenderLight {
public:
	idRenderLight();
	~idRenderLight();

	int GetIndex() const;
	idParmBlock * GetParmBlock();
	const idParmBlock * GetParmBlock() const;
	void SetParm( const idDeclRenderParm * parm, const idVec4 & value );
	void CommitThisFrame();
	void Delete();
	void Unlink();
	void Commit();
	void Save( idFile * file ) const;
	bool Load( idFile * file );
	void SerializeSnapshot( idSerializer & serializer );

	idRenderLightParms g;
	idStaticParmBlock<32> gameParmBlock;
	bool deleteOnSync;
	bool unlinked;
	bool needWriteToSnapshot;
	bool skipAutoReplication;
	int serializedChangeCount;
	idRenderLightCommitted * committed;

private:
	friend class idRenderWorldLocal;
};
