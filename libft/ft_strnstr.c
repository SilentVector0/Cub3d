/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:56:54 by aroduit           #+#    #+#             */
/*   Updated: 2025/10/14 19:56:54 by aroduit          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!*s2)
		return ((char *)s1);
	while (n-- && *s1)
	{
		i = 0;
		while (s2[i] && s1[i] == s2[i] && i < n + 1)
			i++;
		if (!s2[i])
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
