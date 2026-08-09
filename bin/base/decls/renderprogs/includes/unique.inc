
/*
==================================================================================
FETCH_UNIQUE
==================================================================================
*/
#template FETCH_UNIQUE( sampleSpecular, sampleYCoCg, sampleNormal )
{
	float3 physCoord = UniqueVirtualToPhysical( fragment.texcoord0.xy );

#ifdef USE_VIRTUAL_ANISO_FOOTPRINT
	float2 dx = ddx( fragment.texcoord0.xy ) * physCoord.z;
	float2 dy = ddy( fragment.texcoord0.xy ) * physCoord.z;

	sampleSpecular	= texPhys( $physicalUniquePagesMap0, physCoord.xy, dx, dy );
	sampleYCoCg		= texPhys( $physicalUniquePagesMap1, physCoord.xy, dx, dy );
	sampleNormal	= texPhys( $physicalUniquePagesMap2, physCoord.xy, dx, dy );
#else
	sampleSpecular	= h4texPhys( $physicalUniquePagesMap0, physCoord.xy );
	sampleYCoCg		= h4texPhys( $physicalUniquePagesMap1, physCoord.xy );
	sampleNormal	= h4texPhys( $physicalUniquePagesMap2, physCoord.xy );
#endif
}
#endtemplate

/*
==================================================================================
FETCH_UNIQUE_BLEND

uses fragment.texcoord0;
out half4 sampleSpecular;
out half4 sampleYCoCg;
out half4 sampleNormal;
out half2 feedbackTexCoord;
out half morphScale;
==================================================================================
*/
#template FETCH_UNIQUE_BLEND( sampleSpecular, sampleYCoCg, sampleNormal, feedbackTexCoord, morphScale )
{
	float4 texCoord = fragment.texcoord0;

	float3 physCoord = UniqueVirtualToPhysical( texCoord.xy );

#ifdef USE_VIRTUAL_ANISO_FOOTPRINT
	float2 dx = ddx( texCoord.xy ) * physCoord.z;
	float2 dy = ddy( texCoord.xy ) * physCoord.z;

	sampleSpecular	= texPhys( $physicalUniquePagesMap0, physCoord.xy, dx, dy );
	sampleYCoCg		= texPhys( $physicalUniquePagesMap1, physCoord.xy, dx, dy );
	sampleNormal	= texPhys( $physicalUniquePagesMap2, physCoord.xy, dx, dy );
#else
	sampleSpecular	= texPhys( $physicalUniquePagesMap0, physCoord.xy );
	sampleYCoCg		= texPhys( $physicalUniquePagesMap1, physCoord.xy );
	sampleNormal	= texPhys( $physicalUniquePagesMap2, physCoord.xy );
#endif

	feedbackTexCoord = texCoord.xy;

	/* blend in another texture based on the morph map */
	{
		float3 physCoord = UniqueVirtualToPhysical( texCoord.zw );

#ifdef USE_VIRTUAL_ANISO_FOOTPRINT
		float2 dx = ddx( texCoord.zw ) * physCoord.z;
		float2 dy = ddy( texCoord.zw ) * physCoord.z;

		float4 sampleSpecular2 =	texPhys( $physicalUniquePagesMap0, physCoord.xy, dx, dy );
		float4 sampleYCoCg2 =		texPhys( $physicalUniquePagesMap1, physCoord.xy, dx, dy );
		float4 sampleNormal2 =		texPhys( $physicalUniquePagesMap2, physCoord.xy, dx, dy );
#else
		float4 sampleSpecular2 =	texPhys( $physicalUniquePagesMap0, physCoord.xy );
		float4 sampleYCoCg2 =		texPhys( $physicalUniquePagesMap1, physCoord.xy );
		float4 sampleNormal2 =		texPhys( $physicalUniquePagesMap2, physCoord.xy );
#endif

		sampleSpecular = lerp( sampleSpecular, sampleSpecular2, morphScale );
		sampleYCoCg = lerp( sampleYCoCg, sampleYCoCg2, morphScale );
		sampleNormal = lerp( sampleNormal, sampleNormal2, morphScale );

		float2 fp = fragment.position.xy * $positionToFeedback.zw;
		float2 xy = frac( fp ) - 0.5;
		feedbackTexCoord = ( xy.x * xy.y < 0.0 ) ? texCoord.xy : texCoord.zw;
	}
}
#endtemplate


/*
==================================================================================
FETCH_UNIQUE_YCOCG
==================================================================================
*/
#template FETCH_UNIQUE_YCOCG( sampleYCoCg )
{
	float3 physCoord = UniqueVirtualToPhysical( fragment.texcoord0.xy );

#ifdef USE_VIRTUAL_ANISO_FOOTPRINT
	float2 dx = ddx( fragment.texcoord0.xy ) * physCoord.z;
	float2 dy = ddy( fragment.texcoord0.xy ) * physCoord.z;

	sampleYCoCg = texPhys( $physicalUniquePagesMap1, physCoord.xy, dx, dy );
#else
	sampleYCoCg = texPhys( $physicalUniquePagesMap1, physCoord.xy );
#endif
}
#endtemplate

