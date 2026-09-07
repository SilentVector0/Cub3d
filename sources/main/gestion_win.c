#include "includes/cub3d.h"

void	ft_load_wall_textures(t_data *data)
{
	int endian;
	int i;

	i = 0;
	while (i < 4)
	{
		data->wall[i].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->wall[i].path, &data->wall[i].width, &data->wall[i].height);
		if (!data->wall[i].mlx_img)
			ft_error_msg("Texture load fail", data);
		data->wall[i].addr = (int *)mlx_get_data_addr(data->wall[i].mlx_img,
			&data->wall[i].bpp, &data->wall[i].line_length, &endian);
		i++;
	}
}

void	ft_win_creation(t_data *data)
{
	int	endian;

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_error_msg("Alloc mlx_ptr fail", data);
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->global.width, data->global.height, "cub3d");
	if (!data->mlx_win)
		ft_error_msg("Window display fail", data);
	data->global.mlx_img = mlx_new_image(data->mlx_ptr, data->global.width, data->global.height);
	if (!data->global.mlx_img)
		ft_error_msg("Alloc mlx_img fail", data);
	data->global.addr = (int *)mlx_get_data_addr(data->global.mlx_img, &data->global.bpp, &data->global.line_length, &endian);
	if (!data->global.addr)
		ft_error_msg("Take addr fail", data);
	ft_load_wall_textures(data);
}

