/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:10:11 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/05 23:06:18 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
// # include <./mlx/mlx.h>
// # include "./mlx/mlx_png.h"
// # include "./mlx/mlx_opengl.h"
// # include "./mlx/mlx_new_window.h"
// # include "./mlx/mlx_int.h"

typedef struct s_map
{
	int		i;
	int		j;
	int		height;
	int		width;
	char	*map_count;
	char	**map;
	int		p_index;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	*background;
	char	*walls;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	void	*wall_img;
}	t_img;

typedef struct s_counter
{
	int		collectibles;
	int		player;
	int		exit;
}	t_counter;

void		check_map(char *av[], t_map *m, t_counter *c);
void		lines_counter(t_map *m, int fd);
void		insert_map(t_map *m, char *av[]);
int			cut_nl(char *str);
void		count_wid(t_map *m);
void		free_strings(char **str);
void		free_and_exit(t_map *m);
void		check_the_edges(t_map *m);
void		check_rectangular(t_map *m);
void		check_map_contents(t_map *m, t_counter *c);
void		valid_path(t_map *m, t_counter *c);
void		put_background(t_map *m, t_mlx *mlx, t_img *img);
void		put_player(t_map *m, t_mlx *mlx, t_img *img, char ch);
void		put_collectibles(t_map *m, t_mlx *mlx, t_img *img, char ch);
void		put_exit(t_map *m, t_mlx *mlx, t_img *img, char ch);
void		put_walls(t_map *m, t_mlx *mlx, t_img *img, char ch);
int			key_hook(int keycode, t_mlx *mlx, t_map *m, t_img *img);
void		player_index(t_map *m);
void		print_map(t_map *m, t_mlx *mlx, t_img *img);
void		move_player(t_map *m);
void		pp(t_map *m, t_mlx *mlx, t_img *img);
#endif