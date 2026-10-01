#include "includes/cub3d.h"

static	void	ft_get_info_wall(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = data->pl.pos_y / data->map.ecart_h
			+ ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = data->pl.pos_x / data->map.ecart_w
			+ ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * TEXTURE_SIZE);
	if ((ray->side == 0 && ray->ray_dir_x < 0)
		|| (ray->side == 1 && ray->ray_dir_y > 0))
		ray->tex_x = TEXTURE_SIZE - ray->tex_x - 1;
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			ray->dir = WE;
		else
			ray->dir = EA;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			ray->dir = NO;
		else
			ray->dir = SO;
	}
}

void	ft_draw_textured_column(t_data *data, t_ray *ray, int x)
{
	int		y;
	int		color;
	size_t	offset;

	ft_get_info_wall(data, ray);
	ray->step = 1.0 * TEXTURE_SIZE / ray->line_height;
	ray->pos = (ray->draw_start - data->global.height / 2
			+ ray->line_height / 2) * ray->step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		ray->tex_y = (int)(ray->pos) % TEXTURE_SIZE;
		ray->pos += ray->step;
		color = data->wall[ray->dir].addr[ray->tex_y
				* (data->wall[ray->dir].line_length / 4) + ray->tex_x];
		offset = y * (data->global.line_length / 4) + x;
		data->global.addr[offset] = color;
		y++;
	}
}