/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:15:12 by anmedyns          #+#    #+#             */
/*   Updated: 2024/06/23 19:45:53 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_press(int key, t_game *game)
{
	if(key == 65307)
		ft_exit(game);
	else if(key == 119)
		game->nmoves += w_m(game);
	else if(key == 100)
		game->nmoves += d_m(game);
	else if(key == 97)
		game->nmoves += a_m(game);
	else if(key == 115)
		game->nmoves += s_m(game);
	print_map(*game);
	return(0);
}

int w_m(t_game *game)
{
	int y;
	int x;

	y = game->map.player.posy;
	x = game->map.player.posx;
	if(game->map.mat[y - 1][x] != '1' && check_next_move(game, (y -1), x))
	{
		game->map.mat[y][x] = '0';
		y = (game->map.player.posy - 1);
		game->map.player.posy = y;
		game->map.mat[y][x] = 'P';
		return(1);
	}
	return(0);
}

int d_m(t_game *game)
{
	int y;
	int x;

	y = game->map.player.posy;
	x = game->map.player.posx;
	if(game->map.mat[y][x + 1] != '1' && check_next_move(game, y, (x + 1)))
	{
		game->map.mat[y][x] = '0';
		x = (game->map.player.posx + 1);
		game->map.player.posx = x;
		game->map.mat[y][x] = 'P';
		return(1);
	}
	return(0);
}

int a_m(t_game *game)
{
	int y;
	int x;

	y = game->map.player.posy;
	x = game->map.player.posx;
	if(game->map.mat[y][x - 1] != '1' && check_next_move(game, y, (x - 1)))
	{
		game->map.mat[y][x] = '0';
		x = (game->map.player.posx - 1);
		game->map.player.posx = x;
		game->map.mat[y][x] = 'P';
		return(1);
	}
	return(0);
}

int s_m(t_game *game)
{
	int y;
	int x;

	y = game->map.player.posy;
	x = game->map.player.posx;
	if(game->map.mat[y + 1][x] != '1' && check_next_move(game, (y + 1), x))
	{
		game->map.mat[y][x] = '0';
		y = (game->map.player.posy + 1);
		game->map.player.posy = y;
		game->map.mat[y][x] = 'P';
		return(1);
	}
	return(0);
}
