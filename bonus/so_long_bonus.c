/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:10:07 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/19 19:15:46 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char *av[])
{
	int			i;
	t_sl		s;
	char		**str;

	i = 16766720;
	str = NULL;
	initialization(&s);
	if (ac == 2)
	{
		check_map(av, &s);
		s.mlx.mlx = mlx_init();
		s.counter.st = strr_i(s.counter.moves);
		s.mlx.mlx_win = mlx_new_window(s.mlx.mlx, (s.map.width * 64),
				(s.map.height * 64) + 25, "so_long");
		converting_xpm(&s);
		mlx_hook(s.mlx.mlx_win, 2, 0, key_hook, &s);
		mlx_hook(s.mlx.mlx_win, 17, 0, free_and_destory, &s);
		mlx_loop_hook(s.mlx.mlx, enemy_key, &s);
		pp(&s);
		printing_moves(&s);
		mlx_loop(s.mlx.mlx);
	}
	exit(0);
}

void	print_map(t_sl *s)
{
	put_player(s);
	printing_moves(s);
}

void	pp(t_sl *s)
{
	put_background(s);
	put_player(s);
	printing_moves(s);
}

void	rot(t_sl *s)
{
	put_player_r(s, 'P');
	printing_moves(s);
}

char	*strr_i(int totoal_moves)
{
	char	*s;
	char	*it;
	char	*join;

	s = ft_strdup("Total moves = ");
	it = ft_itoa(totoal_moves);
	join = ft_strjoin(s, it);
	free(s);
	free(it);
	return (join);
}
