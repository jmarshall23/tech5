#include "../../renderer_d3d9.h"
#include "../../declrenderprog.h"
#include "../../image.h"
#include "../../renderdestination.h"
#include "../../../models/rendermodel.h"
#include "parmstate.h"

#include <algorithm>
#include <array>
#include <cstring>

// The PDB-authentic filename is retained for source correlation.  This file
// is the Windows D3D9 implementation; it contains no Xbox graphics calls.

namespace {

struct querySlot_t {
	querySlot_t() : query( nullptr ), number( -1 ), result( 0 ), pending( false ) {}
	IDirect3DQuery9 * query;
	std::int64_t number;
	DWORD result;
	bool pending;
};

struct renderStateD3D9_t {
	renderStateD3D9_t() : currentState( ~0ull ), targetWidth( 0 ), targetHeight( 0 ),
		frameNumber( 0 ), nextQueryNumber( 0 ), activeQuery( nullptr ),
		frameFence( nullptr ), frameStartMicroseconds( 0 ), frameEndMicroseconds( 0 ),
		lastTextureUnit( -1 ), lastProgram( nullptr ), lastVertexMask( 0 ),
		boundVertexParmVersion( 0 ), boundFragmentParmVersion( 0 ),
		boundTextureParmVersion( 0 ) {
		std::memset( boundTextures, 0, sizeof( boundTextures ) );
	}
	glStateBits_t currentState;
	int targetWidth;
	int targetHeight;
	int frameNumber;
	std::int64_t nextQueryNumber;
	querySlot_t * activeQuery;
	IDirect3DQuery9 * frameFence;
	std::uint64_t frameStartMicroseconds;
	std::uint64_t frameEndMicroseconds;
	int lastTextureUnit;
	const idDeclRenderProg * lastProgram;
	unsigned int lastVertexMask;
	std::uint64_t boundVertexParmVersion;
	std::uint64_t boundFragmentParmVersion;
	std::uint64_t boundTextureParmVersion;
	const idImage * boundTextures[16];
};

wrapperContext_t wrapperContext;
wrapperConfig_t wrapperConfig = {};
wrapperStats_t wrapperStats = {};
renderStateD3D9_t renderState;
std::array< querySlot_t, 4096 > querySlots;

std::uint64_t Microseconds() {
	LARGE_INTEGER counter = {};
	LARGE_INTEGER frequency = {};
	QueryPerformanceCounter( &counter );
	QueryPerformanceFrequency( &frequency );
	return frequency.QuadPart != 0 ?
		static_cast< std::uint64_t >( counter.QuadPart * 1000000ull / frequency.QuadPart ) : 0;
}

DWORD FloatBits( float value ) {
	DWORD bits = 0;
	std::memcpy( &bits, &value, sizeof( bits ) );
	return bits;
}

D3DBLEND SourceBlend( glStateBits_t state ) {
	switch ( ( state & GLS_SRCBLEND_BITS ) >> 0 ) {
		case 1: return D3DBLEND_ZERO;
		case 2: return D3DBLEND_DESTCOLOR;
		case 3: return D3DBLEND_INVDESTCOLOR;
		case 4: return D3DBLEND_SRCALPHA;
		case 5: return D3DBLEND_INVSRCALPHA;
		case 6: return D3DBLEND_DESTALPHA;
		case 7: return D3DBLEND_INVDESTALPHA;
		default: return D3DBLEND_ONE;
	}
}

D3DBLEND DestinationBlend( glStateBits_t state ) {
	switch ( ( state & GLS_DSTBLEND_BITS ) >> 3 ) {
		case 1: return D3DBLEND_ONE;
		case 2: return D3DBLEND_SRCCOLOR;
		case 3: return D3DBLEND_INVSRCCOLOR;
		case 4: return D3DBLEND_SRCALPHA;
		case 5: return D3DBLEND_INVSRCALPHA;
		case 6: return D3DBLEND_DESTALPHA;
		case 7: return D3DBLEND_INVDESTALPHA;
		default: return D3DBLEND_ZERO;
	}
}

D3DBLENDOP BlendOperation( glStateBits_t state ) {
	switch ( ( state & GLS_BLENDOP_BITS ) >> 18 ) {
		case 1: return D3DBLENDOP_SUBTRACT;
		case 2: return D3DBLENDOP_MIN;
		case 3: return D3DBLENDOP_MAX;
		default: return D3DBLENDOP_ADD;
	}
}

D3DCMPFUNC DepthFunction( glStateBits_t state ) {
	// idTech 5 uses a reversed depth buffer (viewport Z is 1..0).
	switch ( ( state & GLS_DEPTHFUNC_BITS ) >> 13 ) {
		case 1: return D3DCMP_ALWAYS;
		case 2: return D3DCMP_LESS;
		case 3: return D3DCMP_EQUAL;
		default: return D3DCMP_GREATER;
	}
}

D3DCMPFUNC StencilFunction( glStateBits_t state ) {
	static const D3DCMPFUNC functions[8] = {
		D3DCMP_ALWAYS, D3DCMP_LESS, D3DCMP_LESSEQUAL, D3DCMP_GREATER,
		D3DCMP_GREATEREQUAL, D3DCMP_EQUAL, D3DCMP_NOTEQUAL, D3DCMP_NEVER
	};
	return functions[ static_cast< unsigned int >( ( state >> 36 ) & 7 ) ];
}

D3DSTENCILOP StencilOperation( unsigned int operation ) {
	static const D3DSTENCILOP operations[8] = {
		D3DSTENCILOP_KEEP, D3DSTENCILOP_ZERO, D3DSTENCILOP_REPLACE,
		D3DSTENCILOP_INCRSAT, D3DSTENCILOP_DECRSAT, D3DSTENCILOP_INVERT,
		D3DSTENCILOP_INCR, D3DSTENCILOP_DECR
	};
	return operations[ operation & 7 ];
}

IDirect3DDevice9 * Device() {
	return wrapperContext.d3d != nullptr ? wrapperContext.d3d : rendererD3D9.GetDevice();
}

void PollQuery( querySlot_t & slot, bool wait ) {
	if ( !slot.pending || slot.query == nullptr ) {
		return;
	}
	const std::uint64_t start = Microseconds();
	HRESULT result = slot.query->GetData( &slot.result, sizeof( slot.result ),
		wait ? D3DGETDATA_FLUSH : 0 );
	while ( wait && result == S_FALSE ) {
		SwitchToThread();
		result = slot.query->GetData( &slot.result, sizeof( slot.result ), D3DGETDATA_FLUSH );
	}
	if ( result == S_OK ) {
		slot.pending = false;
		wrapperStats.c_queriesPassed += slot.result != 0 ? 1 : 0;
	}
	wrapperStats.c_queriesWaitTime += static_cast< int >( Microseconds() - start );
}

} // namespace

