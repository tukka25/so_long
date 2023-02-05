/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:23:37 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/05 23:08:01 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_mlx *mlx, t_map *m, t_img *img)
{
	static int	i;
	(void)mlx;
	// (void)keycode;
	i++;
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
	{
		if (keycode == 124)
		{
			move_player(m);
			mlx_destroy_image(mlx->mlx, img->img);
			pp(m, mlx, img);
		}
		ft_printf("total moves = %d\n", i);
	}
	return (0);
}

void	move_player(t_map *m)
{
	m->i = 0;
	m->j = 0;
	while (m->map[m->i])
	{
		m->j = 0;
		while (m->map[m->j])
		{
			if (m->map[m->i][m->j] == 'P')
			{
				m->map[m->i][m->j] = 0;
				m->map[m->i][m->j + 1] = 'P';
			}
			m->j++;
		}
		m->i++;
	}
}
