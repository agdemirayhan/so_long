/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:47:27 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/13 18:41:44 by aagdemir         ###   ########.fr       */
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
	if (game->map[game->posx][game->posy - 1] != '1')
	{
		if (game->assets.lumberjack)
			mlx_delete_image(game->mlx, game->assets.lumberjack);
		ft_printf("posx:%d\n", game->posx);
		ft_printf("posy:%d\n", game->posy);
		game->map[game->posx][game->posy] = '0';
		game->map[game->posx][game->posy - 1] = 'P';
		game->posy -= 1;
		ft_printf("posx:%d\n", game->posx);
		ft_printf("posy:%d\n", game->posy);
		game->assets.lumberjack = ft_asset_to_image(game->mlx,
				"./temp/lumberjack.xpm42");
		if (!game->assets.lumberjack)
		{
			// Handle error (e.g., print error message, exit, etc.)
			puts("Error loading image");
			return ;
		}
		mlx_image_to_window(game->mlx, game->assets.lumberjack, game->posx
			* TILESIZE, game->posy * TILESIZE);
		puts("UP");
	}
}

void	move_down(t_game *game)
{
	printf("height:%d\nposx:%d\nposy:%d",game->mapheight,game->posx,game->posy);
	if (game->map[game->posx][game->posy + 1] != '1')
	{
		if (game->assets.lumberjack)
			mlx_delete_image(game->mlx, game->assets.lumberjack);
		ft_printf("posx:%d\n", game->posx);
		ft_printf("posy:%d\n", game->posy);
		game->map[game->posx][game->posy] = '0';
		game->map[game->posx][game->posy + 1] = 'P';
		game->posy += 1;
		ft_printf("posx:%d\n", game->posx);
		ft_printf("posy:%d\n", game->posy);
		game->assets.lumberjack = ft_asset_to_image(game->mlx,
				"./temp/lumberjack.xpm42");
		if (!game->assets.lumberjack)
		{
			// Handle error (e.g., print error message, exit, etc.)
			puts("Error loading image");
			return ;
		}
		mlx_image_to_window(game->mlx, game->assets.lumberjack, game->posx
			* TILESIZE, game->posy * TILESIZE);
		puts("UP");
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->posx - 1][game->posy] != '1')
	{
		if (game->assets.lumberjack)
			mlx_delete_image(game->mlx, game->assets.lumberjack);
		ft_printf("posx:%d\n", game->posx);
		ft_printf("posy:%d\n", game->posy);
		game->map[game->posx][game->posy] = '0';
		game->map[game->posx - 1][game->posy] = 'P';
		game->posx -= 1;
		ft_printf("posx:%d\n", game->posx);
		ft_printf("posy:%d\n", game->posy);
		game->assets.lumberjack = ft_asset_to_image(game->mlx,
				"./temp/lumberjack.xpm42");
		if (!game->assets.lumberjack)
		{
			// Handle error (e.g., print error message, exit, etc.)
			puts("Error loading image");
			return ;
		}
		mlx_image_to_window(game->mlx, game->assets.lumberjack, game->posx
			* TILESIZE, game->posy * TILESIZE);
		puts("UP");
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->posx + 1][game->posy] != '1')
	{
		if (game->assets.lumberjack)
			mlx_delete_image(game->mlx, game->assets.lumberjack);

		ft_printf("posx:%d\n", game->posx);
		ft_printf("posy:%d\n", game->posy);

		game->map[game->posx][game->posy] = '0';
		game->map[game->posx + 1][game->posy] = 'P';
		game->posx += 1;

		ft_printf("posx:%d\n", game->posx);
		ft_printf("posy:%d\n", game->posy);

		game->assets.lumberjack = ft_asset_to_image(game->mlx,
				"./temp/lumberjack.xpm42");
		if (!game->assets.lumberjack)
		{
			// Handle error (e.g., print error message, exit, etc.)
			puts("Error loading image");
			return ;
		}

		mlx_image_to_window(game->mlx, game->assets.lumberjack, game->posx
			* TILESIZE, game->posy * TILESIZE);
		puts("UP");
	}
}