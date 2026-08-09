
	float2 tc = fragment.texcoord1.xy;

	// To prevent edge filtering bleed-through, apply an 8-texel inset to the texcoords (for 3 mip levels)
	float2 inset;
	inset.xy = 8.0 / float2( fragment.texcoord0.y * $transSortAtlasDim.x, fragment.texcoord0.w * $transSortAtlasDim.y );

	clip( min( tc - inset, _float2( 1.0 ) - ( tc + inset ) ) );

	// texcoord0 has the scale/bias into the image atlas
	float2 texcoord;
	texcoord.x = tc.x * fragment.texcoord0.y + fragment.texcoord0.x;
	texcoord.y = tc.y * fragment.texcoord0.w + fragment.texcoord0.z;

	half fog = saturate( exp2( fragment.texcoord1.w ) );

	half4 final = tex2D( $transMap, texcoord );
	final.w *= fragment.color.w;
