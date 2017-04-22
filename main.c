/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 09:35:22 by tbouline          #+#    #+#             */
/*   Updated: 2017/01/10 22:56:48 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*map_grid(t_fdf *f)
{
	parallel(f);
	put_string(f);
	return (f);
}

int		key_hook(int keycode, t_fdf *f)
{
	if (keycode == ESCAPE)
		error(f, 0);
	else if (keycode == 8 && f->colormode == 0)
		f->colormode = 1;
	else if (keycode == 8)
		f = exit_color_mode(f);
	else if (f->colormode)
		f = color_management(f, keycode);
	else if (keycode == 69)
		f->zoom += 0.25;
	else if (keycode == 78)
	{
		if (f->zoom != 0.25)
			f->zoom -= 0.25;
	}
	else if (keycode == 124)
		f->xdec += 25;
	else if (keycode == 125)
		f->ydec += 25;
	else if (keycode == 123)
		f->xdec -= 25;
	else if (keycode == 126)
		f->ydec -= 25;
	mlx_clear_window(f->mlx, f->win);
	f = map_grid(f);
	return (0);
}

int		expose_hook(t_fdf *f)
{
	f = map_grid(f);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf *f;

	f = NULL;
	f = init(f);
	if (argc != 2 || !argv)
		error(f, ARGUMENT);
	f = parse(argv, f);
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_X, WIN_Y, "mlx42");
	mlx_key_hook(f->win, key_hook, f);
	mlx_expose_hook(f->win, expose_hook, f);
	mlx_hook(f->win, 2, 1, NULL, f);
	mlx_loop(f->mlx);
	return (0);
}
