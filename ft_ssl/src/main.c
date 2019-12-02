#include "ft_ssl.h"

# define OPT_DEBUG      1
# define CMD_MD5        2
# define CMD_SHA256     3
# define CMD_SHA224     4
# define OPT_VAL        5

t_vec               *md5_opt()
{
    t_vec           *params;
    t_param_def     def;

    if ((params = ft_vec(sizeof(t_param_def))) == NULL)
    {
        return (NULL);
    }
    def = (t_param_def){
        OPT_VAL,
        "string",
        "s",
        String,
        FALSE,
    };
    ft_vec_push(&params, &def);
    return (params);
}

int                setup_opt(t_opts *opts)
{
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
        md5_opt(),
        NULL,
    };
    ft_vec_push(&opts->template.sub, &cdef);
    cdef = (t_cmd_def) {
        CMD_SHA256,
        "sha256",
        NULL,
        NULL,
    };
    ft_vec_push(&opts->template.sub, &cdef);
    cdef = (t_cmd_def) {
        CMD_SHA224,
        "sha224",
        NULL,
        NULL,
    };
    ft_vec_push(&opts->template.sub, &cdef);
    return (0);
}

void                md5(t_ctx *ctx)
{
    ctx++;
}

void                sha256(t_ctx *ctx)
{
    ctx++;
}

void                sha224(t_ctx *ctx)
{
    ctx++;
}

int                 main(int ac, char **av) {
    t_ctx           context;
    t_param         *pval;
    if (setup_opt(&context.opts) != 0)
    {
        return (1);
    }
    if (ft_getopt(&context.opts, av + 1, ac - 1) != 0)
    {
        ft_useopt(&context.opts);
        return (1);
    }
    if (context.opts.match.sub == NULL) {
        ft_putendl_fd("subcommand required: [md5, sha256, sha224]", 1);
        return (1);
    }
    context.stdin_raw = NULL;

        printf("FOund value\n");

    if  ((pval = ft_opt_param(context.opts.match.sub, OPT_VAL)) != NULL) {
        printf("FOund value\n");
        printf("%s\n", pval->value);
    } else {
        context.stdin_raw = ft_fillbuf_fd(0, &context.stdin_len);
    }
    if (context.opts.match.sub->id == CMD_MD5)
    {
        md5(&context);
    }
    else if (context.opts.match.sub->id == CMD_SHA256)
    {
        sha256(&context);
    } 
    else if (context.opts.match.sub->id == CMD_SHA224)
    {
        sha224(&context);
    }
    return (0);
}

