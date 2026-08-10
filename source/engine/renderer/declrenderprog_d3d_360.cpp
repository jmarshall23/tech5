#include "declrenderprog.h"

#include <algorithm>
#include <cstring>

// PDB-authentic filename retained; HLSL is compiled for D3D9 shader model 3.

namespace {

void AddElement( D3DVERTEXELEMENT9 * elements, int & count, WORD stream,
	WORD offset, BYTE type, BYTE usage, BYTE usageIndex ) {
	elements[count].Stream = stream;
	elements[count].Offset = offset;
	elements[count].Type = type;
	elements[count].Method = D3DDECLMETHOD_DEFAULT;
	elements[count].Usage = usage;
	elements[count].UsageIndex = usageIndex;
	++count;
}

const char * SelectSource( const idStr code[PT_NUM_TARGETS] ) {
	if ( code[PT_PC_D3D].Length() > 0 ) return code[PT_PC_D3D].c_str();
	if ( code[PT_PC].Length() > 0 ) return code[PT_PC].c_str();
	if ( code[PT_360].Length() > 0 ) return code[PT_360].c_str();
	return "";
}

bool CompileShader( const char * source, const char * profile, ID3DBlob ** output,
	idStr & error ) {
	if ( source == nullptr || source[0] == '\0' ) return false;
	ID3DBlob * messages = nullptr;
	const HRESULT result = D3DCompile( source, std::strlen( source ), nullptr,
		nullptr, nullptr, "main", profile,
		D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_OPTIMIZATION_LEVEL3, 0,
		output, &messages );
	if ( messages != nullptr ) {
		error = static_cast< const char * >( messages->GetBufferPointer() );
		messages->Release();
	} else error.Clear();
	return SUCCEEDED( result );
}

} // namespace

int idDeclRenderProg::AddDeclarationForVertexFormat( unsigned int storedVertexMask,
		IDirect3DVertexShader9 * shader, IDirect3DVertexDeclaration9 * declaration,
		const unsigned int * strides ) {
	int index = -1;
	for ( int scan = 0; scan < numVertexDeclarations; ++scan ) {
		if ( vertexDeclarations[scan].vertexMask == storedVertexMask ) { index = scan; break; }
	}
	if ( index < 0 ) {
		if ( numVertexDeclarations >= vertexDeclarations.Num() ) return -1;
		index = numVertexDeclarations++;
	}
	vertexDeclaration_t & target = vertexDeclarations[index];
	D3D9Release( target.vertexShaderD3D );
	D3D9Release( target.vertexDeclarationD3D );
	target.vertexShaderD3D = shader;
	target.vertexDeclarationD3D = declaration;
	if ( shader != nullptr ) shader->AddRef();
	if ( declaration != nullptr ) declaration->AddRef();
	target.vertexMask = storedVertexMask;
	for ( int stream = 0; stream < 3; ++stream )
		target.streamStrides[stream] = strides != nullptr ? strides[stream] : 0;
	return index;
}

IDirect3DVertexShader9 * idDeclRenderProg::GetVertexProgramForVertexFormat(
		unsigned int storedVertexMask ) const {
	for ( int index = 0; index < numVertexDeclarations; ++index )
		if ( vertexDeclarations[index].vertexMask == storedVertexMask )
			return vertexDeclarations[index].vertexShaderD3D;
	return nullptr;
}

IDirect3DVertexDeclaration9 * idDeclRenderProg::GetVertexDeclarationForVertexFormat(
		unsigned int storedVertexMask ) const {
	for ( int index = 0; index < numVertexDeclarations; ++index )
		if ( vertexDeclarations[index].vertexMask == storedVertexMask )
			return vertexDeclarations[index].vertexDeclarationD3D;
	return nullptr;
}

const unsigned int * idDeclRenderProg::GetStreamStridesForVertexFormat(
		unsigned int storedVertexMask ) const {
	for ( int index = 0; index < numVertexDeclarations; ++index )
		if ( vertexDeclarations[index].vertexMask == storedVertexMask )
			return vertexDeclarations[index].streamStrides;
	return nullptr;
}

