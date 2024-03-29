#include "ft_acstd.h"

void				ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
		ft_putchar_buff_fd('-', fd);
	nb = ((n > 0) ? n : -n);
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_buff_fd((nb % 10) + '0', fd);
}

void				ft_putchar_buff_fd(char c, int fd)
{
	static usize	index = 0;
	static char		buffer[PUTFMT_BUFFER_SIZE] = {0};

	buffer[index++] = c;
	if (c == '\n' || index == PUTFMT_BUFFER_SIZE - 1)
	{
		write(fd, buffer, index);
		index = 0;
	}
}

void				ft_putfmt_inner(const char * fmt, usize *i, va_list args)
{
	if (fmt[*i] == '%')
	{
		if (ft_strncmp(fmt + *i + 1, "u", 1) == 0)
		{
			ft_putull_fd(va_arg(args, u128), 1);
			*i += 2;
		}
		else if (fmt[*i + 1] == 'x' || fmt[*i + 1] == 'p')
		{
			ft_putnbrbase_fd(va_arg(args, u128), "0123456789ABCDEF", 1);
			*i += 2;
		}
		else if (fmt[*i + 1] == 'd')
		{
			ft_putnbr_fd(va_arg(args, int), 1);
			*i += 2;
		}
		else
			ft_putchar_fd(fmt[*i], 1);
	}
	ft_putchar_buff_fd(fmt[*i], 1);
}

void				ft_putfmt(const char * fmt, ...)
{
	va_list			args;
	usize			i;
	usize			len;

	len = ft_strlen(fmt);
	i = 0;
	va_start(args, fmt);
	while (i < len)
	{
		ft_putfmt_inner(fmt, &i, args);
		i++;
	}
}
