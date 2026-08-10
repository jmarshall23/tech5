#pragma once

#include "render_types.h"

struct renderAdapativeGlareParms_t {
	const renderSettings_t * settings;
	const idRenderView * renderView;
	int frameNumber;
	float xScale;
	float yScale;
	float minThreshold;
	float maxThreshold;
	float avgBrightness;
	float decayRate;
	const idRenderDestination * renderDestDefault;
	const idRenderDestination * renderDestViewColor;
	const idRenderDestination * renderDestAdaptiveGlare;
	const idRenderDestination * renderDestAdaptiveGlareAlt;
	const idRenderDestination * renderDestLuminosity;
	const idRenderDestination * renderDestLuminosityAlt;
	const idDeclRenderParm * rpViewColor;
	const idDeclRenderParm * rpGlareMap;
	const idDeclRenderParm * rpAdaptiveGlareMap;
	const idDeclRenderParm * rpAdaptiveGlareMapAlt;
	const idDeclRenderParm * rpDownSample2x2Map;
	const idDeclRenderParm * rpLuminosityMap;
	const idDeclRenderParm * rpLuminosityMapAlt;
	const idDeclRenderParm * rpAdaptiveLuminance;
	const idDeclRenderParm * rpAdaptiveGlareBlurMap;
	const idDeclRenderParm * rpAdaptiveGlareBlurStep;
	const idDeclRenderParm * rpAdaptiveGlareParms;
	const idDeclRenderProg * progLuminosity;
	const idDeclRenderProg * progBloomThreshold;
	const idDeclRenderProg * progAdaptiveGlareGauss;
	const idImage * imgViewColor;
	const idImage * imgGlare;
	const idImage * imgLuminosity;
	const idImage * imgLuminosityAlt;
	const idTriangles * unitSquareTris;
};

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\renderglare.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22928; PDB kind: struct.
struct renderGlareParms_t
{
  const renderSettings_t *settings;
  const idRenderView *renderView;
  float xScale;
  float yScale;
  const idRenderDestination *renderDestDefault;
  const idRenderDestination *renderDestViewColor;
  const idRenderDestination *renderDestMip3;
  const idRenderDestination *renderDestMip3Alt;
  const idImage *imgBlack;
  const idDeclRenderParm *rpGlareMap;
  const idDeclRenderParm *rpGlareStep;
  const idDeclRenderProg *progGauss;
  const idDeclRenderProg *progGlareScale;
  const idTriangles *unitSquareTris;
};

void RenderGlare( const renderGlareParms_t * parms );
void RenderAdaptiveGlare( const renderAdapativeGlareParms_t * parms );
