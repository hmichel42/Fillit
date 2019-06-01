/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 00:58:10 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 05:30:30 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*cdest;
	char		*csrc;

	cdest = (char *)dest;
	csrc = (char *)src;
	i = -1;
	if (csrc < cdest)
	{
		while ((int)(--n) >= 0)
		{
			*(cdest + n) = *(csrc + n);
		}
	}
	else
	{
		while (++i < n)
		{
			*(cdest + i) = *(csrc + i);
		}
	}
	return (dest);
}
