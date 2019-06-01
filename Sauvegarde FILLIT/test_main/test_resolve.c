#include "../src/fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
    t_tetri *begin_list;
    t_map   *map;
    int     nb;

    map = NULL;
    nb = ft_readmap(ac, av, &begin_list);
    //printf("return %d\n", nb);
    map = ft_resolve(&begin_list, nb);
    //ft_putmap(map);
    //printf ("size = %d\n", map->size);
    return (0);
}