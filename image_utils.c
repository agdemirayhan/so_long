/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:27:02 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/29 21:11:08 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"

void	image_to_window(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->assets.terrain, x * TILESIZE, y
		* TILESIZE);
	if (game->map[y][x] == '1')
		mlx_image_to_window(game->mlx, game->assets.wall, x * TILESIZE, y
			* TILESIZE);
	else if (game->map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->assets.hut, x * TILESIZE, y
			* TILESIZE);
	else if (game->map[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->assets.lumberjack, x * TILESIZE, y
			* TILESIZE);
	else if (game->map[y][x] == 'X')
	{
		mlx_image_to_window(game->mlx, game->assets.hut, x * TILESIZE, y
			* TILESIZE);
		mlx_image_to_window(game->mlx, game->assets.lumberjack, x * TILESIZE, y
			* TILESIZE);
	}
	else if (game->map[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->assets.tree, x * TILESIZE, y
			* TILESIZE);
}

void	clean_old_assets(t_game *game)
{
	mlx_delete_image(game->mlx, game->assets.lumberjack);
	mlx_delete_image(game->mlx, game->assets.tree);
	mlx_delete_image(game->mlx, game->assets.hut);
	mlx_delete_image(game->mlx, game->assets.wall);
	mlx_delete_image(game->mlx, game->assets.terrain);
}

void	load_assets(t_game *game)
{
	game->assets.terrain = ft_asset_to_image(game->mlx,
			"./textures/terrain.xpm42");
	game->assets.wall = ft_asset_to_image(game->mlx, "./textures/tree2.xpm42");
	game->assets.lumberjack = ft_asset_to_image(game->mlx,
			"./textures/lumberjack.xpm42");
	game->assets.hut = ft_asset_to_image(game->mlx, "./textures/hut.xpm42");
	game->assets.tree = ft_asset_to_image(game->mlx, "./textures/tree.xpm42");
}

void	put_image_in_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	clean_old_assets(game);
	load_assets(game);
	while (y < game->mapheight)
	{
		x = 0;
		while (x < game->mapwidth)
		{
			image_to_window(game, x, y);
			x++;
		}
		y++;
	}
	return ;
}

mlx_image_t	*ft_asset_to_image(mlx_t *mlx, char *img_path)
{
	xpm_t		*xpm;
	mlx_image_t	*img;

	xpm = mlx_load_xpm42(img_path);
	if (!xpm)
		error_handling("Failed to load xpm!");
	img = mlx_texture_to_image(mlx, &xpm->texture);
	if (!img)
		error_handling("Failed to get images");
	mlx_delete_xpm42(xpm);
	return (img);
}
