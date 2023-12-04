CC = cc

NAME = FdF

LIB = includes/libft/libft.a

CFLAGS = -Wall -Wextra -Werror -g

MLXFLAGS = -Iinclude -lglfw

SRC = src/main.c src/parse_map.c src/free_exit.c src/calc_2d_coords.c src/draw_lines.c

OBJ = $(SRC:.c=.o)

all: MLX42 $(NAME)

$(NAME): $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) ./MLX42/build/libmlx42.a $(MLXFLAGS) $(LIB)

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