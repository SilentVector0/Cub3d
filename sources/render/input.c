#include "includes/cub3d.h"

int	ft_handle_hook(int keycode, t_data *data)
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
	// else if (keycode == XK_Escape)
	// 	handle_esc(data);
	return (0);
}

int	ft_release_hook(int keycode, t_data *data)
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
	// else if (keycode == XK_Escape)
	// 	handle_esc(data);
	return (0);
}

int	ft_verif_state(t_data *data)
{
	long now_time;

	now_time = my_time();
	data->delta = now_time - data->time;
	data->time = now_time;
	if (data->kp.key[W] == 1)
		ft_handle_move(data, SPEED * data->delta, 0);
	if (data->kp.key[A] == 1)
		ft_handle_move(data, 0, -SPEED * data->delta);
	if (data->kp.key[S] == 1)
		ft_handle_move(data, -SPEED * data->delta, 0);
	if (data->kp.key[D] == 1)
		ft_handle_move(data, 0, SPEED * data->delta);
	if (data->kp.key[LEFT] == 1)
		ft_handle_rotate(data, -ROT_SPEED * data->delta);
	if (data->kp.key[RIGHT] == 1)
		ft_handle_rotate(data, ROT_SPEED * data->delta);
	return(ft_render_frame(data));
}
