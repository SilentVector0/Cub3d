#include "includes/cub3d.h"

int	handle_hook(int keycode, t_data *data)
{
	if (keycode == XK_w)
		handle_w(data);
	else if (keycode == XK_a)
		handle_a(data);
	else if (keycode == XK_s)
		handle_s(data);
	else if (keycode == XK_d)
		handle_d(data);
	// else if (keycode == XK_Escape)
	// 	handle_esc(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->global.mlx_img, 0, 0);
	return (0);
}
