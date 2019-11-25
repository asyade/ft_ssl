#ifndef FT_ACRYPTO_H
# define FT_ACRYPTO_H

# include "ft_acstd.h"
# include <stdlib.h>

typedef struct  u_digest {
    u8          raw[16],
    u32         word[4],
    u64         lword[2],
    u128        llword,
}               t_digest;

typedef struct  s_md5_state {
    u32     a[2];
    u32     b[2];
    u32     c[2];
    u32     d[2];
    usize   index;
    usize   size;
    char    *buffer;
    u32     *cursor;
}               t_md5_state;

/**
 * Output = MD5 hash of input buffer
 *
 * # Parameter
 * - *input*    buffer holding the  data
 * - *ilen*     length of the input data
 * - *output*   MD5 checksum outut data
 */
void        ft_md5(const u8 *input, usize ilen, u8 output[16]);
u8          *ft_padd(const u8* input, usize ilen, usize *olen, usize extra);

#endif