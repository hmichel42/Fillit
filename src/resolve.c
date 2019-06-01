/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/28 09:52:09 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 19:49:11 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkcoord1(t_map *map, t_tetri *tetris, int i, int j)
{
	int		cmt;

	cmt = 0;
	if (map->map[j][i] == '.' && (tetris->tetri)[tetris->y][tetris->x] != '.')
		cmt++;
	if (i + 1 < map->size && tetris->x + 1 <= 3 && (map->map)[j][i + 1] == '.'
		&& (tetris->tetri)[tetris->y][tetris->x + 1] != '.')
		cmt++;
	if (i + 2 < map->size && tetris->x + 2 <= 3 && (map->map)[j][i + 2] == '.'
		&& (tetris->tetri)[tetris->y][tetris->x + 2] != '.')
		cmt++;
	if (i + 3 < map->size && tetris->x + 3 <= 3 && (map->map)[j][i + 3] == '.'
		&& (tetris->tetri)[tetris->y][tetris->x + 3] != '.')
		cmt++;
	if (i - 2 >= 0 && j + 1 < map->size && tetris->x - 2 >= 0 &&
		tetris->y + 1 <= 3 && (map->map)[j + 1][i - 2] == '.' &&
		(tetris->tetri)[tetris->y + 1][tetris->x - 2] != '.')
		cmt++;
	if (i - 1 >= 0 && j + 1 < map->size && tetris->x - 1 >= 0 &&
		tetris->y + 1 <= 3 && (map->map)[j + 1][i - 1] == '.' &&
		(tetris->tetri)[tetris->y + 1][tetris->x - 1] != '.')
		cmt++;
	return (cmt);
}

int		ft_checkcoord2(t_map *map, t_tetri *tetris, int i, int j)
{
	int		cmt;

	cmt = 0;
	if (j + 1 < map->size && i + 1 < map->size && tetris->x + 1 <= 3 &&
		tetris->y + 1 <= 3 && (map->map)[j + 1][i + 1] == '.' &&
		(tetris->tetri)[tetris->y + 1][tetris->x + 1] != '.')
		cmt++;
	if (j + 1 < map->size && i + 2 < map->size && tetris->x + 2 <= 3 &&
		tetris->y + 1 <= 3 && (map->map)[j + 1][i + 2] == '.' &&
		(tetris->tetri)[tetris->y + 1][tetris->x + 2] != '.')
		cmt++;
	if (i - 1 >= 0 && j + 2 < map->size && tetris->x - 1 >= 0 &&
		tetris->y + 2 <= 3 && (map->map)[j + 2][i - 1] == '.' &&
		(tetris->tetri)[tetris->y + 2][tetris->x - 1] != '.')
		cmt++;
	if (j + 2 < map->size && (map->map)[j + 2][i] && tetris->y + 2 <= 3 &&
		(map->map)[j + 2][i] == '.' &&
		(tetris->tetri)[tetris->y + 2][tetris->x] != '.')
		cmt++;
	if (j + 2 < map->size && i + 1 < map->size && tetris->y + 2 <= 3 &&
		tetris->x + 1 <= 3 && (map->map)[j + 2][i + 1] == '.' &&
		(tetris->tetri)[tetris->y + 2][tetris->x + 1] != '.')
		cmt++;
	return (cmt);
}

t_coord	*ft_findplace(t_map *map, t_tetri *tetris, int i, int j)
{
	t_coord		*coord;
	int			cmt;

	if (!(coord = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	cmt = ft_checkcoord1(map, tetris, i, j) + ft_checkcoord2(map, tetris, i, j);
	if (j + 3 < map->size && (map->map)[j + 3][i] && tetris->y + 3 <= 3 &&
		(map->map)[j + 3][i] == '.' &&
		(tetris->tetri)[tetris->y + 3][tetris->x] != '.')
		cmt++;
	if (j + 1 < map->size && tetris->y + 1 <= 3 &&
		(map->map)[j + 1][i] == '.' &&
		(tetris->tetri)[tetris->y + 1][tetris->x] != '.')
		cmt++;
	if (cmt == 4)
	{
		coord->i = i;
		coord->j = j;
		return (coord);
	}
	coord->i = -1;
	return (coord);
}

void	ft_fillmap(t_tetri *tetris, t_map **map, t_coord *coord, char letter)
{
	((*map)->map)[coord->j][coord->i] = letter;
	if (tetris->x + 1 <= 3 && (tetris->tetri)[tetris->y][tetris->x + 1] != '.')
		((*map)->map)[coord->j][coord->i + 1] = letter;
	if (tetris->x + 2 <= 3 && (tetris->tetri)[tetris->y][tetris->x + 2] != '.')
		((*map)->map)[coord->j][coord->i + 2] = letter;
	if (tetris->x + 3 <= 3 && (tetris->tetri)[tetris->y][tetris->x + 3] != '.')
		((*map)->map)[coord->j][coord->i + 3] = letter;
	if (tetris->x - 2 >= 0 && tetris->y + 1 <= 3 &&
		(tetris->tetri)[tetris->y + 1][tetris->x - 2] != '.')
		((*map)->map)[coord->j + 1][coord->i - 2] = letter;
	if (tetris->x - 1 >= 0 && tetris->y + 1 <= 3 &&
		(tetris->tetri)[tetris->y + 1][tetris->x - 1] != '.')
		((*map)->map)[coord->j + 1][coord->i - 1] = letter;
	if (tetris->y + 1 <= 3 && (tetris->tetri)[tetris->y + 1][tetris->x] != '.')
		((*map)->map)[coord->j + 1][coord->i] = letter;
	if (tetris->x + 1 <= 3 && tetris->y + 1 <= 3 &&
		(tetris->tetri)[tetris->y + 1][tetris->x + 1] != '.')
		((*map)->map)[coord->j + 1][coord->i + 1] = letter;
	if (tetris->x + 2 <= 3 && tetris->y + 1 <= 3 &&
		(tetris->tetri)[tetris->y + 1][tetris->x + 2] != '.')
		((*map)->map)[coord->j + 1][coord->i + 2] = letter;
	if (tetris->x - 1 >= 0 && tetris->y + 2 <= 3 &&
		(tetris->tetri)[tetris->y + 2][tetris->x - 1] != '.')
		((*map)->map)[coord->j + 2][coord->i - 1] = letter;
}

int		ft_puttetri(t_tetri *tetris, t_map **map, char letter, int start)
{
	t_coord *coord;

	while (tetris != NULL && tetris->letter != letter)
		tetris = tetris->next;
	coord = ft_findplace(*map, tetris, start % (*map)->size, \
	start / (*map)->size);
	if (coord->i == -1 || tetris == NULL)
	{
		free(coord);
		return (0);
	}
	ft_fillmap(tetris, map, coord, letter);
	if (tetris->y + 2 <= 3 && (tetris->tetri)[tetris->y + 2][tetris->x] != '.')
		((*map)->map)[coord->j + 2][coord->i] = letter;
	if (tetris->x + 1 <= 3 && tetris->y + 2 <= 3 &&
		(tetris->tetri)[tetris->y + 2][tetris->x + 1] != '.')
		((*map)->map)[coord->j + 2][coord->i + 1] = letter;
	if (tetris->y + 3 <= 3 && (tetris->tetri)[tetris->y + 3][tetris->x] != '.')
		((*map)->map)[coord->j + 3][coord->i] = letter;
	free(coord);
	return (1);
}
