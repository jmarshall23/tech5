
/*
==================================================================================
CALC_GORE_VERTEX
==================================================================================
*/
#template CALC_GORE_VERTEX( woundPos1, woundPos2 )
{
	// Convert back from 16 bit vertex elements.
	float4 vertexPos = vertex.position * $vertexXYZScale + $vertexXYZBias;

	float3 wound1LocalPos = $wound1Pos.xyz - vertexPos.xyz;
	float3 wound1LocalSpace;

	wound1LocalSpace.x = dot( $wound1dirX.xyz, wound1LocalPos.xyz );
	wound1LocalSpace.y = dot( $wound1dirY.xyz, wound1LocalPos.xyz );
	wound1LocalSpace.z = dot( $wound1dirZ.xyz, wound1LocalPos.xyz );
	float3 wound1Local = wound1LocalSpace / $wound1Size.xyz;
	woundPos1.xy = wound1Local.xy + _float2( 0.5 );
	woundPos1.z = 1.0 - abs( wound1Local.z );
	woundPos1.w = 0.0;

	float wound3A = ( length( ( $wound3PosA.xyz - vertexPos.xyz ) * $wound3PosA.w ) - 1.0f );
	float wound3B = ( length( ( $wound3PosB.xyz - vertexPos.xyz ) * $wound3PosB.w ) - 1.0f );
	float wound3C = ( length( ( $wound3PosC.xyz - vertexPos.xyz ) * $wound3PosC.w ) - 1.0f );
	float wound3D = ( length( ( $wound3PosD.xyz - vertexPos.xyz ) * $wound3PosD.w ) - 1.0f );
	float wound3E = ( length( ( $wound3PosE.xyz - vertexPos.xyz ) * $wound3PosE.w ) - 1.0f );

	woundPos2.w = min( wound3A, wound3B );
	woundPos2.w = min( woundPos2.w, wound3C );
	woundPos2.w = min( woundPos2.w, wound3D );
	woundPos2.w = min( woundPos2.w, wound3E );

	float maskInfo = saturate( 1.0f - ( woundPos2.w * 0.2 ) );
	maskInfo *= maskInfo * maskInfo;
}
#endtemplate

/*
==================================================================================
OCCLUDER_GORE_CLIP
==================================================================================
*/
#template OCCLUDER_GORE_CLIP( woundPos1, woundPos2 )
{
	// gore wound 1
	half4 woundMap1 = tex2D( $woundTexture, saturate( woundPos1.xy ) );
	woundMap1 *= $wound1RGBA;
	woundMap1 = woundMap1.xxxx + woundMap1.yyyy + woundMap1.zzzz + woundMap1.wwww;
	woundMap1 = 1.0 - ( 1.0 - woundMap1 ) * ( saturate( woundPos1.z * half4( 1.0, 1.0 ,1.0 , 5.0 ) ) ) * $wound1Size.w;
	woundMap1.x = saturate( ( woundMap1.x - 0.25 ) * 1.33 );

	// gore wound 2
	half4 woundMap2 = tex2D( $woundTexture, saturate( woundPos2.xy ) );
	woundMap2 *= $wound2RGBA;
	woundMap2 = woundMap2.xxxx + woundMap2.yyyy + woundMap2.zzzz + woundMap2.wwww;
	woundMap2 = 1.0 - ( 1.0 - woundMap2 ) * ( saturate( woundPos2.z * half4( 1.0 , 1.0 ,1.0 ,5.0 ) ) ) * $wound2Size.w; // Photoshop screen blend
	woundMap2.x = saturate( ( woundMap2.x - 0.25 ) * 1.33 );

	// gore decal texture
//	half4 woundMap3 = tex2D( $woundTexture, fragment.htexcoord0.xy * 2.0 ).wwww;
//	woundMap3.xyz = woundMap3.xyz + _half3( 1.0 - woundPos1.w ) - _half3( woundPos1.w );
//	woundMap3.w = saturate( ( 1.0 - ( 1.0 - woundMap3.w ) * 0.2 ) - woundPos1.w );
//	float woundMask = min( min ( woundMap1.w, woundMap2.w ), woundMap3.w );

	float woundMask = min( woundMap1.w, woundMap2.w );
	woundMask = 1.0 -( ( 1.0 - woundMask ) * $woundClip.x );

	clip( woundMask - 0.2 );
}
#endtemplate

