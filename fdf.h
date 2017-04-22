/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 10:18:39 by tbouline          #+#    #+#             */
/*   Updated: 2017/04/18 22:05:05 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

# define ESCAPE 53
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define BACKSPACE 49
# define RETURN 36
# define ARGUMENT 1
# define ERROR 2
# define MALLOC_ERROR 3
# define WIN_X 2560
# define WIN_Y 1440
# define START_X (WIN_X / 5)
# define START_Y (WIN_Y / 5)
# define LENGTH f->length / 2
# define WIDTH f->width / 2
# define SPACING ((WIDTH > LENGTH) ? START_X / (WIDTH) : START_Y / (LENGTH))
# define ANGLE 45

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	int				**map;
	int				width;
	int				length;
	int				x;
	int				y;
	double			spacing;
	double			angle;
	double			xdec;
	double			ydec;
	double			zoom;
	unsigned long	color;
	int				colormode;
	int				r;
	int				g;
	int				b;
	int				which;
	int				colormod[3];
	t_coord			p1;
	t_coord			p2;
}					t_fdf;

t_fdf				*parse(char **argv, t_fdf *f);
void				error(t_fdf *f, int error);
t_fdf				*init(t_fdf *f);
void				put_string(t_fdf *f);
t_fdf				*color_management(t_fdf *f, int keycode);
void				line(t_fdf *f);
void				parallel(t_fdf *f);
t_fdf				*gettab(t_fdf *f);
t_fdf				*reverse(t_fdf *f);
t_fdf				*inverse(t_fdf *f);
void				put_color_strings(t_fdf *f);
t_fdf				*exit_color_mode(t_fdf *f);

#endif
