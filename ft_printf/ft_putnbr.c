/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:59:09 by gghaya            #+#    #+#             */
/*   Updated: 2022/11/16 22:11:06 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr(int nb)
{
	long	n;
	int		r;

	r = 0;
	n = nb;
	if (n < 0)
	{
		r += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		r += ft_putnbr(n / 10);
		r += ft_putnbr(n % 10);
	}
	else
		r += ft_putchar(n + '0');
	return (r);
}
