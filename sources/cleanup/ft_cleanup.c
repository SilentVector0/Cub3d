/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 00:56:11 by aroduit           #+#    #+#             */
/*   Updated: 2026/10/27 00:57:31 by aroduit          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	ft_destroy_images(t_data *data)
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

static void	ft_drain_fd(int fd)
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

static void	ft_free_map(t_data *data)
{
	int	i;

	if (!data->map.alloc)
		return ;
	i = 0;
	while (i < data->map.rows)
		free(data->map.grid[i++]);
	free(data->map.grid);
}

static void	ft_free_mlx(t_data *data)
{
	ft_destroy_images(data);
	if (data->mlx_ptr && data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	ft_cleanup(t_data *data)
{
	int	i;

	if (!data)
		return ;
	if (data->first_line)
		free(data->first_line);
	ft_free_map(data);
	i = 0;
	while (i < 4)
		free(data->wall[i++].path);
	ft_free_mlx(data);
	if (data->current_fd >= 0)
		ft_drain_fd(data->current_fd);
	free(data);
}
