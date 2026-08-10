#include "render.h"

#include "renderer_d3d9.h"
#include "renderview.h"
#include "renderworld_local.h"

#include <algorithm>
#include <vector>

// PDB-authentic filename retained; all debug submission below is Windows
// D3D9 and uses pre-transformed vertices instead of the 360 command buffer.

namespace {
	struct debugVertex_t {
		float x, y, z, rhw;
		D3DCOLOR color;
	};

	D3DCOLOR DebugColor( const idVec4 & color ) {
		return D3DCOLOR_COLORVALUE(
			(std::max)( 0.0f, (std::min)( 1.0f, color.x ) ),
			(std::max)( 0.0f, (std::min)( 1.0f, color.y ) ),
			(std::max)( 0.0f, (std::min)( 1.0f, color.z ) ),
			(std::max)( 0.0f, (std::min)( 1.0f, color.w ) ) );
	}

	bool ProjectDebugPoint( const idRenderView & view, const idVec3 & point,
			const D3DCOLOR color, debugVertex_t & output ) {
		idVec4 clip;
		view.worldSpaceMVPMatrix.TransformPoint( point, clip );
		if ( clip.w <= 1.0e-4f ) return false;
		const float inverseW = 1.0f / clip.w;
		const float ndcX = clip.x * inverseW;
		const float ndcY = clip.y * inverseW;
		output.x = ( ndcX * 0.5f + 0.5f ) * view.renderWidth;
		output.y = ( -ndcY * 0.5f + 0.5f ) * view.renderHeight;
		output.z = (std::max)( 0.0f, (std::min)( 1.0f, clip.z * inverseW ) );
		output.rhw = inverseW;
		output.color = color;
		return true;
	}

	void SetDebugDepthState( IDirect3DDevice9 * device, const bool depthTest ) {
		device->SetRenderState( D3DRS_ZENABLE, depthTest ? D3DZB_TRUE : D3DZB_FALSE );
		device->SetRenderState( D3DRS_ZWRITEENABLE, FALSE );
	}

	void DrawDebugLine( IDirect3DDevice9 * device, const idRenderView & view,
			const idVec3 & start, const idVec3 & end, const idVec4 & color,
			const bool depthTest ) {
		debugVertex_t vertices[2];
		const D3DCOLOR packedColor = DebugColor( color );
		if ( !ProjectDebugPoint( view, start, packedColor, vertices[0] ) ||
				!ProjectDebugPoint( view, end, packedColor, vertices[1] ) ) return;
		SetDebugDepthState( device, depthTest );
		device->DrawPrimitiveUP( D3DPT_LINELIST, 1, vertices,
			sizeof( debugVertex_t ) );
	}

	void BeginDebugDrawing( IDirect3DDevice9 * device ) {
		device->SetVertexShader( nullptr );
		device->SetPixelShader( nullptr );
		device->SetFVF( D3DFVF_XYZRHW | D3DFVF_DIFFUSE );
		device->SetRenderState( D3DRS_LIGHTING, FALSE );
		device->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );
		device->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
		device->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
		device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
		device->SetTexture( 0, nullptr );
		device->SetTextureStageState( 0, D3DTSS_COLOROP, D3DTOP_SELECTARG1 );
		device->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_DIFFUSE );
		device->SetTextureStageState( 0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1 );
		device->SetTextureStageState( 0, D3DTSS_ALPHAARG1, D3DTA_DIFFUSE );
	}

	void BoundsPoints( const debugBounds_t & bounds, idVec3 points[8] ) {
		for ( int corner = 0; corner < 8; ++corner ) {
			const idVec3 local(
				bounds.bounds[( corner & 1 ) != 0 ? 1 : 0].x,
				bounds.bounds[( corner & 2 ) != 0 ? 1 : 0].y,
				bounds.bounds[( corner & 4 ) != 0 ? 1 : 0].z );
			points[corner] = bounds.origin + bounds.axis[0] * local.x +
				bounds.axis[1] * local.y + bounds.axis[2] * local.z;
		}
	}
}

