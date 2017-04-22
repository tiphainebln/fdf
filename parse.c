/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 03:23:34 by tbouline          #+#    #+#             */
/*   Updated: 2017/01/17 09:35:11 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf		*translatetoint(char **map, t_fdf *f)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	k = 0;
	while (map[i])
	{
		j = 0;
		l = 0;
		while (map[i][j])
		{
			while (map[i][j] && ft_isspace(map[i][j]))
				j++;
			if (map[i][j] && !ft_isspace(map[i][j]))
				f->map[k][l++] = ft_atoi(&map[i][j]);
			while (map[i][j] && !ft_isspace(map[i][j]))
				j++;
		}
		i++;
		k++;
	}
	return (f);
}

int			how_many_numbers(char *str)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && !ft_isspace(str[i]))
			num++;
		while (str[i] && !ft_isspace(str[i]))
			i++;
	}
	return (num);
}

t_fdf		*get_map_size(char **map, t_fdf *f)
{
	int		i;

	i = 0;
	f->width = how_many_numbers(map[i++]);
	while (map[i])
	{
		if (f->width != how_many_numbers(map[i++]))
			error(f, ERROR);
	}
	f->length = i;
	f->map = (int **)malloc(sizeof(int *) * (f->length + 1));
	i = 0;
	while (i < f->length)
		f->map[i++] = (int *)malloc(sizeof(int) * (f->width + 1));
	f = translatetoint(map, f);
	f = reverse(f);
	f = inverse(f);
	return (f);
}

int			get_lines(char *path, t_fdf *f)
{
	char	buf;
	int		fd;
	int		nblines;

	nblines = 0;
	if (open(path, O_DIRECTORY) != -1)
		error(f, ARGUMENT);
	if ((fd = open(path, O_RDONLY)) < 0)
		error(f, ARGUMENT);
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			nblines++;
	}
	close(fd);
	if (buf == '\n')
		return (nblines);
	else
		return (nblines + 1);
}

t_fdf		*parse(char **argv, t_fdf *f)
{
	int		fd;
	char	**map;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (get_lines(argv[1], f) + 1))))
		error(f, MALLOC_ERROR);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &map[i]) > 0)
	{
		k = -1;
		while (map[i][++k] != '\0')
		{
			if (map[i][k] != ' ' && map[i][k] != '-' && !ft_isdigit(map[i][k]))
				error(f, ERROR);
		}
		i++;
	}
	map[i] = NULL;
	f = get_map_size(map, f);
	return (f);
}
