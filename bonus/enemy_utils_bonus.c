/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:17:28 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/19 18:57:42 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	demons_count(t_sl *s)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	s->counter.d_count = 0;
	while (s->map.map[i])
	{
		j = 0;
		while (s->map.map[i][j])
		{
			if (s->map.map[i][j] == 'D')
				s->counter.d_count++;
			j++;
		}
		i++;
	}
}

void	fill_array(t_sl *s)
{
	int		count;

	demons_count(s);
	s->map.i = 0;
	count = 0;
	s->map.j = 0;
	s->map.d_array = malloc((s->counter.d_count * 2 + 1) * sizeof(int));
	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			if (s->map.map[s->map.i][s->map.j] == 'D')
			{
				s->map.d_array[count] = s->map.i;
				s->map.d_array[count + 1] = s->map.j;
				count += 2;
			}
			s->map.j++;
		}
		s->map.i++;
	}
	s->map.d_array[count] = 0;
}

void	check_if_exit(t_sl *s, int y, int x)
{
	if ((s->map.map[y][x] == 'E'
		&& s->counter.collectibles == 0)
		|| s->map.map[y][x] == 'D')
	{
		if (s->map.map[y][x] == 'D')
		{
			ft_printf("looooser\n");
			free_and_destory(s);
		}
		last_photo(s);
	}
}

void	map_handle(char *str, int fd)
{
	if (fd == -1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (ft_strncmp(str, ".ber", 4) == 0)
		ft_printf("valid map name\n");
	else
	{
		ft_printf("Dont play with me, put a valid map name\n");
		exit(1);
	}
}