void R_DrawBounds( const idBounds & ) {
	// Bounds are submitted through the regular shader-driven debug polygon
	// list.  D3D9 has no Xbox immediate-mode command-buffer equivalent.
}

void idRender::InternalDrawText( const char *, const idVec3 &, float,
		const idVec4 &, const idMat3 &, int ) {
	// The retail glyph path depends on the game font system.  Debug text stays
	// queued in the render world; line, polygon, and bounds tools remain usable
	// in a renderer-only Windows build without taking a UI dependency.
}
void idRender::ShowDebugText() {}
void idRender::ShowDebugLines() {
	IDirect3DDevice9 * const device = rendererD3D9.GetDevice();
	if ( device == nullptr || renderViewObject == nullptr || world == nullptr ) return;
	IDirect3DStateBlock9 * state = nullptr;
	if ( FAILED( device->CreateStateBlock( D3DSBT_ALL, &state ) ) || state == nullptr ) return;
	state->Capture();
	BeginDebugDrawing( device );
	for ( int index = 0; index < world->rb_debugLines.Num(); ++index ) {
		const debugLine_t & line = world->rb_debugLines[index];
		DrawDebugLine( device, *renderViewObject, line.start, line.end,
			line.color, line.depthTest );
	}
	static const int edges[12][2] = {
		{ 0, 1 }, { 0, 2 }, { 0, 4 }, { 1, 3 }, { 1, 5 }, { 2, 3 },
		{ 2, 6 }, { 3, 7 }, { 4, 5 }, { 4, 6 }, { 5, 7 }, { 6, 7 }
	};
	for ( int index = 0; index < world->rb_debugBounds.Num(); ++index ) {
		const debugBounds_t & bounds = world->rb_debugBounds[index];
		idVec3 points[8];
		BoundsPoints( bounds, points );
		for ( const auto & edge : edges )
			DrawDebugLine( device, *renderViewObject, points[edge[0]],
				points[edge[1]], bounds.color, bounds.depthTest );
	}
	state->Apply();
	state->Release();
}
void idRender::ShowDebugPolygons() {
	IDirect3DDevice9 * const device = rendererD3D9.GetDevice();
	if ( device == nullptr || renderViewObject == nullptr || world == nullptr ) return;
	IDirect3DStateBlock9 * state = nullptr;
	if ( FAILED( device->CreateStateBlock( D3DSBT_ALL, &state ) ) || state == nullptr ) return;
	state->Capture();
	BeginDebugDrawing( device );
	for ( int polygonIndex = 0; polygonIndex < world->rb_debugPolygons.Num();
			++polygonIndex ) {
		const debugPolygon_t & polygon = world->rb_debugPolygons[polygonIndex];
		if ( polygon.points.Num() < 3 ) continue;
		std::vector< debugVertex_t > vertices;
		vertices.reserve( static_cast< std::size_t >( polygon.points.Num() ) );
		const D3DCOLOR color = DebugColor( polygon.color );
		bool visible = true;
		for ( int pointIndex = 0; pointIndex < polygon.points.Num(); ++pointIndex ) {
			debugVertex_t vertex;
			if ( !ProjectDebugPoint( *renderViewObject, polygon.points[pointIndex],
					color, vertex ) ) { visible = false; break; }
			vertices.push_back( vertex );
		}
		if ( !visible ) continue;
		SetDebugDepthState( device, polygon.depthTest );
		device->DrawPrimitiveUP( D3DPT_TRIANGLEFAN, polygon.points.Num() - 2,
			vertices.data(), sizeof( debugVertex_t ) );
	}
	state->Apply();
	state->Release();
}
void idRender::ShowTestCubeImage() {}
void idRender::RenderDebugTools_NonPortable() {
	ShowDebugText();
	ShowDebugLines();
	ShowDebugPolygons();
	ShowTestCubeImage();
}
