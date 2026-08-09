
/*
==================================================================================
INTERACTION_VERTEX

output:
	texcoord 0.xyzw	is the light projection / falloff texture coordinates
	texcoord 1.xy	is the bump / diffuse / specular texture coordinate
	texcoord 2.xyz	is the global vertex position after model matrix transform
	texcoord 3.xyz	is the normal transform 1
	texcoord 4.xyz	is the normal transform 2
	texcoord 5.xyz	is the normal transform 3
	texcoord 6.xyzw	is the shadow buffer coordinates
==================================================================================
*/
#template INTERACTION_VERTEX()
{
	// texture 0 has four texgens for light projection and falloff
	result.texcoord0.x = dot4( position, $lightProjectionS );
	result.texcoord0.y = dot4( position, $lightProjectionT );
	result.texcoord0.z = dot4( position, $lightProjectionR );
	result.texcoord0.w = dot4( position, $lightProjectionQ );

	// Convert back from 16 bit vertex elements.
	float4 texcoord0 = ( vertex.texcoord0.xyxy * $vertexStScaleBias.xyxy + $vertexStScaleBias.zwzw ) + skinOffsets.xyzw;

	// texture 1 takes the base texture coordinates
	result.texcoord1 = texcoord0;

	float4 worldPosition;
	worldPosition.x = dot4( position, $modelMatrixX );
	worldPosition.y = dot4( position, $modelMatrixY );
	worldPosition.z = dot4( position, $modelMatrixZ );
	worldPosition.w = dot4( position, $modelMatrixW );

	// texture 2 takes the global position
	result.texcoord2.x = worldPosition.x;
	result.texcoord2.y = worldPosition.y;
	result.texcoord2.z = worldPosition.z;
	result.texcoord2.w = - dot4( worldPosition, $viewMatrixZ );

	//transform the local space vectors to world space
	result.texcoord3.x = dot3( tangent,   $modelMatrixX );
	result.texcoord3.y = dot3( bitangent, $modelMatrixX );
	result.texcoord3.z = dot3( normal,    $modelMatrixX );
	result.texcoord3.w = 1.0;

	result.texcoord4.x = dot3( tangent,   $modelMatrixY );
	result.texcoord4.y = dot3( bitangent, $modelMatrixY );
	result.texcoord4.z = dot3( normal,    $modelMatrixY );
	result.texcoord4.w = 1.0;

	result.texcoord6.x = dot3( tangent,   $modelMatrixZ );
	result.texcoord6.y = dot3( bitangent, $modelMatrixZ );
	result.texcoord6.z = dot3( normal,    $modelMatrixZ );
	result.texcoord6.w = 1.0;

#ifndef NOSHADOW
	// texcoord 5 has the shadow buffer texcoords
	// transform local space xyz into light space
	result.texcoord5.x = dot4( position, $localToLightS );
	result.texcoord5.y = dot4( position, $localToLightT );
	result.texcoord5.z = dot4( position, $localToLightR );
	result.texcoord5.w = dot4( position, $localToLightQ );
#endif

	// position
	result.position.x = dot4( position, $mvpMatrixX );
	result.position.y = dot4( position, $mvpMatrixY );
	result.position.z = dot4( position, $mvpMatrixZ );
	result.position.w = dot4( position, $mvpMatrixW );
}
#endtemplate

