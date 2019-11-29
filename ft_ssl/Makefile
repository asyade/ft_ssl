NAME = ft_ssl
PATH_SRC = src
ODIRS = obj/
SRC = src/main.c
OBJ = $(patsubst $(PATH_SRC)/%.c, obj/%.o, $(SRC))
DEPS = ./include/ft_ssl.h Makefile
LCRYPTO = -I./../lib/ft_acrypto/include -L../lib/ft_acrypto -lacrypto
LSTD = -I./../lib/ft_acstd/include -L../lib/ft_acstd -lacstd
INC = -I ./include

CC=gcc
FLAGS = -g3 -Wall -Wextra -Werror

all : $(NAME)

obj/%.o : $(PATH_SRC)/%.c $(DEPS) ../lib/ft_acrypto/src/* ../lib/ft_acstd/src/* ../lib/ft_acrypto/include/* ../lib/ft_acstd/include/*
	mkdir -p $(ODIRS)
	$(CC) $(FLAGS) $(LCRYPTO) $(LSTD) -c $< -o $@ $(INC)

$(NAME) : $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LCRYPTO) $(LSTD)

clean :
	/bin/rm -rf obj/

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re