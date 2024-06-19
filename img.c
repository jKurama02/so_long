/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:15:12 by anmedyns          #+#    #+#             */
/*   Updated: 2024/06/19 19:01:14 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int img_init(t_game *g)
{
	int dmx;

	dmx = 128;
	g->map.wall.img = mlx_xpm_file_to_image(g->mlx, "xpm/1.xpm", &dmx, &dmx);
	g->map.coin.img = mlx_xpm_file_to_image(g->mlx, "xpm/C.xpm", &dmx, &dmx);
	g->map.bg.img = mlx_xpm_file_to_image(g->mlx, "xpm/0.xpm", &dmx, &dmx);
	g->map.player.img= mlx_xpm_file_to_image(g->mlx, "xpm/P.xpm", &dmx, &dmx);
	g->map.exit.img = mlx_xpm_file_to_image(g->mlx, "xpm/E.xpm", &dmx, &dmx);
}
