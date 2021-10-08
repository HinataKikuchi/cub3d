/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:40:28 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/04/09 13:18:16 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

int	get_next_line(int fd, char **line)
{
	int			res;
	static char	*save[MAX_ASIZE];
	int			i;

	i = 0;
	res = 1;
	if (!line || (fd < 0 || 256 <= fd) || BUFFER_SIZE <= 0)
		return (ERROR_NO);
	save[fd] = ft_read_line(fd, &res, save[fd]);
	if (res == -1)
		return (res);
	line[0] = ft_cat_line(&res, line[0], save[fd], &i);
	if (!save[fd])
		return (res);
	ft_strlcpy(save[fd], &save[fd][i + 1], ft_nstrlen(&save[fd][i + 1]));
	if (!res)
	{
		free(save[fd]);
		save[fd] = NULL;
	}
	return (res);
}

char	*ft_read_line(int fd, int *res, char *save)
{
	char	*buf;

	buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buf)
	{
		(*res) = -1;
		return (NULL);
	}
	while ((!save || !ft_memchr(save, '\n', ft_nstrlen(save))) && (*res) != -1)
	{
		(*res) = read(fd, buf, BUFFER_SIZE);
		if ((*res) == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[(*res)] = '\0';
		if (!(*res))
			break ;
		save = ft_strjoin_free(save, buf);
	}
	free(buf);
	return (save);
}

char	*ft_cat_line(int *res, char *line, char *save, int *i)
{
	if (!(*res))
		return (ft_strdup(save));
	while (save[*i] != '\n')
		(*i)++;
	line = malloc(((*i) + 1) * sizeof(char));
	if (!line)
	{
		(*res) = -1;
		return (NULL);
	}
	ft_strlcpy(line, save, (*i));
	(*res) = 1;
	return (line);
}
