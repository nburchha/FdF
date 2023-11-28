CC = cc

NAME = FdF

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -Iinclude -lglfw

SRC = src/main.c

OBJ = $(SRC:.c=.o)

all: MLX42 $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) ./MLX42/build/libmlx42.a $(MLXFLAGS)

MLX42:
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && cmake -B build && cmake --build build -j4

clean:
	@rm -rf MLX42
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all