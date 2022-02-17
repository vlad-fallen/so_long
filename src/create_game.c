/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:46:40 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/17 10:52:28 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_image(t_prog_var *prog)
{
	open_image_wall(prog);
	open_image_empty_space(prog);
	open_image_player(prog);
	open_image_collectibles(prog);
	open_image_escape(prog);
}

void	game_init(t_prog_var *prog, int argc, char **argv)
{
	if (argc < 2)
		err_arg(1);
	init_map(prog, argv);
	prog->mlx = mlx_init();
	prog->window = mlx_new_window(prog->mlx, prog->window_size.x,
			prog->window_size.y, "so_long");
	mlx_hook(prog->window, 17, 0, end_program, prog);
	open_image(prog);
	render_map(prog);
}
