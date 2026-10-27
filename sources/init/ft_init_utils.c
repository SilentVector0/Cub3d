/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 21:40:21 by aroduit           #+#    #+#             */
/*   Updated: 2026/10/27 21:44:53 by aroduit          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	ft_is_config_line(char *line)
{
	while (*line == ' ')
		line++;
	if (ft_strlen(line) == 0)
		return (1);
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3)
		|| !ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

void	ft_set_scale(t_data *data)
{
	data->map.ecart_h = 200 / data->map.rows;
	data->map.ecart_w = 200 / data->map.columns;
	if (data->map.ecart_h < data->map.ecart_w)
		data->map.ecart_w = data->map.ecart_h;
	else
		data->map.ecart_h = data->map.ecart_w;
	if (data->map.ecart_w < 1)
	{
		data->map.ecart_w = 1;
		data->map.ecart_h = 1;
	}
}

static int	ft_is_blank_row(char *row)
{
	int	i;

	i = 0;
	while (row[i] == ' ')
		i++;
	return (row[i] == '\0');
}

static void	ft_trim_trailing_rows(t_data *data)
{
	while (data->map.rows > 1
		&& ft_is_blank_row(data->map.grid[data->map.rows - 1]))
	{
		free(data->map.grid[data->map.rows - 1]);
		data->map.grid[data->map.rows - 1] = NULL;
		data->map.rows--;
	}
}

void	ft_check_empty_rows(t_data *data)
{
	int	j;

	ft_trim_trailing_rows(data);
	j = 0;
	while (j < data->map.rows)
	{
		if (ft_is_blank_row(data->map.grid[j]))
			ft_error_msg("Empty line in map", data);
		j++;
	}
}
