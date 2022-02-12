/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:43:45 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/12 18:48:34 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_vector
{
	int x;
	int y;
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
	void		*img_player;
	t_vector	player_position;
}	t_player;

typedef struct s_collectible
{
	void		*img_collect;
	t_vector	*collect_position;
}	t_collectible;

typedef struct s_escape
{
	void		*img_escape;
	t_vector	*escape_position;
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
void clean_map(char **map);
int get_height_of_map(char **map);
int end_program(t_prog_var *prog);

/* check_map.c */
void check_valid_map(t_map *map);

/* create_map.c */
void init_map(t_prog_var *prog, char **argv);

/* create_game.c */
void game_init(t_prog_var *prog, int argc, char **argv);

/* render */
void render_map(t_prog_var *prog);

/* open_image.c */
void open_image_wall(t_prog_var *prog);
void open_image_empty_space(t_prog_var *prog);
void open_image_player(t_prog_var *prog);
void open_image_collectibles(t_prog_var *prog);
void open_image_escape(t_prog_var *prog);

#endif