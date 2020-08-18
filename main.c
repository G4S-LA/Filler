/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:15:07 by dmetallo          #+#    #+#             */
/*   Updated: 2019/11/13 14:28:57 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void	mapprint(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putstr("\n");
		i++;
	}
	ft_freememmass(map);
}

void	fakemain(t_tetr *tetric)
{
	char	**map;
	size_t	plus;

	plus = 0;
	start_position(&tetric);
	map = newmap(tetric, plus);
	while (checkmap(map, tetric) == NULL)
	{
		ft_freememmass(map);
		map = newmap(tetric, ++plus);
	}
	mapprint(map);
	tetr_clear(&tetric);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_tetr	*tetric;

	if (argc != 2)
	{
		ft_putstr("usage: use 1 txt file");
		return (0);
	}
	tetric = NULL;
	fd = open(argv[1], O_RDONLY);
	if (!validation(fd, &tetric, argv[1]))
	{
		ft_putstr("error\n");
		tetr_clear(&tetric);
		close(fd);
		return (0);
	}
	fakemain(tetric);
	close(fd);
	return (0);
}
