#include "includes/cub3d.h"

void	handle_w(t_data *data)
{
	int	j;
	int	i;

	j = data->pl.pos_x / data->map.ecart_w;
	i = (data->pl.pos_y - 4 - (SPEED * data->delta)) / data->map.ecart_h;
	if (data->map.grid[i][j] == '1')
		return;
	raycast_2d(data, 0X000000);
	print_pixel(data, 0X000000);
	data->pl.pos_y -= SPEED * data->delta;
	print_pixel(data, 0xFF0000);
	raycast_2d(data, 0X0000FF);
}

void	handle_a(t_data *data)
{
	int	j;
	int	i;

	j = (data->pl.pos_x - 4 - (SPEED * data->delta)) / data->map.ecart_w;
	i = data->pl.pos_y / data->map.ecart_h;
	if (data->map.grid[i][j] == '1')
		return;
	raycast_2d(data, 0X000000);
	print_pixel(data, 0X000000);
	data->pl.pos_x -= SPEED * data->delta;
	print_pixel(data, 0xFF0000);
	raycast_2d(data, 0X0000FF);
}

void	handle_s(t_data *data)
{
	int	j;
	int	i;

	j = data->pl.pos_x / data->map.ecart_w;
	i = (data->pl.pos_y + 4 + (SPEED * data->delta)) / data->map.ecart_h;
	if (data->map.grid[i][j] == '1')
		return;
	raycast_2d(data, 0X000000);
	print_pixel(data, 0X000000);
	data->pl.pos_y += SPEED * data->delta;
	print_pixel(data, 0xFF0000);
	raycast_2d(data, 0X0000FF);
}

void	handle_d(t_data *data)
{
	int	j;
	int	i;

	j = (data->pl.pos_x  + 4 + (SPEED * data->delta)) / data->map.ecart_w;
	i = data->pl.pos_y / data->map.ecart_h;
	if (data->map.grid[i][j] == '1')
		return;
	raycast_2d(data, 0X000000);
	print_pixel(data, 0X000000);
	data->pl.pos_x += SPEED * data->delta;
	print_pixel(data, 0xFF0000);
	raycast_2d(data, 0X0000FF);
}

// void	handle_esc(t_data *data)
// {

// }