void GL_SetWrapperContext( const wrapperContext_t & context ) {
	wrapperContext = context;
	renderState.currentState = ~0ull;
	renderState.targetWidth = rendererD3D9.Width();
	renderState.targetHeight = rendererD3D9.Height();
	renderState.activeQuery = nullptr;
}

void GL_SetWrapperConfig( const wrapperConfig_t & config ) {
	wrapperConfig = config;
}

void GL_StartFrame( int frame ) {
	renderState.frameNumber = frame;
	renderState.frameStartMicroseconds = Microseconds();
	renderState.frameEndMicroseconds = renderState.frameStartMicroseconds;
	renderState.targetWidth = rendererD3D9.Width();
	renderState.targetHeight = rendererD3D9.Height();
	rendererD3D9.BeginScene();
}

void GL_EndFrame() {
	IDirect3DDevice9 * device = Device();
	renderState.frameEndMicroseconds = Microseconds();
	D3D9Release( renderState.frameFence );
	if ( device != nullptr && SUCCEEDED( device->CreateQuery( D3DQUERYTYPE_EVENT,
			&renderState.frameFence ) ) ) {
		renderState.frameFence->Issue( D3DISSUE_END );
	}
}

void GL_WaitForEndFrame() {
	if ( renderState.frameFence == nullptr ) {
		return;
	}
	while ( renderState.frameFence->GetData( nullptr, 0, D3DGETDATA_FLUSH ) == S_FALSE ) {
		SwitchToThread();
	}
}

