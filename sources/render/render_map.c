#include "includes/cub3d.h"

static	void	ft_print_case(t_data *data, int i, int j, int color)
{
	int y;
	int x;
	int offset;

	y = data->map.ecart_h * i;
	while (y < data->map.ecart_h * (i + 1))
	{
		x = data->map.ecart_w * j;
		while (x < data->map.ecart_w * (j + 1))
		{
			offset = y * (data->global.line_length / 4) + x;
			if (y >= 0 && y < data->global.height && x >= 0 && x < data->global.width)
				data->global.addr[offset] = color;
			x++;
		}
		y++;
	}
}

void	ft_draw_walls(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i != data->map.rows)
	{
		j = 0;
		while (j < data->map.columns)
		{
			if (data->map.grid[i][j] == '1')
				ft_print_case(data, i, j, COLOR_WALL);
			j++;
		}
		i++;
	}
}