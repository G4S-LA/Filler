/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:16:02 by dmetallo          #+#    #+#             */
/*   Updated: 2019/09/19 11:30:57 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t			i;
	unsigned char	*mas1;
	unsigned char	*mas2;

	mas1 = (unsigned char *)arr1;
	mas2 = (unsigned char *)arr2;
	i = 0;
	while (n--)
	{
		if (mas1[i] != mas2[i])
			return ((unsigned char)mas1[i] - (unsigned char)mas2[i]);
		i++;
	}
	return (0);
}
