/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:11:00 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/17 04:10:02 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_background(t_sl *s)
{
	int		k = 25;
	int		c = 25;
	s->map.i = 0;
	s->map.j = 0;
	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		k = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			s->img.img = mlx_xpm_file_to_image(s->mlx.mlx, s->mlx.background, &s->map.width, &s->map.height);
			mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.img, k, c);
			k = k + 64;
			s->map.j++;
		}
		s->map.i++;
		c = c + 64;
		// ft_printf("finished");
	}
}

void	put_player(t_sl *s, char ch)
{
	int		k = 25;
	int		c = 25;
	s->map.i = 0;
	s->map.j = 0;
	ch = 0;
	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		k = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			// s->img.img = mlx_xpm_file_to_image(s->mlx.mlx, s->mlx.background, &s->map.width, &s->map.height);
			mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.img, k, c);
			if (s->map.map[s->map.i][s->map.j] == 'P')
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.p_img, k, c);
			else if (s->map.map[s->map.i][s->map.j] == 'C')
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.c_img, k, c);
			else if (s->map.map[s->map.i][s->map.j] == 'E')
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.e_img, k, c);
			else if (s->map.map[s->map.i][s->map.j] == '1')
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.w_img, k, c);
			else if (s->map.map[s->map.i][s->map.j] == 'D')
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.d_img, k, c);
			k = k + 64;
			s->map.j++;
		}
		s->map.i++;
		c = c + 64;
		// ft_printf("finished");
	}
}

void	put_player_r(t_sl *s, char ch)
{
	int		k = 25;
	int		c = 25;
	s->map.i = 0;
	s->map.j = 0;
	ch = 0;
	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		k = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.img, k, c);
			if (s->map.map[s->map.i][s->map.j] == 'P')
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.p2_img, k, c);
			else if (s->map.map[s->map.i][s->map.j] == 'C')
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.c_img, k, c);
			else if (s->map.map[s->map.i][s->map.j] == 'E')
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.e_img, k, c);
			else if (s->map.map[s->map.i][s->map.j] == '1')
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.w_img, k, c);
			else if (s->map.map[s->map.i][s->map.j] == 'D')
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.d_img, k, c);
			k = k + 64;
			s->map.j++;
		}
		s->map.i++;
		c = c + 64;
		// ft_printf("finished");
	}
}

void	put_exit(t_sl *s, char ch)
{
	int		k = 0;
	int		c = 0;
	s->map.i = 0;
	s->map.j = 0;
	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		k = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			if (s->map.map[s->map.i][s->map.j] == ch)
			{
				s->img.img = mlx_xpm_file_to_image(s->mlx.mlx, s->mlx.exit_photo, &s->map.width, &s->map.height);
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.img, k, c);
			}
			k = k + 64;
			s->map.j++;
		}
		s->map.i++;
		c = c + 64;
	}
}

void	put_walls(t_sl *s, char ch)
{
	int		k = 0;
	int		c = 0;
	s->map.i = 0;
	s->map.j = 0;
	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		k = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			if (s->map.map[s->map.i][s->map.j] == ch)
			{
				s->img.img = mlx_xpm_file_to_image(s->mlx.mlx, s->mlx.walls, &s->map.width, &s->map.height);
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.img, k, c);
			}
			k = k + 64;
			s->map.j++;
		}
		s->map.i++;
		c = c + 64;
	}
}

void	animation(t_sl *s)
{
	int		k = 25;
	int		c = 25;
	int		n = 0x00000000;
	char	*line;
	s->map.i = 0;
	s->map.j = 0;

	while (s->map.map[s->map.i])
	{
		s->map.j = 0;
		k = 0;
		while (s->map.map[s->map.i][s->map.j])
		{
			mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.img, k, c);
			if (s->map.map[s->map.i][s->map.j] == 'P')
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.p_img, k, c);
			else if (s->map.map[s->map.i][s->map.j] == 'C')
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.c2_img, k, c);
			else if (s->map.map[s->map.i][s->map.j] == 'E')
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.e_img, k, c);
			else if (s->map.map[s->map.i][s->map.j] == '1')
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.w_img, k, c);
			else if (s->map.map[s->map.i][s->map.j] == 'D')
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.d_img, k, c);
			k = k + 64;
			s->map.j++;
		}
		s->map.i++;
		c = c + 64;
		// ft_printf("finished");
	}
	line = "-------------------";
	s->counter.st = strr_i(s->counter.moves);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 80, 76, n, line);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 78, 84, n, "|");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 84, 84, n, s->counter.st);
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 210, 84, n, "|");
	mlx_string_put(s->mlx.mlx, s->mlx.mlx_win, 82, 91, n, line);
}
