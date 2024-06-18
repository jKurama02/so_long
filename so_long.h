/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:55:47 by anmedyns          #+#    #+#             */
/*   Updated: 2024/06/17 19:15:41 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RES 64

# include "printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"


typedef struct s_item
{
	int	c;
	int e;
	int p;
}			t_item;

typedef struct s_dim
{
	void *img;
	char type;
	int	posx;
	int	posy;
}			t_dim;

typedef struct s_map
{
	int		t_h;
	int		t_w;
	char	**mat;
	char	**copy;
	char	*path;
	int		h;
	int		len;
	t_dim	player[4];
	t_dim	player_to_print;
	t_dim	exit;
	t_dim	coin;
	t_dim	enemy[2];
	int		enemy_to_print;
	t_dim	wall;
	t_dim	bg;
}				t_map;
typedef struct s_game
{
	t_item	item;
	void	*mlx;
	void	*win;
	t_map	map;
	int		w;
	int		h;
	int		nmoves;
	int		loop;
	int		aux_rand;
}				t_game;

int controllo_quadrato(t_game g);
int d_matrix(t_map *map);
int	ft_argcheck(t_game *g);
char **matrice(t_map *map);
int controllo_quadrato(t_game g);
int validate(t_game *g, char **argv);
int set_game(t_game *game,char *path);
void set_item(t_item *item);
int controllo_oggetti(t_map *map, t_item *item);
int letter_c(t_map *map, int x, int y, t_item *item);






#endif
