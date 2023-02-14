/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:50 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/14 19:02:28 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy_key(t_sl *s)
{
	int		i;

	i = 0;
	print_map(s);
	if (s->counter.enemy == 0)
	{
		while (s->counter.enemy < 3)
		{
			mlx_clear_window(s->mlx.mlx, s->mlx.mlx_win);
			move_enemy(s);
			usleep(10000);
			// print_map(s);
			s->counter.enemy++;
		}
	}
	else if (s->counter.enemy == 3)
	{
		while (s->counter.enemy > 0)
		{
			mlx_clear_window(s->mlx.mlx, s->mlx.mlx_win);
			move_enemy_back(s);
			usleep(10000);
			// print_map(s);
			s->counter.enemy--;
		}
	}
	print_map(s);
	return (0);
}

void	move_enemy(t_sl *s)
{
	s->map.i = 0;
	s->map.j = 0;
	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			if (s->map.map[s->map.i][s->map.j] == 'D' && s->map.map[s->map.i][s->map.j + 1] != '1' && s->map.map[s->map.i][s->map.j + 1] != 'E')
			{
				s->map.map[s->map.i][s->map.j] = '0';
				s->map.map[s->map.i][s->map.j + 1] = 'D';
			}
			s->map.j++;
		}
		s->map.i++;
	}
	// s->counter.enemy += 3;
	// print_map(s);
}

void	move_enemy_back(t_sl *s)
{
	s->map.i = 0;
	s->map.j = 0;
	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			if (s->map.map[s->map.i][s->map.j] == 'D' && s->map.map[s->map.i][s->map.j - 1] != '1' && s->map.map[s->map.i][s->map.j - 1] != 'E')
			{
				s->map.map[s->map.i][s->map.j] = '0';
				s->map.map[s->map.i][s->map.j - 1] = 'D';
			}
			s->map.j++;
		}
		s->map.i++;
	}
	// print_map(s);
}
