/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:15:14 by gghaya            #+#    #+#             */
/*   Updated: 2023/06/11 15:43:12 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static int	countwords(const char *str, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && c == str[i])
			i++;
		if (str[i])
			k++;
		while (str[i] && c != str[i])
			i++;
	}
	return (k);
}

static void	freewords(char **c, int i)
{
	while (i >= 0)
	{
		free(c[i]);
		i--;
	}
	free(c);
}

static char	**fct(const char *s, char c, int i, int k)
{
	int		start;
	char	**rslt;

	rslt = (char **)malloc((countwords(s, c) + 1) * sizeof(char *));
	if (!rslt)
		return (0);
	while (++k < countwords(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		rslt[k] = ft_substr(s, start, i - start);
		if (rslt[k] == NULL)
		{
			freewords (rslt, k);
			return (NULL);
		}
	}
	rslt[k] = 0;
	return (rslt);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (fct (s, c, 0, -1));
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
