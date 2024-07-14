/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:47:27 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/14 15:11:21 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"

// void	move_up(t_game *game)
// {
// 	ft_printf("game->map[game->posx][game->posy - 1]:%c\n", game->mapwidth);
// 	if (game->map[game->posx][game->posy - 1] != '1')
// 	{
// 		if (game->assets.lumberjack)
// 			mlx_delete_image(game->mlx, game->assets.lumberjack);
// 		ft_printf("posx:%d\n", game->posx);
// 		ft_printf("posy:%d\n", game->posy);
// 		game->map[game->posx][game->posy] = '0';
// 		game->map[game->posx][game->posy - 1] = 'P';
// 		game->posy -= 1;
// 		ft_printf("posx:%d\n", game->posx);
// 		ft_printf("posy:%d\n", game->posy);
// 		game->assets.lumberjack = ft_asset_to_image(game->mlx,
// 				"./temp/lumberjack.xpm42");
// 		if (!game->assets.lumberjack)
// 		{
// 			// Handle error (e.g., print error message, exit, etc.)
// 			puts("Error loading image");
// 			return ;
// 		}
// 		mlx_image_to_window(game->mlx, game->assets.lumberjack, game->posx
// 			* TILESIZE, game->posy * TILESIZE);
// 		puts("UP");
// 	}
// }

// if (game2->map[game2->posx][game2->posy - 1] != '1')
// {
// 	if (game2->assets.lumberjack)
// 		mlx_delete_image(game2->mlx, game2->assets.lumberjack);
// 	ft_printf("posx:%d\n", game2->count);
// 	ft_printf("posy:%d\n", game2->posy);
// 	game2->map[game2->posx][game2->posy] = '0';
// 	game2->map[game2->posx][game2->posy - 1] = 'P';
// 	game2->posy -= 1;
// 	ft_printf("posx:%d\n", game2->posx);
// 	ft_printf("posy:%d\n", game2->posy);
// 	game2->assets.lumberjack = ft_asset_to_image(game2->mlx,
// 			"./temp/lumberjack.xpm42");
// 	if (!game2->assets.lumberjack)
// 	{
// 		// Handle error (e.g., print error message, exit, etc.)
// 		puts("Error loading image");
// 		return ;
// 	}
// 	mlx_image_to_window(game2->mlx, game2->assets.lumberjack, game2->posx
// 		* TILESIZE, game2->posy * TILESIZE);
// 	puts("UP");
// }

void	move_up(t_game *game)
{
	int	x;
	int	y;

	if (game->map[game->posy - 1][game->posx] != '1')
	{
		game->map[game->posy][game->posx] = '0';
		game->map[game->posy - 1][game->posx] = 'P';
		game->posy -= 1;
		game->movecount++;
		ft_printf("Moves:%d\n", game->movecount);
		return ;
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->posy + 1][game->posx] != '1')
	{
		game->map[game->posy][game->posx] = '0';
		game->map[game->posy + 1][game->posx] = 'P';
		game->posy += 1;
		game->movecount++;
		ft_printf("Moves:%d\n", game->movecount);
		return ;
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->posy][game->posx + 1] != '1')
	{
		game->map[game->posy][game->posx] = '0';
		game->map[game->posy][game->posx + 1] = 'P';
		game->posx += 1;
		game->movecount++;
		ft_printf("Moves:%d\n", game->movecount);
		return ;
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->posy][game->posx - 1] != '1')
	{
		game->map[game->posy][game->posx] = '0';
		game->map[game->posy][game->posx - 1] = 'P';
		game->posx -= 1;
		game->movecount++;
		ft_printf("Moves:%d\n", game->movecount);
		return ;
	}
}

// void	move_down(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	while (++y < game->mapwidth)
// 	{
// 		x = -1;
// 		while (++x < game->mapheight)
// 		{
// 			if (game->map[y][x] == 'P')
// 			{
// 				if (game->map[y + 1][x] == '0' || game->map[y - 1][x] == 'C'
// 					|| game->map[y + 1][x] == 'E')
// 				{
// 					game->map[y + 1][x] = 'P';
// 					game->map[y][x] = '0';
// 					game->movecount++;
// 					ft_printf("Moves:%d\n", game->movecount);
// 					return ;
// 				}
// 			}
// 		}
// 	}
// }

// void	move_left(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	while (++y < game->mapwidth)
// 	{
// 		x = -1;
// 		while (++x < game->mapheight)
// 		{
// 			if (game->map[y][x] == 'P')
// 			{
// 				if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C'
// 					|| game->map[y][x - 1] == 'E')
// 				{
// 					game->map[y][x - 1] = 'P';
// 					game->map[y][x] = '0';
// 					game->movecount++;
// 					ft_printf("Moves:%d\n", game->movecount);
// 					return ;
// 				}
// 			}
// 		}
// 	}
// }

// void	move_right(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	while (++y < game->mapwidth)
// 	{
// 		x = -1;
// 		while (++x < game->mapheight)
// 		{
// 			if (game->map[y][x] == 'P')
// 			{
// 				if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C'
// 					|| game->map[y][x + 1] == 'E')
// 				{
// 					game->map[y][x + 1] = 'P';
// 					game->map[y][x] = '0';
// 					game->movecount++;
// 					ft_printf("Moves:%d\n", game->movecount);
// 					return ;
// 				}
// 			}
// 		}
// 	}
// }
