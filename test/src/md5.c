#include "ft_acrypto.h"

int main(int ac, const char **av, const char **env) {
    (void *)av;
    (void *)env;
    (void *)ac;
    t_digest32 out;
    ft_sha2(av[1], ft_strlen(av[1]), &out);
    char *base = "0123456789abcdef";
    for (int i = 0; i < 32; i++) {
        write(1, &base[out.raw[i] / 16], 1);
        write(1, &base[out.raw[i] % 16], 1);
    }
    write(1, "\n", 1);
    return 0;
}
