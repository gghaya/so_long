/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:12:32 by gghaya            #+#    #+#             */
/*   Updated: 2023/06/16 20:14:01 by gghaya           ###   ########.fr       */
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

void	util1(char *c, t_struct *s, t_var	var, int j)
{
	var.x = 0;
	while (c[j] != '\0')
	{
		mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgback, var.x, var.y);
		if (s->map[var.i][j] == 'C')
			mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgcollect, var.x,
				var.y);
		if (s->map[var.i][j] == 'E')
		{
			if (s->c == 0)
				mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgdoor, var.x,
					var.y);
			else
				mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgexit, var.x,
					var.y);
		}
		if (s->map[var.i][j] == 'P')
			mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgplayer, var.x,
				var.y);
		if (s->map[var.i][j] == '1')
			mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgwall, var.x,
				var.y);
		var.x += 64;
		j++;
	}
}

void	util2(t_struct *s, t_var var, char *c)
{
	var.j = 0;
	while (c[var.j] != '\0')
	{
		if (c[var.j] == 'P' && (c[var.j + 1] == '0' || c[var.j + 1] == 'C'))
		{
			if (c[var.j + 1] == 'C')
				s->c--;
			c[var.j] = '0';
			c[var.j + 1] = 'P';
			s->move++;
			ft_printf("move %d\n", s->move);
			return ;
		}
		if (c[var.j] == 'P' && c[var.j + 1] == 'E'
			&& s->c == 0)
			exit(0);
		var.j++;
	}
}
