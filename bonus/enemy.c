/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:50 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/17 03:42:33 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy_key(t_sl *s)
{
	static int		i;

	i++;
	if (i == 2000)
		animation(s);
	if (i == 5080)
	{
		if (s->counter.enemy < 6 && s->counter.flag == 0)
		{
			move_enemy(s);
			s->counter.enemy++;
			if (s->counter.enemy == 5)
				s->counter.flag = 6;
		}
		else
		{
			move_enemy_back(s);
			s->counter.enemy--;
			if (s->counter.enemy == 0)
				s->counter.flag = 0;
		}
		animation(s);
		print_map(s, 0x00000000);
		i = 0;
	}
	// animation(s);
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
			if ((s->map.map[s->map.i][s->map.j] == 'D' && s->map.map[s->map.i][s->map.j + 1] == '0') || (s->map.map[s->map.i][s->map.j] == 'D' && s->map.map[s->map.i][s->map.j + 1] == 'P'))
			{
				if (s->map.map[s->map.i][s->map.j + 1] == 'P')
				{
					ft_printf("you lost!");
					free_and_destory(s);
				}
				s->map.map[s->map.i][s->map.j] = '0';
				s->map.map[s->map.i][s->map.j + 1] = 'D';
			}
			s->map.j++;
		}
		s->map.i++;
	}
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
			if ((s->map.map[s->map.i][s->map.j] == 'D' && s->map.map[s->map.i][s->map.j - 1] == '0') || (s->map.map[s->map.i][s->map.j] == 'D' && s->map.map[s->map.i][s->map.j - 1] == 'P'))
			{
				if (s->map.map[s->map.i][s->map.j - 1] == 'P')
				{
					ft_printf("you lost!");
					free_and_destory(s);
				}
				s->map.map[s->map.i][s->map.j] = '0';
				s->map.map[s->map.i][s->map.j - 1] = 'D';
			}
			s->map.j++;
		}
		s->map.i++;
	}
}
