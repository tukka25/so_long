NAME = so_long

SRC =	so_long_bonus.c    \
		parsing_bonus.c    \
		utils_bonus.c      \
		parsing2_bonus.c   \
		drawing_bonus.c    \
		hooks_bonus.c      \
		valid_path_bonus.c \
		enemy_bonus.c      \
		destory_bonus.c    \
		utils2_bonus.c     \
		enemy_utils_bonus.c 
   
OBJS = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

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