/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 06:50:59 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 06:51:48 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrev(char *str)
{
	int		c;
	int		compteur;
	char	*temp;
	char	swap;

	if (str == NULL)
		return (NULL);
	temp = str;
	c = ft_strlen(temp);
	temp = str;
	c = c - 1;
	compteur = 0;
	while (c > compteur)
	{
		swap = str[compteur];
		str[compteur] = str[c];
		str[c] = swap;
		c--;
		compteur++;
	}
	return (str);
}
