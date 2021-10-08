/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:48:30 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/05/15 22:34:07 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_front(const char *s, char const *set)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (!ft_strchr(set, *(s + i)))
			break ;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ans;
	size_t		i;
	size_t		j;

	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1);
	i = ft_count_front(s1, set);
	while (j > i)
	{
		if (!ft_strchr(set, *(s1 + j - 1)))
			break ;
		j--;
	}
	ans = (char *)ft_calloc(((j - i) + 1), sizeof(char));
	if (!ans)
		return (NULL);
	ft_memcpy(ans, s1 + i, (j - i));
	return (ans);
}
