/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:28:54 by poatmeal          #+#    #+#             */
/*   Updated: 2019/11/13 14:29:56 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

char	**newmap(t_tetr *start, size_t plus)
{
	size_t	i;
	size_t	quad;
	char	**map;

	i = 0;
	while (start)
	{
		start = start->next;
		i++;
	}
	i = i * 4;
	quad = ft_sqrt(i) + plus;
	map = (char **)ft_memalloc(sizeof(char *) * quad + 1);
	i = 0;
	while (i < quad)
	{
		map[i] = (char *)ft_memalloc(sizeof(char) * quad + 1);
		ft_memset(map[i], 46, quad);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**clean(char **map, char let)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == let)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int		put_letter(char **map, t_tetr *s, size_t i, size_t j)
{
	size_t	t;
	size_t	max;
	size_t	l;
	size_t	m;

	t = 0;
	l = s->fig[t][1] + i;
	m = s->fig[t][0] + j;
	max = ft_strlen(*map);
	while (t < 4 && l < max && m < max)
		if (map[l][m] == '.')
		{
			map[l][m] = s->letter;
			if (++t < 4)
			{
				l = s->fig[t][1] + i;
				m = s->fig[t][0] + j;
			}
		}
		else
			break ;
	if (t == 4)
		return (1);
	(t > 0) ? map = clean(map, s->letter) : 0;
	return (0);
}

char	**checkmap(char **map, t_tetr *s)
{
	size_t	i;
	size_t	j;
	size_t	max;

	i = 0;
	max = ft_strlen(*map);
	if (!s)
		return (map);
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			if (put_letter(map, s, i, j) == 1)
			{
				if ((checkmap(map, s->next)))
					return (map);
				map = clean(map, s->letter);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
