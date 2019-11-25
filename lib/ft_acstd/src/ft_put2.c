#include "ft_acstd.h"

static void			ft_putnbrbase_fd_inner(u128 nbr, const char *base,
											usize baselen, i32 fd)
{
	if (nbr >= baselen)
	{
		ft_putnbrbase_fd_inner(nbr / baselen, base, baselen, fd);
		ft_putnbrbase_fd_inner(nbr % baselen, base, baselen, fd);
	}
	else
		ft_putchar_buff_fd(base[nbr], fd);
}

void				ft_putnbrbase_fd(u128 nbr, const char *base, i32 fd)
{
	ft_putnbrbase_fd_inner(nbr, base, ft_strlen(base), fd);
}

i32					ft_ulllen(u128 nbr)
{
	i32 len;

	len = 1;
	while ((nbr /= 10) > 0)
		len++;
	return (len);
}

void				ft_putull_fd(u128 nbr, i32 fd)
{
	if (nbr > 9)
		ft_putull_fd(nbr / 10, fd);
	ft_putchar_buff_fd((nbr % 10) + '0', fd);
}
