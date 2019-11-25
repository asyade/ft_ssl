#include "ft_acrypto.h"

static const  u32 K[] = { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,  0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,  0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,  0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,  0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,  0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,  0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,  0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,  0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,  0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,  0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,  0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,  0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,  0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,  0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,  0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };
static const  u32 S[] = { 7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22, 5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20, 4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23, 6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21 };

unsigned char *ft_padd(const unsigned char* input, usize ilen, usize *olen) {
    unsigned    char *buffer;
    usize       new_len;

    new_len = ((((ilen + 8) / 64) + 1) * 64) - 8;
    printf("%d == %d\n", ilen, new_len);
    *olen = new_len;
    if ((buffer = malloc(new_len)) == NULL) {
        return NULL;
    }
    ft_memcpy(input, buffer, ilen);
    buffer[ilen] = 0X80;
    int i = ilen;
    while (++i < new_len ) {
        buffer[i] = 0x00;
    }
    u32 blen = 8 * ilen;
    ft_memcpy(&blen, buffer + new_len, 4);
    printf("\n");

    for(int j =0; j < new_len; j++) printf("%x ",  buffer[j]);
    printf("\n");
    return (buffer);
}

int        ft_md5_init(const unsigned char *input, usize ilen, t_md5_state *state)
{
    state->a[0] = 0x67452301;
    state->b[0] = 0xefcdab89;
    state->c[0] = 0x98badcfe;
    state->d[0] = 0x10325476;
    state->index = 0;
    state->size = 0;
    if ((state->buffer = ft_padd(input, ilen, &state->size)) == NULL) {
        ft_putfmt("ERROR\n");
        return 1;
    }
    return 0;
}

u32         ft_leftrot(u32 val, u32 rcount)
{
    return ((val << rcount) | (val >> (32 - rcount)));
}

u32         fn_f(u32 b, u32 c, u32 d)
{
    return ((b & c) | ((~b) & d));    
}

u32         fn_g(u32 b, u32 c, u32 d)
{
    return ((d & b) | (c & (~d)));
}

u32         fn_h(u32 b, u32 c, u32 d)
{
    return (b ^ c ^ d);
}

u32         fn_i(u32 b, u32 c, u32 d)
{
    return (c ^ (b | (~d)));
}

void        ft_md5_round(t_md5_state *state)
{
    usize       idx;
    u32         f;
    u32         g;

    idx = 0;
    while (idx < 64)
    {
        if (idx < 16)
        {
            f = fn_f(state->b[1], state->c[1], state->d[1]);
            g = idx;
        }
        else if (idx < 32)
        {
            f = fn_g(state->b[1], state->c[1], state->d[1]);
            g = (5 * idx + 1) % 16;
        }
        else if (idx < 48)
        {
            f = fn_h(state->b[1], state->c[1], state->d[1]);
            g = (3 * idx + 5) % 16;
        }
        else
        {
            f = fn_i(state->b[1], state->c[1], state->d[1]);
            g = (7 * idx) % 16;
        }
        f = f + state->a[1] + K[idx] + state->cursor[g];
        state->a[1] = state->d[1];
        state->d[1] = state->c[1];
        state->c[1] = state->b[1];
        state->b[1] = state->b[1] + ft_leftrot(f, S[idx]);
        idx++;
    }
}

void        ft_md5(const unsigned char *input, usize ilen, unsigned char output[16])
{
    t_md5_state state;
    u32         f;
    u32         g;

    if (ft_md5_init(input, ilen, &state) != 0) {
        return 1;
    }
    //printf("%d\n", state.size);
    while (state.index < state.size) {
        state.cursor = (i32*)(state.buffer + state.index);
    //    printf("\n");
        state.a[1] = state.a[0];
        state.b[1] = state.b[0];
        state.c[1] = state.c[0];
        state.d[1] = state.d[0];
        ft_md5_round(&state);
        state.a[0] += state.a[1];
        state.b[0] += state.b[1];
        state.c[0] += state.c[1];
        state.d[0] += state.d[1];
        state.index += 64;
    }
    u32 *buffer = (u32*)output;
    buffer[0] = state.a[0];
    buffer[1] = state.b[0];
    buffer[2] = state.c[0];
    buffer[3] = state.d[0];
}
