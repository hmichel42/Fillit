/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/14 18:22:21 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/14 23:23:00 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_len(long n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n >= 10 || n <= -10)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*tab;
	int		len;
	int		i;
	long	nbr;

	nbr = (long)n;
	len = ft_len(nbr);
	if (!(tab = ft_strnew(len)))
		return (NULL);
	i = 0;
	nbr = ABS(nbr);
	while (len--)
	{
		tab[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (n < 0)
		tab[0] = '-';
	return (tab);
}
