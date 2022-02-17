/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:43:45 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/17 12:06:41 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include <mlx.h>

typedef enum e_bool
{
	e_false,
	e_true
}	t_bool;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
	char		**map;
	t_vector	map_size;
	int			count_player;
	int			count_collect;
	int			count_escape;
}	t_map;

typedef struct s_player
{
	void		*img_player[2];
	t_vector	position;
	t_bool		left_or_right;
	int			count_move;
}	t_player;

typedef struct s_collectible
{
	void		*img_collect;
	int			count_collect;
}	t_collectible;

typedef struct s_escape
{
	void		*img_escape[2];
	t_vector	position;
}	t_escape;

typedef struct s_space
{
	void	*wall[9];
	void	*empty_space;
}	t_space;

typedef struct s_prog_var
{
	void			*mlx;
	void			*window;
	t_vector		window_size;
	t_map			map;
	t_player		player;
	t_collectible	diamond;
	t_escape		exit;
	t_space			space;
	void			*img;
}	t_prog_var;

/* utils.c */
void	err_arg(int n);
void	clean_map(char **map);
int		get_height_of_map(char **map);
int		end_program(t_prog_var *prog);
void	print_move(t_prog_var *prog);

/* check_map.c */
void	check_valid_map(t_map *map);

/* create_map.c */
void	init_map(t_prog_var *prog, char **argv);

/* create_game.c */
void	game_init(t_prog_var *prog, int argc, char **argv);

/* render */
void	render_map(t_prog_var *prog);
void	render_image(void *image, int x, int y, t_prog_var *prog);

/* open_image.c */
void	open_image_wall(t_prog_var *prog);
void	open_image_empty_space(t_prog_var *prog);
void	open_image_player(t_prog_var *prog);
void	open_image_collectibles(t_prog_var *prog);
void	open_image_escape(t_prog_var *prog);

/* movement */
void	go_right(t_prog_var *prog);
void	go_left(t_prog_var *prog);
void	go_up(t_prog_var *prog);
void	go_down(t_prog_var *prog);

/* event */
void	collect_item(t_prog_var *prog, int x, int y);
void	go_to_exit(t_prog_var *prog, int x, int y);
void	render_door(t_prog_var *p);

#endif