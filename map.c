/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 03:26:51 by tbouline          #+#    #+#             */
/*   Updated: 2017/03/01 03:27:29 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			**malloc_array(int x, int y)
{
	int		i;
	int		**array;

	i = -1;
	array = (int **)malloc(sizeof(int *) * x);
	while (++i < x)
		array[i] = (int *)malloc(sizeof(int) * y);
	return (array);
}

t_fdf		*reverse(t_fdf *f)
{
	int		i;
	int		j;
	int		**newtab;

	newtab = malloc_array(f->width, f->length);
	i = -1;
	while (++i < f->length)
	{
		j = -1;
		while (++j < f->width)
			newtab[j][f->length - (i + 1)] = f->map[i][j];
	}
	i = f->width;
	f->width = f->length;
	f->length = i;
	free(f->map);
	f->map = newtab;
	return (f);
}

t_fdf		*inverse(t_fdf *f)
{
	int		i;
	int		k;
	int		j;
	int		**tab;

	i = 0;
	k = f->width - 1;
	j = 0;
	tab = malloc_array(f->length, f->width);
	while (i < f->length)
	{
		j = 0;
		k = f->width - 1;
		while (j < f->width)
			tab[i][j++] = f->map[i][k--];
		i++;
	}
	free(f->map);
	f->map = tab;
	return (f);
}
