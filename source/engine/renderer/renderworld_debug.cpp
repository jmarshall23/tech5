#include "renderworld_local.h"

#include "idlib/bv/box.h"
#include "idlib/bv/cylinder.h"
#include "idlib/bv/frustum.h"
#include "idlib/bv/sphere.h"
#include "idlib/geometry/winding.h"
#include "idlib/math/curve.h"

#include <algorithm>
#include <cmath>

namespace {

const float PI = 3.14159265358979323846f;

idVec3 TransformPoint( const idVec3 & point, const idVec3 & origin,
		const idMat3 & axis ) {
	return origin + axis[0] * point.x + axis[1] * point.y +
		axis[2] * point.z;
}

void BasisForNormal( idVec3 normal, idVec3 & left, idVec3 & up ) {
	if ( normal.NormalizeFast() == 0.0f ) normal.Set( 0.0f, 0.0f, 1.0f );
	const idVec3 seed = std::fabs( normal.z ) < 0.9f
		? idVec3( 0.0f, 0.0f, 1.0f ) : idVec3( 0.0f, 1.0f, 0.0f );
	left = normal.Cross( seed );
	left.NormalizeFast();
	up = left.Cross( normal );
	up.NormalizeFast();
}

idVec4 AxisColor( const int axis ) {
	return axis == 0 ? idVec4( 1.0f, 0.0f, 0.0f, 1.0f ) :
		axis == 1 ? idVec4( 0.0f, 1.0f, 0.0f, 1.0f ) :
		idVec4( 0.0f, 0.0f, 1.0f, 1.0f );
}

template< typename type >
void AgeList( idList< type, 3 > & list, const int deltaTime ) {
	for ( int index = list.Num() - 1; index >= 0; --index ) {
		if ( list[index].lifeTime <= 0 ) {
			list.RemoveIndex( index );
		} else {
			list[index].lifeTime -= deltaTime;
			if ( list[index].lifeTime <= 0 ) list.RemoveIndex( index );
		}
	}
}

}

void idRenderWorldLocal::DebugClear( const int deltaTime ) {
	if ( deltaTime <= 0 ) {
		rb_debugLines.Clear();
		rb_debugText.Clear();
		rb_debugPolygons.Clear();
		rb_debugBounds.Clear();
		return;
	}
	AgeList( rb_debugLines, deltaTime );
	AgeList( rb_debugText, deltaTime );
	AgeList( rb_debugPolygons, deltaTime );
	AgeList( rb_debugBounds, deltaTime );
}

void idRenderWorldLocal::DebugLine( const idVec4 * color,
		const idVec3 * start, const idVec3 * end, const int lifeTime,
		const bool depthTest ) {
	if ( color == nullptr || start == nullptr || end == nullptr ) return;
	debugLine_t line;
	line.color = *color;
	line.start = *start;
	line.end = *end;
	line.lifeTime = lifeTime;
	line.depthTest = depthTest;
	rb_debugLines.Append( line );
}

void idRenderWorldLocal::DebugArrow( const idVec4 * color,
		const idVec3 * start, const idVec3 * end, const float size,
		const int lifeTime, const bool depthTest ) {
	DebugArrow2( color, start, end, size, lifeTime, depthTest, nullptr );
}

void idRenderWorldLocal::DebugArrow2( const idVec4 * color,
		const idVec3 * start, const idVec3 * end, const float size,
		const int lifeTime, const bool depthTest, const idVec3 * preferredUp ) {
	if ( color == nullptr || start == nullptr || end == nullptr ) return;
	DebugLine( color, start, end, lifeTime, depthTest );
	idVec3 direction = *end - *start;
	if ( direction.NormalizeFast() == 0.0f ) return;
	idVec3 left;
	idVec3 up;
	if ( preferredUp != nullptr ) {
		left = direction.Cross( *preferredUp );
		if ( left.NormalizeFast() == 0.0f ) BasisForNormal( direction, left, up );
		else { up = left.Cross( direction ); up.NormalizeFast(); }
	} else {
		BasisForNormal( direction, left, up );
	}
	const idVec3 base = *end - direction * size;
	const idVec3 points[4] = {
		base + left * ( size * 0.5f ), base - left * ( size * 0.5f ),
		base + up * ( size * 0.5f ), base - up * ( size * 0.5f )
	};
	for ( int index = 0; index < 4; ++index )
		DebugLine( color, end, &points[index], lifeTime, depthTest );
}

