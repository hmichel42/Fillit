/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_list.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/27 10:43:34 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 10:43:36 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../src/fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
    t_tetri *begin_list;
    int     nb;
    int     i;

    nb = ft_readmap(ac, av, &begin_list);
    printf("return %d\n", nb);
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
    return (0);
}