#pragma once

struct hdpQuantizer_t { int step; int offset; };
struct hdpTileQuantization_t {
	hdpQuantizer_t * pQuantizerDC[16];
	hdpQuantizer_t * pQuantizerLP[16];
	hdpQuantizer_t * pQuantizerHP[16];
	unsigned char cNumQPLP, cNumQPHP, cBitsLP, cBitsHP;
};
