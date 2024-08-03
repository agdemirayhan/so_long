/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:31:49 by aagdemir          #+#    #+#             */
/*   Updated: 2024/08/03 09:04:52 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"

void	ft_hook(void *param)
{
	t_game	*game;

	game = param;
	put_image_in_map(game);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	put_image_in_map(game);
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			ft_printf("Exit");
			mlx_close_window(game->mlx);
		}
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_up(game);
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_down(game);
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_left(game);
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_right(game);
		if (game->status == END)
		{
			ft_printf("Congratulations!\n");
			mlx_close_window(game->mlx);
		}
	}
}
