/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:15:12 by anmedyns          #+#    #+#             */
/*   Updated: 2024/06/24 20:16:42 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate(t_game *g, char **argv)
{
	set_item(&(g->item));
	set_game(g, argv[1]);
	if (ft_argcheck(g))
		return (-1);
	d_matrix(&g->map);
	matrice(&g->map);
	if (controllo_quadrato(*g) == -1)
		return (ft_printf("Errore controllo_quadrato \n"));
	if (controllo_oggetti(&g->map, &g->item) != 1)
		return (ft_printf("Errore controllo_oggetti \n"));
	if (percorso_ceck(*g) != 1)
		return (ft_printf("Errore percorso_ceck \n"));
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("give 2 argument, ty \n");
		return (-1);
	}
	if (validate(&game, argv) != 1)
	{
		if (game.map.mat)
			free_matrix_c(game.map.mat);
		return (-1);
	}
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (EXIT_FAILURE);
	game.win = mlx_new_window(game.mlx, game.map.len * RES,
			(game.map.h) * RES, "So_Long");
	img_init(&game);
	print_map(game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 1L << 0, ft_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}

int	ft_numlen(long int i)
{
	int	j;

	j = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i *= -1;
		j++;
	}
	while (i > 0)
	{
		i /= 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			l;
	int			j;

	nb = (long int) n;
	l = ft_numlen(nb);
	j = -1 ;
	str = (char *)malloc((sizeof(char) * (l + 1)));
	if (!str)
		return (0);
	str[l--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
		j = 0;
	}
	while (l > j)
	{
		str[l] = 48 + (nb % 10);
		nb = nb / 10;
		l--;
	}
	return (str);
}
