#include "ft_acstd.h"

bool        ft_cmp_param(void *state, void *elem)
{
    t_param_def *param;
    char        *av;

    param = (t_param_def *)elem;
    av = (char *)state;
    if (ft_strncmp(av, "--", 2) == 0 && ft_strcmp(av + 2, param->long_name) == 0)
    {
        return (TRUE);
    }
    if (ft_strncmp(av, "-", 1) == 0 && ft_strcmp(av + 1, param->short_name) == 0)
    {
        return (TRUE);
    }
    return (FALSE);
}

int         ft_getopt(t_opts *opts, const char **av, i32 ac)
{
    usize   findex;

    if ((opts->commands = ft_vec(sizeof(t_cmd))) == NULL) {
        return (1);
    }
    if ((opts->params = ft_vec(sizeof(t_param))) == NULL) {
        ft_vec_free(opts->commands);
        return (1);
    }
    while (ac-- > 0)
    {
        if ((findex = ft_vec_find(opts->template.params, av++, &ft_cmp_param)) != (usize)-1)
        {
            ft_putfmt("Found argument at index %d\n", findex);
        }
    }
    return (0);
}

void        ft_useopt(t_opts *opts)
{
    ft_putendl("Usage: ");
    opts->commands++;
    opts->commands--;
}