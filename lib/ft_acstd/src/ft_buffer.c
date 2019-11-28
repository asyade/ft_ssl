#include "ft_acstd.h"

t_buffer            *ft_buf(usize size)
{
    t_buffer        *ret;

    if ((ret = malloc(sizeof(t_buffer) + size)) == NULL)
    {
        return (NULL);
    }
    ret->size = size;
    ft_memset(ret + 1, 42, size);
    return (ret);
}

void                ft_buffree(t_buffer *buffer)
{
    free(buffer);
}

t_buffer            *ft_fillbuf_fd(int fd, usize *outsize)
{
    t_buffer        *buf;
    void            *target;
    isize           rd;

    if ((buf = ft_buf(FILLBUFF_FD_SIZE)) == NULL) {
        return (NULL);
    }
    *outsize = 0;
    target = NULL;
    while (1)
    {
        if ((target = ft_bufwr3(&buf, FILLBUFF_FD_SIZE, *outsize)) == NULL) {
            ft_buffree(buf);
            return (NULL);
        }
        if ((rd = read(fd, target, FILLBUFF_FD_SIZE)) == -1) {
            ft_buffree(buf);
            return (NULL);    
        }
        *outsize += rd;
        if (rd == 0)
        {
            return (buf);
        }
    }
}

// Copy `src` to `dst` at `offset`, return zero or n byte that do not fill in the buffer
i32                 ft_bufwr(t_buffer *dst, void *src, usize len, usize offset)
{
    u8              *rdst;
    u8              *rsrc;

    rsrc = (u8 *)src;
    rdst = (u8 *)(dst + 1) + offset;
    while  (offset < dst->size && len-- > 0)
    {
        *rdst++ = *rsrc++;
        offset++;
    }
    return (len);
}

i32                ft_bufexpand(t_buffer **buffer, size_t new_size)
{
    t_buffer        *new;

    if (new_size <= (*buffer)->size)
    {
        return (0);
    }
    if ((new = ft_buf(new_size)) == NULL)
    {
        return (1);
    }
    ft_bufwr(new, (*buffer) + 1, (*buffer)->size, 0);
    *buffer = new;
    return (0);
}

// Same as `ft_bufwr` but try to expand the buffer size by two if len + offset is bigger than the buffer size
i32                 ft_bufwr2(t_buffer **dst, void *src, usize len, usize offset)
{
    if (len + offset > (*dst)->size)
    {
        ft_bufexpand(dst, (*dst)->size * 2);
    }
    return (ft_bufwr(*dst, src, len, offset));
}

void                 *ft_bufwr3(t_buffer **dst, usize len, usize offset)
{
    if (len + offset > (*dst)->size)
    {
        ft_bufexpand(dst, (*dst)->size * 2);
    }
    return (ft_bufrd(*dst, len, offset));
}

// Return a pointer to the desired area if len+offset isnt bigger than the buffer size, else a NULL ptr is returned
void                *ft_bufrd(t_buffer *rc, usize len, usize offset)
{
    if (rc->size >= len + offset)
    {
        return ((u8 *)(rc + 1) + offset);
    }
    else
    {
        return (NULL);
    }
}

