#include "includes/cub3d.h"

void	handle_w(t_data *data)
{
	int	j;
	int	i;

	j = data->pl.pos_x / data->map.ecart_w;
	i = (data->pl.pos_y - 4 - (SPEED * data->delta)) / data->map.ecart_h;
	if (data->map.grid[i][j] == '1')
		return;
	print_pixel(data, 0X000000);
	data->pl.pos_y -= SPEED * data->delta;
	print_pixel(data, 0xFF0000);
}

void	handle_a(t_data *data)
{
	int	j;
	int	i;

	j = (data->pl.pos_x - 4 - (SPEED * data->delta)) / data->map.ecart_w;
	i = data->pl.pos_y / data->map.ecart_h;
	if (data->map.grid[i][j] == '1')
		return;
	print_pixel(data, 0X000000);
	data->pl.pos_x -= SPEED * data->delta;
	print_pixel(data, 0xFF0000);
}

void	handle_s(t_data *data)
{
	int	j;
	int	i;

	j = data->pl.pos_x / data->map.ecart_w;
	i = (data->pl.pos_y + 4 + (SPEED * data->delta)) / data->map.ecart_h;
	if (data->map.grid[i][j] == '1')
		return;
	print_pixel(data, 0X000000);
	data->pl.pos_y += SPEED * data->delta;
	print_pixel(data, 0xFF0000);
}

void	handle_d(t_data *data)
{
	int	j;
	int	i;

	j = (data->pl.pos_x  + 4 + (SPEED * data->delta)) / data->map.ecart_w;
	i = data->pl.pos_y / data->map.ecart_h;
	if (data->map.grid[i][j] == '1')
		return;
	print_pixel(data, 0X000000);
	data->pl.pos_x += SPEED * data->delta;
	print_pixel(data, 0xFF0000);
}

// void	handle_esc(t_data *data)
// {

// }
