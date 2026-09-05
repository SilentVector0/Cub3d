#include "includes/cub3d.h"

static void	ft_raycast_2d(t_data *data, int color, double ray_x, double ray_y)
{
	size_t	offset;
	double	x;
	double	y;

	x = data->pl.pos_x;
	y = data->pl.pos_y;
	while ((y >= 0 && y < data->global.height) && (x >= 0 && x < data->global.width)
		&& data->map.grid[(int)(y / data->map.ecart_h)][(int)(x / data->map.ecart_w)] != '1')
	{
		offset = (int)y * (data->global.line_length / 4) + (int)x;
		data->global.addr[offset] = color;
		x += ray_x * 0.1;
		y += ray_y * 0.1;
	}
}

void	ft_print_fov(t_data *data, int color)
{
	double	ray_x;
	double	ray_y;
	double	camera_x;
	int		x;

	x = 0;
	while (x < data->global.width)
	{
		camera_x = 2 * (double)x / data->global.width - 1;
		ray_x = data->pl.dir_x + data->pl.plane_x * camera_x;
		ray_y = data->pl.dir_y + data->pl.plane_y * camera_x;
		ft_raycast_2d(data, color, ray_x, ray_y);
		x++;
	}
}
