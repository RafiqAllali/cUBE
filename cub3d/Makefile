# Project name
NAME = cub3D

# Directories
GNL_DIR = gnl
PARSE_DIR = parsing
UTILS_DIR = utils
INC_DIR = include
MLX_DIR = /home/rallali/Desktop/cub3d/MLX42

# Source files
SRCS = \
	main.c \
	$(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c \
	$(UTILS_DIR)/ft_split.c \
	$(UTILS_DIR)/utils.c \
	# $(PARSE_DIR)/config_valid.c \
	# $(PARSE_DIR)/handle_colors.c \
	# $(PARSE_DIR)/map_utils.c \
	# $(PARSE_DIR)/map_valid.c \
	# $(PARSE_DIR)/parse_utils.c \
	# $(PARSE_DIR)/text_handle.c

# Object files
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g \
	-I$(INC_DIR) -I$(GNL_DIR) \
	-I$(MLX_DIR)/include

LDFLAGS = -L$(MLX_DIR)/build -lmlx42 -lglfw -ldl -lm -pthread

# Main rule
all: $(NAME)

# Linking
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Compilation rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rules
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