void idDeclRenderProg::CreateVertexShaderForVertexFormat( unsigned int mask ) {
	if ( compiledVertexCode == nullptr || rendererD3D9.GetDevice() == nullptr ||
		GetVertexProgramForVertexFormat( mask ) != nullptr ) return;
	IDirect3DVertexShader9 * shader = nullptr;
	if ( FAILED( rendererD3D9.GetDevice()->CreateVertexShader(
		static_cast< const DWORD * >( compiledVertexCode->GetBufferPointer() ), &shader ) ) ) return;

	D3DVERTEXELEMENT9 elements[16] = {};
	int count = 0;
	WORD offset = 0;
	if ( ( mask & 1 ) != 0 ) {
		const BYTE type = ( mask & 0x20 ) != 0 ? D3DDECLTYPE_SHORT4N : D3DDECLTYPE_FLOAT3;
		AddElement( elements, count, 0, offset, type, D3DDECLUSAGE_POSITION, 0 );
		offset += ( mask & 0x20 ) != 0 ? 8 : 12;
	}
	if ( ( mask & 2 ) != 0 ) {
		const BYTE type = ( mask & 0x40 ) != 0 ? D3DDECLTYPE_SHORT2N : D3DDECLTYPE_FLOAT2;
		AddElement( elements, count, 0, offset, type, D3DDECLUSAGE_TEXCOORD, 0 );
		offset += ( mask & 0x40 ) != 0 ? 4 : 8;
	}
	if ( ( mask & 0x400 ) != 0 ) {
		const BYTE type = ( mask & 0x800 ) != 0 ? D3DDECLTYPE_SHORT2N : D3DDECLTYPE_FLOAT2;
		AddElement( elements, count, 0, offset, type, D3DDECLUSAGE_TEXCOORD, 1 );
		offset += ( mask & 0x800 ) != 0 ? 4 : 8;
	}
	if ( ( mask & 4 ) != 0 ) {
		AddElement( elements, count, 0, offset, D3DDECLTYPE_UBYTE4N, D3DDECLUSAGE_NORMAL, 0 );
		offset += 4;
	}
	if ( ( mask & 0x10 ) != 0 ) {
		AddElement( elements, count, 0, offset, D3DDECLTYPE_UBYTE4N, D3DDECLUSAGE_TANGENT, 0 );
		offset += 4;
	}
	if ( ( mask & 8 ) != 0 ) {
		AddElement( elements, count, 0, offset, D3DDECLTYPE_D3DCOLOR, D3DDECLUSAGE_COLOR, 0 );
		offset += 4;
	}
	const char * source = SelectSource( vertexCode );
	if ( std::strstr( source, "position1" ) != nullptr ) {
		AddElement( elements, count, 1, 0, D3DDECLTYPE_FLOAT4, D3DDECLUSAGE_POSITION, 1 );
		AddElement( elements, count, 1, 16, D3DDECLTYPE_FLOAT4, D3DDECLUSAGE_POSITION, 2 );
		AddElement( elements, count, 1, 32, D3DDECLTYPE_FLOAT4, D3DDECLUSAGE_POSITION, 3 );
	}
	if ( ( vertexMask & 0x80 ) != 0 )
		AddElement( elements, count, 2, 0, D3DDECLTYPE_D3DCOLOR, D3DDECLUSAGE_COLOR, 1 );
	elements[count] = D3DDECL_END();
	IDirect3DVertexDeclaration9 * declaration = nullptr;
	if ( FAILED( rendererD3D9.GetDevice()->CreateVertexDeclaration( elements,
			&declaration ) ) ) { shader->Release(); return; }
	const unsigned int strides[3] = { offset, 48, 4 };
	AddDeclarationForVertexFormat( mask, shader, declaration, strides );
	shader->Release();
	declaration->Release();
}

bool idDeclRenderProg::UploadTargetCode() {
	FreeData();
	const char * pixelSource = SelectSource( fragmentCode );
	const char * vertexSource = SelectSource( vertexCode );
	ID3DBlob * pixelCode = nullptr;
	bool pixelOK = pixelSource[0] == '\0' || CompileShader( pixelSource,
		"ps_3_0", &pixelCode, compilerError );
	if ( pixelCode != nullptr && rendererD3D9.GetDevice() != nullptr ) {
		pixelOK = SUCCEEDED( rendererD3D9.GetDevice()->CreatePixelShader(
			static_cast< const DWORD * >( pixelCode->GetBufferPointer() ), &fragmentShaderD3D ) );
		pixelCode->Release();
	}
	const bool vertexOK = vertexSource[0] == '\0' || CompileShader( vertexSource,
		"vs_3_0", &compiledVertexCode, compilerError );
	isFastZ = std::strstr( pixelSource, "clip(" ) == nullptr;
	if ( vertexOK && compiledVertexCode != nullptr )
		CreateVertexShaderForVertexFormat( vertexMask != 0 ? vertexMask : 0x1f );
	return pixelOK && vertexOK;
}

