/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:19:46 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/04 18:28:35 by abdamoha         ###   ########.fr       */
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
	if (c->player > 1 || c->exit > 1 || c->collectibles == 0)
		free_and_exit(m);
}

void	valid_path(t_map *m, t_counter *c)
{
	ft_printf("m = %d\n", m->height);
	ft_printf("c = %d\n", c->collectibles);
	ft_printf("e = %d\n", c->exit);
	ft_printf("p = %d\n", c->player);
}
