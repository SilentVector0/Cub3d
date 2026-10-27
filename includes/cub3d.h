/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 21:12:12 by aroduit           #+#    #+#             */
/*   Updated: 2026/10/27 21:12:16 by aroduit          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <math.h>
# include <minilibx-linux/mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define ROT_SPEED		0.003
# define HITBOX			0.2
# define SPEED			0.004
# define MAX_DELTA		50
# define FOV			66

# define COLOR_WALL		0xFFFFFF
# define COLOR_PLAYER	0xFF0000

# define RED	"\033[31m"
# define PURPLE	"\033[35m"
# define RESET	"\033[0m"

typedef enum s_key
{
	W,
	A,
	S,
	D,
	LEFT,
	RIGHT,
}	t_key;

typedef struct s_keypress
{
	int	key[6];
}	t_keypress;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
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

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		columns;
	int		player;
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
}	t_orient;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		*first_line;
	t_map		map;
	t_image		global;
	t_image		wall[4];
	t_player	pl;
	t_keypress	kp;
	long		time;
	long		delta;
	int			current_fd;
	int			floor;
	int			ceiling;
}	t_data;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	double	step;
	double	pos;
	int		tex_x;
	int		tex_y;
	int		dir;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

//init and check fonctions
void	ft_init_game(t_data *data);
void	ft_alloc_map(t_data *data, char *filename);
void	ft_config_and_search_map(t_data *data, int fd);
void	ft_check_parameters(int argc, char **argv, t_data *data);
void	ft_check_map(t_data *data);
void	ft_set_scale(t_data *data);
void	ft_check_config(t_data *data);
int		ft_is_config_line(char *line);
void	ft_check_empty_rows(t_data *data);

//render and MLX fonctions
void	ft_win_creation(t_data *data);
int		ft_render_frame(t_data *data);
void	ft_raycasting(t_data *data);
void	ft_draw_textured_column(t_data *data, t_ray *ray, int x);

//hooks fonctions
void	ft_setup_hooks(t_data *data);
void	ft_handle_rotate(t_data *data, double angle);
void	ft_move_player(t_data *data);
long	my_time(void);

//clean and exit fonctions
void	ft_cleanup(t_data *data);
void	ft_error_msg(char *msg, t_data *data);
int		ft_close_game(t_data *data);

#endif
