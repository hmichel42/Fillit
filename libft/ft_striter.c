/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_striter.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 02:55:27 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 05:35:09 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int		i;
	int		len;

	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		i = -1;
		while (++i < len)
			f(&s[i]);
	}
}
