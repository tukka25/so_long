NAME = so_long

SRC =	so_long.c    \
		parsing.c    \
		utils.c      \
		parsing2.c   \
		drawing.c    \
		hooks.c      \
		valid_path.c \
		enemy.c      \
		destory.c    \
		utils2.c
   
OBJS = $(SRC:.c=.o)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

CC = cc

CFLAGS = -g3 -Wall -Werror -Wextra -fsanitize=address

all:$(NAME)

$(NAME):$(OBJS)
	@make -C ./libft
	@make -C ./mlx
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ./libft/libft.a  ./mlx/libmlx.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf ./libft/*.o
	rm -rf ./mlx/*.o
fclean: clean
	rm -rf $(NAME)
	rm -rf ./libft/libft.a
	rm -rf ./mlx/*.a

re:fclean all