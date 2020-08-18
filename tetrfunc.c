/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:54:20 by dmetallo          #+#    #+#             */
/*   Updated: 2019/11/01 17:42:53 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void	tetr_add(t_tetr **root, int m[4][2], char c)
{
	t_tetr *cur;
	t_tetr *new;

	if (!root || !(new = tetr_new(m, c)))
		return ;
	if (!(*root))
		*root = new;
	else
	{
		cur = *root;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
}

t_tetr	*tetr_new(int m[4][2], char c)
{
	t_tetr	*tetromin;
	int		i;

	if (!(tetromin = (t_tetr *)ft_memalloc(sizeof(t_tetr))))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		tetromin->fig[i][0] = m[i][0];
		tetromin->fig[i][1] = m[i][1];
		i++;
	}
	tetromin->letter = c;
	tetromin->next = NULL;
	return (tetromin);
}

void	tetr_clear(t_tetr **root)
{
	if (root && *root)
	{
		tetr_clear(&(*root)->next);
		free(*root);
		*root = NULL;
	}
}

void	tetr_show(t_tetr *root, int i, int j)
{
	int k;

	if (root)
		while (root)
		{
			i = -1;
			k = 0;
			while (++i < 4)
			{
				j = -1;
				while (++j < 4)
				{
					if (root->fig[k][0] == j && root->fig[k][1] == i)
					{
						ft_putchar(root->letter);
						k++;
					}
					else
						ft_putchar('.');
				}
				ft_putchar('\n');
			}
			ft_putstr("----------------\n");
			root = root->next;
		}
}

void	start_position(t_tetr **root)
{
	int		i;
	int		min_x;
	int		min_y;
	t_tetr	*tmp;

	tmp = *root;
	if (root && *root)
		while (tmp)
		{
			min_x = tmp->fig[0][0];
			min_y = tmp->fig[0][1];
			i = -1;
			while (++i < 4)
			{
				min_x = (tmp->fig[i][0] < min_x) ? tmp->fig[i][0] : min_x;
				min_y = (tmp->fig[i][1] < min_y) ? tmp->fig[i][1] : min_y;
			}
			i = -1;
			while (++i < 4)
			{
				tmp->fig[i][0] -= min_x;
				tmp->fig[i][1] -= min_y;
			}
			tmp = tmp->next;
		}
}
