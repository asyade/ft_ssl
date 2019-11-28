#include "ft_ssl.h"

# define OPT_DEBUG  1
# define CMD_MD5    2
# define CMD_SHA2   3

int                setup_opt(t_opts *opts) {
    t_param_def     def;
    t_cmd_def       cdef;

    if ((opts->template.params = ft_vec(sizeof(t_param_def))) == NULL)
    {
        return (1);
    }
    if ((opts->template.sub = ft_vec(sizeof(t_cmd_def))) == NULL)
    {
        return (1);
    }
    def = (t_param_def) { OPT_DEBUG, "debug", "d", Flag, FALSE };
    ft_vec_push(&opts->template.params, &def);
    cdef = (t_cmd_def) {
        CMD_MD5,
        "md5",
        NULL,
        NULL,
    };
    ft_vec_push(&opts->template.sub, &cdef);
    cdef = (t_cmd_def) {
        CMD_SHA2,
        "sha2",
        NULL,
        NULL,
    };
    ft_vec_push(&opts->template.sub, &cdef);
    return (0);
}

void                md5(t_opts *opts)
{
    t_buffer        *raw;
    usize           raw_len;
    
    if ((raw = ft_fillbuf_fd(0, &raw_len)) == NULL) {
        ft_putendl("FUU");
    }
    printf("## %ld\n\n", raw_len);
    write(1, ft_bufrd(raw, raw_len, 0), raw_len);
}

void                sha2(t_opts *opts)
{
    ft_putendl("SHA2");
}

int                 main(int ac, char **av) {
    t_opts          opts;
    
    if (setup_opt(&opts) != 0)
    {
        return (1);
    }
    if (ft_getopt(&opts, av + 1, ac - 1) != 0)
    {
        ft_useopt(&opts);
        return (1);
    }
    if (opts.match.sub == NULL) {
        ft_putendl_fd("subcommand required: [md5, sha2]", 1);
        return (1);
    }
    if (opts.match.sub->id == CMD_MD5)
    {
        md5(&opts);
    } else if (opts.match.sub->id == CMD_SHA2)
    {
        sha2(&opts);
    }
    return (0);
}