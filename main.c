/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:01:40 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/09 22:04:54 by aagdemir         ###   ########.fr       */
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
	if (argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e' || argv[1][i - 3] != 'b'
		|| argv[1][i - 4] != '.')
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
			return (0);
		(*i)++;
	}
	return (1);
}

void	get_map_height_and_width(t_game *game, int fd)
{
	char	*text;

	text = get_next_line(fd);
	if (text == NULL)
	{
		ft_printf("Empty map file or error reading file");
		exit(1);
	}
	game->mapwidth = strlen(text) - 1;
	game->mapheight = 0;
	while (text)
	{
		free(text);
		text = get_next_line(fd);
		game->mapheight++;
	}
	close(fd);
}

void	error_handling(char *str)
{
	ft_printf(str);
	exit(1);
}

char	**get_map(int argc, char **argv, t_game *game)
{
	char	**map;
	int		fd;
	int		i;

	i = 0;
	if (!check_args(argc, argv))
		error_handling("args are wrong!");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_handling("cannot read the map");
	if (!check_lines(argc, argv, &i, fd))
		error_handling("lines are broken");
	get_map_height_and_width(game, fd);
	map = malloc((game->mapheight + 1) * sizeof(char *));
	if (map == NULL)
		error_handling("Memory allocation failed");
	i = 0;
	map[i] = get_next_line(fd);
	while (map[i])
		map[++i] = get_next_line(fd);
	map[i] = NULL;
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	t_game game;
	int fd;
	int y;
	char **map;
	int i;

	map = get_map(argc, argv, &game);
	i = 0;
	while (map[i])
	{
		ft_printf("%s", map[i]);
		free(map[i]);
		i++;
	}
	free(map);

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


	i = 0;
	while (map[i])
	{
		for (int x = 0; x < game.mapwidth; x++)
		{
			if (mlx_image_to_window(game.mlx, game.assets.terrain, x * TILESIZE,
					y * TILESIZE) < 0)
				error();

			if (map[i][x]== 'P' && mlx_image_to_window(game.mlx,
					game.assets.lumberjack, x * TILESIZE, y * TILESIZE) < 0)
				error();
			if (map[i][x]== '1' && mlx_image_to_window(game.mlx,
					game.assets.wall, x * TILESIZE, y * TILESIZE) < 0)
				error();
			if (map[i][x]== 'C' && mlx_image_to_window(game.mlx,
					game.assets.tree, x * TILESIZE, y * TILESIZE) < 0)
				error();
			if (map[i][x]== 'E' && mlx_image_to_window(game.mlx, game.assets.hut,
					x * TILESIZE, y * TILESIZE) < 0)
				error();
		}
	}
	// close(fd);

	mlx_loop(game.mlx);

	mlx_delete_image(game.mlx, game.assets.terrain);
	mlx_delete_image(game.mlx, game.assets.wall);
	mlx_delete_image(game.mlx, game.assets.lumberjack);
	mlx_delete_image(game.mlx, game.assets.hut);
	mlx_delete_image(game.mlx, game.assets.tree);
	mlx_terminate(game.mlx);

	return (EXIT_SUCCESS);
}