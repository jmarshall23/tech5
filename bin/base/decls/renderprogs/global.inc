/*

Do not use render parms in this file directly or they will be included in every single
vertex and fragment program which may come at a significant performance penalty.
For convenience render parms may be used in a #define declared in this file and such
a define may then be used in the actual vertex or fragment program that needs it.

*/

#if defined( XBOX )
#define BRANCH	[branch]
#define IFANY	[ifAny]
#elif defined( PS3 )
#define BRANCH	[branch]
#define IFANY
#else
#define BRANCH
#define IFANY
#endif

static float dot2( float2 a, float2 b ) { return dot( a, b ); }
static float dot3( float3 a, float3 b ) { return dot( a, b ); }
static float dot3( float3 a, float4 b ) { return dot( a, b.xyz ); }
static float dot3( float4 a, float3 b ) { return dot( a.xyz, b ); }
static float dot3( float4 a, float4 b ) { return dot( a.xyz, b.xyz ); }
static float dot4( float4 a, float4 b ) { return dot( a, b ); }
static float dot4( float2 a, float4 b ) { return dot( float4( a, 0, 1 ), b ); }

#ifdef PC_D3D
	#define sampler2D			Texture2D
	#define samplerCUBE			TextureCube
	#define samplerRECT			Texture2D	// FIXME: Rect support
#endif

#ifdef GLSL
	#define anyEqual( x, y )			any( equal( x, y ) )
	#define anyNotEqual( x, y )			any( notEqual( x, y ) )
	#define anyNotEqualZero( x )		max( sign( x ), 0.0 )
	#define fmod( x, y ) mod( x, y )
	#define SineCosine( x, s, c )		s = sin( x ); c = cos( x );
#else
	#define anyEqual( x, y )			any( (x) == (y) )
	#define anyNotEqual( x, y )			any( (x) != (y) )
	#define anyNotEqualZero( x )		any( (x) )
	#define greaterThanEqual( x, y )	( (x) >= (y) )
	#define SineCosine( x, s, c )		sincos( x, s, c );

	static half dot2( half2 a, half2 b ) { return dot( a, b ); }
	static half dot3( half3 a, half3 b ) { return dot( a, b ); }
	static half dot3( half3 a, half4 b ) { return dot( a, b.xyz ); }
	static half dot3( half4 a, half3 b ) { return dot( a.xyz, b ); }
	static half dot3( half4 a, half4 b ) { return dot( a.xyz, b.xyz ); }
	static half dot4( half4 a, half4 b ) { return dot( a, b ); }
	static half dot4( half2 a, half4 b ) { return dot( half4( a, 0, 1 ), b ); }

	#define sampler2DShadow		sampler2D
	#define samplerCUBEShadow	samplerCUBE
	#define samplerRECTShadow	samplerRECT
#endif

static half PAGE_SIZE = 128;
static half PAGE_BORDER = 4;
static half PAGE_SIZE_LOG2 = 7;
static half PAYLOAD_SIZE = PAGE_SIZE - 2 * PAGE_BORDER;
static half PAYLOAD_SIZE_LOG2 = 6.907;

#ifdef XBOX
	// these are here because HLSL does not implement vector constructors with a single scalar parameter
	half2 _half2( float x ) { return half2( x, x ); }
	half3 _half3( float x ) { return half3( x, x, x ); }
	half4 _half4( float x ) { return half4( x, x, x, x ); }
	float2 _float2( float x ) { return float2( x, x ); }
	float3 _float3( float x ) { return float3( x, x, x ); }
	float4 _float4( float x ) { return float4( x, x, x, x ); }

	static float4 h4tex2D( sampler2D image, float2 texcoord ) { return tex2D( image, texcoord ); }
	static float4 h4tex2Dproj( sampler2D image, float3 texcoord ) { return tex2Dproj( image, float4( texcoord.xy, 0, texcoord.z ) ); }
	static float4 texPhys( sampler2D image, float2 texcoord ) { return tex2D( image, texcoord ); }
	static float4 texPhys( sampler2D image, float2 texcoord, float2 dx, float2 dy ) { return tex2D( image, texcoord, dx, dy ); }
	static float4 h4texPhys( sampler2D image, float2 texcoord ) { return tex2D( image, texcoord ); }
	static float4 h4texPhys( sampler2D image, float2 texcoord, float2 dx, float2 dy ) { return tex2D( image, texcoord, dx, dy ); }
	// return the depth value at texcoord.xy
	static float tex2Ddepth( sampler2D image, float2 texcoord ) { return 1.0 - tex2D( image, texcoord ).x; }
	static float tex2Ddepth_fast( sampler2D image, float2 texcoord ) { return 1.0 - tex2D( image, texcoord ).x; }
	// compare texcoord.z with the depth value at texcoord.xy and return 1 if less and 0 if larger equal
	static float shadow2Ddepth( sampler2DShadow image, float3 texcoord ) { return float( ( 1.0 - tex2D( image, texcoord.xy ).x ) >= texcoord.z ); }
	static float4 swizzleColor( float4 color ) { return color.abgr; }
	static float2 screenPosToTexcoord( float2 pos, float4 bias_scale ) { return ( pos * bias_scale.zw + bias_scale.xy ); }
	bool bHardwareSkinning : register(b1);
	bool bHardwareMorphing : register(b2);
