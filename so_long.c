/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:10:07 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/05 23:07:14 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	int			i;
	t_map		m;
	t_mlx		mlx;
	t_counter	c;
	t_img		img;
	char		**str;

	i = 0;
	str = NULL;
	// mlx.background = "./photos/image.xpm";
	mlx.walls = "./photos/ground.xpm";
	if (ac == 2)
	{
		check_map(av, &m, &c);
		mlx.mlx = mlx_init();
		mlx.mlx_win = mlx_new_window(mlx.mlx, m.width * 64, m.height * 64, "so_long");
		mlx_key_hook(mlx.mlx_win, key_hook, &mlx);
		print_map(&m, &mlx, &img);
		// player_index(&m);
		// printf("p_index = %d\n", m.p_index);
		// exit(0);
	}
	exit(0);
}

void	print_map(t_map *m, t_mlx *mlx, t_img *img)
{
	put_background(m, mlx, img);
	put_player(m, mlx, img, 'P');
	put_collectibles(m, mlx, img, 'C');
	put_exit(m, mlx, img, 'E');
	put_walls(m, mlx, img, '1');
	mlx_loop(mlx->mlx);
}

void	pp(t_map *m, t_mlx *mlx, t_img *img)
{
	put_background(m, mlx, img);
	put_player(m, mlx, img, 'P');
	put_collectibles(m, mlx, img, 'C');
	put_exit(m, mlx, img, 'E');
	put_walls(m, mlx, img, '1');
}
