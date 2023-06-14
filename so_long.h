/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:49:19 by gghaya            #+#    #+#             */
/*   Updated: 2023/06/14 20:42:25 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL	"img/AnyConv.com__tree1.xpm"
# define PLAYER	"img/AnyConv.com__lofifront.xpm"
# define COLLECT	"img/AnyConv.com__collect.xpm"
# define EXIT	"img/AnyConv.com__doorclosed.xpm"
# define BACK	"img/AnyConv.com__background.xpm"
# define DOOR	"img/AnyConv.com__dooropened.xpm"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "get_next_line.h"
# include "mlx/mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef struct s_var
{
	int	i;
	int	c;
	int	e;
	int	p;
	int	j;
}	t_var;
typedef struct var
{
	char	*str;
	int		i;
	int		fd;
	int		len;
	int		len1;
}	t_varr;

typedef struct win
{
	void	*mlx;
	void	*win;
}				t_win;

typedef struct s_ss
{
	void	*imgwall;
	void	*imgcollect;
	void	*imgexit;
	void	*imgplayer;
	void	*imgback;
	void	*imgdoor;
	t_var	var;
	int		h;
	int		w;
	int		x;
	int		y;
}				t_vvar;

typedef struct s_s
{
	t_vvar	v;
	t_win	w;
	char	**map;
	int		size;
	int		len;
	int		x;
	int		y;
	int		c;
}				t_struct;

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	check_extension(char *fname);
char	*ft_strrchr(const char *string, int searchedChar);
int		ft_strncmp(const char *first, const char *second, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
t_struct	*fillin_map(char *filename, t_struct *s);
void	ft_error(char **map, int i);
int	checkcaracteres(char	**map);
void	check_walls(char	**map, int size);
void	checkcontour(char **map, int size, int len);
int	check(t_struct	*s);
void	check_form(char **map, int size, int len);
int		ft_strsearch(const char *string, int searchedChar);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_close(t_win *w);
t_struct	*new_win(t_struct	*s);
t_struct	*initt(t_struct	*s);
int	ft_handelpress(int key, t_struct *s);
void manage_events(t_struct *s);
void wkey(t_struct *s);
void	dkey(t_struct *s);
void	akey(t_struct *s);
void f(t_struct *s);
void	skey(t_struct *s);
#endif