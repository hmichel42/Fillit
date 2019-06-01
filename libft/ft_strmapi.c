/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 03:41:32 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 04:42:05 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		tab[i] = f((unsigned int)i, s[i]);
		i++;
	}
	return (tab);
}
