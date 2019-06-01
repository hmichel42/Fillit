/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/14 17:35:04 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/14 18:20:08 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_nbchar(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len++;
			while (*s && *s != c)
				s++;
		}
	}
	return (len);
}

static int		ft_wordlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_nbchar(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	while (len--)
	{
		while (*s == c && *s)
			s++;
		if (!(tab[i] = ft_strsub(s, 0, ft_wordlen(s, c))))
			return (NULL);
		s = s + ft_wordlen(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
