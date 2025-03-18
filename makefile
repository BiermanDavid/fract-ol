# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 13:55:17 by dabierma          #+#    #+#              #
#    Updated: 2025/03/18 00:02:40 by dabierma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program executable name
NAME = fractol
# MiniLibx directory
MLX_DIR = mlx
# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -Wextra -g 
# MiniLibx Compiler flags
MLX_CFLAGS = -Wall -Wextra
# library links
LIBRARIES = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm
# Header files
HEADERS = fractol.h
# Source files
SRCS = main.c \
functions/init.c \
functions/string_utils.c \
functions/render.c \
functions/mandelbrot.c \
functions/colors.c \
functions/events.c
# Object files
OBJS = $(SRCS:.c=.o)
# Delivery files
DELIVERY_FILES = $(NAME)
# Phony targets
.PHONY: all clean fclean re valgrind help
# Default target
all: $(NAME)
# Create the library
$(NAME): $(OBJS)
	@make -C $(MLX_DIR) CFLAGS="$(MLX_CFLAGS)" > /dev/null 2>&1
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBRARIES)
# Rule for creating object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
VPATH = functions:.
# Build the executable
$(NAME): $(OBJS)
	@make -C $(MLX_DIR) CFLAGS="$(MLX_CFLAGS)" > /dev/null 2>&1
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBRARIES)
# Clean up object files
clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean
# Clean up object files and the library
fclean: clean
	rm -f $(NAME)
	make -C $(MLX_DIR) clean
# Rebuild the library
re: fclean all
valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)
# Default target
all: message $(NAME)
# Display the message
message:
	@echo "#############################################################################"
	@echo "#                                                                           #"
	@echo "#       ___                 __                __     ___ ___ _______        #"
	@echo "#     .'  _.----.---.-.----|  |_ ______.-----|  |   |   Y   |       |       #"
	@echo "#     |   _|   _|  _  |  __|   _|______|  _  |  |   |   |   |___|   |       #"
	@echo "#     |__| |__| |___._|____|____|      |_____|__|   |____   |/  ___/        #"
	@echo "#                                                       |:  |:  42 \\        #"
	@echo "#                                                       |::.|::.. . |       #"
	@echo "#                                                       \`---\`-------'       #"
	@echo "#     =================================================================     #"
	@echo "#                                                                           #"
	@echo "#    ~How to run fractol~                                                   #"
	@echo "#           Option 1: ./fractol Mandelbrot                                  #"
	@echo "#          *Option 2: ./fractol Julia <number> <number>                     #"
	@echo "#                      ~for Julia, do not use <> symbols~                   #"
	@echo "#                                                                           #"
	@echo "#    ~Commands~                                                             #"
	@echo "#           Mouse Wheel: Zoom                                               #"
	@echo "#            Arrow Keys: shift position                                     #"
	@echo "#               ESC Key: Exits program                                      #"
	@echo "#                                                          *Case Sensitive  #"
	@echo "#############################################################################"