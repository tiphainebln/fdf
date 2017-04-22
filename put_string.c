/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:51:57 by tbouline          #+#    #+#             */
/*   Updated: 2017/04/14 18:52:00 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		*ft_sign(int num)
{
	if (num > 0)
		return ("+");
	else if (num < 0)
		return ("-");
	else
		return ("");
}

void		put_string(t_fdf *f)
{
	if (f->colormode == 0)
		mlx_string_put(f->mlx, f->win, WIN_X / 6 - 350, WIN_Y / 6 - 200, 0xFFFFFF, "Color mode : Press C to Enter.");
	else if (f->which == 0)
		mlx_string_put(f->mlx, f->win, WIN_X / 6 - 350, WIN_Y / 6 - 200, 0xFFFFFF, "Press 1 to change Red, 2 to change Green, 3 to change Blue");
	else
		mlx_string_put(f->mlx, f->win, WIN_X / 6 - 350, WIN_Y / 6 - 200, 0xFFFFFF, "Choose a value between 000 and 255, then confirm with Return.");
	if (f->colormod[0] != -1)
	{
		if (f->colormod[1] != -1)
		{
			if (f->colormod[2] != -1)
				mlx_string_put(f->mlx, f->win, WIN_X / 6 - 350, WIN_Y / 6 - 175, 0xFFFFFF, ft_strjoin(ft_strjoin(ft_itoa(f->colormod[0]), ft_itoa(f->colormod[1])), ft_itoa(f->colormod[2])));
			else
				mlx_string_put(f->mlx, f->win, WIN_X / 6 - 350, WIN_Y / 6 - 175, 0xFFFFFF, ft_strjoin(ft_itoa(f->colormod[0]), ft_itoa(f->colormod[1])));
		}
		else
			mlx_string_put(f->mlx, f->win, WIN_X / 6 - 350, WIN_Y / 6 - 175, 0xFFFFFF, ft_itoa(f->colormod[0]));
	}
	if (f->xdec != 0 || f->ydec != 0)
	{
		mlx_string_put(f->mlx, f->win, WIN_X / 6 - 350, WIN_Y / 6 - 140, 0xFFFFFF, ft_strjoin("X: ", ft_sign(f->xdec)));
		mlx_string_put(f->mlx, f->win, WIN_X / 6 - 310, WIN_Y / 6 - 140, 0xFFFFFF, ft_itoa(fabs(f->xdec)));
		mlx_string_put(f->mlx, f->win, WIN_X / 6 - 350, WIN_Y / 6 - 125, 0xFFFFFF, ft_strjoin("Y: ", ft_sign(f->ydec)));
		mlx_string_put(f->mlx, f->win, WIN_X / 6 - 310, WIN_Y / 6 - 125, 0xFFFFFF, ft_itoa(fabs(f->ydec)));
	}
	mlx_string_put(f->mlx, f->win, WIN_X / 6 - 350, WIN_Y / 6 - 95, 0xFFFFFF, ft_strjoin("Red: ", ft_itoa(f->r)));
	mlx_string_put(f->mlx, f->win, WIN_X / 6 - 350, WIN_Y / 6 - 70, 0xFFFFFF, ft_strjoin("Green: ", ft_itoa(f->g)));
	mlx_string_put(f->mlx, f->win, WIN_X / 6 - 350, WIN_Y / 6 - 45, 0xFFFFFF, ft_strjoin("Blue: ", ft_itoa(f->b)));
	mlx_string_put(f->mlx, f->win, WIN_X / 6 - 350, WIN_Y / 6 - 5, 0xFFFFFF, "Zoom option : Press + or -.");
	mlx_string_put(f->mlx, f->win, WIN_X / 6 - 350, WIN_Y / 6 - -20, 0xFFFFFF, ft_strjoin(ft_strjoin("Zoom: ", ft_itoa(f->zoom * 100)), "%"));
}
