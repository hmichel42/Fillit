/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 01:53:43 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 15:09:29 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char		*tab;

	if (!(tab = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(tab, size + 1);
	return (tab);
}
