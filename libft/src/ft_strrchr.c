/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:56:12 by dmetallo          #+#    #+#             */
/*   Updated: 2019/09/10 12:00:46 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char *ptr;
	char *cur;

	cur = NULL;
	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == ch)
			cur = ptr;
		ptr++;
	}
	if (ch == '\0')
		return (ptr);
	return (cur);
}