void idRenderWorldLocal::DebugArrow3( const idVec4 * color,
		const idVec3 * start, const idVec3 * end, const float size,
		const int lifeTime, const bool depthTest ) {
	DebugArrow2( color, start, end, size, lifeTime, depthTest, nullptr );
}

void idRenderWorldLocal::DebugPyramid( const idVec4 * color,
		const idVec3 * origin, const idVec3 * direction, const idVec3 * up,
		const float nearSize, const float farSize, const int lifeTime,
		const bool depthTest ) {
	if ( color == nullptr || origin == nullptr || direction == nullptr ) return;
	idVec3 forward = *direction;
	const float length = forward.NormalizeFast();
	if ( length == 0.0f ) return;
	idVec3 left;
	idVec3 realUp;
	if ( up != nullptr ) {
		left = forward.Cross( *up );
		left.NormalizeFast();
		realUp = left.Cross( forward );
		realUp.NormalizeFast();
	} else BasisForNormal( forward, left, realUp );
	const idVec3 nearCenter = *origin + forward * nearSize;
	const idVec3 farCenter = *origin + forward * length;
	idVec3 corners[8];
	for ( int corner = 0; corner < 4; ++corner ) {
		const float x = ( corner & 1 ) != 0 ? 1.0f : -1.0f;
		const float y = ( corner & 2 ) != 0 ? 1.0f : -1.0f;
		corners[corner] = nearCenter + left * ( x * nearSize ) +
			realUp * ( y * nearSize );
		corners[4 + corner] = farCenter + left * ( x * farSize ) +
			realUp * ( y * farSize );
	}
	for ( int corner = 0; corner < 4; ++corner ) {
		const int next = ( corner + 1 ) & 3;
		DebugLine( color, &corners[corner], &corners[next], lifeTime, depthTest );
		DebugLine( color, &corners[4 + corner], &corners[4 + next], lifeTime,
			depthTest );
		DebugLine( color, &corners[corner], &corners[4 + corner], lifeTime,
			depthTest );
	}
}

void idRenderWorldLocal::DebugWinding( const idVec4 * color,
		const idWinding * winding, const idVec3 * origin, const idMat3 * axis,
		const int lifeTime, const bool depthTest ) {
	if ( color == nullptr || winding == nullptr || winding->GetNumPoints() < 2 )
		return;
	const idVec3 actualOrigin = origin != nullptr ? *origin :
		idVec3( 0.0f, 0.0f, 0.0f );
	const idMat3 actualAxis = axis != nullptr ? *axis : idMat3( 1.0f );
	for ( int index = 0; index < winding->GetNumPoints(); ++index ) {
		const idVec5 & a5 = ( *winding )[index];
		const idVec5 & b5 = ( *winding )[( index + 1 ) % winding->GetNumPoints()];
		const idVec3 a = TransformPoint( idVec3( a5.x, a5.y, a5.z ),
			actualOrigin, actualAxis );
		const idVec3 b = TransformPoint( idVec3( b5.x, b5.y, b5.z ),
			actualOrigin, actualAxis );
		DebugLine( color, &a, &b, lifeTime, depthTest );
	}
}

void idRenderWorldLocal::DebugCircle( const idVec4 * color,
		const idVec3 * origin, const idVec3 * normal, const float radius,
		const int numSteps, const int lifeTime, const bool depthTest ) {
	if ( color == nullptr || origin == nullptr || normal == nullptr ) return;
	const int steps = std::max( 3, numSteps );
	idVec3 left;
	idVec3 up;
	BasisForNormal( *normal, left, up );
	idVec3 previous = *origin + left * radius;
	for ( int step = 1; step <= steps; ++step ) {
		const float angle = 2.0f * PI * static_cast< float >( step ) /
			static_cast< float >( steps );
		const idVec3 point = *origin + left * ( std::cos( angle ) * radius ) +
			up * ( std::sin( angle ) * radius );
		DebugLine( color, &previous, &point, lifeTime, depthTest );
		previous = point;
	}
}

