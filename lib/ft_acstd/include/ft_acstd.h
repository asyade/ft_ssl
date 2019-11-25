#ifndef FT_ACSTD_H
# define FT_ACSTD_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

# define PUTFMT_BUFFER_SIZE 128


typedef char        i8;
typedef short       i16;
typedef int         i32;
typedef long        i64;
typedef long long   i128;

typedef unsigned char        u8;
typedef unsigned short       u16;
typedef unsigned int         u32;
typedef unsigned long        u64;
typedef unsigned long long   u128;

typedef u64 usize;
typedef i64 isize;

void                ft_memcpy(const u8* source, u8* dest, usize len);
void				ft_putstr_fd(const char *str, int fd);
void				ft_pustr(const char *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(const char *str, int fd);
void				ft_putendl(const char *str);
void				ft_putchar_buff_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_strncmp(const char * a, const char * b, usize n);
usize				ft_strlen(const char *str);
void				ft_putnbrbase_fd(u128 nbr, const char *base, i32 fd);
i32					ft_ulllen(u128 nbr);
void				ft_putull_fd(u128 nbr, i32 fd);
void				ft_putstr_fd(const char *str, int fd);
void				ft_pustr(const char *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(const char *str, int fd);
void				ft_putendl(const char *str);
void				ft_putfmt(const char *fmt, ...);
void                ft_log(const char *fmt, ...);
void                ft_error(const char *fmt, ...);
void                ft_warn(const char *fmt, ...);
void                ft_panic(const char *fmt, ...);

#endif