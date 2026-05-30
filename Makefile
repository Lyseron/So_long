NAME       = so_long
CC         = cc
CFLAGS     = -Wall -Wextra -Werror -g

INCS	   = -I. -I$(LIBFT_DIR)

LIBFT_DIR  = libft

LIBFT      = $(LIBFT_DIR)/libft.a

SRCS    = check_map_wall.c check_map_wall_utils.c get_next_line.c get_next_line_utils.c main.c \
check_map_component.c check_playability.c check_playability_utils.c gameplay.c print_map.c \
create_map_tab.c check_map_ext.c

OBJS    = $(SRCS:%.c=%.o)
RM      = rm -f
UNAME_S := $(shell uname)

ifeq ($(UNAME_S),Darwin)
	MLX_DIR = mlx_macos
	MLX_INC = -I$(MLX_DIR)
	MLX_LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR = mlx_linux
	MLX_INC = -I$(MLX_DIR)
	MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
endif

INC = -Iincludes $(MLX_INC)
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) $(INC) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re