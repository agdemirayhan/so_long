/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:01:40 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/06 11:48:59 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
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

int32_t	main(void)
{
	
	
	// Start mlx
	mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
		error();

	// Try to load the file
	xpm_t *xpm = mlx_load_xpm42("./temp/terrain.xpm42");
	if (!xpm)
		error();

	// Convert texture to a displayable image
	mlx_image_t *img = mlx_texture_to_image(mlx, &xpm->texture);
	if (!img)
		error();

	// Display the image
	for (int i = 0; i <= WIDTH; i = i + 120)
	{
		for (int j = 0; j <= HEIGHT; j = j + 120)
		{
			if (mlx_image_to_window(mlx, img, i, j) < 0)
				error();
		}
	}


	// mlx_key_hook(mlx, &my_keyhook, NULL);

	// mlx_loop_hook(mlx, ft_randomize, mlx);
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);

	// Optional, terminate will clean up any leftovers,
	mlx_delete_image(mlx, img);
	mlx_delete_xpm42(xpm);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}