/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:02:59 by dmetallo          #+#    #+#             */
/*   Updated: 2019/09/15 13:51:38 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	size_t	len_str2;
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ptr = (char *)str1;
	len_str2 = ft_strlen(str2);
	if (!len_str2)
		return (ptr);
	while (ptr[i])
	{
		j = 0;
		while (str2[j] && str2[j] == ptr[i + j])
			j++;
		if (j == len_str2)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