void GL_GetLastFrameTime( std::uint64_t & startGPUTimeMicroSec,
		std::uint64_t & endGPUTimeMicroSec ) {
	startGPUTimeMicroSec = renderState.frameStartMicroseconds;
	endGPUTimeMicroSec = renderState.frameEndMicroseconds;
}

void GL_Flush() {
	IDirect3DDevice9 * device = Device();
	if ( device == nullptr ) {
		return;
	}
	IDirect3DQuery9 * query = nullptr;
	if ( SUCCEEDED( device->CreateQuery( D3DQUERYTYPE_EVENT, &query ) ) ) {
		query->Issue( D3DISSUE_END );
		query->GetData( nullptr, 0, D3DGETDATA_FLUSH );
		query->Release();
	}
}

void GL_Finish() {
	IDirect3DDevice9 * device = Device();
	if ( device == nullptr ) {
		return;
	}
	IDirect3DQuery9 * query = nullptr;
	if ( SUCCEEDED( device->CreateQuery( D3DQUERYTYPE_EVENT, &query ) ) ) {
		query->Issue( D3DISSUE_END );
		while ( query->GetData( nullptr, 0, D3DGETDATA_FLUSH ) == S_FALSE ) {
			SwitchToThread();
		}
		query->Release();
	}
}

void GL_State( glStateBits_t state, bool forceGlState ) {
	IDirect3DDevice9 * device = Device();
	if ( device == nullptr ) {
		return;
	}
	if ( wrapperConfig.forceTwoSided ) {
		state |= GLS_CULL_TWOSIDED;
	}
	if ( !forceGlState && !wrapperConfig.disableStateCaching &&
			renderState.currentState == state ) {
		return;
	}

	device->SetRenderState( D3DRS_CULLMODE,
		( state & GLS_CULL_TWOSIDED ) != 0 ? D3DCULL_NONE :
		( ( state & GLS_CULL_BACKSIDED ) != 0 ? D3DCULL_CW : D3DCULL_CCW ) );
	device->SetRenderState( D3DRS_ZENABLE, TRUE );
	device->SetRenderState( D3DRS_ZFUNC, DepthFunction( state ) );
	device->SetRenderState( D3DRS_ZWRITEENABLE, ( state & GLS_DEPTHMASK ) == 0 );

	const D3DBLEND src = SourceBlend( state );
	const D3DBLEND dst = DestinationBlend( state );
	const D3DBLENDOP op = BlendOperation( state );
	device->SetRenderState( D3DRS_ALPHABLENDENABLE,
		!( src == D3DBLEND_ONE && dst == D3DBLEND_ZERO && op == D3DBLENDOP_ADD ) );
	device->SetRenderState( D3DRS_SRCBLEND, src );
	device->SetRenderState( D3DRS_DESTBLEND, dst );
	device->SetRenderState( D3DRS_BLENDOP, op );

	DWORD colorMask = 0;
	if ( ( state & GLS_REDMASK ) == 0 ) colorMask |= D3DCOLORWRITEENABLE_RED;
	if ( ( state & GLS_GREENMASK ) == 0 ) colorMask |= D3DCOLORWRITEENABLE_GREEN;
	if ( ( state & GLS_BLUEMASK ) == 0 ) colorMask |= D3DCOLORWRITEENABLE_BLUE;
	if ( ( state & GLS_ALPHAMASK ) == 0 ) colorMask |= D3DCOLORWRITEENABLE_ALPHA;
	device->SetRenderState( D3DRS_COLORWRITEENABLE, colorMask );
	device->SetRenderState( D3DRS_FILLMODE,
		( state & GLS_POLYMODE_LINE ) != 0 ? D3DFILL_WIREFRAME : D3DFILL_SOLID );

	if ( ( state & GLS_POLYGON_OFFSET ) != 0 ) {
		device->SetRenderState( D3DRS_SLOPESCALEDEPTHBIAS,
			FloatBits( -wrapperConfig.defaultPolyOfsFactor ) );
		device->SetRenderState( D3DRS_DEPTHBIAS,
			FloatBits( -wrapperConfig.defaultPolyOfsUnits ) );
	} else {
		device->SetRenderState( D3DRS_SLOPESCALEDEPTHBIAS, 0 );
		device->SetRenderState( D3DRS_DEPTHBIAS, 0 );
	}

	const bool stencil = ( state & ( GLS_STENCIL_FUNC_BITS | GLS_STENCIL_OP_BITS ) ) != 0;
	device->SetRenderState( D3DRS_STENCILENABLE, stencil ? TRUE : FALSE );
	if ( stencil ) {
		device->SetRenderState( D3DRS_STENCILREF,
			static_cast< DWORD >( ( state & GLS_STENCIL_FUNC_REF_BITS ) >> GLS_STENCIL_FUNC_REF_SHIFT ) );
		device->SetRenderState( D3DRS_STENCILMASK,
			static_cast< DWORD >( ( state & GLS_STENCIL_FUNC_MASK_BITS ) >> GLS_STENCIL_FUNC_MASK_SHIFT ) );
		device->SetRenderState( D3DRS_STENCILFUNC, StencilFunction( state ) );
		device->SetRenderState( D3DRS_STENCILFAIL,
			StencilOperation( static_cast< unsigned int >( state >> 39 ) ) );
		device->SetRenderState( D3DRS_STENCILZFAIL,
			StencilOperation( static_cast< unsigned int >( state >> 42 ) ) );
		device->SetRenderState( D3DRS_STENCILPASS,
			StencilOperation( static_cast< unsigned int >( state >> 45 ) ) );
	}
	renderState.currentState = state;
}

