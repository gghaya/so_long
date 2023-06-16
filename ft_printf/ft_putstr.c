/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 03:13:28 by gghaya            #+#    #+#             */
/*   Updated: 2022/11/16 22:58:05 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i] != '\0')
	{
		r += ft_putchar(str[i]);
		i++;
	}
	return (r);
}
