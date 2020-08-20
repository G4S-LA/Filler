/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freememmass.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:56:39 by poatmeal          #+#    #+#             */
/*   Updated: 2019/11/01 15:30:45 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_freememmass(char **memmass)
{
	int		i;

	i = 0;
	while (memmass[i])
	{
		free(memmass[i]);
		i++;
	}
	free(memmass);
	memmass = NULL;
}
