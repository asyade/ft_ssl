#include "ft_acstd.h"


void				ft_putstr_fd(const char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void				ft_pustr(const char *str)
{
	ft_putstr_fd(str, 1);
}

void				ft_putchar_fd(char c, int fd)
{
	write(1, &c, fd);
}

void				ft_putendl_fd(const char *str, int fd)
{
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
}

void				ft_putendl(const char *str)
{
	ft_putendl_fd(str, 1);
}