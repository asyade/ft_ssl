#include "ft_acrypto.h"

static const        u32 K[] = { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501, 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821, 0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };
static const        u32 S[] = { 7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22, 5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20, 4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23, 6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21 };

int                 ft_md5_init(unsigned char *input, usize ilen, t_md5_state *state)
{
    u32             bit_len;

    ft_dig16_set(&state->base, 0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476);
    state->index = 0;
    state->size = 0;
    if ((state->buffer = (char *)ft_padd(input, ilen, &state->size, 4)) == NULL)
        return (1);
    bit_len = ilen * 8;
    ft_memcpy(&bit_len, state->buffer + state->size - 4, 4);
    return (0);
}

void                ft_md5_shift(t_md5_state *state, usize idx, u32 *f, u32 *g) {
    if (idx < 16)
    {
        *f = MD5_F(state->curr);
        *g = idx;
    }
    else if (idx < 32)
    {
        *f = MD5_G(state->curr);
        *g = (5 * idx + 1) % 16;
    }
    else if (idx < 48)
    {
        *f = MD5_H(state->curr);
        *g = (3 * idx + 5) % 16;
    }
    else
    {
        *f = MD5_I(state->curr);
        *g = (7 * idx) % 16;
    }
}

void                ft_md5_round(t_md5_state *state)
{
    usize           idx;
    u32             f;
    u32             g;
    u32             f_rot;

    idx = 0;
    while (idx < 64)
    {
        ft_md5_shift(state, idx, &f, &g);
        f = f + DWA(state->curr) + K[idx] + state->cursor[g];
        f_rot = RLEFT(f, S[idx]);
        ft_dig16_set(&state->curr, DWD(state->curr), DWB(state->curr) + f_rot, DWB(state->curr), DWC(state->curr));
        idx++;
    }
}

void                ft_md5( unsigned char *input, usize ilen, t_digest16 *output)
{
    t_md5_state     state;

    if (ft_md5_init(input, ilen, &state) != 0) {
        return;
    }
    while (state.index < state.size - 4) {
        state.cursor = (u32*)(state.buffer + state.index);
        state.curr = state.base;
        ft_md5_round(&state);
        ft_dig16_add(&state.base, DWA(state.curr), DWB(state.curr), DWC(state.curr), DWD(state.curr));
        state.index += 64;
    }
    *output = state.base;
    free(state.buffer);
}
