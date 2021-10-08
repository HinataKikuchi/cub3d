/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:51:40 by hkikuchi          #+#    #+#             */
/*   Updated: 2020/11/26 17:06:21 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *buf1, const char *buf2, size_t n)
{
	size_t			b1_size;
	size_t			b2_size;
	unsigned int	i;

	i = 0;
	b1_size = ft_strlen(buf1);
	b2_size = ft_strlen(buf2);
	if (b1_size >= n)
		return (b2_size + n);
	else
	{
		while (*(buf2 + i) != '\0' && i < n - b1_size - 1)
		{
			*(buf1 + (b1_size + i)) = *(buf2 + i);
			i++;
		}
		*(buf1 + (b1_size + i)) = '\0';
	}
	return (b1_size + b2_size);
}
