/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_solong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:15:14 by gghaya            #+#    #+#             */
/*   Updated: 2023/06/17 18:35:59 by gghaya           ###   ########.fr       */
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
	char	**copy;

	copy = copyy(s->map, s->size);
	s->i = 0;
	s->c = check(s);
	while (s->i < s->size)
	{
		s->j = 0;
		while (s->j < s->len)
		{
			if (s->map[s->i][s->j] == 'P')
			{
				s->xp = s->i;
				s->yp = s->j;
				break ;
			}
			s->j++;
		}
		s->i++;
	}
	s->i = backtracking(s, s->xp, s->yp, copy);
	if (s->i == 0)
		ft_error();
	freecopy(copy, s->size);
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
	ft_checkimages(v);
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
