/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:07:02 by dmetallo          #+#    #+#             */
/*   Updated: 2019/09/10 09:19:03 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *app, size_t n)
{
	int		i;
	size_t	j;

	i = 0;
	j = -1;
	while (dst[i])
		i++;
	while (app[++j] && j < n)
	{
		dst[i] = app[j];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
