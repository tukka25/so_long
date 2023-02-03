/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:50:51 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/03 16:18:04 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**check_map(char *av[])
{
	t_map	m;
	int		fd;
	int		j;

	m.height = 0;
	m.map = NULL;
	j = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit(0);
	lines_counter(&m, fd);
	insert_map(&m, av);
	ft_printf("height = %d\n", m.height);
	while (m.map[j])
	{
		ft_printf("map = %s\n", m.map[j]);
		j++;
	}
	count_wid(&m);
	ft_printf("width = %d", m.width);
	exit(0);
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
