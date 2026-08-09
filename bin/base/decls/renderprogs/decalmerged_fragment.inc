
	// Use the screen pos and the depth buffer value at this location to compute the local
	// position within the decal box

	float3 window;
	window.xy = screenPosToTexcoord( fragment.position.xy, $renderPositionToViewTexture );

	// fetch the window space depth value
//#ifndef PS3
	window.z = tex2Ddepth( $viewDepthMap, window.xy );
//#else
//		// This depth reconstruct fixes the decal artifacts on the ps3
//
//		half4 dt = h4tex2D( $viewDepthMap, window.xy );
//		float4 d4;
//		d4.w = floor( dt.w * half( 255.0 + 1.0 / 256.0 ) + 0.1 ) / 256;
//		d4.x = floor( dt.x * half( 255.0 + 1.0 / 256.0 ) + 0.1 ) / 256 / 256;
//		d4.y = floor( dt.y * half( 255.0 + 1.0 / 256.0 ) + 0.1 ) / 256 / 256 / 256;
//		const float depth = ( d4.w + d4.x + d4.y );
//		window.z = depth;
//#endif

	float4 wclip = float4( window.xyz, 1.0 );

	// transform to global space
	float4 worldPos;
	worldPos.x = dot( wclip, $decalPosToLocalBoxSpaceX );
	worldPos.y = dot( wclip, $decalPosToLocalBoxSpaceY );
	worldPos.z = dot( wclip, $decalPosToLocalBoxSpaceZ );
	worldPos.w = dot( wclip, $decalPosToLocalBoxSpaceW );
	worldPos /= worldPos.w;

	// transform to local space of box

	float3 center = fragment.texcoord4.xyz;

	// translate to origin of box
	worldPos.xyz -= center;

	// rotate
	float3 tangent = normalize( fragment.texcoord1.xyz );
	float3 bitangent = normalize( fragment.texcoord2.xyz );
	float3 normal = normalize( fragment.texcoord3.xyz );

	float3 localPos = worldPos.xyz;
	localPos.x = dot3( worldPos, tangent );
	localPos.y = dot3( worldPos, bitangent );
	localPos.z = dot3( worldPos, normal );

	// scale back down to [-1,1]
	float3 sizes = fragment.color.xyz;
	localPos.xyz *= sizes;

	// Use the local space pos to construct the texture coordinates for lookup into the decal texture
	float3 tc = saturate( ( localPos * 0.5 ) + 0.5 );
	tc.x = 1.0 - tc.x;

	// To prevent edge filtering bleed-through, apply an 8-texel inset to the texcoords (for 3 mip levels)
	float4 inset;
	inset.xy = 8.0 / float2( fragment.texcoord0.y * $transSortAtlasDim.x, fragment.texcoord0.w * $transSortAtlasDim.y );
	inset.zw = _float2( 0.0 );

	clip( min( tc.xyzx - inset, _float4( 1.0 ) - ( tc.xyzx + inset ) ) );

	// GK: Test performing the divide by w after clip
	//clip( min( extrudePos.w + extrudePos.xyzx, extrudePos.w - extrudePos.xyzx ) );

	float edgefade = 1.0;
#if 1 //ndef PC
	// spherical edge fade test
	float dist = dot( localPos, localPos );
	dist = pow( dist, 4.0 );
	edgefade = 1.0 - dist;
//		result.color = edgefade;
//		result.color.w = 1;
//		return;
#else
	// TODO: Test on consoles
	// Fade out decals so they don't draw on perpendicular surfaces
	float3 surfNormal = normal;
	float3 texelNormal = normalize( cross( ddx( worldPos.xyz ), ddy( worldPos.xyz ) ) );
	float angleDot = dot3( surfNormal, texelNormal );
	clip( angleDot - 0.7 );
#endif

//#if 1
	// texcoord0 has the scale/bias into the image atlas
	float2 texcoord;
	texcoord.x = tc.x * fragment.texcoord0.y + fragment.texcoord0.x;
	texcoord.y = tc.y * fragment.texcoord0.w + fragment.texcoord0.z;

	//half fog = saturate( exp2( fragment.texcoord4.w ) );
	half fog = fragment.texcoord4.w;

	// Just want the texcoords, the rest of the shader will determin what to do with them

//	half4 final = tex2D( $transMap, texcoord );
//	final.w *= fragment.color.w;			// fade based on time
//	final.w *= edgefade;					// apply edge fade
//#else
//	half4 final;
//	final.xy = tc.xy;
//	final.z = 0.0;
//	final.w = 1.0;
//#endif