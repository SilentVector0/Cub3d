/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroduit <aroduit@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 08:52:05 by aroduit           #+#    #+#             */
/*   Updated: 2026/01/24 08:53:11 by aroduit          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*alloc_line(int fd, char *str);
static char	*gnl_strjoin(char *s1, char *s2);
static char	*next_line(char *str);
static char	*rm_line(char *str);

static char	*alloc_line(int fd, char *str)
{
	char	*buf;
	int		count_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	count_read = 1;
	while (count_read > 0)
	{
		count_read = read(fd, buf, BUFFER_SIZE);
		if (count_read == -1)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[count_read] = '\0';
		str = gnl_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buf);
	return (str);
}

static char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		dest[i++] = s1[j++];
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}

static char	*next_line(char	*str)
{
	char	*new;
	int		i;

	if (!str[0])
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

static char	*rm_line(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new = malloc(ft_strlen(str) - i + 1);
	if (!new)
		return (NULL);
	j = 0;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	free(str);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash[fd] = alloc_line(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = next_line(stash[fd]);
	stash[fd] = rm_line(stash[fd]);
	return (line);
}
