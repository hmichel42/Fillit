/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 00:51:48 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 20:21:49 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	size_t	neg;
	size_t	nb;

	neg = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-' && str[i - 1] != '+')
	{
		neg = -1;
		i++;
	}
	while (48 <= str[i] && str[i] <= 57)
	{
		nb = nb * 10;
		nb = nb + str[i] - '0';
		i++;
	}
	return (nb * neg);
}
