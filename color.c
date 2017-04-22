/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 22:41:56 by tbouline          #+#    #+#             */
/*   Updated: 2017/04/13 22:41:57 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*createRGB(int r, int g, int b, t_fdf *f)
{
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		return (f);
	if (f->which == 1)
		f->r = r;
	if (f->which == 2)
		f->g = g;
	if (f->which == 3)
		f->b = b;
	f->color = ((r & 255) * 65536) + ((g & 255) * 256) + (b & 255);
	return (f);
}

int		ft_fuse(int *colormod)
{
	int value;

	value = colormod[0];
	value *= 10;
	value += colormod[1];
	value *= 10;
	value += colormod[2];
	return (value);
}

t_fdf	*exit_color_mode(t_fdf *f)
{
	f->which = 0;
	f->colormod[0] = -1;
	f->colormod[1] = -1;
	f->colormod[2] = -1;
	f->colormode = 0;
	return (f);
}

t_fdf	*valid_colormod(t_fdf *f, int keycode)
{
	if (f->colormod[0] == -1 && keycode >= 82 && keycode <= 92 && keycode != 90)
	{
		if (keycode > 89)
			f->colormod[0] = keycode - 83;
		else
			f->colormod[0] = keycode - 82;
	}
	else if (f->colormod[1] == -1 && keycode >= 82 && keycode <= 92 && \
		keycode != 90)
	{
		if (keycode > 89)
			f->colormod[1] = keycode - 83;
		else
			f->colormod[1] = keycode - 82;
	}
	else if (f->colormod[2] == -1 && keycode >= 82 && keycode <= 92 && \
		keycode != 90)
	{
		if (keycode > 89)
			f->colormod[2] = keycode - 83;
		else
			f->colormod[2] = keycode - 82;
	}
	return (f);
}

t_fdf	*color_management(t_fdf *f, int keycode)
{
	if (f->which == 0)
	{
		if (keycode == 83 || keycode == 84 || keycode == 85)
			f->which = keycode - 82;
	}
	else if (keycode == 36)
	{
		if (f->which == 1)
			f = createRGB(ft_fuse(f->colormod), f->g, f->b, f);
		else if (f->which == 2)
			f = createRGB(f->r, ft_fuse(f->colormod), f->b, f);
		else if (f->which == 3)
			f = createRGB(f->r, f->g, ft_fuse(f->colormod), f);
		f = exit_color_mode(f);
	}
	else
		f = valid_colormod(f, keycode);
	return (f);
}
