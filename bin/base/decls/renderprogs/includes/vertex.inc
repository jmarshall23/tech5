
/*
==================================================================================
CALC_TEXCOORDS

uses vertex.texcoord0;

out float4 texcoords;
==================================================================================
*/
#template CALC_TEXCOORDS( texcoords )
{
	// base coordinates modified by stScaleBias for 16 bit vertex elements
	texcoords = ( vertex.texcoord0.xy * $vertexStScaleBias.xy + $vertexStScaleBias.zw ).xyxy;
}
#endtemplate

/*
==================================================================================
CALC_TEXCOORDS_BLEND

uses vertex.texcoord0;

out float4 texcoords;
==================================================================================
*/
#template CALC_TEXCOORDS_BLEND( texcoords )
{
	// base coordinates modified by stScaleBias for 16 bit vertex elements
	texcoords = ( vertex.texcoord0.xyxy * $vertexStScaleBias.xyxy + $vertexStScaleBias.zwzw ) + skinOffsets.xyzw;
}
#endtemplate

/*
==================================================================================
CALC_POSITION

uses vertex.position;

out float4 resultPosition;
==================================================================================
*/
#template CALC_POSITION( resultPosition )
{
	// Convert back from 16 bit vertex elements.
	float4 localPosition = vertex.position * $vertexXYZScale + $vertexXYZBias;

	resultPosition.x = dot4( localPosition, $mvpMatrixX );
	resultPosition.y = dot4( localPosition, $mvpMatrixY );
	resultPosition.z = dot4( localPosition, $mvpMatrixZ );
	resultPosition.w = dot4( localPosition, $mvpMatrixW );
}
#endtemplate

/*
==================================================================================
CALC_MUZZLE_FLASH_VECTOR

uses MFOffset;

out MFVector;
==================================================================================
*/
#template CALC_MUZZLE_FLASH_VECTOR( MFOffset, MFVector )
{
	//float3 globalPosition = _float4( 0.0 );
	//globalPosition.x = dot4( position, $modelMatrixX );
	//globalPosition.y = dot4( position, $modelMatrixY );
	//globalPosition.z = dot4( position, $modelMatrixZ );

	float3 globalMFOffset = _float3( 0.0 );
	
	//float3 altGlobalViewFwd = cross( $globalViewLeft.xyz, $globalViewUp.xyz );
	//globalMFOffset.xyz = altGlobalViewFwd.xyz * _float3( MFOffset.x );
	
	globalMFOffset.xyz = $globalViewFwd.xyz * _float3( MFOffset.x );
	globalMFOffset.xyz += $globalViewLeft.xyz * _float3( MFOffset.y );
	globalMFOffset.xyz += $globalViewUp.xyz * _float3( MFOffset.z );
	//float3 globalMFPosition = $globalViewOrigin.xyz + globalMFOffset;

	MFVector.xyz = normalize( globalMFOffset );
	//MFVector.xyz = normalize( $globalViewFwd.xyz );
	MFVector.w = 1.0;


	//float4 localPosition = vertex.position * $vertexXYZScale + $vertexXYZBias;
	//MFOffset = normalize( MFOffset - localPosition );
	//MFVector.x = dot3( MFOffset,    $modelMatrixX );
	//MFVector.y = dot3( MFOffset,    $modelMatrixY );
	//MFVector.z = dot3( MFOffset,    $modelMatrixZ );
	//MFVector.w = 0.0;
}
#endtemplate

