/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxfunc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:48 by gghaya            #+#    #+#             */
/*   Updated: 2023/06/17 17:40:24 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	akey(t_struct *s)
{
	t_var	var;

	var.i = 0;
	while (s->map[var.i] != NULL)
	{
		var.j = 1;
		while (s->map[var.i][var.j] != '\0')
		{
			if (s->map[var.i][var.j] == 'P' && (s->map[var.i][var.j - 1] == '0'
				|| s->map[var.i][var.j - 1] == 'C'))
			{
				if (s->map[var.i][var.j - 1] == 'C')
					s->c--;
				s->map[var.i][var.j] = '0';
				s->map[var.i][var.j - 1] = 'P';
				s->move++;
				ft_printf("move %d\n", s->move);
			}
			if (s->map[var.i][var.j] == 'P' && s->map[var.i][var.j - 1] == 'E'
				&& s->c == 0)
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
	while (s->map[var.i] != NULL)
	{
		if (util3(s, var, s->map[var.i], s->map[var.i + 1]))
			return ;
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
		util3(s, var, s->map[var.i], s->map[var.i - 1]);
		var.i++;
	}
}

void	ft_checkimages(t_vvar	v)
{
	if (v.imgback == NULL || v.imgcollect == NULL || v.imgdoor == NULL)
		ft_error();
	if (v.imgexit == NULL || v.imgplayer == NULL || v.imgwall == NULL)
		ft_error();
}
