/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:10:07 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/17 04:01:05 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	int			i;
	t_sl		s;
	char		**str;

	i = 0x00000000;
	str = NULL;
	initialization(&s);
	if (ac == 2)
	{
		check_map(av, &s);
		s.mlx.mlx = mlx_init();
		s.counter.st = strr_i(s.counter.moves);
		s.mlx.mlx_win = mlx_new_window(s.mlx.mlx, (s.map.width * 64), (s.map.height * 64) + 25, "so_long");
		converting_xpm(&s);
		mlx_hook(s.mlx.mlx_win, 2, 0, key_hook, &s);
		mlx_loop_hook(s.mlx.mlx, enemy_key, &s);
		pp(&s, i);
		mlx_string_put(s.mlx.mlx, s.mlx.mlx_win, 80, 86, i, "---------");
		mlx_string_put(s.mlx.mlx, s.mlx.mlx_win, 78, 84, i, "|");
		mlx_string_put(s.mlx.mlx, s.mlx.mlx_win, 84, 84, i, s.counter.st);
		mlx_string_put(s.mlx.mlx, s.mlx.mlx_win, 210, 84, i, "|");
		mlx_string_put(s.mlx.mlx, s.mlx.mlx_win, 82, 91, i, "---------");
		mlx_loop(s.mlx.mlx);
	}
	exit(0);
}

void	print_map(t_sl *s, int i)
{
	char	*line;

	line = "-------------------";
	put_player(s, 'P');
	s->counter.st = strr_i(s->counter.moves);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 80, 76, i, line);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 78, 84, i, "|");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 84, 84, i, s->counter.st);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 210, 84, i, "|");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 82, 91, i, line);
}

void	pp(t_sl *s, int i)
{
	char	*line;

	line = "-------------------";
	put_background(s);
	put_player(s, 'P');
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 80, 76, i, line);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 78, 84, i, "|");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 84, 84, i, s->counter.st);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 210, 84, i, "|");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 82, 91, i, line);
}

void	rot(t_sl *s, int i)
{
	char	*line;

	line = "-------------------";
	put_player_r(s, 'P');
	s->counter.st = strr_i(s->counter.moves);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 80, 76, i, line);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 78, 84, i, "|");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 84, 84, i, s->counter.st);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 210, 84, i, "|");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 82, 91, i, line);
}

char	*strr_i(int totoal_moves)
{
	char	*s;
	char	*join;

	s = ft_strdup("total moves = ");
	join = ft_strjoin(s, ft_itoa(totoal_moves));
	free(s);
	return (join);
}
