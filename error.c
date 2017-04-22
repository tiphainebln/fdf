/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 07:09:13 by tbouline          #+#    #+#             */
/*   Updated: 2017/01/16 07:17:03 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void				exit_fdf(t_fdf *f)
{
	int		i;

	i = 0;
	if (f->mlx)
		mlx_destroy_window(f->mlx, f->win);
	if (f->map)
	{
		while (i < f->length)
		{
			free(f->map[i]);
			f->map[i++] = NULL;
		}
		free(f->map);
		f->map = NULL;
	}
	free(f);
	f = NULL;
}

void					error(t_fdf *f, int error)
{
	if (error == ARGUMENT)
		ft_putendl_fd("Usage: ./fdf [invalid argument]", 1);
	if (error == ERROR)
		ft_putendl_fd("error", 2);
	else if (error == MALLOC_ERROR)
		ft_putendl_fd("Malloc error", 3);
	if (f)
		exit_fdf(f);
	exit(error);
}
