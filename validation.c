/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:18:11 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/17 22:57:50 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"

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
	return (is_acc);
}

int	count_chars(char **map, int *p, int *e, int width)
{
	int	c;
	int	i;

	c = 0;
	while (*map)
	{
		i = 0;
		while (i < width)
		{
			if (((*map)[i] == 'P' && *p) || ((*map)[i] == 'E' && *e))
				error_handling("Chars are not correct");
			else if ((*map)[i] == 'P')
				*p = 1;
			else if ((*map)[i] == 'E')
				*e = 1;
			else if ((*map)[i] == 'C')
				c++;
			else if (((*map)[i] != '1') && ((*map)[i] != '0'))
				error_handling("Chars are not correct3");
			i++;
		}
		map++;
	}
	return (c);
}

int	check_chars(char **map, int width)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = count_chars(map, &p, &e, width);
	if (!c || !p || !e)
		error_handling("Chars are not correct");
	return (c);
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

int	check_borders(int fd, t_game *game)
{
	char	*text;
	int		i;
	int		j;

	j = 0;
	if (game->mapwidth < 3)
		return (0);
	while (j < game->mapheight)
	{
		i = 0;
		text = get_next_line(fd);
		while (i < game->mapwidth)
		{
			if ((text[i] != '1' && (j == 0 || j == game->mapheight))
				|| text[0] != '1' || text[game->mapwidth - 1] != '1')
				return (0);
			i++;
		}
		if (i != game->mapwidth)
			return (0);
		j++;
	}
	return (1);
}
