#include "ft_acstd.h"

t_vec               *ft_vec(usize elem_size)
{
    return (ft_vec_capacity(128, elem_size));
}

t_vec               *ft_vec_capacity(usize capacity, usize elem_size)
{
    t_vec           *buffer;

    if ((buffer = malloc((capacity * elem_size) + sizeof(t_vec))) == NULL) {
        return (NULL);
    }
    buffer->capacity = capacity;
    buffer->elem_size = elem_size;
    buffer->len = 0;
    return (buffer);
}

void               ft_vec_free(t_vec *vec)
{
    free(vec);
}

int                 ft_vec_append(t_vec **vec, t_vec *elems) {
    if ((*vec)->elem_size != elems->elem_size) {
        ft_panic("Operation betwen two different sized `vec`");
    }
    if (ft_vec_extend(vec, (*vec)->len + elems->len) != 0) {
        return (2);
    }
    if (elems->len == 0) {
        return (0);
    }
    ft_memcpy(VPTR(elems, 0), VPTR(*vec, (*vec)->len), VSIZE(*vec, (*vec)->len));
    return (0);
}

/*
** Extend the capacity of the buffer, returning new vec address
** return NULL on allocation error keeping the source vec
*/
int                 ft_vec_extend(t_vec **vec, usize capacity)
{
    t_vec           *target;

    if ((*vec)->capacity >= capacity) {
        return (0);
    }
    if ((target = ft_vec_capacity(capacity, (*vec)->elem_size)) == NULL) {
        return (1);
    }
    // Ignore append result, this can't fail: capacity is enough to hold vec
    ft_vec_append(&target, *vec);
    ft_vec_free(*vec);
    *vec = target;
    return (0);
}

/*
** Push an element at the end of the buffer and return his index
** Return extend the buffer size if there is no space left
** return -1 on allocation failure
*/
usize               ft_vec_push(t_vec **vec, void *elem)
{
    if ((*vec)->capacity == (*vec)->len && ft_vec_extend(vec, (*vec)->capacity * 2) != 0)
    {
        return (-1);
    }
    ft_putendl("Do coupy");
    ft_memcpy(elem, VPTR(*vec, (*vec)->len), (*vec)->elem_size);
    return ((*vec)->len++);
}

usize               ft_vec_find(t_vec *vec, void *state, bool (*cmp)(void *state, void *item))
{
    usize           idx;

    idx = 0;
    while (idx < vec->len)
    {
        if ((cmp)(state, VPTR(vec, idx))) {
            return (idx);
        }
    }
    return (-1);
}