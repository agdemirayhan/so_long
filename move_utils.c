/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:47:27 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/31 22:29:38 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"

void	move(t_game *game, int dy, int dx)
{
	int	new_posy;
	int	new_posx;

	new_posy = game->posy + dy;
	new_posx = game->posx + dx;
	if (game->map[new_posy][new_posx] != '1')
	{
		if (game->map[new_posy][new_posx] == 'C')
			game->coll -= 1;
		else if (game->map[new_posy][new_posx] == 'E' && game->coll == 0)
			game->status = END;
		if (game->map[new_posy][new_posx] == 'E' && game->coll != 0)
			game->map[new_posy][new_posx] = 'X';
		else
			game->map[new_posy][new_posx] = 'P';
		if (game->map[game->posy][game->posx] == 'X')
			game->map[game->posy][game->posx] = 'E';
		else
			game->map[game->posy][game->posx] = '0';
		game->posy = new_posy;
		game->posx = new_posx;
		game->movecount++;
		ft_printf("Moves:%d\n", game->movecount);
	}
}

void	move_up(t_game *game)
{
	move(game, -1, 0);
}

void	move_down(t_game *game)
{
	move(game, 1, 0);
}

void	move_right(t_game *game)
{
	move(game, 0, 1);
}

void	move_left(t_game *game)
{
	move(game, 0, -1);
}
