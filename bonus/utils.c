/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:11:40 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/18 15:59:08 by abdamoha         ###   ########.fr       */
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
	int		k;
	int		c;

	c = 0;
	k = 0;
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
				s->img.img = mlx_xpm_file_to_image(s->mlx.mlx, s->mlx.p_photo,
						&s->map.width, &s->map.height);
				mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.img, k, c);
			}
			k = k + 64;
			s->map.j++;
		}
		s->map.i++;
		c = c + 64;
	}
}

void	converting_xpm(t_sl *s)
{
	int	i;

	i = 64;
	s->img.img = mlx_xpm_file_to_image(s->mlx.mlx, "./photos/b2.xpm", &i, &i);
	s->img.p_img = mlx_xpm_file_to_image(s->mlx.mlx, "./photos/tt.xpm", &i, &i);
	s->img.e_img = mlx_xpm_file_to_image(s->mlx.mlx,
			"./photos/exit2.xpm", &i, &i);
	s->img.w_img = mlx_xpm_file_to_image(s->mlx.mlx,
			"./photos/out.xpm", &i, &i);
	s->img.c_img = mlx_xpm_file_to_image(s->mlx.mlx,
			"./photos/nez.xpm", &i, &i);
	s->img.p2_img = mlx_xpm_file_to_image(s->mlx.mlx,
			"./photos/tl.xpm", &i, &i);
	s->img.d_img = mlx_xpm_file_to_image(s->mlx.mlx,
			"./photos/ee2.xpm", &i, &i);
	s->img.c2_img = mlx_xpm_file_to_image(s->mlx.mlx,
			"./photos/nezuku2.xpm", &i, &i);
	s->img.l_img = mlx_xpm_file_to_image(s->mlx.mlx, "./photos/l3.xpm", &i, &i);
	if (s->img.img == NULL || s->img.p_img == NULL
		|| s->img.e_img == NULL || s->img.w_img == NULL
		|| s->img.c_img == NULL || s->img.p2_img == NULL
		|| s->img.d_img == NULL)
		free_and_destory(s);
}

void	valid_path(t_sl *s)
{
	int		i;
	int		j;

	i = 0;
	j = s->counter.collectibles;
	map_dup(s);
	ft_printf("\n\n");
	i = 0;
	i = check_valid_path(s->map.p_index_y, s->map.p_index_x, s->map.map_tmp, s);
	if (!(s->counter.collectibles <= 0 && s->counter.exit <= 0))
	{
		ft_printf("not valid");
		free_and_exit(&s->map);
	}
	free_strings(s->map.map_tmp);
	s->counter.collectibles = j;
	s->counter.exit = 1;
}
