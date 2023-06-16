/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:32:04 by gghaya            #+#    #+#             */
/*   Updated: 2023/06/16 19:10:53 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	backtracking(t_struct *s, int xp, int yp, char **map)
{
	static int	e;
	static int	c;

	if (map[xp][yp] == 'E')
	{
		e = 1;
		return (0);
	}
	if (map[xp][yp] == 'C')
		c++;
	map[xp][yp] = '1';
	if (map[xp + 1][yp] != '1')
		backtracking(s, xp + 1, yp, map);
	if (map[xp][yp + 1] != '1')
		backtracking(s, xp, yp + 1, map);
	if (map[xp - 1][yp] != '1')
		backtracking(s, xp - 1, yp, map);
	if (map[xp][yp - 1] != '1')
		backtracking(s, xp, yp - 1, map);
	if (e == 1 && c == s->c)
		return (1);
	return (0);
}

void	manage_events(t_struct *s)
{
	mlx_hook(s->w.win, 17, 0, ft_close, &s->w);
	mlx_hook(s->w.win, 2, 0, ft_handelpress, s);
	mlx_loop(s->w.mlx);
}
