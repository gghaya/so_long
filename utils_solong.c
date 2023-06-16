/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_solong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:15:14 by gghaya            #+#    #+#             */
/*   Updated: 2023/06/16 17:37:40 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**copyy(char	**map, int size)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * size);
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	return (copy);
}

void	check2(t_struct *s)
{
	int		i;
	int		j;
	char	**copy;

	copy = copyy(s->map, s->size);
	i = 0;
	s->c = check(s);
	while (i < s->size)
	{
		j = 0;
		while (j < s->len)
		{
			if (s->map[i][j] == 'P')
			{
				s->xp = i;
				s->yp = j;
				break ;
			}
			j++;
		}
		i++;
	}
	i = backtracking(s, s->xp, s->yp, copy);
	if (i == 0)
		ft_error(s->map, s->size - 1);
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
	v.imgdoor = mlx_xpm_file_to_image(s->w.mlx, DOOR, &v.h, &v.w);
	s->v = v;
	s->move = 0;
	put_images(s);
	return (s);
}

t_struct	*new_win(t_struct	*s)
{
	t_win	win;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, (s->len - 1) * 64, (s->size) * 64, "GG");
	s->w = win;
	return (initt(s));
}
