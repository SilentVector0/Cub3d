#include "includes/cub3d.h"

int	win_creation(t_data *data)
{
	int	endian;

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	printf("win1\n");
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->global.width, data->global.height, "cub3d");
	if (!data->mlx_win)
		return (1);
	printf("win2\n");
	data->global.mlx_img = mlx_new_image(data->mlx_ptr, data->global.width, data->global.height);
	printf("win3\n");
	data->global.addr = (int *)mlx_get_data_addr(data->global.mlx_img, &data->global.bpp, &data->global.line_length, &endian);
	if (!data->global.mlx_img)
		return (1);
	printf("win4\n");
	return (0);
}
