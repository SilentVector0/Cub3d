#include "includes/cub3d.h"

void	raycast_2d(t_data *data, int color, double ray_x, double ray_y)
{
	size_t offset;
	double	x;
	double	y;
	int	j;
	int	i;

	x = data->pl.pos_x;
	y = data->pl.pos_y;
	j = x / data->map.ecart_w;
	i = y / data->map.ecart_h;
	while ((y >= 0 && y < data->global.height) && (x >= 0 && x < data->global.width) && data->map.grid[i][j] != '1')
	{
		offset = (int)y * (data->global.line_length/4) + (int)x;
		data->global.addr[offset] = color;
		j = x / data->map.ecart_w;
		i = y / data->map.ecart_h;
		x += ray_x * 0.1;
		y += ray_y * 0.1;
	}
	//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->global.mlx_img, 0, 0);
}

void	print_fov(t_data *data, int color)
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
		raycast_2d(data, color, ray_x, ray_y);
		x++;
	}
}
