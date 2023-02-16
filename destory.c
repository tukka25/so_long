/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:57:16 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/15 17:08:35 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_and_destory(t_sl *s)
{
	free_strings(s->map.map);
	mlx_destroy_image(s->mlx.mlx, s->img.img);
	mlx_destroy_image(s->mlx.mlx, s->img.p_img);
	mlx_destroy_image(s->mlx.mlx, s->img.e_img);
	mlx_destroy_image(s->mlx.mlx, s->img.w_img);
	mlx_destroy_image(s->mlx.mlx, s->img.c_img);
	mlx_destroy_image(s->mlx.mlx, s->img.p2_img);
	mlx_destroy_image(s->mlx.mlx, s->img.d_img);
	mlx_destroy_window(s->mlx.mlx, s->mlx.mlx_win);
	exit(0);
}
