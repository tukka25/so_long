/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:19:46 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/11 16:31:18 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_and_exit(t_map *m)
{
	free_strings(m->map);
	ft_printf("put a valid map, loser!!");
	exit(1);
}

void	free_strings(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	check_rectangular(t_map *m)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	j = 0;
	k = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			j++;
		}
		if (j != m->width)
			free_and_exit(m);
		i++;
	}
}

void	check_map_contents(t_map *m, t_counter *c)
{
	m->i = 0;
	m->j = 0;
	c->collectibles = 0;
	c->exit = 0;
	c->player = 0;
	while (m->map[m->i])
	{
		m->j = 0;
		while (m->map[m->i][m->j])
		{
			if (m->map[m->i][m->j] == 'P')
				c->player++;
			else if (m->map[m->i][m->j] == 'E')
				c->exit++;
			else if (m->map[m->i][m->j] == 'C')
				c->collectibles++;
			m->j++;
		}
		m->i++;
	}
	if (c->player != 1 || c->exit != 1 || c->collectibles == 0)
		free_and_exit(m);
}

void	player_index(t_sl *s)
{
	s->map.i = 0;
	s->map.j = 0;
	s->map.p_index_x = 0;
	s->map.p_index_y = 0;
	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			if (s->map.map[s->map.i][s->map.j] == 'P')
				break ;
			s->map.j++;
			s->map.p_index_x++;
		}
		if (s->map.j != s->map.width)
			break ;
		s->map.i++;
	}
	s->map.p_index_x = s->map.j;
	s->map.p_index_y = s->map.i;
}
