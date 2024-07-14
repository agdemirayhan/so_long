/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:47:27 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/14 09:42:53 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"

// void	move_up(t_game *game)
// {
// 	mlx_delete_image(game2->mlx, game2->assets.terrain);
// 	mlx_delete_image(game2->mlx, game2->assets.wall);
// 	mlx_delete_image(game2->mlx, game2->assets.lumberjack);
// 	mlx_delete_image(game2->mlx, game2->assets.hut);
// 	mlx_delete_image(game2->mlx, game2->assets.tree);
// 	// under construction
// 	game2->map[game2->posx][game2->posy] = '0';
// 	game2->map[game2->posx][game2->posy - 1] = 'P';

// 	game2->assets.terrain = ft_asset_to_image(game2->mlx,
// 			"./temp/terrain.xpm42");
// 	game2->assets.wall = ft_asset_to_image(game2->mlx, "./temp/tree2.xpm42");
// 	game2->assets.lumberjack = ft_asset_to_image(game2->mlx,
// 			"./temp/lumberjack.xpm42");
// 	game2->assets.hut = ft_asset_to_image(game2->mlx, "./temp/hut.xpm42");
// 	game2->assets.tree = ft_asset_to_image(game2->mlx, "./temp/tree.xpm42");

// 	int y = 0;
// 	while (game2->map[y])
// 	{
// 		for (int x = 0; x < game2->mapwidth; x++)
// 		{
// 			if (mlx_image_to_window(game2->mlx, game2->assets.terrain, x
// 					* TILESIZE, y * TILESIZE) < 0)
// 				error_handling("Failed to put terrain image to window");

// 			if (game2->map[y][x] == 'P' && mlx_image_to_window(game2->mlx,
// 					game2->assets.lumberjack, x * TILESIZE, y * TILESIZE) < 0)
// 				error_handling("Failed to put lumberjack image to window");
// 			if (game2->map[y][x] == '1' && mlx_image_to_window(game2->mlx,
// 					game2->assets.wall, x * TILESIZE, y * TILESIZE) < 0)
// 				error_handling("Failed to put wall image to window");
// 			if (game2->map[y][x] == 'C' && mlx_image_to_window(game2->mlx,
// 					game2->assets.tree, x * TILESIZE, y * TILESIZE) < 0)
// 				error_handling("Failed to put tree image to window");
// 			if (game2->map[y][x] == 'E' && mlx_image_to_window(game2->mlx,
// 					game2->assets.hut, x * TILESIZE, y * TILESIZE) < 0)
// 				error_handling("Failed to put hut image to window");
// 		}
// 		y++;
// 	}
// 	puts("UP");
// }

void	move_up(t_game *game)
{
	t_game	*game2;

	game2 = game;
	printf("game2->map[game2->posx][game2->posy - 1]:%c\n",
		game2->map[game2->posx][game2->posy - 1]);
	if (game2->map[game2->posx][game2->posy - 1] != '1')
	{
		if (game2->assets.lumberjack)
			mlx_delete_image(game2->mlx, game2->assets.lumberjack);
		ft_printf("posx:%d\n", game2->posx);
		ft_printf("posy:%d\n", game2->posy);
		game2->map[game2->posx][game2->posy] = '0';
		game2->map[game2->posx][game2->posy - 1] = 'P';
		game2->posy -= 1;
		ft_printf("posx:%d\n", game2->posx);
		ft_printf("posy:%d\n", game2->posy);
		game2->assets.lumberjack = ft_asset_to_image(game2->mlx,
				"./temp/lumberjack.xpm42");
		if (!game2->assets.lumberjack)
		{
			// Handle error (e.g., print error message, exit, etc.)
			puts("Error loading image");
			return ;
		}
		mlx_image_to_window(game2->mlx, game2->assets.lumberjack, game2->posx
			* TILESIZE, game2->posy * TILESIZE);
		puts("UP");
	}
}

void	move_down(t_game *game)
{
	t_game	*game2;

	game2 = game;
	printf("game2->map[game2->posx][game2->posy + 1]:%c\n",
		game2->map[game2->posx][game2->posy + 1]);
	if (game2->map[game2->posx][game2->posy + 1] != '1')
	{
		if (game2->assets.lumberjack)
			mlx_delete_image(game2->mlx, game2->assets.lumberjack);
		ft_printf("posx:%d\n", game2->posx);
		ft_printf("posy:%d\n", game2->posy);
		game2->map[game2->posx][game2->posy] = '0';
		game2->map[game2->posx][game2->posy + 1] = 'P';
		game2->posy += 1;
		ft_printf("posx:%d\n", game2->posx);
		ft_printf("posy:%d\n", game2->posy);
		game2->assets.lumberjack = ft_asset_to_image(game2->mlx,
				"./temp/lumberjack.xpm42");
		if (!game2->assets.lumberjack)
		{
			// Handle error (e.g., print error message, exit, etc.)
			puts("Error loading image");
			return ;
		}
		mlx_image_to_window(game2->mlx, game2->assets.lumberjack, game2->posx
			* TILESIZE, game2->posy * TILESIZE);
		puts("UP");
	}
}

void	move_left(t_game *game)
{
	t_game	*game2;

	game2 = game;
	printf("game2->map[game2->posx - 1][game2->posy]:%c\n",
		game2->map[game2->posx - 1][game2->posy]);
	if (game2->map[game2->posx - 1][game2->posy] != '1')
	{
		if (game2->assets.lumberjack)
			mlx_delete_image(game2->mlx, game2->assets.lumberjack);
		ft_printf("posx:%d\n", game2->posx);
		ft_printf("posy:%d\n", game2->posy);
		game2->map[game2->posx][game2->posy] = '0';
		game2->map[game2->posx - 1][game2->posy] = 'P';
		game2->posx -= 1;
		ft_printf("posx:%d\n", game2->posx);
		ft_printf("posy:%d\n", game2->posy);
		game2->assets.lumberjack = ft_asset_to_image(game2->mlx,
				"./temp/lumberjack.xpm42");
		if (!game2->assets.lumberjack)
		{
			// Handle error (e.g., print error message, exit, etc.)
			puts("Error loading image");
			return ;
		}
		mlx_image_to_window(game2->mlx, game2->assets.lumberjack, game2->posx
			* TILESIZE, game2->posy * TILESIZE);
		puts("UP");
	}
}

void	move_right(t_game *game)
{
	t_game *game2;

	game2 = game;
	printf("game2->map[game2->posx + 1][game2->posy]:%c\n",
		game2->map[game2->posx + 1][game2->posy]);
	if (game2->map[game2->posx + 1][game2->posy] != '1')
	{
		if (game2->assets.lumberjack)
			mlx_delete_image(game2->mlx, game2->assets.lumberjack);

		ft_printf("posx:%d\n", game2->posx);
		ft_printf("posy:%d\n", game2->posy);

		game2->map[game2->posx][game2->posy] = '0';
		game2->map[game2->posx + 1][game2->posy] = 'P';
		game2->posx += 1;

		ft_printf("posx:%d\n", game2->posx);
		ft_printf("posy:%d\n", game2->posy);

		game2->assets.lumberjack = ft_asset_to_image(game2->mlx,
				"./temp/lumberjack.xpm42");
		if (!game2->assets.lumberjack)
		{
			// Handle error (e.g., print error message, exit, etc.)
			puts("Error loading image");
			return ;
		}

		mlx_image_to_window(game2->mlx, game2->assets.lumberjack, game2->posx
			* TILESIZE, game2->posy * TILESIZE);
		puts("UP");
	}
}