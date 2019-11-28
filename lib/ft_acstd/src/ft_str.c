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

int		ft_strncmp(const char *a, const char *b, usize n)
{
	char	*ptra;
	char	*ptrb;

	ptra = (char *)a;
	ptrb = (char *)b;
	if (!ptra && !ptrb)
		return (0);
	while (*ptra && *ptrb && *ptra == *ptrb && n--)
	{
		ptra++;
		ptrb++;
	}
	return (n == 0) ? 0 : ((unsigned char)*ptra - (unsigned char)*ptrb);
}

int		ft_strnequ(const char *s1, const char *s2, usize n)
{
	if (!s1 || !s2)
		return (0);
	return (ft_strncmp(s1, s2, n) == 0);
}

int		ft_strcmp(const char *a, const char *b)
{
	char	*ptra;
	char	*ptrb;

	ptra = (char *)a;
	ptrb = (char *)b;
	if (!ptra && !ptrb)
		return (0);
	while (*ptra && *ptrb && *ptra == *ptrb)
	{
		ptra++;
		ptrb++;
	}
	return ((unsigned char)*ptra - (unsigned char)*ptrb);
}
