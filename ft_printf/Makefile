# Variables
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_putstr.c ft_putnbr.c ft_putnbr_uint.c ft_puthexvalue.c ft_putchar.c ft_printf.c ft_itoa.c ft_hexdigit.c ft_memcpy.c ft_strchr.c ft_strlen.c
OBJDIR = ../obj/ft_printf
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
INCLUDES = -I../include -I.

# Build rule for the library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to compile .c files into .o files
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Phony targets for standard operations
.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