/*
==================================================================================
INTERACTION_FRAGMENT_BASIC

Should the color of the light influence the environment color? probably.

vertex input:
	texcoord 0.xyzw	is the light projection / falloff texture coordinates
	texcoord 1.xy	is the bump / diffuse / specular texture coordinate
	texcoord 2.xyz	is the global vertex position after model matrix transform
	texcoord 3.xyz	is the normal transform 1
	texcoord 4.xyz	is the normal transform 2
	texcoord 5.xyzw	is the shadow buffer coordinates
	texcoord 6.xyz	is the normal transform 3

	in float shadow;

render parms:
	globalViewOrigin
	globalLightOrigin
==================================================================================
*/
#template INTERACTION_FRAGMENT_BASIC( shadow )
{
	//-------- non-wrapping virtual texture lookup ------------
	float2 texcoord = fragment.texcoord1.xy;
	BRANCH if ( $useVirtualMapping.x > 0 ) {
		// this is basically only for non pre-lit levels, and shouldn't be used often.
		// this doesn't attempt to get the derivative correct at the frac crossing point
		texcoord = frac( texcoord ) * $virtualMapping.xy + $virtualMapping.zw;
	}

	float3 physCoord = VmtrVirtualToPhysical( texcoord );

	//---------------------------------------------------------------
	// load the virtual textures
	//---------------------------------------------------------------
#ifdef USE_VIRTUAL_ANISO_FOOTPRINT
	float2 dx = ddx( texcoord.xy ) * physCoord.z;
	float2 dy = ddy( texcoord.xy ) * physCoord.z;

	half4 specularPage = texPhys( $physicalVmtrPagesMap0, physCoord.xy, dx, dy );
	half4 YCoCg = texPhys( $physicalVmtrPagesMap1, physCoord.xy, dx, dy );
	half4 bumpPage = texPhys( $physicalVmtrPagesMap2, physCoord.xy, dx, dy );
#else
	half4 specularPage = texPhys( $physicalVmtrPagesMap0, physCoord.xy );
	half4 YCoCg = texPhys( $physicalVmtrPagesMap1, physCoord.xy );
	half4 bumpPage = texPhys( $physicalVmtrPagesMap2, physCoord.xy );
#endif

	specularPage.xyz = ScaleSpecular( specularPage.xyz, bumpPage.z );
	bumpPage.z = 0;

	//---------------------------------------------------------------
	// derive localNormal, then transform to a global normal
	//---------------------------------------------------------------

	float3 localNormal = float3( ( bumpPage.wy * 2.0 ) - 1.0, 0.0 );

	// derive the localNormal.z component
	localNormal.z = sqrt( abs( 1.0 - dot3( localNormal, localNormal ) ) );

	// transform into global space
	float3 globalNormal;
	globalNormal.x = dot3( localNormal, fragment.htexcoord3 );
	globalNormal.y = dot3( localNormal, fragment.htexcoord4 );
	globalNormal.z = dot3( localNormal, fragment.htexcoord6 );
	globalNormal = normalize( globalNormal );

	//---------------------------------------------------------------
	// normalize the directions to the light and viewer
	//---------------------------------------------------------------
	float3 toLight = normalize( $globalLightOrigin.xyz - fragment.texcoord2.xyz );
	float3 toViewer = normalize( $globalViewOrigin.xyz - fragment.texcoord2.xyz );

	//---------------------------------------------------------------
	// Incoming light color is the product of two light projection
	// texture maps, the light color parameter, the dor with the surface
	// normal, and the faded shadow factor
	// optimize: if we assumed one or both of the light maps are monochrome,
	// we could save some math.
	//---------------------------------------------------------------

	half3 light;
	{
		float3 lightTexCoord = fragment.htexcoord0.xyz / fragment.htexcoord0.w;

		half4 lpm = h4tex2D( $lightProjectMap, lightTexCoord.xy );
		half4 lfm = h4tex2D( $lightFalloffMap, float2( lightTexCoord.z, 0.5 ) );

		light = _float3( dot3( toLight, globalNormal ) );

		// modulate by the light projection and falloff
		light *= lpm.xyz * lfm.xyz;

		// modulate by the light color
		light *= $lightColor.xyz;

		// modulate by the shadow factor adjusted by the shadow fade
		light *= ( shadow * $shadowFade.x ) + $shadowFade.y;
	}

	half3 specular;
	{
#if 0
		//---------------------------------------------------------------
		// calculate the static specular at this point
		//---------------------------------------------------------------

		// reflection vector = 2 * N * ( N . V ) - V
		half3 reflection;
		reflection = ( 2.0 * globalNormal * dot3( globalNormal, toLight ) ) - toLight;

		// Use the absolute value of the dot, so we get static
		// highlights on both sides of objects.  Oh, the horror! :-)
		float specularD = abs( dot3( reflection, $staticSpecularVector ) );

		// power factor is stored in bumpPage.x as 0.0 - 1.0, we want a 0 to 64 scale
		float power = bumpPage.x * 64;

		float specularStrength = $staticSpecularScale.x * pow( specularD, power );

		specular = specularStrength;
#else
		//---------------------------------------------------------------
		// sample envColor from the environment map
		//---------------------------------------------------------------

		// reflection vector = 2 * N * ( N . V ) - V
		half4 reflection;
		reflection.xyz = ( 2.0 * globalNormal * dot3( globalNormal, toViewer ) ) - toViewer;

		// power factor is stored in bumpPage.x as 0.0 - 1.0, we want a 0 | 1 | 2 | 3 mip value
		// we could probably skip the floor, but I am wary of hardware / api rounding
		// the artists really prefer white to be shiny instead of dull, so invert it here
		reflection.w = floor( ( 1.0 - bumpPage.x ) * 4.0 + $newPowerScale.x );

		half3 envColor = texCUBElod( $dynamicEnvMap, reflection ).xyz;

		specular = envColor * specularPage.xyz * $newSpecularScale.xyz;
#endif
	}

	//---------------------------------------------------------------
	// covert the diffuse from YCoCg
	//---------------------------------------------------------------
	half4 diffuse;
	{
		YCoCg.z = ( YCoCg.z * 31.875 ) + 1.0;			//z = z * 255.0/8.0 + 1.0
		YCoCg.z = 1.0 / YCoCg.z;
		YCoCg.xy *= YCoCg.z;
		diffuse.x = dot4( YCoCg, matrixCoCg1YtoRGB1X );
		diffuse.y = dot4( YCoCg, matrixCoCg1YtoRGB1Y );
		diffuse.z = dot4( YCoCg, matrixCoCg1YtoRGB1Z );
		diffuse.w = 1.0;
		diffuse.xyz *= $newDiffuseScale.xyz * 2.0;
	}

	//---------------------------------------------------------------
	// sum everything up
	//---------------------------------------------------------------
	half3 color = light * ( specular + diffuse.xyz );

	result.color.rgb = color;
	result.color.a = 1;
}
#endtemplate

