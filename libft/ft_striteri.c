/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_striteri.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 03:08:59 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 05:34:34 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;
	int		len;

	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		i = -1;
		while (++i < len)
			f((unsigned int)i, &s[i]);
	}
}
