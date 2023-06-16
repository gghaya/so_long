/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:51:21 by gghaya            #+#    #+#             */
/*   Updated: 2022/11/16 23:32:44 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_check(char c, int r, void *arg)
{
	if (c == 'd' || c == 'i')
		r += ft_putnbr((int)arg);
	else if (c == 'c')
		r += ft_putchar((int)arg);
	else if (c == 's')
		r += ft_putstr((char *)arg);
	else if (c == 'x' || c == 'X')
		r += ft_hexa((unsigned int)arg, c);
	else if (c == 'p')
	{
		r += ft_putstr("0x");
		r += ft_putptr((unsigned long)arg);
	}
	else if (c == 'u')
		r += ft_putunsigned((unsigned int)arg);
	return (r);
}

static int	ft_strchr(const char *string, int searchedChar)
{
	int		i;
	char	c;

	c = (char)searchedChar;
	i = 0;
	while (string[i])
	{
		if ((char)string[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	p;
	int		i;
	int		r;

	i = 0;
	r = 0;
	va_start(p, str);
	while (str[i])
	{
		if (str[i] == '%' && str[++i] != '\0')
		{
			if (ft_strchr("uixXdscp", str[i]) == 0)
				r += ft_putchar(str[i]);
			else
				r += ft_check(str[i], 0, va_arg(p, void *));
		}
		else if (str[i] != '\0')
			r += ft_putchar(str[i]);
		if (str[i])
			i++;
	}
	if (r < 0)
		return (-1);
	va_end(p);
	return (r);
}
