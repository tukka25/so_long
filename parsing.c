/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:50:51 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/06 20:19:36 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char *av[], t_sl *s)
{
	int		fd;
	int		j;

	s->map.height = 0;
	s->map.map = NULL;
	j = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit(0);
	lines_counter(&s->map, fd);
	insert_map(&s->map, av);
	ft_printf("height = %d\n", s->map.height);
	while (s->map.map[j])
	{
		ft_printf("map = %s\n", s->map.map[j]);
		j++;
	}
	count_wid(&s->map);
	check_the_edges(&s->map);
	check_rectangular(&s->map);
	check_map_contents(&s->map, &s->counter);
	// valid_path(m, c);
}

void	lines_counter(t_map *m, int fd)
{
	m->map_count = get_next_line(fd);
	while (m->map_count)
	{
		m->height++;
		m->map_count = get_next_line(fd);
	}
	close(fd);
	if (m->height == 0)
	{
		ft_printf("put map, loser!!");
		exit(1);
	}
}

void	insert_map(t_map *m, char *av[])
{
	int		j;
	int		fd;

	j = 0;
	fd = open(av[1], O_RDONLY);
	m->map = malloc((m->height + 1) * sizeof(char *));
	m->map_count = get_next_line(fd);
	while (m->map_count)
	{
		m->map[j] = ft_substr(m->map_count, 0, cut_nl(m->map_count));
		free(m->map_count);
		m->map_count = get_next_line(fd);
		j++;
	}
	m->map[j] = NULL;
	close(fd);
}

void	count_wid(t_map *m)
{
	int		i;
	int		j;

	m->width = 0;
	i = 0;
	j = 0;
	while (m->map[0][j])
	{
		m->width++;
		j++;
	}
}

void	check_the_edges(t_map *m)
{
	m->i = 0;
	m->j = 0;
	while (m->map[0][m->j] && m->map[0][m->j] == '1')
		m->j++;
	if (m->j > 0)
		m->j--;
	if (m->map[0][m->j] != '1' || m->j + 1 != m->width)
		free_and_exit(m);
	m->j = 0;
	m->i = 1;
	while (m->map[m->i])
	{
		m->j = 0;
		while (m->map[m->i][m->j])
		{
			if (m->j == 0 || m->j == m->width - 1 || m->i == m->height - 1)
			{
				if (m->map[m->i][m->j] != '1')
					free_and_exit(m);
			}
			m->j++;
		}
		m->i++;
	}
}
