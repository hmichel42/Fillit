/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnequ.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 04:04:19 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 05:44:23 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL && s2 == NULL && n == 0)
		return (0);
	if (n == 1)
		return (ft_strequ(s1, s2));
	if (ft_strncmp((char *)s1, (char *)s2, n) == 0)
		return (1);
	return (0);
}
