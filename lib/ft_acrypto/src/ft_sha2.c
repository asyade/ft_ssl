#include "ft_acrypto.h"

static u32      K[] = { 0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 };

u32 ft_ch(u32 x, u32 y, u32 z) {
    return (x & y) ^ (~x & z);
}
u32 ft_maj(u32 x, u32 y, u32 z) {
    return (x & y) ^ (x & z) ^ (y & z);
}
u32 ft_e0(u32 x) {
    return RRIGHT(x, 2) ^ RRIGHT(x, 13) ^ RRIGHT(x, 22);
}
u32 ft_e1(u32 x) {
    return RRIGHT(x, 6) ^ RRIGHT(x, 11) ^ RRIGHT(x, 25);
}
u32 ft_s0(u32 x) {
    return RRIGHT(x, 7) ^ RRIGHT(x, 18) ^ (x >> 3);
}
u32 ft_s1(u32 x) {
    return RRIGHT(x, 17) ^ RRIGHT(x, 19) ^ (x >> 10);
}

void            ft_sha2_init( u8 *input, usize ilen, t_sha2_state *state)
{
    u64         bit_len;

    ft_dig32_set(&state->h, (u32[]){ 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 });
    state->buffer = ft_padd(input, ilen, &state->size, 8);//TODO check malloc
    state->index = 0;
    bit_len = ft_swap_64(ilen * 8);
    ft_memcpy(&bit_len, state->buffer + state->size - 8, 8);
}


void            ft_sha2_extend(t_sha2_state *state) {
    isize       idx;

    idx = 0;
    while (idx < 16)
    {
        state->w[idx] = *((u32 *)(state->buffer + state->index) + idx);
        idx++;
    }
    idx = 16;
    while (idx < 64)
    {
        state->w[idx] = state->w[idx-16] + state->w[idx-7] + ft_s0(state->w[idx - 15]) + ft_s1(state->w[idx - 2]);
        idx ++;
    }
}

void            ft_sha2_comp(t_sha2_state *state)
{
    usize       i;
    u32         tmp[2];

    i = 0;
    while (i < 64)
    {
        printf("W %8x\n", state->w[i++]);
    }

    i = 0;
    while (i < 64)
    {
            
        tmp[0] = DWH(state->curr) +
                ft_e1(DWE(state->curr)) +
                ft_ch(DWE(state->curr), DWF(state->curr), DWG(state->curr)) +
                K[i] +
                state->w[i];
        tmp[1] = ft_e0(DWA(state->curr)) + ft_maj(DWA(state->curr), DWB(state->curr), DWC(state->curr));
        printf("%8x %8x %8x k=%8x w=%8x ~ %8x %8x\n", DWH(state->curr),
                ft_e1(DWE(state->curr)),
                ft_ch(DWE(state->curr), DWF(state->curr), DWG(state->curr)),
                K[i],
                state->w[i], tmp[0], tmp[1]);
        ft_dig32_set(&state->curr, (u32[]) {
            tmp[0] + tmp[1],
            DWA(state->curr),
            DWB(state->curr),
            DWC(state->curr),
            DWD(state->curr) + tmp[0],
            DWE(state->curr),
            DWF(state->curr),
            DWG(state->curr)
        });
        // printf("%x %x %x %x %x %x %x %x\n", state->curr.word[0], state->curr.word[1], state->curr.word[2], state->curr.word[3], state->curr.word[4], state->curr.word[5], state->curr.word[6], state->curr.word[7]);
        i++;
    }


}

void            ft_sha2( u8 *input, usize ilen, t_digest32 *output)
{
    t_sha2_state    state;

    ft_sha2_init(input, ilen, &state);
    ft_swap_32_array((u32 *)state.buffer, state.size / 4);
    while (state.index < state.size - 8) {
        ft_memcpy(state.buffer + state.index, (void *)state.w, 16 * sizeof(int));
        ft_sha2_extend(&state);
        state.curr = state.h;
        ft_sha2_comp(&state);
        ft_dig32_add(&state.h, state.curr.word);
        state.index += 64;
    }
    ft_swap_32_array((u32 *)state.h.word, 8);
    *output = state.h;
}