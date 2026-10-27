/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 15:40:38 by aroduit           #+#    #+#             */
/*   Updated: 2026/10/27 15:40:50 by aroduit          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	ft_grid_size(t_data *data, int fd)
{
	char	*line;

	data->map.columns = ft_strlen(data->first_line);
	data->map.rows = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if ((int)ft_strlen(line) > data->map.columns)
			data->map.columns = ft_strlen(line);
		data->map.rows++;
		free(line);
	}
}

static void	ft_skip_config_lines(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (!ft_is_config_line(line))
		{
			free(line);
			break ;
		}
		free(line);
	}
}

static void	ft_alloc_grid(t_data *data, int fd)
{
	char	*line;
	int		i;

	i = 1;
	while (i < data->map.rows)
	{
		data->map.grid[i] = malloc(data->map.columns + 1);
		if (!data->map.grid[i])
			ft_error_msg("Memory allocation failed for row", data);
		ft_memset(data->map.grid[i], ' ', data->map.columns);
		data->map.grid[i][data->map.columns] = '\0';
		line = get_next_line(fd);
		if (!line)
			ft_error_msg("Map corruption", data);
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		ft_memcpy(data->map.grid[i], line, ft_strlen(line));
		free(line);
		i++;
	}
	data->map.grid[i] = NULL;
}

static void	ft_build_grid(t_data *data, int fd)
{
	int	i;

	data->map.grid = malloc(sizeof(char *) * (data->map.rows + 1));
	if (!data->map.grid)
		ft_error_msg("Memory allocation failed for grid", data);
	i = 0;
	while (i <= data->map.rows)
		data->map.grid[i++] = NULL;
	data->map.alloc = 1;
	data->map.grid[0] = malloc(data->map.columns + 1);
	if (!data->map.grid[0])
		ft_error_msg("Memory allocation failed for row", data);
	ft_memset(data->map.grid[0], ' ', data->map.columns);
	data->map.grid[0][data->map.columns] = '\0';
	ft_memcpy(data->map.grid[0], data->first_line, ft_strlen(data->first_line));
	ft_alloc_grid(data, fd);
}

void	ft_alloc_map(t_data *data, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Map couldn't be opened", data);
	data->current_fd = fd;
	ft_config_and_search_map(data, fd);
	ft_grid_size(data, fd);
	close(fd);
	data->current_fd = -1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Map couldn't be opened", data);
	data->current_fd = fd;
	ft_skip_config_lines(fd);
	ft_build_grid(data, fd);
	close(fd);
	data->current_fd = -1;
	ft_set_scale(data);
}