/*
==================================================================================
CALC_POSITION_NORMALS

uses vertex.position;
uses vertex.normal;
uses vertex.tangent;

out float4 resultPosition;
out float4 localToGlobalX;
out float4 localToGlobalY;
out float4 localToGlobalZ;
out float4 viewOriginToVertex;
==================================================================================
*/
#template CALC_POSITION_NORMALS( resultPosition, localToGlobalX, localToGlobalY, localToGlobalZ, viewOriginToVertex )
{
	// Convert back from 16 bit vertex elements.
	float4 localPosition = vertex.position * $vertexXYZScale + $vertexXYZBias;
	float4 normal = vertex.normal * 2.0 - 1.0;
	float4 tangent = vertex.tangent * 2.0 - 1.0;
	float3 bitangent = cross( normal.xyz, tangent.xyz ) * tangent.w;

	resultPosition.x = dot4( localPosition, $mvpMatrixX );
	resultPosition.y = dot4( localPosition, $mvpMatrixY );
	resultPosition.z = dot4( localPosition, $mvpMatrixZ );
	resultPosition.w = dot4( localPosition, $mvpMatrixW );

	localToGlobalX.x = dot3( tangent,   $modelMatrixX );
	localToGlobalX.y = dot3( bitangent, $modelMatrixX );
	localToGlobalX.z = dot3( normal,    $modelMatrixX );
	localToGlobalX.w = 0.0;

	localToGlobalY.x = dot3( tangent,   $modelMatrixY );
	localToGlobalY.y = dot3( bitangent, $modelMatrixY );
	localToGlobalY.z = dot3( normal,    $modelMatrixY );
	localToGlobalY.w = 0.0;

	localToGlobalZ.x = dot3( tangent,   $modelMatrixZ );
	localToGlobalZ.y = dot3( bitangent, $modelMatrixZ );
	localToGlobalZ.z = dot3( normal,    $modelMatrixZ );
	localToGlobalZ.w = 0.0;

	viewOriginToVertex.x = dot4( localPosition, $modelMatrixX );
	viewOriginToVertex.y = dot4( localPosition, $modelMatrixY );
	viewOriginToVertex.z = dot4( localPosition, $modelMatrixZ );
	viewOriginToVertex.xyz -= $globalViewOrigin.xyz;
	viewOriginToVertex.w = 0.0;
}
#endtemplate

