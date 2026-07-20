#include "includes/cub3d.h"

int	win_creation(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->global.width, data->global.height, "cub3d");
	if (!data->mlx_win)
		return (1);
	data->global.mlx_img = mlx_new_image(data->mlx_ptr, data->global.width, data->global.height);
	if (!data->global.mlx_img)
		return (1);
	return (0);
}
