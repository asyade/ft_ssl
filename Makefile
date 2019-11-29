CC = clang
NAME = ft_ssl
PATH_SRC = src
ODIRS = obj/
SRC = src/main.c
OBJ = $(patsubst $(PATH_SRC)/%.c, obj/%.o, $(SRC))
ifeq ($(PROFILE),)
FLAGS = -o3 -Wall -Wextra
else
FLAGS = -g3 -fsanitize=address -Wall -Wextra
endif

all : 
	make -C lib/ft_acstd/
	make -C lib/ft_acrypto/
	make -C ft_ssl/

clean :
	make -C lib/ft_acstd/ clean
	make -C lib/ft_acrypto/ clean
	make -C ft_ssl/ clean

fclean : clean
	make -C lib/ft_acstd/ fclean
	make -C lib/ft_acrypto/ fclean
	make -C ft_ssl/ fclean

test:
	gcc test/src/md5.c -o test/bin/md5 -g3
	gcc test/src/sha2.c -o test/bin/sha2 -g3

re : fclean all

.PHONY : all clean fclean re test