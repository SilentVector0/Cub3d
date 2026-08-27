#include "includes/cub3d.h"

static void	print_case(t_data *data, int i, int j, int color)
{
	int	counter_i;
	int	counter_j;
	int	target_i;
	int	target_j;
	int	offset;

	counter_i = data->map.ecart_h * i;
	counter_j = data->map.ecart_w * j;
	target_i = data->map.ecart_h * (i + 1);
	target_j = data->map.ecart_w * (j + 1);
	while (counter_i != target_i)
	{
		while (counter_j != target_j)
		{
			offset = counter_i * (data->global.line_length / 4) + counter_j;
			if ((counter_i >= 0 && counter_i < data->global.height) && (counter_j >= 0 && counter_j < data->global.width))
				data->global.addr[offset] = color;
			counter_j++;
		}
		counter_i++;
		counter_j -= data->map.ecart_w;
	}
}

int	print_map(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(i != data->map.rows)
	{
		j = 0;
		while(j != data->map.columns)
		{
			if (data->map.grid[i][j] == '1')
				print_case(data, i, j, 0XFFFFFF);
			else if (data->map.grid[i][j] == '0')
				print_case(data, i, j, 0X000000);
			else if (data->map.grid[i][j] == 'N' || data->map.grid[i][j] == 'S'
				|| data->map.grid[i][j] == 'E' || data->map.grid[i][j] == 'W')
				pos_player(data, i, j);
			// else
			// {
			// 	printf("error on the map, wierd character\n");
			// 	ft_cleanup(data);
			// }
			j++;
		}
		i++;
	}
	return (0);
}
