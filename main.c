/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:01:40 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/06 15:00:17 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "so_long.h"
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>

// #define WIDTH 1024
// #define HEIGHT 1024
// #include "MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define WIDTH 1280
#define HEIGHT 720

static mlx_image_t	*image;

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_randomize(void *param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(rand() % 0xFF, // R
										rand() % 0xFF, // G
										rand() % 0xFF, // B
										rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");
	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");
	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
}

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

mlx_image_t	*ft_asset_to_image(mlx_t *mlx, char *img_path)
{
	xpm_t		*xpm;
	mlx_image_t	*img;

	// Try to load the file
	xpm = mlx_load_xpm42(img_path);
	if (!xpm)
		error();
	// Convert texture to a displayable image
	img = mlx_texture_to_image(mlx, &xpm->texture);
	if (!img)
		error();
	// Clean up the xpm structure after conversion
	mlx_delete_xpm42(xpm);
	return (img);
}

int32_t	main(void)
{
	t_game game;

	// Initialize MLX
	game.mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!game.mlx)
		error();

	// Load the terrain, wall, and lumberjack images
	game.assets.terrain = ft_asset_to_image(game.mlx, "./temp/terrain.xpm42");
	game.assets.wall = ft_asset_to_image(game.mlx, "./temp/tree2.xpm42");
	game.assets.lumberjack = ft_asset_to_image(game.mlx,
			"./temp/lumberjack.xpm42");
	game.assets.hut = ft_asset_to_image(game.mlx, "./temp/hut.xpm42");
	game.assets.tree = ft_asset_to_image(game.mlx, "./temp/tree.xpm42");

	// Define the map
	char *map[] = {"1111111111111", "100100000C0C1", "100001101C001",
		"1C0011EP10001", "1111111111111", NULL};

	// Define the tile size
	int tile_size = 120; // Adjust this value to match the size of your images

	// Display the images based on the map
	for (int y = 0; map[y] != NULL; y++)
	{
		for (int x = 0; map[y][x] != '\0'; x++)
		{
			// Place terrain on each tile
			if (mlx_image_to_window(game.mlx, game.assets.terrain, x
					* tile_size, y * tile_size) < 0)
				error();

			// Place the specific assets based on the map characters
			if (map[y][x] == '1')
			{
				if (mlx_image_to_window(game.mlx, game.assets.wall, x
						* tile_size, y * tile_size) < 0)
					error();
			}
			else if (map[y][x] == 'P')
			{
				if (mlx_image_to_window(game.mlx, game.assets.lumberjack, x
						* tile_size, y * tile_size) < 0)
					error();
			}
			else if (map[y][x] == 'E')
			{
				if (mlx_image_to_window(game.mlx, game.assets.hut, x
						* tile_size, y * tile_size) < 0)
					error();
			}
			else if (map[y][x] == 'C')
			{
				if (mlx_image_to_window(game.mlx, game.assets.tree, x
						* tile_size, y * tile_size) < 0)
					error();
			}
			// Add more conditions here for other characters if needed
		}
	}

	// Enter the MLX loop
	mlx_loop(game.mlx);

	// Clean up any leftovers
	mlx_delete_image(game.mlx, game.assets.terrain);
	mlx_delete_image(game.mlx, game.assets.wall);
	mlx_delete_image(game.mlx, game.assets.lumberjack);
	mlx_terminate(game.mlx);

	return (EXIT_SUCCESS);
}