/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:56:27 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/19 21:30:53 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_conditions(t_counter *c, t_map *m, int i, int j)
{
	if (m->map[i][j] == 'P')
		c->player++;
	else if (m->map[i][j] == 'E')
		c->exit++;
	else if (m->map[i][j] == 'C')
		c->collectibles++;
	else if (m->map[i][j] == 'D')
		c->demons++;
	else if (!(m->map[m->i][m->j] == '1' || m->map[m->i][m->j] == '0'))
		free_and_exit(m);
}

void	last_photo(t_sl *s)
{
	s->map.i = 0;
	s->map.j = 0;
	s->counter.st = strr_i(s->counter.moves + 1);
	s->counter.moves++;
	ft_printf("You Won!!\n");
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
