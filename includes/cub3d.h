/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 14:34:08 by aroduit           #+#    #+#             */
/*   Updated: 2026/06/19 15:19:35 by msuter           ###   ########.fr       */
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

typedef struct s_texture
{
	void	*tex_img;
	int		tex_bpp;
	int		tex_

}	t_texture;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_img;
	void	*mlx_win;
	int		h;
	int		l;

}	t_mlx;

typedef struct s_game
{
	

}	t_game;

#endif