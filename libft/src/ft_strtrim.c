/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 09:24:21 by dmetallo          #+#    #+#             */
/*   Updated: 2019/09/15 14:34:04 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(const char s)
{
	return (s == ' ' || s == '\t' || s == '\n') ? 1 : 0;
}

static int	is_end(const char *s)
{
	int i;

	i = 0;
	while (s[i] && is_space(s[i]))
		i++;
	return (!s[i]) ? 1 : 0;
}

static int	num_mem(const char *s)
{
	int i;
	int ans;

	ans = 0;
	i = 0;
	while (s[i] && is_space(s[i]))
		i++;
	i--;
	while (!(is_end(&s[++i])))
		ans++;
	return (ans);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	if (s)
	{
		if (!(str = (char *)ft_memalloc(num_mem(s) + 1)))
			return (NULL);
		while (s[i] && is_space(s[i]))
			i++;
		while (!(is_end(&s[i])))
			str[j++] = s[i++];
	}
	return (str);
}
