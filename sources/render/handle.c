#include "includes/cub3d.h"

static int ft_can_move(t_data *data, double new_x, double new_y)
{
	int j;
	int i;

	j = new_x / data->map.ecart_w;
	i = new_y / data->map.ecart_h;
	if (data->map.grid[i][j] == '1')
		return (0);
	return (1);
}

void ft_handle_move(t_data *data, double dx, double dy)
{
	double new_x;
	double new_y;

	new_x = data->pl.pos_x + dx * data->pl.dir_x - dy * data->pl.dir_y;
	new_y = data->pl.pos_y + dx * data->pl.dir_y + dy * data->pl.dir_x;
	if (ft_can_move(data, new_x, data->pl.pos_y))
		data->pl.pos_x = new_x;
	if (ft_can_move(data, data->pl.pos_x, new_y))
		data->pl.pos_y = new_y;
}

void	ft_handle_rotate(t_data *data, double angle)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = data->pl.dir_x;
	data->pl.dir_x = data->pl.dir_x * cos(angle) - data->pl.dir_y * sin(angle);
	data->pl.dir_y = old_dir_x * sin(angle) + data->pl.dir_y * cos(angle);
	old_plane_x = data->pl.plane_x;
	data->pl.plane_x = data->pl.plane_x * cos(angle) - data->pl.plane_y * sin(angle);
	data->pl.plane_y = old_plane_x * sin(angle) + data->pl.plane_y * cos(angle);
}

// void	handle_esc(t_data *data)
// {

// }