void GL_Scissor( int x, int y, int width, int height ) {
	IDirect3DDevice9 * device = Device();
	if ( device == nullptr ) return;
	RECT rect = { x, renderState.targetHeight - y - height,
		x + std::max( width, 0 ), renderState.targetHeight - y };
	device->SetRenderState( D3DRS_SCISSORTESTENABLE, TRUE );
	device->SetScissorRect( &rect );
}

void GL_Viewport( int x, int y, int width, int height ) {
	IDirect3DDevice9 * device = Device();
	if ( device == nullptr ) return;
	D3DVIEWPORT9 viewport = {};
	viewport.X = static_cast< DWORD >( std::max( x, 0 ) );
	viewport.Y = static_cast< DWORD >( std::max( renderState.targetHeight - y - height, 0 ) );
	viewport.Width = static_cast< DWORD >( std::max( width, 1 ) );
	viewport.Height = static_cast< DWORD >( std::max( height, 1 ) );
	viewport.MinZ = 1.0f;
	viewport.MaxZ = 0.0f;
	device->SetViewport( &viewport );
}

void GL_Clear( bool color, bool depth, bool stencil, unsigned char stencilValue,
		float red, float green, float blue, float alpha ) {
	IDirect3DDevice9 * device = Device();
	if ( device == nullptr ) return;
	DWORD flags = 0;
	if ( color ) flags |= D3DCLEAR_TARGET;
	if ( depth ) flags |= D3DCLEAR_ZBUFFER;
	if ( stencil ) flags |= D3DCLEAR_STENCIL;
	const D3DCOLOR clearColor = D3DCOLOR_COLORVALUE( red, green, blue, alpha );
	device->Clear( 0, nullptr, flags, clearColor, 0.0f, stencilValue );
}

void GL_PolygonOffset( float scale, float bias, bool fill ) {
	IDirect3DDevice9 * device = Device();
	if ( device == nullptr ) return;
	device->SetRenderState( D3DRS_SLOPESCALEDEPTHBIAS, FloatBits( fill ? -scale : 0.0f ) );
	device->SetRenderState( D3DRS_DEPTHBIAS, FloatBits( fill ? -bias : 0.0f ) );
}

std::int64_t GL_GetCurrentQueryNumber() {
	return renderState.nextQueryNumber;
}

void GL_CacheOcclusionQueryBatches( std::int64_t upToIncludingBatchNum ) {
	for ( querySlot_t & slot : querySlots ) {
		if ( slot.pending && slot.number <= upToIncludingBatchNum ) {
			PollQuery( slot, wrapperConfig.waitForOcclusionQuery );
		}
	}
}

