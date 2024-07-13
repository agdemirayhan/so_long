/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:54:07 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/13 08:58:01 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"

# define TILESIZE 60

// # define RED "\033[1m\033[31m"
// # define GREEN "\033[1m\033[32m"
// # define ENDC "\033[0m"
// # define BOLDRED "\033[31m"
// # define UP 13
// # define DOWN 1
// # define LEFT 0
// # define RIGHT 2
// # define ESC 53
// # define SIZE 48

typedef struct s_assets
{
	mlx_image_t	*hut;
	mlx_image_t	*lumberjack;
	mlx_image_t	*wall;
	mlx_image_t	*tree;
	mlx_image_t	*terrain;
}				t_assets;

typedef struct s_game
{
	mlx_t		*mlx;
	t_assets	assets;
	int			mapheight;
	int			mapwidth;
	int			posx;
	int			posy;
	char		**map;
}				t_game;

void			move_up(t_game *game);
void			error_handling(char *str);
mlx_image_t	*ft_asset_to_image(mlx_t *mlx, char *img_path);

#endif