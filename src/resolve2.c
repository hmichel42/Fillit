/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/25 11:42:33 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 11:43:28 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_setmap(int size, t_map **map)
{
	int	i;

	if (!(*map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if (!((*map)->map = (char **)malloc(sizeof(char *) * (size))))
		return (0);
	(*map)->size = size;
	i = 0;
	while (i < size)
	{
		if (!((*map)->map[i] = ft_strnew(size)))
			return (0);
		(*map)->map[i] = (char *)ft_memset((char *)(*map)->map[i], 46, size);
		i++;
	}
	return (1);
}

void	ft_freemap(t_map **map)
{
	int	i;

	if (*map)
	{
		i = 0;
		while (i < (*map)->size)
		{
			free((*map)->map[i]);
			i++;
		}
		free((*map)->map);
		free(*map);
	}
}

void	ft_cleantetri(t_map **map, char letter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (*map)->size && j < (*map)->size)
	{
		if (((*map)->map)[j][i] == letter)
			((*map)->map)[j][i] = '.';
		if (i + 1 < ((*map)->size))
			i++;
		else
		{
			i = 0;
			j++;
		}
	}
}

int		ft_solvemap(t_tetri *begin_tetris, t_map **map, int start)
{
	if (!(begin_tetris))
		return (1);
	if (ft_puttetri(begin_tetris, map, begin_tetris->letter, start))
	{
		if (ft_solvemap(begin_tetris->next, map, 0))
			return (1);
		else
		{
			ft_cleantetri(map, begin_tetris->letter);
			if (ft_solvemap(begin_tetris, map, start + 1))
				return (1);
		}
	}
	if (start + 1 < (*map)->size * (*map)->size)
	{
		if (ft_solvemap(begin_tetris, map, start + 1))
			return (1);
	}
	return (0);
}

t_map	*ft_resolve(t_tetri **begin_tetris, int nb_tetri)
{
	t_map	*map;
	int		size;

	size = ft_intsqrt(nb_tetri * 4);
	if (!(ft_setmap(size, &map)))
		return (NULL);
	while (!ft_solvemap(*begin_tetris, &map, 0))
	{
		size++;
		ft_freemap(&map);
		if (!(ft_setmap(size, &map)))
			return (NULL);
	}
	return (map);
}
