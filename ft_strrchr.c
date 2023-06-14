/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:51:52 by gghaya            #+#    #+#             */
/*   Updated: 2023/06/11 19:55:07 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	char	ch;
	char	*str;
	int		i;

	str = (char *)string;
	ch = (char)searchedChar;
	i = ft_strlen(string);
	while (i >= 0)
	{
		if (str[i] == ch)
			return (str + i);
		i--;
	}
	return (0);
}

int	ft_strsearch(const char *string, int searchedChar)
{
	int		i;
	char	c;

	c = (char)searchedChar;
	i = 0;
	while (string[i])
	{
		if ((char)string[i] == c)
			i++;
	}
	return (0);
}