#endif

#ifdef PS3
	#define _half2( x )		half2( x )
	#define _half3( x )		half3( x )
	#define _half4( x )		half4( x )
	#define _float2( x )	float2( x )
	#define _float3( x )	float3( x )
	#define _float4( x )	float4( x )

	static float4 texPhys( sampler2D image, float2 texcoord ) { return tex2D( image, texcoord ); }
	static float4 texPhys( sampler2D image, float2 texcoord, float2 dx, float2 dy ) { return tex2D( image, texcoord, dx, dy ); }
	static half4 h4texPhys( sampler2D image, float2 texcoord ) { return h4tex2D( image, texcoord ); }
	static half4 h4texPhys( sampler2D image, float2 texcoord, float2 dx, float2 dy ) { return h4tex2D( image, texcoord, dx, dy ); }
	// return the depth value at texcoord.xy
	static float tex2Ddepth( sampler2D image, float2 texcoord ) { return texDepth2D_precise( image, texcoord ); }
	static float tex2Ddepth_fast( sampler2D image, float2 texcoord ) {
		// Perform most accurate integer reconstruction using a half precision multiply.
		// Make sure the assember code looks like this:
		//
		//    TEXR H0, R1, TEX0;
		//    MULH H0, H0, {0x437f0000(255), 0x00000000(0), 0x00000000(0), 0x00000000(0)}.x;
		//    DP3R R1.z, H0, {0x3b800000(0.00390625), 0x37800000(1.52588e-005), 0x33800000(5.96046e-008), 0x00000000(0)};
		//
		half4 dt = h4tex2D( image, texcoord ) * half( 255.0 );
		return dot( dt, float4( 1.0 / 256, 1.0 / 256 / 256, 1.0 / 256 / 256 / 256, 0.0 ) );
	}
	// compare the depth value at texcoord.xy with texcoord.z and return 0 if less and 1 if larger equal
	static float shadow2Ddepth( sampler2DShadow image, float3 texcoord ) { return tex2D( image, texcoord ).x; }
	static float4 swizzleColor( float4 color ) { return color; }
	static float2 screenPosToTexcoord( float2 pos, float4 bias_scale ) { return ( pos * bias_scale.zw + bias_scale.xy ); }
	bool hardwareSkinning : b1;
	bool hardwareMorphing : b2;
#endif

