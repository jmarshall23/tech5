
// Store fog and frame fraction value
float fogVal = fragment.texcoord0.z;
float frameFrac = fragment.texcoord1.z;


#ifdef PARTICLE_FP_ALT
// Remove trans-atlas coordinate mapping if we're using atlas coords
half2 texcoord0 = ( fragment.texcoord0.xy - $transAtlasScaleBiasInv.zw ) * $transAtlasScaleBiasInv.xy;
half2 texcoord1 = ( fragment.texcoord1.xy - $transAtlasScaleBiasInv.zw ) * $transAtlasScaleBiasInv.xy;
#else
// Simple copy texture coordinates from vertex program output
half2 texcoord0 = fragment.texcoord0.xy;
half2 texcoord1 = fragment.texcoord1.xy;
#endif


// Sample extra parameters if needed
#if defined( PARTICLE_FP_MASK_LUT ) || defined( PARTICLE_FP_MOD_TEXCOORD )
half2 texcoord2;
texcoord2.x = dot4( fragment.texcoord2.xy, $sMatrix );
texcoord2.y = dot4( fragment.texcoord2.xy, $tMatrix );

half4 parm = tex2D( $textureMap, texcoord2 );
#endif


// Offset texture coordinates
#ifdef PARTICLE_FP_MOD_TEXCOORD
half2 offset = parm.xy * _half2( 2.0 ) - _half2( 1.0 );
offset *= _half2( $distortionScale.x );

texcoord0 += offset;
texcoord1 += offset;
#endif


// Sample color from either transMap1 or transMap depending on wheter we're running alternative particle program or not
#ifdef PARTICLE_FP_ALT
half4 color = ComputeAnimCrossFadeColor( $transMap1, texcoord0, texcoord1, frameFrac );
#else
half4 color = ComputeAnimCrossFadeColor( $transMap, texcoord0, texcoord1, frameFrac );
#endif


#ifdef PARTICLE_FP_MASK_LUT
	half3 coordLUT = max( min( color.xyz * _half3( parm.z ), _half3( 1.0 - 0.015625 ) ), _half3( 0.015625 ) );
	color.x = tex2D( $transMap2, half2( coordLUT.x, 0.5 ) ).x;
	color.y = tex2D( $transMap2, half2( coordLUT.y, 0.5 ) ).y;
	color.z = tex2D( $transMap2, half2( coordLUT.z, 0.5 ) ).z;
#endif

