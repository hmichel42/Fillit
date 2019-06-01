/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/28 09:52:09 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 09:52:12 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int     ft_setmap(int size, t_map **map) // OK
{
    int     i;

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

void    ft_freemap(t_map **map)
{
    int    i;

    if (*map)
    {
        i = 0;
        while (i < (*map)->size)
        {
            free ((*map)->map[i]);
            i++;
        }
        free ((*map)->map);
        free (*map);
    }
}

void    ft_cleantetri(t_map **map, char letter) // OK
{
    int     i;
    int     j;

    //printf ("clean tetri lettre %c\n", letter);
    i = 0;
    j = 0;
    while (i < (*map)->size && j < (*map)->size)
    {
        //printf("i = %d\n", i);
        //printf("j = %d\n\n", j);
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
/*
t_coord *ft_findplace(t_map *map, t_tetri *tetris, int i, int j) // OK
{
    t_coord     *coord;
    int         cmt;

    printf("depart findplace\n");
    while ((map->map)[j][i] != '.')
    {
        if (i < map->size)
            i++;
        else if (j < map->size)
        {
            i = 0;
            j++;
        }
        else
            return (NULL);
    }
    if (!(coord = (t_coord *)malloc(sizeof(t_coord *))))
        return (NULL);
    //printf("findplace, depart : i = %d et j = %d\n", i, j);
    //printf("findplace, depart : x = %d et y = %d\n", tetris->x, tetris->y);
    while (1) //i < map->size - 1 || j < map->size - 1
    {
        cmt = 0;
        if (map->map[j][i] == '.' && (tetris->tetri)[tetris->y][tetris->x] != '.')
            cmt++;
        if (i + 1 < map->size && tetris->x + 1 <= 3 && (map->map)[j][i + 1] == '.'
            && (tetris->tetri)[tetris->y][tetris->x + 1] != '.')
            cmt++;
        if (i + 2 < map->size && tetris->x + 2 <= 3 &&
            (map->map)[j][i + 2] == '.' && (tetris->tetri)[tetris->y][tetris->x + 2] != '.')
            cmt++;
        if (i + 3 < map->size && tetris->x + 3 <= 3 && (map->map)[j][i + 3] == '.' &&
            (tetris->tetri)[tetris->y][tetris->x + 3] != '.')
            cmt++;
        if (i - 2 >= 0 && j + 1 < map->size && tetris->x - 2 >= 0 && tetris->y + 1 <= 3 &&
            (map->map)[j + 1][i - 2] == '.' && (tetris->tetri)[tetris->y + 1][tetris->x - 2] != '.')
            cmt++;
        if (i - 1 >= 0 && j + 1 < map->size && tetris->x - 1 >= 0 && tetris->y + 1 <= 3 &&
            (map->map)[j + 1][i - 1] == '.' && (tetris->tetri)[tetris->y + 1][tetris->x - 1] != '.')
            cmt++;
        if (j + 1 < map->size && tetris->y + 1 <= 3 && (map->map)[j + 1][i] == '.' &&
            (tetris->tetri)[tetris->y + 1][tetris->x] != '.')
            cmt++;
        if (j + 1 < map->size && i + 1 < map->size && tetris->x + 1 <= 3 && tetris->y + 1 <= 3 &&
            (map->map)[j + 1][i + 1] == '.' && (tetris->tetri)[tetris->y + 1][tetris->x + 1] != '.')
            cmt++;
        if (j + 1 < map->size && i + 2 < map->size && tetris->x + 2 <= 3 && tetris->y + 1 <= 3 &&
            (map->map)[j + 1][i + 2] == '.' && (tetris->tetri)[tetris->y + 1][tetris->x + 2] != '.')
            cmt++;
        if (i - 1 >= 0 && j + 2 < map->size && tetris->x - 1 >= 0 && tetris->y + 2 <= 3 &&
            (map->map)[j + 2][i - 1] == '.' && (tetris->tetri)[tetris->y + 2][tetris->x - 1] != '.')
            cmt++;
        if (j + 2 < map->size && (map->map)[j + 2][i] && tetris->y + 2 <= 3 &&
            (map->map)[j + 2][i] == '.' && (tetris->tetri)[tetris->y + 2][tetris->x] != '.')
            cmt++;
        if (j + 2 < map->size && i + 1 < map->size && tetris->y + 2 <= 3 && tetris->x + 1 <= 3 &&
            (map->map)[j + 2][i + 1] == '.' && (tetris->tetri)[tetris->y + 2][tetris->x + 1] != '.')
            cmt++;
        if (j + 3 < map->size && (map->map)[j + 3][i] && tetris->y + 3 <= 3 &&
            (map->map)[j + 3][i] == '.' && (tetris->tetri)[tetris->y + 3][tetris->x] != '.')
            cmt++;
        //printf("fp2,  cmt = %d et i = %d, j = %d\n", cmt, i, j);
        if (cmt == 4)
        {
            coord->i = i;
            coord->j = j;
            return (coord);
        }
        if (i == map->size - 1 && j == map->size - 1)
        {
            coord->i = -1;
            return (coord);
        }
        if (i + 1 < map->size)
            i++;
        else if (j + 1 < map->size)
        {
            i = 0;
            j++;
        }
    }
    return (NULL);
}
*/

t_coord *ft_findplace(t_map *map, t_tetri *tetris, int i, int j) // OK
{
    t_coord     *coord;
    int         cmt;

    //printf("depart findplace\n");
    if (!(coord = (t_coord *)malloc(sizeof(t_coord *))))
        return (NULL);
    cmt = 0;
    if (map->map[j][i] == '.' && (tetris->tetri)[tetris->y][tetris->x] != '.')
        cmt++;
    if (i + 1 < map->size && tetris->x + 1 <= 3 && (map->map)[j][i + 1] == '.'
           && (tetris->tetri)[tetris->y][tetris->x + 1] != '.')
        cmt++;
    if (i + 2 < map->size && tetris->x + 2 <= 3 &&
        (map->map)[j][i + 2] == '.' && (tetris->tetri)[tetris->y][tetris->x + 2] != '.')
        cmt++;
    if (i + 3 < map->size && tetris->x + 3 <= 3 && (map->map)[j][i + 3] == '.' &&
        (tetris->tetri)[tetris->y][tetris->x + 3] != '.')
        cmt++;
    if (i - 2 >= 0 && j + 1 < map->size && tetris->x - 2 >= 0 && tetris->y + 1 <= 3 &&
        (map->map)[j + 1][i - 2] == '.' && (tetris->tetri)[tetris->y + 1][tetris->x - 2] != '.')
        cmt++;
    if (i - 1 >= 0 && j + 1 < map->size && tetris->x - 1 >= 0 && tetris->y + 1 <= 3 &&
        (map->map)[j + 1][i - 1] == '.' && (tetris->tetri)[tetris->y + 1][tetris->x - 1] != '.')
        cmt++;
    if (j + 1 < map->size && tetris->y + 1 <= 3 && (map->map)[j + 1][i] == '.' &&
        (tetris->tetri)[tetris->y + 1][tetris->x] != '.')
        cmt++;
    if (j + 1 < map->size && i + 1 < map->size && tetris->x + 1 <= 3 && tetris->y + 1 <= 3 &&
        (map->map)[j + 1][i + 1] == '.' && (tetris->tetri)[tetris->y + 1][tetris->x + 1] != '.')
        cmt++;
    if (j + 1 < map->size && i + 2 < map->size && tetris->x + 2 <= 3 && tetris->y + 1 <= 3 &&
        (map->map)[j + 1][i + 2] == '.' && (tetris->tetri)[tetris->y + 1][tetris->x + 2] != '.')
        cmt++;
    if (i - 1 >= 0 && j + 2 < map->size && tetris->x - 1 >= 0 && tetris->y + 2 <= 3 &&
        (map->map)[j + 2][i - 1] == '.' && (tetris->tetri)[tetris->y + 2][tetris->x - 1] != '.')
        cmt++;
    if (j + 2 < map->size && (map->map)[j + 2][i] && tetris->y + 2 <= 3 &&
        (map->map)[j + 2][i] == '.' && (tetris->tetri)[tetris->y + 2][tetris->x] != '.')
        cmt++;
    if (j + 2 < map->size && i + 1 < map->size && tetris->y + 2 <= 3 && tetris->x + 1 <= 3 &&
        (map->map)[j + 2][i + 1] == '.' && (tetris->tetri)[tetris->y + 2][tetris->x + 1] != '.')
        cmt++;
    if (j + 3 < map->size && (map->map)[j + 3][i] && tetris->y + 3 <= 3 &&
        (map->map)[j + 3][i] == '.' && (tetris->tetri)[tetris->y + 3][tetris->x] != '.')
        cmt++;
    //printf("fp2,  cmt = %d et i = %d, j = %d\n", cmt, i, j);
    if (cmt == 4)
    {
        coord->i = i;
        coord->j = j;
        return (coord);
    }
    coord->i = -1;
    return (coord);
}

int     ft_puttetri(t_tetri *tetris, t_map **map, char letter, int start) // OK
{
    t_coord *coord;

    while (tetris != NULL && tetris->letter != letter)
        tetris = tetris->next;
    coord = ft_findplace(*map, tetris, start % (*map)->size, start / (*map)->size);
    //printf ("coord->i = %d\n", coord->i);
    //printf ("coord->j = %d\n", coord->j);
    if (coord->i == -1|| tetris == NULL)
    {
        //printf ("puttetri return 0\n");
        return (0);
    }
    ((*map)->map)[coord->j][coord->i] = letter;
    if (tetris->x + 1 <= 3 && (tetris->tetri)[tetris->y][tetris->x + 1] != '.')
        ((*map)->map)[coord->j][coord->i + 1] = tetris->letter;
    if (tetris->x + 2 <= 3 && (tetris->tetri)[tetris->y][tetris->x + 2] != '.')
        ((*map)->map)[coord->j][coord->i + 2] = letter;
    if (tetris->x + 3 <= 3 && (tetris->tetri)[tetris->y][tetris->x + 3] != '.')
        ((*map)->map)[coord->j][coord->i + 3] = letter;
    if (tetris->x - 2 >= 0 && tetris->y + 1 <= 3 && (tetris->tetri)[tetris->y + 1][tetris->x - 2] != '.')
        ((*map)->map)[coord->j + 1][coord->i - 2] = letter;
    if (tetris->x - 1 >= 0 && tetris->y + 1 <= 3 && (tetris->tetri)[tetris->y + 1][tetris->x - 1] != '.')
        ((*map)->map)[coord->j + 1][coord->i - 1] = letter;
    if (tetris->y + 1 <= 3 && (tetris->tetri)[tetris->y + 1][tetris->x] != '.')
        ((*map)->map)[coord->j + 1][coord->i] = letter;
    if (tetris->x + 1 <= 3 && tetris->y + 1 <= 3 && (tetris->tetri)[tetris->y + 1][tetris->x + 1] != '.')
        ((*map)->map)[coord->j + 1][coord->i + 1] = letter;
    if (tetris->x + 2 <= 3 && tetris->y + 1 <= 3 && (tetris->tetri)[tetris->y + 1][tetris->x + 2] != '.')
        ((*map)->map)[coord->j + 1][coord->i + 2] = letter;
    if (tetris->x - 1 >= 0 && tetris->y + 2 <= 3 && (tetris->tetri)[tetris->y + 2][tetris->x - 1] != '.')
        ((*map)->map)[coord->j + 2][coord->i - 1] = letter;
    if (tetris->y + 2 <= 3 && (tetris->tetri)[tetris->y + 2][tetris->x] != '.')
        ((*map)->map)[coord->j + 2][coord->i] = letter;
    if (tetris->x + 1 <= 3 && tetris->y + 2 <= 3 && (tetris->tetri)[tetris->y + 2][tetris->x + 1] != '.')
        ((*map)->map)[coord->j + 2][coord->i + 1] = letter;
    if (tetris->y + 3 <= 3 && (tetris->tetri)[tetris->y + 3][tetris->x] != '.')
        ((*map)->map)[coord->j + 3][coord->i] = letter;
    free (coord);
    //printf ("puttetri return 1\n");
    return (1);
}

int     ft_solvemap(t_tetri *begin_tetris, t_map **map, int start)
{
    //printf ("START = %d\n", start);
    if (!(begin_tetris))
        return (1);
    if (ft_puttetri(begin_tetris, map, begin_tetris->letter, start))
    {
        if (ft_solvemap(begin_tetris->next, map, 0)) // si on place le tetri
            return (1);
        else
        {
            ft_cleantetri(map, begin_tetris->letter);
            //printf("Apres clean:\n");
            //ft_putmap(*map);
            if (ft_solvemap(begin_tetris, map, start + 1)) // si le tetri etait mal place
                return (1);
        }
    }
    if (start + 1 < (*map)->size * (*map)->size)
    {
        //printf ("start++;");
        if (ft_solvemap(begin_tetris, map, start + 1)) // si le tetri ne peut pas etre place
            return (1);
    }
    return (0);
}

t_map     *ft_resolve(t_tetri **begin_tetris, int nb_tetri)
{
    t_map   *map;
    int     size;

    size  = ft_intsqrt(nb_tetri * 4);
    if (size < 4)
        size = 4;
    //printf("%d\n", size);
    //printf("OK\n");
    if (!(ft_setmap(size, &map)))
        return (NULL);
    //ft_putmap(map);
    //printf("OK\n");
    while (!ft_solvemap(*begin_tetris, &map, 0))
    {
        size++;
        ft_freemap(&map);
        if (!(ft_setmap(size, &map)))
            return (NULL);
    }
    return (map);
}