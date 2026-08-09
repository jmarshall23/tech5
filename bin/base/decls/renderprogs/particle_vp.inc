
result.position.x = dot4( vertex.position, $mvpMatrixX );
result.position.y = dot4( vertex.position, $mvpMatrixY );
result.position.z = dot4( vertex.position, $mvpMatrixZ );
result.position.w = dot4( vertex.position, $mvpMatrixW );

const float eyeDist = result.position.w;
const float frameFrac = vertex.tangent.z;
const float alphascale = vertex.tangent.w;

// fade particle based on distance to near clip
float fade = saturate( abs( eyeDist ) * $particleFade.x );

const float fogTerm = -( clamp( eyeDist - $fogStart.x, 0.0, $fogEnd.x ) * $fogScale.x );
// moving the fogVal calculation to the vert shader for particles does not appear to cause any artifacts
const float fogVal = saturate( exp2( fogTerm ) );

// Convert back from 16 bit vertex elements.
result.texcoord0.xy = vertex.texcoord0.xy * $particleStScaleBias.x + $particleStScaleBias.y;
result.texcoord0.z = fogVal;
result.texcoord0.w = 0.0;

#ifndef VP_SINGLETEXCOORD
	// Convert back from 16 bit vertex elements.
	result.texcoord1.xy = vertex.texcoord1.xy * $particleStScaleBias.x + $particleStScaleBias.y;
	result.texcoord1.z = frameFrac;
	result.texcoord1.w = 0.0;
#endif

#ifdef VP_UNITTEXCOORD
	result.texcoord2.xy = vertex.tangent.xy;
	result.texcoord2.zw = vertex.tangent.xy;
#endif

float4 vertColor = swizzleColor( vertex.color );