/*
==================================================================================
INTERACTION_FRAGMENT_GRAZING

Should the color of the light influence the environment color? probably.

vertex input:
	texcoord 0.xyzw	is the light projection / falloff texture coordinates
	texcoord 1.xy	is the bump / diffuse / specular texture coordinate
	texcoord 2.xyz	is the global vertex position after model matrix transform
	texcoord 3.xyz	is the normal transform 1
	texcoord 4.xyz	is the normal transform 2
	texcoord 5.xyzw	is the shadow buffer coordinates
	texcoord 6.xyz	is the normal transform 3

	in float shadow;

render parms:
	globalViewOrigin
	globalLightOrigin
==================================================================================
*/
#template INTERACTION_FRAGMENT_GRAZING( shadow )
{
	//-------- non-wrapping virtual texture lookup ------------
	float2 texcoord = fragment.texcoord1.xy;
	BRANCH if ( $useVirtualMapping.x > 0 ) {
		// this is basically only for non pre-lit levels, and shouldn't be used often.
		// this doesn't attempt to get the derivative correct at the frac crossing point
		texcoord = frac( texcoord ) * $virtualMapping.xy + $virtualMapping.zw;
	}

	float3 physCoord = VmtrVirtualToPhysical( texcoord );

	//---------------------------------------------------------------
	// load the virtual textures
	//---------------------------------------------------------------
#ifdef USE_VIRTUAL_ANISO_FOOTPRINT
	float2 dx = ddx( texcoord.xy ) * physCoord.z;
	float2 dy = ddy( texcoord.xy ) * physCoord.z;

	half4 specularPage = texPhys( $physicalVmtrPagesMap0, physCoord.xy, dx, dy );
	half4 YCoCg = texPhys( $physicalVmtrPagesMap1, physCoord.xy, dx, dy );
	half4 bumpPage = texPhys( $physicalVmtrPagesMap2, physCoord.xy, dx, dy );
#else
	half4 specularPage = texPhys( $physicalVmtrPagesMap0, physCoord.xy );
	half4 YCoCg = texPhys( $physicalVmtrPagesMap1, physCoord.xy );
	half4 bumpPage = texPhys( $physicalVmtrPagesMap2, physCoord.xy );
#endif

	specularPage.xyz = ScaleSpecular( specularPage.xyz, bumpPage.z );
	bumpPage.z = 0;

	//---------------------------------------------------------------
	// derive localNormal, then transform to a global normal
	//---------------------------------------------------------------

	float3 localNormal = float3( ( bumpPage.wy * 2.0 ) - 1.0, 0.0 );

	// derive the localNormal.z component
	localNormal.z = sqrt( abs( 1.0 - dot3( localNormal, localNormal ) ) );

	// transform into global space
	float3 globalNormal;
	globalNormal.x = dot3( localNormal, fragment.htexcoord3 );
	globalNormal.y = dot3( localNormal, fragment.htexcoord4 );
	globalNormal.z = dot3( localNormal, fragment.htexcoord6 );
	globalNormal = normalize( globalNormal );

	//---------------------------------------------------------------
	// normalize the directions to the light and viewer
	//---------------------------------------------------------------
	float3 toLight = normalize( $globalLightOrigin.xyz - fragment.texcoord2.xyz );
	float3 toViewer = normalize( $globalViewOrigin.xyz - fragment.texcoord2.xyz );

	//---------------------------------------------------------------
	// Incoming light color is the product of two light projection
	// texture maps, the light color parameter, the dor with the surface
	// normal, and the faded shadow factor
	// optimize: if we assumed one or both of the light maps are monochrome,
	// we could save some math.
	//---------------------------------------------------------------

	half3 light;
	{
		float3 lightTexCoord = fragment.htexcoord0.xyz / fragment.htexcoord0.w;

		half4 lpm = h4tex2D( $lightProjectMap, lightTexCoord.xy );
		half4 lfm = h4tex2D( $lightFalloffMap, float2( lightTexCoord.z, 0.5 ) );

		light = _float3( dot3( toLight, globalNormal ) );

		// modulate by the light projection and falloff
		light *= lpm.xyz * lfm.xyz;

		// modulate by the light color
		light *= $lightColor.xyz;

		// modulate by the shadow factor adjusted by the shadow fade
		light *= ( shadow * $shadowFade.x ) + $shadowFade.y;
	}

	half3 specular;
	{
#if 0
		//---------------------------------------------------------------
		// calculate the static specular
		//---------------------------------------------------------------

		// reflection vector = 2 * N * ( N . V ) - V
		half3 reflection;
		reflection = ( 2.0 * globalNormal * dot3( globalNormal, toLight ) ) - toLight;

		// Use the absolute value of the dot, so we get static
		// highlights on both sides of objects.  Oh, the horror! :-)
		float specularD = abs( dot3( reflection, $staticSpecularVector ) );

		// power factor is stored in bumpPage.x as 0.0 - 1.0, we want a 0 to 64 scale
		float power = bumpPage.x * 64;

		float specularStrength = $staticSpecularScale.x * pow( specularD, power );

		specular = specularStrength;
#else
		//---------------------------------------------------------------
		// sample envColor from the environment map
		//---------------------------------------------------------------

		// reflection vector = 2 * N * ( N . V ) - V
		half4 reflection;
		reflection.xyz = ( 2.0 * globalNormal * dot3( globalNormal, toViewer ) ) - toViewer;

		// power factor is stored in bumpPage.x as 0.0 - 1.0, we want a 0 | 1 | 2 | 3 mip value
		// we could probably skip the floor, but I am wary of hardware / api rounding
		// the artists really prefer white to be shiny instead of dull, so invert it here
		reflection.w = floor( ( 1.0 - bumpPage.x ) * 4.0 + $newPowerScale.x );

		half3 envColor = texCUBElod( $dynamicEnvMap, reflection ).xyz;

		specular = envColor * $newSpecularScale.xyz;
#endif
	}

	//---------------------------------------------------------------
	// covert the diffuse from YCoCg
	//---------------------------------------------------------------
	half4 diffuse;
	{
		YCoCg.z = ( YCoCg.z * 31.875 ) + 1.0;			//z = z * 255.0/8.0 + 1.0
		YCoCg.z = 1.0 / YCoCg.z;
		YCoCg.xy *= YCoCg.z;
		diffuse.x = dot4( YCoCg, matrixCoCg1YtoRGB1X );
		diffuse.y = dot4( YCoCg, matrixCoCg1YtoRGB1Y );
		diffuse.z = dot4( YCoCg, matrixCoCg1YtoRGB1Z );
		diffuse.w = 1.0;
	}

	//---------------------------------------------------------------
	// Calculate the light grazing fraction
	//---------------------------------------------------------------

	float graze = dot3( toViewer, globalNormal );
	graze = saturate( ( $viewGraze.x - graze ) / ( $viewGraze.x + 0.0001 ) );

	// The diffuse color will be a lerp between the diffuseMap and grazingDiffuseColor
	// and a modulate by the constant diffuse factor ( automatically scale newDiffuseScale
	// by 2.0 to match the baked-in behavior )
	half3 grazingDiffuse  = lerp( diffuse.xyz,  $grazingDiffuseColor.xyz,  graze );
	half3 grazingSpecular = lerp( specularPage.xyz, $grazingSpecularColor.xyz, graze );

	half3 color = light * ( specular * grazingSpecular + grazingDiffuse * $newDiffuseScale.xyz * 2.0 );

	result.color.rgb = color;
	result.color.a = 1;
}
#endtemplate

