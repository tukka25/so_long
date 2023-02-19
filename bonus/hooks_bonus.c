/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:23:37 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/19 19:15:27 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook(int keycode, t_sl *s)
{
	if (keycode == 123 || keycode == 124 || keycode == 125
		|| keycode == 126 || keycode == 0 || keycode == 1
		|| keycode == 2 || keycode == 13)
	{
		if (keycode == 124 || keycode == 2)
			move_player(s);
		else if (keycode == 123 || keycode == 0)
			move_back(s);
		else if (keycode == 126 || keycode == 13)
			move_up(s);
		else if (keycode == 125 || keycode == 1)
			move_down(s);
	}
	else if (keycode == 53)
		free_and_destory(s);
	return (0);
}

void	move_player(t_sl *s)
{
	if (s->map.map[s->map.p_index_y][s->map.p_index_x] == 'P'
	&& s->map.map[s->map.p_index_y][s->map.p_index_x + 1] != '1')
	{
		if (s->map.map[s->map.p_index_y][s->map.p_index_x + 1] == 'C')
			s->counter.collectibles--;
		check_if_exit(s, s->map.p_index_y, s->map.p_index_x + 1);
		if (s->map.map[s->map.p_index_y][s->map.p_index_x + 1] != 'E')
		{
			s->map.map[s->map.p_index_y][s->map.p_index_x] = '0';
			if (s->map.map[s->map.p_index_y][s->map.p_index_x + 1] == 'C')
			{
				s->map.map[s->map.p_index_y][s->map.p_index_x + 1] = '0';
				print_map(s);
			}
			s->map.map[s->map.p_index_y][s->map.p_index_x + 1] = 'P';
			s->map.p_index_x += 1;
			s->counter.moves++;
			ft_printf("total moves = %d\n", s->counter.moves);
			print_map(s);
		}
	}
}

void	move_back(t_sl *s)
{
	if (s->map.map[s->map.p_index_y][s->map.p_index_x] == 'P'
	&& s->map.map[s->map.p_index_y][s->map.p_index_x - 1] != '1')
	{
		if (s->map.map[s->map.p_index_y][s->map.p_index_x - 1] == 'C')
			s->counter.collectibles--;
		check_if_exit(s, s->map.p_index_y, s->map.p_index_x - 1);
		if (s->map.map[s->map.p_index_y][s->map.p_index_x - 1] != 'E')
		{
			s->map.map[s->map.p_index_y][s->map.p_index_x] = '0';
			s->map.map[s->map.p_index_y][s->map.p_index_x - 1] = 'P';
			s->map.p_index_x -= 1;
			s->counter.moves++;
			ft_printf("total moves = %d\n", s->counter.moves);
			rot(s);
		}
	}
}

void	move_up(t_sl *s)
{
	if (s->map.map[s->map.p_index_y][s->map.p_index_x] == 'P'
	&& s->map.map[s->map.p_index_y - 1][s->map.p_index_x] != '1')
	{
		if (s->map.map[s->map.p_index_y - 1][s->map.p_index_x] == 'C')
			s->counter.collectibles--;
		check_if_exit(s, s->map.p_index_y - 1, s->map.p_index_x);
		if (s->map.map[s->map.p_index_y - 1][s->map.p_index_x] != 'E')
		{
			s->map.map[s->map.p_index_y][s->map.p_index_x] = '0';
			s->map.map[s->map.p_index_y - 1][s->map.p_index_x] = 'P';
			s->map.p_index_y -= 1;
			s->counter.moves++;
			ft_printf("total moves = %d\n", s->counter.moves);
			print_map(s);
		}
	}
}

void	move_down(t_sl *s)
{
	if (s->map.map[s->map.p_index_y][s->map.p_index_x] == 'P'
	&& s->map.map[s->map.p_index_y + 1][s->map.p_index_x] != '1')
	{
		if (s->map.map[s->map.p_index_y + 1][s->map.p_index_x] == 'C')
			s->counter.collectibles--;
		check_if_exit(s, s->map.p_index_y + 1, s->map.p_index_x);
		if (s->map.map[s->map.p_index_y + 1][s->map.p_index_x] != 'E')
		{
			s->map.map[s->map.p_index_y][s->map.p_index_x] = '0';
			s->map.map[s->map.p_index_y + 1][s->map.p_index_x] = 'P';
			s->map.p_index_y += 1;
			s->counter.moves++;
			ft_printf("total moves = %d\n", s->counter.moves);
			print_map(s);
		}
	}
}
