/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:20:04 by dmetallo          #+#    #+#             */
/*   Updated: 2019/09/19 18:36:49 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numwords(const char *s)
{
	int		ans;
	size_t	i;

	i = -1;
	ans = 0;
	while (s[++i])
	{
		if (ft_isspace(s[i]))
			continue ;
		while (!(ft_isspace(s[i])))
			i++;
		ans++;
		i--;
	}
	return (ans);
}
