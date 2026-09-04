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

void	raycast_2d(t_data *data, int color)
{
	size_t offset;
	double	x;
	double	y;
	int	j;
	int	i;

	x = data->pl.pos_x;
	y = data->pl.pos_y;
	j = x / data->map.ecart_w;
	i = y / data->map.ecart_h;
	while ((y >= 0 && y < data->global.height) && data->map.grid[i][j] != '1')
	{
		offset = (int)y * (data->global.line_length/4) + (int)x;
		printf("x: %f, offset: %zu\n", x, offset);
		data->global.addr[offset] = color;
		j = x / data->map.ecart_w;
		i = y / data->map.ecart_h;
		y--;
	}
	//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->global.mlx_img, 0, 0);
}

int	print_map(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while(i != data->map.rows)
	{
		j = 0;
		while(j < data->map.columns)
		{
			if (data->map.grid[i][j] == '1')
				print_case(data, i, j, 0XFFFFFF);
			if (data->map.grid[i][j] == 'N' || data->map.grid[i][j] == 'S'
				|| data->map.grid[i][j] == 'E' || data->map.grid[i][j] == 'W')
				print_pixel(data, 0xFF0000);
			j++;
		}
		i++;
	}
	//raycast_2d(data, 0X0000FF);
	return (0);
}
