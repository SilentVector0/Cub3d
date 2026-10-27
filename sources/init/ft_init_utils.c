/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 01:35:50 by aroduit           #+#    #+#             */
/*   Updated: 2026/10/27 01:35:50 by aroduit          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	ft_is_config_line(char *line)
{
	if (ft_strlen(line) == 0)
		return (1);
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3)
		|| !ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}
