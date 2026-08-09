
/*
==================================================================================
CALC_POSITION_AUTOSPRITE1
==================================================================================
*/
#template CALC_POSITION_AUTOSPRITE1( resultPosition, midpoint, viewLeft, viewUp, tangent )
{
	// Normals and tangents are stored as unsigned bytes - need to expand back to [-1,1] range
	float3 parms = tangent;
	parms.yz = parms.yz * 2.0 - 1.0;

	float radius = parms.x * 255.0;
	float signLeft = parms.y;
	float signUp = parms.z;

	float3 scaledLeft = normalize( viewLeft ) * radius;
	float3 scaledUp = normalize( viewUp ) * radius;
	resultPosition = ( midpoint + ( signLeft * scaledLeft ) + ( signUp * scaledUp ) );
}
#endtemplate

/*
==================================================================================
CALC_POSITION_AUTOSPRITE1
==================================================================================
*/
#template CALC_POSITION_AUTOSPRITE2( resultPosition, viewOrg, midpoint, majorAxis, sign, edgeLen )
{
	// Normals and tangents are stored as unsigned bytes - need to expand back to [-1,1] range
	float s = sign * 2.0 - 1.0;
	float3 axis = majorAxis * 2.0 - 1.0;

	float len = edgeLen * 255.0 * s;
	float3 dir = normalize( midpoint - viewOrg );
	float3 minor = cross( axis, dir );
	resultPosition = ( midpoint + len * minor );
}
#endtemplate
