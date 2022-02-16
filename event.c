/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:20:39 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/16 17:57:14 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void collect_item(t_prog_var *prog, int x, int y)
{
	prog->diamond.count_collect--;
	prog->map.map[y / 64][x / 64] = '0';
	render_image(prog->space.empty_space, x, y, prog);
	if (prog->diamond.count_collect == 0)
		render_image(prog->exit.img_escape[1], prog->exit.position.x, prog->exit.position.y, prog);
}

void go_to_exit(t_prog_var *prog, int x, int y)
{
	if (prog->diamond.count_collect != 0)
	{
		render_image(prog->exit.img_escape[0], prog->exit.position.x, prog->exit.position.y, prog);
		return ;
	}
	else
		render_image(prog->exit.img_escape[1], prog->exit.position.x, prog->exit.position.y, prog);
	if (x == (prog->exit.position.x - 9) && (y - 6) == (prog->exit.position.y - 8))
		end_program(prog);
}

void render_door(t_prog_var *p)
{
	render_image(p->space.empty_space, p->exit.position.x - 9, p->exit.position.y - 8, p);
	if (p->diamond.count_collect == 0)
		render_image(p->exit.img_escape[1], p->exit.position.x, p->exit.position.y, p);
	else
		render_image(p->exit.img_escape[0], p->exit.position.x, p->exit.position.y, p);
}