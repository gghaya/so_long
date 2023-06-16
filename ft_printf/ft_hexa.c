/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basehexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:36:44 by gghaya            #+#    #+#             */
/*   Updated: 2022/11/16 22:12:06 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_hexa(unsigned int nb, char c)
{
	char	*hextable;
	int		r;

	r = 0;
	if (nb >= 16)
	{
		r += ft_hexa(nb / 16, c);
		r += ft_hexa(nb % 16, c);
	}
	else if (c == 'X')
	{
		hextable = "0123456789ABCDEF" ;
		r += ft_putchar(hextable[nb]);
	}
	else
	{
		hextable = "0123456789abcdef";
		r += ft_putchar(hextable[nb]);
	}
	return (r);
}
