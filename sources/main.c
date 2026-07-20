/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:30:49 by aroduit           #+#    #+#             */
/*   Updated: 2026/07/20 14:32:02 by aroduit          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	init_game(data);
	ft_check_parameters(argcc, argv, data);
	ft_init_map(data, argv[1]);
	verif_para(data);
	ray_casting(data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask,
		ft_handle_input, game);
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask,
		ft_close_game, game);
	mlx_hook(data->mlx_win, Expose, ExposureMask,
		ft_render_map, game);
	mlx_loop(data->mlx_ptr);
}