#if defined( PC_D3D )

	// these are here because HLSL does not implement vector constructors with a single scalar parameter
	half2 _half2( float x ) { return half2( x, x ); }
	half3 _half3( float x ) { return half3( x, x, x ); }
	half4 _half4( float x ) { return half4( x, x, x, x ); }
	float2 _float2( float x ) { return float2( x, x ); }
	float3 _float3( float x ) { return float3( x, x, x ); }
	float4 _float4( float x ) { return float4( x, x, x, x ); }

	SamplerState samplerGeneric : register( s0 );	// FIXME
	static float4 tex2D( sampler2D image, float2 texcoord ) { return image.Sample( samplerGeneric, texcoord ); }
	static float4 tex2Dproj( sampler2D image, float3 texcoord ) { return image.Sample( samplerGeneric, texcoord ); }
	static float4 tex2DGrad( sampler2D image, float2 texcoord, float2 dx, float2 dy )  { return image.SampleGrad( samplerGeneric, texcoord, dx, dy ); }
	static float4 tex2Dlod( sampler2D image, float4 texcoord ) { return image.SampleLevel( samplerGeneric, texcoord.xy, texcoord.w, 0 ); }
	static float4 tex2Dbias( sampler2D image, float4 texcoord ) { return image.SampleBias( samplerGeneric, texcoord.xy, texcoord.w ); }
	static float4 texCUBE( samplerCUBE image, float3 texcoord ) { return image.Sample( samplerGeneric, texcoord ); }
	static float4 texCUBElod( samplerCUBE image, float4 texcoord ) { return image.SampleLevel( samplerGeneric, texcoord.xyz, texcoord.w ); }

	static float4 h4tex2D( sampler2D image, float2 texcoord ) { return tex2D( image, texcoord ); }
	static float4 h4tex2Dproj( sampler2D image, float3 texcoord ) { return tex2Dproj( image, float4( texcoord.xy, 0, texcoord.z ) ); }
	static float4 texPhys( sampler2D image, float2 texcoord ) { return tex2D( image, texcoord ); }
	static float4 texPhys( sampler2D image, float2 texcoord, float2 dx, float2 dy ) { return tex2DGrad( image, texcoord, dx, dy ); }
	static float4 h4texPhys( sampler2D image, float2 texcoord ) { return tex2D( image, texcoord ); }
	static float4 h4texPhys( sampler2D image, float2 texcoord, float2 dx, float2 dy ) { return tex2DGrad( image, texcoord, dx, dy ); }
	// return the depth value at texcoord.xy
	static float tex2Ddepth( sampler2D image, float2 texcoord ) { return 1.0 - tex2D( image, texcoord ).x; }
	static float tex2Ddepth_fast( sampler2D image, float2 texcoord ) { return 1.0 - tex2D( image, texcoord ).x; }
	// compare texcoord.z with the depth value at texcoord.xy and return 1 if less and 0 if larger equal
	static float shadow2Ddepth( sampler2DShadow image, float3 texcoord ) { return float( ( 1.0 - tex2D( image, texcoord.xy ).x ) >= texcoord.z ); }
	static float4 swizzleColor( float4 color ) { return color.rgba; }
	static float2 screenPosToTexcoord( float2 pos, float4 bias_scale ) { return ( pos * bias_scale.zw + bias_scale.xy ); }
	bool bHardwareSkinning : register(b1);
	bool bHardwareMorphing : register(b2);
#elif defined( PC )

	#define _half2( x )		half2( x )
	#define _half3( x )		half3( x )
	#define _half4( x )		half4( x )
	#define _float2( x )	float2( x )
	#define _float3( x )	float3( x )
	#define _float4( x )	float4( x )

	static float4 h4tex2D( sampler2D image, float2 texcoord ) { return tex2D( image, texcoord ); }
	static float4 h4tex2Dproj( sampler2D image, float3 texcoord ) { return tex2Dproj( image, texcoord ); }
	static float4 texPhys( sampler2D image, float2 texcoord ) { return tex2D( image, texcoord ); }
	static float4 texPhys( sampler2D image, float2 texcoord, float2 dx, float2 dy ) { return tex2D( image, texcoord, dx, dy ); }
	static float4 h4texPhys( sampler2D image, float2 texcoord ) { return tex2D( image, texcoord ); }
	static float4 h4texPhys( sampler2D image, float2 texcoord, float2 dx, float2 dy ) { return tex2D( image, texcoord, dx, dy ); }
	// return the depth value at texcoord.xy
	static float tex2Ddepth( sampler2D image, float2 texcoord ) { return tex2D( image, texcoord ).x; }
	static float tex2Ddepth_fast( sampler2D image, float2 texcoord ) { return tex2D( image, texcoord ).x; }
	// compare the depth value at texcoord.xy with texcoord.z and return 0 if less and 1 if larger equal
	static float shadow2Ddepth( sampler2DShadow image, float3 texcoord ) { return tex2D( image, texcoord ).x; }
	static float4 swizzleColor( float4 color ) { return color; }
	static float2 screenPosToTexcoord( float2 pos, float4 bias_scale ) { return ( pos * bias_scale.zw + bias_scale.xy ); }
#endif

