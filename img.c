/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:15:12 by anmedyns          #+#    #+#             */
/*   Updated: 2024/06/24 20:13:16 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_game g)
{
	int		x;
	int		y;
	char	*str;

	y = 0;
	while (y < g.map.h)
	{
		x = 0;
		while (x < g.map.len)
		{
			mlx_put_image_to_window(g.mlx, g.win,
				take_item(g, g.map.mat[y][x]), x * 128, y * 128);
			x++;
		}
		y++;
	}
	str = ft_itoa(g.nmoves);
	mlx_string_put(g.mlx, g.win, 128, 128, INT_MAX, str);
	free(str);
}

void	*take_item(t_game game, char c)
{
	if (c == '1')
		return (game.map.wall.img);
	if (c == '0')
		return (game.map.bg.img);
	if (c == 'E')
		return (game.map.exit.img);
	if (c == 'P')
		return (game.map.player.img);
	if (c == 'C')
		return (game.map.coin.img);
	else
		return (NULL);
}

int	img_init(t_game *g)
{
	int	dmx;

	dmx = 128;
	g->map.wall.img = mlx_xpm_file_to_image(g->mlx, "xpm/1.xpm", &dmx, &dmx);
	g->map.coin.img = mlx_xpm_file_to_image(g->mlx, "xpm/C.xpm", &dmx, &dmx);
	g->map.bg.img = mlx_xpm_file_to_image(g->mlx, "xpm/0.xpm", &dmx, &dmx);
	g->map.player.img = mlx_xpm_file_to_image(g->mlx, "xpm/P.xpm", &dmx, &dmx);
	g->map.exit.img = mlx_xpm_file_to_image(g->mlx, "xpm/E.xpm", &dmx, &dmx);
	return (0);
}

int	ft_exit(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit (0);
	return (0);
}

int	check_next_move(t_game *g, int y, int x)
{
	char	**mat;

	mat = g->map.mat;
	if (mat[y][x] == 'C')
	{
		g->item.c--;
	}
	else if (mat[y][x] == 'E')
	{
		if (g->item.c == 0)
			ft_exit(g);
		else
			return (0);
	}
	return (1);
}
