/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:10:11 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/23 14:55:25 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./mlx/mlx.h"

typedef struct s_map
{
	int		i;
	int		j;
	int		height;
	int		width;
	char	*map_count;
	char	**map;
	int		p_index_x;
	int		p_index_y;
	int		color;
	char	**map_tmp;
	int		*d_array;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	*background;
	char	*p_photo;
	char	*p2_photo;
	char	*c_photo;
	char	*exit_photo;
	char	*walls;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	void	*wall_img;
	void	*p_img;
	void	*p2_img;
	void	*e_img;
	void	*c_img;
	void	*w_img;
	void	*d_img;
	void	*l_img;
	void	*c2_img;
}	t_img;

typedef struct s_counter
{
	int		collectibles;
	int		player;
	int		exit;
	int		demons;
	int		moves;
	char	*st;
	int		enemy;
	int		flag;
	int		d_count;
}	t_counter;

typedef struct s_so_long
{
	t_counter	counter;
	t_img		img;
	t_mlx		mlx;
	t_map		map;
}	t_sl;

void		check_map(char *av[], t_sl *s);
void		lines_counter(t_map *m, int fd);
void		insert_map(t_map *m, char *av[]);
int			cut_nl(char *str);
void		count_wid(t_map *m);
void		free_strings(char **str);
void		free_and_exit(t_map *m);
void		check_the_edges(t_map *m);
void		check_rectangular(t_map *m);
void		check_map_contents(t_map *m, t_counter *c);
void		valid_path(t_sl *s);
void		put_background(t_sl *s);
void		put_player(t_sl *s);
void		put_collectibles(t_sl *s, char ch);
void		put_exit(t_sl *s, char ch);
void		put_walls(t_sl *s, char ch);
int			key_hook(int keycode, t_sl *s);
void		player_index(t_sl *s);
void		print_map(t_sl *s);
void		move_player(t_sl *s);
void		pp(t_sl *s);
void		move_back(t_sl *s);
void		move_up(t_sl *s);
void		move_down(t_sl *s);
void		map_handle(char *str, int fd);
void		put_player_move(t_sl *s, char ch);
void		converting_xpm(t_sl *s);
void		put_player_r(t_sl *s);
void		rot(t_sl *s);
void		checker_behind(t_sl *s);
void		check_behind2(t_sl *s);
char		*strr_i(int totoal_moves);
void		last_photo(t_sl *s);
int			enemy_key(t_sl *s);
void		move_enemy(t_sl *s);
void		move_enemy_back(t_sl *s);
int			free_and_destory(t_sl *s);
void		animation(t_sl *s);
void		map_dup(t_sl *s);
int			check_valid_path(int x, int y, char **str, t_sl *s);
void		initialization(t_sl *s);
void		printing_moves(t_sl *s);
void		print_layer(t_sl *s);
void		demons_count(t_sl *s);
void		fill_array(t_sl *s);
void		printing_conditions(t_sl *s, int k, int c);
void		animation_conditions(t_sl *s, int k, int c);
void		map_conditions(t_counter *c, t_map *m, int i, int j);
void		check_if_exit(t_sl *s, int x, int y);
void		file_error(t_sl *s);
#endif