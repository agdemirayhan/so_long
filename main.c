/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:01:40 by aagdemir          #+#    #+#             */
/*   Updated: 2024/08/03 12:36:01 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"

// norminette validation.c &&norminette so_long.h &&norminette move_utils.c
// && norminette map_utils.c &&norminette main.c &&norminette image_utils.c
// && norminette hooks.c &&norminette ft_printf &&norminette get_next_line
// && norminette libft

void	check_leaks(void)
{
	system("leaks so_long");
}

void	accessibility(char **map, t_game *game, char **argv)
{
	int		i;
	int		j;
	char	**temp_map;

	i = 0;
	while (i < game->mapheight)
	{
		j = 0;
		while (j < game->mapwidth)
		{
			if (map[i][j] == 'C' || map[i][j] == 'P')
			{
				temp_map = open_map(argv, game->mapheight);
				if (!check_accessible(temp_map, i, j))
				{
					free_map(temp_map);
					error_handling("Collectible or Exit is not accessible!");
				}
				free_map(temp_map);
			}
			(j)++;
		}
		(i)++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	error_handling(char *str)
{
	ft_printf("Error\n");
	ft_printf(str);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (LEAKS)
		atexit(check_leaks);
	game.map = get_map(argc, argv, &game);
	game.movecount = 0;
	game.status = INIT;
	game.mlx = mlx_init(TILESIZE * game.mapwidth, TILESIZE * game.mapheight,
			"Lumberjack", true);
	if (!game.mlx)
		error_handling("Failed to initialize mlx");
	put_image_in_map(&game);
	game.status = INGAME;
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_loop(game.mlx);
	clean_old_assets(&game);
	free_map(game.map);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
