/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:17:25 by dmetallo          #+#    #+#             */
/*   Updated: 2019/09/15 13:52:37 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*mas1;
	unsigned char	*mas2;

	mas1 = (unsigned char *)str1;
	mas2 = (unsigned char *)str2;
	i = 0;
	while ((mas1[i] || mas2[i]) && n--)
	{
		if (mas1[i] != mas2[i])
			return (mas1[i] - mas2[i]);
		i++;
	}
	return (0);
}
