
result.position.x = dot4( vertex.position, $mvpMatrixX );
result.position.y = dot4( vertex.position, $mvpMatrixY );
result.position.z = dot4( vertex.position, $mvpMatrixZ );
result.position.w = dot4( vertex.position, $mvpMatrixW );

const float eyeDist = result.position.w;
const float frameFrac = vertex.tangent.z;
const float alphascale = vertex.tangent.w;
const float4 genericParm = vertex.normal;

// create thickness based on alpha scale
float thickness = ( ( 1.0 - alphascale ) * 127.0 ) / eyeDist;

// fade particle based on distance to near clip and thickness
float fade = saturate( abs( eyeDist ) / ( ( 1.0 - alphascale ) * 127.0 ) );

const float fogTerm = -( clamp( eyeDist - $fogStart.x, 0.0, $fogEnd.x ) * $fogScale.x );
// moving the fogVal calculation to the vert shader for particles does not appear to cause any artifacts
const float fogVal = saturate( exp2( fogTerm ) );

// Convert back from 16 bit vertex elements.
result.texcoord0.xy = vertex.texcoord0.xy * $particleStScaleBias.x + $particleStScaleBias.y;
result.texcoord0.z = fogVal;
result.texcoord0.w = alphascale;

// Convert back from 16 bit vertex elements.
result.texcoord1.xy = vertex.texcoord1.xy * $particleStScaleBias.x + $particleStScaleBias.y;
result.texcoord1.z = frameFrac;
result.texcoord1.w = 0.0;

//result.texcoord2.x = genericParm.x * 10.0 + 1.0;		// color multiply
//result.texcoord2.y = genericParm.y * 10.0 + 1.0;		// alpha multiply
//result.texcoord2.z = 1.0 - genericParm.z;				// color screen
//result.texcoord2.w = genericParm.w;						// 

// pw-note: this works absolutely crap if you have particles locked in certain axes.
//			light streaks will have a fake depth that isn't really correct and end up infront of depth causing flickering
//			Use the 'Depth Offset' in the particle system instead to achive exactly this in a proper way.
// adding half of the alpha scale to create a fake thickness to the particle
// makes particles that are flat against surfaces show up much better, result: need fewer particles.
//result.position.z -= thickness;

#ifdef XBOX
	result.texcoord3 = result.position;
#endif

float4 vertColor = swizzleColor( vertex.color );