static const half4 matrixRGB1toCoCg1YX = half4(  0.50,  0.0, -0.50, 0.50196078 );	// Co
static const half4 matrixRGB1toCoCg1YY = half4( -0.25,  0.5, -0.25, 0.50196078 );	// Cg
static const half4 matrixRGB1toCoCg1YZ = half4(  0.0,   0.0,  0.0,  1.0 );			// 1.0
static const half4 matrixRGB1toCoCg1YW = half4(  0.25,  0.5,  0.25, 0.0 );			// Y

static const half4 matrixCoCg1YtoRGB1X = half4(  1.0, -1.0,  0.0,        1.0 );
static const half4 matrixCoCg1YtoRGB1Y = half4(  0.0,  1.0, -0.50196078, 1.0 ); // -0.5 * 256.0 / 255.0
static const half4 matrixCoCg1YtoRGB1Z = half4( -1.0, -1.0,  1.00392156, 1.0 ); // +1.0 * 256.0 / 255.0

// uses texel space coordinates, not normalized coordinates
static float ComputeLOD( float2 virtCoords ) {
	float2 dx = ddx( virtCoords.xy );
	float2 dy = ddy( virtCoords.xy );

	float px = dot2( dx, dx );
	float py = dot2( dy, dy );

	float maxLod = 0.5 * log2( max( px, py ) );  // log2(sqrt()) = 0.5*log2()
	return maxLod;
}

// uses texel space coordinates, not normalized coordinates
static float ComputeAnisoLOD( float2 virtCoords, float maxAnisoLog2 ) {
	float2 dx = ddx( virtCoords.xy );
	float2 dy = ddy( virtCoords.xy );

	float px = dot2( dx, dx );
	float py = dot2( dy, dy );

	float maxLod = 0.5 * log2( max( px, py ) );  // log2(sqrt()) = 0.5*log2()
	float minLod = 0.5 * log2( min( px, py ) );

	return maxLod - min( maxAnisoLog2, maxLod - minLod );
}

static float4 ComputeVirtualLOD( float4 filterParms, float4 feedbackFloat, float4 virtMapping, float2 virtCoords ) {
	// Used for the land generation tool path.
	float drawBias = filterParms.x;
	float maxAnisoLog2 = filterParms.z;
	float widthInPages = feedbackFloat.y;

	// take just the fractional part of the original texture coordinate to give texture wrapping
	// scale and bias it by the source to virtual texture mapping
	float4 virtualTexCoord;
	virtualTexCoord.zw = _float2( 0.0 );
	virtualTexCoord.xy = frac( virtCoords );
	virtualTexCoord.xy = virtualTexCoord.xy * virtMapping.xy + virtMapping.zw;

	// look up the proper LOD in the dedicated LOD texture, based on the original, non-wrapped,
	// non-paged texture coordinates to avoid discontinuities. Still need to multiply by virtualMapping.xy
	// to account for the dimensions of the original texture.
	virtualTexCoord.w = ComputeAnisoLOD( virtCoords * virtMapping.xy * widthInPages * PAYLOAD_SIZE, maxAnisoLog2 );

	// adjust for the LOD bias already applied in the virtToPhysPage sampler (log2TexelSizeRatio)
	virtualTexCoord.w -= PAYLOAD_SIZE_LOG2 + drawBias;

	return virtualTexCoord;
}

#if defined( XBOX ) || ( defined( ATI ) && !defined( ATI_CLAMPED_ANISO ) )
// use the virtual texture coordinate instead of the physical texture coordinate for the anisotropic texture lookup
#define USE_VIRTUAL_ANISO_FOOTPRINT
#endif

// bias the page table lookup anticipating an anisotropic texture lookup
// this is expensive but may be a nice quality improvement for high end PCs
//#define USE_ANISO_PAGE_TABLE_LOOKUP

static float4 PageTableBiasForAniso( float2 virtCoords ) {
	const float minAnisoBias = -2;	// -log2( maxAniso )

	// calculate a bias for the page table lookup based on the size of the anisotropic footprint
	float2 dx = ddx( virtCoords.xy );
	float2 dy = ddy( virtCoords.xy );

	float px = dot2( dx, dx );
	float py = dot2( dy, dy );

	float maxLod = 0.5 * log2( max( px, py ) );  // log2(sqrt()) = 0.5*log2()
	float minLod = 0.5 * log2( min( px, py ) );

	float anisoBias = max( minLod - maxLod, minAnisoBias );

	return float4( virtCoords.x, virtCoords.y, 0, anisoBias );
}

