NAME		= cub3D

GREEN			=	\033[0;32m
RED				=	\033[0;31m
RESET			=	\033[0m

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

SRC_DIR		= sources
LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux

INCLUDES	= -I. -I$(LIBFT_DIR) -I$(MLX_DIR)
MLXFLAGS	= -lXext -lX11 -lm -lz

SRCS		= $(SRC_DIR)/main/main.c \
			$(SRC_DIR)/main/ft_utils.c \
			$(SRC_DIR)/main/ft_gestion_win.c \
			$(SRC_DIR)/init/ft_init_game.c \
			$(SRC_DIR)/init/ft_init_map.c \
			$(SRC_DIR)/init/ft_init_param.c \
			$(SRC_DIR)/init/ft_init_utils.c \
			$(SRC_DIR)/check_map/ft_check_map.c \
			$(SRC_DIR)/check_map/ft_check_utils.c \
			$(SRC_DIR)/cleanup/ft_cleanup.c \
			$(SRC_DIR)/cleanup/ft_exit_game.c \
			$(SRC_DIR)/render/render.c \
			$(SRC_DIR)/render/raycasting.c \
			$(SRC_DIR)/render/draw_texture.c \
			$(SRC_DIR)/hooks/hook.c \
			$(SRC_DIR)/hooks/handle.c

OBJS		= $(SRCS:.c=.o)

LIBFT		= $(LIBFT_DIR)/libft.a
MINILIBX	= $(MLX_DIR)/libmlx_Linux.a

MAP			= map/good/dungeon.cub

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)
	@printf "$(GREEN)✔ $(NAME) compiled$(RESET)\n"

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(MINILIBX):
	@$(MAKE) -s -C $(MLX_DIR)

$(OBJS): includes/cub3d.h

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

run: $(NAME)
	@./$(NAME) $(MAP)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@echo "$(RED)✘ $(NAME) deleted$(RESET)"

re: fclean all

.PHONY: all run clean fclean re