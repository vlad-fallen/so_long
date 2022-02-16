/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:40:56 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/16 17:26:57 by mbutter          ###   ########.fr       */
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
		prog->player.position.x = pixel_map.x;
		prog->player.position.y = pixel_map.y + 6;
		render_image(prog->space.empty_space, pixel_map.x, pixel_map.y, prog);
		render_image(prog->player.img_player[0], prog->player.position.x, prog->player.position.y, prog);
	}
	else if (prog->map.map[map.y][map.x] == 'C')
	{
		prog->diamond.count_collect++;
		render_image(prog->space.empty_space, pixel_map.x, pixel_map.y, prog);
		render_image(prog->diamond.img_collect, pixel_map.x + 8, pixel_map.y + 12, prog);
	}
	else if (prog->map.map[map.y][map.x] == 'E')
	{
		prog->exit.position.x = pixel_map.x + 9;
		prog->exit.position.y = pixel_map.y + 8;
		render_image(prog->space.empty_space, pixel_map.x, pixel_map.y, prog);
		render_image(prog->exit.img_escape[0], pixel_map.x + 9, pixel_map.y + 8, prog);
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
	prog->player.count_move = 0;
	prog->diamond.count_collect = 0;
	while (map.y < prog->map.map_size.y)
	{
		map.x = 0;
		pixel_map.x = 0;
		while (map.x < prog->map.map_size.x)
		{
			selection_of_render(prog, map, pixel_map);
			map.x++;
			pixel_map.x += 64;
		}
		map.y++;
		pixel_map.y += 64;
	}
}