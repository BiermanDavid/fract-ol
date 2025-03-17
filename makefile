NAME = fractol
MLX_DIR = mlx
# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -g \
         -L$(MLX_DIR)
#I deleted the Werror flag, I should put it back later
LIBRARIES = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm
# Header files
HEADERS = fractol.h
# Source files
SRCS = main.c init.c string_utils.c
# Object files (replace .c with .o). Compiling source files to object files
OBJS = $(SRCS:.c=.o)
# Delivery files
DELIVERY_FILES = $(NAME)
# Phony targets
.PHONY: all clean fclean re
# Rule for creating object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# Create the library
$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBRARIES)
# Default target
all: $(NAME)
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
# Specify what happens when the Makefile is executed
help:
	@echo "Makefile for $(NAME)"
	@echo "Usage:"
	@echo "  make          Build the project"
	@echo "  make clean    Remove object files"
	@echo "  make fclean   Remove object files and the library"
	@echo "  make re       Rebuild the project"
	@echo "  make help     Display this help message"