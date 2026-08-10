#pragma once

// The original file was an Xbox command-processor register dump accidentally
// attributed to the DCT directory by PDB source paths.  It has no renderer
// codec API; retain the path as a portable marker instead of publishing the
// invalid nested-type syntax emitted by Hex-Rays.
struct dctReferenceRegisters_t {
	unsigned int value[16];
};
