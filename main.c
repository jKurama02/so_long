/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:15:12 by anmedyns          #+#    #+#             */
/*   Updated: 2024/06/14 17:34:45 by anmedyns         ###   ########.fr       */
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
	matrix(&g->map);
}

int main(int argc, char **argv)
{
	t_game game;
	if(argc != 2)
		return(printf("error"));
	if(validate(&game, argv) != 1)
	{
		printf("Error \n");
		return(-1);
	}
	return(0);
}



