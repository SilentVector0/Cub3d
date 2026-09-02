#ifndef CUB_3D_H
#define CUB_3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <math.h>
#include <minilibx-linux/mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>

# define SPEED 0.1

# define RED	"\033[31m"
# define PURPLE	"\033[35m"
# define RESET	"\033[0m"

typedef struct s_ray
{
	double	dx;
	double	dy;
}	t_ray;

typedef enum s_key
{
	W,
	A,
	S,
	D,
} t_key;

typedef struct s_keypress
{
	int key[4];
} t_keypress;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	angle;
}	t_player;

typedef struct s_image
{
	char	*path;
	int		*addr;
	void	*mlx_img;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
}	t_image;

typedef	struct s_map
{
	char	**grid;
	int		rows;
	int		columns;
	int		player;
	int		exit;
	int		alloc;
	int		ecart_h;
	int		ecart_w;
}	t_map;

typedef enum s_orientation
{
	NO,
	SO,
	WE,
	EA,
} t_orient;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_map		map;
	char		*celling;
	char		*floor;
	t_image		global;
	t_image		wall[4];
	t_image		door;
	t_player	pl;
	t_keypress	kp;
	long		time;
	long		delta;
	int			current_fd;
}	t_data;

void	ft_check_parameters(int argc, char **argv, t_data *data);
int		win_creation(t_data *data);
void	ft_init_game(t_data *data);
void	print_pixel(t_data *data, int color);
long	my_time();
void	ft_alloc_map(t_data *data, char *filename);
int		print_map(t_data *data);
void	pos_player(t_data *data, int i, int j, char angle);

//! fonction handle
void	handle_w(t_data *data);
void	handle_a(t_data *data);
void	handle_s(t_data *data);
void	handle_d(t_data *data);
//void	handle_esc(t_data *data);
void	detect_press(t_data *data);

//exit fonction

void	ft_cleanup(t_data *data);
void	ft_error_msg(char *msg, t_data *data);
int		ft_close_game(t_data *data);
void	ft_victory(t_data *data);

#endif
