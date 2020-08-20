/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 09:23:53 by dmetallo          #+#    #+#             */
/*   Updated: 2019/09/16 14:11:43 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		flag;
	int		numb;

	flag = (n < 0) ? 1 : 0;
	numb = len(n) + flag;
	if (!(str = (char *)ft_memalloc(sizeof(char) * (numb + 1))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (flag)
	{
		str[0] = '-';
		n *= -1;
	}
	str[numb--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[numb--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
