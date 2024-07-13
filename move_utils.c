/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:47:27 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/13 09:24:03 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"

// void	move_up(t_game *game)
// {
// 	mlx_delete_image(game->mlx, game->assets.terrain);
// 	mlx_delete_image(game->mlx, game->assets.wall);
// 	mlx_delete_image(game->mlx, game->assets.lumberjack);
// 	mlx_delete_image(game->mlx, game->assets.hut);
// 	mlx_delete_image(game->mlx, game->assets.tree);
// 	// under construction
// 	game->map[game->posx][game->posy] = '0';
// 	game->map[game->posx][game->posy - 1] = 'P';

// 	game->assets.terrain = ft_asset_to_image(game->mlx,
// 			"./temp/terrain.xpm42");
// 	game->assets.wall = ft_asset_to_image(game->mlx, "./temp/tree2.xpm42");
// 	game->assets.lumberjack = ft_asset_to_image(game->mlx,
// 			"./temp/lumberjack.xpm42");
// 	game->assets.hut = ft_asset_to_image(game->mlx, "./temp/hut.xpm42");
// 	game->assets.tree = ft_asset_to_image(game->mlx, "./temp/tree.xpm42");

// 	int y = 0;
// 	while (game->map[y])
// 	{
// 		for (int x = 0; x < game->mapwidth; x++)
// 		{
// 			if (mlx_image_to_window(game->mlx, game->assets.terrain, x
// 					* TILESIZE, y * TILESIZE) < 0)
// 				error_handling("Failed to put terrain image to window");

// 			if (game->map[y][x] == 'P' && mlx_image_to_window(game->mlx,
// 					game->assets.lumberjack, x * TILESIZE, y * TILESIZE) < 0)
// 				error_handling("Failed to put lumberjack image to window");
// 			if (game->map[y][x] == '1' && mlx_image_to_window(game->mlx,
// 					game->assets.wall, x * TILESIZE, y * TILESIZE) < 0)
// 				error_handling("Failed to put wall image to window");
// 			if (game->map[y][x] == 'C' && mlx_image_to_window(game->mlx,
// 					game->assets.tree, x * TILESIZE, y * TILESIZE) < 0)
// 				error_handling("Failed to put tree image to window");
// 			if (game->map[y][x] == 'E' && mlx_image_to_window(game->mlx,
// 					game->assets.hut, x * TILESIZE, y * TILESIZE) < 0)
// 				error_handling("Failed to put hut image to window");
// 		}
// 		y++;
// 	}
// 	puts("UP");
// }

void	move_up(t_game *game)
{
	mlx_delete_image(game->mlx, game->assets.lumberjack);
	// under construction
	game->map[game->posx][game->posy] = '0';
	game->map[game->posx][game->posy - 1] = 'P';
	ft_printf("%s",game->map[0]);
	ft_printf("%s",game->map[1]);
	ft_printf("%s",game->map[2]);
	ft_printf("%s",game->map[3]);
	ft_printf("%s",game->map[4]);

	game->assets.lumberjack = ft_asset_to_image(game->mlx,
			"./temp/lumberjack.xpm42");

	// if (game->map[y][x] == 'P' && mlx_image_to_window(game->mlx,
			// game->assets.lumberjack, x * TILESIZE, y * TILESIZE) < 0)
		puts("UP");
}