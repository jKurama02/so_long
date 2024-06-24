/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapval.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:09:53 by anmedyns          #+#    #+#             */
/*   Updated: 2024/06/24 18:34:03 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int d_matrix(t_map *map)
{
	int fd;
	char *fil;
	char *fil_free;

	fd = open(map->path, O_RDONLY);
	fil = get_next_line(fd);
	if(!fil)
		return(-1);
	map->len = (ft_strlen(fil) - 1);
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
	int	v;

	v = ft_strlen(g->map.path);
	if (g->map.path[v - 2] != 'e'
		|| g->map.path[v - 1] != 'r' || g->map.path[v - 3] != 'b'
		|| g->map.path[v - 4] != '.')
		{
			ft_printf("inserisci un *.ber");
			return (1);
		}
	return (0);
}

char **matrice(t_map *map)

{
	int i;
	int fd;
	char **matrix;

	i = -1;
	fd = open(map->path, O_RDONLY);
	if(fd == -1)
	{
		return NULL;
	}

	matrix = (char**)malloc(sizeof(char *) * (map->h + 1));
	if(!matrix)
	{
		close(fd);
		return (NULL);
	}
	i = 0;

	while(i < map->h)
	{
		matrix[i] = get_next_line(fd);
		if(!matrix)
		{
			while(i > 0)
				free(matrix[--i]);
			free(matrix);
			close(fd);
			return NULL;
		}
		i++;
	}
	matrix[map->h] = NULL;
	close(fd);
	map->mat = matrix;
	return(matrix);
}

int controllo_quadrato(t_game g)
{
	int p;
	int l;

	p = 0;
	l = (int)ft_strlen(g.map.mat[p]);

	while(p < g.map.h)
	{
		if((int)ft_strlen(g.map.mat[p]) != l)
		{
			return(-1);
		}
		p++;
	}
	return(1);
}

int controllo_oggetti(t_map *map, t_item *item)
{
	int x = 0;
	int y;

	while (x < map->len)
	{
		y = 0;
		while (y < map->h)
		{
			if ((x == 0 || x == map->len - 1 || y == 0 || y == map->h - 1) && map->mat[y][x] != '1') {
				return -1;
			}
			if (map->mat[y][x] != 'C' && map->mat[y][x] != 'E' && map->mat[y][x] != 'P' &&
				map->mat[y][x] != '1' && map->mat[y][x] != '0') {
				return -1;
			}
			letter_c(map, x, y, item);
			y++;
		}
		x++;
	}
	if (item->e != 1 || item->p != 1 || item->c < 1) {
		return -1;
	}
	return 1;
}
