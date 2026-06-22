

#include "includes/cub3d.h"

void	ft_cleanup(t_data *data)
{
	int	i;

	if (!data)
		return ;
	i = 0;
	if (data->map.alloc)
	{
		while (i < data->map.rows)
			free(data->map.grid[i++]);
		free(data->map.grid);
	}
	ft_destroy_images(data);
	if (data->mlx_ptr && data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win)

}