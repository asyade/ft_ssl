#include "ft_acstd.h"

#include <stdlib.h>
void    ft_panic(const char *msg)
{
    ft_putfmt("PANIC: %s\n", msg);
    exit(1);
}
