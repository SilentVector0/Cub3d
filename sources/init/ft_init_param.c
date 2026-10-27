/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 01:47:47 by aroduit           #+#    #+#             */
/*   Updated: 2026/10/27 01:48:21 by aroduit          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	ft_get_path(t_data *data, char *line, char **path)
{
	int		i;
	int		len;

	i = 0;
	while (line[i] == ' ')
		i++;
	len = ft_strlen(line) - i;
	while (len > 0 && line[len + i - 1] == ' ')
		len--;
	if (len == 0)
		ft_error_msg("Missing texture path", data);
	*path = malloc(len + 1);
	if (!*path)
		ft_error_msg("alloc path fail", data);
	ft_memcpy(*path, line + i, len);
	(*path)[len] = '\0';
}

static int	ft_get_nb(t_data *data, char **s, char sep)
{
	int	nb;
	int	digits;

	while (**s == ' ')
		(*s)++;
	nb = 0;
	digits = 0;
	while (**s >= '0' && **s <= '9')
	{
		nb = nb * 10 + (**s - '0');
		if (nb > 255)
			ft_error_msg("Invalide color (exepted R,G,B in [0, 255])", data);
		(*s)++;
		digits++;
	}
	while (**s == ' ')
		(*s)++;
	if (digits == 0 || **s != sep)
		ft_error_msg("Invalide color (exepted R,G,B in [0, 255])", data);
	if (sep)
		(*s)++;
	return (nb);
}

static void	ft_get_color(t_data *data, char *line, int *color)
{
	char	*s;

	s = line;
	*color = ft_get_nb(data, &s, ',') << 16;
	*color |= ft_get_nb(data, &s, ',') << 8;
	*color |= ft_get_nb(data, &s, '\0');
}

static void	ft_is_texture_path(t_data *data, char *line)
{
	if (!ft_strncmp(line, "NO ", 3) && !data->wall[NO].path)
		ft_get_path(data, line + 3, &data->wall[NO].path);
	else if (!ft_strncmp(line, "SO ", 3) && !data->wall[SO].path)
		ft_get_path(data, line + 3, &data->wall[SO].path);
	else if (!ft_strncmp(line, "WE ", 3) && !data->wall[WE].path)
		ft_get_path(data, line + 3, &data->wall[WE].path);
	else if (!ft_strncmp(line, "EA ", 3) && !data->wall[EA].path)
		ft_get_path(data, line + 3, &data->wall[EA].path);
	else if (!ft_strncmp(line, "F ", 2) && data->floor == -1)
		ft_get_color(data, line + 2, &data->floor);
	else if (!ft_strncmp(line, "C ", 2) && data->ceiling == -1)
		ft_get_color(data, line + 2, &data->ceiling);
	else
		ft_error_msg("Duplicate texture or color", data);
}

void	ft_config_and_search_map(t_data *data, int fd)
{
	while (1)
	{
		data->first_line = get_next_line(fd);
		if (!data->first_line)
			break ;
		if (ft_strlen(data->first_line) > 0
			&& data->first_line[ft_strlen(data->first_line) - 1] == '\n')
			data->first_line[ft_strlen(data->first_line) - 1] = '\0';
		if (!ft_is_config_line(data->first_line))
			return ;
		if (ft_strlen(data->first_line) > 0)
			ft_is_texture_path(data, data->first_line);
		free(data->first_line);
	}
	ft_error_msg("No map found in file", data);
}
