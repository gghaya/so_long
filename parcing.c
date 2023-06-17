/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:46:22 by gghaya            #+#    #+#             */
/*   Updated: 2023/06/17 18:28:59 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_struct	*readmap(char *filename)
{
	char		*str;
	int			fd;
	t_struct	s;

	fd = open(filename, O_RDWR, 0777);
	if (fd == -1)
		ft_error();
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

	v.fd = open(filename, O_RDWR, 0777);
	v.str = get_next_line(v.fd);
	v.len = ft_strlen(v.str);
	s->len = v.len;
	v.i = 0;
	if (!v.str)
		ft_error();
	while (v.str != NULL)
	{
		if (v.i == s->size - 1)
			v.len++;
		if (v.len != s->len || v.len > 40 || s->size > 22 || v.str[0] == '\n')
			ft_error();
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

void	ft_error(void)
{
	ft_printf("Error\n");
	ft_printf("invalid map!\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		check_extension(argv[1]);
	readmap(argv[1]);
	return (0);
}
