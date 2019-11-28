NAME = libacrypto.a
PATH_SRC = src
ODIRS = obj/
SRC = src/ft_md5.c src/ft_sha2.c src/ft_utils.c src/ft_digest.c 
OBJ = $(patsubst $(PATH_SRC)/%.c, obj/%.o, $(SRC))
DEPS = include/ft_acrypto.h Makefile
HEADERS = -I include/ -I ../ft_acstd/include
LFT = -L./../ft_acstd/ -lacstd

CC=gcc
FLAGS = -g3 -Wall -Wextra -Werror

export CC
export FLAGS

all : $(NAME)

obj/%.o : $(PATH_SRC)/%.c $(DEPS)
	mkdir -p $(ODIRS)
	$(CC) $(FLAGS) $(LFT) -c $< -o $@ $(HEADERS)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	/bin/rm -rf obj/

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re