void GL_BeginQueryBatch() {
	GL_CacheOcclusionQueryBatches( renderState.nextQueryNumber -
		static_cast< std::int64_t >( querySlots.size() ) );
}

void GL_BeginQuery( std::int64_t * queryNumber ) {
	IDirect3DDevice9 * device = Device();
	if ( queryNumber == nullptr ) return;
	const std::int64_t number = renderState.nextQueryNumber++;
	*queryNumber = number;
	querySlot_t & slot = querySlots[ static_cast< std::size_t >( number ) % querySlots.size() ];
	if ( slot.pending ) PollQuery( slot, true );
	D3D9Release( slot.query );
	slot.number = number;
	slot.result = 0;
	slot.pending = false;
	if ( device != nullptr && SUCCEEDED( device->CreateQuery( D3DQUERYTYPE_OCCLUSION,
			&slot.query ) ) ) {
		slot.query->Issue( D3DISSUE_BEGIN );
		renderState.activeQuery = &slot;
		++wrapperStats.c_queriesIssued;
	}
}

void GL_EndQuery() {
	if ( renderState.activeQuery != nullptr && renderState.activeQuery->query != nullptr ) {
		renderState.activeQuery->query->Issue( D3DISSUE_END );
		renderState.activeQuery->pending = true;
	}
	renderState.activeQuery = nullptr;
}

int GL_GetDeferredQueryResult( std::int64_t queryNumber ) {
	querySlot_t & slot = querySlots[ static_cast< std::size_t >( queryNumber ) % querySlots.size() ];
	if ( slot.number != queryNumber ) {
		++wrapperStats.c_queriesTooOld;
		return 0;
	}
	PollQuery( slot, wrapperConfig.waitForOcclusionQuery );
	return static_cast< int >( slot.result );
}

void GL_ResetProgramState() {
	renderState.lastProgram = nullptr;
	renderState.lastVertexMask = 0;
	renderState.boundVertexParmVersion = 0;
	renderState.boundFragmentParmVersion = 0;
}

void GL_ResetTextureState() {
	renderState.lastTextureUnit = -1;
	renderState.boundTextureParmVersion = 0;
	std::memset( renderState.boundTextures, 0, sizeof( renderState.boundTextures ) );
}

wrapperStats_t GL_GetCurrentStats() {
	return wrapperStats;
}

void GL_ClearStats() {
	std::memset( &wrapperStats, 0, sizeof( wrapperStats ) );
}

void GL_SetDefaultState() {
	renderState.currentState = ~0ull;
	GL_State( GLS_DEFAULT, true );
	IDirect3DDevice9 * device = Device();
	if ( device != nullptr ) {
		device->SetRenderState( D3DRS_LIGHTING, FALSE );
		device->SetRenderState( D3DRS_CLIPPING, TRUE );
		device->SetRenderState( D3DRS_SCISSORTESTENABLE, TRUE );
		device->SetRenderState( D3DRS_SEPARATEALPHABLENDENABLE, FALSE );
	}
}

void GL_SetRenderDestination( const idRenderDestination * destination,
		int face, int mipLevel ) {
	if ( destination == nullptr ) return;
	destination->Bind( face, mipLevel );
	renderState.targetWidth = destination->targetWidth;
	renderState.targetHeight = destination->targetHeight;
	GL_Viewport( 0, 0, renderState.targetWidth, renderState.targetHeight );
	GL_Scissor( 0, 0, renderState.targetWidth, renderState.targetHeight );
}

void GL_ResolveTarget( resolveTarget_t target,
		const idRenderDestination * destination ) {
	if ( destination == nullptr ) return;
	GL_ResolveTarget( target, destination, 0, 0, 0, 0,
		destination->targetWidth, destination->targetHeight );
}