#ifdef USE_ANISO_PAGE_TABLE_LOOKUP
#define tex2DPageTable( sampler, coords )		tex2Dbias( sampler, PageTableBiasForAniso( coords ) )
#else
#define tex2DPageTable( sampler, coords )		tex2D( sampler, coords )
#endif

//#define PAGE_TABLE_ONLY_8888
#if defined( PS3 ) || defined( XBOX )
#define PAGE_TABLE_ONLY_565
#endif
//#define MAPPING_IMAGE_3X_FLOAT32
//#define MAPPING_IMAGE_2X_FIXED16

#if defined( PAGE_TABLE_ONLY_8888 )

// using only the page table in 8-bit per component RGBA format
#define UniqueVirtualToPhysical( coords )					VirtualToPhysical2( $pageTableMap, coords, 32 )
#define UniqueDiffuseOnlyVirtualToPhysical( coords )		VirtualToPhysical2( $pageTableMap, coords, 32 )
#define UniqueDiffuseOnly2VirtualToPhysical( coords )		VirtualToPhysical2( $pageTableMap, coords, 32 )
#define VmtrVirtualToPhysical( coords )						VirtualToPhysical2( $pageTableMap, coords, 16 )
#define VmtrVirtualLODToPhysical( virtMapping, coords )		VirtualToPhysical2( $vmtrPageTableMap, coords, 16 ).xy

static float3 VirtualToPhysical2( sampler2D virtToPhysPage, float2 virtCoords, float physPagesWide ) {
	// constants
	const float pageWidth = 128;
	const float pageBorder = 4;
	//const float physPagesWide = 32;

	#if defined( PS3 ) || defined( XBOX )
		const float floatToByte = 255.0 + 1.0 / 256;
	#else
		const float floatToByte = 255.0;
	#endif

	// derived constants
	const float pageFracScale = ( pageWidth - 2 * pageBorder ) / pageWidth / physPagesWide;
	const float borderOffset = pageBorder / pageWidth / physPagesWide;
	const float4 texScale = {
		floatToByte / physPagesWide,
		floatToByte / physPagesWide,
		floatToByte * 1.0 / 16.0,
		floatToByte * 256.0 / 16.0
	};
	const float4 texBias = { borderOffset, borderOffset, 0, 0 };

	// translation
	float4 physPage = tex2DPageTable( virtToPhysPage, virtCoords ) * texScale + texBias;
	float2 pageFrac = frac( virtCoords * ( physPage.z + physPage.w ) );
	float3 physCoord;
	physCoord.xy = pageFrac * pageFracScale + physPage.xy;
	physCoord.z = ( physPage.z + physPage.w ) * pageFracScale;
	return physCoord;
}

#elif defined( PAGE_TABLE_ONLY_565 )

// using only the page table in 565 RGB format
#define UniqueVirtualToPhysical( coords )					VirtualToPhysical2( $pageTableMap, coords, 32 )
#define UniqueDiffuseOnlyVirtualToPhysical( coords )		VirtualToPhysical2( $pageTableMap, coords, 32 )
#define UniqueDiffuseOnly2VirtualToPhysical( coords )		VirtualToPhysical2( $pageTableMap, coords, 32 )
#define VmtrVirtualToPhysical( coords )						VirtualToPhysical2( $pageTableMap, coords, 16 )
#define VmtrVirtualLODToPhysical( virtMapping, coords )		VirtualToPhysical2( $vmtrPageTableMap, coords, 16 ).xy

static float3 VirtualToPhysical2( sampler2D virtToPhysPage, float2 virtCoords, float physPagesWide ) {
	// constants
	const float pageWidth = 128;
	const float pageBorder = 4;
	//const float physPagesWide = 32;

	#if defined( PS3 )
		const float floatToPagesWide = ( 255.0 + 1.0 / 256 ) / 256.0 * physPagesWide;
		const float floatToMip = ( 255.0 + 1.0 / 256 ) / 256.0 * 64.0;
	#elif defined( XBOX )
		const float floatToPagesWide = ( 31.0 + 1.0 / 33.0 ) / 32.0 * physPagesWide;
		const float floatToMip = ( 63.0 + 1.0 / 65.0 );
	#else
		const float floatToPagesWide = 255.0 / 256.0 * physPagesWide;
		const float floatToMip = 255.0 / 256.0 * 64.0;
	#endif

	// derived constants
	const float pageFracScale = ( pageWidth - 2 * pageBorder ) / pageWidth / physPagesWide;
	const float borderOffset = pageBorder / pageWidth / physPagesWide;
	const float4 texScale = {
		floatToPagesWide,
		floatToMip,
		floatToPagesWide,
		0
	};
	float4 texBias = { 0, 1.0 / 4096.0, 0, 0 };

	// translation
	half4 physPage = tex2DPageTable( virtToPhysPage, virtCoords ) * texScale + texBias;	// NOTE: must be half4 for PS3 ?
	physPage.y = exp2( physPage.y );
	physPage = floor( physPage );
	float2 pageFrac = frac( virtCoords * physPage.y );
	float3 physCoord;
	physCoord.xy = pageFrac * pageFracScale + physPage.xz / physPagesWide + borderOffset;
	physCoord.z = physPage.y * pageFracScale;
	return physCoord;
}

