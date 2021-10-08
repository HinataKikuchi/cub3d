/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:00:52 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/05/15 16:11:18 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*ans;
	size_t		i;
	size_t		s_size;

	s_size = ft_strlen(s);
	ans = (char *)malloc((s_size + 1) * sizeof(char));
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (i < s_size)
	{
		*(ans + i) = *(s + i);
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
