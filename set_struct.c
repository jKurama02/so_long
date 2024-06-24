/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:31:27 by anmedyns          #+#    #+#             */
/*   Updated: 2024/06/24 20:20:52 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_game(t_game *game, char *path)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map.path = path;
	game->map.copy = NULL;
	game->map.mat = NULL;
	game->map.h = 0;
	game->map.len = 0;
	game->w = 0;
	game->h = 0;
	game->nmoves = 0;
	game->loop = 0;
	game->aux_rand = 0;
	return (1);
}

void	set_item(t_item *item)
{
	item->c = 0;
	item->e = 0;
	item->p = 0;
}
