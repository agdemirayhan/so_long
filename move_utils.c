/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:47:27 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/14 19:04:49 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"

// GOTTA CARE REFACTORING
void	move_up(t_game *game)
{
	if (game->map[game->posy - 1][game->posx] != '1')
	{
		if (game->map[game->posy - 1][game->posx] == 'C')
			game->coll -= 1;
		else if (game->map[game->posy - 1][game->posx] == 'E'
			&& game->coll == 0)
			game->status = END;
		else if (game->map[game->posy - 1][game->posx] == 'E'
			&& game->coll != 0)
			game->map[game->posy - 1][game->posx] = 'X';
		game->map[game->posy - 1][game->posx] = 'P';
		game->map[game->posy][game->posx] = '0';
		game->posy -= 1;
		game->movecount++;
		ft_printf("Moves:%d\n", game->movecount);
		ft_printf("Coll:%d\n", game->coll);
		return ;
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->posy + 1][game->posx] != '1')
	{
		if (game->map[game->posy + 1][game->posx] == 'C')
			game->coll -= 1;
		else if (game->map[game->posy + 1][game->posx] == 'E'
			&& game->coll == 0)
			game->status = END;
		else if (game->map[game->posy + 1][game->posx] == 'E'
			&& game->coll != 0)
			game->map[game->posy + 1][game->posx] = 'X';
		game->map[game->posy + 1][game->posx] = 'P';
		game->map[game->posy][game->posx] = '0';
		game->posy += 1;
		game->movecount++;
		ft_printf("Moves:%d\n", game->movecount);
		ft_printf("Coll:%d\n", game->coll);
		return ;
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->posy][game->posx + 1] != '1')
	{
		if (game->map[game->posy][game->posx + 1] == 'C')
			game->coll -= 1;
		else if (game->map[game->posy][game->posx + 1] == 'E'
			&& game->coll == 0)
			game->status = END;
		if (game->map[game->posy][game->posx + 1] == 'E' && game->coll != 0)
			game->map[game->posy][game->posx + 1] = 'X';
		else
			game->map[game->posy][game->posx + 1] = 'P';
		game->map[game->posy][game->posx] = '0';
		game->posx += 1;
		game->movecount++;
		ft_printf("Moves:%d\n", game->movecount);
		ft_printf("Coll:%d\n", game->coll);
		return ;
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->posy][game->posx - 1] != '1')
	{
		if (game->map[game->posy][game->posx - 1] == 'C')
			game->coll -= 1;
		else if (game->map[game->posy][game->posx - 1] == 'E'
			&& game->coll == 0)
			game->status = END;
		if (game->map[game->posy][game->posx - 1] == 'E' && game->coll != 0)
			game->map[game->posy][game->posx - 1] = 'X';
		else
			game->map[game->posy][game->posx - 1] = 'P';
		game->map[game->posy][game->posx] = '0';
		game->posx -= 1;
		game->movecount++;
		ft_printf("Moves:%d\n", game->movecount);
		ft_printf("Coll:%d\n", game->coll);
		ft_printf("Status:%d\n", game->status);
		return ;
	}
}
