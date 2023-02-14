/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:50 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/14 18:23:04 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy_key(int keycode, t_sl *s)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		move_enemy(s);
		i++;
	}
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
			if (s->map.map[s->map.i][s->map.j] == 'D')
			{
				s->map.map[s->map.i][s->map.j] == 0;
				s->map.map[s->map.i][s->map.j + 1] == 'D';
			}
			s->map.j++;
		}
		s->map.i++;
	}
	print_map(s);
}
