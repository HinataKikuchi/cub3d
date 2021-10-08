/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:53:22 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/05/06 13:39:57 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char	*ft_skip_blank(const char *nptr)
{
	while (('\t' <= *nptr && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	return ((char *)(nptr));
}

int	ft_atoi(const char *nptr)
{
	unsigned long	ans;
	int				sign;
	char			*tmp;

	sign = 1;
	ans = 0;
	nptr = (const char *)ft_skip_blank(nptr);
	if (nptr[0] == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	tmp = (char *)nptr;
	while (*nptr != '\0' && ft_isdigit(*nptr))
	{
		ans = (ans * 10) + (int)*nptr - '0';
		nptr++;
		if (((nptr - tmp) > 19 || ans >= LONG_MAX) && sign == 1)
			return (-1);
		else if (ans > LONG_MAX || (nptr - tmp) > 19)
			return (0);
	}
	return ((int)(ans * sign));
}
