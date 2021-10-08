/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:09:23 by hkikuchi          #+#    #+#             */
/*   Updated: 2020/11/26 19:39:19 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;
	char			c;
	int				tmp;

	i = n;
	if (n < 0)
	{
		i = (-1) * i;
		write(fd, "-", 1);
	}
	tmp = i % 10;
	i /= 10;
	c = tmp + '0';
	if (i)
		ft_putnbr_fd(i, fd);
	ft_putchar_fd(c, fd);
}
