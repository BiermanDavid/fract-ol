# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 13:55:17 by dabierma          #+#    #+#              #
#    Updated: 2025/03/24 21:34:59 by dabierma         ###   ########.fr        #
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
functions/events.c \
functions/julia.c
# Object files
OBJS = $(SRCS:.c=.o)
# Delivery files
DELIVERY_FILES = $(NAME)
# Phony targets
.PHONY: all clean fclean re valgrind help
# Default target
all: $(NAME)
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
	@echo "╔═══════════════════════════════════════════════════════════════════════════╗"
	@echo "║                                                                           ║"
	@echo "║          _____                _        _           _  _  ____             ║"
	@echo "║         |  ___|  __ __ _  ___| |_ ___ | |         | || ||___ \\            ║"
	@echo "║         | |_  | '__/ _\` |/ __| __/ _ \\| |  _____  | || |_ __) |           ║"
	@echo "║         |  _| | | | (_| | (__| || (_) | | |_____| |__   _/ __/            ║"
	@echo "║         |_|   |_|  \\__,_|\\___|\\__\\___/|_|            |_||_____|           ║"
	@echo "║                                                                           ║"
	@echo "║              ━─━──────────────────༺༻───────────────────━─━                ║"
	@echo "║                            [Author: Dabierma]                             ║"
	@echo "║                                                                           ║"
	@echo "║⠀                   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣏⡦⠤⣤⠽⠤⡄                             ║"
	@echo "║⠀⠀                 ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠤⠣⢈⠇⠀⠁⣠⡿⡄                             ║"
	@echo "║⠀⠀                 ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠂⠉⠀⠀⠀⠀⠀⢀⡀⠈⠀⠀⠈                             ║"
	@echo "║⠀⠀                   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡔⠀⠀⠀⠀⠀⡀⠀⡰⣯⡀⠀⠀⠀⠀                             ║"
	@echo "║⠀⠀               ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠁⠀⠀⠀⠀⠀⡹⠂⢽⠎⠁⠀⠀⠀⠀                             ║"
	@echo "║⠀⠀               ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠠⠄⠃⣴⠀⠀⢀⡠⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀                             ║"
	@echo "║⠀⠀               ⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀⠈⠧⣢⠌⣁⠐⠋⠂⠀⠀⠀⠀⠀⠀⠀                             ║"
	@echo "║⠀⠀⠀               ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                             ║"
	@echo "║              ━─━──────────────────༺༻───────────────────━─━                ║"
	@echo "║                         ・:。Build Steps [▼]・:。                         ║"
	@echo "║              ━─━──────────────────༺༻───────────────────━─━                ║"
	@echo "║           [▼] [Commands:]                [make]                           ║"
	@echo "║           [Mouse Wheel: Zoom]            [./fractol Mandlebrot]           ║"
	@echo "║           [Arrow Keys: Pan screen]       [./fractol Julia # # ]           ║"
	@echo "║           [ESC Key: Exits program]                                        ║"
	@echo "║                                                                           ║"
	@echo "╚═══════════════════════════════════════════════════════════════════════════╝"
