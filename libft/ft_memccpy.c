/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:57:10 by dmetallo          #+#    #+#             */
/*   Updated: 2019/09/19 11:28:02 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t cnt)
{
	while (cnt--)
	{
		*((unsigned char *)dest++) = *((unsigned char *)src++);
		if (*(unsigned char *)(dest - 1) == (unsigned char)c)
			return (dest);
	}
	return (NULL);
}
