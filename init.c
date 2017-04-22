/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 23:55:13 by tbouline          #+#    #+#             */
/*   Updated: 2017/01/16 07:21:51 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init(t_fdf *f)
{
	if (f == NULL)
	{
		f = (t_fdf *)malloc(sizeof(t_fdf));
		f->mlx = NULL;
		f->win = NULL;
		f->width = 0;
		f->length = 0;
		f->xdec = 0;
		f->ydec = 0;
		f->map = NULL;
		f->color = 0xFFFFFF;
		f->r = 255;
		f->g = 255;
		f->b = 255;
		f->zoom = 1.0;
		f->colormode = 0;
		f->colormod[0] = -1;
		f->colormod[1] = -1;
		f->colormod[2] = -1;
	}
	return (f);
}
