#include "ft_acrypto.h"

void ft_dig_set(t_digest *digest, u32 a, u32 b, u32 c, u32 d)
{
    digest->word[0] = a;
    digest->word[1] = b;
    digest->word[2] = c;
    digest->word[3] = d;
}
