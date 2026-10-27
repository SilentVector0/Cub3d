/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:04:31 by aroduit           #+#    #+#             */
/*   Updated: 2026/10/27 16:04:31 by aroduit          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		ft_error_msg("Malloc data fail", NULL);
	ft_init_game(data);
	ft_check_parameters(argc, argv, data);
	ft_alloc_map(data, argv[1]);
	ft_check_config(data);
	ft_check_map(data);
	ft_win_creation(data);
	data->time = my_time();
	ft_setup_hooks(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
