# Variables
NAME = so_long
CC = cc 
CFLAGS = -Wall -Wextra -Werror 
LDFLAGS =-framework Cocoa -framework OpenGL -framework IOKit -lglfw
SRCS = main.c \
       move_utils.c \
       validation.c \
       image_utils.c \
       map_utils.c \
	   hooks.c \
       $(wildcard GET_NEXT_LINE/*.c) \
       $(wildcard Libft/*.c) \
       $(wildcard ft_printf/*.c)
OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
INCDIR = include
MLX42_PATH = MLX42
MLX42_BUILD_PATH = $(MLX42_PATH)/build
MLX42 = $(MLX42_BUILD_PATH)/libmlx42.a
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
RM = rm -f

# Default rule
all: $(NAME)

# Compilation rule
$(NAME): $(OBJS) $(MLX42) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(OBJS) $(CFLAGS) $(MLX42) $(LIBFT) $(FT_PRINTF) -I$(INCDIR) $(LDFLAGS) -o $(NAME)
	@echo "Built $(NAME)"

# Object files rule
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(MLX42_PATH)/include -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -c $< -o $@

# MinilibX library
$(MLX42):
	@cd $(MLX42_PATH) && rm -rf build && cmake -B build && cmake --build build -j4

# Libft library
$(LIBFT):
	@make -C $(LIBFT_DIR)

# ft_printf library
$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

# Clean object files
clean:
	$(RM) $(OBJS)
	@rm -rf $(OBJDIR)
	@cd $(MLX42_PATH) && cmake --build build --target clean || true
	@make -C $(LIBFT_DIR) clean || true
	@make -C $(FT_PRINTF_DIR) clean || true
	@echo "Cleaned object files and libraries"

# Clean all generated files
fclean: clean
	$(RM) $(NAME)
	@cd $(MLX42_PATH) && rm -rf build
	@make -C $(LIBFT_DIR) fclean || true
	@make -C $(FT_PRINTF_DIR) fclean || true
	@echo "Cleaned all generated files"

# Recompile everything
re: fclean all

leaks: CFLAGS += -g -DLEAKS
leaks: all

# Declare phony targets
.PHONY: all clean fclean re $(LIBFT) $(FT_PRINTF)