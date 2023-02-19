NAME = so_long

SRC =	so_long.c    \
		parsing.c    \
		utils.c      \
		parsing2.c   \
		drawing.c    \
		hooks.c      \
		valid_path.c \
		destory.c    \
		utils2.c     
   
OBJS = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME):$(OBJS)
	@make -C ../libft
	@make -C ./mlx
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ../libft/libft.a  ./mlx/libmlx.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJS)
	(cd ../libft && make clean)
	(cd mlx && make clean)
fclean: clean
	rm -rf $(NAME)
	rm -rf ../libft/libft.a

re:fclean all