/*
==================================================================================
CALC_SKINNED_POSITIONS

uses vertex.position;

out float4 localPosition;
out float4 resultPosition;
==================================================================================
*/
// CALC_SKINNED_POSITIONS is a reduced form of CALC_SKINNED_POSITIONS_NORMALS
#template CALC_SKINNED_POSITIONS( localPosition, resultPosition )
{
	// Convert back from 16 bit vertex elements.
	localPosition = vertex.position * $vertexXYZScale + $vertexXYZBias;

#if defined( XBOX )

	if ( bHardwareSkinning ) {
		float4 vertexPosition = localPosition;
		if ( bHardwareMorphing ) {
#if 0
			// Fetch the morph value with inline asm,
			// so it only gets getched when bHardwareMorphing is
			// enabled.  If we just used vertex.morph.xyz, it would
			// always be fetched, and gives streams of Pix warnings
			// when the stream buffer is bound to NULL.
			float4 vertexMorph;
			int		index = vertex.index;
			asm {
				vfetch vertexMorph, index, color2
			};
			float3 morphVector = ( vertexMorph.xyz * 2 ) - 1;
			vertexPosition.xyz += ( morphVector * vertexMorph.w * 32.0f );
#else
			float3 morphVector = ( vertex.morph.xyz * 2 ) - 1;
			vertexPosition.xyz += ( morphVector * vertex.morph.w * 32.0f );
#endif
		}

		// multiplying with 255.1 give us the same result and is faster than floor( w * 255 + 0.5 )
		float weights = vertex.normal.w * 255.1;			// [0,  1] -> [0, 255]
		float w1 = floor( weights / 16 );					// [0, 15] (= 4 bits)
		float w2 = floor( weights / 4 ) - ( w1 * 4 );		// [0,  3] (= 2 bits)
		float w3 = weights - ( w2 * 4 ) - ( w1 * 16 );		// [0,  3] (= 2 bits)

		w1 *= 1.0 / 30.0;									// [0, 15] -> [0, 1/2]
		w2 *= 1.0 / 9.0;									// [0,  3] -> [0, 1/3]
		w3 *= 1.0 / 12.0;									// [0,  3] -> [0, 1/4]

		float w0 = 1 - ( w1 + w2 + w3 );					// [1/4, 1]

		float4 matX, matY, matZ;

		float joint = vertex.color.a * 255.1;
		asm {
			vfetch matX, joint, position1, UseTextureCache=true, RoundIndex = true
			vfetch matY, joint, position2, UseTextureCache=true, RoundIndex = true
			vfetch matZ, joint, position3, UseTextureCache=true, RoundIndex = true
		};

		matX *= w0;
		matY *= w0;
		matZ *= w0;

		float4	tmatX, tmatY, tmatZ;
		joint = vertex.color.b * 255.1;
		asm {
			vfetch tmatX, joint, position1, UseTextureCache=true, RoundIndex = true
			vfetch tmatY, joint, position2, UseTextureCache=true, RoundIndex = true
			vfetch tmatZ, joint, position3, UseTextureCache=true, RoundIndex = true
		};
		matX += tmatX * w1;
		matY += tmatY * w1;
		matZ += tmatZ * w1;

		joint = vertex.color.g * 255.1;
		asm {
			vfetch tmatX, joint, position1, UseTextureCache=true, RoundIndex = true
			vfetch tmatY, joint, position2, UseTextureCache=true, RoundIndex = true
			vfetch tmatZ, joint, position3, UseTextureCache=true, RoundIndex = true
		};
		matX += tmatX * w2;
		matY += tmatY * w2;
		matZ += tmatZ * w2;

		joint = vertex.color.r * 255.1;
		asm {
			vfetch tmatX, joint, position1, UseTextureCache=true, RoundIndex = true
			vfetch tmatY, joint, position2, UseTextureCache=true, RoundIndex = true
			vfetch tmatZ, joint, position3, UseTextureCache=true, RoundIndex = true
		};
		matX += tmatX * w3;
		matY += tmatY * w3;
		matZ += tmatZ * w3;

		localPosition.x = dot4( vertexPosition, matX );
		localPosition.y = dot4( vertexPosition, matY );
		localPosition.z = dot4( vertexPosition, matZ );
		localPosition.w = 1.0;
	}

#elif defined( PS3 )

	if ( hardwareSkinning ) {
		float4 vertexPosition = localPosition;
		if ( hardwareMorphing ) {
			float3 morphVector = ( vertex.morph.xyz * 2 ) - 1;
			vertexPosition.xyz += ( morphVector * vertex.morph.w * 32.0f );
		}

		// multiplying with 255.1 give us the same result and is faster than floor( w * 255 + 0.5 )
		float weights = vertex.normal.w * 255.1;			// [0,  1] -> [0, 255]
		float w1 = floor( weights / 16 );					// [0, 15] (= 4 bits)
		float w2 = floor( weights / 4 ) - ( w1 * 4 );		// [0,  3] (= 2 bits)
		float w3 = weights - ( w2 * 4 ) - ( w1 * 16 );		// [0,  3] (= 2 bits)

		w1 *= 1.0 / 30.0;									// [0, 15] -> [0, 1/2]
		w2 *= 1.0 / 9.0;									// [0,  3] -> [0, 1/3]
		w3 *= 1.0 / 12.0;									// [0,  3] -> [0, 1/4]

		float w0 = 1 - ( w1 + w2 + w3 );					// [1/4, 1]

		float4 matX, matY, matZ;

		float joint = vertex.color.r * 255.1 * 3;
		matX = matrices[joint+0] * w0;
		matY = matrices[joint+1] * w0;
		matZ = matrices[joint+2] * w0;

		joint = vertex.color.g * 255.1 * 3;
		matX += matrices[joint+0] * w1;
		matY += matrices[joint+1] * w1;
		matZ += matrices[joint+2] * w1;

		joint = vertex.color.b * 255.1 * 3;
		matX += matrices[joint+0] * w2;
		matY += matrices[joint+1] * w2;
		matZ += matrices[joint+2] * w2;

		joint = vertex.color.a * 255.1 * 3;
		matX += matrices[joint+0] * w3;
		matY += matrices[joint+1] * w3;
		matZ += matrices[joint+2] * w3;

		localPosition.x = dot4( vertexPosition, matX );
		localPosition.y = dot4( vertexPosition, matY );
		localPosition.z = dot4( vertexPosition, matZ );
		localPosition.w = 1.0;
	}

#elif defined( PC_D3D )

	if ( hardwareSkinning.x != 0.0 ) {
		float4 vertexPosition = localPosition;
		if ( hardwareSkinning.y != 0.0 ) {
			float3 morphVector = ( vertex.morph.xyz * 2 ) - 1;
			vertexPosition.xyz += ( morphVector * vertex.morph.w * 32.0f );
		}

		float weights = vertex.normal.w * 255;				// [0,  1] -> [0, 255]
		float w1 = floor( weights / 16 );					// [0, 15] (= 4 bits)
		float w2 = floor( weights / 4 ) - ( w1 * 4 );		// [0,  3] (= 2 bits)
		float w3 = weights - ( w2 * 4 ) - ( w1 * 16 );		// [0,  3] (= 2 bits)

		w1 *= 1.0 / 30.0;									// [0, 15] -> [0, 1/2]
		w2 *= 1.0 / 9.0;									// [0,  3] -> [0, 1/3]
		w3 *= 1.0 / 12.0;									// [0,  3] -> [0, 1/4]

		float w0 = 1 - ( w1 + w2 + w3 );					// [1/4, 1]

		float4 matX, matY, matZ;

		float joint = vertex.color.r * 255;
		matX = matrices[int(joint*3+0)] * w0;
		matY = matrices[int(joint*3+1)] * w0;
		matZ = matrices[int(joint*3+2)] * w0;

		joint = vertex.color.g * 255;
		matX += matrices[int(joint*3+0)] * w1;
		matY += matrices[int(joint*3+1)] * w1;
		matZ += matrices[int(joint*3+2)] * w1;

		joint = vertex.color.b * 255;
		matX += matrices[int(joint*3+0)] * w2;
		matY += matrices[int(joint*3+1)] * w2;
		matZ += matrices[int(joint*3+2)] * w2;

		joint = vertex.color.a * 255;
		matX += matrices[int(joint*3+0)] * w3;
		matY += matrices[int(joint*3+1)] * w3;
		matZ += matrices[int(joint*3+2)] * w3;

		localPosition.x = dot4( vertexPosition, matX );
		localPosition.y = dot4( vertexPosition, matY );
		localPosition.z = dot4( vertexPosition, matZ );
		localPosition.w = 1.0;
	}

#elif defined( PC )
    // apply vertex morphs
    if ( hardwareSkinning.z != 0.0 ) {
        localPosition += $vertexMorphScale.x * vertex.position1;
    }

	if ( hardwareSkinning.x != 0.0 ) {
		float4 vertexPosition = localPosition;
		if ( hardwareSkinning.y != 0.0 ) {
			float3 morphVector = ( vertex.morph.xyz * 2 ) - 1;
			vertexPosition.xyz += ( morphVector * vertex.morph.w * 32.0f );
		}

		float weights = vertex.normal.w * 255;				// [0,  1] -> [0, 255]
		float w1 = floor( weights / 16 );					// [0, 15] (= 4 bits)
		float w2 = floor( weights / 4 ) - ( w1 * 4 );		// [0,  3] (= 2 bits)
		float w3 = weights - ( w2 * 4 ) - ( w1 * 16 );		// [0,  3] (= 2 bits)

		w1 *= 1.0 / 30.0;									// [0, 15] -> [0, 1/2]
		w2 *= 1.0 / 9.0;									// [0,  3] -> [0, 1/3]
		w3 *= 1.0 / 12.0;									// [0,  3] -> [0, 1/4]

		float w0 = 1 - ( w1 + w2 + w3 );					// [1/4, 1]

		float4 matX, matY, matZ;

		float joint = vertex.color.r * 255;
		matX = matrices[int(joint*3+0)] * w0;
		matY = matrices[int(joint*3+1)] * w0;
		matZ = matrices[int(joint*3+2)] * w0;

		joint = vertex.color.g * 255;
		matX += matrices[int(joint*3+0)] * w1;
		matY += matrices[int(joint*3+1)] * w1;
		matZ += matrices[int(joint*3+2)] * w1;

		joint = vertex.color.b * 255;
		matX += matrices[int(joint*3+0)] * w2;
		matY += matrices[int(joint*3+1)] * w2;
		matZ += matrices[int(joint*3+2)] * w2;

		joint = vertex.color.a * 255;
		matX += matrices[int(joint*3+0)] * w3;
		matY += matrices[int(joint*3+1)] * w3;
		matZ += matrices[int(joint*3+2)] * w3;

		localPosition.x = dot4( vertexPosition, matX );
		localPosition.y = dot4( vertexPosition, matY );
		localPosition.z = dot4( vertexPosition, matZ );
		localPosition.w = 1.0;
	}

#else
#error "unknown platform"
#endif

	resultPosition.x = dot4( localPosition, $mvpMatrixX );
	resultPosition.y = dot4( localPosition, $mvpMatrixY );
	resultPosition.z = dot4( localPosition, $mvpMatrixZ );
	resultPosition.w = dot4( localPosition, $mvpMatrixW );
}
#endtemplate

