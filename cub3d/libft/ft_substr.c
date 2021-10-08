/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:42:49 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/05/06 13:54:44 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	judge_len(size_t len, size_t s_len)
{
	if (s_len < len)
		return (s_len);
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	s_len;
	size_t	malloc_size;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start || len == 0)
	{
		ans = ft_calloc(1, sizeof(char));
		return (ans);
	}
	malloc_size = judge_len(len, s_len);
	ans = ft_calloc((malloc_size + 1), sizeof(char));
	if (!ans)
		return (NULL);
	i = (size_t)start;
	j = 0;
	while (j < len && i < s_len)
		*(ans + j++) = *(s + i++);
	return (ans);
}
