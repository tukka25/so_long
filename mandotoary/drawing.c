/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:11:00 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/20 13:16:22 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_background(t_sl *s)
{
	int		k;
	int		c;

	s->map.i = 0;
	s->map.j = 0;
	k = 0;
	c = 0;
	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		k = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			s->img.img = mlx_xpm_file_to_image(s->mlx.mlx, s->mlx.background,
					&s->map.width, &s->map.height);
			mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win,
				s->img.img, k, c);
			k = k + 64;
			s->map.j++;
		}
		s->map.i++;
		c = c + 64;
	}
}

void	put_player(t_sl *s)
{
	int		k;
	int		c;

	s->map.i = 0;
	s->map.j = 0;
	k = 0;
	c = 0;
	mlx_clear_window(s->mlx.mlx, s->mlx.mlx_win);
	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		k = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			drawing_conditions(s, k, c);
			k = k + 64;
			s->map.j++;
		}
		s->map.i++;
		c = c + 64;
	}
}

void	put_player_r(t_sl *s)
{
	int		c;
	int		k;

	k = 0;
	c = 0;
	s->map.i = 0;
	s->map.j = 0;
	mlx_clear_window(s->mlx.mlx, s->mlx.mlx_win);
	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		k = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			drawing_conditions(s, k, c);
			k = k + 64;
			s->map.j++;
		}
		s->map.i++;
		c = c + 64;
	}
}
