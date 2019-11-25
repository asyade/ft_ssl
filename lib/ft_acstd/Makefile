CC = gcc
NAME = libacstd.a
PATH_SRC = src
ODIRS = obj/
SRC = src/ft_fmt.c src/ft_log.c src/ft_mem.c src/ft_put.c src/ft_str.c src/ft_put2.c  src/ft_math.c
OBJ = $(patsubst $(PATH_SRC)/%.c, obj/%.o, $(SRC))
FLAGS = -g -Wall -Wextra -Werror
H_FILES = include/ft_acstd.h
HEADERS = -I include/

all : $(NAME)

obj/%.o : $(PATH_SRC)/%.c $(H_FILES)
	mkdir -p $(ODIRS)
	@$(CC) $(FLAGS) -c $< -o $@ $(HEADERS)
	echo "\033[33mCompiling \033[32m[✔] \033[0m$<"

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ) obj/*.o
	ranlib $(NAME)

clean :
	/bin/rm -rf obj/
	echo "\033[31mRemoving  \033[32m[✔] \033[0mObject files"

fclean : clean
	/bin/rm -f $(NAME)
	echo "\033[31mRemoving  \033[32m[✔] \033[0m$(NAME)"

re : fclean all

.PHONY : clean fclean re