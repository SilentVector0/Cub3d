#include "includes/cub3d.h"

int handle_hook(int keycode, t_data *data)
{
	if (keycode == XK_w)
		handle_w();
	else if (keycode == XK_a)
		handle_a(data);
	else if (keycode == XK_s)
		handle_s(data);
	else if (keycode == XK_d)
		handle_d(data);
	else if (keycode == XK_Escape)
		handle_esc(data);
	return (0);
}
