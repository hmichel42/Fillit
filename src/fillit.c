/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 17:23:59 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 18:08:44 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tetri		*begin_list;
	t_map		*map;
	int			nb;

	begin_list = NULL;
	nb = ft_readmap(ac, av, &begin_list);
	if (nb == -1)
	{
		if (begin_list)
			ft_freetetri(&begin_list);
		return (1);
	}
	map = ft_resolve(&begin_list, nb);
	ft_putmap(map);
	ft_freemap(&map);
	ft_freetetri(&begin_list);
	return (0);
}
