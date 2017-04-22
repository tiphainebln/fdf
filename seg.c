/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 06:26:35 by tbouline          #+#    #+#             */
/*   Updated: 2017/01/28 06:26:40 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_line(t_fdf *f, int option)
{
	int		start;

	start = 0;
	if (option == 0 && (start = f->p1.x - 1))
		while (++start <= f->p2.x)
			mlx_pixel_put(f->mlx, f->win, start, f->p1.y + ((f->p2.y - \
				f->p1.y) * (start - f->p1.x)) / (f->p2.x - f->p1.x), f->color);
	if (option == 1 && (start = f->p2.x - 1))
		while (++start <= f->p1.x)
			mlx_pixel_put(f->mlx, f->win, start, f->p2.y + ((f->p1.y - \
				f->p2.y) * (start - f->p2.x)) / (f->p1.x - f->p2.x), f->color);
	if (option == 2 && (start = f->p2.y - 1))
		while (++start <= f->p1.y)
			mlx_pixel_put(f->mlx, f->win, f->p2.x + ((f->p1.x - f->p2.x) * \
				(start - f->p2.y)) / (f->p1.y - f->p2.y), start, f->color);
	if (option == 3 && (start = f->p1.y - 1))
		while (++start <= f->p2.y)
			mlx_pixel_put(f->mlx, f->win, f->p1.x + ((f->p2.x - f->p1.x) * \
				(start - f->p1.y)) / (f->p2.y - f->p1.y), start, f->color);
}

void		line(t_fdf *f)
{
	if (fabs(f->p2.x - f->p1.x) > fabs(f->p2.y - f->p1.y))
		f->angle = (f->p2.z - f->p1.z) / (f->p2.x - f->p1.x);
	else
		f->angle = (f->p2.z - f->p1.z) / (f->p2.y - f->p1.y);
	if (f->p1.x <= f->p2.x && (f->p2.x - f->p1.x) >= fabs(f->p2.y - \
		f->p1.y))
		draw_line(f, 0);
	else if (f->p2.x <= f->p1.x && (f->p1.x - f->p2.x) >= fabs(f->p1.y - \
		f->p2.y))
		draw_line(f, 1);
	else if (f->p2.y <= f->p1.y && (f->p1.y - f->p2.y) >= fabs(f->p1.x - \
		f->p2.x))
		draw_line(f, 2);
	else if (f->p1.y <= f->p2.y && (f->p2.y - f->p1.y) >= fabs(f->p2.x - \
		f->p1.x))
		draw_line(f, 3);
}
