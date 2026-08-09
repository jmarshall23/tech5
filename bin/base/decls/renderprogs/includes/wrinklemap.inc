#template SAMPLE_WRINKLEMAPS( occlusionRes, bumpRes, occlusionSrc, bumpSrc, texCoord )
{

	half4 mask01 = tex2D( $fadeMap, float2( texCoord.x * 0.5f, texCoord.y ) );
	half4 mask23 = tex2D( $fadeMap, float2( texCoord.x * 0.5f + 0.5f, texCoord.y ) );

	mask01 = (mask01 - 0.50f)*2.2f;
	float wrinkleResFactor0 = (dot4(saturate(mask01 - 0.05f), $wrinkleFactor0) 
		+ dot4(saturate(-mask01 - 0.05f), $wrinkleFactor1) );
	mask23 = (mask23 - 0.50f)*2.2f;
	float wrinkleResFactor1 = (dot4(saturate(mask23 - 0.05f), $wrinkleFactor2) 
		+ dot4(saturate(-mask23 - 0.05f), $wrinkleFactor3) );
	
	float wrinkleResFactor = clamp( wrinkleResFactor0 + wrinkleResFactor1, -1.0f, 1.0f );
	wrinkleResFactor *= $wrinkleScale.x;
	
	float ambOccl = occlusionSrc.g;
	half4 bumpNormal = bumpSrc;
	// + is expand, - is contract
	if ( wrinkleResFactor > 0.05 ) {
		ambOccl = lerp( occlusionSrc.g, occlusionSrc.b, wrinkleResFactor );
		bumpNormal = lerp( bumpSrc, tex2D( $spareBumpMap2, texCoord.xy ), wrinkleResFactor );
	} else if ( wrinkleResFactor < -0.05 ) {
		ambOccl = lerp( occlusionSrc.g, occlusionSrc.r, -wrinkleResFactor );
		bumpNormal = lerp( bumpSrc, tex2D( $spareBumpMap1, texCoord.xy ), -wrinkleResFactor );
	}
	
	occlusionRes = ambOccl;
	bumpRes = bumpNormal;

}
#endtemplate