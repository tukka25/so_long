/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:11:00 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/20 13:21:58 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_background(t_sl *s)
{
	int		k;
	int		c;

	c = 25;
	k = 25;
	s->map.i = 0;
	s->map.j = 0;
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

	k = 25;
	c = 25;
	s->map.i = 0;
	s->map.j = 0;
	mlx_clear_window(s->mlx.mlx, s->mlx.mlx_win);
	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		k = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			printing_conditions(s, k, c);
			k = k + 64;
			s->map.j++;
		}
		s->map.i++;
		c = c + 64;
	}
}

void	put_player_r(t_sl *s)
{
	int		k;
	int		c;

	k = 25;
	c = 25;
	s->map.i = 0;
	s->map.j = 0;
	mlx_clear_window(s->mlx.mlx, s->mlx.mlx_win);
	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		k = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			printing_conditions(s, k, c);
			k = k + 64;
			s->map.j++;
		}
		s->map.i++;
		c = c + 64;
	}
}

void	animation(t_sl *s)
{
	int		k;
	int		c;

	k = 25;
	c = 25;
	s->map.i = 0;
	s->map.j = 0;
	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		k = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			animation_conditions(s, k, c);
			k = k + 64;
			s->map.j++;
		}
		s->map.i++;
		c = c + 64;
	}
	printing_moves(s);
}
