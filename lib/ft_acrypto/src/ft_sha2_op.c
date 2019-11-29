#include "ft_acrypto.h"

u32         ft_ch(u32 x, u32 y, u32 z) {
    return (x & y) ^ (~x & z);
}

u32         ft_maj(u32 x, u32 y, u32 z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

u32         ft_e0(u32 x) {
    return RRIGHT(x, 2) ^ RRIGHT(x, 13) ^ RRIGHT(x, 22);
}

u32         ft_e1(u32 x) {
    return RRIGHT(x, 6) ^ RRIGHT(x, 11) ^ RRIGHT(x, 25);
}

u32         ft_s0(u32 x) {
    return RRIGHT(x, 7) ^ RRIGHT(x, 18) ^ (x >> 3);
}

u32         ft_s1(u32 x) {
    return RRIGHT(x, 17) ^ RRIGHT(x, 19) ^ (x >> 10);
}
