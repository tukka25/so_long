NAME = so_long

SRC =	so_long.c    \
		parsing.c    \
		utils.c      \
		parsing2.c   \
		drawing.c    \
		hooks.c       
   
OBJS = $(SRC:.c=.o)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

CC = cc

CFLAGS = -g3 -Wall -Werror -Wextra -fsanitize=address

all:$(NAME)

$(NAME):$(OBJS)
	@make -C ./libft
	@make -C ./mlx
	# $(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ./libft/libft.a  ./mlx/libmlx.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf ./libft/*.o
fclean: clean
	rm -rf $(NAME)
	rm -rf ./libft/libft.a

re:fclean all