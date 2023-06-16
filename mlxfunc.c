/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:54:18 by gghaya            #+#    #+#             */
/*   Updated: 2023/06/16 20:13:29 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	put_images(t_struct *s)
{
	t_var	var;

	var.y = 0;
	var.i = 0;
	while (s->map[var.i] != NULL)
	{
		util1(s->map[var.i], s, var, 0);
		var.y += 64;
		var.i++;
	}
	manage_events(s);
}

int	ft_close(t_win *w)
{
	mlx_destroy_window(w->mlx, w->win);
	exit(0);
}

int	ft_handelpress(int key, t_struct *s)
{
	if (key == 13)
		wkey(s);
	if (key == 0)
		akey(s);
	if (key == 1)
		dkey(s);
	if (key == 2)
		skey(s);
	if (key == 53)
		exit(0);
	mlx_clear_window(s->w.mlx, s->w.win);
	put_images(s);
	return (key);
}

void	skey(t_struct *s)
{
	t_var	var;

	var.i = 0;
	while (s->map[var.i] != NULL)
	{
		util2(s, var, s->map[var.i]);
		var.i++;
	}
}
