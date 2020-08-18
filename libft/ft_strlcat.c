/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:29:57 by dmetallo          #+#    #+#             */
/*   Updated: 2019/09/10 11:35:47 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *app, size_t n)
{
	size_t len_d;
	size_t len;

	len_d = ft_strlen(dst);
	len = ((len_d < n) ? len_d : n) + ft_strlen(app);
	if (len_d < n)
	{
		dst += len_d;
		n -= len_d;
		while (*app && n-- > 1)
			*dst++ = *app++;
		*dst = '\0';
	}
	return (len);
}
