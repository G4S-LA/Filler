/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:48:34 by dmetallo          #+#    #+#             */
/*   Updated: 2019/11/13 14:27:47 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H
# include "libft/libft.h"

typedef struct			s_tetr
{
	int					fig[4][2];
	char				letter;
	struct s_tetr		*next;
}						t_tetr;

t_tetr					*tetr_new(int g_m[4][2], char c);
void					tetr_add(t_tetr **root, int g_m[4][2], char c);
void					figures_init(int fd, char**line, t_tetr **root);
int						validation(int fd, t_tetr **root, char *txt);
int						size_and_hash(char *str, int *hesh, int y);
void					tetr_clear(t_tetr **root);
void					tetr_show(t_tetr *root, int i, int j);
void					start_position(t_tetr **root);
char					**newmap(t_tetr *start, size_t plus);
char					**clean(char **map, char let);
int						put_letter(char **map, t_tetr *s, size_t i, size_t j);
char					**checkmap(char **map, t_tetr *s);
void					mapprint(char **map);

#endif
