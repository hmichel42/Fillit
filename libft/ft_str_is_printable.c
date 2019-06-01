/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_printable.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/07 18:13:39 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 05:53:30 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_str_is_printable(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] && str[i] >= 32 && str[i] < 127)
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}