/*
==================================================================================
INTERACTION_FRAGMENT_SIMPLE

Should the color of the light influence the environment color? probably.

vertex input:
	texcoord 0.xyzw	is the light projection / falloff texture coordinates
	texcoord 1.xy	is the bump / diffuse / specular texture coordinate
	texcoord 2.xyz	is the global vertex position after model matrix transform
	texcoord 3.xyz	is the normal transform 1
	texcoord 4.xyz	is the normal transform 2
	texcoord 5.xyzw	is the shadow buffer coordinates
	texcoord 6.xyz	is the normal transform 3

	in float shadow;

render parms:
	globalViewOrigin
	globalLightOrigin
==================================================================================
*/
#template INTERACTION_FRAGMENT_SIMPLE( shadow )
{
	//-------- non-wrapping virtual texture lookup ------------
	float2 texcoord = fragment.texcoord1.xy;
	BRANCH if ( $useVirtualMapping.x > 0 ) {
		// this is basically only for non pre-lit levels, and shouldn't be used often.
		// this doesn't attempt to get the derivative correct at the frac crossing point
		texcoord = frac( texcoord ) * $virtualMapping.xy + $virtualMapping.zw;
	}

	float3 physCoord = VmtrVirtualToPhysical( texcoord );

	//---------------------------------------------------------------
	// load the virtual textures
	//---------------------------------------------------------------
#ifdef USE_VIRTUAL_ANISO_FOOTPRINT
	float2 dx = ddx( texcoord.xy ) * physCoord.z;
	float2 dy = ddy( texcoord.xy ) * physCoord.z;

	half4 specularPage = texPhys( $physicalVmtrPagesMap0, physCoord.xy, dx, dy );
	half4 YCoCg = texPhys( $physicalVmtrPagesMap1, physCoord.xy, dx, dy );
	half4 bumpPage = texPhys( $physicalVmtrPagesMap2, physCoord.xy, dx, dy );
#else
	half4 specularPage = texPhys( $physicalVmtrPagesMap0, physCoord.xy );
	half4 YCoCg = texPhys( $physicalVmtrPagesMap1, physCoord.xy );
	half4 bumpPage = texPhys( $physicalVmtrPagesMap2, physCoord.xy );
#endif

	specularPage.xyz = ScaleSpecular( specularPage.xyz, bumpPage.z );
	bumpPage.z = 0;

	//---------------------------------------------------------------
	// derive localNormal, then transform to a global normal
	//---------------------------------------------------------------

	float3 localNormal = float3( ( bumpPage.wy * 2.0 ) - 1.0, 0.0 );

	// derive the localNormal.z component
	localNormal.z = sqrt( abs( 1.0 - dot3( localNormal, localNormal ) ) );

	// transform into global space
	float3 globalNormal;
	globalNormal.x = dot3( localNormal, fragment.htexcoord3 );
	globalNormal.y = dot3( localNormal, fragment.htexcoord4 );
	globalNormal.z = dot3( localNormal, fragment.htexcoord6 );
	globalNormal = normalize( globalNormal );

	//---------------------------------------------------------------
	// normalize the directions to the light and viewer
	//---------------------------------------------------------------
	float3 toLight = normalize( $globalLightOrigin.xyz - fragment.texcoord2.xyz );
	float3 toViewer = normalize( $globalViewOrigin.xyz - fragment.texcoord2.xyz );

	//---------------------------------------------------------------
	// Incoming light color is the product of two light projection
	// texture maps, the light color parameter, the dor with the surface
	// normal, and the faded shadow factor
	// optimize: if we assumed one or both of the light maps are monochrome,
	// we could save some math.
	//---------------------------------------------------------------

	half3 light;
	{
		float3 lightTexCoord = fragment.htexcoord0.xyz / fragment.htexcoord0.w;

		half4 lpm = h4tex2D( $lightProjectMap, lightTexCoord.xy );
		half4 lfm = h4tex2D( $lightFalloffMap, float2( lightTexCoord.z, 0.5 ) );

		light = _float3( dot3( toLight, globalNormal ) );

		// modulate by the light projection and falloff
		light *= lpm.xyz * lfm.xyz;

		// modulate by the light color
		light *= $lightColor.xyz;

		// modulate by the shadow factor adjusted by the shadow fade
		light *= ( shadow * $shadowFade.x ) + $shadowFade.y;
	}

	//---------------------------------------------------------------
	// sample envColor from the environment map
	//---------------------------------------------------------------

	half3 specular;
	{
		// reflection vector = 2 * N * ( N . V ) - V
		half4 reflection;
		reflection.xyz = ( 2.0 * globalNormal * dot3( globalNormal, toViewer ) ) - toViewer;

		// power factor is stored in bumpPage.x as 0.0 - 1.0, we want a 0 | 1 | 2 | 3 mip value
		// we could probably skip the floor, but I am wary of hardware / api rounding
		// the artists really prefer white to be shinny instead of dull, so invert it here
		reflection.w = floor( ( 1.0 - bumpPage.x ) * 4.0 + $newPowerScale.x );

		half3 envColor = texCUBElod( $dynamicEnvMap, reflection ).xyz;

		specular = envColor * specularPage.xyz * $newSpecularScale.xyz;
	}

	half3 diffuse = _float3( 1.0f );

	half3 color = light * ( specular + diffuse );

	result.color.xyz = color;
	result.color.w = 1.0f;
}
#endtemplate

/*
==================================================================================
INTERACTION_FRAGMENT_EYE

For the cornea sclera we scale the diffuse towards black using the alpha so that
the hole into the iris doesn't give off any diffuse color.
We do keep the specular as is since we want the rounded glass shape the eye over
the actual iris rendered underneath.

Should the color of the light influence the environment color? probably.

vertex input:
	texcoord 0.xyzw	is the light projection / falloff texture coordinates
	texcoord 1.xy	is the bump / diffuse / specular texture coordinate
	texcoord 2.xyz	is the global vertex position after model matrix transform
	texcoord 3.xyz	is the normal transform 1
	texcoord 4.xyz	is the normal transform 2
	texcoord 5.xyzw	is the shadow buffer coordinates
	texcoord 6.xyz	is the normal transform 3

	in float shadow;

render parms:
	globalViewOrigin
	globalLightOrigin
==================================================================================
*/
#template INTERACTION_FRAGMENT_EYE( shadow )
{
	half power = 1.0;

	half4 sampleDiffuse = tex2D( $spareDiffuseMap, fragment.texcoord1.xy );
	half4 sampleSpecular = tex2D( $spareSpecularMap, fragment.texcoord1.xy );
	half4 sampleBump = tex2D( $spareBumpMap, fragment.texcoord1.xy );
	
	//---------------------------------------------------------------
	// derive localNormal, then transform to a global normal
	//---------------------------------------------------------------

	half3 localNormal = half3( ( sampleBump.wy * 2.0 ) - 1.0, 0.0 );

	// derive the localNormal.z component
	localNormal.z = sqrt( abs( 1.0 - dot3( localNormal, localNormal ) ) );
	
	// transform into global space
	half3 globalNormal;
	globalNormal.x = dot3( localNormal, fragment.htexcoord3 );
	globalNormal.y = dot3( localNormal, fragment.htexcoord4 );
	globalNormal.z = dot3( localNormal, fragment.htexcoord6 );
	globalNormal = normalize( globalNormal );

	//---------------------------------------------------------------
	// normalize the directions to the light and viewer
	//---------------------------------------------------------------
	half3 toLight = normalize( $globalLightOrigin.xyz - fragment.texcoord2.xyz );
	half3 toViewer = normalize( $globalViewOrigin.xyz - fragment.texcoord2.xyz );

	//---------------------------------------------------------------
	// Incoming light color is the product of two light projection
	// texture maps, the light color parameter, the dor with the surface
	// normal, and the faded shadow factor
	// optimize: if we assumed one or both of the light maps are monochrome,
	// we could save some math.
	//---------------------------------------------------------------

	half3 light;
	{
		half3 lightTexCoord = fragment.htexcoord0.xyz / fragment.htexcoord0.w;

		half4 lpm = h4tex2D( $lightProjectMap, lightTexCoord.xy );
		half4 lfm = h4tex2D( $lightFalloffMap, half2( lightTexCoord.z, 0.5 ) );

		light = _half3( saturate( dot3( toLight, globalNormal ) + 0.1 ) );

		// modulate by the light projection and falloff
		light *= lpm.xyz * lfm.xyz;

		// modulate by the light color
		light *= $lightColor.xyz;

		// modulate by the shadow factor adjusted by the shadow fade
		light *= ( shadow * $shadowFade.x ) + $shadowFade.y;
	}

	half3 specular;
	{
		//---------------------------------------------------------------
		// sample envColor from the environment map
		//---------------------------------------------------------------

		// reflection vector = 2 * N * ( N . V ) - V
		half4 reflection;
		reflection.xyz = ( 2.0 * globalNormal * dot3( globalNormal, toViewer ) ) - toViewer;

		// power factor is stored in ________ as 0.0 - 1.0, we want a 0 | 1 | 2 | 3 mip value
		// we could probably skip the floor, but I am wary of hardware / api rounding
		// the artists really prefer white to be shiny instead of dull, so invert it here
		reflection.w = floor( ( 1.0 - power ) * 4.0 + $newPowerScale.x );

		half3 envColor = texCUBElod( $dynamicEnvMap, reflection ).xyz;

		specular = envColor * sampleSpecular.xyz * $newSpecularScale.xyz;
	}
	
	{
		half3 toCameraLight = normalize( toViewer + half3( 0.0, 0.0, 6.5 ) );
		half coss = saturate( dot3( globalNormal, toCameraLight ) );
		specular += _half3( saturate( pow( coss, $eyeHighlightPowLevel.x ) * $eyeHighlightPowLevel.y ) );
	}
	
	half3 diffuse = sampleDiffuse.xyz;
	
	// Scale diffuse so that we get black where the iris is supposed to be.
	diffuse *= _half3( saturate( ceil( sampleDiffuse.w - 0.5 ) ) );
	
	half3 color = light * ( diffuse + specular );
	
	result.color.xyz = color;
	result.color.w = 1;
}
#endtemplate


