NAME = bsq
LIST = main.c ft_check_map.c ft_create_map.c ft_print_map.c ft_read_map.c new_alg.c
OBJ = ${LIST:.c=.o}
INCLUDES = -I ./includes

all : $(NAME)

$(NAME) : $(OBJ)
	gcc -Wall -Werror -Wextra -o $(NAME) $(OBJ) $(INCLUDES)
%.o : %.c
	gcc -Wall -Werror -Wextra  -c $< -o $@ $(INCLUDES)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
