/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:43:23 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/17 11:33:02 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_prog_var *prog)
{
	if (keycode == 2)
		go_right(prog);
	else if (keycode == 0)
		go_left(prog);
	else if (keycode == 13)
		go_up(prog);
	else if (keycode == 1)
		go_down(prog);
	else if (keycode == 53)
		end_program(prog);
	return (0);
}

int	main(int argc, char **argv)
{
	t_prog_var	prog;

	game_init(&prog, argc, argv);
	mlx_hook(prog.window, 2, 0, key_hook, &prog);
	mlx_loop(prog.mlx);
	return (0);
}
