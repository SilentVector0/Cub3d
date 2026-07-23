NAME = cub3D
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lXext -lX11 -lm -lz
INCLUDES = -I. -Ilibft -Iminilibx-linux

S = sources

SRCS_MAIN = $(S)/main/gestion_win.c $(S)/main/main.c

SRCS_INIT = $(S)/init/init_game.c

SRCS_CLEANUP =

SRCS_RAY_CAST = $(S)/render/render_player.c

SRCS = $(SRCS_INIT) $(SRCS_CLEANUP) $(SRCS_RAY_CAST) $(SRCS_MAIN)
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
MINILIBX = minilibx-linux/libmlx_Linux.a

all: $(LIBFT) $(MINILIBX) $(NAME)
	clear

$(LIBFT):
	$(MAKE) -C libft

$(MINILIBX):
	$(MAKE) -C minilibx-linux

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean
	clear

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	clear

re: fclean all