void GL_ResolveTarget( resolveTarget_t target,
		const idRenderDestination * destination, int sourceX, int sourceY,
		int destinationX, int destinationY, int width, int height ) {
	IDirect3DDevice9 * device = Device();
	if ( device == nullptr || destination == nullptr || target == RESOLVE_TARGET_DEPTH ) return;
	const int index = static_cast< int >( target );
	IDirect3DSurface9 * source = nullptr;
	IDirect3DSurface9 * output = destination->AcquireTargetSurface( index, 0, 0 );
	if ( output == nullptr || FAILED( device->GetRenderTarget( index, &source ) ) ) {
		D3D9Release( output );
		return;
	}
	if ( source != output ) {
		RECT sourceRect = { sourceX, sourceY, sourceX + width, sourceY + height };
		RECT destinationRect = { destinationX, destinationY,
			destinationX + width, destinationY + height };
		device->StretchRect( source, &sourceRect, output, &destinationRect, D3DTEXF_NONE );
	}
	D3D9Release( source );
	D3D9Release( output );
}

void GL_BindTexture( const idImage * image, int unit ) {
	if ( image != nullptr ) {
		image->Bind( unit );
		++wrapperStats.c_texturesBound;
	} else if ( Device() != nullptr ) {
		Device()->SetTexture( unit, nullptr );
	}
}

void GL_BindProgram( const idDeclRenderProg * program,
		glStateBits_t extraState, unsigned int mask ) {
	IDirect3DDevice9 * device = Device();
	if ( device == nullptr || program == nullptr ) return;
	const bool programChanged = renderState.lastProgram != program ||
		renderState.lastVertexMask != mask;
	idDeclRenderProg * mutableProgram = const_cast< idDeclRenderProg * >( program );
	if ( mutableProgram->compiledVertexCode == nullptr &&
			mutableProgram->fragmentShaderD3D == nullptr ) mutableProgram->UploadTargetCode();
	if ( program->GetVertexProgramForVertexFormat( mask ) == nullptr )
		mutableProgram->CreateVertexShaderForVertexFormat( mask );
	if ( programChanged || !wrapperConfig.lazyBindPrograms ) {
		device->SetVertexShader( program->GetVertexProgramForVertexFormat( mask ) );
		device->SetVertexDeclaration(
			program->GetVertexDeclarationForVertexFormat( mask ) );
		device->SetPixelShader( program->isFastZ
			? nullptr : program->fragmentShaderD3D );
	}
	GL_State( program->glState | extraState );

	if ( renderThreadParmState != nullptr ) {
		renderThreadParmState->UpdateParmUsageMasks( program );
		const glStateBits_t state = program->glState | extraState;
		if ( ( state & GLS_CULL_TWOSIDED ) == 0 ) {
			const bool backSided = ( state & GLS_CULL_BACKSIDED ) != 0;
			const bool clockwise = backSided !=
				renderThreadParmState->currentMVPHasNegativeDeterminant;
			device->SetRenderState( D3DRS_CULLMODE,
				clockwise ? D3DCULL_CW : D3DCULL_CCW );
		}

		if ( programChanged || !wrapperConfig.lazyBindParms ||
				renderState.boundVertexParmVersion !=
				renderThreadParmState->vertexParmVersion ) {
			for ( int index = 0; index < program->numVertexParms; ++index ) {
				const int parmIndex = program->vertexParms[index];
				if ( parmIndex >= 0 && parmIndex < RENDERPARM_INVALID )
					device->SetVertexShaderConstantF( index,
						renderThreadParmState->values[parmIndex].value, 1 );
			}
		}
		if ( programChanged || !wrapperConfig.lazyBindParms ||
				renderState.boundFragmentParmVersion !=
				renderThreadParmState->fragmentParmVersion ) {
			for ( int index = 0; index < program->numFragmentParms; ++index ) {
				const int parmIndex = program->fragmentParms[index];
				if ( parmIndex >= 0 && parmIndex < RENDERPARM_INVALID )
					device->SetPixelShaderConstantF( index,
						renderThreadParmState->values[parmIndex].value, 1 );
			}
		}
		if ( programChanged || !wrapperConfig.lazyBindTextures ||
				renderState.boundTextureParmVersion !=
				renderThreadParmState->textureParmVersion ) {
			int index = 0;
			for ( ; index < program->numTextureParms && index < 16; ++index ) {
				const int parmIndex = program->textureParms[index];
				const idImage * image = parmIndex >= 0 &&
					parmIndex < RENDERPARM_INVALID
					? renderThreadParmState->values[parmIndex].image : nullptr;
				if ( programChanged || renderState.boundTextures[index] != image ) {
					GL_BindTexture( image, index );
					renderState.boundTextures[index] = image;
				}
			}
			for ( ; index < 16; ++index ) {
				if ( renderState.boundTextures[index] != nullptr )
					device->SetTexture( index, nullptr );
				renderState.boundTextures[index] = nullptr;
			}
		}
		renderState.boundVertexParmVersion =
			renderThreadParmState->vertexParmVersion;
		renderState.boundFragmentParmVersion =
			renderThreadParmState->fragmentParmVersion;
		renderState.boundTextureParmVersion =
			renderThreadParmState->textureParmVersion;
	}
	renderState.lastProgram = program;
	renderState.lastVertexMask = mask;
	++wrapperStats.c_programsBound;
}

