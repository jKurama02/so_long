/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapval.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:09:53 by anmedyns          #+#    #+#             */
/*   Updated: 2024/06/12 20:17:04 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int d_matrix(t_map *map)
{
	int fd;
	char *fil;
	char *fil_free;

	fd = open(map-> path, O_RDONLY);
	fil = get_next_line(fd);
	if(!fil)
		return(-1);
	map->len + ft_strlen(fil) -1;
	while(fil)
	{
		map->h++;
		fil_free = fil;
		fil = get_next_line(fd);
		free(fil_free);
	}
	free(fil);
	close(fd);
	return(1);
}

int	ft_argcheck(t_game *g)
{
	int	i;

	i = ft_strlen(g->map.path);
	if (g->map.path[i - 2] != 'e'
		|| g->map.path[i - 1] != 'r' || g->map.path[i - 3] != 'b'
		|| g->map.path[i - 4] != '.')
		{
			ft_printf("inserisci un *.ber");
			return (1);
		}
	return (0);
}
