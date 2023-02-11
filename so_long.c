/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:10:07 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/11 21:55:39 by abdamoha         ###   ########.fr       */
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
	s.mlx.background = "./photos/ground.xpm";
	s.mlx.c_photo = "./photos/coins.xpm";
	s.mlx.exit_photo = "./photos/black-hole-2.xpm";
	s.mlx.p_photo = "./photos/tt.xpm";
	s.mlx.walls = "./photos/out.xpm";
	converting_xpm(&s);
	if (ac == 2)
	{
		check_map(av, &s);
		// converting_xpm(&s);
		s.mlx.mlx = mlx_init();
		s.mlx.mlx_win = mlx_new_window(s.mlx.mlx, s.map.width * 64, s.map.height * 64, "so_long");
		mlx_hook(s.mlx.mlx_win, 2, 0, key_hook, &s);
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
