#pragma once

#include "../../shared/idlib/math/vector.h"
#include "../../shared/idlib/text/atomicstring.h"

class idMaterial;
struct idVmtrCPU;

class idVirtualMaterial {
public:
	enum vmtrFlag_t : int {
		VF_TRANSMAP = 1,
		VF_NO_BORDER = 2
	};

	idVirtualMaterial();

	idAtomicString materialName;
	unsigned int materialChecksum;
	unsigned int cpuVmtrTimeStamp;
	int allocX;
	int allocY;
	int allocWidth;
	int allocHeight;
	int flags;
	const idMaterial * material;
	const idVmtrCPU * cpuVmtr;
	idVec4 scaleAndBias;
};
