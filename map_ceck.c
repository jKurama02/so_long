/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ceck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:15:12 by anmedyns          #+#    #+#             */
/*   Updated: 2024/06/12 20:15:13 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "so_long.h"

int main(int argc, char **argv)
{
	t_game;
	if(argc != 2)
		return(printf("error"));
	if(validate(&game, **argv) != 1)
		return(printf("error"));


}

int validate(t_game *g, char **argv)
{
	set_item(&(g->item));
	set_game(g,argv[1]);
	if(ft_argcheck(g->map.path))
		return(-1);
	d_matrix(&g->map);
}


