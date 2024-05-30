CC				= cc 
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g3
MINILIBX_PATH	= ./minilibx-linux/
MLXFLAGS		= -L $(MINILIBX_PATH) -lmlx -Ilmlx -lXext -lX11
SO_LONG_NAME 	= so_long
SO_LONG_SRCS	= so_long.c so_long_utils.c check_map.c check_str.c check_tab.c flood_fill_utils.c xpm.c hooks.c libft/*.c libft/printf/*.c get_next_line/*.c
SO_LONG_OBJS 	= $(SO_LONG_SRCS:.c=.o)
MINILIBX		= $(MINILIBX_PATH)libmlx.a

all:			$(SO_LONG_NAME)

$(MINILIBX):
					make -C $(MINILIBX_PATH)

$(SO_LONG_NAME):	$(SO_LONG_OBJS) $(MINILIBX)
					$(CC) -o $(SO_LONG_NAME) $(SO_LONG_SRCS) $(CFLAGS) $(MLXFLAGS) $(MINILIBX)

clean:
				$(RM) $(SO_LONG_OBJS)
				 
fclean:	 		clean
				$(RM) $(SO_LONG_NAME)
				
re:				fclean all

.PHONY:			all clean fclean re