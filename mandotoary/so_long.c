/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:10:07 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/20 13:07:25 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_sl		s;
	char		**str;

	str = NULL;
	s.counter.moves = 0;
	s.counter.flag = 0;
	s.counter.enemy = 0;
	s.mlx.background = "./photos/bb.xpm";
	s.mlx.c_photo = "./photos/nez.xpm";
	s.mlx.exit_photo = "./photos/exit2.xpm";
	s.mlx.p_photo = "./photos/tt.xpm";
	s.mlx.walls = "./photos/out.xpm";
	if (ac == 2)
	{
		check_map(av, &s);
		s.mlx.mlx = mlx_init();
		s.mlx.mlx_win = mlx_new_window(s.mlx.mlx, s.map.width * 64,
				s.map.height * 64, "so_long");
		converting_xpm(&s);
		mlx_hook(s.mlx.mlx_win, 2, 0, key_hook, &s);
		mlx_hook(s.mlx.mlx_win, 17, 0, free_and_destory, &s);
		pp(&s);
		mlx_loop(s.mlx.mlx);
	}
	exit(0);
}

void	print_map(t_sl *s)
{
	put_player(s, 'P');
}

void	pp(t_sl *s)
{
	put_background(s);
	put_player(s, 'P');
}

void	rot(t_sl *s)
{
	put_player_r(s, 'P');
}
