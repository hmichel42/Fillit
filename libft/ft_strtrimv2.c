/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrimv2.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 05:25:52 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 05:27:30 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_onlyblank(const char *s)
{
	int	res;

	while (*s)
	{
		if (*s != ' ' && *s != '\t' && *s != '\n')
			return (0);
		s++;
	}
	return (1);
}

static int	ft_start(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static int	ft_end(char const *s)
{
	size_t	i;

	if (ft_strlen(s) == 0)
		return (0);
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	return (i);
}

char		*ft_strtrimv2(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*copy;

	if (s == NULL)
		return (NULL);
	start = ft_start(s);
	end = ft_end(s);
	if (ft_onlyblank(s))
	{
		copy = ft_strnew(1);
		return (copy);
	}
	copy = ft_strnew(end - start + 1);
	if (!(copy))
		return (NULL);
	i = 0;
	while (start <= end)
		copy[i++] = s[start++];
	copy[i] = '\0';
	return (copy);
}
