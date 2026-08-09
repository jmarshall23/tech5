
/*
==================================================================================
SAMPLE_SHADOW_BUFFER_PCF

in float4 shadowTexCoord;
out float shadow;
==================================================================================
*/
#template SAMPLE_SHADOW_BUFFER_PCF( shadow, shadowTexCoord )
{
#if defined( XBOX )
	// The Xbox 360 does not implement percentage-closer-filtering (PCF) in hardware.
	// Instead the following implements bilinear PCF between four point samples.
	float3 texCoord = shadowTexCoord;
	float2 texelXY = texCoord.xy * $shadowBufferResolution.x - _float2( 0.5 );
	float2 floorXY = floor( texelXY );
	float2 fracXY = texelXY - floorXY;

	float step = $shadowBufferResolution.y;
	float2 baseXY = ( floorXY + _float2( 0.5 ) ) * $shadowBufferResolution.y;

	float4 samples;
	samples.x = tex2D( $lightDepthMap, baseXY + float2( 0*step, 0*step ) ).x;
	samples.y = tex2D( $lightDepthMap, baseXY + float2( 1*step, 0*step ) ).x;
	samples.z = tex2D( $lightDepthMap, baseXY + float2( 1*step, 1*step ) ).x;
	samples.w = tex2D( $lightDepthMap, baseXY + float2( 0*step, 1*step ) ).x;

	float4 pcf = float4( greaterThanEqual( ( _float4( 1.0 ) - samples ), texCoord.zzzz ) );

	float4 weights;
	weights.x = ( 1.0 - fracXY.x ) * ( 1.0 - fracXY.y );
	weights.y = (       fracXY.x ) * ( 1.0 - fracXY.y );
	weights.z = (       fracXY.x ) * (       fracXY.y );
	weights.w = ( 1.0 - fracXY.x ) * (       fracXY.y );

	shadow = dot4( pcf, weights );
#else
	shadow = shadow2Ddepth( $lightDepthCompareMap, shadowTexCoord );
#endif
}
#endtemplate

/*
==================================================================================
SAMPLE_SHADOW_BUFFER_4ROOKS_PCF

in float4 shadowTexCoord;
out float shadow;
==================================================================================
*/
#template SAMPLE_SHADOW_BUFFER_4ROOKS_PCF( shadow, shadowTexCoord )
{
	float s = $shadowBufferResolution.y * 2.0;

	float4 shadow4;
	SAMPLE_SHADOW_BUFFER_PCF( shadow4.x, shadowTexCoord.xyz + s * float3( -0.375, -0.125, 0 ) );
	SAMPLE_SHADOW_BUFFER_PCF( shadow4.y, shadowTexCoord.xyz + s * float3( -0.125,  0.375, 0 ) );
	SAMPLE_SHADOW_BUFFER_PCF( shadow4.z, shadowTexCoord.xyz + s * float3(  0.125, -0.375, 0 ) );
	SAMPLE_SHADOW_BUFFER_PCF( shadow4.w, shadowTexCoord.xyz + s * float3(  0.375,  0.125, 0 ) );

	shadow = dot( shadow4, _float4( 0.25 ) );
}
#endtemplate

/*
==================================================================================
SAMPLE_VARIANCE_SHADOW_MAP

in float4 shadowTexCoord;
out float shadow;

$varianceShadowMapSettings.x = minimumVariance
$varianceShadowMapSettings.y = deltaScale
$varianceShadowMapSettings.z = bleedReduction
$varianceShadowMapSettings.w = 1.0 / ( 1.0 - bleedReduction )
==================================================================================
*/
#template SAMPLE_VARIANCE_SHADOW_MAP( shadow, shadowTexCoord )
{
	// Fetch the moments.
	float2 moments = tex2D( $lightDepthVarianceMap, shadowTexCoord.xy ).xy;

	// Compute variance.
	float variance = moments.y - ( moments.x * moments.x );
	variance = max( variance, $varianceShadowMapSettings.x );

	// Compute probabilistic upper bound.
	float d = $varianceShadowMapSettings.y * saturate( shadowTexCoord.z - moments.x );
	float p_max = saturate( variance / ( variance + d * d ) );

	// Remove the [0, bleedReduction] tail and linearly rescale (bleedReduction, 1].
	shadow = saturate( ( p_max - $varianceShadowMapSettings.z ) * $varianceShadowMapSettings.w );
}
#endtemplate

