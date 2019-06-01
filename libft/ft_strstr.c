/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 22:16:43 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 04:58:55 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int b;
	int temp;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = -1;
	while (haystack[++i])
	{
		if (haystack[i] == needle[0])
		{
			if (needle[1] == '\0')
				return ((char *)&haystack[i]);
			temp = i;
			b = 1;
			while (haystack[temp + 1] == needle[b])
			{
				if (needle[b + 1] == '\0')
					return ((char *)&haystack[i]);
				temp++;
				b++;
			}
		}
	}
	return (NULL);
}
