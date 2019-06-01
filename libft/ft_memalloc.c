/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 01:38:48 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 23:34:55 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tab;
	int		i;

	i = 0;
	if (!(tab = malloc(size)))
		return (NULL);
	ft_bzero(tab, size);
	return (tab);
}