/*
==================================================================================
INTERACTION_FRAGMENT_SKIN

Should the color of the light influence the environment color? probably.

vertex input:
	texcoord 0.xyzw	is the light projection / falloff texture coordinates
	texcoord 1.xy	is the bump / diffuse-bump / diffuse / specular / ambient-occlusion texture coordinate
	texcoord 2.xyz	is the global vertex position after model matrix transform
	texcoord 3.xyz	is the normal transform 1
	texcoord 4.xyz	is the normal transform 2
	texcoord 5.xyzw	is the shadow buffer coordinates
	texcoord 6.xyz	is the normal transform 3

	in float shadow;

render parms:
	globalViewOrigin
	globalLightOrigin
==================================================================================
*/
#template INTERACTION_FRAGMENT_SKIN( shadow )
{
	//-------- non-wrapping virtual texture lookup ------------
	half2 texcoord = fragment.texcoord1.xy;
	BRANCH if ( $useVirtualMapping.x > 0 ) {
		// this is basically only for non pre-lit levels, and shouldn't be used often.
		// this doesn't attempt to get the derivative correct at the frac crossing point
		texcoord = frac( texcoord ) * $virtualMapping.xy + $virtualMapping.zw;
	}

	half3 physCoord = VmtrVirtualToPhysical( texcoord );

	//---------------------------------------------------------------
	// load the virtual textures
	//---------------------------------------------------------------
#ifdef USE_VIRTUAL_ANISO_FOOTPRINT
	half2 dx = ddx( texcoord.xy ) * physCoord.z;
	half2 dy = ddy( texcoord.xy ) * physCoord.z;

	half4 sampleSpecular = texPhys( $physicalVmtrPagesMap0, physCoord.xy, dx, dy );
	half4 sampleYCoCg = texPhys( $physicalVmtrPagesMap1, physCoord.xy, dx, dy );
	half4 sampleSpecularNormal = texPhys( $physicalVmtrPagesMap2, physCoord.xy, dx, dy );
#else
	half4 sampleSpecular = texPhys( $physicalVmtrPagesMap0, physCoord.xy );
	half4 sampleYCoCg = texPhys( $physicalVmtrPagesMap1, physCoord.xy );
	half4 sampleSpecularNormal = texPhys( $physicalVmtrPagesMap2, physCoord.xy );
#endif

	//---------------------------------------------------------------
	// load the diffuse normal and ambient occlusion
	//---------------------------------------------------------------
	half4 sampleDiffuseNormal = tex2D( $spareBumpMap, fragment.texcoord1.xy );
	half4 sampleAmbientOcclusion = tex2D( $transMap, fragment.texcoord1.xy );
	
	float occlusionRes;
	half4 bumpRes;
#ifdef INTERWRINKLE
	SAMPLE_WRINKLEMAPS( occlusionRes, bumpRes, sampleAmbientOcclusion, sampleDiffuseNormal, fragment.texcoord1 );
#else //INTERWRINKLE
	occlusionRes = sampleAmbientOcclusion.g;
	bumpRes = sampleDiffuseNormal;
#endif //INTERWRINKLE
	
	//---------------------------------------------------------------
	// convert the diffuse from YCoCg
	//---------------------------------------------------------------
	half4 surfaceDiffuse;
	{
		sampleYCoCg.z = ( sampleYCoCg.z * 31.875 ) + 1.0;			//z = z * 255.0/8.0 + 1.0
		sampleYCoCg.z = 1.0 / sampleYCoCg.z;
		sampleYCoCg.xy *= sampleYCoCg.z;
		surfaceDiffuse.x = dot4( sampleYCoCg, matrixCoCg1YtoRGB1X );
		surfaceDiffuse.y = dot4( sampleYCoCg, matrixCoCg1YtoRGB1Y );
		surfaceDiffuse.z = dot4( sampleYCoCg, matrixCoCg1YtoRGB1Z );
		surfaceDiffuse.w = 1.0;
	}

	//---------------------------------------------------------------
	// scale specular
	//---------------------------------------------------------------
	half3 surfaceSpecular;
	{
		surfaceSpecular.xyz = ScaleSpecular( sampleSpecular.xyz, sampleSpecularNormal.z );
		sampleSpecularNormal.z = 0;
	}

	//---------------------------------------------------------------
	// calculate global diffuse normal
	//---------------------------------------------------------------
	half3 globalDiffuseNormal;
	{
		half3 localNormal = half3( ( bumpRes.wy * 2.0 ) - 1.0, 0.0 );
		localNormal.z = sqrt( abs( 1.0 - dot3( localNormal, localNormal ) ) );
		
		globalDiffuseNormal.x = dot3( localNormal, fragment.htexcoord3 );
		globalDiffuseNormal.y = dot3( localNormal, fragment.htexcoord4 );
		globalDiffuseNormal.z = dot3( localNormal, fragment.htexcoord6 );
		globalDiffuseNormal = normalize( globalDiffuseNormal );
	}
	
	//---------------------------------------------------------------
	// calculate global specular normal
	//---------------------------------------------------------------
	half3 globalSpecularNormal;
	{
		half3 localNormal = half3( ( sampleSpecularNormal.wy * 2.0 ) - 1.0, 0.0 );
		localNormal.z = sqrt( abs( 1.0 - dot3( localNormal, localNormal ) ) );
		
		globalSpecularNormal.x = dot3( localNormal, fragment.htexcoord3 );
		globalSpecularNormal.y = dot3( localNormal, fragment.htexcoord4 );
		globalSpecularNormal.z = dot3( localNormal, fragment.htexcoord6 );
		globalSpecularNormal = normalize( globalSpecularNormal );
	}
	
	//---------------------------------------------------------------
	// normalize the directions to the light and viewer
	//---------------------------------------------------------------
	half3 toLight = normalize( $globalLightOrigin.xyz - fragment.texcoord2.xyz );
	half3 toViewer = normalize( $globalViewOrigin.xyz - fragment.texcoord2.xyz );

	//---------------------------------------------------------------
	// calculate and apply the diffuse light grazing
	//---------------------------------------------------------------
	{
		half grazeDiffuse = dot3( toViewer, globalDiffuseNormal );
		grazeDiffuse = saturate( ( $viewGraze.x - max( grazeDiffuse, -grazeDiffuse ) ) / max( $viewGraze.x, 0.0001 ) );
		surfaceDiffuse.xyz = lerp( surfaceDiffuse.xyz, $grazingDiffuseColor.xyz, grazeDiffuse );
	}
	
	//---------------------------------------------------------------
	// calculate and apply the specular light grazing
	//---------------------------------------------------------------
	{
		half grazeSpecular = dot3( toViewer, globalSpecularNormal );
		grazeSpecular = saturate( ( $viewGraze.x - max( grazeSpecular, -grazeSpecular ) ) / max( $viewGraze.x, 0.0001 ) );
		surfaceSpecular.xyz = lerp( surfaceSpecular.xyz, $grazingSpecularColor.xyz, grazeSpecular );
	}
	
	//---------------------------------------------------------------
	// apply specular reflection
	//---------------------------------------------------------------
	{
		// reflection vector = 2 * N * ( N . V ) - V
		half4 reflection;
		reflection.xyz = ( 2.0 * globalSpecularNormal * dot3( globalSpecularNormal, toViewer ) ) - toViewer;

		// power factor is stored in sampleSpecularNormal.x as 0.0 - 1.0, we want a 0 | 1 | 2 | 3 mip value
		// we could probably skip the floor, but I am wary of hardware / api rounding
		// the artists really prefer white to be shiny instead of dull, so invert it here
		reflection.w = floor( ( 1.0 - sampleSpecularNormal.x ) * 4.0 + $newPowerScale.x );

		// sample envColor from the environment map
		half3 envColor = texCUBElod( $dynamicEnvMap, reflection ).xyz;

		// apply
		surfaceSpecular *= envColor;
	}

	//---------------------------------------------------------------
	// diffuse light is the dot between the diffuse surface normal and the light,
	// this is then used to lookup a warp value in a texture
	//---------------------------------------------------------------
	half3 diffuseLight;
	{
		// pw-note: I get super weird artifacts on edges if I don't clamp them down, probably texture filtering? :(
		//			it's weird I don't get them in the skinVmtr programs though (?)
		half cosd = max( min( dot3( toLight, globalDiffuseNormal ) * 0.5 + 0.5, 0.99 ), 0.01 );
		half3 diffuseWarp = tex2D( $textureMap, half2( cosd, 0.0 ) ).xyz;

		diffuseLight = diffuseWarp;
	}
	
	//---------------------------------------------------------------
	// specular light is the dot between the specular surface normal and the light
	//---------------------------------------------------------------
	half3 specularLight;
	{
		half coss = saturate( dot3( toLight, globalSpecularNormal ) );
		specularLight = _half3( coss );
	}
	
	//---------------------------------------------------------------
	// Incoming light color is the product of two light projection
	// texture maps, the light color parameter and the faded shadow factor
	// optimize: if we assumed one or both of the light maps are monochrome,
	// we could save some math.
	//---------------------------------------------------------------
	half3 lightColor;
	{
		half3 lightTexCoord = fragment.htexcoord0.xyz / fragment.htexcoord0.w;
		half4 lpm = h4tex2D( $lightProjectMap, lightTexCoord.xy );
		half4 lfm = h4tex2D( $lightFalloffMap, half2( lightTexCoord.z, 0.5 ) );
		
		// Modulate with ambient occlusion (this is not really correct)
		lightColor = _float3( occlusionRes );
		
		// modulate by the light projection and falloff
		lightColor *= lpm.xyz * lfm.xyz;

		// modulate by the light color
		lightColor *= $lightColor.xyz;

		// modulate by the shadow factor adjusted by the shadow fade
		lightColor *= ( shadow * $shadowFade.x ) + $shadowFade.y;
	}
	
	//---------------------------------------------------------------
	// apply light scale on diffuse and specular
	//---------------------------------------------------------------
	{
		diffuseLight *= lightColor;
		specularLight *= lightColor;
	}
	
	//---------------------------------------------------------------
	// apply diffuse and specular scales
	//---------------------------------------------------------------
	{
		surfaceDiffuse.xyz *= $newDiffuseScale.xyz * 2.0;
		surfaceSpecular.xyz *= $newSpecularScale.xyz;
	}
	
	//---------------------------------------------------------------
	// sum everything up
	//---------------------------------------------------------------
	half3 color = _half3( 0.0 );
	color += specularLight * surfaceSpecular.xyz;
	color += diffuseLight * surfaceDiffuse.xyz;

	result.color.rgb = color;
	result.color.a = 1;
}
#endtemplate

