/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:01:40 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/07 09:17:15 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 1280
#define HEIGHT 720

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
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
char	**read_map(const char *file_path)
{
	int		fd;
	char	*buffer;
	size_t	buffer_size;
	char	ch;
	size_t	line_count;
	char	**map;
	size_t	line_start;
	size_t	map_index;
	size_t	line_length;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error();
	// Read the file content
	buffer = NULL;
	buffer_size = 0;
	while (read(fd, &ch, 1) > 0)
	{
		buffer = realloc(buffer, buffer_size + 1);
		buffer[buffer_size++] = ch;
	}
	close(fd);
	if (!buffer)
		error();
	// Null-terminate the buffer
	buffer = realloc(buffer, buffer_size + 1);
	buffer[buffer_size] = '\0';
	// Count the number of lines
	line_count = 0;
	for (size_t i = 0; i < buffer_size; i++)
	{
		if (buffer[i] == '\n')
			line_count++;
	}
	// Allocate memory for the map
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		error();
	// Parse the buffer into lines
	line_start = 0;
	map_index = 0;
	for (size_t i = 0; i <= buffer_size; i++)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
		{
			line_length = i - line_start;
			map[map_index] = malloc(line_length + 1);
			if (!map[map_index])
				error();
			ft_memcpy(map[map_index], &buffer[line_start], line_length);
			map[map_index][line_length] = '\0';
			line_start = i + 1;
			map_index++;
		}
	}
	free(buffer); // Free the buffer after parsing
	return (map);
}

void	free_map(char **map)
{
	for (size_t i = 0; map[i] != NULL; i++)
	{
		free(map[i]);
	}
	free(map);
}

// void *getmap(char **argv, t_game *game)
// {
// 	int fd;

// 	fd = open(argv[1],O_RDONLY);
// }

int	main(int argc, char **argv)
{
	t_game game;
	char **map;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	int fd;
	char *text;

	fd = open("./maps/map1.ber", O_RDONLY);

	text = get_next_line(fd);

	printf("\ntext:%s\n",text);

	// Read the map
	map = read_map(argv[1]);

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
	mlx_delete_image(game.mlx, game.assets.hut);
	mlx_delete_image(game.mlx, game.assets.tree);
	mlx_terminate(game.mlx);

	// Free the map
	free_map(map);

	return (EXIT_SUCCESS);
}