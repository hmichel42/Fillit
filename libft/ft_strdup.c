/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 16:53:21 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 00:07:19 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;

	if (!(copy = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	copy = ft_strcpy(copy, src);
	return (copy);
}
