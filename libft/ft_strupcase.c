/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strupcase.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 06:00:12 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 06:00:33 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strupcase(char *str)
{
	char *init;

	init = str;
	while (*str)
	{
		if (*str <= 122 && *str >= 97)
			*str = *str - 32;
		str++;
	}
	str = init;
	return (str);
}
