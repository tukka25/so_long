/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:11:40 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/11 20:04:31 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cut_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	put_player_move(t_sl *s, char ch)
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
				s->img.img = mlx_xpm_file_to_image(s->mlx.mlx, s->mlx.p_photo, &s->map.width, &s->map.height);
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.img, k, c);
			}
			k = k + 64;
			s->map.j++;
		}
		s->map.i++;
		c = c + 64;
		// ft_printf("finished");
	}
}

void	converting_xpm(t_sl *s)
{
	s->img.img = mlx_xpm_file_to_image(s->mlx.mlx, s->mlx.background, &s->map.width, &s->map.height);
	s->img.p_img = mlx_xpm_file_to_image(s->mlx.mlx, s->mlx.p_photo, &s->map.width, &s->map.height);
	s->img.e_img = mlx_xpm_file_to_image(s->mlx.mlx, s->mlx.exit_photo, &s->map.width, &s->map.height);
	s->img.w_img = mlx_xpm_file_to_image(s->mlx.mlx, s->mlx.walls, &s->map.width, &s->map.height);
	s->img.c_img = mlx_xpm_file_to_image(s->mlx.mlx, s->mlx.c_photo, &s->map.width, &s->map.height);
}
