
/*
==================================================================================
CALC_VMTR_TEXCOORD

uses fragment.texcoord0;
out half4 texCoord
==================================================================================
*/
#template CALC_VMTR_TEXCOORD( texCoord ) 
{
	texCoord = fragment.texcoord0;

	/*-------- non-wrapping virtual texture lookup ------------*/
	BRANCH if ( $useVirtualMapping.x > 0 ) {
		/* This is basically only for non pre-lit levels, and shouldn't be used often. */
		/* This doesn't attempt to get the derivative correct at the frac crossing point. */
#ifdef VMTR_TEXCOORD_SKIP_FRAC
		texCoord = texCoord * $virtualMapping.xyxy + $virtualMapping.zwzw;
#else
		texCoord = frac( texCoord ) * $virtualMapping.xyxy + $virtualMapping.zwzw;
#endif
	}
}
#endtemplate

/*
==================================================================================
FETCH_VMTR

uses fragment.texcoord0;
out half4 sampleSpecular;
out half4 sampleYCoCg;
out half4 sampleNormal;
out half2 feedbackTexCoord;
==================================================================================
*/
#template FETCH_VMTR( sampleSpecular, sampleYCoCg, sampleNormal, feedbackTexCoord )
{
	float4 texCoord;
	CALC_VMTR_TEXCOORD( texCoord );

	float3 physCoord = VmtrVirtualToPhysical( texCoord.xy );

#ifdef USE_VIRTUAL_ANISO_FOOTPRINT
	float2 dx = ddx( texCoord.xy ) * physCoord.z;
	float2 dy = ddy( texCoord.xy ) * physCoord.z;

	sampleSpecular = texPhys( $physicalVmtrPagesMap0, physCoord.xy, dx, dy );
	sampleYCoCg = texPhys( $physicalVmtrPagesMap1, physCoord.xy, dx, dy );
	sampleNormal = texPhys( $physicalVmtrPagesMap2, physCoord.xy, dx, dy );
#else
	sampleSpecular = texPhys( $physicalVmtrPagesMap0, physCoord.xy );
	sampleYCoCg = texPhys( $physicalVmtrPagesMap1, physCoord.xy );
	sampleNormal = texPhys( $physicalVmtrPagesMap2, physCoord.xy );
#endif

	feedbackTexCoord = texCoord.xy;
}
#endtemplate

