#include "ft_acstd.h"

bool            ft_memeq(void *a, void *b, usize len)
{
    u8          *aa;
    u8          *bb;

    aa = (u8*)a;
    bb = (u8*)b;
    while (len--) {
        if (*aa++ != *bb++)
        {
            return (FALSE);
        }
    }
    return (TRUE);
}

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