#include "ft_acstd.h"

void            ft_memcpy(void *src, void *dst, usize len) {
    const u8*   source = src;
    u8*         dest = dst;
    while (len--) {
        *dest++ = *source++;
    }
}

void            ft_memset(void *dst, char c, usize len) {
    u8*         dest = dst;
    while (len--) {
        *dest++ = c;
    }
}