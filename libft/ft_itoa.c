/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:06:15 by aroduit           #+#    #+#             */
/*   Updated: 2025/10/12 14:06:15 by aroduit          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_n(long n)
{
	int	count;

	count = (n <= 0);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		count;
	long	nmb;

	nmb = n;
	count = count_n(nmb);
	dest = malloc(count + 1);
	if (!dest)
		return (NULL);
	dest[count--] = '\0';
	if (nmb == 0)
		dest[0] = '0';
	if (nmb < 0)
	{
		dest[0] = '-';
		nmb = -nmb;
	}
	while (nmb)
	{
		dest[count--] = nmb % 10 + '0';
		nmb /= 10;
	}
	return (dest);
}
