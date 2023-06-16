/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:46:22 by gghaya            #+#    #+#             */
/*   Updated: 2023/06/16 20:47:09 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_struct	*readmap(char *filename)
{
	char		*str;
	int			fd;
	t_struct	s;

	fd = open(filename, O_CREAT | O_RDWR, 0777);
	if (fd == -1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	s.size = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		s.size++;
		free(str);
		str = get_next_line(fd);
	}
	s.map = malloc ((s.size + 1) * sizeof(char *));
	s.map [s.size] = NULL;
	close(fd);
	return (fillin_map(filename, &s));
}

t_struct	*fillin_map(char *filename, t_struct *s)
{
	t_varr	v;

	v.fd = open(filename, O_CREAT | O_RDWR, 0777);
	v.str = get_next_line(v.fd);
	v.len = ft_strlen(v.str);
	s->len = v.len;
	v.i = 0;
	while (v.str != NULL)
	{
		if (v.str[0] == '\n')
			ft_error(s->map, v.i);
		if (v.i == s->size - 1)
			v.len++;
		s->map[v.i] = malloc ((v.len) * sizeof(char));
		s->map[v.i] = ft_strncpy(s->map[v.i], v.str, v.len - 1);
		free(v.str);
		v.str = get_next_line(v.fd);
		v.len = ft_strlen(v.str);
		v.i++;
	}
	check2(s);
	new_win(s);
	return (s);
}

void	ft_error(char **map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	ft_printf("Error\n");
	exit(1);
}

void	check_form(char **map, int size, int len)
{
	if (len - 1 == size)
		ft_error(map, 0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	// char** map =
	readmap(argv[1]);

	// int i = -1;
	// while(++i < 7)
	// 	free(map[i]);
	// free(map); while true ;do leaks so_long; done;
	return(0);
}

// void	leaks()
// {
// 	system("leaks so_long");
// }
// int main(int ar, char**arg)
// {
// 	main2(ar, arg);
// 	// atexit(leaks);
// }