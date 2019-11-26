#include "ft_acrypto.h"

void ft_dig16_set(t_digest16 *digest, u32 a, u32 b, u32 c, u32 d)
{
    digest->word[0] = a;
    digest->word[1] = b;
    digest->word[2] = c;
    digest->word[3] = d;
}

void ft_dig16_add(t_digest16 *digest, u32 a, u32 b, u32 c, u32 d)
{
    digest->word[0] += a;
    digest->word[1] += b;
    digest->word[2] += c;
    digest->word[3] += d;
}

void ft_dig32_add(t_digest32 *digest, u32 add[8])
{
    digest->word[0] += add[0];
    digest->word[1] += add[1];
    digest->word[2] += add[2];
    digest->word[3] += add[3];
    digest->word[4] += add[4];
    digest->word[5] += add[5];
    digest->word[6] += add[6];
    digest->word[7] += add[7];
}

void ft_dig32_set(t_digest32 *digest, u32 val[8])
{
    digest->word[0] = val[0];
    digest->word[1] = val[1];
    digest->word[2] = val[2];
    digest->word[3] = val[3];
    digest->word[4] = val[4];
    digest->word[5] = val[5];
    digest->word[6] = val[6];
    digest->word[7] = val[7];
}