#elif defined( MAPPING_IMAGE_2X_FIXED16 )

// using two unsigned fixed point 16-bit mapping textures, one with a single channel and one with two channels
#define UniqueVirtualToPhysical( coords )					VirtualToPhysical2( $pageTableMap, $physicalUniqueMappingsMap0, $physicalUniqueMappingsMap1, coords )
#define UniqueDiffuseOnlyVirtualToPhysical( coords )		VirtualToPhysical2( $pageTableMap, $physicalUniqueDiffuseOnlyMappingsMap0, $physicalUniqueDiffuseOnlyMappingsMap1, coords )
#define UniqueDiffuseOnly2VirtualToPhysical( coords )		VirtualToPhysical2( $pageTableMap, $physicalUniqueDiffuseOnly2MappingsMap0, $physicalUniqueDiffuseOnly2MappingsMap1, coords )
#define VmtrVirtualToPhysical( coords )						VirtualToPhysical2( $pageTableMap, $physicalVmtrMappingsMap0, $physicalVmtrMappingsMap1, coords )
#define VmtrVirtualLODToPhysical( virtMapping, coords )		VirtualToPhysical2( $vmtrPageTableMap, $physicalVmtrMappingsMap0, $physicalVmtrMappingsMap1, coords ).xy

static float3 VirtualToPhysical2( sampler2D virtToPhysPage, sampler2D physPageToXform0, sampler2D physPageToXform1, float2 virtCoords ) {
	half2 physPage = tex2DPageTable( virtToPhysPage, virtCoords ).xy;
	float4 xform0 = tex2D( physPageToXform0, physPage ) * 32.0;
	float4 xform1 = tex2D( physPageToXform1, physPage ) * 32.0;
	float3 physCoord;
	physCoord.xy = virtCoords * xform0.y + xform1.xw - 30.0;
	physCoord.z = 0.0f;
	return physCoord;
}

#elif defined( MAPPING_IMAGE_3X_FLOAT32 )

// using three single channel float 32 mapping textures, one for each component
#define UniqueVirtualToPhysical( coords )					VirtualToPhysical2( $pageTableMap, $physicalUniqueMappingsMap0, $physicalUniqueMappingsMap1, $physicalUniqueMappingsMap2, coords )
#define UniqueDiffuseOnlyVirtualToPhysical( coords )		VirtualToPhysical2( $pageTableMap, $physicalUniqueDiffuseOnlyMappingsMap0, $physicalUniqueDiffuseOnlyMappingsMap1, $physicalUniqueDiffuseOnlyMappingsMap2, coords )
#define UniqueDiffuseOnly2VirtualToPhysical( coords )		VirtualToPhysical2( $pageTableMap, $physicalUniqueDiffuseOnly2MappingsMap0, $physicalUniqueDiffuseOnly2MappingsMap1, $physicalUniqueDiffuseOnly2MappingsMap2, coords )
#define VmtrVirtualToPhysical( coords )						VirtualToPhysical2( $pageTableMap, $physicalVmtrMappingsMap0, $physicalVmtrMappingsMap1, $physicalVmtrMappingsMap2, coords )
#define VmtrVirtualLODToPhysical( virtMapping, coords )		VirtualToPhysical2( $vmtrPageTableMap, $physicalVmtrMappingsMap0, $physicalVmtrMappingsMap1, $physicalVmtrMappingsMap2, coords ).xy

