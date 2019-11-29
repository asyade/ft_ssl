#include "ft_acrypto.h"

u8       *ft_padd(u8* input, usize ilen, usize *olen, usize extra) {
    unsigned        char *buffer;
    usize           new_len;

    new_len = ((((ilen+8) / 64) + 1) * 64) - 8;
    *olen = new_len;
    if ((buffer = malloc(new_len + extra)) == NULL)
        return NULL;
    ft_memcpy(input, buffer, ilen);
    ft_memset(buffer + ilen + 1, 0x00, new_len - ilen);
    buffer[ilen] = 0X80;
    return (buffer);
}
