#include "ft_acrypto.h"

int main(int ac, const char **av, const char **env) {
    (void *)av;
    (void *)env;
    (void *)ac;
    unsigned char output[16] = {0};
    ft_md5(av[1], ft_strlen(av[1]), output);
    char *base = "0123456789abcdef";
    for (int i = 0; i < 16; i++) {
        write(1, &base[output[i] / 16], 1);
        write(1, &base[output[i] % 16], 1);
    }
    return 0;
}