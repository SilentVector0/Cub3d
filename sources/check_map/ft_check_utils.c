/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:06:59 by aroduit           #+#    #+#             */
/*   Updated: 2026/10/27 17:06:59 by aroduit          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_check_parameters(int argc, char **argv, t_data *data)
{
	int	arg_len;

	if (argc != 2)
		ft_error_msg("You must provide exactly one map file", data);
	arg_len = ft_strlen(argv[1]);
	if (arg_len < 4 || ft_strncmp(argv[1] + arg_len - 4, ".cub", 4))
		ft_error_msg("Map file must have a .cub extension", data);
}

void	ft_check_config(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!data->wall[i].path)
			ft_error_msg("Missing texture", data);
		i++;
	}
	if (data->floor == -1 || data->ceiling == -1)
		ft_error_msg("Missing floor or ceiling color", data);
}
