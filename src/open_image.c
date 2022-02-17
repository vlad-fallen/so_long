/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:08:47 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/17 13:38:26 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_image_wall(t_prog_var *prog)
{
	int	img_width;
	int	img_height;

	prog->space.wall[0] = mlx_xpm_file_to_image(prog->mlx,
			"./game/wall/wall_000.xpm", &img_width, &img_height);
	prog->space.wall[1] = mlx_xpm_file_to_image(prog->mlx,
			"./game/wall/wall_001.xpm", &img_width, &img_height);
	prog->space.wall[2] = mlx_xpm_file_to_image(prog->mlx,
			"./game/wall/wall_002.xpm", &img_width, &img_height);
	prog->space.wall[3] = mlx_xpm_file_to_image(prog->mlx,
			"./game/wall/wall_003.xpm", &img_width, &img_height);
	prog->space.wall[4] = mlx_xpm_file_to_image(prog->mlx,
			"./game/wall/wall_004.xpm", &img_width, &img_height);
	prog->space.wall[5] = mlx_xpm_file_to_image(prog->mlx,
			"./game/wall/wall_005.xpm", &img_width, &img_height);
	prog->space.wall[6] = mlx_xpm_file_to_image(prog->mlx,
			"./game/wall/wall_006.xpm", &img_width, &img_height);
	prog->space.wall[7] = mlx_xpm_file_to_image(prog->mlx,
			"./game/wall/wall_007.xpm", &img_width, &img_height);
	prog->space.wall[8] = mlx_xpm_file_to_image(prog->mlx,
			"./game/wall/wall_008.xpm", &img_width, &img_height);
}

void	open_image_empty_space(t_prog_var *prog)
{
	int	img_width;
	int	img_height;

	prog->space.empty_space = mlx_xpm_file_to_image(prog->mlx,
			"./game/empty_space/empty_space_001.xpm", &img_width, &img_height);
}

void	open_image_player(t_prog_var *prog)
{
	int	img_width;
	int	img_height;

	prog->player.img_player[0] = mlx_xpm_file_to_image(prog->mlx,
			"./game/player/Idle_right_001.xpm", &img_width, &img_height);
	prog->player.img_player[1] = mlx_xpm_file_to_image(prog->mlx,
			"./game/player/Idle_left_001.xpm", &img_width, &img_height);
}

void	open_image_collectibles(t_prog_var *prog)
{
	int	img_width;
	int	img_height;

	prog->diamond.img_collect = mlx_xpm_file_to_image(prog->mlx,
			"./game/collectibles/Big_Diamond_001.xpm", &img_width, &img_height);
}

void	open_image_escape(t_prog_var *prog)
{
	int	img_width;
	int	img_height;

	prog->exit.img_escape[0] = mlx_xpm_file_to_image(prog->mlx,
			"./game/escape/door_001.xpm", &img_width, &img_height);
	prog->exit.img_escape[1] = mlx_xpm_file_to_image(prog->mlx,
			"./game/escape/door_002.xpm", &img_width, &img_height);
}
