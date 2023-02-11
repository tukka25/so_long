/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:10:07 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/11 20:09:07 by abdamoha         ###   ########.fr       */
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
		// converting_xpm(&s);
		// mlx_loop_hook(s.mlx.mlx, key_hook, &s);
		// mlx_key_hook(s.mlx.mlx_win, key_hook, &s);
		mlx_hook(s.mlx.mlx_win, 2, 0, key_hook, &s);
		// mlx_loop_hook(s.mlx.mlx, key_hook, &s);
		pp(&s);
		// put_player(&s, 'P');
		// print_map(&s);
		// player_index(&m);
		// printf("p_index = %d\n", m.p_index);
		// exit(0);
		mlx_loop(s.mlx.mlx);
	}
	exit(0);
}

void	print_map(t_sl *s)
{
	// put_background(s);
	put_player(s, 'P');
	// put_collectibles(s, 'C');
	// put_exit(s, 'E');
	// put_walls(s, '1');
}

void	pp(t_sl *s)
{
	put_background(s);
	put_player(s, 'P');
}
