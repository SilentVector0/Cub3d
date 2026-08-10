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
#include <mlx-test>

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
	int		alloc;
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
	void	*mlx_ptr;
	void	*mlx_win;
	t_map	map;
	char	*celling;
	char	*floor;
	t_image	global;
	t_image	wall[4];
	t_image	door;
}	t_data;

int		win_creation(t_data *data);
void	init_game(t_data *data);
void	moving_pixel(t_data *data);

#endif
