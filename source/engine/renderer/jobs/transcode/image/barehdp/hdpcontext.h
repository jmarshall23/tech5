#pragma once

#include "hdpbitio.h"

struct hdpContext_t {
	hdpBitIO_t * bitIODC;
	hdpBitIO_t * bitIOLP;
	hdpBitIO_t * bitIOHP;
	hdpBitIO_t * bitIOFL;
	unsigned char adaptiveState[512];
	int trimTileFlexBits;
};

using HCONTEXT = void *;
