/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:15:12 by anmedyns          #+#    #+#             */
/*   Updated: 2024/06/13 13:41:56 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int validate(t_game *g, char **argv)
{
	set_item(&(g->item));
	set_game(g,argv[1]);
	if(ft_argcheck(g))
		return(-1);
	d_matrix(&g->map);
	return (1);
}


