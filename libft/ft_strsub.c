/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:37:55 by dmetallo          #+#    #+#             */
/*   Updated: 2019/09/15 14:17:28 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	substr = NULL;
	if (s)
	{
		if (len + 1 < len)
			return (NULL);
		if (!(substr = (char *)ft_memalloc(sizeof(char) * len + 1)))
			return (NULL);
		while (i < len)
		{
			substr[i] = s[i + start];
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}
