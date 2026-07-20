/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 13:36:41 by aroduit           #+#    #+#             */
/*   Updated: 2026/07/20 17:44:28 by msuter           ###   ########.fr       */
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
	img_init(&data->wall[NORD]);
	img_init(&data->wall[SUD]);
	img_init(&data->wall[EST]);
	img_init(&data->wall[OUEST]);
	data->global.width = 1280;
	data->global.height = 720;
	data->map.columns = 0;
	data->map.exit = 0;
	data->map.grid = NULL;
	data->map.player = 0;
	data->map.rows = 0;
	data->map.alloc = 0;
}