/*
==================================================================================
SAMPLE_POINT_LIGHT_SHADOW

in float4 shadowTexCoord;
out float shadow;
==================================================================================
*/
#template SAMPLE_POINT_LIGHT_SHADOW( shadow, shadowTexCoord )
{
	// calculate the maximum absolute shadow texture coordinate
	float3 absTexCoord = abs( shadowTexCoord.xyz );
	float3 maxTexCoord = max( absTexCoord.xyz, max( absTexCoord.yzx, absTexCoord.zxy ) );

	// create a vector with a 1.0 for the first largest absolute component and 0.0 for the other components
	float4 axis;
	axis.xyz = float3( greaterThanEqual( absTexCoord, maxTexCoord ) );	// set 1.0 for any component equal to the max
	axis.yz = saturate( axis.yz - axis.xx - axis.xy );					// make sure only one component is set to 1.0
	axis.w = 0.0;

	// rotate the shadow texture coordinate from one of the cube sides to the flat shadow buffer
	float4 rotate = axis.yxxy + axis.zwzw;
	float4 flatTexCoord;
	flatTexCoord.x = dot( rotate.xy, shadowTexCoord.xz );
	flatTexCoord.y = dot( rotate.zw, shadowTexCoord.yz );
	flatTexCoord.z = -maxTexCoord.x;
	flatTexCoord.w = shadowTexCoord.w;

	// calculate the bias for the shadow buffer sub-image that corresponds to this axis
	float sBias = 0.5 + dot( axis.xyz, float3( greaterThanEqual( float3( 0, 0, 0 ), shadowTexCoord.xyz ) ) );
	float tBias = 0.5 + dot( axis.xyz, float3( 0, 1, 2 ) );

	float4 faceTexCoord;
	faceTexCoord.x = dot4( flatTexCoord, $shadowProjectionS + sBias * $shadowProjectionQ );
	faceTexCoord.y = dot4( flatTexCoord, $shadowProjectionT + tBias * $shadowProjectionQ );
	faceTexCoord.z = dot4( flatTexCoord, $shadowProjectionR );
	faceTexCoord.w = dot4( flatTexCoord, $shadowProjectionQ );
	faceTexCoord.xyz /= faceTexCoord.w;

	faceTexCoord.xy *= $shadowBufferResolution.z;

	SAMPLE_SHADOW_BUFFER_4ROOKS_PCF( shadow, faceTexCoord );
}
#endtemplate

/*
==================================================================================
SAMPLE_SPOT_LIGHT_SHADOW

in float4 shadowTexCoord;
out float shadow;
==================================================================================
*/
#template SAMPLE_SPOT_LIGHT_SHADOW( shadow, shadowTexCoord )
{
	float3 texCoord = shadowTexCoord.xyz / shadowTexCoord.w;

	SAMPLE_SHADOW_BUFFER_4ROOKS_PCF( shadow, texCoord );
}
#endtemplate

/*
==================================================================================
SAMPLE_PARALLEL_LIGHT_SHADOW

in float4 shadowTexCoord;
in float viewZ;
out float shadow;
==================================================================================
*/
#template SAMPLE_PARALLEL_LIGHT_SHADOW( shadow, shadowTexCoord, viewZ )
{
	float3 texCoord = shadowTexCoord.xyz / shadowTexCoord.w;

	float sliceLOD = log2( max( 1.0, viewZ * $parallelLightSliceScale.x ) ) * $parallelLightSliceScale.z;
	float sliceLODi = floor( sliceLOD );
	float2 slice = min( float2( 3.0, 3.0 ), float2( sliceLODi, sliceLODi ) + float2( 0.0, 1.0 ) );
	float2 stScale = exp2( - slice * $parallelLightSliceScale.y );
	float4 stBias;
	stBias.xy = 0.25 + frac( slice * 0.5 );
	stBias.zw = 0.25 + floor( slice * 0.5 ) * 0.5;
	float4 sliceTexCoords = texCoord.xxyy * stScale.xyxy + stBias;
	float3 slice1TexCoord = float3( sliceTexCoords.x, sliceTexCoords.z, texCoord.z );
	float3 slice2TexCoord = float3( sliceTexCoords.y, sliceTexCoords.w, texCoord.z );
	float fraction = saturate( ( slice.y - sliceLOD ) * $parallelLightSliceScale.w );

	float shadow1;
	SAMPLE_SHADOW_BUFFER_4ROOKS_PCF( shadow1, slice1TexCoord );

	float shadow2;
	SAMPLE_SHADOW_BUFFER_4ROOKS_PCF( shadow2, slice2TexCoord );

	shadow = lerp( shadow2, shadow1, fraction );
}
#endtemplate
