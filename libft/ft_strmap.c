/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 03:15:53 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 04:45:14 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	len;
	char	*tab;

	if (s == 0)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	tab = (char *)ft_strnew(len);
	if (tab == NULL)
		return (NULL);
	while (i < len)
	{
		tab[i] = f(s[i]);
		i++;
	}
	return (tab);
}