/*
==================================================================================
FETCH_VMTR_BLEND

uses fragment.texcoord0;
out half4 sampleSpecular;
out half4 sampleYCoCg;
out half4 sampleNormal;
out half2 feedbackTexCoord;
in  half morphScale;
==================================================================================
*/
#template FETCH_VMTR_BLEND( sampleSpecular, sampleYCoCg, sampleNormal, feedbackTexCoord, morphScale )
{
	float4 texCoord;
	CALC_VMTR_TEXCOORD( texCoord );
	
	float3 physCoord = VmtrVirtualToPhysical( texCoord.xy );

#ifdef USE_VIRTUAL_ANISO_FOOTPRINT
	float2 dx = ddx( texCoord.xy ) * physCoord.z;
	float2 dy = ddy( texCoord.xy ) * physCoord.z;

	sampleSpecular = texPhys( $physicalVmtrPagesMap0, physCoord.xy, dx, dy );
	sampleYCoCg = texPhys( $physicalVmtrPagesMap1, physCoord.xy, dx, dy );
	sampleNormal = texPhys( $physicalVmtrPagesMap2, physCoord.xy, dx, dy );
#else
	sampleSpecular = texPhys( $physicalVmtrPagesMap0, physCoord.xy );
	sampleYCoCg = texPhys( $physicalVmtrPagesMap1, physCoord.xy );
	sampleNormal = texPhys( $physicalVmtrPagesMap2, physCoord.xy );
#endif

	feedbackTexCoord = texCoord.xy;

	/* blend in another texture based on the morph map */
	BRANCH if ( $useSkinBlending.x > 0.0 ) {
		float3 physCoord = VmtrVirtualToPhysical( texCoord.zw );

#ifdef USE_VIRTUAL_ANISO_FOOTPRINT
		float2 dx = ddx( texCoord.zw ) * physCoord.z;
		float2 dy = ddy( texCoord.zw ) * physCoord.z;

		float4 sampleSpecular2 = texPhys( $physicalVmtrPagesMap0, physCoord.xy, dx, dy );
		float4 sampleYCoCg2 = texPhys( $physicalVmtrPagesMap1, physCoord.xy, dx, dy );
		float4 sampleNormal2 = texPhys( $physicalVmtrPagesMap2, physCoord.xy, dx, dy );
#else
		float4 sampleSpecular2 = texPhys( $physicalVmtrPagesMap0, physCoord.xy );
		float4 sampleYCoCg2 = texPhys( $physicalVmtrPagesMap1, physCoord.xy );
		float4 sampleNormal2 = texPhys( $physicalVmtrPagesMap2, physCoord.xy );
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
CALC_VMTR_FEEDBACK

in half2 feedbackTexCoord;
out float4 feedback;
==================================================================================
*/
#template CALC_VMTR_FEEDBACK( feedback, feedbackTexCoord )
{
	feedback = PackFeedback( CalculateFeedback( feedbackTexCoord, $virtualTextureFeedbackFloat, $physicalVmtrFilterParms ) );
}
#endtemplate

/*
==================================================================================
CALC_DIFFUSE_RGB

in half4 sampleYCoCg;
inout half4 diffuse;
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
}
#endtemplate

/*
==================================================================================
CALC_SPECULAR_RGB
==================================================================================
*/
#template CALC_SPECULAR_RGB( specular, sampleSpecular, specularScale )
{
	specular = sampleSpecular.xyz * 8.0 / ( specularScale * 255.0 + 8.0 );
	specular += 0.001;
}
#endtemplate

/*
==================================================================================
CALC_LOCAL_NORMAL
==================================================================================
*/
#template CALC_LOCAL_NORMAL( localNormal, sampleNormal )
{
	/* Note that the optimized derivation of the localNormal below results */
	/* in a vector that is half-unit length! */
	localNormal = sampleNormal.wyz - 0.5;
	localNormal.z = sqrt( abs( dot( localNormal.xy, localNormal.xy ) - 0.25 ) );
}
#endtemplate

/*
==================================================================================
CALC_SMOOTH_NORMAL
==================================================================================
*/
#template CALC_SMOOTH_NORMAL( smoothNormal, localToGlobalX, localToGlobalY, localToGlobalZ )
{
	smoothNormal.x = localToGlobalX.z;
	smoothNormal.y = localToGlobalY.z;
	smoothNormal.z = localToGlobalZ.z;
	smoothNormal = normalize( smoothNormal );
}
#endtemplate

/*
==================================================================================
CALC_GLOBAL_NORMAL
==================================================================================
*/
#template CALC_GLOBAL_NORMAL( globalNormal, sampleNormal, localToGlobalX, localToGlobalY, localToGlobalZ )
{
	/* Note that the optimized derivation of the localNormal below results */
	/* in a vector that is half-unit length! */
	half3 localNormal = sampleNormal.wyz - 0.5;
	localNormal.z = sqrt( abs( dot( localNormal.xy, localNormal.xy ) - 0.25 ) );

	/* transform the normal into ambient map space */
	globalNormal.x = dot3( localNormal, localToGlobalX );
	globalNormal.y = dot3( localNormal, localToGlobalY );
	globalNormal.z = dot3( localNormal, localToGlobalZ );
	globalNormal = normalize( globalNormal );
}
#endtemplate

/*
==================================================================================
CALC_GLOBAL_NORMAL_TWOSIDED
==================================================================================
*/
#template CALC_GLOBAL_NORMAL_TWOSIDED( globalNormal, sampleNormal, localToGlobalX, localToGlobalY, localToGlobalZ )
{
	/* Note that the optimized derivation of the localNormal below results */
	/* in a vector that is half-unit length! */
	half3 localNormal = sampleNormal.wyz - 0.5;
	localNormal.z = sqrt( abs( dot( localNormal.xy, localNormal.xy ) - 0.25 ) );

	/* flip the normal around if looking at the back side */
#if defined( XBOX )
	if ( fragment.facing > 0 ) {
		localNormal.z = -localNormal.z;
	}
#elif defined( PS3 )
	if ( fragment.face < 0 ) {
		localNormal.z = -localNormal.z;
	}
#elif defined( GLSL )
	if ( !gl_FrontFacing ) {
		localNormal.z = -localNormal.z;
	}
#endif

	/* transform the normal into ambient map space */
	globalNormal.x = dot3( localNormal, localToGlobalX );
	globalNormal.y = dot3( localNormal, localToGlobalY );
	globalNormal.z = dot3( localNormal, localToGlobalZ );
	globalNormal = normalize( globalNormal );
}
#endtemplate

/*
==================================================================================
CALC_FROM_VIEWER
==================================================================================
*/
#template CALC_FROM_VIEWER( fromViewerN, fromViewer )
{
	fromViewerN = normalize( fromViewer.xyz );
}
#endtemplate

/*
==================================================================================
CALC_GLOBAL_REFLECTION
==================================================================================
*/
#template CALC_GLOBAL_REFLECTION( globalReflection, globalNormal, fromViewerN )
{
	// reflection vector
	globalReflection.xyz = fromViewerN - ( globalNormal * dot3( fromViewerN, globalNormal ) * 2.0 );
}
#endtemplate

/*
==================================================================================
SAMPLE_DIMSHADOW_BUFFER
==================================================================================
*/
#template SAMPLE_DIMSHADOW_BUFFER( shadow )
{
	// this is normalized window space, not strict openGL window space
	// that uses integer viewport values.
	float3 window;
	window.xy = screenPosToTexcoord( fragment.position.xy, $renderPositionToViewTexture );

	// fetch the window space depth value
	window.z = tex2Ddepth( $viewDepthMap, window.xy );

	float4 wclip = float4( window.xyz, 1.0f );

	// now transform to the light clip space
	float4 light;
	light.x = dot4( wclip, $windowPosToDimShadowBlurS );
	light.y = dot4( wclip, $windowPosToDimShadowBlurT );
	light.z = dot4( wclip, $windowPosToDimShadowBlurR );
	light.w = dot4( wclip, $windowPosToDimShadowBlurQ );

	// divide by w to get to light device coordinates
	light.xyz /= light.w;

	// move the -1.0 - 1.0 light device st to the 0.0 - 1.0 texture range
#ifdef XBOX
	light.xy = ( light * 0.5 ) + 0.5;	// don't adjust z, it is already 0 - 1
#else
	light = ( light * 0.5 ) + 0.5;
#endif

#ifndef PC
	light.y = 1.0 - light.y;	// image y origin adjust
#endif
	// clamp before sampling, because the shadow depth map may have
	// only been updated in a restricted viewport
	light.xy = min( light.xy, 0.99 );
	light.xy = max( light.xy, 0.01 );

	// make sure that the cleared z = 1.0 in the shadow buffer
	// will always be farther away than any world surface
	light.z = min( light.z, 0.9999999 );

	// four samples
	float2 tc = fragment.position.xy * float2( 1.0/128, 1.0/128 ) + $viewRandom.xy;
	float2 dither = tex2D( $dither256map, tc ).xw;
		
	const float step = 1.0 / 768.0;	// FIXME: hard coded dim-shadow buffer size
	float3 center;
	// this biases by +1.5 on average, so we can test -3, -2, -1, 0 offsets
	center.xy = light.xy + step + dither * step;
	center.z = light.z;

	shadow = shadow2Ddepth( $dimShadowDepthMap, center +  float3( -2*step, -2*step, 0 ) );
	shadow += shadow2Ddepth( $dimShadowDepthMap, center + float3( -1*step, -2*step, 0 ) );
	shadow += shadow2Ddepth( $dimShadowDepthMap, center + float3( -2*step, -1*step, 0 ) );
	shadow += shadow2Ddepth( $dimShadowDepthMap, center + float3( -1*step, -1*step, 0 ) );
	shadow *= 0.25;
}
#endtemplate

/*
==================================================================================
APPLY_MODEL_FADE
==================================================================================
*/
#template APPLY_MODEL_FADE()
{
	BRANCH if ( $modelFade.x < 1.0 ) {
		float2 texcoord = fragment.position.xy * ( 1.0 / 256.0 );
		float dither = tex2D( $dither256Map, texcoord ).x;

		// 1 - fully opaque - 0.8 - stippling - 0.2 - fully transparent - 0
		clip( $modelFade.x - 0.2 - dither * 0.6 );
	}
}
#endtemplate

/*
==================================================================================
CALC_GRAZING
==================================================================================
*/
#template CALC_GRAZING( graze, globalNormal, fromViewerN )
{
	/* calculate the view grazing fraction */
	graze = saturate( dot3( -fromViewerN, globalNormal ) );
	graze = saturate( ( $viewGraze.x - max( graze, -graze ) ) / max( $viewGraze.x, 0.0001 ) );
}
#endtemplate

/*
==================================================================================
APPLY_DIFFUSE_GRAZING
==================================================================================
*/
#template APPLY_DIFFUSE_GRAZING( diffuse, graze )
{
	diffuse.xyz = lerp( diffuse.xyz, $grazingDiffuseColor.xyz, graze );
}
#endtemplate

/*
==================================================================================
APPLY_SPECULAR_GRAZING
==================================================================================
*/
#template APPLY_SPECULAR_GRAZING( specular, graze )
{
	specular.xyz = lerp( specular.xyz, $grazingSpecularColor.xyz, graze );
}
#endtemplate

/*
==================================================================================
APPLY_GRAZING
==================================================================================
*/
#template APPLY_GRAZING( diffuse, specular, globalNormal, fromViewerN )
{
	half graze;
	CALC_GRAZING( graze, globalNormal, fromViewerN );
	APPLY_DIFFUSE_GRAZING( diffuse, graze, );
	APPLY_SPECULAR_GRAZING( specular, graze );
}
#endtemplate

/*
==================================================================================
APPLY_GRAZINGS
==================================================================================
*/
#template APPLY_GRAZINGS( diffuse, globalDiffuseNormal, specular, globalSpecularNormal, fromViewerN )
{
	half grazeDiffuse;
	half grazeSpecular;
	CALC_GRAZING( grazeDiffuse, globalDiffuseNormal, fromViewerN );
	CALC_GRAZING( grazeSpecular, globalSpecularNormal, fromViewerN );
	APPLY_DIFFUSE_GRAZING( diffuse, grazeDiffuse );
	APPLY_SPECULAR_GRAZING( specular, grazeSpecular );
}
#endtemplate

/*
==================================================================================
APPLY_RIMLIGHT
==================================================================================
*/
#template APPLY_RIMLIGHT( diffuse, globalNormal, fromViewer )
{
	/* calculate the view grazing fraction */
	half graze = 1.0 - saturate( dot3( -normalize( fromViewer ), globalNormal ) );
	graze *= saturate( globalNormal.z );
	graze = pow( graze, $RimlightColor.w );
	diffuse.xyz += $rimlightColor.xyz * _half3( graze );
}
#endtemplate

/*
==================================================================================
APPLY_SCALING_SPECULAR
==================================================================================
*/
#template APPLY_SCALING_SPECULAR( specular )
{
	specular.xyz *= $newSpecularScale.xyz;
}
#endtemplate

/*
==================================================================================
APPLY_SCALING_DIFFUSE
==================================================================================
*/
#template APPLY_SCALING_DIFFUSE( diffuse )
{
	diffuse.xyz *= $newDiffuseScale.xyz * 2.0;	/* why times two? */
}
#endtemplate

/*
==================================================================================
APPLY_SCALING
==================================================================================
*/
#template APPLY_SCALING( diffuse, specular )
{
	APPLY_SCALING_DIFFUSE( diffuse )
	APPLY_SCALING_SPECULAR( specular );
}
#endtemplate

/*
==================================================================================
APPLY_SPECULAR_REFLECTION
==================================================================================
*/
#template APPLY_SPECULAR_REFLECTION( specular, power, globalReflection )
{
	/* Power factor is stored in sampleNormal.x as 0.0 - 1.0 */
	/* We want a 0 | 1 | 2 | 3 mip value. */
	/* The artists really prefer white to be shiny instead of dull, so invert it here. */
	/* We could probably skip the floor, but I am wary of hardware / api rounding. */
	globalReflection.w = floor( ( 1.0 - power ) * 4.0 + $newPowerScale.x );

	half3 envColor = texCUBElod( $dynamicEnvMap, globalReflection ).xyz;

	/* modulate by the environment mask map (specular channel) */
	specular *= envColor;
}
#endtemplate


/*
==================================================================================
APPLY_FOLIAGE_SPECULAR
==================================================================================
*/
#template APPLY_FOLIAGE_SPECULAR( specular, power, globalNormal, fromViewer )
{
	/* calculate the specular reflection vector from viewer and globalNormal */
	half4 reflection;
	reflection.xyz = fromViewer - ( globalNormal * dot3( fromViewer, globalNormal ) * 2.0 );

	/* Power factor is stored in sampleNormal.x as 0.0 - 1.0 */
	/* We want a 0 | 1 | 2 | 3 mip value. */
	/* The artists really prefer white to be shiny instead of dull, so invert it here. */
	/* We could probably skip the floor, but I am wary of hardware / api rounding. */
	reflection.w = floor( ( 1.0 - power ) * 4.0 + $newPowerScale.x );

	half3 envColor = texCUBElod( $dynamicEnvMap, reflection ).xyz;

	/* modulate by the environment mask map (specular channel) */
	envColor = lerp( _half3( max( max( envColor.x, envColor.y ), envColor.z ) ), envColor,  _half3( $envSatScalePower.x ) );
	envColor = pow( envColor, _half3( $envSatScalePower.z ) );
	//envColor *= _half3( saturate( globalNormal.z + 1.0 ) );
	specular *= envColor * _half3( $envSatScalePower.y );
}
#endtemplate

/*
==================================================================================
APPLY_PHYSICAL_SPECULAR
==================================================================================
*/
#template APPLY_PHYSICAL_SPECULAR( specular, surfaceSpecular, globalNormal, fromViewer )
{
	/* calculate the specular reflection vector from viewer and globalNormal */
	half4 reflection;
	reflection.xyz = fromViewer - ( globalNormal * dot3( fromViewer, globalNormal ) * 2.0 );

	//extract the color from the specular map
	half3 specColor = normalize( surfaceSpecular.xyz ) * _half3( 1.73 );

	//the gloss map is a greyscale version of the specular map
	half glossMask = ( surfaceSpecular.x + surfaceSpecular.y + surfaceSpecular.z ) * 0.333;

	//make dark parts of the spec map have less color
	specColor = lerp( _half3( 1.0 ), specColor, glossMask );

	glossMask = glossMask * $maxGloss.x;
	half piMul = 0.039808917197; // 1 / ( pi * 8 )
	half3 pSpecMask = _half3( ( glossMask + 8.0 ) * piMul );

	half3 pSpecular = _half3( saturate( dot3( normalize( reflection.xyz ), $primeLightDir.xyz ) ) );
	pSpecular *= pow( pSpecular, _half3( glossMask ) );
	pSpecular *= $primeLightColor.xyz;
	pSpecular *= pSpecMask * specColor;

	specular += pSpecular;
}
#endtemplate

/*
==================================================================================
APPLY_MUZZLE_FLASH
==================================================================================
*/
#template APPLY_MUZZLE_FLASH( color, surfaceDiffuse, globalNormal, MFVector )
{
	half muzzleFlash = saturate( dot( MFVector, globalNormal ) );
	color.xyz += _half3( $gunMuzzleFlash.x * muzzleFlash * $gunMuzzleFlashColor.w ) * $gunMuzzleFlashColor.xyz * surfaceDiffuse;
}
#endtemplate

/*
==================================================================================
APPLY_LIGHTING_FOLIAGE
==================================================================================
*/
#template APPLY_LIGHTING_FOLIAGE( color, diffuse, specular, trueNormal, fromViewer, treeMask, transmissionMask )
{
	
	//half treeMaskFromZ = saturate( ( 1.0 - treeMask ) * 5.0 );
	//half3 trueNormal = lerp( globalNormal, treeNormal, 0.9 * treeMaskFromZ );

	half ndotl = dot3( $primeLightDir, trueNormal );
	half3 primeLightFactor = _half3( saturate( ndotl ) );
	half3 primeLight = $primeLightColor.xyz * primeLightFactor;
	half3 channelLight =
		+ max(  trueNormal.x * $channelLight0.xyz, 0 )
		+ max( -trueNormal.x * $channelLight1.xyz, 0 )
		+ max(  trueNormal.y * $channelLight2.xyz, 0 )
		+ max( -trueNormal.y * $channelLight3.xyz, 0 )
		+ max(  trueNormal.z * $channelLight4.xyz, 0 )
		+ max( -trueNormal.z * $channelLight5.xyz, 0 );

	half backLightFactor = pow( saturate( dot3( $primeLightDir, normalize( fromViewer ) ) ), 5.0 );
	half backLightFalloff = pow( 1.0 - abs( ndotl ), 3.0 );
	backLightFactor *= backLightFalloff * 3.0;
	half3 backLight = $primeLightColor.xyz * transmissionMask.xyz * treeMask * backLightFactor;

	half3 light = primeLight + channelLight + backLight;

	/* maximum amount of dim-shadowing based on the pime light contribution */
	float acceptDimShadow = max( primeLightFactor.x, max( primeLightFactor.y, primeLightFactor.z ) ) * ( 1.0 - saturate( 0.5 + $primeLightMin.x ) );

	color.xyz = light * ( diffuse + specular );
	color.w = acceptDimShadow;
}
#endtemplate

/*
==================================================================================
APPLY_LIGHTING
==================================================================================
*/
#template APPLY_LIGHTING( color, diffuse, specular, globalNormal )
{
	half primeLightFactor = saturate( dot3( $primeLightDir, globalNormal ) );
	half3 primeLight = $primeLightColor.xyz * primeLightFactor;
	half3 channelLight =
		+ max(  globalNormal.x * $channelLight0.xyz, 0 )
		+ max( -globalNormal.x * $channelLight1.xyz, 0 )
		+ max(  globalNormal.y * $channelLight2.xyz, 0 )
		+ max( -globalNormal.y * $channelLight3.xyz, 0 )
		+ max(  globalNormal.z * $channelLight4.xyz, 0 )
		+ max( -globalNormal.z * $channelLight5.xyz, 0 );
	half3 light = primeLight + channelLight;

	/* maximum amount of dim-shadowing based on the pime light contribution */
	float acceptDimShadow = primeLightFactor * ( 1.0 - saturate( 0.5 + $primeLightMin.x ) );

	color.xyz = light * ( diffuse + specular );
	color.w = acceptDimShadow;
}
#endtemplate

/*
==================================================================================
APPLY_LIGHTING_NOAMBIENT
==================================================================================
*/
#template APPLY_LIGHTING_NOAMBIENT( color, diffuse, specular, globalNormal )
{
	half primeLightFactor = saturate( dot3( $primeLightDir, globalNormal ) );
	half3 primeLight = $primeLightColor.xyz * primeLightFactor;
	half3 light = primeLight;

	/* maximum amount of dim-shadowing based on the pime light contribution */
	float acceptDimShadow = primeLightFactor * ( 1.0 - saturate( 0.5 + $primeLightMin.x ) );

	color.xyz = light * ( diffuse + specular );
	color.w = acceptDimShadow;
}
#endtemplate

/*
==================================================================================
APPLY_LIGHTING_ZHEIGHT
==================================================================================
*/
#template APPLY_LIGHTING_ZHEIGHT( color, diffuse, specular, globalNormal, height )
{
	half primeLightFactor = saturate( dot3( $primeLightDir, globalNormal ) );
	half3 primeLight = $primeLightColor.xyz * primeLightFactor;
	half3 channelLight =
		+ max(  globalNormal.x * $channelLight0.xyz, 0 )
		+ max( -globalNormal.x * $channelLight1.xyz, 0 )
		+ max(  globalNormal.y * $channelLight2.xyz, 0 )
		+ max( -globalNormal.y * $channelLight3.xyz, 0 )
		+ max(  globalNormal.z * $channelLight4.xyz, 0 )
		+ max( -globalNormal.z * $channelLight5.xyz, 0 );
	half3 light = primeLight + channelLight;

	/* modulate by the z-height blend */
	light = lerp( channelLight, light, height );

	/* maximum amount of dim-shadowing based on the pime light contribution */
	float acceptDimShadow = primeLightFactor * ( 1.0 - saturate( 0.5 + $primeLightMin.x ) );

	color.xyz = light * ( diffuse + specular );
	color.w = acceptDimShadow;
}
#endtemplate

/*
==================================================================================
APPLY_LIGHTING_KEY
==================================================================================
*/
#template APPLY_LIGHTING_KEY( color, diffuse, specular, power, globalNormal, fromViewer,
								primaryShadow, secondaryShadow, ambientScale, directScale )
{
	half3 fromViewerN;
	half3 globalReflection;
	
	// reflection vector
	CALC_FROM_VIEWER( fromViewerN, fromViewer );
	CALC_GLOBAL_REFLECTION( globalReflection, globalNormal, fromViewerN );

	half3 specularLight;
	half3 diffuseLight;
		
	//---------------------------------------------------------------
	// primary light
	//---------------------------------------------------------------

	float primaryFactor = saturate( dot3( $primeLightDir, globalNormal ) );
	float3 primeLight = primaryShadow * $primeLightColor.xyz * primaryFactor;
	diffuseLight = primeLight;
			 
	// classic specular calculation
	// power factor is stored in bumpPage.x as 0.0 - 1.0, with 1.0 being tightest highlights
	float specDot = saturate( dot3( $primeLightDir, globalReflection ) );
	specDot = pow( specDot, 1 + power * 40 );

	specularLight = primeLight * specDot;

	//---------------------------------------------------------------
	// secondary light
	//---------------------------------------------------------------

	float secondaryFactor = saturate( dot3( $secondaryLightDir, globalNormal ) );
	float3 secondaryLight = secondaryShadow * $secondaryLightColor.xyz * secondaryFactor;
	diffuseLight += secondaryLight;
		
	specDot = saturate( dot3( $secondaryLightDir, globalReflection ) );
	specDot = pow( specDot, 1 + power * 40 );
		
	specularLight += secondaryLight * specDot;

	//---------------------------------------------------------------
	// ambient lighting
	//---------------------------------------------------------------

	float3 ambientLight = 
		+ max(  globalNormal.x * $channelLight0.xyz, 0 )
		+ max( -globalNormal.x * $channelLight1.xyz, 0 )
		+ max(  globalNormal.y * $channelLight2.xyz, 0 )
		+ max( -globalNormal.y * $channelLight3.xyz, 0 )
		+ max(  globalNormal.z * $channelLight4.xyz, 0 )
		+ max( -globalNormal.z * $channelLight5.xyz, 0 );

	//---------------------------------------------------------------
	// height lerp
	//---------------------------------------------------------------

	// lerp in the diffuse lighting from the ground up
	diffuseLight *= directScale;
	specularLight *= directScale;
	// lerp down the ambient from the ground up
	diffuseLight += ambientLight * ambientScale;
		
	//---------------------------------------------------------------
	// sum everything up
	//---------------------------------------------------------------

	/* maximum amount of dim-shadowing based on the pime light contribution */
	float acceptDimShadow = primaryFactor * ( 1.0 - saturate( 0.5 + $primeLightMin.x ) );

	color.xyz = ( specularLight * specular.xyz ) + ( diffuseLight * diffuse.xyz );
	color.w = acceptDimShadow;
}
#endtemplate

/*
==================================================================================
CALC_FRAGMENT_POS
==================================================================================
*/
#template CALC_FRAGMENT_POS( fragmentXYZ, fromViewer )
{
	// world space coordinate of the fragment
    // texcoord4 is fragmentXYZ - $globalViewOrigin.xyz;
	fragmentXYZ = fromViewer + $globalViewOrigin.xyz;
}
#endtemplate

/*
==================================================================================
APPLY_LIGHTING
==================================================================================
*/
#template APPLY_LIGHTING_LOCAL( color, diffuse, specular, power, globalNormal, fragmentXYZ, globalReflection )
{
	// power factor is stored in bumpPage.x as 0.0 - 1.0, with 1.0 being tightest highlights
    const float powerExp = 4 + power * 100;

	half3 specularLight = half3( 0, 0, 0 );
	half3 diffuseLight = half3( 0, 0, 0 );

	//---------------------------------------------------------------
	// first light
	//---------------------------------------------------------------
    const float3    light0Dir = $channellight0.xyz - fragmentXYZ;
    const float3    light0DirNormalized = normalize( light0Dir );
    const float     light0Dist = length( light0Dir );
    const float     light0Attenuation = 1.0 - ( min( light0Dist, $channellight1.w ) / $channellight1.w );
	const float     light0Factor = saturate( dot3( light0DirNormalized, globalNormal ) );
	const float     light0SpecDot = saturate( dot3( light0DirNormalized, globalReflection ) );
	const float     light0Pow = pow( light0SpecDot, powerExp );
    const float3    light0Color = $channellight1.xyz * light0Factor * light0Attenuation;

	diffuseLight += light0Color;
	specularLight += light0Color * light0Pow;

	//---------------------------------------------------------------
	// second light
	//---------------------------------------------------------------
    const float3    light1Dir = $channellight2.xyz - fragmentXYZ;
    const float3    light1DirNormalized = normalize( light1Dir );
    const float     light1Dist = length( light1Dir );
    const float     light1Attenuation = 1.0 - ( min( light1Dist, $channellight1.w ) / $channellight1.w );
	const float     light1Factor = saturate( dot3( light1DirNormalized, globalNormal ) );
	const float     light1SpecDot = saturate( dot3( light1DirNormalized, globalReflection ) );
	const float     light1Pow = pow( light1SpecDot, powerExp );
    const float3    light1Color = $channellight3.xyz * light1Factor * light1Attenuation;

	diffuseLight += light1Color;
	specularLight += light1Color * light1Pow;

	//---------------------------------------------------------------
	// third light
	//---------------------------------------------------------------
    const float3    light2Dir = $channellight4.xyz - fragmentXYZ;
    const float3    light2DirNormalized = normalize( light2Dir );
    const float     light2Dist = length( light2Dir );
    const float     light2Attenuation = 1.0 - ( min( light2Dist, $channellight1.w ) / $channellight1.w );
	const float     light2Factor = saturate( dot3( light2DirNormalized, globalNormal ) );
	const float     light2SpecDot = saturate( dot3( light2DirNormalized, globalReflection ) );
	const float     light2Pow = pow( light2SpecDot, powerExp );
    const float3    light2Color = $channellight5.xyz * light2Factor * light2Attenuation;

	diffuseLight += light2Color;
	specularLight += light2Color * light2Pow;

	//---------------------------------------------------------------
	// sum everything up
	//---------------------------------------------------------------

    // the YCoCg conversion can go slightly negative!
    diffuse = saturate( diffuse );

    // de-gamma the textures
    diffuse.x = pow( diffuse.x, 2.2 );
    diffuse.y = pow( diffuse.y, 2.2 );
    diffuse.z = pow( diffuse.z, 2.2 );

    specular.x = pow( specular.x, 2.2 );
    specular.y = pow( specular.y, 2.2 );
    specular.z = pow( specular.z, 2.2 );

    const float3 finalColor = ( specularLight * specular.xyz ) + ( diffuseLight * diffuse.xyz );

    // gamma correct
    color.x = pow( finalColor.x, 1.0/2.2 );
    color.y = pow( finalColor.y, 1.0/2.2 );
    color.z = pow( finalColor.z, 1.0/2.2 );

	/* maximum amount of dim-shadowing based on the pime light contribution */
	const half primeLightFactor = saturate( dot3( $primeLightDir, globalNormal ) ) 
        *  ( 1.0 - saturate( 0.5 + $primeLightMin.x ) );    // FIXME: make a constant!

	color.w = primeLightFactor;
}
#endtemplate

/*
==================================================================================
APPLY_LIGHTING_SKIN
==================================================================================
*/
#template APPLY_LIGHTING_SKIN( color, diffuse, specular, ambientOcclusion, globalDiffuseNormal, globalReflection )
{
	// Calculate diffuse warp from diffuse normal and use it as lookup
	half cosd = saturate( ( dot3( $primeLightDir, globalDiffuseNormal ) * 0.5 ) + 0.5 );
	half3 diffuseWarp = tex2D( $textureMap, float2( cosd, 0.0 ) ).xyz;
	
	half specularAmbienceScale = 0.25;
	half primeLightFactor = saturate( dot3( $primeLightDir, globalDiffuseNormal ) );
	
	// Diffuse primary and ambient light
	half3 diffusePrimary = $primeLightColor.xyz * diffuseWarp;
	half3 diffuseAmbient = _half3( 0.0 )
		+ max(  globalDiffuseNormal.x * $channelLight0.xyz, 0.0 )
		+ max( -globalDiffuseNormal.x * $channelLight1.xyz, 0.0 )
		+ max(  globalDiffuseNormal.y * $channelLight2.xyz, 0.0 )
		+ max( -globalDiffuseNormal.y * $channelLight3.xyz, 0.0 )
		+ max(  globalDiffuseNormal.z * $channelLight4.xyz, 0.0 )
		+ max( -globalDiffuseNormal.z * $channelLight5.xyz, 0.0 );
	
	// Specular primary and ambient light
	half3 specularPrimary = $primeLightColor.xyz * saturate( dot3( globalReflection, $primeLightDir ) );
	half3 specularAmbient = _half3( 0.0 )
		+ max(  globalReflection.x * $channelLight0.xyz, 0.0 );
		+ max( -globalReflection.x * $channelLight1.xyz, 0.0 );
		+ max(  globalReflection.y * $channelLight2.xyz, 0.0 );
		+ max( -globalReflection.y * $channelLight3.xyz, 0.0 );
		+ max(  globalReflection.z * $channelLight4.xyz, 0.0 );
		+ max( -globalReflection.z * $channelLight5.xyz, 0.0 );
		
	// Apply ambient occlusion on ambient lights
	diffuseAmbient *= ambientOcclusion;
	specularAmbient *= ambientOcclusion * specularAmbienceScale;

	half3 diffuseLight = diffusePrimary + diffuseAmbient;
	half3 specularLight = specularPrimary + specularAmbient;
	
	// Maximum amount of dim-shadowing based on the pime light contribution
	float acceptDimShadow = primeLightFactor * ( 1.0 - saturate( 0.5 + $primeLightMin.x ) );
	
	// Sum
	color.xyz = _half3( 0.0 )
		+ ( diffuseLight * diffuse )
		+ ( specularLight * specular );
	color.w = acceptDimShadow;
}
#endtemplate

/*
==================================================================================
APPLY_HOLOGRAM
==================================================================================
*/
#template APPLY_HOLOGRAM( color )
{
	// scanline texture
	float2 screenCoords = screenPosToTexcoord( fragment.position.xy, $positionToViewTexture );
	half scanlinesWide = tex2D( $scanlineMap, screenCoords + ( $time.x * 0.025 ) ).x;

	screenCoords *= float2( 1.0, 5.5 );
	half scanlinesFine = tex2D( $scanlineMap, screenCoords + ( $time.x * 0.01 ) ).x;

	color.xyz *= scanlinesWide + ( scanlinesFine * 0.25 ) ;
	color.xyz *= 2.5;
	color.xyz += $hologramColor.xyz * ( color.xyz + 0.1 );
	color.xyz *= $hologramColor.w;
}
#endtemplate

/*
==================================================================================
APPLY_HIGHLIGHT
==================================================================================
*/
#template APPLY_HIGHLIGHT( color, fromViewerN, localToGlobalX, localToGlobalY, localToGlobalZ )
{
	/* Reference,
		This is the code we ran to get the approximated look of how we wanted the
		rimming of usables to look like. 
	half k = 1.0 - saturate( abs( dot3( objectNormal.xyz, $globalViewFwd.xyz ) ) );
	half bias = 0.25;
	half scale = 1.0 / max( 1.0 - bias, 0.00001 );
	
	half r = saturate( ( k - bias ) * scale );
	color.xyz += _half3( r * r ) * half3( 0.968, 0.941, 0.705 ) * _half3( 1.0 );
	*/

	half3 objectNormal = half3( localToGlobalX.z, localToGlobalY.z, localToGlobalZ.z );
	half k = 1.0 - saturate( abs( dot3( objectNormal.xyz, $globalViewFwd.xyz ) ) );
	half r = ( k - 0.25 ) * 1.333333;
	
	color.xyz += $highlightColor.xyz * _half3( r * r );
}
#endtemplate

/*
==================================================================================
OUTPUT_SURFACE_ATTRIBUTES
==================================================================================
*/
#template OUTPUT_SURFACE_ATTRIBUTES( diffuse, specular, power, globalNormal )
{
#ifdef DEFERRED_LIGHTING
	result.color2.xyz = diffuse.xyz;
	result.color2.w = length( specular.xyz );

	result.color3.xyz = globalNormal.xyz * _float3( 0.5 ) + _float3( 0.5 );
	result.color3.w = power;
#endif
}
#endtemplate
