/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:49:19 by gghaya            #+#    #+#             */
/*   Updated: 2023/06/17 16:15:42 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL	"textures/AnyConv.com__tree1.xpm"
# define PLAYER	"textures/AnyConv.com__lofifront.xpm"
# define COLLECT	"textures/AnyConv.com__collect.xpm"
# define EXIT	"textures/AnyConv.com__doorclosed.xpm"
# define BACK	"textures/AnyConv.com__background.xpm"
# define DOOR	"textures/AnyConv.com__dooropened.xpm"
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line.h"
# include "ft_printf/ft_printf.h"

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
	int	x;
	int	y;
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
	int		xp;
	int		yp;
	int		xe;
	int		ye;
	int		c;
	int		move;
}				t_struct;

int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
void		check_extension(char *fname);
char		*ft_strrchr(const char *string, int searchedChar);
int			ft_strncmp(const char *first, const char *second, size_t n);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
t_struct	*fillin_map(char *filename, t_struct *s);
void		ft_error(void);
int			checkcaracteres(char	**map, int i, int j);
void		check_walls(char	**map, int size);
void		checkcontour(char **map, int size, int len);
int			check(t_struct	*s);
void		check_form(int size, int len);
int			ft_strsearch(const char *string, int searchedChar);
int			ft_close(t_win *w);
t_struct	*new_win(t_struct	*s);
t_struct	*initt(t_struct	*s);
int			ft_handelpress(int key, t_struct *s);
t_struct	*readmap(char *filename);
void		manage_events(t_struct *s);
void		wkey(t_struct *s);
void		dkey(t_struct *s);
void		akey(t_struct *s);
void		skey(t_struct *s);
int			backtracking(t_struct *s, int xp, int yp, char **map);
void		check2(t_struct *s);
char		**copyy(char	**map, int size);
void		put_images(t_struct *s);
void		util1(char *c, t_struct *s, t_var var, int i);
void		util2(t_struct *s, t_var var, char *c);
void		ft_checkimages(t_vvar	v);
void		util3(t_struct *s, t_var var, char *c, char *cc);
void		util4(t_struct *s, t_var var, char *c, char *cc);
#endif