/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:52:22 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/19 21:06:00 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialization(t_sl *s)
{
	s->counter.moves = 0;
	s->counter.flag = 0;
	s->counter.enemy = 1;
	s->mlx.background = "./photos/b.xpm";
	s->mlx.c_photo = "./photos/nez.xpm";
	s->mlx.exit_photo = "./photos/e.xpm";
	s->mlx.p_photo = "./photos/p.xpm";
	s->mlx.walls = "./photos/wall.xpm";
}

void	printing_moves(t_sl *s)
{
	int		i;
	char	*line;

	i = 16711680;
	print_layer(s);
	line = "-------------------";
	if (s->counter.st)
		free(s->counter.st);
	s->counter.st = strr_i(s->counter.moves);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 8, 7, i, line);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 6, 15, i, "|");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 12, 15, i, s->counter.st);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 138, 15, i, "|");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 10, 22, i, line);
}

void	print_layer(t_sl *s)
{
	int		k;

	k = 0;
	s->map.j = 0;
	while (s->map.map[0][s->map.j])
	{
		mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.l_img, k, 1);
		k += 64;
		s->map.j++;
	}
}

void	printing_conditions(t_sl *s, int k, int c)
{
	mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.img, k, c);
	if (s->map.map[s->map.i][s->map.j] == 'P')
		mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.p_img, k, c);
	else if (s->map.map[s->map.i][s->map.j] == 'C')
		mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.c_img, k, c);
	else if (s->map.map[s->map.i][s->map.j] == 'E')
		mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.e_img, k, c);
	else if (s->map.map[s->map.i][s->map.j] == '1')
		mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.w_img, k, c);
	else if (s->map.map[s->map.i][s->map.j] == 'D')
		mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.d_img, k, c);
}

void	animation_conditions(t_sl *s, int k, int c)
{
	mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.img, k, c);
	if (s->map.map[s->map.i][s->map.j] == 'P')
		mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.p_img, k, c);
	else if (s->map.map[s->map.i][s->map.j] == 'C')
		mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win,
			s->img.c2_img, k, c);
	else if (s->map.map[s->map.i][s->map.j] == 'E')
		mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.e_img, k, c);
	else if (s->map.map[s->map.i][s->map.j] == '1')
		mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.w_img, k, c);
	else if (s->map.map[s->map.i][s->map.j] == 'D')
		mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.d_img, k, c);
}
