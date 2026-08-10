#include "baredct.h"

idBareDctDecoder::idBareDctDecoder() {}

void idBareDctDecoder::SetHuffmanTables( const idBareDCTHuffmanTable *,
		const idBareDCTHuffmanTable *, const idBareDCTHuffmanTable *,
		const idBareDCTHuffmanTable *, const idBareDCTHuffmanTable *,
		const idBareDCTHuffmanTable * ) {
	// WIC owns canonical JPEG entropy tables on Windows.
}

