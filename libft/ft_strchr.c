/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:38:51 by dmetallo          #+#    #+#             */
/*   Updated: 2019/09/10 11:53:23 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char *ptr;

	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == ch)
			return (ptr);
		ptr++;
	}
	if (ch == '\0')
		return (ptr);
	return (NULL);
}