/*
==================================================================================
CALC_SKINNED_POSITIONS_NORMALS

uses vertex.position;
uses vertex.normal;
uses vertex.tangent;

out float4 localPosition;
out float4 resultPosition;
out float4 localToGlobalX;
out float4 localToGlobalY;
out float4 localToGlobalZ;
out float4 viewOriginToVertex;
==================================================================================
*/

#template CALC_PNT( position, normal, tangent )
{
	// Convert back from 16 bit vertex elements.
	position = vertex.position * $vertexXYZScale + $vertexXYZBias;
	normal = vertex.normal * 2.0 - 1.0;
	tangent = vertex.tangent * 2.0 - 1.0;
	//float morphScale = 0.0f;
}
#endtemplate

// CALC_SKINNED_POSITIONS is a reduced form of CALC_SKINNED_POSITIONS_NORMALS
#template CALC_SKINNED_POSITIONS_NORMALS( localPosition, resultPosition, localToGlobalX, localToGlobalY, localToGlobalZ, viewOriginToVertex, position, normal, tangent, worldPosition )
{
	// Convert back from 16 bit vertex elements.
	//localPosition = vertex.position * $vertexXYZScale + $vertexXYZBias;
	//float4 normal = vertex.normal * 2.0 - 1.0;
	//float4 tangent = vertex.tangent * 2.0 - 1.0;
	float morphScale = 0.0f;

	localPosition = position;

#if defined( XBOX )

	if ( bHardwareSkinning ) {
		float4 vertexPosition = localPosition;
		if ( bHardwareMorphing ) {
#if 0
			// Fetch the morph value with inline asm,
			// so it only gets getched when bHardwareMorphing is
			// enabled.  If we just used vertex.morph.xyz, it would
			// always be fetched, and gives streams of Pix warnings
			// when the stream buffer is bound to NULL.
			float4 vertexMorph;
			int index = vertex.index;
			asm {
				vfetch vertexMorph, index, color2
			};
			float3 morphVector = ( vertexMorph.xyz * 2 ) - 1;
			morphScale = vertexMorph.w;
			vertexPosition.xyz += ( morphVector * morphScale * 32.0f );
#else
			float3 morphVector = ( vertex.morph.xyz * 2 ) - 1;
			morphScale = vertex.morph.w;
			vertexPosition.xyz += ( morphVector * morphScale * 32.0f );
#endif
		}

		// multiplying with 255.1 give us the same result and is faster than floor( w * 255 + 0.5 )
		float weights = vertex.normal.w * 255.1;			// [0,  1] -> [0, 255]
		float w1 = floor( weights / 16 );					// [0, 15] (= 4 bits)
		float w2 = floor( weights / 4 ) - ( w1 * 4 );		// [0,  3] (= 2 bits)
		float w3 = weights - ( w2 * 4 ) - ( w1 * 16 );		// [0,  3] (= 2 bits)

		w1 *= 1.0 / 30.0;									// [0, 15] -> [0, 1/2]
		w2 *= 1.0 / 9.0;									// [0,  3] -> [0, 1/3]
		w3 *= 1.0 / 12.0;									// [0,  3] -> [0, 1/4]

		float w0 = 1 - ( w1 + w2 + w3 );					// [1/4, 1]

		float4 matX, matY, matZ;

		float joint = vertex.color.a * 255.1;
		asm {
			vfetch matX, joint, position1, UseTextureCache=true, RoundIndex = true
			vfetch matY, joint, position2, UseTextureCache=true, RoundIndex = true
			vfetch matZ, joint, position3, UseTextureCache=true, RoundIndex = true
		};

		matX *= w0;
		matY *= w0;
		matZ *= w0;

		float4	tmatX, tmatY, tmatZ;
		joint = vertex.color.b * 255.1;
		asm {
			vfetch tmatX, joint, position1, UseTextureCache=true, RoundIndex = true
			vfetch tmatY, joint, position2, UseTextureCache=true, RoundIndex = true
			vfetch tmatZ, joint, position3, UseTextureCache=true, RoundIndex = true
		};
		matX += tmatX * w1;
		matY += tmatY * w1;
		matZ += tmatZ * w1;

		joint = vertex.color.g * 255.1;
		asm {
			vfetch tmatX, joint, position1, UseTextureCache=true, RoundIndex = true
			vfetch tmatY, joint, position2, UseTextureCache=true, RoundIndex = true
			vfetch tmatZ, joint, position3, UseTextureCache=true, RoundIndex = true
		};
		matX += tmatX * w2;
		matY += tmatY * w2;
		matZ += tmatZ * w2;

		joint = vertex.color.r * 255.1;
		asm {
			vfetch tmatX, joint, position1, UseTextureCache=true, RoundIndex = true
			vfetch tmatY, joint, position2, UseTextureCache=true, RoundIndex = true
			vfetch tmatZ, joint, position3, UseTextureCache=true, RoundIndex = true
		};
		matX += tmatX * w3;
		matY += tmatY * w3;
		matZ += tmatZ * w3;

		localPosition.x = dot4( vertexPosition, matX );
		localPosition.y = dot4( vertexPosition, matY );
		localPosition.z = dot4( vertexPosition, matZ );
		localPosition.w = 1.0;

		float4 tempNormal = normal;
		normal.x = dot3( tempNormal, matX );
		normal.y = dot3( tempNormal, matY );
		normal.z = dot3( tempNormal, matZ );

		float4 tempTangent = tangent;
		tangent.x = dot3( tempTangent, matX );
		tangent.y = dot3( tempTangent, matY );
		tangent.z = dot3( tempTangent, matZ );
	}

#elif defined( PS3 )

	if ( hardwareSkinning ) {
		float4 vertexPosition = localPosition;
		if ( hardwareMorphing ) {
			float3 morphVector = ( vertex.morph.xyz * 2 ) - 1;
			morphScale = vertex.morph.w;
			vertexPosition.xyz += ( morphVector * morphScale * 32.0f );
		}

		// multiplying with 255.1 give us the same result and is faster than floor( w * 255 + 0.5 )
		float weights = vertex.normal.w * 255.1;			// [0,  1] -> [0, 255]
		float w1 = floor( weights / 16 );					// [0, 15] (= 4 bits)
		float w2 = floor( weights / 4 ) - ( w1 * 4 );		// [0,  3] (= 2 bits)
		float w3 = weights - ( w2 * 4 ) - ( w1 * 16 );		// [0,  3] (= 2 bits)

		w1 *= 1.0 / 30.0;									// [0, 15] -> [0, 1/2]
		w2 *= 1.0 / 9.0;									// [0,  3] -> [0, 1/3]
		w3 *= 1.0 / 12.0;									// [0,  3] -> [0, 1/4]

		float w0 = 1 - ( w1 + w2 + w3 );					// [1/4, 1]

		float4 matX, matY, matZ;

		float joint = vertex.color.r * 255.1 * 3;
		matX = matrices[joint+0] * w0;
		matY = matrices[joint+1] * w0;
		matZ = matrices[joint+2] * w0;

		joint = vertex.color.g * 255.1 * 3;
		matX += matrices[joint+0] * w1;
		matY += matrices[joint+1] * w1;
		matZ += matrices[joint+2] * w1;

		joint = vertex.color.b * 255.1 * 3;
		matX += matrices[joint+0] * w2;
		matY += matrices[joint+1] * w2;
		matZ += matrices[joint+2] * w2;

		joint = vertex.color.a * 255.1 * 3;
		matX += matrices[joint+0] * w3;
		matY += matrices[joint+1] * w3;
		matZ += matrices[joint+2] * w3;

		localPosition.x = dot4( vertexPosition, matX );
		localPosition.y = dot4( vertexPosition, matY );
		localPosition.z = dot4( vertexPosition, matZ );
		localPosition.w = 1.0;

		float4 tempNormal = normal;
		normal.x = dot3( tempNormal, matX );
		normal.y = dot3( tempNormal, matY );
		normal.z = dot3( tempNormal, matZ );

		float4 tempTangent = tangent;
		tangent.x = dot3( tempTangent, matX );
		tangent.y = dot3( tempTangent, matY );
		tangent.z = dot3( tempTangent, matZ );
	}

#elif defined( PC_D3D )

		// FIXME_D3D

#elif defined( PC )

    // apply vertex morphs
    if ( hardwareSkinning.z != 0.0 ) {
        localPosition += $vertexMorphScale.x * vertex.position1;
    }

	if ( hardwareSkinning.x != 0.0 ) {
		float4 vertexPosition = localPosition;
		if ( hardwareSkinning.y != 0.0 ) {
			float3 morphVector = ( vertex.morph.xyz * 2 ) - 1;
			morphScale = vertex.morph.w;
			vertexPosition.xyz += ( morphVector * morphScale * 32.0f );
		}

		float weights = vertex.normal.w * 255;				// [0,  1] -> [0, 255]
		float w1 = floor( weights / 16 );					// [0, 15] (= 4 bits)
		float w2 = floor( weights / 4 ) - ( w1 * 4 );		// [0,  3] (= 2 bits)
		float w3 = weights - ( w2 * 4 ) - ( w1 * 16 );		// [0,  3] (= 2 bits)

		w1 *= 1.0 / 30.0;									// [0, 15] -> [0, 1/2]
		w2 *= 1.0 / 9.0;									// [0,  3] -> [0, 1/3]
		w3 *= 1.0 / 12.0;									// [0,  3] -> [0, 1/4]

		float w0 = 1 - ( w1 + w2 + w3 );					// [1/4, 1]

		float4 matX, matY, matZ;

		float joint = vertex.color.r * 255;
		matX = matrices[int(joint*3+0)] * w0;
		matY = matrices[int(joint*3+1)] * w0;
		matZ = matrices[int(joint*3+2)] * w0;

		joint = vertex.color.g * 255;
		matX += matrices[int(joint*3+0)] * w1;
		matY += matrices[int(joint*3+1)] * w1;
		matZ += matrices[int(joint*3+2)] * w1;

		joint = vertex.color.b * 255;
		matX += matrices[int(joint*3+0)] * w2;
		matY += matrices[int(joint*3+1)] * w2;
		matZ += matrices[int(joint*3+2)] * w2;

		joint = vertex.color.a * 255;
		matX += matrices[int(joint*3+0)] * w3;
		matY += matrices[int(joint*3+1)] * w3;
		matZ += matrices[int(joint*3+2)] * w3;

		localPosition.x = dot4( vertexPosition, matX );
		localPosition.y = dot4( vertexPosition, matY );
		localPosition.z = dot4( vertexPosition, matZ );
		localPosition.w = 1.0;

		float4 tempNormal = normal;
		normal.x = dot3( tempNormal, matX );
		normal.y = dot3( tempNormal, matY );
		normal.z = dot3( tempNormal, matZ );

		float4 tempTangent = tangent;
		tangent.x = dot3( tempTangent, matX );
		tangent.y = dot3( tempTangent, matY );
		tangent.z = dot3( tempTangent, matZ );
	}

#else
#error "unknown platform"
#endif

	float3 bitangent = cross( normal.xyz, tangent.xyz ) * tangent.w;

	position = localPosition;

	// vertex position
	resultPosition.x = dot4( localPosition, $mvpMatrixX );
	resultPosition.y = dot4( localPosition, $mvpMatrixY );
	resultPosition.z = dot4( localPosition, $mvpMatrixZ );
	resultPosition.w = dot4( localPosition, $mvpMatrixW );

	// transform matrix from vertex local space to world space
	worldPosition.x = dot4( localPosition, $modelMatrixX );
	worldPosition.y = dot4( localPosition, $modelMatrixY );
	worldPosition.z = dot4( localPosition, $modelMatrixZ );

	// transform matrix from vertex local space to world space
	localToGlobalX.x = dot3( tangent,   $modelMatrixX );
	localToGlobalX.y = dot3( bitangent, $modelMatrixX );
	localToGlobalX.z = dot3( normal,    $modelMatrixX );
	localToGlobalX.w = morphScale;

	localToGlobalY.x = dot3( tangent,   $modelMatrixY );
	localToGlobalY.y = dot3( bitangent, $modelMatrixY );
	localToGlobalY.z = dot3( normal,    $modelMatrixY );
	localToGlobalY.w = 0.0;

	localToGlobalZ.x = dot3( tangent,   $modelMatrixZ );
	localToGlobalZ.y = dot3( bitangent, $modelMatrixZ );
	localToGlobalZ.z = dot3( normal,    $modelMatrixZ );
	localToGlobalZ.w = 0.0;

	// dir from the viewer to the vertex
	viewOriginToVertex.x = dot4( localPosition, $modelMatrixX );
	viewOriginToVertex.y = dot4( localPosition, $modelMatrixY );
	viewOriginToVertex.z = dot4( localPosition, $modelMatrixZ );
	viewOriginToVertex.xyz -= $globalViewOrigin.xyz;
	viewOriginToVertex.w = 0.0;
}
#endtemplate

/*
==================================================================================
CALC_SKINNED_POSITION

uses vertex.position;

out float4 resultPosition;
==================================================================================
*/
#template CALC_SKINNED_POSITION( resultPosition )
{
	float4 localPosition;
	CALC_SKINNED_POSITIONS( localPosition, resultPosition );
}
#endtemplate

/*
==================================================================================
CALC_SKINNED_POSITIONS_NORMALS

uses vertex.position;
uses vertex.normal;
uses vertex.tangent;

out float4 resultPosition;
out float4 localToGlobalX;
out float4 localToGlobalY;
out float4 localToGlobalZ;
out float4 viewOriginToVertex;
==================================================================================
*/
#template CALC_SKINNED_POSITION_NORMALS( resultPosition, localToGlobalX, localToGlobalY, localToGlobalZ, viewOriginToVertex, position, normal, tangent, worldPosition )
{
	float4 localPosition;
	CALC_SKINNED_POSITIONS_NORMALS( localPosition, resultPosition, localToGlobalX, localToGlobalY, localToGlobalZ, viewOriginToVertex, position, normal, tangent, worldPosition );
}
#endtemplate
