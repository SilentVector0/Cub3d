/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:32:30 by aroduit           #+#    #+#             */
/*   Updated: 2026/06/22 13:34:36 by aroduit          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_var(&data);
	verif_para(&data);
	ray_casting(&data);
	mlx_hook(&data->mlx_win, KeyPress, KeyPressMask,
		ft_handle_input, game);
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask,
		ft_close_game, game);
	mlx_hook(data->mlx_win, Expose, ExposureMask,
		ft_render_map, game);
	mlx_loop(data->mlx_ptr);
}
