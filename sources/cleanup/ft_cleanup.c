
#include "includes/cub3d.h"

void	ft_destroy_images(t_data *data)
{
	int	i;

	if (!data->mlx_ptr)
		return ;
	if (data->global.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->global.mlx_img);
	if (data->door.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->door.mlx_img);
	i = 0;
	while (i < 4)
	{
		if (data->wall[i].mlx_img)
			mlx_destroy_image(data->mlx_ptr, data->wall[i].mlx_img);
		i++;
	}
}

void	ft_drain_fd(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
	close(fd);
}

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
	i = 0;
	while (i < 4)
		free(data->wall[i++].path);
	free(data->floor);
	free(data->celling);
	ft_destroy_images(data);
	if (data->mlx_ptr && data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->current_fd >= 0)
		ft_drain_fd(data->current_fd);
	free(data);
}
