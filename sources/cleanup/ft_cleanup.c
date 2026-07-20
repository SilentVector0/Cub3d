

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
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free(data);
}

void	ft_destroy_images(t_data *data)
{
	if (!data->mlx_ptr)
		return ;
	if (data->wall.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->wall.mlx_img);
	if (data->player.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->player.mlx_img);
	if (data->exit.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->exit.mlx_img);
	if (data->door.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->door.mlx_img);
}
