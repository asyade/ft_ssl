#include "ft_ssl.h"

int main(int ac, char **av) {
    t_opts opts;
    t_param_def def;

    if ((opts.template.params = ft_vec(sizeof(t_param_def))) == NULL)
    {
        return (1);
    }
    ft_putendl("Loading vec ..");
    def = (t_param_def) { 1, "debug", "d", Flag, FALSE };
    ft_vec_push(opts.template.params, &def);
    def = (t_param_def) { 1, "load", "l", Flag, FALSE };
    ft_vec_push(opts.template.params, &def);
    ft_putendl("get opt ..");

    if (ft_getopt(&opts, av + 1, ac - 1) != 0)
    {
        ft_useopt(&opts);
        return (1);
    }
}