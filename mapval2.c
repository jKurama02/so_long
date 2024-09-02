/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapval2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:09:53 by anmedyns          #+#    #+#             */
/*   Updated: 2024/09/02 19:14:37 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	letter_c(t_map *map, int x, int y, t_item *item)
{
	if (map->mat[y][x] == 'E')
		item->e++;
	else if (map->mat[y][x] == 'P')
	{
		item->p++;
		map->player.posx = x;
		map->player.posy = y;
	}
	else if (map->mat[y][x] == 'C')
		item->c++;
	return (1);
}

char	**c_mat(t_game g)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)malloc(sizeof(char *) *(g.map.h + 1));
	if (!copy)
		return (NULL);
	copy[g.map.h] = NULL;
	while (i < g.map.h)
	{
		copy[i] = ft_strdup(g.map.mat[i]);
		i++;
	}
	return (copy);
}

void	percorso_fell(t_game *g, int y, int x)
{
	g->map.copy[y][x] = '1';
	if (g->map.copy[y +1][x] != '1')
		percorso_fell(g, y + 1, x);
	if (g->map.copy[y - 1][x] != '1')
		percorso_fell(g, y - 1, x);
	if (g->map.copy[y][x + 1] != '1')
		percorso_fell(g, y, x + 1);
	if (g->map.copy[y][x - 1] != '1')
		percorso_fell(g, y, x - 1);
}

int	percorso_ceck(t_game g)
{
	int	y;

	y = 0;
	g.map.copy = c_mat(g);
	percorso_fell(&g, g.map.player.posy, g.map.player.posx);
	while (y < g.map.h)
	{
		if (strchr(g.map.copy[y], 'C') != 0)
		{
			free_matrix_c(g.map.copy);
			free_matrix_c(g.map.mat);
			return (-1);
		}
		if (strchr(g.map.copy[y], 'E') != 0)
		{
			free_matrix_c(g.map.copy);
			free_matrix_c(g.map.mat);
			return (-1);
		}
		y++;
	}
	free_matrix_c(g.map.copy);
	return (1);
}

void	free_matrix_c(char **matrix)
{
	int	g;

	g = 0;
	if (matrix == NULL)
		return ;
	while (matrix[g])
	{
		free(matrix[g]);
		g++;
	}
	free(matrix);
}
