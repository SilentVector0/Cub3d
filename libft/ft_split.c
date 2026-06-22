/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:51:31 by aroduit           #+#    #+#             */
/*   Updated: 2025/10/14 19:51:31 by aroduit          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	in;

	count = 0;
	in = 0;
	while (*s)
	{
		if (*s != c && !in && ++count)
			in = 1;
		else if (*s == c)
			in = 0;
		s++;
	}
	return (count);
}

static size_t	len_word(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static char	*word_dup(char const *s, size_t len)
{
	char	*word;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static void	*free_split(char **dest, size_t i)
{
	while (i--)
		free(dest[i]);
	free(dest);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	i;
	size_t	len;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	dest = malloc(sizeof(char *) * (words + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = len_word(s, c);
		dest[i] = word_dup(s, len);
		if (!dest[i])
			return (free_split(dest, i));
		i++;
		s += len;
	}
	dest[i] = NULL;
	return (dest);
}