/*
==================================================================================
APPLY_GORE_WOUNDS
==================================================================================
*/
#template APPLY_GORE_WOUNDS( diffuse, woundPos1, woundPos2, specularScale, skinMap )
{
	// gore wound 1
	half4 woundMap1 = tex2D( $woundClipTexture, saturate( woundPos1.xy ) );
	woundMap1 *= $wound1RGBA;
	woundMap1 = woundMap1.xxxx + woundMap1.yyyy + woundMap1.zzzz + woundMap1.wwww;
	woundMap1 = 1.0f - ( 1.0f - woundMap1 ) * ( saturate( woundPos1.z * half4( 1.0f, 1.0f, 1.0f, 5.0f ) ) ) * $wound1Size.w;
	woundMap1.x = saturate( ( woundMap1.x - 0.25 ) * 1.33 );
	
	// gore decal texture
	half4 woundMap3 = tex2D( $woundClipTexture, fragment.htexcoord7.xy ).wwww;
	woundMap3.xyz = woundMap3.xyz + _half3( 1.0 - woundPos2.w ) - _half3( woundPos2.w );
	woundMap3.w = woundPos2.w + ( woundMap3.w - 0.5f ) * 0.1f;
	float woundMask = min ( woundMap1.w, woundMap3.w );
	woundMask = 1.0f - ( ( 1.0f - woundMask ) * $woundClip.x );
	
	clip( woundMask - 0.2f );

	half3 woundComp = woundMap3.xyz;
	woundComp = min( woundComp, woundMap1.xxx );
	woundComp = saturate( woundComp );

	// now just color the grayscale image by our chosen blood color - right now hardcoded to ( 0.3, 0.2, 0.1 );
	woundComp = _float3( 1.0 ) - ( ( _float3( 1.0 ) - woundComp ) * ( _float3( 1.0 ) - float3( 0.3, 0.15, 0.1 ) ) );
	woundComp *= woundComp * woundComp;

	// now apply to diffuse - done!
	diffuse.xyz *= woundComp.xyz;
}
#endtemplate

/*
==================================================================================
APPLY_GORE_COLOR
==================================================================================
*/
#template APPLY_GORE_COLOR( inColor )
{
	diffuse.xyz *= _half3( 1.0 ) - ( _half3( inColor ) * half3( 0.7f, 0.85f, 0.9f ) );
}
#endtemplate

/*
==================================================================================
CALC_GORE_CLIP_SPHERES
==================================================================================
*/
#template CALC_GORE_CLIP_SPHERES( clipInfo )
{
	float3 vertexPos = vertex.position.xyz;
	clipInfo = _half4( 0 );
	float wound3A = ( length( ( $wound3PosA.xyz - vertexPos.xyz ) * $wound3PosA.w ) - 1.0f );
	float wound3B = ( length( ( $wound3PosB.xyz - vertexPos.xyz ) * $wound3PosB.w ) - 1.0f );
	float wound3C = ( length( ( $wound3PosC.xyz - vertexPos.xyz ) * $wound3PosC.w ) - 1.0f );
	float wound3D = ( length( ( $wound3PosD.xyz - vertexPos.xyz ) * $wound3PosD.w ) - 1.0f );
	float wound3E = ( length( ( $wound3PosE.xyz - vertexPos.xyz ) * $wound3PosE.w ) - 1.0f );
	float wound3F = ( length( ( $wound3PosF.xyz - vertexPos.xyz ) * $wound3PosF.w ) - 1.0f );
	float wound3G = ( length( ( $wound3PosG.xyz - vertexPos.xyz ) * $wound3PosG.w ) - 1.0f );
	float wound3H = ( length( ( $wound3PosH.xyz - vertexPos.xyz ) * $wound3PosH.w ) - 1.0f );
	float wound3I = ( length( ( $wound3PosI.xyz - vertexPos.xyz ) * $wound3PosI.w ) - 1.0f );
	float wound3J = ( length( ( $wound3PosJ.xyz - vertexPos.xyz ) * $wound3PosJ.w ) - 1.0f );
	
	float3 ellipsoid;
	float3 localPos = vertexPos.xyz - float3( $woundEllipsoidX.w, $woundEllipsoidY.w, $woundEllipsoidZ.w );
	ellipsoid.x = dot( $woundEllipsoidX.xyz, localPos.xyz );
	ellipsoid.y = dot( $woundEllipsoidY.xyz, localPos.xyz );
	ellipsoid.z = dot( $woundEllipsoidZ.xyz, localPos.xyz );
	float distToEllipsoid = length( ellipsoid ) - 1.0f;

	clipInfo.w = min( wound3A, wound3B );
	clipInfo.w = min( clipInfo.w, wound3C );
	clipInfo.w = min( clipInfo.w, wound3D );
	clipInfo.w = min( clipInfo.w, wound3E );
	clipInfo.w = min( clipInfo.w, wound3F );
	clipInfo.w = min( clipInfo.w, wound3G );
	clipInfo.w = min( clipInfo.w, wound3H );
	clipInfo.w = min( clipInfo.w, distToEllipsoid );

	clipInfo.z = min( min( wound3I, wound3J ), clipInfo.w );
}
#endtemplate

/*
==================================================================================
APPLY_GORE_CLIP_SPHERES
==================================================================================
*/
#template APPLY_GORE_CLIP_SPHERES( woundClip, woundMap )
{
	float clipValue = woundClip + ( woundMap.w - 0.5 ) * 0.1;

	//-- dissolve effect
	//if ( $modelFade.x < 1.0f ) {
	//	float4 mask = tex2D( $impDissolveTexture, fragment.texcoord7.xy );
	//	float dissolve = 1.0f - $modelFade.x;
	//	float dMask = mask.x - 0.01 - ( dissolve );
	//	clipValue = min( clipValue, dMask );
	//}
	//-- dissolve effect
	clip( clipValue );
}	
#endtemplate
