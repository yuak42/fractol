NAME = fractol

SRC = main.c fractol_init.c \
	str_utils/is_double.c str_utils/str_to_double.c str_utils/exactly_zero.c str_utils/remove_space.c \
	graph_utils/put_pixel.c graph_utils/get_color.c \
	hook_utils/handle_keys.c hook_utils/close_window.c hook_utils/mouse_handler.c \
	julia/paint_julia.c julia/julia.c julia/draw_julia.c \
	mandelbrot/paint_mandelbrot.c mandelbrot/mandelbrot.c mandelbrot/draw_mandelbrot.c

OBJ = $(SRC:.c=.o)

CC = cc

LIBFT = libft/libft.a

MLX = minilibx-linux/libmlx.a

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11

LIBFT_FLAGS = -Llibft -lft

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C libft

$(MLX):
	make -C minilibx-linux

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	make -C minilibx-linux clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
