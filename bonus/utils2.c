/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:52:22 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/17 04:25:57 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialization(t_sl *s)
{
	s->counter.moves = 0;
	s->counter.flag = 0;
	s->counter.enemy = 0;
	s->mlx.background = "./photos/bb.xpm";
	s->mlx.c_photo = "./photos/nez.xpm";
	s->mlx.exit_photo = "./photos/exit2.xpm";
	s->mlx.p_photo = "./photos/tt.xpm";
	s->mlx.walls = "./photos/out.xpm";
}

// void	printing_moves()
// {
// 	mlx_string_put(s.mlx.mlx, s.mlx.mlx_win, 80, 86, i, "---------");
// 	mlx_string_put(s.mlx.mlx, s.mlx.mlx_win, 78, 84, i, "|");
// 	mlx_string_put(s.mlx.mlx, s.mlx.mlx_win, 84, 84, i, s.counter.st);
// 	mlx_string_put(s.mlx.mlx, s.mlx.mlx_win, 140, 84, i, "|");
// 	mlx_string_put(s.mlx.mlx, s.mlx.mlx_win, 82, 91, i, "---------");
// }