#include "../src/fillit.h"
#include <stdio.h>

//gcc -g -fsanitize=address src/resolve2.c src/test_map.c src/util.c test_main/test_functions.c libft/libft.a

/*
//PUT_TETTRI

int		main(int ac, char **av)
{
    t_tetri *begin_list;
    t_map   *map;
    int     nb;
    int     i;

    map = NULL;
    nb = ft_readmap(ac, av, &begin_list);
    while (begin_list != NULL)
    {
        i = 0;
        while (i < 4)
        {
            printf("%s\n", begin_list->tetri[i]);
            i++;
        }
        printf("\n");
        printf("letter = %c, x = %d, y = %d\n", begin_list->letter, begin_list->x, begin_list->y);
        begin_list = begin_list->next;
    }
    printf("return %d\n", nb); 
    if (!ft_setmap(4, &map))
        return (1);
    printf("OK\n");
    nb = ft_puttetri(begin_list, &map, 'A', 0);
    ft_putmap(map);
    return (0);
}


//CLEANTETRI

int		main(int ac, char **av)
{
    t_tetri *begin_list;
    t_map   *map;
    int     nb;
    int     i;

    map = NULL;
    nb = ft_readmap(ac, av, &begin_list);
    if (!ft_setmap(4, &map))
        return (1);
    ft_putmap(map);
    i = 0;
    while (i < 16)
    {
        if (i % 2 == 0)
            map->map[i / 4][i % 4] = 'B';
        else
            map->map[i / 4][i % 4] = 'F';
        i++;
    }
    //nb = ft_puttetri(begin_list, &map, 'A', 0);
    //printf ("return ft_puttetri = %d\n", nb);
    ft_putmap(map);
    ft_cleantetri(&map, 'F');
    ft_putmap(map);
    return (0);
}


// SETMAP

int		main(int ac, char **av)
{
    t_tetri *begin_list;
    t_map   *map;
    int     nb;

    map = NULL;
    nb = ft_readmap(ac, av, &begin_list);
    //printf("return %d\n", nb); 
    if (!ft_setmap(4, &map))
        return (1);
    printf ("l1 = |%s|\n", map->map[0]);
    printf ("l2 = |%s|\n", map->map[1]);
    printf ("l3 = |%s|\n", map->map[2]);
    printf ("l4 = |%s|\n", map->map[3]);
    //printf("OK\n");
    //ft_putmap(map);
    return (0);
}


// SOLVEMAP

int		main(int ac, char **av)
{
    t_tetri *begin_list;
    t_map   *map;
    int     nb;

    map = NULL;
    nb = ft_readmap(ac, av, &begin_list);
    if (!ft_setmap(6, &map))
        return (1);
    //ft_putmap(map);
    nb = ft_solvemap(begin_list, &map, 0);
    printf ("\n\n");
    ft_putmap(map);
    printf("\nreturn backtrack = %d\n", nb);
    return (0);
}
*/
// RESOLVE

int		main(int ac, char **av)
{
    t_tetri *begin_list;
    t_map   *map;
    int     nb;

    map = NULL;
    nb = ft_readmap(ac, av, &begin_list);
    //if (!ft_setmap(6, &map))
    //    return (1);
    //ft_putmap(map);
    //nb = ft_solvemap(begin_list, &map, 0);
    map = ft_resolve(&begin_list, nb);
    //ft_putmap(map);
    printf("\nreturn backtrack = %d\n", nb);
    return (0);
}