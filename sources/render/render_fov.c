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
		x += ray_x * 2;
		y += ray_y * 2;
	}
}

void	ft_calculate_step(t_data *data, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->ray_dir_y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	ft_print_fov(t_data *data, int color)
{
	int		x;

	x = 0;
	while (x < data->global.width)
	{
		ray->camera_x = 2 * (double)x / data->global.width - 1;
		ray->ray_dir_x = data->pl.dir_x + data->pl.plane_x * ray->camera_x;
		ray->ray_dir_y = data->pl.dir_y + data->pl.plane_y * ray->camera_x;
		ray->map_x = (int)(data->pl.pos_x / data->map.ecart_w);
		ray->map_y = (int)(data->pl.pos_y / data->map.ecart_h);
		ft_calculate_step(data, ray);
		ft_perform_dda(data, ray);
		x++;
	}
}
