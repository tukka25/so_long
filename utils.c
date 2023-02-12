/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:11:40 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/12 19:37:27 by abdamoha         ###   ########.fr       */
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
	int	i;

	i = 64;
	s->img.img = mlx_xpm_file_to_image(s->mlx.mlx, "./photos/ground.xpm", &i, &i);
	s->img.p_img = mlx_xpm_file_to_image(s->mlx.mlx, "./photos/tt.xpm", &i, &i);
	s->img.e_img = mlx_xpm_file_to_image(s->mlx.mlx, "./photos/black-hole-2.xpm", &i, &i);
	s->img.w_img = mlx_xpm_file_to_image(s->mlx.mlx,  "./photos/out.xpm", &i, &i);
	s->img.c_img = mlx_xpm_file_to_image(s->mlx.mlx, "./photos/coins.xpm", &i, &i);
	s->img.p2_img = mlx_xpm_file_to_image(s->mlx.mlx, "./photos/tl.xpm", &i, &i);
	if (s->img.img == NULL || s->img.p_img == NULL || s->img.e_img == NULL || s->img.w_img == NULL || s->img.c_img == NULL || s->img.p2_img == NULL)
		exit (1);
}

// void	valid_path(t_sl *s)
// {
// 	s->map.i = 0;
// 	s->map.j = 0;
// 	while (s->map.map[s->map.i])
// 	{
// 		s->map.j = 0;
// 		while (s->map.map[s->map.i][s->map.j])
// 		{
// 			if (s->map.map[s->map.i][s->map.j] == '1')
// 				break ;
// 			if (s->map.map[s->map.i][s->map.j] == 'C')
// 				s->counter.collectibles--;
// 			if (s->map.map[s->map.i][s->map.j] == 'E')
// 				s->counter.exit--;
// 			if (s->counter.collectibles == 0 && s->counter.exit == 0)
// 				return ;
// 			if (s->map.j == s->map.width)
// 			{
// 				s->map.i += 1;
// 				while (s->map.map[s->map.i][s->map.j])
// 				{
// 					if (s->map.map[s->map.i][s->map.j] == '1')
// 					{
// 						s->map.i += 1;
// 						while (s->map.map[s->map.i][s->map.j])
// 						{
// 							if (s->map.map[s->map.i][s->map.j] == '1')
// 							{
// 								s->map.i += 1;
// 								while (s->map.map[s->map.i][s->map.j])
// 								{
// 									if (s->map.map[s->map.i][s->map.j] == '1')
// 										break ;
// 									if (s->map.map[s->map.i][s->map.j] == 'C')
// 										s->counter.collectibles--;
// 									if (s->map.map[s->map.i][s->map.j] == 'E')
// 										s->counter.exit--;
// 									if (s->counter.collectibles == 0 && s->counter.exit == 0)
// 										return ;
// 									s->map.j--;
// 								}
// 							}
// 							s->map.j--;
// 						}
// 							s->map.j--;
// 					}
// 					s->map.j--;
// 				}
// 			}
// 			s->map.j++;
// 		}
// 	}
// 	if (s->counter.collectibles != 0 && s->counter.exit != 0)
// 	{
// 		ft_printf("not a valid path");
// 		exit(0);
// 	}
// }
