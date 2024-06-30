# Variables
NAME = so_long
CC = cc
# CFLAGS = -Wall -Wextra -Werror
SRCS = main.c 
OBJS = $(SRCS:.c=.o)
MLX_PATH = mlx
MLX = $(MLX_PATH)/libmlx.a
RM = rm -f

# Compilation rule
$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# Object files rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# MinilibX library
$(MLX):
	make -C $(MLX_PATH)

# Clean object files
clean:
	$(RM) $(OBJS)
	make -C $(MLX_PATH) clean

# Clean all generated files
fclean: clean
	$(RM) $(NAME)

# Recompile everything
re: fclean all

# Declare phony targets
.PHONY: all clean fclean re

# Default rule
all: $(NAME)
