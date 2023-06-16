/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:47:16 by gghaya            #+#    #+#             */
/*   Updated: 2022/11/16 22:54:39 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putunsigned(unsigned int nb)
{
	long int	n;
	int			r;

	r = 0;
	n = nb;
	if (n < 0)
	{
		r += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		r += ft_putunsigned(n / 10);
		r += ft_putunsigned(n % 10);
	}
	else
		r += ft_putchar(n + '0');
	return (r);
}
