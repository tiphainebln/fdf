/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 05:15:05 by tbouline          #+#    #+#             */
/*   Updated: 2017/02/18 05:15:09 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord			points(int x, int y, int z, t_fdf *f)
{
	t_coord		p;

	x = x * f->spacing + START_X;
	y = y * f->spacing + START_Y;
	p.x = (y + f->xdec) + 0.75 / 2.0 * (-z * 8.0);
	p.y = (x + f->ydec) + 0.75 * -z;
	p.z = z;
	return (p);
}

void			parallel(t_fdf *f)
{
	int			i;
	int			j;

	i = -1;
	f->spacing = ((double)(WIN_X + WIN_Y) / 2.0) / \
				((double)(f->width + f->length) / 2.0) / 3.0;
	f->spacing *= f->zoom;
	while (++i < f->width)
	{
		j = f->length;
		while (--j >= 0)
		{
			f->p1 = points(i, j, f->map[j][i], f);
			if (i < f->width - 1)
			{
				f->p2 = points(i + 1, j, f->map[j][i + 1], f);
				line(f);
			}
			if (j < f->length - 1)
			{
				f->p2 = points(i, j + 1, f->map[j + 1][i], f);
				line(f);
			}
		}
	}
}
