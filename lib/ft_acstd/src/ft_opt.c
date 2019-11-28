#include "ft_acstd.h"

bool        ft_cmp_param_def(void *state, void *elem)
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

bool        ft_cmp_cmd_def(void *state, void *elem)
{
    t_cmd_def   *param;
    char        *av;

    param = (t_cmd_def *)elem;
    av = (char *)state;
    if (ft_strcmp(av, param->name) == 0)
    {
        return (TRUE);
    }
    return (FALSE);
}

bool        ft_cmp_param_id(void *state, void *elem)
{
    u32     id;
    t_param *check;

    id = *(u32 *)state;
    check = (t_param *)elem;
    return (id == check->id);
}

int         ft_inicmd(t_cmd *opts) {
    opts->sub = NULL;
    if ((opts->params = ft_vec(sizeof(t_param))) == NULL) {
        ft_putendl("Alloc failed");
        return (1);
    }
    return (0);
}

int         ft_parsecmd(t_cmd_def *cmd, t_cmd *out, char **values, i32 vc) {
    usize       findex;
    t_param_def *def;
    t_param     new;

    while (vc > 0)
    {
        if ((findex = ft_vec_find(cmd->params, (void *)*values, &ft_cmp_param_def)) != (usize)-1)
        {
            def = VPTR(cmd->params, findex);
            if (!def->multiple && ft_vec_find(out->params, &def->id, &ft_cmp_param_id) != (usize)-1) {
                ft_putstr_fd("Error: Duplicate argument: ", 2);
                ft_putendl_fd(def->long_name, 2);
            }
            new.id = def->id;
            new.value = NULL;
            ft_vec_push(&out->params, &new);
        } else if ((findex = ft_vec_find(cmd->sub, (void *)*values, &ft_cmp_cmd_def)) != (usize)-1) {
            if ((out->sub = malloc(sizeof(t_cmd))) == NULL) {
                return (2);
            }
            if (ft_inicmd(out->sub) != 0) {
                return (2);
            }
            out->sub->id = ((t_cmd_def*)VPTR(cmd->sub, findex))->id;
            if(ft_parsecmd(VPTR(cmd->sub, findex), out->sub, ++values, --vc) != 0)
            {
                return (2);
            }
            return (0);
        }
        values++;
        vc -= 1;
    }
    return (0);
}

int         ft_getopt(t_opts *opts, char **av, i32 ac)
{
    if (ft_inicmd(&opts->match) != 0) {
        return (1);
    }
    return (ft_parsecmd(&opts->template, &opts->match, av, ac));    
}

void        ft_useopt(t_opts *opts)
{
    opts++;
    opts--;
    ft_putendl("Usage: ");
}