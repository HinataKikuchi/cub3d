/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:46:48 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/05/06 13:57:16 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_nstrlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*b;
	unsigned char	c;

	i = 0;
	b = (unsigned char *)buf;
	c = (unsigned char)ch;
	while (i < n)
	{
		if (*(b + i) == c)
			return ((void *)(b + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char			*ans;
	unsigned int	i;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	ans = (char *)malloc((ft_nstrlen(s1) + ft_nstrlen(s2) + 1) * sizeof(char));
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(ans + i) = *(s1 + i);
		i++;
	}
	while (*s2 != '\0')
	{
		*(ans + i) = *s2;
		s2++;
		i++;
	}
	*(ans + i) = '\0';
	free(s1);
	return (ans);
}

size_t	ft_strlcpy(char *buf1, const char *buf2, size_t n)
{
	size_t			i;
	unsigned char	*b1;
	unsigned char	*b2;

	i = 0;
	b1 = (unsigned char *)buf1;
	b2 = (unsigned char *)buf2;
	if (!buf2)
		return (0);
	if (n == 0)
	{
		buf1[0] = '\0';
		return (ft_nstrlen(buf2));
	}
	while (i <= n - 1)
	{
		b1[i] = b2[i];
		if (b2[i] == '\0')
			break ;
		i++;
	}
	b1[i] = '\0';
	return (ft_nstrlen(buf2));
}
