LIB=-I lib/ft_acrypto/include/ -I lib/ft_acstd/include/ lib/ft_acstd/obj/* lib/ft_acrypto/obj/*

all:
	make -C lib/ft_acstd
	make -C lib/ft_acrypto

test_md5: all
	gcc $(LIB) -C test/src/md5.c -o test/bin/md5 

real_md5:
	gcc $(LIB) -C test/src/md5_real.c -o test/bin/md5_real 