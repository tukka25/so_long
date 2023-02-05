/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:11:00 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/05 21:18:43 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_background(t_map *m, t_mlx *mlx, t_img *img)
{
	int		k = 0;
	int		c = 0;
	m->i = 0;
	m->j = 0;
	while (m->map[m->i])
	{
		m->j = 0;
		k = 0;
		while (m->map[m->i][m->j])
		{
			mlx->mlx_img = mlx_new_image(mlx->mlx, m->width * 64, m->height * 64);
			img->img = mlx_xpm_file_to_image(mlx->mlx, mlx->walls, &m->width, &m->height);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img, k, c);
			k = k + 64;
			m->j++;
		}
		m->i++;
		c = c + 64;
		// ft_printf("finished");
	}
	// ft_printf("finished");
	// mlx_loop(mlx->mlx);
}

void	put_player(t_map *m, t_mlx *mlx, t_img *img, char ch)
{
	int		k = 0;
	int		c = 0;
	m->i = 0;
	m->j = 0;
	mlx->background = "./photos/tt.xpm";
	while (m->map[m->i])
	{
		m->j = 0;
		k = 0;
		while (m->map[m->i][m->j])
		{
			if (m->map[m->i][m->j] == ch)
			{
				mlx->mlx_img = mlx_new_image(mlx->mlx, m->width * 64, m->height * 64);
				img->img = mlx_xpm_file_to_image(mlx->mlx, mlx->background, &m->width, &m->height);
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img, k, c);
			}
			k = k + 64;
			m->j++;
		}
		m->i++;
		c = c + 64;
		// ft_printf("finished");
	}
}

void	put_collectibles(t_map *m, t_mlx *mlx, t_img *img, char ch)
{
	int		k = 0;
	int		c = 0;
	m->i = 0;
	m->j = 0;
	mlx->background = "./photos/coins.xpm";
	while (m->map[m->i])
	{
		m->j = 0;
		k = 0;
		while (m->map[m->i][m->j])
		{
			if (m->map[m->i][m->j] == ch)
			{
				mlx->mlx_img = mlx_new_image(mlx->mlx, m->width * 64, m->height * 64);
				img->img = mlx_xpm_file_to_image(mlx->mlx, mlx->background, &m->width, &m->height);
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img, k, c);
			}
			k = k + 64;
			m->j++;
		}
		m->i++;
		c = c + 64;
		// ft_printf("finished");
	}
}

void	put_exit(t_map *m, t_mlx *mlx, t_img *img, char ch)
{
	int		k = 0;
	int		c = 0;
	m->i = 0;
	m->j = 0;
	mlx->background = "./photos/black-hole-2.xpm";
	while (m->map[m->i])
	{
		m->j = 0;
		k = 0;
		while (m->map[m->i][m->j])
		{
			if (m->map[m->i][m->j] == ch)
			{
				mlx->mlx_img = mlx_new_image(mlx->mlx, m->width * 64, m->height * 64);
				img->img = mlx_xpm_file_to_image(mlx->mlx, mlx->background, &m->width, &m->height);
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img, k, c);
			}
			k = k + 64;
			m->j++;
		}
		m->i++;
		c = c + 64;
		// ft_printf("finished");
	}
}

void	put_walls(t_map *m, t_mlx *mlx, t_img *img, char ch)
{
	int		k = 0;
	int		c = 0;
	m->i = 0;
	m->j = 0;
	mlx->background = "./photos/out.xpm";
	while (m->map[m->i])
	{
		m->j = 0;
		k = 0;
		while (m->map[m->i][m->j])
		{
			if (m->map[m->i][m->j] == ch)
			{
				mlx->mlx_img = mlx_new_image(mlx->mlx, m->width * 64, m->height * 64);
				img->img = mlx_xpm_file_to_image(mlx->mlx, mlx->background, &m->width, &m->height);
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img, k, c);
			}
			k = k + 64;
			m->j++;
		}
		m->i++;
		c = c + 64;
		// ft_printf("finished");
	}
}
