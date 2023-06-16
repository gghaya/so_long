/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 01:19:52 by gghaya            #+#    #+#             */
/*   Updated: 2022/11/16 22:11:10 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	char	*hexa;
	int		r;

	hexa = "0123456789abcdef";
	r = 0;
	if (ptr >= 16)
	{
		r += ft_putptr(ptr / 16);
		r += ft_putptr(ptr % 16);
	}
	else
		r += ft_putchar(hexa[ptr]);
	return (r);
}
