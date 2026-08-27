#include "includes/cub3d.h"

void	print_map(t_data *data)
{
	double	ecart_h;
	double	ecart_w;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ecart_h = data->global.height / data->map.rows;
	ecart_w = data->global.width / data->map.columns;
	while(i != data->map.rows)
	{
		while()
		i++;
	}
}

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
