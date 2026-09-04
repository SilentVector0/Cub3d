#include "includes/cub3d.h"

void	ft_set_player(t_data *data, char c, int j, int i)
{
	if (data->map.player == 1)
		ft_error_msg("Too Many player", data);
	data->map.player = 1;
	data->pl.pos_x = data->map.ecart_w * i + data->map.ecart_w / 2;
	data->pl.pos_y = data->map.ecart_h * j + data->map.ecart_h / 2;
	if (c == 'N')
		data->pl.dir_y = -1;
	else if (c == 'E')
		data->pl.dir_x = 1;
	else if (c == 'S')
		data->pl.dir_y = 1;
	else if (c == 'W')
		data->pl.dir_x = -1;
	data->pl.plane_x = -data->pl.dir_y * tan((FOV / 2.0) * M_PI / 180);
	data->pl.plane_y = data->pl.dir_x * tan((FOV / 2.0) * M_PI / 180);
	return ;
}