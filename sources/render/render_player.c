#include "includes/cub3d.h"

void	moving_pixel(t_data *data)
{
	size_t offset;
	int		size_y;
	int		size_x;
	int		count_x;
	int		current_y;

	size_x = data->global.height / 2;
	size_y = data->global.width / 2;
	current_y = size_x - 7;
	while(current_y != size_x + 7)
	{
		offset = current_y * (data->global.line_length / 4) + size_y - 7;
		count_x = 0;
		while (count_x != 15)
		{
			data->global.addr[offset] = 0xFFFFFF;
			offset++;
			count_x++;
		}
		current_y++;
	}
}
