/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:59:17 by aroduit           #+#    #+#             */
/*   Updated: 2026/10/27 16:59:17 by aroduit          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static int	ft_press_hook(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->kp.key[W] = 1;
	if (keycode == XK_a)
		data->kp.key[A] = 1;
	if (keycode == XK_s)
		data->kp.key[S] = 1;
	if (keycode == XK_d)
		data->kp.key[D] = 1;
	if (keycode == XK_Left)
		data->kp.key[LEFT] = 1;
	if (keycode == XK_Right)
		data->kp.key[RIGHT] = 1;
	if (keycode == XK_Escape)
		ft_close_game(data);
	return (0);
}

static int	ft_release_hook(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->kp.key[W] = 0;
	if (keycode == XK_a)
		data->kp.key[A] = 0;
	if (keycode == XK_s)
		data->kp.key[S] = 0;
	if (keycode == XK_d)
		data->kp.key[D] = 0;
	if (keycode == XK_Left)
		data->kp.key[LEFT] = 0;
	if (keycode == XK_Right)
		data->kp.key[RIGHT] = 0;
	return (0);
}

static int	ft_update(t_data *data)
{
	long	now_time;

	now_time = my_time();
	data->delta = now_time - data->time;
	if (data->delta > MAX_DELTA)
		data->delta = MAX_DELTA;
	data->time = now_time;
	ft_move_player(data);
	if (data->kp.key[LEFT] == 1)
		ft_handle_rotate(data, -ROT_SPEED * data->delta);
	if (data->kp.key[RIGHT] == 1)
		ft_handle_rotate(data, ROT_SPEED * data->delta);
	return (ft_render_frame(data));
}

void	ft_setup_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, ft_press_hook, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, ft_release_hook, data);
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask,
		ft_close_game, data);
	mlx_hook(data->mlx_win, Expose, ExposureMask, ft_render_frame, data);
	mlx_loop_hook(data->mlx_ptr, ft_update, data);
}
