NAME = so_long

SRC =	so_long.c    \
		parsing.c    \
		utils.c      
   
OBJS = $(SRC:.c=.o)

CC = cc

CFLAGS = -g  -Wall -Werror -Wextra -fsanitize=address

all:$(NAME)

$(NAME):$(OBJS)
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ./libft/libft.a -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf ./libft/*.o
fclean: clean
	rm -rf $(NAME)
	rm -rf ./libft/libft.a

re:fclean all