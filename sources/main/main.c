/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:30:49 by aroduit           #+#    #+#             */
/*   Updated: 2026/07/20 18:15:07 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	data = malloc(sizeof(t_data));
	// if (!data)
	// 	return (1);
	init_game(data);
	printf("test1\n");
	//ft_check_parameters(argc, argv, data);
	//ft_init_map(data, argv[1]);
	if (win_creation(data) == 1)
		return (1);
	printf("test2\n");
	// mlx_hook(data->mlx_win, KeyPress, KeyPressMask,
	// 	ft_handle_input, data);
	//mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask,
	// 	ft_close_game, data);
	// mlx_hook(data->mlx_win, Expose, ExposureMask,
	// 	ft_render_map, data);
	mlx_loop(data->mlx_ptr);
}
