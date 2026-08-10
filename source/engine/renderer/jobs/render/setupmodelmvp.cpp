#include "../../rendermodelcommitted.h"
#include "../../renderview.h"

#include <algorithm>
#include <cmath>

void SetupModelMVPMatrix( idRenderMatrix & mvpMatrix,
		const idRenderModelCommitted * model, const idRenderView * renderView,
		float zNear, float zFar ) {
	if ( model == nullptr || model->r.mvpIsIdentity || renderView == nullptr ) {
		mvpMatrix.Identity();
		return;
	}
	if ( model->r.mvpIsOrthographic ) {
		mvpMatrix.Identity();
		const float width = static_cast< float >(
			std::max( renderView->windowWidth, 1 ) );
		const float height = static_cast< float >(
			std::max( renderView->windowHeight, 1 ) );
		mvpMatrix.m[0] = 2.0f * model->r.scale.x / width;
		mvpMatrix.m[3] = 2.0f * model->r.origin.x / width - 1.0f;
		mvpMatrix.m[5] = -2.0f * model->r.scale.y / height;
		mvpMatrix.m[7] = 1.0f - 2.0f * model->r.origin.y / height;
		mvpMatrix.m[10] = 1.0f;
		return;
	}
	if ( model->r.viewOriented ) {
		idRenderMatrix rotationOnly = renderView->viewMatrix;
		rotationOnly.m[3] = rotationOnly.m[7] = rotationOnly.m[11] = 0.0f;
		idVec4 clip;
		rotationOnly.TransformPoint( model->r.origin, clip );
		renderView->projectionMatrix.TransformPoint( clip, clip );
		const float inverseW = std::fabs( clip.w ) > 1.0e-20f
			? 1.0f / clip.w : 1.0f;
		mvpMatrix.Identity();
		mvpMatrix.m[0] = model->r.scale.x /
			static_cast< float >( std::max( renderView->windowWidth, 1 ) );
		mvpMatrix.m[5] = -model->r.scale.y /
			static_cast< float >( std::max( renderView->windowHeight, 1 ) );
		mvpMatrix.m[3] = clip.x * inverseW;
		mvpMatrix.m[7] = clip.y * inverseW;
		mvpMatrix.m[11] = clip.z >= 0.0f && clip.z <= clip.w
			? 0.9999f : clip.z * inverseW;
		return;
	}

	idRenderMatrix modelView;
	idRenderMatrix::Multiply( renderView->viewMatrix, model->modelMatrix,
		modelView );
	idRenderMatrix projection = renderView->projectionMatrix;
	if ( model->r.fovScale != 1.0f ) {
		if ( renderView->r.cramZNear ) zNear *= 0.25f;
		idRenderMatrix::BuildProjectionFov(
			renderView->r.fov_x * model->r.fovScale,
			renderView->r.fov_y * model->r.fovScale,
			zNear, zFar, 0.0f, 0.0f, projection );
	}
	idRenderMatrix::Multiply( projection, modelView, mvpMatrix );
	if ( model->r.modelDepthHack > 0.0f ) {
		for ( int column = 0; column < 4; ++column )
			mvpMatrix.m[8 + column] *= model->r.modelDepthHack;
	}
}
