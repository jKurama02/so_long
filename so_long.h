/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:55:47 by anmedyns          #+#    #+#             */
/*   Updated: 2024/06/25 17:14:51 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RES 128

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
	t_dim	player;
	t_dim	exit;
	t_dim	coin;
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
void	matrice(t_map *map);
int controllo_quadrato(t_game g);
int validate(t_game *g, char **argv);
int set_game(t_game *game,char *path);
void set_item(t_item *item);
int controllo_oggetti(t_map *map, t_item *item);
int letter_c(t_map *map, int x, int y, t_item *item);
void free_matrix_c(char **matrix);
int percorso_ceck(t_game g);
void percorso_fell(t_game *g, int x, int y);
char **c_mat(t_game g);
void print_map(t_game g);
void *take_item(t_game game, char c);
int img_init(t_game *g);
int ft_exit(t_game *g);
int check_next_move(t_game *g, int y, int x);
int key_press(int key, t_game *game);
int w_m(t_game *game);
int a_m(t_game *game);
int s_m(t_game *game);
int d_m(t_game *game);
int	ft_numlen(long int i);
char	*ft_itoa(int n);


#endif
