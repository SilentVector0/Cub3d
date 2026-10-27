/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 21:14:23 by aroduit           #+#    #+#             */
/*   Updated: 2026/10/27 21:14:51 by aroduit          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	ft_set_player(t_data *data, char c, int j, int i)
{
	if (data->map.player == 1)
		ft_error_msg("Too Many player", data);
	data->map.player = 1;
	data->pl.pos_x = i + 0.5;
	data->pl.pos_y = j + 0.5;
	if (c == 'N')
		data->pl.dir_y = -1;
	else if (c == 'E')
		data->pl.dir_x = 1;
	else if (c == 'S')
		data->pl.dir_y = 1;
	else if (c == 'W')
		data->pl.dir_x = -1;
	data->pl.plane_x = -data->pl.dir_y * tan((FOV / 2.0) * M_PI / 180);
	data->pl.plane_y = data->pl.dir_x * tan((FOV / 2.0) * M_PI / 180);
	return ;
}

static void	ft_check_space_neighbors(t_data *data, int j, int i)
{
	if (j > 0)
		if (data->map.grid[j - 1][i] != '1' && data->map.grid[j - 1][i] != ' ')
			ft_error_msg("Map is not closed", data);
	if (j < data->map.rows - 1)
		if (data->map.grid[j + 1][i] != '1' && data->map.grid[j + 1][i] != ' ')
			ft_error_msg("Map is not closed", data);
	if (i > 0)
		if (data->map.grid[j][i - 1] != '1' && data->map.grid[j][i - 1] != ' ')
			ft_error_msg("Map is not closed", data);
	if (i < data->map.columns - 1)
		if (data->map.grid[j][i + 1] != '1' && data->map.grid[j][i + 1] != ' ')
			ft_error_msg("Map is not closed", data);
}

static void	ft_check_border(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map.grid[0][++i])
		if (data->map.grid[0][i] != ' ' && data->map.grid[0][i] != '1')
			ft_error_msg("Map is not closed", data);
	i = -1;
	j = data->map.rows - 1;
	while (data->map.grid[j][++i])
		if (data->map.grid[j][i] != ' ' && data->map.grid[j][i] != '1')
			ft_error_msg("Map is not closed", data);
	j = -1;
	while (++j < data->map.rows)
		if (data->map.grid[j][0] != ' ' && data->map.grid[j][0] != '1')
			ft_error_msg("Map is not closed", data);
	j = -1;
	i = data->map.columns - 1;
	while (++j < data->map.rows)
		if (data->map.grid[j][i] != ' ' && data->map.grid[j][i] != '1')
			ft_error_msg("Map is not closed", data);
}

void	ft_check_map(t_data *data)
{
	int		i;
	int		j;
	char	c;

	j = -1;
	ft_check_border(data);
	ft_check_empty_rows(data);
	while (++j < data->map.rows)
	{
		i = -1;
		while (++i < data->map.columns)
		{
			c = data->map.grid[j][i];
			if (c != '0' && c != '1' && c != 'N' && c != 'S'
				&& c != 'E' && c != 'W' && c != ' ')
				ft_error_msg("Invalid character in map", data);
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				ft_set_player(data, c, j, i);
			if (c == ' ')
				ft_check_space_neighbors(data, j, i);
		}
	}
	if (data->map.player == 0)
		ft_error_msg("No player", data);
}
