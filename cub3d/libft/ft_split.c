/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:08:24 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/04/07 19:48:56 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count(char const *s, char c)
{
	int				i;
	unsigned int	ans;

	i = 0;
	ans = 0;
	if (*(s + i) == c)
		while (*(s + i) == c)
			i++;
	while (*(s + i) != '\0')
	{
		if ((*(s + i) == c && *(s + (i + 1)) != c) && *(s + (i + 1)) != '\0')
			ans++;
		i++;
	}
	return (ans);
}

static char	**ft_splitcpy(char const *s, char c, char **ans)
{
	unsigned int	i;
	int				j;
	int				line;

	i = 0;
	j = 0;
	line = ft_count(s, c) + 1;
	while (j < line)
	{
		if (*s == c)
			while (*s == c)
				s++;
		while ((*s != c) && *s != '\0')
		{
			ans[j][i] = *s;
			i++;
			s++;
		}
		ans[j][i] = '\0';
		i = 0;
		j++;
	}
	ans[j] = NULL;
	return (ans);
}

static void	ft_free_col(char **ans, unsigned int i)
{
	unsigned int	n;

	n = i;
	while (n > 0)
	{
		free(*(ans + n));
		*(ans + n) = NULL;
		n--;
	}
	free(*(ans + n));
	*(ans + n) = NULL;
	free(ans);
}

static char	**ft_single_string(char const *s, char c)
{
	char		**ans;
	char		*str;
	const char	c_string[2] = {c, '\0'};

	str = ft_strtrim(s, c_string);
	if (!str)
		return (NULL);
	if (str[0] == '\0')
	{
		ans = (char **)malloc(sizeof(char *));
		ans[0] = NULL;
		free(str);
	}
	else
	{
		ans = (char **)malloc(2 * sizeof(char *));
		ans[0] = str;
		ans[1] = NULL;
	}
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	char			**ans;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_count(s, c) == 0)
		return (ft_single_string(s, c));
	ans = (char **)malloc((ft_count(s, c) + 2) * sizeof(char *));
	if (ans == NULL)
		return (NULL);
	while (i < (ft_count(s, c) + 1))
	{
		*(ans + i) = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (*(ans + i) == NULL)
		{
			ft_free_col(ans, i);
			return (NULL);
		}
		i++;
	}
	ans = ft_splitcpy(s, c, ans);
	return (ans);
}
