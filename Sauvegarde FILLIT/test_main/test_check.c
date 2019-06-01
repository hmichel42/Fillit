/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_check.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 17:35:51 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 17:48:15 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../src/fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	//char	buf[2001];
	//int		ret;

	//ret = read(open(av[1], O_RDONLY), buf, 2000);
	//buf[ret + 1] = '\0';
	//printf("%s\n", buf);
	printf("return %d\n", ft_readmap(ac, av));
	return (0);
}
