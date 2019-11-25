#include "ft_acstd.h"

void ft_memcpy(const u8* source, u8* dest, usize len) {
    while (len--) {
        *dest++ = *source++;
    }
}