/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 21:45:57 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 14:12:20 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_char;

	s_char = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s_char[i] = (unsigned char)c;
		i++;
	}
	return (s_char);
}
