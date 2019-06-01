/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 16:49:40 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 16:53:24 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t i;
	size_t j;
	size_t cmp;

	cmp = 0;
	j = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[j] && cmp < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
		cmp++;
	}
	if (dest[i] != '\0')
		dest[i] = '\0';
	return (dest);
}
