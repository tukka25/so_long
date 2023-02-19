/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:19:35 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/19 17:06:39 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_handle(char *str, int fd)
{
	int		i;

	i = 0;
	if (fd == -1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (ft_strncmp(str, ".ber", 4) == 0)
		ft_printf("valid map name\n");
	else
	{
		ft_printf("Dont play with me, put a valid map name\n");
		exit(1);
	}
}
