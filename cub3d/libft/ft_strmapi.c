/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:30:40 by hkikuchi          #+#    #+#             */
/*   Updated: 2020/11/24 13:53:32 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ans;
	int		i;

	if (!s || !f)
		return (NULL);
	ans = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(ans + i) = f(i, *(s + i));
		i++;
	}
	*(ans + i) = '\0';
	return (ans);
}
