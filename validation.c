/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:06:53 by dmetallo          #+#    #+#             */
/*   Updated: 2019/11/19 10:11:04 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int			g_m[4][2];
int			g_all;

int			links(void)
{
	int link;
	int i;
	int j;

	link = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (i != j)
			{
				if (g_m[i][0] == g_m[j][0] && g_m[i][1] + 1 == g_m[j][1])
					link++;
				if (g_m[i][1] == g_m[j][1] && g_m[i][0] + 1 == g_m[j][0])
					link++;
				if (g_m[i][0] == g_m[j][0] && g_m[i][1] - 1 == g_m[j][1])
					link++;
				if (g_m[i][1] == g_m[j][1] && g_m[i][0] - 1 == g_m[j][0])
					link++;
			}
	}
	if (link == 6 || link == 8)
		return (1);
	return (0);
}

int			size_and_hash(char *str, int *hesh, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (str)
		while (str[i] == '#' || str[i] == '.')
		{
			if (str[i] == '#')
			{
				g_m[*hesh][0] = i;
				g_m[(*hesh)++][1] = y;
			}
			if (i > 3 || (*hesh) > 4)
				return (0);
			i++;
		}
	return ((i < 4) ? 0 : 1);
}

static int	glob(char *txt)
{
	char	line[21];
	int		fd;

	fd = open(txt, O_RDONLY);
	while (read(fd, line, 21) > 0)
	{
		if (line[19] != '\n')
		{
			close(fd);
			return (0);
		}
		line[19] = '\0';
	}
	close(fd);
	return (1);
}

static int	cycle(t_tetr **root, char *line, int *heshteg, int *y)
{
	if (line[0])
	{
		if (!size_and_hash(line, heshteg, *y) || (*y)++ > 3)
			return (0);
	}
	else
	{
		if (!links() || *y != 4)
			return (0);
		tetr_add(root, g_m, 'A' + g_all++);
		*heshteg = 0;
		*y = 0;
	}
	return (1);
}

int			validation(int fd, t_tetr **root, char *txt)
{
	int		heshteg;
	char	*line;
	int		y;

	g_all = 0;
	heshteg = 0;
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!cycle(root, line, &heshteg, &y))
		{
			free(line);
			break ;
		}
		free(line);
	}
	if (y != 4 || !glob(txt) || !links() || heshteg != 4 || g_all > 25)
		return (0);
	tetr_add(root, g_m, 'A' + g_all);
	return (1);
}
