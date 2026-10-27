/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 15:46:56 by aroduit           #+#    #+#             */
/*   Updated: 2026/10/27 15:46:56 by aroduit          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	ft_draw_background(t_data *data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < data->global.height)
	{
		color = data->ceiling;
		if (y >= data->global.height / 2)
			color = data->floor;
		x = 0;
		while (x < data->global.width)
		{
			data->global.addr[y * (data->global.line_length / 4) + x] = color;
			x++;
		}
		y++;
	}
}

static	void	ft_print_case(t_data *data, int i, int j, int color)
{
	int	y;
	int	x;
	int	offset;

	y = data->map.ecart_h * i;
	while (y < data->map.ecart_h * (i + 1))
	{
		x = data->map.ecart_w * j;
		while (x < data->map.ecart_w * (j + 1))
		{
			offset = y * (data->global.line_length / 4) + x;
			if (y >= 0 && y < data->global.height
				&& x >= 0 && x < data->global.width)
				data->global.addr[offset] = color;
			x++;
		}
		y++;
	}
}

static void	ft_draw_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i != data->map.rows)
	{
		j = 0;
		while (j < data->map.columns)
		{
			if (data->map.grid[i][j] == '1')
				ft_print_case(data, i, j, COLOR_WALL);
			j++;
		}
		i++;
	}
}

static void	ft_print_player(t_data *data, int color)
{
	int	px;
	int	py;
	int	x;
	int	y;

	px = data->pl.pos_x * data->map.ecart_w;
	py = data->pl.pos_y * data->map.ecart_h;
	y = py - 3;
	while (y <= py + 3)
	{
		x = px - 3;
		while (x <= px + 3)
		{
			if (y >= 0 && y < data->global.height
				&& x >= 0 && x < data->global.width)
				data->global.addr[y * (data->global.line_length / 4)
					+ x] = color;
			x++;
		}
		y++;
	}
}

int	ft_render_frame(t_data *data)
{
	ft_draw_background(data);
	ft_raycasting(data);
	ft_draw_walls(data);
	ft_print_player(data, COLOR_PLAYER);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->global.mlx_img, 0, 0);
	return (0);
}
