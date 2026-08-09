
	// this is normalized window space, not strict openGL window space that uses integer viewport values.
	float4 window;
	window.xy = screenPosToTexcoord( fragment.position.xy, $renderPositionToViewTexture );
	window.z = tex2Ddepth( $viewDepthMap, window.xy );
	window.w = 1.0;

	float4 texcoord;
	texcoord.x = dot4( window, $windowPosToProjectedTexS );
	texcoord.y = dot4( window, $windowPosToProjectedTexT );
	texcoord.z = dot4( window, $windowPosToProjectedTexR );
	texcoord.w = dot4( window, $windowPosToProjectedTexQ );

	texcoord.xyz /= texcoord.w;

	half4 lpm = h4tex2D( $lightProjectMap, texcoord.xy );
	half4 lfm = h4tex2D( $lightFalloffMap, float2( texcoord.z, 0.5 ) );

	half4 color = lpm * lfm * $lightColor;
	color.xyz *= $lightFade.x;
