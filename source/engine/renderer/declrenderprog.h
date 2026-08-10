#pragma once

#include "../decls/decl.h"
#include "parmblock.h"
#include "renderer_d3d9.h"
#include "../../shared/idlib/containers/array.h"

enum progTarget_t : int {
	PT_PC = 0,
	PT_PC_D3D = 1,
	PT_360 = 2,
	PT_PS3 = 3,
	PT_NUM_TARGETS = 4
};

class alignas( 8 ) idDeclRenderProg : public idDecl {
public:
	enum programType_t : int {
		PROGRAM_TYPE_VERTEX = 0,
		PROGRAM_TYPE_FRAGMENT = 1
	};

	struct vertexDeclaration_t {
		vertexDeclaration_t();
		IDirect3DVertexShader9 * vertexShaderD3D;
		IDirect3DVertexDeclaration9 * vertexDeclarationD3D;
		unsigned int vertexMask;
		unsigned int streamStrides[3];
	};

	idDeclRenderProg();
	~idDeclRenderProg() override;
	idDeclInfo * GetDeclInfo() const override;
	const char * DefaultDefinition() const override;
	void Parse( idParser * parser ) override;
	void FreeData() override;
	void Print() override;
	void List() override;
	unsigned int Size() const override;

	void Clear( progTarget_t target );
	bool ProgUsesParm( const idDeclRenderParm * parm ) const;
	void SetTextureParm( int index, const idImage * image ) const;
	void BindForImmediate( glStateBits_t extraState ) const;
	static void BindTexture( const idImage * image, int unit );

	int AddDeclarationForVertexFormat( unsigned int storedVertexMask,
		IDirect3DVertexShader9 * vertexShaderD3D,
		IDirect3DVertexDeclaration9 * declaration = nullptr,
		const unsigned int * streamStrides = nullptr );
	IDirect3DVertexShader9 * GetVertexProgramForVertexFormat(
		unsigned int storedVertexMask ) const;
	IDirect3DVertexDeclaration9 * GetVertexDeclarationForVertexFormat(
		unsigned int storedVertexMask ) const;
	const unsigned int * GetStreamStridesForVertexFormat(
		unsigned int storedVertexMask ) const;
	void CreateVertexShaderForVertexFormat( unsigned int storedVertexMask );
	bool UploadTargetCode();
	void SetSource( programType_t type, progTarget_t target, const char * source );
	const char * GetLastCompilerError() const { return compilerError.c_str(); }

	const idDeclRenderProg * renamed;
	glStateBits_t glState;
	bool hasClip;
	bool hasAlphaToCoverage;
	bool hasHardwareSkinning;
	bool hasInteractions;
	bool has16BitScaleBias;
	bool hasVertexTexture;
	unsigned short fragmentOutputs;
	unsigned char registerCountPS3;
	unsigned char registerCount360;
	float stageSort;
	idParmBlock parmBlock;
	unsigned int vertexMask;
	unsigned int vertexProgramChecksum;
	unsigned int fragmentProgramChecksum;
	short vertexParms[32];
	int numVertexParms;
	short fragmentParms[32];
	int numFragmentParms;
	short textureParms[16];
	int numTextureParms;
	bool hasDerived;
	const idDeclRenderProg * inheritedVertexProgram;
	const idDeclRenderProg * inheritedFragmentProgram;
	idArray< vertexDeclaration_t, 4 > vertexDeclarations;
	int numVertexDeclarations;
	ID3DBlob * compiledVertexCode;
	IDirect3DPixelShader9 * fragmentShaderD3D;
	bool isFastZ;
	idStr vertexCode[PT_NUM_TARGETS];
	idStr fragmentCode[PT_NUM_TARGETS];
	const idDeclRenderProg * versions[PT_NUM_TARGETS];
	idStr compilerError;

	static idDeclInfoTemplate< idDeclRenderProg > resourceList;
};
