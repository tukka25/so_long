/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:19:46 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/05 22:51:31 by abdamoha         ###   ########.fr       */
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

void	player_index(t_map *m)
{
	m->i = 0;
	m->j = 0;
	m->p_index = 0;
	while (m->map[m->i])
	{
		m->j = 0;
		while (m->map[m->i][m->j])
		{
			if (m->map[m->i][m->j] == 'P')
				break ;
			m->j++;
			m->p_index++;
		}
		if (m->j != m->width)
			break ;
		printf("i = %d", m->p_index);
		m->i++;
	}
}
