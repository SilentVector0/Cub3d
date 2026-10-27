/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 03:21:18 by aroduit           #+#    #+#             */
/*   Updated: 2026/10/27 03:21:18 by aroduit          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

long	my_time(void)
{
	long			time;
	struct timeval	t;

	gettimeofday(&t, NULL);
	time = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (time);
}
