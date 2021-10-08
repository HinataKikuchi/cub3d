/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:08:02 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/04/07 20:06:01 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(int n)
{
	int	j;

	j = 0;
	while (n)
	{
		n /= 10;
		j++;
	}
	return (j);
}

static int	ft_judge_minimam(int n)
{
	if (n == -2147483648)
		return (1);
	return (0);
}

static void	ft_intoa(char *ans, int tmp1, int j)
{
	int		tmp2;
	char	tmp;

	while (tmp1)
	{
		tmp2 = tmp1 % 10;
		tmp1 = tmp1 / 10;
		tmp = tmp2 + '0';
		*(ans + j - 1) = tmp;
		j--;
	}
}

static char	*ft_min(char *ans)
{
	ft_memcpy(ans, "-2147483648", 11);
	ans[11] = '\0';
	return (ans);
}

char	*ft_itoa(int n)
{
	char	*ans;
	int		j;
	int		tmp1;

	if (n > 0)
		ans = ft_calloc((ft_countdigits(n) + 1), sizeof(char));
	else
		ans = ft_calloc((ft_countdigits(n) + 2), sizeof(char));
	if (!ans)
		return (NULL);
	if (ft_judge_minimam(n))
		return (ft_min(ans));
	j = 0;
	*ans = '0';
	if (n < 0)
	{
		n *= (-1);
		*ans = '-';
		j++;
	}
	tmp1 = n;
	j += ft_countdigits(n);
	ft_intoa(ans, tmp1, j);
	return (ans);
}
