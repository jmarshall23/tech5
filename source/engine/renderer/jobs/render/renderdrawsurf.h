#pragma once

#include "rendercapture.h"

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\renderdrawsurf.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22829; PDB kind: struct.
struct renderDrawSurfParms_t
{
  const renderSettings_t *settings;
  const idRenderView *renderView;
  bool allowInGameGUIs;
  captureParms_t captureParms;
  const idRenderDestination *renderDestDefault;
  const idRenderDestination *renderDestGui;
};

// IDA Local Type ordinal 22910; PDB kind: class.
class idRenderDrawSurf
{
public:
	idRenderDrawSurf() : currentModel( nullptr ) {}
	~idRenderDrawSurf() { PopModel(); }
	void RenderDrawSurf( const renderDrawSurfParms_t * parms,
		const drawSurf_t * drawSurf, glStateBits_t extraState = 0 );

  const idRenderModelCommitted *currentModel;

private:
	void PushModel( const renderDrawSurfParms_t * parms,
		const idRenderModelCommitted * model );
	void PopModel();
};

void RenderGui( const idRenderModelCommitted * model,
	const renderSettings_t * settings, const idRenderView * renderView,
	bool allowInGameGUIs );