static float3 VirtualToPhysical2( sampler2D virtToPhysPage, sampler2D physPageToXform0, sampler2D physPageToXform1, sampler2D physPageToXform2, float2 virtCoords ) {
	half2 physPage = tex2DPageTable( virtToPhysPage, virtCoords ).xy;
	float xform0 = tex2D( physPageToXform0, physPage ).x;
	float xform1 = tex2D( physPageToXform1, physPage ).x;
	float xform2 = tex2D( physPageToXform2, physPage ).x;
	float3 physCoord;
	physCoord.xy = virtCoords * xform0 + float2( xform1, xform2 );
	physCoord.z = 0.0f;
	return physCoord;
}

#else

// using a single 4 channel float 32 mapping texture
#define UniqueVirtualToPhysical( coords )					VirtualToPhysical2( $pageTableMap, $physicalUniqueMappingsMap0, coords )
#define UniqueDiffuseOnlyVirtualToPhysical( coords )		VirtualToPhysical2( $pageTableMap, $physicalUniqueDiffuseOnlyMappingsMap0, coords )
#define UniqueDiffuseOnly2VirtualToPhysical( coords )		VirtualToPhysical2( $pageTableMap, $physicalUniqueDiffuseOnly2MappingsMap0, coords )
#define VmtrVirtualToPhysical( coords )						VirtualToPhysical2( $pageTableMap, $physicalVmtrMappingsMap0, coords )
#define VmtrVirtualLODToPhysical( virtMapping, coords )		VirtualLODToPhysical2( $vmtrPageTableMap, $physicalVmtrMappingsMap0, ComputeVirtualLOD( $physicalVmtrFilterParms, $virtualTextureFeedbackFloat, virtMapping, coords ) )

static float3 VirtualToPhysical2( sampler2D virtToPhysPage, sampler2D physPageToXform0, float2 virtCoords ) {
	half2 physPage = tex2DPageTable( virtToPhysPage, virtCoords ).xy;
	float4 xform = tex2D( physPageToXform0, physPage );
	float3 physCoord;
	physCoord.xy = virtCoords * xform.x + xform.zw;
	physCoord.z = xform.y;
	return physCoord;
}

static float2 VirtualLODToPhysical2( sampler2D virtToPhysPage, sampler2D physPageToXform0, float4 virtCoords ) {
	half2 physPage = tex2Dlod( virtToPhysPage, virtCoords ).xy;
	float4 xform = tex2D( physPageToXform0, physPage );
	return virtCoords.xy * xform.x + xform.zw;
}

#endif

static float ComputeSoftParticleScale( sampler2D image, float2 tc, float interpolatedZOverW, float softness ) {
	// This instruction handles the 1.0 - depth calc automatically when using an inverted depth buffer
	float depth = tex2Ddepth( image, tc );

	// Approximate a linear depth difference
	float r1 = 1.0 / ( 1.0 - depth );
	float r2 = 1.0 / ( 1.0 - interpolatedZOverW );
	return saturate( ( r1 - r2 ) * softness );
}

static half4 ComputeAnimCrossFadeColor( sampler2D image, float2 tc0, float2 tc1, float frameFrac ) {
	// For strip animations, we need to cross-fade
	half4 result0 = tex2D( image, tc0 ) * ( 1.0 - frameFrac );
	half4 result1 = tex2D( image, tc1 ) * ( frameFrac );	// when frameFrac is 0, no contribution
	return ( result0 + result1 );
}

// the 'distortVec' is in the range [-1.0, 1.0] for each component where 1.0 is the
// full screen width or height respectively
// the 'blur' value is in the range [0.0, 1.0] where 1.0 offsets the mip level by 8
static float4 ComputeDistortion( float2 distortVec, float blur ) {
	// The distortion vector is usually very small so store a close to normalized vector
	// in 'xy' and store a scale value in 'z'.
	// The blur value is moved in the range [0.5, 1.0] which allows multiple distortions
	// to be blended with GL_ONE_MINUS_DST_ALPHA GL_DST_ALPHA. The 'blur' (alpha channel) in
	// the distortion map is initialized to zero such that the first distortion fully contributes
	// and then consecutive distortions will blend in with a value in the range [0.0, 0.5].
	// Blending based on the blur value is of course wrong but it works if no blurring is applied.
	// Also, as the blur value goes up, additional distortions contribute less which is
	// fine because the distortions won't be noticeable when there is a lot of blurring.
	// A linear blend of the two vectors with separate scale values does not result in the
	// same vector as a linear blend of the original vectors. However, the resulting vector
	// is still nicely bounded between the original vectors and representative of accumulated
	// distortions.
	// To decode the distortion vector and blur value in the post process we use:
	// half4 distortion = h4tex2D( $postDistortionMap, texcoord.xy ) - ( 127.0 / 255.0 );
	// perturb += distortion.xy * distortion.z;
	// blur += saturate( distortion.w ) * 16;
	float4 final;
	final.z = 0.125 + sqrt( dot( distortVec, distortVec ) );
	final.xy = distortVec / final.z;
	final.w = blur * 0.5;
	return final + ( 127.0 / 255.0 );
}

