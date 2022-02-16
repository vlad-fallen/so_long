/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:57:58 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/15 17:55:53 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_arg(int n)
{
	if (n == 1)
		ft_putstr_fd("Error\n", 2);
	else if (n == 2)
		ft_putstr_fd("Error with allocate memory\n", 2);
	else if (n == 3)
		ft_putstr_fd("Error with open file\n", 2);
	exit(EXIT_FAILURE);
}

int get_height_of_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void clean_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

int end_program(t_prog_var *prog)
{
	clean_map(prog->map.map);
	mlx_destroy_window(prog->mlx, prog->window);
	exit(0);
	return (0);
}

void print_move(t_prog_var *prog)
{
	prog->player.count_move++;
	ft_putstr_fd("Move: ", 1);
	ft_putnbr_fd(prog->player.count_move, 1);
	ft_putstr_fd("\n", 1);

}
