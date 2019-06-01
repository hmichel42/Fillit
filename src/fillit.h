/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 17:47:36 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 17:17:11 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <unistd.h>
# define BUFF_SIZE 545

typedef	struct	s_tetri
{
	char				**tetri;
	int					x;
	int					y;
	char				letter;
	struct s_tetri		*next;
}				t_tetri;

typedef struct	s_map
{
	char				**map;
	int					size;
}				t_map;

typedef struct	s_coord
{
	int					i;
	int					j;
}				t_coord;

/*
** Check's functions
*/
int				ft_checkmap(char *buf, int nb);
int				ft_checktetri(char *buf, int nb, int cmp, int links);
int				ft_checkchar(char *buf, int nb);
int				ft_readmap(int ac, char **av, t_tetri **begin_list);

/*
** Util.c
*/
int				ft_strtolist(char *buf, t_tetri **begin_list, int nb);
void			ft_setposition(t_tetri **begin_list, int nb);
t_tetri			*ft_tetrinew(char *buf, char letter, int start);
void			ft_putmap(t_map *map);
void			ft_freetetri(t_tetri **tetris);

/*
** Resolve.c
*/

int				ft_checkcoord1(t_map *map, t_tetri *tetris, int i, int j);
int				ft_checkcoord2(t_map *map, t_tetri *tetris, int i, int j);
t_coord			*ft_findplace(t_map *map, t_tetri *tetris, int i, int j);
void			ft_fillmap(t_tetri *tetris, t_map **map, t_coord *coord, \
				char letter);
int				ft_puttetri(t_tetri *tetris, t_map **map, char letter, \
				int start);

/*
** Resolve2.c
*/

int				ft_setmap(int size, t_map **map);
void			ft_freemap(t_map **map);
void			ft_cleantetri(t_map **map, char letter);
int				ft_solvemap(t_tetri *begin_tetris, t_map **map, int start);
t_map			*ft_resolve(t_tetri **begin_tetris, int nb_tetri);

#endif
