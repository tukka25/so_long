/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:10:07 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/14 18:58:19 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	int			i;
	t_sl		s;
	char		**str;

	i = 0;
	str = NULL;
	s.counter.moves = 0;
	s.counter.enemy = 0;
	s.mlx.background = "./photos/ground.xpm";
	s.mlx.c_photo = "./photos/nez.xpm";
	s.mlx.exit_photo = "./photos/black-hole-2.xpm";
	s.mlx.p_photo = "./photos/tt.xpm";
	s.mlx.walls = "./photos/out.xpm";
	// s.mlx.
	// converting_xpm(&s);
	if (ac == 2)
	{
		check_map(av, &s);
		s.mlx.mlx = mlx_init();
		s.counter.st = strr_i(s.counter.moves);
		s.mlx.mlx_win = mlx_new_window(s.mlx.mlx, s.map.width * 64, s.map.height * 64, "so_long");
		converting_xpm(&s);
		mlx_hook(s.mlx.mlx_win, 2, 0, key_hook, &s);
		mlx_loop_hook(s.mlx.mlx, enemy_key, &s);
		pp(&s);
		int factor_y = 20;
		int factor_x = 20;
		mlx_string_put(s.mlx.mlx, s.mlx.mlx_win, 60 + factor_x, 56 + factor_y, 0x00000000, "---------");
		mlx_string_put(s.mlx.mlx, s.mlx.mlx_win, 58 + factor_x, 64 + factor_y, 0x00000000, "|");
		mlx_string_put(s.mlx.mlx, s.mlx.mlx_win, 64 + factor_x, 64 + factor_y, 0x00000000, s.counter.st);
		mlx_string_put(s.mlx.mlx, s.mlx.mlx_win, 120 + factor_x, 64 + factor_y, 0x00000000, "|");
		mlx_string_put(s.mlx.mlx, s.mlx.mlx_win, 62 + factor_x, 71 + factor_y, 0x00000000, "---------");
		mlx_loop(s.mlx.mlx);
	}
	exit(0);
}

void	print_map(t_sl *s)
{
	put_player(s, 'P');
	s->counter.st = strr_i(s->counter.moves);
	int factor_y = 20;
	int factor_x = 20;
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 60 + factor_x, 56 + factor_y, 0x00000000, "-------------------");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 58 + factor_x, 64 + factor_y, 0x00000000, "|");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 64 + factor_x, 64 + factor_y, 0x00000000, s->counter.st);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 190 + factor_x, 64 + factor_y, 0x00000000, "|");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 62 + factor_x, 71 + factor_y, 0x00000000, "-------------------");
}

void	pp(t_sl *s)
{
	put_background(s);
	put_player(s, 'P');
	int factor_y = 20;
	int factor_x = 20;
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 60 + factor_x, 56 + factor_y, 0x00000000, "-------------------");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 58 + factor_x, 64 + factor_y, 0x00000000, "|");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 64 + factor_x, 64 + factor_y, 0x00000000, s->counter.st);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 190 + factor_x, 64 + factor_y, 0x00000000, "|");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 62 + factor_x, 71 + factor_y, 0x00000000, "-------------------");
}

void	rot(t_sl *s)
{
	put_player_r(s, 'P');
	s->counter.st = strr_i(s->counter.moves);
	int factor_y = 20;
	int factor_x = 20;
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 60 + factor_x, 56 + factor_y, 0x00000000, "-------------------");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 58 + factor_x, 64 + factor_y, 0x00000000, "|");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 64 + factor_x, 64 + factor_y, 0x00000000, s->counter.st);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 190 + factor_x, 64 + factor_y, 0x00000000, "|");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 62 + factor_x, 71 + factor_y, 0x00000000, "-------------------");
}

char *strr_i(int totoal_moves)
{
	char *s = ft_strdup("total moves = ");
	char *join = ft_strjoin(s, ft_itoa(totoal_moves));
	return join;
}