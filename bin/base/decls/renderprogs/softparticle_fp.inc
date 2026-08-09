
#ifdef XBOX
float interpolatedZOverW = fragment.texcoord3.z / fragment.texcoord3.w;
#else
float interpolatedZOverW = fragment.position.z;
#endif

float fogVal = fragment.texcoord0.z;
float alphaScale = fragment.texcoord0.w;
float frameFrac = fragment.texcoord1.z;

float2 screenTC = screenPosToTexcoord( fragment.position.xy, $renderPositionToViewTexture );
float scale = ComputeSoftParticleScale( $viewDepthMap, screenTC, interpolatedZOverW, alphaScale );

half4 color = ComputeAnimCrossFadeColor( $transMap, fragment.texcoord0.xy, fragment.texcoord1.xy, frameFrac );
