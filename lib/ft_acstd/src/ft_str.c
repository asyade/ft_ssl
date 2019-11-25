#include "ft_acstd.h"

usize				ft_strlen(const char *str)
{
	usize			len;

	len = 0;
	while (*str++ != '\0')
	{
		len++;
	}
	return (len);
}