/*
==================================================================================
INTERACTION_FRAGMENT_HAIR

Should the color of the light influence the environment color? probably.

vertex input:
	texcoord 0.xyzw	is the light projection / falloff texture coordinates
	texcoord 1.xy	is the bump / diffuse / specular texture coordinate
	texcoord 2.xyz	is the global vertex position after model matrix transform
	texcoord 3.xyz	is the normal transform 1
	texcoord 4.xyz	is the normal transform 2
	texcoord 5.xyzw	is the shadow buffer coordinates
	texcoord 6.xyz	is the normal transform 3

	in float shadow;

render parms:
	globalViewOrigin
	globalLightOrigin
==================================================================================
*/
#template INTERACTION_FRAGMENT_HAIR( shadow )
{
	float2 texcoord2 = fragment.texcoord7.xy;

	//---------------------------------------------------------------
	// load the coverage and clip pixel if not visible
	//---------------------------------------------------------------
	half4 coverage;
	{
		coverage = tex2D( $transMap, texcoord2 );
	}
	clip( coverage.w - 0.25 );
	
	//-------- non-wrapping virtual texture lookup ------------
	float2 texcoord = fragment.texcoord1.xy;
	BRANCH if ( $useVirtualMapping.x > 0 ) {
		// this is basically only for non pre-lit levels, and shouldn't be used often.
		// this doesn't attempt to get the derivative correct at the frac crossing point
		texcoord = frac( texcoord ) * $virtualMapping.xy + $virtualMapping.zw;
	}

	float3 physCoord = VmtrVirtualToPhysical( texcoord );

	//---------------------------------------------------------------
	// load the virtual textures
	//---------------------------------------------------------------
#ifdef USE_VIRTUAL_ANISO_FOOTPRINT
	float2 dx = ddx( texcoord.xy ) * physCoord.z;
	float2 dy = ddy( texcoord.xy ) * physCoord.z;

	half4 specularPage = texPhys( $physicalVmtrPagesMap0, physCoord.xy, dx, dy );
	half4 YCoCg = texPhys( $physicalVmtrPagesMap1, physCoord.xy, dx, dy );
	half4 bumpPage = texPhys( $physicalVmtrPagesMap2, physCoord.xy, dx, dy );
#else
	half4 specularPage = texPhys( $physicalVmtrPagesMap0, physCoord.xy );
	half4 YCoCg = texPhys( $physicalVmtrPagesMap1, physCoord.xy );
	half4 bumpPage = texPhys( $physicalVmtrPagesMap2, physCoord.xy );
#endif

	specularPage.xyz = ScaleSpecular( specularPage.xyz, bumpPage.z );
	bumpPage.z = 0;

	//---------------------------------------------------------------
	// derive localNormal, then transform to a global normal
	//---------------------------------------------------------------

	float3 localNormal = float3( ( bumpPage.wy * 2.0 ) - 1.0, 0.0 );

	// derive the localNormal.z component
	localNormal.z = sqrt( abs( 1.0 - dot3( localNormal, localNormal ) ) );

	// transform into global space
	float3 globalNormal;
	globalNormal.x = dot3( localNormal, fragment.htexcoord3 );
	globalNormal.y = dot3( localNormal, fragment.htexcoord4 );
	globalNormal.z = dot3( localNormal, fragment.htexcoord6 );
	globalNormal = normalize( globalNormal );

	//---------------------------------------------------------------
	// normalize the directions to the light and viewer
	//---------------------------------------------------------------
	float3 toLight = normalize( $globalLightOrigin.xyz - fragment.texcoord2.xyz );
	float3 toViewer = normalize( $globalViewOrigin.xyz - fragment.texcoord2.xyz );

	//---------------------------------------------------------------
	// Incoming light color is the product of two light projection
	// texture maps, the light color parameter, the dor with the surface
	// normal, and the faded shadow factor
	// optimize: if we assumed one or both of the light maps are monochrome,
	// we could save some math.
	//---------------------------------------------------------------

	half3 light;
	{
		float3 lightTexCoord = fragment.htexcoord0.xyz / fragment.htexcoord0.w;

		half4 lpm = h4tex2D( $lightProjectMap, lightTexCoord.xy );
		half4 lfm = h4tex2D( $lightFalloffMap, float2( lightTexCoord.z, 0.5 ) );

		light = _float3( dot3( toLight, globalNormal ) );

		// modulate by the light projection and falloff
		light *= lpm.xyz * lfm.xyz;

		// modulate by the light color
		light *= $lightColor.xyz;

		// modulate by the shadow factor adjusted by the shadow fade
		light *= ( shadow * $shadowFade.x ) + $shadowFade.y;
	}

	half3 specular;
	{
		//---------------------------------------------------------------
		// sample envColor from the environment map
		//---------------------------------------------------------------

		// reflection vector = 2 * N * ( N . V ) - V
		half4 reflection;
		reflection.xyz = ( 2.0 * globalNormal * dot3( globalNormal, toViewer ) ) - toViewer;

		// power factor is stored in bumpPage.x as 0.0 - 1.0, we want a 0 | 1 | 2 | 3 mip value
		// we could probably skip the floor, but I am wary of hardware / api rounding
		// the artists really prefer white to be shiny instead of dull, so invert it here
		reflection.w = floor( ( 1.0 - bumpPage.x ) * 4.0 + $newPowerScale.x );

		half3 envColor = texCUBElod( $dynamicEnvMap, reflection ).xyz;

		specular = envColor * specularPage.xyz * $newSpecularScale.xyz;
	}

	//---------------------------------------------------------------
	// covert the diffuse from YCoCg
	//---------------------------------------------------------------
	half4 diffuse;
	{
		YCoCg.z = ( YCoCg.z * 31.875 ) + 1.0;			//z = z * 255.0/8.0 + 1.0
		YCoCg.z = 1.0 / YCoCg.z;
		YCoCg.xy *= YCoCg.z;
		diffuse.x = dot4( YCoCg, matrixCoCg1YtoRGB1X );
		diffuse.y = dot4( YCoCg, matrixCoCg1YtoRGB1Y );
		diffuse.z = dot4( YCoCg, matrixCoCg1YtoRGB1Z );
		diffuse.w = 1.0;
		diffuse.xyz *= $newDiffuseScale.xyz * 2.0;
	}
	
	//---------------------------------------------------------------
	// sum everything up
	//---------------------------------------------------------------
	half3 color = light * ( specular + diffuse.xyz );
	
	result.color.rgb = color;
	result.color.a = 1;
}
#endtemplate

