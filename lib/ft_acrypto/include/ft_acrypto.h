#ifndef FT_ACRYPTO_H
# define FT_ACRYPTO_H

# include "ft_acstd.h"
# include <stdlib.h>

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
void ft_md5(const unsigned char *input, usize ilen, unsigned char output[16]);
#endif