/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:37:46 by dmetallo          #+#    #+#             */
/*   Updated: 2019/09/19 17:40:12 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if ((list = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		if (!(content))
		{
			list->content = NULL;
			list->content_size = 0;
		}
		else
		{
			if (!(list->content = ft_memalloc(content_size)))
			{
				free(list);
				return (NULL);
			}
			list->content = ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
		}
		list->next = NULL;
	}
	return (list);
}
