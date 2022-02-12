/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:40:56 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/12 19:21:35 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render_image(void *image, int x, int y, t_prog_var *prog)
{
	mlx_put_image_to_window(prog->mlx, prog->window, image, x, y);
}

void render_wall(t_prog_var *prog, t_vector map, t_vector pixel_map)
{
	if (map.x == 0 && map.y == 0)
		render_image(prog->space.wall[4], pixel_map.x, pixel_map.y, prog);
	else if ((map.x == prog->map.map_size.x - 1) && map.y == 0)
		render_image(prog->space.wall[5], pixel_map.x, pixel_map.y, prog);
	else if (map.x == 0 && (map.y == prog->map.map_size.y - 1))
		render_image(prog->space.wall[6], pixel_map.x, pixel_map.y, prog);
	else if ((map.x == prog->map.map_size.x - 1) && (map.y == prog->map.map_size.y - 1))
		render_image(prog->space.wall[7], pixel_map.x, pixel_map.y, prog);
	else if (map.y == 0 && (map.x > 0 && (map.x < prog->map.map_size.x - 1)))
		render_image(prog->space.wall[3], pixel_map.x, pixel_map.y, prog);
	else if (map.x == 0 && (map.y > 0 && map.y < prog->map.map_size.y - 1))
		render_image(prog->space.wall[2], pixel_map.x, pixel_map.y, prog);
	else if ((map.y == prog->map.map_size.y - 1) && (map.x > 0 && map.x < prog->map.map_size.x - 1))
		render_image(prog->space.wall[0], pixel_map.x, pixel_map.y, prog);
	else if ((map.x == prog->map.map_size.x - 1) && (map.y > 0 && map.y < prog->map.map_size.y - 1))
		render_image(prog->space.wall[1], pixel_map.x, pixel_map.y, prog);
	else
		render_image(prog->space.wall[8], pixel_map.x, pixel_map.y, prog);
}

void selection_of_render(t_prog_var *prog, t_vector map, t_vector pixel_map)
{
	if (prog->map.map[map.y][map.x] == '1')
		render_wall(prog, map, pixel_map);
	else if (prog->map.map[map.y][map.x] == '0')
		render_image(prog->space.empty_space, pixel_map.x, pixel_map.y, prog);
	else if (prog->map.map[map.y][map.x] == 'P')
	{
		prog->player.player_position = map;
		render_image(prog->space.empty_space, pixel_map.x, pixel_map.y, prog);
		render_image(prog->player.img_player, pixel_map.x + 27, pixel_map.y + 76, prog);
	}
	else if (prog->map.map[map.y][map.x] == 'C')
	{
		render_image(prog->space.empty_space, pixel_map.x, pixel_map.y, prog);
		render_image(prog->diamond.img_collect, pixel_map.x, pixel_map.y, prog);
	}
	else if (prog->map.map[map.y][map.x] == 'E')
	{
		render_image(prog->space.empty_space, pixel_map.x, pixel_map.y, prog);
		render_image(prog->exit.img_escape, pixel_map.x, pixel_map.y, prog);
	}
}

void render_map(t_prog_var *prog)
{
	t_vector map;
	t_vector pixel_map;

	map.x = 0;
	map.y = 0;
	pixel_map.x = 0;
	pixel_map.y = 0;
	while (map.y < prog->map.map_size.y)
	{
		map.x = 0;
		pixel_map.x = 0;
		while (map.x < prog->map.map_size.x)
		{
			selection_of_render(prog, map, pixel_map);
			map.x++;
			pixel_map.x += 128;
		}
		map.y++;
		pixel_map.y += 128;
	}
}