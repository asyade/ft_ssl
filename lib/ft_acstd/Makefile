NAME = libacstd.a
PATH_SRC = src
ODIRS = obj/
SRC = src/ft_opt.c src/ft_fmt.c src/ft_log.c src/ft_mem.c src/ft_put.c src/ft_str.c src/ft_put2.c  src/ft_math.c src/ft_vec.c src/ft_buffer.c src/ft_cursor.c src/ft_endian.c
OBJ = $(patsubst $(PATH_SRC)/%.c, obj/%.o, $(SRC))
DEPS = include/ft_acstd.h Makefile
HEADERS = -I include/

CC=gcc
FLAGS = -g3 -Wall -Wextra -Werror

all : $(NAME)

obj/%.o : $(PATH_SRC)/%.c $(DEPS)
	mkdir -p $(ODIRS)
	$(CC) $(FLAGS) -c $< -o $@ $(HEADERS)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	/bin/rm -rf obj/

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all