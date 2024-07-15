/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:01:40 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/15 22:34:25 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	error_handling(char *str)
{
	ft_printf(str);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.map = get_map(argc, argv, &game);
	game.movecount = 0;
	game.status = INIT;
	game.mlx = mlx_init(TILESIZE * game.mapwidth, TILESIZE * game.mapheight,
			"Lumberjack", true);
	if (!game.mlx)
		error_handling("Failed to initialize mlx");
	put_image_in_map(&game);
	game.status = INGAME;
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_loop(game.mlx);
	clean_old_assets(&game);
	free_map(&game);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
