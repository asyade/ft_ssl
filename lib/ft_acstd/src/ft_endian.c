#include "ft_acstd.h"


u64 ft_swap_64(u64 val) {
    u64 tmp;
    
    tmp = val;
    tmp = (tmp & 0xffffffff00000000) >> 32 | (tmp & 0x00000000ffffffff) << 32;
    tmp = (tmp & 0xffff0000ffff0000) >> 16 | (tmp & 0x0000ffff0000ffff) << 16;
    tmp = (tmp & 0xff00ff00ff00ff00) >>  8 | (tmp & 0x00ff00ff00ff00ff) <<  8;
    return tmp;
}

u32 ft_swap_32(u32 val) {
    u32 tmp;
    
    tmp = val;
    tmp = (tmp & 0xffff0000) >> 16 | (tmp & 0x0000ffff) << 16;
    tmp = (tmp & 0xff00ff00) >>  8 | (tmp & 0x00ff00ff) <<  8;
    return tmp;
}

void ft_swap_32_array(u32 *val, usize count) {
    while (count--)
    {
        *val = ft_swap_32(*val);
        val++;
    }
}