/*
==================================================================================
INTERACTION_FRAGMENT_BASIC_NOVMTR

Should the color of the light influence the environment color? probably.

vertex input:
	texcoord 0.xyzw	is the light projection / falloff texture coordinates
	texcoord 1.xy	is the bump / diffuse / specular texture coordinate
	texcoord 2.xyz	is the global vertex position after model matrix transform
	texcoord 3.xyz	is the normal transform 1
	texcoord 4.xyz	is the normal transform 2
	texcoord 5.xyzw	is the shadow buffer coordinates
	texcoord 6.xyz	is the normal transform 3

	in float shadow;

render parms:
	globalViewOrigin
	globalLightOrigin
==================================================================================
*/
#template INTERACTION_FRAGMENT_BASIC_NOVMTR( shadow )
{
	float2 texcoord = fragment.texcoord1.xy;

	//---------------------------------------------------------------
	// sample diffuse, bump, specular textures
	//---------------------------------------------------------------
	half4 sampleDiffuse = tex2D( $spareDiffuseMap, texcoord );
	half4 sampleSpecular = tex2D( $spareSpecularMap, texcoord );
	half4 sampleBump = tex2D( $spareBumpMap, texcoord );
	
	//---------------------------------------------------------------
	// sample morph diffuse, bump, specular textures and interpolate
	//---------------------------------------------------------------

	BRANCH if ( $useSkinBlending.x > 0.0 ) {	// fragment.htexcoord3.w > 0.0
		half4 sampleDiffuse2 = tex2D( $spareDiffuseMap2, texcoord );
		half4 sampleSpecular2 = tex2D( $spareSpecularMap2, texcoord );
		half4 sampleBump2 = tex2D( $spareBumpMap2, texcoord );

		half morphScale = fragment.htexcoord3.w;
		sampleDiffuse = lerp( sampleDiffuse, sampleDiffuse2, morphScale );
		sampleSpecular = lerp( sampleSpecular, sampleSpecular2, morphScale );
		sampleBump = lerp( sampleBump, sampleBump2, morphScale );
	}

	//---------------------------------------------------------------
	// derive localNormal, then transform to a global normal
	//---------------------------------------------------------------

	float3 localNormal = float3( ( sampleBump.wy * 2.0 ) - 1.0, 0.0 );

	// derive the localNormal.z component
	localNormal.z = sqrt( abs( 1.0 - dot3( localNormal, localNormal ) ) );

	// transform into global space
	float3 globalNormal;
	globalNormal.x = dot3( localNormal, fragment.htexcoord3 );
	globalNormal.y = dot3( localNormal, fragment.htexcoord4 );
	globalNormal.z = dot3( localNormal, fragment.htexcoord6 );
	globalNormal = normalize( globalNormal );

	//---------------------------------------------------------------
	// normalize the directions to the light and viewer
	//---------------------------------------------------------------
	float3 toLight = normalize( $globalLightOrigin.xyz - fragment.texcoord2.xyz );
	float3 toViewer = normalize( $globalViewOrigin.xyz - fragment.texcoord2.xyz );

	//---------------------------------------------------------------
	// Incoming light color is the product of two light projection
	// texture maps, the light color parameter, the dor with the surface
	// normal, and the faded shadow factor
	// optimize: if we assumed one or both of the light maps are monochrome,
	// we could save some math.
	//---------------------------------------------------------------

	half3 light;
	{
		float3 lightTexCoord = fragment.htexcoord0.xyz / fragment.htexcoord0.w;

		half4 lpm = h4tex2D( $lightProjectMap, lightTexCoord.xy );
		half4 lfm = h4tex2D( $lightFalloffMap, float2( lightTexCoord.z, 0.5 ) );

		light = _float3( dot3( toLight, globalNormal ) );

		// modulate by the light projection and falloff
		light *= lpm.xyz * lfm.xyz;

		// modulate by the light color
		light *= $lightColor.xyz;

		// modulate by the shadow factor adjusted by the shadow fade
		light *= ( shadow * $shadowFade.x ) + $shadowFade.y;
	}

	half3 specular;
	half power = 1.0;
	{
#if 0
		//---------------------------------------------------------------
		// calculate the static specular at this point
		//---------------------------------------------------------------

		// reflection vector = 2 * N * ( N . V ) - V
		half3 reflection;
		reflection = ( 2.0 * globalNormal * dot3( globalNormal, toLight ) ) - toLight;

		// Use the absolute value of the dot, so we get static
		// highlights on both sides of objects.  Oh, the horror! :-)
		float specularD = abs( dot3( reflection, $staticSpecularVector ) );

		// power factor is stored in __________ as 0.0 - 1.0, we want a 0 to 64 scale
		float factor = power * 64;

		float specularStrength = $staticSpecularScale.x * pow( specularD, factor );

		specular = specularStrength;
#else
		//---------------------------------------------------------------
		// sample envColor from the environment map
		//---------------------------------------------------------------

		// reflection vector = 2 * N * ( N . V ) - V
		half4 reflection;
		reflection.xyz = ( 2.0 * globalNormal * dot3( globalNormal, toViewer ) ) - toViewer;

		// power factor is stored in __________ as 0.0 - 1.0, we want a 0 | 1 | 2 | 3 mip value
		// we could probably skip the floor, but I am wary of hardware / api rounding
		// the artists really prefer white to be shiny instead of dull, so invert it here
		reflection.w = floor( ( 1.0 - power ) * 4.0 + $newPowerScale.x );

		half3 envColor = texCUBElod( $dynamicEnvMap, reflection ).xyz;

		specular = envColor * sampleSpecular.xyz * $newSpecularScale.xyz;
#endif
	}

	//---------------------------------------------------------------
	// scale the diffuse from texture sample
	//---------------------------------------------------------------
	half4 diffuse;
	{
		diffuse.xyz = sampleDiffuse.xyz * $newDiffuseScale.xyz * 2.0;
		diffuse.w = 1.0;
	}

	//---------------------------------------------------------------
	// sum everything up
	//---------------------------------------------------------------
	half3 color = light * ( specular + diffuse.xyz );

	result.color.rgb = color;
	result.color.a = 1;
}
#endtemplate