void idRenderWorldLocal::DebugCylinder( const idVec4 * color,
		const idCylinder * cylinder, const idVec3 * offset, const int numSteps,
		const int lifeTime, const bool depthTest ) {
	if ( color == nullptr || cylinder == nullptr ) return;
	const idVec3 ofs = offset != nullptr ? *offset : idVec3( 0.0f, 0.0f, 0.0f );
	const idVec3 bottom = cylinder->origin + ofs +
		idVec3( 0.0f, 0.0f, -cylinder->halfHeight );
	const idVec3 top = cylinder->origin + ofs +
		idVec3( 0.0f, 0.0f, cylinder->halfHeight );
	const idVec3 normal( 0.0f, 0.0f, 1.0f );
	DebugCircle( color, &bottom, &normal, cylinder->radius, numSteps, lifeTime,
		depthTest );
	DebugCircle( color, &top, &normal, cylinder->radius, numSteps, lifeTime,
		depthTest );
	for ( int side = 0; side < 4; ++side ) {
		const float angle = side * PI * 0.5f;
		const idVec3 a = bottom + idVec3( std::cos( angle ) * cylinder->radius,
			std::sin( angle ) * cylinder->radius, 0.0f );
		const idVec3 b = top + idVec3( std::cos( angle ) * cylinder->radius,
			std::sin( angle ) * cylinder->radius, 0.0f );
		DebugLine( color, &a, &b, lifeTime, depthTest );
	}
}

void idRenderWorldLocal::DebugArc( const idVec4 * color,
		const idVec3 * origin, const idVec3 * normal, const float radius,
		const float startAngle, const float endAngle, const float stepAngle,
		const int lifeTime, const bool depthTest, const bool ) {
	if ( color == nullptr || origin == nullptr || normal == nullptr ) return;
	idVec3 left;
	idVec3 up;
	BasisForNormal( *normal, left, up );
	const float step = std::max( 0.1f, std::fabs( stepAngle ) );
	const int segments = std::max( 1, static_cast< int >(
		std::ceil( std::fabs( endAngle - startAngle ) / step ) ) );
	idVec3 previous;
	for ( int index = 0; index <= segments; ++index ) {
		const float fraction = static_cast< float >( index ) / segments;
		const float angle = ( startAngle + ( endAngle - startAngle ) * fraction ) *
			( PI / 180.0f );
		const idVec3 point = *origin + left * ( std::cos( angle ) * radius ) +
			up * ( std::sin( angle ) * radius );
		if ( index > 0 ) DebugLine( color, &previous, &point, lifeTime, depthTest );
		previous = point;
	}
}

void idRenderWorldLocal::DebugShadedArc( const idVec4 * color,
		const idVec3 * origin, const idVec3 * normal, const idVec3 *,
		const float radius, const float startAngle, const float endAngle,
		const float stepAngle, const int lifeTime, const bool depthTest ) {
	DebugArc( color, origin, normal, radius, startAngle, endAngle, stepAngle,
		lifeTime, depthTest, false );
}

void idRenderWorldLocal::DebugSphere( const idVec4 * color,
		const idSphere * sphere, const int numSteps, const int lifeTime,
		const bool depthTest ) {
	if ( color == nullptr || sphere == nullptr ) return;
	const idVec3 normals[3] = { idVec3( 1.0f, 0.0f, 0.0f ),
		idVec3( 0.0f, 1.0f, 0.0f ), idVec3( 0.0f, 0.0f, 1.0f ) };
	for ( int axis = 0; axis < 3; ++axis ) DebugCircle( color,
		&sphere->origin, &normals[axis], sphere->radius, numSteps, lifeTime,
		depthTest );
}

void idRenderWorldLocal::DebugBounds( const idVec4 * color,
		const idBounds * bounds, const idVec3 * origin, const int lifeTime,
		const bool depthTest ) {
	const idMat3 axis( 1.0f );
	DebugOrientedBounds( color, bounds, origin, &axis, lifeTime, depthTest );
}

