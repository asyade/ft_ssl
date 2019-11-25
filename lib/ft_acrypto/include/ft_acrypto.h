#ifndef FT_ACRYPTO_H
# define FT_ACRYPTO_H

# include "ft_acstd.h"
# include <stdlib.h>

# define DWA(digest) ((digest).word[0])
# define DWB(digest) ((digest).word[1])
# define DWC(digest) ((digest).word[2])
# define DWD(digest) ((digest).word[3])

typedef union  u_digest {
    u8          raw[16];
    u32         word[4];
}               t_digest;

typedef struct  s_md5_state {
    t_digest    curr;
    t_digest    base;
    usize       index;
    usize       size;
    char        *buffer;
    u32         *cursor;
}               t_md5_state;

/**
 * Output = MD5 hash of input buffer
 *
 * # Parameter
 * - *input*    buffer holding the  data
 * - *ilen*     length of the input data
 * - *output*   MD5 checksum outut data
 */
void        ft_md5(const unsigned char *input, usize ilen, t_digest *output);
u8          *ft_padd(const u8* input, usize ilen, usize *olen, usize extra);
void        ft_dig_set(t_digest *digest, u32 a, u32 b, u32 c, u32 d);

#endif