/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:54:05 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/16 17:38:01 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render_backspace(t_prog_var *prog, int x, int y)
{
	render_image(prog->space.empty_space, x, y, prog);
	if (prog->map.map[y / 64 - 1][x / 64 - 1] == '0' || prog->map.map[y / 64 - 1][x / 64 - 1] == 'P')
		render_image(prog->space.empty_space, x - 64, y - 64, prog);
	if (prog->map.map[y / 64 - 1][x / 64] == '0' || prog->map.map[y / 64 - 1][x / 64] == 'P')
		render_image(prog->space.empty_space, x, y - 64, prog);
	if (prog->map.map[y / 64 - 1][x / 64 + 1] == '0' || prog->map.map[y / 64 - 1][x / 64 + 1] == 'P')
		render_image(prog->space.empty_space, x + 64, y - 64, prog);
	if (prog->map.map[y / 64][x / 64 - 1] == '0' || prog->map.map[y / 64][x / 64 - 1] == 'P')
		render_image(prog->space.empty_space, x - 64, y, prog);
	if (prog->map.map[y / 64][x / 64 + 1] == '0' || prog->map.map[y / 64][x / 64 + 1] == 'P')
		render_image(prog->space.empty_space, x + 64, y, prog);
	if (prog->map.map[y / 64 + 1][x / 64 - 1] == '0' || prog->map.map[y / 64 + 1][x / 64 - 1] == 'P')
		render_image(prog->space.empty_space, x - 64, y + 64, prog);
	if (prog->map.map[y / 64 + 1][x / 64] == '0' || prog->map.map[y / 64 + 1][x / 64] == 'P')
		render_image(prog->space.empty_space, x, y + 64, prog);
	if (prog->map.map[y / 64 + 1][x / 64 + 1] == '0' || prog->map.map[y / 64 + 1][x / 64 + 1] == '0')
		render_image(prog->space.empty_space, x + 64, y + 64, prog);
}

void go_right(t_prog_var *p)
{
	t_vector pixel_map;

	pixel_map.x = p->player.position.x - p->player.position.x % 64;
	pixel_map.y = p->player.position.y - p->player.position.y % 64;
	render_backspace(p, pixel_map.x, pixel_map.y);
	if (p->map.map[pixel_map.y / 64][(p->player.position.x + 70) / 64] != '1' && p->map.map[(p->player.position.y + 32) / 64][(p->player.position.x + 70) / 64] != '1')
		p->player.position.x += 32;
	if (p->map.map[pixel_map.y / 64][(p->player.position.x + 32) / 64] == 'C')
		collect_item(p, pixel_map.x + 64, pixel_map.y);
	else if (p->map.map[(p->player.position.y + 32) / 64][(p->player.position.x + 32) / 64] == 'C')
		collect_item(p, pixel_map.x + 64, pixel_map.y + 64);
	if (p->map.map[p->player.position.y / 64][p->player.position.x / 64] == 'E')
		go_to_exit(p, p->player.position.x, p->player.position.y);
	render_door(p);
	render_image(p->player.img_player[0], p->player.position.x, p->player.position.y, p);
	p->player.left_or_right = e_true;
	print_move(p);
}

void go_left(t_prog_var *p)
{
	t_vector pixel_map;

	pixel_map.x = p->player.position.x - p->player.position.x % 64;
	pixel_map.y = p->player.position.y - p->player.position.y % 64;
	render_backspace(p, pixel_map.x, pixel_map.y);
	if (p->map.map[pixel_map.y / 64][(p->player.position.x - 1) / 64] != '1' && p->map.map[(p->player.position.y + 35) / 64][(p->player.position.x - 1) / 64] != '1')
		p->player.position.x -= 32;
	if (p->map.map[pixel_map.y / 64][p->player.position.x / 64] == 'C')
		collect_item(p, pixel_map.x - 64, pixel_map.y);
	else if (p->map.map[(p->player.position.y + 32) / 64][p->player.position.x / 64] == 'C')
		collect_item(p, pixel_map.x - 64, pixel_map.y + 64);
	if (p->map.map[p->player.position.y / 64][p->player.position.x / 64] == 'E')
		go_to_exit(p, p->player.position.x, p->player.position.y);
	render_door(p);
	render_image(p->player.img_player[1], p->player.position.x, p->player.position.y, p);
	p->player.left_or_right = e_false;
	print_move(p);
}

void go_up(t_prog_var *p)
{
	t_vector pixel_map;

	pixel_map.x = p->player.position.x - p->player.position.x % 64;
	pixel_map.y = p->player.position.y - p->player.position.y % 64;
	render_backspace(p, pixel_map.x, pixel_map.y);
	if (p->map.map[(p->player.position.y - 7) / 64][pixel_map.x / 64] != '1' && p->map.map[(p->player.position.y - 7) / 64][(p->player.position.x + 63) / 64] != '1')
		p->player.position.y -= 32;
	if (p->map.map[p->player.position.y / 64][p->player.position.x / 64] == 'C')
		collect_item(p, pixel_map.x, pixel_map.y - 64);
	else if (p->map.map[p->player.position.y / 64][(p->player.position.x + 32) / 64] == 'C')
		collect_item(p, pixel_map.x + 64, pixel_map.y - 64);
	if (p->map.map[p->player.position.y / 64][p->player.position.x / 64] == 'E')
		go_to_exit(p, p->player.position.x, p->player.position.y);
	render_door(p);
	if (p->player.left_or_right)
		render_image(p->player.img_player[0], p->player.position.x, p->player.position.y, p);
	else
		render_image(p->player.img_player[1], p->player.position.x, p->player.position.y, p);
	print_move(p);
}

void go_down(t_prog_var *p)
{
	t_vector pixel_map;


	pixel_map.x = p->player.position.x - p->player.position.x % 64;
	pixel_map.y = p->player.position.y - p->player.position.y % 64;
	render_backspace(p, pixel_map.x, pixel_map.y);
	if (p->map.map[(p->player.position.y + 64) / 64][pixel_map.x / 64] != '1' && p->map.map[(p->player.position.y + 64) / 64][(p->player.position.x + 63) / 64] != '1')
		p->player.position.y += 32;
	if (p->map.map[(p->player.position.y + 32) / 64][p->player.position.x / 64] == 'C')
		collect_item(p, pixel_map.x, pixel_map.y + 64);
	else if (p->map.map[(p->player.position.y + 32) / 64][(p->player.position.x + 32) / 64] == 'C')
		collect_item(p, pixel_map.x + 64, pixel_map.y + 64);
	if (p->map.map[p->player.position.y / 64][p->player.position.x / 64] == 'E')
		go_to_exit(p, p->player.position.x, p->player.position.y);
	render_door(p);
	if (p->player.left_or_right)
		render_image(p->player.img_player[0], p->player.position.x, p->player.position.y, p);
	else
		render_image(p->player.img_player[1], p->player.position.x, p->player.position.y, p);
	print_move(p);
}