void idRenderWorldLocal::DebugOrientedBounds( const idVec4 * color,
		const idBounds * bounds, const idVec3 * origin, const idMat3 * axis,
		const int lifeTime, const bool depthTest ) {
	if ( color == nullptr || bounds == nullptr ) return;
	const idVec3 actualOrigin = origin != nullptr ? *origin :
		idVec3( 0.0f, 0.0f, 0.0f );
	const idMat3 actualAxis = axis != nullptr ? *axis : idMat3( 1.0f );
	idVec3 points[8];
	for ( int corner = 0; corner < 8; ++corner ) {
		const idVec3 local( ( *bounds )[( corner & 1 ) != 0 ? 1 : 0].x,
			( *bounds )[( corner & 2 ) != 0 ? 1 : 0].y,
			( *bounds )[( corner & 4 ) != 0 ? 1 : 0].z );
		points[corner] = TransformPoint( local, actualOrigin, actualAxis );
	}
	for ( int corner = 0; corner < 8; ++corner ) {
		for ( int bit = 0; bit < 3; ++bit ) {
			const int other = corner ^ ( 1 << bit );
			if ( corner < other ) DebugLine( color, &points[corner], &points[other],
				lifeTime, depthTest );
		}
	}
}

void idRenderWorldLocal::DebugBox( const idVec4 * color, const idBox * box,
		const int lifeTime, const bool depthTest ) {
	if ( box == nullptr ) return;
	idBounds bounds;
	bounds[0] = -box->extents;
	bounds[1] = box->extents;
	DebugOrientedBounds( color, &bounds, &box->center, &box->axis, lifeTime,
		depthTest );
}

void idRenderWorldLocal::DebugFrustum( const idVec4 * color,
		const idFrustum * frustum, const bool depthTest, const int lifeTime ) {
	if ( color == nullptr || frustum == nullptr ) return;
	idVec3 points[8];
	frustum->ToPoints( points );
	for ( int corner = 0; corner < 4; ++corner ) {
		const int next = ( corner + 1 ) & 3;
		DebugLine( color, &points[corner], &points[next], lifeTime, depthTest );
		DebugLine( color, &points[4 + corner], &points[4 + next], lifeTime,
			depthTest );
		DebugLine( color, &points[corner], &points[4 + corner], lifeTime,
			depthTest );
	}
}

void idRenderWorldLocal::DebugCone( const idVec4 * color,
		const idVec3 * apex, const idVec3 * direction, const float radius,
		const int lifeTime, const bool depthTest ) {
	DebugCone_2( color, apex, direction, radius, radius, lifeTime, depthTest );
}

void idRenderWorldLocal::DebugCone_2( const idVec4 * color,
		const idVec3 * apex, const idVec3 * direction, const float radius,
		const float arrowSize, const int lifeTime, const bool depthTest ) {
	if ( color == nullptr || apex == nullptr || direction == nullptr ) return;
	idVec3 normal = *direction;
	const float length = normal.NormalizeFast();
	if ( length == 0.0f ) return;
	const idVec3 base = *apex + *direction;
	DebugCircle( color, &base, &normal, radius, 16, lifeTime, depthTest );
	idVec3 left;
	idVec3 up;
	BasisForNormal( normal, left, up );
	const idVec3 rim[4] = { base + left * radius, base - left * radius,
		base + up * radius, base - up * radius };
	for ( int index = 0; index < 4; ++index )
		DebugLine( color, apex, &rim[index], lifeTime, depthTest );
	if ( arrowSize > 0.0f ) DebugArrow( color, apex, &base, arrowSize,
		lifeTime, depthTest );
}

void idRenderWorldLocal::DebugAxis( const idVec4 * color,
		const idVec3 * origin, const idMat3 * axis, const int lifeTime,
		const bool depthTest ) {
	if ( color == nullptr || origin == nullptr || axis == nullptr ) return;
	for ( int index = 0; index < 3; ++index ) {
		const idVec3 end = *origin + ( *axis )[index] * 16.0f;
		DebugArrow( color, origin, &end, 2.0f, lifeTime, depthTest );
	}
}

