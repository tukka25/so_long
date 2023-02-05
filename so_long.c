/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:10:07 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/05 14:18:06 by abdamoha         ###   ########.fr       */
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
	mlx.walls = "./photos/wall.xpm";
	if (ac == 2)
	{
		check_map(av, &m, &c);
		mlx.mlx = mlx_init();
		mlx.mlx_win = mlx_new_window(mlx.mlx, m.width * 64, m.height * 64, "so_long");
		// mlx.mlx_img = mlx_new_image(mlx.mlx, m.width * 64, m.height * 64);
		// img.img = mlx_xpm_file_to_image(mlx.mlx, mlx.walls, &m.width, &m.height);
		// mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);
		put_background(&m, &mlx, &img);
		// mlx_loop(mlx.mlx);
	}
	exit(0);
}
