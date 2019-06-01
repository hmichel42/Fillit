/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 17:35:38 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 17:38:47 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_tetrinew(char *buf, char letter, int start)
{
	t_tetri		*elem;
	int			i;

	i = 0;
	if (!(elem = ft_memalloc(sizeof(t_tetri))))
		return (NULL);
	if (buf != NULL && *buf != '\0' && letter >= 'A' && letter <= 'Z')
	{
		if (!(elem->tetri = (char **)ft_memalloc(sizeof(char *) * 4)))
			return (NULL);
		while (i <= 3)
		{
			if (!(elem->tetri[i] = ft_strsub(buf, start, 4)))
				return (NULL);
			i++;
			start = start + 5;
		}
		elem->letter = letter;
	}
	else
		return (NULL);
	elem->next = NULL;
	return (elem);
}

void	ft_setposition(t_tetri **begin_list, int nb)
{
	int		x;
	int		y;
	t_tetri	*tetris;

	tetris = *begin_list;
	while (nb)
	{
		x = 0;
		y = 0;
		while (tetris->tetri[y][x] != '#')
		{
			x++;
			if (x == 4)
			{
				x = 0;
				y++;
			}
		}
		tetris->x = x;
		tetris->y = y;
		tetris = tetris->next;
		nb--;
	}
}

int		ft_strtolist(char *buf, t_tetri **begin_list, int nb)
{
	int		i;
	t_tetri	*tetris;

	i = 1;
	if (!((*begin_list) = ft_tetrinew(buf, 'A', 0)))
		return (-1);
	tetris = *begin_list;
	while (i < nb)
	{
		if (!(tetris->next = ft_tetrinew(buf, 'A' + i, i * 21)))
			return (-1);
		tetris = tetris->next;
		i++;
	}
	ft_setposition(begin_list, nb);
	return (1);
}

void	ft_putmap(t_map *map)
{
	int		j;

	j = 0;
	while (j < map->size)
	{
		write(1, (map->map)[j], ft_strlen((map->map)[j]));
		write(1, "\n", 1);
		j++;
	}
}

void	ft_freetetri(t_tetri **tetris)
{
	int		i;
	t_tetri	*actual_one;
	t_tetri	*next_one;

	actual_one = *tetris;
	while (actual_one != NULL)
	{
		i = 0;
		next_one = actual_one->next;
		while (i <= 3)
		{
			free(actual_one->tetri[i]);
			i++;
		}
		free(actual_one->tetri);
		free(actual_one);
		actual_one = next_one;
	}
}
