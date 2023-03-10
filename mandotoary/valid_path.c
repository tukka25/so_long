/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:56:27 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/19 20:55:04 by abdamoha         ###   ########.fr       */
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
			if (s->map.map[s->map.i][s->map.j] == 'P'
			|| s->map.map[s->map.i][s->map.j] == 'E'
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
	int		k;

	k = 16711680;
	s->counter.moves++;
	ft_printf("You Won !!\n");
	ft_printf("total moves = %d\n", s->counter.moves);
	free_and_destory(s);
}

void	map_dup(t_sl *s)
{
	int		i;

	i = 0;
	s->map.map_tmp = NULL;
	s->map.map_tmp = malloc((s->map.height + 1) * sizeof(char *));
	while (s->map.map[i] != NULL)
	{
		s->map.map_tmp[i] = ft_strdup(s->map.map[i]);
		i++;
	}
	s->map.map_tmp[i] = NULL;
}

int	check_valid_path(int y, int x, char **str, t_sl *s)
{
	if (str[y][x] == 'C')
		s->counter.collectibles--;
	if (str[y][x] == 'E')
		s->counter.exit--;
	if (str[y][x] == '1' || str[y][x] == 'X' || str[y][x] == 'E')
		return (1);
	str[y][x] = 'X';
	check_valid_path(y - 1, x, str, s);
	check_valid_path(y, x + 1, str, s);
	check_valid_path(y + 1, x, str, s);
	check_valid_path(y, x - 1, str, s);
	return (0);
}
