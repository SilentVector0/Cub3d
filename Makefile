NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

SRC_DIR		= sources
LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux

INCLUDES	= -I. -I$(LIBFT_DIR) -I$(MLX_DIR)
MLXFLAGS	= -lXext -lX11 -lm -lz

SRCS		= $(wildcard $(SRC_DIR)/main/*.c) \
			$(wildcard $(SRC_DIR)/init/*.c) \
			$(wildcard $(SRC_DIR)/check_map/*.c) \
			$(wildcard $(SRC_DIR)/cleanup/*.c) \
			$(wildcard $(SRC_DIR)/render/*.c) \
			$(wildcard $(SRC_DIR)/hooks/*.c)

OBJS		= $(SRCS:.c=.o)

LIBFT		= $(LIBFT_DIR)/libft.a
MINILIBX	= $(MLX_DIR)/libmlx_Linux.a

MAP			= map/good/dungeon.cub

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(MINILIBX):
	@$(MAKE) -s -C $(MLX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

val: $(NAME)
	@valgrind --leak-check=full \
	--show-leak-kinds=all \
	--track-fds=all \
	--track-origins=yes \
	--error-exitcode=1 \
	./$(NAME) $(MAP)

run: $(NAME)
	@./$(NAME) $(MAP)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s -C libft fclean

re: fclean all

.PHONY: all val run clean fclean re