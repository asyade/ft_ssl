#ifndef FT_ACSTD_H
# define FT_ACSTD_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define PUTFMT_BUFFER_SIZE 128

# define TRUE 1
# define FALSE 0

// Primitive types



typedef char        bool;
typedef char        i8;
typedef short       t_i16;
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

/// Arguments parsing

typedef struct      s_vec
{
    usize           len;
    usize           capacity;
    usize           elem_size;
}                   t_vec;

typedef enum        e_param_kind
{
    Flag,
    String,
    I32,
    U32,
}                   t_param_kind;

typedef struct      s_param_def
{
    u32             id;
    char              *long_name;
    char              *short_name;
    t_param_kind    kind;
    bool            multiple;
}                   t_param_def;

typedef struct      s_opts_def
{
    t_vec           *params;
}                   t_opts_def;    

typedef struct      s_param {
    u32             id;
    char              *value;
}                   t_param;

typedef struct      s_cmd
{
    u32             id;
    t_vec           *params;
    t_vec           *subcmds;
}                   t_cmd;

typedef struct      s_opts
{
    t_opts_def      template;
    t_vec           *params;
    t_vec           *commands;
}                   t_opts;

int         ft_getopt(t_opts *opts, const char **av, i32 ac);
void        ft_useopt(t_opts *opts);

// VEC

// Get a raw ptr to the element at index
# define VPTR(vec, idx) ((void *)((usize)((vec) + 1) + (vec)->elem_size * idx))
// Get size in byte of n elements in the vector
# define VSIZE(vec, n) ((vec)->elem_size * n)
// Convert a vec ptr into a raw ptr to the first element
# define VINTO(vec) ((void *)(vec + 1))
// Convert a raw ptr obtained using VINTO into a vec* ptr
# define VFROM(vec) (((t_vec *)vec) - 1)


usize               ft_vec_push(t_vec **vec, void *elem);
int                 ft_vec_extend(t_vec **vec, usize capacity);
int                 ft_vec_append(t_vec **vec, t_vec *elems);
void                ft_vec_free(t_vec *vec);
t_vec               *ft_vec_capacity(usize capacity, usize elem_size);
t_vec               *ft_vec(usize elem_size);
usize               ft_vec_find(t_vec *vec, void *state, bool (*cmp)(void *state, void *item));


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
void                ft_panic(const char *msg);
i32		            ft_strcmp(const i8 *a, const i8 *b);
i32		            ft_strnequ(const i8 *s1, const i8 *s2, usize n);
i32		            ft_strncmp(const i8 *a, const i8 *b, usize n);
bool                ft_memeq(void *a, void *b, usize len);

#endif