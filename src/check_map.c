/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:40:48 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/17 10:51:25 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_rectangularity(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i - 1]))
		{
			clean_map(map);
			err_arg(1);
		}
		i++;
	}
}

static void	check_surrounded_by_wall(char **map)
{
	int	x;
	int	y;
	int	length_of_map;
	int	height_of_map;

	x = 0;
	y = 0;
	length_of_map = ft_strlen(map[x]);
	height_of_map = get_height_of_map(map);
	while (x < length_of_map)
	{
		if (map[0][x] != '1' || map[height_of_map - 1][x] != '1')
			err_arg(1);
		x++;
	}
	while (y < height_of_map)
	{
		if (map[y][0] != '1' || map[y][length_of_map - 1] != '1')
			err_arg(1);
		y++;
	}	
}

static void	check_characters(t_map *m)
{
	int	x;
	int	y;

	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] != '1' && m->map[y][x] != '0'
				&& m->map[y][x] != 'P' && m->map[y][x] != 'C'
				&& m->map[y][x] != 'E')
				err_arg(1);
			x++;
		}
		y++;
	}
}

static void	count_pce(t_map *m)
{
	int	x;
	int	y;

	m->count_player = 0;
	m->count_collect = 0;
	m->count_escape = 0;
	y = -1;
	while (m->map[++y])
	{
		x = -1;
		while (m->map[y][++x])
		{
			if (m->map[y][x] == 'P')
				m->count_player++;
			if (m->map[y][x] == 'C')
				m->count_collect++;
			if (m->map[y][x] == 'E')
				m->count_escape++;
		}
	}
	if (m->count_player != 1 || m->count_escape != 1)
		err_arg(1);
	if (m->count_collect == 0)
		err_arg(1);
}

void	check_valid_map(t_map *map)
{
	check_rectangularity(map->map);
	check_surrounded_by_wall(map->map);
	check_characters(map);
	count_pce(map);
}
