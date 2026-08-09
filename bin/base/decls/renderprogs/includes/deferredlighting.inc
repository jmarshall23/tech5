
/*
==================================================================================
DEFERRED_LIGHTING

inout float3 color;
in float4 fragmentPosition;
in float4 windowPosition;
in float shadow;
==================================================================================
*/
#template DEFERRED_LIGHTING( color, fragmentPosition, windowPosition, shadow )
{
#if defined( PC ) && !defined( PC_D3D )
	half4 viewDiffuse = texelFetch( $viewDiffuseMap, ivec2( fragmentPosition.xy ), 0 );
	half4 viewNormal = texelFetch( $viewNormalMap, ivec2( fragmentPosition.xy ), 0 ) * 2.0 - 1.0;
#else
	half4 viewDiffuse = tex2D( $viewDiffuseMap, windowPosition.xy );
	half4 viewNormal = tex2D( $viewNormalMap, windowPosition.xy ) * 2.0 - 1.0;
#endif
	half viewSpecular = viewDiffuse.w;
	half viewPower = viewNormal.w;

	half4 globalPosition;
	globalPosition.x = dot4( windowPosition, $windowPosToGlobalX );
	globalPosition.y = dot4( windowPosition, $windowPosToGlobalY );
	globalPosition.z = dot4( windowPosition, $windowPosToGlobalZ );
	globalPosition.w = dot4( windowPosition, $windowPosToGlobalW );

	globalPosition.xyz /= globalPosition.w;

	half3 light;
	{
		float4 lightTexCoord;
		lightTexCoord.x = dot4( windowPosition, $windowPosToProjectedTexS );
		lightTexCoord.y = dot4( windowPosition, $windowPosToProjectedTexT );
		lightTexCoord.z = dot4( windowPosition, $windowPosToProjectedTexR );
		lightTexCoord.w = dot4( windowPosition, $windowPosToProjectedTexQ );

		lightTexCoord.xyz /= lightTexCoord.w;

		half4 lpm = h4tex2D( $lightProjectMap, lightTexCoord.xy );
		half4 lfm = h4tex2D( $lightFalloffMap, float2( lightTexCoord.z, 0.5 ) );

		half3 toLight = normalize( $globalLightOrigin.xyz - globalPosition.xyz );

		light = $lightColor.xyz * lpm.xyz * lfm.xyz;
		light *= _float3( dot3( toLight, viewNormal.xyz ) );
		light *= shadow;
	}

	half3 diffuse;
	{
		diffuse = viewDiffuse.xyz * $newDiffuseScale.xyz * 2.0;
	}

	half3 specular;
	{
		half3 toViewer = normalize( $globalViewOrigin.xyz - globalPosition.xyz );

		// The reflection vector = 2 * N * ( N . V ) - V
		half4 reflection;
		reflection.xyz = ( 2.0 * viewNormal.xyz * dot3( viewNormal.xyz, toViewer ) ) - toViewer;

		// Power factor is stored as 0.0 - 1.0 while we want a 0 | 1 | 2 | 3 mip value.
		// The artists really prefer white to be shiny instead of dull, so invert it here.
		// We could probably skip the floor, but I am wary of hardware / api rounding.
		reflection.w = floor( ( 1.0 - viewPower ) * 4.0 + $newPowerScale.x );

		half3 envColor = texCUBElod( $dynamicEnvMap, reflection ).xyz;

		specular = envColor * viewSpecular * $newSpecularScale.xyz;
	}

	color.xyz = light * ( diffuse + specular );
}
#endtemplate
