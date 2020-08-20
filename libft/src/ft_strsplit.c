/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 09:24:11 by dmetallo          #+#    #+#             */
/*   Updated: 2019/09/19 17:32:10 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(const char s, char c)
{
	return (s == c || s == '\0') ? 1 : 0;
}

static int	n1(const char *s, char c)
{
	int		ans;
	size_t	i;

	i = -1;
	ans = 0;
	while (s[++i])
	{
		if (is_space(s[i], c))
			continue;
		while (!(is_space(s[i], c)))
			i++;
		ans++;
		i--;
	}
	return (ans);
}

static int	n2(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] && !is_space(s[i], c))
		i++;
	return (i);
}

static char	**free_words(char **words, size_t i)
{
	while (i--)
		ft_strdel((&words[i]));
	free(*words);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	i = -1;
	j = 0;
	if (!s || !(str = (char**)ft_memalloc(sizeof(char*) * n1(s, c) + 1)))
		return (NULL);
	while (s[++i])
	{
		if (is_space(s[i], c))
			continue ;
		k = 0;
		if (!(str[j] = (char*)ft_memalloc(sizeof(char) * n2(&s[i], c) + 1)))
			return (free_words(str, i));
		while (!is_space(s[i], c))
			str[j][k++] = s[i++];
		str[j++][k] = '\0';
		i--;
	}
	str[j] = NULL;
	return (str);
}
