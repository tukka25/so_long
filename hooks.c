/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:23:37 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/11 14:18:43 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_sl *s)
{
	// t_counter	c;
	// (void)m;
	// (void)keycode;
	// int j = 0;
	// s->counter.moves = 0;
	// s->counter.moves++;
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
	{
		if (keycode == 124)
			move_player(s);
		else if (keycode == 123)
			move_back(s);
		else if (keycode == 126)
			move_up(s);
		else if (keycode == 125)
			move_down(s);
		print_map(s);
		// ft_printf("total moves = %d\n", s->counter.moves);
	}
	else if (keycode == 53)
		exit(0);
	return (0);
}

void	move_player(t_sl *s)
{
	int i = 0;
	int j = 0;

	while (s->map.map[i])
	{
		j = 0;
		while (s->map.map[i][j])
		{
			if (s->map.map[i][j] == 'P' && s->map.map[i][j + 1] != '1')
			{
				if (s->map.map[i][j + 1] == 'C')
					s->counter.collectibles--;
				if (s->map.map[i][j + 1] == 'E' && s->counter.collectibles == 0)
					exit(0);
				if (s->map.map[i][j + 1] != 'E')
				{
					s->map.map[i][j] = '0';
					s->map.map[i][j + 1] = 'P';
					s->counter.moves++;
					ft_printf("total moves = %d\n", s->counter.moves);
				}
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_back(t_sl *s)
{
	int i = 0;
	int j = 0;

	while (s->map.map[i])
	{
		j = 0;
		while (s->map.map[i][j])
		{
			if (s->map.map[i][j] == 'P' && s->map.map[i][j - 1] != '1')
			{
				if (s->map.map[i][j - 1] == 'C')
					s->counter.collectibles--;
				if (s->map.map[i][j - 1] == 'E' && s->counter.collectibles == 0)
					exit(0);
				if (s->map.map[i][j - 1] != 'E')
				{
					s->map.map[i][j] = '0';
					s->map.map[i][j - 1] = 'P';
					s->counter.moves++;
					ft_printf("total moves = %d\n", s->counter.moves);
				}
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_up(t_sl *s)
{
	int i = 0;
	int j = 0;

	while (s->map.map[i])
	{
		j = 0;
		while (s->map.map[i][j])
		{
			if (s->map.map[i][j] == 'P' && s->map.map[i - 1][j] != '1')
			{
				if (s->map.map[i - 1][j] == 'C')
					s->counter.collectibles--;
				if (s->map.map[i - 1][j] == 'E' && s->counter.collectibles == 0)
					exit(0);
				if (s->map.map[i - 1][j] != 'E')
				{
					s->map.map[i][j] = '0';
					s->map.map[i - 1][j] = 'P';
					s->counter.moves++;
					ft_printf("total moves = %d\n", s->counter.moves);
				}
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_down(t_sl *s)
{
	int i = 0;
	int j = 0;

	while (s->map.map[i])
	{
		j = 0;
		while (s->map.map[i][j])
		{
			if (s->map.map[i][j] == 'P' && s->map.map[i + 1][j] != '1')
			{
				if (s->map.map[i + 1][j] == 'C')
					s->counter.collectibles--;
				if (s->map.map[i + 1][j] == 'E' && s->counter.collectibles == 0)
					exit(0);
				if (s->map.map[i + 1][j] != 'E')
				{
					s->map.map[i][j] = '0';
					s->map.map[i + 1][j] = 'P';
					s->counter.moves++;
					ft_printf("total moves = %d\n", s->counter.moves);
				}
				return ;
			}
			j++;
		}
		i++;
	}
}
