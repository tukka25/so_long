/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:50 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/18 15:50:53 by abdamoha         ###   ########.fr       */
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
		if (s->counter.enemy <= 6 && s->counter.flag == 0)
		{
			move_enemy(s);
			s->counter.enemy++;
			ft_printf("e = %d", s->counter.enemy);
			if (s->counter.enemy == 6)
				s->counter.flag = 6;
		}
		else
		{
			move_enemy_back(s);
			s->counter.enemy--;
			if (s->counter.enemy == 0)
				s->counter.flag = 0;
		}
		print_map(s);
		i = 0;
	}
	return (0);
}

void	move_enemy(t_sl *s)
{
	int		k;

	k = 0;
	s->map.i = 0;
	s->map.j = 0;
	fill_array(s);
	if (!s->map.d_array)
		return ;
	while (k <= s->counter.d_count * 2 - 1)
	{
		s->map.i = s->map.d_array[k];
		s->map.j = s->map.d_array[k + 1];
		if (s->map.map[s->map.i][s->map.j + 1] == 'P')
		{
			ft_printf("You Lost!!");
			free_and_destory(s);
		}
		if (s->map.map[s->map.i][s->map.j + 1] == '0')
		{
			s->map.map[s->map.i][s->map.j] = '0';
			s->map.map[s->map.i][s->map.j + 1] = 'D';
		}
		k += 2;
	}
}

void	move_enemy_back(t_sl *s)
{
	int		k;

	k = 0;
	s->map.i = 0;
	s->map.j = 0;
	fill_array(s);
	if (!s->map.d_array)
		return ;
	while (k <= s->counter.d_count * 2 - 1)
	{
		s->map.i = s->map.d_array[k];
		s->map.j = s->map.d_array[k + 1];
		if (s->map.map[s->map.i][s->map.j - 1] == 'P')
		{
			ft_printf("You Lost!!");
			free_and_destory(s);
		}
		if (s->map.map[s->map.i][s->map.j - 1] == '0')
		{
			s->map.map[s->map.i][s->map.j] = '0';
			s->map.map[s->map.i][s->map.j - 1] = 'D';
		}
		k += 2;
	}
}
