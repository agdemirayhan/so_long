# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 14:23:31 by aagdemir          #+#    #+#              #
#    Updated: 2024/06/23 20:43:48 by aagdemir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIRS := str_utils mem_utils char_utils put_utils
OBJ_DIR := obj

# vpath for finding source files
vpath %.c $(SRC_DIRS)

# Source files categorized
STRING_UTILS := ft_atoi.c \
ft_split.c \
ft_strdup.c \
ft_strjoin.c \
ft_strlcpy.c \
ft_strmapi.c \
ft_strnstr.c \
ft_strtrim.c \
ft_tolower.c \
ft_itoa.c \
ft_strchr.c \
ft_striteri.c \
ft_strlcat.c \
ft_strlen.c \
ft_strncmp.c \
ft_strrchr.c \
ft_substr.c \
ft_toupper.c

MEMORY_UTILS := ft_bzero.c \
ft_calloc.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c

PUT_UTILS := ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c

CHAR_UTILS := ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c

# Combined source files
CFILES := $(STRING_UTILS) $(MEMORY_UTILS) $(PUT_UTILS) $(CHAR_UTILS)
# Corresponding object files
OFILES := $(addprefix $(OBJ_DIR)/, $(CFILES:%.c=%.o))

# Header files
HEADERS := libft.h

# Library name
NAME := libft.a

# Default target
all: $(NAME)

# Rule to build the library
$(NAME): $(OBJ_DIR) $(OFILES)
	ar rcs $(NAME) $(OFILES)

# Rule to compile .c files into .o files
$(OBJ_DIR)/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean object files
clean:
	rm -f $(OFILES)
	rm -rf $(OBJ_DIR)

# Clean object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
