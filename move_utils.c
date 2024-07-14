/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:47:27 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/14 13:26:38 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"

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
		ft_printf("posx:%d\n", game2->count);
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