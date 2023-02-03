/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:10:11 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/03 16:16:48 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_map
{
	int		height;
	int		width;
	char	*map_count;
	char	**map;
}	t_map;
char		**check_map(char *av[]);
void		lines_counter(t_map *m, int fd);
void		insert_map(t_map *m, char *av[]);
int			cut_nl(char *str);
void		count_wid(t_map *m);
#endif