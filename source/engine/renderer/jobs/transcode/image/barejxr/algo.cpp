#include "jxr_compat.h"

int _jxr_floor_div2( const int value ) { return value >= 0 ? value / 2 : -static_cast< int >( ( -value + 1 ) / 2 ); }
int _jxr_ceil_div2( const int value ) { return value >= 0 ? ( value + 1 ) / 2 : -static_cast< int >( ( -value ) / 2 ); }
void _jxr_2ptT( int * a, int * b ) {
	if ( a == nullptr || b == nullptr ) return;
	*b -= *a >> 1; *a += *b;
}
void _jxr_2ptFwdT( int * a, int * b ) {
	if ( a == nullptr || b == nullptr ) return;
	*a -= *b; *b += *a >> 1;
}
void _jxr_2x2IPCT( int * v ) {
	if ( v == nullptr ) return;
	_jxr_2ptT( &v[0], &v[1] ); _jxr_2ptT( &v[2], &v[3] );
	_jxr_2ptT( &v[0], &v[2] ); _jxr_2ptT( &v[1], &v[3] );
}
void _jxr_4x4IPCT( int * v ) {
	if ( v == nullptr ) return;
	for ( int y = 0; y < 4; ++y ) { _jxr_2ptT( &v[y * 4], &v[y * 4 + 2] ); _jxr_2ptT( &v[y * 4 + 1], &v[y * 4 + 3] ); }
	for ( int x = 0; x < 4; ++x ) { _jxr_2ptT( &v[x], &v[8 + x] ); _jxr_2ptT( &v[4 + x], &v[12 + x] ); }
}
void _jxr_4x4PCT( int * v ) {
	if ( v == nullptr ) return;
	for ( int x = 0; x < 4; ++x ) { _jxr_2ptFwdT( &v[x], &v[8 + x] ); _jxr_2ptFwdT( &v[4 + x], &v[12 + x] ); }
	for ( int y = 0; y < 4; ++y ) { _jxr_2ptFwdT( &v[y * 4], &v[y * 4 + 2] ); _jxr_2ptFwdT( &v[y * 4 + 1], &v[y * 4 + 3] ); }
}
