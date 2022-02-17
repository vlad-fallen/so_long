/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:55:13 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/17 10:53:29 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_file_name(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
	{
		if (file_name[i] == '.')
		{
			if (!ft_strncmp(&file_name[i], ".ber", 5))
				return ;
		}
		i++;
	}
	err_arg(1);
	exit(EXIT_FAILURE);
}

static void	open_map(char *file_name, t_map *map)
{
	int		fd;
	char	*line;
	char	*all_line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		err_arg(2);
	line = NULL;
	all_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_line = ft_strjoin(all_line, line);
		if (all_line == NULL)
			err_arg(2);
		free(line);
	}
	free(line);
	close(fd);
	map->map = ft_split(all_line, '\n');
}

void	init_map(t_prog_var *prog, char **argv)
{
	check_file_name(argv[1]);
	open_map(argv[1], &(prog->map));
	check_valid_map(&(prog->map));
	prog->map.map_size.x = ft_strlen(prog->map.map[0]);
	prog->map.map_size.y = get_height_of_map(prog->map.map);
	prog->window_size.x = prog->map.map_size.x * 64;
	prog->window_size.y = prog->map.map_size.y * 64;
}
