/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:25:28 by dmetallo          #+#    #+#             */
/*   Updated: 2019/11/13 14:22:48 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_line(const int fd, char **line, char **s)
{
	size_t	i;
	char	*cur;

	i = 0;
	while (s[fd][i] && s[fd][i] != '\n')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		cur = ft_strdup(s[fd] + i + 1);
		free(s[fd]);
		s[fd] = cur;
	}
	else if (!s[fd][i])
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int			res;
	char		*cur;
	char		str[BUFF_SIZE + 1];
	static char	*s[12000];

	if (fd < 0 || !line)
		return (-1);
	while ((res = read(fd, &str, BUFF_SIZE)) > 0)
	{
		str[res] = '\0';
		if (!s[fd])
			s[fd] = ft_strnew(1);
		cur = ft_strjoin(s[fd], str);
		free(s[fd]);
		s[fd] = cur;
		if (ft_strchr(str, '\n'))
			break ;
	}
	if (res < 0)
		return (-1);
	else if (res == 0 && (!s[fd] || !s[fd][0]))
		return (0);
	return (get_line(fd, line, s));
}
