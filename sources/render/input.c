#include "includes/cub3d.h"

int	handle_hook(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->kp.key[W] = 1;
	if (keycode == XK_a)
		data->kp.key[A] = 1;
	if (keycode == XK_s)
		data->kp.key[S] = 1;
	if (keycode == XK_d)
		data->kp.key[D] = 1;
	// else if (keycode == XK_Escape)
	// 	handle_esc(data);
	return (0);
}

int	release_hook(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->kp.key[W] = 0;
	if (keycode == XK_a)
		data->kp.key[A] = 0;
	if (keycode == XK_s)
		data->kp.key[S] = 0;
	if (keycode == XK_d)
		data->kp.key[D] = 0;
	// else if (keycode == XK_Escape)
	// 	handle_esc(data);
	return (0);
}

int	verif_state(t_data *data)
{
	long	now_time;

	now_time = my_time();
	data->delta = now_time - data->time;
	data->time = now_time;
	if (data->kp.key[W] == 1)
		handle_w(data);
	if (data->kp.key[A] == 1)
		handle_a(data);
	if (data->kp.key[S] == 1)
		handle_s(data);
	if (data->kp.key[D] == 1)
		handle_d(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->global.mlx_img, 0, 0);
	return (0);
}

void	detect_press(t_data *data)
{
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, handle_hook, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, release_hook, data);
	mlx_loop_hook(data->mlx_ptr, verif_state, data);
}
