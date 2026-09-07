#include "includes/cub3d.h"

/*void	ft_draw_ray_vector(t_data *data, t_player *pl, double dir_x, double dir_y, int color)
{
    double  norm;
    double  ux;
    double  uy;
    double  x;
    double  y;
    int     px;
    int     py;
    int     map_x;
    int     map_y;
    size_t  offset;
    int     safety;

    norm = sqrt(dir_x * dir_x + dir_y * dir_y);
    ux = dir_x / norm;
    uy = dir_y / norm;
    x = pl->pos_x;
    y = pl->pos_y;
    safety = 0;
    while (safety < 2000)
    {
        map_x = (int)(x / data->map.ecart_w);
        map_y = (int)(y / data->map.ecart_h);
        if (map_x < 0 || map_x >= data->map.columns
            || map_y < 0 || map_y >= data->map.rows
            || data->map.grid[map_y][map_x] == '1')
            break ;
        px = (int)x;
        py = (int)y;
        if (px >= 0 && px < data->global.width && py >= 0 && py < data->global.height)
        {
            offset = py * (data->global.line_length / 4) + px;
            data->global.addr[offset] = COLOR_FOV;
        }
        x += ux;
        y += uy;
        safety++;
    }
}*/

void    ft_perform_dda(t_data *data, t_ray *ray)
{
    int safety;

    safety = 0;
    while (data->map.grid[ray->map_y][ray->map_x] != '1' && safety < 1000)
    {
        if (ray->side_dist_x < ray->side_dist_y)
        {
            ray->side_dist_x += ray->delta_dist_x;
            ray->map_x += ray->step_x;
            ray->side = 0;
        }
        else
        {
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            ray->side = 1;
        }
        safety++;
    }
}

void	ft_pos_player(t_data *data, t_ray *ray)
{
	double	p_x;
	double	p_y;

	p_x = data->pl.pos_x / data->map.ecart_w;
	p_y = data->pl.pos_y / data->map.ecart_h;
	if (ray->step_x == 1)
		ray->side_dist_x = (ray->map_x + 1.0 - p_x) * ray->delta_dist_x;
	else
		ray->side_dist_x = (p_x - ray->map_x) * ray->delta_dist_x;
	if (ray->step_y == 1)
		ray->side_dist_y = (ray->map_y + 1.0 - p_y) * ray->delta_dist_y;
	else
		ray->side_dist_y = (p_y - ray->map_y) * ray->delta_dist_y;
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
	ft_pos_player(data, ray);
}

void	ft_print_fov(t_data *data)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < data->global.width)
	{
		ray.camera_x = 2 * (double)x / data->global.width - 1;
		ray.ray_dir_x = data->pl.dir_x + data->pl.plane_x * ray.camera_x;
		ray.ray_dir_y = data->pl.dir_y + data->pl.plane_y * ray.camera_x;
		ray.map_x = (int)(data->pl.pos_x / data->map.ecart_w);
		ray.map_y = (int)(data->pl.pos_y / data->map.ecart_h);
		ft_calculate_step(data, &ray);
		ft_perform_dda(data, &ray);
		//ft_draw_ray_vector(data, &data->pl, ray.ray_dir_x, ray.ray_dir_y);
		ft_wall_dist(&ray);
		x++;
	}
} 