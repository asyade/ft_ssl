#ifndef FT_ACSTD_H
# define FT_ACSTD_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

# define PUTFMT_BUFFER_SIZE 128

#define M_LOG10E   0.434294481903251827651
// M_LN2     ln(2)
#define M_LN2      0.693147180559945309417
// M_LN10    ln(10)
#define M_LN10     2.30258509299404568402
// M_PI      pi
#define M_PI       3.14159265358979323846
// M_PI_2    pi/2
#define M_PI_2     1.57079632679489661923
// M_PI_4    pi/4
#define M_PI_4     0.785398163397448309616
// M_1_PI    1/pi
#define M_1_PI     0.318309886183790671538
// M_2_PI    2/pi
#define M_2_PI     0.636619772367581343076
// M_2_SQRTP 2/sqrt(pi)
#define M_2_SQRTPI 1.12837916709551257390
// M_SQRT2   sqrt(2)
#define M_SQRT2    1.41421356237309504880
// M_SQRT1_2  - 1/sqrt(2)
#define M_SQRT1_2  0.707106781186547524401

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

double              ft_sin(double radians);
void                ft_memcpy(void *src, void *dst, usize len);
void                ft_memset(void *dst, char data, usize len);
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