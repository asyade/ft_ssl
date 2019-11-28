CC = gcc
NAME = ft_ssl
PATH_SRC = src
ODIRS = obj/
SRC = src/main.c
OBJ = $(patsubst $(PATH_SRC)/%.c, obj/%.o, $(SRC))
FLAGS = -g3 -Wall -Wextra
DEPS = ./include/ft_ssl.h Makefile
LCRYPTO = -I./../lib/ft_acrypto/include -L../lib/ft_acrypto -lacrypto
LSTD = -I./../lib/ft_acstd/include -L../lib/ft_acstd -lacstd
INC = -I ./include

all : $(NAME)

obj/%.o : $(PATH_SRC)/%.c $(DEPS)
	make -C ../lib/ft_acstd/
	make -C ../lib/ft_acrypto/
	mkdir -p $(ODIRS)
	@$(CC) $(FLAGS) $(LCRYPTO) $(LSTD) -c $< -o $@ $(INC)
	echo "\033[33mCompiling \033[32m[✔] \033[0m$<"

$(NAME) : $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LCRYPTO) $(LSTD)

clean :
	make -C ../lib/ft_acstd/ clean
	make -C ../lib/ft_acrypto/ clean
	/bin/rm -rf obj/
	echo "\033[31mRemoving  \033[32m[✔] \033[0mObject files"

fclean : clean
	make -C ../lib/ft_acstd/ fclean
	make -C ../lib/ft_acrypto/ flcean
	/bin/rm -f $(NAME)
	echo "\033[31mRemoving  \033[32m[✔] \033[0m$(NAME)"

re : fclean all

.PHONY : all clean fclean re