CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIRECT) #-fsanitize=address -g
RM = rm -f

MLX_DIRECT = .MLX42/build
MLX_FLAGS = -L$(MLX_DIRECT) -lmlx42 -lXext -lX11 -lm /home/cbayousf/Desktop/cub/cub3D/.glfw/build/src/libglfw3.a
#MLX_FLAGS = -L$(MLX_DIRECT) -lmlx42 -lXext -lX11 -lm -lglfw

SRCS = libft/split.c parsing/get_next_line.c parsing/get_next_line_utils.c parsing/main.c parsing/garbage_collector.c parsing/cub_utils1.c parsing/cub_utils2.c \
		libft/libft1.c libft/libft3.c libft/libft2.c parsing/parse_colors.c parsing/parse_map.c parsing/map.c \
		parsing/parse_texture.c parsing/check_utils.c parsing/load_tex.c  raycasting/start.c  raycasting/mlx_func.c  parsing/texture.c \
		raycasting/key_handel.c raycasting/raycasting.c
OB = $(SRCS:.c=.o)

NAME = cub

all: $(NAME)

$(NAME): $(OB)
	$(CC) $(CFLAGS) $(OB) $(MLX_FLAGS) -o $(NAME)

$(OB): cub.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OB)

fclean: clean
	$(RM) $(NAME)

re: fclean all
