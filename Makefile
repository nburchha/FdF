CC = cc

NAME = fdf

LIB = includes/libft/libft.a

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

MLXFLAGS = -L/opt/homebrew/opt/glfw/lib -lglfw -framework OpenGL

SRC = src/main.c src/parse_map.c src/free_exit.c src/calc_2d_coords.c \
	src/draw_lines.c src/color.c src/hooks.c src/rotation.c \
	src/parse_map_util.c src/hooks_util.c src/draw_lines_util.c

OBJ = $(SRC:.c=.o)

all: MLX42 $(NAME)

$(NAME): $(OBJ) $(LIB)
	@$(CC) -o $(NAME) $(OBJ) ./MLX42/build/libmlx42.a $(MLXFLAGS) $(LIB) $(CFLAGS)

MLX42:
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && cmake -B build && cmake --build build -j4

$(LIB):
	cd includes/libft && make

clean:
	@rm -rf MLX42
	@rm -f $(OBJ)
	@cd includes/libft && make clean

fclean: clean
	@rm -f $(NAME)
	@cd includes/libft && make fclean

re: fclean all

.PHONY: clean fclean all re