/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxfunc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:48 by gghaya            #+#    #+#             */
/*   Updated: 2023/06/16 20:19:18 by gghaya           ###   ########.fr       */
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
				ft_printf("move %d\n",s->move);
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
		var.j = 1;
		while (s->map[var.i][var.j] != '\0')
		{
			if (s->map[var.i][var.j] == 'P' && (s->map[var.i + 1][var.j] == '0'
				|| s->map[var.i + 1][var.j] == 'C'))
			{
				if  (s->map[var.i + 1][var.j] == 'C')
					s->c--;
				s->map[var.i][var.j] = '0';
				s->map[var.i + 1][var.j] = 'P';
				s->move++;
				ft_printf("move %d\n",s->move);
				return ;
			}
			if (s->map[var.i][var.j] == 'P' && s->map[var.i + 1][var.j] == 'E'
				&& s->c == 0)
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
			if (s->map[var.i][var.j] == 'P' && (s->map[var.i - 1][var.j] == '0'
				|| s->map[var.i - 1][var.j] == 'C'))
			{
				if (s->map[var.i - 1][var.j] == 'C')
					s->c--;
				s->map[var.i -1][var.j] = 'P';
				s->map[var.i][var.j] = '0';
				s->move++;
				ft_printf("move %d\n",s->move);
			}
			if (s->map[var.i][var.j] == 'P' && s->map[var.i - 1][var.j] == 'E'
				&& s->c == 0)
				exit(0);
			var.j++;
		}
		var.i++;
	}
}
