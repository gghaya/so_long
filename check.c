/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:12:08 by gghaya            #+#    #+#             */
/*   Updated: 2023/06/17 18:31:30 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkcaracteres(char **map, int i, int j)
{
	t_var	var;

	var.i = 0;
	var.c = 0;
	var.e = 0;
	var.p = 0;
	while (map[var.i] != NULL)
	{
		var.j = 0;
		while (map[var.i][var.j] != '\0')
		{
			fstatment(map[var.i][var.j], &var);
			if (map[var.i][var.j] == 'P')
			{
				var.p++;
				i = var.i;
				j = var.j;
			}
			var.j++;
		}
		var.i++;
	}
	if (var.c < 1 || var.e != 1 || var.p != 1)
		ft_error();
	return (var.c);
}

void	check_extension(char *fname)
{
	char	*res;

	res = ft_strrchr(fname, '.');
	if (ft_strncmp(res, ".ber", 4) != 0 || ft_strlen(res) != 4)
	{
		ft_printf("Error\ninvalid file extension\n");
		exit(0);
	}
}

void	check_walls(char	**map, int size)
{
	int	i;

	i = 0;
	while (map[0][i] == '1')
		i++;
	if (map[0][i] != '\0')
		ft_error();
	i = 0;
	while (map[size - 1][i] == '1')
		i++;
	if (map[size - 1][i] != '\0')
	{
		ft_error();
	}
}

void	checkcontour(char **map, int size, int len)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] == '1' && map[i][len - 2] == '1')
				i++;
		else
			break ;
	}
	if (i != size)
		ft_error();
}

int	check(t_struct	*s)
{
	check_walls(s->map, s->size);
	checkcontour(s->map, s->size, s->len);
	return (checkcaracteres(s->map, s->xp, s->yp));
}
