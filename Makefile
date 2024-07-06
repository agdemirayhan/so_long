# Variables
NAME = so_long
CC = cc -g
CFLAGS = -framework Cocoa -framework OpenGL -framework IOKit
SRCS = main.c
OBJDIR := obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
MLX42_PATH = MLX42
MLX42_BUILD_PATH = $(MLX42_PATH)/build
MLX42 = $(MLX42_BUILD_PATH)/libmlx42.a
RM = rm -f

# Compilation rule
$(NAME): $(OBJS) $(MLX42)
	@$(CC) $(OBJS) $(CFLAGS) $(MLX42) -Iinclude -lglfw -g -o $(NAME)

# Object files rule
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# MinilibX library
$(MLX42):
	@cd $(MLX42_PATH) && rm -rf build && cmake -B build && cmake --build build -j4

# Clean object files
clean:
	$(RM) $(OBJS)
	@cd $(MLX42_PATH) && cmake --build build --target clean || true

# Clean all generated files
fclean: clean
	$(RM) $(NAME)
	@cd $(MLX42_PATH) && rm -rf build

# Recompile everything
re: fclean all

# Declare phony targets
.PHONY: all clean fclean re

# Default rule
all: $(NAME)
