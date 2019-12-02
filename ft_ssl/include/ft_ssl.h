#ifndef FT_SSL_H
# define FT_SSL_H

#include "ft_acstd.h"
#include "ft_acrypto.h"


typedef struct      s_ctx
{
    t_opts          opts;
    usize           stdin_len;
    t_buffer        *stdin_raw;
}                   t_ctx;


#endif