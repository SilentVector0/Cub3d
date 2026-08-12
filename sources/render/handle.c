#include "includes/cub3d.h"

void	handle_w(t_data *data)
{
	print_pixel(data, 0X000000);
	data->pl.pos_y -= SPEED * data->delta;
	print_pixel(data, 0xFFFFFF);
}

void	handle_a(t_data *data)
{
	print_pixel(data, 0X000000);
	data->pl.pos_x -= SPEED * data->delta;
	print_pixel(data, 0xFFFFFF);
}

void	handle_s(t_data *data)
{
	print_pixel(data, 0X000000);
	data->pl.pos_y += SPEED * data->delta;
	print_pixel(data, 0xFFFFFF);
}

void	handle_d(t_data *data)
{
	print_pixel(data, 0X000000);
	data->pl.pos_x += SPEED * data->delta;
	print_pixel(data, 0xFFFFFF);
}

// void	handle_esc(t_data *data)
// {

// }
