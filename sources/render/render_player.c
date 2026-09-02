#include "includes/cub3d.h"

void	print_pixel(t_data *data, int color)
{
	size_t offset;
	int		count_x;
	int		current_y;

	current_y = data->pl.pos_y - 3;
	while(current_y <= data->pl.pos_y + 3)
	{
		offset = current_y * (data->global.line_length / 4) + data->pl.pos_x - 3;
		count_x = 0;
		while (count_x < 7)
		{
			if ((current_y >= 0 && current_y < data->global.height) && (data->pl.pos_x -3 + count_x >= 0 && data->pl.pos_x -3 + count_x  < data->global.width))
				data->global.addr[offset] = color;
			offset++;
			count_x++;
		}
		current_y++;
	}
}

void	pos_player(t_data *data, int i, int j, char angle)
{
	if (angle == 'N')
		data->pl.angle = (M_PI + M_PI_2) / 2;
	data->pl.pos_x = data->map.ecart_w * j + data->map.ecart_w / 2;
	data->pl.pos_y = data->map.ecart_h * i + data->map.ecart_h / 2;
	print_pixel(data, 0xFF0000);
}
