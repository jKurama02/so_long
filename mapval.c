/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapval.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:09:53 by anmedyns          #+#    #+#             */
/*   Updated: 2024/06/15 19:41:41 by anmedyns         ###   ########.fr       */
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
	map->len = (ft_strlen(fil) -1);
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
	for(i = 0; i < map->h; i++)
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