void idRenderWorldLocal::DebugAxis_2( const idVec3 * origin,
		const idMat3 * axis, const int lifeTime, const bool depthTest ) {
	if ( origin == nullptr || axis == nullptr ) return;
	for ( int index = 0; index < 3; ++index ) {
		const idVec4 color = AxisColor( index );
		const idVec3 end = *origin + ( *axis )[index] * 16.0f;
		DebugArrow( &color, origin, &end, 2.0f, lifeTime, depthTest );
	}
}

void idRenderWorldLocal::DebugAxisScaled( const idVec3 * origin,
		const idMat3 * axis, const float scale, const int lifeTime,
		const bool depthTest ) {
	if ( origin == nullptr || axis == nullptr ) return;
	for ( int index = 0; index < 3; ++index ) {
		const idVec4 color = AxisColor( index );
		const idVec3 end = *origin + ( *axis )[index] * scale;
		DebugArrow( &color, origin, &end, scale * 0.125f, lifeTime, depthTest );
	}
}

void idRenderWorldLocal::DebugPoint( const idVec4 * color,
		const idVec3 * point, const int lifeTime, const bool depthTest ) {
	if ( color == nullptr || point == nullptr ) return;
	for ( int axis = 0; axis < 3; ++axis ) {
		idVec3 a = *point;
		idVec3 b = *point;
		a[axis] -= 2.0f;
		b[axis] += 2.0f;
		DebugLine( color, &a, &b, lifeTime, depthTest );
	}
}

void idRenderWorldLocal::DebugFilledPolygon( const idVec4 * color,
		const idWinding * winding, const int lifeTime, const bool depthTest ) {
	if ( color == nullptr || winding == nullptr ) return;
	debugPolygon_t polygon;
	polygon.color = *color;
	polygon.lifeTime = lifeTime;
	polygon.depthTest = depthTest;
	for ( int index = 0; index < winding->GetNumPoints(); ++index ) {
		const idVec5 & point = ( *winding )[index];
		polygon.points.Append( idVec3( point.x, point.y, point.z ) );
	}
	rb_debugPolygons.Append( polygon );
}

void idRenderWorldLocal::DebugFilledBounds( const idVec4 * color,
		const idBounds * bounds, const idVec3 * origin, const int lifeTime,
		const bool depthTest ) {
	if ( color == nullptr || bounds == nullptr ) return;
	debugBounds_t item;
	item.color = *color;
	item.bounds = *bounds;
	item.origin = origin != nullptr ? *origin : idVec3( 0.0f, 0.0f, 0.0f );
	item.axis = idMat3( 1.0f );
	item.lifeTime = lifeTime;
	item.depthTest = depthTest;
	item.filled = true;
	rb_debugBounds.Append( item );
}

void idRenderWorldLocal::DebugText( const char * text,
		const idVec3 * origin, const float scale, const idVec4 * color,
		const int align, const int lifeTime, const bool depthTest,
		const bool fixedWidth ) {
	const idMat3 axis( 1.0f );
	DebugText_2( text, origin, scale, color, &axis, align, lifeTime, depthTest,
		fixedWidth );
}

void idRenderWorldLocal::DebugText_2( const char * text,
		const idVec3 * origin, const float scale, const idVec4 * color,
		const idMat3 * axis, const int align, const int lifeTime,
		const bool depthTest, const bool fixedWidth ) {
	if ( text == nullptr || origin == nullptr || color == nullptr ) return;
	debugText_t item;
	item.text = text;
	item.origin = *origin;
	item.scale = scale;
	item.color = *color;
	item.viewAxis = axis != nullptr ? *axis : idMat3( 1.0f );
	item.align = align;
	item.lifeTime = lifeTime;
	item.depthTest = depthTest;
	item.fixedWidth = fixedWidth;
	rb_debugText.Append( item );
}

void idRenderWorldLocal::DebugSpline( const idVec4 * color,
		idCurve_Spline< idVec3 > * spline, float, bool, const int lifeTime,
		const bool depthTest ) {
	if ( color == nullptr || spline == nullptr ) return;
	for ( int index = 1; index < spline->GetNumValues(); ++index ) {
		const idVec3 & a = spline->GetValue( index - 1 );
		const idVec3 & b = spline->GetValue( index );
		DebugLine( color, &a, &b, lifeTime, depthTest );
	}
}
