/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapval2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:09:53 by anmedyns          #+#    #+#             */
/*   Updated: 2024/06/19 13:33:46 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int letter_c(t_map *map, int x, int y, t_item *item)
{
	if(map->mat[y][x] == 'E')
		item->e++;
	else if(map->mat[y][x] == 'P')
	{
		item->p++;
		map->player->posx = x;
		map->player->posy = y;
	}
	else if(map->mat[y][x] == 'C')
		item->c++;
	return(1);
}
