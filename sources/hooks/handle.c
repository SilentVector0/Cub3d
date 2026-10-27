/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:55:36 by aroduit           #+#    #+#             */
/*   Updated: 2026/10/27 16:57:23 by aroduit          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static int	ft_is_wall(t_data *data, double x, double y)
{
	return (data->map.grid[(int)y][(int)x] == '1');
}

static int	ft_can_move(t_data *data, double x, double y)
{
	return (!ft_is_wall(data, x - HITBOX, y - HITBOX)
		&& !ft_is_wall(data, x + HITBOX, y - HITBOX)
		&& !ft_is_wall(data, x - HITBOX, y + HITBOX)
		&& !ft_is_wall(data, x + HITBOX, y + HITBOX));
}

static void	ft_handle_move(t_data *data, double dx, double dy)
{
	double	new_x;
	double	new_y;

	new_x = data->pl.pos_x + dx * data->pl.dir_x - dy * data->pl.dir_y;
	new_y = data->pl.pos_y + dx * data->pl.dir_y + dy * data->pl.dir_x;
	if (ft_can_move(data, new_x, data->pl.pos_y))
		data->pl.pos_x = new_x;
	if (ft_can_move(data, data->pl.pos_x, new_y))
		data->pl.pos_y = new_y;
}

void	ft_move_player(t_data *data)
{
	double	fwd;
	double	side;
	double	step;

	fwd = data->kp.key[W] - data->kp.key[S];
	side = data->kp.key[D] - data->kp.key[A];
	if (fwd != 0 && side != 0)
	{
		fwd /= sqrt(2);
		side /= sqrt(2);
	}
	step = SPEED * data->delta;
	if (fwd != 0 || side != 0)
		ft_handle_move(data, step * fwd, step * side);
}

void	ft_handle_rotate(t_data *data, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->pl.dir_x;
	data->pl.dir_x = data->pl.dir_x * cos(angle) - data->pl.dir_y * sin(angle);
	data->pl.dir_y = old_dir_x * sin(angle) + data->pl.dir_y * cos(angle);
	old_plane_x = data->pl.plane_x;
	data->pl.plane_x = data->pl.plane_x * cos(angle)
		- data->pl.plane_y * sin(angle);
	data->pl.plane_y = old_plane_x * sin(angle) + data->pl.plane_y * cos(angle);
}
