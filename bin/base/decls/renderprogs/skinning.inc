		// Convert back from 16 bit vertex elements.
		float4 position = vertex.position * $vertexXYZScale + $vertexXYZBias;
		
#if defined( XBOX )

		if ( bHardwareSkinning ) {
			float4 vertexPosition = position;
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

			position.x = dot4( vertexPosition, matX );
			position.y = dot4( vertexPosition, matY );
			position.z = dot4( vertexPosition, matZ );
			position.w = 1.0;
		}

#elif defined( PS3 )

		if ( hardwareSkinning ) {
			float4 vertexPosition = position;
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

			position.x = dot4( vertexPosition, matX );
			position.y = dot4( vertexPosition, matY );
			position.z = dot4( vertexPosition, matZ );
			position.w = 1.0;
		}

#elif defined( PC_D3D )

		if ( hardwareSkinning.x != 0.0 ) {
			float4 vertexPosition = position;
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

			position.x = dot4( vertexPosition, matX );
			position.y = dot4( vertexPosition, matY );
			position.z = dot4( vertexPosition, matZ );
			position.w = 1.0;
		}

#elif defined( PC )

		if ( hardwareSkinning.x != 0.0 ) {
			float4 vertexPosition = position;
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

			if ( hardwareSkinning.z == 0.0 ) {
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

				position.x = dot4( vertexPosition, matX );
				position.y = dot4( vertexPosition, matY );
				position.z = dot4( vertexPosition, matZ );
				position.w = 1.0;
			} else {
				float4 dualQuats[ 8 ];
				float joint = vertex.color.r * 255;
				dualQuats[0] = matrices[ int(joint*2+0) ];
				dualQuats[1] = matrices[ int(joint*2+1) ];

				joint = vertex.color.g * 255;
				dualQuats[2] = matrices[ int(joint*2+0) ];
				dualQuats[3] = matrices[ int(joint*2+1) ];

				joint = vertex.color.b * 255;
				dualQuats[4] = matrices[ int(joint*2+0) ];
				dualQuats[5] = matrices[ int(joint*2+1) ];

				joint = vertex.color.a * 255;
				dualQuats[6] = matrices[ int(joint*2+0) ];
				dualQuats[7] = matrices[ int(joint*2+1) ];

				// Find rot directions
				if (dot4(dualQuats[0], dualQuats[2]) < 0.0)
					w1 = -w1;
				if (dot4(dualQuats[0], dualQuats[4]) < 0.0)
					w2 = -w2;
				if (dot4(dualQuats[0], dualQuats[6]) < 0.0)
					w3 = -w3;

				// blend dualquats
				float4 Trans0 = dualQuats[0] * w0;
				float4 Trans1 = dualQuats[1] * w0;
				Trans0 += dualQuats[2] * w1;
				Trans1 += dualQuats[3] * w1;
				Trans0 += dualQuats[4] * w2;
				Trans1 += dualQuats[5] * w2;
				Trans0 += dualQuats[6] * w3;
				Trans1 += dualQuats[7] * w3;

				// Normalize
				float invlen = 1.0/length(Trans0);
				Trans0 *= invlen;
				Trans1 *= invlen;

				float4 LocPos = vertexPosition;
				position.xyz = LocPos.xyz + 2.0 * cross(Trans0.xyz, cross(Trans0.xyz, LocPos.xyz) + Trans0.w * LocPos.xyz);
				position.xyz += 2.0 * (Trans0.w * Trans1.xyz - Trans1.w * Trans0.xyz + cross(Trans0.xyz, Trans1.xyz));
				position.w = 1.0;
			}
		}

#else
#error "unknown platform"
#endif
