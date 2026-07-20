#include "includes/cub3d.h"

void	ft_victory(t_data *data)
{
	ft_putendl_fd(PURPLE "\n\
██████████████████████████████████████████████████████████████████\n\
██                                                              ██\n\
██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
██                                                              ██\n\
██████████████████████████████████████████████████████████████████\n\n\
	" RESET, 1);
	ft_cleanup(data);
	exit(EXIT_SUCCESS);
}

int	ft_close_game(t_data *data)
{
	ft_putendl_fd(PURPLE
		"\nYou have closed the game (maybe skill issue)"
		RESET, 1);
	ft_cleanup(data);
	exit(EXIT_SUCCESS);
}

void	ft_error_msg(char *msg, t_data *data)
{
	ft_putstr_fd(RED "Error\n" PURPLE, 2);
	ft_putendl_fd(msg, 2);
	ft_putstr_fd(RESET, 2);
	ft_cleanup(data);
	exit(EXIT_FAILURE);
}
