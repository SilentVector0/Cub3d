/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 13:36:41 by aroduit           #+#    #+#             */
/*   Updated: 2026/07/20 13:37:41 by aroduit          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	img_init(t_image *img)
{
	img->mlx_img = NULL;
	img->x = 0;
	img->y = 0;
}

void	init_game(t_data *data)
{
	data->mlx_img = NULL;
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	img_init(&data->door);
	img_init(&data->player);
	img_init(&data->wall);
	data->map.columns = 0;
	data->map.exit = 0;
	data->map.grid = NULL;
	data->map.player = 0;
	data->map.rows = 0;
}

void	verif_para(t_data *data)
{
	
}