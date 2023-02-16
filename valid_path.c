/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:56:27 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/16 15:48:11 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker_behind(t_sl *s)
{
	s->map.i = 0;
	s->map.j = 0;
	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			if (s->map.map[s->map.i][s->map.j] == 'P' || s->map.map[s->map.i][s->map.j] == 'E'
			|| s->map.map[s->map.i][s->map.j] == 'C')
			{
				check_behind2(s);
				if (s->map.map[s->map.i][s->map.j] == 'C' &&
				s->map.map[s->map.i][s->map.j + 1] == '1' &&
				s->map.map[s->map.i][s->map.j - 1] == '1' &&
				s->map.map[s->map.i - 1][s->map.j] == '1' &&
				s->map.map[s->map.i + 1][s->map.j] == '1')
					free_and_exit(&s->map);
			}
			s->map.j++;
		}
		s->map.i++;
	}
}

void	check_behind2(t_sl *s)
{
	if (s->map.map[s->map.i][s->map.j] == 'P'
	|| s->map.map[s->map.i][s->map.j] == 'E')
	{
		if (s->map.map[s->map.i][s->map.j] == 'P' &&
		s->map.map[s->map.i][s->map.j + 1] == '1' &&
		s->map.map[s->map.i][s->map.j - 1] == '1' &&
		s->map.map[s->map.i - 1][s->map.j] == '1' &&
		s->map.map[s->map.i + 1][s->map.j] == '1')
			free_and_exit(&s->map);
		if (s->map.map[s->map.i][s->map.j] == 'E' &&
		s->map.map[s->map.i][s->map.j + 1] == '1' &&
		s->map.map[s->map.i][s->map.j - 1] == '1' &&
		s->map.map[s->map.i - 1][s->map.j] == '1' &&
		s->map.map[s->map.i + 1][s->map.j] == '1')
			free_and_exit(&s->map);
	}
}

void	last_photo(t_sl *s)
{
	// int		k = 0;
	// int		c = 0;
	s->map.i = 0;
	s->map.j = 0;
	// ft_printf("ffff\n");
	mlx_clear_window(s->mlx.mlx, s->mlx.mlx_win);
	s->counter.st = strr_i(s->counter.moves + 1);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 650, 300, 16766720, "You Win🥳🥳");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 650, 350, 16766720, s->counter.st);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 20, 20, 16711680, "Press ESC to exit");
	// return ;
	// sleep_exit();
	// return ;
	// pause();
	exit(0);
}

