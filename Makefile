NAME	= so_long

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

HEADER		= so_long.h

SRCS	= so_long.c so_long_init_array.c get_next_line.c get_next_line_utils.c put_xpm.c moves_hero.c moves_cop.c \
key_handlers.c init_cop_positions.c moves_cop_helper.c init_free_string.c creat_xpm.c put_explosion.c \
chek_map_array.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME) 
%.o: 	%.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
			$(MAKE) all -C ./libft
			$(MAKE) all -C ./minilibx
			cp libft/libft.a ./$(NAME)
			cp minilibx/libmlx.a ./$(NAME)
			$(CC) $(OBJS)  -framework OpenGL -framework AppKit ./minilibx/libmlx.a ./libft/libft.a -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx
	-rm -rf $(OBJS)
	
fclean: clean
	$(MAKE) fclean -C ./libft
	-rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re
