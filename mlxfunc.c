/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:54:18 by gghaya            #+#    #+#             */
/*   Updated: 2023/06/16 19:33:58 by gghaya           ###   ########.fr       */
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
		var.j = 0;
		var.x = 0;
		while (s->map[var.i][var.j] != '\0')
		{
			mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgback, var.x, var.y);
			if (s->map[var.i][var.j] == 'C')
				mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgcollect, var.x, var.y);
			if (s->map[var.i][var.j] == 'E')
			{
				if(s->c == 0)
					mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgdoor, var.x, var.y);
				else
					mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgexit, var.x, var.y);
			}
			if (s->map[var.i][var.j] == 'P')
				mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgplayer, var.x, var.y);
			if (s->map[var.i][var.j] == '1')
				mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgwall, var.x, var.y);
			var.x += 64;
			var.j++;
		}
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
		var.j = 0;
		while (s->map[var.i][var.j] != '\0')
		{
			if (s->map[var.i][var.j] == 'P' && (s->map[var.i][var.j + 1] == '0'
				|| s->map[var.i][var.j + 1] == 'C'))
			{
				if (s->map[var.i][var.j + 1] == 'C')
					s->c--;
				s->map[var.i][var.j] = '0';
				s->map[var.i][var.j + 1] = 'P';
				s->move++;
				ft_printf("move %d\n", s->move);
				return ;
			}
			if (s->map[var.i][var.j] == 'P' && s->map[var.i][var.j + 1] == 'E'
				&& s->c == 0)
				exit(0);
			var.j++;
		}
		var.i++;
	}
}
