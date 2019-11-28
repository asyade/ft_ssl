#ifndef FT_ACRYPTO_H
# define FT_ACRYPTO_H

# include <ft_acstd.h>
# include <stdlib.h>

# define PANIC(str) (ft_panic(str))

# define RRIGHT(r, n) ((r >> n) | (r << (32 - n)))
# define RLEFT(r, n) ((r << n) | (r >> (32 - n)))

# define DWA(digest) ((digest).word[0])
# define DWB(digest) ((digest).word[1])
# define DWC(digest) ((digest).word[2])
# define DWD(digest) ((digest).word[3])
# define DWE(digest) ((digest).word[4])
# define DWF(digest) ((digest).word[5])
# define DWG(digest) ((digest).word[6])
# define DWH(digest) ((digest).word[7])

# define MD5_F(st) (DWB(st) & DWC(st) | ((~(DWB(st))) & DWD(st)))
# define MD5_G(st) ((DWD(st) & DWB(st)) | (DWC(st) & (~DWD(st))))
# define MD5_H(st) (DWB(st) ^ DWC(st) ^ DWD(st))
# define MD5_I(st) (DWC(st) ^ (DWB(st) | (~DWD(st))))

typedef union  u_digest16 {
    u8          raw[16];
    u32         word[4];
}               t_digest16;

typedef union  u_digest512 {
    u8          raw[32];
    u32         word[8];
}               t_digest32;

typedef struct  s_md5_state {
    t_digest16  curr;
    t_digest16  base;
    usize       index;
    usize       size;
    char        *buffer;
    u32         *cursor;
}               t_md5_state;

typedef struct  s_sha2_state
{
    t_digest32  h;
    t_digest32  curr;
    u8          *buffer;
    usize       size;
    usize       index;
    u32         w[64];
}               t_sha2_state;

/**
 * Output = MD5 hash of input buffer
 *
 * # Parameter
 * - *input*    buffer holding the  data
 * - *ilen*     length of the input data
 * - *output*   MD5 checksum outut data
 */
void        ft_md5(const u8 *input, usize ilen, t_digest16 *output);
void        ft_sha2(const u8 *input, usize ilen, t_digest32 *output);
u8          *ft_padd(const u8* input, usize ilen, usize *olen, usize extra);
void        ft_dig16_set(t_digest16 *digest, u32 a, u32 b, u32 c, u32 d);
void        ft_dig16_add(t_digest16 *digest, u32 a, u32 b, u32 c, u32 d);
void        ft_dig32_set(t_digest32 *digest, u32 val[8]);
void        ft_dig32_add(t_digest32 *digest, u32 val[8]);

#endif