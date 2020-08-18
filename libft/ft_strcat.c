/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:57:57 by dmetallo          #+#    #+#             */
/*   Updated: 2019/09/09 18:03:57 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *app)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (dst[i])
		i++;
	while (app[++j])
	{
		dst[i] = app[j];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
