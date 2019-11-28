CC = gcc
NAME = libacrypto.a
PATH_SRC = src
ODIRS = obj/
SRC = src/ft_md5.c src/ft_sha2.c src/ft_utils.c src/ft_digest.c 
OBJ = $(patsubst $(PATH_SRC)/%.c, obj/%.o, $(SRC))
FLAGS = -g3 -Wall -Wextra
DEPS = include/ft_acrypto.h Makefile
HEADERS = -I include/ -I ../ft_acstd/include
LFT = -L./../ft_acstd/ -lacstd

all : $(NAME)

obj/%.o : $(PATH_SRC)/%.c $(DEPS)
	make -C ../ft_acstd/	
	mkdir -p $(ODIRS)
	@$(CC) $(FLAGS) $(LFT) -c $< -o $@ $(HEADERS)
	echo "\033[33mCompiling \033[32m[✔] \033[0m$<"

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	make -C ../ft_acstd/ clean
	/bin/rm -rf obj/
	echo "\033[31mRemoving  \033[32m[✔] \033[0mObject files"

fclean : clean
	make -C ../ft_acstd/ fclean
	/bin/rm -f $(NAME)
	echo "\033[31mRemoving  \033[32m[✔] \033[0m$(NAME)"

re : fclean all

.PHONY : all clean fclean re