NAME = fractol
SRC = main.c math.c init.c event_listener.c render.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGES = -Wall -Werror -Wextra
LDFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -ldl -lm -g

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a
MLX = MLX42/build/libmlx42.a

all: $(NAME)

$(MLX):
		@git clone https://github.com/codam-coding-college/MLX42.git
		@cd MLX42 && cmake -B build && cmake --build build -j4

$(LIBFT):
		make -C $(LIBFT_DIR)

$(NAME): $(MLX) $(OBJ) $(LIBFT)
	$(CC) $(CFLAGES) $(OBJ) $(MLX) $(LIBFT) -o $(NAME) $(LDFLAGS)

%.o: %.c fractol.h
		$(CC) $(CFLAGES) -Imlx -c $< -o $@

clean:
		rm -rf $(OBJ)
		rm -rf MLX42
		make clean -C $(LIBFT_DIR)

fclean: clean
		rm -rf $(NAME) $(MLX)
		make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re mlx