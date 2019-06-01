/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlowcase.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 05:58:01 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 06:00:53 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strlowcase(char *str)
{
	char *init;

	init = str;
	while (*str)
	{
		if (*str <= 90 && *str >= 65)
			*str = *str + 32;
		str++;
	}
	str = init;
	return (str);
}
