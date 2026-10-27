/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 03:13:11 by aroduit           #+#    #+#             */
/*   Updated: 2026/10/27 03:13:28 by aroduit          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	ft_pos_player(t_data *data, t_ray *ray)
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

static void	ft_calculate_step(t_data *data, t_ray *ray)
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

static void	ft_perform_dda(t_data *data, t_ray *ray)
{
	int	safety;

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

static void	ft_compute_wall_dist(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->line_height = (int)(data->global.height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + data->global.height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->global.height / 2;
	if (ray->draw_end >= data->global.height)
		ray->draw_end = data->global.height - 1;
}

void	ft_raycasting(t_data *data)
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
		ft_compute_wall_dist(data, &ray);
		ft_draw_textured_column(data, &ray, x);
		x++;
	}
}
