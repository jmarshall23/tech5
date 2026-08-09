#pragma once

#include "idlib/text/tokenstatic.h"

enum Tokens : int {
    TOK_basedLp = 0,
    TOK_cdecl,
    TOK_pascal,
    TOK_stdcall,
    TOK_thiscall,
    TOK_fastcall,
    TOK_cocall,
    TOK_eabi,
    TOK_ptr64,
    TOK_restrict,
    TOK_unaligned,
    TOK__last
};

typedef idTokenStatic<256> token_t;

