/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:01:40 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/08 22:23:07 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TILESIZE 60

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

mlx_image_t	*ft_asset_to_image(mlx_t *mlx, char *img_path)
{
	xpm_t		*xpm;
	mlx_image_t	*img;

	xpm = mlx_load_xpm42(img_path);
	if (!xpm)
		error();
	img = mlx_texture_to_image(mlx, &xpm->texture);
	if (!img)
		error();
	mlx_delete_xpm42(xpm);
	return (img);
}

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (0);
	i = 0;
	while (argv[1][i])
		i++;
	if (argv[1][i] != 'r' || argv[1][i - 1] != 'e' || argv[1][i
		- 2] != 'b' || argv[1][i - 3] != '.')
		return (0);
	return (1);
}

int	check_lines(int argc, char **argv, int *i, int fd)
{
	char	*text;

	text = get_next_line(fd);
	while (text[*i])
	{
		if (text[0] != '1')
			return (printf("outer border must be walls"));
		(*i)++;
	}

	return 0;
}

char	**get_map(int argc, char **argv)
{
	char	**map;
	int		fd;
	int		i;

	i = 0;
	if (!check_args(argc, argv))
	{
		printf("args are wrong!");
		return (NULL);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("cannot read the map");
		return (NULL);
	}
	if (!check_lines(argc, argv, &i, fd))
	{
		printf("lines are broken");
		return (NULL);
	}
}

int	main(int argc, char **argv)
{
	t_game game;
	int fd;
	char *text;
	int y;

	get_map(argc, argv);

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Failed to open map file");
		return (EXIT_FAILURE);
	}

	text = get_next_line(fd);
	if (!text)
	{
		fprintf(stderr, "Failed to read from map file\n");
		close(fd);
		return (EXIT_FAILURE);
	}

	game.mapwidth = strlen(text) - 1;
	game.mapheight = 0;
	while (text)
	{
		free(text);
		text = get_next_line(fd);
		game.mapheight++;
	}
	close(fd);

	game.mlx = mlx_init(TILESIZE * game.mapwidth, TILESIZE * game.mapheight,
			"Test", true);
	if (!game.mlx)
		error();

	game.assets.terrain = ft_asset_to_image(game.mlx, "./temp/terrain.xpm42");
	game.assets.wall = ft_asset_to_image(game.mlx, "./temp/tree2.xpm42");
	game.assets.lumberjack = ft_asset_to_image(game.mlx,
			"./temp/lumberjack.xpm42");
	game.assets.hut = ft_asset_to_image(game.mlx, "./temp/hut.xpm42");
	game.assets.tree = ft_asset_to_image(game.mlx, "./temp/tree.xpm42");

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Failed to reopen map file");
		return (EXIT_FAILURE);
	}

	y = 0;
	text = get_next_line(fd);
	while (text)
	{
		for (int x = 0; x < game.mapwidth; x++)
		{
			if (mlx_image_to_window(game.mlx, game.assets.terrain, x * TILESIZE,
					y * TILESIZE) < 0)
				error();

			if (text[x] == 'P' && mlx_image_to_window(game.mlx,
					game.assets.lumberjack, x * TILESIZE, y * TILESIZE) < 0)
				error();
			if (text[x] == '1' && mlx_image_to_window(game.mlx,
					game.assets.wall, x * TILESIZE, y * TILESIZE) < 0)
				error();
			if (text[x] == 'C' && mlx_image_to_window(game.mlx,
					game.assets.tree, x * TILESIZE, y * TILESIZE) < 0)
				error();
			if (text[x] == 'E' && mlx_image_to_window(game.mlx, game.assets.hut,
					x * TILESIZE, y * TILESIZE) < 0)
				error();
		}
		free(text);
		text = get_next_line(fd);
		y++;
	}
	close(fd);

	printf("\nwidth: %d\n", game.mapwidth);
	printf("\nheight: %d\n", game.mapheight);

	mlx_loop(game.mlx);

	mlx_delete_image(game.mlx, game.assets.terrain);
	mlx_delete_image(game.mlx, game.assets.wall);
	mlx_delete_image(game.mlx, game.assets.lumberjack);
	mlx_delete_image(game.mlx, game.assets.hut);
	mlx_delete_image(game.mlx, game.assets.tree);
	mlx_terminate(game.mlx);

	return (EXIT_SUCCESS);
}