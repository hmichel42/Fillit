/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 00:44:03 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 23:14:35 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t i;
	size_t j;

	if (n == 0)
		return (0);
	j = 1;
	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && j < n)
	{
		i++;
		j++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
