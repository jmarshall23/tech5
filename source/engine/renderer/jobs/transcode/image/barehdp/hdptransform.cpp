#include <utility>

void Hadamard2x2dnStage1( int * a, int * b, int * c, int * d ) {
	if ( !a || !b || !c || !d ) return;
	const int x0 = *a + *d, x1 = *b + *c, x2 = *b - *c, x3 = *a - *d;
	*a = x0 + x1; *b = x3 + x2; *c = x0 - x1; *d = x3 - x2;
}
void Hadamard2x2upStage1( int * a, int * b, int * c, int * d ) { Hadamard2x2dnStage1( a, b, c, d ); }
void Hadamard2x2dnStage2( int * a, int * b, int * c, int * d ) { Hadamard2x2dnStage1( a, b, c, d ); }
void Hadamard2x2upStage2( int * a, int * b, int * c, int * d ) { Hadamard2x2dnStage1( a, b, c, d ); }
