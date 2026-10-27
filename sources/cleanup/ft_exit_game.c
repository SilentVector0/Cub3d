/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 22:36:29 by aroduit           #+#    #+#             */
/*   Updated: 2026/10/27 22:36:29 by aroduit          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	ft_close_game(t_data *data)
{
	ft_putendl_fd(PURPLE "Exit Game" RESET, 1);
	ft_cleanup(data);
	exit(EXIT_SUCCESS);
}

void	ft_error_msg(char *msg, t_data *data)
{
	ft_putstr_fd(RED "Error\n" PURPLE, 2);
	ft_putendl_fd(msg, 2);
	ft_putstr_fd(RESET, 2);
	ft_cleanup(data);
	exit(EXIT_FAILURE);
}
