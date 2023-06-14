/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:54:18 by gghaya            #+#    #+#             */
/*   Updated: 2023/06/14 21:24:48 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	put_images(t_struct *s)
{
	t_var	var;
	int		x;
	int		y;

	x = 0;
	y = 0;
	var.i = 0;
	// printf("%d*",s->c);
	while (s->map[var.i] != NULL)
	{
		var.j = 0;
		x = 0;
		while (s->map[var.i][var.j] != '\0')
		{
			mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgback, x, y);
			if (s->map[var.i][var.j] == 'C')
				mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgcollect, x, y);
			if (s->map[var.i][var.j] == 'E')
			{
				if(s->c == 0)
					mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgdoor, x, y);
				else
					mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgexit, x, y);
			}
			if (s->map[var.i][var.j] == 'P')
				mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgplayer, x, y);
			if (s->map[var.i][var.j] == '1')
				mlx_put_image_to_window(s->w.mlx, s->w.win, s->v.imgwall, x, y);
			x += 64;
			var.j++;
		}
		y += 64;
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
			if (s->map[var.i][var.j] == 'P' && (s->map[var.i][var.j+1] == '0' || s->map[var.i][var.j+1] == 'C'))
			{
				if(s->map[var.i][var.j+1] == 'C')
					s->c--;
				s->map[var.i][var.j] = '0';
				s->map[var.i][var.j + 1] = 'P';
				return ;
			}
			if (s->map[var.i][var.j] == 'P' && s->map[var.i ][var.j + 1] == 'E' && s->c == 0)
				exit(0);
			var.j++;
		}
		var.i++;
	}
}

void	akey(t_struct *s)
{
	t_var	var;

	var.i = 0;

	while (s->map[var.i] != NULL)
	{
		var.j = 1;
		while (s->map[var.i][var.j] != '\0')
		{
			if (s->map[var.i][var.j] == 'P' &&( s->map[var.i][var.j - 1] == '0' || s->map[var.i][var.j - 1] == 'C'))
			{
				if(s->map[var.i][var.j - 1] == 'C')
					s->c--;
				s->map[var.i][var.j] = '0';
				s->map[var.i][var.j - 1] = 'P';
			}
			if (s->map[var.i][var.j] == 'P' && s->map[var.i][var.j - 1] == 'E' && s->c == 0)
				exit(0);
			var.j++;
		}
		var.i++;
	}
}

void	dkey(t_struct *s)
{
	t_var	var;

	var.i = 0;
	var.c = 0;
	var.e = 0;
	var.p = 0;
	while (s->map[var.i] != NULL)
	{
		var.j = 1;
		while (s->map[var.i][var.j] != '\0')
		{
			if (s->map[var.i][var.j] == 'P' && (s->map[var.i + 1][var.j] == '0' || s->map[var.i + 1][var.j] == 'C'))
			{
				if(s->map[var.i + 1][var.j] == 'C')
					s->c--;
				s->map[var.i][var.j] = '0';
				s->map[var.i + 1][var.j] = 'P';
				return ;
			}
			if (s->map[var.i][var.j] == 'P' && s->map[var.i + 1][var.j] == 'E' && s->c == 0)
				exit(0);
			var.j++;
		}
		var.i++;
	}
}

void	wkey(t_struct *s)
{
	t_var	var;

	var.i = 1;
	var.c = 0;
	var.e = 0;
	var.p = 0;
	while (s->map[var.i] != NULL)
	{
		var.j = 0;
		while (s->map[var.i][var.j] != '\0')
		{
			if (s->map[var.i][var.j] == 'P' && (s->map[var.i - 1][var.j] == '0' || s->map[var.i - 1][var.j] == 'C'))
			{
				if(s->map[var.i - 1][var.j] == 'C')
					s->c--;
				s->map[var.i -1][var.j] = 'P';
				s->map[var.i][var.j] = '0';
			}
			if (s->map[var.i][var.j] == 'P' && s->map[var.i - 1][var.j] == 'E' && s->c == 0)
				exit(0);
			var.j++;
		}
		var.i++;
	}
}

t_struct	*initt(t_struct	*s)
{
	t_vvar	v;

	v.x = 0;
	v.y = 0;
	v.imgwall = mlx_xpm_file_to_image(s->w.mlx, WALL, &v.h, &v.w);
	v.imgcollect = mlx_xpm_file_to_image(s->w.mlx, COLLECT, &v.h, &v.w);
	v.imgexit = mlx_xpm_file_to_image(s->w.mlx, EXIT, &v.h, &v.w);
	v.imgplayer = mlx_xpm_file_to_image(s->w.mlx, PLAYER, &v.h, &v.w);
	v.imgback = mlx_xpm_file_to_image(s->w.mlx, BACK, &v.h, &v.w);
	v.imgdoor  = mlx_xpm_file_to_image(s->w.mlx, DOOR, &v.h, &v.w);
	s->v = v;
	printf("%d",s->c);
	put_images(s);
	return (s);
}

t_struct	*new_win(t_struct	*s)
{
	t_win	win;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, (s->len - 1) * 64, (s->size) * 64, "so_long");
	s->w = win;
	return(initt(s));
}

void manage_events(t_struct *s)
{
	mlx_hook(s->w.win, 17, 0, ft_close, &s->w);
	mlx_hook(s->w.win, 2, 0, ft_handelpress, s);
	mlx_loop(s->w.mlx);
}