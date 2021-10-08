/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:04:05 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/04/07 20:03:45 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1_t;
	unsigned char	*s2_t;

	i = 0;
	s1_t = (unsigned char *)s1;
	s2_t = (unsigned char *)s2;
	while ((*s1_t != '\0' || *s2_t != '\0') && (i < n))
	{
		if (*s1_t != *s2_t)
			return (*s1_t - *s2_t);
		s1_t++;
		s2_t++;
		i++;
	}
	return (0);
}
