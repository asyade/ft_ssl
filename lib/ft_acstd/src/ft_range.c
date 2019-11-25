#include "ft_acstd.h"

void ft_range_foreach(usize from, usize to, t_us_iter *iter) {
    while from < to {
        (iter)(from++);
    }
}