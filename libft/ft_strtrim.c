/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 17:26:20 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 05:29:41 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*c;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		len--;
	if (len < 0)
		len = -1;
	if (!(c = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	if (!c)
		return (NULL);
	s = s + i;
	i = -1;
	while (++i < len)
		c[i] = *s++;
	c[i] = 0;
	return (c);
}
