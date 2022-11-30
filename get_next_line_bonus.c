/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:52:15 by tmiftah           #+#    #+#             */
/*   Updated: 2022/11/30 16:06:27 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_rhyme(char *str)
{
	ssize_t	i;
	char	*r;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	r = malloc(i + 1);
	r[i--] = 0;
	while (i >= 0)
	{
		r[i] = str[i];
		i--;
	}
	return (r);
}

char	*next_rhyme(char *str)
{
	char	*ret;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	i++;
	ret = malloc(ft_strlen(str) - i + 1);
	if (!ret)
		return (NULL);
	while (str[i])
		ret[j++] = str[i++];
	ret[j] = 0;
	free (str);
	return (ret);
}

char	*ft_read(int fd, char *str)
{
	int		i;
	char	*ret;

	i = 1;
	ret = malloc(BUFFER_SIZE + 1);
	if (!ret)
		return (NULL);
	while (!find_break(str) && i != 0)
	{
		i = read(fd, ret, BUFFER_SIZE);
		if (i == -1)
		{
			free(ret);
			free(str);
			return (NULL);
		}
		ret[i] = '\0';
		str = ft_join(str, ret);
	}
	free(ret);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*c;
	static char	*str[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	c = ft_rhyme(str[fd]);
	str[fd] = next_rhyme(str[fd]);
	return (c);
}
