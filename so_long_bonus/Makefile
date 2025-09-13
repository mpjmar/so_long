# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 16:59:57 by maria-j2          #+#    #+#              #
#    Updated: 2025/09/13 15:05:04 by maria-j2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the file
NAME = so_long_bonus

# Compiler and compilation flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(LIBFT_DIR) -I$(MLX42_DIR)

# Tools
AR = ar rcs
RM = rm -f

# Directories
SRCS_DIR = src
OBJ_DIR = obj

# Libft
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

# MLX42
MLX42_DIR = ../MLX42
MLX42 = $(MLX42_DIR)/libmlx42.a

# Source files
SRC_FILES = \
	events.c \
	free_and_errors.c \
	game.c \
	main.c \
	map_building.c \
	map_checking.c \
	map_validation.c \
	render.c \
	utils.c

# Add paths
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Header file
INCLUDE = so_long.h

# Default rule
all: $(LIBFT) $(NAME)

# Build so_long
$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX42) -ldl -lglfw -pthread

# Build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Ensure object dir exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile .c into .o
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Cleaning rules
clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
