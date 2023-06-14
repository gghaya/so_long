/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:12:32 by gghaya            #+#    #+#             */
/*   Updated: 2023/05/04 17:15:15 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *first, const char *second, size_t n)
{
	unsigned char	*f ;
	unsigned char	*s;
	size_t			i;

	f = (unsigned char *)first;
	s = (unsigned char *)second;
	i = 0;
	if (first == NULL)
		return (-1);
	while ((f[i] || s[i]) && i < n)
	{
		if (f[i] != s[i])
			return ((unsigned char )f[i] - (unsigned char )s[i]);
		i++;
	}
	return (0);
}