void GL_DrawElements( const idDeclRenderProg * program,
		const idRenderModelSurface * surface, glStateBits_t extraState,
		bool skipDetailTriangles ) {
	if ( surface == nullptr ) return;
	GL_DrawElements( program, surface->geometry,
		extraState | surface->extraGLState, skipDetailTriangles );
}

void GL_DrawElements( const idDeclRenderProg * program,
		const idTriangles * triangles, glStateBits_t extraState,
		bool skipDetailTriangles ) {
	IDirect3DDevice9 * device = Device();
	if ( device == nullptr || program == nullptr || triangles == nullptr ||
			triangles->numIndexes < 3 || triangles->numVerts <= 0 ) return;
	unsigned int mask = triangles->vertexMask != 0 ? triangles->vertexMask : 0x1f;
	if ( ( mask & 0x60 ) != 0 && renderThreadParmState != nullptr )
		renderThreadParmState->Set16BitVertexScaleBias( triangles->vsb );
	GL_BindProgram( program, extraState, mask );
	const int drawIndexes = ( wrapperConfig.skipDetailTris || skipDetailTriangles ) &&
		triangles->detailOffset > 0 && triangles->detailOffset < triangles->numIndexes
		? triangles->detailOffset : triangles->numIndexes;
	if ( drawIndexes < 3 ) return;
	const bool strip = ( mask & 0x200 ) != 0;
	const D3DPRIMITIVETYPE primitive = strip ? D3DPT_TRIANGLESTRIP : D3DPT_TRIANGLELIST;
	const UINT primitiveCount = strip ? drawIndexes - 2 : drawIndexes / 3;
	const unsigned int * strides = program->GetStreamStridesForVertexFormat( mask );
	const UINT stride = strides != nullptr && strides[0] != 0 ? strides[0] : sizeof( idDrawVert );

	IDirect3DVertexBuffer9 * vertexBuffer = static_cast< IDirect3DVertexBuffer9 * >(
		triangles->vertexBuffer.apiObject );
	IDirect3DIndexBuffer9 * indexBuffer = static_cast< IDirect3DIndexBuffer9 * >(
		triangles->indexBuffer.apiObject );
	HRESULT result = E_FAIL;
	if ( vertexBuffer != nullptr && indexBuffer != nullptr ) {
		device->SetStreamSource( 0, vertexBuffer,
			triangles->vertexBuffer.offsetInOtherBuffer, stride );
		device->SetIndices( indexBuffer );
		const UINT startIndex = triangles->indexBuffer.offsetInOtherBuffer / sizeof( unsigned short );
		result = device->DrawIndexedPrimitive( primitive, 0, 0,
			triangles->numVerts, startIndex, primitiveCount );
	} else if ( triangles->verts != nullptr && triangles->indexes != nullptr ) {
		result = device->DrawIndexedPrimitiveUP( primitive, 0, triangles->numVerts,
			primitiveCount, triangles->indexes, D3DFMT_INDEX16,
			triangles->verts, sizeof( idDrawVert ) );
	}
	if ( SUCCEEDED( result ) ) {
		++wrapperStats.c_drawElements;
		wrapperStats.c_drawIndices += drawIndexes;
		wrapperStats.c_drawVertices += triangles->numVerts;
	}
	if ( wrapperConfig.finishEveryDraw ) GL_Finish();
}