/*
==================================================================================
FETCH_DIFFUSE_ONLY
==================================================================================
*/
#template FETCH_DIFFUSE_ONLY( sampleYCoCg )
{
	float3 physCoord = UniqueDiffuseOnlyVirtualToPhysical( fragment.texcoord0.xy );

#ifdef USE_VIRTUAL_ANISO_FOOTPRINT
	float2 dx = ddx( fragment.texcoord0.xy ) * physCoord.z;
	float2 dy = ddy( fragment.texcoord0.xy ) * physCoord.z;

	sampleYCoCg = texPhys( $physicalUniqueDiffuseOnlyPagesMap1, physCoord.xy, dx, dy );
#else
	sampleYCoCg = texPhys( $physicalUniqueDiffuseOnlyPagesMap1, physCoord.xy );
#endif
}
#endtemplate

/*
==================================================================================
FETCH_DIFFUSE_ONLY2
==================================================================================
*/
#template FETCH_DIFFUSE_ONLY2( sampleYCoCg )
{
	float3 physCoord = UniqueDiffuseOnly2VirtualToPhysical( fragment.texcoord0.xy );

#ifdef USE_VIRTUAL_ANISO_FOOTPRINT
	float2 dx = ddx( fragment.texcoord0.xy ) * physCoord.z;
	float2 dy = ddy( fragment.texcoord0.xy ) * physCoord.z;

	sampleYCoCg = texPhys( $physicalUniqueDiffuseOnly2PagesMap1, physCoord.xy, dx, dy );
#else
	sampleYCoCg = texPhys( $physicalUniqueDiffuseOnly2PagesMap1, physCoord.xy );
#endif
}
#endtemplate

/*
==================================================================================
CALC_DIFFUSE_RGB
==================================================================================
*/
#template CALC_DIFFUSE_RGB( diffuse, sampleYCoCg )
{
	sampleYCoCg.z = ( sampleYCoCg.z * 31.875 ) + 1.0;	/* z = z * 255.0/8.0 + 1.0 */
	sampleYCoCg.z = 1.0 / sampleYCoCg.z;
	sampleYCoCg.xy *= sampleYCoCg.z;
	diffuse.x = dot4( sampleYCoCg, matrixCoCg1YtoRGB1X );
	diffuse.y = dot4( sampleYCoCg, matrixCoCg1YtoRGB1Y );
	diffuse.z = dot4( sampleYCoCg, matrixCoCg1YtoRGB1Z );
	diffuse.w = 0.5;	// how much to accept dim-shadows

	diffuse.xyz *= $newDiffuseScale.xyz;
}
#endtemplate

/*
==================================================================================
APPLY_SPECULAR
==================================================================================
*/
#template APPLY_SPECULAR( color, sampleSpecular, sampleNormal, localToGlobalX, localToGlobalY, localToGlobalZ, viewOriginToFragment )
{
	/* Note that the optimized derivation of the localNormal below results */
	/* in a vector that is half-unit length! */
	half3 localNormal;
	localNormal.xy = sampleNormal.wy - 0.5;
	localNormal.z = sqrt( abs( dot( localNormal.xy, localNormal.xy ) - 0.25 ) );

	/* transform the normal into ambient map space */
	half3 globalNormal;
	globalNormal.x = dot3( localNormal, localToGlobalX );
	globalNormal.y = dot3( localNormal, localToGlobalY );
	globalNormal.z = dot3( localNormal, localToGlobalZ );
	globalNormal = normalize( globalNormal );

	/* calculate the specular reflection vector from viewer and globalNormal */
	half4 reflection;
	reflection.xyz = viewOriginToFragment - ( globalNormal * dot3( viewOriginToFragment, globalNormal ) * 2.0 );

	/* Power factor is stored in sampleNormal.x as 0.0 - 1.0 */
	/* We want a 0 | 1 | 2 | 3 mip value. */
	/* The artists really prefer white to be shiny instead of dull, so invert it here. */
	/* We could probably skip the floor, but I am wary of hardware / api rounding. */
	reflection.w = floor( ( 1.0 - sampleNormal.x ) * 4.0 + $newPowerScale.x );

	half3 envColor = texCUBElod( $dynamicEnvMap, reflection ).xyz;

	half3 specular = sampleSpecular.xyz * 8.0 / ( sampleNormal.z * 255.0 + 8.0 );

	/* modulate by the environment mask map (specular channel) */
	color.xyz += envColor * specular * $newSpecularScale.xyz;
}
#endtemplate
