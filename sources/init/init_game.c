/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 13:36:41 by aroduit           #+#    #+#             */
/*   Updated: 2026/08/12 13:32:39 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	img_init(t_image *img)
{
	img->mlx_img = NULL;
	img->addr = NULL;
	img->width = 0;
	img->height = 0;
	img->bpp = 0;
	img->line_length = 0;
}

void	init_game(t_data *data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	img_init(&data->door);
	img_init(&data->global);
	img_init(&data->wall[NO]);
	img_init(&data->wall[SO]);
	img_init(&data->wall[WE]);
	img_init(&data->wall[EA]);
	data->global.width = 1080;
	data->global.height = 720;
	data->pl.pos_x = data->global.width / 2; // lignes tempo
	data->pl.pos_y = data->global.height / 2; //lignes tempo
	data->map.columns = 0;
	data->map.exit = 0;
	data->map.grid = NULL;
	data->map.player = 0;
	data->map.rows = 0;
	data->map.alloc = 0;
	data->kp.key[W] = 0;
	data->kp.key[A] = 0;
	data->kp.key[S] = 0;
	data->kp.key[D] = 0;
}

