/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:29:23 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/15 22:34:55 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"

void	get_player_pos(char **map, int *i, int *j, t_game *game)
{
	while (*i < game->mapheight)
	{
		*j = 0;
		while (*j < game->mapwidth)
		{
			if (map[*i][*j] == 'P')
			{
				game->posx = *j;
				game->posy = *i;
				return ;
			}
			(*j)++;
		}
		(*i)++;
	}
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
	free(text);
	close(fd);
}

char	**open_map(char **argv, int height)
{
	int		fd;
	char	**map;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_handling("cannot read the map");
	map = malloc((height + 1) * sizeof(char *));
	if (!map)
		error_handling("Memory allocation failed");
	i = 0;
	map[i] = get_next_line(fd);
	while (map[i])
	{
		map[++i] = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

void	check_map(int argc, char **argv, t_game *game)
{
	int	fd;

	if (!check_args(argc, argv))
		error_handling("args are wrong!");
	fd = open(argv[1], O_RDONLY);
	get_map_height_and_width(game, fd);
	if (fd == -1)
		error_handling("cannot read the map");
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_handling("cannot read the map");
	if (!check_borders(fd, game))
		error_handling("lines are broken");
	close(fd);
}

char	**get_map(int argc, char **argv, t_game *game)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	check_map(argc, argv, game);
	map = open_map(argv, game->mapheight);
	game->coll = check_chars(map, game->mapwidth);
	get_player_pos(map, &x, &y, game);
	if (!check_accessible(map, x, y))
		error_handling("exit is not accessible!");
	map = open_map(argv, game->mapheight);
	return (map);
}
