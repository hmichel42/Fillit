/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Test_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 17:28:23 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 17:55:43 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkchar(char *buf, int nb)
{
	int		i;
	int		j;

	while (nb)
	{
		j = 0;
		while (++j <= 4)
		{
			i = 0;
			while (++i <= 4)
			{
				if (buf && *buf != '.' && *buf != '#')
					return (1);
				buf++;
			}
			if (buf && ((nb == 1 && *buf == '\0') || (*buf != '\n')))
				return (1);
			buf++;
		}
		if (nb > 1 && *buf != '\n')
			return (1);
		buf++;
		nb--;
	}
	return (0);
}

int		ft_checktetri(char *buf, int nb, int cmp, int links)
{
	int		i;
	int		elem;

	while (++cmp != nb && !(elem = 0))
	{
		links = 0;
		i = -1;
		while (++i < 19)
		{
			if (buf[21 * cmp + i] == '#' && ++elem)
			{
				if (i >= 1 && buf[21 * cmp + i - 1] == '#')
					links++;
				if (i >= 5 && buf[21 * cmp + i - 5] == '#')
					links++;
				if (i <= 13 && buf[21 * cmp + i + 5] == '#')
					links++;
				if (buf[21 * cmp + i + 1] == '#')
					links++;
			}
		}
		if ((links != 6 && links != 8) || elem != 4)
			return (1);
	}
	return (0);
}

int		ft_checkmap(char *buf, int nb)
{
	return (ft_checktetri(buf, nb, -1, 0) || ft_checkchar(buf, nb));
}

int		ft_readmap(int ac, char **av, t_tetri **begin_list)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		ret;

	if (ac != 2)
	{
		write(1, "usage : ./fillit target_file\n", 29);
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[ret] = '\0';
	if (read(fd, buf, 1) != 0 || ft_checkmap(buf, (ret + 1) / 21) ||
		(ret % 21) != 20)
	{
		close(fd);
		write(1, "error\n", 6);
		return (-1);
	}
	close(fd);
	if (ft_strtolist(buf, begin_list, (ret + 1) / 21) == -1)
		return (-1);
	return ((ret + 1) / 21);
}
