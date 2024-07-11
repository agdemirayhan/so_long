/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:01:40 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/11 22:01:35 by aagdemir         ###   ########.fr       */
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

void	error_handling(char *str)
{
	ft_printf(str);
	exit(1);
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

void	get_player_pos(char **map, int *i, int *j, int w, int h)
{
	while (*i < h)
	{
		*j = 0;
		while (*j < w)
		{
			if (map[*i][*j] == 'P')
				return ;
			(*j)++;
		}
		(*i)++;
	}
}

int	check_accessible(char **map, int i, int j)
{
	int	is_acc;

	is_acc = 0;
	if (map[i][j] != '1' && map[i][j] != 'E')
	{
		map[i][j] = '1';
		is_acc += check_accessible(map, i + 1, j);
		is_acc += check_accessible(map, i - 1, j);
		is_acc += check_accessible(map, i, j + 1);
		is_acc += check_accessible(map, i, j - 1);
	}
	is_acc += map[i][j] == 'E';
	return is_acc;
}

void	check_chars(char **map, int width)
{
	int	p;
	int	e;
	int	c;
	int	i;

	p = 0;
	e = 0;
	c = 0;
	while (*map)
	{
		i = 0;
		while (i < width)
		{
			if (((*map)[i] == 'P' && p) || ((*map)[i] == 'E' && e))
				error_handling("chars are not correct");
			else if ((*map)[i] == 'P')
				p = 1;
			else if ((*map)[i] == 'E')
				e = 1;
			else if ((*map)[i] == 'C')
				c++;
			else if (((*map)[i] != '1') && ((*map)[i] != '0'))
				error_handling("chars are not correct3");
			i++;
		}
		map++;
	}
	if (!c || !p || !e)
		error_handling("chars are not correct");
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

int	check_map(int argc, char **argv, int fd, int height, int width)
{
	char	*text;
	int		i;
	int		j;

	j = 0;
	if (width < 3)
		return (0);
	while (j < height)
	{
		i = 0;
		text = get_next_line(fd);
		ft_printf("%s", text);
		while (i < width)
		{
			if ((text[i] != '1' && (j == 0 || j == height)) || text[0] != '1'
				|| text[width - 1] != '1')
				return (0);
			i++;
		}
		if (i != width)
			return (0);
		j++;
		// free(text);
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

char	**get_map(int argc, char **argv, t_game *game)
{
	char	**map;
	int		fd;
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!check_args(argc, argv))
		error_handling("args are wrong!");
	fd = open(argv[1], O_RDONLY);
	get_map_height_and_width(game, fd);
	if (fd == -1)
		error_handling("cannot read the map");
	// Reopen the file to read the map data again
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_handling("cannot read the map");
	if (!check_map(argc, argv, fd, game->mapheight, game->mapwidth))
		error_handling("lines are broken");
	// Reopen the file to read again from the beginning
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_handling("cannot read the map");
	map = malloc((game->mapheight + 1) * sizeof(char *));
	if (!map)
		error_handling("Memory allocation failed");
	i = 0;
	map[i] = get_next_line(fd);
	while (map[i])
	{
		map[++i] = get_next_line(fd);
	}
	map[i] = NULL;
	check_chars(map, game->mapwidth);
	get_player_pos(map, &x, &y, game->mapwidth, game->mapheight);
	ft_printf("%d\n",check_accessible(map, x, y));
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	t_game game;
	int y;
	char **map;
	int i;

	map = get_map(argc, argv, &game);

	// Initialize the MLX window
	game.mlx = mlx_init(TILESIZE * game.mapwidth, TILESIZE * game.mapheight,
			"Test", true);
	if (!game.mlx)
		error_handling("Failed to initialize mlx");

	game.assets.terrain = ft_asset_to_image(game.mlx, "./temp/terrain.xpm42");
	game.assets.wall = ft_asset_to_image(game.mlx, "./temp/tree2.xpm42");
	game.assets.lumberjack = ft_asset_to_image(game.mlx,
			"./temp/lumberjack.xpm42");
	game.assets.hut = ft_asset_to_image(game.mlx, "./temp/hut.xpm42");
	game.assets.tree = ft_asset_to_image(game.mlx, "./temp/tree.xpm42");

	y = 0;
	while (map[y])
	{
		for (int x = 0; x < game.mapwidth; x++)
		{
			if (mlx_image_to_window(game.mlx, game.assets.terrain, x * TILESIZE,
					y * TILESIZE) < 0)
				error_handling("Failed to put terrain image to window");

			if (map[y][x] == 'P' && mlx_image_to_window(game.mlx,
					game.assets.lumberjack, x * TILESIZE, y * TILESIZE) < 0)
				error_handling("Failed to put lumberjack image to window");
			if (map[y][x] == '1' && mlx_image_to_window(game.mlx,
					game.assets.wall, x * TILESIZE, y * TILESIZE) < 0)
				error_handling("Failed to put wall image to window");
			if (map[y][x] == 'C' && mlx_image_to_window(game.mlx,
					game.assets.tree, x * TILESIZE, y * TILESIZE) < 0)
				error_handling("Failed to put tree image to window");
			if (map[y][x] == 'E' && mlx_image_to_window(game.mlx,
					game.assets.hut, x * TILESIZE, y * TILESIZE) < 0)
				error_handling("Failed to put hut image to window");
		}
		y++;
	}

	// Free the map after use
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);

	// Enter the MLX loop
	mlx_loop(game.mlx);

	// Clean up images and terminate MLX
	mlx_delete_image(game.mlx, game.assets.terrain);
	mlx_delete_image(game.mlx, game.assets.wall);
	mlx_delete_image(game.mlx, game.assets.lumberjack);
	mlx_delete_image(game.mlx, game.assets.hut);
	mlx_delete_image(game.mlx, game.assets.tree);
	mlx_terminate(game.mlx);

	return (EXIT_SUCCESS);
}