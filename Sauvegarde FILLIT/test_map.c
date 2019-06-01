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
#include <stdio.h>

int		ft_checkchar(char *buf, int nb)
{
	int		i;
	int		j;

	while (nb)
	{
		j = 1;
		while (j <= 4)
		{
			i = 1;
			while (i <= 4)
			{
				if (buf && *buf != '.' && *buf != '#')
				{
					printf ("i = %d, j = %d, *buf = %c, nb = %d\n", i, j, *buf, nb);
					return (1);
				}
				i++;
				buf++;
			}
			if (nb == 1 && buf == '\0')
				return (1);
			if (buf && *buf != '\n')
			{
				printf ("i = %d, j = %d, *buf = %c\n", i, j, *buf);
			 	return (1);
			}
			buf++;
			j++;
		}
		if (nb > 1 && *buf != '\n')
			return (1);
		buf++;
		nb--;
	}
	return (0);
}

int		ft_checktetri(char *buf, int nb)
{
	int		i;
	int		links;
	int		elem;
	int		cmp;

	cmp = 0;
	while (cmp != nb)
	{
		i = 0;
		links = 0;
		elem = 0;
		while (i < 19)
		{
			if (buf[21 * cmp + i] == '#')
			{
				if (i >= 1 && buf[21 * cmp + i - 1] == '#')
					links++;
				if (i >= 5 && buf[21 * cmp + i - 5] == '#')
					links++;
				if (i <= 13 && buf[21 * cmp + i + 5] == '#')
					links++;
				if (buf[21 * cmp + i + 1] == '#')
					links++;
				elem++;
			}
			i++;
		}
		if ((links != 6 && links != 8) || elem != 4)
			return (1);
		cmp++;
	}
	return (0);
}

int		ft_checkmap(char *buf, int nb)
{
	return (ft_checktetri(buf, nb) || ft_checkchar(buf, nb));
}

int		ft_readmap(int	ac, char **av, t_tetri **begin_list)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		ret;

	if (ac != 2)
	{
		write(1, "usage : ./fillit target_file\n", 29);
		return (-1);
	}
	fd = open (av[1], O_RDONLY);
	if ((ret = read (fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[ret] = '\0';
	if (read (fd, buf, 1) != 0 || ft_checkmap(buf, ret / 20) || (ret % 21) != 20) // attention ret / 20
	{
		close (fd);
		write(1, "error\n", 6);
		return (-1);
	}
	close (fd);
	if (ft_strtolist(buf, begin_list, ret / 20) == -1) //mettre ret / 21 
		return (-1);
	return (ret / 20); // mettre ret / 21
}

/*
int		ft_checksize_char(char **map)
{
	int		i;
	int		j;

	j = 0;
	while (map[j][0])
	{
		while (map[j][0] && map[j][0] != '\n')
		{
			i = 0;
			while (map[j][i] && (map[j][i] == '.' || map[j][i] == '#'))
				i++;
			if (i != 4 || map[j][i] != '\n' || map[j][i + 1] != '\0')
				return (0);
			j++;
		}
		if (map[j][0] == '\0')
			return (1);
		else if (map[j][0] != '\n' || map[j][1] != '\0')
			return (0);
		j++;
	}
	return (1);
}
*/