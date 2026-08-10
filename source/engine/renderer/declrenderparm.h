#pragma once

#include "../decls/decl.h"
#include "parmblock.h"
#include "renderer_types.h"

class idImage;
class idParser;

// A render parm is both a declaration and the stable identity used by the
// expression bytecode.  Retail reserved index 2047 as the invalid value.
class alignas( 4 ) idDeclRenderParm : public idDecl {
public:
	idDeclRenderParm();
	~idDeclRenderParm() override;

	idDeclInfo * GetDeclInfo() const override;
	const char * DefaultDefinition() const override;
	void Parse( idParser * parser ) override;
	void FreeData() override;
	void Print() override;
	void List() override;
	unsigned int Size() const override;

	void ParseStringToValue( const char * text, parmValue_t & value ) const;
	void ParseValue( idParser & parser, parmValue_t & value ) const;
	static bool ParseVectorConstant( idParser & parser, float vector[4] );
	static const idDeclRenderParm * FindByIndex( int index );
	static const idDeclRenderParm * FindByName( const char * name,
		bool makeDefault = true );

	int parmIndex;
	parmType_t parmType;
	parmCreator_t creator;
	bool cubeFilterTexture;
	parmValue_t declaredValue;
	parmEdit_t edit;
	float editRange[2];

	static idDeclInfoTemplate< idDeclRenderParm > resourceList;

private:
	const idImage * ParseImageLine( idParser & parser ) const;
	void RegisterParm();
};

#if defined( _WIN32 ) && !defined( _WIN64 )
static_assert( sizeof( idDeclRenderParm ) == 100,
	"Recovered render-parm declaration ABI changed" );
#endif
