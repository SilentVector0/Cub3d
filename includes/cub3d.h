/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:12:50 by aroduit           #+#    #+#             */
/*   Updated: 2026/07/20 14:38:37 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
#define CUB_3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <math.h>

typedef struct s_image
{
	void	*mlx_img;
	int		x;
	int		y;
}	t_image;

typedef	struct s_map
{
	char	**grid;
	int		rows;
	int		columns;
	int		player;
	int		exit;
	int		alloc;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_img;
	void	*mlx_win;
	t_map	map;
	t_image	player;
	t_image	wall;
	t_image	door;
}	t_data;

#endif