static half2 ComputeTransAtlasCoord( half2 tc, half4 scaleBias ) {
	// Figure out half texel, pick fraction from texture coordinates and clamp it inside [ 0+halfTexel, 1-halfTexel ]
	half2 halfScale = scaleBias.xy * _half2( 0.5 );
	half2 result = max( min( frac( tc ), _half2( 1.0 ) - halfScale ), halfScale );
	
	// Scale and bias clamped texture coordinates
	return result * scaleBias.xy + scaleBias.zw;
}

static float4 ComputeDistortionMV( float2 distortVec, float blur ) {
	float4 final;
	final.xy = saturate( distortVec * 0.5 + 0.5 );
	final.z = blur * 0.5 + 0.5;
	final.w = 1.0;
	return final;
}

static float3 CoCgScYToRGB( float4 CoCgScY ) {
	float3	rgb;
	CoCgScY.z = ( CoCgScY.z * 31.875 ) + 1.0;			//z = z * 255.0/8.0 + 1.0
	CoCgScY.z = 1.0 / CoCgScY.z;
	CoCgScY.xy *= CoCgScY.z;
	rgb.x = dot4( CoCgScY, matrixCoCg1YtoRGB1X );
	rgb.y = dot4( CoCgScY, matrixCoCg1YtoRGB1Y );
	rgb.z = dot4( CoCgScY, matrixCoCg1YtoRGB1Z );
	return rgb;
}

static float4 CoCgScYToRGB1( float4 CoCgScY ) {
	float4 rgba;
	rgba.xyz = CoCgScYToRGB( CoCgScY );
	rgba.w = 1;
	return rgba;
}

static float3 ScaleSpecular( float3 unscaled, float factor ) {
	return ( unscaled * 8.0 )  / ( factor * 255.0 + 8.0 );
}

//#define FEEDBACK_FORMAT_FLOAT32

static float4 CalculateFeedback( float2 texCoords, float4 feedbackParms, float4 filterParms ) {
	float4 feedback;

	float bias = filterParms.y;
	float maxAnisoLog2 = filterParms.z;
	float widthInPages = feedbackParms.y;

	// xy is the integral page coordinates
	feedback.xy = texCoords * widthInPages;

	// compute the desired LOD for anisotropic filtering
	float desiredLod = ComputeAnisoLOD( feedback.xy * PAYLOAD_SIZE, maxAnisoLog2 ) + bias;

	// z is the lod level, never adjust below 0
	feedback.z = max( 0.0, desiredLod );

	// w holds the virtual texture index
	feedback.w = feedbackParms.x;

	return feedback;
}

/*
	pageX		= ( data[0] & 0xFF ) + ( data[2] & 0x0F ) << 8 );
	pageY		= ( data[1] & 0xFF ) + ( data[2] & 0xF0 ) << 4 );
	pageLOD		= ( data[3] & 0x0F );
	pageSource	= ( data[3] & 0xF0 ) >> 4;
*/
static float4 PackFeedback( float4 feedback ) {
#ifdef FEEDBACK_FORMAT_FLOAT32
	return feedback;
#else
	feedback = floor( feedback ) / 256.0;
	float2 xy_low = frac( feedback.xy + 0.5 / 256.0 );
	float2 xy_high = floor( feedback.xy ) / 256.0;

	float4 color;
	color.xy = xy_low;
	color.z = xy_high.y * 16.0 + xy_high.x;
	color.w = feedback.w * 16.0 + feedback.z;
#if defined( XBOX )
	return color.zyxw;	// stored as B-G-R-A
#elif defined( PS3 )
	return color.yzwx;	// stored as A-R-G-B
#else
	return color;
#endif
#endif
}
