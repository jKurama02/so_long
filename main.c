/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:15:12 by anmedyns          #+#    #+#             */
/*   Updated: 2024/06/21 19:14:51 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int validate(t_game *g, char **argv)
{
	set_item(&(g->item));
	set_game(g,argv[1]);
	if(ft_argcheck(g))
		return(-1);
	d_matrix(&g->map);
	matrice(&g->map);
	if(controllo_quadrato(*g) == -1)
		return(ft_printf("Errore controllo_quadrato \n"));
	if(controllo_oggetti(&g->map, &g->item) != -1)
		return(ft_printf("Errore controllo_oggetti \n"));
	if(percorso_ceck(*g) != 1)
		return(ft_printf("Errore percorso_ceck \n"));
	return(1);
}

int main(int argc, char **argv)
{
	t_game game;
	if(argc != 2)
		return(printf("error"));
	if(validate(&game, argv) != 1)
	{
		if(game.map.mat)
			free_matrix_c(game.map.mat);
		return(-1);
	}
	game.mlx = mlx_init();
	if(game.mlx == NULL)
		return (EXIT_FAILURE);
	game.win = mlx_new_window(game.mlx, game.map.len * RES, game.map.h * RES, "So_Long");
	img_init(&game);
	print_map(game);
	mlx_loop_hook();
}



