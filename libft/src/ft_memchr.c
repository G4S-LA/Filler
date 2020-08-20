/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:37:02 by dmetallo          #+#    #+#             */
/*   Updated: 2019/09/19 15:39:30 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	while (n--)
	{
		if ((*(unsigned char *)arr++) == (unsigned char)c)
			return ((void *)arr - 1);
	}
	return (NULL);
}
